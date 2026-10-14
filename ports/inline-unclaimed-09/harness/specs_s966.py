"""specs_s966.py - area 56 band, claim A30 (0x5273b0): constructor that calls 0x526ef0 (original exe code).

this is an 0x80-byte object of random bytes. ret='eax' (returns this)."""
from pilot import S


def _gen(c):
    a = c.emu.alloc(0x80, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    return [a]


S(0x5273b0, 'unnamed 0x5273b0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A30; constructor calling 0x526ef0 (A29)')
