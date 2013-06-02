#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>

ssize_t __libc_write (int fd, const void* buf, size_t nbytes) {
    if (fd == 1) {
        pirix_syscall(SYS_PRINT, buf, nbytes, 0, 0);
    }
    return nbytes;
}
libc_hidden_def(__libc_write)

weak_alias(__libc_write, __write)
libc_hidden_weak(__write)
weak_alias(__libc_write, write)
