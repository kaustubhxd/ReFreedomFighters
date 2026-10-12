"""specs_s315.py - gap band, batch 315: 0x61f2c0, parser-state initializer (cdecl, plain ret). Args: this (0x100 random bytes), base (any value)."""
from pilot import S


def _gen(c):
    obj = c.emu.alloc(0x100, 4)
    c.emu.wbytes(obj, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [obj, c.rng.getrandbits(32)]


S(0x61f2c0, 'parser init (GUESS)', 'cdecl', None, ret='eax', gen=_gen, note='batch315; plain ret; returns 1')
