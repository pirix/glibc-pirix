#include <unistd.h>
#include <errno.h>

int __getpagesize(void) {
    return 0x1000;
}
libc_hidden_def(__getpagesize)
weak_alias(__getpagesize, getpagesize)
