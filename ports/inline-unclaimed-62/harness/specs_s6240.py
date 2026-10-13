"""specs_s6240.py - unclaimed-62 claim 33 (gap band): 0x565840 (thiscall, no argument; returns this) and 0x565b60 (thiscall, two stack arguments;
returns al = 0). The callees 0x564460 (base constructor, no argument), 0x564600 (one argument) and 0x565020 (two arguments) are recording stubs
installed by address (GUESS: their bodies are not part of this batch); each stub writes nothing and returns 0. The record is 0x200 random bytes.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _stubs(c):
    e = c.emu

    def rec_stub(name, argbytes, nargs):
        def h(em, rr):
            em.calllog.append((name, em.reg('ecx')) + tuple(em.arg32(k) for k in range(nargs)))
            em.ret(eax=0, argbytes=argbytes)
        return h
    e.hook(0x564460, rec_stub('564460', 0, 0))
    e.hook(0x564600, rec_stub('564600', 4, 1))
    e.hook(0x565020, rec_stub('565020', 8, 2))


def _x565840(c):
    _stubs(c)
    return [rnd(c, 0x200)]


def _x565b60(c):
    r = c.rng
    _stubs(c)
    return [rnd(c, 0x200), r.getrandbits(32), r.getrandbits(32)]


S(0x565840, 'unnamed 0x565840', 'thiscall', None, ret='eax', gen=_x565840, n=1000)
S(0x565b60, 'unnamed 0x565b60', 'thiscall', None, ret='al', gen=_x565b60, n=1000)
