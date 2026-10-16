from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    resource = obj(c, 0x30, {0x80: pystub(c, 2, this=True, pop=8)})
    table = obj(c, 0x30, {0x58: pystub(c, 1, this=True, pop=4, ret=resource)})
    service = obj(c, 0x30, {0xb4: pystub(c, 1, this=True, pop=4, ret=r.getrandbits(32))})
    sys = rnd(c, 0x2000)
    e.w32(sys + 0x9b, table)
    e.w32(sys + 0x190f, service)
    e.w32(0x70039c, sys)
    self = obj(c, 0x700, {0x94: pystub(c, 2, this=True, pop=8)})
    enabled = r.random() < 0.5
    e.w8(self + 0x67f, int(enabled))
    fallback = obj(c, 0x30, {0x14: pystub(c, 4, this=True, pop=16, ret=r.getrandbits(32))})
    e.w32(self + 0x6c, fallback)
    hook_rec(c, 0x462d10, 3, this=True, pop=12, ret=r.getrandbits(32))
    return [self, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]

S(0x591980, 'GUESS dispatch_resource_action_by_enabled_state', 'thiscall', None, ret='al', gen=gen, note='batch62118')
