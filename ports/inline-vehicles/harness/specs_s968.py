"""specs_s968.py - residue-05, batch 968: ZWindControl::FrameUpdate (0x4c3510). The engine vslot 0x1c0 (float), the render
manager's slot 0x58 (the entry's object), the list object's slots 0x4c and 0x5c (the 0x5c slot is a machine-code stub that
answers 'more' for K calls) and the helper 0x4c3740 (counting stub) are stood in. The float inputs are random in ranges that
hit both sides of the timer test."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, fconst, obj, r32, rf


def g(c):
    ss.patch(c, 0x4c3740, ss.rec(c, 1))
    sysobj = obj(c, 0x200, {0x1c0: _stub(c, 2, fld=fconst(c, rf(c, 0.5, 2.0)))})
    c.emu.w32(sysobj + 0x48, rf(c, 0.0, 0.5))
    c.emu.w32(0x70039c, sysobj)
    # the render manager's slot 0x58 must answer an object whose +8 is a y object with flag bits
    y = obj(c, 0x40)
    c.emu.w32(y + 0x3c, r32(c) if c.rng.random() < 0.5 else (r32(c) | 0x1000))
    xobj = obj(c, 0x20)
    c.emu.w32(xobj + 8, y)
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=xobj)})
    c.emu.w32(sysobj + 0x9b, rm)
    # list object: slot 0x4c is a no-op; slot 0x5c answers 'more' for k calls
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
    c.emu.w32(t + 0x48, lst if c.rng.random() < 0.8 else 0)
    c.emu.w32(t + 0x4c, rf(c, -0.5, 1.0))
    c.emu.w32(t + 0x50, rf(c, 0.5, 2.0))
    c.emu.w32(t + 0x54, rf(c, -1.0, 1.0))
    c.emu.w32(t + 0x5c, rf(c, -1.0, 1.0))
    return [t]


S(0x4c3510, 'ZWindControl::FrameUpdate', 'thiscall', gen=g)
