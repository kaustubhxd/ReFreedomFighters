"""specs_s6216.py - unclaimed-62 claim 9 (slice 1): 0x44b610 (no name; thiscall, no arguments). The engine's helper object A (+0x1a9f) is
a logged vtable object (slots 0x130, 0x134 with the 0x134 stack local peeked); its byte +0xc is 0 or 1 (1 is the early exit) and it may be
null. The message table's slot 0x58 gives a per-case object (its slot 0x210 and +0x1c are logged) or null; slot 0x64 gives a value.
this+0, +0x30, +0x34, +0x38 and +0x7c are random, zero or set. No faulting cases."""
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
    eng = e.alloc(0x1b00)
    obj = e.alloc(0x40)
    e.w32(obj + 0x1c, r.getrandbits(32))
    e.w32(obj, vtable(c, 'obj44b', 0x240, impl={0x210: lambda em, a: 0}, argwords={0x210: 1}))
    retv = r.getrandbits(32)
    msg = e.alloc(0x80)
    e.w32(msg, vtable(c, 'msg44b', 0x80, impl={
        0x58: lambda em, a: obj if r.random() < 0.8 else 0,
        0x64: lambda em, a: retv}, argwords={0x58: 1, 0x64: 1}))
    e.w32(eng + 0x9b, msg)
    if r.random() < 0.9:
        a = e.alloc(0x40)
        e.w32(a, vtable(c, 'helper44b', 0x180, impl={0x130: lambda em, a: 0, 0x134: lambda em, a: 0},
                        argwords={0x130: 1, 0x134: 2}, opts={0x134: {'peek': {1: 4}}}))
        e.w8(a + 0xc, r.choice([0, 0, 1]))
        e.w32(eng + 0x1a9f, a)
    else:
        e.w32(eng + 0x1a9f, 0)
    e.w32(0x70039c, eng)
    self_ = rnd(c, 0x100)
    e.w32(self_, r.choice([0, 0x12345678 + r.getrandbits(8)]))
    for off in (0x30, 0x34, 0x38):
        e.w32(self_ + off, r.choice([0, 0, r.getrandbits(32) | 1]))
    e.w32(self_ + 0x7c, r.choice([0, r.getrandbits(32) | 1]))
    return [self_]


S(0x44b610, 'unnamed 0x44b610', 'thiscall', None, gen=_x, n=1000)
