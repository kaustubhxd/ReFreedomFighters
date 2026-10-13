"""specs_s1044.py - area 81, batch 1044: 0x634844 (plain ret, no arguments). The flag blocks at 0x6ff948 and 0x6ff950 (exe data) get random words; the
getters 0x42acaf and 0x42acb5 are real exe code and run unpatched."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def g(c):
    for a in (0x6ff948, 0x6ff950):
        c.emu.w32(a, c.rng.getrandbits(32))
        c.emu.w32(a + 4, c.rng.getrandbits(32))
    return []


S(0x634844, 'GUESS 0x634844 flag bits', 'cdecl', None, ret=None, gen=g)
