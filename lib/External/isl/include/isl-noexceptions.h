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

// declarations for isl::Aff
inline Aff manage(__isl_take isl_aff *ptr);

inline Aff give(__isl_take isl_aff *ptr);

class Aff {
  friend inline Aff manage(__isl_take isl_aff *ptr);

inline Aff give(__isl_take isl_aff *ptr);

  isl_aff *ptr = nullptr;

  inline explicit Aff(__isl_take isl_aff *ptr);

public:
  inline Aff();
  inline Aff(const Aff &obj);
  inline Aff(std::nullptr_t);
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
};

// declarations for isl::AstBuild
inline AstBuild manage(__isl_take isl_ast_build *ptr);

inline AstBuild give(__isl_take isl_ast_build *ptr);

class AstBuild {
  friend inline AstBuild manage(__isl_take isl_ast_build *ptr);

inline AstBuild give(__isl_take isl_ast_build *ptr);

  isl_ast_build *ptr = nullptr;

  inline explicit AstBuild(__isl_take isl_ast_build *ptr);

public:
  inline AstBuild();
  inline AstBuild(const AstBuild &obj);
  inline AstBuild(std::nullptr_t);
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
};

// declarations for isl::AstExpr
inline AstExpr manage(__isl_take isl_ast_expr *ptr);

inline AstExpr give(__isl_take isl_ast_expr *ptr);

class AstExpr {
  friend inline AstExpr manage(__isl_take isl_ast_expr *ptr);

inline AstExpr give(__isl_take isl_ast_expr *ptr);

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
};

// declarations for isl::AstNode
inline AstNode manage(__isl_take isl_ast_node *ptr);

inline AstNode give(__isl_take isl_ast_node *ptr);

class AstNode {
  friend inline AstNode manage(__isl_take isl_ast_node *ptr);

inline AstNode give(__isl_take isl_ast_node *ptr);

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
};

// declarations for isl::BasicMap
inline BasicMap manage(__isl_take isl_basic_map *ptr);

inline BasicMap give(__isl_take isl_basic_map *ptr);

class BasicMap {
  friend inline BasicMap manage(__isl_take isl_basic_map *ptr);

inline BasicMap give(__isl_take isl_basic_map *ptr);

  isl_basic_map *ptr = nullptr;

  inline explicit BasicMap(__isl_take isl_basic_map *ptr);

public:
  inline BasicMap();
  inline BasicMap(const BasicMap &obj);
  inline BasicMap(std::nullptr_t);
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
};

// declarations for isl::BasicSet
inline BasicSet manage(__isl_take isl_basic_set *ptr);

inline BasicSet give(__isl_take isl_basic_set *ptr);

class BasicSet {
  friend inline BasicSet manage(__isl_take isl_basic_set *ptr);

inline BasicSet give(__isl_take isl_basic_set *ptr);

  isl_basic_set *ptr = nullptr;

  inline explicit BasicSet(__isl_take isl_basic_set *ptr);

public:
  inline BasicSet();
  inline BasicSet(const BasicSet &obj);
  inline BasicSet(std::nullptr_t);
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
};

// declarations for isl::Id
inline Id manage(__isl_take isl_id *ptr);

inline Id give(__isl_take isl_id *ptr);

class Id {
  friend inline Id manage(__isl_take isl_id *ptr);

inline Id give(__isl_take isl_id *ptr);

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

// declarations for isl::Map
inline Map manage(__isl_take isl_map *ptr);

inline Map give(__isl_take isl_map *ptr);

class Map {
  friend inline Map manage(__isl_take isl_map *ptr);

inline Map give(__isl_take isl_map *ptr);

  isl_map *ptr = nullptr;

  inline explicit Map(__isl_take isl_map *ptr);

public:
  inline Map();
  inline Map(const Map &obj);
  inline Map(std::nullptr_t);
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
};

// declarations for isl::MultiAff
inline MultiAff manage(__isl_take isl_multi_aff *ptr);

inline MultiAff give(__isl_take isl_multi_aff *ptr);

class MultiAff {
  friend inline MultiAff manage(__isl_take isl_multi_aff *ptr);

inline MultiAff give(__isl_take isl_multi_aff *ptr);

  isl_multi_aff *ptr = nullptr;

  inline explicit MultiAff(__isl_take isl_multi_aff *ptr);

public:
  inline MultiAff();
  inline MultiAff(const MultiAff &obj);
  inline MultiAff(std::nullptr_t);
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
};

// declarations for isl::MultiPwAff
inline MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr);

inline MultiPwAff give(__isl_take isl_multi_pw_aff *ptr);

class MultiPwAff {
  friend inline MultiPwAff manage(__isl_take isl_multi_pw_aff *ptr);

inline MultiPwAff give(__isl_take isl_multi_pw_aff *ptr);

  isl_multi_pw_aff *ptr = nullptr;

  inline explicit MultiPwAff(__isl_take isl_multi_pw_aff *ptr);

public:
  inline MultiPwAff();
  inline MultiPwAff(const MultiPwAff &obj);
  inline MultiPwAff(std::nullptr_t);
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
};

// declarations for isl::MultiUnionPwAff
inline MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr);

inline MultiUnionPwAff give(__isl_take isl_multi_union_pw_aff *ptr);

class MultiUnionPwAff {
  friend inline MultiUnionPwAff manage(__isl_take isl_multi_union_pw_aff *ptr);

inline MultiUnionPwAff give(__isl_take isl_multi_union_pw_aff *ptr);

  isl_multi_union_pw_aff *ptr = nullptr;

  inline explicit MultiUnionPwAff(__isl_take isl_multi_union_pw_aff *ptr);

public:
  inline MultiUnionPwAff();
  inline MultiUnionPwAff(const MultiUnionPwAff &obj);
  inline MultiUnionPwAff(std::nullptr_t);
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
};

// declarations for isl::MultiVal
inline MultiVal manage(__isl_take isl_multi_val *ptr);

inline MultiVal give(__isl_take isl_multi_val *ptr);

class MultiVal {
  friend inline MultiVal manage(__isl_take isl_multi_val *ptr);

inline MultiVal give(__isl_take isl_multi_val *ptr);

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
};

// declarations for isl::Point
inline Point manage(__isl_take isl_point *ptr);

inline Point give(__isl_take isl_point *ptr);

class Point {
  friend inline Point manage(__isl_take isl_point *ptr);

inline Point give(__isl_take isl_point *ptr);

  isl_point *ptr = nullptr;

  inline explicit Point(__isl_take isl_point *ptr);

public:
  inline Point();
  inline Point(const Point &obj);
  inline Point(std::nullptr_t);
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

inline PwAff give(__isl_take isl_pw_aff *ptr);

  isl_pw_aff *ptr = nullptr;

  inline explicit PwAff(__isl_take isl_pw_aff *ptr);

public:
  inline PwAff();
  inline PwAff(const PwAff &obj);
  inline PwAff(std::nullptr_t);
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
};

// declarations for isl::PwMultiAff
inline PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr);

inline PwMultiAff give(__isl_take isl_pw_multi_aff *ptr);

class PwMultiAff {
  friend inline PwMultiAff manage(__isl_take isl_pw_multi_aff *ptr);

inline PwMultiAff give(__isl_take isl_pw_multi_aff *ptr);

  isl_pw_multi_aff *ptr = nullptr;

  inline explicit PwMultiAff(__isl_take isl_pw_multi_aff *ptr);

public:
  inline PwMultiAff();
  inline PwMultiAff(const PwMultiAff &obj);
  inline PwMultiAff(std::nullptr_t);
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
};

// declarations for isl::Schedule
inline Schedule manage(__isl_take isl_schedule *ptr);

inline Schedule give(__isl_take isl_schedule *ptr);

class Schedule {
  friend inline Schedule manage(__isl_take isl_schedule *ptr);

inline Schedule give(__isl_take isl_schedule *ptr);

  isl_schedule *ptr = nullptr;

  inline explicit Schedule(__isl_take isl_schedule *ptr);

public:
  inline Schedule();
  inline Schedule(const Schedule &obj);
  inline Schedule(std::nullptr_t);
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
};

// declarations for isl::ScheduleConstraints
inline ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr);

inline ScheduleConstraints give(__isl_take isl_schedule_constraints *ptr);

class ScheduleConstraints {
  friend inline ScheduleConstraints manage(__isl_take isl_schedule_constraints *ptr);

inline ScheduleConstraints give(__isl_take isl_schedule_constraints *ptr);

  isl_schedule_constraints *ptr = nullptr;

  inline explicit ScheduleConstraints(__isl_take isl_schedule_constraints *ptr);

public:
  inline ScheduleConstraints();
  inline ScheduleConstraints(const ScheduleConstraints &obj);
  inline ScheduleConstraints(std::nullptr_t);
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
};

// declarations for isl::ScheduleNode
inline ScheduleNode manage(__isl_take isl_schedule_node *ptr);

inline ScheduleNode give(__isl_take isl_schedule_node *ptr);

class ScheduleNode {
  friend inline ScheduleNode manage(__isl_take isl_schedule_node *ptr);

inline ScheduleNode give(__isl_take isl_schedule_node *ptr);

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
};

// declarations for isl::Set
inline Set manage(__isl_take isl_set *ptr);

inline Set give(__isl_take isl_set *ptr);

class Set {
  friend inline Set manage(__isl_take isl_set *ptr);

inline Set give(__isl_take isl_set *ptr);

  isl_set *ptr = nullptr;

  inline explicit Set(__isl_take isl_set *ptr);

public:
  inline Set();
  inline Set(const Set &obj);
  inline Set(std::nullptr_t);
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
};

// declarations for isl::Space
inline Space manage(__isl_take isl_space *ptr);

inline Space give(__isl_take isl_space *ptr);

class Space {
  friend inline Space manage(__isl_take isl_space *ptr);

inline Space give(__isl_take isl_space *ptr);

  isl_space *ptr = nullptr;

  inline explicit Space(__isl_take isl_space *ptr);

public:
  inline Space();
  inline Space(const Space &obj);
  inline Space(std::nullptr_t);
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
};

// declarations for isl::UnionAccessInfo
inline UnionAccessInfo manage(__isl_take isl_union_access_info *ptr);

inline UnionAccessInfo give(__isl_take isl_union_access_info *ptr);

class UnionAccessInfo {
  friend inline UnionAccessInfo manage(__isl_take isl_union_access_info *ptr);

inline UnionAccessInfo give(__isl_take isl_union_access_info *ptr);

  isl_union_access_info *ptr = nullptr;

  inline explicit UnionAccessInfo(__isl_take isl_union_access_info *ptr);

public:
  inline UnionAccessInfo();
  inline UnionAccessInfo(const UnionAccessInfo &obj);
  inline UnionAccessInfo(std::nullptr_t);
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
};

// declarations for isl::UnionFlow
inline UnionFlow manage(__isl_take isl_union_flow *ptr);

inline UnionFlow give(__isl_take isl_union_flow *ptr);

class UnionFlow {
  friend inline UnionFlow manage(__isl_take isl_union_flow *ptr);

inline UnionFlow give(__isl_take isl_union_flow *ptr);

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
};

// declarations for isl::UnionMap
inline UnionMap manage(__isl_take isl_union_map *ptr);

inline UnionMap give(__isl_take isl_union_map *ptr);

class UnionMap {
  friend inline UnionMap manage(__isl_take isl_union_map *ptr);

inline UnionMap give(__isl_take isl_union_map *ptr);

  isl_union_map *ptr = nullptr;

  inline explicit UnionMap(__isl_take isl_union_map *ptr);

public:
  inline UnionMap();
  inline UnionMap(const UnionMap &obj);
  inline UnionMap(std::nullptr_t);
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
};

// declarations for isl::UnionPwAff
inline UnionPwAff manage(__isl_take isl_union_pw_aff *ptr);

inline UnionPwAff give(__isl_take isl_union_pw_aff *ptr);

class UnionPwAff {
  friend inline UnionPwAff manage(__isl_take isl_union_pw_aff *ptr);

inline UnionPwAff give(__isl_take isl_union_pw_aff *ptr);

  isl_union_pw_aff *ptr = nullptr;

  inline explicit UnionPwAff(__isl_take isl_union_pw_aff *ptr);

public:
  inline UnionPwAff();
  inline UnionPwAff(const UnionPwAff &obj);
  inline UnionPwAff(std::nullptr_t);
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
};

// declarations for isl::UnionPwMultiAff
inline UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr);

inline UnionPwMultiAff give(__isl_take isl_union_pw_multi_aff *ptr);

class UnionPwMultiAff {
  friend inline UnionPwMultiAff manage(__isl_take isl_union_pw_multi_aff *ptr);

inline UnionPwMultiAff give(__isl_take isl_union_pw_multi_aff *ptr);

  isl_union_pw_multi_aff *ptr = nullptr;

  inline explicit UnionPwMultiAff(__isl_take isl_union_pw_multi_aff *ptr);

public:
  inline UnionPwMultiAff();
  inline UnionPwMultiAff(const UnionPwMultiAff &obj);
  inline UnionPwMultiAff(std::nullptr_t);
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
};

// declarations for isl::UnionSet
inline UnionSet manage(__isl_take isl_union_set *ptr);

inline UnionSet give(__isl_take isl_union_set *ptr);

class UnionSet {
  friend inline UnionSet manage(__isl_take isl_union_set *ptr);

inline UnionSet give(__isl_take isl_union_set *ptr);

  isl_union_set *ptr = nullptr;

  inline explicit UnionSet(__isl_take isl_union_set *ptr);

public:
  inline UnionSet();
  inline UnionSet(const UnionSet &obj);
  inline UnionSet(std::nullptr_t);
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
};

// declarations for isl::Val
inline Val manage(__isl_take isl_val *ptr);

inline Val give(__isl_take isl_val *ptr);

class Val {
  friend inline Val manage(__isl_take isl_val *ptr);

inline Val give(__isl_take isl_val *ptr);

  isl_val *ptr = nullptr;

  inline explicit Val(__isl_take isl_val *ptr);

public:
  inline Val();
  inline Val(const Val &obj);
  inline Val(std::nullptr_t);
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

}; /* namespace noexpections */

}; /* namespace isl */

#endif /* ISL_CPP_ALL */
