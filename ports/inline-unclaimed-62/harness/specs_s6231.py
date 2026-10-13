"""specs_s6231.py - unclaimed-62 claim 24 (short exe leaves): 0x54f0b0 (thiscall, one argument; writes this+0xc and makes a vtable call on slot 0x18
with the argument, the exe's tail jump) and 0x4d1df0 (thiscall, one argument; returns ST0, the float at the pointer that vtable slot 0x3c returns).
The object at this has logged vtable slots (0x18: one argument; 0x3c: one argument, returns a pointer to a random float block). No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd, vtable


def _obj(c, name, impl, argwords):
    e = c.emu
    o = rnd(c, 0x100)
    e.w32(o, vtable(c, name, 0x100, impl=impl, argwords=argwords))
    return o


def _x54(c):
    r = c.rng
    o = _obj(c, 'v54f0b0', {0x18: lambda em, a: 0}, {0x18: 1})
    return [o, r.getrandbits(32)]


def _x4d(c):
    e = c.emu
    r = c.rng
    block = e.alloc(16)
    e.w32(block, r.getrandbits(32))
    o = _obj(c, 'v4d1df0', {0x3c: lambda em, a: block}, {0x3c: 1})
    return [o, r.getrandbits(32)]


S(0x54f0b0, 'unnamed 0x54f0b0', 'thiscall', None, gen=_x54, n=1000)
S(0x4d1df0, 'unnamed 0x4d1df0', 'thiscall', None, ret='st0', gen=_x4d, n=1000)
