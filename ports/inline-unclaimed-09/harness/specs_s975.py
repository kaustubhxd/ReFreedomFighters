"""specs_s975.py - area 56 band, claim A41 (0x5244f0).

this is a 0x40-byte object of random bytes. The float argument is the image constant at 0x67cd44 (about one case in five), the
constant at 0x6785d0 (one in five), or a random float in [-50, 50] otherwise; the constants are read from the loaded image.
ret=None (void)."""
import struct
from pilot import S
from pe_emu import F


def _gen(c):
    e = c.emu
    rng = c.rng
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(rng.getrandbits(8) for _ in range(0x40)))
    r = rng.random()
    if r < 0.2:
        word = e.r32(0x67cd44)
    elif r < 0.4:
        word = e.r32(0x6785d0)
    else:
        word = struct.unpack('<I', struct.pack('<f', rng.uniform(-50.0, 50.0)))[0]
    x = struct.unpack('<f', struct.pack('<I', word))[0]
    return [this, F(x)]


S(0x5244f0, 'unnamed 0x5244f0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-56 A41; float argument, no calls')
