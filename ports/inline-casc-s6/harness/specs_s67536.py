"""specs_s67536.py - cascade s6 batch 67536 (0x428010, thiscall(key, src, total, chunk) ret 0x10, no return value). The object's slots 0x14 / 0xc return handles (0 sometimes), 0x38 takes
3 args, 0x1c 1 arg (all recorders, call order logged); src is an arbitrary number (only added to); total includes negative values, chunk is non-negative (a negative chunk makes the original loop 2^32 times)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _g428010(c):
    clear_hooks(c)
    r = c.rng
    hs = [0x1000, 0x2000, 0x3000]
    t = obj(c, 0x40, {0x14: pystub(c, 1, this=True, ret=lambda em, k: r.choice(hs + [0, hs[0]])),
                      0xc: pystub(c, 1, this=True, ret=lambda em, k: r.choice(hs)),
                      0x38: pystub(c, 3, this=True), 0x1c: pystub(c, 1, this=True)})
    chunk = r.choice([0, 1, 2, 3, 4, 5, 8, 16])
    total = r.choice([-3, 0, 1, 2, 3, 4, 7, 8, 9, 12, 15, 16, 17, 20, 33, 64])
    return [t, r.getrandbits(32), r.getrandbits(32), total & 0xffffffff, chunk]


S(0x428010, 'GUESS write_chunked', 'thiscall', None, ret=None, gen=_g428010, note='batch67536')
