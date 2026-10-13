"""specs_s6236.py - unclaimed-62 claim 29 (short call-free exe functions): 0x4d2300 (thiscall, two random arguments; returns this), 0x4e0e30
(thiscall, one argument: a random block whose first dword is a random header word; returns this), 0x5a46f0 (thiscall, one argument in -2..8; the
function returns an address or 0). Records are 0x1000 random bytes; the blocks are 0x40 bytes. No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _x4d23(c):
    r = c.rng
    rec = rnd(c, 0x100)
    return [rec, r.getrandbits(32), r.getrandbits(32)]


def _x4e0e(c):
    r = c.rng
    e = c.emu
    rec = rnd(c, 0x100)
    p = rnd(c, 0x40)
    e.w32(p, r.getrandbits(32))
    return [rec, p]


def _x5a46(c):
    rec = rnd(c, 0x1000)
    return [rec, c.rng.randint(-2, 8) & 0xffffffff]


S(0x4d2300, 'unnamed 0x4d2300', 'thiscall', None, ret='eax', gen=_x4d23, n=1000)
S(0x4e0e30, 'unnamed 0x4e0e30', 'thiscall', None, ret='eax', gen=_x4e0e, n=1000)
S(0x5a46f0, 'unnamed 0x5a46f0', 'thiscall', None, ret='eax', gen=_x5a46, n=1000)
