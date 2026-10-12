"""specs_s1957.py - unclaimed-66 batch 67 (gap band, GUESS name). THISCALL(this), no arguments; returns this.

Pure field stores (no calls). The object is 0x40 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    return [_rnd(c, 0x40)]


S(0x511c60, 'GUESS FUN_00511c60 (field clear; returns this)', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-66 batch 1957; gap band; no callees')
