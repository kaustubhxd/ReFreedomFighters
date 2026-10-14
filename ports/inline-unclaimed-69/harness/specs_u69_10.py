"""specs_u69_10.py - area 69, group 10 (unclaimed-69 thread): SerialInfo_t::loadbool."""
from pilot import S
from ckit import rnd


def _lb(c):
    r = c.rng
    e = c.emu
    buf = rnd(c, 0x40)
    words = r.randint(1, 6)
    for i in range(words):
        e.w32(buf + 4 * i, r.choice([0, 1, 0x80000000, r.getrandbits(32)]))
    o = rnd(c, 0x20)
    e.w32(o + 8, buf + 4 * r.randrange(0, words))   # cursor, somewhere in the buffer
    e.w32(o + 0xc, buf + 4 * words)
    cur = e.r32(o + 8)
    if cur + 4 > buf + 4 * words:
        e.w32(o + 8, buf)
    out = rnd(c, 4)
    return [o, out]


S(0x5f2e10, 'SerialInfo_t::loadbool', 'thiscall', None, ret=None, gen=_lb, note='u69; assert hook not used (cursor kept in range)')
