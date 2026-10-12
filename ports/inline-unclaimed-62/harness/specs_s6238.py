"""specs_s6238.py - unclaimed-62 claim 31 (gap band 0x561000-0x581000): eight constructors (0x569380, 0x56db70, 0x571960, 0x5773f0, 0x57a3b0,
0x57abc0, 0x57c100, 0x57f1b0). Each calls the base constructor 0x561020, writes its vtable at this[0] and returns this. The base constructor is a
recording stub installed by address (GUESS: its body is not part of this batch); its stub writes nothing. The records are 0x100 random bytes.
No faulting cases."""
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
        em.calllog.append(('base561020', em.reg('ecx')))
        em.ret(argbytes=0)
    e.hook(0x561020, base)
    return [rnd(c, 0x100)]


S(0x569380, 'unnamed 0x569380', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x56db70, 'unnamed 0x56db70', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x571960, 'unnamed 0x571960', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x5773f0, 'unnamed 0x5773f0', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x57a3b0, 'unnamed 0x57a3b0', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x57abc0, 'unnamed 0x57abc0', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x57c100, 'unnamed 0x57c100', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x57f1b0, 'unnamed 0x57f1b0', 'thiscall', None, ret='eax', gen=_x, n=300)
