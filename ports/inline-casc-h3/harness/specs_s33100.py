"""specs_s33100.py - h3 () batch 33100: tier H float/SSE functions."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c):
    return c.rng.getrandbits(32)


def _b(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _setlog(c, argn):
    e = c.emu
    slog = pystub(c, argn, pop=0, ret=lambda em, k: _w(c))
    robj = obj(c, 0x80, {0x2c: slog})
    s20 = pystub(c, 2, this=True, ret=lambda em, k: robj)
    e.w32(0x700390, obj(c, 0x80, {0x20: s20}))


def _g523040(c):
    clear_hooks(c)
    r = c.rng
    _setlog(c, 2)
    hook_rec(c, 0x523280, 0, this=True)
    a = rnd(c, 0x30) if r.random() < 0.8 else 0
    f = r.choice([0, 0x80000000, 0x7fc00000, _b(1.0), _b(-1.0), _w(c)])
    return [rnd(c, 0x60), a, f]


def _g5a83e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x5ec090, 2, this=True)
    hook_rec(c, 0x5a5d00, 3, this=True, ret=lambda em, k: _w(c))
    hook_rec(c, 0x5ec340, 2, this=True)
    me = rnd(c, 0x660)
    e.w32(me + 0x434, rnd(c, 0x20))
    cur = r.choice([0.0, 1.0, 0.5, -1.0, 2.0, c.fv(-2, 2, 0.1), float('nan')])
    e.w32(me + 0x2fc, _b(cur) if cur == cur else 0x7fc00000)
    e.wbytes(me + 0x658, bytes([r.choice([0, 1, 0xff])]))
    x = r.choice([cur, 0.0, -0.0, 1.0, 0.5, 0.25, 0.001, 1.5, -3.0, 0.999, c.fv(-1, 2, 0.05), float('nan'), 0.0078125, 1 / 55.0, 1 / 119.0])
    return [me, x if False else (_b(x) if x == x else 0x7fc00000)]


def _g5b7c70(c):
    clear_hooks(c)
    s4c = pystub(c, 1, this=True)
    s60 = pystub(c, 1, this=True)
    s3c = pystub(c, 1, this=True)
    s68b = pystub(c, 1, this=True)
    rb = obj(c, 0x80, {0x68: s68b})
    s68 = pystub(c, 1, this=True, ret=lambda em, k: rb)
    o = obj(c, 0x80, {0x4c: s4c, 0x60: s60, 0x3c: s3c, 0x68: s68})
    return [rnd(c, 0x40), o]


S(0x523040, 'GUESS bind target object with sign from float', 'thiscall', None, ret=None, gen=_g523040, note='batch33100')
S(0x5a83e0, 'GUESS set clamped value and update widget', 'thiscall', None, ret=None, gen=_g5a83e0, note='batch33100')
S(0x5b7c70, 'GUESS write fields to stream object', 'thiscall', None, ret=None, gen=_g5b7c70, note='batch33100')
