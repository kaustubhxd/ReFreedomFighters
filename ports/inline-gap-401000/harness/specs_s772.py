"""specs_s772.py - gap band batch 772 (docs/20-gap-band-401000.md): 0x410ec0, cdecl (p). A bit reader: p[0] count, p[1] bit index, p[3] byte
pointer, p[4] limit. The bytes behind p[3] are random. Both branches (bit and -1) run."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S


def _gen(c):
    p = c.emu.alloc(0x20, 4)
    buf = c.emu.alloc(0x10, 4)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0x10)))
    c.emu.w32(p, c.rng.randint(0, 5))
    c.emu.w32(p + 4, c.rng.randint(0, 8))
    c.emu.w32(p + 0xc, buf)
    c.emu.w32(p + 0x10, c.rng.randint(0, 6))
    return [p]


S(0x410ec0, 'CRT helper 0x410ec0 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 772: bit read and bit-index rollover')
