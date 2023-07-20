/*
 * libecb - http://software.schmorp.de/pkg/libecb
 *
 * Copyright (©) 2009-2015,2018-2021 Marc Alexander Lehmann <libecb@schmorp.de>
 * Copyright (©) 2011 Emanuele Giaquinta
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modifica-
 * tion, are permitted provided that the following conditions are met:
 *
 *   1.  Redistributions of source code must retain the above copyright notice,
 *       this list of conditions and the following disclaimer.
 *
 *   2.  Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MER-
 * CHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO
 * EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPE-
 * CIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTH-
 * ERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Alternatively, the contents of this file may be used under the terms of
 * the GNU General Public License ("GPL") version 2 or any later version,
 * in which case the provisions of the GPL are applicable instead of
 * the above. If you wish to allow the use of your version of this file
 * only under the terms of the GPL and not to allow others to use your
 * version of this file under the BSD license, indicate your decision
 * by deleting the provisions above and replace them with the notice
 * and other provisions required by the GPL. If you do not delete the
 * provisions above, a recipient may use your version of this file under
 * either the BSD or the GPL.
 */
#ifndef ECB_H
#define ECB_H

/* 16 bits major, 16 bits minor */
#define ECB_VERSION 0x0001000a

#include <string.h> /* for memcpy */

#if defined (_WIN32) && !defined (__MINGW32__)
typedef   signed char   int8_t;
typedef unsigned char  uint8_t;
typedef   signed char   int_fast8_t;
typedef unsigned char  uint_fast8_t;
typedef   signed short  int16_t;
typedef unsigned short uint16_t;
typedef   signed int    int_fast16_t;
typedef unsigned int   uint_fast16_t;
typedef   signed int    int32_t;
typedef unsigned int   uint32_t;
typedef   signed int    int_fast32_t;
typedef unsigned int   uint_fast32_t;
#if __GNUC__
typedef   signed long long int64_t;
typedef unsigned long long uint64_t;
#else /* _MSC_VER || __BORLANDC__ */
typedef   signed __int64   int64_t;
typedef unsigned __int64   uint64_t;
#endif
typedef  int64_t  int_fast64_t;
typedef uint64_t uint_fast64_t;
#ifdef _WIN64
#define ECB_PTRSIZE 8
typedef uint64_t uintptr_t;
typedef  int64_t  intptr_t;
#else
#define ECB_PTRSIZE 4
typedef uint32_t uintptr_t;
typedef  int32_t  intptr_t;
#endif
#else
#include <inttypes.h>
#if (defined INTPTR_MAX ? INTPTR_MAX : ULONG_MAX) > 0xffffffffU
#define ECB_PTRSIZE 8
#else
#define ECB_PTRSIZE 4
#endif
#endif

#define ECB_GCC_AMD64 (__amd64 || __amd64__ || __x86_64 || __x86_64__)
#define ECB_MSVC_AMD64 (_M_AMD64 || _M_X64)

#ifndef ECB_OPTIMIZE_SIZE
#if __OPTIMIZE_SIZE__
#define ECB_OPTIMIZE_SIZE 1
#else
#define ECB_OPTIMIZE_SIZE 0
#endif
#endif

/* work around x32 idiocy by defining proper macros */
#if ECB_GCC_AMD64 || ECB_MSVC_AMD64
#if _ILP32
#define ECB_AMD64_X32 1
#else
#define ECB_AMD64 1
#endif
#endif

#if ECB_PTRSIZE >= 8 || ECB_AMD64_X32
#define ECB_64BIT_NATIVE 1
#else
#define ECB_64BIT_NATIVE 0
#endif

/* many compilers define _GNUC_ to some versions but then only implement
 * what their idiot authors think are the "more important" extensions,
 * causing enormous grief in return for some better fake benchmark numbers.
 * or so.
 * we try to detect these and simply assume they are not gcc - if they have
 * an issue with that they should have done it right in the first place.
 */
#if !defined __GNUC_MINOR__ || defined __INTEL_COMPILER || defined __SUNPRO_C || defined __SUNPRO_CC || defined __llvm__ || defined __clang__
#define ECB_GCC_VERSION(major,minor) 0
#else
#define ECB_GCC_VERSION(major,minor) (__GNUC__ > (major) || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))
#endif

#define ECB_CLANG_VERSION(major,minor) (__clang_major__ > (major) || (__clang_major__ == (major) && __clang_minor__ >= (minor)))

#if __clang__ && defined __has_builtin
#define ECB_CLANG_BUILTIN(x) __has_builtin (x)
#else
#define ECB_CLANG_BUILTIN(x) 0
#endif

#if __clang__ && defined __has_extension
#define ECB_CLANG_EXTENSION(x) __has_extension (x)
#else
#define ECB_CLANG_EXTENSION(x) 0
#endif

#define ECB_CPP   (__cplusplus+0)
#define ECB_CPP11 (__cplusplus >= 201103L)
#define ECB_CPP14 (__cplusplus >= 201402L)
#define ECB_CPP17 (__cplusplus >= 201703L)

#if ECB_CPP
#define ECB_C            0
#define ECB_STDC_VERSION 0
#else
#define ECB_C            1
#define ECB_STDC_VERSION __STDC_VERSION__
#endif

#define ECB_C99   (ECB_STDC_VERSION >= 199901L)
#define ECB_C11   (ECB_STDC_VERSION >= 201112L)
#define ECB_C17   (ECB_STDC_VERSION >= 201710L)

#if ECB_CPP
#define ECB_EXTERN_C extern "C"
#define ECB_EXTERN_C_BEG ECB_EXTERN_C {
#define ECB_EXTERN_C_END }
#define ECB_EXT_C_BEG ECB_EXTERN_C_BEG
 // #define ECB_CMODE_START  \#ifdef __cplusplus extern "C" { \#endif

#define C_MODE extern "C" 
#define C_MODE_START C_MODE {
#define C_MODE_END }
#else
#define ECB_EXTERN_C extern
#define ECB_EXTERN_C_BEG
#define ECB_EXTERN_C_END

#define C_MODE
#define C_MODE_START
#define C_MODE_END 
#endif

/*****************************************************************************/

/* ECB_NO_THREADS - ecb is not used by multiple threads, ever */
/* ECB_NO_SMP     - ecb might be used in multiple threads, but only on a single cpu */

#if ECB_NO_THREADS
#define ECB_NO_SMP 1
#endif

#if ECB_NO_SMP
#define ECB_MEMORY_FENCE do { } while (0)
#endif

/* http://www-01.ibm.com/support/knowledgecenter/SSGH3R_13.1.0/com.ibm.xlcpp131.aix.doc/compiler_ref/compiler_builtins.html */
#if __xlC__ && ECB_CPP
#include <builtins.h>
#endif

#if 1400 <= _MSC_VER
#include <intrin.h> /* fence functions _ReadBarrier, also bit search functions _BitScanReverse */
#endif

#ifndef ECB_MEMORY_FENCE
#if ECB_GCC_VERSION(2,5) || defined __INTEL_COMPILER || (__llvm__ && __GNUC__) || __SUNPRO_C >= 0x5110 || __SUNPRO_CC >= 0x5110
#define ECB_MEMORY_FENCE_RELAXED __asm__ __volatile__ ("" : : : "memory")
#if __i386 || __i386__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("lock; orb $0, -1(%%esp)" : : : "memory")
#define ECB_MEMORY_FENCE_ACQUIRE __asm__ __volatile__ (""                        : : : "memory")
#define ECB_MEMORY_FENCE_RELEASE __asm__ __volatile__ (""                        : : : "memory")
#elif ECB_GCC_AMD64
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("mfence"   : : : "memory")
#define ECB_MEMORY_FENCE_ACQUIRE __asm__ __volatile__ (""         : : : "memory")
#define ECB_MEMORY_FENCE_RELEASE __asm__ __volatile__ (""         : : : "memory")
#elif __powerpc__ || __ppc__ || __powerpc64__ || __ppc64__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("sync"     : : : "memory")
#elif defined __ARM_ARCH_2__ \
    || defined __ARM_ARCH_3__  || defined __ARM_ARCH_3M__  \
|| defined __ARM_ARCH_4__  || defined __ARM_ARCH_4T__  \
|| defined __ARM_ARCH_5__  || defined __ARM_ARCH_5E__  \
|| defined __ARM_ARCH_5T__ || defined __ARM_ARCH_5TE__ \
|| defined __ARM_ARCH_5TEJ__
/* should not need any, unless running old code on newer cpu - arm doesn't support that */
#elif defined __ARM_ARCH_6__  || defined __ARM_ARCH_6J__  \
    || defined __ARM_ARCH_6K__ || defined __ARM_ARCH_6ZK__ \
|| defined __ARM_ARCH_6T2__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("mcr p15,0,%0,c7,c10,5" : : "r" (0) : "memory")
#elif defined __ARM_ARCH_7__  || defined __ARM_ARCH_7A__  \
    || defined __ARM_ARCH_7R__ || defined __ARM_ARCH_7M__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("dmb"      : : : "memory")
#elif __aarch64__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("dmb ish"  : : : "memory")
#elif (__sparc || __sparc__) && !(__sparc_v8__ || defined __sparcv8)
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("membar #LoadStore | #LoadLoad | #StoreStore | #StoreLoad" : : : "memory")
#define ECB_MEMORY_FENCE_ACQUIRE __asm__ __volatile__ ("membar #LoadStore | #LoadLoad"                            : : : "memory")
#define ECB_MEMORY_FENCE_RELEASE __asm__ __volatile__ ("membar #LoadStore             | #StoreStore")
#elif defined __s390__ || defined __s390x__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("bcr 15,0" : : : "memory")
#elif defined __mips__
/* GNU/Linux emulates sync on mips1 architectures, so we force its use */
/* anybody else who still uses mips1 is supposed to send in their version, with detection code. */
#define ECB_MEMORY_FENCE         __asm__ __volatile__ (".set mips2; sync; .set mips0" : : : "memory")
#elif defined __alpha__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("mb"       : : : "memory")
#elif defined __hppa__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ (""         : : : "memory")
#define ECB_MEMORY_FENCE_RELEASE __asm__ __volatile__ ("")
#elif defined __ia64__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("mf"       : : : "memory")
#elif defined __m68k__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ (""         : : : "memory")
#elif defined __m88k__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ ("tb1 0,%%r0,128" : : : "memory")
#elif defined __sh__
#define ECB_MEMORY_FENCE         __asm__ __volatile__ (""         : : : "memory")
#endif
#endif
#endif

#ifndef ECB_MEMORY_FENCE
#if ECB_GCC_VERSION(4,7)
/* see comment below (stdatomic.h) about the C11 memory model. */
#define ECB_MEMORY_FENCE         __atomic_thread_fence (__ATOMIC_SEQ_CST)
#define ECB_MEMORY_FENCE_ACQUIRE __atomic_thread_fence (__ATOMIC_ACQUIRE)
#define ECB_MEMORY_FENCE_RELEASE __atomic_thread_fence (__ATOMIC_RELEASE)
#undef ECB_MEMORY_FENCE_RELAXED
#define ECB_MEMORY_FENCE_RELAXED __atomic_thread_fence (__ATOMIC_RELAXED)

#elif ECB_CLANG_EXTENSION(c_atomic)
/* see comment below (stdatomic.h) about the C11 memory model. */
#define ECB_MEMORY_FENCE         __c11_atomic_thread_fence (__ATOMIC_SEQ_CST)
#define ECB_MEMORY_FENCE_ACQUIRE __c11_atomic_thread_fence (__ATOMIC_ACQUIRE)
#define ECB_MEMORY_FENCE_RELEASE __c11_atomic_thread_fence (__ATOMIC_RELEASE)
#undef ECB_MEMORY_FENCE_RELAXED
#define ECB_MEMORY_FENCE_RELAXED __c11_atomic_thread_fence (__ATOMIC_RELAXED)

#elif ECB_GCC_VERSION(4,4) || defined __INTEL_COMPILER || defined __clang__
#define ECB_MEMORY_FENCE         __sync_synchronize ()
#elif _MSC_VER >= 1500 /* VC++ 2008 */
/* apparently, microsoft broke all the memory barrier stuff in Visual Studio 2008... */
#pragma intrinsic(_ReadBarrier,_WriteBarrier,_ReadWriteBarrier)
#define ECB_MEMORY_FENCE         _ReadWriteBarrier (); MemoryBarrier()
#define ECB_MEMORY_FENCE_ACQUIRE _ReadWriteBarrier (); MemoryBarrier() /* according to msdn, _ReadBarrier is not a load fence */
#define ECB_MEMORY_FENCE_RELEASE _WriteBarrier (); MemoryBarrier()
#elif _MSC_VER >= 1400 /* VC++ 2005 */
#pragma intrinsic(_ReadBarrier,_WriteBarrier,_ReadWriteBarrier)
#define ECB_MEMORY_FENCE         _ReadWriteBarrier ()
#define ECB_MEMORY_FENCE_ACQUIRE _ReadWriteBarrier () /* according to msdn, _ReadBarrier is not a load fence */
#define ECB_MEMORY_FENCE_RELEASE _WriteBarrier ()
#elif defined _WIN32
#include <WinNT.h>
#define ECB_MEMORY_FENCE         MemoryBarrier () /* actually just xchg on x86... scary */
#elif __SUNPRO_C >= 0x5110 || __SUNPRO_CC >= 0x5110
#include <mbarrier.h>
#define ECB_MEMORY_FENCE         __machine_rw_barrier  ()
#define ECB_MEMORY_FENCE_ACQUIRE __machine_acq_barrier ()
#define ECB_MEMORY_FENCE_RELEASE __machine_rel_barrier ()
#define ECB_MEMORY_FENCE_RELAXED __compiler_barrier ()
#elif __xlC__
#define ECB_MEMORY_FENCE         __sync ()
#endif
#endif

#ifndef ECB_MEMORY_FENCE
#if ECB_C11 && !defined __STDC_NO_ATOMICS__
/* we assume that these memory fences work on all variables/all memory accesses, */
/* not just C11 atomics and atomic accesses */
#include <stdatomic.h>
#define ECB_MEMORY_FENCE         atomic_thread_fence (memory_order_seq_cst)
#define ECB_MEMORY_FENCE_ACQUIRE atomic_thread_fence (memory_order_acquire)
#define ECB_MEMORY_FENCE_RELEASE atomic_thread_fence (memory_order_release)
#endif
#endif

#ifndef ECB_MEMORY_FENCE
#if !ECB_AVOID_PTHREADS
/*
 * if you get undefined symbol references to pthread_mutex_lock,
 * or failure to find pthread.h, then you should implement
 * the ECB_MEMORY_FENCE operations for your cpu/compiler
 * OR provide pthread.h and link against the posix thread library
 * of your system.
 */
#include <pthread.h>
#define ECB_NEEDS_PTHREADS 1
#define ECB_MEMORY_FENCE_NEEDS_PTHREADS 1

static pthread_mutex_t ecb_mf_lock = PTHREAD_MUTEX_INITIALIZER;
#define ECB_MEMORY_FENCE do { pthread_mutex_lock (&ecb_mf_lock); pthread_mutex_unlock (&ecb_mf_lock); } while (0)
#endif
#endif

#if !defined ECB_MEMORY_FENCE_ACQUIRE && defined ECB_MEMORY_FENCE
#define ECB_MEMORY_FENCE_ACQUIRE ECB_MEMORY_FENCE
#endif

#if !defined ECB_MEMORY_FENCE_RELEASE && defined ECB_MEMORY_FENCE
#define ECB_MEMORY_FENCE_RELEASE ECB_MEMORY_FENCE
#endif

#if !defined ECB_MEMORY_FENCE_RELAXED && defined ECB_MEMORY_FENCE
#define ECB_MEMORY_FENCE_RELAXED ECB_MEMORY_FENCE /* very heavy-handed */
#endif

/*****************************************************************************/

#if ECB_CPP
#define ECB_INLINE static inline
#elif ECB_GCC_VERSION(2,5)
#define ECB_INLINE static __inline__
#elif ECB_C99
#define ECB_INLINE static inline __attribute__((always_inline))
#else
#define ECB_INLINE static
#endif

#if ECB_GCC_VERSION(3,3)
#define ECB_RESTRICT __restrict__
#elif ECB_C99
#define ECB_RESTRICT restrict
#else
#define ECB_RESTRICT
#endif

typedef int ECB_BOOL;

#define ECB_CONCAT_(a, b) a ## b
#define ECB_CONCAT(a, b) ECB_CONCAT_(a, b)
#define ECB_STRINGIFY_(a) # a
#define ECB_STRINGIFY(a) ECB_STRINGIFY_(a)
#define ECB_STRINGIFY_EXPR(expr) ((expr), ECB_STRINGIFY_ (expr))

#define ECB_FUNCTION_ ECB_INLINE

#if ECB_GCC_VERSION(3,1) || ECB_CLANG_VERSION(2,8)
#define ECB_ARRT(attrlist)        __attribute__ (attrlist)
#else
#define ECB_ARRT(attrlist)
#endif

#if ECB_GCC_VERSION(3,1) || ECB_CLANG_BUILTIN(__builtin_constant_p)
#define ECB_IS_CONST(expr)          __builtin_constant_p (expr)
#else
/* possible C11 impl for integral types
   typedef struct ecb_is_constant_struct ecb_is_constant_struct;
#define ECB_IS_CONST(expr)          _Generic ((1 ? (struct ecb_is_constant_struct *)0 : (void *)((expr) - (expr)), ecb_is_constant_struct *: 0, default: 1)) */

#define ECB_IS_CONST(expr)          0
#endif

#if ECB_GCC_VERSION(3,1) || ECB_CLANG_BUILTIN(__builtin_expect)
#define ECB_EXPECT(expr,value)         __builtin_expect ((expr),(value))
#else
#define ECB_EXPECT(expr,value)         (expr)
#endif

#if ECB_GCC_VERSION(3,1) || ECB_CLANG_BUILTIN(__builtin_prefetch)
#define ECB_PREFETCH(addr,rw,locality) __builtin_prefetch (addr, rw, locality)
#else
#define ECB_PREFETCH(addr,rw,locality)
#endif

/* no emulation for ecb_decltype */
#if ECB_CPP11
// older implementations might have problems with decltype(x)::type, work around it
template<class T> struct ecb_decltype_t { typedef T type; };
#define ECB_DECLTYPE(x) ecb_decltype_t<decltype (x)>::type
#elif ECB_GCC_VERSION(3,0) || ECB_CLANG_VERSION(2,8)
#define ECB_DECLTYPE(x) __typeof__ (x)
#endif

#if _MSC_VER >= 1300
#define ECB_DEPRECATED __declspec (deprecated)
#else
#define ECB_DEPRECATED ECB_ATTR((__deprecated__))
#endif

#if _MSC_VER >= 1500
#define ECB_DEPRECATED_MESSAGE(msg) __declspec (deprecated (msg))
#elif ECB_GCC_VERSION(4,5)
#define ECB_DEPRECATED_MESSAGE(msg) ECB_ATTR ((__deprecated__ (msg))
#else
#define ECB_DEPRECATED_MESSAGE(msg) ECB_DEPRECATED
#endif

        /**
         * 声明为非内联函数
         *
         */
#if _MSC_VER >= 1400
#define ECB_NOINLINE __declspec (noinline)
#else
#define ECB_NOINLINE ECB_ATTR ((__noinline__))
#endif

#define ECB_UNUSED     ECB_ATTR ((__unused__))
#define ECB_CONST      ECB_ATTR ((__const__))
#define ECB_PURE       ECB_ATTR ((__pure__))


        /**
         * 这个属性告诉编译器函数不会返回，这可以用来抑制关于未达到代码路径的错误。
         * C库函数abort（）和exit（）都使用此属性声明：
         */
#if ECB_C11 || __IBMC_NORETURN
/* http://www-01.ibm.com/support/knowledgecenter/SSGH3R_13.1.0/com.ibm.xlcpp131.aix.doc/language_ref/noreturn.html */
#define ECB_NORETURN   _Noreturn
#elif ECB_CPP11
#define ECB_NORETURN   [[noreturn]]
#elif _MSC_VER >= 1200
/* http://msdn.microsoft.com/en-us/library/k6ktzx3s.aspx */
#define ECB_NORETURN   __declspec (noreturn)
#else
#define ECB_NORETURN   ECB_ATTR((__noreturn__))
#endif

#if ECB_GCC_VERSION(4,3)
#define ECB_ARTIFICIAL ECB_ATTR((__artificial__))
#define ECB_HOT        ECB_ATTR((__hot__))
#define ECB_COLD       ECB_ATTR((__cold__))
#else
#define ECB_ARTIFICIAL
#define ECB_HOT
#define ECB_COLD
#endif

/* put around conditional expressions if you are very sure that the  */
/* expression is mostly true or mostly false. note that these return */
/* booleans, not the expression.                                     */
#define ECB_EXPECT_FALSE(expr) ECB_EXPECT (!!(expr), 0)
#define ECB_EXPECT_TRUE(expr)  ECB_EXPECT (!!(expr), 1)
/* for compatibility to the rest of the world */
#define ECB_LIKELY(expr)   ECB_EXPECT_TRUE  (expr)
#define ECB_UNLIKELY(expr) ECB_EXPECT_FALSE (expr)

/* count trailing zero bits and count # of one bits */
#if ECB_GCC_VERSION(3,4) \
    || (ECB_CLANG_BUILTIN(__builtin_clz) && ECB_CLANG_BUILTIN(__builtin_clzll) \
            && ECB_CLANG_BUILTIN(__builtin_ctz) && ECB_CLANG_BUILTIN(__builtin_ctzll) \
            && ECB_CLANG_BUILTIN(__builtin_popcount))
/* we assume int == 32 bit, long == 32 or 64 bit and long long == 64 bit */
#define ECB_LD32(x)      (__builtin_clz      (x) ^ 31)
#define ECB_LD64(x)      (__builtin_clzll    (x) ^ 63)
#define ECB_CTZ32(x)      __builtin_ctz      (x)
#define ECB_CTZ64(x)      __builtin_ctzll    (x)
#define ECB_POPCOUNT32(x) __builtin_popcount (x)
/* no popcountll */
#else
ECB_FUNCTION_ ECB_CONST int ECB_CTZ32 (uint32_t x);
    ECB_FUNCTION_ ECB_CONST int
ECB_CTZ32 (uint32_t x)
{
#if 1400 <= _MSC_VER && (_M_IX86 || _M_X64 || _M_IA64 || _M_ARM)
    unsigned long r;
    _BitScanForward (&r, x);
    return (int)r;
#else
    int r = 0;

    x &= ~x + 1; /* this isolates the lowest bit */

#if ECB_BRANCHLESS_ON_I386
    r += !!(x & 0xaaaaaaaa) << 0;
    r += !!(x & 0xcccccccc) << 1;
    r += !!(x & 0xf0f0f0f0) << 2;
    r += !!(x & 0xff00ff00) << 3;
    r += !!(x & 0xffff0000) << 4;
#else
    if (x & 0xaaaaaaaa) r +=  1;
    if (x & 0xcccccccc) r +=  2;
    if (x & 0xf0f0f0f0) r +=  4;
    if (x & 0xff00ff00) r +=  8;
    if (x & 0xffff0000) r += 16;
#endif

    return r;
#endif
}

ECB_FUNCTION_ ECB_CONST int ECB_CTZ64 (uint64_t x);
    ECB_FUNCTION_ ECB_CONST int
ecb_ctz64 (uint64_t x)
{
#if 1400 <= _MSC_VER && (_M_X64 || _M_IA64 || _M_ARM)
    unsigned long r;
    _BitScanForward64 (&r, x);
    return (int)r;
#else
    int shift = x & 0xffffffff ? 0 : 32;
    return ecb_ctz32 (x >> shift) + shift;
#endif
}

ECB_FUNCTION_ ECB_CONST int ECB_POPCOUNT32 (uint32_t x);
    ECB_FUNCTION_ ECB_CONST int
ECB_POPCOUNT32 (uint32_t x)
{
    x -=  (x >> 1) & 0x55555555;
    x  = ((x >> 2) & 0x33333333) + (x & 0x33333333);
    x  = ((x >> 4) + x) & 0x0f0f0f0f;
    x *= 0x01010101;

    return x >> 24;
}

ECB_FUNCTION_ ECB_CONST int ECB_LD32 (uint32_t x);
ECB_FUNCTION_ ECB_CONST int ECB_LD32 (uint32_t x)
{
#if 1400 <= _MSC_VER && (_M_IX86 || _M_X64 || _M_IA64 || _M_ARM)
    unsigned long r;
    _BitScanReverse (&r, x);
    return (int)r;
#else
    int r = 0;

    if (x >> 16) { x >>= 16; r += 16; }
    if (x >>  8) { x >>=  8; r +=  8; }
    if (x >>  4) { x >>=  4; r +=  4; }
    if (x >>  2) { x >>=  2; r +=  2; }
    if (x >>  1) {           r +=  1; }

    return r;
#endif
}

ECB_FUNCTION_ ECB_CONST int ECB_LD64 (uint64_t x);
ECB_FUNCTION_ ECB_CONST int ECB_LD64 (uint64_t x)
{
#if 1400 <= _MSC_VER && (_M_X64 || _M_IA64 || _M_ARM)
    unsigned long r;
    _BitScanReverse64 (&r, x);
    return (int)r;
#else
    int r = 0;

    if (x >> 32) { x >>= 32; r += 32; }

    return r + ECB_LD32 (x);
#endif
}
#endif

ECB_FUNCTION_ ECB_CONST ecb_bool ECB_IS_POT32 (uint32_t x);
ECB_FUNCTION_ ECB_CONST ecb_bool ECB_IS_POT32 (uint32_t x) { return !(x & (x - 1)); }
ECB_FUNCTION_ ECB_CONST ecb_bool ECB_IS_POT64 (uint64_t x);
ECB_FUNCTION_ ECB_CONST ecb_bool ECB_IS_POT64 (uint64_t x) { return !(x & (x - 1)); }

ECB_FUNCTION_ ECB_CONST uint8_t  ECB_BITREV8  (uint8_t  x);
ECB_FUNCTION_ ECB_CONST uint8_t  ECB_BITREV8  (uint8_t  x)
{
    return (  (x * 0x0802U & 0x22110U)
            | (x * 0x8020U & 0x88440U)) * 0x10101U >> 16;
}

ECB_FUNCTION_ ECB_CONST uint16_t ECB_BITREV16 (uint16_t x);
ECB_FUNCTION_ ECB_CONST uint16_t ECB_BITREV16 (uint16_t x)
{
    x = ((x >>  1) &     0x5555) | ((x &     0x5555) <<  1);
    x = ((x >>  2) &     0x3333) | ((x &     0x3333) <<  2);
    x = ((x >>  4) &     0x0f0f) | ((x &     0x0f0f) <<  4);
    x = ( x >>  8              ) | ( x               <<  8);

    return x;
}

ECB_FUNCTION_ ECB_CONST uint32_t ECB_BITREV32 (uint32_t x);
ECB_FUNCTION_ ECB_CONST uint32_t ECB_BITREV32 (uint32_t x)
{
    x = ((x >>  1) & 0x55555555) | ((x & 0x55555555) <<  1);
    x = ((x >>  2) & 0x33333333) | ((x & 0x33333333) <<  2);
    x = ((x >>  4) & 0x0f0f0f0f) | ((x & 0x0f0f0f0f) <<  4);
    x = ((x >>  8) & 0x00ff00ff) | ((x & 0x00ff00ff) <<  8);
    x = ( x >> 16              ) | ( x               << 16);

    return x;
}

/* popcount64 is only available on 64 bit cpus as gcc builtin */
/* so for this version we are lazy */
ECB_FUNCTION_ ECB_CONST int ECB_POPCOUNT64 (uint64_t x);
    ECB_FUNCTION_ ECB_CONST int
ECB_POPCOUNT64 (uint64_t x)
{
    return ECB_POPCOUNT32 (x) + ECB_POPCOUNT32 (x >> 32);
}

ECB_INLINE ECB_CONST uint8_t  ECB_ROTL8  (uint8_t  x, unsigned int count);
ECB_INLINE ECB_CONST uint8_t  ECB_ROTR8  (uint8_t  x, unsigned int count);
ECB_INLINE ECB_CONST uint16_t ECB_ROTL16 (uint16_t x, unsigned int count);
ECB_INLINE ECB_CONST uint16_t ECB_ROTR16 (uint16_t x, unsigned int count);
ECB_INLINE ECB_CONST uint32_t ECB_ROTL32 (uint32_t x, unsigned int count);
ECB_INLINE ECB_CONST uint32_t ECB_ROTR32 (uint32_t x, unsigned int count);
ECB_INLINE ECB_CONST uint64_t ECB_ROTL64 (uint64_t x, unsigned int count);
ECB_INLINE ECB_CONST uint64_t ECB_ROTR64 (uint64_t x, unsigned int count);

ECB_INLINE ECB_CONST uint8_t  ECB_ROTL8  (uint8_t  x, unsigned int count) { return (x >> (-count &  7)) | (x << (count &  7)); }
ECB_INLINE ECB_CONST uint8_t  ECB_ROTR8  (uint8_t  x, unsigned int count) { return (x << (-count &  7)) | (x >> (count &  7)); }
ECB_INLINE ECB_CONST uint16_t ECB_ROTL16 (uint16_t x, unsigned int count) { return (x >> (-count & 15)) | (x << (count & 15)); }
ECB_INLINE ECB_CONST uint16_t ECB_ROTR16 (uint16_t x, unsigned int count) { return (x << (-count & 15)) | (x >> (count & 15)); }
ECB_INLINE ECB_CONST uint32_t ECB_ROTL32 (uint32_t x, unsigned int count) { return (x >> (-count & 31)) | (x << (count & 31)); }
ECB_INLINE ECB_CONST uint32_t ECB_ROTR32 (uint32_t x, unsigned int count) { return (x << (-count & 31)) | (x >> (count & 31)); }
ECB_INLINE ECB_CONST uint64_t ECB_ROTL64 (uint64_t x, unsigned int count) { return (x >> (-count & 63)) | (x << (count & 63)); }
ECB_INLINE ECB_CONST uint64_t ECB_ROTR64 (uint64_t x, unsigned int count) { return (x << (-count & 63)) | (x >> (count & 63)); }

#if ECB_CPP

inline uint8_t  ECB_CTZ (uint8_t  v) { return ECB_CTZ32 (v); }
inline uint16_t ECB_CTZ (uint16_t v) { return ECB_CTZ32 (v); }
inline uint32_t ECB_CTZ (uint32_t v) { return ECB_CTZ32 (v); }
inline uint64_t ECB_CTZ (uint64_t v) { return ECB_CTZ64 (v); }

inline bool ECB_IS_POT (uint8_t  v) { return ECB_IS_POT32 (v); }
inline bool ECB_IS_POT (uint16_t v) { return ECB_IS_POT32 (v); }
inline bool ECB_IS_POT (uint32_t v) { return ECB_IS_POT32 (v); }
inline bool ECB_IS_POT (uint64_t v) { return ECB_IS_POT64 (v); }

inline int ECB_LD (uint8_t  v) { return ECB_LD32 (v); }
inline int ECB_LD (uint16_t v) { return ECB_LD32 (v); }
inline int ECB_LD (uint32_t v) { return ECB_LD32 (v); }
inline int ECB_LD (uint64_t v) { return ECB_LD64 (v); }

inline int ECB_POPCOUNT (uint8_t  v) { return ECB_POPCOUNT32 (v); }
inline int ECB_POPCOUNT (uint16_t v) { return ECB_POPCOUNT32 (v); }
inline int ECB_POPCOUNT (uint32_t v) { return ECB_POPCOUNT32 (v); }
inline int ECB_POPCOUNT (uint64_t v) { return ECB_POPCOUNT64 (v); }

inline uint8_t  ECB_BITREV (uint8_t  v) { return ECB_BITREV8  (v); }
inline uint16_t ECB_BITREV (uint16_t v) { return ECB_BITREV16 (v); }
inline uint32_t ECB_BITREV (uint32_t v) { return ECB_BITREV32 (v); }

inline uint8_t  ECB_ROTL (uint8_t  v, unsigned int count) { return ECB_ROTL8  (v, count); }
inline uint16_t ECB_ROTL (uint16_t v, unsigned int count) { return ECB_ROTL16 (v, count); }
inline uint32_t ECB_ROTL (uint32_t v, unsigned int count) { return ECB_ROTL32 (v, count); }
inline uint64_t ECB_ROTL (uint64_t v, unsigned int count) { return ECB_ROTL64 (v, count); }

inline uint8_t  ECB_ROTR (uint8_t  v, unsigned int count) { return ECB_ROTR8  (v, count); }
inline uint16_t ECB_ROTR (uint16_t v, unsigned int count) { return ECB_ROTR16 (v, count); }
inline uint32_t ECB_ROTR (uint32_t v, unsigned int count) { return ECB_ROTR32 (v, count); }
inline uint64_t ECB_ROTR (uint64_t v, unsigned int count) { return ECB_ROTR64 (v, count); }

#endif

#if ECB_GCC_VERSION(4,3) || (ECB_CLANG_BUILTIN(__builtin_bswap32) && ECB_CLANG_BUILTIN(__builtin_bswap64))
#if ECB_GCC_VERSION(4,8) || ECB_CLANG_BUILTIN(__builtin_bswap16)
#define ECB_BSWAP16(x)  __builtin_bswap16 (x)
#else
#define ECB_BSWAP16(x) (__builtin_bswap32 (x) >> 16)
#endif
#define ECB_BSWAP32(x)  __builtin_bswap32 (x)
#define ECB_BSWAP64(x)  __builtin_bswap64 (x)
#elif _MSC_VER
#include <stdlib.h>
#define ECB_BSWAP16(x) ((uint16_t)_byteswap_ushort ((uint16_t)(x)))
#define ECB_BSWAP32(x) ((uint32_t)_byteswap_ulong  ((uint32_t)(x)))
#define ECB_BSWAP64(x) ((uint64_t)_byteswap_uint64 ((uint64_t)(x)))
#else
ECB_FUNCTION_ ECB_CONST uint16_t ECB_BSWAP16 (uint16_t x);
    ECB_FUNCTION_ ECB_CONST uint16_t
ECB_BSWAP16 (uint16_t x)
{
    return ECB_ROTL16 (x, 8);
}

ECB_FUNCTION_ ECB_CONST uint32_t ECB_BSWAP32 (uint32_t x);
    ECB_FUNCTION_ ECB_CONST uint32_t
ECB_BSWAP32 (uint32_t x)
{
    return (((uint32_t)ECB_BSWAP16 (x)) << 16) | ECB_BSWAP16 (x >> 16);
}

ECB_FUNCTION_ ECB_CONST uint64_t ECB_BSWAP64 (uint64_t x);
    ECB_FUNCTION_ ECB_CONST uint64_t
ECB_BSWAP64 (uint64_t x)
{
    return (((uint64_t)ECB_BSWAP32 (x)) << 32) | ECB_BSWAP32 (x >> 32);
}
#endif

#if ECB_GCC_VERSION(4,5) || ECB_CLANG_BUILTIN(__builtin_unreachable)
#define ECB_UNREACHABLE() __builtin_unreachable ()
#else
/* this seems to work fine, but gcc always emits a warning for it :/ */
ECB_INLINE ECB_NORETURN void ECB_UNREACHABLE (void);
ECB_INLINE ECB_NORETURN void ECB_UNREACHABLE (void) { }
#endif

/* try to tell the compiler that some condition is definitely true */
#define ECB_ASSUME(cond) if (!(cond)) ECB_UNREACHABLE (); else 0

ECB_INLINE ECB_CONST uint32_t ECB_BYTEORDER_HELPER (void);
    ECB_INLINE ECB_CONST uint32_t
ECB_BYTEORDER_HELPER (void)
{
    /* the union code still generates code under pressure in gcc, */
    /* but less than using pointers, and always seems to */
    /* successfully return a constant. */
    /* the reason why we have this horrible preprocessor mess */
    /* is to avoid it in all cases, at least on common architectures */
    /* or when using a recent enough gcc version (>= 4.6) */
#if (defined __BYTE_ORDER__ && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) \
    || ((__i386 || __i386__ || _M_IX86 || ECB_GCC_AMD64 || ECB_MSVC_AMD64) && !__VOS__)
#define ECB_LITTLE_ENDIAN 1
    return 0x44332211;
#elif (defined __BYTE_ORDER__ && __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__) \
    || ((__AARCH64EB__ || __MIPSEB__ || __ARMEB__) && !__VOS__)
#define ECB_BIG_ENDIAN 1
    return 0x11223344;
#else
    union
    {
        uint8_t c[4];
        uint32_t u;
    } u = { 0x11, 0x22, 0x33, 0x44 };
    return u.u;
#endif
}

ECB_INLINE ECB_CONST ecb_bool ECB_BIG_ENDIAN    (void);
ECB_INLINE ECB_CONST ecb_bool ECB_BIG_ENDIAN    (void) { return ECB_BYTEORDER_HELPER () == 0x11223344; }
ECB_INLINE ECB_CONST ecb_bool ECB_LITTLE_ENDIAN (void);
ECB_INLINE ECB_CONST ecb_bool ECB_LITTLE_ENDIAN (void) { return ECB_BYTEORDER_HELPER () == 0x44332211; }

/*****************************************************************************/
/* unaligned load/store */

ECB_INLINE uint_fast16_t ECB_BE_U16_TO_HOST (uint_fast16_t v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP16 (v) : v; }
ECB_INLINE uint_fast32_t ECB_BE_U32_TO_HOST (uint_fast32_t v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP32 (v) : v; }
ECB_INLINE uint_fast64_t ECB_BE_U64_TO_HOST (uint_fast64_t v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP64 (v) : v; }

ECB_INLINE uint_fast16_t ECB_LE_U16_TO_HOST (uint_fast16_t v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP16 (v) : v; }
ECB_INLINE uint_fast32_t ECB_LE_U32_TO_HOST (uint_fast32_t v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP32 (v) : v; }
ECB_INLINE uint_fast64_t ECB_LE_U64_TO_HOST (uint_fast64_t v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP64 (v) : v; }

ECB_INLINE uint_fast16_t ECB_PEEK_U16_U (const void *ptr) { uint16_t v; memcpy (&v, ptr, sizeof (v)); return v; }
ECB_INLINE uint_fast32_t ECB_PEEK_U32_U (const void *ptr) { uint32_t v; memcpy (&v, ptr, sizeof (v)); return v; }
ECB_INLINE uint_fast64_t ECB_PEEK_U64_U (const void *ptr) { uint64_t v; memcpy (&v, ptr, sizeof (v)); return v; }

ECB_INLINE uint_fast16_t ECB_PEEK_BE_U16_U (const void *ptr) { return ECB_BE_U16_TO_HOST (ecb_peek_u16_u (ptr)); }
ECB_INLINE uint_fast32_t ECB_PEEK_BE_U32_U (const void *ptr) { return ECB_BE_U32_TO_HOST (ecb_peek_u32_u (ptr)); }
ECB_INLINE uint_fast64_t ECB_PEEK_BE_U64_U (const void *ptr) { return ECB_BE_U64_TO_HOST (ecb_peek_u64_u (ptr)); }

ECB_INLINE uint_fast16_t ECB_PEEK_LE_U16_U (const void *ptr) { return ECB_LE_U16_TO_HOST (ECB_PEEK_U16_U (ptr)); }
ECB_INLINE uint_fast32_t ECB_PEEK_LE_U32_U (const void *ptr) { return ECB_LE_U32_TO_HOST (ECB_PEEK_U32_U (ptr)); }
ECB_INLINE uint_fast64_t ECB_PEEK_LE_U64_U (const void *ptr) { return ECB_LE_U64_TO_HOST (ECB_PEEK_U64_U (ptr)); }

ECB_INLINE uint_fast16_t ECB_HOST_TO_BE_U16 (uint_fast16_t v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP16 (v) : v; }
ECB_INLINE uint_fast32_t ECB_HOST_TO_BE_U32 (uint_fast32_t v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP32 (v) : v; }
ECB_INLINE uint_fast64_t ECB_HOST_TO_BE_U64 (uint_fast64_t v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP64 (v) : v; }

ECB_INLINE uint_fast16_t ECB_HOST_TO_LE_U16 (uint_fast16_t v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP16 (v) : v; }
ECB_INLINE uint_fast32_t ECB_HOST_TO_LE_U32 (uint_fast32_t v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP32 (v) : v; }
ECB_INLINE uint_fast64_t ECB_HOST_TO_LE_U64 (uint_fast64_t v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP64 (v) : v; }

ECB_INLINE void ECB_POKE_U16_U (void *ptr, uint16_t v) { memcpy (ptr, &v, sizeof (v)); }
ECB_INLINE void ECB_POKE_U32_U (void *ptr, uint32_t v) { memcpy (ptr, &v, sizeof (v)); }
ECB_INLINE void ECB_POKE_U64_U (void *ptr, uint64_t v) { memcpy (ptr, &v, sizeof (v)); }

ECB_INLINE void ECB_POKE_BE_U16_U (void *ptr, uint_fast16_t v) { ECB_POKE_U16_U (ptr, ECB_HOST_TO_BE_U16 (v)); }
ECB_INLINE void ECB_POKE_BE_U32_U (void *ptr, uint_fast32_t v) { ECB_POKE_U32_U (ptr, ECB_HOST_TO_BE_U32 (v)); }
ECB_INLINE void ECB_POKE_BE_U64_U (void *ptr, uint_fast64_t v) { ECB_POKE_U64_U (ptr, ECB_HOST_TO_BE_U64 (v)); }

ECB_INLINE void ECB_POKE_LE_U16_U (void *ptr, uint_fast16_t v) { ECB_POKE_U16_U (ptr, ECB_HOST_TO_LE_U16 (v)); }
ECB_INLINE void ECB_POKE_LE_U32_U (void *ptr, uint_fast32_t v) { ECB_POKE_U32_U (ptr, ECB_HOST_TO_LE_U32 (v)); }
ECB_INLINE void ECB_POKE_LE_U64_U (void *ptr, uint_fast64_t v) { ECB_POKE_U64_U (ptr, ECB_HOST_TO_LE_U64 (v)); }

#if ECB_CPP

inline uint8_t  ECB_BSWAP (uint8_t  v) { return v; }
inline uint16_t ECB_BSWAP (uint16_t v) { return ECB_BSWAP16 (v); }
inline uint32_t ECB_BSWAP (uint32_t v) { return ECB_BSWAP32 (v); }
inline uint64_t ECB_BSWAP (uint64_t v) { return ECB_BSWAP64 (v); }

template<typename T> inline T ECB_BE_TO_HOST (T v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP (v) : v; }
template<typename T> inline T ECB_LE_TO_HOST (T v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP (v) : v; }
template<typename T> inline T ECB_PEEK       (const void *ptr) { return *(const T *)ptr; }
template<typename T> inline T ECB_PEEK_BE    (const void *ptr) { return ECB_BE_TO_HOST (ECB_PEEK  <T> (ptr)); }
template<typename T> inline T ECB_PEEK_LE    (const void *ptr) { return ECB_LE_TO_HOST (ECB_PEEK  <T> (ptr)); }
template<typename T> inline T ECB_PEEK_U     (const void *ptr) { T v; memcpy (&v, ptr, sizeof (v)); return v; }
template<typename T> inline T ECB_PEEK_BE_U  (const void *ptr) { return ECB_BE_TO_HOST (ECB_PEEK_U<T> (ptr)); }
template<typename T> inline T ECB_PEEK_LE_U  (const void *ptr) { return ECB_LE_TO_HOST (ECB_PEEK_U<T> (ptr)); }

template<typename T> inline T ECB_HOST_TO_BE (T v) { return ECB_LITTLE_ENDIAN () ? ECB_BSWAP (v) : v; }
template<typename T> inline T ECB_HOST_TO_LE (T v) { return ECB_BIG_ENDIAN    () ? ECB_BSWAP (v) : v; }
template<typename T> inline void ECB_POKE      (void *ptr, T v) { *(T *)ptr = v; }
template<typename T> inline void ECB_POKE_BE   (void *ptr, T v) { return ECB_POKE  <T> (ptr, ECB_HOST_TO_BE (v)); }
template<typename T> inline void ECB_POKE_LE   (void *ptr, T v) { return ECB_POKE  <T> (ptr, ECB_HOST_TO_LE (v)); }
template<typename T> inline void ECB_POKE_U    (void *ptr, T v) { memcpy (ptr, &v, sizeof (v)); }
template<typename T> inline void ECB_POKE_BE_U (void *ptr, T v) { return ECB_POKE_U<T> (ptr, ECB_HOST_TO_BE (v)); }
template<typename T> inline void ECB_POKE_LE_U (void *ptr, T v) { return ECB_POKE_U<T> (ptr, ECB_HOST_TO_LE (v)); }

#endif

/*****************************************************************************/
/* pointer/integer hashing */

/* based on hash by Chris Wellons, https://nullprogram.com/blog/2018/07/31/ */
ECB_FUNCTION_ uint32_t ECB_MIX32 (uint32_t v);
ECB_FUNCTION_ uint32_t ECB_MIX32 (uint32_t v)
{
    v ^= v >> 16; v *= 0x7feb352dU;
    v ^= v >> 15; v *= 0x846ca68bU;
    v ^= v >> 16;
    return v;
}

ECB_FUNCTION_ uint32_t ECB_UNMIX32 (uint32_t v);
ECB_FUNCTION_ uint32_t ECB_UNMIX32 (uint32_t v)
{
    v ^= v >> 16          ; v *= 0x43021123U;
    v ^= v >> 15 ^ v >> 30; v *= 0x1d69e2a5U;
    v ^= v >> 16          ;
    return v;
}

/* based on splitmix64, by Sebastiona Vigna, https://prng.di.unimi.it/splitmix64.c */
ECB_FUNCTION_ uint64_t ECB_MIX64 (uint64_t v);
ECB_FUNCTION_ uint64_t ECB_MIX64 (uint64_t v)
{
    v ^= v >> 30; v *= 0xbf58476d1ce4e5b9U;
    v ^= v >> 27; v *= 0x94d049bb133111ebU;
    v ^= v >> 31;
    return v;
}

ECB_FUNCTION_ uint64_t ECB_UNMIX64 (uint64_t v);
ECB_FUNCTION_ uint64_t ECB_UNMIX64 (uint64_t v)
{
    v ^= v >> 31 ^ v >> 62; v *= 0x319642b2d24d8ec3U;
    v ^= v >> 27 ^ v >> 54; v *= 0x96de1b173f119089U;
    v ^= v >> 30 ^ v >> 60;
    return v;
}

ECB_FUNCTION_ uintptr_t ECB_PTRMIX (void *p);
ECB_FUNCTION_ uintptr_t ECB_PTRMIX (void *p)
{
#if ECB_PTRSIZE <= 4
    return ECB_MIX32 ((uint32_t)p);
#else
    return ECB_MIX64 ((uint64_t)p);
#endif
}

ECB_FUNCTION_ void *ECB_PTRUNMIX (uintptr_t v);
ECB_FUNCTION_ void *ECB_PTRUNMIX (uintptr_t v)
{
#if ECB_PTRSIZE <= 4
    return (void *)ECB_UNMIX32 (v);
#else
    return (void *)ECB_UNMIX64 (v);
#endif
}

#if ECB_CPP

    template<typename T>
inline uintptr_t ECB_PTRMIX (T *p)
{
    return ECB_PTRMIX (static_cast<void *>(p));
}

    template<typename T>
inline T *ECB_PTRUNMIX (uintptr_t v)
{
    return static_cast<T *>(ECB_PTRUNMIX (v));
}

#endif

/*****************************************************************************/
/* division */

#if ECB_GCC_VERSION(3,0) || ECB_C99
/* C99 tightened the definition of %, so we can use a more efficient version */
#define ECB_MOD(m,n) ((m) % (n) + ((m) % (n) < 0 ? (n) : 0))
#else
#define ECB_MOD(m,n) ((m) < 0 ? ((n) - 1 - ((-1 - (m)) % (n))) : ((m) % (n)))
#endif

#if ECB_CPP
    template<typename T>
static inline T ECB_DIV_RD (T val, T div)
{
    return val < 0 ? - ((-val + div - 1) / div) : (val          ) / div;
}
    template<typename T>
static inline T ECB_DIV_RU (T val, T div)
{
    return val < 0 ? - ((-val          ) / div) : (val + div - 1) / div;
}
#else
#define ECB_DIV_RD(val,div) ((val) < 0 ? - ((-(val) + (div) - 1) / (div)) : ((val)            ) / (div))
#define ECB_DIV_RU(val,div) ((val) < 0 ? - ((-(val)            ) / (div)) : ((val) + (div) - 1) / (div))
#endif

/*****************************************************************************/
/* array length */

#if ecb_cplusplus_does_not_suck
/* does not work for local types (http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2657.htm) */
    template<typename T, int N>
static inline int ECB_ARRAY_LENGTH (const T (&arr)[N])
{
    return N;
}
#else
#define ECB_ARRAY_LENGTH(name) (sizeof (name) / sizeof (name [0]))
#endif

/*****************************************************************************/
/* IEEE 754-2008 half float conversions */

ECB_FUNCTION_ ECB_CONST uint32_t ECB_BINARY16_TO_BINARY32 (uint32_t x);
    ECB_FUNCTION_ ECB_CONST uint32_t
ECB_BINARY16_TO_BINARY32 (uint32_t x)
{
    unsigned int s = (x & 0x8000) << (31 - 15);
    int          e = (x >> 10) & 0x001f;
    unsigned int m =  x        & 0x03ff;

    if (ECB_EXPECT_FALSE (e == 31))
        /* infinity or NaN */
        e = 255 - (127 - 15);
    else if (ECB_EXPECT_FALSE (!e))
    {
        if (ECB_EXPECT_TRUE (!m))
            /* zero, handled by code below by forcing e to 0 */
            e = 0 - (127 - 15);
        else
        {
            /* subnormal, renormalise */
            unsigned int s = 10 - ECB_LD32 (m);

            m = (m << s) & 0x3ff; /* mask implicit bit */
            e -= s - 1;
        }
    }

    /* e and m now are normalised, or zero, (or inf or nan) */
    e += 127 - 15;

    return s | (e << 23) | (m << (23 - 10));
}

ECB_FUNCTION_ ECB_CONST uint16_t ECB_BINARY32_TO_BINARY16 (uint32_t x);
    ECB_FUNCTION_ ECB_CONST uint16_t
ECB_BINARY32_TO_BINARY16 (uint32_t x)
{
    unsigned int s =  (x >> 16) & 0x00008000; /* sign bit, the easy part */
    int          e = ((x >> 23) & 0x000000ff) - (127 - 15); /* the desired exponent */
    unsigned int m =   x        & 0x007fffff;

    x &= 0x7fffffff;

    /* if it's within range of binary16 normals, use fast path */
    if (ECB_EXPECT_TRUE (0x38800000 <= x && x <= 0x477fefff))
    {
        /* mantissa round-to-even */
        m += 0x00000fff + ((m >> (23 - 10)) & 1);

        /* handle overflow */
        if (ECB_EXPECT_FALSE (m >= 0x00800000))
        {
            m >>= 1;
            e +=  1;
        }

        return s | (e << 10) | (m >> (23 - 10));
    }

    /* handle large numbers and infinity */
    if (ECB_EXPECT_TRUE (0x477fefff < x && x <= 0x7f800000))
        return s | 0x7c00;

    /* handle zero, subnormals and small numbers */
    if (ECB_EXPECT_TRUE (x < 0x38800000))
    {
        /* zero */
        if (ECB_EXPECT_TRUE (!x))
            return s;

        /* handle subnormals */

        /* too small, will be zero */
        if (e < (14 - 24)) /* might not be sharp, but is good enough */
            return s;

        m |= 0x00800000; /* make implicit bit explicit */

        /* very tricky - we need to round to the nearest e (+10) bit value */
        {
            unsigned int bits = 14 - e;
            unsigned int half = (1 << (bits - 1)) - 1;
            unsigned int even = (m >> bits) & 1;

            /* if this overflows, we will end up with a normalised number */
            m = (m + half + even) >> bits;
        }

        return s | m;
    }

    /* handle NaNs, preserve leftmost nan bits, but make sure we don't turn them into infinities */
    m >>= 13;

    return s | 0x7c00 | m | !m;
}

/*******************************************************************************/
/* fast integer to ascii */

/*
 * This code is pretty complicated because it is general. The idea behind it,
 * however, is pretty simple: first, the number is multiplied with a scaling
 * factor (2**bits / 10**(digits-1)) to convert the integer into a fixed-point
 * number with the first digit in the upper bits.
 * Then this digit is converted to text and masked out. The resulting number
 * is then multiplied by 10, by multiplying the fixed point representation
 * by 5 and shifting the (binary) decimal point one to the right, so a 4.28
 * format becomes 5.27, 6.26 and so on.
 * The rest involves only advancing the pointer if we already generated a
 * non-zero digit, so leading zeroes are overwritten.
 */

/* simply return a mask with "bits" bits set */
#define ECB_I2A_MASK(type,bits) ((((type)1) << (bits)) - 1)

/* oputput a single digit. maskvalue is 10**digitidx */
#define ECB_I2A_DIGIT(type,bits,digitmask,maskvalue,digitidx) \
    if (digitmask >= maskvalue) /* constant, used to decide how many digits to generate */ \
{ \
    char digit = x >> (bits - digitidx); /* calculate the topmost digit */ \
    *ptr = digit + '0'; /* output it */ \
    nz = (digitmask == maskvalue) || nz || digit; /* first term == always output last digit */ \
    ptr += nz; /* output digit only if non-zero digit seen */ \
    x = (x & ECB_I2A_MASK (type, bits - digitidx)) * 5; /* *10, but shift decimal point right */ \
}

/* convert integer to fixed point format and multiply out digits, highest first */
/* requires magic constants: max. digits and number of bits after the decimal point */
#define ECB_I2A_DEF(suffix,ptr,v,type,bits,digitmask,lz) \
    ECB_INLINE char *ECB_I2A_ ## suffix (char *ptr, uint32_t u) \
{ \
    char nz = lz; /* non-zero digit seen? */ \
    /* convert to x.bits fixed-point */ \
    type x = u * ((ECB_I2A_MASK (type, bits) + digitmask) / digitmask); \
    /* output up to 10 digits */ \
    ECB_I2A_DIGIT (type,bits,digitmask,          1, 0); \
    ECB_I2A_DIGIT (type,bits,digitmask,         10, 1); \
    ECB_I2A_DIGIT (type,bits,digitmask,        100, 2); \
    ECB_I2A_DIGIT (type,bits,digitmask,       1000, 3); \
    ECB_I2A_DIGIT (type,bits,digitmask,      10000, 4); \
    ECB_I2A_DIGIT (type,bits,digitmask,     100000, 5); \
    ECB_I2A_DIGIT (type,bits,digitmask,    1000000, 6); \
    ECB_I2A_DIGIT (type,bits,digitmask,   10000000, 7); \
    ECB_I2A_DIGIT (type,bits,digitmask,  100000000, 8); \
    ECB_I2A_DIGIT (type,bits,digitmask, 1000000000, 9); \
    return ptr; \
}

/* predefined versions of the above, for various digits */
/* ecb_i2a_xN = almost N digits, limit defined by macro */
/* ecb_i2a_N = up to N digits, leading zeroes suppressed */
/* ecb_i2a_0N = exactly N digits, including leading zeroes */

/* non-leading-zero versions, limited range */
#define ECB_I2A_MAX_X5       59074 /* limit for ecb_i2a_x5 */
#define ECB_I2A_MAX_X10 2932500665 /* limit for ecb_i2a_x10 */
    ECB_I2A_DEF ( x5, ptr, v, uint32_t, 26,      10000, 0)
ECB_I2A_DEF (x10, ptr, v, uint64_t, 60, 1000000000, 0)

    /* non-leading zero versions, all digits, 4 and 9 are optimal for 32/64 bit */
    ECB_I2A_DEF ( 2, ptr, v, uint32_t, 10,          10, 0)
    ECB_I2A_DEF ( 3, ptr, v, uint32_t, 12,         100, 0)
    ECB_I2A_DEF ( 4, ptr, v, uint32_t, 26,        1000, 0)
    ECB_I2A_DEF ( 5, ptr, v, uint64_t, 30,       10000, 0)
    ECB_I2A_DEF ( 6, ptr, v, uint64_t, 36,      100000, 0)
    ECB_I2A_DEF ( 7, ptr, v, uint64_t, 44,     1000000, 0)
    ECB_I2A_DEF ( 8, ptr, v, uint64_t, 50,    10000000, 0)
ECB_I2A_DEF ( 9, ptr, v, uint64_t, 56,   100000000, 0)

    /* leading-zero versions, all digits, 04 and 09 are optimal for 32/64 bit */
    ECB_I2A_DEF (02, ptr, v, uint32_t, 10,          10, 1)
    ECB_I2A_DEF (03, ptr, v, uint32_t, 12,         100, 1)
    ECB_I2A_DEF (04, ptr, v, uint32_t, 26,        1000, 1)
    ECB_I2A_DEF (05, ptr, v, uint64_t, 30,       10000, 1)
    ECB_I2A_DEF (06, ptr, v, uint64_t, 36,      100000, 1)
    ECB_I2A_DEF (07, ptr, v, uint64_t, 44,     1000000, 1)
    ECB_I2A_DEF (08, ptr, v, uint64_t, 50,    10000000, 1)
ECB_I2A_DEF (09, ptr, v, uint64_t, 56,   100000000, 1)

#define ECB_I2A_I32_DIGITS 11
#define ECB_I2A_U32_DIGITS 10
#define ECB_I2A_I64_DIGITS 20
#define ECB_I2A_U64_DIGITS 21
#define ECB_I2A_MAX_DIGITS 21

    ECB_INLINE char *
ECB_I2A_U32 (char *ptr, uint32_t u)
{
#if ECB_64BIT_NATIVE
    if (ECB_EXPECT_TRUE (u <= ECB_I2A_MAX_X10))
        ptr = ECB_I2A_X10 (ptr, u);
    else /* x10 almost, but not fully, covers 32 bit */
    {
        uint32_t u1 = u % 1000000000;
        uint32_t u2 = u / 1000000000;

        *ptr++ = u2 + '0';
        ptr = ECB_I2A_09 (ptr, u1);
    }
#else
    if (ECB_EXPECT_TRUE (u <= ECB_I2A_MAX_X5))
        ECB_I2A_X5 (ptr, u);
    else if (ECB_EXPECT_TRUE (u <= ECB_I2A_MAX_X5 * 10000))
    {
        uint32_t u1 = u % 10000;
        uint32_t u2 = u / 10000;

        ptr = ECB_I2A_X5 (ptr, u2);
        ptr = ECB_I2A_04 (ptr, u1);
    }
    else
    {
        uint32_t u1 = u  % 10000;
        uint32_t ua = u  / 10000;
        uint32_t u2 = ua % 10000;
        uint32_t u3 = ua / 10000;

        ptr = ECB_I2A_2  (ptr, u3);
        ptr = ECB_I2A_04 (ptr, u2);
        ptr = ECB_I2A_04 (ptr, u1);
    }
#endif

    return ptr;
}

    ECB_INLINE char *
ECB_I2A_I32 (char *ptr, int32_t v)
{
    *ptr = '-'; ptr += v < 0;
    uint32_t u = v < 0 ? -(uint32_t)v : v;

#if ECB_64BIT_NATIVE
    ptr = ECB_I2A_X10 (ptr, u); /* x10 fully covers 31 bit */
#else
    ptr = ECB_I2A_U32 (ptr, u);
#endif

    return ptr;
}

    ECB_INLINE char *
ECB_I2A_U64 (char *ptr, uint64_t u)
{
#if ECB_64BIT_NATIVE
    if (ECB_EXPECT_TRUE (u <= ECB_I2A_MAX_X10))
        ptr = ECB_I2A_X10 (ptr, u);
    else if (ECB_EXPECT_FALSE (u <= ECB_I2A_MAX_X10 * 1000000000))
    {
        uint64_t u1 = u % 1000000000;
        uint64_t u2 = u / 1000000000;

        ptr = ECB_I2A_X10 (ptr, u2);
        ptr = ECB_I2A_09  (ptr, u1);
    }
    else
    {
        uint64_t u1 = u  % 1000000000;
        uint64_t ua = u  / 1000000000;
        uint64_t u2 = ua % 1000000000;
        uint64_t u3 = ua / 1000000000;

        ptr = ECB_I2A_2  (ptr, u3);
        ptr = ECB_I2A_09 (ptr, u2);
        ptr = ECB_I2A_09 (ptr, u1);
    }
#else
    if (ECB_EXPECT_TRUE (u <= ECB_I2A_MAX_X5))
        ptr = ECB_I2A_X5 (ptr, u);
    else
    {
        uint64_t u1 = u % 10000;
        uint64_t u2 = u / 10000;

        ptr = ECB_I2A_U64 (ptr, u2);
        ptr = ECB_I2A_04 (ptr, u1);
    }
#endif

    return ptr;
}

    ECB_INLINE char *
ECB_I2A_I64 (char *ptr, int64_t v)
{
    *ptr = '-'; ptr += v < 0;
    uint64_t u = v < 0 ? -(uint64_t)v : v;

#if ECB_64BIT_NATIVE
    if (ECB_EXPECT_TRUE (u <= ECB_I2A_MAX_X10))
        ptr = ECB_I2A_X10 (ptr, u);
    else if (ECB_EXPECT_FALSE (u <= ECB_I2A_MAX_X10 * 1000000000))
    {
        uint64_t u1 = u % 1000000000;
        uint64_t u2 = u / 1000000000;

        ptr = ECB_I2A_X10 (ptr, u2);
        ptr = ECB_I2A_09  (ptr, u1);
    }
    else
    {
        uint64_t u1 = u  % 1000000000;
        uint64_t ua = u  / 1000000000;
        uint64_t u2 = ua % 1000000000;
        uint64_t u3 = ua / 1000000000;

        /* 2**31 is 19 digits, so the top is exactly one digit */
        *ptr++ = u3 + '0';
        ptr = ECB_I2A_09 (ptr, u2);
        ptr = ECB_I2A_09 (ptr, u1);
    }
#else
    ptr = ECB_I2A_U64 (ptr, u);
#endif

    return ptr;
}

/*******************************************************************************/
/* floating point stuff, can be disabled by defining ECB_NO_LIBM */

/* basically, everything uses "ieee pure-endian" floating point numbers */
/* the only noteworthy exception is ancient armle, which uses order 43218765 */
#if 0 \
    || __i386 || __i386__ \
    || ECB_GCC_AMD64 \
    || __powerpc__ || __ppc__ || __powerpc64__ || __ppc64__ \
    || defined __s390__ || defined __s390x__ \
    || defined __mips__ \
    || defined __alpha__ \
    || defined __hppa__ \
    || defined __ia64__ \
    || defined __m68k__ \
    || defined __m88k__ \
    || defined __sh__ \
    || defined _M_IX86 || defined ECB_MSVC_AMD64 || defined _M_IA64 \
    || (defined __arm__ && (defined __ARM_EABI__ || defined __EABI__ || defined __VFP_FP__ || defined _WIN32_WCE || defined __ANDROID__)) \
    || defined __aarch64__
#define ECB_STDFP 1
#else
#define ECB_STDFP 0
#endif

#ifndef ECB_NO_LIBM

#include <math.h> /* for frexp*, ldexp*, INFINITY, NAN */

/* only the oldest of old doesn't have this one. solaris. */
#ifdef INFINITY
#define ECB_INFINITY INFINITY
#else
#define ECB_INFINITY HUGE_VAL
#endif

#ifdef NAN
#define ECB_NAN NAN
#else
#define ECB_NAN ECB_INFINITY
#endif

#if ECB_C99 || _XOPEN_VERSION >= 600 || _POSIX_VERSION >= 200112L
#define ECB_LDEXPF(x,e) ldexpf ((x), (e))
#define ECB_FREXPF(x,e) frexpf ((x), (e))
#else
#define ECB_LDEXPF(x,e) (float) ldexp ((double) (x), (e))
#define ECB_FREXPF(x,e) (float) frexp ((double) (x), (e))
#endif

/* convert a float to ieee single/binary32 */
ECB_FUNCTION_ ECB_CONST uint32_t ECB_FLOAT_TO_BINARY32 (float x);
    ECB_FUNCTION_ ECB_CONST uint32_t
ECB_FLOAT_TO_BINARY32 (float x)
{
    uint32_t r;

#if ECB_STDFP
    memcpy (&r, &x, 4);
#else
    /* slow emulation, works for anything but -0 */
    uint32_t m;
    int e;

    if (x == 0e0f                    ) return 0x00000000U;
    if (x > +3.40282346638528860e+38f) return 0x7f800000U;
    if (x < -3.40282346638528860e+38f) return 0xff800000U;
    if (x != x                       ) return 0x7fbfffffU;

    m = ECB_FREXPF (x, &e) * 0x1000000U;

    r = m & 0x80000000U;

    if (r)
        m = -m;

    if (e <= -126)
    {
        m &= 0xffffffU;
        m >>= (-125 - e);
        e = -126;
    }

    r |= (e + 126) << 23;
    r |= m & 0x7fffffU;
#endif

    return r;
}

/* converts an ieee single/binary32 to a float */
ECB_FUNCTION_ ECB_CONST float ecb_binary32_to_float (uint32_t x);
    ECB_FUNCTION_ ECB_CONST float
ECB_BINARY32_TO_FLOAT (uint32_t x)
{
    float r;

#if ECB_STDFP
    memcpy (&r, &x, 4);
#else
    /* emulation, only works for normals and subnormals and +0 */
    int neg = x >> 31;
    int e = (x >> 23) & 0xffU;

    x &= 0x7fffffU;

    if (e)
        x |= 0x800000U;
    else
        e = 1;

    /* we distrust ldexpf a bit and do the 2**-24 scaling by an extra multiply */
    r = ECB_LDEXPF (x * (0.5f / 0x800000U), e - 126);

    r = neg ? -r : r;
#endif

    return r;
}

/* convert a double to ieee double/binary64 */
ECB_FUNCTION_ ECB_CONST uint64_t ECB_DOUBLE_TO_BINARY64 (double x);
    ECB_FUNCTION_ ECB_CONST uint64_t
ECB_DOUBLE_TO_BINARY64 (double x)
{
    uint64_t r;

#if ECB_STDFP
    memcpy (&r, &x, 8);
#else
    /* slow emulation, works for anything but -0 */
    uint64_t m;
    int e;

    if (x == 0e0                     ) return 0x0000000000000000U;
    if (x > +1.79769313486231470e+308) return 0x7ff0000000000000U;
    if (x < -1.79769313486231470e+308) return 0xfff0000000000000U;
    if (x != x                       ) return 0X7ff7ffffffffffffU;

    m = frexp (x, &e) * 0x20000000000000U;

    r = m & 0x8000000000000000;;

    if (r)
        m = -m;

    if (e <= -1022)
    {
        m &= 0x1fffffffffffffU;
        m >>= (-1021 - e);
        e = -1022;
    }

    r |= ((uint64_t)(e + 1022)) << 52;
    r |= m & 0xfffffffffffffU;
#endif

    return r;
}

/* converts an ieee double/binary64 to a double */
ECB_FUNCTION_ ECB_CONST double ECB_BINARY64_TO_DOUBLE (uint64_t x);
    ECB_FUNCTION_ ECB_CONST double
ECB_BINARY64_TO_DOUBLE (uint64_t x)
{
    double r;

#if ECB_STDFP
    memcpy (&r, &x, 8);
#else
    /* emulation, only works for normals and subnormals and +0 */
    int neg = x >> 63;
    int e = (x >> 52) & 0x7ffU;

    x &= 0xfffffffffffffU;

    if (e)
        x |= 0x10000000000000U;
    else
        e = 1;

    /* we distrust ldexp a bit and do the 2**-53 scaling by an extra multiply */
    r = ldexp (x * (0.5 / 0x10000000000000U), e - 1022);

    r = neg ? -r : r;
#endif

    return r;
}

/* convert a float to ieee half/binary16 */
ECB_FUNCTION_ ECB_CONST uint16_t ECB_FLOAT_TO_BINARY16 (float x);
    ECB_FUNCTION_ ECB_CONST uint16_t
ecb_float_to_binary16 (float x)
{
    return ecb_binary32_to_binary16 (ECB_FLOAT_TO_BINARY32 (x));
}

/* convert an ieee half/binary16 to float */
ECB_FUNCTION_ ECB_CONST float ECB_BINARY16_TO_FLOAT (uint16_t x);
    ECB_FUNCTION_ ECB_CONST float
ECB_BINARY16_TO_FLOAT (uint16_t x)
{
    return ECB_BINARY32_TO_FLOAT (ECB_BINARY16_TO_BINARY32 (x));
}

#endif

#include "_ecb.h"

#endif

