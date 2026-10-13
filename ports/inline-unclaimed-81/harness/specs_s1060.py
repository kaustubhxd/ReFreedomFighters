"""specs_s1060.py - area 81 (residue 0), batch 1060: 0x54cb80 initializer.
Sets vtable and zero-initializes large object. Thiscall, returns this.
"""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import obj


def g(c):
    # Allocate object (needs at least 0x8069 bytes for all the writes)
    o = c.emu.alloc(0x8100, 4)
    # Fill with marker bytes to verify initialization
    for i in range(0, 0x8100, 4):
        c.emu.w32(o + i, 0xffffffff)

    # Call thiscall: ecx = o (returns eax = o)
    return [o]


S(0x54cb80, 'batch1060_init', 'thiscall', gen=g)
