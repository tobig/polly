/// These are automatically generated C++ bindings for isl.
///
///
/// isl is a library for computing with integer sets and maps described by
/// Presburger formula. On top of this, isl provides various tools for
/// Polyhedral compilation ranging from dependence analysis over scheduling
/// to AST generation.
///
///
/// WARNING: Even though these bindings have been throughly tested and the
///          design has been reviewed by various members of the isl community,
///          we do not yet provide any stability guarantees for this interface.
///          We do not expect any larger changes to the interface, but want to
///          reserve the freedom to improve the bindings based on insights that
///          only become visible after shipping these bindings with isl itself.

#include <isl/val.h>
#include <isl/aff.h>
#include <isl/set.h>
#include <isl/map.h>
#include <isl/ilp.h>
#include <isl/union_set.h>
#include <isl/union_map.h>
#include <isl/flow.h>
#include <isl/schedule.h>
#include <isl/schedule_node.h>
#include <isl/ast_build.h>
#include <assert.h>
#include <utility>
#include <string>

#ifndef ISL_CPP_ALL
#define ISL_CPP_ALL

namespace isl {

// forward declarations
class Aff;
class AstBuild;
class AstExpr;
class AstNode;
class BasicMap;
class BasicSet;
class Map;
class MultiAff;
class MultiPwAff;
class MultiUnionPwAff;
class MultiVal;
class Point;
class PwAff;
class PwMultiAff;
class Schedule;
class ScheduleConstraints;
class ScheduleNode;
class Set;
class Space;
class UnionAccessInfo;
class UnionFlow;
class UnionMap;
class UnionPwAff;
class UnionPwMultiAff;
class UnionSet;
class Val;

#define STRINGIZE_(X) #X
#define STRINGIZE(X) STRINGIZE_(X)

#define ISLPP_ASSERT(test, message)                                            \
  do {                                                                         \
    if (test)                                                                  \
      break;                                                                   \
    fputs("Assertion \"" #test "\" failed at " __FILE__                        \
          ":" STRINGIZE(__LINE__) "\n  " message "\n",                         \
          stderr);                                                             \
  } while (0)

class Bool {
private:
  friend Bool manage(isl_bool Val);

  enum class internal_t {
    False = isl_bool_false,
    True = isl_bool_true,
    Error = isl_bool_error
  };
  internal_t Val;

  /* implicit */ Bool(internal_t Val) : Val(Val) {}
  explicit Bool(isl_bool Val) : Val(static_cast<internal_t>(Val)) {}

public:
  Bool() : Val(internal_t::Error) {}
  /* implicit */ Bool(bool Val)
      : Val(Val ? internal_t::True : internal_t::False) {}

  bool isError() const { return Val == internal_t::Error; }
  bool isFalseOrError() const { return Val != internal_t::True; }
  bool isTrueOrError() const { return Val != internal_t::False; }
  bool isNoError() const { return Val != internal_t::Error; }
  bool isFalseNoError() const { return Val == internal_t::False; }
  bool isTrueNoError() const { return Val == internal_t::True; }

  explicit operator bool() const {
    ISLPP_ASSERT(isNoError(), "IMPLEMENTATION ERROR: Unhandled error state");
    return isTrueNoError();
  }

  Bool operator!() const {
    if (isError())
      return Bool();
    return !isTrueNoError();
  }
};

inline Bool manage(isl_bool Val) { return Bool(Val); }
class Ctx {
  isl_ctx *ptr;
public:
  Ctx(__isl_keep isl_ctx *ctx) : ptr(ctx) {}
  __isl_keep isl_ctx *release() { return ptr; }
};

enum class DimType {
  Cst   =  isl_dim_cst,
  Param = isl_dim_param,
  In    = isl_dim_in,
  Out   = isl_dim_out,
  Set   = isl_dim_set,
  Div   = isl_dim_div,
  All   = isl_dim_all
};

// declarations for isl::Aff
inline Aff manage(__isl_take isl_aff *ptr);

class Aff {
  friend inline Aff manage(__isl_take isl_aff *ptr);

  isl_aff *ptr = nullptr;

  inline explicit Aff(__isl_take isl_aff *ptr);

public:
  inline Aff();
  inline Aff(const Aff &obj);
  static inline Aff readFromStr(Ctx ctx, std::string str);
  inline Aff& operator=(Aff obj);
  inline ~Aff();
  inline __isl_give isl_aff *copy() const &;
  inline __isl_give isl_aff *copy() && = delete;
  inline __isl_keep isl_aff *get() const;
  inline __isl_give isl_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Aff& add(Aff aff2);
  inline Val getConstantVal() const;
  inline Bool isCst() const;
  inline Aff& pullback(MultiAff ma);
};

// declarations for isl::AstBuild
inline AstBuild manage(__isl_take isl_ast_build *ptr);

class AstBuild {
  friend inline AstBuild manage(__isl_take isl_ast_build *ptr);

  isl_ast_build *ptr = nullptr;

  inline explicit AstBuild(__isl_take isl_ast_build *ptr);

public:
  inline AstBuild();
  inline AstBuild(const AstBuild &obj);
  static inline AstBuild alloc(Ctx ctx);
  inline AstBuild& operator=(AstBuild obj);
  inline ~AstBuild();
  inline __isl_give isl_ast_build *copy() const &;
  inline __isl_give isl_ast_build *copy() && = delete;
  inline __isl_keep isl_ast_build *get() const;
  inline __isl_give isl_ast_build *release();
  inline bool isNull() const;
  inline AstExpr accessFrom(PwMultiAff pma) const;
  inline AstExpr accessFrom(MultiPwAff mpa) const;
  inline AstExpr callFrom(PwMultiAff pma) const;
  inline AstExpr callFrom(MultiPwAff mpa) const;
  inline AstExpr exprFrom(Set set) const;
  inline AstExpr exprFrom(PwAff pa) const;
  static inline AstBuild fromContext(Set set);
  inline AstNode nodeFromScheduleMap(UnionMap schedule) const;
};

// declarations for isl::AstExpr
inline AstExpr manage(__isl_take isl_ast_expr *ptr);

class AstExpr {
  friend inline AstExpr manage(__isl_take isl_ast_expr *ptr);

  isl_ast_expr *ptr = nullptr;

  inline explicit AstExpr(__isl_take isl_ast_expr *ptr);

public:
  inline AstExpr();
  inline AstExpr(const AstExpr &obj);
  inline AstExpr& operator=(AstExpr obj);
  inline ~AstExpr();
  inline __isl_give isl_ast_expr *copy() const &;
  inline __isl_give isl_ast_expr *copy() && = delete;
  inline __isl_keep isl_ast_expr *get() const;
  inline __isl_give isl_ast_expr *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline std::string toCStr() const;
};

// declarations for isl::AstNode
inline AstNode manage(__isl_take isl_ast_node *ptr);

class AstNode {
  friend inline AstNode manage(__isl_take isl_ast_node *ptr);

  isl_ast_node *ptr = nullptr;

  inline explicit AstNode(__isl_take isl_ast_node *ptr);

public:
  inline AstNode();
  inline AstNode(const AstNode &obj);
  inline AstNode& operator=(AstNode obj);
  inline ~AstNode();
  inline __isl_give isl_ast_node *copy() const &;
  inline __isl_give isl_ast_node *copy() && = delete;
  inline __isl_keep isl_ast_node *get() const;
  inline __isl_give isl_ast_node *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline std::string toCStr() const;
};

// declarations for isl::BasicMap
inline BasicMap manage(__isl_take isl_basic_map *ptr);

class BasicMap {
  friend inline BasicMap manage(__isl_take isl_basic_map *ptr);

  isl_basic_map *ptr = nullptr;

  inline explicit BasicMap(__isl_take isl_basic_map *ptr);

public:
  inline BasicMap();
  inline BasicMap(const BasicMap &obj);
  static inline BasicMap readFromStr(Ctx ctx, std::string str);
  inline BasicMap& operator=(BasicMap obj);
  inline ~BasicMap();
  inline __isl_give isl_basic_map *copy() const &;
  inline __isl_give isl_basic_map *copy() && = delete;
  inline __isl_keep isl_basic_map *get() const;
  inline __isl_give isl_basic_map *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline BasicMap& affineHull();
  inline BasicMap& applyDomain(BasicMap bmap2);
  inline BasicMap& applyRange(BasicMap bmap2);
  inline BasicSet deltas() const;
  inline BasicMap& detectEqualities();
  inline BasicMap& flatten();
  inline BasicMap& flattenDomain();
  inline BasicMap& flattenRange();
  inline BasicMap& gist(BasicMap context);
  inline BasicMap& intersect(BasicMap bmap2);
  inline BasicMap& intersectDomain(BasicSet bset);
  inline BasicMap& intersectRange(BasicSet bset);
  inline Bool isEmpty() const;
  inline Bool isEqual(const BasicMap &bmap2) const;
  inline Bool isSubset(const BasicMap &bmap2) const;
  inline Map lexmax() const;
  inline Map lexmin() const;
  inline Val plainGetValIfFixed(enum DimType type, unsigned int pos) const;
  inline BasicMap& projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline BasicMap& reverse();
  inline BasicMap& sample();
  inline Map unite(BasicMap bmap2) const;
};

// declarations for isl::BasicSet
inline BasicSet manage(__isl_take isl_basic_set *ptr);

class BasicSet {
  friend inline BasicSet manage(__isl_take isl_basic_set *ptr);

  isl_basic_set *ptr = nullptr;

  inline explicit BasicSet(__isl_take isl_basic_set *ptr);

public:
  inline BasicSet();
  inline BasicSet(const BasicSet &obj);
  static inline BasicSet readFromStr(Ctx ctx, std::string str);
  inline /* implicit */ BasicSet(Point obj);
  inline BasicSet& operator=(BasicSet obj);
  inline ~BasicSet();
  inline __isl_give isl_basic_set *copy() const &;
  inline __isl_give isl_basic_set *copy() && = delete;
  inline __isl_keep isl_basic_set *get() const;
  inline __isl_give isl_basic_set *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline BasicSet& affineHull();
  inline BasicSet& apply(BasicMap bmap);
  inline BasicSet& detectEqualities();
  inline BasicSet& flatten();
  inline BasicSet& gist(BasicSet context);
  inline BasicSet& intersect(BasicSet bset2);
  inline BasicSet& intersectParams(BasicSet bset2);
  inline int isBounded() const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const BasicSet &bset2) const;
  inline Bool isSubset(const BasicSet &bset2) const;
  inline Bool isWrapping() const;
  inline Set lexmax() const;
  inline Set lexmin() const;
  inline BasicSet& projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline BasicSet& sample();
  inline Point samplePoint() const;
  inline Set unite(BasicSet bset2) const;
};

// declarations for isl::Map
inline Map manage(__isl_take isl_map *ptr);

class Map {
  friend inline Map manage(__isl_take isl_map *ptr);

  isl_map *ptr = nullptr;

  inline explicit Map(__isl_take isl_map *ptr);

public:
  inline Map();
  inline Map(const Map &obj);
  static inline Map readFromStr(Ctx ctx, std::string str);
  inline /* implicit */ Map(BasicMap obj);
  inline Map& operator=(Map obj);
  inline ~Map();
  inline __isl_give isl_map *copy() const &;
  inline __isl_give isl_map *copy() && = delete;
  inline __isl_keep isl_map *get() const;
  inline __isl_give isl_map *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline BasicMap affineHull() const;
  inline Map& applyDomain(Map map2);
  inline Map& applyRange(Map map2);
  inline Map& coalesce();
  inline Map& complement();
  inline Set deltas() const;
  inline Map& detectEqualities();
  inline unsigned int dim(enum DimType type) const;
  inline PwAff dimMax(int pos) const;
  inline PwAff dimMin(int pos) const;
  inline Map& flatten();
  inline Map& flattenDomain();
  inline Map& flattenRange();
  inline Map& gist(Map context);
  inline Map& gistDomain(Set context);
  inline Map& intersect(Map map2);
  inline Map& intersectDomain(Set set);
  inline Map& intersectParams(Set params);
  inline Map& intersectRange(Set set);
  inline Bool isBijective() const;
  inline Bool isDisjoint(const Map &map2) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const Map &map2) const;
  inline Bool isInjective() const;
  inline Bool isSingleValued() const;
  inline Bool isStrictSubset(const Map &map2) const;
  inline Bool isSubset(const Map &map2) const;
  inline Map& lexmax();
  inline Map& lexmin();
  inline BasicMap polyhedralHull() const;
  inline Map& projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline Map& reverse();
  inline BasicMap sample() const;
  inline Map& subtract(Map map2);
  inline Map& unite(Map map2);
  inline BasicMap unshiftedSimpleHull() const;
};

// declarations for isl::MultiAff
inline MultiAff manage(__isl_take isl_multi_aff *ptr);

class MultiAff {
  friend inline MultiAff manage(__isl_take isl_multi_aff *ptr);

  isl_multi_aff *ptr = nullptr;

  inline explicit MultiAff(__isl_take isl_multi_aff *ptr);

public:
  inline MultiAff();
  inline MultiAff(const MultiAff &obj);
  inline /* implicit */ MultiAff(Aff obj);
  static inline MultiAff readFromStr(Ctx ctx, std::string str);
  inline MultiAff& operator=(MultiAff obj);
  inline ~MultiAff();
  inline __isl_give isl_multi_aff *copy() const &;
  inline __isl_give isl_multi_aff *copy() && = delete;
  inline __isl_keep isl_multi_aff *get() const;
  inline __isl_give isl_multi_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiAff& add(MultiAff multi2);
  inline MultiAff& flatRangeProduct(MultiAff multi2);
  inline MultiAff& product(MultiAff multi2);
  inline MultiAff& pullback(MultiAff ma2);
  inline MultiAff& rangeProduct(MultiAff multi2);
};

// declarations for isl::MultiPwAff
inline MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr);

class MultiPwAff {
  friend inline MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr);

  isl_multi_pw_aff *ptr = nullptr;

  inline explicit MultiPwAff(__isl_take isl_multi_pw_aff *ptr);

public:
  inline MultiPwAff();
  inline MultiPwAff(const MultiPwAff &obj);
  inline /* implicit */ MultiPwAff(MultiAff obj);
  inline /* implicit */ MultiPwAff(PwAff obj);
  inline /* implicit */ MultiPwAff(PwMultiAff obj);
  static inline MultiPwAff readFromStr(Ctx ctx, std::string str);
  inline MultiPwAff& operator=(MultiPwAff obj);
  inline ~MultiPwAff();
  inline __isl_give isl_multi_pw_aff *copy() const &;
  inline __isl_give isl_multi_pw_aff *copy() && = delete;
  inline __isl_keep isl_multi_pw_aff *get() const;
  inline __isl_give isl_multi_pw_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiPwAff& add(MultiPwAff multi2);
  inline MultiPwAff& flatRangeProduct(MultiPwAff multi2);
  inline MultiPwAff& product(MultiPwAff multi2);
  inline MultiPwAff& pullback(MultiAff ma);
  inline MultiPwAff& pullback(PwMultiAff pma);
  inline MultiPwAff& pullback(MultiPwAff mpa2);
  inline MultiPwAff& rangeProduct(MultiPwAff multi2);
};

// declarations for isl::MultiUnionPwAff
inline MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr);

class MultiUnionPwAff {
  friend inline MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr);

  isl_multi_union_pw_aff *ptr = nullptr;

  inline explicit MultiUnionPwAff(__isl_take isl_multi_union_pw_aff *ptr);

public:
  inline MultiUnionPwAff();
  inline MultiUnionPwAff(const MultiUnionPwAff &obj);
  inline /* implicit */ MultiUnionPwAff(UnionPwAff obj);
  inline /* implicit */ MultiUnionPwAff(MultiPwAff obj);
  inline explicit MultiUnionPwAff(UnionPwMultiAff obj);
  static inline MultiUnionPwAff readFromStr(Ctx ctx, std::string str);
  inline MultiUnionPwAff& operator=(MultiUnionPwAff obj);
  inline ~MultiUnionPwAff();
  inline __isl_give isl_multi_union_pw_aff *copy() const &;
  inline __isl_give isl_multi_union_pw_aff *copy() && = delete;
  inline __isl_keep isl_multi_union_pw_aff *get() const;
  inline __isl_give isl_multi_union_pw_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiUnionPwAff& add(MultiUnionPwAff multi2);
  inline MultiUnionPwAff& flatRangeProduct(MultiUnionPwAff multi2);
  inline MultiUnionPwAff& pullback(UnionPwMultiAff upma);
  inline MultiUnionPwAff& rangeProduct(MultiUnionPwAff multi2);
  inline MultiUnionPwAff& unionAdd(MultiUnionPwAff mupa2);
};

// declarations for isl::MultiVal
inline MultiVal manage(__isl_take isl_multi_val *ptr);

class MultiVal {
  friend inline MultiVal manage(__isl_take isl_multi_val *ptr);

  isl_multi_val *ptr = nullptr;

  inline explicit MultiVal(__isl_take isl_multi_val *ptr);

public:
  inline MultiVal();
  inline MultiVal(const MultiVal &obj);
  inline MultiVal& operator=(MultiVal obj);
  inline ~MultiVal();
  inline __isl_give isl_multi_val *copy() const &;
  inline __isl_give isl_multi_val *copy() && = delete;
  inline __isl_keep isl_multi_val *get() const;
  inline __isl_give isl_multi_val *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiVal& add(MultiVal multi2);
  inline MultiVal& flatRangeProduct(MultiVal multi2);
  inline MultiVal& product(MultiVal multi2);
  inline MultiVal& rangeProduct(MultiVal multi2);
};

// declarations for isl::Point
inline Point manage(__isl_take isl_point *ptr);

class Point {
  friend inline Point manage(__isl_take isl_point *ptr);

  isl_point *ptr = nullptr;

  inline explicit Point(__isl_take isl_point *ptr);

public:
  inline Point();
  inline Point(const Point &obj);
  inline Point& operator=(Point obj);
  inline ~Point();
  inline __isl_give isl_point *copy() const &;
  inline __isl_give isl_point *copy() && = delete;
  inline __isl_keep isl_point *get() const;
  inline __isl_give isl_point *release();
  inline bool isNull() const;
  inline std::string getStr() const;
};

// declarations for isl::PwAff
inline PwAff manage(__isl_take isl_pw_aff *ptr);

class PwAff {
  friend inline PwAff manage(__isl_take isl_pw_aff *ptr);

  isl_pw_aff *ptr = nullptr;

  inline explicit PwAff(__isl_take isl_pw_aff *ptr);

public:
  inline PwAff();
  inline PwAff(const PwAff &obj);
  inline /* implicit */ PwAff(Aff obj);
  static inline PwAff readFromStr(Ctx ctx, std::string str);
  inline PwAff& operator=(PwAff obj);
  inline ~PwAff();
  inline __isl_give isl_pw_aff *copy() const &;
  inline __isl_give isl_pw_aff *copy() && = delete;
  inline __isl_keep isl_pw_aff *get() const;
  inline __isl_give isl_pw_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline PwAff& add(PwAff pwaff2);
  inline PwAff& mul(PwAff pwaff2);
  inline PwAff& neg();
  inline PwAff& pullback(MultiAff ma);
  inline PwAff& pullback(PwMultiAff pma);
  inline PwAff& pullback(MultiPwAff mpa);
  inline PwAff& sub(PwAff pwaff2);
  inline PwAff& unionAdd(PwAff pwaff2);
};

// declarations for isl::PwMultiAff
inline PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr);

class PwMultiAff {
  friend inline PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr);

  isl_pw_multi_aff *ptr = nullptr;

  inline explicit PwMultiAff(__isl_take isl_pw_multi_aff *ptr);

public:
  inline PwMultiAff();
  inline PwMultiAff(const PwMultiAff &obj);
  inline /* implicit */ PwMultiAff(MultiAff obj);
  inline /* implicit */ PwMultiAff(PwAff obj);
  static inline PwMultiAff readFromStr(Ctx ctx, std::string str);
  inline PwMultiAff& operator=(PwMultiAff obj);
  inline ~PwMultiAff();
  inline __isl_give isl_pw_multi_aff *copy() const &;
  inline __isl_give isl_pw_multi_aff *copy() && = delete;
  inline __isl_keep isl_pw_multi_aff *get() const;
  inline __isl_give isl_pw_multi_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline PwMultiAff& add(PwMultiAff pma2);
  inline PwMultiAff& flatRangeProduct(PwMultiAff pma2);
  inline PwMultiAff& product(PwMultiAff pma2);
  inline PwMultiAff& pullback(MultiAff ma);
  inline PwMultiAff& pullback(PwMultiAff pma2);
  inline PwMultiAff& rangeProduct(PwMultiAff pma2);
  inline PwMultiAff& unionAdd(PwMultiAff pma2);
};

// declarations for isl::Schedule
inline Schedule manage(__isl_take isl_schedule *ptr);

class Schedule {
  friend inline Schedule manage(__isl_take isl_schedule *ptr);

  isl_schedule *ptr = nullptr;

  inline explicit Schedule(__isl_take isl_schedule *ptr);

public:
  inline Schedule();
  inline Schedule(const Schedule &obj);
  static inline Schedule readFromStr(Ctx ctx, std::string str);
  inline Schedule& operator=(Schedule obj);
  inline ~Schedule();
  inline __isl_give isl_schedule *copy() const &;
  inline __isl_give isl_schedule *copy() && = delete;
  inline __isl_keep isl_schedule *get() const;
  inline __isl_give isl_schedule *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionMap getMap() const;
  inline ScheduleNode getRoot() const;
  inline Schedule& pullback(UnionPwMultiAff upma);
};

// declarations for isl::ScheduleConstraints
inline ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr);

class ScheduleConstraints {
  friend inline ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr);

  isl_schedule_constraints *ptr = nullptr;

  inline explicit ScheduleConstraints(__isl_take isl_schedule_constraints *ptr);

public:
  inline ScheduleConstraints();
  inline ScheduleConstraints(const ScheduleConstraints &obj);
  static inline ScheduleConstraints readFromStr(Ctx ctx, std::string str);
  inline ScheduleConstraints& operator=(ScheduleConstraints obj);
  inline ~ScheduleConstraints();
  inline __isl_give isl_schedule_constraints *copy() const &;
  inline __isl_give isl_schedule_constraints *copy() && = delete;
  inline __isl_keep isl_schedule_constraints *get() const;
  inline __isl_give isl_schedule_constraints *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionMap getCoincidence() const;
  inline UnionMap getConditionalValidity() const;
  inline UnionMap getConditionalValidityCondition() const;
  inline Set getContext() const;
  inline UnionSet getDomain() const;
  inline UnionMap getProximity() const;
  inline UnionMap getValidity() const;
};

// declarations for isl::ScheduleNode
inline ScheduleNode manage(__isl_take isl_schedule_node *ptr);

class ScheduleNode {
  friend inline ScheduleNode manage(__isl_take isl_schedule_node *ptr);

  isl_schedule_node *ptr = nullptr;

  inline explicit ScheduleNode(__isl_take isl_schedule_node *ptr);

public:
  inline ScheduleNode();
  inline ScheduleNode(const ScheduleNode &obj);
  inline ScheduleNode& operator=(ScheduleNode obj);
  inline ~ScheduleNode();
  inline __isl_give isl_schedule_node *copy() const &;
  inline __isl_give isl_schedule_node *copy() && = delete;
  inline __isl_keep isl_schedule_node *get() const;
  inline __isl_give isl_schedule_node *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Bool bandMemberGetCoincident(int pos) const;
  inline ScheduleNode& bandMemberSetCoincident(int pos, int coincident);
  inline ScheduleNode& child(int pos);
  inline MultiUnionPwAff getPrefixScheduleMultiUnionPwAff() const;
  inline UnionMap getPrefixScheduleUnionMap() const;
  inline UnionPwMultiAff getPrefixScheduleUnionPwMultiAff() const;
  inline Schedule getSchedule() const;
  inline ScheduleNode& parent();
};

// declarations for isl::Set
inline Set manage(__isl_take isl_set *ptr);

class Set {
  friend inline Set manage(__isl_take isl_set *ptr);

  isl_set *ptr = nullptr;

  inline explicit Set(__isl_take isl_set *ptr);

public:
  inline Set();
  inline Set(const Set &obj);
  inline explicit Set(UnionSet obj);
  static inline Set readFromStr(Ctx ctx, std::string str);
  inline /* implicit */ Set(BasicSet obj);
  inline /* implicit */ Set(Point obj);
  inline Set& operator=(Set obj);
  inline ~Set();
  inline __isl_give isl_set *copy() const &;
  inline __isl_give isl_set *copy() && = delete;
  inline __isl_keep isl_set *get() const;
  inline __isl_give isl_set *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Set& addDims(enum DimType type, unsigned int n);
  inline BasicSet affineHull() const;
  inline Set& apply(Map map);
  inline Set& coalesce();
  inline Set& complement();
  inline Set& detectEqualities();
  inline unsigned int dim(enum DimType type) const;
  inline PwAff dimMax(int pos) const;
  inline PwAff dimMin(int pos) const;
  inline Set& flatten();
  inline Set& gist(Set context);
  inline Map identity() const;
  inline Set& intersect(Set set2);
  inline Set& intersectParams(Set params);
  inline int isBounded() const;
  inline Bool isDisjoint(const Set &set2) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const Set &set2) const;
  inline Bool isStrictSubset(const Set &set2) const;
  inline Bool isSubset(const Set &set2) const;
  inline Bool isWrapping() const;
  inline Set& lexmax();
  inline Set& lexmin();
  inline Val maxVal(const Aff &obj) const;
  inline Val minVal(const Aff &obj) const;
  inline BasicSet polyhedralHull() const;
  inline Set& projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline BasicSet sample() const;
  inline Point samplePoint() const;
  inline Set& subtract(Set set2);
  inline Set& unite(Set set2);
  inline BasicSet unshiftedSimpleHull() const;
};

// declarations for isl::Space
inline Space manage(__isl_take isl_space *ptr);

class Space {
  friend inline Space manage(__isl_take isl_space *ptr);

  isl_space *ptr = nullptr;

  inline explicit Space(__isl_take isl_space *ptr);

public:
  inline Space();
  inline Space(const Space &obj);
  inline Space& operator=(Space obj);
  inline ~Space();
  inline __isl_give isl_space *copy() const &;
  inline __isl_give isl_space *copy() && = delete;
  inline __isl_keep isl_space *get() const;
  inline __isl_give isl_space *release();
  inline bool isNull() const;
  inline std::string getStr() const;
};

// declarations for isl::UnionAccessInfo
inline UnionAccessInfo manage(__isl_take isl_union_access_info *ptr);

class UnionAccessInfo {
  friend inline UnionAccessInfo manage(__isl_take isl_union_access_info *ptr);

  isl_union_access_info *ptr = nullptr;

  inline explicit UnionAccessInfo(__isl_take isl_union_access_info *ptr);

public:
  inline UnionAccessInfo();
  inline UnionAccessInfo(const UnionAccessInfo &obj);
  inline explicit UnionAccessInfo(UnionMap obj);
  inline UnionAccessInfo& operator=(UnionAccessInfo obj);
  inline ~UnionAccessInfo();
  inline __isl_give isl_union_access_info *copy() const &;
  inline __isl_give isl_union_access_info *copy() && = delete;
  inline __isl_keep isl_union_access_info *get() const;
  inline __isl_give isl_union_access_info *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionFlow computeFlow() const;
  inline UnionAccessInfo& setMaySource(UnionMap may_source);
  inline UnionAccessInfo& setMustSource(UnionMap must_source);
  inline UnionAccessInfo& setSchedule(Schedule schedule);
  inline UnionAccessInfo& setScheduleMap(UnionMap schedule_map);
};

// declarations for isl::UnionFlow
inline UnionFlow manage(__isl_take isl_union_flow *ptr);

class UnionFlow {
  friend inline UnionFlow manage(__isl_take isl_union_flow *ptr);

  isl_union_flow *ptr = nullptr;

  inline explicit UnionFlow(__isl_take isl_union_flow *ptr);

public:
  inline UnionFlow();
  inline UnionFlow(const UnionFlow &obj);
  inline UnionFlow& operator=(UnionFlow obj);
  inline ~UnionFlow();
  inline __isl_give isl_union_flow *copy() const &;
  inline __isl_give isl_union_flow *copy() && = delete;
  inline __isl_keep isl_union_flow *get() const;
  inline __isl_give isl_union_flow *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionMap getFullMayDependence() const;
  inline UnionMap getFullMustDependence() const;
  inline UnionMap getMayDependence() const;
  inline UnionMap getMayNoSource() const;
  inline UnionMap getMustDependence() const;
  inline UnionMap getMustNoSource() const;
};

// declarations for isl::UnionMap
inline UnionMap manage(__isl_take isl_union_map *ptr);

class UnionMap {
  friend inline UnionMap manage(__isl_take isl_union_map *ptr);

  isl_union_map *ptr = nullptr;

  inline explicit UnionMap(__isl_take isl_union_map *ptr);

public:
  inline UnionMap();
  inline UnionMap(const UnionMap &obj);
  inline explicit UnionMap(UnionPwAff obj);
  inline /* implicit */ UnionMap(BasicMap obj);
  inline /* implicit */ UnionMap(Map obj);
  static inline UnionMap readFromStr(Ctx ctx, std::string str);
  inline UnionMap& operator=(UnionMap obj);
  inline ~UnionMap();
  inline __isl_give isl_union_map *copy() const &;
  inline __isl_give isl_union_map *copy() && = delete;
  inline __isl_keep isl_union_map *get() const;
  inline __isl_give isl_union_map *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionMap& addMap(Map map);
  inline UnionMap& affineHull();
  inline UnionMap& applyDomain(UnionMap umap2);
  inline UnionMap& applyRange(UnionMap umap2);
  inline UnionMap& coalesce();
  inline UnionMap& computeDivs();
  inline UnionSet deltas() const;
  inline UnionMap& detectEqualities();
  inline UnionSet domain() const;
  inline UnionMap& domainFactorDomain();
  inline UnionMap& domainFactorRange();
  inline UnionMap& domainMap();
  inline UnionPwMultiAff domainMapUnionPwMultiAff() const;
  inline UnionMap& domainProduct(UnionMap umap2);
  inline UnionMap& factorDomain();
  inline UnionMap& factorRange();
  inline UnionMap& fixedPower(Val exp);
  inline UnionMap& flatRangeProduct(UnionMap umap2);
  static inline UnionMap from(UnionPwMultiAff upma);
  static inline UnionMap from(MultiUnionPwAff mupa);
  static inline UnionMap fromDomainAndRange(UnionSet domain, UnionSet range);
  inline UnionMap& gist(UnionMap context);
  inline UnionMap& gistDomain(UnionSet uset);
  inline UnionMap& gistParams(Set set);
  inline UnionMap& gistRange(UnionSet uset);
  inline UnionMap& intersect(UnionMap umap2);
  inline UnionMap& intersectDomain(UnionSet uset);
  inline UnionMap& intersectParams(Set set);
  inline UnionMap& intersectRange(UnionSet uset);
  inline Bool isBijective() const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const UnionMap &umap2) const;
  inline Bool isInjective() const;
  inline Bool isSingleValued() const;
  inline Bool isStrictSubset(const UnionMap &umap2) const;
  inline Bool isSubset(const UnionMap &umap2) const;
  inline UnionMap& lexmax();
  inline UnionMap& lexmin();
  inline UnionMap& polyhedralHull();
  inline UnionMap& product(UnionMap umap2);
  inline UnionSet range() const;
  inline UnionMap& rangeFactorDomain();
  inline UnionMap& rangeFactorRange();
  inline UnionMap& rangeMap();
  inline UnionMap& rangeProduct(UnionMap umap2);
  inline UnionMap& reverse();
  inline UnionMap& subtract(UnionMap umap2);
  inline UnionMap& subtractDomain(UnionSet dom);
  inline UnionMap& subtractRange(UnionSet dom);
  inline UnionMap& unite(UnionMap umap2);
  inline UnionSet wrap() const;
  inline UnionMap& zip();
};

// declarations for isl::UnionPwAff
inline UnionPwAff manage(__isl_take isl_union_pw_aff *ptr);

class UnionPwAff {
  friend inline UnionPwAff manage(__isl_take isl_union_pw_aff *ptr);

  isl_union_pw_aff *ptr = nullptr;

  inline explicit UnionPwAff(__isl_take isl_union_pw_aff *ptr);

public:
  inline UnionPwAff();
  inline UnionPwAff(const UnionPwAff &obj);
  inline /* implicit */ UnionPwAff(PwAff obj);
  static inline UnionPwAff readFromStr(Ctx ctx, std::string str);
  inline UnionPwAff& operator=(UnionPwAff obj);
  inline ~UnionPwAff();
  inline __isl_give isl_union_pw_aff *copy() const &;
  inline __isl_give isl_union_pw_aff *copy() && = delete;
  inline __isl_keep isl_union_pw_aff *get() const;
  inline __isl_give isl_union_pw_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionPwAff& add(UnionPwAff upa2);
  inline UnionPwAff& pullback(UnionPwMultiAff upma);
  inline UnionPwAff& sub(UnionPwAff upa2);
  inline UnionPwAff& unionAdd(UnionPwAff upa2);
};

// declarations for isl::UnionPwMultiAff
inline UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr);

class UnionPwMultiAff {
  friend inline UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr);

  isl_union_pw_multi_aff *ptr = nullptr;

  inline explicit UnionPwMultiAff(__isl_take isl_union_pw_multi_aff *ptr);

public:
  inline UnionPwMultiAff();
  inline UnionPwMultiAff(const UnionPwMultiAff &obj);
  inline explicit UnionPwMultiAff(UnionMap obj);
  static inline UnionPwMultiAff readFromStr(Ctx ctx, std::string str);
  inline /* implicit */ UnionPwMultiAff(UnionPwAff obj);
  inline /* implicit */ UnionPwMultiAff(PwMultiAff obj);
  inline UnionPwMultiAff& operator=(UnionPwMultiAff obj);
  inline ~UnionPwMultiAff();
  inline __isl_give isl_union_pw_multi_aff *copy() const &;
  inline __isl_give isl_union_pw_multi_aff *copy() && = delete;
  inline __isl_keep isl_union_pw_multi_aff *get() const;
  inline __isl_give isl_union_pw_multi_aff *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionPwMultiAff& add(UnionPwMultiAff upma2);
  inline UnionPwMultiAff& flatRangeProduct(UnionPwMultiAff upma2);
  inline UnionPwMultiAff& pullback(UnionPwMultiAff upma2);
  inline UnionPwMultiAff& unionAdd(UnionPwMultiAff upma2);
};

// declarations for isl::UnionSet
inline UnionSet manage(__isl_take isl_union_set *ptr);

class UnionSet {
  friend inline UnionSet manage(__isl_take isl_union_set *ptr);

  isl_union_set *ptr = nullptr;

  inline explicit UnionSet(__isl_take isl_union_set *ptr);

public:
  inline UnionSet();
  inline UnionSet(const UnionSet &obj);
  inline /* implicit */ UnionSet(BasicSet obj);
  inline /* implicit */ UnionSet(Set obj);
  inline /* implicit */ UnionSet(Point obj);
  static inline UnionSet readFromStr(Ctx ctx, std::string str);
  inline UnionSet& operator=(UnionSet obj);
  inline ~UnionSet();
  inline __isl_give isl_union_set *copy() const &;
  inline __isl_give isl_union_set *copy() && = delete;
  inline __isl_keep isl_union_set *get() const;
  inline __isl_give isl_union_set *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionSet& affineHull();
  inline UnionSet& apply(UnionMap umap);
  inline UnionSet& coalesce();
  inline UnionSet& computeDivs();
  inline UnionSet& detectEqualities();
  inline UnionSet& gist(UnionSet context);
  inline UnionSet& gistParams(Set set);
  inline UnionMap identity() const;
  inline UnionSet& intersect(UnionSet uset2);
  inline UnionSet& intersectParams(Set set);
  inline Bool isEmpty() const;
  inline Bool isEqual(const UnionSet &uset2) const;
  inline Bool isStrictSubset(const UnionSet &uset2) const;
  inline Bool isSubset(const UnionSet &uset2) const;
  inline UnionSet& lexmax();
  inline UnionSet& lexmin();
  inline UnionSet& polyhedralHull();
  inline Point samplePoint() const;
  inline UnionSet& subtract(UnionSet uset2);
  inline UnionSet& unite(UnionSet uset2);
  inline UnionMap unwrap() const;
};

// declarations for isl::Val
inline Val manage(__isl_take isl_val *ptr);

class Val {
  friend inline Val manage(__isl_take isl_val *ptr);

  isl_val *ptr = nullptr;

  inline explicit Val(__isl_take isl_val *ptr);

public:
  inline Val();
  inline Val(const Val &obj);
  static inline Val intFromSi(Ctx ctx, long i);
  static inline Val readFromStr(Ctx ctx, std::string str);
  inline Val& operator=(Val obj);
  inline ~Val();
  inline __isl_give isl_val *copy() const &;
  inline __isl_give isl_val *copy() && = delete;
  inline __isl_keep isl_val *get() const;
  inline __isl_give isl_val *release();
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Val& abs();
  inline Bool absEq(const Val &v2) const;
  inline Val& add(Val v2);
  inline Val& addUi(unsigned long v2);
  inline Val& ceil();
  inline int cmpSi(long i) const;
  inline Val& div(Val v2);
  inline Bool eq(const Val &v2) const;
  inline Val& floor();
  inline Val& gcd(Val v2);
  inline Bool ge(const Val &v2) const;
  inline Bool gt(const Val &v2) const;
  static inline Val infty(Ctx ctx);
  inline Val& inv();
  inline Bool isDivisibleBy(const Val &v2) const;
  inline Bool isInfty() const;
  inline Bool isInt() const;
  inline Bool isNan() const;
  inline Bool isNeg() const;
  inline Bool isNeginfty() const;
  inline Bool isNegone() const;
  inline Bool isNonneg() const;
  inline Bool isNonpos() const;
  inline Bool isOne() const;
  inline Bool isPos() const;
  inline Bool isRat() const;
  inline Bool isZero() const;
  inline Bool le(const Val &v2) const;
  inline Bool lt(const Val &v2) const;
  inline Val& max(Val v2);
  inline Val& min(Val v2);
  inline Val& mod(Val v2);
  inline Val& mul(Val v2);
  static inline Val nan(Ctx ctx);
  inline Bool ne(const Val &v2) const;
  inline Val& neg();
  static inline Val neginfty(Ctx ctx);
  static inline Val negone(Ctx ctx);
  static inline Val one(Ctx ctx);
  inline int sgn() const;
  inline Val& sub(Val v2);
  inline Val& trunc();
  static inline Val zero(Ctx ctx);
};

// implementations for isl::Aff
Aff manage(__isl_take isl_aff *ptr) {
  return Aff(ptr);
}

Aff::Aff() : ptr(nullptr) {}

Aff::Aff(const Aff &obj) : ptr(obj.copy()) {}

Aff::Aff(__isl_take isl_aff *ptr) : ptr(ptr) {}

Aff Aff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

Aff& Aff::operator=(Aff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Aff::~Aff() {
  if (ptr)
    isl_aff_free(ptr);
}

__isl_give isl_aff *Aff::copy() const & {
  return isl_aff_copy(ptr);
}

__isl_keep isl_aff *Aff::get() const {
  return ptr;
}

__isl_give isl_aff *Aff::release() {
  isl_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Aff::isNull() const {
  return ptr == nullptr;
}

std::string Aff::getStr() const {
  char *Tmp = isl_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Aff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
Aff& Aff::add(Aff aff2) {
   auto res = isl_aff_add(copy(), aff2.release());
   isl_aff_free(ptr);
   ptr = res;
   return *this;
}

Val Aff::getConstantVal() const {
   auto res = isl_aff_get_constant_val(get());
   return manage(res);
}

Bool Aff::isCst() const {
   auto res = isl_aff_is_cst(get());
   return res;
}

Aff& Aff::pullback(MultiAff ma) {
   auto res = isl_aff_pullback_multi_aff(copy(), ma.release());
   isl_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::AstBuild
AstBuild manage(__isl_take isl_ast_build *ptr) {
  return AstBuild(ptr);
}

AstBuild::AstBuild() : ptr(nullptr) {}

AstBuild::AstBuild(const AstBuild &obj) : ptr(obj.copy()) {}

AstBuild::AstBuild(__isl_take isl_ast_build *ptr) : ptr(ptr) {}

AstBuild AstBuild::alloc(Ctx ctx) {
   auto res = isl_ast_build_alloc(ctx.release());
   return manage(res);
}

AstBuild& AstBuild::operator=(AstBuild obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

AstBuild::~AstBuild() {
  if (ptr)
    isl_ast_build_free(ptr);
}

__isl_give isl_ast_build *AstBuild::copy() const & {
  return isl_ast_build_copy(ptr);
}

__isl_keep isl_ast_build *AstBuild::get() const {
  return ptr;
}

__isl_give isl_ast_build *AstBuild::release() {
  isl_ast_build *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool AstBuild::isNull() const {
  return ptr == nullptr;
}

AstExpr AstBuild::accessFrom(PwMultiAff pma) const {
   auto res = isl_ast_build_access_from_pw_multi_aff(get(), pma.release());
   return manage(res);
}

AstExpr AstBuild::accessFrom(MultiPwAff mpa) const {
   auto res = isl_ast_build_access_from_multi_pw_aff(get(), mpa.release());
   return manage(res);
}

AstExpr AstBuild::callFrom(PwMultiAff pma) const {
   auto res = isl_ast_build_call_from_pw_multi_aff(get(), pma.release());
   return manage(res);
}

AstExpr AstBuild::callFrom(MultiPwAff mpa) const {
   auto res = isl_ast_build_call_from_multi_pw_aff(get(), mpa.release());
   return manage(res);
}

AstExpr AstBuild::exprFrom(Set set) const {
   auto res = isl_ast_build_expr_from_set(get(), set.release());
   return manage(res);
}

AstExpr AstBuild::exprFrom(PwAff pa) const {
   auto res = isl_ast_build_expr_from_pw_aff(get(), pa.release());
   return manage(res);
}

AstBuild AstBuild::fromContext(Set set) {
   auto res = isl_ast_build_from_context(set.release());
   return manage(res);
}

AstNode AstBuild::nodeFromScheduleMap(UnionMap schedule) const {
   auto res = isl_ast_build_node_from_schedule_map(get(), schedule.release());
   return manage(res);
}

// implementations for isl::AstExpr
AstExpr manage(__isl_take isl_ast_expr *ptr) {
  return AstExpr(ptr);
}

AstExpr::AstExpr() : ptr(nullptr) {}

AstExpr::AstExpr(const AstExpr &obj) : ptr(obj.copy()) {}

AstExpr::AstExpr(__isl_take isl_ast_expr *ptr) : ptr(ptr) {}

AstExpr& AstExpr::operator=(AstExpr obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

AstExpr::~AstExpr() {
  if (ptr)
    isl_ast_expr_free(ptr);
}

__isl_give isl_ast_expr *AstExpr::copy() const & {
  return isl_ast_expr_copy(ptr);
}

__isl_keep isl_ast_expr *AstExpr::get() const {
  return ptr;
}

__isl_give isl_ast_expr *AstExpr::release() {
  isl_ast_expr *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool AstExpr::isNull() const {
  return ptr == nullptr;
}

std::string AstExpr::getStr() const {
  char *Tmp = isl_ast_expr_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  AstExpr &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
std::string AstExpr::toCStr() const {
   auto res = isl_ast_expr_to_C_str(get());
   return res;
}

// implementations for isl::AstNode
AstNode manage(__isl_take isl_ast_node *ptr) {
  return AstNode(ptr);
}

AstNode::AstNode() : ptr(nullptr) {}

AstNode::AstNode(const AstNode &obj) : ptr(obj.copy()) {}

AstNode::AstNode(__isl_take isl_ast_node *ptr) : ptr(ptr) {}

AstNode& AstNode::operator=(AstNode obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

AstNode::~AstNode() {
  if (ptr)
    isl_ast_node_free(ptr);
}

__isl_give isl_ast_node *AstNode::copy() const & {
  return isl_ast_node_copy(ptr);
}

__isl_keep isl_ast_node *AstNode::get() const {
  return ptr;
}

__isl_give isl_ast_node *AstNode::release() {
  isl_ast_node *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool AstNode::isNull() const {
  return ptr == nullptr;
}

std::string AstNode::getStr() const {
  char *Tmp = isl_ast_node_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  AstNode &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
std::string AstNode::toCStr() const {
   auto res = isl_ast_node_to_C_str(get());
   return res;
}

// implementations for isl::BasicMap
BasicMap manage(__isl_take isl_basic_map *ptr) {
  return BasicMap(ptr);
}

BasicMap::BasicMap() : ptr(nullptr) {}

BasicMap::BasicMap(const BasicMap &obj) : ptr(obj.copy()) {}

BasicMap::BasicMap(__isl_take isl_basic_map *ptr) : ptr(ptr) {}

BasicMap BasicMap::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_basic_map_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

BasicMap& BasicMap::operator=(BasicMap obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

BasicMap::~BasicMap() {
  if (ptr)
    isl_basic_map_free(ptr);
}

__isl_give isl_basic_map *BasicMap::copy() const & {
  return isl_basic_map_copy(ptr);
}

__isl_keep isl_basic_map *BasicMap::get() const {
  return ptr;
}

__isl_give isl_basic_map *BasicMap::release() {
  isl_basic_map *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool BasicMap::isNull() const {
  return ptr == nullptr;
}

std::string BasicMap::getStr() const {
  char *Tmp = isl_basic_map_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  BasicMap &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
BasicMap& BasicMap::affineHull() {
   auto res = isl_basic_map_affine_hull(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::applyDomain(BasicMap bmap2) {
   auto res = isl_basic_map_apply_domain(copy(), bmap2.release());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::applyRange(BasicMap bmap2) {
   auto res = isl_basic_map_apply_range(copy(), bmap2.release());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicSet BasicMap::deltas() const {
   auto res = isl_basic_map_deltas(copy());
   return manage(res);
}

BasicMap& BasicMap::detectEqualities() {
   auto res = isl_basic_map_detect_equalities(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::flatten() {
   auto res = isl_basic_map_flatten(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::flattenDomain() {
   auto res = isl_basic_map_flatten_domain(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::flattenRange() {
   auto res = isl_basic_map_flatten_range(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::gist(BasicMap context) {
   auto res = isl_basic_map_gist(copy(), context.release());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::intersect(BasicMap bmap2) {
   auto res = isl_basic_map_intersect(copy(), bmap2.release());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::intersectDomain(BasicSet bset) {
   auto res = isl_basic_map_intersect_domain(copy(), bset.release());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::intersectRange(BasicSet bset) {
   auto res = isl_basic_map_intersect_range(copy(), bset.release());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

Bool BasicMap::isEmpty() const {
   auto res = isl_basic_map_is_empty(get());
   return res;
}

Bool BasicMap::isEqual(const BasicMap &bmap2) const {
   auto res = isl_basic_map_is_equal(get(), bmap2.get());
   return res;
}

Bool BasicMap::isSubset(const BasicMap &bmap2) const {
   auto res = isl_basic_map_is_subset(get(), bmap2.get());
   return res;
}

Map BasicMap::lexmax() const {
   auto res = isl_basic_map_lexmax(copy());
   return manage(res);
}

Map BasicMap::lexmin() const {
   auto res = isl_basic_map_lexmin(copy());
   return manage(res);
}

Val BasicMap::plainGetValIfFixed(enum DimType type, unsigned int pos) const {
   auto res = isl_basic_map_plain_get_val_if_fixed(get(), static_cast<enum isl_dim_type>(type), pos);
   return manage(res);
}

BasicMap& BasicMap::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_basic_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::reverse() {
   auto res = isl_basic_map_reverse(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap& BasicMap::sample() {
   auto res = isl_basic_map_sample(copy());
   isl_basic_map_free(ptr);
   ptr = res;
   return *this;
}

Map BasicMap::unite(BasicMap bmap2) const {
   auto res = isl_basic_map_union(copy(), bmap2.release());
   return manage(res);
}

// implementations for isl::BasicSet
BasicSet manage(__isl_take isl_basic_set *ptr) {
  return BasicSet(ptr);
}

BasicSet::BasicSet() : ptr(nullptr) {}

BasicSet::BasicSet(const BasicSet &obj) : ptr(obj.copy()) {}

BasicSet::BasicSet(__isl_take isl_basic_set *ptr) : ptr(ptr) {}

BasicSet BasicSet::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_basic_set_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

BasicSet::BasicSet(Point obj) {
  ptr = isl_basic_set_from_point(obj.release());
}

BasicSet& BasicSet::operator=(BasicSet obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

BasicSet::~BasicSet() {
  if (ptr)
    isl_basic_set_free(ptr);
}

__isl_give isl_basic_set *BasicSet::copy() const & {
  return isl_basic_set_copy(ptr);
}

__isl_keep isl_basic_set *BasicSet::get() const {
  return ptr;
}

__isl_give isl_basic_set *BasicSet::release() {
  isl_basic_set *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool BasicSet::isNull() const {
  return ptr == nullptr;
}

std::string BasicSet::getStr() const {
  char *Tmp = isl_basic_set_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  BasicSet &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
BasicSet& BasicSet::affineHull() {
   auto res = isl_basic_set_affine_hull(copy());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::apply(BasicMap bmap) {
   auto res = isl_basic_set_apply(copy(), bmap.release());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::detectEqualities() {
   auto res = isl_basic_set_detect_equalities(copy());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::flatten() {
   auto res = isl_basic_set_flatten(copy());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::gist(BasicSet context) {
   auto res = isl_basic_set_gist(copy(), context.release());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::intersect(BasicSet bset2) {
   auto res = isl_basic_set_intersect(copy(), bset2.release());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::intersectParams(BasicSet bset2) {
   auto res = isl_basic_set_intersect_params(copy(), bset2.release());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

int BasicSet::isBounded() const {
   auto res = isl_basic_set_is_bounded(get());
   return res;
}

Bool BasicSet::isEmpty() const {
   auto res = isl_basic_set_is_empty(get());
   return res;
}

Bool BasicSet::isEqual(const BasicSet &bset2) const {
   auto res = isl_basic_set_is_equal(get(), bset2.get());
   return res;
}

Bool BasicSet::isSubset(const BasicSet &bset2) const {
   auto res = isl_basic_set_is_subset(get(), bset2.get());
   return res;
}

Bool BasicSet::isWrapping() const {
   auto res = isl_basic_set_is_wrapping(get());
   return res;
}

Set BasicSet::lexmax() const {
   auto res = isl_basic_set_lexmax(copy());
   return manage(res);
}

Set BasicSet::lexmin() const {
   auto res = isl_basic_set_lexmin(copy());
   return manage(res);
}

BasicSet& BasicSet::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_basic_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet& BasicSet::sample() {
   auto res = isl_basic_set_sample(copy());
   isl_basic_set_free(ptr);
   ptr = res;
   return *this;
}

Point BasicSet::samplePoint() const {
   auto res = isl_basic_set_sample_point(copy());
   return manage(res);
}

Set BasicSet::unite(BasicSet bset2) const {
   auto res = isl_basic_set_union(copy(), bset2.release());
   return manage(res);
}

// implementations for isl::Map
Map manage(__isl_take isl_map *ptr) {
  return Map(ptr);
}

Map::Map() : ptr(nullptr) {}

Map::Map(const Map &obj) : ptr(obj.copy()) {}

Map::Map(__isl_take isl_map *ptr) : ptr(ptr) {}

Map Map::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_map_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

Map::Map(BasicMap obj) {
  ptr = isl_map_from_basic_map(obj.release());
}

Map& Map::operator=(Map obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Map::~Map() {
  if (ptr)
    isl_map_free(ptr);
}

__isl_give isl_map *Map::copy() const & {
  return isl_map_copy(ptr);
}

__isl_keep isl_map *Map::get() const {
  return ptr;
}

__isl_give isl_map *Map::release() {
  isl_map *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Map::isNull() const {
  return ptr == nullptr;
}

std::string Map::getStr() const {
  char *Tmp = isl_map_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Map &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
BasicMap Map::affineHull() const {
   auto res = isl_map_affine_hull(copy());
   return manage(res);
}

Map& Map::applyDomain(Map map2) {
   auto res = isl_map_apply_domain(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::applyRange(Map map2) {
   auto res = isl_map_apply_range(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::coalesce() {
   auto res = isl_map_coalesce(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::complement() {
   auto res = isl_map_complement(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Set Map::deltas() const {
   auto res = isl_map_deltas(copy());
   return manage(res);
}

Map& Map::detectEqualities() {
   auto res = isl_map_detect_equalities(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

unsigned int Map::dim(enum DimType type) const {
   auto res = isl_map_dim(get(), static_cast<enum isl_dim_type>(type));
   return res;
}

PwAff Map::dimMax(int pos) const {
   auto res = isl_map_dim_max(copy(), pos);
   return manage(res);
}

PwAff Map::dimMin(int pos) const {
   auto res = isl_map_dim_min(copy(), pos);
   return manage(res);
}

Map& Map::flatten() {
   auto res = isl_map_flatten(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::flattenDomain() {
   auto res = isl_map_flatten_domain(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::flattenRange() {
   auto res = isl_map_flatten_range(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::gist(Map context) {
   auto res = isl_map_gist(copy(), context.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::gistDomain(Set context) {
   auto res = isl_map_gist_domain(copy(), context.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::intersect(Map map2) {
   auto res = isl_map_intersect(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::intersectDomain(Set set) {
   auto res = isl_map_intersect_domain(copy(), set.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::intersectParams(Set params) {
   auto res = isl_map_intersect_params(copy(), params.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::intersectRange(Set set) {
   auto res = isl_map_intersect_range(copy(), set.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Bool Map::isBijective() const {
   auto res = isl_map_is_bijective(get());
   return res;
}

Bool Map::isDisjoint(const Map &map2) const {
   auto res = isl_map_is_disjoint(get(), map2.get());
   return res;
}

Bool Map::isEmpty() const {
   auto res = isl_map_is_empty(get());
   return res;
}

Bool Map::isEqual(const Map &map2) const {
   auto res = isl_map_is_equal(get(), map2.get());
   return res;
}

Bool Map::isInjective() const {
   auto res = isl_map_is_injective(get());
   return res;
}

Bool Map::isSingleValued() const {
   auto res = isl_map_is_single_valued(get());
   return res;
}

Bool Map::isStrictSubset(const Map &map2) const {
   auto res = isl_map_is_strict_subset(get(), map2.get());
   return res;
}

Bool Map::isSubset(const Map &map2) const {
   auto res = isl_map_is_subset(get(), map2.get());
   return res;
}

Map& Map::lexmax() {
   auto res = isl_map_lexmax(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::lexmin() {
   auto res = isl_map_lexmin(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap Map::polyhedralHull() const {
   auto res = isl_map_polyhedral_hull(copy());
   return manage(res);
}

Map& Map::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::reverse() {
   auto res = isl_map_reverse(copy());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap Map::sample() const {
   auto res = isl_map_sample(copy());
   return manage(res);
}

Map& Map::subtract(Map map2) {
   auto res = isl_map_subtract(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

Map& Map::unite(Map map2) {
   auto res = isl_map_union(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
   return *this;
}

BasicMap Map::unshiftedSimpleHull() const {
   auto res = isl_map_unshifted_simple_hull(copy());
   return manage(res);
}

// implementations for isl::MultiAff
MultiAff manage(__isl_take isl_multi_aff *ptr) {
  return MultiAff(ptr);
}

MultiAff::MultiAff() : ptr(nullptr) {}

MultiAff::MultiAff(const MultiAff &obj) : ptr(obj.copy()) {}

MultiAff::MultiAff(__isl_take isl_multi_aff *ptr) : ptr(ptr) {}

MultiAff::MultiAff(Aff obj) {
  ptr = isl_multi_aff_from_aff(obj.release());
}

MultiAff MultiAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_multi_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

MultiAff& MultiAff::operator=(MultiAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

MultiAff::~MultiAff() {
  if (ptr)
    isl_multi_aff_free(ptr);
}

__isl_give isl_multi_aff *MultiAff::copy() const & {
  return isl_multi_aff_copy(ptr);
}

__isl_keep isl_multi_aff *MultiAff::get() const {
  return ptr;
}

__isl_give isl_multi_aff *MultiAff::release() {
  isl_multi_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool MultiAff::isNull() const {
  return ptr == nullptr;
}

std::string MultiAff::getStr() const {
  char *Tmp = isl_multi_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  MultiAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
MultiAff& MultiAff::add(MultiAff multi2) {
   auto res = isl_multi_aff_add(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiAff& MultiAff::flatRangeProduct(MultiAff multi2) {
   auto res = isl_multi_aff_flat_range_product(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiAff& MultiAff::product(MultiAff multi2) {
   auto res = isl_multi_aff_product(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiAff& MultiAff::pullback(MultiAff ma2) {
   auto res = isl_multi_aff_pullback_multi_aff(copy(), ma2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiAff& MultiAff::rangeProduct(MultiAff multi2) {
   auto res = isl_multi_aff_range_product(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::MultiPwAff
MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr) {
  return MultiPwAff(ptr);
}

MultiPwAff::MultiPwAff() : ptr(nullptr) {}

MultiPwAff::MultiPwAff(const MultiPwAff &obj) : ptr(obj.copy()) {}

MultiPwAff::MultiPwAff(__isl_take isl_multi_pw_aff *ptr) : ptr(ptr) {}

MultiPwAff::MultiPwAff(MultiAff obj) {
  ptr = isl_multi_pw_aff_from_multi_aff(obj.release());
}

MultiPwAff::MultiPwAff(PwAff obj) {
  ptr = isl_multi_pw_aff_from_pw_aff(obj.release());
}

MultiPwAff::MultiPwAff(PwMultiAff obj) {
  ptr = isl_multi_pw_aff_from_pw_multi_aff(obj.release());
}

MultiPwAff MultiPwAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_multi_pw_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

MultiPwAff& MultiPwAff::operator=(MultiPwAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

MultiPwAff::~MultiPwAff() {
  if (ptr)
    isl_multi_pw_aff_free(ptr);
}

__isl_give isl_multi_pw_aff *MultiPwAff::copy() const & {
  return isl_multi_pw_aff_copy(ptr);
}

__isl_keep isl_multi_pw_aff *MultiPwAff::get() const {
  return ptr;
}

__isl_give isl_multi_pw_aff *MultiPwAff::release() {
  isl_multi_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool MultiPwAff::isNull() const {
  return ptr == nullptr;
}

std::string MultiPwAff::getStr() const {
  char *Tmp = isl_multi_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  MultiPwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
MultiPwAff& MultiPwAff::add(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_add(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiPwAff& MultiPwAff::flatRangeProduct(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_flat_range_product(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiPwAff& MultiPwAff::product(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_product(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiPwAff& MultiPwAff::pullback(MultiAff ma) {
   auto res = isl_multi_pw_aff_pullback_multi_aff(copy(), ma.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiPwAff& MultiPwAff::pullback(PwMultiAff pma) {
   auto res = isl_multi_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiPwAff& MultiPwAff::pullback(MultiPwAff mpa2) {
   auto res = isl_multi_pw_aff_pullback_multi_pw_aff(copy(), mpa2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiPwAff& MultiPwAff::rangeProduct(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_range_product(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::MultiUnionPwAff
MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr) {
  return MultiUnionPwAff(ptr);
}

MultiUnionPwAff::MultiUnionPwAff() : ptr(nullptr) {}

MultiUnionPwAff::MultiUnionPwAff(const MultiUnionPwAff &obj) : ptr(obj.copy()) {}

MultiUnionPwAff::MultiUnionPwAff(__isl_take isl_multi_union_pw_aff *ptr) : ptr(ptr) {}

MultiUnionPwAff::MultiUnionPwAff(UnionPwAff obj) {
  ptr = isl_multi_union_pw_aff_from_union_pw_aff(obj.release());
}

MultiUnionPwAff::MultiUnionPwAff(MultiPwAff obj) {
  ptr = isl_multi_union_pw_aff_from_multi_pw_aff(obj.release());
}

MultiUnionPwAff::MultiUnionPwAff(UnionPwMultiAff obj) {
  ptr = isl_multi_union_pw_aff_from_union_pw_multi_aff(obj.release());
}

MultiUnionPwAff MultiUnionPwAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_multi_union_pw_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

MultiUnionPwAff& MultiUnionPwAff::operator=(MultiUnionPwAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

MultiUnionPwAff::~MultiUnionPwAff() {
  if (ptr)
    isl_multi_union_pw_aff_free(ptr);
}

__isl_give isl_multi_union_pw_aff *MultiUnionPwAff::copy() const & {
  return isl_multi_union_pw_aff_copy(ptr);
}

__isl_keep isl_multi_union_pw_aff *MultiUnionPwAff::get() const {
  return ptr;
}

__isl_give isl_multi_union_pw_aff *MultiUnionPwAff::release() {
  isl_multi_union_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool MultiUnionPwAff::isNull() const {
  return ptr == nullptr;
}

std::string MultiUnionPwAff::getStr() const {
  char *Tmp = isl_multi_union_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  MultiUnionPwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
MultiUnionPwAff& MultiUnionPwAff::add(MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_add(copy(), multi2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiUnionPwAff& MultiUnionPwAff::flatRangeProduct(MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_flat_range_product(copy(), multi2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiUnionPwAff& MultiUnionPwAff::pullback(UnionPwMultiAff upma) {
   auto res = isl_multi_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiUnionPwAff& MultiUnionPwAff::rangeProduct(MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_range_product(copy(), multi2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

MultiUnionPwAff& MultiUnionPwAff::unionAdd(MultiUnionPwAff mupa2) {
   auto res = isl_multi_union_pw_aff_union_add(copy(), mupa2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::MultiVal
MultiVal manage(__isl_take isl_multi_val *ptr) {
  return MultiVal(ptr);
}

MultiVal::MultiVal() : ptr(nullptr) {}

MultiVal::MultiVal(const MultiVal &obj) : ptr(obj.copy()) {}

MultiVal::MultiVal(__isl_take isl_multi_val *ptr) : ptr(ptr) {}

MultiVal& MultiVal::operator=(MultiVal obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

MultiVal::~MultiVal() {
  if (ptr)
    isl_multi_val_free(ptr);
}

__isl_give isl_multi_val *MultiVal::copy() const & {
  return isl_multi_val_copy(ptr);
}

__isl_keep isl_multi_val *MultiVal::get() const {
  return ptr;
}

__isl_give isl_multi_val *MultiVal::release() {
  isl_multi_val *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool MultiVal::isNull() const {
  return ptr == nullptr;
}

std::string MultiVal::getStr() const {
  char *Tmp = isl_multi_val_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  MultiVal &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
MultiVal& MultiVal::add(MultiVal multi2) {
   auto res = isl_multi_val_add(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
   return *this;
}

MultiVal& MultiVal::flatRangeProduct(MultiVal multi2) {
   auto res = isl_multi_val_flat_range_product(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
   return *this;
}

MultiVal& MultiVal::product(MultiVal multi2) {
   auto res = isl_multi_val_product(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
   return *this;
}

MultiVal& MultiVal::rangeProduct(MultiVal multi2) {
   auto res = isl_multi_val_range_product(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::Point
Point manage(__isl_take isl_point *ptr) {
  return Point(ptr);
}

Point::Point() : ptr(nullptr) {}

Point::Point(const Point &obj) : ptr(obj.copy()) {}

Point::Point(__isl_take isl_point *ptr) : ptr(ptr) {}

Point& Point::operator=(Point obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Point::~Point() {
  if (ptr)
    isl_point_free(ptr);
}

__isl_give isl_point *Point::copy() const & {
  return isl_point_copy(ptr);
}

__isl_keep isl_point *Point::get() const {
  return ptr;
}

__isl_give isl_point *Point::release() {
  isl_point *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Point::isNull() const {
  return ptr == nullptr;
}

std::string Point::getStr() const {
  char *Tmp = isl_point_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Point &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
// implementations for isl::PwAff
PwAff manage(__isl_take isl_pw_aff *ptr) {
  return PwAff(ptr);
}

PwAff::PwAff() : ptr(nullptr) {}

PwAff::PwAff(const PwAff &obj) : ptr(obj.copy()) {}

PwAff::PwAff(__isl_take isl_pw_aff *ptr) : ptr(ptr) {}

PwAff::PwAff(Aff obj) {
  ptr = isl_pw_aff_from_aff(obj.release());
}

PwAff PwAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_pw_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

PwAff& PwAff::operator=(PwAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

PwAff::~PwAff() {
  if (ptr)
    isl_pw_aff_free(ptr);
}

__isl_give isl_pw_aff *PwAff::copy() const & {
  return isl_pw_aff_copy(ptr);
}

__isl_keep isl_pw_aff *PwAff::get() const {
  return ptr;
}

__isl_give isl_pw_aff *PwAff::release() {
  isl_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool PwAff::isNull() const {
  return ptr == nullptr;
}

std::string PwAff::getStr() const {
  char *Tmp = isl_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  PwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
PwAff& PwAff::add(PwAff pwaff2) {
   auto res = isl_pw_aff_add(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::mul(PwAff pwaff2) {
   auto res = isl_pw_aff_mul(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::neg() {
   auto res = isl_pw_aff_neg(copy());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::pullback(MultiAff ma) {
   auto res = isl_pw_aff_pullback_multi_aff(copy(), ma.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::pullback(PwMultiAff pma) {
   auto res = isl_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::pullback(MultiPwAff mpa) {
   auto res = isl_pw_aff_pullback_multi_pw_aff(copy(), mpa.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::sub(PwAff pwaff2) {
   auto res = isl_pw_aff_sub(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

PwAff& PwAff::unionAdd(PwAff pwaff2) {
   auto res = isl_pw_aff_union_add(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::PwMultiAff
PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr) {
  return PwMultiAff(ptr);
}

PwMultiAff::PwMultiAff() : ptr(nullptr) {}

PwMultiAff::PwMultiAff(const PwMultiAff &obj) : ptr(obj.copy()) {}

PwMultiAff::PwMultiAff(__isl_take isl_pw_multi_aff *ptr) : ptr(ptr) {}

PwMultiAff::PwMultiAff(MultiAff obj) {
  ptr = isl_pw_multi_aff_from_multi_aff(obj.release());
}

PwMultiAff::PwMultiAff(PwAff obj) {
  ptr = isl_pw_multi_aff_from_pw_aff(obj.release());
}

PwMultiAff PwMultiAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_pw_multi_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

PwMultiAff& PwMultiAff::operator=(PwMultiAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

PwMultiAff::~PwMultiAff() {
  if (ptr)
    isl_pw_multi_aff_free(ptr);
}

__isl_give isl_pw_multi_aff *PwMultiAff::copy() const & {
  return isl_pw_multi_aff_copy(ptr);
}

__isl_keep isl_pw_multi_aff *PwMultiAff::get() const {
  return ptr;
}

__isl_give isl_pw_multi_aff *PwMultiAff::release() {
  isl_pw_multi_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool PwMultiAff::isNull() const {
  return ptr == nullptr;
}

std::string PwMultiAff::getStr() const {
  char *Tmp = isl_pw_multi_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  PwMultiAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
PwMultiAff& PwMultiAff::add(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_add(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

PwMultiAff& PwMultiAff::flatRangeProduct(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_flat_range_product(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

PwMultiAff& PwMultiAff::product(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_product(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

PwMultiAff& PwMultiAff::pullback(MultiAff ma) {
   auto res = isl_pw_multi_aff_pullback_multi_aff(copy(), ma.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

PwMultiAff& PwMultiAff::pullback(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_pullback_pw_multi_aff(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

PwMultiAff& PwMultiAff::rangeProduct(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_range_product(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

PwMultiAff& PwMultiAff::unionAdd(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_union_add(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::Schedule
Schedule manage(__isl_take isl_schedule *ptr) {
  return Schedule(ptr);
}

Schedule::Schedule() : ptr(nullptr) {}

Schedule::Schedule(const Schedule &obj) : ptr(obj.copy()) {}

Schedule::Schedule(__isl_take isl_schedule *ptr) : ptr(ptr) {}

Schedule Schedule::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_schedule_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

Schedule& Schedule::operator=(Schedule obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Schedule::~Schedule() {
  if (ptr)
    isl_schedule_free(ptr);
}

__isl_give isl_schedule *Schedule::copy() const & {
  return isl_schedule_copy(ptr);
}

__isl_keep isl_schedule *Schedule::get() const {
  return ptr;
}

__isl_give isl_schedule *Schedule::release() {
  isl_schedule *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Schedule::isNull() const {
  return ptr == nullptr;
}

std::string Schedule::getStr() const {
  char *Tmp = isl_schedule_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Schedule &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionMap Schedule::getMap() const {
   auto res = isl_schedule_get_map(get());
   return manage(res);
}

ScheduleNode Schedule::getRoot() const {
   auto res = isl_schedule_get_root(get());
   return manage(res);
}

Schedule& Schedule::pullback(UnionPwMultiAff upma) {
   auto res = isl_schedule_pullback_union_pw_multi_aff(copy(), upma.release());
   isl_schedule_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::ScheduleConstraints
ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr) {
  return ScheduleConstraints(ptr);
}

ScheduleConstraints::ScheduleConstraints() : ptr(nullptr) {}

ScheduleConstraints::ScheduleConstraints(const ScheduleConstraints &obj) : ptr(obj.copy()) {}

ScheduleConstraints::ScheduleConstraints(__isl_take isl_schedule_constraints *ptr) : ptr(ptr) {}

ScheduleConstraints ScheduleConstraints::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_schedule_constraints_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

ScheduleConstraints& ScheduleConstraints::operator=(ScheduleConstraints obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

ScheduleConstraints::~ScheduleConstraints() {
  if (ptr)
    isl_schedule_constraints_free(ptr);
}

__isl_give isl_schedule_constraints *ScheduleConstraints::copy() const & {
  return isl_schedule_constraints_copy(ptr);
}

__isl_keep isl_schedule_constraints *ScheduleConstraints::get() const {
  return ptr;
}

__isl_give isl_schedule_constraints *ScheduleConstraints::release() {
  isl_schedule_constraints *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool ScheduleConstraints::isNull() const {
  return ptr == nullptr;
}

std::string ScheduleConstraints::getStr() const {
  char *Tmp = isl_schedule_constraints_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  ScheduleConstraints &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionMap ScheduleConstraints::getCoincidence() const {
   auto res = isl_schedule_constraints_get_coincidence(get());
   return manage(res);
}

UnionMap ScheduleConstraints::getConditionalValidity() const {
   auto res = isl_schedule_constraints_get_conditional_validity(get());
   return manage(res);
}

UnionMap ScheduleConstraints::getConditionalValidityCondition() const {
   auto res = isl_schedule_constraints_get_conditional_validity_condition(get());
   return manage(res);
}

Set ScheduleConstraints::getContext() const {
   auto res = isl_schedule_constraints_get_context(get());
   return manage(res);
}

UnionSet ScheduleConstraints::getDomain() const {
   auto res = isl_schedule_constraints_get_domain(get());
   return manage(res);
}

UnionMap ScheduleConstraints::getProximity() const {
   auto res = isl_schedule_constraints_get_proximity(get());
   return manage(res);
}

UnionMap ScheduleConstraints::getValidity() const {
   auto res = isl_schedule_constraints_get_validity(get());
   return manage(res);
}

// implementations for isl::ScheduleNode
ScheduleNode manage(__isl_take isl_schedule_node *ptr) {
  return ScheduleNode(ptr);
}

ScheduleNode::ScheduleNode() : ptr(nullptr) {}

ScheduleNode::ScheduleNode(const ScheduleNode &obj) : ptr(obj.copy()) {}

ScheduleNode::ScheduleNode(__isl_take isl_schedule_node *ptr) : ptr(ptr) {}

ScheduleNode& ScheduleNode::operator=(ScheduleNode obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

ScheduleNode::~ScheduleNode() {
  if (ptr)
    isl_schedule_node_free(ptr);
}

__isl_give isl_schedule_node *ScheduleNode::copy() const & {
  return isl_schedule_node_copy(ptr);
}

__isl_keep isl_schedule_node *ScheduleNode::get() const {
  return ptr;
}

__isl_give isl_schedule_node *ScheduleNode::release() {
  isl_schedule_node *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool ScheduleNode::isNull() const {
  return ptr == nullptr;
}

std::string ScheduleNode::getStr() const {
  char *Tmp = isl_schedule_node_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  ScheduleNode &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
Bool ScheduleNode::bandMemberGetCoincident(int pos) const {
   auto res = isl_schedule_node_band_member_get_coincident(get(), pos);
   return res;
}

ScheduleNode& ScheduleNode::bandMemberSetCoincident(int pos, int coincident) {
   auto res = isl_schedule_node_band_member_set_coincident(copy(), pos, coincident);
   isl_schedule_node_free(ptr);
   ptr = res;
   return *this;
}

ScheduleNode& ScheduleNode::child(int pos) {
   auto res = isl_schedule_node_child(copy(), pos);
   isl_schedule_node_free(ptr);
   ptr = res;
   return *this;
}

MultiUnionPwAff ScheduleNode::getPrefixScheduleMultiUnionPwAff() const {
   auto res = isl_schedule_node_get_prefix_schedule_multi_union_pw_aff(get());
   return manage(res);
}

UnionMap ScheduleNode::getPrefixScheduleUnionMap() const {
   auto res = isl_schedule_node_get_prefix_schedule_union_map(get());
   return manage(res);
}

UnionPwMultiAff ScheduleNode::getPrefixScheduleUnionPwMultiAff() const {
   auto res = isl_schedule_node_get_prefix_schedule_union_pw_multi_aff(get());
   return manage(res);
}

Schedule ScheduleNode::getSchedule() const {
   auto res = isl_schedule_node_get_schedule(get());
   return manage(res);
}

ScheduleNode& ScheduleNode::parent() {
   auto res = isl_schedule_node_parent(copy());
   isl_schedule_node_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::Set
Set manage(__isl_take isl_set *ptr) {
  return Set(ptr);
}

Set::Set() : ptr(nullptr) {}

Set::Set(const Set &obj) : ptr(obj.copy()) {}

Set::Set(__isl_take isl_set *ptr) : ptr(ptr) {}

Set::Set(UnionSet obj) {
  ptr = isl_set_from_union_set(obj.release());
}

Set Set::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_set_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

Set::Set(BasicSet obj) {
  ptr = isl_set_from_basic_set(obj.release());
}

Set::Set(Point obj) {
  ptr = isl_set_from_point(obj.release());
}

Set& Set::operator=(Set obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Set::~Set() {
  if (ptr)
    isl_set_free(ptr);
}

__isl_give isl_set *Set::copy() const & {
  return isl_set_copy(ptr);
}

__isl_keep isl_set *Set::get() const {
  return ptr;
}

__isl_give isl_set *Set::release() {
  isl_set *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Set::isNull() const {
  return ptr == nullptr;
}

std::string Set::getStr() const {
  char *Tmp = isl_set_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Set &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
Set& Set::addDims(enum DimType type, unsigned int n) {
   auto res = isl_set_add_dims(copy(), static_cast<enum isl_dim_type>(type), n);
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet Set::affineHull() const {
   auto res = isl_set_affine_hull(copy());
   return manage(res);
}

Set& Set::apply(Map map) {
   auto res = isl_set_apply(copy(), map.release());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::coalesce() {
   auto res = isl_set_coalesce(copy());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::complement() {
   auto res = isl_set_complement(copy());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::detectEqualities() {
   auto res = isl_set_detect_equalities(copy());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

unsigned int Set::dim(enum DimType type) const {
   auto res = isl_set_dim(get(), static_cast<enum isl_dim_type>(type));
   return res;
}

PwAff Set::dimMax(int pos) const {
   auto res = isl_set_dim_max(copy(), pos);
   return manage(res);
}

PwAff Set::dimMin(int pos) const {
   auto res = isl_set_dim_min(copy(), pos);
   return manage(res);
}

Set& Set::flatten() {
   auto res = isl_set_flatten(copy());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::gist(Set context) {
   auto res = isl_set_gist(copy(), context.release());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Map Set::identity() const {
   auto res = isl_set_identity(copy());
   return manage(res);
}

Set& Set::intersect(Set set2) {
   auto res = isl_set_intersect(copy(), set2.release());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::intersectParams(Set params) {
   auto res = isl_set_intersect_params(copy(), params.release());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

int Set::isBounded() const {
   auto res = isl_set_is_bounded(get());
   return res;
}

Bool Set::isDisjoint(const Set &set2) const {
   auto res = isl_set_is_disjoint(get(), set2.get());
   return res;
}

Bool Set::isEmpty() const {
   auto res = isl_set_is_empty(get());
   return res;
}

Bool Set::isEqual(const Set &set2) const {
   auto res = isl_set_is_equal(get(), set2.get());
   return res;
}

Bool Set::isStrictSubset(const Set &set2) const {
   auto res = isl_set_is_strict_subset(get(), set2.get());
   return res;
}

Bool Set::isSubset(const Set &set2) const {
   auto res = isl_set_is_subset(get(), set2.get());
   return res;
}

Bool Set::isWrapping() const {
   auto res = isl_set_is_wrapping(get());
   return res;
}

Set& Set::lexmax() {
   auto res = isl_set_lexmax(copy());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::lexmin() {
   auto res = isl_set_lexmin(copy());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Val Set::maxVal(const Aff &obj) const {
   auto res = isl_set_max_val(get(), obj.get());
   return manage(res);
}

Val Set::minVal(const Aff &obj) const {
   auto res = isl_set_min_val(get(), obj.get());
   return manage(res);
}

BasicSet Set::polyhedralHull() const {
   auto res = isl_set_polyhedral_hull(copy());
   return manage(res);
}

Set& Set::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet Set::sample() const {
   auto res = isl_set_sample(copy());
   return manage(res);
}

Point Set::samplePoint() const {
   auto res = isl_set_sample_point(copy());
   return manage(res);
}

Set& Set::subtract(Set set2) {
   auto res = isl_set_subtract(copy(), set2.release());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

Set& Set::unite(Set set2) {
   auto res = isl_set_union(copy(), set2.release());
   isl_set_free(ptr);
   ptr = res;
   return *this;
}

BasicSet Set::unshiftedSimpleHull() const {
   auto res = isl_set_unshifted_simple_hull(copy());
   return manage(res);
}

// implementations for isl::Space
Space manage(__isl_take isl_space *ptr) {
  return Space(ptr);
}

Space::Space() : ptr(nullptr) {}

Space::Space(const Space &obj) : ptr(obj.copy()) {}

Space::Space(__isl_take isl_space *ptr) : ptr(ptr) {}

Space& Space::operator=(Space obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Space::~Space() {
  if (ptr)
    isl_space_free(ptr);
}

__isl_give isl_space *Space::copy() const & {
  return isl_space_copy(ptr);
}

__isl_keep isl_space *Space::get() const {
  return ptr;
}

__isl_give isl_space *Space::release() {
  isl_space *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Space::isNull() const {
  return ptr == nullptr;
}

std::string Space::getStr() const {
  char *Tmp = isl_space_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Space &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
// implementations for isl::UnionAccessInfo
UnionAccessInfo manage(__isl_take isl_union_access_info *ptr) {
  return UnionAccessInfo(ptr);
}

UnionAccessInfo::UnionAccessInfo() : ptr(nullptr) {}

UnionAccessInfo::UnionAccessInfo(const UnionAccessInfo &obj) : ptr(obj.copy()) {}

UnionAccessInfo::UnionAccessInfo(__isl_take isl_union_access_info *ptr) : ptr(ptr) {}

UnionAccessInfo::UnionAccessInfo(UnionMap obj) {
  ptr = isl_union_access_info_from_sink(obj.release());
}

UnionAccessInfo& UnionAccessInfo::operator=(UnionAccessInfo obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

UnionAccessInfo::~UnionAccessInfo() {
  if (ptr)
    isl_union_access_info_free(ptr);
}

__isl_give isl_union_access_info *UnionAccessInfo::copy() const & {
  return isl_union_access_info_copy(ptr);
}

__isl_keep isl_union_access_info *UnionAccessInfo::get() const {
  return ptr;
}

__isl_give isl_union_access_info *UnionAccessInfo::release() {
  isl_union_access_info *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool UnionAccessInfo::isNull() const {
  return ptr == nullptr;
}

std::string UnionAccessInfo::getStr() const {
  char *Tmp = isl_union_access_info_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  UnionAccessInfo &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionFlow UnionAccessInfo::computeFlow() const {
   auto res = isl_union_access_info_compute_flow(copy());
   return manage(res);
}

UnionAccessInfo& UnionAccessInfo::setMaySource(UnionMap may_source) {
   auto res = isl_union_access_info_set_may_source(copy(), may_source.release());
   isl_union_access_info_free(ptr);
   ptr = res;
   return *this;
}

UnionAccessInfo& UnionAccessInfo::setMustSource(UnionMap must_source) {
   auto res = isl_union_access_info_set_must_source(copy(), must_source.release());
   isl_union_access_info_free(ptr);
   ptr = res;
   return *this;
}

UnionAccessInfo& UnionAccessInfo::setSchedule(Schedule schedule) {
   auto res = isl_union_access_info_set_schedule(copy(), schedule.release());
   isl_union_access_info_free(ptr);
   ptr = res;
   return *this;
}

UnionAccessInfo& UnionAccessInfo::setScheduleMap(UnionMap schedule_map) {
   auto res = isl_union_access_info_set_schedule_map(copy(), schedule_map.release());
   isl_union_access_info_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::UnionFlow
UnionFlow manage(__isl_take isl_union_flow *ptr) {
  return UnionFlow(ptr);
}

UnionFlow::UnionFlow() : ptr(nullptr) {}

UnionFlow::UnionFlow(const UnionFlow &obj) : ptr(obj.copy()) {}

UnionFlow::UnionFlow(__isl_take isl_union_flow *ptr) : ptr(ptr) {}

UnionFlow& UnionFlow::operator=(UnionFlow obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

UnionFlow::~UnionFlow() {
  if (ptr)
    isl_union_flow_free(ptr);
}

__isl_give isl_union_flow *UnionFlow::copy() const & {
  return isl_union_flow_copy(ptr);
}

__isl_keep isl_union_flow *UnionFlow::get() const {
  return ptr;
}

__isl_give isl_union_flow *UnionFlow::release() {
  isl_union_flow *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool UnionFlow::isNull() const {
  return ptr == nullptr;
}

std::string UnionFlow::getStr() const {
  char *Tmp = isl_union_flow_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  UnionFlow &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionMap UnionFlow::getFullMayDependence() const {
   auto res = isl_union_flow_get_full_may_dependence(get());
   return manage(res);
}

UnionMap UnionFlow::getFullMustDependence() const {
   auto res = isl_union_flow_get_full_must_dependence(get());
   return manage(res);
}

UnionMap UnionFlow::getMayDependence() const {
   auto res = isl_union_flow_get_may_dependence(get());
   return manage(res);
}

UnionMap UnionFlow::getMayNoSource() const {
   auto res = isl_union_flow_get_may_no_source(get());
   return manage(res);
}

UnionMap UnionFlow::getMustDependence() const {
   auto res = isl_union_flow_get_must_dependence(get());
   return manage(res);
}

UnionMap UnionFlow::getMustNoSource() const {
   auto res = isl_union_flow_get_must_no_source(get());
   return manage(res);
}

// implementations for isl::UnionMap
UnionMap manage(__isl_take isl_union_map *ptr) {
  return UnionMap(ptr);
}

UnionMap::UnionMap() : ptr(nullptr) {}

UnionMap::UnionMap(const UnionMap &obj) : ptr(obj.copy()) {}

UnionMap::UnionMap(__isl_take isl_union_map *ptr) : ptr(ptr) {}

UnionMap::UnionMap(UnionPwAff obj) {
  ptr = isl_union_map_from_union_pw_aff(obj.release());
}

UnionMap::UnionMap(BasicMap obj) {
  ptr = isl_union_map_from_basic_map(obj.release());
}

UnionMap::UnionMap(Map obj) {
  ptr = isl_union_map_from_map(obj.release());
}

UnionMap UnionMap::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_union_map_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

UnionMap& UnionMap::operator=(UnionMap obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

UnionMap::~UnionMap() {
  if (ptr)
    isl_union_map_free(ptr);
}

__isl_give isl_union_map *UnionMap::copy() const & {
  return isl_union_map_copy(ptr);
}

__isl_keep isl_union_map *UnionMap::get() const {
  return ptr;
}

__isl_give isl_union_map *UnionMap::release() {
  isl_union_map *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool UnionMap::isNull() const {
  return ptr == nullptr;
}

std::string UnionMap::getStr() const {
  char *Tmp = isl_union_map_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  UnionMap &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionMap& UnionMap::addMap(Map map) {
   auto res = isl_union_map_add_map(copy(), map.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::affineHull() {
   auto res = isl_union_map_affine_hull(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::applyDomain(UnionMap umap2) {
   auto res = isl_union_map_apply_domain(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::applyRange(UnionMap umap2) {
   auto res = isl_union_map_apply_range(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::coalesce() {
   auto res = isl_union_map_coalesce(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::computeDivs() {
   auto res = isl_union_map_compute_divs(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionSet UnionMap::deltas() const {
   auto res = isl_union_map_deltas(copy());
   return manage(res);
}

UnionMap& UnionMap::detectEqualities() {
   auto res = isl_union_map_detect_equalities(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionSet UnionMap::domain() const {
   auto res = isl_union_map_domain(copy());
   return manage(res);
}

UnionMap& UnionMap::domainFactorDomain() {
   auto res = isl_union_map_domain_factor_domain(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::domainFactorRange() {
   auto res = isl_union_map_domain_factor_range(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::domainMap() {
   auto res = isl_union_map_domain_map(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionPwMultiAff UnionMap::domainMapUnionPwMultiAff() const {
   auto res = isl_union_map_domain_map_union_pw_multi_aff(copy());
   return manage(res);
}

UnionMap& UnionMap::domainProduct(UnionMap umap2) {
   auto res = isl_union_map_domain_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::factorDomain() {
   auto res = isl_union_map_factor_domain(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::factorRange() {
   auto res = isl_union_map_factor_range(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::fixedPower(Val exp) {
   auto res = isl_union_map_fixed_power_val(copy(), exp.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::flatRangeProduct(UnionMap umap2) {
   auto res = isl_union_map_flat_range_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap UnionMap::from(UnionPwMultiAff upma) {
   auto res = isl_union_map_from_union_pw_multi_aff(upma.release());
   return manage(res);
}

UnionMap UnionMap::from(MultiUnionPwAff mupa) {
   auto res = isl_union_map_from_multi_union_pw_aff(mupa.release());
   return manage(res);
}

UnionMap UnionMap::fromDomainAndRange(UnionSet domain, UnionSet range) {
   auto res = isl_union_map_from_domain_and_range(domain.release(), range.release());
   return manage(res);
}

UnionMap& UnionMap::gist(UnionMap context) {
   auto res = isl_union_map_gist(copy(), context.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::gistDomain(UnionSet uset) {
   auto res = isl_union_map_gist_domain(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::gistParams(Set set) {
   auto res = isl_union_map_gist_params(copy(), set.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::gistRange(UnionSet uset) {
   auto res = isl_union_map_gist_range(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::intersect(UnionMap umap2) {
   auto res = isl_union_map_intersect(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::intersectDomain(UnionSet uset) {
   auto res = isl_union_map_intersect_domain(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::intersectParams(Set set) {
   auto res = isl_union_map_intersect_params(copy(), set.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::intersectRange(UnionSet uset) {
   auto res = isl_union_map_intersect_range(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

Bool UnionMap::isBijective() const {
   auto res = isl_union_map_is_bijective(get());
   return res;
}

Bool UnionMap::isEmpty() const {
   auto res = isl_union_map_is_empty(get());
   return res;
}

Bool UnionMap::isEqual(const UnionMap &umap2) const {
   auto res = isl_union_map_is_equal(get(), umap2.get());
   return res;
}

Bool UnionMap::isInjective() const {
   auto res = isl_union_map_is_injective(get());
   return res;
}

Bool UnionMap::isSingleValued() const {
   auto res = isl_union_map_is_single_valued(get());
   return res;
}

Bool UnionMap::isStrictSubset(const UnionMap &umap2) const {
   auto res = isl_union_map_is_strict_subset(get(), umap2.get());
   return res;
}

Bool UnionMap::isSubset(const UnionMap &umap2) const {
   auto res = isl_union_map_is_subset(get(), umap2.get());
   return res;
}

UnionMap& UnionMap::lexmax() {
   auto res = isl_union_map_lexmax(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::lexmin() {
   auto res = isl_union_map_lexmin(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::polyhedralHull() {
   auto res = isl_union_map_polyhedral_hull(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::product(UnionMap umap2) {
   auto res = isl_union_map_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionSet UnionMap::range() const {
   auto res = isl_union_map_range(copy());
   return manage(res);
}

UnionMap& UnionMap::rangeFactorDomain() {
   auto res = isl_union_map_range_factor_domain(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::rangeFactorRange() {
   auto res = isl_union_map_range_factor_range(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::rangeMap() {
   auto res = isl_union_map_range_map(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::rangeProduct(UnionMap umap2) {
   auto res = isl_union_map_range_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::reverse() {
   auto res = isl_union_map_reverse(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::subtract(UnionMap umap2) {
   auto res = isl_union_map_subtract(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::subtractDomain(UnionSet dom) {
   auto res = isl_union_map_subtract_domain(copy(), dom.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::subtractRange(UnionSet dom) {
   auto res = isl_union_map_subtract_range(copy(), dom.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionMap& UnionMap::unite(UnionMap umap2) {
   auto res = isl_union_map_union(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

UnionSet UnionMap::wrap() const {
   auto res = isl_union_map_wrap(copy());
   return manage(res);
}

UnionMap& UnionMap::zip() {
   auto res = isl_union_map_zip(copy());
   isl_union_map_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::UnionPwAff
UnionPwAff manage(__isl_take isl_union_pw_aff *ptr) {
  return UnionPwAff(ptr);
}

UnionPwAff::UnionPwAff() : ptr(nullptr) {}

UnionPwAff::UnionPwAff(const UnionPwAff &obj) : ptr(obj.copy()) {}

UnionPwAff::UnionPwAff(__isl_take isl_union_pw_aff *ptr) : ptr(ptr) {}

UnionPwAff::UnionPwAff(PwAff obj) {
  ptr = isl_union_pw_aff_from_pw_aff(obj.release());
}

UnionPwAff UnionPwAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_union_pw_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

UnionPwAff& UnionPwAff::operator=(UnionPwAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

UnionPwAff::~UnionPwAff() {
  if (ptr)
    isl_union_pw_aff_free(ptr);
}

__isl_give isl_union_pw_aff *UnionPwAff::copy() const & {
  return isl_union_pw_aff_copy(ptr);
}

__isl_keep isl_union_pw_aff *UnionPwAff::get() const {
  return ptr;
}

__isl_give isl_union_pw_aff *UnionPwAff::release() {
  isl_union_pw_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool UnionPwAff::isNull() const {
  return ptr == nullptr;
}

std::string UnionPwAff::getStr() const {
  char *Tmp = isl_union_pw_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  UnionPwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionPwAff& UnionPwAff::add(UnionPwAff upa2) {
   auto res = isl_union_pw_aff_add(copy(), upa2.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

UnionPwAff& UnionPwAff::pullback(UnionPwMultiAff upma) {
   auto res = isl_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

UnionPwAff& UnionPwAff::sub(UnionPwAff upa2) {
   auto res = isl_union_pw_aff_sub(copy(), upa2.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

UnionPwAff& UnionPwAff::unionAdd(UnionPwAff upa2) {
   auto res = isl_union_pw_aff_union_add(copy(), upa2.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::UnionPwMultiAff
UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr) {
  return UnionPwMultiAff(ptr);
}

UnionPwMultiAff::UnionPwMultiAff() : ptr(nullptr) {}

UnionPwMultiAff::UnionPwMultiAff(const UnionPwMultiAff &obj) : ptr(obj.copy()) {}

UnionPwMultiAff::UnionPwMultiAff(__isl_take isl_union_pw_multi_aff *ptr) : ptr(ptr) {}

UnionPwMultiAff::UnionPwMultiAff(UnionMap obj) {
  ptr = isl_union_pw_multi_aff_from_union_map(obj.release());
}

UnionPwMultiAff UnionPwMultiAff::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_union_pw_multi_aff_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

UnionPwMultiAff::UnionPwMultiAff(UnionPwAff obj) {
  ptr = isl_union_pw_multi_aff_from_union_pw_aff(obj.release());
}

UnionPwMultiAff::UnionPwMultiAff(PwMultiAff obj) {
  ptr = isl_union_pw_multi_aff_from_pw_multi_aff(obj.release());
}

UnionPwMultiAff& UnionPwMultiAff::operator=(UnionPwMultiAff obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

UnionPwMultiAff::~UnionPwMultiAff() {
  if (ptr)
    isl_union_pw_multi_aff_free(ptr);
}

__isl_give isl_union_pw_multi_aff *UnionPwMultiAff::copy() const & {
  return isl_union_pw_multi_aff_copy(ptr);
}

__isl_keep isl_union_pw_multi_aff *UnionPwMultiAff::get() const {
  return ptr;
}

__isl_give isl_union_pw_multi_aff *UnionPwMultiAff::release() {
  isl_union_pw_multi_aff *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool UnionPwMultiAff::isNull() const {
  return ptr == nullptr;
}

std::string UnionPwMultiAff::getStr() const {
  char *Tmp = isl_union_pw_multi_aff_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  UnionPwMultiAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionPwMultiAff& UnionPwMultiAff::add(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_add(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

UnionPwMultiAff& UnionPwMultiAff::flatRangeProduct(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_flat_range_product(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

UnionPwMultiAff& UnionPwMultiAff::pullback(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_pullback_union_pw_multi_aff(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

UnionPwMultiAff& UnionPwMultiAff::unionAdd(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_union_add(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
   return *this;
}

// implementations for isl::UnionSet
UnionSet manage(__isl_take isl_union_set *ptr) {
  return UnionSet(ptr);
}

UnionSet::UnionSet() : ptr(nullptr) {}

UnionSet::UnionSet(const UnionSet &obj) : ptr(obj.copy()) {}

UnionSet::UnionSet(__isl_take isl_union_set *ptr) : ptr(ptr) {}

UnionSet::UnionSet(BasicSet obj) {
  ptr = isl_union_set_from_basic_set(obj.release());
}

UnionSet::UnionSet(Set obj) {
  ptr = isl_union_set_from_set(obj.release());
}

UnionSet::UnionSet(Point obj) {
  ptr = isl_union_set_from_point(obj.release());
}

UnionSet UnionSet::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_union_set_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

UnionSet& UnionSet::operator=(UnionSet obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

UnionSet::~UnionSet() {
  if (ptr)
    isl_union_set_free(ptr);
}

__isl_give isl_union_set *UnionSet::copy() const & {
  return isl_union_set_copy(ptr);
}

__isl_keep isl_union_set *UnionSet::get() const {
  return ptr;
}

__isl_give isl_union_set *UnionSet::release() {
  isl_union_set *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool UnionSet::isNull() const {
  return ptr == nullptr;
}

std::string UnionSet::getStr() const {
  char *Tmp = isl_union_set_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  UnionSet &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
UnionSet& UnionSet::affineHull() {
   auto res = isl_union_set_affine_hull(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::apply(UnionMap umap) {
   auto res = isl_union_set_apply(copy(), umap.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::coalesce() {
   auto res = isl_union_set_coalesce(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::computeDivs() {
   auto res = isl_union_set_compute_divs(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::detectEqualities() {
   auto res = isl_union_set_detect_equalities(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::gist(UnionSet context) {
   auto res = isl_union_set_gist(copy(), context.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::gistParams(Set set) {
   auto res = isl_union_set_gist_params(copy(), set.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionMap UnionSet::identity() const {
   auto res = isl_union_set_identity(copy());
   return manage(res);
}

UnionSet& UnionSet::intersect(UnionSet uset2) {
   auto res = isl_union_set_intersect(copy(), uset2.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::intersectParams(Set set) {
   auto res = isl_union_set_intersect_params(copy(), set.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

Bool UnionSet::isEmpty() const {
   auto res = isl_union_set_is_empty(get());
   return res;
}

Bool UnionSet::isEqual(const UnionSet &uset2) const {
   auto res = isl_union_set_is_equal(get(), uset2.get());
   return res;
}

Bool UnionSet::isStrictSubset(const UnionSet &uset2) const {
   auto res = isl_union_set_is_strict_subset(get(), uset2.get());
   return res;
}

Bool UnionSet::isSubset(const UnionSet &uset2) const {
   auto res = isl_union_set_is_subset(get(), uset2.get());
   return res;
}

UnionSet& UnionSet::lexmax() {
   auto res = isl_union_set_lexmax(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::lexmin() {
   auto res = isl_union_set_lexmin(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::polyhedralHull() {
   auto res = isl_union_set_polyhedral_hull(copy());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

Point UnionSet::samplePoint() const {
   auto res = isl_union_set_sample_point(copy());
   return manage(res);
}

UnionSet& UnionSet::subtract(UnionSet uset2) {
   auto res = isl_union_set_subtract(copy(), uset2.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionSet& UnionSet::unite(UnionSet uset2) {
   auto res = isl_union_set_union(copy(), uset2.release());
   isl_union_set_free(ptr);
   ptr = res;
   return *this;
}

UnionMap UnionSet::unwrap() const {
   auto res = isl_union_set_unwrap(copy());
   return manage(res);
}

// implementations for isl::Val
Val manage(__isl_take isl_val *ptr) {
  return Val(ptr);
}

Val::Val() : ptr(nullptr) {}

Val::Val(const Val &obj) : ptr(obj.copy()) {}

Val::Val(__isl_take isl_val *ptr) : ptr(ptr) {}

Val Val::intFromSi(Ctx ctx, long i) {
   auto res = isl_val_int_from_si(ctx.release(), i);
   return manage(res);
}

Val Val::readFromStr(Ctx ctx, std::string str) {
   auto res = isl_val_read_from_str(ctx.release(), str.c_str());
   return manage(res);
}

Val& Val::operator=(Val obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Val::~Val() {
  if (ptr)
    isl_val_free(ptr);
}

__isl_give isl_val *Val::copy() const & {
  return isl_val_copy(ptr);
}

__isl_keep isl_val *Val::get() const {
  return ptr;
}

__isl_give isl_val *Val::release() {
  isl_val *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

bool Val::isNull() const {
  return ptr == nullptr;
}

std::string Val::getStr() const {
  char *Tmp = isl_val_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return Tmp;
}

#ifdef LLVM_OSTREAM
inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  Val &Obj) {
  OS << Obj.getStr();
  return OS;
}

#endif
Val& Val::abs() {
   auto res = isl_val_abs(copy());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Bool Val::absEq(const Val &v2) const {
   auto res = isl_val_abs_eq(get(), v2.get());
   return res;
}

Val& Val::add(Val v2) {
   auto res = isl_val_add(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::addUi(unsigned long v2) {
   auto res = isl_val_add_ui(copy(), v2);
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::ceil() {
   auto res = isl_val_ceil(copy());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

int Val::cmpSi(long i) const {
   auto res = isl_val_cmp_si(get(), i);
   return res;
}

Val& Val::div(Val v2) {
   auto res = isl_val_div(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Bool Val::eq(const Val &v2) const {
   auto res = isl_val_eq(get(), v2.get());
   return res;
}

Val& Val::floor() {
   auto res = isl_val_floor(copy());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::gcd(Val v2) {
   auto res = isl_val_gcd(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Bool Val::ge(const Val &v2) const {
   auto res = isl_val_ge(get(), v2.get());
   return res;
}

Bool Val::gt(const Val &v2) const {
   auto res = isl_val_gt(get(), v2.get());
   return res;
}

Val Val::infty(Ctx ctx) {
   auto res = isl_val_infty(ctx.release());
   return manage(res);
}

Val& Val::inv() {
   auto res = isl_val_inv(copy());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Bool Val::isDivisibleBy(const Val &v2) const {
   auto res = isl_val_is_divisible_by(get(), v2.get());
   return res;
}

Bool Val::isInfty() const {
   auto res = isl_val_is_infty(get());
   return res;
}

Bool Val::isInt() const {
   auto res = isl_val_is_int(get());
   return res;
}

Bool Val::isNan() const {
   auto res = isl_val_is_nan(get());
   return res;
}

Bool Val::isNeg() const {
   auto res = isl_val_is_neg(get());
   return res;
}

Bool Val::isNeginfty() const {
   auto res = isl_val_is_neginfty(get());
   return res;
}

Bool Val::isNegone() const {
   auto res = isl_val_is_negone(get());
   return res;
}

Bool Val::isNonneg() const {
   auto res = isl_val_is_nonneg(get());
   return res;
}

Bool Val::isNonpos() const {
   auto res = isl_val_is_nonpos(get());
   return res;
}

Bool Val::isOne() const {
   auto res = isl_val_is_one(get());
   return res;
}

Bool Val::isPos() const {
   auto res = isl_val_is_pos(get());
   return res;
}

Bool Val::isRat() const {
   auto res = isl_val_is_rat(get());
   return res;
}

Bool Val::isZero() const {
   auto res = isl_val_is_zero(get());
   return res;
}

Bool Val::le(const Val &v2) const {
   auto res = isl_val_le(get(), v2.get());
   return res;
}

Bool Val::lt(const Val &v2) const {
   auto res = isl_val_lt(get(), v2.get());
   return res;
}

Val& Val::max(Val v2) {
   auto res = isl_val_max(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::min(Val v2) {
   auto res = isl_val_min(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::mod(Val v2) {
   auto res = isl_val_mod(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::mul(Val v2) {
   auto res = isl_val_mul(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val Val::nan(Ctx ctx) {
   auto res = isl_val_nan(ctx.release());
   return manage(res);
}

Bool Val::ne(const Val &v2) const {
   auto res = isl_val_ne(get(), v2.get());
   return res;
}

Val& Val::neg() {
   auto res = isl_val_neg(copy());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val Val::neginfty(Ctx ctx) {
   auto res = isl_val_neginfty(ctx.release());
   return manage(res);
}

Val Val::negone(Ctx ctx) {
   auto res = isl_val_negone(ctx.release());
   return manage(res);
}

Val Val::one(Ctx ctx) {
   auto res = isl_val_one(ctx.release());
   return manage(res);
}

int Val::sgn() const {
   auto res = isl_val_sgn(get());
   return res;
}

Val& Val::sub(Val v2) {
   auto res = isl_val_sub(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val& Val::trunc() {
   auto res = isl_val_trunc(copy());
   isl_val_free(ptr);
   ptr = res;
   return *this;
}

Val Val::zero(Ctx ctx) {
   auto res = isl_val_zero(ctx.release());
   return manage(res);
}

};

#endif /* ISL_CPP_ALL */
