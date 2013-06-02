#include <unistd.h>
#include <sys/types.h>
#include <errno.h>

off_t __libc_lseek(int fd, off_t offset, int whence) {
    __set_errno(EBADF);
    return -1;
}

weak_alias(__libc_lseek, __lseek)
libc_hidden_def(__lseek)
weak_alias(__libc_lseek, lseek)
