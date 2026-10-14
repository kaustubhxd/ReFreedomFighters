"""specs_u69_53.py - area 69, group 53 (slice 8): 0x4d4480, a ring index modulo 1000 and a table read (no callees).
The counter and the x argument are biased toward the boundaries (x == 0, c == 1000, c == -1000, x + base negative, index 999 and 0)."""
from pilot import S
from ckit import rnd


def _gen(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x2000)
    counter = r.randrange(-1000, 1001)
    if r.random() < 0.15:
        counter = r.choice([1000, -1000, 999, -999, 0])
    e.w32(o + 0xfb3, counter & 0xffffffff)
    k = r.random()
    if k < 0.12:
        x = (r.choice([1000, -1000]) - counter) & 0xffffffff   # counter + x exactly at the +1000 or -1000 limit
        if x == 0:
            x = 1
    elif k < 0.22:
        x = 0
    elif k < 0.3:
        x = r.randrange(1001, 3000)              # c > 1000: error path
    elif k < 0.34:
        x = (-r.randrange(1001, 3000)) & 0xffffffff   # c < -1000: error path
    else:
        x = r.randrange(-1000, 1001) & 0xffffffff
    if r.random() < 0.25:
        base = 999 - counter - (x - (1 << 32) if x >= (1 << 31) else x)   # index sum exactly 999 (the boundary)
    else:
        base = r.randrange(-5000, 5000)
    e.w32(o + 0xfaf, base & 0xffffffff)
    return [o, x]


S(0x4d4480, 'ringIndex4d4480 (thiscall, one arg, ret 4)', 'thiscall', None, ret='eax', gen=_gen, note='u69 group 53; no callees')
