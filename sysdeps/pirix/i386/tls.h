#ifndef _I386_TLS_H
#define _I386_TLS_H

#ifndef __ASSEMBLER__

#include <sysdeps/pirix/tls.h>
#include <arch/i386/tls.h>
#include <sys/syscall.h>
#include <libc-internal.h>

/*
 * The TCB can have any size and the memory following the address the
 * thread pointer points to is unspecified.  Allocate the TCB there.
 */
#define TLS_TCB_AT_TP 1

#define THREAD_OFFSET(member) (offsetof(struct pthread, member))

/* Read member of the thread descriptor directly.  */
#define THREAD_GETMEM(descr, member) ({                                 \
     __typeof(descr->member) __value;                                   \
    if (sizeof(__value) == 1)                                           \
        asm volatile("movb %%gs:%P2, %b0"                               \
                     : "=q" (__value)                                   \
                     : "0" (0), "i" THREAD_OFFSET(member));             \
    else if (sizeof(__value) == 4)                                      \
        asm volatile("movl %%gs:%P1, %0"                                \
                     : "=r" (__value)                                   \
                     : "i" THREAD_OFFSET(member));                      \
    else if (sizeof(__value) == 8)                                      \
        asm volatile("movl %%gs:%P1, %%eax\n\t"                         \
                     "movl %%gs:%P2, %%edx"                             \
                     : "=A" (__value)                                   \
                     : "i" THREAD_OFFSET(member),                       \
                       "i" (THREAD_OFFSET(member) + 4));                \
    else abort();                                                       \
    __value;                                                            \
})

/* Set member of the thread descriptor directly.  */
#define THREAD_SETMEM(descr, member, value) ({                          \
    if (sizeof(descr->member) == 1)                                     \
        asm volatile("movb %b0, %%gs:%P1" :                             \
                     : "iq" (value),                                    \
                       "i" THREAD_OFFSET(member));                      \
    else if (sizeof(descr->member) == 4)                                \
        asm volatile("movl %0,%%gs:%P1" :                               \
                     : "ir" (value),                                    \
                       "i" THREAD_OFFSET(member));                      \
    else if (sizeof(descr->member) == 8)                                \
        asm volatile("movl %%eax,%%gs:%P1\n\t"                          \
                     "movl %%edx,%%gs:%P2" :                            \
                     : "A" ((uint64_t)cast_to_integer(value)),          \
                       "i" THREAD_OFFSET(member),                       \
                       "i" (THREAD_OFFSET(member) + 4));                \
    else abort();                                                       \
})

/*
 * Install the dtv pointer.  The pointer passed is to the element with
 * index -1 which contain the length.
 */
#define INSTALL_DTV(descr, dtvp) ((tcbhead_t*)(descr))->dtv = (dtvp) + 1

/*
 * Install new dtv for current thread.
 */
#define INSTALL_NEW_DTV(dtvp) ({                        \
    struct pthread* __pd;                               \
    THREAD_SETMEM(__pd, header.dtv, (dtvp));            \
})

/*
 * Return dtv of given thread descriptor.
 */
#define GET_DTV(descr) (((tcbhead_t*) (descr))->dtv)

/*
 * Return the address of the dtv for the current thread.
 */
#define THREAD_DTV() ({                         \
    struct pthread *__pd;                       \
    THREAD_GETMEM(__pd, header.dtv);            \
})

/*
 * Return the thread descriptor for the current thread.
 */
#define THREAD_SELF ({                          \
    struct pthread *__self;                     \
    asm ("movl %%gs:%c1, %0" : "=r" (__self)    \
         : "i" THREAD_OFFSET(header.self));     \
    __self;                                     \
})

/*
 * Macros to load from and store into segment registers.
 */
#ifndef TLS_GET_GS
#define TLS_GET_GS() ({                         \
    int __seg;                                  \
    __asm("movw %%gs, %w0" : "=q" (__seg));     \
    __seg & 0xffff;                             \
})
#endif

#ifndef TLS_SET_GS
#define TLS_SET_GS(val) \
    __asm("movw %w0, %%gs" :: "q" (val))
#endif


#define TLS_INIT_TP(thrdescr, secondcall) ({                           \
    void* _thrdescr = (thrdescr);                                      \
    tcbhead_t* head = _thrdescr;                                       \
    struct tls_desc _desc;                                             \
                                                                       \
    head->tcb = _thrdescr;                                             \
    head->self = _thrdescr;                                            \
                                                                       \
    /* base addr */                                                    \
    _desc.base = (unsigned long)_thrdescr;                             \
                                                                       \
    /* limit 4GB (0xfffff pages) */                                    \
    _desc.limit = 0xfffff;                                             \
                                                                       \
    int res = pirix_syscall(SYS_TLS_SET, &_desc, 0, 0, 0);             \
                                                                       \
    if (res) TLS_SET_GS(res);                                          \
                                                                       \
    res == 0 ? "tls_set failed" : NULL;                                \
})

#define STACK_ALIGN 16

#define THREAD_GSCOPE_FLAG_UNUSED 0
#define THREAD_GSCOPE_FLAG_USED   1
#define THREAD_GSCOPE_FLAG_WAIT   2
#define THREAD_GSCOPE_RESET_FLAG() (0)
#define THREAD_GSCOPE_SET_FLAG() (0)
#define THREAD_GSCOPE_WAIT() (0)

#endif /* !ASSEMBLER */

#endif /* _I386_TLS_H */
