"""specs_s991.py - residue-10, batch 991: ZDamageBox2::FrameUpdate (0x5dba60). The list object's slots (0x4c writes 'more', 0x5c answers the
next entry and 'more' for K calls, machine code), the render manager's slot 0x58 (the entry's object), the object X's slots (0x84 writes
the vector through its pointer, 0x128 counting), the point object P's slots (0x8c writes the vector, 0x180 answers a flag), the helper
0x4daf90 (stood in, its stack pointer not recorded), and the registry slot 0x114 (six args, counting) are stubs. The frame time and
timers are random, so every branch is reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x4daf90, ss.rec(c, 1, log=False))
    vsrc = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(vsrc + 4 * j, rf(c, -1, 1))
    x = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), ofills=((0, 0, vsrc, 3),)), 0x128: ss.rec(c, 1)})
    c.emu.w32(x + 8, obj(c, 0x40))
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=x), 0x114: _stub(c, 6, ret=c.rng.randint(0, 0xffff))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x48, rf(c, 0, 0.5))
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    p = obj(c, 0x40, {0x8c: _stub(c, 1, skip=(0,), ofills=((0, 0, vsrc, 3),)),
                      0x180: _stub(c, 2, skip=(0,), ret=c.rng.randint(0, 1))})
    k = c.rng.randint(0, 2)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    entry = obj(c, 0x40)
    more1 = c.emu.alloc(4, 4)
    code4c = b'\x8b\x44\x24\x04' + b'\xc7\x00\x01\x00\x00\x00' + b'\xc2\x04\x00'        # mov eax,[esp+4]; mov dword [eax],1; ret 4
    a4c = c.emu.alloc(32, 16)
    c.emu.wbytes(a4c, code4c)
    code5c = (b'\x8b\x44\x24\x04'                                 # mov eax,[esp+4]   (more pointer)
              + b'\x8b\x15' + struct.pack('<I', cnt)              # mov edx,[cnt]
              + b'\xff\x05' + struct.pack('<I', cnt)              # inc dword [cnt]
              + b'\x31\xc9'                                       # xor ecx,ecx
              + b'\x83\xfa' + bytes([k])                          # cmp edx,K
              + b'\x7d\x02'                                       # jge +2
              + b'\xb1\x01'                                       # mov cl,1
              + b'\x89\x08'                                       # mov [eax],ecx
              + b'\xb8' + struct.pack('<I', entry)                # mov eax,entry
              + b'\xc2\x04\x00')                                  # ret 4
    a5c = c.emu.alloc(len(code5c) + 16, 16)
    c.emu.wbytes(a5c, code5c)
    l = obj(c, 0x40, {0x4c: a4c, 0x5c: a5c})
    t = obj(c, 0x200)
    c.emu.wbytes(t + 0x54, bytes([1 if c.rng.random() < 0.9 else 0]))
    c.emu.w32(t + 0x48, l if c.rng.random() < 0.9 else 0)
    c.emu.w32(t + 0x44, p)
    for off in (0x8b, 0x8f, 0x9b, 0x50, 0x97, 0x87, 0x93, 0x57):
        c.emu.w32(t + off, rf(c, 0, 1) if off in (0x50, 0x87, 0x97) else rf(c, -0.5, 1))
    return [t]


S(0x5dba60, 'ZDamageBox2::FrameUpdate', 'thiscall', gen=g)
