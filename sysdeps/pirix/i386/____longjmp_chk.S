.extern __longjmp
.global ____longjmp_chk
____longjmp_chk:
    jmp __longjmp
