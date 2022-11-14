#ifndef ECB_ATOMIC_H
#define ECB_ATOMIC_H


typedef struct {  
    volatile int cnt;  
} atomic_t;

#define ATOMIC_INIT(i)  { (i) }  

/**
 * atomic_read - read atomic variable
 * @v: pointer of type atomic_t
 *
 * Atomically reads the value of @v.
 */
static inline int atomic_read(const atomic_t *v)
{
	return READ_ONCE((v)->cnt);
}

/**
 * atomic_set - set atomic variable
 * @v: pointer of type atomic_t
 * @i: required value
 *
 * Atomically sets the value of @v to @i.
 */
static inline void atomic_set(atomic_t *v, int i)
{
       // v->cnt = i;
       WRITE_ONCE(v->cnt,i);
}

/**
 * atomic_inc - increment atomic variable
 * @v: pointer of type atomic_t
 *
 * Atomically increments @v by 1.
 */
static inline void atomic_incr(atomic_t *v)
{
    sync_incr_fetch(&(v->cnt));
}

static inline void atomic_add(atomic_t *v,int q) {
    sync_add_fetch(&(v->cnt),q);
}
/**
 * atomic_dec_and_test - decrement and test
 * @v: pointer of type atomic_t
 *
 * Atomically decrements @v by 1 and
 * returns true if the result is 0, or false for all other
 * cases.
 */
static inline int atomic_decr_and_test(atomic_t *v)
{
    return sync_decr_fetch(&(v->cnt)) == 0;
}

static inline int atomic_incr_and_test(atomic_t *v) {
    return sync_incr_fetch(&(v->cnt)) == 0 ;

static inline void atomic_decr(atomic_t *v) {
    sync_decr_fetch(&(v->cnt));
}

static inline void atomic_sub(atomic_t *v,int  q) {
    sync_sub_fetch(&(v->cnt),q);
}

static inline int atomic_add_ex(atomic_t *v,int q) {
    return sync_add_fetch(&(v->cnt),q);
}

static inline int atomic_sub_ex(atomic_t *v,int q) {
    return sync_sub_fetch(&(v->cnt),q);
}



#define cmpxchg(ptr, oldval, newval) \
	__sync_val_compare_and_swap(ptr, oldval, newval)

static inline int atomic_cmpxchg(atomic_t *v, int oldval, int newval)
{
	return cmpxchg(&(v)->cnt, oldval, newval);
}

/** 
 * atomic_add_unless - add unless the number is already a given value 
 * @v: pointer of type atomic_t 
 * @a: the amount to add to v... 
 * @u: ...unless v is equal to u. 
 * 
 * Atomically adds @a to @v, so long as @v was not already @u. 
 * Returns non-zero if @v was not @u, and zero otherwise. 
 */  
static inline int atomic_add_unless(atomic_t *v, int q, int u)  {  
    int c, old;  
    c = atomic_read(v);  
    for (;;) {  
        if (unlikely(c == (u)))  
            break;  
        old = atomic_cmpxchg((v), c, c + (q));  
        if (likely(old == c))  
            break;  
        c = old;  
    }  
    return c != (u);  
}  


#define atomic_incr_not_zero(v) atomic_add_unless((v), 1, 0)  
  
#define atomic_incr_ex(v)  (atomic_add_ex(1, v))  
#define atomic_decr_ex(v)  (atomic_sub_ex(1, v))

static inline int atomic_add_isneg(atomic_t *v,int q)  {  
    return sync_add_fetch(&(v->cnt),q) < 0;
}  


#endif
