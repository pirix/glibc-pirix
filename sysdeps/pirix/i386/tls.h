#ifndef _I386_TLS_H
#define _I386_TLS_H

#include <sysdeps/pirix/tls.h>

#define TLS_TCB_AT_TP 1

#define THREAD_SETMEM(descr, member, value) (0)
#define THREAD_GETMEM(descr, member) (0)

#define INSTALL_DTV(descr, dtvp)                \
    ((tcbhead_t*) (descr))->dtv = (dtvp) + 1

#define INSTALL_NEW_DTV(dtvp) (0)

#define GET_DTV(descr)                          \
    (((tcbhead_t*) (descr))->dtv)

#define THREAD_DTV() (0)

#define THREAD_SELF 0

#define TLS_INIT_TP(tcb, firstcall) (0)

#define STACK_ALIGN 16

#define THREAD_GSCOPE_FLAG_UNUSED 0
#define THREAD_GSCOPE_FLAG_USED   1
#define THREAD_GSCOPE_FLAG_WAIT   2
#define THREAD_GSCOPE_RESET_FLAG() (0)
#define THREAD_GSCOPE_SET_FLAG() (0)
#define THREAD_GSCOPE_WAIT() (0)

#endif /* _I386_TLS_H */
