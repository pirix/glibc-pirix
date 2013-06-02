#ifndef _TLS_H
#define _TLS_H

#ifndef __ASSEMBLER__

#include <stddef.h>
#include <stdbool.h>

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
} tcbhead_t;

typedef struct pthread {
    tcbhead_t header;
} pthread_t;

#define TLS_INIT_TCB_SIZE sizeof(tcbhead_t)
#define TLS_INIT_TCB_ALIGN __alignof__(tcbhead_t)
#define TLS_TCB_SIZE TLS_INIT_TCB_SIZE
#define TLS_TCB_ALIGN TLS_INIT_TCB_ALIGN

#endif /* !ASSEMBLER */

#endif /* tls.h */
