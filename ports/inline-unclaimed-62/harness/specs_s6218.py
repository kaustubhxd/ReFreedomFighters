"""specs_s6218.py - unclaimed-62 claim 11 (slice 2): six leaves that take this only (0x437070, 0x438330 write a byte at this+0x10; 0x440930 and
0x44c0f0 return constants; 0x440cb0 and 0x4632f0 return a dword field). The record is 0x100 bytes of random data, so every write is compared.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x(c):
    return [rnd(c, 0x100)]


S(0x437070, 'unnamed 0x437070', 'thiscall', None, gen=_x, n=300)
S(0x438330, 'unnamed 0x438330', 'thiscall', None, gen=_x, n=300)
S(0x440930, 'unnamed 0x440930', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x440cb0, 'unnamed 0x440cb0', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x44c0f0, 'unnamed 0x44c0f0', 'thiscall', None, ret='eax', gen=_x, n=300)
S(0x4632f0, 'unnamed 0x4632f0', 'thiscall', None, ret='eax', gen=_x, n=300)
