"""specs_s6206.py - unclaimed-62 claim 3 (slice-1 leaves): 0x5a8350 (dword getter), 0x5ab050 (conditional increment), 0x462bd0 (null gives a
constant; otherwise the tail call to 0x4e5330, which is patched to a stub returning a value in eax). No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd


def _plain(c):
    return [rnd(c, 0x900)]


def _inc(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x900)
    e.w32(self_ + 0x300, 0x10000000 if r.random() < 0.5 else r.getrandbits(32))
    return [self_]


def _tail(c):
    e = c.emu
    r = c.rng
    ss.patch(c, 0x4e5330, ss.rec(c, 0, ret=r.getrandbits(32)))
    self_ = rnd(c, 0x100)
    if r.random() < 0.6:
        o = rnd(c, 0x40)
        e.w32(self_ + 0x5c, o)
    else:
        e.w32(self_ + 0x5c, 0)
    return [self_]


S(0x5a8350, 'leaf 0x5a8350', 'thiscall', None, ret='eax', gen=_plain, n=300)
S(0x5ab050, 'leaf 0x5ab050', 'thiscall', None, gen=_inc, n=300)
S(0x462bd0, 'leaf 0x462bd0', 'thiscall', None, ret='eax', gen=_tail, n=300)
