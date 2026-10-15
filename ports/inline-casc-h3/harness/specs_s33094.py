"""specs_s33094.py - h3 (Sonnet) batch 33094: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _g545e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    slog = pystub(c, 2, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))
    n = r.choice([1, 2, 4, 8])
    tab = rnd(c, 0x34 * 8 + 0x10)
    me = rnd(c, 0x40)
    e.w32(me + 0x28, n)
    e.w32(me + 0xf, tab)
    i = r.choice([0, 1, n - 1, n, n + 1, -1, 0x80000000, 0x7fffffff, r.randrange(0, 8)])
    if i in (n - 1,) or 0 <= i < n:
        i = i % 8
    return [me, i & 0xffffffff, rnd(c, 0x10), rnd(c, 0x10), _w(c)]


S(0x545e60, 'GUESS store segment endpoints into table entry i', 'thiscall', None, ret=None, gen=_g545e60, note='batch33094')
