"""specs_s972.py - residue-04, batch 972: ZActorIf::SetHoldWeaponUBAnim (0x508100). The helper 0x5003d0 (thiscall, returns a
pointer to an int) is stood in; the debug object (0x700390) has slot 0x20 stood in, and the channel it returns has a cdecl
slot 0x2c (three stack args, caller cleans; cstub). The this-object's helper object has slots 0x20 and 0x69c; the render
manager is an object with +0x44. The int is random in -5..5, so both the tail path and the print path are reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, cstub, obj, r32


def g(c):
    cell = c.emu.alloc(4, 4)
    c.emu.w32(cell, c.rng.randint(-5, 5) & 0xffffffff)
    ss.patch(c, 0x5003d0, _stub(c, 1, ret=cell))
    xobj = obj(c, 0x40)
    c.emu.w32(xobj + 4, r32(c) if c.rng.random() < 0.6 else 0)
    ch = obj(c, 0x40, {0x2c: cstub(c, 3)})
    dbg = obj(c, 0x40, {0x20: _stub(c, 2, ret=ch)})
    c.emu.w32(0x700390, dbg)
    rm = obj(c, 0x100)
    c.emu.w32(rm + 0x44, r32(c))
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    e = obj(c, 0x40, {0x20: _stub(c, 0, ret=xobj), 0x69c: _stub(c, 1, ret=r32(c))})
    t = obj(c, 0x80)
    c.emu.w32(t + 0x18, e)
    p = obj(c, 0x40)
    q = obj(c, 0x40)
    c.emu.w32(p + 4, q)
    return [t, p]


S(0x508100, 'ZActorIf::SetHoldWeaponUBAnim', 'thiscall', ret='eax', gen=g)
