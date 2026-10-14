"""specs_s965.py - residue-05, batch 965: ZFFActor::GetWeaponDrawn (0x5a0050). The render manager's slot 0x58 and the
actor's slots 0x504 and 0x500 are stubs. Their answers are chosen per case so that all branches (X zero, X equal to A,
X equal to B, X different) are reached."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, obj, r32


def g(c):
    a = r32(c) | 1
    b = r32(c) | 1
    x = c.rng.choice([0, a, b, r32(c) | 1])
    rm = obj(c, 0x100, {0x58: _stub(c, 1, ret=x)})
    sysobj = c.emu.alloc(0x200, 4)
    c.emu.w32(sysobj + 0x9b, rm)
    c.emu.w32(0x70039c, sysobj)
    t = obj(c, 0x80, {0x504: _stub(c, 0, ret=a), 0x500: _stub(c, 0, ret=b)})
    return [t, r32(c)]


S(0x5a0050, 'ZFFActor::GetWeaponDrawn', 'thiscall', ret='al', gen=g)
