"""specs_s35010.py - 0x434fb0. [this+4] = container (null in 1/6) with slots 0x4c, 0x44 (out param, flag-recorded), 0x64 (hands out 0..3 pointers to a word holding an item, then 0), 0x14 (zero in half;
may clear [this+4] in 1/6), 0 (delete); items have slots 0x38 (0 args) and 0x30 (1 arg)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g434fb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x20)
    m = r.choice([0, 1, 2, 3])
    ptrs = []
    for _ in range(m):
        s = obj(c, 0x20, {0x38: pystub(c, 0, this=True), 0x30: pystub(c, 1, this=True)}, nslots=0x20)
        b = rnd(c, 8)
        e.w32(b, s)
        ptrs.append(b)

    def s14(em, k):
        if r.random() < 1 / 6:
            em.w32(me + 4, 0)
    z = 0 if r.random() < 0.5 else r.getrandbits(32) | 1
    cont = obj(c, 0x20, {0x4c: pystub(c, 1, nullflag=(0,), this=True), 0x44: pystub(c, 1, nullflag=(0,), this=True),
                         0x64: pystub(c, 1, nullflag=(0,), this=True, ret=lambda em, k: ptrs[k] if k < len(ptrs) else 0),
                         0x14: pystub(c, 0, ret=z, this=True, side=s14), 0: pystub(c, 1, this=True)}, nslots=0x20)
    e.w32(me + 4, 0 if r.random() < 1 / 6 else cont)
    return [me]


S(0x434fb0, 'GUESS release container and items', 'thiscall', None, ret=None, gen=_g434fb0, note='batch35010')
