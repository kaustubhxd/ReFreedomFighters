from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    token = r.getrandbits(32)
    manager = obj(c, 0x20, {
        0x3a8: pystub(c, 1, this=True, pop=4, ret=token),
        0x398: pystub(c, 1, this=True, pop=4),
    }, nslots=0x3a8 // 4 + 1) if r.random() < 0.7 else 0
    owner = obj(c, 0x20, {0x84: pystub(c, 1, this=True, pop=4)}, nslots=0x84 // 4 + 1)
    self = rnd(c, 0x20)
    e.w32(self + 8, manager)
    e.w32(self + 4, owner)
    out = rnd(c, 0xc)
    return [self, out]


S(0x512db0, 'GUESS initialize output and notify owner', 'thiscall', None,
  ret=None, gen=gen, note='batch62109')
