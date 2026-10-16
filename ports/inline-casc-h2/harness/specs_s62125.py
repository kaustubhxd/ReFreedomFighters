from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    log = obj(c, 0x30, {0x2c: pystub(c, 4, this=True, pop=0)})
    engine = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=log)})
    e.w32(0x700390, engine)
    self = rnd(c, 0x40)
    e.w8(self + 8, r.randrange(2))
    e.w32(self + 0x15, obj(c, 0x30, {0x0c: pystub(c, 2, this=True, pop=4, ret=r.getrandbits(32))}))
    e.w32(self + 4, r.getrandbits(32))
    e.w32(self + 0x11, r.getrandbits(32))
    e.w32(self + 0x0d, r.getrandbits(32))
    return [self]

S(0x4d5fa0, 'GUESS two_branch_resource_logger_dispatch', 'thiscall', None, ret=None, gen=gen, note='batch62125')
