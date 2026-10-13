"""specs_s1045.py - area 81, batch 1045: 0x663b40 (stdcall, one argument p; ret 4). p is null in about a fifth of the cases. The object's vtable slot 0x28
is a GUESS stub with no arguments that records its ecx into a heap cell, so a wrong object or a skipped call shows in the memory compare."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj


def g(c):
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, 0)
    slot = ss.code(c, b'\x89\x0d' + struct.pack('<I', cell) + b'\x31\xc0' + b'\xc3')   # mov [cell], ecx; xor eax,eax; ret
    o = obj(c, 0x40, {0x28: slot})
    p = o if c.rng.random() < 0.8 else 0
    return [p]


S(0x663b40, 'GUESS 0x663b40 slot-28 call', 'stdcall', None, ret=None, gen=g)
