"""specs_s994.py - residue-11, batch 994: ZFFSearchLightGroup::PutAnimatedGeomsIntoList (0x5c7570). The helper 0x4db2f0 (stood in, one arg)
answers the object R whose slot 0x25c (copy buffer, zero) answers a handle or zero; the render manager's slot 0x4c, the slot-4 calls and the
this+0x44 slots (0x130, 0x12c) are counting stubs; the debug channel's cdecl slot 0x2c is a counting stub. The copy buffer's address is a
stack pointer (skipped in the record). The word at 0x714348 is random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32, rf


def g(c):
    c.emu.w32(0x714348, r32(c))
    R = obj(c, 0x40, {0x25c: _stub(c, 2, skip=(0,), ret=(c.rng.randint(1, 0xffffff) if c.rng.random() < 0.6 else 0))})
    ss.patch(c, 0x4db2f0, _stub(c, 1, ret=R))
    rm = obj(c, 0x100, {0x4c: _stub(c, 1, ret=r32(c))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    Q = obj(c, 0x40, {4: _stub(c, 1)})
    ch = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    ex = obj(c, 0x40, {0x130: _stub(c, 3), 0x12c: _stub(c, 3)})
    X = obj(c, 0x40)
    sp = c.emu.alloc(16, 4)
    c.emu.wbytes(sp, bytes(c.rng.randint(65, 90) for _ in range(8)) + b'\x00')
    c.emu.w32(X + 4, sp if c.rng.random() < 0.5 else 0)
    c.emu.w32(X + 8, obj(c, 0x40))
    a = obj(c, 0x40)
    c.emu.w32(a + 0x10, Q)
    c.emu.w32(a + 0x1c, X)
    c.emu.w32(a, r32(c))
    self_ = obj(c, 0x80)
    c.emu.w32(self_ + 0x44, ex)
    return [self_, a]


S(0x5c7570, 'ZFFSearchLightGroup::PutAnimatedGeomsIntoList', 'thiscall', gen=g)
