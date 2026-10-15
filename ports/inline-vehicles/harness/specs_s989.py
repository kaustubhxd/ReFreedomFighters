"""specs_s989.py - residue-11, batch 989: ZFFHeroIf::BeamToRef (0x55ee30). The id helper 0x5003d0 and 0x55f900 (three args, ret 12) are
stood in; 0x4e09b0 runs as exe code. The render manager's slot 0x58 answers an object or zero; the object's slots 0x80 (writes the two
output vectors through its stack pointers, three dwords each) and 0x1e0 (flag) are stubs. The print path's channel slot 0x30 is a cdecl
counting stub (three logged arguments; the object's data is heap)."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32, rf


def g(c):
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, r32(c))
    ss.patch(c, 0x5003d0, _stub(c, 1, ret=cell))
    ss.patch(c, 0x55f900, _stub(c, 3, skip=(1, 2), ret=0))
    src1 = c.emu.alloc(12, 4)
    src2 = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(src1 + 4 * j, rf(c, -5, 5))
        c.emu.w32(src2 + 4 * j, rf(c, -5, 5))
    x = obj(c, 0x40, {0x80: _stub(c, 2, skip=(0, 1), ofills=((0, 0, src1, 3), (1, 0, src2, 3))),
                      0x1e0: _stub(c, 1, ret=c.rng.randint(0, 1))})
    rmx = obj(c, 0x100, {0x58: _stub(c, 1, ret=(x if c.rng.random() < 0.7 else 0))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rmx)
    c.emu.w32(0x70039c, sysobj)
    w = obj(c, 0x40)
    c.emu.w32(w + 4, r32(c))
    e = obj(c, 0x40, {0x20: _stub(c, 0, ret=w), 0x370: _stub(c, 2, skip=(0, 1))})
    ch = obj(c, 0x40, {0x30: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    t = obj(c, 0x100)
    c.emu.w32(t + 0x18, e)
    p = obj(c, 0x40)
    q = obj(c, 0x40)
    c.emu.w32(p + 4, q)
    return [t, p]


S(0x55ee30, 'ZFFHeroIf::BeamToRef', 'thiscall', gen=g)
