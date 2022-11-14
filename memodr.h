
#ifndef ECB_MEMODR_H
#define ECB_MEMODR_H


#ifdef __cplusplus
extern "C" {
#endif

    typedef enum{
        memodr_relaxed = __ATOMIC_RELAXED,
        memodr_consume = __ATOMIC_CONSUME,
        memodr_acquire = __ATOMIC_ACQUIRE,
        memodr_release = __ATOMIC_RELEASE,
        memodr_acq_rel = __ATOMIC_ACQ_REL,
        memodr_seq_cst = __ATOMIC_SEQ_CST
    } memodr;

    /**
     * *ptr += q;
     * return *ptr;
     */
#define atomic_add_fetch(ptr,q,memodr) \
    __atomic_add_fetch ((ptr),(q),(memodr)) 

    /**
     * *ptr -= q;
     * return *ptr;
     */
#define atomic_sub_fetch(ptr,q,memodr) \
    __atomic_sub_fetch ((ptr),(q),memodr)

    /**
     * *ptr += 1;
     * return *ptr;
     */
#define atomic_incr_fetch(ptr,memodr) \
    atomic_add_fetch((ptr),1,memodr)

    /**
     * *ptr -= 1;
     * return *ptr;
     */
#define atomic_decr_fetch(ptr,memodr) \
    atomic_sub_fetch((ptr),1,memodr) 

    /**
     * *ptr &= q;
     * return *ptr;
     */
#define atomic_and_fetch(ptr,q,memodr) \
    __atomic_and_fetch ((ptr),q,memodr)

    /**
     * *ptr ^= q;
     * return *ptr;
     */
#define atomic_xor_fetch(ptr,q,memodr) \
    __atomic_xor_fetch ((ptr),q,memodr)

    /**
     * *ptr |= q;
     * return *ptr;
     */
#define atomic_or_fetch(ptr,q,memodr) \
    __atomic_or_fetch ((ptr),q,memodr)

    /**
     * *ptr = ~(*ptr & q);
     * return *ptr;
     */
#define atomic_nand_fetch(ptr,q,memodr) \
    __atomic_nand_fetch ((ptr),q,memodr)


    /**
     * before = *ptr;
     * *ptr += q;
     * return before;
     */
#define atomic_fetch_add(ptr,q,memodr) \
    __atomic_fetch_add ((ptr),(q),memodr) 

    /**
     * before = *ptr;
     * *ptr -= q;
     * return before;
     */
#define atomic_fetch_sub(ptr,q,memodr) \
    __atomic_fetch_sub ((ptr),(q),memodr)

    /**
     * before = *ptr;
     * *ptr += 1;
     * return before;
     */
#define atomic_fetch_incr(ptr,memodr) \
    atomic_fetch(add((ptr),q,memodr)

            /**
             * before = *ptr;
             * *ptr -= 1;
             * return before;
             */
#define atomic_fetch_decr(ptr,memodr) \
atomic_fetch_sub((ptr),1,memodr)

            /**
             * before = *ptr;
             * *ptr &= q;
             * return before;
             */
#define atomic_fetch_and(ptr,q,memodr) \
__atomic_fetch_and ((ptr),(q),memodr)

            /**
             * before = *ptr;
             * *ptr ^= q;
             * return before;
             */
#define atomic_fetch_xor(ptr,q,memodr) \
    __atomic_fetch_xor((ptr),(q),memodr)

    /**
     * before = *ptr;
     * *ptr |= q;
     * return before;
     */
#define atomic_fetch_or(ptr,q,memodr) \
    __atomic_fetch_or ((ptr),(q),memodr)

    /**
     * before = *ptr;
     * *ptr = ~(*ptr & q);
     * return before;
     */
#define atomic_fetch_nand(ptr,q,memodr) \
    __atomic_fetch_nand ((ptr),(q),memodr)


    /**
     * load *ptr to *refptr
     * *refptr = *ptr;
     * noreturn
     * memodr:memodr_relaxed / memodr_consume 
     *        memodr_acquire / memodr_seq_cst
     */
#define atomic_load(ptr,refptr,memodr) __atomic_load((ptr),(refptr),memodr)

    /**
     * load *ptr to *ret
     *  tmp = *ptr;
     *  return *tmp;
     * memodr:memodr_relaxed / memodr_consume /
     *        memodr_acquire / memodr_seq_cst
     */
#define atomic_load_ex(ptr,memodr) __atomic_load_n((ptr),memodr)

    /**
     * *ptr = *qptr;
     * noreturn
     * memodr:memodr_relaxed / memodr_release / memodr_seq_cst
     */
#define atomic_store(ptr,qptr,memodr) __atomi_store((ptr),(qptr),memodr)

    /**
     * *ptr = q;
     * noreturn
     * memodr:memodr_relaxed / memodr_release / memodr_seq_cst
     */
#define atomic_store_ex(ptr,q,memodr) __atomi_store_n((ptr),(q),memodr)

    /* *refptr = *ptr;
     * *ptr = *qptr;
     * noreturn
     */
#define atomic_xchg(ptr,qptr,refptr,memodr) __atomic_exchange((ptr),(qptr),(refptr),memodr)

    /*
     * tmp = *ptr;
     * *ptr = q;
     * return tmp;
     *
     */
#define atomic_xchg_ex(ptr,q,memodr) __atomic_exchange_n((ptr),(q),memodr)

    /**
     * if( *ptr = *cmp_ptr) { *ptr = *qptr; return true;}
     * else { *cmp_ptr = *ptr; return false;}
     * return bool variable for operator
     */
#define atomic_try_cmpxchg_storage(ptr,cmp_ptr,qptr,ok_memodr,fail_memodr) \
    __atomic_compare_exchange((ptr),(cmp_ptr),(qptr),0,ok_memodr,fail_memodr)

    /**
     * if( *ptr = *cmp_ptr) { *ptr = *qptr; return true;}
     * else { *cmp_ptr = *ptr; return false;}
     * return bool variable for operator
     */
#define atomic_try_cmpxchg_weak(ptr,cmp_ptr,qptr,ok_memodr,fail_memodr) \
    __atomic_compare_exchange((ptr),(cmp_ptr),(qptr),1,ok_memodr,fail_memodr)

    /**
     *  ** 99.9999% use this one **
     *
     * if( *ptr = *cmp_ptr) { *ptr = *qptr; return true;}
     * else { *cmp_ptr = *ptr; return false;}
     * return bool variable for operator
     */
#define atomic_try_cmpxchg(ptr,cmp_ptr,qptr,ok_memodr,fail_memodr) \
    atomic_try_cmpxchg_storage((ptr),(cmp_ptr),(qptr),ok_memodr,fail_memodr)

    /**
     * if( *ptr = *cmp_ptr) { *ptr = q; return true;}
     * else { *cmp_ptr = *ptr; return false;}
     * return bool variable for operator
     */
#define atomic_try_cmpxchg_storage_ex(ptr,cmp_ptr,q,ok_memodr,fail_memodr) \
    __atomic_compare_exchange_n((ptr),(cmp_ptr),(q),0,ok_memodr,fail_memodr)

    /**
     * if( *ptr = *cmp_ptr) { *ptr = q; return true;}
     * else { *cmp_ptr = *ptr; return false;}
     * return bool variable for operator
     */
#define atomic_try_cmpxchg_weak_ex(ptr,cmp_ptr,q,ok_memodr,fail_memodr) \
    __atomic_compare_exchange_n((ptr),(cmp_ptr),(q),1,ok_memodr,fail_memodr)

    /**
     *  ** 99.9999% use this one **
     *
     * if( *ptr = *cmp_ptr) { *ptr = q; return true;}
     * else { *cmp_ptr = *ptr; return false;}
     * return bool variable for operator
     */
#define atomic_try_cmpxchg_ex(ptr,cmp_ptr,q,ok_memodr,fail_memodr) \
    atomic_try_cmpxchg_storage_ex((ptr),(cmp_ptr),(q),ok_memodr,fail_memodr)



#define atomic_cmpxchg(ptr,cmp_ptr,qptr,ok_memodr,fail_memodr) ({ \
        while(true) { \
        if( atomic_try_cmpxchg((ptr),(cmp_ptr),(qptr),ok_memodr,fail_memodr))  break; \
        }\
        true; \
        })

    /**
     *  try to success by maxtrys
     * *ptr = (*ptr == oldval ? newval : *ptr);
     * return *ptr = newval;
     */
#define atomic_trys_cmpxchg(ptr,cmp_ptr,qptr,maxtrys,ok_memodr,fail_memodr) ({\
        int trys = 0;\
        typeof(maxtrys) mt = (maxtrys); \
        bool isok = false; \
        while((++trys) < mt) { \
        ecb_iif(atomic_try_cmpxchg((ptr),(cmp_ptr),(qptr),ok_memodr,fail_memodr),\
                { isok = true;break; }, \
                { cpu_pause(); }); \
                } \
                isok; \
                })


#define atomic_cmpxchg_ex(ptr,cmp_ptr,q,ok_memodr,fail_memodr) ({ \
        while(true) { \
        if( atomic_try_cmpxchg((ptr),(cmp_ptr),(q),ok_memodr,fail_memodr))  break; \
        }\
        true; \
        })

    /**
     *  try to success by maxtrys
     * *ptr = (*ptr == oldval ? newval : *ptr);
     * return *ptr = newval;
     */
#define atomic_trys_cmpxchg_ex(ptr,cmp_ptr,q,maxtrys,ok_memodr,fail_memodr) ({\
        int trys = 0;\
        typeof(maxtrys) mt = (maxtrys); \
        bool isok = false; \
        while((++trys) < mt) { \
        ecb_iif(atomic_try_cmpxchg((ptr),(cmp_ptr),(q),ok_memodr,fail_memodr),\
                { isok = true;break; }, \
                { cpu_pause(); }); \
                } \
                isok; \
                })


#define atomic_set(ptr,memodr) \
    __atomic_test_and_set((ptr),memodr)

#define atomic_rls(ptr,memodr) \
    __atomic_clear((ptr),memodr)


#define atomic_mb(memodr) __atomic_thread_fence(memodr)

#define atomic_signal_mb(memodr) __atomic_signal_fence(memodr)

#ifdef __cplusplus
}
#endif


#endif
