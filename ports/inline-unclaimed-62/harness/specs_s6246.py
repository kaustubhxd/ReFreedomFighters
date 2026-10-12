"""specs_s6246.py - ragdoll side (claim 39): 0x645120, ZBoneModifyBase::ZBoneModifyBase (thiscall, one argument; returns this). The engine object at
eng+0x1aa3 has a logged vtable slot 0x94 (no argument) returning a random word. The record is 0x400 random bytes; every field the constructor writes is
compared. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _x(c):
    e = c.emu
    r = c.rng
    obj = e.alloc(0x40)
    retv = r.getrandbits(32)
    e.w32(obj, vtable(c, 'obj645120', 0x100, impl={0x94: lambda em, a: retv}, argwords={0x94: 0}))
    eng = e.alloc(0x1b00)
    e.w32(eng + 0x1aa3, obj)
    e.w32(0x70039c, eng)
    return [rnd(c, 0x400), r.getrandbits(32)]


S(0x645120, 'unnamed 0x645120', 'thiscall', None, ret='eax', gen=_x, n=300)
