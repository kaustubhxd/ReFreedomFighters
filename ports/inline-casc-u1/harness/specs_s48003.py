"""specs_s48003.py - tier H. 0x6368d0: this = {count at +0x10, record array at +0x14}; records of 0x14 bytes with w (+4), h (+8) and a random pixel buffer (+0x10); float arg t around 0..1 and edge values; ext 0x636540 runs unhooked."""
from pilot import S, F, EDGE_F
from recruits_util import rnd, clear_hooks


def _g6368d0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    n = r.choice([0, 1, 1, 2, 3, 0xffffffff])
    recs = em.alloc(0x14 * 4 + 4, 4)
    em.wbytes(recs, bytes(r.getrandbits(8) for _ in range(0x14 * 4)))
    dims = [0, 1, 3, 4, 5, 8, 9, 12, 16, 17, 20, 24]
    for i in range(4):
        w = r.choice(dims + [0xfffffff0, 0xfffffffd])
        h = r.choice(dims + [0xfffffff0, 0xfffffffd])
        buf = rnd(c, 0x500)
        if r.random() < 0.1:
            buf += 2
        base = recs + 0x14 * i
        em.w32(base + 4, w)
        em.w32(base + 8, h)
        em.w32(base + 0x10, buf)
    me = rnd(c, 0x40)
    em.w32(me + 0x10, n)
    em.w32(me + 0x14, recs)
    k = r.random()
    if k < 0.15:
        t = r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 1e-7, 0.999999, 1e-40, 100.0])
    else:
        t = r.uniform(-0.5, 1.5) if r.random() < 0.8 else r.uniform(-4, 4)
    return [me, F(t)]


S(0x6368d0, 'GUESS desaturate and order RGB565 pairs of block images', 'thiscall', None, ret=None, gen=_g6368d0, nan_heap=True, note='batch48003')
