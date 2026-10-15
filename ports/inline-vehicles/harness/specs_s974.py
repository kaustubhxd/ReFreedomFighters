"""specs_s974.py - residue-05, batch 974: ZFFActorIf::DrawLineToRef (0x558d90). The helper 0x5003d0 (returns a pointer to an id) is
stood in; the render manager's slot 0x58 answers an object or zero (both paths); the debug channel's cdecl slot 0x2c (cstub); the
X and Y objects' slot 0x84 fill the vectors through an output-fill stub; the sys slot 0x1bc answers a random int; the render
object's slot 0x218 (thiscall, callee pops 12) is a counting stub with the stack vectors skipped."""
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
    srcx = c.emu.alloc(12, 4)
    srcy = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(srcx + 4 * j, rf(c, -50, 50))
        c.emu.w32(srcy + 4 * j, rf(c, -50, 50))
    x = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), ofills=((0, 0, srcx, 3),))})
    y = obj(c, 0x40, {0x84: _stub(c, 1, skip=(0,), ofills=((0, 0, srcy, 3),))})
    c.emu.w32(y + 4, r32(c) if c.rng.random() < 0.6 else 0)
    rm = obj(c, 0x1000, {0x58: _stub(c, 1, ret=(x if c.rng.random() < 0.5 else 0))})
    R = obj(c, 0x40, {0x218: _stub(c, 3, skip=(0, 1))})
    c.emu.w32(rm + 0xadc, R)
    sysobj = obj(c, 0x200, {0x1bc: _stub(c, 2, ret=r32(c))})
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    ch = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    t = obj(c, 0x80)
    c.emu.w32(t + 0x1c, y)
    p = obj(c, 0x40)
    q = obj(c, 0x40)
    c.emu.w32(p + 4, q)
    return [t, p]


S(0x558d90, 'ZFFActorIf::DrawLineToRef', 'thiscall', gen=g)
