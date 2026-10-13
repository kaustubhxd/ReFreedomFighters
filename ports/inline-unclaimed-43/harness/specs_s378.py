"""specs_s378.py - gap band batch 378: 0x40b6a0, cdecl(a0, a1, a2, a3, a4): 32-bit integers. The divisor a1 - a0 is nonzero and not
-1 (a zero divisor or INT_MIN / -1 faults in the original, so those inputs are excluded). Both signs of the difference occur."""
from pilot import S


def _gen(c):
    r = c.rng
    a0 = r.getrandbits(32)
    k = r.choice([x for x in range(-300, 301) if x not in (0, -1)])
    a1 = (a0 + k) & 0xffffffff
    a2 = r.getrandbits(32)
    a3 = r.getrandbits(32)
    if r.random() < 0.3:
        a3 = (a2 & 0x7fff) | (r.getrandbits(1) << 15)   # equal masked values: diff == 0 (the >= boundary)
    a4 = r.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [a0, a1, a2, a3, a4]


S(0x40b6a0, 'masked blend (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen, note='gap band batch 378')
