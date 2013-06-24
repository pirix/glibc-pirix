#ifndef _TLS_H
#define _TLS_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef union dtv {
    size_t counter;
    struct {
        void* val;
        bool is_static;
    } pointer;
} dtv_t;

typedef struct {
    void* tcb;
    dtv_t* dtv;
    void* self;
    int multiple_threads;
    uintptr_t sysinfo;
    uintptr_t stack_guard;
    uintptr_t pointer_guard;
    int gscope_flag;
} tcbhead_t;

typedef struct pthread {
    tcbhead_t header;
} pthread_t;

#define TLS_INIT_TCB_SIZE sizeof(struct pthread)
#define TLS_INIT_TCB_ALIGN __alignof__(struct pthread)
#define TLS_TCB_SIZE TLS_INIT_TCB_SIZE
#define TLS_TCB_ALIGN TLS_INIT_TCB_ALIGN
#define TLS_MULTIPLE_THREADS_IN_TCB 1

#endif /* tls.h */
