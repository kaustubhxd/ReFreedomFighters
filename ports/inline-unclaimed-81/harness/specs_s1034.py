"""specs_s1034.py - area 81, batch 1034: 0x546fa0 (stdcall: a, b, out, v, s, f; ret 0x18). The vectors v and s have random components in -3..3 (the dot
product is below zero in about half the cases), so the scale and clear paths both run. The helpers 0x451890, 0x4e0d00 and 0x443ef0 are the exe's own code."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import rf


def _vec(c):
    a = c.emu.alloc(12, 4)
    for off in (0, 4, 8):
        c.emu.w32(a + off, rf(c, -3, 3))
    return a


def g(c):
    A = c.emu.alloc(12, 4)
    B = _vec(c)
    OUT = c.emu.alloc(12, 4)
    V = _vec(c)
    Sv = _vec(c)
    f = rf(c, -2, 2)
    return [A, B, OUT, V, Sv, f]


S(0x546fa0, 'GUESS 0x546fa0 vector clamp step', 'stdcall', None, ret=None, gen=g)
