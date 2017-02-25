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

#ifndef ISL_CPP_ALL
#define ISL_CPP_ALL

#include <isl/aff.h>
#include <isl/ast_build.h>
#include <isl/flow.h>
#include <isl/id.h>
#include <isl/ilp.h>
#include <isl/map.h>
#include <isl/schedule.h>
#include <isl/schedule_node.h>
#include <isl/set.h>
#include <isl/union_map.h>
#include <isl/union_set.h>
#include <isl/val.h>

#include <functional>
#include <string>

namespace isl {

inline namespace noexceptions {

// forward declarations
class Aff;
class AstBuild;
class AstExpr;
class AstNode;
class BasicMap;
class BasicSet;
class Id;
class LocalSpace;
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

#define ISLPP_STRINGIZE_(X) #X
#define ISLPP_STRINGIZE(X) ISLPP_STRINGIZE_(X)

#define ISLPP_ASSERT(test, message)                          \
  do {                                                       \
    if (test)                                                \
      break;                                                 \
    fputs("Assertion \"" #test "\" failed at " __FILE__      \
          ":" ISLPP_STRINGIZE(__LINE__) "\n  " message "\n", \
          stderr);                                           \
  } while (0)

class Bool {
private:
  friend Bool manage(isl_bool Val);

  isl_bool Val;

public:
  Bool()
      : Val(isl_bool_error) {}
  /* implicit */ Bool(bool Val)
      : Val(Val ? isl_bool_true : isl_bool_false) {}

  bool isError() const { return Val == isl_bool_error; }
  bool isFalseOrError() const { return Val != isl_bool_true; }
  bool isTrueOrError() const { return Val != isl_bool_false; }
  bool isNoError() const { return Val != isl_bool_error; }
  bool isFalseNoError() const { return Val == isl_bool_false; }
  bool isTrueNoError() const { return Val == isl_bool_true; }

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

inline Bool manage(isl_bool Val) {
  return Bool(Val);
}
class Ctx {
  isl_ctx *ptr;

public:
  Ctx(__isl_keep isl_ctx *ctx)
      : ptr(ctx) {}
  __isl_keep isl_ctx *release() { return ptr; }
};

enum class Dim {
  Cst = isl_dim_cst,
  Param = isl_dim_param,
  In = isl_dim_in,
  Out = isl_dim_out,
  Set = isl_dim_set,
  Div = isl_dim_div,
  All = isl_dim_all
};

enum class Stat {
  OK = isl_stat_ok,
  Error = isl_stat_error,
};

// declarations for isl::Aff
inline Aff manage(__isl_take isl_aff *ptr);

inline Aff give(__isl_take isl_aff *ptr);

class Aff {
  friend inline Aff manage(__isl_take isl_aff *ptr);

  isl_aff *ptr = nullptr;

  inline explicit Aff(__isl_take isl_aff *ptr);

public:
  inline Aff();
  inline Aff(const Aff &obj);
  inline Aff(std::nullptr_t);
  inline explicit Aff(LocalSpace ls);
  inline explicit Aff(LocalSpace ls, Val val);
  inline explicit Aff(Ctx ctx, std::string str);
  inline Aff &operator=(Aff obj);
  inline ~Aff();
  inline __isl_give isl_aff *copy() const &;
  inline __isl_give isl_aff *copy() && = delete;
  inline __isl_keep isl_aff *get() const;
  inline __isl_give isl_aff *release();
  inline __isl_keep isl_aff *keep() const;
  inline __isl_give isl_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Aff add(Aff aff2) const;
  inline Val getConstantVal() const;
  inline Bool isCst() const;
  inline Aff pullback(MultiAff ma) const;
};

// declarations for isl::AstBuild
inline AstBuild manage(__isl_take isl_ast_build *ptr);

inline AstBuild give(__isl_take isl_ast_build *ptr);

class AstBuild {
  friend inline AstBuild manage(__isl_take isl_ast_build *ptr);

  isl_ast_build *ptr = nullptr;

  inline explicit AstBuild(__isl_take isl_ast_build *ptr);

public:
  inline AstBuild();
  inline AstBuild(const AstBuild &obj);
  inline AstBuild(std::nullptr_t);
  inline explicit AstBuild(Ctx ctx);
  inline AstBuild &operator=(AstBuild obj);
  inline ~AstBuild();
  inline __isl_give isl_ast_build *copy() const &;
  inline __isl_give isl_ast_build *copy() && = delete;
  inline __isl_keep isl_ast_build *get() const;
  inline __isl_give isl_ast_build *release();
  inline __isl_keep isl_ast_build *keep() const;
  inline __isl_give isl_ast_build *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
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

inline AstExpr give(__isl_take isl_ast_expr *ptr);

class AstExpr {
  friend inline AstExpr manage(__isl_take isl_ast_expr *ptr);

  isl_ast_expr *ptr = nullptr;

  inline explicit AstExpr(__isl_take isl_ast_expr *ptr);

public:
  inline AstExpr();
  inline AstExpr(const AstExpr &obj);
  inline AstExpr(std::nullptr_t);
  inline AstExpr &operator=(AstExpr obj);
  inline ~AstExpr();
  inline __isl_give isl_ast_expr *copy() const &;
  inline __isl_give isl_ast_expr *copy() && = delete;
  inline __isl_keep isl_ast_expr *get() const;
  inline __isl_give isl_ast_expr *release();
  inline __isl_keep isl_ast_expr *keep() const;
  inline __isl_give isl_ast_expr *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline std::string toCStr() const;
};

// declarations for isl::AstNode
inline AstNode manage(__isl_take isl_ast_node *ptr);

inline AstNode give(__isl_take isl_ast_node *ptr);

class AstNode {
  friend inline AstNode manage(__isl_take isl_ast_node *ptr);

  isl_ast_node *ptr = nullptr;

  inline explicit AstNode(__isl_take isl_ast_node *ptr);

public:
  inline AstNode();
  inline AstNode(const AstNode &obj);
  inline AstNode(std::nullptr_t);
  inline AstNode &operator=(AstNode obj);
  inline ~AstNode();
  inline __isl_give isl_ast_node *copy() const &;
  inline __isl_give isl_ast_node *copy() && = delete;
  inline __isl_keep isl_ast_node *get() const;
  inline __isl_give isl_ast_node *release();
  inline __isl_keep isl_ast_node *keep() const;
  inline __isl_give isl_ast_node *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline std::string toCStr() const;
};

// declarations for isl::BasicMap
inline BasicMap manage(__isl_take isl_basic_map *ptr);

inline BasicMap give(__isl_take isl_basic_map *ptr);

class BasicMap {
  friend inline BasicMap manage(__isl_take isl_basic_map *ptr);

  isl_basic_map *ptr = nullptr;

  inline explicit BasicMap(__isl_take isl_basic_map *ptr);

public:
  inline BasicMap();
  inline BasicMap(const BasicMap &obj);
  inline BasicMap(std::nullptr_t);
  inline explicit BasicMap(Ctx ctx, std::string str);
  inline BasicMap &operator=(BasicMap obj);
  inline ~BasicMap();
  inline __isl_give isl_basic_map *copy() const &;
  inline __isl_give isl_basic_map *copy() && = delete;
  inline __isl_keep isl_basic_map *get() const;
  inline __isl_give isl_basic_map *release();
  inline __isl_keep isl_basic_map *keep() const;
  inline __isl_give isl_basic_map *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline BasicMap affineHull() const;
  inline BasicMap applyDomain(BasicMap bmap2) const;
  inline BasicMap applyRange(BasicMap bmap2) const;
  inline BasicSet deltas() const;
  inline BasicMap detectEqualities() const;
  inline BasicMap fixSi(enum Dim type, unsigned int pos, int value) const;
  inline BasicMap flatten() const;
  inline BasicMap flattenDomain() const;
  inline BasicMap flattenRange() const;
  inline BasicMap gist(BasicMap context) const;
  inline BasicMap intersect(BasicMap bmap2) const;
  inline BasicMap intersectDomain(BasicSet bset) const;
  inline BasicMap intersectRange(BasicSet bset) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const BasicMap &bmap2) const;
  inline Bool isSubset(const BasicMap &bmap2) const;
  inline Map lexmax() const;
  inline Map lexmin() const;
  inline Val plainGetValIfFixed(enum Dim type, unsigned int pos) const;
  inline BasicMap projectOut(enum Dim type, unsigned int first, unsigned int n) const;
  inline BasicMap reverse() const;
  inline BasicMap sample() const;
  inline Map unite(BasicMap bmap2) const;
  static inline BasicMap universe(Space dim);
};

// declarations for isl::BasicSet
inline BasicSet manage(__isl_take isl_basic_set *ptr);

inline BasicSet give(__isl_take isl_basic_set *ptr);

class BasicSet {
  friend inline BasicSet manage(__isl_take isl_basic_set *ptr);

  isl_basic_set *ptr = nullptr;

  inline explicit BasicSet(__isl_take isl_basic_set *ptr);

public:
  inline BasicSet();
  inline BasicSet(const BasicSet &obj);
  inline BasicSet(std::nullptr_t);
  inline explicit BasicSet(Ctx ctx, std::string str);
  inline /* implicit */ BasicSet(Point pnt);
  inline BasicSet &operator=(BasicSet obj);
  inline ~BasicSet();
  inline __isl_give isl_basic_set *copy() const &;
  inline __isl_give isl_basic_set *copy() && = delete;
  inline __isl_keep isl_basic_set *get() const;
  inline __isl_give isl_basic_set *release();
  inline __isl_keep isl_basic_set *keep() const;
  inline __isl_give isl_basic_set *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline BasicSet affineHull() const;
  inline BasicSet apply(BasicMap bmap) const;
  inline BasicSet detectEqualities() const;
  inline BasicSet flatten() const;
  inline BasicSet gist(BasicSet context) const;
  inline BasicSet intersect(BasicSet bset2) const;
  inline BasicSet intersectParams(BasicSet bset2) const;
  inline Bool isBounded() const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const BasicSet &bset2) const;
  inline Bool isSubset(const BasicSet &bset2) const;
  inline Bool isWrapping() const;
  inline Set lexmax() const;
  inline Set lexmin() const;
  inline BasicSet projectOut(enum Dim type, unsigned int first, unsigned int n) const;
  inline BasicSet sample() const;
  inline Point samplePoint() const;
  inline Set unite(BasicSet bset2) const;
};

// declarations for isl::Id
inline Id manage(__isl_take isl_id *ptr);

inline Id give(__isl_take isl_id *ptr);

class Id {
  friend inline Id manage(__isl_take isl_id *ptr);

  isl_id *ptr = nullptr;

  inline explicit Id(__isl_take isl_id *ptr);

public:
  inline Id();
  inline Id(const Id &obj);
  inline Id(std::nullptr_t);
  inline Id &operator=(Id obj);
  inline ~Id();
  inline __isl_give isl_id *copy() const &;
  inline __isl_give isl_id *copy() && = delete;
  inline __isl_keep isl_id *get() const;
  inline __isl_give isl_id *release();
  inline __isl_keep isl_id *keep() const;
  inline __isl_give isl_id *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
};

// declarations for isl::LocalSpace
inline LocalSpace manage(__isl_take isl_local_space *ptr);

inline LocalSpace give(__isl_take isl_local_space *ptr);

class LocalSpace {
  friend inline LocalSpace manage(__isl_take isl_local_space *ptr);

  isl_local_space *ptr = nullptr;

  inline explicit LocalSpace(__isl_take isl_local_space *ptr);

public:
  inline LocalSpace();
  inline LocalSpace(const LocalSpace &obj);
  inline LocalSpace(std::nullptr_t);
  inline explicit LocalSpace(Space dim);
  inline LocalSpace &operator=(LocalSpace obj);
  inline ~LocalSpace();
  inline __isl_give isl_local_space *copy() const &;
  inline __isl_give isl_local_space *copy() && = delete;
  inline __isl_keep isl_local_space *get() const;
  inline __isl_give isl_local_space *release();
  inline __isl_keep isl_local_space *keep() const;
  inline __isl_give isl_local_space *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
};

// declarations for isl::Map
inline Map manage(__isl_take isl_map *ptr);

inline Map give(__isl_take isl_map *ptr);

class Map {
  friend inline Map manage(__isl_take isl_map *ptr);

  isl_map *ptr = nullptr;

  inline explicit Map(__isl_take isl_map *ptr);

public:
  inline Map();
  inline Map(const Map &obj);
  inline Map(std::nullptr_t);
  inline explicit Map(Ctx ctx, std::string str);
  inline /* implicit */ Map(BasicMap bmap);
  inline Map &operator=(Map obj);
  inline ~Map();
  inline __isl_give isl_map *copy() const &;
  inline __isl_give isl_map *copy() && = delete;
  inline __isl_keep isl_map *get() const;
  inline __isl_give isl_map *release();
  inline __isl_keep isl_map *keep() const;
  inline __isl_give isl_map *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline BasicMap affineHull() const;
  inline Map applyDomain(Map map2) const;
  inline Map applyRange(Map map2) const;
  inline Map coalesce() const;
  inline Map complement() const;
  inline Set deltas() const;
  inline Map detectEqualities() const;
  inline unsigned int dim(enum Dim type) const;
  inline PwAff dimMax(int pos) const;
  inline PwAff dimMin(int pos) const;
  inline Map flatten() const;
  inline Map flattenDomain() const;
  inline Map flattenRange() const;
  inline Stat foreachBasicMap(std::function<Stat(BasicMap)> &&fn) const;
  static inline Map fromRange(Set set);
  inline Map gist(Map context) const;
  inline Map gistDomain(Set context) const;
  inline Map intersect(Map map2) const;
  inline Map intersectDomain(Set set) const;
  inline Map intersectParams(Set params) const;
  inline Map intersectRange(Set set) const;
  inline Bool isBijective() const;
  inline Bool isDisjoint(const Map &map2) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const Map &map2) const;
  inline Bool isInjective() const;
  inline Bool isSingleValued() const;
  inline Bool isStrictSubset(const Map &map2) const;
  inline Bool isSubset(const Map &map2) const;
  inline Map lexmax() const;
  inline Map lexmin() const;
  inline BasicMap polyhedralHull() const;
  inline Map projectOut(enum Dim type, unsigned int first, unsigned int n) const;
  inline Map reverse() const;
  inline BasicMap sample() const;
  inline Map subtract(Map map2) const;
  inline Map unite(Map map2) const;
  inline BasicMap unshiftedSimpleHull() const;
};

// declarations for isl::MultiAff
inline MultiAff manage(__isl_take isl_multi_aff *ptr);

inline MultiAff give(__isl_take isl_multi_aff *ptr);

class MultiAff {
  friend inline MultiAff manage(__isl_take isl_multi_aff *ptr);

  isl_multi_aff *ptr = nullptr;

  inline explicit MultiAff(__isl_take isl_multi_aff *ptr);

public:
  inline MultiAff();
  inline MultiAff(const MultiAff &obj);
  inline MultiAff(std::nullptr_t);
  inline /* implicit */ MultiAff(Aff aff);
  inline explicit MultiAff(Ctx ctx, std::string str);
  inline MultiAff &operator=(MultiAff obj);
  inline ~MultiAff();
  inline __isl_give isl_multi_aff *copy() const &;
  inline __isl_give isl_multi_aff *copy() && = delete;
  inline __isl_keep isl_multi_aff *get() const;
  inline __isl_give isl_multi_aff *release();
  inline __isl_keep isl_multi_aff *keep() const;
  inline __isl_give isl_multi_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiAff add(MultiAff multi2) const;
  inline MultiAff flatRangeProduct(MultiAff multi2) const;
  inline Aff getAff(int pos) const;
  inline MultiAff product(MultiAff multi2) const;
  inline MultiAff pullback(MultiAff ma2) const;
  inline MultiAff rangeProduct(MultiAff multi2) const;
};

// declarations for isl::MultiPwAff
inline MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr);

inline MultiPwAff give(__isl_take isl_multi_pw_aff *ptr);

class MultiPwAff {
  friend inline MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr);

  isl_multi_pw_aff *ptr = nullptr;

  inline explicit MultiPwAff(__isl_take isl_multi_pw_aff *ptr);

public:
  inline MultiPwAff();
  inline MultiPwAff(const MultiPwAff &obj);
  inline MultiPwAff(std::nullptr_t);
  inline /* implicit */ MultiPwAff(MultiAff ma);
  inline /* implicit */ MultiPwAff(PwAff pa);
  inline /* implicit */ MultiPwAff(PwMultiAff pma);
  inline explicit MultiPwAff(Ctx ctx, std::string str);
  inline MultiPwAff &operator=(MultiPwAff obj);
  inline ~MultiPwAff();
  inline __isl_give isl_multi_pw_aff *copy() const &;
  inline __isl_give isl_multi_pw_aff *copy() && = delete;
  inline __isl_keep isl_multi_pw_aff *get() const;
  inline __isl_give isl_multi_pw_aff *release();
  inline __isl_keep isl_multi_pw_aff *keep() const;
  inline __isl_give isl_multi_pw_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiPwAff add(MultiPwAff multi2) const;
  inline MultiPwAff flatRangeProduct(MultiPwAff multi2) const;
  inline PwAff getPwAff(int pos) const;
  inline MultiPwAff product(MultiPwAff multi2) const;
  inline MultiPwAff pullback(MultiAff ma) const;
  inline MultiPwAff pullback(PwMultiAff pma) const;
  inline MultiPwAff pullback(MultiPwAff mpa2) const;
  inline MultiPwAff rangeProduct(MultiPwAff multi2) const;
};

// declarations for isl::MultiUnionPwAff
inline MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr);

inline MultiUnionPwAff give(__isl_take isl_multi_union_pw_aff *ptr);

class MultiUnionPwAff {
  friend inline MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr);

  isl_multi_union_pw_aff *ptr = nullptr;

  inline explicit MultiUnionPwAff(__isl_take isl_multi_union_pw_aff *ptr);

public:
  inline MultiUnionPwAff();
  inline MultiUnionPwAff(const MultiUnionPwAff &obj);
  inline MultiUnionPwAff(std::nullptr_t);
  inline /* implicit */ MultiUnionPwAff(UnionPwAff upa);
  inline /* implicit */ MultiUnionPwAff(MultiPwAff mpa);
  inline explicit MultiUnionPwAff(UnionPwMultiAff upma);
  inline explicit MultiUnionPwAff(Ctx ctx, std::string str);
  inline MultiUnionPwAff &operator=(MultiUnionPwAff obj);
  inline ~MultiUnionPwAff();
  inline __isl_give isl_multi_union_pw_aff *copy() const &;
  inline __isl_give isl_multi_union_pw_aff *copy() && = delete;
  inline __isl_keep isl_multi_union_pw_aff *get() const;
  inline __isl_give isl_multi_union_pw_aff *release();
  inline __isl_keep isl_multi_union_pw_aff *keep() const;
  inline __isl_give isl_multi_union_pw_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiUnionPwAff add(MultiUnionPwAff multi2) const;
  inline MultiUnionPwAff flatRangeProduct(MultiUnionPwAff multi2) const;
  inline UnionPwAff getUnionPwAff(int pos) const;
  inline MultiUnionPwAff pullback(UnionPwMultiAff upma) const;
  inline MultiUnionPwAff rangeProduct(MultiUnionPwAff multi2) const;
  inline MultiUnionPwAff unionAdd(MultiUnionPwAff mupa2) const;
};

// declarations for isl::MultiVal
inline MultiVal manage(__isl_take isl_multi_val *ptr);

inline MultiVal give(__isl_take isl_multi_val *ptr);

class MultiVal {
  friend inline MultiVal manage(__isl_take isl_multi_val *ptr);

  isl_multi_val *ptr = nullptr;

  inline explicit MultiVal(__isl_take isl_multi_val *ptr);

public:
  inline MultiVal();
  inline MultiVal(const MultiVal &obj);
  inline MultiVal(std::nullptr_t);
  inline MultiVal &operator=(MultiVal obj);
  inline ~MultiVal();
  inline __isl_give isl_multi_val *copy() const &;
  inline __isl_give isl_multi_val *copy() && = delete;
  inline __isl_keep isl_multi_val *get() const;
  inline __isl_give isl_multi_val *release();
  inline __isl_keep isl_multi_val *keep() const;
  inline __isl_give isl_multi_val *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline MultiVal add(MultiVal multi2) const;
  inline MultiVal flatRangeProduct(MultiVal multi2) const;
  inline Val getVal(int pos) const;
  inline MultiVal product(MultiVal multi2) const;
  inline MultiVal rangeProduct(MultiVal multi2) const;
};

// declarations for isl::Point
inline Point manage(__isl_take isl_point *ptr);

inline Point give(__isl_take isl_point *ptr);

class Point {
  friend inline Point manage(__isl_take isl_point *ptr);

  isl_point *ptr = nullptr;

  inline explicit Point(__isl_take isl_point *ptr);

public:
  inline Point();
  inline Point(const Point &obj);
  inline Point(std::nullptr_t);
  inline explicit Point(Space dim);
  inline Point &operator=(Point obj);
  inline ~Point();
  inline __isl_give isl_point *copy() const &;
  inline __isl_give isl_point *copy() && = delete;
  inline __isl_keep isl_point *get() const;
  inline __isl_give isl_point *release();
  inline __isl_keep isl_point *keep() const;
  inline __isl_give isl_point *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
};

// declarations for isl::PwAff
inline PwAff manage(__isl_take isl_pw_aff *ptr);

inline PwAff give(__isl_take isl_pw_aff *ptr);

class PwAff {
  friend inline PwAff manage(__isl_take isl_pw_aff *ptr);

  isl_pw_aff *ptr = nullptr;

  inline explicit PwAff(__isl_take isl_pw_aff *ptr);

public:
  inline PwAff();
  inline PwAff(const PwAff &obj);
  inline PwAff(std::nullptr_t);
  inline /* implicit */ PwAff(Aff aff);
  inline explicit PwAff(LocalSpace ls);
  inline explicit PwAff(Set domain, Val v);
  inline explicit PwAff(Ctx ctx, std::string str);
  inline PwAff &operator=(PwAff obj);
  inline ~PwAff();
  inline __isl_give isl_pw_aff *copy() const &;
  inline __isl_give isl_pw_aff *copy() && = delete;
  inline __isl_keep isl_pw_aff *get() const;
  inline __isl_give isl_pw_aff *release();
  inline __isl_keep isl_pw_aff *keep() const;
  inline __isl_give isl_pw_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline PwAff add(PwAff pwaff2) const;
  inline Stat foreachPiece(std::function<Stat(Set, Aff)> &&fn) const;
  inline Space getSpace() const;
  inline Bool isCst() const;
  inline PwAff mul(PwAff pwaff2) const;
  inline PwAff neg() const;
  inline PwAff pullback(MultiAff ma) const;
  inline PwAff pullback(PwMultiAff pma) const;
  inline PwAff pullback(MultiPwAff mpa) const;
  inline PwAff sub(PwAff pwaff2) const;
  inline PwAff unionAdd(PwAff pwaff2) const;
};

// declarations for isl::PwMultiAff
inline PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr);

inline PwMultiAff give(__isl_take isl_pw_multi_aff *ptr);

class PwMultiAff {
  friend inline PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr);

  isl_pw_multi_aff *ptr = nullptr;

  inline explicit PwMultiAff(__isl_take isl_pw_multi_aff *ptr);

public:
  inline PwMultiAff();
  inline PwMultiAff(const PwMultiAff &obj);
  inline PwMultiAff(std::nullptr_t);
  inline explicit PwMultiAff(Ctx ctx, std::string str);
  inline /* implicit */ PwMultiAff(MultiAff ma);
  inline /* implicit */ PwMultiAff(PwAff pa);
  inline PwMultiAff &operator=(PwMultiAff obj);
  inline ~PwMultiAff();
  inline __isl_give isl_pw_multi_aff *copy() const &;
  inline __isl_give isl_pw_multi_aff *copy() && = delete;
  inline __isl_keep isl_pw_multi_aff *get() const;
  inline __isl_give isl_pw_multi_aff *release();
  inline __isl_keep isl_pw_multi_aff *keep() const;
  inline __isl_give isl_pw_multi_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline PwMultiAff add(PwMultiAff pma2) const;
  inline PwMultiAff flatRangeProduct(PwMultiAff pma2) const;
  inline PwMultiAff product(PwMultiAff pma2) const;
  inline PwMultiAff pullback(MultiAff ma) const;
  inline PwMultiAff pullback(PwMultiAff pma2) const;
  inline PwMultiAff rangeProduct(PwMultiAff pma2) const;
  inline PwMultiAff unionAdd(PwMultiAff pma2) const;
};

// declarations for isl::Schedule
inline Schedule manage(__isl_take isl_schedule *ptr);

inline Schedule give(__isl_take isl_schedule *ptr);

class Schedule {
  friend inline Schedule manage(__isl_take isl_schedule *ptr);

  isl_schedule *ptr = nullptr;

  inline explicit Schedule(__isl_take isl_schedule *ptr);

public:
  inline Schedule();
  inline Schedule(const Schedule &obj);
  inline Schedule(std::nullptr_t);
  inline explicit Schedule(Ctx ctx, std::string str);
  inline Schedule &operator=(Schedule obj);
  inline ~Schedule();
  inline __isl_give isl_schedule *copy() const &;
  inline __isl_give isl_schedule *copy() && = delete;
  inline __isl_keep isl_schedule *get() const;
  inline __isl_give isl_schedule *release();
  inline __isl_keep isl_schedule *keep() const;
  inline __isl_give isl_schedule *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionMap getMap() const;
  inline ScheduleNode getRoot() const;
  inline Schedule pullback(UnionPwMultiAff upma) const;
};

// declarations for isl::ScheduleConstraints
inline ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr);

inline ScheduleConstraints give(__isl_take isl_schedule_constraints *ptr);

class ScheduleConstraints {
  friend inline ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr);

  isl_schedule_constraints *ptr = nullptr;

  inline explicit ScheduleConstraints(__isl_take isl_schedule_constraints *ptr);

public:
  inline ScheduleConstraints();
  inline ScheduleConstraints(const ScheduleConstraints &obj);
  inline ScheduleConstraints(std::nullptr_t);
  inline explicit ScheduleConstraints(Ctx ctx, std::string str);
  inline ScheduleConstraints &operator=(ScheduleConstraints obj);
  inline ~ScheduleConstraints();
  inline __isl_give isl_schedule_constraints *copy() const &;
  inline __isl_give isl_schedule_constraints *copy() && = delete;
  inline __isl_keep isl_schedule_constraints *get() const;
  inline __isl_give isl_schedule_constraints *release();
  inline __isl_keep isl_schedule_constraints *keep() const;
  inline __isl_give isl_schedule_constraints *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
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

inline ScheduleNode give(__isl_take isl_schedule_node *ptr);

class ScheduleNode {
  friend inline ScheduleNode manage(__isl_take isl_schedule_node *ptr);

  isl_schedule_node *ptr = nullptr;

  inline explicit ScheduleNode(__isl_take isl_schedule_node *ptr);

public:
  inline ScheduleNode();
  inline ScheduleNode(const ScheduleNode &obj);
  inline ScheduleNode(std::nullptr_t);
  inline ScheduleNode &operator=(ScheduleNode obj);
  inline ~ScheduleNode();
  inline __isl_give isl_schedule_node *copy() const &;
  inline __isl_give isl_schedule_node *copy() && = delete;
  inline __isl_keep isl_schedule_node *get() const;
  inline __isl_give isl_schedule_node *release();
  inline __isl_keep isl_schedule_node *keep() const;
  inline __isl_give isl_schedule_node *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Bool bandMemberGetCoincident(int pos) const;
  inline ScheduleNode bandMemberSetCoincident(int pos, int coincident) const;
  inline ScheduleNode child(int pos) const;
  inline MultiUnionPwAff getPrefixScheduleMultiUnionPwAff() const;
  inline UnionMap getPrefixScheduleUnionMap() const;
  inline UnionPwMultiAff getPrefixScheduleUnionPwMultiAff() const;
  inline Schedule getSchedule() const;
  inline ScheduleNode parent() const;
};

// declarations for isl::Set
inline Set manage(__isl_take isl_set *ptr);

inline Set give(__isl_take isl_set *ptr);

class Set {
  friend inline Set manage(__isl_take isl_set *ptr);

  isl_set *ptr = nullptr;

  inline explicit Set(__isl_take isl_set *ptr);

public:
  inline Set();
  inline Set(const Set &obj);
  inline Set(std::nullptr_t);
  inline explicit Set(Ctx ctx, std::string str);
  inline /* implicit */ Set(BasicSet bset);
  inline /* implicit */ Set(Point pnt);
  inline explicit Set(UnionSet uset);
  inline Set &operator=(Set obj);
  inline ~Set();
  inline __isl_give isl_set *copy() const &;
  inline __isl_give isl_set *copy() && = delete;
  inline __isl_keep isl_set *get() const;
  inline __isl_give isl_set *release();
  inline __isl_keep isl_set *keep() const;
  inline __isl_give isl_set *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Set addDims(enum Dim type, unsigned int n) const;
  inline BasicSet affineHull() const;
  inline Set apply(Map map) const;
  inline Set coalesce() const;
  inline Set complement() const;
  inline Set detectEqualities() const;
  inline unsigned int dim(enum Dim type) const;
  inline PwAff dimMax(int pos) const;
  inline PwAff dimMin(int pos) const;
  inline Set flatten() const;
  inline Stat foreachBasicSet(std::function<Stat(BasicSet)> &&fn) const;
  inline Set gist(Set context) const;
  inline Map identity() const;
  inline Set intersect(Set set2) const;
  inline Set intersectParams(Set params) const;
  inline Bool isBounded() const;
  inline Bool isDisjoint(const Set &set2) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const Set &set2) const;
  inline Bool isStrictSubset(const Set &set2) const;
  inline Bool isSubset(const Set &set2) const;
  inline Bool isWrapping() const;
  inline Set lexmax() const;
  inline Set lexmin() const;
  inline Val maxVal(const Aff &obj) const;
  inline Val minVal(const Aff &obj) const;
  inline BasicSet polyhedralHull() const;
  inline Set projectOut(enum Dim type, unsigned int first, unsigned int n) const;
  inline BasicSet sample() const;
  inline Point samplePoint() const;
  inline Set subtract(Set set2) const;
  inline Set unite(Set set2) const;
  static inline Set universe(Space dim);
  inline BasicSet unshiftedSimpleHull() const;
};

// declarations for isl::Space
inline Space manage(__isl_take isl_space *ptr);

inline Space give(__isl_take isl_space *ptr);

class Space {
  friend inline Space manage(__isl_take isl_space *ptr);

  isl_space *ptr = nullptr;

  inline explicit Space(__isl_take isl_space *ptr);

public:
  inline Space();
  inline Space(const Space &obj);
  inline Space(std::nullptr_t);
  inline explicit Space(Ctx ctx, unsigned int nparam, unsigned int n_in, unsigned int n_out);
  inline explicit Space(Ctx ctx, unsigned int nparam, unsigned int dim);
  inline Space &operator=(Space obj);
  inline ~Space();
  inline __isl_give isl_space *copy() const &;
  inline __isl_give isl_space *copy() && = delete;
  inline __isl_keep isl_space *get() const;
  inline __isl_give isl_space *release();
  inline __isl_keep isl_space *keep() const;
  inline __isl_give isl_space *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Space domain() const;
  inline Bool isEqual(const Space &space2) const;
  inline Space params() const;
  inline Space setFromParams() const;
};

// declarations for isl::UnionAccessInfo
inline UnionAccessInfo manage(__isl_take isl_union_access_info *ptr);

inline UnionAccessInfo give(__isl_take isl_union_access_info *ptr);

class UnionAccessInfo {
  friend inline UnionAccessInfo manage(__isl_take isl_union_access_info *ptr);

  isl_union_access_info *ptr = nullptr;

  inline explicit UnionAccessInfo(__isl_take isl_union_access_info *ptr);

public:
  inline UnionAccessInfo();
  inline UnionAccessInfo(const UnionAccessInfo &obj);
  inline UnionAccessInfo(std::nullptr_t);
  inline explicit UnionAccessInfo(UnionMap sink);
  inline UnionAccessInfo &operator=(UnionAccessInfo obj);
  inline ~UnionAccessInfo();
  inline __isl_give isl_union_access_info *copy() const &;
  inline __isl_give isl_union_access_info *copy() && = delete;
  inline __isl_keep isl_union_access_info *get() const;
  inline __isl_give isl_union_access_info *release();
  inline __isl_keep isl_union_access_info *keep() const;
  inline __isl_give isl_union_access_info *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionFlow computeFlow() const;
  inline UnionAccessInfo setMaySource(UnionMap may_source) const;
  inline UnionAccessInfo setMustSource(UnionMap must_source) const;
  inline UnionAccessInfo setSchedule(Schedule schedule) const;
  inline UnionAccessInfo setScheduleMap(UnionMap schedule_map) const;
};

// declarations for isl::UnionFlow
inline UnionFlow manage(__isl_take isl_union_flow *ptr);

inline UnionFlow give(__isl_take isl_union_flow *ptr);

class UnionFlow {
  friend inline UnionFlow manage(__isl_take isl_union_flow *ptr);

  isl_union_flow *ptr = nullptr;

  inline explicit UnionFlow(__isl_take isl_union_flow *ptr);

public:
  inline UnionFlow();
  inline UnionFlow(const UnionFlow &obj);
  inline UnionFlow(std::nullptr_t);
  inline UnionFlow &operator=(UnionFlow obj);
  inline ~UnionFlow();
  inline __isl_give isl_union_flow *copy() const &;
  inline __isl_give isl_union_flow *copy() && = delete;
  inline __isl_keep isl_union_flow *get() const;
  inline __isl_give isl_union_flow *release();
  inline __isl_keep isl_union_flow *keep() const;
  inline __isl_give isl_union_flow *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
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

inline UnionMap give(__isl_take isl_union_map *ptr);

class UnionMap {
  friend inline UnionMap manage(__isl_take isl_union_map *ptr);

  isl_union_map *ptr = nullptr;

  inline explicit UnionMap(__isl_take isl_union_map *ptr);

public:
  inline UnionMap();
  inline UnionMap(const UnionMap &obj);
  inline UnionMap(std::nullptr_t);
  inline explicit UnionMap(Ctx ctx, std::string str);
  inline explicit UnionMap(UnionPwAff upa);
  inline /* implicit */ UnionMap(BasicMap bmap);
  inline /* implicit */ UnionMap(Map map);
  inline UnionMap &operator=(UnionMap obj);
  inline ~UnionMap();
  inline __isl_give isl_union_map *copy() const &;
  inline __isl_give isl_union_map *copy() && = delete;
  inline __isl_keep isl_union_map *get() const;
  inline __isl_give isl_union_map *release();
  inline __isl_keep isl_union_map *keep() const;
  inline __isl_give isl_union_map *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionMap addMap(Map map) const;
  inline UnionMap affineHull() const;
  inline UnionMap applyDomain(UnionMap umap2) const;
  inline UnionMap applyRange(UnionMap umap2) const;
  inline UnionMap coalesce() const;
  inline UnionMap computeDivs() const;
  inline UnionSet deltas() const;
  inline UnionMap detectEqualities() const;
  inline UnionSet domain() const;
  inline UnionMap domainFactorDomain() const;
  inline UnionMap domainFactorRange() const;
  inline UnionMap domainMap() const;
  inline UnionPwMultiAff domainMapUnionPwMultiAff() const;
  inline UnionMap domainProduct(UnionMap umap2) const;
  static inline UnionMap empty(Space dim);
  inline UnionMap factorDomain() const;
  inline UnionMap factorRange() const;
  inline UnionMap fixedPower(Val exp) const;
  inline UnionMap flatRangeProduct(UnionMap umap2) const;
  inline Stat foreachMap(std::function<Stat(Map)> &&fn) const;
  static inline UnionMap from(UnionPwMultiAff upma);
  static inline UnionMap from(MultiUnionPwAff mupa);
  static inline UnionMap fromDomainAndRange(UnionSet domain, UnionSet range);
  inline Space getSpace() const;
  inline UnionMap gist(UnionMap context) const;
  inline UnionMap gistDomain(UnionSet uset) const;
  inline UnionMap gistParams(Set set) const;
  inline UnionMap gistRange(UnionSet uset) const;
  inline UnionMap intersect(UnionMap umap2) const;
  inline UnionMap intersectDomain(UnionSet uset) const;
  inline UnionMap intersectParams(Set set) const;
  inline UnionMap intersectRange(UnionSet uset) const;
  inline Bool isBijective() const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const UnionMap &umap2) const;
  inline Bool isInjective() const;
  inline Bool isSingleValued() const;
  inline Bool isStrictSubset(const UnionMap &umap2) const;
  inline Bool isSubset(const UnionMap &umap2) const;
  inline UnionMap lexmax() const;
  inline UnionMap lexmin() const;
  inline UnionMap polyhedralHull() const;
  inline UnionMap product(UnionMap umap2) const;
  inline UnionSet range() const;
  inline UnionMap rangeFactorDomain() const;
  inline UnionMap rangeFactorRange() const;
  inline UnionMap rangeMap() const;
  inline UnionMap rangeProduct(UnionMap umap2) const;
  inline UnionMap reverse() const;
  inline UnionMap subtract(UnionMap umap2) const;
  inline UnionMap subtractDomain(UnionSet dom) const;
  inline UnionMap subtractRange(UnionSet dom) const;
  inline UnionMap unite(UnionMap umap2) const;
  inline UnionSet wrap() const;
  inline UnionMap zip() const;
};

// declarations for isl::UnionPwAff
inline UnionPwAff manage(__isl_take isl_union_pw_aff *ptr);

inline UnionPwAff give(__isl_take isl_union_pw_aff *ptr);

class UnionPwAff {
  friend inline UnionPwAff manage(__isl_take isl_union_pw_aff *ptr);

  isl_union_pw_aff *ptr = nullptr;

  inline explicit UnionPwAff(__isl_take isl_union_pw_aff *ptr);

public:
  inline UnionPwAff();
  inline UnionPwAff(const UnionPwAff &obj);
  inline UnionPwAff(std::nullptr_t);
  inline /* implicit */ UnionPwAff(PwAff pa);
  inline explicit UnionPwAff(UnionSet domain, Val v);
  inline explicit UnionPwAff(Ctx ctx, std::string str);
  inline UnionPwAff &operator=(UnionPwAff obj);
  inline ~UnionPwAff();
  inline __isl_give isl_union_pw_aff *copy() const &;
  inline __isl_give isl_union_pw_aff *copy() && = delete;
  inline __isl_keep isl_union_pw_aff *get() const;
  inline __isl_give isl_union_pw_aff *release();
  inline __isl_keep isl_union_pw_aff *keep() const;
  inline __isl_give isl_union_pw_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionPwAff add(UnionPwAff upa2) const;
  static inline UnionPwAff empty(Space space);
  inline Stat foreachPwAff(std::function<Stat(PwAff)> &&fn) const;
  inline Space getSpace() const;
  inline UnionPwAff pullback(UnionPwMultiAff upma) const;
  inline UnionPwAff sub(UnionPwAff upa2) const;
  inline UnionPwAff unionAdd(UnionPwAff upa2) const;
};

// declarations for isl::UnionPwMultiAff
inline UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr);

inline UnionPwMultiAff give(__isl_take isl_union_pw_multi_aff *ptr);

class UnionPwMultiAff {
  friend inline UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr);

  isl_union_pw_multi_aff *ptr = nullptr;

  inline explicit UnionPwMultiAff(__isl_take isl_union_pw_multi_aff *ptr);

public:
  inline UnionPwMultiAff();
  inline UnionPwMultiAff(const UnionPwMultiAff &obj);
  inline UnionPwMultiAff(std::nullptr_t);
  inline /* implicit */ UnionPwMultiAff(PwMultiAff pma);
  inline explicit UnionPwMultiAff(UnionSet uset);
  inline explicit UnionPwMultiAff(UnionMap umap);
  inline explicit UnionPwMultiAff(Ctx ctx, std::string str);
  inline /* implicit */ UnionPwMultiAff(UnionPwAff upa);
  inline UnionPwMultiAff &operator=(UnionPwMultiAff obj);
  inline ~UnionPwMultiAff();
  inline __isl_give isl_union_pw_multi_aff *copy() const &;
  inline __isl_give isl_union_pw_multi_aff *copy() && = delete;
  inline __isl_keep isl_union_pw_multi_aff *get() const;
  inline __isl_give isl_union_pw_multi_aff *release();
  inline __isl_keep isl_union_pw_multi_aff *keep() const;
  inline __isl_give isl_union_pw_multi_aff *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionPwMultiAff add(UnionPwMultiAff upma2) const;
  inline UnionPwMultiAff flatRangeProduct(UnionPwMultiAff upma2) const;
  inline UnionPwMultiAff pullback(UnionPwMultiAff upma2) const;
  inline UnionPwMultiAff unionAdd(UnionPwMultiAff upma2) const;
};

// declarations for isl::UnionSet
inline UnionSet manage(__isl_take isl_union_set *ptr);

inline UnionSet give(__isl_take isl_union_set *ptr);

class UnionSet {
  friend inline UnionSet manage(__isl_take isl_union_set *ptr);

  isl_union_set *ptr = nullptr;

  inline explicit UnionSet(__isl_take isl_union_set *ptr);

public:
  inline UnionSet();
  inline UnionSet(const UnionSet &obj);
  inline UnionSet(std::nullptr_t);
  inline /* implicit */ UnionSet(BasicSet bset);
  inline /* implicit */ UnionSet(Set set);
  inline /* implicit */ UnionSet(Point pnt);
  inline explicit UnionSet(Ctx ctx, std::string str);
  inline UnionSet &operator=(UnionSet obj);
  inline ~UnionSet();
  inline __isl_give isl_union_set *copy() const &;
  inline __isl_give isl_union_set *copy() && = delete;
  inline __isl_keep isl_union_set *get() const;
  inline __isl_give isl_union_set *release();
  inline __isl_keep isl_union_set *keep() const;
  inline __isl_give isl_union_set *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline UnionSet affineHull() const;
  inline UnionSet apply(UnionMap umap) const;
  inline UnionSet coalesce() const;
  inline UnionSet computeDivs() const;
  inline UnionSet detectEqualities() const;
  inline Stat foreachPoint(std::function<Stat(Point)> &&fn) const;
  inline Stat foreachSet(std::function<Stat(Set)> &&fn) const;
  inline UnionSet gist(UnionSet context) const;
  inline UnionSet gistParams(Set set) const;
  inline UnionMap identity() const;
  inline UnionSet intersect(UnionSet uset2) const;
  inline UnionSet intersectParams(Set set) const;
  inline Bool isEmpty() const;
  inline Bool isEqual(const UnionSet &uset2) const;
  inline Bool isStrictSubset(const UnionSet &uset2) const;
  inline Bool isSubset(const UnionSet &uset2) const;
  inline UnionSet lexmax() const;
  inline UnionSet lexmin() const;
  inline UnionSet polyhedralHull() const;
  inline Point samplePoint() const;
  inline UnionSet subtract(UnionSet uset2) const;
  inline UnionSet unite(UnionSet uset2) const;
  inline UnionMap unwrap() const;
};

// declarations for isl::Val
inline Val manage(__isl_take isl_val *ptr);

inline Val give(__isl_take isl_val *ptr);

class Val {
  friend inline Val manage(__isl_take isl_val *ptr);

  isl_val *ptr = nullptr;

  inline explicit Val(__isl_take isl_val *ptr);

public:
  inline Val();
  inline Val(const Val &obj);
  inline Val(std::nullptr_t);
  inline explicit Val(Ctx ctx, long i);
  inline explicit Val(Ctx ctx, unsigned long u);
  inline explicit Val(Ctx ctx, std::string str);
  inline Val &operator=(Val obj);
  inline ~Val();
  inline __isl_give isl_val *copy() const &;
  inline __isl_give isl_val *copy() && = delete;
  inline __isl_keep isl_val *get() const;
  inline __isl_give isl_val *release();
  inline __isl_keep isl_val *keep() const;
  inline __isl_give isl_val *take();
  inline explicit operator bool() const;
  inline isl_ctx *getCtx() const;
  inline bool isNull() const;
  inline std::string getStr() const;
  inline Val two_exp() const;
  inline Val abs() const;
  inline Bool absEq(const Val &v2) const;
  inline Val add(Val v2) const;
  inline Val addUi(unsigned long v2) const;
  inline Val ceil() const;
  inline int cmpSi(long i) const;
  inline Val div(Val v2) const;
  inline Bool eq(const Val &v2) const;
  inline Val floor() const;
  inline Val gcd(Val v2) const;
  inline Bool ge(const Val &v2) const;
  inline Bool gt(const Val &v2) const;
  static inline Val infty(Ctx ctx);
  inline Val inv() const;
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
  inline Val max(Val v2) const;
  inline Val min(Val v2) const;
  inline Val mod(Val v2) const;
  inline Val mul(Val v2) const;
  static inline Val nan(Ctx ctx);
  inline Bool ne(const Val &v2) const;
  inline Val neg() const;
  static inline Val neginfty(Ctx ctx);
  static inline Val negone(Ctx ctx);
  static inline Val one(Ctx ctx);
  inline int sgn() const;
  inline Val sub(Val v2) const;
  inline Val subUi(unsigned long v2) const;
  inline Val trunc() const;
  static inline Val zero(Ctx ctx);
};

// implementations for isl::Aff
Aff manage(__isl_take isl_aff *ptr) {
  return Aff(ptr);
}

Aff give(__isl_take isl_aff *ptr) {
  return manage(ptr);
}

Aff::Aff()
    : ptr(nullptr) {}

Aff::Aff(const Aff &obj)
    : ptr(obj.copy()) {}

Aff::Aff(std::nullptr_t)
    : ptr(nullptr) {}

Aff::Aff(__isl_take isl_aff *ptr)
    : ptr(ptr) {}

Aff::Aff(LocalSpace ls) {
  auto res = isl_aff_zero_on_domain(ls.release());
  ptr = res;
}
Aff::Aff(LocalSpace ls, Val val) {
  auto res = isl_aff_val_on_domain(ls.release(), val.release());
  ptr = res;
}
Aff::Aff(Ctx ctx, std::string str) {
  auto res = isl_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
Aff &Aff::operator=(Aff obj) {
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

__isl_keep isl_aff *Aff::keep() const {
  return get();
}

__isl_give isl_aff *Aff::take() {
  return release();
}

Aff::operator bool() const {
  return !isNull();
}

isl_ctx *Aff::getCtx() const {
  return isl_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Aff &Obj) {
  OS << Obj.getStr();
  return OS;
}

Aff Aff::add(Aff aff2) const {
  auto res = isl_aff_add(copy(), aff2.release());
  return manage(res);
}
Val Aff::getConstantVal() const {
  auto res = isl_aff_get_constant_val(get());
  return manage(res);
}
Bool Aff::isCst() const {
  auto res = isl_aff_is_cst(get());
  return res;
}
Aff Aff::pullback(MultiAff ma) const {
  auto res = isl_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}
// implementations for isl::AstBuild
AstBuild manage(__isl_take isl_ast_build *ptr) {
  return AstBuild(ptr);
}

AstBuild give(__isl_take isl_ast_build *ptr) {
  return manage(ptr);
}

AstBuild::AstBuild()
    : ptr(nullptr) {}

AstBuild::AstBuild(const AstBuild &obj)
    : ptr(obj.copy()) {}

AstBuild::AstBuild(std::nullptr_t)
    : ptr(nullptr) {}

AstBuild::AstBuild(__isl_take isl_ast_build *ptr)
    : ptr(ptr) {}

AstBuild::AstBuild(Ctx ctx) {
  auto res = isl_ast_build_alloc(ctx.release());
  ptr = res;
}
AstBuild &AstBuild::operator=(AstBuild obj) {
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

__isl_keep isl_ast_build *AstBuild::keep() const {
  return get();
}

__isl_give isl_ast_build *AstBuild::take() {
  return release();
}

AstBuild::operator bool() const {
  return !isNull();
}

isl_ctx *AstBuild::getCtx() const {
  return isl_ast_build_get_ctx(ptr);
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

AstExpr give(__isl_take isl_ast_expr *ptr) {
  return manage(ptr);
}

AstExpr::AstExpr()
    : ptr(nullptr) {}

AstExpr::AstExpr(const AstExpr &obj)
    : ptr(obj.copy()) {}

AstExpr::AstExpr(std::nullptr_t)
    : ptr(nullptr) {}

AstExpr::AstExpr(__isl_take isl_ast_expr *ptr)
    : ptr(ptr) {}

AstExpr &AstExpr::operator=(AstExpr obj) {
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

__isl_keep isl_ast_expr *AstExpr::keep() const {
  return get();
}

__isl_give isl_ast_expr *AstExpr::take() {
  return release();
}

AstExpr::operator bool() const {
  return !isNull();
}

isl_ctx *AstExpr::getCtx() const {
  return isl_ast_expr_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const AstExpr &Obj) {
  OS << Obj.getStr();
  return OS;
}

std::string AstExpr::toCStr() const {
  auto res = isl_ast_expr_to_C_str(get());
  return res;
}
// implementations for isl::AstNode
AstNode manage(__isl_take isl_ast_node *ptr) {
  return AstNode(ptr);
}

AstNode give(__isl_take isl_ast_node *ptr) {
  return manage(ptr);
}

AstNode::AstNode()
    : ptr(nullptr) {}

AstNode::AstNode(const AstNode &obj)
    : ptr(obj.copy()) {}

AstNode::AstNode(std::nullptr_t)
    : ptr(nullptr) {}

AstNode::AstNode(__isl_take isl_ast_node *ptr)
    : ptr(ptr) {}

AstNode &AstNode::operator=(AstNode obj) {
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

__isl_keep isl_ast_node *AstNode::keep() const {
  return get();
}

__isl_give isl_ast_node *AstNode::take() {
  return release();
}

AstNode::operator bool() const {
  return !isNull();
}

isl_ctx *AstNode::getCtx() const {
  return isl_ast_node_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const AstNode &Obj) {
  OS << Obj.getStr();
  return OS;
}

std::string AstNode::toCStr() const {
  auto res = isl_ast_node_to_C_str(get());
  return res;
}
// implementations for isl::BasicMap
BasicMap manage(__isl_take isl_basic_map *ptr) {
  return BasicMap(ptr);
}

BasicMap give(__isl_take isl_basic_map *ptr) {
  return manage(ptr);
}

BasicMap::BasicMap()
    : ptr(nullptr) {}

BasicMap::BasicMap(const BasicMap &obj)
    : ptr(obj.copy()) {}

BasicMap::BasicMap(std::nullptr_t)
    : ptr(nullptr) {}

BasicMap::BasicMap(__isl_take isl_basic_map *ptr)
    : ptr(ptr) {}

BasicMap::BasicMap(Ctx ctx, std::string str) {
  auto res = isl_basic_map_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
BasicMap &BasicMap::operator=(BasicMap obj) {
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

__isl_keep isl_basic_map *BasicMap::keep() const {
  return get();
}

__isl_give isl_basic_map *BasicMap::take() {
  return release();
}

BasicMap::operator bool() const {
  return !isNull();
}

isl_ctx *BasicMap::getCtx() const {
  return isl_basic_map_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const BasicMap &Obj) {
  OS << Obj.getStr();
  return OS;
}

BasicMap BasicMap::affineHull() const {
  auto res = isl_basic_map_affine_hull(copy());
  return manage(res);
}
BasicMap BasicMap::applyDomain(BasicMap bmap2) const {
  auto res = isl_basic_map_apply_domain(copy(), bmap2.release());
  return manage(res);
}
BasicMap BasicMap::applyRange(BasicMap bmap2) const {
  auto res = isl_basic_map_apply_range(copy(), bmap2.release());
  return manage(res);
}
BasicSet BasicMap::deltas() const {
  auto res = isl_basic_map_deltas(copy());
  return manage(res);
}
BasicMap BasicMap::detectEqualities() const {
  auto res = isl_basic_map_detect_equalities(copy());
  return manage(res);
}
BasicMap BasicMap::fixSi(enum Dim type, unsigned int pos, int value) const {
  auto res = isl_basic_map_fix_si(copy(), static_cast<enum isl_dim_type>(type), pos, value);
  return manage(res);
}
BasicMap BasicMap::flatten() const {
  auto res = isl_basic_map_flatten(copy());
  return manage(res);
}
BasicMap BasicMap::flattenDomain() const {
  auto res = isl_basic_map_flatten_domain(copy());
  return manage(res);
}
BasicMap BasicMap::flattenRange() const {
  auto res = isl_basic_map_flatten_range(copy());
  return manage(res);
}
BasicMap BasicMap::gist(BasicMap context) const {
  auto res = isl_basic_map_gist(copy(), context.release());
  return manage(res);
}
BasicMap BasicMap::intersect(BasicMap bmap2) const {
  auto res = isl_basic_map_intersect(copy(), bmap2.release());
  return manage(res);
}
BasicMap BasicMap::intersectDomain(BasicSet bset) const {
  auto res = isl_basic_map_intersect_domain(copy(), bset.release());
  return manage(res);
}
BasicMap BasicMap::intersectRange(BasicSet bset) const {
  auto res = isl_basic_map_intersect_range(copy(), bset.release());
  return manage(res);
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
Val BasicMap::plainGetValIfFixed(enum Dim type, unsigned int pos) const {
  auto res = isl_basic_map_plain_get_val_if_fixed(get(), static_cast<enum isl_dim_type>(type), pos);
  return manage(res);
}
BasicMap BasicMap::projectOut(enum Dim type, unsigned int first, unsigned int n) const {
  auto res = isl_basic_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}
BasicMap BasicMap::reverse() const {
  auto res = isl_basic_map_reverse(copy());
  return manage(res);
}
BasicMap BasicMap::sample() const {
  auto res = isl_basic_map_sample(copy());
  return manage(res);
}
Map BasicMap::unite(BasicMap bmap2) const {
  auto res = isl_basic_map_union(copy(), bmap2.release());
  return manage(res);
}
BasicMap BasicMap::universe(Space dim) {
  auto res = isl_basic_map_universe(dim.release());
  return manage(res);
}
// implementations for isl::BasicSet
BasicSet manage(__isl_take isl_basic_set *ptr) {
  return BasicSet(ptr);
}

BasicSet give(__isl_take isl_basic_set *ptr) {
  return manage(ptr);
}

BasicSet::BasicSet()
    : ptr(nullptr) {}

BasicSet::BasicSet(const BasicSet &obj)
    : ptr(obj.copy()) {}

BasicSet::BasicSet(std::nullptr_t)
    : ptr(nullptr) {}

BasicSet::BasicSet(__isl_take isl_basic_set *ptr)
    : ptr(ptr) {}

BasicSet::BasicSet(Ctx ctx, std::string str) {
  auto res = isl_basic_set_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
BasicSet::BasicSet(Point pnt) {
  auto res = isl_basic_set_from_point(pnt.release());
  ptr = res;
}
BasicSet &BasicSet::operator=(BasicSet obj) {
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

__isl_keep isl_basic_set *BasicSet::keep() const {
  return get();
}

__isl_give isl_basic_set *BasicSet::take() {
  return release();
}

BasicSet::operator bool() const {
  return !isNull();
}

isl_ctx *BasicSet::getCtx() const {
  return isl_basic_set_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const BasicSet &Obj) {
  OS << Obj.getStr();
  return OS;
}

BasicSet BasicSet::affineHull() const {
  auto res = isl_basic_set_affine_hull(copy());
  return manage(res);
}
BasicSet BasicSet::apply(BasicMap bmap) const {
  auto res = isl_basic_set_apply(copy(), bmap.release());
  return manage(res);
}
BasicSet BasicSet::detectEqualities() const {
  auto res = isl_basic_set_detect_equalities(copy());
  return manage(res);
}
BasicSet BasicSet::flatten() const {
  auto res = isl_basic_set_flatten(copy());
  return manage(res);
}
BasicSet BasicSet::gist(BasicSet context) const {
  auto res = isl_basic_set_gist(copy(), context.release());
  return manage(res);
}
BasicSet BasicSet::intersect(BasicSet bset2) const {
  auto res = isl_basic_set_intersect(copy(), bset2.release());
  return manage(res);
}
BasicSet BasicSet::intersectParams(BasicSet bset2) const {
  auto res = isl_basic_set_intersect_params(copy(), bset2.release());
  return manage(res);
}
Bool BasicSet::isBounded() const {
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
BasicSet BasicSet::projectOut(enum Dim type, unsigned int first, unsigned int n) const {
  auto res = isl_basic_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}
BasicSet BasicSet::sample() const {
  auto res = isl_basic_set_sample(copy());
  return manage(res);
}
Point BasicSet::samplePoint() const {
  auto res = isl_basic_set_sample_point(copy());
  return manage(res);
}
Set BasicSet::unite(BasicSet bset2) const {
  auto res = isl_basic_set_union(copy(), bset2.release());
  return manage(res);
}
// implementations for isl::Id
Id manage(__isl_take isl_id *ptr) {
  return Id(ptr);
}

Id give(__isl_take isl_id *ptr) {
  return manage(ptr);
}

Id::Id()
    : ptr(nullptr) {}

Id::Id(const Id &obj)
    : ptr(obj.copy()) {}

Id::Id(std::nullptr_t)
    : ptr(nullptr) {}

Id::Id(__isl_take isl_id *ptr)
    : ptr(ptr) {}

Id &Id::operator=(Id obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

Id::~Id() {
  if (ptr)
    isl_id_free(ptr);
}

__isl_give isl_id *Id::copy() const & {
  return isl_id_copy(ptr);
}

__isl_keep isl_id *Id::get() const {
  return ptr;
}

__isl_give isl_id *Id::release() {
  isl_id *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_id *Id::keep() const {
  return get();
}

__isl_give isl_id *Id::take() {
  return release();
}

Id::operator bool() const {
  return !isNull();
}

isl_ctx *Id::getCtx() const {
  return isl_id_get_ctx(ptr);
}

bool Id::isNull() const {
  return ptr == nullptr;
}

std::string Id::getStr() const {
  char *Tmp = isl_id_to_str(get());
  if (!Tmp)
    return "";
  std::string S(Tmp);
  free(Tmp);
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Id &Obj) {
  OS << Obj.getStr();
  return OS;
}

// implementations for isl::LocalSpace
LocalSpace manage(__isl_take isl_local_space *ptr) {
  return LocalSpace(ptr);
}

LocalSpace give(__isl_take isl_local_space *ptr) {
  return manage(ptr);
}

LocalSpace::LocalSpace()
    : ptr(nullptr) {}

LocalSpace::LocalSpace(const LocalSpace &obj)
    : ptr(obj.copy()) {}

LocalSpace::LocalSpace(std::nullptr_t)
    : ptr(nullptr) {}

LocalSpace::LocalSpace(__isl_take isl_local_space *ptr)
    : ptr(ptr) {}

LocalSpace::LocalSpace(Space dim) {
  auto res = isl_local_space_from_space(dim.release());
  ptr = res;
}
LocalSpace &LocalSpace::operator=(LocalSpace obj) {
  std::swap(this->ptr, obj.ptr);
  return *this;
}

LocalSpace::~LocalSpace() {
  if (ptr)
    isl_local_space_free(ptr);
}

__isl_give isl_local_space *LocalSpace::copy() const & {
  return isl_local_space_copy(ptr);
}

__isl_keep isl_local_space *LocalSpace::get() const {
  return ptr;
}

__isl_give isl_local_space *LocalSpace::release() {
  isl_local_space *tmp = ptr;
  ptr = nullptr;
  return tmp;
}

__isl_keep isl_local_space *LocalSpace::keep() const {
  return get();
}

__isl_give isl_local_space *LocalSpace::take() {
  return release();
}

LocalSpace::operator bool() const {
  return !isNull();
}

isl_ctx *LocalSpace::getCtx() const {
  return isl_local_space_get_ctx(ptr);
}

bool LocalSpace::isNull() const {
  return ptr == nullptr;
}

// implementations for isl::Map
Map manage(__isl_take isl_map *ptr) {
  return Map(ptr);
}

Map give(__isl_take isl_map *ptr) {
  return manage(ptr);
}

Map::Map()
    : ptr(nullptr) {}

Map::Map(const Map &obj)
    : ptr(obj.copy()) {}

Map::Map(std::nullptr_t)
    : ptr(nullptr) {}

Map::Map(__isl_take isl_map *ptr)
    : ptr(ptr) {}

Map::Map(Ctx ctx, std::string str) {
  auto res = isl_map_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
Map::Map(BasicMap bmap) {
  auto res = isl_map_from_basic_map(bmap.release());
  ptr = res;
}
Map &Map::operator=(Map obj) {
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

__isl_keep isl_map *Map::keep() const {
  return get();
}

__isl_give isl_map *Map::take() {
  return release();
}

Map::operator bool() const {
  return !isNull();
}

isl_ctx *Map::getCtx() const {
  return isl_map_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Map &Obj) {
  OS << Obj.getStr();
  return OS;
}

BasicMap Map::affineHull() const {
  auto res = isl_map_affine_hull(copy());
  return manage(res);
}
Map Map::applyDomain(Map map2) const {
  auto res = isl_map_apply_domain(copy(), map2.release());
  return manage(res);
}
Map Map::applyRange(Map map2) const {
  auto res = isl_map_apply_range(copy(), map2.release());
  return manage(res);
}
Map Map::coalesce() const {
  auto res = isl_map_coalesce(copy());
  return manage(res);
}
Map Map::complement() const {
  auto res = isl_map_complement(copy());
  return manage(res);
}
Set Map::deltas() const {
  auto res = isl_map_deltas(copy());
  return manage(res);
}
Map Map::detectEqualities() const {
  auto res = isl_map_detect_equalities(copy());
  return manage(res);
}
unsigned int Map::dim(enum Dim type) const {
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
Map Map::flatten() const {
  auto res = isl_map_flatten(copy());
  return manage(res);
}
Map Map::flattenDomain() const {
  auto res = isl_map_flatten_domain(copy());
  return manage(res);
}
Map Map::flattenRange() const {
  auto res = isl_map_flatten_range(copy());
  return manage(res);
}
Stat Map::foreachBasicMap(std::function<Stat(BasicMap)> &&fn) const {
  auto fn_lambda = [](isl_basic_map *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<Stat(BasicMap)> *)arg_1;
    Stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_map_foreach_basic_map(get(), fn_lambda, &fn);
  return Stat(res);
}
Map Map::fromRange(Set set) {
  auto res = isl_map_from_range(set.release());
  return manage(res);
}
Map Map::gist(Map context) const {
  auto res = isl_map_gist(copy(), context.release());
  return manage(res);
}
Map Map::gistDomain(Set context) const {
  auto res = isl_map_gist_domain(copy(), context.release());
  return manage(res);
}
Map Map::intersect(Map map2) const {
  auto res = isl_map_intersect(copy(), map2.release());
  return manage(res);
}
Map Map::intersectDomain(Set set) const {
  auto res = isl_map_intersect_domain(copy(), set.release());
  return manage(res);
}
Map Map::intersectParams(Set params) const {
  auto res = isl_map_intersect_params(copy(), params.release());
  return manage(res);
}
Map Map::intersectRange(Set set) const {
  auto res = isl_map_intersect_range(copy(), set.release());
  return manage(res);
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
Map Map::lexmax() const {
  auto res = isl_map_lexmax(copy());
  return manage(res);
}
Map Map::lexmin() const {
  auto res = isl_map_lexmin(copy());
  return manage(res);
}
BasicMap Map::polyhedralHull() const {
  auto res = isl_map_polyhedral_hull(copy());
  return manage(res);
}
Map Map::projectOut(enum Dim type, unsigned int first, unsigned int n) const {
  auto res = isl_map_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}
Map Map::reverse() const {
  auto res = isl_map_reverse(copy());
  return manage(res);
}
BasicMap Map::sample() const {
  auto res = isl_map_sample(copy());
  return manage(res);
}
Map Map::subtract(Map map2) const {
  auto res = isl_map_subtract(copy(), map2.release());
  return manage(res);
}
Map Map::unite(Map map2) const {
  auto res = isl_map_union(copy(), map2.release());
  return manage(res);
}
BasicMap Map::unshiftedSimpleHull() const {
  auto res = isl_map_unshifted_simple_hull(copy());
  return manage(res);
}
// implementations for isl::MultiAff
MultiAff manage(__isl_take isl_multi_aff *ptr) {
  return MultiAff(ptr);
}

MultiAff give(__isl_take isl_multi_aff *ptr) {
  return manage(ptr);
}

MultiAff::MultiAff()
    : ptr(nullptr) {}

MultiAff::MultiAff(const MultiAff &obj)
    : ptr(obj.copy()) {}

MultiAff::MultiAff(std::nullptr_t)
    : ptr(nullptr) {}

MultiAff::MultiAff(__isl_take isl_multi_aff *ptr)
    : ptr(ptr) {}

MultiAff::MultiAff(Aff aff) {
  auto res = isl_multi_aff_from_aff(aff.release());
  ptr = res;
}
MultiAff::MultiAff(Ctx ctx, std::string str) {
  auto res = isl_multi_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
MultiAff &MultiAff::operator=(MultiAff obj) {
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

__isl_keep isl_multi_aff *MultiAff::keep() const {
  return get();
}

__isl_give isl_multi_aff *MultiAff::take() {
  return release();
}

MultiAff::operator bool() const {
  return !isNull();
}

isl_ctx *MultiAff::getCtx() const {
  return isl_multi_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const MultiAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

MultiAff MultiAff::add(MultiAff multi2) const {
  auto res = isl_multi_aff_add(copy(), multi2.release());
  return manage(res);
}
MultiAff MultiAff::flatRangeProduct(MultiAff multi2) const {
  auto res = isl_multi_aff_flat_range_product(copy(), multi2.release());
  return manage(res);
}
Aff MultiAff::getAff(int pos) const {
  auto res = isl_multi_aff_get_aff(get(), pos);
  return manage(res);
}
MultiAff MultiAff::product(MultiAff multi2) const {
  auto res = isl_multi_aff_product(copy(), multi2.release());
  return manage(res);
}
MultiAff MultiAff::pullback(MultiAff ma2) const {
  auto res = isl_multi_aff_pullback_multi_aff(copy(), ma2.release());
  return manage(res);
}
MultiAff MultiAff::rangeProduct(MultiAff multi2) const {
  auto res = isl_multi_aff_range_product(copy(), multi2.release());
  return manage(res);
}
// implementations for isl::MultiPwAff
MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr) {
  return MultiPwAff(ptr);
}

MultiPwAff give(__isl_take isl_multi_pw_aff *ptr) {
  return manage(ptr);
}

MultiPwAff::MultiPwAff()
    : ptr(nullptr) {}

MultiPwAff::MultiPwAff(const MultiPwAff &obj)
    : ptr(obj.copy()) {}

MultiPwAff::MultiPwAff(std::nullptr_t)
    : ptr(nullptr) {}

MultiPwAff::MultiPwAff(__isl_take isl_multi_pw_aff *ptr)
    : ptr(ptr) {}

MultiPwAff::MultiPwAff(MultiAff ma) {
  auto res = isl_multi_pw_aff_from_multi_aff(ma.release());
  ptr = res;
}
MultiPwAff::MultiPwAff(PwAff pa) {
  auto res = isl_multi_pw_aff_from_pw_aff(pa.release());
  ptr = res;
}
MultiPwAff::MultiPwAff(PwMultiAff pma) {
  auto res = isl_multi_pw_aff_from_pw_multi_aff(pma.release());
  ptr = res;
}
MultiPwAff::MultiPwAff(Ctx ctx, std::string str) {
  auto res = isl_multi_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
MultiPwAff &MultiPwAff::operator=(MultiPwAff obj) {
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

__isl_keep isl_multi_pw_aff *MultiPwAff::keep() const {
  return get();
}

__isl_give isl_multi_pw_aff *MultiPwAff::take() {
  return release();
}

MultiPwAff::operator bool() const {
  return !isNull();
}

isl_ctx *MultiPwAff::getCtx() const {
  return isl_multi_pw_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const MultiPwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

MultiPwAff MultiPwAff::add(MultiPwAff multi2) const {
  auto res = isl_multi_pw_aff_add(copy(), multi2.release());
  return manage(res);
}
MultiPwAff MultiPwAff::flatRangeProduct(MultiPwAff multi2) const {
  auto res = isl_multi_pw_aff_flat_range_product(copy(), multi2.release());
  return manage(res);
}
PwAff MultiPwAff::getPwAff(int pos) const {
  auto res = isl_multi_pw_aff_get_pw_aff(get(), pos);
  return manage(res);
}
MultiPwAff MultiPwAff::product(MultiPwAff multi2) const {
  auto res = isl_multi_pw_aff_product(copy(), multi2.release());
  return manage(res);
}
MultiPwAff MultiPwAff::pullback(MultiAff ma) const {
  auto res = isl_multi_pw_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}
MultiPwAff MultiPwAff::pullback(PwMultiAff pma) const {
  auto res = isl_multi_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
  return manage(res);
}
MultiPwAff MultiPwAff::pullback(MultiPwAff mpa2) const {
  auto res = isl_multi_pw_aff_pullback_multi_pw_aff(copy(), mpa2.release());
  return manage(res);
}
MultiPwAff MultiPwAff::rangeProduct(MultiPwAff multi2) const {
  auto res = isl_multi_pw_aff_range_product(copy(), multi2.release());
  return manage(res);
}
// implementations for isl::MultiUnionPwAff
MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr) {
  return MultiUnionPwAff(ptr);
}

MultiUnionPwAff give(__isl_take isl_multi_union_pw_aff *ptr) {
  return manage(ptr);
}

MultiUnionPwAff::MultiUnionPwAff()
    : ptr(nullptr) {}

MultiUnionPwAff::MultiUnionPwAff(const MultiUnionPwAff &obj)
    : ptr(obj.copy()) {}

MultiUnionPwAff::MultiUnionPwAff(std::nullptr_t)
    : ptr(nullptr) {}

MultiUnionPwAff::MultiUnionPwAff(__isl_take isl_multi_union_pw_aff *ptr)
    : ptr(ptr) {}

MultiUnionPwAff::MultiUnionPwAff(UnionPwAff upa) {
  auto res = isl_multi_union_pw_aff_from_union_pw_aff(upa.release());
  ptr = res;
}
MultiUnionPwAff::MultiUnionPwAff(MultiPwAff mpa) {
  auto res = isl_multi_union_pw_aff_from_multi_pw_aff(mpa.release());
  ptr = res;
}
MultiUnionPwAff::MultiUnionPwAff(UnionPwMultiAff upma) {
  auto res = isl_multi_union_pw_aff_from_union_pw_multi_aff(upma.release());
  ptr = res;
}
MultiUnionPwAff::MultiUnionPwAff(Ctx ctx, std::string str) {
  auto res = isl_multi_union_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
MultiUnionPwAff &MultiUnionPwAff::operator=(MultiUnionPwAff obj) {
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

__isl_keep isl_multi_union_pw_aff *MultiUnionPwAff::keep() const {
  return get();
}

__isl_give isl_multi_union_pw_aff *MultiUnionPwAff::take() {
  return release();
}

MultiUnionPwAff::operator bool() const {
  return !isNull();
}

isl_ctx *MultiUnionPwAff::getCtx() const {
  return isl_multi_union_pw_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const MultiUnionPwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

MultiUnionPwAff MultiUnionPwAff::add(MultiUnionPwAff multi2) const {
  auto res = isl_multi_union_pw_aff_add(copy(), multi2.release());
  return manage(res);
}
MultiUnionPwAff MultiUnionPwAff::flatRangeProduct(MultiUnionPwAff multi2) const {
  auto res = isl_multi_union_pw_aff_flat_range_product(copy(), multi2.release());
  return manage(res);
}
UnionPwAff MultiUnionPwAff::getUnionPwAff(int pos) const {
  auto res = isl_multi_union_pw_aff_get_union_pw_aff(get(), pos);
  return manage(res);
}
MultiUnionPwAff MultiUnionPwAff::pullback(UnionPwMultiAff upma) const {
  auto res = isl_multi_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
  return manage(res);
}
MultiUnionPwAff MultiUnionPwAff::rangeProduct(MultiUnionPwAff multi2) const {
  auto res = isl_multi_union_pw_aff_range_product(copy(), multi2.release());
  return manage(res);
}
MultiUnionPwAff MultiUnionPwAff::unionAdd(MultiUnionPwAff mupa2) const {
  auto res = isl_multi_union_pw_aff_union_add(copy(), mupa2.release());
  return manage(res);
}
// implementations for isl::MultiVal
MultiVal manage(__isl_take isl_multi_val *ptr) {
  return MultiVal(ptr);
}

MultiVal give(__isl_take isl_multi_val *ptr) {
  return manage(ptr);
}

MultiVal::MultiVal()
    : ptr(nullptr) {}

MultiVal::MultiVal(const MultiVal &obj)
    : ptr(obj.copy()) {}

MultiVal::MultiVal(std::nullptr_t)
    : ptr(nullptr) {}

MultiVal::MultiVal(__isl_take isl_multi_val *ptr)
    : ptr(ptr) {}

MultiVal &MultiVal::operator=(MultiVal obj) {
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

__isl_keep isl_multi_val *MultiVal::keep() const {
  return get();
}

__isl_give isl_multi_val *MultiVal::take() {
  return release();
}

MultiVal::operator bool() const {
  return !isNull();
}

isl_ctx *MultiVal::getCtx() const {
  return isl_multi_val_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const MultiVal &Obj) {
  OS << Obj.getStr();
  return OS;
}

MultiVal MultiVal::add(MultiVal multi2) const {
  auto res = isl_multi_val_add(copy(), multi2.release());
  return manage(res);
}
MultiVal MultiVal::flatRangeProduct(MultiVal multi2) const {
  auto res = isl_multi_val_flat_range_product(copy(), multi2.release());
  return manage(res);
}
Val MultiVal::getVal(int pos) const {
  auto res = isl_multi_val_get_val(get(), pos);
  return manage(res);
}
MultiVal MultiVal::product(MultiVal multi2) const {
  auto res = isl_multi_val_product(copy(), multi2.release());
  return manage(res);
}
MultiVal MultiVal::rangeProduct(MultiVal multi2) const {
  auto res = isl_multi_val_range_product(copy(), multi2.release());
  return manage(res);
}
// implementations for isl::Point
Point manage(__isl_take isl_point *ptr) {
  return Point(ptr);
}

Point give(__isl_take isl_point *ptr) {
  return manage(ptr);
}

Point::Point()
    : ptr(nullptr) {}

Point::Point(const Point &obj)
    : ptr(obj.copy()) {}

Point::Point(std::nullptr_t)
    : ptr(nullptr) {}

Point::Point(__isl_take isl_point *ptr)
    : ptr(ptr) {}

Point::Point(Space dim) {
  auto res = isl_point_zero(dim.release());
  ptr = res;
}
Point &Point::operator=(Point obj) {
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

__isl_keep isl_point *Point::keep() const {
  return get();
}

__isl_give isl_point *Point::take() {
  return release();
}

Point::operator bool() const {
  return !isNull();
}

isl_ctx *Point::getCtx() const {
  return isl_point_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Point &Obj) {
  OS << Obj.getStr();
  return OS;
}

// implementations for isl::PwAff
PwAff manage(__isl_take isl_pw_aff *ptr) {
  return PwAff(ptr);
}

PwAff give(__isl_take isl_pw_aff *ptr) {
  return manage(ptr);
}

PwAff::PwAff()
    : ptr(nullptr) {}

PwAff::PwAff(const PwAff &obj)
    : ptr(obj.copy()) {}

PwAff::PwAff(std::nullptr_t)
    : ptr(nullptr) {}

PwAff::PwAff(__isl_take isl_pw_aff *ptr)
    : ptr(ptr) {}

PwAff::PwAff(Aff aff) {
  auto res = isl_pw_aff_from_aff(aff.release());
  ptr = res;
}
PwAff::PwAff(LocalSpace ls) {
  auto res = isl_pw_aff_zero_on_domain(ls.release());
  ptr = res;
}
PwAff::PwAff(Set domain, Val v) {
  auto res = isl_pw_aff_val_on_domain(domain.release(), v.release());
  ptr = res;
}
PwAff::PwAff(Ctx ctx, std::string str) {
  auto res = isl_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
PwAff &PwAff::operator=(PwAff obj) {
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

__isl_keep isl_pw_aff *PwAff::keep() const {
  return get();
}

__isl_give isl_pw_aff *PwAff::take() {
  return release();
}

PwAff::operator bool() const {
  return !isNull();
}

isl_ctx *PwAff::getCtx() const {
  return isl_pw_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const PwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

PwAff PwAff::add(PwAff pwaff2) const {
  auto res = isl_pw_aff_add(copy(), pwaff2.release());
  return manage(res);
}
Stat PwAff::foreachPiece(std::function<Stat(Set, Aff)> &&fn) const {
  auto fn_lambda = [](isl_set *arg_0, isl_aff *arg_1, void *arg_2) -> isl_stat {
    auto *func = (std::function<Stat(Set, Aff)> *)arg_2;
    Stat ret = (*func)(isl::manage(arg_0), isl::manage(arg_1));
    return isl_stat(ret);
  };
  auto res = isl_pw_aff_foreach_piece(get(), fn_lambda, &fn);
  return Stat(res);
}
Space PwAff::getSpace() const {
  auto res = isl_pw_aff_get_space(get());
  return manage(res);
}
Bool PwAff::isCst() const {
  auto res = isl_pw_aff_is_cst(get());
  return res;
}
PwAff PwAff::mul(PwAff pwaff2) const {
  auto res = isl_pw_aff_mul(copy(), pwaff2.release());
  return manage(res);
}
PwAff PwAff::neg() const {
  auto res = isl_pw_aff_neg(copy());
  return manage(res);
}
PwAff PwAff::pullback(MultiAff ma) const {
  auto res = isl_pw_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}
PwAff PwAff::pullback(PwMultiAff pma) const {
  auto res = isl_pw_aff_pullback_pw_multi_aff(copy(), pma.release());
  return manage(res);
}
PwAff PwAff::pullback(MultiPwAff mpa) const {
  auto res = isl_pw_aff_pullback_multi_pw_aff(copy(), mpa.release());
  return manage(res);
}
PwAff PwAff::sub(PwAff pwaff2) const {
  auto res = isl_pw_aff_sub(copy(), pwaff2.release());
  return manage(res);
}
PwAff PwAff::unionAdd(PwAff pwaff2) const {
  auto res = isl_pw_aff_union_add(copy(), pwaff2.release());
  return manage(res);
}
// implementations for isl::PwMultiAff
PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr) {
  return PwMultiAff(ptr);
}

PwMultiAff give(__isl_take isl_pw_multi_aff *ptr) {
  return manage(ptr);
}

PwMultiAff::PwMultiAff()
    : ptr(nullptr) {}

PwMultiAff::PwMultiAff(const PwMultiAff &obj)
    : ptr(obj.copy()) {}

PwMultiAff::PwMultiAff(std::nullptr_t)
    : ptr(nullptr) {}

PwMultiAff::PwMultiAff(__isl_take isl_pw_multi_aff *ptr)
    : ptr(ptr) {}

PwMultiAff::PwMultiAff(Ctx ctx, std::string str) {
  auto res = isl_pw_multi_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
PwMultiAff::PwMultiAff(MultiAff ma) {
  auto res = isl_pw_multi_aff_from_multi_aff(ma.release());
  ptr = res;
}
PwMultiAff::PwMultiAff(PwAff pa) {
  auto res = isl_pw_multi_aff_from_pw_aff(pa.release());
  ptr = res;
}
PwMultiAff &PwMultiAff::operator=(PwMultiAff obj) {
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

__isl_keep isl_pw_multi_aff *PwMultiAff::keep() const {
  return get();
}

__isl_give isl_pw_multi_aff *PwMultiAff::take() {
  return release();
}

PwMultiAff::operator bool() const {
  return !isNull();
}

isl_ctx *PwMultiAff::getCtx() const {
  return isl_pw_multi_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const PwMultiAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

PwMultiAff PwMultiAff::add(PwMultiAff pma2) const {
  auto res = isl_pw_multi_aff_add(copy(), pma2.release());
  return manage(res);
}
PwMultiAff PwMultiAff::flatRangeProduct(PwMultiAff pma2) const {
  auto res = isl_pw_multi_aff_flat_range_product(copy(), pma2.release());
  return manage(res);
}
PwMultiAff PwMultiAff::product(PwMultiAff pma2) const {
  auto res = isl_pw_multi_aff_product(copy(), pma2.release());
  return manage(res);
}
PwMultiAff PwMultiAff::pullback(MultiAff ma) const {
  auto res = isl_pw_multi_aff_pullback_multi_aff(copy(), ma.release());
  return manage(res);
}
PwMultiAff PwMultiAff::pullback(PwMultiAff pma2) const {
  auto res = isl_pw_multi_aff_pullback_pw_multi_aff(copy(), pma2.release());
  return manage(res);
}
PwMultiAff PwMultiAff::rangeProduct(PwMultiAff pma2) const {
  auto res = isl_pw_multi_aff_range_product(copy(), pma2.release());
  return manage(res);
}
PwMultiAff PwMultiAff::unionAdd(PwMultiAff pma2) const {
  auto res = isl_pw_multi_aff_union_add(copy(), pma2.release());
  return manage(res);
}
// implementations for isl::Schedule
Schedule manage(__isl_take isl_schedule *ptr) {
  return Schedule(ptr);
}

Schedule give(__isl_take isl_schedule *ptr) {
  return manage(ptr);
}

Schedule::Schedule()
    : ptr(nullptr) {}

Schedule::Schedule(const Schedule &obj)
    : ptr(obj.copy()) {}

Schedule::Schedule(std::nullptr_t)
    : ptr(nullptr) {}

Schedule::Schedule(__isl_take isl_schedule *ptr)
    : ptr(ptr) {}

Schedule::Schedule(Ctx ctx, std::string str) {
  auto res = isl_schedule_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
Schedule &Schedule::operator=(Schedule obj) {
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

__isl_keep isl_schedule *Schedule::keep() const {
  return get();
}

__isl_give isl_schedule *Schedule::take() {
  return release();
}

Schedule::operator bool() const {
  return !isNull();
}

isl_ctx *Schedule::getCtx() const {
  return isl_schedule_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Schedule &Obj) {
  OS << Obj.getStr();
  return OS;
}

UnionMap Schedule::getMap() const {
  auto res = isl_schedule_get_map(get());
  return manage(res);
}
ScheduleNode Schedule::getRoot() const {
  auto res = isl_schedule_get_root(get());
  return manage(res);
}
Schedule Schedule::pullback(UnionPwMultiAff upma) const {
  auto res = isl_schedule_pullback_union_pw_multi_aff(copy(), upma.release());
  return manage(res);
}
// implementations for isl::ScheduleConstraints
ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr) {
  return ScheduleConstraints(ptr);
}

ScheduleConstraints give(__isl_take isl_schedule_constraints *ptr) {
  return manage(ptr);
}

ScheduleConstraints::ScheduleConstraints()
    : ptr(nullptr) {}

ScheduleConstraints::ScheduleConstraints(const ScheduleConstraints &obj)
    : ptr(obj.copy()) {}

ScheduleConstraints::ScheduleConstraints(std::nullptr_t)
    : ptr(nullptr) {}

ScheduleConstraints::ScheduleConstraints(__isl_take isl_schedule_constraints *ptr)
    : ptr(ptr) {}

ScheduleConstraints::ScheduleConstraints(Ctx ctx, std::string str) {
  auto res = isl_schedule_constraints_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
ScheduleConstraints &ScheduleConstraints::operator=(ScheduleConstraints obj) {
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

__isl_keep isl_schedule_constraints *ScheduleConstraints::keep() const {
  return get();
}

__isl_give isl_schedule_constraints *ScheduleConstraints::take() {
  return release();
}

ScheduleConstraints::operator bool() const {
  return !isNull();
}

isl_ctx *ScheduleConstraints::getCtx() const {
  return isl_schedule_constraints_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const ScheduleConstraints &Obj) {
  OS << Obj.getStr();
  return OS;
}

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

ScheduleNode give(__isl_take isl_schedule_node *ptr) {
  return manage(ptr);
}

ScheduleNode::ScheduleNode()
    : ptr(nullptr) {}

ScheduleNode::ScheduleNode(const ScheduleNode &obj)
    : ptr(obj.copy()) {}

ScheduleNode::ScheduleNode(std::nullptr_t)
    : ptr(nullptr) {}

ScheduleNode::ScheduleNode(__isl_take isl_schedule_node *ptr)
    : ptr(ptr) {}

ScheduleNode &ScheduleNode::operator=(ScheduleNode obj) {
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

__isl_keep isl_schedule_node *ScheduleNode::keep() const {
  return get();
}

__isl_give isl_schedule_node *ScheduleNode::take() {
  return release();
}

ScheduleNode::operator bool() const {
  return !isNull();
}

isl_ctx *ScheduleNode::getCtx() const {
  return isl_schedule_node_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const ScheduleNode &Obj) {
  OS << Obj.getStr();
  return OS;
}

Bool ScheduleNode::bandMemberGetCoincident(int pos) const {
  auto res = isl_schedule_node_band_member_get_coincident(get(), pos);
  return res;
}
ScheduleNode ScheduleNode::bandMemberSetCoincident(int pos, int coincident) const {
  auto res = isl_schedule_node_band_member_set_coincident(copy(), pos, coincident);
  return manage(res);
}
ScheduleNode ScheduleNode::child(int pos) const {
  auto res = isl_schedule_node_child(copy(), pos);
  return manage(res);
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
ScheduleNode ScheduleNode::parent() const {
  auto res = isl_schedule_node_parent(copy());
  return manage(res);
}
// implementations for isl::Set
Set manage(__isl_take isl_set *ptr) {
  return Set(ptr);
}

Set give(__isl_take isl_set *ptr) {
  return manage(ptr);
}

Set::Set()
    : ptr(nullptr) {}

Set::Set(const Set &obj)
    : ptr(obj.copy()) {}

Set::Set(std::nullptr_t)
    : ptr(nullptr) {}

Set::Set(__isl_take isl_set *ptr)
    : ptr(ptr) {}

Set::Set(Ctx ctx, std::string str) {
  auto res = isl_set_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
Set::Set(BasicSet bset) {
  auto res = isl_set_from_basic_set(bset.release());
  ptr = res;
}
Set::Set(Point pnt) {
  auto res = isl_set_from_point(pnt.release());
  ptr = res;
}
Set::Set(UnionSet uset) {
  auto res = isl_set_from_union_set(uset.release());
  ptr = res;
}
Set &Set::operator=(Set obj) {
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

__isl_keep isl_set *Set::keep() const {
  return get();
}

__isl_give isl_set *Set::take() {
  return release();
}

Set::operator bool() const {
  return !isNull();
}

isl_ctx *Set::getCtx() const {
  return isl_set_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Set &Obj) {
  OS << Obj.getStr();
  return OS;
}

Set Set::addDims(enum Dim type, unsigned int n) const {
  auto res = isl_set_add_dims(copy(), static_cast<enum isl_dim_type>(type), n);
  return manage(res);
}
BasicSet Set::affineHull() const {
  auto res = isl_set_affine_hull(copy());
  return manage(res);
}
Set Set::apply(Map map) const {
  auto res = isl_set_apply(copy(), map.release());
  return manage(res);
}
Set Set::coalesce() const {
  auto res = isl_set_coalesce(copy());
  return manage(res);
}
Set Set::complement() const {
  auto res = isl_set_complement(copy());
  return manage(res);
}
Set Set::detectEqualities() const {
  auto res = isl_set_detect_equalities(copy());
  return manage(res);
}
unsigned int Set::dim(enum Dim type) const {
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
Set Set::flatten() const {
  auto res = isl_set_flatten(copy());
  return manage(res);
}
Stat Set::foreachBasicSet(std::function<Stat(BasicSet)> &&fn) const {
  auto fn_lambda = [](isl_basic_set *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<Stat(BasicSet)> *)arg_1;
    Stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_set_foreach_basic_set(get(), fn_lambda, &fn);
  return Stat(res);
}
Set Set::gist(Set context) const {
  auto res = isl_set_gist(copy(), context.release());
  return manage(res);
}
Map Set::identity() const {
  auto res = isl_set_identity(copy());
  return manage(res);
}
Set Set::intersect(Set set2) const {
  auto res = isl_set_intersect(copy(), set2.release());
  return manage(res);
}
Set Set::intersectParams(Set params) const {
  auto res = isl_set_intersect_params(copy(), params.release());
  return manage(res);
}
Bool Set::isBounded() const {
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
Set Set::lexmax() const {
  auto res = isl_set_lexmax(copy());
  return manage(res);
}
Set Set::lexmin() const {
  auto res = isl_set_lexmin(copy());
  return manage(res);
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
Set Set::projectOut(enum Dim type, unsigned int first, unsigned int n) const {
  auto res = isl_set_project_out(copy(), static_cast<enum isl_dim_type>(type), first, n);
  return manage(res);
}
BasicSet Set::sample() const {
  auto res = isl_set_sample(copy());
  return manage(res);
}
Point Set::samplePoint() const {
  auto res = isl_set_sample_point(copy());
  return manage(res);
}
Set Set::subtract(Set set2) const {
  auto res = isl_set_subtract(copy(), set2.release());
  return manage(res);
}
Set Set::unite(Set set2) const {
  auto res = isl_set_union(copy(), set2.release());
  return manage(res);
}
Set Set::universe(Space dim) {
  auto res = isl_set_universe(dim.release());
  return manage(res);
}
BasicSet Set::unshiftedSimpleHull() const {
  auto res = isl_set_unshifted_simple_hull(copy());
  return manage(res);
}
// implementations for isl::Space
Space manage(__isl_take isl_space *ptr) {
  return Space(ptr);
}

Space give(__isl_take isl_space *ptr) {
  return manage(ptr);
}

Space::Space()
    : ptr(nullptr) {}

Space::Space(const Space &obj)
    : ptr(obj.copy()) {}

Space::Space(std::nullptr_t)
    : ptr(nullptr) {}

Space::Space(__isl_take isl_space *ptr)
    : ptr(ptr) {}

Space::Space(Ctx ctx, unsigned int nparam, unsigned int n_in, unsigned int n_out) {
  auto res = isl_space_alloc(ctx.release(), nparam, n_in, n_out);
  ptr = res;
}
Space::Space(Ctx ctx, unsigned int nparam, unsigned int dim) {
  auto res = isl_space_set_alloc(ctx.release(), nparam, dim);
  ptr = res;
}
Space &Space::operator=(Space obj) {
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

__isl_keep isl_space *Space::keep() const {
  return get();
}

__isl_give isl_space *Space::take() {
  return release();
}

Space::operator bool() const {
  return !isNull();
}

isl_ctx *Space::getCtx() const {
  return isl_space_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Space &Obj) {
  OS << Obj.getStr();
  return OS;
}

Space Space::domain() const {
  auto res = isl_space_domain(copy());
  return manage(res);
}
Bool Space::isEqual(const Space &space2) const {
  auto res = isl_space_is_equal(get(), space2.get());
  return res;
}
Space Space::params() const {
  auto res = isl_space_params(copy());
  return manage(res);
}
Space Space::setFromParams() const {
  auto res = isl_space_set_from_params(copy());
  return manage(res);
}
// implementations for isl::UnionAccessInfo
UnionAccessInfo manage(__isl_take isl_union_access_info *ptr) {
  return UnionAccessInfo(ptr);
}

UnionAccessInfo give(__isl_take isl_union_access_info *ptr) {
  return manage(ptr);
}

UnionAccessInfo::UnionAccessInfo()
    : ptr(nullptr) {}

UnionAccessInfo::UnionAccessInfo(const UnionAccessInfo &obj)
    : ptr(obj.copy()) {}

UnionAccessInfo::UnionAccessInfo(std::nullptr_t)
    : ptr(nullptr) {}

UnionAccessInfo::UnionAccessInfo(__isl_take isl_union_access_info *ptr)
    : ptr(ptr) {}

UnionAccessInfo::UnionAccessInfo(UnionMap sink) {
  auto res = isl_union_access_info_from_sink(sink.release());
  ptr = res;
}
UnionAccessInfo &UnionAccessInfo::operator=(UnionAccessInfo obj) {
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

__isl_keep isl_union_access_info *UnionAccessInfo::keep() const {
  return get();
}

__isl_give isl_union_access_info *UnionAccessInfo::take() {
  return release();
}

UnionAccessInfo::operator bool() const {
  return !isNull();
}

isl_ctx *UnionAccessInfo::getCtx() const {
  return isl_union_access_info_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const UnionAccessInfo &Obj) {
  OS << Obj.getStr();
  return OS;
}

UnionFlow UnionAccessInfo::computeFlow() const {
  auto res = isl_union_access_info_compute_flow(copy());
  return manage(res);
}
UnionAccessInfo UnionAccessInfo::setMaySource(UnionMap may_source) const {
  auto res = isl_union_access_info_set_may_source(copy(), may_source.release());
  return manage(res);
}
UnionAccessInfo UnionAccessInfo::setMustSource(UnionMap must_source) const {
  auto res = isl_union_access_info_set_must_source(copy(), must_source.release());
  return manage(res);
}
UnionAccessInfo UnionAccessInfo::setSchedule(Schedule schedule) const {
  auto res = isl_union_access_info_set_schedule(copy(), schedule.release());
  return manage(res);
}
UnionAccessInfo UnionAccessInfo::setScheduleMap(UnionMap schedule_map) const {
  auto res = isl_union_access_info_set_schedule_map(copy(), schedule_map.release());
  return manage(res);
}
// implementations for isl::UnionFlow
UnionFlow manage(__isl_take isl_union_flow *ptr) {
  return UnionFlow(ptr);
}

UnionFlow give(__isl_take isl_union_flow *ptr) {
  return manage(ptr);
}

UnionFlow::UnionFlow()
    : ptr(nullptr) {}

UnionFlow::UnionFlow(const UnionFlow &obj)
    : ptr(obj.copy()) {}

UnionFlow::UnionFlow(std::nullptr_t)
    : ptr(nullptr) {}

UnionFlow::UnionFlow(__isl_take isl_union_flow *ptr)
    : ptr(ptr) {}

UnionFlow &UnionFlow::operator=(UnionFlow obj) {
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

__isl_keep isl_union_flow *UnionFlow::keep() const {
  return get();
}

__isl_give isl_union_flow *UnionFlow::take() {
  return release();
}

UnionFlow::operator bool() const {
  return !isNull();
}

isl_ctx *UnionFlow::getCtx() const {
  return isl_union_flow_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const UnionFlow &Obj) {
  OS << Obj.getStr();
  return OS;
}

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

UnionMap give(__isl_take isl_union_map *ptr) {
  return manage(ptr);
}

UnionMap::UnionMap()
    : ptr(nullptr) {}

UnionMap::UnionMap(const UnionMap &obj)
    : ptr(obj.copy()) {}

UnionMap::UnionMap(std::nullptr_t)
    : ptr(nullptr) {}

UnionMap::UnionMap(__isl_take isl_union_map *ptr)
    : ptr(ptr) {}

UnionMap::UnionMap(Ctx ctx, std::string str) {
  auto res = isl_union_map_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
UnionMap::UnionMap(UnionPwAff upa) {
  auto res = isl_union_map_from_union_pw_aff(upa.release());
  ptr = res;
}
UnionMap::UnionMap(BasicMap bmap) {
  auto res = isl_union_map_from_basic_map(bmap.release());
  ptr = res;
}
UnionMap::UnionMap(Map map) {
  auto res = isl_union_map_from_map(map.release());
  ptr = res;
}
UnionMap &UnionMap::operator=(UnionMap obj) {
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

__isl_keep isl_union_map *UnionMap::keep() const {
  return get();
}

__isl_give isl_union_map *UnionMap::take() {
  return release();
}

UnionMap::operator bool() const {
  return !isNull();
}

isl_ctx *UnionMap::getCtx() const {
  return isl_union_map_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const UnionMap &Obj) {
  OS << Obj.getStr();
  return OS;
}

UnionMap UnionMap::addMap(Map map) const {
  auto res = isl_union_map_add_map(copy(), map.release());
  return manage(res);
}
UnionMap UnionMap::affineHull() const {
  auto res = isl_union_map_affine_hull(copy());
  return manage(res);
}
UnionMap UnionMap::applyDomain(UnionMap umap2) const {
  auto res = isl_union_map_apply_domain(copy(), umap2.release());
  return manage(res);
}
UnionMap UnionMap::applyRange(UnionMap umap2) const {
  auto res = isl_union_map_apply_range(copy(), umap2.release());
  return manage(res);
}
UnionMap UnionMap::coalesce() const {
  auto res = isl_union_map_coalesce(copy());
  return manage(res);
}
UnionMap UnionMap::computeDivs() const {
  auto res = isl_union_map_compute_divs(copy());
  return manage(res);
}
UnionSet UnionMap::deltas() const {
  auto res = isl_union_map_deltas(copy());
  return manage(res);
}
UnionMap UnionMap::detectEqualities() const {
  auto res = isl_union_map_detect_equalities(copy());
  return manage(res);
}
UnionSet UnionMap::domain() const {
  auto res = isl_union_map_domain(copy());
  return manage(res);
}
UnionMap UnionMap::domainFactorDomain() const {
  auto res = isl_union_map_domain_factor_domain(copy());
  return manage(res);
}
UnionMap UnionMap::domainFactorRange() const {
  auto res = isl_union_map_domain_factor_range(copy());
  return manage(res);
}
UnionMap UnionMap::domainMap() const {
  auto res = isl_union_map_domain_map(copy());
  return manage(res);
}
UnionPwMultiAff UnionMap::domainMapUnionPwMultiAff() const {
  auto res = isl_union_map_domain_map_union_pw_multi_aff(copy());
  return manage(res);
}
UnionMap UnionMap::domainProduct(UnionMap umap2) const {
  auto res = isl_union_map_domain_product(copy(), umap2.release());
  return manage(res);
}
UnionMap UnionMap::empty(Space dim) {
  auto res = isl_union_map_empty(dim.release());
  return manage(res);
}
UnionMap UnionMap::factorDomain() const {
  auto res = isl_union_map_factor_domain(copy());
  return manage(res);
}
UnionMap UnionMap::factorRange() const {
  auto res = isl_union_map_factor_range(copy());
  return manage(res);
}
UnionMap UnionMap::fixedPower(Val exp) const {
  auto res = isl_union_map_fixed_power_val(copy(), exp.release());
  return manage(res);
}
UnionMap UnionMap::flatRangeProduct(UnionMap umap2) const {
  auto res = isl_union_map_flat_range_product(copy(), umap2.release());
  return manage(res);
}
Stat UnionMap::foreachMap(std::function<Stat(Map)> &&fn) const {
  auto fn_lambda = [](isl_map *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<Stat(Map)> *)arg_1;
    Stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_map_foreach_map(get(), fn_lambda, &fn);
  return Stat(res);
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
Space UnionMap::getSpace() const {
  auto res = isl_union_map_get_space(get());
  return manage(res);
}
UnionMap UnionMap::gist(UnionMap context) const {
  auto res = isl_union_map_gist(copy(), context.release());
  return manage(res);
}
UnionMap UnionMap::gistDomain(UnionSet uset) const {
  auto res = isl_union_map_gist_domain(copy(), uset.release());
  return manage(res);
}
UnionMap UnionMap::gistParams(Set set) const {
  auto res = isl_union_map_gist_params(copy(), set.release());
  return manage(res);
}
UnionMap UnionMap::gistRange(UnionSet uset) const {
  auto res = isl_union_map_gist_range(copy(), uset.release());
  return manage(res);
}
UnionMap UnionMap::intersect(UnionMap umap2) const {
  auto res = isl_union_map_intersect(copy(), umap2.release());
  return manage(res);
}
UnionMap UnionMap::intersectDomain(UnionSet uset) const {
  auto res = isl_union_map_intersect_domain(copy(), uset.release());
  return manage(res);
}
UnionMap UnionMap::intersectParams(Set set) const {
  auto res = isl_union_map_intersect_params(copy(), set.release());
  return manage(res);
}
UnionMap UnionMap::intersectRange(UnionSet uset) const {
  auto res = isl_union_map_intersect_range(copy(), uset.release());
  return manage(res);
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
UnionMap UnionMap::lexmax() const {
  auto res = isl_union_map_lexmax(copy());
  return manage(res);
}
UnionMap UnionMap::lexmin() const {
  auto res = isl_union_map_lexmin(copy());
  return manage(res);
}
UnionMap UnionMap::polyhedralHull() const {
  auto res = isl_union_map_polyhedral_hull(copy());
  return manage(res);
}
UnionMap UnionMap::product(UnionMap umap2) const {
  auto res = isl_union_map_product(copy(), umap2.release());
  return manage(res);
}
UnionSet UnionMap::range() const {
  auto res = isl_union_map_range(copy());
  return manage(res);
}
UnionMap UnionMap::rangeFactorDomain() const {
  auto res = isl_union_map_range_factor_domain(copy());
  return manage(res);
}
UnionMap UnionMap::rangeFactorRange() const {
  auto res = isl_union_map_range_factor_range(copy());
  return manage(res);
}
UnionMap UnionMap::rangeMap() const {
  auto res = isl_union_map_range_map(copy());
  return manage(res);
}
UnionMap UnionMap::rangeProduct(UnionMap umap2) const {
  auto res = isl_union_map_range_product(copy(), umap2.release());
  return manage(res);
}
UnionMap UnionMap::reverse() const {
  auto res = isl_union_map_reverse(copy());
  return manage(res);
}
UnionMap UnionMap::subtract(UnionMap umap2) const {
  auto res = isl_union_map_subtract(copy(), umap2.release());
  return manage(res);
}
UnionMap UnionMap::subtractDomain(UnionSet dom) const {
  auto res = isl_union_map_subtract_domain(copy(), dom.release());
  return manage(res);
}
UnionMap UnionMap::subtractRange(UnionSet dom) const {
  auto res = isl_union_map_subtract_range(copy(), dom.release());
  return manage(res);
}
UnionMap UnionMap::unite(UnionMap umap2) const {
  auto res = isl_union_map_union(copy(), umap2.release());
  return manage(res);
}
UnionSet UnionMap::wrap() const {
  auto res = isl_union_map_wrap(copy());
  return manage(res);
}
UnionMap UnionMap::zip() const {
  auto res = isl_union_map_zip(copy());
  return manage(res);
}
// implementations for isl::UnionPwAff
UnionPwAff manage(__isl_take isl_union_pw_aff *ptr) {
  return UnionPwAff(ptr);
}

UnionPwAff give(__isl_take isl_union_pw_aff *ptr) {
  return manage(ptr);
}

UnionPwAff::UnionPwAff()
    : ptr(nullptr) {}

UnionPwAff::UnionPwAff(const UnionPwAff &obj)
    : ptr(obj.copy()) {}

UnionPwAff::UnionPwAff(std::nullptr_t)
    : ptr(nullptr) {}

UnionPwAff::UnionPwAff(__isl_take isl_union_pw_aff *ptr)
    : ptr(ptr) {}

UnionPwAff::UnionPwAff(PwAff pa) {
  auto res = isl_union_pw_aff_from_pw_aff(pa.release());
  ptr = res;
}
UnionPwAff::UnionPwAff(UnionSet domain, Val v) {
  auto res = isl_union_pw_aff_val_on_domain(domain.release(), v.release());
  ptr = res;
}
UnionPwAff::UnionPwAff(Ctx ctx, std::string str) {
  auto res = isl_union_pw_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
UnionPwAff &UnionPwAff::operator=(UnionPwAff obj) {
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

__isl_keep isl_union_pw_aff *UnionPwAff::keep() const {
  return get();
}

__isl_give isl_union_pw_aff *UnionPwAff::take() {
  return release();
}

UnionPwAff::operator bool() const {
  return !isNull();
}

isl_ctx *UnionPwAff::getCtx() const {
  return isl_union_pw_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const UnionPwAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

UnionPwAff UnionPwAff::add(UnionPwAff upa2) const {
  auto res = isl_union_pw_aff_add(copy(), upa2.release());
  return manage(res);
}
UnionPwAff UnionPwAff::empty(Space space) {
  auto res = isl_union_pw_aff_empty(space.release());
  return manage(res);
}
Stat UnionPwAff::foreachPwAff(std::function<Stat(PwAff)> &&fn) const {
  auto fn_lambda = [](isl_pw_aff *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<Stat(PwAff)> *)arg_1;
    Stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_pw_aff_foreach_pw_aff(get(), fn_lambda, &fn);
  return Stat(res);
}
Space UnionPwAff::getSpace() const {
  auto res = isl_union_pw_aff_get_space(get());
  return manage(res);
}
UnionPwAff UnionPwAff::pullback(UnionPwMultiAff upma) const {
  auto res = isl_union_pw_aff_pullback_union_pw_multi_aff(copy(), upma.release());
  return manage(res);
}
UnionPwAff UnionPwAff::sub(UnionPwAff upa2) const {
  auto res = isl_union_pw_aff_sub(copy(), upa2.release());
  return manage(res);
}
UnionPwAff UnionPwAff::unionAdd(UnionPwAff upa2) const {
  auto res = isl_union_pw_aff_union_add(copy(), upa2.release());
  return manage(res);
}
// implementations for isl::UnionPwMultiAff
UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr) {
  return UnionPwMultiAff(ptr);
}

UnionPwMultiAff give(__isl_take isl_union_pw_multi_aff *ptr) {
  return manage(ptr);
}

UnionPwMultiAff::UnionPwMultiAff()
    : ptr(nullptr) {}

UnionPwMultiAff::UnionPwMultiAff(const UnionPwMultiAff &obj)
    : ptr(obj.copy()) {}

UnionPwMultiAff::UnionPwMultiAff(std::nullptr_t)
    : ptr(nullptr) {}

UnionPwMultiAff::UnionPwMultiAff(__isl_take isl_union_pw_multi_aff *ptr)
    : ptr(ptr) {}

UnionPwMultiAff::UnionPwMultiAff(PwMultiAff pma) {
  auto res = isl_union_pw_multi_aff_from_pw_multi_aff(pma.release());
  ptr = res;
}
UnionPwMultiAff::UnionPwMultiAff(UnionSet uset) {
  auto res = isl_union_pw_multi_aff_from_domain(uset.release());
  ptr = res;
}
UnionPwMultiAff::UnionPwMultiAff(UnionMap umap) {
  auto res = isl_union_pw_multi_aff_from_union_map(umap.release());
  ptr = res;
}
UnionPwMultiAff::UnionPwMultiAff(Ctx ctx, std::string str) {
  auto res = isl_union_pw_multi_aff_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
UnionPwMultiAff::UnionPwMultiAff(UnionPwAff upa) {
  auto res = isl_union_pw_multi_aff_from_union_pw_aff(upa.release());
  ptr = res;
}
UnionPwMultiAff &UnionPwMultiAff::operator=(UnionPwMultiAff obj) {
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

__isl_keep isl_union_pw_multi_aff *UnionPwMultiAff::keep() const {
  return get();
}

__isl_give isl_union_pw_multi_aff *UnionPwMultiAff::take() {
  return release();
}

UnionPwMultiAff::operator bool() const {
  return !isNull();
}

isl_ctx *UnionPwMultiAff::getCtx() const {
  return isl_union_pw_multi_aff_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const UnionPwMultiAff &Obj) {
  OS << Obj.getStr();
  return OS;
}

UnionPwMultiAff UnionPwMultiAff::add(UnionPwMultiAff upma2) const {
  auto res = isl_union_pw_multi_aff_add(copy(), upma2.release());
  return manage(res);
}
UnionPwMultiAff UnionPwMultiAff::flatRangeProduct(UnionPwMultiAff upma2) const {
  auto res = isl_union_pw_multi_aff_flat_range_product(copy(), upma2.release());
  return manage(res);
}
UnionPwMultiAff UnionPwMultiAff::pullback(UnionPwMultiAff upma2) const {
  auto res = isl_union_pw_multi_aff_pullback_union_pw_multi_aff(copy(), upma2.release());
  return manage(res);
}
UnionPwMultiAff UnionPwMultiAff::unionAdd(UnionPwMultiAff upma2) const {
  auto res = isl_union_pw_multi_aff_union_add(copy(), upma2.release());
  return manage(res);
}
// implementations for isl::UnionSet
UnionSet manage(__isl_take isl_union_set *ptr) {
  return UnionSet(ptr);
}

UnionSet give(__isl_take isl_union_set *ptr) {
  return manage(ptr);
}

UnionSet::UnionSet()
    : ptr(nullptr) {}

UnionSet::UnionSet(const UnionSet &obj)
    : ptr(obj.copy()) {}

UnionSet::UnionSet(std::nullptr_t)
    : ptr(nullptr) {}

UnionSet::UnionSet(__isl_take isl_union_set *ptr)
    : ptr(ptr) {}

UnionSet::UnionSet(BasicSet bset) {
  auto res = isl_union_set_from_basic_set(bset.release());
  ptr = res;
}
UnionSet::UnionSet(Set set) {
  auto res = isl_union_set_from_set(set.release());
  ptr = res;
}
UnionSet::UnionSet(Point pnt) {
  auto res = isl_union_set_from_point(pnt.release());
  ptr = res;
}
UnionSet::UnionSet(Ctx ctx, std::string str) {
  auto res = isl_union_set_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
UnionSet &UnionSet::operator=(UnionSet obj) {
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

__isl_keep isl_union_set *UnionSet::keep() const {
  return get();
}

__isl_give isl_union_set *UnionSet::take() {
  return release();
}

UnionSet::operator bool() const {
  return !isNull();
}

isl_ctx *UnionSet::getCtx() const {
  return isl_union_set_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const UnionSet &Obj) {
  OS << Obj.getStr();
  return OS;
}

UnionSet UnionSet::affineHull() const {
  auto res = isl_union_set_affine_hull(copy());
  return manage(res);
}
UnionSet UnionSet::apply(UnionMap umap) const {
  auto res = isl_union_set_apply(copy(), umap.release());
  return manage(res);
}
UnionSet UnionSet::coalesce() const {
  auto res = isl_union_set_coalesce(copy());
  return manage(res);
}
UnionSet UnionSet::computeDivs() const {
  auto res = isl_union_set_compute_divs(copy());
  return manage(res);
}
UnionSet UnionSet::detectEqualities() const {
  auto res = isl_union_set_detect_equalities(copy());
  return manage(res);
}
Stat UnionSet::foreachPoint(std::function<Stat(Point)> &&fn) const {
  auto fn_lambda = [](isl_point *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<Stat(Point)> *)arg_1;
    Stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_set_foreach_point(get(), fn_lambda, &fn);
  return Stat(res);
}
Stat UnionSet::foreachSet(std::function<Stat(Set)> &&fn) const {
  auto fn_lambda = [](isl_set *arg_0, void *arg_1) -> isl_stat {
    auto *func = (std::function<Stat(Set)> *)arg_1;
    Stat ret = (*func)(isl::manage(arg_0));
    return isl_stat(ret);
  };
  auto res = isl_union_set_foreach_set(get(), fn_lambda, &fn);
  return Stat(res);
}
UnionSet UnionSet::gist(UnionSet context) const {
  auto res = isl_union_set_gist(copy(), context.release());
  return manage(res);
}
UnionSet UnionSet::gistParams(Set set) const {
  auto res = isl_union_set_gist_params(copy(), set.release());
  return manage(res);
}
UnionMap UnionSet::identity() const {
  auto res = isl_union_set_identity(copy());
  return manage(res);
}
UnionSet UnionSet::intersect(UnionSet uset2) const {
  auto res = isl_union_set_intersect(copy(), uset2.release());
  return manage(res);
}
UnionSet UnionSet::intersectParams(Set set) const {
  auto res = isl_union_set_intersect_params(copy(), set.release());
  return manage(res);
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
UnionSet UnionSet::lexmax() const {
  auto res = isl_union_set_lexmax(copy());
  return manage(res);
}
UnionSet UnionSet::lexmin() const {
  auto res = isl_union_set_lexmin(copy());
  return manage(res);
}
UnionSet UnionSet::polyhedralHull() const {
  auto res = isl_union_set_polyhedral_hull(copy());
  return manage(res);
}
Point UnionSet::samplePoint() const {
  auto res = isl_union_set_sample_point(copy());
  return manage(res);
}
UnionSet UnionSet::subtract(UnionSet uset2) const {
  auto res = isl_union_set_subtract(copy(), uset2.release());
  return manage(res);
}
UnionSet UnionSet::unite(UnionSet uset2) const {
  auto res = isl_union_set_union(copy(), uset2.release());
  return manage(res);
}
UnionMap UnionSet::unwrap() const {
  auto res = isl_union_set_unwrap(copy());
  return manage(res);
}
// implementations for isl::Val
Val manage(__isl_take isl_val *ptr) {
  return Val(ptr);
}

Val give(__isl_take isl_val *ptr) {
  return manage(ptr);
}

Val::Val()
    : ptr(nullptr) {}

Val::Val(const Val &obj)
    : ptr(obj.copy()) {}

Val::Val(std::nullptr_t)
    : ptr(nullptr) {}

Val::Val(__isl_take isl_val *ptr)
    : ptr(ptr) {}

Val::Val(Ctx ctx, long i) {
  auto res = isl_val_int_from_si(ctx.release(), i);
  ptr = res;
}
Val::Val(Ctx ctx, unsigned long u) {
  auto res = isl_val_int_from_ui(ctx.release(), u);
  ptr = res;
}
Val::Val(Ctx ctx, std::string str) {
  auto res = isl_val_read_from_str(ctx.release(), str.c_str());
  ptr = res;
}
Val &Val::operator=(Val obj) {
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

__isl_keep isl_val *Val::keep() const {
  return get();
}

__isl_give isl_val *Val::take() {
  return release();
}

Val::operator bool() const {
  return !isNull();
}

isl_ctx *Val::getCtx() const {
  return isl_val_get_ctx(ptr);
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
  return S;
}

inline llvm::raw_ostream &operator<<(llvm::raw_ostream &OS,
  const Val &Obj) {
  OS << Obj.getStr();
  return OS;
}

Val Val::two_exp() const {
  auto res = isl_val_2exp(copy());
  return manage(res);
}
Val Val::abs() const {
  auto res = isl_val_abs(copy());
  return manage(res);
}
Bool Val::absEq(const Val &v2) const {
  auto res = isl_val_abs_eq(get(), v2.get());
  return res;
}
Val Val::add(Val v2) const {
  auto res = isl_val_add(copy(), v2.release());
  return manage(res);
}
Val Val::addUi(unsigned long v2) const {
  auto res = isl_val_add_ui(copy(), v2);
  return manage(res);
}
Val Val::ceil() const {
  auto res = isl_val_ceil(copy());
  return manage(res);
}
int Val::cmpSi(long i) const {
  auto res = isl_val_cmp_si(get(), i);
  return res;
}
Val Val::div(Val v2) const {
  auto res = isl_val_div(copy(), v2.release());
  return manage(res);
}
Bool Val::eq(const Val &v2) const {
  auto res = isl_val_eq(get(), v2.get());
  return res;
}
Val Val::floor() const {
  auto res = isl_val_floor(copy());
  return manage(res);
}
Val Val::gcd(Val v2) const {
  auto res = isl_val_gcd(copy(), v2.release());
  return manage(res);
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
Val Val::inv() const {
  auto res = isl_val_inv(copy());
  return manage(res);
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
Val Val::max(Val v2) const {
  auto res = isl_val_max(copy(), v2.release());
  return manage(res);
}
Val Val::min(Val v2) const {
  auto res = isl_val_min(copy(), v2.release());
  return manage(res);
}
Val Val::mod(Val v2) const {
  auto res = isl_val_mod(copy(), v2.release());
  return manage(res);
}
Val Val::mul(Val v2) const {
  auto res = isl_val_mul(copy(), v2.release());
  return manage(res);
}
Val Val::nan(Ctx ctx) {
  auto res = isl_val_nan(ctx.release());
  return manage(res);
}
Bool Val::ne(const Val &v2) const {
  auto res = isl_val_ne(get(), v2.get());
  return res;
}
Val Val::neg() const {
  auto res = isl_val_neg(copy());
  return manage(res);
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
Val Val::sub(Val v2) const {
  auto res = isl_val_sub(copy(), v2.release());
  return manage(res);
}
Val Val::subUi(unsigned long v2) const {
  auto res = isl_val_sub_ui(copy(), v2);
  return manage(res);
}
Val Val::trunc() const {
  auto res = isl_val_trunc(copy());
  return manage(res);
}
Val Val::zero(Ctx ctx) {
  auto res = isl_val_zero(ctx.release());
  return manage(res);
}
}; /* namespace noexpections */

}; /* namespace isl */

#endif /* ISL_CPP_ALL */
