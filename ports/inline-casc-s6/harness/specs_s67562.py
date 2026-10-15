"""specs_s67562.py - cascade s6 batch 67562 (0x52d080, thiscall() plain ret, return value unused). Each of the thirteen pointer fields is zero or a heap pointer; 0x634273 (free) is a custom hook that
logs every (pointer, class) pair in the call log (the stock recorder keeps only 8 rows)."""
from pilot import S
from recruits_util import rnd, clear_hooks


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g52d080(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def fr(em, res_):
        em.calllog.append(('free', em.arg32(0), em.arg32(1)))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, fr)
    t = rnd(c, 0xa0)
    for off in (0x54, 0x5a, 0x60, 0x66, 0x6c, 0x72, 0x78, 0x82, 0x98, 0x88, 0x8c, 0x90, 0x7c):
        _w(c, t + off, rnd(c, 8) if r.random() < 0.6 else 0)
    return [t]


S(0x52d080, 'GUESS destroy_blocks', 'thiscall', None, ret=None, gen=_g52d080, note='batch67562')
