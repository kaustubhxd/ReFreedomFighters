"""specs_s33107.py - h3 () batch 33107: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _fl(c, lo=-10.0, hi=10.0):
    return F(c.fv(lo, hi, 0.25))


def _g5a3690(c):
    clear_hooks(c)
    r = c.rng
    cnt = r.randrange(1, 9)
    me = rnd(c, 4 + 16 * 24)
    c.emu.w32(me, cnt)
    mode = r.random()
    if mode < 0.4:
        i = r.randrange(0, 10)
        j = i
    else:
        j = r.randrange(0, cnt + 1)
        i = r.randrange(0, 10)
    return [me, i, j]


def _g504b60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        for p, n in ((em.arg32(0), 9), (em.arg32(1), 3)):
            for q in range(n):
                em.w32(p + 4 * q, _w(c))
    s80 = pystub(c, 2, this=True, stackmark=(0, 1), side=side)
    s37c = pystub(c, 7, this=True, deref={3: 9, 4: 3}, ret=lambda em, k: r.choice([0, 1, 0x100, 0xff, _w(c)]))
    o = obj(c, 0x400, {0x80: s80, 0x37c: s37c})
    me = rnd(c, 0x20)
    e.w32(me + 0x14, o)
    a = r.choice([0, 1, _w(c), _w(c)])
    return [me, a, _fl(c), _fl(c), _fl(c), _fl(c)]


S(0x5a3690, 'GUESS erase range from array of 16-byte entries', 'thiscall', None, ret=None, gen=_g5a3690, note='batch33107')
S(0x504b60, 'GUESS query with temp structs via two slots', 'thiscall', None, ret='eax', gen=_g504b60, note='batch33107')
