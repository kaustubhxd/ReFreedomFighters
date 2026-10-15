from pilot import S
from recruits_util import rnd, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    table = sysobj(c, table_size=0xbd0,
        table_slots={0x114: pystub(c, 4, this=True, pop=16, ret=r.getrandbits(32))})
    tab = e.r32(table + 0x9b)
    e.w8(tab + 0xbc4, 1)
    state = rnd(c, 0xb0)
    e.w32(state + 0x9c, 2)
    e.w32(state + 0xa0, 0)
    e.w32(state + 0xa4, 0)
    self = rnd(c, 0x20)
    e.w32(self + 0xc, state)
    return [self]


S(0x5f2720, 'GUESS decrement state and notify resource table', 'thiscall', None,
  ret=None, gen=gen, note='batch62103')
