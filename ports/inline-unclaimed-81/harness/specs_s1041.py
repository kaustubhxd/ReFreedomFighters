"""specs_s1041.py - area 81, batch 1041: 0x63b500 (thiscall: this, two stack arguments; ecx += 0x8270, then a tail jump to 0x65e300). 0x65e300 is hooked by
a GUESS stub with two stack arguments and ret 0 (its real body is large and faults on random objects)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj, _stub


def g(c):
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, 0)
    # GUESS hook: records ecx (the object the thunk adjusted) into a heap cell, then ret 8 with eax 0
    ss.patch(c, 0x65e300, ss.code(c, b'\x89\x0d' + struct.pack('<I', cell) + b'\x31\xc0' + b'\xc2\x08\x00'))
    self_ = obj(c, 0x9000)
    return [self_, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x63b500, 'GUESS 0x63b500 offset thunk', 'thiscall', None, ret=None, gen=g)
