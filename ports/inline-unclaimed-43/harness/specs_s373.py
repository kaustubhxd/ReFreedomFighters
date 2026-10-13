"""specs_s373.py - gap band batch 373: 0x403e50, cdecl(dst, src): 56 floats; dst[i] takes src[i] when src[i] > dst[i] (ordered).
The arrays are random floats; some entries are equal, and some are NaN (written as bits in the array) so the unordered case runs."""
import struct
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    dst = c.fbuf(56)
    src = c.fbuf(56)
    for k in range(0, 56, 7):
        c.emu.wbytes(src + 4 * k, struct.pack('<f', c.emu.rf32(dst + 4 * k)))
    if r.random() < 0.5:
        c.emu.wbytes(src + 4 * r.randrange(56), struct.pack('<I', 0x7fc00000))
    c.emu.mu.ctl_flush_tb()
    return [dst, src]


S(0x403e50, 'copy where src greater (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, note='gap band batch 373')
