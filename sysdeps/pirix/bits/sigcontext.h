#ifndef _SIGNAL_H
# error "Never use <bits/sigcontext.h> directly; include <signal.h> instead."
#endif

/* State of this thread when the signal was taken.  */
struct sigcontext {
    int sc_onstack;
    __sigset_t sc_mask;
    /* Registers and such.  */
    int sc_pc;
};
