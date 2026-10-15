from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    event1, event2, thread = r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)
    e.w32(0x676148, pystub(c, 4, pop=16, ret=lambda emu, k: event1 if k == 0 else event2))
    e.w32(0x67614c, pystub(c, 6, pop=24, ret=thread, stackmark=(5,)))
    e.w32(0x676150, pystub(c, 2, pop=8, ret=r.getrandbits(32)))
    self = rnd(c, 0x320)
    count = r.choice([0, 1, 3])
    e.w32(self + 0x1c5, count)
    hook_rec(c, 0x54e3f0, 0, this=True, pop=0)
    return [self]


S(0x54e770, 'GUESS create events and worker then initialize items', 'thiscall', None,
  ret=None, gen=gen, note='batch62110')
