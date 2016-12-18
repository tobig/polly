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
  inline void add(Aff aff2);
  inline Val getConstantVal() const;
  inline Bool isCst() const;
  inline void pullback(MultiAff ma);
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
  inline void affineHull();
  inline void applyDomain(BasicMap bmap2);
  inline void applyRange(BasicMap bmap2);
  inline BasicSet deltas() const;
  inline void detectEqualities();
  inline void flatten();
  inline void flattenDomain();
  inline void flattenRange();
  inline void gist(BasicMap context);
  inline void intersect(BasicMap bmap2);
  inline void intersectDomain(BasicSet bset);
  inline void intersectRange(BasicSet bset);
  inline Bool isEmpty() const;
  inline Bool isEqual(const BasicMap &bmap2) const;
  inline Bool isSubset(const BasicMap &bmap2) const;
  inline Map lexmax() const;
  inline Map lexmin() const;
  inline Val plainGetValIfFixed(enum DimType type, unsigned int pos) const;
  inline void projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline void reverse();
  inline void sample();
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
  inline void affineHull();
  inline void apply(BasicMap bmap);
  inline void detectEqualities();
  inline void flatten();
  inline void gist(BasicSet context);
  inline void intersect(BasicSet bset2);
  inline void intersectParams(BasicSet bset2);
  inline int isBounded() const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const BasicSet &bset2) const;
  inline Bool isSubset(const BasicSet &bset2) const;
  inline Bool isWrapping() const;
  inline Set lexmax() const;
  inline Set lexmin() const;
  inline void projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline void sample();
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
  inline void applyDomain(Map map2);
  inline void applyRange(Map map2);
  inline void coalesce();
  inline void complement();
  inline Set deltas() const;
  inline void detectEqualities();
  inline unsigned int dim(enum DimType type) const;
  inline PwAff dimMax(int pos) const;
  inline PwAff dimMin(int pos) const;
  inline void flatten();
  inline void flattenDomain();
  inline void flattenRange();
  inline void gist(Map context);
  inline void gistDomain(Set context);
  inline void intersect(Map map2);
  inline void intersectDomain(Set set);
  inline void intersectParams(Set params);
  inline void intersectRange(Set set);
  inline Bool isBijective() const;
  inline Bool isDisjoint(const Map &map2) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const Map &map2) const;
  inline Bool isInjective() const;
  inline Bool isSingleValued() const;
  inline Bool isStrictSubset(const Map &map2) const;
  inline Bool isSubset(const Map &map2) const;
  inline void lexmax();
  inline void lexmin();
  inline BasicMap polyhedralHull() const;
  inline void projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline void reverse();
  inline BasicMap sample() const;
  inline void subtract(Map map2);
  inline void unite(Map map2);
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
  inline void add(MultiAff multi2);
  inline void flatRangeProduct(MultiAff multi2);
  inline void product(MultiAff multi2);
  inline void pullback(MultiAff ma2);
  inline void rangeProduct(MultiAff multi2);
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
  inline void add(MultiPwAff multi2);
  inline void flatRangeProduct(MultiPwAff multi2);
  inline void product(MultiPwAff multi2);
  inline void pullback(MultiAff ma);
  inline void pullback(PwMultiAff pma);
  inline void pullback(MultiPwAff mpa2);
  inline void rangeProduct(MultiPwAff multi2);
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
  inline void add(MultiUnionPwAff multi2);
  inline void flatRangeProduct(MultiUnionPwAff multi2);
  inline void pullback(UnionPwMultiAff upma);
  inline void rangeProduct(MultiUnionPwAff multi2);
  inline void unionAdd(MultiUnionPwAff mupa2);
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
  inline void add(MultiVal multi2);
  inline void flatRangeProduct(MultiVal multi2);
  inline void product(MultiVal multi2);
  inline void rangeProduct(MultiVal multi2);
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
  inline void add(PwAff pwaff2);
  inline void mul(PwAff pwaff2);
  inline void neg();
  inline void pullback(MultiAff ma);
  inline void pullback(PwMultiAff pma);
  inline void pullback(MultiPwAff mpa);
  inline void sub(PwAff pwaff2);
  inline void unionAdd(PwAff pwaff2);
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
  inline void add(PwMultiAff pma2);
  inline void flatRangeProduct(PwMultiAff pma2);
  inline void product(PwMultiAff pma2);
  inline void pullback(MultiAff ma);
  inline void pullback(PwMultiAff pma2);
  inline void rangeProduct(PwMultiAff pma2);
  inline void unionAdd(PwMultiAff pma2);
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
  inline void pullback(UnionPwMultiAff upma);
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
  inline void bandMemberSetCoincident(int pos, int coincident);
  inline void child(int pos);
  inline MultiUnionPwAff getPrefixScheduleMultiUnionPwAff() const;
  inline UnionMap getPrefixScheduleUnionMap() const;
  inline UnionPwMultiAff getPrefixScheduleUnionPwMultiAff() const;
  inline Schedule getSchedule() const;
  inline void parent();
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
  inline void addDims(enum DimType type, unsigned int n);
  inline BasicSet affineHull() const;
  inline void apply(Map map);
  inline void coalesce();
  inline void complement();
  inline void detectEqualities();
  inline unsigned int dim(enum DimType type) const;
  inline PwAff dimMax(int pos) const;
  inline PwAff dimMin(int pos) const;
  inline void flatten();
  inline void gist(Set context);
  inline Map identity() const;
  inline void intersect(Set set2);
  inline void intersectParams(Set params);
  inline int isBounded() const;
  inline Bool isDisjoint(const Set &set2) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const Set &set2) const;
  inline Bool isStrictSubset(const Set &set2) const;
  inline Bool isSubset(const Set &set2) const;
  inline Bool isWrapping() const;
  inline void lexmax();
  inline void lexmin();
  inline Val maxVal(const Aff &obj) const;
  inline Val minVal(const Aff &obj) const;
  inline BasicSet polyhedralHull() const;
  inline void projectOut(enum DimType type, unsigned int first, unsigned int n);
  inline BasicSet sample() const;
  inline Point samplePoint() const;
  inline void subtract(Set set2);
  inline void unite(Set set2);
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
  inline void setMaySource(UnionMap may_source);
  inline void setMustSource(UnionMap must_source);
  inline void setSchedule(Schedule schedule);
  inline void setScheduleMap(UnionMap schedule_map);
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
  inline void addMap(Map map);
  inline void affineHull();
  inline void applyDomain(UnionMap umap2);
  inline void applyRange(UnionMap umap2);
  inline void coalesce();
  inline void computeDivs();
  inline UnionSet deltas() const;
  inline void detectEqualities();
  inline UnionSet domain() const;
  inline void domainFactorDomain();
  inline void domainFactorRange();
  inline void domainMap();
  inline UnionPwMultiAff domainMapUnionPwMultiAff() const;
  inline void domainProduct(UnionMap umap2);
  inline void factorDomain();
  inline void factorRange();
  inline void fixedPower(Val exp);
  inline void flatRangeProduct(UnionMap umap2);
  static inline UnionMap from(UnionPwMultiAff upma);
  static inline UnionMap from(MultiUnionPwAff mupa);
  static inline UnionMap fromDomainAndRange(UnionSet domain, UnionSet range);
  inline void gist(UnionMap context);
  inline void gistDomain(UnionSet uset);
  inline void gistParams(Set set);
  inline void gistRange(UnionSet uset);
  inline void intersect(UnionMap umap2);
  inline void intersectDomain(UnionSet uset);
  inline void intersectParams(Set set);
  inline void intersectRange(UnionSet uset);
  inline Bool isBijective() const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const UnionMap &umap2) const;
  inline Bool isInjective() const;
  inline Bool isSingleValued() const;
  inline Bool isStrictSubset(const UnionMap &umap2) const;
  inline Bool isSubset(const UnionMap &umap2) const;
  inline void lexmax();
  inline void lexmin();
  inline void polyhedralHull();
  inline void product(UnionMap umap2);
  inline UnionSet range() const;
  inline void rangeFactorDomain();
  inline void rangeFactorRange();
  inline void rangeMap();
  inline void rangeProduct(UnionMap umap2);
  inline void reverse();
  inline void subtract(UnionMap umap2);
  inline void subtractDomain(UnionSet dom);
  inline void subtractRange(UnionSet dom);
  inline void unite(UnionMap umap2);
  inline UnionSet wrap() const;
  inline void zip();
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
  inline void add(UnionPwAff upa2);
  inline void pullback(UnionPwMultiAff upma);
  inline void sub(UnionPwAff upa2);
  inline void unionAdd(UnionPwAff upa2);
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
  inline void add(UnionPwMultiAff upma2);
  inline void flatRangeProduct(UnionPwMultiAff upma2);
  inline void pullback(UnionPwMultiAff upma2);
  inline void unionAdd(UnionPwMultiAff upma2);
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
  inline void affineHull();
  inline void apply(UnionMap umap);
  inline void coalesce();
  inline void computeDivs();
  inline void detectEqualities();
  inline void gist(UnionSet context);
  inline void gistParams(Set set);
  inline UnionMap identity() const;
  inline void intersect(UnionSet uset2);
  inline void intersectParams(Set set);
  inline Bool isEmpty() const;
  inline Bool isEqual(const UnionSet &uset2) const;
  inline Bool isStrictSubset(const UnionSet &uset2) const;
  inline Bool isSubset(const UnionSet &uset2) const;
  inline void lexmax();
  inline void lexmin();
  inline void polyhedralHull();
  inline Point samplePoint() const;
  inline void subtract(UnionSet uset2);
  inline void unite(UnionSet uset2);
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
  inline void abs();
  inline Bool absEq(const Val &v2) const;
  inline void add(Val v2);
  inline void addUi(unsigned long v2);
  inline void ceil();
  inline int cmpSi(long i) const;
  inline void div(Val v2);
  inline Bool eq(const Val &v2) const;
  inline void floor();
  inline void gcd(Val v2);
  inline Bool ge(const Val &v2) const;
  inline Bool gt(const Val &v2) const;
  static inline Val infty(Ctx ctx);
  inline void inv();
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
  inline void max(Val v2);
  inline void min(Val v2);
  inline void mod(Val v2);
  inline void mul(Val v2);
  static inline Val nan(Ctx ctx);
  inline Bool ne(const Val &v2) const;
  inline void neg();
  static inline Val neginfty(Ctx ctx);
  static inline Val negone(Ctx ctx);
  static inline Val one(Ctx ctx);
  inline int sgn() const;
  inline void sub(Val v2);
  inline void trunc();
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
void Aff::add(Aff aff2) {
   auto res = isl_aff_add(copy(), aff2.release());
   isl_aff_free(ptr);
   ptr = res;
}

inline Aff add(Aff aff1, Aff aff2) {
   auto res = isl_aff_add(aff1.release(), aff2.release());
   return manage(res);
}

Val Aff::getConstantVal() const {
   auto res = isl_aff_get_constant_val(get());
   return manage(res);
}

inline Val getConstantVal(const Aff &aff) {
   auto res = isl_aff_get_constant_val(aff.get());
   return manage(res);
}

Bool Aff::isCst() const {
   auto res = isl_aff_is_cst(get());
   return res;
}

inline Bool isCst(const Aff &aff) {
   auto res = isl_aff_is_cst(aff.get());
   return res;
}

void Aff::pullback(MultiAff ma) {
   auto res = isl_aff_pullback_multi_aff(copy(), ma.release());
   isl_aff_free(ptr);
   ptr = res;
}

inline Aff pullback(Aff aff, MultiAff ma) {
   auto res = isl_aff_pullback_multi_aff(aff.release(), ma.release());
   return manage(res);
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

inline AstExpr accessFrom(const AstBuild &build, PwMultiAff pma) {
   auto res = isl_ast_build_access_from_pw_multi_aff(build.get(), pma.release());
   return manage(res);
}

AstExpr AstBuild::accessFrom(MultiPwAff mpa) const {
   auto res = isl_ast_build_access_from_multi_pw_aff(get(), mpa.release());
   return manage(res);
}

inline AstExpr accessFrom(const AstBuild &build, MultiPwAff mpa) {
   auto res = isl_ast_build_access_from_multi_pw_aff(build.get(), mpa.release());
   return manage(res);
}

AstExpr AstBuild::callFrom(PwMultiAff pma) const {
   auto res = isl_ast_build_call_from_pw_multi_aff(get(), pma.release());
   return manage(res);
}

inline AstExpr callFrom(const AstBuild &build, PwMultiAff pma) {
   auto res = isl_ast_build_call_from_pw_multi_aff(build.get(), pma.release());
   return manage(res);
}

AstExpr AstBuild::callFrom(MultiPwAff mpa) const {
   auto res = isl_ast_build_call_from_multi_pw_aff(get(), mpa.release());
   return manage(res);
}

inline AstExpr callFrom(const AstBuild &build, MultiPwAff mpa) {
   auto res = isl_ast_build_call_from_multi_pw_aff(build.get(), mpa.release());
   return manage(res);
}

AstExpr AstBuild::exprFrom(Set set) const {
   auto res = isl_ast_build_expr_from_set(get(), set.release());
   return manage(res);
}

inline AstExpr exprFrom(const AstBuild &build, Set set) {
   auto res = isl_ast_build_expr_from_set(build.get(), set.release());
   return manage(res);
}

AstExpr AstBuild::exprFrom(PwAff pa) const {
   auto res = isl_ast_build_expr_from_pw_aff(get(), pa.release());
   return manage(res);
}

inline AstExpr exprFrom(const AstBuild &build, PwAff pa) {
   auto res = isl_ast_build_expr_from_pw_aff(build.get(), pa.release());
   return manage(res);
}

AstBuild AstBuild::fromContext(Set set) {
   auto res = isl_ast_build_from_context(set.release());
   return manage(res);
}

inline AstBuild fromContext(Set set) {
   auto res = isl_ast_build_from_context(set.release());
   return manage(res);
}

AstNode AstBuild::nodeFromScheduleMap(UnionMap schedule) const {
   auto res = isl_ast_build_node_from_schedule_map(get(), schedule.release());
   return manage(res);
}

inline AstNode nodeFromScheduleMap(const AstBuild &build, UnionMap schedule) {
   auto res = isl_ast_build_node_from_schedule_map(build.get(), schedule.release());
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

inline std::string toCStr(const AstExpr &expr) {
   auto res = isl_ast_expr_to_C_str(expr.get());
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

inline std::string toCStr(const AstNode &node) {
   auto res = isl_ast_node_to_C_str(node.get());
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
void BasicMap::affineHull() {
   auto res = isl_basic_map_affine_hull(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap affineHull(BasicMap bmap) {
   auto res = isl_basic_map_affine_hull(bmap.release());
   return manage(res);
}

void BasicMap::applyDomain(BasicMap bmap2) {
   auto res = isl_basic_map_apply_domain(copy(), bmap2.release());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap applyDomain(BasicMap bmap1, BasicMap bmap2) {
   auto res = isl_basic_map_apply_domain(bmap1.release(), bmap2.release());
   return manage(res);
}

void BasicMap::applyRange(BasicMap bmap2) {
   auto res = isl_basic_map_apply_range(copy(), bmap2.release());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap applyRange(BasicMap bmap1, BasicMap bmap2) {
   auto res = isl_basic_map_apply_range(bmap1.release(), bmap2.release());
   return manage(res);
}

BasicSet BasicMap::deltas() const {
   auto res = isl_basic_map_deltas(copy());
   return manage(res);
}

inline BasicSet deltas(BasicMap bmap) {
   auto res = isl_basic_map_deltas(bmap.release());
   return manage(res);
}

void BasicMap::detectEqualities() {
   auto res = isl_basic_map_detect_equalities(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap detectEqualities(BasicMap bmap) {
   auto res = isl_basic_map_detect_equalities(bmap.release());
   return manage(res);
}

void BasicMap::flatten() {
   auto res = isl_basic_map_flatten(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap flatten(BasicMap bmap) {
   auto res = isl_basic_map_flatten(bmap.release());
   return manage(res);
}

void BasicMap::flattenDomain() {
   auto res = isl_basic_map_flatten_domain(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap flattenDomain(BasicMap bmap) {
   auto res = isl_basic_map_flatten_domain(bmap.release());
   return manage(res);
}

void BasicMap::flattenRange() {
   auto res = isl_basic_map_flatten_range(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap flattenRange(BasicMap bmap) {
   auto res = isl_basic_map_flatten_range(bmap.release());
   return manage(res);
}

void BasicMap::gist(BasicMap context) {
   auto res = isl_basic_map_gist(copy(), context.release());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap gist(BasicMap bmap, BasicMap context) {
   auto res = isl_basic_map_gist(bmap.release(), context.release());
   return manage(res);
}

void BasicMap::intersect(BasicMap bmap2) {
   auto res = isl_basic_map_intersect(copy(), bmap2.release());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap intersect(BasicMap bmap1, BasicMap bmap2) {
   auto res = isl_basic_map_intersect(bmap1.release(), bmap2.release());
   return manage(res);
}

void BasicMap::intersectDomain(BasicSet bset) {
   auto res = isl_basic_map_intersect_domain(copy(), bset.release());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap intersectDomain(BasicMap bmap, BasicSet bset) {
   auto res = isl_basic_map_intersect_domain(bmap.release(), bset.release());
   return manage(res);
}

void BasicMap::intersectRange(BasicSet bset) {
   auto res = isl_basic_map_intersect_range(copy(), bset.release());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap intersectRange(BasicMap bmap, BasicSet bset) {
   auto res = isl_basic_map_intersect_range(bmap.release(), bset.release());
   return manage(res);
}

Bool BasicMap::isEmpty() const {
   auto res = isl_basic_map_is_empty(get());
   return res;
}

inline Bool isEmpty(const BasicMap &bmap) {
   auto res = isl_basic_map_is_empty(bmap.get());
   return res;
}

Bool BasicMap::isEqual(const BasicMap &bmap2) const {
   auto res = isl_basic_map_is_equal(get(), bmap2.get());
   return res;
}

inline Bool isEqual(const BasicMap &bmap1, const BasicMap &bmap2) {
   auto res = isl_basic_map_is_equal(bmap1.get(), bmap2.get());
   return res;
}

Bool BasicMap::isSubset(const BasicMap &bmap2) const {
   auto res = isl_basic_map_is_subset(get(), bmap2.get());
   return res;
}

inline Bool isSubset(const BasicMap &bmap1, const BasicMap &bmap2) {
   auto res = isl_basic_map_is_subset(bmap1.get(), bmap2.get());
   return res;
}

Map BasicMap::lexmax() const {
   auto res = isl_basic_map_lexmax(copy());
   return manage(res);
}

inline Map lexmax(BasicMap bmap) {
   auto res = isl_basic_map_lexmax(bmap.release());
   return manage(res);
}

Map BasicMap::lexmin() const {
   auto res = isl_basic_map_lexmin(copy());
   return manage(res);
}

inline Map lexmin(BasicMap bmap) {
   auto res = isl_basic_map_lexmin(bmap.release());
   return manage(res);
}

Val BasicMap::plainGetValIfFixed(enum DimType type, unsigned int pos) const {
   auto res = isl_basic_map_plain_get_val_if_fixed(get(), static_cast<enum isl_dim_type>(type), pos);
   return manage(res);
}

inline Val plainGetValIfFixed(const BasicMap &bmap, enum DimType type, unsigned int pos) {
   auto res = isl_basic_map_plain_get_val_if_fixed(bmap.get(), static_cast<enum isl_dim_type>(type), pos);
   return manage(res);
}

void BasicMap::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_basic_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap projectOut(BasicMap bmap, enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_basic_map_project_out(bmap.release(), static_cast<enum isl_dim_type>(type), first, n);
   return manage(res);
}

void BasicMap::reverse() {
   auto res = isl_basic_map_reverse(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap reverse(BasicMap bmap) {
   auto res = isl_basic_map_reverse(bmap.release());
   return manage(res);
}

void BasicMap::sample() {
   auto res = isl_basic_map_sample(copy());
   isl_basic_map_free(ptr);
   ptr = res;
}

inline BasicMap sample(BasicMap bmap) {
   auto res = isl_basic_map_sample(bmap.release());
   return manage(res);
}

Map BasicMap::unite(BasicMap bmap2) const {
   auto res = isl_basic_map_union(copy(), bmap2.release());
   return manage(res);
}

inline Map unite(BasicMap bmap1, BasicMap bmap2) {
   auto res = isl_basic_map_union(bmap1.release(), bmap2.release());
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
void BasicSet::affineHull() {
   auto res = isl_basic_set_affine_hull(copy());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet affineHull(BasicSet bset) {
   auto res = isl_basic_set_affine_hull(bset.release());
   return manage(res);
}

void BasicSet::apply(BasicMap bmap) {
   auto res = isl_basic_set_apply(copy(), bmap.release());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet apply(BasicSet bset, BasicMap bmap) {
   auto res = isl_basic_set_apply(bset.release(), bmap.release());
   return manage(res);
}

void BasicSet::detectEqualities() {
   auto res = isl_basic_set_detect_equalities(copy());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet detectEqualities(BasicSet bset) {
   auto res = isl_basic_set_detect_equalities(bset.release());
   return manage(res);
}

void BasicSet::flatten() {
   auto res = isl_basic_set_flatten(copy());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet flatten(BasicSet bset) {
   auto res = isl_basic_set_flatten(bset.release());
   return manage(res);
}

void BasicSet::gist(BasicSet context) {
   auto res = isl_basic_set_gist(copy(), context.release());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet gist(BasicSet bset, BasicSet context) {
   auto res = isl_basic_set_gist(bset.release(), context.release());
   return manage(res);
}

void BasicSet::intersect(BasicSet bset2) {
   auto res = isl_basic_set_intersect(copy(), bset2.release());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet intersect(BasicSet bset1, BasicSet bset2) {
   auto res = isl_basic_set_intersect(bset1.release(), bset2.release());
   return manage(res);
}

void BasicSet::intersectParams(BasicSet bset2) {
   auto res = isl_basic_set_intersect_params(copy(), bset2.release());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet intersectParams(BasicSet bset1, BasicSet bset2) {
   auto res = isl_basic_set_intersect_params(bset1.release(), bset2.release());
   return manage(res);
}

int BasicSet::isBounded() const {
   auto res = isl_basic_set_is_bounded(get());
   return res;
}

inline int isBounded(const BasicSet &bset) {
   auto res = isl_basic_set_is_bounded(bset.get());
   return res;
}

Bool BasicSet::isEmpty() const {
   auto res = isl_basic_set_is_empty(get());
   return res;
}

inline Bool isEmpty(const BasicSet &bset) {
   auto res = isl_basic_set_is_empty(bset.get());
   return res;
}

Bool BasicSet::isEqual(const BasicSet &bset2) const {
   auto res = isl_basic_set_is_equal(get(), bset2.get());
   return res;
}

inline Bool isEqual(const BasicSet &bset1, const BasicSet &bset2) {
   auto res = isl_basic_set_is_equal(bset1.get(), bset2.get());
   return res;
}

Bool BasicSet::isSubset(const BasicSet &bset2) const {
   auto res = isl_basic_set_is_subset(get(), bset2.get());
   return res;
}

inline Bool isSubset(const BasicSet &bset1, const BasicSet &bset2) {
   auto res = isl_basic_set_is_subset(bset1.get(), bset2.get());
   return res;
}

Bool BasicSet::isWrapping() const {
   auto res = isl_basic_set_is_wrapping(get());
   return res;
}

inline Bool isWrapping(const BasicSet &bset) {
   auto res = isl_basic_set_is_wrapping(bset.get());
   return res;
}

Set BasicSet::lexmax() const {
   auto res = isl_basic_set_lexmax(copy());
   return manage(res);
}

inline Set lexmax(BasicSet bset) {
   auto res = isl_basic_set_lexmax(bset.release());
   return manage(res);
}

Set BasicSet::lexmin() const {
   auto res = isl_basic_set_lexmin(copy());
   return manage(res);
}

inline Set lexmin(BasicSet bset) {
   auto res = isl_basic_set_lexmin(bset.release());
   return manage(res);
}

void BasicSet::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_basic_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet projectOut(BasicSet bset, enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_basic_set_project_out(bset.release(), static_cast<enum isl_dim_type>(type), first, n);
   return manage(res);
}

void BasicSet::sample() {
   auto res = isl_basic_set_sample(copy());
   isl_basic_set_free(ptr);
   ptr = res;
}

inline BasicSet sample(BasicSet bset) {
   auto res = isl_basic_set_sample(bset.release());
   return manage(res);
}

Point BasicSet::samplePoint() const {
   auto res = isl_basic_set_sample_point(copy());
   return manage(res);
}

inline Point samplePoint(BasicSet bset) {
   auto res = isl_basic_set_sample_point(bset.release());
   return manage(res);
}

Set BasicSet::unite(BasicSet bset2) const {
   auto res = isl_basic_set_union(copy(), bset2.release());
   return manage(res);
}

inline Set unite(BasicSet bset1, BasicSet bset2) {
   auto res = isl_basic_set_union(bset1.release(), bset2.release());
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

inline BasicMap affineHull(Map map) {
   auto res = isl_map_affine_hull(map.release());
   return manage(res);
}

void Map::applyDomain(Map map2) {
   auto res = isl_map_apply_domain(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map applyDomain(Map map1, Map map2) {
   auto res = isl_map_apply_domain(map1.release(), map2.release());
   return manage(res);
}

void Map::applyRange(Map map2) {
   auto res = isl_map_apply_range(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map applyRange(Map map1, Map map2) {
   auto res = isl_map_apply_range(map1.release(), map2.release());
   return manage(res);
}

void Map::coalesce() {
   auto res = isl_map_coalesce(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map coalesce(Map map) {
   auto res = isl_map_coalesce(map.release());
   return manage(res);
}

void Map::complement() {
   auto res = isl_map_complement(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map complement(Map map) {
   auto res = isl_map_complement(map.release());
   return manage(res);
}

Set Map::deltas() const {
   auto res = isl_map_deltas(copy());
   return manage(res);
}

inline Set deltas(Map map) {
   auto res = isl_map_deltas(map.release());
   return manage(res);
}

void Map::detectEqualities() {
   auto res = isl_map_detect_equalities(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map detectEqualities(Map map) {
   auto res = isl_map_detect_equalities(map.release());
   return manage(res);
}

unsigned int Map::dim(enum DimType type) const {
   auto res = isl_map_dim(get(), static_cast<enum isl_dim_type>(type));
   return res;
}

inline unsigned int dim(const Map &map, enum DimType type) {
   auto res = isl_map_dim(map.get(), static_cast<enum isl_dim_type>(type));
   return res;
}

PwAff Map::dimMax(int pos) const {
   auto res = isl_map_dim_max(copy(), pos);
   return manage(res);
}

inline PwAff dimMax(Map map, int pos) {
   auto res = isl_map_dim_max(map.release(), pos);
   return manage(res);
}

PwAff Map::dimMin(int pos) const {
   auto res = isl_map_dim_min(copy(), pos);
   return manage(res);
}

inline PwAff dimMin(Map map, int pos) {
   auto res = isl_map_dim_min(map.release(), pos);
   return manage(res);
}

void Map::flatten() {
   auto res = isl_map_flatten(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map flatten(Map map) {
   auto res = isl_map_flatten(map.release());
   return manage(res);
}

void Map::flattenDomain() {
   auto res = isl_map_flatten_domain(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map flattenDomain(Map map) {
   auto res = isl_map_flatten_domain(map.release());
   return manage(res);
}

void Map::flattenRange() {
   auto res = isl_map_flatten_range(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map flattenRange(Map map) {
   auto res = isl_map_flatten_range(map.release());
   return manage(res);
}

void Map::gist(Map context) {
   auto res = isl_map_gist(copy(), context.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map gist(Map map, Map context) {
   auto res = isl_map_gist(map.release(), context.release());
   return manage(res);
}

void Map::gistDomain(Set context) {
   auto res = isl_map_gist_domain(copy(), context.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map gistDomain(Map map, Set context) {
   auto res = isl_map_gist_domain(map.release(), context.release());
   return manage(res);
}

void Map::intersect(Map map2) {
   auto res = isl_map_intersect(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map intersect(Map map1, Map map2) {
   auto res = isl_map_intersect(map1.release(), map2.release());
   return manage(res);
}

void Map::intersectDomain(Set set) {
   auto res = isl_map_intersect_domain(copy(), set.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map intersectDomain(Map map, Set set) {
   auto res = isl_map_intersect_domain(map.release(), set.release());
   return manage(res);
}

void Map::intersectParams(Set params) {
   auto res = isl_map_intersect_params(copy(), params.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map intersectParams(Map map, Set params) {
   auto res = isl_map_intersect_params(map.release(), params.release());
   return manage(res);
}

void Map::intersectRange(Set set) {
   auto res = isl_map_intersect_range(copy(), set.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map intersectRange(Map map, Set set) {
   auto res = isl_map_intersect_range(map.release(), set.release());
   return manage(res);
}

Bool Map::isBijective() const {
   auto res = isl_map_is_bijective(get());
   return res;
}

inline Bool isBijective(const Map &map) {
   auto res = isl_map_is_bijective(map.get());
   return res;
}

Bool Map::isDisjoint(const Map &map2) const {
   auto res = isl_map_is_disjoint(get(), map2.get());
   return res;
}

inline Bool isDisjoint(const Map &map1, const Map &map2) {
   auto res = isl_map_is_disjoint(map1.get(), map2.get());
   return res;
}

Bool Map::isEmpty() const {
   auto res = isl_map_is_empty(get());
   return res;
}

inline Bool isEmpty(const Map &map) {
   auto res = isl_map_is_empty(map.get());
   return res;
}

Bool Map::isEqual(const Map &map2) const {
   auto res = isl_map_is_equal(get(), map2.get());
   return res;
}

inline Bool isEqual(const Map &map1, const Map &map2) {
   auto res = isl_map_is_equal(map1.get(), map2.get());
   return res;
}

Bool Map::isInjective() const {
   auto res = isl_map_is_injective(get());
   return res;
}

inline Bool isInjective(const Map &map) {
   auto res = isl_map_is_injective(map.get());
   return res;
}

Bool Map::isSingleValued() const {
   auto res = isl_map_is_single_valued(get());
   return res;
}

inline Bool isSingleValued(const Map &map) {
   auto res = isl_map_is_single_valued(map.get());
   return res;
}

Bool Map::isStrictSubset(const Map &map2) const {
   auto res = isl_map_is_strict_subset(get(), map2.get());
   return res;
}

inline Bool isStrictSubset(const Map &map1, const Map &map2) {
   auto res = isl_map_is_strict_subset(map1.get(), map2.get());
   return res;
}

Bool Map::isSubset(const Map &map2) const {
   auto res = isl_map_is_subset(get(), map2.get());
   return res;
}

inline Bool isSubset(const Map &map1, const Map &map2) {
   auto res = isl_map_is_subset(map1.get(), map2.get());
   return res;
}

void Map::lexmax() {
   auto res = isl_map_lexmax(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map lexmax(Map map) {
   auto res = isl_map_lexmax(map.release());
   return manage(res);
}

void Map::lexmin() {
   auto res = isl_map_lexmin(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map lexmin(Map map) {
   auto res = isl_map_lexmin(map.release());
   return manage(res);
}

BasicMap Map::polyhedralHull() const {
   auto res = isl_map_polyhedral_hull(copy());
   return manage(res);
}

inline BasicMap polyhedralHull(Map map) {
   auto res = isl_map_polyhedral_hull(map.release());
   return manage(res);
}

void Map::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_map_free(ptr);
   ptr = res;
}

inline Map projectOut(Map map, enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_map_project_out(map.release(), static_cast<enum isl_dim_type>(type), first, n);
   return manage(res);
}

void Map::reverse() {
   auto res = isl_map_reverse(copy());
   isl_map_free(ptr);
   ptr = res;
}

inline Map reverse(Map map) {
   auto res = isl_map_reverse(map.release());
   return manage(res);
}

BasicMap Map::sample() const {
   auto res = isl_map_sample(copy());
   return manage(res);
}

inline BasicMap sample(Map map) {
   auto res = isl_map_sample(map.release());
   return manage(res);
}

void Map::subtract(Map map2) {
   auto res = isl_map_subtract(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map subtract(Map map1, Map map2) {
   auto res = isl_map_subtract(map1.release(), map2.release());
   return manage(res);
}

void Map::unite(Map map2) {
   auto res = isl_map_union(copy(), map2.release());
   isl_map_free(ptr);
   ptr = res;
}

inline Map unite(Map map1, Map map2) {
   auto res = isl_map_union(map1.release(), map2.release());
   return manage(res);
}

BasicMap Map::unshiftedSimpleHull() const {
   auto res = isl_map_unshifted_simple_hull(copy());
   return manage(res);
}

inline BasicMap unshiftedSimpleHull(Map map) {
   auto res = isl_map_unshifted_simple_hull(map.release());
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
void MultiAff::add(MultiAff multi2) {
   auto res = isl_multi_aff_add(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
}

inline MultiAff add(MultiAff multi1, MultiAff multi2) {
   auto res = isl_multi_aff_add(multi1.release(), multi2.release());
   return manage(res);
}

void MultiAff::flatRangeProduct(MultiAff multi2) {
   auto res = isl_multi_aff_flat_range_product(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
}

inline MultiAff flatRangeProduct(MultiAff multi1, MultiAff multi2) {
   auto res = isl_multi_aff_flat_range_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiAff::product(MultiAff multi2) {
   auto res = isl_multi_aff_product(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
}

inline MultiAff product(MultiAff multi1, MultiAff multi2) {
   auto res = isl_multi_aff_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiAff::pullback(MultiAff ma2) {
   auto res = isl_multi_aff_pullback_multi_aff(copy(), ma2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
}

inline MultiAff pullback(MultiAff ma1, MultiAff ma2) {
   auto res = isl_multi_aff_pullback_multi_aff(ma1.release(), ma2.release());
   return manage(res);
}

void MultiAff::rangeProduct(MultiAff multi2) {
   auto res = isl_multi_aff_range_product(copy(), multi2.release());
   isl_multi_aff_free(ptr);
   ptr = res;
}

inline MultiAff rangeProduct(MultiAff multi1, MultiAff multi2) {
   auto res = isl_multi_aff_range_product(multi1.release(), multi2.release());
   return manage(res);
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
void MultiPwAff::add(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_add(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff add(MultiPwAff multi1, MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_add(multi1.release(), multi2.release());
   return manage(res);
}

void MultiPwAff::flatRangeProduct(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_flat_range_product(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff flatRangeProduct(MultiPwAff multi1, MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_flat_range_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiPwAff::product(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_product(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff product(MultiPwAff multi1, MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiPwAff::pullback(MultiAff ma) {
   auto res = isl_multi_pw_aff_pullback_multi_aff(copy(), ma.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff pullback(MultiPwAff mpa, MultiAff ma) {
   auto res = isl_multi_pw_aff_pullback_multi_aff(mpa.release(), ma.release());
   return manage(res);
}

void MultiPwAff::pullback(PwMultiAff pma) {
   auto res = isl_multi_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff pullback(MultiPwAff mpa, PwMultiAff pma) {
   auto res = isl_multi_pw_aff_pullback_pw_multi_aff(mpa.release(), pma.release());
   return manage(res);
}

void MultiPwAff::pullback(MultiPwAff mpa2) {
   auto res = isl_multi_pw_aff_pullback_multi_pw_aff(copy(), mpa2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff pullback(MultiPwAff mpa1, MultiPwAff mpa2) {
   auto res = isl_multi_pw_aff_pullback_multi_pw_aff(mpa1.release(), mpa2.release());
   return manage(res);
}

void MultiPwAff::rangeProduct(MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_range_product(copy(), multi2.release());
   isl_multi_pw_aff_free(ptr);
   ptr = res;
}

inline MultiPwAff rangeProduct(MultiPwAff multi1, MultiPwAff multi2) {
   auto res = isl_multi_pw_aff_range_product(multi1.release(), multi2.release());
   return manage(res);
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
void MultiUnionPwAff::add(MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_add(copy(), multi2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
}

inline MultiUnionPwAff add(MultiUnionPwAff multi1, MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_add(multi1.release(), multi2.release());
   return manage(res);
}

void MultiUnionPwAff::flatRangeProduct(MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_flat_range_product(copy(), multi2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
}

inline MultiUnionPwAff flatRangeProduct(MultiUnionPwAff multi1, MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_flat_range_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiUnionPwAff::pullback(UnionPwMultiAff upma) {
   auto res = isl_multi_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
}

inline MultiUnionPwAff pullback(MultiUnionPwAff mupa, UnionPwMultiAff upma) {
   auto res = isl_multi_union_pw_aff_pullback_union_pw_multi_aff(mupa.release(), upma.release());
   return manage(res);
}

void MultiUnionPwAff::rangeProduct(MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_range_product(copy(), multi2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
}

inline MultiUnionPwAff rangeProduct(MultiUnionPwAff multi1, MultiUnionPwAff multi2) {
   auto res = isl_multi_union_pw_aff_range_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiUnionPwAff::unionAdd(MultiUnionPwAff mupa2) {
   auto res = isl_multi_union_pw_aff_union_add(copy(), mupa2.release());
   isl_multi_union_pw_aff_free(ptr);
   ptr = res;
}

inline MultiUnionPwAff unionAdd(MultiUnionPwAff mupa1, MultiUnionPwAff mupa2) {
   auto res = isl_multi_union_pw_aff_union_add(mupa1.release(), mupa2.release());
   return manage(res);
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
void MultiVal::add(MultiVal multi2) {
   auto res = isl_multi_val_add(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
}

inline MultiVal add(MultiVal multi1, MultiVal multi2) {
   auto res = isl_multi_val_add(multi1.release(), multi2.release());
   return manage(res);
}

void MultiVal::flatRangeProduct(MultiVal multi2) {
   auto res = isl_multi_val_flat_range_product(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
}

inline MultiVal flatRangeProduct(MultiVal multi1, MultiVal multi2) {
   auto res = isl_multi_val_flat_range_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiVal::product(MultiVal multi2) {
   auto res = isl_multi_val_product(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
}

inline MultiVal product(MultiVal multi1, MultiVal multi2) {
   auto res = isl_multi_val_product(multi1.release(), multi2.release());
   return manage(res);
}

void MultiVal::rangeProduct(MultiVal multi2) {
   auto res = isl_multi_val_range_product(copy(), multi2.release());
   isl_multi_val_free(ptr);
   ptr = res;
}

inline MultiVal rangeProduct(MultiVal multi1, MultiVal multi2) {
   auto res = isl_multi_val_range_product(multi1.release(), multi2.release());
   return manage(res);
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
void PwAff::add(PwAff pwaff2) {
   auto res = isl_pw_aff_add(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff add(PwAff pwaff1, PwAff pwaff2) {
   auto res = isl_pw_aff_add(pwaff1.release(), pwaff2.release());
   return manage(res);
}

void PwAff::mul(PwAff pwaff2) {
   auto res = isl_pw_aff_mul(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff mul(PwAff pwaff1, PwAff pwaff2) {
   auto res = isl_pw_aff_mul(pwaff1.release(), pwaff2.release());
   return manage(res);
}

void PwAff::neg() {
   auto res = isl_pw_aff_neg(copy());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff neg(PwAff pwaff) {
   auto res = isl_pw_aff_neg(pwaff.release());
   return manage(res);
}

void PwAff::pullback(MultiAff ma) {
   auto res = isl_pw_aff_pullback_multi_aff(copy(), ma.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff pullback(PwAff pa, MultiAff ma) {
   auto res = isl_pw_aff_pullback_multi_aff(pa.release(), ma.release());
   return manage(res);
}

void PwAff::pullback(PwMultiAff pma) {
   auto res = isl_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff pullback(PwAff pa, PwMultiAff pma) {
   auto res = isl_pw_aff_pullback_pw_multi_aff(pa.release(), pma.release());
   return manage(res);
}

void PwAff::pullback(MultiPwAff mpa) {
   auto res = isl_pw_aff_pullback_multi_pw_aff(copy(), mpa.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff pullback(PwAff pa, MultiPwAff mpa) {
   auto res = isl_pw_aff_pullback_multi_pw_aff(pa.release(), mpa.release());
   return manage(res);
}

void PwAff::sub(PwAff pwaff2) {
   auto res = isl_pw_aff_sub(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff sub(PwAff pwaff1, PwAff pwaff2) {
   auto res = isl_pw_aff_sub(pwaff1.release(), pwaff2.release());
   return manage(res);
}

void PwAff::unionAdd(PwAff pwaff2) {
   auto res = isl_pw_aff_union_add(copy(), pwaff2.release());
   isl_pw_aff_free(ptr);
   ptr = res;
}

inline PwAff unionAdd(PwAff pwaff1, PwAff pwaff2) {
   auto res = isl_pw_aff_union_add(pwaff1.release(), pwaff2.release());
   return manage(res);
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
void PwMultiAff::add(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_add(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff add(PwMultiAff pma1, PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_add(pma1.release(), pma2.release());
   return manage(res);
}

void PwMultiAff::flatRangeProduct(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_flat_range_product(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff flatRangeProduct(PwMultiAff pma1, PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_flat_range_product(pma1.release(), pma2.release());
   return manage(res);
}

void PwMultiAff::product(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_product(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff product(PwMultiAff pma1, PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_product(pma1.release(), pma2.release());
   return manage(res);
}

void PwMultiAff::pullback(MultiAff ma) {
   auto res = isl_pw_multi_aff_pullback_multi_aff(copy(), ma.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff pullback(PwMultiAff pma, MultiAff ma) {
   auto res = isl_pw_multi_aff_pullback_multi_aff(pma.release(), ma.release());
   return manage(res);
}

void PwMultiAff::pullback(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_pullback_pw_multi_aff(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff pullback(PwMultiAff pma1, PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_pullback_pw_multi_aff(pma1.release(), pma2.release());
   return manage(res);
}

void PwMultiAff::rangeProduct(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_range_product(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff rangeProduct(PwMultiAff pma1, PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_range_product(pma1.release(), pma2.release());
   return manage(res);
}

void PwMultiAff::unionAdd(PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_union_add(copy(), pma2.release());
   isl_pw_multi_aff_free(ptr);
   ptr = res;
}

inline PwMultiAff unionAdd(PwMultiAff pma1, PwMultiAff pma2) {
   auto res = isl_pw_multi_aff_union_add(pma1.release(), pma2.release());
   return manage(res);
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

inline UnionMap getMap(const Schedule &sched) {
   auto res = isl_schedule_get_map(sched.get());
   return manage(res);
}

ScheduleNode Schedule::getRoot() const {
   auto res = isl_schedule_get_root(get());
   return manage(res);
}

inline ScheduleNode getRoot(const Schedule &schedule) {
   auto res = isl_schedule_get_root(schedule.get());
   return manage(res);
}

void Schedule::pullback(UnionPwMultiAff upma) {
   auto res = isl_schedule_pullback_union_pw_multi_aff(copy(), upma.release());
   isl_schedule_free(ptr);
   ptr = res;
}

inline Schedule pullback(Schedule schedule, UnionPwMultiAff upma) {
   auto res = isl_schedule_pullback_union_pw_multi_aff(schedule.release(), upma.release());
   return manage(res);
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

inline UnionMap getCoincidence(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_coincidence(sc.get());
   return manage(res);
}

UnionMap ScheduleConstraints::getConditionalValidity() const {
   auto res = isl_schedule_constraints_get_conditional_validity(get());
   return manage(res);
}

inline UnionMap getConditionalValidity(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_conditional_validity(sc.get());
   return manage(res);
}

UnionMap ScheduleConstraints::getConditionalValidityCondition() const {
   auto res = isl_schedule_constraints_get_conditional_validity_condition(get());
   return manage(res);
}

inline UnionMap getConditionalValidityCondition(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_conditional_validity_condition(sc.get());
   return manage(res);
}

Set ScheduleConstraints::getContext() const {
   auto res = isl_schedule_constraints_get_context(get());
   return manage(res);
}

inline Set getContext(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_context(sc.get());
   return manage(res);
}

UnionSet ScheduleConstraints::getDomain() const {
   auto res = isl_schedule_constraints_get_domain(get());
   return manage(res);
}

inline UnionSet getDomain(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_domain(sc.get());
   return manage(res);
}

UnionMap ScheduleConstraints::getProximity() const {
   auto res = isl_schedule_constraints_get_proximity(get());
   return manage(res);
}

inline UnionMap getProximity(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_proximity(sc.get());
   return manage(res);
}

UnionMap ScheduleConstraints::getValidity() const {
   auto res = isl_schedule_constraints_get_validity(get());
   return manage(res);
}

inline UnionMap getValidity(const ScheduleConstraints &sc) {
   auto res = isl_schedule_constraints_get_validity(sc.get());
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

inline Bool bandMemberGetCoincident(const ScheduleNode &node, int pos) {
   auto res = isl_schedule_node_band_member_get_coincident(node.get(), pos);
   return res;
}

void ScheduleNode::bandMemberSetCoincident(int pos, int coincident) {
   auto res = isl_schedule_node_band_member_set_coincident(copy(), pos, coincident);
   isl_schedule_node_free(ptr);
   ptr = res;
}

inline ScheduleNode bandMemberSetCoincident(ScheduleNode node, int pos, int coincident) {
   auto res = isl_schedule_node_band_member_set_coincident(node.release(), pos, coincident);
   return manage(res);
}

void ScheduleNode::child(int pos) {
   auto res = isl_schedule_node_child(copy(), pos);
   isl_schedule_node_free(ptr);
   ptr = res;
}

inline ScheduleNode child(ScheduleNode node, int pos) {
   auto res = isl_schedule_node_child(node.release(), pos);
   return manage(res);
}

MultiUnionPwAff ScheduleNode::getPrefixScheduleMultiUnionPwAff() const {
   auto res = isl_schedule_node_get_prefix_schedule_multi_union_pw_aff(get());
   return manage(res);
}

inline MultiUnionPwAff getPrefixScheduleMultiUnionPwAff(const ScheduleNode &node) {
   auto res = isl_schedule_node_get_prefix_schedule_multi_union_pw_aff(node.get());
   return manage(res);
}

UnionMap ScheduleNode::getPrefixScheduleUnionMap() const {
   auto res = isl_schedule_node_get_prefix_schedule_union_map(get());
   return manage(res);
}

inline UnionMap getPrefixScheduleUnionMap(const ScheduleNode &node) {
   auto res = isl_schedule_node_get_prefix_schedule_union_map(node.get());
   return manage(res);
}

UnionPwMultiAff ScheduleNode::getPrefixScheduleUnionPwMultiAff() const {
   auto res = isl_schedule_node_get_prefix_schedule_union_pw_multi_aff(get());
   return manage(res);
}

inline UnionPwMultiAff getPrefixScheduleUnionPwMultiAff(const ScheduleNode &node) {
   auto res = isl_schedule_node_get_prefix_schedule_union_pw_multi_aff(node.get());
   return manage(res);
}

Schedule ScheduleNode::getSchedule() const {
   auto res = isl_schedule_node_get_schedule(get());
   return manage(res);
}

inline Schedule getSchedule(const ScheduleNode &node) {
   auto res = isl_schedule_node_get_schedule(node.get());
   return manage(res);
}

void ScheduleNode::parent() {
   auto res = isl_schedule_node_parent(copy());
   isl_schedule_node_free(ptr);
   ptr = res;
}

inline ScheduleNode parent(ScheduleNode node) {
   auto res = isl_schedule_node_parent(node.release());
   return manage(res);
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
void Set::addDims(enum DimType type, unsigned int n) {
   auto res = isl_set_add_dims(copy(), static_cast<enum isl_dim_type>(type), n);
   isl_set_free(ptr);
   ptr = res;
}

inline Set addDims(Set set, enum DimType type, unsigned int n) {
   auto res = isl_set_add_dims(set.release(), static_cast<enum isl_dim_type>(type), n);
   return manage(res);
}

BasicSet Set::affineHull() const {
   auto res = isl_set_affine_hull(copy());
   return manage(res);
}

inline BasicSet affineHull(Set set) {
   auto res = isl_set_affine_hull(set.release());
   return manage(res);
}

void Set::apply(Map map) {
   auto res = isl_set_apply(copy(), map.release());
   isl_set_free(ptr);
   ptr = res;
}

inline Set apply(Set set, Map map) {
   auto res = isl_set_apply(set.release(), map.release());
   return manage(res);
}

void Set::coalesce() {
   auto res = isl_set_coalesce(copy());
   isl_set_free(ptr);
   ptr = res;
}

inline Set coalesce(Set set) {
   auto res = isl_set_coalesce(set.release());
   return manage(res);
}

void Set::complement() {
   auto res = isl_set_complement(copy());
   isl_set_free(ptr);
   ptr = res;
}

inline Set complement(Set set) {
   auto res = isl_set_complement(set.release());
   return manage(res);
}

void Set::detectEqualities() {
   auto res = isl_set_detect_equalities(copy());
   isl_set_free(ptr);
   ptr = res;
}

inline Set detectEqualities(Set set) {
   auto res = isl_set_detect_equalities(set.release());
   return manage(res);
}

unsigned int Set::dim(enum DimType type) const {
   auto res = isl_set_dim(get(), static_cast<enum isl_dim_type>(type));
   return res;
}

inline unsigned int dim(const Set &set, enum DimType type) {
   auto res = isl_set_dim(set.get(), static_cast<enum isl_dim_type>(type));
   return res;
}

PwAff Set::dimMax(int pos) const {
   auto res = isl_set_dim_max(copy(), pos);
   return manage(res);
}

inline PwAff dimMax(Set set, int pos) {
   auto res = isl_set_dim_max(set.release(), pos);
   return manage(res);
}

PwAff Set::dimMin(int pos) const {
   auto res = isl_set_dim_min(copy(), pos);
   return manage(res);
}

inline PwAff dimMin(Set set, int pos) {
   auto res = isl_set_dim_min(set.release(), pos);
   return manage(res);
}

void Set::flatten() {
   auto res = isl_set_flatten(copy());
   isl_set_free(ptr);
   ptr = res;
}

inline Set flatten(Set set) {
   auto res = isl_set_flatten(set.release());
   return manage(res);
}

void Set::gist(Set context) {
   auto res = isl_set_gist(copy(), context.release());
   isl_set_free(ptr);
   ptr = res;
}

inline Set gist(Set set, Set context) {
   auto res = isl_set_gist(set.release(), context.release());
   return manage(res);
}

Map Set::identity() const {
   auto res = isl_set_identity(copy());
   return manage(res);
}

inline Map identity(Set set) {
   auto res = isl_set_identity(set.release());
   return manage(res);
}

void Set::intersect(Set set2) {
   auto res = isl_set_intersect(copy(), set2.release());
   isl_set_free(ptr);
   ptr = res;
}

inline Set intersect(Set set1, Set set2) {
   auto res = isl_set_intersect(set1.release(), set2.release());
   return manage(res);
}

void Set::intersectParams(Set params) {
   auto res = isl_set_intersect_params(copy(), params.release());
   isl_set_free(ptr);
   ptr = res;
}

inline Set intersectParams(Set set, Set params) {
   auto res = isl_set_intersect_params(set.release(), params.release());
   return manage(res);
}

int Set::isBounded() const {
   auto res = isl_set_is_bounded(get());
   return res;
}

inline int isBounded(const Set &set) {
   auto res = isl_set_is_bounded(set.get());
   return res;
}

Bool Set::isDisjoint(const Set &set2) const {
   auto res = isl_set_is_disjoint(get(), set2.get());
   return res;
}

inline Bool isDisjoint(const Set &set1, const Set &set2) {
   auto res = isl_set_is_disjoint(set1.get(), set2.get());
   return res;
}

Bool Set::isEmpty() const {
   auto res = isl_set_is_empty(get());
   return res;
}

inline Bool isEmpty(const Set &set) {
   auto res = isl_set_is_empty(set.get());
   return res;
}

Bool Set::isEqual(const Set &set2) const {
   auto res = isl_set_is_equal(get(), set2.get());
   return res;
}

inline Bool isEqual(const Set &set1, const Set &set2) {
   auto res = isl_set_is_equal(set1.get(), set2.get());
   return res;
}

Bool Set::isStrictSubset(const Set &set2) const {
   auto res = isl_set_is_strict_subset(get(), set2.get());
   return res;
}

inline Bool isStrictSubset(const Set &set1, const Set &set2) {
   auto res = isl_set_is_strict_subset(set1.get(), set2.get());
   return res;
}

Bool Set::isSubset(const Set &set2) const {
   auto res = isl_set_is_subset(get(), set2.get());
   return res;
}

inline Bool isSubset(const Set &set1, const Set &set2) {
   auto res = isl_set_is_subset(set1.get(), set2.get());
   return res;
}

Bool Set::isWrapping() const {
   auto res = isl_set_is_wrapping(get());
   return res;
}

inline Bool isWrapping(const Set &set) {
   auto res = isl_set_is_wrapping(set.get());
   return res;
}

void Set::lexmax() {
   auto res = isl_set_lexmax(copy());
   isl_set_free(ptr);
   ptr = res;
}

inline Set lexmax(Set set) {
   auto res = isl_set_lexmax(set.release());
   return manage(res);
}

void Set::lexmin() {
   auto res = isl_set_lexmin(copy());
   isl_set_free(ptr);
   ptr = res;
}

inline Set lexmin(Set set) {
   auto res = isl_set_lexmin(set.release());
   return manage(res);
}

Val Set::maxVal(const Aff &obj) const {
   auto res = isl_set_max_val(get(), obj.get());
   return manage(res);
}

inline Val maxVal(const Set &set, const Aff &obj) {
   auto res = isl_set_max_val(set.get(), obj.get());
   return manage(res);
}

Val Set::minVal(const Aff &obj) const {
   auto res = isl_set_min_val(get(), obj.get());
   return manage(res);
}

inline Val minVal(const Set &set, const Aff &obj) {
   auto res = isl_set_min_val(set.get(), obj.get());
   return manage(res);
}

BasicSet Set::polyhedralHull() const {
   auto res = isl_set_polyhedral_hull(copy());
   return manage(res);
}

inline BasicSet polyhedralHull(Set set) {
   auto res = isl_set_polyhedral_hull(set.release());
   return manage(res);
}

void Set::projectOut(enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
   isl_set_free(ptr);
   ptr = res;
}

inline Set projectOut(Set set, enum DimType type, unsigned int first, unsigned int n) {
   auto res = isl_set_project_out(set.release(), static_cast<enum isl_dim_type>(type), first, n);
   return manage(res);
}

BasicSet Set::sample() const {
   auto res = isl_set_sample(copy());
   return manage(res);
}

inline BasicSet sample(Set set) {
   auto res = isl_set_sample(set.release());
   return manage(res);
}

Point Set::samplePoint() const {
   auto res = isl_set_sample_point(copy());
   return manage(res);
}

inline Point samplePoint(Set set) {
   auto res = isl_set_sample_point(set.release());
   return manage(res);
}

void Set::subtract(Set set2) {
   auto res = isl_set_subtract(copy(), set2.release());
   isl_set_free(ptr);
   ptr = res;
}

inline Set subtract(Set set1, Set set2) {
   auto res = isl_set_subtract(set1.release(), set2.release());
   return manage(res);
}

void Set::unite(Set set2) {
   auto res = isl_set_union(copy(), set2.release());
   isl_set_free(ptr);
   ptr = res;
}

inline Set unite(Set set1, Set set2) {
   auto res = isl_set_union(set1.release(), set2.release());
   return manage(res);
}

BasicSet Set::unshiftedSimpleHull() const {
   auto res = isl_set_unshifted_simple_hull(copy());
   return manage(res);
}

inline BasicSet unshiftedSimpleHull(Set set) {
   auto res = isl_set_unshifted_simple_hull(set.release());
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

inline UnionFlow computeFlow(UnionAccessInfo access) {
   auto res = isl_union_access_info_compute_flow(access.release());
   return manage(res);
}

void UnionAccessInfo::setMaySource(UnionMap may_source) {
   auto res = isl_union_access_info_set_may_source(copy(), may_source.release());
   isl_union_access_info_free(ptr);
   ptr = res;
}

inline UnionAccessInfo setMaySource(UnionAccessInfo access, UnionMap may_source) {
   auto res = isl_union_access_info_set_may_source(access.release(), may_source.release());
   return manage(res);
}

void UnionAccessInfo::setMustSource(UnionMap must_source) {
   auto res = isl_union_access_info_set_must_source(copy(), must_source.release());
   isl_union_access_info_free(ptr);
   ptr = res;
}

inline UnionAccessInfo setMustSource(UnionAccessInfo access, UnionMap must_source) {
   auto res = isl_union_access_info_set_must_source(access.release(), must_source.release());
   return manage(res);
}

void UnionAccessInfo::setSchedule(Schedule schedule) {
   auto res = isl_union_access_info_set_schedule(copy(), schedule.release());
   isl_union_access_info_free(ptr);
   ptr = res;
}

inline UnionAccessInfo setSchedule(UnionAccessInfo access, Schedule schedule) {
   auto res = isl_union_access_info_set_schedule(access.release(), schedule.release());
   return manage(res);
}

void UnionAccessInfo::setScheduleMap(UnionMap schedule_map) {
   auto res = isl_union_access_info_set_schedule_map(copy(), schedule_map.release());
   isl_union_access_info_free(ptr);
   ptr = res;
}

inline UnionAccessInfo setScheduleMap(UnionAccessInfo access, UnionMap schedule_map) {
   auto res = isl_union_access_info_set_schedule_map(access.release(), schedule_map.release());
   return manage(res);
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

inline UnionMap getFullMayDependence(const UnionFlow &flow) {
   auto res = isl_union_flow_get_full_may_dependence(flow.get());
   return manage(res);
}

UnionMap UnionFlow::getFullMustDependence() const {
   auto res = isl_union_flow_get_full_must_dependence(get());
   return manage(res);
}

inline UnionMap getFullMustDependence(const UnionFlow &flow) {
   auto res = isl_union_flow_get_full_must_dependence(flow.get());
   return manage(res);
}

UnionMap UnionFlow::getMayDependence() const {
   auto res = isl_union_flow_get_may_dependence(get());
   return manage(res);
}

inline UnionMap getMayDependence(const UnionFlow &flow) {
   auto res = isl_union_flow_get_may_dependence(flow.get());
   return manage(res);
}

UnionMap UnionFlow::getMayNoSource() const {
   auto res = isl_union_flow_get_may_no_source(get());
   return manage(res);
}

inline UnionMap getMayNoSource(const UnionFlow &flow) {
   auto res = isl_union_flow_get_may_no_source(flow.get());
   return manage(res);
}

UnionMap UnionFlow::getMustDependence() const {
   auto res = isl_union_flow_get_must_dependence(get());
   return manage(res);
}

inline UnionMap getMustDependence(const UnionFlow &flow) {
   auto res = isl_union_flow_get_must_dependence(flow.get());
   return manage(res);
}

UnionMap UnionFlow::getMustNoSource() const {
   auto res = isl_union_flow_get_must_no_source(get());
   return manage(res);
}

inline UnionMap getMustNoSource(const UnionFlow &flow) {
   auto res = isl_union_flow_get_must_no_source(flow.get());
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
void UnionMap::addMap(Map map) {
   auto res = isl_union_map_add_map(copy(), map.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap addMap(UnionMap umap, Map map) {
   auto res = isl_union_map_add_map(umap.release(), map.release());
   return manage(res);
}

void UnionMap::affineHull() {
   auto res = isl_union_map_affine_hull(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap affineHull(UnionMap umap) {
   auto res = isl_union_map_affine_hull(umap.release());
   return manage(res);
}

void UnionMap::applyDomain(UnionMap umap2) {
   auto res = isl_union_map_apply_domain(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap applyDomain(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_apply_domain(umap1.release(), umap2.release());
   return manage(res);
}

void UnionMap::applyRange(UnionMap umap2) {
   auto res = isl_union_map_apply_range(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap applyRange(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_apply_range(umap1.release(), umap2.release());
   return manage(res);
}

void UnionMap::coalesce() {
   auto res = isl_union_map_coalesce(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap coalesce(UnionMap umap) {
   auto res = isl_union_map_coalesce(umap.release());
   return manage(res);
}

void UnionMap::computeDivs() {
   auto res = isl_union_map_compute_divs(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap computeDivs(UnionMap umap) {
   auto res = isl_union_map_compute_divs(umap.release());
   return manage(res);
}

UnionSet UnionMap::deltas() const {
   auto res = isl_union_map_deltas(copy());
   return manage(res);
}

inline UnionSet deltas(UnionMap umap) {
   auto res = isl_union_map_deltas(umap.release());
   return manage(res);
}

void UnionMap::detectEqualities() {
   auto res = isl_union_map_detect_equalities(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap detectEqualities(UnionMap umap) {
   auto res = isl_union_map_detect_equalities(umap.release());
   return manage(res);
}

UnionSet UnionMap::domain() const {
   auto res = isl_union_map_domain(copy());
   return manage(res);
}

inline UnionSet domain(UnionMap umap) {
   auto res = isl_union_map_domain(umap.release());
   return manage(res);
}

void UnionMap::domainFactorDomain() {
   auto res = isl_union_map_domain_factor_domain(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap domainFactorDomain(UnionMap umap) {
   auto res = isl_union_map_domain_factor_domain(umap.release());
   return manage(res);
}

void UnionMap::domainFactorRange() {
   auto res = isl_union_map_domain_factor_range(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap domainFactorRange(UnionMap umap) {
   auto res = isl_union_map_domain_factor_range(umap.release());
   return manage(res);
}

void UnionMap::domainMap() {
   auto res = isl_union_map_domain_map(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap domainMap(UnionMap umap) {
   auto res = isl_union_map_domain_map(umap.release());
   return manage(res);
}

UnionPwMultiAff UnionMap::domainMapUnionPwMultiAff() const {
   auto res = isl_union_map_domain_map_union_pw_multi_aff(copy());
   return manage(res);
}

inline UnionPwMultiAff domainMapUnionPwMultiAff(UnionMap umap) {
   auto res = isl_union_map_domain_map_union_pw_multi_aff(umap.release());
   return manage(res);
}

void UnionMap::domainProduct(UnionMap umap2) {
   auto res = isl_union_map_domain_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap domainProduct(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_domain_product(umap1.release(), umap2.release());
   return manage(res);
}

void UnionMap::factorDomain() {
   auto res = isl_union_map_factor_domain(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap factorDomain(UnionMap umap) {
   auto res = isl_union_map_factor_domain(umap.release());
   return manage(res);
}

void UnionMap::factorRange() {
   auto res = isl_union_map_factor_range(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap factorRange(UnionMap umap) {
   auto res = isl_union_map_factor_range(umap.release());
   return manage(res);
}

void UnionMap::fixedPower(Val exp) {
   auto res = isl_union_map_fixed_power_val(copy(), exp.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap fixedPower(UnionMap umap, Val exp) {
   auto res = isl_union_map_fixed_power_val(umap.release(), exp.release());
   return manage(res);
}

void UnionMap::flatRangeProduct(UnionMap umap2) {
   auto res = isl_union_map_flat_range_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap flatRangeProduct(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_flat_range_product(umap1.release(), umap2.release());
   return manage(res);
}

UnionMap UnionMap::from(UnionPwMultiAff upma) {
   auto res = isl_union_map_from_union_pw_multi_aff(upma.release());
   return manage(res);
}

inline UnionMap from(UnionPwMultiAff upma) {
   auto res = isl_union_map_from_union_pw_multi_aff(upma.release());
   return manage(res);
}

UnionMap UnionMap::from(MultiUnionPwAff mupa) {
   auto res = isl_union_map_from_multi_union_pw_aff(mupa.release());
   return manage(res);
}

inline UnionMap from(MultiUnionPwAff mupa) {
   auto res = isl_union_map_from_multi_union_pw_aff(mupa.release());
   return manage(res);
}

UnionMap UnionMap::fromDomainAndRange(UnionSet domain, UnionSet range) {
   auto res = isl_union_map_from_domain_and_range(domain.release(), range.release());
   return manage(res);
}

inline UnionMap fromDomainAndRange(UnionSet domain, UnionSet range) {
   auto res = isl_union_map_from_domain_and_range(domain.release(), range.release());
   return manage(res);
}

void UnionMap::gist(UnionMap context) {
   auto res = isl_union_map_gist(copy(), context.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap gist(UnionMap umap, UnionMap context) {
   auto res = isl_union_map_gist(umap.release(), context.release());
   return manage(res);
}

void UnionMap::gistDomain(UnionSet uset) {
   auto res = isl_union_map_gist_domain(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap gistDomain(UnionMap umap, UnionSet uset) {
   auto res = isl_union_map_gist_domain(umap.release(), uset.release());
   return manage(res);
}

void UnionMap::gistParams(Set set) {
   auto res = isl_union_map_gist_params(copy(), set.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap gistParams(UnionMap umap, Set set) {
   auto res = isl_union_map_gist_params(umap.release(), set.release());
   return manage(res);
}

void UnionMap::gistRange(UnionSet uset) {
   auto res = isl_union_map_gist_range(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap gistRange(UnionMap umap, UnionSet uset) {
   auto res = isl_union_map_gist_range(umap.release(), uset.release());
   return manage(res);
}

void UnionMap::intersect(UnionMap umap2) {
   auto res = isl_union_map_intersect(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap intersect(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_intersect(umap1.release(), umap2.release());
   return manage(res);
}

void UnionMap::intersectDomain(UnionSet uset) {
   auto res = isl_union_map_intersect_domain(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap intersectDomain(UnionMap umap, UnionSet uset) {
   auto res = isl_union_map_intersect_domain(umap.release(), uset.release());
   return manage(res);
}

void UnionMap::intersectParams(Set set) {
   auto res = isl_union_map_intersect_params(copy(), set.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap intersectParams(UnionMap umap, Set set) {
   auto res = isl_union_map_intersect_params(umap.release(), set.release());
   return manage(res);
}

void UnionMap::intersectRange(UnionSet uset) {
   auto res = isl_union_map_intersect_range(copy(), uset.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap intersectRange(UnionMap umap, UnionSet uset) {
   auto res = isl_union_map_intersect_range(umap.release(), uset.release());
   return manage(res);
}

Bool UnionMap::isBijective() const {
   auto res = isl_union_map_is_bijective(get());
   return res;
}

inline Bool isBijective(const UnionMap &umap) {
   auto res = isl_union_map_is_bijective(umap.get());
   return res;
}

Bool UnionMap::isEmpty() const {
   auto res = isl_union_map_is_empty(get());
   return res;
}

inline Bool isEmpty(const UnionMap &umap) {
   auto res = isl_union_map_is_empty(umap.get());
   return res;
}

Bool UnionMap::isEqual(const UnionMap &umap2) const {
   auto res = isl_union_map_is_equal(get(), umap2.get());
   return res;
}

inline Bool isEqual(const UnionMap &umap1, const UnionMap &umap2) {
   auto res = isl_union_map_is_equal(umap1.get(), umap2.get());
   return res;
}

Bool UnionMap::isInjective() const {
   auto res = isl_union_map_is_injective(get());
   return res;
}

inline Bool isInjective(const UnionMap &umap) {
   auto res = isl_union_map_is_injective(umap.get());
   return res;
}

Bool UnionMap::isSingleValued() const {
   auto res = isl_union_map_is_single_valued(get());
   return res;
}

inline Bool isSingleValued(const UnionMap &umap) {
   auto res = isl_union_map_is_single_valued(umap.get());
   return res;
}

Bool UnionMap::isStrictSubset(const UnionMap &umap2) const {
   auto res = isl_union_map_is_strict_subset(get(), umap2.get());
   return res;
}

inline Bool isStrictSubset(const UnionMap &umap1, const UnionMap &umap2) {
   auto res = isl_union_map_is_strict_subset(umap1.get(), umap2.get());
   return res;
}

Bool UnionMap::isSubset(const UnionMap &umap2) const {
   auto res = isl_union_map_is_subset(get(), umap2.get());
   return res;
}

inline Bool isSubset(const UnionMap &umap1, const UnionMap &umap2) {
   auto res = isl_union_map_is_subset(umap1.get(), umap2.get());
   return res;
}

void UnionMap::lexmax() {
   auto res = isl_union_map_lexmax(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap lexmax(UnionMap umap) {
   auto res = isl_union_map_lexmax(umap.release());
   return manage(res);
}

void UnionMap::lexmin() {
   auto res = isl_union_map_lexmin(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap lexmin(UnionMap umap) {
   auto res = isl_union_map_lexmin(umap.release());
   return manage(res);
}

void UnionMap::polyhedralHull() {
   auto res = isl_union_map_polyhedral_hull(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap polyhedralHull(UnionMap umap) {
   auto res = isl_union_map_polyhedral_hull(umap.release());
   return manage(res);
}

void UnionMap::product(UnionMap umap2) {
   auto res = isl_union_map_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap product(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_product(umap1.release(), umap2.release());
   return manage(res);
}

UnionSet UnionMap::range() const {
   auto res = isl_union_map_range(copy());
   return manage(res);
}

inline UnionSet range(UnionMap umap) {
   auto res = isl_union_map_range(umap.release());
   return manage(res);
}

void UnionMap::rangeFactorDomain() {
   auto res = isl_union_map_range_factor_domain(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap rangeFactorDomain(UnionMap umap) {
   auto res = isl_union_map_range_factor_domain(umap.release());
   return manage(res);
}

void UnionMap::rangeFactorRange() {
   auto res = isl_union_map_range_factor_range(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap rangeFactorRange(UnionMap umap) {
   auto res = isl_union_map_range_factor_range(umap.release());
   return manage(res);
}

void UnionMap::rangeMap() {
   auto res = isl_union_map_range_map(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap rangeMap(UnionMap umap) {
   auto res = isl_union_map_range_map(umap.release());
   return manage(res);
}

void UnionMap::rangeProduct(UnionMap umap2) {
   auto res = isl_union_map_range_product(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap rangeProduct(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_range_product(umap1.release(), umap2.release());
   return manage(res);
}

void UnionMap::reverse() {
   auto res = isl_union_map_reverse(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap reverse(UnionMap umap) {
   auto res = isl_union_map_reverse(umap.release());
   return manage(res);
}

void UnionMap::subtract(UnionMap umap2) {
   auto res = isl_union_map_subtract(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap subtract(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_subtract(umap1.release(), umap2.release());
   return manage(res);
}

void UnionMap::subtractDomain(UnionSet dom) {
   auto res = isl_union_map_subtract_domain(copy(), dom.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap subtractDomain(UnionMap umap, UnionSet dom) {
   auto res = isl_union_map_subtract_domain(umap.release(), dom.release());
   return manage(res);
}

void UnionMap::subtractRange(UnionSet dom) {
   auto res = isl_union_map_subtract_range(copy(), dom.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap subtractRange(UnionMap umap, UnionSet dom) {
   auto res = isl_union_map_subtract_range(umap.release(), dom.release());
   return manage(res);
}

void UnionMap::unite(UnionMap umap2) {
   auto res = isl_union_map_union(copy(), umap2.release());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap unite(UnionMap umap1, UnionMap umap2) {
   auto res = isl_union_map_union(umap1.release(), umap2.release());
   return manage(res);
}

UnionSet UnionMap::wrap() const {
   auto res = isl_union_map_wrap(copy());
   return manage(res);
}

inline UnionSet wrap(UnionMap umap) {
   auto res = isl_union_map_wrap(umap.release());
   return manage(res);
}

void UnionMap::zip() {
   auto res = isl_union_map_zip(copy());
   isl_union_map_free(ptr);
   ptr = res;
}

inline UnionMap zip(UnionMap umap) {
   auto res = isl_union_map_zip(umap.release());
   return manage(res);
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
void UnionPwAff::add(UnionPwAff upa2) {
   auto res = isl_union_pw_aff_add(copy(), upa2.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
}

inline UnionPwAff add(UnionPwAff upa1, UnionPwAff upa2) {
   auto res = isl_union_pw_aff_add(upa1.release(), upa2.release());
   return manage(res);
}

void UnionPwAff::pullback(UnionPwMultiAff upma) {
   auto res = isl_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
}

inline UnionPwAff pullback(UnionPwAff upa, UnionPwMultiAff upma) {
   auto res = isl_union_pw_aff_pullback_union_pw_multi_aff(upa.release(), upma.release());
   return manage(res);
}

void UnionPwAff::sub(UnionPwAff upa2) {
   auto res = isl_union_pw_aff_sub(copy(), upa2.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
}

inline UnionPwAff sub(UnionPwAff upa1, UnionPwAff upa2) {
   auto res = isl_union_pw_aff_sub(upa1.release(), upa2.release());
   return manage(res);
}

void UnionPwAff::unionAdd(UnionPwAff upa2) {
   auto res = isl_union_pw_aff_union_add(copy(), upa2.release());
   isl_union_pw_aff_free(ptr);
   ptr = res;
}

inline UnionPwAff unionAdd(UnionPwAff upa1, UnionPwAff upa2) {
   auto res = isl_union_pw_aff_union_add(upa1.release(), upa2.release());
   return manage(res);
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
void UnionPwMultiAff::add(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_add(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
}

inline UnionPwMultiAff add(UnionPwMultiAff upma1, UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_add(upma1.release(), upma2.release());
   return manage(res);
}

void UnionPwMultiAff::flatRangeProduct(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_flat_range_product(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
}

inline UnionPwMultiAff flatRangeProduct(UnionPwMultiAff upma1, UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_flat_range_product(upma1.release(), upma2.release());
   return manage(res);
}

void UnionPwMultiAff::pullback(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_pullback_union_pw_multi_aff(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
}

inline UnionPwMultiAff pullback(UnionPwMultiAff upma1, UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_pullback_union_pw_multi_aff(upma1.release(), upma2.release());
   return manage(res);
}

void UnionPwMultiAff::unionAdd(UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_union_add(copy(), upma2.release());
   isl_union_pw_multi_aff_free(ptr);
   ptr = res;
}

inline UnionPwMultiAff unionAdd(UnionPwMultiAff upma1, UnionPwMultiAff upma2) {
   auto res = isl_union_pw_multi_aff_union_add(upma1.release(), upma2.release());
   return manage(res);
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
void UnionSet::affineHull() {
   auto res = isl_union_set_affine_hull(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet affineHull(UnionSet uset) {
   auto res = isl_union_set_affine_hull(uset.release());
   return manage(res);
}

void UnionSet::apply(UnionMap umap) {
   auto res = isl_union_set_apply(copy(), umap.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet apply(UnionSet uset, UnionMap umap) {
   auto res = isl_union_set_apply(uset.release(), umap.release());
   return manage(res);
}

void UnionSet::coalesce() {
   auto res = isl_union_set_coalesce(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet coalesce(UnionSet uset) {
   auto res = isl_union_set_coalesce(uset.release());
   return manage(res);
}

void UnionSet::computeDivs() {
   auto res = isl_union_set_compute_divs(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet computeDivs(UnionSet uset) {
   auto res = isl_union_set_compute_divs(uset.release());
   return manage(res);
}

void UnionSet::detectEqualities() {
   auto res = isl_union_set_detect_equalities(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet detectEqualities(UnionSet uset) {
   auto res = isl_union_set_detect_equalities(uset.release());
   return manage(res);
}

void UnionSet::gist(UnionSet context) {
   auto res = isl_union_set_gist(copy(), context.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet gist(UnionSet uset, UnionSet context) {
   auto res = isl_union_set_gist(uset.release(), context.release());
   return manage(res);
}

void UnionSet::gistParams(Set set) {
   auto res = isl_union_set_gist_params(copy(), set.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet gistParams(UnionSet uset, Set set) {
   auto res = isl_union_set_gist_params(uset.release(), set.release());
   return manage(res);
}

UnionMap UnionSet::identity() const {
   auto res = isl_union_set_identity(copy());
   return manage(res);
}

inline UnionMap identity(UnionSet uset) {
   auto res = isl_union_set_identity(uset.release());
   return manage(res);
}

void UnionSet::intersect(UnionSet uset2) {
   auto res = isl_union_set_intersect(copy(), uset2.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet intersect(UnionSet uset1, UnionSet uset2) {
   auto res = isl_union_set_intersect(uset1.release(), uset2.release());
   return manage(res);
}

void UnionSet::intersectParams(Set set) {
   auto res = isl_union_set_intersect_params(copy(), set.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet intersectParams(UnionSet uset, Set set) {
   auto res = isl_union_set_intersect_params(uset.release(), set.release());
   return manage(res);
}

Bool UnionSet::isEmpty() const {
   auto res = isl_union_set_is_empty(get());
   return res;
}

inline Bool isEmpty(const UnionSet &uset) {
   auto res = isl_union_set_is_empty(uset.get());
   return res;
}

Bool UnionSet::isEqual(const UnionSet &uset2) const {
   auto res = isl_union_set_is_equal(get(), uset2.get());
   return res;
}

inline Bool isEqual(const UnionSet &uset1, const UnionSet &uset2) {
   auto res = isl_union_set_is_equal(uset1.get(), uset2.get());
   return res;
}

Bool UnionSet::isStrictSubset(const UnionSet &uset2) const {
   auto res = isl_union_set_is_strict_subset(get(), uset2.get());
   return res;
}

inline Bool isStrictSubset(const UnionSet &uset1, const UnionSet &uset2) {
   auto res = isl_union_set_is_strict_subset(uset1.get(), uset2.get());
   return res;
}

Bool UnionSet::isSubset(const UnionSet &uset2) const {
   auto res = isl_union_set_is_subset(get(), uset2.get());
   return res;
}

inline Bool isSubset(const UnionSet &uset1, const UnionSet &uset2) {
   auto res = isl_union_set_is_subset(uset1.get(), uset2.get());
   return res;
}

void UnionSet::lexmax() {
   auto res = isl_union_set_lexmax(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet lexmax(UnionSet uset) {
   auto res = isl_union_set_lexmax(uset.release());
   return manage(res);
}

void UnionSet::lexmin() {
   auto res = isl_union_set_lexmin(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet lexmin(UnionSet uset) {
   auto res = isl_union_set_lexmin(uset.release());
   return manage(res);
}

void UnionSet::polyhedralHull() {
   auto res = isl_union_set_polyhedral_hull(copy());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet polyhedralHull(UnionSet uset) {
   auto res = isl_union_set_polyhedral_hull(uset.release());
   return manage(res);
}

Point UnionSet::samplePoint() const {
   auto res = isl_union_set_sample_point(copy());
   return manage(res);
}

inline Point samplePoint(UnionSet uset) {
   auto res = isl_union_set_sample_point(uset.release());
   return manage(res);
}

void UnionSet::subtract(UnionSet uset2) {
   auto res = isl_union_set_subtract(copy(), uset2.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet subtract(UnionSet uset1, UnionSet uset2) {
   auto res = isl_union_set_subtract(uset1.release(), uset2.release());
   return manage(res);
}

void UnionSet::unite(UnionSet uset2) {
   auto res = isl_union_set_union(copy(), uset2.release());
   isl_union_set_free(ptr);
   ptr = res;
}

inline UnionSet unite(UnionSet uset1, UnionSet uset2) {
   auto res = isl_union_set_union(uset1.release(), uset2.release());
   return manage(res);
}

UnionMap UnionSet::unwrap() const {
   auto res = isl_union_set_unwrap(copy());
   return manage(res);
}

inline UnionMap unwrap(UnionSet uset) {
   auto res = isl_union_set_unwrap(uset.release());
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
void Val::abs() {
   auto res = isl_val_abs(copy());
   isl_val_free(ptr);
   ptr = res;
}

inline Val abs(Val v) {
   auto res = isl_val_abs(v.release());
   return manage(res);
}

Bool Val::absEq(const Val &v2) const {
   auto res = isl_val_abs_eq(get(), v2.get());
   return res;
}

inline Bool absEq(const Val &v1, const Val &v2) {
   auto res = isl_val_abs_eq(v1.get(), v2.get());
   return res;
}

void Val::add(Val v2) {
   auto res = isl_val_add(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val add(Val v1, Val v2) {
   auto res = isl_val_add(v1.release(), v2.release());
   return manage(res);
}

void Val::addUi(unsigned long v2) {
   auto res = isl_val_add_ui(copy(), v2);
   isl_val_free(ptr);
   ptr = res;
}

inline Val addUi(Val v1, unsigned long v2) {
   auto res = isl_val_add_ui(v1.release(), v2);
   return manage(res);
}

void Val::ceil() {
   auto res = isl_val_ceil(copy());
   isl_val_free(ptr);
   ptr = res;
}

inline Val ceil(Val v) {
   auto res = isl_val_ceil(v.release());
   return manage(res);
}

int Val::cmpSi(long i) const {
   auto res = isl_val_cmp_si(get(), i);
   return res;
}

inline int cmpSi(const Val &v, long i) {
   auto res = isl_val_cmp_si(v.get(), i);
   return res;
}

void Val::div(Val v2) {
   auto res = isl_val_div(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val div(Val v1, Val v2) {
   auto res = isl_val_div(v1.release(), v2.release());
   return manage(res);
}

Bool Val::eq(const Val &v2) const {
   auto res = isl_val_eq(get(), v2.get());
   return res;
}

inline Bool eq(const Val &v1, const Val &v2) {
   auto res = isl_val_eq(v1.get(), v2.get());
   return res;
}

void Val::floor() {
   auto res = isl_val_floor(copy());
   isl_val_free(ptr);
   ptr = res;
}

inline Val floor(Val v) {
   auto res = isl_val_floor(v.release());
   return manage(res);
}

void Val::gcd(Val v2) {
   auto res = isl_val_gcd(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val gcd(Val v1, Val v2) {
   auto res = isl_val_gcd(v1.release(), v2.release());
   return manage(res);
}

Bool Val::ge(const Val &v2) const {
   auto res = isl_val_ge(get(), v2.get());
   return res;
}

inline Bool ge(const Val &v1, const Val &v2) {
   auto res = isl_val_ge(v1.get(), v2.get());
   return res;
}

Bool Val::gt(const Val &v2) const {
   auto res = isl_val_gt(get(), v2.get());
   return res;
}

inline Bool gt(const Val &v1, const Val &v2) {
   auto res = isl_val_gt(v1.get(), v2.get());
   return res;
}

Val Val::infty(Ctx ctx) {
   auto res = isl_val_infty(ctx.release());
   return manage(res);
}

inline Val infty(Ctx ctx) {
   auto res = isl_val_infty(ctx.release());
   return manage(res);
}

void Val::inv() {
   auto res = isl_val_inv(copy());
   isl_val_free(ptr);
   ptr = res;
}

inline Val inv(Val v) {
   auto res = isl_val_inv(v.release());
   return manage(res);
}

Bool Val::isDivisibleBy(const Val &v2) const {
   auto res = isl_val_is_divisible_by(get(), v2.get());
   return res;
}

inline Bool isDivisibleBy(const Val &v1, const Val &v2) {
   auto res = isl_val_is_divisible_by(v1.get(), v2.get());
   return res;
}

Bool Val::isInfty() const {
   auto res = isl_val_is_infty(get());
   return res;
}

inline Bool isInfty(const Val &v) {
   auto res = isl_val_is_infty(v.get());
   return res;
}

Bool Val::isInt() const {
   auto res = isl_val_is_int(get());
   return res;
}

inline Bool isInt(const Val &v) {
   auto res = isl_val_is_int(v.get());
   return res;
}

Bool Val::isNan() const {
   auto res = isl_val_is_nan(get());
   return res;
}

inline Bool isNan(const Val &v) {
   auto res = isl_val_is_nan(v.get());
   return res;
}

Bool Val::isNeg() const {
   auto res = isl_val_is_neg(get());
   return res;
}

inline Bool isNeg(const Val &v) {
   auto res = isl_val_is_neg(v.get());
   return res;
}

Bool Val::isNeginfty() const {
   auto res = isl_val_is_neginfty(get());
   return res;
}

inline Bool isNeginfty(const Val &v) {
   auto res = isl_val_is_neginfty(v.get());
   return res;
}

Bool Val::isNegone() const {
   auto res = isl_val_is_negone(get());
   return res;
}

inline Bool isNegone(const Val &v) {
   auto res = isl_val_is_negone(v.get());
   return res;
}

Bool Val::isNonneg() const {
   auto res = isl_val_is_nonneg(get());
   return res;
}

inline Bool isNonneg(const Val &v) {
   auto res = isl_val_is_nonneg(v.get());
   return res;
}

Bool Val::isNonpos() const {
   auto res = isl_val_is_nonpos(get());
   return res;
}

inline Bool isNonpos(const Val &v) {
   auto res = isl_val_is_nonpos(v.get());
   return res;
}

Bool Val::isOne() const {
   auto res = isl_val_is_one(get());
   return res;
}

inline Bool isOne(const Val &v) {
   auto res = isl_val_is_one(v.get());
   return res;
}

Bool Val::isPos() const {
   auto res = isl_val_is_pos(get());
   return res;
}

inline Bool isPos(const Val &v) {
   auto res = isl_val_is_pos(v.get());
   return res;
}

Bool Val::isRat() const {
   auto res = isl_val_is_rat(get());
   return res;
}

inline Bool isRat(const Val &v) {
   auto res = isl_val_is_rat(v.get());
   return res;
}

Bool Val::isZero() const {
   auto res = isl_val_is_zero(get());
   return res;
}

inline Bool isZero(const Val &v) {
   auto res = isl_val_is_zero(v.get());
   return res;
}

Bool Val::le(const Val &v2) const {
   auto res = isl_val_le(get(), v2.get());
   return res;
}

inline Bool le(const Val &v1, const Val &v2) {
   auto res = isl_val_le(v1.get(), v2.get());
   return res;
}

Bool Val::lt(const Val &v2) const {
   auto res = isl_val_lt(get(), v2.get());
   return res;
}

inline Bool lt(const Val &v1, const Val &v2) {
   auto res = isl_val_lt(v1.get(), v2.get());
   return res;
}

void Val::max(Val v2) {
   auto res = isl_val_max(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val max(Val v1, Val v2) {
   auto res = isl_val_max(v1.release(), v2.release());
   return manage(res);
}

void Val::min(Val v2) {
   auto res = isl_val_min(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val min(Val v1, Val v2) {
   auto res = isl_val_min(v1.release(), v2.release());
   return manage(res);
}

void Val::mod(Val v2) {
   auto res = isl_val_mod(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val mod(Val v1, Val v2) {
   auto res = isl_val_mod(v1.release(), v2.release());
   return manage(res);
}

void Val::mul(Val v2) {
   auto res = isl_val_mul(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val mul(Val v1, Val v2) {
   auto res = isl_val_mul(v1.release(), v2.release());
   return manage(res);
}

Val Val::nan(Ctx ctx) {
   auto res = isl_val_nan(ctx.release());
   return manage(res);
}

inline Val nan(Ctx ctx) {
   auto res = isl_val_nan(ctx.release());
   return manage(res);
}

Bool Val::ne(const Val &v2) const {
   auto res = isl_val_ne(get(), v2.get());
   return res;
}

inline Bool ne(const Val &v1, const Val &v2) {
   auto res = isl_val_ne(v1.get(), v2.get());
   return res;
}

void Val::neg() {
   auto res = isl_val_neg(copy());
   isl_val_free(ptr);
   ptr = res;
}

inline Val neg(Val v) {
   auto res = isl_val_neg(v.release());
   return manage(res);
}

Val Val::neginfty(Ctx ctx) {
   auto res = isl_val_neginfty(ctx.release());
   return manage(res);
}

inline Val neginfty(Ctx ctx) {
   auto res = isl_val_neginfty(ctx.release());
   return manage(res);
}

Val Val::negone(Ctx ctx) {
   auto res = isl_val_negone(ctx.release());
   return manage(res);
}

inline Val negone(Ctx ctx) {
   auto res = isl_val_negone(ctx.release());
   return manage(res);
}

Val Val::one(Ctx ctx) {
   auto res = isl_val_one(ctx.release());
   return manage(res);
}

inline Val one(Ctx ctx) {
   auto res = isl_val_one(ctx.release());
   return manage(res);
}

int Val::sgn() const {
   auto res = isl_val_sgn(get());
   return res;
}

inline int sgn(const Val &v) {
   auto res = isl_val_sgn(v.get());
   return res;
}

void Val::sub(Val v2) {
   auto res = isl_val_sub(copy(), v2.release());
   isl_val_free(ptr);
   ptr = res;
}

inline Val sub(Val v1, Val v2) {
   auto res = isl_val_sub(v1.release(), v2.release());
   return manage(res);
}

void Val::trunc() {
   auto res = isl_val_trunc(copy());
   isl_val_free(ptr);
   ptr = res;
}

inline Val trunc(Val v) {
   auto res = isl_val_trunc(v.release());
   return manage(res);
}

Val Val::zero(Ctx ctx) {
   auto res = isl_val_zero(ctx.release());
   return manage(res);
}

inline Val zero(Ctx ctx) {
   auto res = isl_val_zero(ctx.release());
   return manage(res);
}

};

#endif /* ISL_CPP_ALL */
