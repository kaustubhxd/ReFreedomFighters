"""specs_s1504.py - unclaimed-15 claim 4 (docs/20-unclaimed-15.md): ZFFFlak::Init2 (0x5dcc20) and CTimerEvent::Init (0x5c58e0).

ZFFFlak::Init2: the check helper 0x5dc7a0 is STUBBED (unverified, not lifted): a sequence stub (serial_stubs.seqr) returns
four per-case values in order, so the four checks take each path. The flak object is 0x200 random bytes with a logging
vtable whose slot +0x68 takes two arguments. The helper's own behaviour is not compared.

CTimerEvent::Init: the DBREAD operator (0x4e5e60) is STUBBED through serial_stubs.dbread_patch, returning one per-case
value. The ZGEOM argument is random and unused; the DBREAD object is 0x40 random bytes."""
import os
import sys

for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss   # noqa: E402

from pilot import S   # noqa: E402


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _flak(c):
    o = _rnd(c, 0x200)
    vt = c.emu.logging_vtable('ZFFFlak', 0x80, impl={}, argwords={0x68: 2})
    c.emu.w32(o, vt)
    rets = [c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)]) for _ in range(4)]
    ss.patch(c, 0x5dc7a0, ss.seqr(c, 1, rets))
    return [o]


def _timer(c):
    o = _rnd(c, 0x100)
    geom = _rnd(c, 0x40)
    dbread = _rnd(c, 0x40)
    ss.dbread_patch(c, [c.rng.choice([0, 1, 0x7fffffff, c.rng.getrandbits(32)])], [0], [0])
    return [o, geom, dbread]


S(0x5dcc20, 'ZFFFlak::Init2 (unknown) thiscall', 'thiscall', None, ret=None, gen=_flak,
  note='unclaimed-15 claim 4; helper 0x5dc7a0 stubbed (seqr); slot +0x68 with (0x10, 0)')
S(0x5c58e0, 'CTimerEvent::Init (unknown) thiscall', 'thiscall', None, ret=None, gen=_timer,
  note='unclaimed-15 claim 4; DBREAD operator stubbed (dbread_patch); +0x48 = value or 1')
