#ifndef _ECB_H_
#define _ECH_H_

#define GCC_VERSION ECB_DECLTYPE(i32)(__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if GCC_VERSION >= 70000 && !defined(__CHECKER__)
#define __nobrk __attribute__((fallthrough))
#endif

#if GCC_VERSION >= 40300
#define __compiletime_error(message) \
    __attribute__((error(message)))
#else
#define __compiletime_error(message)
#endif /* GCC_VERSION >= 40300 */

#ifndef ECB_REPLACEABLE
#define ECB_REPLACEABLE __attribute__((weak))
#endif

#ifndef ECB_REPALCEBY
#define ECB_REPALCEBY(n) __attribute__((weak, alias(n)));
#endif



/**
 * decl function be called before main-functon run
 *
 *100 is min value of constructor or destructor
 *and it for system
 **/
#ifndef ECB_CTOR
#define ECB_CTOR(n) __attribute__((constructor(100 + n)))
#endif

/**
 * decl function be called after main-functon run
 *
 *100 is min value of constructor or destructor
 *and it for system
 **/
#ifndef ECB_DTOR
#define ECB_DTOR(n) __attribute__((destructor(100 + n)))
#endif

#ifndef ECB_PACKED
#define ECB_PACKED __attribute__((__packed__))
#endif

#define ECB_ALIGNED __attribute__((__aligned__))

/**
 *
 * 提醒程序员“此可变参数函数需要一个NULL作为最后一个参数。
 *
 */
#define ECB_ENDNIL ECB_ATTRIBUTE((sentinel))

#define ECB_ATOMIC volatile

/**
 * alias for all type
 *
 * type declaring in ecb.h so it must exist now.
 *
 */

#ifndef bool
typedef enum {
    false = 0,
    true = 1
}bool;

    static char *bool_desc[] = {
        "false",
        "true"
    };
#endif


#ifndef byte
typedef signed char byte;
#endif

#ifndef ubyte
typedef unsigned char ubyte;
#endif

#ifndef uchar
typedef unsigned char uchar;
#endif

#ifndef string
typedef char *string;
#endif

#ifndef wstring
typedef wchar_t *wstring;
#endif

#ifndef u64
typedef u_int64_t u64;
#endif

#ifndef u32
typedef u_int32_t u32;
#endif

#ifndef u16
typedef u_int16_t u16;
#endif

#ifndef u8
typedef u_int8_t u8;
#endif

#ifndef i64
typedef int64_t i64;
#endif

#ifndef i32
typedef int32_t i32;
#endif

#ifndef i16
typedef int16_t i16;
#endif

#ifndef i8
typedef int8_t i8;
#endif

#ifndef f32
typedef float f32;
#endif

#ifndef f64
typedef double f64;
#endif

#ifdef _WIN32
#define ECB_SO_EXT ".dll"
#elif defined(__APPLE__)
#define ECB_SO_EXT ".dylib"
#else
#define ECB_SO_EXT ".so"
#endif

#define ECB_TEST(a) ((a) ? 1 : 0)
#define ECB_FN_EXTCHAR '.'
#define ECB_FN_HOMELIB '~'    /* ~/ is used as abbrev for home dir */
#define ECB_FN_CURLIB '.'     /* ./ is used as abbrev for current dir */
#define ECB_FN_PARENTDIR ".." /* Parent directory; Must be a string */

#ifdef _WIN32
#define ECB_FN_LIBCHAR '\\'
#define ECB_FN_LIBCHAR2 '/'
#define ECB_FN_DIRSEP "/\\" /* Valid directory separators */
#define ECB_FN_EXEEXT ".exe"
#define ECB_FN_SOEXT ".dll"
#define ECB_FN_ROOTDIR "\\"
#define ECB_FN_DEVCHAR ':'
#define ECB_FN_NETWORK_DRIVES /* Uses \\ to indicate network drives */
#else
#define ECB_FN_LIBCHAR '/'
#define ECB_FN_LIBCHAR2 '/'
#define ECB_FN_DIRSEP "/" /* Valid directory separators */
#define ECB_FN_EXEEXT ""
#define ECB_FN_SOEXT ".so"
#define ECB_FN_ROOTDIR "/"
#endif
#define ECB_YESNOSTR(X) ((X) ? "yes" : "no")



/**
 * a pointer address expressed as an unsigned/signed integer
 * then it can convert to pointer
 */
typedef uintptr_t uptr;
typedef intptr_t intptr;

/**
 * generic object pointer
 */
typedef char *object;

/**
 * declare return-type or define type for macro
 * it have not practical means
 * maybe "type" is typeof(expr) if expr without negative consequence
 * or String if expr have negative consequence(expl:macro parameter)
 */
#ifndef ECB_DECLTYPE
#define ECB_DECLTYPE(type)
#endif


/**
 * memory aligned by alloc
 */
#define ECB_ALIGNEDSIZE ECB_PTRSIZE

#define ECB_ERRSTR(e) strerror(e)
#define ECB_STRERR errstr(error)
#define ECB_BITS_PER_BYTE 8
#define ECB_BITS_PER_SHORT 16
#define ECB_BITS_PER_I32 32
#define ECB_BITS_PER_I64 64

#define ECB_U16MAX ((0XFF) & (~0U))
#define ECB_I16MAX ((0XFF) & (U16_MAX >> 1))
#define ECB_I16MIN ((0XFF) & (-I16_MAX - 1))
#define ECB_I32MAX ((i32)(~0U >> 1))
#define ECB_I32MIN (-I32_MAX - 1)
#define ECB_U32MAX (~0U)
#define ECB_I64MAX ((u64)(~0ULL >> 1))
#define ECB_I64MIN (-LLONG_MAX - 1)
#define ECB_U64MAX (~0ULL)

#define ECB_GB_PER_TB (1024)
#define ECB_MB_PER_TB (1024 * 1024)
#define ECB_KB_PER_TB (1024 * 1024 * 1024)
#define ECB_B_PER_TB (1024 * 1024 * 1024 * 1024)
#define ECB_MB_PER_GB (1024)
#define ECB_KB_PER_GB (1024 * 1024)
#define ECB_B_PER_GB (1024 * 1024 * 1024)
#define ECB_KB_PER_MB (1024)
#define ECB_B_PER_MB (1024 * 1024)
#define ECB_B_PER_KB (1024)

#define ECB_SEC_PER_MIN (60)
#define ECB_SEC_PER_HOUR (60 * 60)
#define ECB_SEC_PER_DAY (24 * 60 *60)
#define ECB_MIN_PER_HOUR (60)
#define ECB_MIN_PER_DAY (24 * 60)
#define ECB_HOUR_PER_DAY (24)
#define ECB_MS_PER_SEC (1000)
#define ECB_NS_PER_SEC ( 1000 * 1000)
#define ECB_NS_PER_MS ( 1000)

#ifndef null
#define null NULL
#endif

#ifndef nil
#define nil NULL
#endif

#define ECB_STRLOC __FILE__ ":" ECB_STRINGIFY(__LINE__)

#define ECB_IS_RETRY(e) (EAGAIN == (e) || EWOULDBLOCK == (e) || EINTR == (e))
#define ECB_RETRY_DO(e,expr) if(ECB_IS_RETRY(e)) { expr; continue;}
#define ECB_CLOSE(fd) ECB_DOWHILE(ECB_IF(likely(!ECB_ISZERO(fd)),{close(fd);fd = 0;}));

/* *
 * placeholder for argument or expr
 * */
#define ECB_ANYVAL
#define ECB_ANYEXPR ;


#define ECB_OK 0
#define ECB_NO -1

/**
 * get count of macro function arguments
 * but only supported for maxsize is 20 of arguments
 */
#define ECB_ARGC(...) _ECB_ARGC(A, ##__VA_ARGS__, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)
#define _ECB_ARGC(A, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, COUNT, ...) COUNT

// If the number of arguments is 0, return 0, otherwise return N.
#define ECB_ARGV_CHECK(...) _ECB_ARGV_CHECK(A, ##__VA_ARGS__, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, N, 0)
#define _ECB_ARGV_CHECK(A, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, OBJ, ...) OBJ


#define ECB_ISNIL(n) (NULL == (n))
#define ECB_ISZERO(n) (0 == (n))
#define ECB_ISOK(n) (ECB_OK == (n))
#define ECB_ISNO(n) (ECB_NO == (n))

#define ECB_ABS(n) ({ __typeof__(n) _n = (n); 0 >= _n ? _n : (0 - _n) })
#define ECB_MIN(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a < _b ? _a : _b; })
#define ECB_MAX(a, b) ({__typeof__(a) _a = (a); __typeof__(b) _b = (b); _a > _b ? _a : _b; })
#define ECB_TABS(t, n) ({ t _n = (n); 0 <= _n ? _n : (0 - _n) })
#define ECB_TMIN(t, a, b) ({t _a = (a), t _b = (b); _a < _b ? _a : _b; })
#define ECB_TMAX(t, a, b) ({t _a = (a); t _b = (b); _a > _b ? _a : _b; })

#define ECB_SET_ABS(a) a = ECB_ABS(a)
#define ECB_SET_IF_MAX(a, b) a = ECB_MAX((a),(b))
#define ECB_SET_IF_MIN(a, b) a = ECB_MIN((a),(b))
#define ECB_SET_TABS(t,a) a = ECB_TABS(t,a)
#define ECB_SET_IF_TMAX(t,a, b) a = ECB_TMAX((t),(a),(b))
#define ECB_SET_IF_TMIN(t,a, b) a = ECB_TMIN((t),(a),(b))
#define ECB_TEST_ALL_BITS(a, b) (((a) & (b)) == (b))


/**
 * memory pointer operator
 * return value is count by byte
 **/
#define ECB_PADD(p, off) ECB_DECLTYPE(gptr)(((gptr)p) + off)
#define ECB_PSUB(p, off) ECB_DECLTYPE(gptr)(((gptr)p) - off)
#define ECB_PDIFF(lp, rp) ECB_DECLTYPE(i32)(((gptr)lp) - ((gptr)rp))
#define ECB_PDIFF_EX(lp, rp) ECB_DECLTYPE(u32) ECB_ABS(((gptr)lp) - ((gptr)rp))

/**
 *  aligned by memory
 * op=4 base=8 then rtn=8
 **/
#define ECB_ALIGN(op, base) ({       \
        typeof(op) op1 = (op);            \
        typeof(base) b2 = (base);         \
        ((op1 + (b2 - 1)) & (~(b2 - 1))); \
        })

/**
 * aligned by base then calculate count of base
 *
 */
#define ECB_NUMBSOF(op, base) ({ \
        typeof(base) b2 = (base);     \
        (ECB_ALIGN(op, b2) / b2);    \
        })

#define ECB_MALIGN(op) ECB_DECLTYPE(i32) ECB_ALIGN(op, ECB_ALIGNEDSIZE)
#define ECB_MNUMBSOF(op) ecb_decltype(i32) ECB_NUMBSOF(op, ECB_ALIGNEDSIZE)

/**
 * macro function style to shortcut calls ,
 * they are mainly used to save annoying if statements,
 * especially it with only one or two fixed assignments  statements or return statements
 *
 * For so many years, the solution to kill annoying braces turned out to be macro functions
 */
#define ECB_SETNIL(p) (p) == nuil
#define ECB_IF(cond, expr)    if (ECB_EXPECT_TRUE(cond)) { expr; }
#define ECB_IIF(cond, t_expr, f_expr) \
    if(ECB_EXPECT_TRUE(cond)) {t_expr;}else{f_expr;}
#define ECB_IF_RTN(cond, rc)  ECB_IF((cond), { return (rc); })
#define ECB_IIF_RTN(cond, t_rc, f_rc)  ECB_IIF((cond), { return t_rc; }, { return f_rc; })
#define ECB_IF_EXPRTN(cond, expr, rc)  ECB_IF(cond, {expr;return rc; })
#define ECB_IIF_EXPRTN(cond, t_expr, t_rc, f_expr, f_rc)  ECB_IIF(cond, {t_expr;return t_rc; }, {f_expr;return f_rc; })
#define ECB_SETRTN(rc, err, rc)  { rc = err;return rc; }
#define ECB_IF_SETRTN(cond, rc, err, rc) ECB_IF(cond, ECB_SETRTN(rc, err, rc))
#define ECB_IF_SET(cond, name, val)  ECB_IF(cond, { name = (val); })
#define ECB_IF_BRK(cond) ECB_IF(cond, break)
#define ECB_IF_NEXT(cond) ECB_IF(cond, continue)
#define ECB_IF_GOTO(cond, lbl) ECB_IF(cond, { goto lbl; })
#define ECB_IF_EXPRBRK(cond) ECB_IF(cond, {expr; break;})
#define ECB_IF_EXPRNEXT(cond) ECB_IF(cond, { expr; continue; })
#define ECB_IF_EXPRGOTO(cond, lbl) ECB_IF(cond, { expr; goto lbl; })
#define ECB_IIF_SET(cond, name, t_rc, f_rc) ((name) = (cond) ? (t_rc) : (f_rc))
#define ECB_DOWHILE(expr) do { expr;} while(0)

/*
 * lambda for c
 * this is not ANSI C
 * and implemented with c extensions in GCC (maybe not support by Clang)
 * use: ecb_lambda(int,(int x, int y),{ return x + y; })(1,1)
 */
#define ECB_LAMBDA(_rtntype__, _args__, _body__) \
    ({ _rtntype__ __anon__ _args__ _body__ __anon__; })

#define ECB_MSET(ptr, v, len) memset((ptr), (v), (len))
#define ECB_BZERO(ptr, len) ECB_MSET((ptr), 0, (len))
#define ECB_BZERO_EX(ptr) ECB_BZERO(ptr,sizeof(*(ptr))
#define ECB_VZERO(q) ECB_MSET(&(q), 0, sizeof(q))

#ifndef container_of
#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr)-offsetof(type, member)))
#define field_of(ptr, type, member) container_of(ptr, type, member)
#define COF(p,t,m) container_of((p),(t),(m))
#endif

#ifndef offsetof
#define offsetof(type, member) ((size_t) & (((type *)0)->member))
#define OOF(t,m) offsetof((t),(m))
#endif

#ifndef field_sizeof
#define field_sizeof(t, f) __decltype(size_t)(sizeof(((t *) 0)->f))
#define FOF(t,f) field_sizeof((t),(f))
#endif

/**
 * convert function
 *
 */
#define ECB_XCHGTO(type, n, v) (type) n = (type)(v)
#define ECB_XCHGTOPTR(typep, n, v) (type *)n = (type *)(v)

#define ECB_FREE(ptr) ECB_IF(likely(!ECB_ISNIL(ptr)),{free(prt); ptr = nil;})

typedef union  { 
    i32 ival; 
    f32 fval; 
} ecb_fci;

typedef union  { 
    i64 ival; 
    f64 fval; 
} ecb_dcl;

#define ECB_FTOI(valf) ({ ecb_fci fi = {.fval = (valf)}; fi.ival; })
#define ECB_ITOF(vali) ({ ecb_fci fi = {.ival = (vali)}; fi.fval; })
#define ECB_DTOL(valf) ({ ecb_dcl fi = {.fval = (valf)}; fi.ival; })
#define ECB_LTOD(vali) ({ ecb_dcl fi = {.ival = (vali)}; fi.fval; })

#define ECB_MBR() __asm__ __volatile__("":::"memory")
#define ECB_MBRP(ptr) __asm__ __volatile__(""::"r"(ptr):"memory")
#define ECB_READONCE(v)  (*(volatile typeof(v) *)&(v))

/**
 * most functions need return data with result_t
 * if function need return runcode and runmsg to called function to deal,
 * you can use this struct for result
 *
 * when 0 == ok, msg is object address if function have object(struct) to return
 * when 0 != ok, msg is err-msg and marked if it want to free by called
 *
 * if you in bussines code,maybe you donot need this
 * but if in lib code,you donot want to log error msg and give this function
 * to called,but you want to return msg in detail as soon as you possible,
 * then result_t is you only choose.
 */
typedef struct {
    i32 ok;
    uptr msg;
}result_t ecb_aligned;

/**
 * this mark for result_t's msg
 * if msg is heap object then need to free it, marked
 * if msg is const, donot marked
 */
#define ECB_RETMSG_MARK 0x01
#define ECB_RETMSG_MARKING(retptr) ((retptr)->msg) |= ECB_RESULT_MARK
#define ECB_RETMSG_ISMARKED(retptr) (ECB_RETMSG_MARK & ((retptr)->msg))
#define ECB_RETMSG_GET(retptr) ((char *) ((~ECB_RETMSG_MARK) & ((retptr)->msg)))
#define ECB_RETMSG_ISNIL(retptr) (0 == (retptr)->msg)
#define ECB_RETMSG_FREE(retptr,free_handler) \
    ECB_DOWHILE(ECB_IF(!ECB_RETMSG_ISNIL(retptr), \
                    ECB_IF(ECB_RETMSG_ISMARKED(retptr), \
                        free_handler(ECB_RETMSG_GET((retptr))))))
#define ECB_RESULT_INIT(retptr) \
    ECB_DOWHILE({(retptr)->ok = 0;(retptr)->msg = 0;})
#define ECB_RESULT_SET(retptr,_ok,_msg,ismark) \
    ECB_DOWHILE({ (retptr)->ok = (_ok); \
                (retptr)->msg = (uptr) (_msg);\
                ECB_IF((ismark),ECB_RETMSG_MARKING(retptr));\
                })


/**
 * support to functional progame
 * but  have idea now
 *
 */
typedef struct {
    object some;
    object none;
}option_t;


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

#define ECB_BITSET(x, pos) ((x) |= (1 << (pos)))
#define ECB_BITGET(x, pos) ({ int loc_pos = pos; (((x) & (1 << loc_pos)) >> loc_pos); })
#define ECB_BITCLR(x, pos) ((x) &= ~(1 << (pos)))

#define ECB_BITGET_R(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        ((loc_x & (1 << pos_r)) >> pos_r);                    \
        })

#define ECB_BITCLR_R(x, pos_r) ({                    \
        typeof(x) loc_x = x;                              \
        int loc_pos = pos_r;                                \
        int pos_r = (sizeof(loc_x) << 0x03) - 1 - (loc_pos); \
        (loc_x &= ~(1 << pos_r));                           \
        })

#define ECB_BITSET_R(x, pos_r) ({                    \
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
#define ECB_SHIFT32_R(x) ((x) >> 0x05)
#define ECB_SHIFT64_R(x) ((x) >> 0x06)

/*
 * generate mark bit in begin(b)-end(e) range
 * markN,N is 8,16,32 or 64 then range is 1->8,1->16,1->32,1->64 one by one
 */
#define ECB_GENMARK8(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFF >> (loc_b)) << (loc_b))  & ~((0xFF >> (loc_e)) << (loc_e)));})
#define ECB_GENMARK16(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFF >> (loc_e)) << (loc_e)));})
#define ECB_GENMARK32(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFFFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFFFFFF >> (loc_e)) << (loc_e)));})
#define ECB_GENMARK64(b,e) ({ \
        typeof(b) loc_b = (b); typeof(e) loc_e = e;\
        (((0xFFFFFFFFFFFFFFFF >> (loc_b)) << (loc_b))  & ~((0xFFFFFFFFFFFFFFFF >> (loc_e)) << (loc_e)));})

#define ECB_GENUNMARK8(b,e) ({ (0xFF & (~ECB_GENMARK8(b,e))); })
#define ECB_GENUNMARK16(b,e) ({ (0xFFFF & (~ECB_GENMARK16(b,e))); })
#define ECB_GENUNMARK32(b,e) ({ (0xFFFFFFFF & (~ECB_GENMARK32(b,e))); })
#define ECB_GENUNMARK64(b,e) ({ (0xFFFFFFFFFFFFFFFF &(~ECB_GENMARK64(b,e))); })

#define ECB_GENMARK8_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfByte - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfByte - (e);\
        ECB_GENMARK8(loc_rb,loc_re); })
#define ECB_GENMARK16_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfSHORT - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfSHORT - (e);\
        ECB_GENMARK16(loc_rb,loc_re); })
#define ECB_GENMARK32_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI32 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI32 - (e);\
        ECB_GENMARK32(loc_rb,loc_re); })
#define ECB_GENMARK64_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI64 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI64 - (e);\
        ECB_GENMARK64(loc_rb,loc_re); })

#define ECB_GENUNMARK8_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfByte - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfByte - (e);\
        ECB_GENUNMARK8(loc_rb,loc_re); })
#define ECB_GENUNMARK16_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfSHORT - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfSHORT - (e);\
        ECB_GENUNMARK16(loc_rb,loc_re); })
#define ECB_GENUNMARK32_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI32 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI32 - (e);\
        ECB_GENUNMARK32(loc_rb,loc_re); })
#define ECB_GENUNMARK64_R(b,e) ({ \
        typeof(b) loc_re = ECB_BitsCntOfI64 - (b); \
        typeof(e) loc_rb = ECB_BitsCntOfI64 - (e);\
        ECB_GENUNMARK64(loc_rb,loc_re); })

#define ECB_MARK8(x,b,e) ((x) | ECB_GENMARK8(b,e))
#define ECB_MARK16(x,b,e) ((x) | ECB_GENMARK16(b,e))
#define ECB_MARK32(x,b,e) ((x) | ECB_GENMARK32(b,e))
#define ECB_MARK64(x,b,e) ((x) | ECB_GENMARK64(b,e))
#define ECB_MARK8_R(x,b,e) ((x) | ECB_GENMARK8_R(b,e))
#define ECB_MARK16_R(x,b,e) ((x) | ECB_GENMARK16_R(b,e))
#define ECB_MARK32_R(x,b,e) ((x) | ECB_GENMARK32_R(b,e))
#define ECB_MARK64_R(x,b,e) ((x) | ECB_GENMARK64_R(b,e))

#define ECB_UNMARK8(x,b,e) ((x) & ECB_GENUNMARK8(b,e))
#define ECB_UNMARK16(x,b,e) ((x) & ECB_GENUNMARK16(b,e))
#define ECB_UNMARK32(x,b,e) ((x) & ECB_GENUNMARK32(b,e))
#define ECB_UNMARK64(x,b,e) ((x) & ECB_GENUNMARK64(b,e))
#define ECB_UNMARK8_R(x,b,e) ((x) & ECB_GENUNMARK8_R(b,e))
#define ECB_UNMARK16_R(x,b,e) ((x) & ECB_GENUNMARK16_R(b,e))
#define ECB_UNMARK32_R(x,b,e) ((x) & ECB_GENUNMARK32_R(b,e))
#define ECB_UNMARK64_R(x,b,e) ((x) & ECB_GENUNMARK64_R(b,e))

/**
 * find first pos of marking
 * pos range is (7...0)
 */
ECB_INLINE int ECB_FFMARK8(u8 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = ECB_BitsCntOfByte;
    ECB_IF((0x0F & x), {x &= 0x0F;pos -=  4;});
    ECB_IF_RTN((0x11 & x), pos - 4);
    ECB_IF_RTN((0x22 & x), pos - 3);
    ECB_IF_RTN((0x44 & x), pos - 2);
    ECB_IF_RTN((0x88 & x), pos - 1);
    return -1;
}/*}}}*/
ECB_INLINE int ECB_FFMARK16(u16 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = ECB_BitsCntOfSHORT;
    ECB_IF((0xFF & x), {x &= 0xFF; pos -= ECB_BitsCntOfByte;});
    ECB_IF((0x0F0F & x), { x &= 0x0F0F; pos -= 4;});
    ECB_IF_RTN((x & 0x1111), pos - 4);
    ECB_IF_RTN((x & 0x2222), pos - 3);
    ECB_IF_RTN((x & 0x4444), pos - 2);
    ECB_IF_RTN((x & 0x8888), pos - 1);
    return -1;
}/*}}}*/
ECB_INLINE int ECB_FFMARK32(u32 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = ECB_BitsCntOfI32;
    ECB_IF((0xFFFF & x), { x &= 0xFFFF;pos -= ECB_BitsCntOfSHORT;});
    ECB_IF((0xFF00FF & x), {x &= 0xFF00FF; pos -= ECB_BitsCntOfByte;});
    ECB_IF((0x0F0F0F0F & x), { x &= 0x0F0F0F0F; pos -= 4;});
    ECB_IF_RTN((x & 0x11111111), pos - 4);
    ECB_IF_RTN((x & 0x22222222), pos - 3);
    ECB_IF_RTN((x & 0x44444444), pos - 2);
    ECB_IF_RTN((x & 0x88888888), pos - 1);
    return -1;
}/*}}}*/
ECB_INLINE int ECB_FFMARK64(u64 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = ECB_BitsCntOfI64;
    ECB_IF((0xFFFFFFFF & x), { x &= 0xFFFFFFFF;pos -= ECB_BitsCntOfI32;});
    ECB_IF((0xFFFF0000FFFF & x), { x &= 0xFFFF0000FFFF;pos -= ECB_BitsCntOfSHORT;});
    ECB_IF((0x00FF00FF00FF00FF & x), { x &= 0x00FF00FF00FF00FF; pos -= ECB_BitsCntOfByte;});
    ECB_IF((0x0F0F0F0F0F0F0F0F & x), { x &= 0x0F0F0F0F0F0F0F0F; pos -= 4;});
    ECB_IF_RTN((x & 0x1111111111111111), pos - 4);
    ECB_IF_RTN((x & 0x2222222222222222), pos - 3);
    ECB_IF_RTN((x & 0x4444444444444444), pos - 2);
    ECB_IF_RTN((x & 0x8888888888888888), pos - 1);
    return -1;
}/*}}}*/

/**
 * reverse find first pos of marking
 * pos range is (0...7)
 */
ECB_INLINE int ECB_FFMARK8_R(u8 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = 0;
    ECB_IF(ECB_ISZERO(0xF0 & x), {x &= 0x0F;pos +=  4;});
    ECB_IF_RTN((0x88 & x), pos);
    ECB_IF_RTN((0x44 & x), pos + 1);
    ECB_IF_RTN((0x22 & x), pos + 2);
    ECB_IF_RTN((0x11 & x), pos + 3);
    return -1;
}/*}}}*/
ECB_INLINE int ECB_FFMARK16_R(u16 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = 0;
    ECB_IF(ECB_ISZERO(0xFF00 & x), {x &= 0xFF00; pos += ECB_BitsCntOfByte;});
    ECB_IF(ECB_ISZERO(0xF0F0 & x), {x &= 0xF0F0;pos +=  4;});
    ECB_IF_RTN((0x8888 & x), pos);
    ECB_IF_RTN((0x4444 & x), pos + 1);
    ECB_IF_RTN((0x2222 & x), pos + 2);
    ECB_IF_RTN((0x1111 & x), pos + 3);
    return -1;
}/*}}}*/
ECB_INLINE int ECB_FFMARK32_R(u32 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = 0;
    ECB_IF(ECB_ISZERO(0xFFFF0000 & x), {x &= 0xFFFF0000; pos += ECB_BitsCntOfSHORT;});
    ECB_IF(ECB_ISZERO(0xFF00FF00 & x), {x &= 0xFF00FF00; pos += ECB_BitsCntOfByte;});
    ECB_IF(ECB_ISZERO(0xF0F0F0F0 & x), {x &= 0xF0F0F0F0;pos +=  4;});
    ECB_IF_RTN((0x88888888 & x), pos);
    ECB_IF_RTN((0x44444444 & x), pos + 1);
    ECB_IF_RTN((0x22222222 & x), pos + 2);
    ECB_IF_RTN((0x11111111 & x), pos + 3);
    return -1;
}/*}}}*/
ECB_INLINE int ECB_FFMARK64_R(u64 x) {/*{{{*/
    ECB_IF_RTN( 0 == x,-1);
    int pos = 0;
    ECB_IF(ECB_ISZERO(0xFFFFFFFF00000000 & x), { x &= 0xFFFFFFFF00000000;pos += ECB_BitsCntOfI32;});
    ECB_IF(ECB_ISZERO(0xFFFF0000FFFF0000 & x), { x &= 0xFFFF0000FFFF0000;pos += ECB_BitsCntOfSHORT;});
    ECB_IF(ECB_ISZERO(0xFF00FF00FF00FF00 & x), { x &= 0xFF00FF00FF00FF00;pos += ECB_BitsCntOfByte;});
    ECB_IF(ECB_ISZERO(0xF0F0F0F0F0F0F0F0 & x), { x &= 0xF0F0F0F0F0F0F0F0; pos += 4;});
    ECB_IF_RTN((0x8888888888888888 & x), pos);
    ECB_IF_RTN((0x4444444444444444 & x), pos + 1);
    ECB_IF_RTN((0x2222222222222222 & x), pos + 2);
    ECB_IF_RTN((0x1111111111111111 & x), pos + 3);
    return -1;
}/*}}}*/

#define ECB_FFUNMARK8(x) ECB_FFMARK8(~(x))
#define ECB_FFUNMARK16(x) ECB_FFMARK16(~(x))
#define ECB_FFUNMARK32(x) ECB_FFMARK32(~(x))
#define ECB_FFUNMARK64(x) ECB_FFMARK64(~(x))
#define ECB_FFUNMARK8_R(x) ECB_FFMARK8_R(~(x))
#define ECB_FFUNMARK16_R(x) ECB_FFMARK16_R(~(x))
#define ECB_FFUNMARK32_R(x) ECB_FFMARK32_R(~(x))
#define ECB_FFUNMARK64_R(x) ECB_FFMARK64_R(~(x))


ECB_INLINE void ECB_PACKI8(gptr b,const i8 n) {/*{{{*/
    *b++ = (n & 0xff);
}/*}}}*/
ECB_INLINE void ECB_PACKI16(gptr b,const i16 n) {/*{{{*/
    *b++ = ( n >> 8 ) & 0xFF;
    *b++ = ( n & 0xFF );
}/*}}}*/
ECB_INLINE void ECB_PACKI32(gptr b,const i32 n){/*{{{*/
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = n & 0xFF;
}/*}}}*/
ECB_INLINE void ECB_PACKI64(gptr b,const i64 n){/*{{{*/
    *b++ = (n >> 56) & 0xFF;
    *b++ = (n >> 48) & 0xFF;
    *b++ = (n >> 40) & 0xFF;
    *b++ = (n >> 32) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = n & 0xFF;
}/*}}}*/
ECB_INLINE void ECB_PACKF32(gptr b,const f32 n) {/*{{{*/
    i32 val = ECB_FTOI(n);
    ECB_PACKI32(b,val);
}/*}}}*/
ECB_INLINE void ECB_PACKF64(gptr b,const f64 n) {/*{{{*/
    i64 val = ECB_DTOL(n);
    ECB_PACKI64(b,val);
}/*}}}*/

ECB_INLINE i8 ECB_UNPACKI8(gptr b) {/*{{{*/
    return (i8) (*b & 0xFF);
}/*}}}*/
ECB_INLINE i16 ECB_UNPACKI16(gptr b) {/*{{{*/
    return (i16) ((((*b) & 0xFF) << 8 )
            | ((*(b + 1)) & 0xFF));
}/*}}}*/
ECB_INLINE i32 ECB_UNPACKI32(gptr b) {/*{{{*/
    return (i32) ((((*b) & 0xFF) << 24 )
            |((*(b + 1) & 0xFF) << 16 )
            |((*(b + 2) & 0xFF) << 8 )
            | ((*(b + 3)) & 0xFF));
}/*}}}*/
ECB_INLINE i64 ECB_UNPACKI64(gptr b) {/*{{{*/
    return (i64) ((((*b) & 0xFF) << 56 )
            |((*(b + 1) & 0xFF) << 48 )
            |((*(b + 2) & 0xFF) << 40 )
            |((*(b + 3) & 0xFF) << 32 )
            |((*(b + 4) & 0xFF) << 24 )
            |((*(b + 5) & 0xFF) << 16 )
            |((*(b + 6) & 0xFF) << 8 )
            | ((*(b + 3)) & 0xFF));
}/*}}}*/
ECB_INLINE f32 ECB_UNPACKF32(gptr b) {/*{{{*/
    i32 val = ECB_UNPACKI32(b);
    return ECB_ITOF(val);
}/*}}}*/
ECB_INLINE f64 ECB_UNPACKF64(gptr b) {/*{{{*/
    i64 val = ECB_UNPACKI64(b);
    return ECB_LTOD(val);
}/*}}}*/

ECB_INLINE void ECB_PACKI16_LE(gptr b,const i16 n) {/*{{{*/
    *b++ = ( n & 0xFF );
    *b++ = ( n >> 8 ) & 0xFF;
}/*}}}*/
ECB_INLINE void ECB_PACKI32_LE(gptr b,const i32 n) {/*{{{*/
    *b++ = n & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
}/*}}}*/
ECB_INLINE void ECB_PACKI64_LE(gptr b,const i64 n){/*{{{*/
    *b++ = n & 0xFF;
    *b++ = (n >> 8) & 0xFF;
    *b++ = (n >> 16) & 0xFF;
    *b++ = (n >> 24) & 0xFF;
    *b++ = (n >> 32) & 0xFF;
    *b++ = (n >> 40) & 0xFF;
    *b++ = (n >> 48) & 0xFF;
    *b++ = (n >> 56) & 0xFF;
}/*}}}*/
ECB_INLINE void ECB_PACKF32_LE(gptr b,const f32 n){/*{{{*/
    i32 val = ECB_FTOI(n);
    ECB_PACKI32_LE(b,val);
}/*}}}*/
ECB_INLINE void ECB_PACKF64_LE(gptr b,const f64 n) {/*{{{*/
    i64 val = ECB_DTOL(n);
    ECB_PACKI64_LE(b,val);
}/*}}}*/

ECB_INLINE i16 ECB_UNPACKI16_LE(gptr b) {/*{{{*/
    return (i16) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8));
}/*}}}*/
ECB_INLINE i32 ECB_UNPACKI32_LE(gptr b) {/*{{{*/
    return (i32) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8)
            | (((*(b + 2)) & 0xFF) << 16)
            | (((*(b + 3)) & 0xFF) << 24));
}/*}}}*/
ECB_INLINE i64 ECB_UNPACKI64_LE(gptr b) {/*{{{*/
    return (i64) (((*b) & 0xFF)
            | (((*(b + 1)) & 0xFF) << 8)
            | (((*(b + 2)) & 0xFF) << 16)
            | (((*(b + 3)) & 0xFF) << 24)
            | (((*(b + 4)) & 0xFF) << 32)
            | (((*(b + 5)) & 0xFF) << 40)
            | (((*(b + 6)) & 0xFF) << 48)
            | (((*(b + 7)) & 0xFF) << 56));
}/*}}}*/
ECB_INLINE f32 ECB_UNPACKF32_LE(gptr b) {/*{{{*/
    i32 val = ECB_UNPACKI32_LE(b);
    return ECB_ITOF(val);
}/*}}}*/
ECB_INLINE f64 ECB_UNPACKF64_LE(gptr b) {/*{{{*/
    i64 val = ECB_UNPACKI64_LE(b);
    return ECB_LTOD(val);
}/*}}}*/

#endif
