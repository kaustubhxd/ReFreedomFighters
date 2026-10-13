"""specs_s6239.py - unclaimed-62 claim 32 (gap band): 0x573490 and 0x57bd70 (thiscall, two stack arguments; each returns al = 0). The callees 0x562e90
and 0x565020 are recording stubs installed by address (GUESS: their bodies are not part of this batch); the stubs write nothing and return 0.
The record is 0x200 random bytes; the byte at +0x180 of 0x573490 is compared. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _stubs(c):
    e = c.emu

    def mk(name):
        def h(em, rr):
            em.calllog.append((name, em.reg('ecx'), em.arg32(0), em.arg32(1)))
            em.ret(eax=0, argbytes=8)
        return h
    e.hook(0x562e90, mk('562e90'))
    e.hook(0x565020, mk('565020'))


def _x(c):
    r = c.rng
    _stubs(c)
    rec = rnd(c, 0x200)
    return [rec, r.getrandbits(32), r.getrandbits(32)]


S(0x573490, 'unnamed 0x573490', 'thiscall', None, ret='al', gen=_x, n=1000)
S(0x57bd70, 'unnamed 0x57bd70', 'thiscall', None, ret='al', gen=_x, n=1000)
