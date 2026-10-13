"""specs_s6241.py - unclaimed-62 claim 34 (gap band): 0x572e40 (thiscall, no argument; returns this). The base constructor 0x561020 is a recording
stub installed by address (GUESS: its body is not part of this batch). The record is 0x200 random bytes; the vtable word and the byte at +0x180 are
compared. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x(c):
    e = c.emu

    def base(em, rr):
        em.calllog.append(('561020', em.reg('ecx')))
        em.ret(argbytes=0)
    e.hook(0x561020, base)
    return [rnd(c, 0x200)]


S(0x572e40, 'unnamed 0x572e40', 'thiscall', None, ret='eax', gen=_x, n=1000)
