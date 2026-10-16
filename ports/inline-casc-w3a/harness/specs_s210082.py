"""specs_s210082.py - Sonnet-w3a: 0x4cfbe0. Free-block stack at this+8 (count at this+0x1c8), packed counter at this+0x207, slot table at this+0xc628 (index at this+0xd628), the malloc import at IAT 0x6762f0 (stub returning an unaligned block), embedded object at this+0x1ea (packed vtable pointer) with slot 0, and the pool worker 0x4cfb30 hooked."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _ub(c, a, v): c.emu.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))


def g4cfbe0(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x4cfb30, 2, ret=_r(c), this=True)
    blk = rnd(c, 0x40)
    e.w32(0x6762f0, pystub(c, 1, ret=blk + c.rng.randrange(16), pop=0))
    vt = e.alloc(0x40, 4)
    e.w32(vt, pystub(c, 1, ret=_r(c), this=True))
    s = rnd(c, 0xd700)
    e.w32(s + 0x1c8, c.rng.choice([0, 0, 1, 2, 3]))
    _ub(c, s + 0x207, c.rng.choice([0, 5, 0x270f, 0x2710, 0x2711, _r(c)]))
    _ub(c, s + 0x1ea, vt)
    e.w32(s + 0xd628, c.rng.choice([0, 1, 5]))
    for i in range(8):
        e.w32(s + 0xc628 + 4 * i, rnd(c, 0x20))
    return [s]


S(0x4cfbe0, 'grow_pool_block', 'thiscall', None, ret='eax', gen=g4cfbe0, note='batch210082')
