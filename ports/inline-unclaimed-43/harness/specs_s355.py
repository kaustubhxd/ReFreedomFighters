"""specs_s355.py - gap band batch 355: 0x408f90, cdecl with one argument; returns the number of set bits (popcount). The argument
is drawn from zero, all ones, single bits and random dwords."""
from pilot import S


def _gen(c):
    r = c.rng
    v = r.choice([0, 1, 0x80000000, 0xffffffff, 0x55555555, r.getrandbits(32), r.getrandbits(7)])
    c.emu.mu.ctl_flush_tb()
    return [v]


S(0x408f90, 'popcount (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 355')
