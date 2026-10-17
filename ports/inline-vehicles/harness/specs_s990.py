"""specs_s990.py - residue-11, batch 990: ZFFActor::HolsterWeapon (0x5a00b0). The actor's slots 0x1d8 (writes its local's first dword, either
the inline buffer or zero, and returns a random object), 0x6b4 (flag), 0x4b4 (five args, counting) and 0x6d4 (counting) are stubs; the debug
channel's cdecl slot 0x2c is a counting stub. The destructor's free (0x634273) is a counting stub. Both fields (+0x78a and +0x78e) are random
objects or zero, so the print path and the flag path are reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def cstub_skip(c, nargs, skip=()):
    rec = c.emu.alloc(4 * (nargs + 1), 4)
    code = b''
    for i in range(nargs):
        if i in skip:
            continue
        code += b'\x8b\x44\x24' + bytes([4 + 4 * i]) + b'\xa3' + struct.pack('<I', rec + 4 * i)
    code += b'\xff\x05' + struct.pack('<I', rec + 4 * nargs)
    code += b'\xc3'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def g(c):
    ss.patch(c, 0x634273, cstub_skip(c, 2))
    res = obj(c, 0x40)
    inline = c.rng.random() < 0.5
    code = b'\x8b\x44\x24\x04'
    if inline:
        code += b'\x8d\x50\x04\x89\x10'
    else:
        code += b'\xc7\x00\x00\x00\x00\x00'
    code += b'\xb8' + struct.pack('<I', res)
    code += b'\xc2\x08\x00'
    st1d8 = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(st1d8, code)
    ch = obj(c, 0x40, {0x2c: cstub_skip(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    t = obj(c, 0x800, {0x1d8: st1d8, 0x6b4: _stub(c, 1, ret=c.rng.randint(0, 1)),
                       0x4b4: _stub(c, 5), 0x6d4: _stub(c, 1)})
    e1 = obj(c, 0x40) if c.rng.random() < 0.6 else 0
    e2 = obj(c, 0x40) if c.rng.random() < 0.6 else 0
    c.emu.w32(t + 0x78a, e1)
    c.emu.w32(t + 0x78e, e2)
    return [t, c.rng.randint(0, 1)]


S(0x5a00b0, 'ZFFActor::HolsterWeapon', 'thiscall', gen=g)
