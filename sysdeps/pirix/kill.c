#include <sys/syscall.h>
#include <errno.h>

int __kill(int pid, int sig) {
    if (pid < 0) {
        __set_errno(ENOSYS);
        return -1;
    }

    return pirix_syscall(SYS_KILL, pid, sig, 0, 0);
}
weak_alias(__kill, kill)
