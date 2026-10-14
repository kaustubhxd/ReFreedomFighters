"""specs_s35188.py - 0x636690 (thiscall(float t) ret 4, ret=None). this: [+0x10] = level count (0..3, negative in 1/10), [+0x14] -> array of 0x14-byte records ([+4] width -1..4, [+8] rows -1..3, [+0x10] pixel block of random dwords, sized for the largest). t: F(value) from a list with 0, 1, 0.5, 2, -1 and random values."""
from pilot import S, F
from recruits_util import rnd, clear_hooks


def _g636690(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x30)
    n = r.choice([0, 1, 2, 3, 3]) if r.random() > 0.1 else -1
    e.w32(me + 0x10, n & 0xffffffff)
    recs = rnd(c, 0x14 * 4)
    for k in range(4):
        w = r.choice([1, 2, 3, 4, 4, 0, -1])
        rows = r.choice([1, 2, 3, 3, 0, -1])
        px = rnd(c, 4 * 4 * 3 + 16)
        e.w32(recs + 0x14 * k + 4, w & 0xffffffff)
        e.w32(recs + 0x14 * k + 8, rows & 0xffffffff)
        e.w32(recs + 0x14 * k + 0x10, px)
    e.w32(me + 0x14, recs)
    t = r.choice([0.0, 1.0, 0.5, 2.0, -1.0, 1.5, c.fv(-3, 3), c.fv(-3, 3), c.fv(0, 1)])
    if not (-1e6 < t < 1e6):   # NaN / infinity would reach the CRT float-to-int error path (_except1, no stub)
        t = 0.5
    return [me, F(t)]


S(0x636690, 'GUESS saturation blend of all image levels towards luma', 'thiscall', None, ret=None, gen=_g636690, note='batch35188')
