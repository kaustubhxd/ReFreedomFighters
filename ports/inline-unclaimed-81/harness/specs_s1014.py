"""specs_s1014.py - area 81, batch 1014: CInventory::Command (0x4abc30). The command word is one of the twelve compare words of the object in most cases.
The inner object at +0x11a has slot 0x4c (writes a random flag into its stack argument), slot 0x5c (writes the next flag of a table, ones then zeros, and
returns an object E) and slot 0x44 (counting). The render manager's slot 0x58 returns a random object R or null. The argument is an object with slots 4 and
0x128 (counting) or zero. The helpers 0x4acf30, 0x4ad770, 0x4ad9a0 and 0x4ad4d0 are counting stubs. Stack-address arguments are not logged."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4acf30, ss.rec(c, 1))
    ss.patch(c, 0x4ad770, ss.rec(c, 1))
    ss.patch(c, 0x4ad9a0, ss.rec(c, 0))
    ss.patch(c, 0x4ad4d0, ss.rec(c, 0))
    E = obj(c, 0x40)
    fsrc = c.emu.alloc(4, 4)
    c.emu.w32(fsrc, rnd.randint(0, 1))
    tbl = c.emu.alloc(4 * 32, 4)
    for i in range(32):
        c.emu.w32(tbl + 4 * i, rnd.randint(0, 1) if i < 16 else 0)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    getter = c.emu.alloc(64, 16)
    code = (b'\x8b\x44\x24\x04'                                 # mov eax,[esp+4]  (&flag)
            + b'\x8b\x15' + struct.pack('<I', cnt)              # mov edx,[cnt]
            + b'\x8b\x0c\x95' + struct.pack('<I', tbl)          # mov ecx,[tbl+edx*4]
            + b'\x89\x08'                                       # mov [eax],ecx
            + b'\xff\x05' + struct.pack('<I', cnt)              # inc dword [cnt]
            + b'\xb8' + struct.pack('<I', E)                    # mov eax,E
            + b'\xc2\x04\x00')                                  # ret 4
    c.emu.wbytes(getter, code)
    inner = obj(c, 0x40, {0x44: _stub(c, 1, skip=(0,)),
                          0x4c: _stub(c, 1, skip=(0,), ofills=((0, 0, fsrc, 1),)),
                          0x5c: getter})
    R = obj(c, 0x40, {0x128: _stub(c, 3)}) if rnd.random() < 0.7 else 0
    rm = obj(c, 0x40, {0x58: _stub(c, 1, ret=R)})
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm)
    self_ = obj(c, 0x200, {0x84: _stub(c, 1), 0x90: _stub(c, 0), 0x94: _stub(c, 0)})
    words = {}
    for off in (0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66):
        v = rnd.randint(0, 0xffff)
        words[off] = v
        c.emu.wbytes(self_ + off, struct.pack('<H', v))
    c.emu.wbytes(self_ + 0x11a, c.emu.rbytes(inner, 4))   # the inner object is inline at this+0x11a: its vtable word goes there
    c.emu.w32(self_ + 0x6a, r32(c))
    cmdw = rnd.choice(list(words.values())) if rnd.random() < 0.85 else rnd.randint(0, 0xffff)
    cmd = cmdw | (rnd.randint(0, 0xffff) << 16 if rnd.random() < 0.3 else 0)
    argv = obj(c, 0x40, {4: _stub(c, 1), 0x128: _stub(c, 3)}) if rnd.random() < 0.85 else 0
    return [self_, cmd, argv]


S(0x4abc30, 'CInventory::Command', 'thiscall', None, ret='eax', gen=g)
