"""specs_s67559.py - cascade s6 batch 67559 (0x639fb0, thiscall() plain ret, no return value). this[0x10] levels (0..3) of 0x14 bytes at this[0x14] with width +4, height +8 (small, powers of two and
others) and a data pointer +0x10; 0x638ea0 (Morton masks) runs unhooked; 0x41e290 (alloc) returns a zero-filled spec buffer in turn (requested size logged), 0x634d22 (memcpy) performs and logs the copy,
0x634273 (free) is a hook."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g639fb0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    bufs = []
    for _ in range(4):
        b = e.alloc(0x400, 4)
        e.wbytes(b, bytes(r.getrandbits(8) for _ in range(0x400)))
        bufs.append(b)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: bufs[min(k, 3)])

    def cp(em, k):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(d, em.rbytes(s, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    hook_rec(c, 0x634273, 2, pop=0)
    n = r.choice([-1, 0, 1, 1, 2, 3])
    lv = e.alloc(0x14 * 4 + 4, 4)
    e.wbytes(lv, bytes(0x14 * 4 + 4))
    for i in range(max(n, 0)):
        w = r.choice([1, 2, 4, 8, 16, 3, 5, 6])
        h = r.choice([1, 2, 4, 8, 16, 3, 7])
        data = e.alloc(w * h + 4, 4)
        e.wbytes(data, bytes(r.getrandbits(8) for _ in range(w * h + 4)))
        _w(c, lv + 0x14 * i + 4, w)
        _w(c, lv + 0x14 * i + 8, h)
        _w(c, lv + 0x14 * i + 0x10, data)
    t = rnd(c, 0x30)
    _w(c, t + 0x10, n)
    _w(c, t + 0x14, lv)
    return [t]


S(0x639fb0, 'GUESS swizzle_levels', 'thiscall', None, ret=None, gen=_g639fb0, note='batch67559')
