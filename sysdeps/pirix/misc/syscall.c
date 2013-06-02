#include <stdarg.h>
#include <sys/syscall.h>

long int syscall(long int num, ...) {
    va_list vl;
    va_start(vl, num);
    long int a = va_arg(vl, long int);
    long int b = va_arg(vl, long int);
    long int c = va_arg(vl, long int);
    long int d = va_arg(vl, long int);
    va_end(vl);

    return pirix_syscall(num, a, b, c, d);
}
