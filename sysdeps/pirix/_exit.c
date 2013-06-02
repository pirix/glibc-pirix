#include <sys/syscall.h>

void _exit(int status) {
    pirix_syscall(SYS_EXIT, status, 0, 0, 0);
    while(1);
}
libc_hidden_def(_exit)
weak_alias(_exit, _Exit)
