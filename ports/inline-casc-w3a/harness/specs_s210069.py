"""specs_s210069.py - Sonnet-w3a: 0x6206e0. Struct of 6 dwords: block list head s0, free list s1, end s2, mark s3, cursor s4, allocator object s5 whose [0] / [1] are the malloc / realloc code pointers (recorder stubs, cdecl). Cursor states: null, block data start (in-place realloc path), elsewhere; free block sizes around the available span; memcpy hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def g6206e0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x634d22, 3, ret=_r(c), pop=0)
    newb = rnd(c, 0x40); e.w32(newb, _r(c)); e.w32(newb + 4, _r(c))
    nb2 = rnd(c, 0x40)
    mal = pystub(c, 1, ret=c.rng.choice([newb, newb, 0]), pop=0)
    rea = pystub(c, 2, ret=c.rng.choice([nb2, nb2, 0]), pop=0)
    al = rnd(c, 0x10); e.w32(al, mal); e.w32(al + 4, rea)
    cur = 0 if c.rng.random() < 0.15 else rnd(c, 0x40)
    if cur:
        e.w32(cur, _r(c)); e.w32(cur + 4, c.rng.choice([0x10, 0x100, 0x800, _r(c) & 0xfff]))
    free = 0 if c.rng.random() < 0.4 else rnd(c, 0x40)
    avail = c.rng.choice([0, 1, 0x10, 0x3ff, 0x400, 0x401, 0x800, 0xfffffff0, 0x7fffffff])
    if free:
        e.w32(free, _r(c))
        e.w32(free + 4, c.rng.choice([avail, (avail + 1) & 0xffffffff, (avail - 1) & 0xffffffff, 0x10, 0x80000000, _r(c) & 0xfff]))
    r = c.rng.random()
    if cur and r < 0.5:
        s4 = cur + 8
    elif r < 0.62:
        s4 = 0
    elif r < 0.68:
        s4 = 8
    else:
        s4 = (cur + 0x20) if cur else 0x20000
    s = rnd(c, 0x20)
    e.w32(s, cur); e.w32(s + 4, free)
    e.w32(s + 8, (s4 + avail) & 0xffffffff)
    e.w32(s + 0xc, (s4 + c.rng.choice([0, 4, 8, 0x10])) & 0xffffffff)
    e.w32(s + 0x10, s4); e.w32(s + 0x14, al)
    return [s]


S(0x6206e0, 'grow_block_buffer', 'cdecl', None, ret='eax', gen=g6206e0, note='batch210069')
