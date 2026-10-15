from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    selector = r.choice([0, 1, 0x100, 0x200, 0x300, 0x10000, 0xffffffff])
    desc = rnd(c, 0x20)
    e.w32(desc + 4, selector)
    e.w32(desc + 8, r.getrandbits(32))
    e.w32(desc + 0xc, r.choice([0, 0, 1, 2, 0xffffffff]))
    ret_100 = r.getrandbits(32)
    ret_200 = r.getrandbits(32)
    self = obj(c, 0x20, {
        0x2d8: pystub(c, 2, this=True, pop=8, ret=ret_100),
        0x2dc: pystub(c, 2, this=True, pop=8, ret=ret_200),
    }, nslots=0x2dc // 4 + 1)
    return [self, desc]


S(0x4f4020, 'GUESS dispatch descriptor by selector', 'thiscall', None,
  ret='eax', gen=gen, note='batch62100')
