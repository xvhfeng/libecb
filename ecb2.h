#ifndef ECB2_H
#define ECB2_H

#include "ecb.h"

#define GCC_VERSION ecb2_decltype(i32)(__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if GCC_VERSION >= 70000 && !defined(__CHECKER__)
#define __nobrk __attribute__((fallthrough))
#endif

#if GCC_VERSION >= 40300
#define __compiletime_error(message) \
    __attribute__((error(message)))
#else
#define __compiletime_error(message)
#endif /* GCC_VERSION >= 40300 */

/**
 * alias for all integer
 *
 * type declaring in ecb.h so it must exist now.
 *
 */
typedef int8_t i8;
typedef uint8_t u8;
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;
typedef float f32;
typedef double f64;

/**
 * a pointer address expressed as an unsigned/signed integer
 * then it can convert to pointer
 */
typedef uintptr_t uptr;
typedef intptr_t iptr;

/**
 * generic object pointer
 */
typedef char *gptr;

/**
 * declare return-type or define type for macro
 * it have not practical means
 * maybe "type" is typeof(expr) if expr without negative consequence
 * or String if expr have negative consequence(expl:macro parameter)
 */
#ifndef ecb2_decltype
#define ecb2_decltype(type)
#endif

/**
 *
 * 提醒程序员“此可变参数函数需要一个NULL作为最后一个参数。
 *
 */
#define ecb2_endnil ecb_attribute((sentinel))

/**
 * memory aligned by alloc
 */
#define ECB2_ALIGNEDSIZE ECB_PTRSIZE

#define ECB2_BitsCntOfByte 8
#define ECB2_BitsCntOfSHORT 16
#define ECB2_BitsCntOfI32 32
#define ECB2_BitsCntOfI64 64

#define ECB2_U16MAX ((0XFF) & (~0U))
#define ECB2_I16MAX ((0XFF) & (U16_MAX >> 1))
#define ECB2_I16MIN ((0XFF) & (-I16_MAX - 1))
#define ECB2_I32MAX ((i32)(~0U >> 1))
#define ECB2_I32MIN (-I32_MAX - 1)
#define ECB2_U32MAX (~0U)
#define ECB2_I64MAX ((u64)(~0ULL >> 1))
#define ECB2_I64MIN (-LLONG_MAX - 1)
#define ECB2_U64MAX (~0ULL)

#define ECB2_TBOFGB (1024)
#define ECB2_TBOFMB (1024 * 1024)
#define ECB2_TBOFKB (1024 * 1024 * 1024)
#define ECB2_TBOFB (1024 * 1024 * 1024 * 1024)
#define ECB2_GBOFMB (1024)
#define ECB2_GBOFKB (1024 * 1024)
#define ECB2_GBOFB (1024 * 1024 * 1024)
#define ECB2_MBOFKB (1024)
#define ECB2_MBOFB (1024 * 1024)
#define ECB2_KBOFB (1024)

#define ECB2_MINOFSEC (60)
#define ECB2_HOUROFSEC (60 * 60)
#define ECB2_DAYOFSEC (24 * 60 *60)
#define ECB2_HOUROFMIN (60)
#define ECB2_DAYOFMIN (24 * 60)
#define ECB2_HOUROFDAY (24)
#define ECB2_MSTOSEC (1000)
#define ECB2_NSTOSEC ( 1000 * 1000)
#define ECB2_NSTOMS ( 1000)

#ifndef null
#define null NULL
#endif

#ifndef nil
#define nil NULL
#endif

#define ECB2_STRLOC __FILE__ ":" ECB_STRINGIFY(__LINE__)

#define ecb2_retry_when_err(e) (EAGAIN == (e) || EWOULDBLOCK == (e) || EINTR == (e))
#define ecb2_retry_if_err(e,expr) if(ecb2_retry_when_err(e)) { expr; continue;}
#define ecb2_close(fd) ecb2_dorang(ecb2_if(likely(!ecb2_is0(fd)),{close(fd);fd = 0;}));

/* *
 * placeholder for argument or expr
 * */
#define ecb2_anyval
#define ecb2_anyexpr ;

#define ecb2_isnil(n) (NULL == (n))
#define ecb2_is0(n) (0 == (n))

#define ecb2_abs(n) ({ __typeof__(n) _n = (n); 0 >= _n ? _n : (0 - _n) })
#define ecb2_min(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a < _b ? _a : _b; })
#define ecb2_max(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a > _b ? _a : _b; })
#define ecb2_tabs(t, n) ({ t _n = (n); 0 <= _n ? _n : (0 - _n) })
#define ecb2_tmin(t, a, b) ({t _a = (a), t _b = (b); _a < _b ? _a : _b; })
#define ecb2_tmax(t, a, b) ({t _a = (a); t _b = (b); _a > _b ? _a : _b; })

/**
 * memory pointer operator
 * return value is count by byte
 **/
#define ecb2_padd(p, off) ecb2_decltype(gptr)(((gptr)p) + off)
#define ecb2_psub(p, off) ecb2_decltype(gptr)(((gptr)p) - off)
#define ecb2_pdiff(lp, rp) ecb2_decltype(i32)(((gptr)lp) - ((gptr)rp))
#define ecb2_npdiff(lp, rp) ecb2_decltype(u32) ecb2_abs(((gptr)lp) - ((gptr)rp))

/**
 *  aligned by memory
 * op=4 base=8 then rtn=8
 **/
#define ecb2_align(op, base) ({       \
        typeof(op) op1 = (op);            \
        typeof(base) b2 = (base);         \
        ((op1 + (b2 - 1)) & (~(b2 - 1))); \
        })

/**
 * aligned by base then calculate count of base
 *
 */
#define ecb2_numbsof(op, base) ({ \
        typeof(base) b2 = (base);     \
        (ecb2_align(op, b2) / b2);    \
        })

#define ecb2_malign(op) ecb2_decltype(i32) ecb2_align(op, ECB2_ALIGNEDSIZE)
#define ecb2_mnumbsof(op) ecb2_decltype(i32) ecb2_numbsof(op, ECB2_ALIGNEDSIZE)

/**
 * macro function style to shortcut calls ,
 * they are mainly used to save annoying if statements,
 * especially it with only one or two fixed assignments  statements or return statements
 *
 * For so many years, the solution to kill annoying braces turned out to be macro functions
 */
#define ecb2_setnil(p) (p) == nuil
#define ecb2_if(cond, expr)    if (ecb_expect_true(cond)) { expr; }
#define ecb2_iif(cond, texpr, fexpr) \
    if(ecb_expect_true(cond)) {texpr;}else{fexpr;}
#define ecb2_if_rtn(cond, rtnval)  ecb2_if((cond), { return (rtnval); })
#define ecb2_iif_rtn(cond, tval, fval)  ecb2_iif((cond), { return tval; }, { return fval; })
#define ecb2_if_exprtn(cond, expr, rtnval)  ecb2_if(cond, {expr;return rtnval; })
#define ecb2_iif_exprtn(cond, texpr, tval, fexpr, fval)  ecb2_iif(cond, {texpr;return tval; }, {fexpr;return fval; })
#define ecb2_setrtn(rc, err, rtnval)  { rc = err;return rtnval; }
#define ecb2_if_setrtn(cond, rc, err, rtnval) ecb2_if(cond, ecb2_setrtn(rc, err, rtnval))
#define ecb2_if_set(cond, name, val)  ecb2_if(cond, { name = (val); })
#define ecb2_if_brk(cond) ecb2_if(cond, break)
#define ecb2_if_next(cond) ecb2_if(cond, continue)
#define ecb2_if_goto(cond, lbl) ecb2_if(cond, { goto lbl; })
#define ecb2_if_exprbrk(cond) ecb2_if(cond, {expr; break;})
#define ecb2_if_exprnext(cond) ecb2_if(cond, { expr; continue; })
#define ecb2_if_exprgoto(cond, lbl) ecb2_if(cond, { expr; goto lbl; })
#define ecb2_if_set(cond, name, rval)  ecb2_if(cond, name = rval)
#define ecb2_iif_set(cond, name, tval, fval) ((name) = (cond) ? (tval) : (fval))
#define ecb2_dowhile0(expr) do { expr;} while(0)

/*
 * lambda for c
 * this is not ANSI C
 * and implemented with c extensions in GCC (maybe not support by Clang)
 * use: ecb2_lambda(int,(int x, int y),{ return x + y; })(1,1)
 */
#define ecb2_lambda(_rtntype__, _args__, _body__) \
    ({ _rtntype__ __anon__ _args__ _body__ __anon__; })

#define ecb2_mset(ptr, v, len) memset((ptr), (v), (len))
#define ecb2_bzero(ptr, len) ecb2_mset((ptr), 0, (len))

#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr)-offsetof(type, member)))
#endif

#ifndef offsetof
#define offsetof(type, member) ((size_t) & (((type *)0)->member))
#endif

/*
 * container_of is too long to hard coding
 * so decl a key-mapping
 */
#ifndef ecb2_fieldof
#define ecb2_fieldof(ptr, type, member) container_of(ptr, type, member)
#endif

/**
 * convert function
 *
 */
#define ecb2_chgto(type, n, v) (type) n = (type)(v)
#define ecb2_chgtoptr(typep, n, v) (type *)n = (type *)(v)

#define ecb2_free(ptr) ecb2_if(likely(!ecb2_isnil(ptr)),{free(prt); ptr = nil;})

typedef union  { i32 ival; f32 fval; } ecb2_fci;
typedef union  { i64 ival; f64 fval; } ecb2_dcl;
#define ecb2_ftoi(valf) ({ ecb2_fci fi = {.fval = (valf)}; fi.ival; })
#define ecb2_itof(vali) ({ ecb2_fci fi = {.ival = (vali)}; fi.fval; })
#define ecb2_dtol(valf) ({ ecb2_dcl fi = {.fval = (valf)}; fi.ival; })
#define ecb2_ltod(vali) ({ ecb2_dcl fi = {.ival = (vali)}; fi.fval; })

#define ecb2_mbr() __asm__ __volatile__("":::"memory")
#define ecb2_mbrp(ptr) __asm__ __volatile__(""::"r"(ptr):"memory")

/**
 * read memory once
 * then keep load from memory not cache
 */
static __inline void ecb2_mread(const volatile void *p,
        void *res,
        int size) { /*{{{*/
    switch (size)
    {
        case 1:
            *(u8 *)res = *(volatile u8 *)p;
            break;
        case 2:
            *(u16 *)res = *(volatile u16 *)p;
            break;
        case 4:
            *(u32 *)res = *(volatile u32 *)p;
            break;
        case 8:
            *(u64 *)res = *(volatile u64 *)p;
            break;
        default:
            ecb2_mbr();
            __builtin_memcpy((void *)res,
                    (const void *)p,
                    size);
            ecb2_mbr();
    }
} /*}}}*/

/**
 * write memory once
 * then keep write to memory not cache
 */
static __inline void ecb2_mwrite(volatile void *p,
        void *res,
        int size) { /*{{{*/
    switch (size)
    {
        case 1:
            *(volatile u8 *)p = *(u8 *)res;
            break;
        case 2:
            *(volatile u16 *)p = *(u16 *)res;
            break;
        case 4:
            *(volatile u32 *)p = *(u32 *)res;
            break;
        case 8:
            *(volatile u64 *)p = *(u64 *)res;
            break;
        default:
            ecb2_mbr();
            __builtin_memcpy((void *)p,
                    (const void *)res,
                    size);
            ecb2_mbr();
    }
} /*}}}*/

#define ecb2_mustread(x)                                \
    ({                                              \
     union                                       \
     {                                           \
     typeof(x) __val;                        \
     char __c[1];                            \
     } __u = {.__c = {0}};                       \
     ecb2_mread(&(x), __u.__c, sizeof(x)); \
     __u.__val;                                  \
     })

#define ecb2_mustwrite(x, val)                           \
    ({                                               \
     union                                        \
     {                                            \
     typeof(x) __val;                         \
     char __c[1];                             \
     } __u = {.__val = (val)};                    \
     ecb2_mwrite(&(x), __u.__c, sizeof(x)); \
     __u.__val;                                   \
     })


/*
 * Following functions are taken from kernel sources and
 * break aliasing rules in their original form.
 *
 * While kernel is compiled with -fno-strict-aliasing,
 * perf uses -Wstrict-aliasing=3 which makes build fail
 * under gcc 4.4.
 *
 * Using extra __may_alias__ type to allow aliasing
 * in this case.
 */

#define ecb2_bitset(x, pos) ((x) |= (1 << (pos)))
#define ecb2_bitget(x, pos) ({ int loc_pos = pos; (((x) & (1 << loc_pos)) >> loc_pos); })
#define ecb2_bitclr(x, pos) ((x) &= ~(1 << (pos)))

#define ecb2_bitget_r(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        ((loc_x & (1 << pos_r)) >> pos_r);                    \
        })

#define ecb2_bitclr_r(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        (loc_x &= ~(1 << pos_r));                           \
        })

#define ecb2_bitset_r(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        (loc_x |= (1 << pos_r));                            \
        })

/**
 * right move x with 32bits/64bits(5/6 times)
 * return integer value from (x / 32/64)
 *
 */
#define ecb2_shift32_r(x) ((x) >> 0x05)
#define ecb2_shift64_r(x) ((x) >> 0x06)

/*
 * generate mark bit in begin(b)-end(e) range
 * markN,N is 8,16,32 or 64 then range is 1->8,1->16,1->32,1->64 one by one
 */
#define ecb2_genmark8(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFF >> (loc_b)) << (loc_b))  & ~((0xFF >> (loc_e)) << (loc_e)));})
#define ecb2_genmark16(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFF >> (loc_e)) << (loc_e)));})
#define ecb2_genmark32(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFFFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFFFFFF >> (loc_e)) << (loc_e)));})
#define ecb2_genmark64(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFFFFFFFFFFFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFFFFFFFFFFFFFF >> (loc_e)) << (loc_e)));})

#define ecb2_genunmark8(b,e) ({ (0xFF & (~ecb2_genmark8(b,e))); })
#define ecb2_genunmark16(b,e) ({ (0xFFFF & (~ecb2_genmark16(b,e))); })
#define ecb2_genunmark32(b,e) ({ (0xFFFFFFFF & (~ecb2_genmark32(b,e))); })
#define ecb2_genunmark64(b,e) ({ (0xFFFFFFFFFFFFFFFF &(~ecb2_genmark64(b,e))); })

#define ecb2_genmark8_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfByte - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfByte - (e);\
        ecb2_genmark8(loc_rb,loc_re); })
#define ecb2_genmark16_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfSHORT - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfSHORT - (e);\
        ecb2_genmark16(loc_rb,loc_re); })
#define ecb2_genmark32_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfI32 - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfI32 - (e);\
        ecb2_genmark32(loc_rb,loc_re); })
#define ecb2_genmark64_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfI64 - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfI64 - (e);\
        ecb2_genmark64(loc_rb,loc_re); })

#define ecb2_genunmark8_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfByte - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfByte - (e);\
        ecb2_genunmark8(loc_rb,loc_re); })
#define ecb2_genunmark16_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfSHORT - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfSHORT - (e);\
        ecb2_genunmark16(loc_rb,loc_re); })
#define ecb2_genunmark32_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfI32 - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfI32 - (e);\
        ecb2_genunmark32(loc_rb,loc_re); })
#define ecb2_genunmark64_r(b,e) ({ \
        typeof(b) loc_re = ECB2_BitsCntOfI64 - (b); \
        typeof(e) loc_rb = ECB2_BitsCntOfI64 - (e);\
        ecb2_genunmark64(loc_rb,loc_re); })

#define ecb2_mark8(x,b,e) ((x) | ecb2_genmark8(b,e))
#define ecb2_mark16(x,b,e) ((x) | ecb2_genmark16(b,e))
#define ecb2_mark32(x,b,e) ((x) | ecb2_genmark32(b,e))
#define ecb2_mark64(x,b,e) ((x) | ecb2_genmark64(b,e))
#define ecb2_mark8_r(x,b,e) ((x) | ecb2_genmark8_r(b,e))
#define ecb2_mark16_r(x,b,e) ((x) | ecb2_genmark16_r(b,e))
#define ecb2_mark32_r(x,b,e) ((x) | ecb2_genmark32_r(b,e))
#define ecb2_mark64_r(x,b,e) ((x) | ecb2_genmark64_r(b,e))

#define ecb2_unmark8(x,b,e) ((x) & ecb2_genunmark8(b,e))
#define ecb2_unmark16(x,b,e) ((x) & ecb2_genunmark16(b,e))
#define ecb2_unmark32(x,b,e) ((x) & ecb2_genunmark32(b,e))
#define ecb2_unmark64(x,b,e) ((x) & ecb2_genunmark64(b,e))
#define ecb2_unmark8_r(x,b,e) ((x) & ecb2_genunmark8_r(b,e))
#define ecb2_unmark16_r(x,b,e) ((x) & ecb2_genunmark16_r(b,e))
#define ecb2_unmark32_r(x,b,e) ((x) & ecb2_genunmark32_r(b,e))
#define ecb2_unmark64_r(x,b,e) ((x) & ecb2_genunmark64_r(b,e))

/**
 * find first pos of marking
 * pos range is (7...0)
 */
ecb_inline int ecb2_ffmark8(u8 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = ECB2_BitsCntOfByte;
    ecb2_if((0x0F & x), {x &= 0x0F;pos -=  4;});
    ecb2_if_rtn((0x11 & x), pos - 4);
    ecb2_if_rtn((0x22 & x), pos - 3);
    ecb2_if_rtn((0x44 & x), pso - 2);
    ecb2_if_rtn((0x88 & x), pos - 1);
    return -1;
}/*}}}*/
ecb_inline int ecb2_ffmark16(u16 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = ECB2_BitsCntOfSHORT;
    ecb2_if((0xFF & x), {x &= 0xFF; pos -= ECB2_BitsCntOfByte;});
    ecb2_if((0x0F0F & x), { x &= 0x0F0F; pos -= 4;});
    ecb2_if_rtn((x & 0x1111), pos - 4);
    ecb2_if_rtn((x & 0x2222), pos - 3);
    ecb2_if_rtn((x & 0x4444), pso - 2);
    ecb2_if_rtn((x & 0x8888), pos - 1);
    return -1;
}/*}}}*/
ecb_inline int ecb2_ffmark32(u32 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = ECB2_BitsCntOfI32;
    ecb2_if((0xFFFF & x), { x &= 0xFFFF;pos -= ECB2_BitsCntOfSHORT;});
    ecb2_if((0xFF00FF & x), {x &= 0xFF00FF; pos -= ECB2_BitsCntOfByte;});
    ecb2_if((0x0F0F0F0F & x), { x &= 0x0F0F0F0F; pos -= 4;});
    ecb2_if_rtn((x & 0x11111111), pos - 4);
    ecb2_if_rtn((x & 0x22222222), pos - 3);
    ecb2_if_rtn((x & 0x44444444), pso - 2);
    ecb2_if_rtn((x & 0x88888888), pos - 1);
    return -1;
}/*}}}*/
ecb_inline int ecb2_ffmark64(u64 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = ECB2_BitsCntOfI64;
    ecb2_if((0xFFFFFFFF & x), { x &= 0xFFFFFFFF;pos -= ECB2_BitsCntOfI32;});
    ecb2_if((0xFFFF0000FFFF & x), { x &= 0xFFFF0000FFFF;pos -= ECB2_BitsCntOfSHORT;});
    ecb2_if((0xFF00FF00FF00FF00FF00FF00FF00FF & x), {x &= 0xFF00FF00FF00FF00FF00FF00FF00FF; pos -= ECB2_BitsCntOfByte;});
    ecb2_if((0x0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F & x), { x &= 0x0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F0F; pos -= 4;});
    ecb2_if_rtn((x & 0x1111111111111111), pos - 4);
    ecb2_if_rtn((x & 0x2222222222222222), pos - 3);
    ecb2_if_rtn((x & 0x4444444444444444), pso - 2);
    ecb2_if_rtn((x & 0x8888888888888888), pos - 1);
    return -1;
}/*}}}*/

/**
 * reverse find first pos of marking
 * pos range is (0...7)
 */
ecb_inline int ecb2_ffmark8_r(u8 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb2_if(ecb2_is0(0xF0 & x), {x &= 0x0F;pos +=  4;});
    ecb2_if_rtn((0x88 & x), pos);
    ecb2_if_rtn((0x44 & x), pso + 1);
    ecb2_if_rtn((0x22 & x), pos + 2);
    ecb2_if_rtn((0x11 & x), pos + 3);
    return -1;
}/*}}}*/
ecb_inline int ecb2_ffmark16_r(u16 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb2_if(ecb2_is0(0xFF00 & x), {x &= 0xFF00; pos += ECB2_BitsCntOfByte;});
    ecb2_if(ecb2_is0(0xF0F0 & x), {x &= 0xF0F0;pos +=  4;});
    ecb2_if_rtn((0x8888 & x), pos);
    ecb2_if_rtn((0x4444 & x), pso + 1);
    ecb2_if_rtn((0x2222 & x), pos + 2);
    ecb2_if_rtn((0x1111 & x), pos + 3);
    return -1;
}/*}}}*/
ecb_inline int ecb2_ffmark32_r(u32 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb2_if(ecb2_is0(0xFFFF0000 & x), {x &= 0xFFFF0000; pos += ECB2_BitsCntOfSHORT;});
    ecb2_if(ecb2_is0(0xFF00FF00 & x), {x &= 0xFF00FF00; pos += ECB2_BitsCntOfByte;});
    ecb2_if(ecb2_is0(0xF0F0F0F0 & x), {x &= 0xF0F0F0F0;pos +=  4;});
    ecb2_if_rtn((0x88888888 & x), pos);
    ecb2_if_rtn((0x44444444 & x), pso + 1);
    ecb2_if_rtn((0x22222222 & x), pos + 2);
    ecb2_if_rtn((0x11111111 & x), pos + 3);
    return -1;
}/*}}}*/
ecb_inline int ecb2_ffmark64_r(u64 x) {/*{{{*/
    ecb2_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb2_if(ecb2_is0(0xFFFFFFFF00000000 & x), { x &= 0xFFFFFFFF00000000;pos += ECB2_BitsCntOfI32;});
    ecb2_if(ecb2_is0(0xFFFF0000FFFF0000 & x), { x &= 0xFFFF0000FFFF0000;pos += ECB2_BitsCntOfSHORT;});
    ecb2_if(ecb2_is0(0xFF00FF00FF00FF00 & x), { x &= 0xFF00FF00FF00FF00;pos += ECB2_BitsCntOfByte;});
    ecb2_if(ecb2_is0(0xF0F0F0F0F0F0F0F0 & x), { x &= 0xF0F0F0F0F0F0F0F0; pos += 4;});
    ecb2_if_rtn((0x8888888888888888 & x), pos);
    ecb2_if_rtn((0x4444444444444444 & x), pso + 1);
    ecb2_if_rtn((0x2222222222222222 & x), pos + 2);
    ecb2_if_rtn((0x1111111111111111 & x), pos + 3);
    return -1;
}/*}}}*/

#define ecb2_ffunmark8(x) ecb2_ffmark8(~(x))
#define ecb2_ffunmark16(x) ecb2_ffmark16(~(x))
#define ecb2_ffunmark32(x) ecb2_ffmark32(~(x))
#define ecb2_ffunmark64(x) ecb2_ffmark64(~(x))
#define ecb2_ffunmark8_r(x) ecb2_ffmark8_r(~(x))
#define ecb2_ffunmark16_r(x) ecb2_ffmark16_r(~(x))
#define ecb2_ffunmark32_r(x) ecb2_ffmark32_r(~(x))
#define ecb2_ffunmark64_r(x) ecb2_ffmark64_r(~(x))


ecb_inline void ecb2_packi8(gptr b,const i8 n) {/*{{{*/
    *b++ = (n & 0xff);
}/*}}}*/
ecb_inline void ecb2_packi16(gptr b,const i16 n) {/*{{{*/
    *b++ = ( n >> 8 ) & 0xFF;
    *b++ = ( n & 0xFF );
}/*}}}*/
ecb_inline void ecb2_packi32(gptr b,const i32 n){/*{{{*/
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = n & 0xFF;
}/*}}}*/
ecb_inline void ecb2_packi64(gptr b,const i64 n){/*{{{*/
    *b++ = (n >> 56) & 0xFF;
    *b++ = (n >> 48) & 0xFF;
    *b++ = (n >> 40) & 0xFF;
    *b++ = (n >> 32) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = n & 0xFF;
}/*}}}*/
ecb_inline void ecb2_packf32(gptr b,const f32 n) {/*{{{*/
    i32 val = ecb2_ftoi(n);
    ecb2_packi32(b,val);
}/*}}}*/
ecb_inline void ecb2_packf64(gptr b,const f64 n) {/*{{{*/
    i64 val = ecb2_dtol(n);
    ecb2_pack64(b,val);
}/*}}}*/

ecb_inline i8 ecb2_unpacki8(gptr b) {/*{{{*/
    return (i8) (*b & 0xFF);
}/*}}}*/
ecb_inline i16 ecb2_unpacki16(gptr b) {/*{{{*/
    return (i16) ((((*b) & 0xFF) << 8 )
            | ((*(b + 1)) & 0xFF));
}/*}}}*/
ecb_inline i32 ecb2_unpacki32(gptr b) {/*{{{*/
    return (i32) ((((*b) & 0xFF) << 24 )
            |((*(b + 1) & 0xFF) << 16 )
            |((*(b + 2) & 0xFF) << 8 )
            | ((*(b + 3)) & 0xFF));
}/*}}}*/
ecb_inline i64 ecb2_unpacki64(gptr b) {/*{{{*/
    return (i64) ((((*b) & 0xFF) << 56 )
            |((*(b + 1) & 0xFF) << 48 )
            |((*(b + 2) & 0xFF) << 40 )
            |((*(b + 3) & 0xFF) << 32 )
            |((*(b + 4) & 0xFF) << 24 )
            |((*(b + 5) & 0xFF) << 16 )
            |((*(b + 6) & 0xFF) << 8 )
            | ((*(b + 3)) & 0xFF));
}/*}}}*/
ecb_inline f32 ecb2_unpackf32(gptr b) {/*{{{*/
    i32 val = ecb2_unpacki32(b);
    return ecb2_itof(val);
}/*}}}*/
ecb_inline f64 ecb2_unpacki64(gptr b) {/*{{{*/
    i64 val = ecb2_unpacki64(b);
    return ecb2_ltod(val);
}/*}}}*/

ecb_inline void ecb2_packi16_le(gptr b,const i16 n) {/*{{{*/
    *b++ = ( n & 0xFF );
    *b++ = ( n >> 8 ) & 0xFF;
}/*}}}*/
ecb_inline void ecb2_packi32_le(gptr b,const i32 n) {/*{{{*/
    *b++ = n & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
}/*}}}*/
ecb_inline void ecb2_packi64_le(gptr b,const i64 n){/*{{{*/
    *b++ = n & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 32) & 0xFF;
    *b++ = (n >> 40) & 0xFF;
    *b++ = (n >> 48) & 0xFF;
    *b++ = (n >> 56) & 0xFF;
}/*}}}*/
ecb_inline void ecb2_packf32_le(gptr b,const f32 n){/*{{{*/
    i32 val = ecb2_ftoi(n);
    ecb2_packi32_le(b,val);
}/*}}}*/
ecb_inline void ecb2_packf64_le(gptr b,const f64 n) {/*{{{*/
    i64 val = ecb2_dtol(n);
    ecb2_pack64_le(b,val);
}/*}}}*/

ecb_inline i16 ecb2_unpacki16_le(gptr b) {/*{{{*/
    return (i16) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8));
}/*}}}*/
ecb_inline i32 ecb2_unpacki32_le(gptr b) {/*{{{*/
    return (i32) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8)
            | (((*(b + 2)) & 0xFF) << 16)
            | (((*(b + 3)) & 0xFF) << 24));
}/*}}}*/
ecb_inline i64 ecb2_unpacki64_le(gptr b) {/*{{{*/
    return (i64) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8)
            | (((*(b + 2)) & 0xFF) << 16)
            | (((*(b + 3)) & 0xFF) << 24)
            | (((*(b + 4)) & 0xFF) << 32)
            | (((*(b + 5)) & 0xFF) << 40)
            | (((*(b + 6)) & 0xFF) << 48)
            | (((*(b + 7)) & 0xFF) << 56));
}/*}}}*/
ecb_inline f32 ecb2_unpackf32_le(gptr b) {/*{{{*/
    i32 val = ecb2_unpacki32_le(b);
    return ecb2_itof(val);
}/*}}}*/
ecb_inline f64 ecb2_unpacki64_le(gptr b) {/*{{{*/
    i64 val = ecb2_unpacki64_le(b);
    return ecb2_ltod(val);
}/*}}}*/

#endif
