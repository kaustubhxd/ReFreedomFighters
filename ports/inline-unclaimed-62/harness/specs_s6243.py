"""specs_s6243.py - unclaimed-62 claim 36 (gap band): 0x563620 (thiscall, two stack arguments, ret 8). The engine's message table (+0x9b) has a
logged slot 0x58 (two arguments) that returns a random word; the callee 0x563650 (one argument) is a recording stub by address (GUESS: its body is not
part of this batch). The record is 0x200 random bytes. No faulting cases."""
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
    e.hook(0x563650, lambda em, rr: (em.calllog.append(('563650', em.reg('ecx'), em.arg32(0))), em.ret(argbytes=4)))
    msg = e.alloc(0x80)
    retv = r.getrandbits(32)
    e.w32(msg, vtable(c, 'msg563620', 0x80, impl={0x58: lambda em, aa: retv}, argwords={0x58: 2}))
    eng = e.alloc(0xa0)
    e.w32(eng + 0x9b, msg)
    e.w32(0x70039c, eng)
    return [rnd(c, 0x200), r.getrandbits(32), r.getrandbits(32)]


S(0x563620, 'unnamed 0x563620', 'thiscall', None, gen=_x, n=300)
