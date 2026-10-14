"""specs_s33090.py - h3 () batch 33090: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fb(c, lo=-10.0, hi=10.0):
    return _b(c.fv(lo, hi, 0.25))


def _g5da670(c):
    clear_hooks(c)
    e = c.emu
    s23c = pystub(c, 1, this=True, deref={0: 4})
    o = obj(c, 0x20, {0x23c: s23c})
    me = rnd(c, 0x90)
    for off in (0x76, 0x7a, 0x7e, 0x82):
        e.w32(me + off, _fb(c))
    v = rnd(c, 0x10)
    for i in range(4):
        e.w32(v + 4 * i, _fb(c))
    return [me, o, v]


def _g523330(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x460b60, 2, this=True)
    hook_rec(c, 0x4e0d00, 1, this=True)
    hook_rec(c, 0x44c840, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    s88 = pystub(c, 1, this=True)
    s = obj(c, 0x40, {0x88: s88})
    me = rnd(c, 0x60)
    e.w32(me + 0x4b, s if r.random() < 0.8 else 0)
    return [me, rnd(c, 0x10)]


def _g519e00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    p = rnd(c, 8)
    e.w32(p, _fb(c))
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: p)
    fv = lambda em, k: c.fv(-10.0, 10.0, 0.25)
    s10 = pystub(c, 0, this=True, st0=fv)
    s14 = pystub(c, 0, this=True, st0=fv)
    sc = pystub(c, 1, this=True, st0=fv)
    inner = obj(c, 0x20, {0x10: s10, 0x14: s14, 0xc: sc})
    s2f8 = pystub(c, 1, this=True)
    q = obj(c, 0x80, {0x2f8: s2f8})
    e.w32(q + 0x5c, inner)
    me = rnd(c, 0x20)
    e.w32(me + 0x14, q)
    arg = rnd(c, 0x10)
    return [me, arg]


S(0x5da670, 'GUESS build barycentric-like vec4 and slot 0x23c', 'thiscall', None, ret=None, gen=_g5da670, note='batch33090')
S(0x523330, 'GUESS compute normalized direction or default', 'thiscall', None, ret=None, gen=_g523330, note='batch33090')
S(0x519e00, 'GUESS ratio of values to float then slot 0x2f8', 'thiscall', None, ret=None, gen=_g519e00, note='batch33090')
