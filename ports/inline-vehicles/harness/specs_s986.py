"""specs_s986.py - residue-11, batch 986: ZCharacterControl deleting destructor (0x57fdb0). The render manager's slot 0x34 and the free hook
(0x7003b0) are counting stubs; the sized delete (0x4690b0) is exe code (a bare ret). Flags are random 0..7."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj


def g(c):
    sysobj = c.emu.alloc(0x2000, 4)
    rm = obj(c, 0x100, {0x34: _stub(c, 1)})
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(0x7003b0, ss.rec(c, 0))
    t = obj(c, 0x200)
    return [t, c.rng.randint(0, 7)]


S(0x57fdb0, 'ZCharacterControl::~ZCharacterControl', 'thiscall', gen=g)
