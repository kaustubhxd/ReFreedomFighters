"""specs_s338.py - decomp area 64 (docs/20-unclaimed-64.md): 0x5b02f0 five calls to exe 0x5af2a0, zeroes, tail to exe 0x5aef10."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _init(c):
    self_ = _rnd(c, 0x100)
    return [self_]


S(0x5b02f0, 'initSlots (GUESS)', 'thiscall', None, ret='eax', gen=_init,
  note='batch338; no stack words; exe 0x5af2a0 (five calls) and 0x5aef10 (tail) run as original code')
