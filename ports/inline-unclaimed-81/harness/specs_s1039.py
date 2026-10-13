"""specs_s1039.py - area 81, batch 1039: 0x64ff00 (thiscall, this; ecx = [this+0xbd], then the object's vtable slot 0x64 with the same ecx, tail-jumped).
The inner object's slot 0x64 is a plain GUESS stub with no stack arguments (it returns eax as the stub's own value)."""
import os, sys, struct
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import obj, _stub


def g(c):
    inner = obj(c, 0x40, {0x64: _stub(c, 0, ret=c.rng.getrandbits(32))})
    o = obj(c, 0x200)
    c.emu.w32(o + 0xbd, inner)
    return [o]


S(0x64ff00, 'GUESS 0x64ff00 vslot thunk', 'thiscall', None, ret='eax', gen=g)
