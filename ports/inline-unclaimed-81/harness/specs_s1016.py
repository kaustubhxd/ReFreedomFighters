"""specs_s1016.py - area 81, batch 1016: CInventory::GetItemFromItemTemplate (0x4ac640). The inline inner object at this+0x11a (its vtable word is copied
into the self object) has slots 0x44 (counting), 0x4c (writes a random flag into its stack argument) and 0x5c (writes the next flag of a table, ones
then zeros, and returns E). The render manager's slot 0x58 returns R (or null, in 30% of cases), R's slot 0x2e8 returns X (or null) and its slot 0x1d8
writes a pointer to the stack argument's object. The template T is either a fresh object or X (so the early return runs). The name strings at +4 are
random or null. The helpers 0x4cc1d0 and 0x4cbec0 are as in batch 1015; the global compare at 0x676414 is a cdecl stub returning a random bool.
The debug object at 0x700390 has slot 0x20 returning a channel whose slot 0x2c is a cdecl stub."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def cstr(c, text):
    a = c.emu.alloc(len(text) + 1, 4)
    c.emu.wbytes(a, text + b'\0')
    return a


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4cc1d0, ss.rec(c, 0, ret=r32(c)))
    ss.patch(c, 0x4cbec0, ss.rec(c, 0))
    c.emu.w32(0x676414, cstub(c, 2, ret=rnd.choice([0, 1])))
    E = obj(c, 0x40)
    fsrc = c.emu.alloc(4, 4)
    c.emu.w32(fsrc, rnd.randint(0, 1))
    tbl = c.emu.alloc(4 * 32, 4)
    for i in range(32):
        c.emu.w32(tbl + 4 * i, rnd.randint(0, 1) if i < 16 else 0)
    cnt = c.emu.alloc(4, 4)
    c.emu.w32(cnt, 0)
    getter = c.emu.alloc(64, 16)
    code = (b'\x8b\x44\x24\x04'
            + b'\x8b\x15' + struct.pack('<I', cnt)
            + b'\x8b\x0c\x95' + struct.pack('<I', tbl)
            + b'\x89\x08'
            + b'\xff\x05' + struct.pack('<I', cnt)
            + b'\xb8' + struct.pack('<I', E)
            + b'\xc2\x04\x00')
    c.emu.wbytes(getter, code)
    inner = obj(c, 0x40, {0x44: _stub(c, 1, skip=(0,)),
                          0x4c: _stub(c, 1, skip=(0,), ofills=((0, 0, fsrc, 1),)),
                          0x5c: getter})
    Q2 = obj(c, 0x40)
    Q = obj(c, 0x40)
    X = obj(c, 0x40)
    c.emu.w32(X + 4, cstr(c, b'Medkit') if rnd.random() < 0.6 else 0)
    if rnd.random() < 0.15:
        T = X
    else:
        T = obj(c, 0x40)
        c.emu.w32(T + 4, cstr(c, b'Medkit') if rnd.random() < 0.6 else 0)
    R = obj(c, 0x40, {0x2e8: _stub(c, 0, ret=X if rnd.random() < 0.7 else 0),
                      0x1d8: _stub(c, 2, skip=(0,), ret=Q2)})
    rm = obj(c, 0x40, {0x58: _stub(c, 1, ret=R if rnd.random() < 0.7 else 0)})
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm)
    M = obj(c, 0x40, {0x1d8: _stub(c, 2, skip=(0,), ret=Q)})
    chan = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=chan)})
    c.emu.w32(0x700390, dbg)
    self_ = obj(c, 0x200)
    c.emu.w32(self_ + 0x44, M)
    c.emu.wbytes(self_ + 0x11a, c.emu.rbytes(inner, 4))
    return [self_, T, r32(c)]


S(0x4ac640, 'CInventory::GetItemFromItemTemplate', 'thiscall', None, ret='eax', gen=g)
