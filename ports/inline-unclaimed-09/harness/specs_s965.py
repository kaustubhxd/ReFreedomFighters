"""specs_s965.py - area 56 band, claim A29 (0x526ef0): constructor, no calls.

this is a 0x40-byte object of random bytes. ret='eax' (returns this)."""
from pilot import S


def _gen(c):
    a = c.emu.alloc(0x40, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [a]


S(0x526ef0, 'unnamed 0x526ef0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A29; constructor, no calls')
