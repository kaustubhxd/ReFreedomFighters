"""specs_s6244.py - unclaimed-62 claim 37 (gap band): 0x565a40 (thiscall, one stack argument, ret 4; returns eax). The callee 0x564a40 (one argument) is a
recording stub by address (GUESS: its body is not part of this batch). this+0xc7e points at an object whose vtable slot 0xbc (one argument) is a logged
stub returning a random word. The record is 0xd00 random bytes (the object pointer is at +0xc7e). No faulting cases."""
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
    e.hook(0x564a40, lambda em, rr: (em.calllog.append(('564a40', em.reg('ecx'), em.arg32(0))), em.ret(argbytes=4)))
    rec = rnd(c, 0xd00)
    obj = rnd(c, 0x100)
    retv = r.getrandbits(32)
    e.w32(obj, vtable(c, 'o565a40', 0x100, impl={0xbc: lambda em, aa: retv}, argwords={0xbc: 1}))
    e.w32(rec + 0xc7e, obj)
    return [rec, r.getrandbits(32)]


S(0x565a40, 'unnamed 0x565a40', 'thiscall', None, ret='eax', gen=_x, n=300)
