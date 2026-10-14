"""specs_s976.py - area 56 band, claim A42 (0x534010).

this is a 0x40-byte object whose +8 dword points to an array of 0x40000 random bytes (the loop touches up to 0x3f47c bytes). About
one slot in four has a non-zero guard dword at c-0x68 (c = array + 0x78 + i*0xfd); the random floats are zero in about one case in
five. f is a random float in [-5, 5]. ret=None (void)."""
import struct
from pilot import S
from pe_emu import F


def _rnd_bytes(c, n):
    return c.rng.getrandbits(8 * n).to_bytes(n, 'little')


def _gen(c):
    e = c.emu
    rng = c.rng
    arr = e.alloc(0x40000, 4)
    e.wbytes(arr, _rnd_bytes(c, 0x40000))
    # Make the float slots zero about one in five, so the exact-zero branch runs.
    for i in range(0x400):
        slot = arr + 0x78 + i * 0xfd
        if rng.random() < 0.2:
            e.w32(slot, 0)
        if rng.random() < 0.25:
            e.w32(slot - 0x68, 0)
    this = e.alloc(0x40, 4)
    e.wbytes(this, _rnd_bytes(c, 0x40))
    e.w32(this + 8, arr)
    x = rng.uniform(-5.0, 5.0)
    return [this, F(x)]


S(0x534010, 'unnamed 0x534010 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A42; float loop over a 0x40000-byte array, no calls')
