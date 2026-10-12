"""specs_s6219.py - unclaimed-62 claim 12 (slice 2): 0x4682f0 (thiscall, one float argument passed as raw bits; the record's +0x1da is compared)
and 0x561ef0 (thiscall, returns al: the flag at +0x44 is zero or not; clears +0x44 and +0x30). The record is 0x200 bytes of random data.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from pfspec import rnd


def _f(c):
    return [rnd(c, 0x200), c.rng.getrandbits(32)]


def _b(c):
    r = c.rng
    rec = rnd(c, 0x200)
    c.emu.w32(rec + 0x44, r.choice([0, r.getrandbits(32) | 1]))
    return [rec]


S(0x4682f0, 'unnamed 0x4682f0', 'thiscall', None, gen=_f, n=300)
S(0x561ef0, 'unnamed 0x561ef0', 'thiscall', None, ret='al', gen=_b, n=300)
