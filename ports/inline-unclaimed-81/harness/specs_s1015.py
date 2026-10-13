"""specs_s1015.py - area 81, batch 1015: ZParamAnim::Load (0x4a29f0). The load object's slots 0x44, 0x50, 0x58 and 0x68 are counting stubs. The object at
this+0x44 has slot 0x4c (returns R, which is null in 40% of cases and an object otherwise) and 0x1d8 (writes a pointer to its stack argument's
object and returns it). The inline object at this+0x59 (its vtable word is written into the self object) has slots 0x14 and 0x8. The debug object at
0x700390 has slot 0x20 (returns a channel whose slot 0x2c is a cdecl stub). The render manager's slot 0x114 returns random words. The helpers
0x4a2f90, 0x4cc1d0 and 0x4cbec0 are counting stubs (0x4cc1d0 returns a random value). The self object's slot 0x58 is a counting stub."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    rnd = c.rng
    ss.patch(c, 0x4a2f90, ss.rec(c, 0))
    ss.patch(c, 0x4cc1d0, ss.rec(c, 0, ret=r32(c)))
    ss.patch(c, 0x4cbec0, ss.rec(c, 0))
    lg = obj(c, 0x40, {0x44: _stub(c, 1), 0x50: _stub(c, 1), 0x58: _stub(c, 1), 0x68: _stub(c, 1)})
    Q = obj(c, 0x40)
    R = obj(c, 0x40) if rnd.random() < 0.6 else 0
    M = obj(c, 0x40, {0x4c: _stub(c, 1, ret=R), 0x1d8: _stub(c, 2, skip=(0,), ret=Q)})
    chan = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=chan)})
    c.emu.w32(0x700390, dbg)
    rm = obj(c, 0x40, {0x114: _stub(c, 4, ret=r32(c))})
    sysobj = c.emu.alloc(0x2000, 4)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x9b, rm)
    O59 = obj(c, 0x40, {0x8: _stub(c, 1, ret=r32(c)), 0x14: _stub(c, 1, ret=r32(c))})
    self_ = obj(c, 0x200, {0x58: _stub(c, 0, ret=r32(c))})
    c.emu.wbytes(self_ + 0x59, c.emu.rbytes(O59, 4))
    c.emu.w32(self_ + 0x44, M)
    c.emu.w32(self_ + 4, r32(c))
    return [self_, lg]


S(0x4a29f0, 'ZParamAnim::Load', 'thiscall', None, ret='al', gen=g)
