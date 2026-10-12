"""specs_s6245.py - unclaimed-62 claim 38 (gap band): 0x56caf0 (thiscall, one stack argument, ret 4). this[0] is a logged vtable whose slot 0xc8 (one
argument) is a recording stub; 0x561180 and 0x56c950 (one argument each) are recording stubs by address (GUESS: bodies not part of this batch). The record
is 0x200 random bytes. No faulting cases."""
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

    def rec_stub(name):
        def h(em, rr):
            em.calllog.append((name, em.reg('ecx'), em.arg32(0)))
            em.ret(argbytes=4)
        return h
    e.hook(0x561180, rec_stub('561180'))
    e.hook(0x56c950, rec_stub('56c950'))
    rec = rnd(c, 0x200)
    e.w32(rec, vtable(c, 'v56caf0', 0x100, impl={0xc8: lambda em, aa: 0}, argwords={0xc8: 1}))
    return [rec, r.getrandbits(32)]


S(0x56caf0, 'unnamed 0x56caf0', 'thiscall', None, gen=_x, n=300)
