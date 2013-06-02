#ifndef _SYSCALL_H
#define _SYSCALL_H

#include <pirix/syscall.h>

#define pirix_syscall(num, a, b, c, d) __pirix_syscall(num, (int)a, (int)b, (int)c, (int)d)
int __pirix_syscall(int num, int a, int b, int c, int d);

#endif
