"""specs_s33088.py - h3 (Sonnet) batch 33088: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fl(c, lo=-10.0, hi=10.0):
    return F(c.fv(lo, hi, 0.25))


def _g4c99a0(c):
    clear_hooks(c)
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda em, k: c.fv(-10.0, 10.0, 0.25))
    s80 = pystub(c, 2, this=True)
    o = obj(c, 0x100, {0x80: s80})
    me = rnd(c, 0x80)
    c.emu.w32(me + 0x44, o)
    return [me, _w(c), rnd(c, 0x10)]


def _g45bda0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s44 = pystub(c, 2, this=True)
    rr = obj(c, 0x40, {0x44: s44})
    s20 = pystub(c, 0, this=True, ret=lambda em, k: rr)
    o = obj(c, 0x40, {0x20: s20})
    so = sysobj(c)
    e.w32(so + 0x190f, o)
    me = rnd(c, 0x280)
    i = r.randrange(0, 8)
    tab = rnd(c, 0x40)
    e.w32(me + 0x40, tab)
    x = r.choice([60.0, 60.0000076, 59.0, 100.0, 80.0, 1000.0, c.fv(0, 200, 0.1), float('nan'), 0.0])
    e.w32(me + i * 4 + 0x258, _b(x) if x == x else 0x7fc00000)
    f = r.choice([0.0, 0.25, 0.5, 1.0, 0.75, -1.0, 2.0, c.fv(-2, 3, 0.1), float('nan'), 0.4, 0.6, -0.0, -0.0])
    return [me, i, F(f) if f == f else F(float('nan'))]


def _setlog(c, argn):
    e = c.emu
    slog = pystub(c, argn, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _g5dd800(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _setlog(c, 3)
    sysobj(c)
    me = rnd(c, 0x60)
    w = r.getrandbits(16)
    e.wbytes(me + 0x48, struct.pack('<H', w))
    a = (w if r.random() < 0.7 else r.getrandbits(16)) | (r.getrandbits(16) << 16 if r.random() < 0.5 else 0)
    b = r.choice([0, 1, 2, 100, 199, 200, 201, 0xffffffff, 0x80000000, _w(c), r.getrandbits(8)])
    return [me, a, b]


S(0x4c99a0, 'GUESS read six floats then slot 0x80', 'thiscall', None, ret=None, gen=_g4c99a0, note='batch33088')
S(0x45bda0, 'GUESS ramp above 60 then slot 0x44 with clamped value', 'thiscall', None, ret=None, gen=_g45bda0, note='batch33088')
S(0x5dd800, 'GUESS set engine scale from percent when id matches', 'thiscall', None, ret='eax', gen=_g5dd800, note='batch33088')
