"""specs_s6202.py - unclaimed-62 claim 2 (residue 03): ZFFFlak::Load (0x5dccb0). The input read (0x6352f0) and the helper (0x5dcea0) are
patched with stubs (other claims' code); the load object's slots 0x40 and 0x50 (one pointer argument each) are logged. Returns al.
No faulting cases."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss
from pfspec import rnd, vtable


def _flak(c):
    e = c.emu
    r = c.rng
    ss.patch(c, 0x6352f0, ss.rec(c, 1, ret=r.getrandbits(8), log=False))
    ss.patch(c, 0x5dcea0, ss.rec(c, 1, log=False))
    self_ = rnd(c, 0x100)
    load = rnd(c, 0x40)
    e.w32(load, vtable(c, 'zload_flak', 0x80, argwords={0x40: 1, 0x50: 1}))
    return [self_, load]


S(0x5dccb0, 'ZFFFlak::Load', 'thiscall', None, ret='al', gen=_flak, n=300)
