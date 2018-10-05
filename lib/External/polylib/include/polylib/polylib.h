/*
 * polylib.h  V4.12
 */

/* WARNING: you should not directly include this file,
   but use one of those variants:
   - polylib32.h (for 32 bits integers),
   - polylib64.h (for 64 bits integers),
   - polylibgmp.h (for gmp integers).
*/

#if POLYLIB_BITS == 32
@polylib32_defs@
#elif POLYLIB_BITS == 64
@polylib64_defs@
#endif

#define GNUMP

#if ! defined(LINEAR_VALUE_IS_LONGLONG) \
	&& ! defined(LINEAR_VALUE_IS_LONG) \
	&& ! defined(LINEAR_VALUE_IS_INT) \
	&& ! defined(LINEAR_VALUE_IS_CHARS) \
        && ! defined(GNUMP) \
        && ! defined(CLN)
#error Please #include polylib32.h or polylib64.h or polylibgmp.h (NOT polylib.h)
#endif

#include <../source/arith/arithmetique.h>
#include <../source/arith/arithmetic_errors.h>
#include <polylib/types.h>
#include <polylib/errormsg.h>
#include <polylib/vector.h>
#include <polylib/matrix.h>
#include <polylib/polyhedron.h>
#include <polylib/polyparam.h>
#include <polylib/param.h>
#include <polylib/alpha.h>
#include <polylib/ehrhart.h>
#include <polylib/ext_ehrhart.h>
#include <polylib/eval_ehrhart.h>
#include <polylib/SolveDio.h>
#include <polylib/Lattice.h>
#include <polylib/Matop.h>
#include <polylib/NormalForms.h>
#include <polylib/Zpolyhedron.h>

/* added for Ehrhart polynomial approximation + bounds */
#include <polylib/matrix_addon.h>
#include <polylib/matrix_permutations.h>
#include <polylib/compress_parms.h>

#ifdef GNUMP
#include <gmp.h>
#endif


