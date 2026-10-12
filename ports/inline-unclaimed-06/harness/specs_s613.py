"""specs_s613.py - unclaimed-06 claim 13 (docs/20-unclaimed-06.md): ZRunParamAnim::~ZRunParamAnim. Thiscall, one argument
(random flags word), ret 4, returns this. The object is 0x1000 random bytes. The base destructor 0x4e6ce0 (thiscall, no
arguments) and the CRT delete 0x634273 (cdecl) are replaced by plain counting stubs (GUESS): ss.rec(c, 0) pops nothing
and logs no arguments, so the delete size is not compared."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import serial_stubs as ss


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    self = _rnd(c, 0x1000)
    ss.patch(c, 0x4e6ce0, ss.rec(c, 0))    # GUESS-stub of the base destructor
    ss.patch(c, 0x634273, ss.rec(c, 0))    # GUESS-stub of the CRT delete (cdecl: ret 0)
    return [self, c.rng.getrandbits(32)]


S(0x49e490, 'ZRunParamAnim::~ZRunParamAnim (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-06 claim 13; base dtor 0x4e6ce0 and CRT delete 0x634273 stubbed (GUESS)')
