"""specs_s982.py - residue-10, batch 982: ZFFSimpleTrain2::CopyEventDataBlock (0x5b86a0). The DBREAD readers share one counter-table:
the dword reader (0x4e5e60) and the float reader (0x4e5e80, fld) return the next table entry, in call order. The string reader
(0x4e5ea0) returns a short NUL-terminated string. The allocator (0x41e290, cdecl) returns a block or zero (zero skips the constructor
0x4ccbe0); 0x4e6330 is a counting stub with the object logged. The render manager's slot 0x58 answers random values."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    n = 64
    table = c.emu.alloc(4 * n, 4)
    for k in range(n):
        c.emu.w32(table + 4 * k, r32(c))
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    dw = (b'\x8b\x15' + struct.pack('<I', cnt)                   # mov edx,[cnt]
          + b'\x8b\x04\x95' + struct.pack('<I', table)           # mov eax,[table+edx*4]
          + b'\xff\x05' + struct.pack('<I', cnt)                 # inc dword [cnt]
          + b'\xc3')
    fl = (b'\x8b\x15' + struct.pack('<I', cnt)                   # mov edx,[cnt]
          + b'\xd9\x04\x95' + struct.pack('<I', table)           # fld dword [table+edx*4]
          + b'\xff\x05' + struct.pack('<I', cnt)                 # inc dword [cnt]
          + b'\xc3')
    a_dw = c.emu.alloc(len(dw) + 16, 16)
    c.emu.wbytes(a_dw, dw)
    a_fl = c.emu.alloc(len(fl) + 16, 16)
    c.emu.wbytes(a_fl, fl)
    s = c.emu.alloc(16, 4)
    text = bytes(c.rng.randint(65, 90) for _ in range(c.rng.randint(0, 10))) + b'\x00'
    c.emu.wbytes(s, text)
    ss.patch(c, 0x4e5e60, a_dw)
    ss.patch(c, 0x4e5e80, a_fl)
    ss.patch(c, 0x4e5ea0, _stub(c, 0, ret=s))
    ss.patch(c, 0x4e6330, ss.rec(c, 1))
    buf = c.emu.alloc(0x40, 4)
    ss.patch(c, 0x41e290, cstub(c, 1, ret=(0 if c.rng.random() < 0.2 else buf)))
    ss.patch(c, 0x4ccbe0, _stub(c, 2, ret=buf))
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=r32(c))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x200)
    d = obj(c, 0x40)
    return [t, d]


S(0x5b86a0, 'ZFFSimpleTrain2::CopyEventDataBlock', 'thiscall', ret='eax', gen=g)
