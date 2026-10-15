"""specs_s981.py - residue-10, batch 981: ZItemTemplateWeapon::Load (0x46f6e0). The base (0x440e10) is a counting stub. The load
object is one generic object whose slots write random dwords through their pointer arguments (0x40, 0x6c, 0x74, 0x50), with the
slot 0x70 a counting stub; the render manager's slot 0x58 answers random values."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32


def g(c):
    ss.patch(c, 0x440e10, ss.rec(c, 1))
    G = obj(c, 0x80)
    vt = c.emu.r32(G)
    for off in (0x40, 0x50, 0x6c, 0x74):
        src = c.emu.alloc(4, 4)
        c.emu.w32(src, r32(c))
        c.emu.w32(vt + off, _stub(c, 1, skip=(0,), ret=G, ofills=((0, 0, src, 1),)))
    c.emu.w32(vt + 0x70, ss.rec(c, 1))
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=r32(c))})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x200)
    c.emu.w32(t + 0x70, r32(c))
    return [t, G]


S(0x46f6e0, 'ZItemTemplateWeapon::Load', 'thiscall', ret='al', gen=g)
