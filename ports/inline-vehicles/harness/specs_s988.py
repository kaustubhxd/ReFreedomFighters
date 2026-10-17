"""specs_s988.py - residue-11, batch 988: ZFFItemBomb::Load (0x5d4770). The load object is one generic object whose slots write random
dwords through their pointer argument (stack-pointer arguments are not recorded) and return the object itself; the render manager's
slot 0x58 answers random values, its slot 0x138 answers an object whose slot 0x4c is a counting stub."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, obj, r32


def g(c):
    G = obj(c, 0x80)
    vt = c.emu.r32(G)
    from vh import _stub as st
    for off in (0x40, 0x50, 0x68):
        src = c.emu.alloc(4, 4)
        c.emu.w32(src, r32(c))
        c.emu.w32(vt + off, st(c, 1, skip=(0,), ret=G, ofills=((0, 0, src, 1),)))
    X = obj(c, 0x40, {0x4c: _stub(c, 2)})
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=r32(c)), 0x138: _stub(c, 0, ret=X)})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x200)
    return [t, G]


S(0x5d4770, 'ZFFItemBomb::Load', 'thiscall', ret='al', gen=g)
