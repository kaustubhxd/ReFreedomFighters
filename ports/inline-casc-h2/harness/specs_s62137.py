from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    first = rnd(c, 0x20)
    e.w32(first, r.getrandbits(32))
    second = rnd(c, 0x20)
    key = e.r32(first)
    nested = rnd(c, 0x80)
    e.w32(nested + 0x3c, r.getrandbits(32))
    resource = rnd(c, 0x20)
    e.w32(resource + 8, nested)
    manager_ret = resource if r.randrange(2) else 0
    table = obj(c, 0x100, {0x58: pystub(c, 1, this=True, pop=4, ret=manager_ret)})
    sys = rnd(c, 0x200)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    message = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0)})
    engine = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=message)})
    e.w32(0x700390, engine)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=lambda emu, k: first if k == 0 else second)
    hook_rec(c, 0x5002f0, 1, this=True, pop=4)
    self = rnd(c, 0x20)
    e.w32(self + 4, rnd(c, 0x20))
    e.w32(self + 8, rnd(c, 0x20))
    return [self]

S(0x50e8a0, 'GUESS resource_flags_then_forward', 'stdcall', None, ret=None, gen=gen, note='batch62137')
