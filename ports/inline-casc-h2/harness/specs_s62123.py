from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    result_obj = obj(c, 0x30, {0x228: pystub(c, 1, this=True, pop=4)})
    manager = obj(c, 0x30, {0x25c: pystub(c, 2, this=True, pop=8, ret=result_obj)})
    table = obj(c, 0x1000, {0x4c: pystub(c, 3, this=True, pop=12, ret=r.getrandbits(32))})
    e.w32(table + 0xadc, manager)
    sys = rnd(c, 0x2000)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32) | 1))
    self = rnd(c, 0x180)
    e.w16(self + 0x161, r.getrandbits(16))
    e.w16(self + 0x163, r.getrandbits(16))
    hook_rec(c, 0x45d3a0, 0, this=True, pop=0)
    return [self]

S(0x465fd0, 'GUESS initialize_and_dispatch_engine_resource', 'thiscall', None, ret=None, gen=gen, note='batch62123')
