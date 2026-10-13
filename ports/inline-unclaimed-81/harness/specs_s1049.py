"""specs_s1049.py - area 81, batch 1049: 0x65f540 (thiscall: this, five stack arguments; ret 0x14; eax returned). The object's vtable slot 0x28 is a GUESS
stub with six stack arguments (ret 0x18) that records ecx and all six arguments into heap cells and returns a random eax, so a dropped, swapped or
wrong constant argument shows in the memory compare."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj


def g(c):
    P = lambda a: struct.pack('<I', a)
    cell = c.emu.alloc(28, 4)
    for k in range(7):
        c.emu.w32(cell + 4 * k, 0)
    code = b'\x89\x0d' + P(cell)
    for i in range(6):
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + P(cell + 4 + 4 * i)
    code += b'\xb8' + P(c.rng.getrandbits(32)) + b'\xc2\x18\x00'
    self_ = obj(c, 0x40, {0x28: ss.code(c, code)})
    return [self_] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x65f540, 'GUESS 0x65f540 slot-28 forward', 'thiscall', None, ret='eax', gen=g)
