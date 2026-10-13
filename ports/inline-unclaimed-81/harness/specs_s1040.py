"""specs_s1040.py - area 81, batch 1040: 0x63f600 (thiscall: this, one stack argument; tail-jumps to 0x63ef00, real exe code). The object has a sub-object
at +0x268 and the argument is a 0x40-byte object; the callee writes into the argument."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj, _stub


def g(c):
    ss.patch(c, 0x63ef00, _stub(c, 1, ret=0))   # GUESS: hook the tail target by address (its real body is large)
    self_ = obj(c, 0x400)
    arg = obj(c, 0x40)
    return [self_, arg]


S(0x63f600, 'GUESS 0x63f600 tail thunk', 'thiscall', None, ret=None, gen=g)
