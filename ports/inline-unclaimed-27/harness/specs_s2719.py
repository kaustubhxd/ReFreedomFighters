"""specs_s2719.py - unclaimed-27 batch 19: FUN_5897d0 (GUESS). Pure stores; no stubs. The object is 0x800 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _z(c):
    return [_rnd(c, 0x800)]


S(0x5897d0, 'FUN_5897d0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_z,
  note='gap band batch 19; zeroes +0, +0x34, +0x38, +0x7c, +0xb0')
