"""specs_s962.py - residue-04/05, batch 962: 0x55edc0 and 0x55fb90. Each helper (0x55fb90 for the first, 0x506220 for the
second) is stood in for the case with hookrec (it records ECX and the two arguments). The argument X holds the object Z
at +0x15; Z's slot 0x3c is a stub; the render manager's slot 0x4c answers a constant."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, hookrec, obj, r32


def mk(helper):
    def g(c):
        hookrec(c, helper, 2, ret=0, this=True)
        z = obj(c, 0x40, {0x3c: _stub(c, 1)})
        x = obj(c, 0x40)
        c.emu.w32(x + 0x15, z)
        rm = obj(c, 0x100, {0x4c: _stub(c, 1, ret=r32(c))})
        sysobj = c.emu.alloc(0x200, 4)
        c.emu.w32(sysobj + 0x9b, rm)
        c.emu.w32(0x70039c, sysobj)
        t = obj(c, 0x40)
        return [t, x, r32(c)]
    return g


S(0x55edc0, 'GUESS FUN_55edc0 (helper 0x55fb90 stood in)', 'thiscall', gen=mk(0x55fb90))
S(0x55fb90, 'GUESS FUN_55fb90 (helper 0x506220 stood in)', 'thiscall', gen=mk(0x506220))
