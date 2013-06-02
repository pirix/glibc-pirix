int __brk(void* addr) {
    return 0;
}
weak_alias(__brk, brk)
