"""specs_s377.py - gap band batch 377: 0x403f90, cdecl(countp, a, b, d). n is 0..6 (n <= 0 returns at once). The array a holds
random floats with some zeros, -0.0 and NaN (written as bits) so the zero/unordered branch runs; b holds random floats (some zero,
so the x87 divide sees a zero divisor too); d is a separate buffer."""
import struct
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    cnt = E.zero_obj(c, 16)
    n = r.choice([0, -1, 1, 2, 3, 4, 6])
    c.emu.w32(cnt, n & 0xffffffff)
    a = c.fbuf(8, pad=0)
    b = c.fbuf(8, pad=0)
    d = c.fbuf(8, pad=0)
    for k in range(8):
        k2 = r.random()
        if k2 < 0.15:
            c.emu.wbytes(a + 4 * k, struct.pack('<f', 0.0))
        elif k2 < 0.2:
            c.emu.wbytes(a + 4 * k, struct.pack('<I', 0x7fc00000))
        elif k2 < 0.25:
            c.emu.wbytes(a + 4 * k, struct.pack('<f', -0.0))
        if r.random() < 0.1:
            c.emu.wbytes(b + 4 * k, struct.pack('<f', 0.0))
    c.emu.mu.ctl_flush_tb()
    return [cnt, a, b, d]


S(0x403f90, 'divide where nonzero (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, note='gap band batch 377')
