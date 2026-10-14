"""specs_s38035.py - cascade s8 batch 38035. Two int[3] points drawn from small values, negative values, and the int extremes (so the 3a+1 / 2a+1+b wrap-around and the sign handling of the
magic-number division and of the halving run), an output block of 0x40 random bytes with slack, flag 0 / 1 / random non-zero."""
import struct
from pilot import S
from recruits_util import clear_hooks


def _g6383a0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def v():
        return r.choice([0, 1, -1, 2, -2, 5, -7, 100, -100, r.randrange(-1000, 1000), 0x7fffffff, -0x80000000, 0x55555555, -0x55555556, r.getrandbits(32) - 0x80000000])
    a = e.alloc(16, 4)
    b = e.alloc(16, 4)
    e.wbytes(a, struct.pack('<4i', v(), v(), v(), 7))
    e.wbytes(b, struct.pack('<4i', v(), v(), v(), 7))
    out = e.alloc(0x50, 4)
    e.wbytes(out, r.randbytes(0x50))
    flag = r.choice([0, 0, 1, 1, 2, r.getrandbits(32)])
    return [flag, out, a, b]


S(0x6383a0, 'GUESS segment sample points', 'fastcall', None, ret=None, gen=_g6383a0, note='batch38035')
