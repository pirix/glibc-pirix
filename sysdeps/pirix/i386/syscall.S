.text
.global __pirix_syscall
__pirix_syscall:
    push %ebp
    movl %esp, %ebp
    push %ebx
    push %edi
    movl 24(%ebp), %edx
    movl 20(%ebp), %ecx
    movl 16(%ebp), %ebx
    movl 12(%ebp), %eax
    movl 8(%ebp), %edi
    int $0x80
    pop %edi
    pop %ebx
    leave
    ret
