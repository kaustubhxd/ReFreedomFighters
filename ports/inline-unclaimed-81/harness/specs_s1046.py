"""specs_s1046.py - area 81, batch 1046: 0x651580 (thiscall: this, one stack argument; ret 4). The inner object at this+0xbd (unaligned) is null in about
a fifth of the cases. Its vtable slot 0x54 is a GUESS stub (one stack argument, ret 4) that records ecx and its argument into heap cells, so a wrong field
offset, wrong slot or dropped argument shows in the memory compare."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj


def g(c):
    cell = c.emu.alloc(8, 4)
    c.emu.w32(cell, 0)
    c.emu.w32(cell + 4, 0)
    # mov [cell], ecx; mov eax, [esp+4]; mov [cell+4], eax; mov eax, imm; ret 4
    slot = ss.code(c, b'\x89\x0d' + struct.pack('<I', cell) + b'\x8b\x44\x24\x04\xa3' + struct.pack('<I', cell + 4)
                   + b'\xb8' + struct.pack('<I', c.rng.getrandbits(32)) + b'\xc2\x04\x00')
    inner = obj(c, 0x40, {0x54: slot})
    self_ = obj(c, 0x100)
    c.emu.wbytes(self_ + 0xbd, struct.pack('<I', inner if c.rng.random() < 0.8 else 0))
    return [self_, c.rng.getrandbits(32)]


S(0x651580, 'GUESS 0x651580 inner slot-54 thunk', 'thiscall', None, ret=None, gen=g)
