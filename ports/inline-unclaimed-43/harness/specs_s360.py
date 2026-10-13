"""specs_s360.py - gap band batch 360: 0x403e80, cdecl with (56 floats, f). The block is random floats (fv) and f is a float
(wrapped in F for the spec)."""
from pilot import S, F


def _gen(c):
    p = c.fbuf(56)
    f = F(c.fv(-5.0, 5.0))
    c.emu.mu.ctl_flush_tb()
    return [p, f]


S(0x403e80, 'add f to 56 floats (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen, note='gap band batch 360')
