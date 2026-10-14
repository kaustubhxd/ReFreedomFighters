"""specs_s969.py - area 56 band, claim A34 (0x524660): constructor, no calls.

this is a 0x40-byte object of random bytes. ret='eax' (returns this)."""
from pilot import S


def _gen(c):
    a = c.emu.alloc(0x40, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [a]


S(0x524660, 'unnamed 0x524660 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A34; constructor, no calls')
