"""specs_s213094.py - batch 213094: FFT twiddle and bit-reversal tables with x87 trig, Sonnet-w3b."""
import math
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec


def g406590(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    st = {'z': 0.0}

    def malloc_ret(emu, k):
        n = emu.arg32(0)
        return rnd(c, 16 + (n if n < 0x4000 else 0x4000))
    hook_rec(c, 0x634d58, 1, pop=0, ret=malloc_ret)

    def floor_side(emu, k):
        sp = emu.reg('esp')
        x = struct.unpack('<d', bytes(emu.rbytes(sp + 4, 8)))[0]
        emu.calllog.append(('floor', struct.pack('<d', x)))
        try:
            st['z'] = math.floor(x)
        except (OverflowError, ValueError):
            st['z'] = 0
    hook_rec(c, 0x634dca, 0, pop=0, side=floor_side)

    def ftol_ret(emu, k):
        z = st['z']
        try:
            return int(z) & 0xffffffff
        except (OverflowError, ValueError):
            return 0x80000000
    hook_rec(c, 0x634dfa, 0, pop=0, ret=ftol_ret)
    out = rnd(c, 0x14)
    x = r.random()
    if x < 0.6:
        n = 1 << r.randint(1, 7)
    elif x < 0.8:
        n = r.randint(8, 140)
    elif x < 0.9:
        n = r.randint(1, 9)
    else:
        n = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 31, 32, 33, 255, 256, -1, -2, -3, -5, -7, -9, -15, -100])
    return [out, n]


S(0x406590, 'fft_tables', 'cdecl', None, ret=None, gen=g406590)
