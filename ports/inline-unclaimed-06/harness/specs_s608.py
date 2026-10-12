"""specs_s608.py - unclaimed-06 claim 8 (docs/20-unclaimed-06.md): CExplode::CopyData(ZEventBase*). Thiscall, one argument,
ret 4. The object is 0x1000 random bytes, with +0x44 pointing at a 0x40-byte block whose +8 points at a 0x80-byte block
holding the value at +0x3c (random, so bit 10 takes both values). The source is a random 0x100-byte block. The callee
0x5833e0 is stubbed on both sides (GUESS)."""
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
    src = _rnd(c, 0x100)
    ss.patch(c, 0x5833e0, ss.rec(c, 2))   # GUESS-stub of the callee (counts and logs its two arguments)
    p = _rnd(c, 0x40)
    q = _rnd(c, 0x80)
    c.emu.w32(p + 8, q)
    c.emu.w32(q + 0x3c, c.rng.getrandbits(32))
    c.emu.w32(self + 0x44, p)
    return [self, src]


S(0x582690, 'CExplode::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-06 claim 8; calls original 0x5833e0 with (0, 0) when bit 10 clear and +0x5d set')
