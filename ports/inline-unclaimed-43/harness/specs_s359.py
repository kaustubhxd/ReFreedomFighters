"""specs_s359.py - gap band batch 359: 0x40fe50, cdecl with two float pointers. The values cover a < b, a == b, a > b, and NaN
(a quiet NaN written as bits), so the unordered case is exercised."""
import struct
from pilot import S
import engine_stubs as E


def _fl(c, v):
    a = E.zero_obj(c, 0x10)
    c.emu.wbytes(a, struct.pack('<f', v) if not isinstance(v, int) else struct.pack('<I', v))
    return a


def _gen(c):
    r = c.rng
    x = r.uniform(-10.0, 10.0)
    k = r.random()
    if k < 0.2:
        y = x
    elif k < 0.3:
        return [_fl(c, 0x7fc00000), _fl(c, 1.0)]
    else:
        y = r.uniform(-10.0, 10.0)
    c.emu.mu.ctl_flush_tb()
    return [_fl(c, x), _fl(c, y)]


S(0x40fe50, 'float compare fcomp (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 359')
