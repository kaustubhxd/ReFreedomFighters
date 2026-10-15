"""specs_s975.py - residue-05, batch 975: 0x5b0810 (GUESS FUN_5b0810). The buffer reads (0x5f0280) are a machine-code stub that
writes the next value of a random table each call (the first value is the version: 1 in 70% of the cases, so both paths run);
the setters (0x5af2a0), the loop helper (0x5aee20) and the debug channel's cdecl slot 0x2c are stood in with counting stubs.
The loop's constants come from the image (0x6a7400, 0x6a7410)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, cstub, obj, r32


def g(c):
    n = 64
    table = c.emu.alloc(4 * n, 4)
    for k in range(n):
        c.emu.w32(table + 4 * k, r32(c) if k else (1 if c.rng.random() < 0.7 else r32(c)))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]   (out pointer)
    code += b'\x8b\x15' + struct.pack('<I', cnt)                # mov edx,[cnt]
    code += b'\x8b\x0c\x95' + struct.pack('<I', table)          # mov ecx,[table+edx*4]
    code += b'\x89\x08'                                         # mov [eax],ecx
    code += b'\xff\x05' + struct.pack('<I', cnt)                # inc dword [cnt]
    code += b'\xc2\x04\x00'                                     # ret 4
    rd = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(rd, code)
    ss.patch(c, 0x5f0280, rd)
    ss.patch(c, 0x5af2a0, ss.rec(c, 2))
    ss.patch(c, 0x5aee20, ss.rec(c, 2))
    ch = obj(c, 0x40, {0x2c: cstub(c, 2)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    t = obj(c, 0x100)
    buf = obj(c, 0x40)
    c.emu.w32(buf + 0xc, c.rng.choice([0, 1, r32(c)]))   # the byte at +0xc decides the return value
    return [t, buf]


S(0x5b0810, 'GUESS FUN_5b0810 (buffer read mirror)', 'thiscall', ret='al', gen=g)
