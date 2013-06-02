#ifdef _SIGNAL_H

#include <pirix/signum.h>

#define SIG_ERR ((__sighandler_t) -1)
#define SIG_DFL ((__sighandler_t) 0)
#define SIG_IGN ((__sighandler_t) 1)
#ifdef __USE_UNIX98
# define SIG_HOLD ((__sighandler_t) 2)
#endif

#define SIGRTMIN (__libc_current_sigrtmin())
#define SIGRTMAX (__libc_current_sigrtmax())

#define _NSIG     65
#define __SIGRTMIN 32
#define __SIGRTMAX (_NSIG - 1)

#endif
