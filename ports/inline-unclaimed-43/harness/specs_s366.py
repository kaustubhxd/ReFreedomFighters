"""specs_s366.py - gap band batch 366: 0x40bef0, cdecl(a, b, i). a and b are arrays of signed dwords (random, with negative and
positive values in good proportion); i is an index in range."""
from pilot import S
import engine_stubs as E


def _arr(c, n):
    a = E.zero_obj(c, 4 * n + 16)
    for k in range(n):
        v = c.rng.choice([c.rng.randrange(-5, 6), c.rng.getrandbits(31) & 0x3fffffff, -(c.rng.getrandbits(20) + 1)])
        c.emu.w32(a + 4 * k, v & 0xffffffff)
    return a


def _gen(c):
    n = 8
    a = _arr(c, n)
    b = _arr(c, n)
    i = c.rng.randrange(n)
    c.emu.mu.ctl_flush_tb()
    return [a, b, i]


S(0x40bef0, 'blend of two signed values (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 366')
