#include <sys/syscall.h>

int __getpid() {
    return pirix_syscall(SYS_GETPID, 0, 0, 0, 0);
}
libc_hidden_def(__getpid)
weak_alias(__getpid, getpid)
libc_hidden_weak(getpid)
