"""specs_s984.py - residue-11, batch 984: ZFFPRIVATESTDOBJ::CopyDataBlock (0x5a65f0). The base copy 0x610100 (ret 4) and the finish 0x4e1b30
are counting stubs in the exe image; the DBLK read 0x4e12e0 (a jump to 0x4e11e0, which is not read here) is stood in with a
counter-table stub that writes the next value through its pointer (ret 8). The values are random, with zero in some cases so both
branches of the flag are reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _rnd, obj, r32


def g(c):
    ss.patch(c, 0x610100, ss.rec(c, 1))
    ss.patch(c, 0x4e1b30, ss.rec(c, 0))
    n = 8
    table = c.emu.alloc(4 * n, 4)
    for k in range(n):
        v = 0 if c.rng.random() < 0.4 else r32(c)
        c.emu.w32(table + 4 * k, v)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    code = b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]  (out pointer)
    code += b'\x8b\x15' + struct.pack('<I', cnt)                # mov edx,[cnt]
    code += b'\x8b\x0c\x95' + struct.pack('<I', table)          # mov ecx,[table+edx*4]
    code += b'\x89\x08'                                         # mov [eax],ecx
    code += b'\xff\x05' + struct.pack('<I', cnt)                # inc dword [cnt]
    code += b'\xc2\x08\x00'                                     # ret 8
    st = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st, code)
    ss.patch(c, 0x4e12e0, st)
    t = obj(c, 0x40)
    d = _rnd(c, 0x40)
    return [t, d]


S(0x5a65f0, 'ZFFPRIVATESTDOBJ::CopyDataBlock', 'thiscall', gen=g)
