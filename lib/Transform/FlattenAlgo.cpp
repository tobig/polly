//===------ FlattenAlgo.cpp ------------------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Main algorithm of the FlattenSchedulePass. This is a separate file to avoid
// the unittest for this requiring linking against LLVM.
//
//===----------------------------------------------------------------------===//

#include "polly/FlattenAlgo.h"
#include "llvm/Support/Debug.h"
#define DEBUG_TYPE "polly-flatten-algo"

using namespace polly;
using namespace llvm;

namespace {

/// Whether a dimension of a set is bounded (lower and upper) by a constant,
/// i.e. there are two constants Min and Max, such that every value x of the
/// chosen dimensions is Min <= x <= Max.
bool isDimBoundedByConstant(isl::Set Set, unsigned dim) {
  auto ParamDims = Set.dim(isl::Dim::Param);
  Set = Set.projectOut(isl::Dim::Param, 0, ParamDims);
  Set = Set.projectOut(isl::Dim::Set, 0, dim);
  auto SetDims = Set.dim(isl::Dim::Set);
  Set = Set.projectOut(isl::Dim::Set, 1, SetDims - 1);
  return Set.isBounded();
}

/// Whether a dimension of a set is (lower and upper) bounded by a constant or
/// parameters, i.e. there are two expressions Min_p and Max_p of the parameters
/// p, such that every value x of the chosen dimensions is
/// Min_p <= x <= Max_p.
bool isDimBoundedByParameter(isl::Set Set, unsigned dim) {
  Set = Set.projectOut(isl::Dim::Set, 0, dim);
  auto SetDims = Set.dim(isl::Dim::Set);
  Set = Set.projectOut(isl::Dim::Set, 1, SetDims - 1);
  return Set.isBounded();
}

/// Whether BMap's first out-dimension is not a constant.
bool isVariableDim(const isl::BasicMap &BMap) {
  auto FixedVal = BMap.plainGetValIfFixed(isl::Dim::Out, 0);
  return !FixedVal || FixedVal.isNan();
}

/// Whether Map's first out dimension is no constant nor piecewise constant.
bool isVariableDim(const isl::Map &Map) {
  return foreachEltWithBreak(Map, [](isl::BasicMap BMap) -> isl_stat {
    if (isVariableDim(BMap))
      return isl_stat_error;
    return isl_stat_ok;
  });
}

/// Whether UMap's first out dimension is no (piecewise) constant.
bool isVariableDim(const isl::UnionMap &UMap) {
  return foreachEltWithBreak(UMap, [](isl::Map Map) -> isl_stat {
    if (isVariableDim(Map))
      return isl_stat_error;
    return isl_stat_ok;
  });
}

/// If @p PwAff maps to a constant, return said constant. If @p Max/@p Min, it
/// can also be a piecewise constant and it would return the minimum/maximum
/// value. Otherwise, return NaN.
isl::Val getConstant(isl::PwAff PwAff, bool Max, bool Min) {
  assert(!Max || !Min);
  isl::Val Result;
  foreachPieceWithBreak(PwAff, [=, &Result](isl::Set Set, isl::Aff Aff) {
    if (Result && Result.isNan())
      return isl_stat_ok;

    // TODO: If Min/Max, we can also determine a minimum/maximum value if
    // Set is constant-bounded.
    if (!Aff.isCst()) {
      Result = isl::Val::nan(Aff.getCtx());
      return isl_stat_error;
    }

    auto ThisVal = Aff.getConstantVal();
    if (!Result) {
      Result = ThisVal;
      return isl_stat_ok;
    }

    if (Result.eq(ThisVal))
      return isl_stat_ok;

    if (Max && ThisVal.gt(Result)) {
      Result = ThisVal;
      return isl_stat_ok;
    }

    if (Min && ThisVal.lt(Result)) {
      Result = ThisVal;
      return isl_stat_ok;
    }

    // Not compatible
    Result = isl::Val::nan(Aff.getCtx());
    return isl_stat_error;
  });
  return Result;
}

/// Compute @p UPwAff - @p Val.
isl::UnionPwAff subtract(isl::UnionPwAff UPwAff, isl::Val Val) {
  if (Val.isZero())
    return UPwAff;

  auto Result = isl::UnionPwAff::empty(UPwAff.getSpace());
  foreachElt(UPwAff, [=, &Result](isl::PwAff PwAff) {
    auto ValAff = isl::PwAff::valOnDomain(
        isl::Set::universe(PwAff.getSpace().domain()), Val);
    auto Subtracted = PwAff.sub(ValAff);
    Result = Result.unionAdd(isl::UnionPwAff(Subtracted));
  });
  return Result;
}

/// Compute @UPwAff * @p Val.
isl::UnionPwAff multiply(isl::UnionPwAff UPwAff, isl::Val Val) {
  if (Val.isOne())
    return UPwAff;

  auto Result = isl::UnionPwAff::empty(UPwAff.getSpace());
  foreachElt(UPwAff, [=, &Result](isl::PwAff PwAff) {
    auto ValAff = isl::PwAff::valOnDomain(
        isl::Set::universe(PwAff.getSpace().domain()), Val);
    auto Multiplied = PwAff.mul(ValAff);
    Result = Result.unionAdd(Multiplied);
  });
  return Result;
}

/// Remove @p n dimensions from @p UMap's range, starting at @p first.
///
/// It is assumed that all maps in the maps have at least the necessary number
/// of out dimensions.
isl::UnionMap scheduleProjectOut(const isl::UnionMap &UMap, unsigned first,
                                 unsigned n) {
  if (n == 0)
    return UMap; /* isl_map_project_out would also reset the tuple, which should
                    have no effect on schedule ranges */

  auto Result = isl::UnionMap::empty(UMap.getSpace());
  foreachElt(UMap, [=, &Result](isl::Map Map) {
    auto Outprojected = Map.projectOut(isl::Dim::Out, first, n);
    Result = Result.addMap(Outprojected);
  });
  return Result;
}

/// Return the number of dimensions in the input map's range.
///
/// Because this function takes an isl_union_map, the out dimensions could be
/// different. We return the maximum number in this case. However, a different
/// number of dimensions is not supported by the other code in this file.
size_t scheduleScatterDims(const isl::UnionMap &Schedule) {
  unsigned Dims = 0;
  foreachElt(Schedule, [&Dims](isl::Map Map) {
    Dims = std::max(Dims, Map.dim(isl::Dim::Out));
  });
  return Dims;
}

/// Return the @p pos' range dimension, converted to an isl_union_pw_aff.
isl::UnionPwAff scheduleExtractDimAff(isl::UnionMap UMap, unsigned pos) {
  auto SingleUMap = isl::UnionMap::empty(UMap.getSpace());
  foreachElt(UMap, [=, &SingleUMap](isl::Map Map) {
    auto MapDims = Map.dim(isl::Dim::Out);
    auto SingleMap = Map.projectOut(isl::Dim::Out, 0, pos);
    SingleMap = SingleMap.projectOut(isl::Dim::Out, 1, MapDims - pos - 1);
    SingleUMap = SingleUMap.addMap(SingleMap);
  });

  auto UAff = isl::UnionPwMultiAff(SingleUMap);
  auto FirstMAff = isl::MultiUnionPwAff(UAff);
  return FirstMAff.getUnionPwAff(0);
}

/// Flatten a sequence-like first dimension.
///
/// A sequence-like scatter dimension is constant, or at least only small
/// variation, typically the result of ordering a sequence of different
/// statements. An example would be:
///   { Stmt_A[] -> [0, X, ...]; Stmt_B[] -> [1, Y, ...] }
/// to schedule all instances of Stmt_A before any instance of Stmt_B.
///
/// To flatten, first begin with an offset of zero. Then determine the lowest
/// possible value of the dimension, call it "i" [In the example we start at 0].
/// Considering only schedules with that value, consider only instances with
/// that value and determine the extent of the next dimension. Let l_X(i) and
/// u_X(i) its minimum (lower bound) and maximum (upper bound) value. Add them
/// as "Offset + X - l_X(i)" to the new schedule, then add "u_X(i) - l_X(i) + 1"
/// to Offset and remove all i-instances from the old schedule. Repeat with the
/// remaining lowest value i' until there are no instances in the old schedule
/// left.
/// The example schedule would be transformed to:
///   { Stmt_X[] -> [X - l_X, ...]; Stmt_B -> [l_X - u_X + 1 + Y - l_Y, ...] }
isl::UnionMap tryFlattenSequence(isl::UnionMap Schedule) {
  auto IslCtx = Schedule.getCtx();
  auto ScatterSet = isl::Set(Schedule.range());

  auto ParamSpace = Schedule.getSpace().params();
  auto Dims = ScatterSet.dim(isl::Dim::Set);
  assert(Dims >= 2);

  // Would cause an infinite loop.
  if (!isDimBoundedByConstant(ScatterSet, 0)) {
    DEBUG(dbgs() << "Abort; dimension is not of fixed size\n");
    return nullptr;
  }

  auto AllDomains = Schedule.domain();
  auto AllDomainsToNull = isl::UnionPwMultiAff::fromDomain(AllDomains);

  auto NewSchedule = isl::UnionMap::empty(ParamSpace);
  auto Counter = isl::PwAff::zeroOnDomain(
      isl::LocalSpace(isl::Space::setFromParams(ParamSpace)));

  while (!ScatterSet.isEmpty()) {
    DEBUG(dbgs() << "Next counter:\n  " << Counter << "\n");
    DEBUG(dbgs() << "Remaining scatter set:\n  " << ScatterSet << "\n");
    auto ThisSet = ScatterSet.projectOut(isl::Dim::Set, 1, Dims - 1);
    auto ThisFirst = ThisSet.lexmin();
    auto ScatterFirst = ThisFirst.addDims(isl::Dim::Set, Dims - 1);

    auto SubSchedule = Schedule.intersectRange(ScatterFirst);
    SubSchedule = scheduleProjectOut(SubSchedule, 0, 1);
    SubSchedule = flattenSchedule(SubSchedule);

    auto SubDims = scheduleScatterDims(SubSchedule);
    auto FirstSubSchedule = scheduleProjectOut(SubSchedule, 1, SubDims - 1);
    auto FirstScheduleAff = scheduleExtractDimAff(FirstSubSchedule, 0);
    auto RemainingSubSchedule = scheduleProjectOut(SubSchedule, 0, 1);

    auto FirstSubScatter = isl::Set(FirstSubSchedule.range());
    DEBUG(dbgs() << "Next step in sequence is:\n  " << FirstSubScatter << "\n");

    if (!isDimBoundedByParameter(FirstSubScatter, 0)) {
      DEBUG(dbgs() << "Abort; sequence step is not bounded\n");
      return nullptr;
    }

    auto FirstSubScatterMap = isl::Map::fromRange(FirstSubScatter);

    // isl_set_dim_max returns a strange isl_pw_aff with domain tuple_id of
    // 'none'. It doesn't match with any space including a 0-dimensional
    // anonymous tuple.
    // Interesting, one can create such a set using
    // isl_set_universe(ParamSpace). Bug?
    auto PartMin = FirstSubScatterMap.dimMin(0);
    auto PartMax = FirstSubScatterMap.dimMax(0);
    auto One = isl::PwAff::valOnDomain(
        isl::Set::universe(isl::Space::setFromParams(ParamSpace)),
        isl::Val::one(IslCtx));
    auto PartLen = PartMax.add(PartMin.neg()).add(One);

    auto AllPartMin = isl::UnionPwAff(PartMin).pullback(AllDomainsToNull);
    auto FirstScheduleAffNormalized = FirstScheduleAff.sub(AllPartMin);
    auto AllCounter = isl::UnionPwAff(Counter).pullback(AllDomainsToNull);
    auto FirstScheduleAffWithOffset =
        FirstScheduleAffNormalized.add(AllCounter);

    auto ScheduleWithOffset = isl::UnionMap(FirstScheduleAffWithOffset)
                                  .flatRangeProduct(RemainingSubSchedule);
    NewSchedule = NewSchedule.unite(ScheduleWithOffset);

    ScatterSet = ScatterSet.subtract(ScatterFirst);
    Counter = Counter.add(PartLen);
  }

  DEBUG(dbgs() << "Sequence-flatten result is:\n  " << NewSchedule << "\n");
  return NewSchedule;
}

/// Flatten a loop-like first dimension.
///
/// A loop-like dimension is one that depends on a variable (usually a loop's
/// induction variable). Let the input schedule look like this:
///   { Stmt[i] -> [i, X, ...] }
///
/// To flatten, we determine the largest extent of X which may not depend on the
/// actual value of i. Let l_X() the smallest possible value of X and u_X() its
/// largest value. Then, construct a new schedule
///   { Stmt[i] -> [i * (u_X() - l_X() + 1), ...] }
isl::UnionMap tryFlattenLoop(isl::UnionMap Schedule) {
  assert(scheduleScatterDims(Schedule) >= 2);

  auto Remaining = scheduleProjectOut(Schedule, 0, 1);
  auto SubSchedule = flattenSchedule(Remaining);
  auto SubDims = scheduleScatterDims(SubSchedule);

  auto SubExtent = isl::Set(SubSchedule.range());
  auto SubExtentDims = SubExtent.dim(isl::Dim::Param);
  SubExtent = SubExtent.projectOut(isl::Dim::Param, 0, SubExtentDims);
  SubExtent = SubExtent.projectOut(isl::Dim::Set, 1, SubDims - 1);

  if (!isDimBoundedByConstant(SubExtent, 0)) {
    DEBUG(dbgs() << "Abort; dimension not bounded by constant\n");
    return nullptr;
  }

  auto Min = SubExtent.dimMin(0);
  DEBUG(dbgs() << "Min bound:\n  " << Min << "\n");
  auto MinVal = getConstant(Min, false, true);
  auto Max = SubExtent.dimMax(0);
  DEBUG(dbgs() << "Max bound:\n  " << Max << "\n");
  auto MaxVal = getConstant(Max, true, false);

  if (!MinVal || !MaxVal || MinVal.isNan() || MaxVal.isNan()) {
    DEBUG(dbgs() << "Abort; dimension bounds could not be determined\n");
    return nullptr;
  }

  auto FirstSubScheduleAff = scheduleExtractDimAff(SubSchedule, 0);
  auto RemainingSubSchedule = scheduleProjectOut(std::move(SubSchedule), 0, 1);

  auto LenVal = MaxVal.sub(MinVal).addUi(1);
  auto FirstSubScheduleNormalized = subtract(FirstSubScheduleAff, MinVal);

  // TODO: Normalize FirstAff to zero (convert to isl_map, determine minimum,
  // subtract it)
  auto FirstAff = scheduleExtractDimAff(Schedule, 0);
  auto Offset = multiply(FirstAff, LenVal);
  auto Index = FirstSubScheduleNormalized.add(Offset);
  auto IndexMap = isl::UnionMap(Index);

  auto Result = IndexMap.flatRangeProduct(RemainingSubSchedule);
  DEBUG(dbgs() << "Loop-flatten result is:\n  " << Result << "\n");
  return Result;
}
} // anonymous namespace

isl::UnionMap polly::flattenSchedule(isl::UnionMap Schedule) {
  auto Dims = scheduleScatterDims(Schedule);
  DEBUG(dbgs() << "Recursive schedule to process:\n  " << Schedule << "\n");

  // Base case; no dimensions left
  if (Dims == 0) {
    // TODO: Add one dimension?
    return Schedule;
  }

  // Base case; already one-dimensional
  if (Dims == 1)
    return Schedule;

  // Fixed dimension; no need to preserve variabledness.
  if (!isVariableDim(Schedule)) {
    DEBUG(dbgs() << "Fixed dimension; try sequence flattening\n");
    auto NewScheduleSequence = tryFlattenSequence(Schedule);
    if (NewScheduleSequence)
      return NewScheduleSequence;
  }

  // Constant stride
  DEBUG(dbgs() << "Try loop flattening\n");
  auto NewScheduleLoop = tryFlattenLoop(Schedule);
  if (NewScheduleLoop)
    return NewScheduleLoop;

  // Try again without loop condition (may blow up the number of pieces!!)
  DEBUG(dbgs() << "Try sequence flattening again\n");
  auto NewScheduleSequence = tryFlattenSequence(Schedule);
  if (NewScheduleSequence)
    return NewScheduleSequence;

  // Cannot flatten
  return Schedule;
}
