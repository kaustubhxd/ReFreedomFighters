"""specs_s953.py - residue-03, batch 953: ZWeaponTest::Init (0x469130). The DBREAD read (0x4e5e60) and CreateWeapons
(0x46d5f0) are counting stubs in the exe image; the render manager (0x58), the sub-object release (0xc) and the item
objects (0x1e0) are vtable stubs. The CRT memset (0x634d10) runs as exe code. The list is 0..3 nodes long."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _rnd, _stub, obj, r32


def g(c):
    geo = obj(c, 0x80)
    dbres = obj(c, 0x80)
    prev = 0
    for _ in range(c.rng.randint(0, 3)):
        node = obj(c, 0x80)
        if c.rng.random() < 0.8:
            sub = c.emu.alloc(0x40, 4)
            c.emu.w32(sub + 0x23, r32(c))
            item = obj(c, 0x40, {0x1e0: _stub(c, 1, ret=c.rng.randint(0, 1))})
            c.emu.w32(item + 0xc, sub)
            c.emu.w32(node + 0x54, item)
        else:
            c.emu.w32(node + 0x54, 0)
        c.emu.w32(node + 0x60, prev)
        prev = node
    c.emu.w32(geo + 0x50, prev)
    ss.patch(c, 0x4e5e60, _stub(c, 0, ret=dbres))
    ss.patch(c, 0x46d5f0, _stub(c, 0))
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    if c.rng.random() < 0.7:
        c.emu.w32(sysobj + 0x1907, obj(c, 0x40, {0xc: _stub(c, 3)}))
    else:
        c.emu.w32(sysobj + 0x1907, 0)
    c.emu.w32(sysobj + 0x9b, obj(c, 0x100, {0x58: _stub(c, 1, ret=geo)}))
    t = obj(c, 0x800)
    zg = c.emu.alloc(0x40, 4)
    db = c.emu.alloc(0x40, 4)
    return [t, zg, db]


S(0x469130, 'ZWeaponTest::Init', 'thiscall', gen=g)
