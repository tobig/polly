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

#define LLVM_OSTREAM 1

#include "polly/FlattenAlgo.h"
#include "islpp/isl.h"
#include "llvm/Support/Debug.h"
#define DEBUG_TYPE "polly-flatten-algo"

using namespace polly;
using namespace llvm;
using namespace isl;

namespace polly {
UnionMap flattenScheduleIslCPP(UnionMap Schedule);

void foreachElt(const UnionMap &UMap, const std::function<void(Map Map)> &F) {
  isl_union_map_foreach_map(
      UMap.get(),
      [](__isl_take isl_map *M, void *User) -> isl_stat {
        auto &F = *static_cast<const std::function<void(Map)> *>(User);
        F(manage(M));
        return isl_stat_ok;
      },
      const_cast<void *>(static_cast<const void *>(&F)));
}

void foreachElt(const UnionPwAff &UPwAff, const std::function<void(PwAff)> &F) {
  isl_union_pw_aff_foreach_pw_aff(
      UPwAff.get(),
      [](__isl_take isl_pw_aff *Pw, void *User) -> isl_stat {
        auto &F = *static_cast<const std::function<void(PwAff)> *>(User);
        F(manage(Pw));
        return isl_stat_ok;
      },
      const_cast<void *>(static_cast<const void *>(&F)));
}

isl_stat foreachEltWithBreak(const Map &M,
                             const std::function<isl_stat(BasicMap)> &F) {
  return isl_map_foreach_basic_map(
      M.get(),
      [](__isl_take isl_basic_map *BM, void *User) -> isl_stat {
        auto &F = *static_cast<const std::function<isl_stat(BasicMap)> *>(User);
        return F(manage(BM));
      },
      const_cast<void *>(static_cast<const void *>(&F)));
}

isl_stat foreachEltWithBreak(const UnionMap &UMap,
                             const std::function<isl_stat(Map Map)> &F) {
  return isl_union_map_foreach_map(
      UMap.get(),
      [](__isl_take isl_map *M, void *User) -> isl_stat {
        auto &F = *static_cast<const std::function<isl_stat(Map M)> *>(User);
        return F(manage(M));
      },
      const_cast<void *>(static_cast<const void *>(&F)));
}

isl_stat foreachPieceWithBreak(const PwAff &PwAff,
                               const std::function<isl_stat(Set, Aff)> &F) {
  return isl_pw_aff_foreach_piece(
      PwAff.get(),
      [](__isl_take isl_set *Domain, __isl_take isl_aff *A,
         void *User) -> isl_stat {
        auto &F = *static_cast<const std::function<isl_stat(Set, Aff)> *>(User);
        return F(manage(Domain), manage(A));
      },
      const_cast<void *>(static_cast<const void *>(&F)));
}
}
namespace {

/// Whether a dimension of a set is bounded (lower and upper) by a constant,
/// i.e. there are two constants Min and Max, such that every value x of the
/// chosen dimensions is Min <= x <= Max.
bool isDimBoundedByConstant(Set Set, unsigned dim) {
  auto ParamDims = Set.dim(DimType::Param);
  Set = Set.projectOut(DimType::Param, 0, ParamDims);
  Set = Set.projectOut(DimType::Set, 0, dim);
  auto SetDims = Set.dim(DimType::Set);
  Set = Set.projectOut(DimType::Set, 1, SetDims - 1);
  return Set.isBounded();
}

/// Whether a dimension of a set is (lower and upper) bounded by a constant or
/// parameters, i.e. there are two expressions Min_p and Max_p of the parameters
/// p, such that every value x of the chosen dimensions is
/// Min_p <= x <= Max_p.
bool isDimBoundedByParameter(Set Set, unsigned dim) {
  Set = Set.projectOut(DimType::Set, 0, dim);
  auto SetDims = Set.dim(DimType::Set);
  Set = Set.projectOut(DimType::Set, 1, SetDims - 1);
  return Set.isBounded();
}

/// Whether BMap's first out-dimension is not a constant.
bool isVariableDim(const BasicMap &BMap) {
  auto FixedVal = BMap.plainGetValIfFixed(DimType::Out, 0);
  return FixedVal.isNull() || FixedVal.isNan();
}

/// Whether Map's first out dimension is no constant nor piecewise constant.
bool isVariableDim(const Map &M) {
  return foreachEltWithBreak(M, [](BasicMap BMap) -> isl_stat {
    if (isVariableDim(BMap))
      return isl_stat_error;
    return isl_stat_ok;
  });
}

/// Whether UMap's first out dimension is no (piecewise) constant.
bool isVariableDim(const UnionMap &UMap) {
  return foreachEltWithBreak(UMap, [](Map M) -> isl_stat {
    if (isVariableDim(M))
      return isl_stat_error;
    return isl_stat_ok;
  });
}

/// If @p PwAff maps to a constant, return said constant. If @p Max/@p Min, it
/// can also be a piecewise constant and it would return the minimum/maximum
/// value. Otherwise, return NaN.
Val getConstant(PwAff PwAff, bool Max, bool Min) {
  assert(!Max || !Min);
  Val Result;
  foreachPieceWithBreak(PwAff, [=, &Result](Set S, Aff A) {
    if (!Result.isNull() && Result.isNan())
      return isl_stat_ok;

    // TODO: If Min/Max, we can also determine a minimum/maximum value if
    // Set is constant-bounded.
    if (!A.isCst()) {
      Result = manage(isl_val_nan(isl_aff_get_ctx(A.get())));
      return isl_stat_error;
    }

    auto ThisVal = A.getConstantVal();
    if (Result.isNull()) {
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
    Result = manage(isl_val_nan(isl_aff_get_ctx(A.get())));
    return isl_stat_error;
  });
  return Result;
}

/// Compute @p UPwAff - @p Val.
UnionPwAff subtract(UnionPwAff UPwAff, Val Val) {
  if (Val.isZero())
    return UPwAff;

  auto Result =
      manage(isl_union_pw_aff_empty(isl_union_pw_aff_get_space(UPwAff.get())));
  foreachElt(UPwAff, [=, &Result](PwAff PwAff) {
    auto ValAff = manage(isl_pw_aff_val_on_domain(
        isl_set_universe(isl_space_domain(isl_pw_aff_get_space(PwAff.get()))),
        Val.copy()));
    auto Subtracted = PwAff.sub(ValAff);
    Result = Result.add(Subtracted);
  });
  return Result;
}

/// Compute @UPwAff * @p Val.
UnionPwAff multiply(UnionPwAff UPwAff, Val Val) {
  if (Val.isOne())
    return UPwAff;

  auto Result =
      manage(isl_union_pw_aff_empty(isl_union_pw_aff_get_space(UPwAff.get())));
  foreachElt(UPwAff, [=, &Result](PwAff PwAff) {
    auto ValAff = manage(isl_pw_aff_val_on_domain(
        isl_set_universe(isl_space_domain(isl_pw_aff_get_space(PwAff.get()))),
        Val.copy()));
    auto Multiplied = PwAff.mul(ValAff);
    Result = Result.unionAdd(Multiplied);
  });
  return Result;
}

/// Remove @p n dimensions from @p UMap's range, starting at @p first.
///
/// It is assumed that all maps in the maps have at least the necessary number
/// of out dimensions.
UnionMap scheduleProjectOut(const UnionMap &UMap, unsigned first, unsigned n) {
  if (n == 0)
    return UMap; /* isl_map_project_out would also reset the tuple, which should
                    have no effect on schedule ranges */

  auto Result =
      manage(isl_union_map_empty(isl_union_map_get_space(UMap.get())));
  foreachElt(UMap, [=, &Result](Map M) {
    auto Outprojected = M.projectOut(DimType::Out, first, n);
    Result = Result.addMap(Outprojected);
  });
  return Result;
}

/// Return the number of dimensions in the input map's range.
///
/// Because this function releases an isl_union_map, the out dimensions could be
/// different. We return the maximum number in this case. However, a different
/// number of dimensions is not supported by the other code in this file.
size_t scheduleScatterDims(const UnionMap &Schedule) {
  unsigned Dims = 0;
  foreachElt(Schedule,
             [&Dims](Map Map) { Dims = std::max(Dims, Map.dim(DimType::Out)); });
  return Dims;
}

/// Return the @p pos' range dimension, converted to an isl_union_pw_aff.
UnionPwAff scheduleExtractDimAff(UnionMap UMap, unsigned pos) {
  auto SingleUMap =
      manage(isl_union_map_empty(isl_union_map_get_space(UMap.get())));
  foreachElt(UMap, [=, &SingleUMap](Map Map) {
    auto MapDims = Map.dim(DimType::Out);
    auto SingleMap = Map.projectOut(DimType::Out, 0, pos);
    SingleMap = SingleMap.projectOut(DimType::Out, 1, MapDims - pos - 1);
    SingleUMap = SingleUMap.addMap(SingleMap);
  });

  UnionPwMultiAff UAff = UnionPwMultiAff(SingleUMap);
  MultiUnionPwAff FirstMAff = MultiUnionPwAff(UAff);
  return manage(isl_multi_union_pw_aff_get_union_pw_aff(FirstMAff.get(), 0));
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
UnionMap tryFlattenSequence(UnionMap Schedule) {
  auto IslCtx = isl_union_map_get_ctx(Schedule.get());
  Set ScatterSet = Set(Schedule.range());

  auto ParamSpace =
      manage(isl_space_params(isl_union_map_get_space(Schedule.get())));
  auto Dims = ScatterSet.dim(DimType::Set);
  assert(Dims >= 2);

  // Would cause an infinite loop.
  if (!isDimBoundedByConstant(ScatterSet, 0)) {
    DEBUG(dbgs() << "Abort; dimension is not of fixed size\n");
    return UnionMap();
  }

  auto AllDomains = Schedule.domain();
  auto AllDomainsToNull =
      manage(isl_union_pw_multi_aff_from_domain(AllDomains.release()));

  auto NewSchedule = manage(isl_union_map_empty(ParamSpace.copy()));
  auto Counter = manage(isl_pw_aff_zero_on_domain(isl_local_space_from_space(
      isl_space_set_from_params(ParamSpace.copy()))));

  while (!ScatterSet.isEmpty()) {
    DEBUG(dbgs() << "Next counter:\n  " << Counter << "\n");
    DEBUG(dbgs() << "Remaining scatter set:\n  " << ScatterSet << "\n");
    auto ThisSet = ScatterSet.projectOut(DimType::Set, 1, Dims - 1);
    auto ThisFirst = ThisSet.lexmin();
    auto ScatterFirst = ThisFirst.addDims(DimType::Set, Dims - 1);

    auto SubSchedule = Schedule.intersectRange(ScatterFirst);
    SubSchedule = scheduleProjectOut(std::move(SubSchedule), 0, 1);
    SubSchedule = flattenScheduleIslCPP(std::move(SubSchedule));

    auto SubDims = scheduleScatterDims(SubSchedule);
    auto FirstSubSchedule = scheduleProjectOut(SubSchedule, 1, SubDims - 1);
    auto FirstScheduleAff = scheduleExtractDimAff(FirstSubSchedule, 0);
    auto RemainingSubSchedule =
        scheduleProjectOut(std::move(SubSchedule), 0, 1);

    Set FirstSubScatter = Set(FirstSubSchedule.range());
    DEBUG(dbgs() << "Next step in sequence is:\n  " << FirstSubScatter << "\n");

    if (!isDimBoundedByParameter(FirstSubScatter, 0)) {
      DEBUG(dbgs() << "Abort; sequence step is not bounded\n");
      return UnionMap();
    }

    auto FirstSubScatterMap =
        manage(isl_map_from_range(FirstSubScatter.release()));

    // isl_set_dim_max returns a strange isl_pw_aff with domain tuple_id of
    // 'none'. It doesn't match with any space including a 0-dimensional
    // anonymous tuple.
    // Interesting, one can create such a set using
    // isl_set_universe(ParamSpace). Bug?
    auto PartMin = FirstSubScatterMap.dimMin(0);
    auto PartMax = FirstSubScatterMap.dimMax(0);
    auto One = manage(isl_pw_aff_val_on_domain(
        isl_set_universe(isl_space_set_from_params(ParamSpace.copy())),
        isl_val_one(IslCtx)));
    auto PartLen = PartMax.add(PartMin.neg()).add(One);

    auto AllPartMin = manage(isl_union_pw_aff_pullback_union_pw_multi_aff(
        isl_union_pw_aff_from_pw_aff(PartMin.release()),
        AllDomainsToNull.copy()));
    auto FirstScheduleAffNormalized = FirstScheduleAff.sub(AllPartMin);
    auto AllCounter = manage(isl_union_pw_aff_pullback_union_pw_multi_aff(
        isl_union_pw_aff_from_pw_aff(Counter.copy()), AllDomainsToNull.copy()));
    auto FirstScheduleAffWithOffset =
        FirstScheduleAffNormalized.add(AllCounter);

    auto ScheduleWithOffset = manage(isl_union_map_flat_range_product(
        isl_union_map_from_union_pw_aff(FirstScheduleAffWithOffset.release()),
        RemainingSubSchedule.release()));
    NewSchedule = manage(isl_union_map_union(NewSchedule.release(),
                                             ScheduleWithOffset.release()));

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
UnionMap tryFlattenLoop(UnionMap Schedule) {
  assert(scheduleScatterDims(Schedule) >= 2);

  auto Remaining = scheduleProjectOut(Schedule, 0, 1);
  auto SubSchedule = flattenScheduleIslCPP(Remaining);
  auto SubDims = scheduleScatterDims(SubSchedule);

  Set SubExtent = Set(SubSchedule.range());
  auto SubExtentDims = SubExtent.dim(DimType::Param);
  SubExtent = SubExtent.projectOut(DimType::Param, 0, SubExtentDims);
  SubExtent = SubExtent.projectOut(DimType::Set, 1, SubDims - 1);

  if (!isDimBoundedByConstant(SubExtent, 0)) {
    DEBUG(dbgs() << "Abort; dimension not bounded by constant\n");
    return UnionMap();
  }

  auto Min = SubExtent.dimMin(0);
  DEBUG(dbgs() << "Min bound:\n  " << Min << "\n");
  auto MinVal = getConstant(Min, false, true);
  auto Max = SubExtent.dimMax(0);
  DEBUG(dbgs() << "Max bound:\n  " << Max << "\n");
  auto MaxVal = getConstant(Max, true, false);

  if (MinVal.isNull() || MaxVal.isNull() || MinVal.isNan() || MaxVal.isNan()) {
    DEBUG(dbgs() << "Abort; dimension bounds could not be determined\n");
    return UnionMap();
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
  UnionMap IndexMap = UnionMap(Index);

  auto Result = IndexMap.flatRangeProduct(RemainingSubSchedule);
  DEBUG(dbgs() << "Loop-flatten result is:\n  " << Result << "\n");
  return Result;
}
} // anonymous namespace

IslPtr<isl_union_map> polly::flattenSchedule(IslPtr<isl_union_map> Schedule) {
  return give(flattenScheduleIslCPP(manage(Schedule.copy())).release());
}

UnionMap polly::flattenScheduleIslCPP(UnionMap Schedule) {
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
    if (!NewScheduleSequence.isNull())
      return NewScheduleSequence;
  }

  // Constant stride
  DEBUG(dbgs() << "Try loop flattening\n");
  auto NewScheduleLoop = tryFlattenLoop(Schedule);
  if (!NewScheduleLoop.isNull())
    return NewScheduleLoop;

  // Try again without loop condition (may blow up the number of pieces!!)
  DEBUG(dbgs() << "Try sequence flattening again\n");
  auto NewScheduleSequence = tryFlattenSequence(Schedule);
  if (!NewScheduleSequence.isNull())
    return NewScheduleSequence;

  // Cannot flatten
  return Schedule;
}
