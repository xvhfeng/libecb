#ifndef ECB_INTERNAL_H
#define ECB_INTERNAL_H

#define GCC_VERSION ecb_decltype(i32)(__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

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
#ifndef ecb_decltype
#define ecb_decltype(type)
#endif

/**
 *
 * 提醒程序员“此可变参数函数需要一个NULL作为最后一个参数。
 *
 */
#define ecb_endnil ecb_attribute((sentinel))

/**
 * memory aligned by alloc
 */
#define ECB_ALIGNEDSIZE ECB_PTRSIZE

#define ECB_BitsCntOfByte 8
#define ECB_BitsCntOfSHORT 16
#define ECB_BitsCntOfI32 32
#define ECB_BitsCntOfI64 64

#define ECB_U16MAX ((0XFF) & (~0U))
#define ECB_I16MAX ((0XFF) & (U16_MAX >> 1))
#define ECB_I16MIN ((0XFF) & (-I16_MAX - 1))
#define ECB_I32MAX ((i32)(~0U >> 1))
#define ECB_I32MIN (-I32_MAX - 1)
#define ECB_U32MAX (~0U)
#define ECB_I64MAX ((u64)(~0ULL >> 1))
#define ECB_I64MIN (-LLONG_MAX - 1)
#define ECB_U64MAX (~0ULL)

#define ECB_TBOFGB (1024)
#define ECB_TBOFMB (1024 * 1024)
#define ECB_TBOFKB (1024 * 1024 * 1024)
#define ECB_TBOFB (1024 * 1024 * 1024 * 1024)
#define ECB_GBOFMB (1024)
#define ECB_GBOFKB (1024 * 1024)
#define ECB_GBOFB (1024 * 1024 * 1024)
#define ECB_MBOFKB (1024)
#define ECB_MBOFB (1024 * 1024)
#define ECB_KBOFB (1024)

#define ECB_MINOFSEC (60)
#define ECB_HOUROFSEC (60 * 60)
#define ECB_DAYOFSEC (24 * 60 *60)
#define ECB_HOUROFMIN (60)
#define ECB_DAYOFMIN (24 * 60)
#define ECB_HOUROFDAY (24)
#define ECB_MSTOSEC (1000)
#define ECB_NSTOSEC ( 1000 * 1000)
#define ECB_NSTOMS ( 1000)

#ifndef null
#define null NULL
#endif

#ifndef nil
#define nil NULL
#endif

#define ECB_STRLOC __FILE__ ":" ECB_STRINGIFY(__LINE__)

#define ecb_retry_when_err(e) (EAGAIN == (e) || EWOULDBLOCK == (e) || EINTR == (e))
#define ecb_retry_if_err(e,expr) if(ecb_retry_when_err(e)) { expr; continue;}
#define ecb_close(fd) ecb_dowhile(ecb_if(likely(!ecb_is0(fd)),{close(fd);fd = 0;}));

/* *
 * placeholder for argument or expr
 * */
#define ecb_anyval
#define ecb_anyexpr ;

#define ecb_isnil(n) (NULL == (n))
#define ecb_is0(n) (0 == (n))

#define ecb_abs(n) ({ __typeof__(n) _n = (n); 0 >= _n ? _n : (0 - _n) })
#define ecb_min(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a < _b ? _a : _b; })
#define ecb_max(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a > _b ? _a : _b; })
#define ecb_tabs(t, n) ({ t _n = (n); 0 <= _n ? _n : (0 - _n) })
#define ecb_tmin(t, a, b) ({t _a = (a), t _b = (b); _a < _b ? _a : _b; })
#define ecb_tmax(t, a, b) ({t _a = (a); t _b = (b); _a > _b ? _a : _b; })

/**
 * memory pointer operator
 * return value is count by byte
 **/
#define ecb_padd(p, off) ecb_decltype(gptr)(((gptr)p) + off)
#define ecb_psub(p, off) ecb_decltype(gptr)(((gptr)p) - off)
#define ecb_pdiff(lp, rp) ecb_decltype(i32)(((gptr)lp) - ((gptr)rp))
#define ecb_npdiff(lp, rp) ecb_decltype(u32) ecb_abs(((gptr)lp) - ((gptr)rp))

/**
 *  aligned by memory
 * op=4 base=8 then rtn=8
 **/
#define ecb_align(op, base) ({       \
        typeof(op) op1 = (op);            \
        typeof(base) b2 = (base);         \
        ((op1 + (b2 - 1)) & (~(b2 - 1))); \
        })

/**
 * aligned by base then calculate count of base
 *
 */
#define ecb_numbsof(op, base) ({ \
        typeof(base) b2 = (base);     \
        (ecb_align(op, b2) / b2);    \
        })

#define ecb_malign(op) ecb_decltype(i32) ecb_align(op, ECB_ALIGNEDSIZE)
#define ecb_mnumbsof(op) ecb_decltype(i32) ecb_numbsof(op, ECB_ALIGNEDSIZE)

/**
 * macro function style to shortcut calls ,
 * they are mainly used to save annoying if statements,
 * especially it with only one or two fixed assignments  statements or return statements
 *
 * For so many years, the solution to kill annoying braces turned out to be macro functions
 */
#define ecb_setnil(p) (p) == nuil
#define ecb_if(cond, expr)    if (ecb_expect_true(cond)) { expr; }
#define ecb_iif(cond, t_expr, f_expr) \
    if(ecb_expect_true(cond)) {t_expr;}else{f_expr;}
#define ecb_if_rtn(cond, rc)  ecb_if((cond), { return (rc); })
#define ecb_iif_rtn(cond, t_rc, f_rc)  ecb_iif((cond), { return t_rc; }, { return f_rc; })
#define ecb_if_exprtn(cond, expr, rc)  ecb_if(cond, {expr;return rc; })
#define ecb_iif_exprtn(cond, t_expr, t_rc, f_expr, f_rc)  ecb_iif(cond, {t_expr;return t_rc; }, {f_expr;return f_rc; })
#define ecb_setrtn(rc, err, rc)  { rc = err;return rc; }
#define ecb_if_setrtn(cond, rc, err, rc) ecb_if(cond, ecb_setrtn(rc, err, rc))
#define ecb_if_set(cond, name, val)  ecb_if(cond, { name = (val); })
#define ecb_if_brk(cond) ecb_if(cond, break)
#define ecb_if_next(cond) ecb_if(cond, continue)
#define ecb_if_goto(cond, lbl) ecb_if(cond, { goto lbl; })
#define ecb_if_exprbrk(cond) ecb_if(cond, {expr; break;})
#define ecb_if_exprnext(cond) ecb_if(cond, { expr; continue; })
#define ecb_if_exprgoto(cond, lbl) ecb_if(cond, { expr; goto lbl; })
#define ecb_iif_set(cond, name, t_rc, f_rc) ((name) = (cond) ? (t_rc) : (f_rc))
#define ecb_dowhile(expr) do { expr;} while(0)

/*
 * lambda for c
 * this is not ANSI C
 * and implemented with c extensions in GCC (maybe not support by Clang)
 * use: ecb_lambda(int,(int x, int y),{ return x + y; })(1,1)
 */
#define ecb_lambda(_rtntype__, _args__, _body__) \
    ({ _rtntype__ __anon__ _args__ _body__ __anon__; })

#define ecb_mset(ptr, v, len) memset((ptr), (v), (len))
#define ecb_bzero(ptr, len) ecb_mset((ptr), 0, (len))

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
#ifndef ecb_fieldof
#define ecb_fieldof(ptr, type, member) container_of(ptr, type, member)
#endif

/**
 * convert function
 *
 */
#define ecb_chgto(type, n, v) (type) n = (type)(v)
#define ecb_chgtoptr(typep, n, v) (type *)n = (type *)(v)

#define ecb_free(ptr) ecb_if(likely(!ecb_isnil(ptr)),{free(prt); ptr = nil;})

typedef union  { i32 ival; f32 fval; } ecb_fci;
typedef union  { i64 ival; f64 fval; } ecb_dcl;
#define ecb_ftoi(valf) ({ ecb_fci fi = {.fval = (valf)}; fi.ival; })
#define ecb_itof(vali) ({ ecb_fci fi = {.ival = (vali)}; fi.fval; })
#define ecb_dtol(valf) ({ ecb_dcl fi = {.fval = (valf)}; fi.ival; })
#define ecb_ltod(vali) ({ ecb_dcl fi = {.ival = (vali)}; fi.fval; })

#define ecb_mbr() __asm__ __volatile__("":::"memory")
#define ecb_mbrp(ptr) __asm__ __volatile__(""::"r"(ptr):"memory")
#define ecb_readonce(v)  (*(volatile typeof(v) *)&(v))


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

#define ecb_bitset(x, pos) ((x) |= (1 << (pos)))
#define ecb_bitget(x, pos) ({ int loc_pos = pos; (((x) & (1 << loc_pos)) >> loc_pos); })
#define ecb_bitclr(x, pos) ((x) &= ~(1 << (pos)))

#define ecb_bitget_r(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        ((loc_x & (1 << pos_r)) >> pos_r);                    \
        })

#define ecb_bitclr_r(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        (loc_x &= ~(1 << pos_r));                           \
        })

#define ecb_bitset_r(x, pos_r) ({                    \
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
#define ecb_shift32_r(x) ((x) >> 0x05)
#define ecb_shift64_r(x) ((x) >> 0x06)

/*
 * generate mark bit in begin(b)-end(e) range
 * markN,N is 8,16,32 or 64 then range is 1->8,1->16,1->32,1->64 one by one
 */
#define ecb_genmark8(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFF >> (loc_b)) << (loc_b))  & ~((0xFF >> (loc_e)) << (loc_e)));})
#define ecb_genmark16(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFF >> (loc_e)) << (loc_e)));})
#define ecb_genmark32(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFFFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFFFFFF >> (loc_e)) << (loc_e)));})
#define ecb_genmark64(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFFFFFFFFFFFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFFFFFFFFFFFFFF >> (loc_e)) << (loc_e)));})

#define ecb_genunmark8(b,e) ({ (0xFF & (~ecb_genmark8(b,e))); })
#define ecb_genunmark16(b,e) ({ (0xFFFF & (~ecb_genmark16(b,e))); })
#define ecb_genunmark32(b,e) ({ (0xFFFFFFFF & (~ecb_genmark32(b,e))); })
#define ecb_genunmark64(b,e) ({ (0xFFFFFFFFFFFFFFFF &(~ecb_genmark64(b,e))); })

#define ecb_genmark8_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfByte - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfByte - (e);\
        ecb_genmark8(loc_rb,loc_re); })
#define ecb_genmark16_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfSHORT - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfSHORT - (e);\
        ecb_genmark16(loc_rb,loc_re); })
#define ecb_genmark32_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI32 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI32 - (e);\
        ecb_genmark32(loc_rb,loc_re); })
#define ecb_genmark64_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI64 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI64 - (e);\
        ecb_genmark64(loc_rb,loc_re); })

#define ecb_genunmark8_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfByte - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfByte - (e);\
        ecb_genunmark8(loc_rb,loc_re); })
#define ecb_genunmark16_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfSHORT - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfSHORT - (e);\
        ecb_genunmark16(loc_rb,loc_re); })
#define ecb_genunmark32_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI32 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI32 - (e);\
        ecb_genunmark32(loc_rb,loc_re); })
#define ecb_genunmark64_r(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI64 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI64 - (e);\
        ecb_genunmark64(loc_rb,loc_re); })

#define ecb_mark8(x,b,e) ((x) | ecb_genmark8(b,e))
#define ecb_mark16(x,b,e) ((x) | ecb_genmark16(b,e))
#define ecb_mark32(x,b,e) ((x) | ecb_genmark32(b,e))
#define ecb_mark64(x,b,e) ((x) | ecb_genmark64(b,e))
#define ecb_mark8_r(x,b,e) ((x) | ecb_genmark8_r(b,e))
#define ecb_mark16_r(x,b,e) ((x) | ecb_genmark16_r(b,e))
#define ecb_mark32_r(x,b,e) ((x) | ecb_genmark32_r(b,e))
#define ecb_mark64_r(x,b,e) ((x) | ecb_genmark64_r(b,e))

#define ecb_unmark8(x,b,e) ((x) & ecb_genunmark8(b,e))
#define ecb_unmark16(x,b,e) ((x) & ecb_genunmark16(b,e))
#define ecb_unmark32(x,b,e) ((x) & ecb_genunmark32(b,e))
#define ecb_unmark64(x,b,e) ((x) & ecb_genunmark64(b,e))
#define ecb_unmark8_r(x,b,e) ((x) & ecb_genunmark8_r(b,e))
#define ecb_unmark16_r(x,b,e) ((x) & ecb_genunmark16_r(b,e))
#define ecb_unmark32_r(x,b,e) ((x) & ecb_genunmark32_r(b,e))
#define ecb_unmark64_r(x,b,e) ((x) & ecb_genunmark64_r(b,e))

/**
 * find first pos of marking
 * pos range is (7...0)
 */
ecb_inline int ecb_ffmark8(u8 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = ECB_BitsCntOfByte;
    ecb_if((0x0F & x), {x &= 0x0F;pos -=  4;});
    ecb_if_rtn((0x11 & x), pos - 4);
    ecb_if_rtn((0x22 & x), pos - 3);
    ecb_if_rtn((0x44 & x), pos - 2);
    ecb_if_rtn((0x88 & x), pos - 1);
    return -1;
}/*}}}*/
ecb_inline int ecb_ffmark16(u16 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = ECB_BitsCntOfSHORT;
    ecb_if((0xFF & x), {x &= 0xFF; pos -= ECB_BitsCntOfByte;});
    ecb_if((0x0F0F & x), { x &= 0x0F0F; pos -= 4;});
    ecb_if_rtn((x & 0x1111), pos - 4);
    ecb_if_rtn((x & 0x2222), pos - 3);
    ecb_if_rtn((x & 0x4444), pos - 2);
    ecb_if_rtn((x & 0x8888), pos - 1);
    return -1;
}/*}}}*/
ecb_inline int ecb_ffmark32(u32 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = ECB_BitsCntOfI32;
    ecb_if((0xFFFF & x), { x &= 0xFFFF;pos -= ECB_BitsCntOfSHORT;});
    ecb_if((0xFF00FF & x), {x &= 0xFF00FF; pos -= ECB_BitsCntOfByte;});
    ecb_if((0x0F0F0F0F & x), { x &= 0x0F0F0F0F; pos -= 4;});
    ecb_if_rtn((x & 0x11111111), pos - 4);
    ecb_if_rtn((x & 0x22222222), pos - 3);
    ecb_if_rtn((x & 0x44444444), pos - 2);
    ecb_if_rtn((x & 0x88888888), pos - 1);
    return -1;
}/*}}}*/
ecb_inline int ecb_ffmark64(u64 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = ECB_BitsCntOfI64;
    ecb_if((0xFFFFFFFF & x), { x &= 0xFFFFFFFF;pos -= ECB_BitsCntOfI32;});
    ecb_if((0xFFFF0000FFFF & x), { x &= 0xFFFF0000FFFF;pos -= ECB_BitsCntOfSHORT;});
    ecb_if((0x00FF00FF00FF00FF & x), { x &= 0x00FF00FF00FF00FF; pos -= ECB_BitsCntOfByte;});
    ecb_if((0x0F0F0F0F0F0F0F0F & x), { x &= 0x0F0F0F0F0F0F0F0F; pos -= 4;});
    ecb_if_rtn((x & 0x1111111111111111), pos - 4);
    ecb_if_rtn((x & 0x2222222222222222), pos - 3);
    ecb_if_rtn((x & 0x4444444444444444), pos - 2);
    ecb_if_rtn((x & 0x8888888888888888), pos - 1);
    return -1;
}/*}}}*/

/**
 * reverse find first pos of marking
 * pos range is (0...7)
 */
ecb_inline int ecb_ffmark8_r(u8 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb_if(ecb_is0(0xF0 & x), {x &= 0x0F;pos +=  4;});
    ecb_if_rtn((0x88 & x), pos);
    ecb_if_rtn((0x44 & x), pos + 1);
    ecb_if_rtn((0x22 & x), pos + 2);
    ecb_if_rtn((0x11 & x), pos + 3);
    return -1;
}/*}}}*/
ecb_inline int ecb_ffmark16_r(u16 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb_if(ecb_is0(0xFF00 & x), {x &= 0xFF00; pos += ECB_BitsCntOfByte;});
    ecb_if(ecb_is0(0xF0F0 & x), {x &= 0xF0F0;pos +=  4;});
    ecb_if_rtn((0x8888 & x), pos);
    ecb_if_rtn((0x4444 & x), pos + 1);
    ecb_if_rtn((0x2222 & x), pos + 2);
    ecb_if_rtn((0x1111 & x), pos + 3);
    return -1;
}/*}}}*/
ecb_inline int ecb_ffmark32_r(u32 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb_if(ecb_is0(0xFFFF0000 & x), {x &= 0xFFFF0000; pos += ECB_BitsCntOfSHORT;});
    ecb_if(ecb_is0(0xFF00FF00 & x), {x &= 0xFF00FF00; pos += ECB_BitsCntOfByte;});
    ecb_if(ecb_is0(0xF0F0F0F0 & x), {x &= 0xF0F0F0F0;pos +=  4;});
    ecb_if_rtn((0x88888888 & x), pos);
    ecb_if_rtn((0x44444444 & x), pos + 1);
    ecb_if_rtn((0x22222222 & x), pos + 2);
    ecb_if_rtn((0x11111111 & x), pos + 3);
    return -1;
}/*}}}*/
ecb_inline int ecb_ffmark64_r(u64 x) {/*{{{*/
    ecb_if_rtn( 0 == x,-1);
    int pos = 0;
    ecb_if(ecb_is0(0xFFFFFFFF00000000 & x), { x &= 0xFFFFFFFF00000000;pos += ECB_BitsCntOfI32;});
    ecb_if(ecb_is0(0xFFFF0000FFFF0000 & x), { x &= 0xFFFF0000FFFF0000;pos += ECB_BitsCntOfSHORT;});
    ecb_if(ecb_is0(0xFF00FF00FF00FF00 & x), { x &= 0xFF00FF00FF00FF00;pos += ECB_BitsCntOfByte;});
    ecb_if(ecb_is0(0xF0F0F0F0F0F0F0F0 & x), { x &= 0xF0F0F0F0F0F0F0F0; pos += 4;});
    ecb_if_rtn((0x8888888888888888 & x), pos);
    ecb_if_rtn((0x4444444444444444 & x), pos + 1);
    ecb_if_rtn((0x2222222222222222 & x), pos + 2);
    ecb_if_rtn((0x1111111111111111 & x), pos + 3);
    return -1;
}/*}}}*/

#define ecb_ffunmark8(x) ecb_ffmark8(~(x))
#define ecb_ffunmark16(x) ecb_ffmark16(~(x))
#define ecb_ffunmark32(x) ecb_ffmark32(~(x))
#define ecb_ffunmark64(x) ecb_ffmark64(~(x))
#define ecb_ffunmark8_r(x) ecb_ffmark8_r(~(x))
#define ecb_ffunmark16_r(x) ecb_ffmark16_r(~(x))
#define ecb_ffunmark32_r(x) ecb_ffmark32_r(~(x))
#define ecb_ffunmark64_r(x) ecb_ffmark64_r(~(x))


ecb_inline void ecb_packi8(gptr b,const i8 n) {/*{{{*/
    *b++ = (n & 0xff);
}/*}}}*/
ecb_inline void ecb_packi16(gptr b,const i16 n) {/*{{{*/
    *b++ = ( n >> 8 ) & 0xFF;
    *b++ = ( n & 0xFF );
}/*}}}*/
ecb_inline void ecb_packi32(gptr b,const i32 n){/*{{{*/
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = n & 0xFF;
}/*}}}*/
ecb_inline void ecb_packi64(gptr b,const i64 n){/*{{{*/
    *b++ = (n >> 56) & 0xFF;
    *b++ = (n >> 48) & 0xFF;
    *b++ = (n >> 40) & 0xFF;
    *b++ = (n >> 32) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = n & 0xFF;
}/*}}}*/
ecb_inline void ecb_packf32(gptr b,const f32 n) {/*{{{*/
    i32 val = ecb_ftoi(n);
    ecb_packi32(b,val);
}/*}}}*/
ecb_inline void ecb_packf64(gptr b,const f64 n) {/*{{{*/
    i64 val = ecb_dtol(n);
    ecb_packi64(b,val);
}/*}}}*/

ecb_inline i8 ecb_unpacki8(gptr b) {/*{{{*/
    return (i8) (*b & 0xFF);
}/*}}}*/
ecb_inline i16 ecb_unpacki16(gptr b) {/*{{{*/
    return (i16) ((((*b) & 0xFF) << 8 )
            | ((*(b + 1)) & 0xFF));
}/*}}}*/
ecb_inline i32 ecb_unpacki32(gptr b) {/*{{{*/
    return (i32) ((((*b) & 0xFF) << 24 )
            |((*(b + 1) & 0xFF) << 16 )
            |((*(b + 2) & 0xFF) << 8 )
            | ((*(b + 3)) & 0xFF));
}/*}}}*/
ecb_inline i64 ecb_unpacki64(gptr b) {/*{{{*/
    return (i64) ((((*b) & 0xFF) << 56 )
            |((*(b + 1) & 0xFF) << 48 )
            |((*(b + 2) & 0xFF) << 40 )
            |((*(b + 3) & 0xFF) << 32 )
            |((*(b + 4) & 0xFF) << 24 )
            |((*(b + 5) & 0xFF) << 16 )
            |((*(b + 6) & 0xFF) << 8 )
            | ((*(b + 3)) & 0xFF));
}/*}}}*/
ecb_inline f32 ecb_unpackf32(gptr b) {/*{{{*/
    i32 val = ecb_unpacki32(b);
    return ecb_itof(val);
}/*}}}*/
ecb_inline f64 ecb_unpackf64(gptr b) {/*{{{*/
    i64 val = ecb_unpacki64(b);
    return ecb_ltod(val);
}/*}}}*/

ecb_inline void ecb_packi16_le(gptr b,const i16 n) {/*{{{*/
    *b++ = ( n & 0xFF );
    *b++ = ( n >> 8 ) & 0xFF;
}/*}}}*/
ecb_inline void ecb_packi32_le(gptr b,const i32 n) {/*{{{*/
    *b++ = n & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
}/*}}}*/
ecb_inline void ecb_packi64_le(gptr b,const i64 n){/*{{{*/
    *b++ = n & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 32) & 0xFF;
    *b++ = (n >> 40) & 0xFF;
    *b++ = (n >> 48) & 0xFF;
    *b++ = (n >> 56) & 0xFF;
}/*}}}*/
ecb_inline void ecb_packf32_le(gptr b,const f32 n){/*{{{*/
    i32 val = ecb_ftoi(n);
    ecb_packi32_le(b,val);
}/*}}}*/
ecb_inline void ecb_packf64_le(gptr b,const f64 n) {/*{{{*/
    i64 val = ecb_dtol(n);
    ecb_packi64_le(b,val);
}/*}}}*/

ecb_inline i16 ecb_unpacki16_le(gptr b) {/*{{{*/
    return (i16) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8));
}/*}}}*/
ecb_inline i32 ecb_unpacki32_le(gptr b) {/*{{{*/
    return (i32) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8)
            | (((*(b + 2)) & 0xFF) << 16)
            | (((*(b + 3)) & 0xFF) << 24));
}/*}}}*/
ecb_inline i64 ecb_unpacki64_le(gptr b) {/*{{{*/
    return (i64) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8)
            | (((*(b + 2)) & 0xFF) << 16)
            | (((*(b + 3)) & 0xFF) << 24)
            | (((*(b + 4)) & 0xFF) << 32)
            | (((*(b + 5)) & 0xFF) << 40)
            | (((*(b + 6)) & 0xFF) << 48)
            | (((*(b + 7)) & 0xFF) << 56));
}/*}}}*/
ecb_inline f32 ecb_unpackf32_le(gptr b) {/*{{{*/
    i32 val = ecb_unpacki32_le(b);
    return ecb_itof(val);
}/*}}}*/
ecb_inline f64 ecb_unpackf64_le(gptr b) {/*{{{*/
    i64 val = ecb_unpacki64_le(b);
    return ecb_ltod(val);
}/*}}}*/

#endif
