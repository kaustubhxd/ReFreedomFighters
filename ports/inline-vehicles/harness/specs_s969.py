"""specs_s969.py - residue-05, batch 969: ZFFSimpleTrain2::PositionAllTrains (0x5b9050). The list object's slots (0x4c no-op,
0x5c machine-code 'more' stub for K calls), the entry's slot 0x78, the render manager's slot 0x58 and the helpers 0x4db7c0
(fills the vector with random floats through an output-fill stub) and 0x451890 (fastcall, counting stub) are stood in."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, fconst, obj, r32, rf


def g(c):
    src = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(src + 4 * j, rf(c, -50, 50))
    ss.patch(c, 0x4db7c0, _stub(c, 1, skip=(0,), ofills=((0, 0, src, 3),)))
    ss.patch(c, 0x451890, ss.rec(c, 1))
    y = obj(c, 0x40)
    x = obj(c, 0x40, {0x78: _stub(c, 1)})
    c.emu.w32(x + 8, y)
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=x)})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    k = c.rng.randint(0, 3)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    entry = obj(c, 0x40)
    code = b'\x8b\x44\x24\x04'
    code += b'\x8b\x15' + struct.pack('<I', cnt)
    code += b'\xff\x05' + struct.pack('<I', cnt)
    code += b'\x31\xc9'
    code += b'\x83\xfa' + bytes([k])
    code += b'\x7d\x02'
    code += b'\xb1\x01'
    code += b'\x89\x08'
    code += b'\xb8' + struct.pack('<I', entry)
    code += b'\xc2\x04\x00'
    stub = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(stub, code)
    lst = obj(c, 0x40, {0x4c: _stub(c, 1, skip=(0,)), 0x5c: stub})
    t = obj(c, 0x100)
    c.emu.w32(t + 0x4c, lst if c.rng.random() < 0.85 else 0)
    out = c.emu.alloc(16, 4)
    return [t, out]


S(0x5b9050, 'ZFFSimpleTrain2::PositionAllTrains', 'thiscall', gen=g)
