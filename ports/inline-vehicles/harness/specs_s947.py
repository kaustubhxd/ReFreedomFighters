"""specs_s947.py - vehicles batch 947: ZMoveOnSpline::StopSounds (0x5145e0) and its jmp thunk (0x515cf0).
The two vtable slots (0x33c, 0x340) are counting stubs (serial_stubs rec); the object is a random block."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj


def g(c):
    o = obj(c, 0x400, {0x33c: ss.rec(c, 0), 0x340: ss.rec(c, 0)})
    return [o]


S(0x5145e0, 'ZMoveOnSpline::StopSounds', 'thiscall', gen=g)
S(0x515cf0, 'ZMoveOnSpline::StopSounds (jmp thunk)', 'thiscall', gen=g)
