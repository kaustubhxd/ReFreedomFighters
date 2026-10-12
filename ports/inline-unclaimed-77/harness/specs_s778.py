"""specs_s778.py - unclaimed-77 claim 8 (docs/20-unclaimed-77.md): ZActionControlMap::FindGameState(). Thiscall, no arguments,
ret 0. The object is 0x1000 random bytes; the flag bytes at +0x168, +0x1a3, +0x22b, +0x22d are zero in half the cases and nonzero otherwise. this+0x63
and this+0x5f hold pointers to stand-in blocks (0xb00 and 0x800 bytes). The callee 0x591b20 is stubbed (GUESS): a table-driven
stub returning 8 random case indices in 0 to 0x13 (values above 0x10 take the default path)."""
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
    blockA = _rnd(c, 0xb00)
    blockB = _rnd(c, 0x800)
    for off in (0x168, 0x1a3, 0x22b, 0x22d):
        # random bytes are zero only 1 time in 256, so force zero in half the cases (the zero branches are the cmove paths)
        c.emu.wbytes(self + off, bytes([0 if c.rng.random() < 0.5 else c.rng.randint(1, 255)]))
    c.emu.w32(self + 0x63, blockA)
    c.emu.w32(self + 0x5f, blockB)
    rets = [c.rng.randint(0, 0x13) for _ in range(8)]
    ss.patch(c, 0x591b20, ss.seqr(c, 0, rets))   # GUESS-stub of the case selector
    return [self]


S(0x5b2d00, 'ZActionControlMap::FindGameState (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-77 claim 8; callee 0x591b20 stubbed (GUESS, table of case indices 0 to 0x13)')
