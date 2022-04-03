// __malloc_hook
void *__libc_malloc(size_t bytes)
{
    mstate ar_ptr;
    void *victim;
    void *(*hook)(size_t, const void *) = atomic_forced_read(__malloc_hook); // malloc hook read
    if (__builtin_expect(hook != NULL, 0))
        return (*hook)(bytes, RETURN_ADDRESS(0)); // call hook
#if USE_TCACHE
    /* int_free also calls request2size, be careful to not pad twice.  */
    size_t tbytes;
    checked_request2size(bytes, tbytes);
    size_t tc_idx = csize2tidx(tbytes);
    // ...
}
