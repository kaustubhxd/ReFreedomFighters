"""specs_s1043.py - area 81, batch 1043: 0x63f4c0 (plain ret, no arguments). 0x42ab62 is hooked by a GUESS cdecl stub with one argument (a debug print). The
assert hook at 0x7003b0 is set to a plain GUESS stub (never null, so the exe does not hit int3)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import _stub


def g(c):
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, 0)
    # GUESS hook (cdecl, one argument): records the argument into a heap cell, returns
    ss.patch(c, 0x42ab62, ss.code(c, b'\x8b\x44\x24\x04\xa3' + struct.pack('<I', cell) + b'\xc3'))
    c.emu.w32(0x7003b0, _stub(c, 0, ret=0))
    return []


S(0x63f4c0, 'GUESS 0x63f4c0 print then hook', 'cdecl', None, ret='eax', gen=g)
