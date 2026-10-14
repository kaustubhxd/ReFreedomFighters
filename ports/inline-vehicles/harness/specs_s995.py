"""specs_s995.py - residue-10, batch 995: CEnemyFlag::Load (0x5c1b60). The helpers 0x6352f0 and 0x5c1dc0 are stood in (stack argument not
recorded). The load object's slots: 0x40 and 0x48 write a dword through their pointer (stack pointers skipped), 0x68 writes ONE byte (the
exe's flag is a byte; a dword would overwrite the saved EBP), the rest are counting stubs. The render manager's slot 0x58 answers random
values; the point object's slots 0x1e0 (flag) and 0x20 (value) are stubs."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    ss.patch(c, 0x6352f0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x5c1dc0, ss.rec(c, 1, log=False))
    src = c.emu.alloc(4, 4)
    c.emu.w32(src, r32(c))
    code40 = (b'\x8b\x44\x24\x04' + b'\x8b\x0d' + struct.pack('<I', src)
              + b'\x89\x08' + b'\xc2\x04\x00')                    # mov eax,[esp+4]; mov ecx,[src]; mov [eax],ecx; ret 4
    a40 = c.emu.alloc(len(code40) + 16, 16)
    c.emu.wbytes(a40, code40)
    byte_src = c.emu.alloc(4, 4)
    c.emu.w32(byte_src, r32(c))
    code68 = (b'\x8b\x44\x24\x04' + b'\x8a\x0d' + struct.pack('<I', byte_src)
              + b'\x88\x08' + b'\xc2\x04\x00')                    # mov eax,[esp+4]; mov cl,[src]; mov [eax],cl; ret 4
    a68 = c.emu.alloc(len(code68) + 16, 16)
    c.emu.wbytes(a68, code68)
    L = obj(c, 0x80, {0x40: a40, 0x48: a40, 0x68: a68, 0x58: _stub(c, 1), 0x6c: _stub(c, 1), 0x18: _stub(c, 2)})
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=r32(c))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    p = obj(c, 0x40, {0x1e0: _stub(c, 1, ret=c.rng.randint(0, 1)), 0x20: _stub(c, 0, ret=r32(c))})
    t = obj(c, 0x200)
    c.emu.w32(t + 0x44, p)
    return [t, L]


S(0x5c1b60, 'CEnemyFlag::Load', 'thiscall', ret='al', gen=g)
