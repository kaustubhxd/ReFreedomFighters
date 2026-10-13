"""specs_s1048.py - area 81, batch 1048: 0x5738c0 (stdcall shape: one argument, ret 4; eax returned). The global at 0x70039c points to a random block whose
unaligned field +0x9b holds object A. A's slot 0x58 is a GUESS stub (no arguments) that records ecx and returns object B; B's slot 0x254 is a GUESS stub
(one argument, ret 4) that records ecx and its argument and returns a random eax."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj, _rnd


def g(c):
    P = lambda a: struct.pack('<I', a)
    cell = c.emu.alloc(12, 4)
    for k in range(3):
        c.emu.w32(cell + 4 * k, 0)
    # B slot 0x254: mov [cell+4], ecx; mov eax, [esp+4]; mov [cell+8], eax; mov eax, imm; ret 4
    s254 = ss.code(c, b'\x89\x0d' + P(cell + 4) + b'\x8b\x44\x24\x04\xa3' + P(cell + 8)
                   + b'\xb8' + P(c.rng.getrandbits(32)) + b'\xc2\x04\x00')
    b = obj(c, 0x40, {0x254: s254})
    # A slot 0x58: mov [cell], ecx; mov eax, B; ret
    s58 = ss.code(c, b'\x89\x0d' + P(cell) + b'\xb8' + P(b) + b'\xc3')
    a = obj(c, 0x40, {0x58: s58})
    gl = _rnd(c, 0x100)
    c.emu.wbytes(gl + 0x9b, P(a))
    c.emu.w32(0x70039c, gl)
    return [c.rng.getrandbits(32)]


S(0x5738c0, 'GUESS 0x5738c0 global slot chain', 'stdcall', None, ret='eax', gen=g)
