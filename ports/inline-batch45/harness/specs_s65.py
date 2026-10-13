"""specs_s65.py - inline session batch 65 (grenade flight): ZParamParticle::Init, GetPos and the velocity getter, and the
four-argument vaddscalar. exp is the harness's stub for the CRT import (Python's exp), reached through the same import
slot by the exe and the port; PSVECSubtract and the vscalar helpers run as exe code."""
import math
import struct
from pilot import S, F

K_EDGE = struct.unpack('<f', struct.pack('<I', 0x3a83126f))[0]          # 0.001 as the exe stores it
K_BELOW = struct.unpack('<f', struct.pack('<I', 0x3a83126e))[0]


def _f(c):
    r = c.rng
    return r.choice((0.0, -0.0, 1.0, -1.0, math.nan, math.inf, 1e-30, 3e38, r.uniform(-500, 500), r.uniform(-1, 1),
                     c.fv(), r.uniform(-1e5, 1e5), 16777217.0, 1.5e-45, r.uniform(-3000, 3000)))


def _v(c, pad=True):
    if pad:
        c.emu.alloc(0x10, 16)
    a = c.emu.alloc(0x20, 4)
    for i in range(3):
        c.emu.wf32(a + 4 * i, _f(c))
    return a


def _k(c):
    r = c.rng
    return r.choice((0.0, -0.0, K_EDGE, K_BELOW, r.uniform(0.0, 3.0), r.uniform(0.0, 0.01), math.nan, -0.5,
                     r.uniform(0.001, 0.2), 1e-30, math.inf))


def _particle(c):
    r = c.rng
    c.emu.alloc(0x10, 16)
    p = c.emu.alloc(0x40, 4)
    for i in range(11):
        c.emu.wf32(p + 4 * i, _f(c))
    c.emu.wf32(p + 0xc, _k(c))
    c.emu.wf32(p + 0x28, r.choice((0.0, r.uniform(0, 1000), _f(c))))
    return p


def _t(c, p):
    r = c.rng
    t0 = c.emu.rf32(p + 0x28)
    return r.choice((t0, t0 + r.uniform(0, 5), t0 + r.uniform(-1, 10), _f(c), t0 + 1.0))


def _vas4(c):
    a, v = _v(c), _v(c)
    dst = c.rng.choice((_v(c), _v(c), a, v, a + 4, a - 4, v + 4, v - 4))
    return [dst, a, v, F(_f(c))]


def _init(c):
    p = _particle(c)
    return [p, _v(c), _v(c), _v(c), F(_k(c)), F(c.rng.choice((0.0, c.rng.uniform(0, 1000), _f(c))))]


def _getpos(c):
    p = _particle(c)
    out = c.rng.choice((_v(c), _v(c), _v(c), p, p + 0x10, p + 0x1c))
    return [p, out, F(_t(c, p))]


S(0x443ef0, 'vaddscalar(dst, a, v, s)', 'fastcall', None, ret=None, gen=_vas4, note='batch65; dst = a + v * s')
S(0x4e73b0, 'ZParamParticle::Init', 'thiscall', None, ret=None, gen=_init, note='batch65; grenade flight')
S(0x4e71b0, 'ZParamParticle::GetPos', 'thiscall', None, ret=None, gen=_getpos, note='batch65; exp via the CRT import slot', nan_heap=True)
S(0x4e7330, 'ZParamParticle velocity', 'thiscall', None, ret=None, gen=_getpos, note='batch65; exp via the CRT import slot', nan_heap=True)
