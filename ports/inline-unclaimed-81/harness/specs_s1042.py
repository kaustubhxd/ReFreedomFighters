"""specs_s1042.py - area 81, batch 1042: 0x54a740 (thiscall, this; no stack arguments). The object is 0x2100 random bytes, so the call to 0x4109e0 (real
exe code) zeroes five words at this+0x2045+8 and the port matches the exe's writes."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import obj


def g(c):
    return [obj(c, 0x2100)]


S(0x54a740, 'GUESS 0x54a740 field init', 'thiscall', None, ret=None, gen=g)
