"""specs_s970.py - area 56 band, claims A35-A36 (0x534150, 0x533ce0): the 0x7ff-entry table loop.

this is a 0x4100-byte object of random bytes (the table is 0x4008 bytes). A35 returns eax = 0x7ff; A36 returns this.
ret='eax' for both."""
from pilot import S


def _gen(c):
    a = c.emu.alloc(0x4100, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(0x4100)))
    return [a]


S(0x534150, 'unnamed 0x534150 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A35; table loop, returns 0x7ff')
S(0x533ce0, 'unnamed 0x533ce0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A36; table loop, returns this')
