"""specs_s353.py - gap band batch 353: 0x407ed0, cdecl with one argument; returns the number of halvings until the value is 1 or
less (0 for 0 and 1). Values are drawn from zero, one, powers of two, and random dwords."""
from pilot import S


def _gen(c):
    r = c.rng
    v = r.choice([0, 1, 2, 3, 1 << 31, 0xffffffff, 1 << r.randrange(32), r.getrandbits(32)])
    c.emu.mu.ctl_flush_tb()
    return [v]


S(0x407ed0, 'halvings to one (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 353')
