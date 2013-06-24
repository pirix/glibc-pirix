#include <sys/syscall.h>

int __brk(void* addr) {
    return -1;
}
weak_alias(__brk, brk)
