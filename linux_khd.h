#ifndef LINUX_KHD_H
#define LINUX_KHD_H


/* Optimization barrier */
/* The "volatile" is due to gcc bugs */
#ifndef barrier
#define barrier() __asm__ __volatile__("": : :"memory")
#endif

#ifndef mb
#define mb()		__asm__ __volatile__ ("synco": : :"memory")
#endif

static __always_inline void __read_once_size(const volatile void *p, void *res, int size)
{
	switch (size) {
	case 1: *(u8  *) res = *(volatile u8  *) p; break;
	case 2: *(u16 *) res = *(volatile u16 *) p; break;
	case 4: *(u32 *) res = *(volatile u32 *) p; break;
	case 8: *(u64 *) res = *(volatile u64 *) p; break;
	default:
		barrier();
		__builtin_memcpy((void *)res, (const void *)p, size);
		barrier();
	}
}

static __always_inline void __write_once_size(volatile void *p, void *res, int size)
{
	switch (size) {
	case 1: *(volatile  u8 *) p = *(u8  *) res; break;
	case 2: *(volatile u16 *) p = *(u16 *) res; break;
	case 4: *(volatile u32 *) p = *(u32 *) res; break;
	case 8: *(volatile u64 *) p = *(u64 *) res; break;
	default:
		barrier();
		__builtin_memcpy((void *)p, (const void *)res, size);
		barrier();
	}
}

/*
 * Prevent the compiler from merging or refetching reads or writes. The
 * compiler is also forbidden from reordering successive instances of
 * READ_ONCE and WRITE_ONCE, but only when the compiler is aware of some
 * particular ordering. One way to make the compiler aware of ordering is to
 * put the two invocations of READ_ONCE or WRITE_ONCE in different C
 * statements.
 *
 * These two macros will also work on aggregate data types like structs or
 * unions. If the size of the accessed data type exceeds the word size of
 * the machine (e.g., 32 bits or 64 bits) READ_ONCE() and WRITE_ONCE() will
 * fall back to memcpy and print a compile-time warning.
 *
 * Their two major use cases are: (1) Mediating communication between
 * process-level code and irq/NMI handlers, all running on the same CPU,
 * and (2) Ensuring that the compiler does not fold, spindle, or otherwise
 * mutilate accesses that either do not require ordering or that interact
 * with an explicit memory barrier or atomic instruction that provides the
 * required ordering.
 */

#define READ_ONCE(x)					\
({							\
	union { typeof(x) __val; char __c[1]; } __u =	\
		{ .__c = { 0 } };			\
	__read_once_size(&(x), __u.__c, sizeof(x));	\
	__u.__val;					\
})

#define WRITE_ONCE(x, val)				\
({							\
	union { typeof(x) __val; char __c[1]; } __u =	\
		{ .__val = (val) }; 			\
	__write_once_size(&(x), __u.__c, sizeof(x));	\
	__u.__val;					\
})

#ifndef smp_store_release
# define smp_store_release(p, v)		\
do {						\
	mb();				\
	WRITE_ONCE(*p, v);			\
} while (0)
#endif

#define LIST_POISON1 NULL
#define LIST_POISON2 NULL


/**
 *  use for lock-free 
 *  cpu exec "pause" command but not sleep
 */
static inline void rep_nop(void) {
    asm volatile("rep; nop" ::: "memory");
}

#define cpu_relax() rep_nop()
#define cpu_puase() rep_nop()

static inline void sched_yield() {
    usleep(1);
}

/**
 * get all cpu core count
 */
static inline int get_all_cpus(void) {
    return sysconf( _SC_NPROCESSORS_CONF );
}

/**
 * get usable  cpu core count
 */
static inline int get_usable_cpus(void) {
    return sysconf( _SC_NPROCESSORS_ONLN );
}

#endif
