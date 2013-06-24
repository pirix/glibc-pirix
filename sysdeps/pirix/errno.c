#include <errno.h>
#include <dl-sysdep.h>
#undef errno

__thread int errno;
extern __thread int __libc_errno __attribute__((alias ("errno")))
  attribute_hidden;

int* __errno_location(void) {
  return &errno;
}
libc_hidden_def(__errno_location)
