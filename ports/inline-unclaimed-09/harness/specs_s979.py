"""specs_s979.py - area 56 band, claim A45 (0x53b6d0): constant stores only.

this is a 0x100-byte object of random bytes (the stores reach offset 0xc9). ret=None (void)."""
from pilot import S


def _gen(c):
    a = c.emu.alloc(0x100, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [a]


S(0x53b6d0, 'unnamed 0x53b6d0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A45; constant stores only')
