# External: Integer Set Library
if (POLLY_BUNDLED_ISL)
  set(ISL_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/isl")
  set(ISL_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/isl")
  find_package(GMP REQUIRED)
  include_directories(${GMP_INCLUDE_DIR})

  # Determine version of isl
  if (EXISTS "${ISL_SOURCE_DIR}/GIT_HEAD_ID")
    # The source comes from a 'make dist' archive
    file(READ "${ISL_SOURCE_DIR}/GIT_HEAD_ID" ISL_GIT_HEAD_ID)
    string(STRIP "${ISL_GIT_HEAD_ID}" ISL_GIT_HEAD_ID)
  elseif (EXISTS "${ISL_SOURCE_DIR}/gitversion.h")
    # The source directory is preconfigured
    file(READ "${ISL_SOURCE_DIR}/gitversion.h" GITVERSION_H)
    string(REGEX REPLACE ".*\\\"([^\\\"]*)\\\".*" "\\1" ISL_GIT_HEAD_ID "${GITVERSION_H}")
  elseif ()
    # Unknown revision
    # TODO: We could look for a .git and get the revision from HEAD
    set(ISL_GIT_HEAD_ID "UNKNOWN")
  endif ()

  message(STATUS "ISL version: ${ISL_GIT_HEAD_ID}")

  # Enable small integer optimization and imath
  set(USE_GMP_FOR_MP ON)
  set(USE_IMATH_FOR_MP OFF)
  set(USE_SMALL_INT_OPT OFF)

  # Determine compiler characteristics
  include(CheckCSourceCompiles)

  # Like check_c_source_compiles, but sets the result to either
  # 0 (error while compiling) or 1 (compiled successfully)
  # Required for compatibility with autotool's AC_CHECK_DECLS
  function (check_c_source_compiles_numeric _prog _var)
    check_c_source_compiles("${_prog}" "${_var}")
    if ("${${_var}}")
      set("${_var}" 1 PARENT_SCOPE)
    else ()
      set("${_var}" 0 PARENT_SCOPE)
    endif ()
  endfunction ()

  # Check for the existance of a type
  function (check_c_type_exists _type _files _variable)
    set(_includes "")
    foreach (file_name ${_files})
      set(_includes "${_includes}#include<${file_name}>\n")
    endforeach()
    check_c_source_compiles("
    ${_includes}
    ${_type} typeVar;
    int main() {
    return 0;
    }
    " ${_variable})
  endfunction ()


  check_c_source_compiles("
  int func(void) __attribute__((__warn_unused_result__));
  int main() { return 0; }
  " HAS_ATTRIBUTE_WARN_UNUSED_RESULT)
  set(GCC_WARN_UNUSED_RESULT)
  if (HAS_ATTRIBUTE_WARN_UNUSED_RESULT)
    set(GCC_WARN_UNUSED_RESULT "__attribute__((__warn_unused_result__))")
  endif ()

  check_c_source_compiles("
  __attribute__ ((unused)) static void foo(void);
  int main() { return 0; }
  " HAVE___ATTRIBUTE__)


  check_c_source_compiles_numeric("
  #include <strings.h>
  int main() { (void)ffs(0); return 0; }
  " HAVE_DECL_FFS)

  check_c_source_compiles_numeric("
  int main() { (void)__builtin_ffs(0); return 0; }
  " HAVE_DECL___BUILTIN_FFS)

  check_c_source_compiles_numeric("
  #include <intrin.h>
  int main() { (void)_BitScanForward(NULL, 0); return 0; }
  " HAVE_DECL__BITSCANFORWARD)

  if (NOT HAVE_DECL_FFS AND
      NOT HAVE_DECL___BUILTIN_FFS AND
      NOT HAVE_DECL__BITSCANFORWARD)
    message(FATAL_ERROR "No ffs implementation found")
  endif ()


  check_c_source_compiles_numeric("
  #include <strings.h>
  int main() { (void)strcasecmp(\"\", \"\"); return 0; }
  " HAVE_DECL_STRCASECMP)

  check_c_source_compiles_numeric("
  #include <string.h>
  int main() { (void)_stricmp(\"\", \"\"); return 0; }
  " HAVE_DECL__STRICMP)

  if (NOT HAVE_DECL_STRCASECMP AND NOT HAVE_DECL__STRICMP)
    message(FATAL_ERROR "No strcasecmp implementation found")
  endif ()


  check_c_source_compiles_numeric("
  #include <strings.h>
  int main() { (void)strncasecmp(\"\", \"\", 0); return 0; }
  " HAVE_DECL_STRNCASECMP)

  check_c_source_compiles_numeric("
  #include <string.h>
  int main() { (void)_strnicmp(\"\", \"\", 0); return 0; }
  " HAVE_DECL__STRNICMP)

  if (NOT HAVE_DECL_STRNCASECMP AND NOT HAVE_DECL__STRNICMP)
    message(FATAL_ERROR "No strncasecmp implementation found")
  endif ()


  check_c_source_compiles_numeric("
  #include <stdio.h>
  int main() { snprintf((void*)0, 0, \" \"); return 0; }
  " HAVE_DECL_SNPRINTF)

  check_c_source_compiles_numeric("
  #include <stdio.h>
  int main() { _snprintf((void*)0, 0, \" \"); return 0; }
  " HAVE_DECL__SNPRINTF)

  if (NOT HAVE_DECL_SNPRINTF AND NOT HAVE_DECL__SNPRINTF)
    message(FATAL_ERROR "No snprintf implementation found")
  endif ()


  check_c_type_exists(uint8_t "" HAVE_UINT8T)
  check_c_type_exists(uint8_t "stdint.h" HAVE_STDINT_H)
  check_c_type_exists(uint8_t "inttypes.h" HAVE_INTTYPES_H)
  check_c_type_exists(uint8_t "sys/types.h" HAVE_SYS_INTTYPES_H)
  if (HAVE_UINT8T)
    set(INCLUDE_STDINT_H "")
  elseif (HAVE_STDINT_H)
    set(INCLUDE_STDINT_H "#include <stdint.h>")
  elseif (HAVE_INTTYPES_H)
    set(INCLUDE_STDINT_H "#include <inttypes.h>")
  elseif (HAVE_SYS_INTTYPES_H)
    set(INCLUDE_STDINT_H "#include <sys/inttypes.h>")
  else ()
    message(FATAL_ERROR "No stdint.h or compatible found")
  endif ()

  # Write configure result
  # configure_file(... COPYONLY) avoids that the time stamp changes if the file is identical
  file(WRITE "${ISL_BINARY_DIR}/gitversion.h.tmp"
    "#define GIT_HEAD_ID \"${ISL_GIT_HEAD_ID}\"")
  configure_file("${ISL_BINARY_DIR}/gitversion.h.tmp"
    "${ISL_BINARY_DIR}/gitversion.h" COPYONLY)

  file(WRITE "${ISL_BINARY_DIR}/include/isl/stdint.h.tmp"
    "${INCLUDE_STDINT_H}\n")
  configure_file("${ISL_BINARY_DIR}/include/isl/stdint.h.tmp"
    "${ISL_BINARY_DIR}/include/isl/stdint.h" COPYONLY)

  configure_file("isl_config.h.cmake" "${ISL_BINARY_DIR}/isl_config.h")
  configure_file("isl_srcdir.c.cmake" "${ISL_BINARY_DIR}/isl_srcdir.c")

  include_directories(BEFORE
    ${ISL_BINARY_DIR}
    ${ISL_SOURCE_DIR}/imath
    ${ISL_SOURCE_DIR}/include
    ${ISL_SOURCE_DIR}
    )

  # ISL files to compile
  set (ISL_FILES
    isl/basis_reduction_tab.c
    isl/isl_aff.c
    isl/isl_aff_map.c
    isl/isl_affine_hull.c
    isl/isl_arg.c
    isl/isl_ast_build.c
    isl/isl_ast_build_expr.c
    isl/isl_ast.c
    isl/isl_ast_codegen.c
    isl/isl_ast_graft.c
    isl/isl_bernstein.c
    isl/isl_blk.c
    isl/isl_bound.c
    isl/isl_box.c
    isl/isl_coalesce.c
    isl/isl_constraint.c
    isl/isl_convex_hull.c
    isl/isl_ctx.c
    isl/isl_deprecated.c
    isl/isl_dim_map.c
    isl/isl_equalities.c
    isl/isl_factorization.c
    isl/isl_farkas.c
    isl/isl_ffs.c
    isl/isl_flow.c
    isl/isl_fold.c
    isl/isl_hash.c
    isl/isl_id.c
    isl/isl_id_to_ast_expr.c
    isl/isl_id_to_id.c
    isl/isl_id_to_pw_aff.c
    isl/isl_ilp.c
    isl/isl_gmp.c
    isl/isl_input.c
    isl/isl_local.c
    isl/isl_local_space.c
    isl/isl_lp.c
    isl/isl_map.c
    isl/isl_map_list.c
    isl/isl_map_simplify.c
    isl/isl_map_subtract.c
    isl/isl_map_to_basic_set.c
    isl/isl_mat.c
    isl/isl_morph.c
    isl/isl_obj.c
    isl/isl_options.c
    isl/isl_output.c
    isl/isl_point.c
    isl/isl_polynomial.c
    isl/isl_printer.c
    isl/isl_range.c
    isl/isl_reordering.c
    isl/isl_sample.c
    isl/isl_scan.c
    isl/isl_schedule.c
    isl/isl_schedule_band.c
    isl/isl_schedule_constraints.c
    isl/isl_schedule_node.c
    isl/isl_schedule_read.c
    isl/isl_schedule_tree.c
    isl/isl_scheduler.c
    isl/isl_seq.c
    isl/isl_set_list.c
    isl/isl_sort.c
    isl/isl_space.c
    isl/isl_stride.c
    isl/isl_stream.c
    isl/isl_tab.c
    isl/isl_tab_pip.c
    isl/isl_tarjan.c
    isl/isl_transitive_closure.c
    isl/isl_union_map.c
    isl/isl_val.c
    isl/isl_val_gmp.c
    isl/isl_vec.c
    isl/isl_version.c
    isl/isl_vertices.c
    isl/print.c
    isl/set_to_map.c
    isl/set_from_map.c
    isl/uset_to_umap.c
    isl/uset_from_umap.c
    isl/imath/gmp_compat.c
    isl/imath/imath.c
    isl/imath/imrat.c
    )

  add_polly_library(PollyISL
    ${ISL_FILES}
    )
  target_link_libraries(PollyISL ${GMP_LIBRARIES})

  if (NOT LLVM_INSTALL_TOOLCHAIN_ONLY)
    install(DIRECTORY
      ${ISL_SOURCE_DIR}/include/
      ${ISL_BINARY_DIR}/include/
      DESTINATION include/polly
      FILES_MATCHING
      PATTERN "*.h"
      PATTERN "CMakeFiles" EXCLUDE
      PATTERN ".svn" EXCLUDE
      )
  endif()

  add_executable(polly-isl-test
    isl/isl_test.c
    )
  set_target_properties(polly-isl-test PROPERTIES FOLDER "Polly")

  target_link_libraries(polly-isl-test PRIVATE
    PollyISL
    )

  # ISL requires at least C99 to compile. gcc < 5.0 use -std=gnu89 as default.
  target_enable_c99(PollyISL)
  target_enable_c99(polly-isl-test)
endif (POLLY_BUNDLED_ISL)

set(PET_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/pet")
set(PPCG_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/ppcg")
set(PPCG_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/ppcg")

# Determine version of ppcg
if (EXISTS "${PPCG_SOURCE_DIR}/GIT_HEAD_ID")
  # The source comes from a 'make dist' archive
  file(READ "${PPCG_SOURCE_DIR}/GIT_HEAD_ID" PPCG_GIT_HEAD_ID)
  string(STRIP "${PPCG_GIT_HEAD_ID}" PPCG_GIT_HEAD_ID)
elseif (EXISTS "${PPCG_SOURCE_DIR}/gitversion.h")
  # The source directory is preconfigured
  file(READ "${PPCG_SOURCE_DIR}/gitversion.h" GITVERSION_H)
  string(REGEX REPLACE ".*\\\"([^\\\"]*)\\\".*" "\\1" PPCG_GIT_HEAD_ID "${GITVERSION_H}")
elseif ()
  # Unknown revision
  # TODO: We could look for a .git and get the revision from HEAD
  set(PPCG_GIT_HEAD_ID "UNKNOWN")
endif ()

message(STATUS "PPCG version: ${PPCG_GIT_HEAD_ID}")

set (PPCG_FILES
     ppcg/cuda.c
     ppcg/cuda_common.c
     ppcg/external.c
     ppcg/gpu_array_tile.c
     ppcg/gpu.c
     ppcg/gpu_array_tile.c
     ppcg/gpu_group.c
     ppcg/gpu_hybrid.c
     ppcg/gpu_print.c
     ppcg/gpu_tree.c
     ppcg/grouping.c
     ppcg/hybrid.c
     ppcg/ppcg.c
     ppcg/ppcg_options.c
     ppcg/print.c
     ppcg/schedule.c
     ppcg/util.c
     )

include_directories(BEFORE
  ${PPCG_BINARY_DIR}
  ${PPCG_SOURCE_DIR}/imath
  ${PPCG_SOURCE_DIR}/include
  ${PET_SOURCE_DIR}/include
)

add_polly_library(PollyPPCG
  ${PPCG_FILES}
)

target_link_libraries(PollyPPCG PUBLIC ${ISL_TARGET})

set(POLYLIB_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/polylib")
set(POLYLIB_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/polylib")

set (POLYLIB_FILES
        polylib/source/arith/errors.c
        polylib/source/kernel/errormsg.c
        polylib/source/kernel/vector.c
        polylib/source/kernel/matrix.c
        polylib/source/kernel/polyhedron.c
        polylib/source/kernel/polyparam.c
        polylib/source/kernel/param.c
        polylib/source/kernel/alpha.c
        polylib/source/ehrhart/ehrhart.c
        polylib/source/ehrhart/ext_ehrhart.c
        polylib/source/ehrhart/eval_ehrhart.c
        polylib/source/ehrhart/homogenization.c
        polylib/source/ehrhart/ranking.c
        polylib/source/kernel/matrix_addon.c
        polylib/source/kernel/matrix_permutations.c
        polylib/source/kernel/compress_parms.c
        polylib/source/kernel/SolveDio.c
        polylib/source/kernel/Lattice.c
        polylib/source/kernel/Matop.c
        polylib/source/kernel/NormalForms.c
        polylib/source/kernel/Zpolyhedron.c
        polylib/source/arith/arithmetique.h 
     )

include_directories(BEFORE
  ${POLYLIB_BINARY_DIR}
  ${POLYLIB_SOURCE_DIR}/include
)


add_polly_library(PollyPOLYLIB
  ${POLYLIB_FILES}
)
target_link_libraries(PollyPOLYLIB ${GMP_LIBRARIES})

set(BARVINOK_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/barvinok")
set(BARVINOK_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/barvinok")

set (BARVINOK_FILES
barvinok/mpz_divisible_p.c
barvinok/sample.c
barvinok/evalue.c
barvinok/normalization.c
barvinok/scale.c
barvinok/options.c
barvinok/evalue_isl.c
barvinok/param_util.c
barvinok/evalue_read.c
barvinok/basis_reduction.c
barvinok/polysign.c
barvinok/hull.c
barvinok/util.c
barvinok/ilp.c
barvinok/polysign_isl.c
barvinok/bernoulli.c
barvinok/polysign_polylib.c
barvinok/verif_ehrhart.c
barvinok/binomial.c
barvinok/isl_aff_polylib.c
barvinok/verify.c
barvinok/isl_map_polylib.c
barvinok/collect_nonsimple.c
barvinok/isl_obj_list.c
barvinok/version.c
barvinok/isl_obj_str.c
barvinok/volume.c
barvinok/collect_polytopes.c
barvinok/isl_param_util.c
barvinok/reduce_domain.c
barvinok/lattice_width.c
barvinok/remove_equalities.c
barvinok/cone_integer_hull.c
barvinok/lexmin_options.c
barvinok/euler.cc
barvinok/lattice_point.cc
barvinok/param_polynomial.cc
barvinok/series.cc
barvinok/barvinok.cc
barvinok/bfcounter.cc
barvinok/evalue_convert.cc
barvinok/laurent.cc
barvinok/skewed_genfun.cc
barvinok/conversion.cc
barvinok/evalue_util.cc
barvinok/laurent_old.cc
barvinok/counter.cc
barvinok/fdstream.cc
barvinok/verify_series.cc
barvinok/decomposer.cc
barvinok/genfun.cc
barvinok/matrix_read.cc
barvinok/reducer.cc
barvinok/vertex_cone.cc
barvinok/dpoly.cc
barvinok/genfun_constructor.cc
barvinok/mat_util.cc
barvinok/scarf.cc
barvinok/edomain.cc
barvinok/summate.c
barvinok/NTL_QQ.cc
     )

include_directories(BEFORE
  ${BARVINOK_BINARY_DIR}
  ${BARVINOK_SOURCE_DIR}/.
)

add_polly_library(PollyBARVINOK
  ${BARVINOK_FILES}
)



message(STATUS ${ISL_TARGET})
message(STATUS ${POLYLIB_TARGET})
target_link_libraries(PollyBARVINOK PUBLIC PollyPOLYLIB)
target_link_libraries(PollyBARVINOK PUBLIC ntl)
target_link_libraries(PollyBARVINOK PUBLIC dl)
target_link_libraries(PollyBARVINOK PUBLIC ${ISL_TARGET})
target_compile_definitions(PollyBARVINOK PRIVATE "-DNTL_GMP_LIB")

# Disable warnings for upstream projects.
if (MSVC)
  set(DISABLE_WARNING_FLAGS
    -wd4018 # 'expression' : signed/unsigned mismatch
    -wd4090 # 'operation' : different 'modifier' qualifiers
    -wd4200 # nonstandard extension used: zero-sized array in struct/union
    -wd4201 # nonstandard extension used: nameless struct/union
    -wd4334 # 'operator': result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
    -wd4221 # nonstandard extension used : 'identifier' : cannot be initialized using address of automatic variable
  )
  if (POLLY_BUNDLED_ISL)
    target_compile_options(PollyISL PRIVATE ${DISABLE_WARNING_FLAGS})
    target_compile_options(polly-isl-test PRIVATE ${DISABLE_WARNING_FLAGS})
  endif (POLLY_BUNDLED_ISL)
  target_compile_options(PollyPPCG PRIVATE ${DISABLE_WARNING_FLAGS})
  target_compile_options(PollyPOLLYLIB PRIVATE ${DISABLE_WARNING_FLAGS})
  target_compile_options(PollyBARVINOK PRIVATE ${DISABLE_WARNING_FLAGS})
else ()
  if (POLLY_BUNDLED_ISL)
    set_target_properties(PollyISL polly-isl-test PROPERTIES COMPILE_FLAGS "-w")
  endif (POLLY_BUNDLED_ISL)
  set_target_properties(PollyPPCG PROPERTIES COMPILE_FLAGS "-w")
endif ()

if(MSVC)
  # In the Windows API (with some exceptions), the maximum length for a path is
  # MAX_PATH, which is defined as 260 characters.
  target_compile_definitions(PollyPPCG PRIVATE "-DPATH_MAX=260")
endif ()
