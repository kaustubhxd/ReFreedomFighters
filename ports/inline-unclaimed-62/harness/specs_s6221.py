"""specs_s6221.py - unclaimed-62 claim 14 (slice 2): six leaves (see src/batch6221.cpp). Records are 0x1000 bytes of random data; the spec
sets the fields each leaf reads and the arguments are raw bits (the float leaves take three floats from the record). Every write is
compared. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, sf


def _5edc20(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    v1, v2 = r.getrandbits(32), r.getrandbits(32)
    e.w32(rec + 0xeb, v1)
    e.w32(rec + 0xf3, v2)
    a = v1 if r.random() < 0.5 else r.getrandbits(32)
    b = v2 if r.random() < 0.5 else r.getrandbits(32)
    return [rec, a, b, r.getrandbits(32)]


def _594ed0(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    e.w32(rec + 0x417, r.getrandbits(32) & (0xffffffff if r.random() < 0.5 else 0x1fffffff))
    return [rec, r.getrandbits(32)]


def _547730(c):
    e = c.emu
    r = c.rng
    rec = rnd(c, 0x1000)
    e.w32(rec + 0xf, rec + 0x100)
    src = rnd(c, 0x20)
    return [rec, r.randint(0, 10), src]


def _465470(c):
    e = c.emu
    rec = rnd(c, 0x1000)
    for k in range(3):
        e.wf32(rec + 4 * k, sf(c.fv(-40, 40)))
    return [rec]


def _5aef10(c):
    return [rnd(c, 0x1000)]


def _5b7ce0(c):
    r = c.rng
    rec = rnd(c, 0x1000)
    return [rec] + [r.getrandbits(32) for _ in range(6)]


S(0x5edc20, 'unnamed 0x5edc20', 'thiscall', None, gen=_5edc20, n=300)
S(0x594ed0, 'unnamed 0x594ed0', 'thiscall', None, gen=_594ed0, n=300)
S(0x547730, 'unnamed 0x547730', 'thiscall', None, gen=_547730, n=300)
S(0x465470, 'unnamed 0x465470', 'thiscall', None, ret='st0', gen=_465470, n=300)
S(0x5aef10, 'unnamed 0x5aef10', 'thiscall', None, gen=_5aef10, n=300)
S(0x5b7ce0, 'unnamed 0x5b7ce0', 'thiscall', None, gen=_5b7ce0, n=300)
