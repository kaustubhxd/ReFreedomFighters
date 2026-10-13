"""specs_s346.py - gap band batch 346: 0x405090, cdecl with one argument; returns the bit length (0 for 0). The argument is drawn
from zero, single bits, all ones and random values."""
from pilot import S


def _gen(c):
    r = c.rng
    v = r.choice([0, 1, 0x80000000, 0xffffffff, 2, 3, r.getrandbits(32), r.getrandbits(8), r.getrandbits(20)])
    c.emu.mu.ctl_flush_tb()
    return [v]


S(0x405090, 'bit length (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 346')
