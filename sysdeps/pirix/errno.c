#include <errno.h>
#include <dl-sysdep.h>
#undef errno

#if RTLD_PRIVATE_ERRNO

int rtld_errno attribute_hidden;
#define errno rtld_errno

#else

__thread int errno;
extern __thread int __libc_errno __attribute__ ((alias ("errno")))
  attribute_hidden;

#endif

int* __errno_location(void) {
  return &errno;
}
libc_hidden_def(__errno_location)
