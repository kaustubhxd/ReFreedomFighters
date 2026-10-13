"""specs_s3543.py - standing assignment, slice 14, batch 43: four leaves (GUESS names); no callees."""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _g4678(c):
    return [_rnd(c, 0x100), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g65ca(c):
    return [_rnd(c, 0x20), c.rng.getrandbits(32)]


def _g4617(c):
    return [_rnd(c, 0x20), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g6568(c):
    mgr = _rnd(c, 0x2000)
    O = _rnd(c, 0x100)
    P = _rnd(c, 0x100)
    value = c.rng.getrandbits(32)
    c.emu.w32(P + 4, value)
    c.emu.w32(O + 0x20, P)
    c.emu.w32(mgr + 0x1aa3, O)
    c.emu.w32(0x70039c, mgr)
    arg = value if c.rng.random() < 0.3 else c.rng.getrandbits(32)
    return [arg]


S(0x4678e0, 'GUESS method 0x4678e0 thiscall, four args', 'thiscall', None, ret=None, gen=_g4678, note='batch 43 leaf')
S(0x65ca60, 'GUESS method 0x65ca60 thiscall, one arg', 'thiscall', None, ret=None, gen=_g65ca, note='batch 43 leaf')
S(0x461760, 'GUESS function 0x461760 stdcall, three args', 'stdcall', None, ret=None, gen=_g4617, note='batch 43 leaf')
S(0x6568e0, 'GUESS function 0x6568e0 stdcall, one arg', 'stdcall', None, ret='al', gen=_g6568, note='batch 43 leaf')
