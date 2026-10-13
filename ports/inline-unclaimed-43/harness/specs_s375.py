"""specs_s375.py - gap band batch 375: 0x4071d0, cdecl(twiddle, base, count, stride). The base has 256 bytes of padding before it
(the loop's first body reads just below the base), the twiddle buffer is large; count is small and even or odd; stride 0..4."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    buf = c.fbuf(0x100, pad=0)
    base = buf + 0x100
    tw = c.fbuf(0x1000 // 4, pad=0)
    cnt = r.choice([2, 4, 6, 8, 10, 12, 16, 5, 7, 32, 33, 34])   # 32/33 reach the exact loop-exit boundary
    stride = r.randrange(0, 5)
    c.emu.mu.ctl_flush_tb()
    return [tw, base, cnt, stride]


S(0x4071d0, 'butterfly stage loop (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 375; translated from the disassembly')
