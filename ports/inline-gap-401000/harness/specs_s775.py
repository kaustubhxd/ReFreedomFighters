"""specs_s775.py - gap band batch 775 (docs/20-gap-band-401000.md): 0x403f90, cdecl (pn, x, b, out). n is 0 to 6. The constant at 0x6bdfd4
is read from the image and placed in about a third of the x entries, so the equal branch runs. b entries are nonzero."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
import struct


def _gen(c):
    konst = c.emu.rbytes(0x6bdfd4, 4)
    kbits = struct.unpack('<I', bytes(konst))[0]
    n = c.rng.randint(0, 6)
    pn = c.emu.alloc(4, 4)
    c.emu.w32(pn, n)
    x = c.emu.alloc(0x40, 4)
    b = c.emu.alloc(0x40, 4)
    out = c.emu.alloc(0x40, 4)
    for k in range(0x10):
        xv = kbits if c.rng.random() < 1 / 3 else struct.unpack('<I', struct.pack('<f', c.rng.uniform(-50, 50)))[0]
        c.emu.w32(x + 4 * k, xv)
        c.emu.w32(b + 4 * k, struct.unpack('<I', struct.pack('<f', c.rng.choice([c.rng.uniform(0.5, 9.0), -c.rng.uniform(0.5, 9.0)])))[0])
        c.emu.w32(out + 4 * k, 0x7f7f7f7f)
    return [pn, x, b, out]


S(0x403f90, 'CRT helper 0x403f90 (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 775: x87 divide loop with the equal test')
