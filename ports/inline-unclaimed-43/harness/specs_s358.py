"""specs_s358.py - gap band batch 358: 0x410540, cdecl with (block, n). The block has a limit at +4 and a used count at +8 (signed).
n is drawn so that used + n equals the limit in a share of the cases (the boundary) and is random otherwise."""
import struct
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    s = E.zero_obj(c, 0x20)
    lim = r.randrange(-50, 200)
    used = r.randrange(-50, 200)
    c.emu.w32(s + 4, lim & 0xffffffff)
    c.emu.w32(s + 8, used & 0xffffffff)
    if r.random() < 0.3:
        n = lim - used
    else:
        n = r.randrange(-100, 100)
    c.emu.mu.ctl_flush_tb()
    return [s, n & 0xffffffff]


S(0x410540, 'advance used if room (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 358')
