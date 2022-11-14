
#ifndef ECB_MEMSYNC_H
#define ECB_MEMSYNC_H


#ifdef __cplusplus
extern "C" {
#endif


    /**
     * before = *ptr;
     * *ptr += q;
     * return before;
     */
#define sync_fetch_add(ptr,q) __sync_fetch_and_add((ptr),(q))

    /**
     * before = *ptr;
     * *ptr -= q;
     * return before;
     */
#define sync_fetch_sub(ptr,q) __sync_fetch_and_sub((ptr),(q))

    /**
     * before = *ptr;
     * *ptr += 1;
     * return before;
     */
#define sync_fetch_incr(ptr) __sync_fetch_and_add((ptr),(1))

    /**
     * before = *ptr;
     * *ptr -= 1;
     * return before;
     */
#define sync_fetch_decr(ptr) __sync_fetch_and_sub((ptr),(1))
    /**
     * before = *ptr;
     * *ptr |= q;
     * return before;
     */
#define sync_fetch_or(ptr,q) __sync_fetch_and_or((ptr),(q))

    /**
     * before = *ptr;
     * *ptr &= q;
     * return before;
     */
#define sync_fetch_and(ptr,q) __sync_fetch_and_and((ptr),(q))

    /**
     * before = *ptr;
     * *ptr ^= q;
     * return before;
     */
#define sync_fetch_xor(ptr,q) __sync_fetch_and_xor((ptr),(q))

    /**
     * before = *ptr;
     * *ptr = ~(*ptr & q);
     * return before;
     */
#define sync_fetch_nand(ptr,q) __sync_fetch_and_nand((ptr),(q))

    /**
     * *ptr += q;
     * return *ptr;
     */
#define sync_add_fetch(ptr,q) __sync_add_and_fetch((ptr),(q))

    /**
     * *ptr -= q;
     * return *ptr;
     */
#define sync_sub_fetch(ptr,q) __sync_sub_and_fetch((ptr),(q))

    /**
     * *ptr += 1;
     * return *ptr;
     */
#define sync_incr_fetch(ptr) __sync_add_and_fetch((ptr),(1))

    /**
     * *ptr -= 1;
     * return *ptr;
     */
#define sync_decr_fetch(ptr) __sync_sub_and_fetch((ptr),(1))

    /**
     * *ptr |= q;
     * return *ptr;
     */
#define sync_or_fetch(ptr,q) __sync_or_and_fetch((ptr),(q))

    /**
     * *ptr &= q;
     * return *ptr;
     */
#define sync_and_fetch(ptr,q) __sync_and_and_fetch((ptr),(q))

    /**
     * *ptr ^= q;
     * return *ptr;
     */
#define sync_xor_fetch(ptr,q) __sync_xor_and_fetch((ptr),(q))


    /**
     * *ptr = ~(*ptr & q);
     * return *ptr;
     */
#define sync_nand_fetch(ptr,q) __sync_nand_and_fetch((ptr),(q))

    /**
     * *ptr = (*ptr == oldval ? newval : *ptr);
     * return *ptr = newval;
     */
#define sync_try_cmpxchg(ptr,oldval,newval) __sync_bool_compare_and_swap(ptr,oldval,newval)

    /**
     * before = *ptr;
     * *ptr = (*ptr == oldval ? newval : *ptr);
     * return before;
     */
#define sync_try_cmpxchg_ex(ptr,oldval,newval) __sync_val_compare_and_swap(ptr,oldval,newval)


    /**
     * dead try to success
     * *ptr = (*ptr == oldval ? newval : *ptr);
     * return *ptr = newval;
     */
#define sync_cmpxchg(ptr,oldval,newval) ({ \
        while(true) { \
        if( sync_try_cmpxchg(ptr,oldval,newval)) break; \
        }\
        true; \
        })

    /**
     *  try to success by maxtrys
     * *ptr = (*ptr == oldval ? newval : *ptr);
     * return *ptr = newval;
     */
#define sync_trys_cmpxchg(ptr,oldval,newval,maxtrys) ({\
        int trys = 0;\
        typeof(maxtrys) mt = (maxtrys); \
        bool isok = false; \
        while((++trys) < mt) { \
        ecb_iif(sync_try_cmpxchg(ptr,oldval,newval),\
                { isok = true;break; }, \
                { cpu_pause(); }); \
                } \
                isok; \
                })

#define sync_mb() __sync_synchronize()
#define sync_rmb() __sync_synchronize()
#define sync_wmb() __sync_synchronize()

#define sync_set(ptr,p) __sync_lock_test_and_set(ptr,p)
#define sync_xchg(ptr,p) __sync_lock_test_and_set(ptr,p)
#define sync_rls(ptr) __sync_lock_release(ptr)


#ifdef __cplusplus
}
#endif


#endif
