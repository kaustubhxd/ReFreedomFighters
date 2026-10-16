from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    target = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, pop=4, ret=r.choice([0, 1]))})
    iface = obj(c, 0x400, {0x2e8: pystub(c, 0, this=True, ret=target)})
    first = obj(c, 0x20, {0x10: pystub(c, 0, this=True, ret=iface)})
    child = obj(c, 0x240, {0x230: pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32))})
    self = rnd(c, 0x30)
    e.w32(self + 0xc, first)
    e.w32(self + 8, child)
    e.w32(self + 0x10, rnd(c, 0x20))
    e.w32(self + 0x14, rnd(c, 0x20))
    hook_rec(c, 0x461570, 3, this=True, pop=12)
    return [self]

S(0x486890, 'GUESS query_route_then_submit', 'thiscall', None, ret='al', gen=gen, note='batch62129')
