"""Strict fixture for the chunk-growth routine at 0x6206e0."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, pystub, rnd


def g6206e0(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    s = rnd(c, 0x20)
    dispatch = rnd(c, 8)
    old = rnd(c, 0x500)
    free = rnd(c, 0x500)
    next_free = rnd(c, 0x40)
    reallocated = rnd(c, 0x1200)
    allocated = rnd(c, 0x1200)

    e.w32(s + 0x14, dispatch)
    mode = c.case & 7

    # Common valid old chunk.  The mode-specific fields below select every
    # allocation/reuse path, including both failure returns.
    old_capacity = 0x180
    e.w32(old + 4, old_capacity)
    e.w32(old, r.getrandbits(32))
    e.w32(free, next_free)
    e.w32(free + 4, 0x200)

    alloc_ret = 0
    realloc_ret = 0
    if mode == 0:                    # first chunk from the free list
        e.w32(s, old)
        e.w32(s + 4, free)
        e.w32(s + 8, 0)
        e.w32(s + 0x0c, r.getrandbits(32))
        e.w32(s + 0x10, 0)
    elif mode == 1:                  # free chunk is larger than, or equal to, the tail
        cursor = old + 8 + 0x20
        e.w32(s, old)
        e.w32(s + 4, free)
        e.w32(s + 8, old + 8 + 0x80)
        e.w32(s + 0x0c, old + 8)
        e.w32(s + 0x10, cursor)
        if c.case & 8:
            # Equality takes the allocation path in the original (signed jge).
            e.w32(free + 4, 0x60)
            e.w32(s + 0x0c, cursor + 0x20)
            alloc_ret = allocated
        else:
            e.w32(free + 4, 0x100)
    elif mode in (2, 3):             # an inadequate free block; realloc empty current
        cursor = old + 8
        e.w32(s, old)
        e.w32(s + 4, free)
        e.w32(s + 8, old + 8 + old_capacity)
        e.w32(s + 0x0c, cursor)
        e.w32(s + 0x10, cursor)
        e.w32(free + 4, 0)
        realloc_ret = reallocated if mode == 2 else 0
    elif mode in (4, 5):             # allocate a new chunk and copy the marked tail
        cursor = old + 8 + 0x40
        e.w32(s, old)
        e.w32(s + 4, 0)
        e.w32(s + 8, old + 8 + 0x100)
        e.w32(s + 0x0c, cursor + 0x20)
        e.w32(s + 0x10, cursor)
        alloc_ret = allocated if mode == 4 else 0
    else:                            # no current chunk: fresh allocation or failure
        e.w32(s, 0)
        e.w32(s + 4, 0)
        e.w32(s + 8, 0)
        e.w32(s + 0x0c, 0)
        e.w32(s + 0x10, 0)
        alloc_ret = allocated if mode == 6 else 0

    # These slots are caller-cleaned cdecl functions in the original.
    e.w32(dispatch, pystub(c, 1, ret=alloc_ret, pop=0))
    e.w32(dispatch + 4, pystub(c, 2, ret=realloc_ret, pop=0))

    def copy_side(emu, _k):
        dst, src, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.wbytes(dst, emu.rbytes(src, n))

    hook_rec(c, 0x634d22, 3, ret=lambda emu, _k: emu.arg32(0),
             pop=0, this=False, side=copy_side)
    return [s]


S(0x6206e0, 'grow_chunked_output_buffer', 'cdecl', None, ret='eax',
  gen=g6206e0, note='batch220007 hand port; free/reuse/realloc/alloc paths')
