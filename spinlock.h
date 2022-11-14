#ifndef ECB_SPINLOCK_H
#define ECB_SPINLOCK_H

struct spinlock_s {
    char *name;
    volatile int lock;
}spinlock;

#define SPINLOCK_INIT(_name) { .name = _name,.lock = 0}

static inline bool spinlock_trylock(spinlock *spl,
        const int owner) {
    return sync_try_cmpxchg(&(spl->lock),0,owner);
}

static inline bool spinlock_tryslock(spinlock *spl,
        const int owner,
        const int maxtrys) {
    return sync_trys_cmpxchg(&(spl->lock),0,owner,maxtrys);
}

static inline void spinlock_lock(spinlock *spl,
        const int owner) {
    sync_cmpxchg(&(spl->lock),0,owner);
}

static inline bool spinlock_unlock(spinlock *spl,
        const int onwer) {
    return sync_cmpxchg(&(spl->lock),owner,0);
}

static inline void spinlock_rls(spinlock *spl) {
   sync_set(&(spl->lock),0); 
}

#endif
