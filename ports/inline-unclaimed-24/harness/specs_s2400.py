"""specs_s2400.py - decomp area 24, batch 2400: zstd::vector<CSprite2D::tagSPRITE2DINFO*>::_M_insert_aux (0x5fe3b0).
The vector: begin/finish/end in a heap object; elements are 4-byte pointers; the insert position is inside
[begin, finish] or at finish; the value is a pointer-sized value behind a pointer. The allocator (0x6014a0, stdcall
ret 4) is a hook that allocates from the heap; the free (0x54f870, ret 8) is a recorder that logs (ptr, bytes)."""
import random
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks
import recruits_util as ru


def _alloc_hook(c):
    e = c.emu

    def h(em, rr):
        size = em.arg32(0)
        p = em.alloc(max(size, 4), 16)
        em.ret(p, 4)
    e.hook(0x6014a0, h)
    ru._HOOKED.add(0x6014a0)


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _alloc_hook(c)
    hook_rec(c, 0x54f870, 2, this=True)
    cap = r.randint(1, 10)
    blk = e.alloc(4 * cap, 16)
    length = r.randint(0, cap)
    if r.random() < 0.3:
        length = cap   # the no-room path
    vec = rnd(c, 0x20)
    e.w32(vec, blk)
    e.w32(vec + 4, blk + 4 * length)
    e.w32(vec + 8, blk + 4 * cap)
    for i in range(cap):
        e.w32(blk + 4 * i, r.getrandbits(32))
    pos = blk + 4 * r.randint(0, length)
    val = rnd(c, 8)
    e.w32(val, r.getrandbits(32))
    return [vec, pos, val]


S(0x5fe3b0, 'zstd::vector<CSprite2D::tagSPRITE2DINFO*>::_M_insert_aux', 'thiscall', None, gen=_gen, note='batch2400')
