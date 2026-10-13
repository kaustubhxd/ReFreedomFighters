"""specs_s1038.py - area 81, batch 1038: 0x4527c0 (thiscall, this; tail-jumps to 0x45c3e0, real exe code). The object is random bytes with a vtable
word (not used by the thunk)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj, _stub


def g(c):
    ss.patch(c, 0x45c3e0, _stub(c, 0, ret=0))   # GUESS: hook the tail target (a large destructor) by address
    return [obj(c, 0x40)]


S(0x4527c0, 'GUESS 0x4527c0 vtable thunk', 'thiscall', None, ret=None, gen=g)
