"""specs_s801.py - gap band batch 801 (docs/20-gap-band-401000.md): 0x420450, thiscall. The float at +0x2c, the count at +0x40 and the float at +0xa03
are random over a range that makes the comparison go both ways; the flag bytes at +0xa0b and +0xf0b are random. The constants 0x678620 and 0x6785e4
are read from the image; the result is compared bit for bit."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct


def _gen(c):
    this = c.emu.alloc(0x1000, 4)
    c.emu.wbytes(this, bytes(c.rng.getrandbits(8) for _ in range(0x1000)))
    c.emu.wbytes(this + 0x2c, struct.pack('<f', c.rng.uniform(-40, 40)))
    c.emu.w32(this + 0x40, c.rng.randint(-20, 60) & 0xffffffff)
    c.emu.wbytes(this + 0xa03, struct.pack('<f', c.rng.uniform(-40, 40)))
    return [this]


S(0x420450, 'ZFF class float update 0x420450 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  setup=lambda c: (c.emu.mu.ctl_remove_cache(0x20000000, 0x21000000), c.emu.mu.ctl_remove_cache(c.emu.base, c.emu.base + c.emu.size)),
  note='gap band batch 801: two single-precision scalings and two flag-bit clearing loops')
