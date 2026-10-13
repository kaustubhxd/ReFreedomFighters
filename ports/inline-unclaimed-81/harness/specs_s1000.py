"""specs_s1000.py - area 81 (residue 0), batch 1000: ZMovementAnimation::Move (0x489400). The helpers 0x43e920 (fastcall, one stack argument) and
0x4e0d00 (thiscall, one float argument) are GUESS stand-ins (counting, machine code no-op). The object's vslots 0x50 (four args) and 0x48 (five
args) are counting stubs. The frame time and the object's field at +0x18 are random, with zero in some cases so both branches run."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x43e920, ss.rec(c, 1, log=False))
    ss.patch(c, 0x4e0d00, ss.rec(c, 1))
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x48, rf(c, -2, 2))
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x80, {0x50: _stub(c, 4), 0x48: _stub(c, 5)})
    c.emu.w32(t + 0x18, 0 if c.rng.random() < 0.3 else rf(c, -2, 2))
    a = [c.emu.alloc(12, 4) for _ in range(5)]
    return [t] + a


S(0x489400, 'ZMovementAnimation::Move', 'thiscall', gen=g)
