#ifndef OPUS_CONFIG_H
#define OPUS_CONFIG_H

/* Get CPU Info by asm method */
/* #undef CPU_INFO_BY_ASM */

/* Get CPU Info by c method */
/* #undef CPU_INFO_BY_C */

/* Custom modes */
/* #undef CUSTOM_MODES */

/* Do not build the float API */
/* #undef DISABLE_FLOAT_API */

/* Assertions */
/* #undef ENABLE_ASSERTIONS */

/* Ambisonics Support */
/* #undef ENABLE_EXPERIMENTAL_AMBISONICS */

/* Debug fixed-point implementation */
/* #undef FIXED_DEBUG */

/* Compile as fixed-point (for machines without a fast enough FPU) */
/* #undef FIXED_POINT */

/* Float approximations */
/* #undef FLOAT_APPROX */

/* Fuzzing */
/* #undef FUZZING */

/* Define to 1 if you have the <alloca.h> header file. */
/* #undef HAVE_ALLOCA_H */
#define HAVE_ALLOCA_H 1

/* NE10 library is installed on host. Make sure it is on target! */
/* #undef HAVE_ARM_NE10 */

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `lrint' function. */
#define HAVE_LRINT 1

/* Define to 1 if you have the `lrintf' function. */
#define HAVE_LRINTF 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `__malloc_hook' function. */
/* #undef HAVE___MALLOC_HOOK */

/* Define to the sub-directory where libtool stores uninstalled libraries. */
#define LT_OBJDIR ".libs/"

/* Make use of ARM asm optimization */
/* #undef OPUS_ARM_ASM */

/* Use generic ARMv4 inline asm optimizations */
/* #undef OPUS_ARM_INLINE_ASM */

/* Use ARMv5E inline asm optimizations */
/* #undef OPUS_ARM_INLINE_EDSP */

/* Use ARMv6 inline asm optimizations */
/* #undef OPUS_ARM_INLINE_MEDIA */

/* Use ARM NEON inline asm optimizations */
/* #undef OPUS_ARM_INLINE_NEON */

/* Define if assembler supports EDSP instructions */
/* #undef OPUS_ARM_MAY_HAVE_EDSP */

/* Define if assembler supports ARMv6 media instructions */
/* #undef OPUS_ARM_MAY_HAVE_MEDIA */

/* Define if compiler supports NEON instructions */
/* #undef OPUS_ARM_MAY_HAVE_NEON */

/* Compiler supports ARMv7/Aarch64 Neon Intrinsics */
/* #undef OPUS_ARM_MAY_HAVE_NEON_INTR */

/* Define if binary requires Aarch64 Neon Intrinsics */
/* #undef OPUS_ARM_PRESUME_AARCH64_NEON_INTR */

/* Define if binary requires EDSP instruction support */
/* #undef OPUS_ARM_PRESUME_EDSP */

/* Define if binary requires ARMv6 media instruction support */
/* #undef OPUS_ARM_PRESUME_MEDIA */

/* Define if binary requires NEON instruction support */
/* #undef OPUS_ARM_PRESUME_NEON */

/* Define if binary requires NEON intrinsics support */
/* #undef OPUS_ARM_PRESUME_NEON_INTR */

/* This is a build of OPUS */
#define OPUS_BUILD /**/

/* Use run-time CPU capabilities detection */
/* #undef OPUS_HAVE_RTCD */

/* Compiler supports X86 AVX Intrinsics */
/* #undef OPUS_X86_MAY_HAVE_AVX */

/* Compiler supports X86 SSE Intrinsics */
/* #undef OPUS_X86_MAY_HAVE_SSE */

/* Compiler supports X86 SSE2 Intrinsics */
/* #undef OPUS_X86_MAY_HAVE_SSE2 */

/* Compiler supports X86 SSE4.1 Intrinsics */
/* #undef OPUS_X86_MAY_HAVE_SSE4_1 */

/* Define if binary requires AVX intrinsics support */
/* #undef OPUS_X86_PRESUME_AVX */

/* Define if binary requires SSE intrinsics support */
/* #undef OPUS_X86_PRESUME_SSE */

/* Define if binary requires SSE2 intrinsics support */
/* #undef OPUS_X86_PRESUME_SSE2 */

/* Define if binary requires SSE4.1 intrinsics support */
/* #undef OPUS_X86_PRESUME_SSE4_1 */

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "opus@xiph.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "opus"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "opus 1.1.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "opus"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.1.4"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Make use of alloca */
/* #undef USE_ALLOCA */
#define USE_ALLOCA 1

/* Use C99 variable-size arrays */
//#define VAR_ARRAYS 1



/* 1234 = LIL_ENDIAN, 4321 = BIGENDIAN */
#define BYTEORDER 1234

/* Define to 1 if you have the `bcopy' function. */
#define HAVE_BCOPY 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `getpagesize' function. */
#define HAVE_GETPAGESIZE 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have a working `mmap' system call. */
#define HAVE_MMAP 1

#define HAVE_ERRNO_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/param.h> header file. */
#define HAVE_SYS_PARAM_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"


/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* whether byteorder is bigendian */
/* #undef WORDS_BIGENDIAN */



/* Define to __FUNCTION__ or "" if `__func__' does not conform to ANSI C. */
/* #undef __func__ */

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `long int' if <sys/types.h> does not define. */
/* #undef off_t */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */


#endif
