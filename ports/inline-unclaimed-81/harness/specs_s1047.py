"""specs_s1047.py - area 81, batch 1047: 0x57c240 (thiscall: this, no stack arguments). 0x5626c0 is hooked by a GUESS stub (no arguments, plain ret) that
records ecx and a call counter; 0x563510 by a GUESS stub (one argument, ret 4) that records ecx, its argument and the counter at call time, so a swapped
call order shows. 0x563610 runs as real exe code (writes this+0x58)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from vh import obj


def g(c):
    cell = c.emu.alloc(0x14, 4, fill=0)
    for k in range(5):
        c.emu.w32(cell + 4 * k, 0)
    P = lambda a: struct.pack('<I', a)
    # 0x5626c0: mov [cell], ecx; inc [cell+16]; mov eax, [cell+16]; mov [cell+4], eax; ret
    ss.patch(c, 0x5626c0, ss.code(c, b'\x89\x0d' + P(cell) + b'\xff\x05' + P(cell + 16) + b'\xa1' + P(cell + 16)
                                  + b'\xa3' + P(cell + 4) + b'\xc3'))
    # 0x563510: mov [cell+8], ecx; mov eax, [esp+4]; mov [cell+12], eax; inc [cell+16]; mov eax, [cell+16]; ret 4
    ss.patch(c, 0x563510, ss.code(c, b'\x89\x0d' + P(cell + 8) + b'\x8b\x44\x24\x04\xa3' + P(cell + 12)
                                  + b'\xff\x05' + P(cell + 16) + b'\xa1' + P(cell + 16) + b'\xc2\x04\x00'))
    return [obj(c, 0x100)]


S(0x57c240, 'GUESS 0x57c240 init calls', 'thiscall', None, ret=None, gen=g)
