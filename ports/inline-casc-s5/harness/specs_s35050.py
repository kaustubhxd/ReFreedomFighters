"""specs_s35050.py - 0x4fc9e0 (thiscall, no args). [[this+0x44]+0x18] = list L (null in 1/6; slots 0x4c, 0x5c (flag-recorded out param; iterator's first dword zeroed after 0..3 calls, non-zero at the start in 4/5));
0x41e290 hooked (cdecl, 1 arg) returning fresh 0x20-byte blocks (null in 1/5 of the calls); [this+0x4c] tail: null in a half, else a heap node; object random bytes."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _g4fc9e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [0 if r.random() < 0.2 else rnd(c, 0x20) for _ in range(4)]
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: blocks[min(k, 3)])
    m = 0 if r.random() < 0.2 else r.choice([1, 2, 3])
    seq = [r.getrandbits(32) for _ in range(5)]

    def s5c(em, k):
        em.w32(em.arg32(0), 0 if k >= m else r.getrandbits(32) | 1)
    L = 0 if r.random() < 1 / 6 else obj(c, 0x10, {0x4c: pystub(c, 1, nullflag=(0,), this=True),
                                                    0x5c: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: seq[min(k, 4)], side=s5c)}, nslots=0x20)
    mid = rnd(c, 0x40)
    e.w32(mid + 0x18, L)
    me = rnd(c, 0x60)
    e.w32(me + 0x44, mid)
    e.w32(me + 0x4c, 0 if r.random() < 0.5 else rnd(c, 0x20))
    return [me]


S(0x4fc9e0, 'GUESS append list node per source entry', 'thiscall', None, ret=None, gen=_g4fc9e0, note='batch35050')
