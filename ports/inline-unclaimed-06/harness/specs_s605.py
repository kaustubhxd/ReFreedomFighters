"""specs_s605.py - unclaimed-06 claim 5 (docs/20-unclaimed-06.md): ZDamageBox::CopyEventDataBlock(DBREAD&).
Thiscall, one argument, ret 4. The DBREAD operators, GetRefTab and GetInput come from the shared serialisation stubs
(decomp-pilot/shared-harness/serial_stubs.py), the same set batch 81 uses. The callee 0x4e5ef0 is original code on both sides."""
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


def _dbread(c):
    r = c.rng
    rets32 = [r.getrandbits(32) for _ in range(8)]
    rets16 = [r.getrandbits(16) | (r.getrandbits(16) << 16) for _ in range(8)]
    counts = [r.randint(0, 3) for _ in range(8)]
    ss.dbread_patch(c, rets32, rets16, counts)
    ss.rm_object(c, r.getrandbits(32))


def _gen(c):
    self = _rnd(c, 0x1000)
    db = _rnd(c, 0x40)
    _dbread(c)
    ss.patch(c, 0x4e5ef0, ss.rec(c, 0, ret=c.rng.getrandbits(8)))   # GUESS-stub of the DBREAD bool reader
    c.emu.mu.ctl_flush_tb()
    return [self, db]


S(0x5db150, 'ZDamageBox::CopyEventDataBlock (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-06 claim 5; callee 0x4e5ef0 stubbed (GUESS, returns random byte), byte to +0x88, bool dword to +0x60')
