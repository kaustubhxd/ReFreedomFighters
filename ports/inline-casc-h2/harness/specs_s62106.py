from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    count = r.choice([0, 1, 4, 0x123])
    buffer = rnd(c, 0x40)
    object = obj(c, 0x80, {
        0x30: pystub(c, 2, this=True, pop=8, ret=count),
        0x60: pystub(c, 5, this=True, pop=20),
    }, nslots=0x60 // 4 + 1)
    e.w32(0x700394, object)
    self = rnd(c, 0x20)
    old = rnd(c, 0x20) if r.random() < 0.7 else 0
    e.w32(self + 4, old)
    hook_rec(c, 0x41e290, 1, ret=buffer, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)
    return [self, r.getrandbits(32)]


S(0x49e0e0, 'GUESS allocate counted resource and submit buffer', 'thiscall', None,
  ret=None, gen=gen, note='batch62106')
