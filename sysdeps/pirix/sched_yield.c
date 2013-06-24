#include <errno.h>
#include <sched.h>
#include <sys/syscall.h>

int __sched_yield(void) {
    return pirix_syscall(SYS_YIELD, 0, 0, 0, 0);
}
libc_hidden_def(__sched_yield)
weak_alias(__sched_yield, sched_yield)
