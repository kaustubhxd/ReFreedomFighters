"""specs_s33105.py - h3 (Sonnet) batch 33105: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fl(c, lo=-10.0, hi=10.0):
    return F(c.fv(lo, hi, 0.25))


def _g464650(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s288 = pystub(c, 5, this=True, ret=lambda em, k: _w(c))
    me_obj = obj(c, 0x300, {0x288: s288})
    s18 = pystub(c, 1, this=True)
    o = obj(c, 0x40, {0x18: s18})
    e.w32(me_obj + 0x6c, o)
    a = rnd(c, 0x70)
    b = rnd(c, 0x70)
    return [me_obj, a, _fl(c), b, _fl(c), _fl(c), _fl(c)]


def _g5246a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ep = rnd(c, 0x10)
    gp = rnd(c, 0x10)
    base = r.choice([0.0, 1.0, -2.0, c.fv(-5, 5, 0.1)])
    delta = r.choice([0.0, 0.0, 1.0, -1.0, 0.5, c.fv(-3, 3, 0.1)])
    e.w32(ep, _b(base + delta) if (base + delta) == (base + delta) else 0x7fc00000)
    e.w32(gp, _b(base))
    me = rnd(c, 0x30)
    e.w32(me + 0x18, ep)
    e.w32(me + 0x1c, gp)
    for off in (0x4, 0x8, 0xc, 0x10, 0x14):
        e.w32(me + off, _b(c.fv(-4, 4, 0.1)))
    return [me, _fl(c, -3, 3)]


S(0x464650, 'GUESS two scaled vertex queries via slot 0x288', 'thiscall', None, ret=None, gen=_g464650, note='batch33105')
S(0x5246a0, 'GUESS spring-like transfer between two values', 'thiscall', None, ret='st0', gen=_g5246a0, nan_heap=True, note='batch33105')
