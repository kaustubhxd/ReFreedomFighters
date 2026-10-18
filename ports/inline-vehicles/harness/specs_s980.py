"""specs_s980.py - residue-05, batch 980: ZItemContainer::InsertItem (0x46f2d0). The render manager (0x58, 0x4c), the item's
slots (0x2e8, 0x1d8, 0x2d4, 0x31c via Y, 0x25c via Y), X's slots (0x1d8, 0x2d4, 0x2f0, 0x300, 0x31c) and the sub-object (slot 4) are
stubs. The local-writing 1d8 stub stores either its own inline buffer pointer (no free) or zero in its first dword; the destructor's
free (0x634273) is a counting stub. 0x4db2c0 (vector copy, calls 0x4de420) is stood in; 0x4de7a0 runs as exe code. The channel's cdecl
slot 0x2c is a counting stub that logs its first three arguments (the fourth is not logged; it is one of the two dwords in
the path, the value of the other is covered by the first)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def cstub_skip(c, nargs, skip=()):
    """cdecl stub like vh.cstub (caller pops), but the arguments in skip are not recorded (stack-derived values)."""
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


def local_stub(c, g):
    inline = c.rng.random() < 0.5
    code = b'\x8b\x44\x24\x04'                                  # mov eax,[esp+4]   (local pointer)
    if inline:
        code += b'\x8d\x50\x04\x89\x10'                          # lea edx,[eax+4]; mov [eax],edx
    else:
        code += b'\xc7\x00\x00\x00\x00\x00'                      # mov dword [eax],0
    code += b'\xb8' + struct.pack('<I', g)                      # mov eax,g
    code += b'\xc2\x08\x00'                                     # ret 8
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def g(c):
    ss.patch(c, 0x634273, cstub_skip(c, 2))
    ss.patch(c, 0x4db2c0, ss.rec(c, 2, log=False))
    ga = obj(c, 0x40)
    gb = obj(c, 0x40)
    z = obj(c, 0x40) if c.rng.random() < 0.5 else 0
    if z:
        c.emu.w32(z + 8, obj(c, 0x20))
    r = obj(c, 0x40)
    ch = obj(c, 0x40, {0x2c: cstub_skip(c, 3, skip=(2,))})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    x = obj(c, 0x80, {0x1d8: local_stub(c, gb), 0x2d4: _stub(c, 2, skip=(0, 1)), 0x2f0: _stub(c, 1),
                      0x300: _stub(c, 1), 0x31c: _stub(c, 1, ret=0)})
    c.emu.w32(x + 4, r32(c) if c.rng.random() < 0.6 else 0)
    y = obj(c, 0x40, {0x31c: _stub(c, 1, ret=c.rng.randint(0, 1)), 0x25c: _stub(c, 2, ret=z)})
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=x), 0x4c: _stub(c, 3, ret=r)})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    sub = obj(c, 0x40, {4: _stub(c, 1)})
    t = obj(c, 0x200, {0x1d8: local_stub(c, ga), 0x2e8: _stub(c, 0, ret=y)})
    c.emu.w32(t + 4, r32(c) if c.rng.random() < 0.6 else 0)
    c.emu.w32(t + 0x94, sub)
    return [t, r32(c)]


S(0x46f2d0, 'ZItemContainer::InsertItem', 'thiscall', gen=g)
