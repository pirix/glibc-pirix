#include <sys/syscall.h>

int __sbrk(int inc) {
    return pirix_syscall(SYS_SBRK, inc, 0, 0, 0);
}
libc_hidden_def(__sbrk)
weak_alias(__sbrk, sbrk)
