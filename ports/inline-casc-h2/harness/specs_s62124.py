from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x70)
    e.w8(self + 0x54, r.getrandbits(8))
    callback = obj(c, 0x20, {
        0x94: pystub(c, 2, ret=r.getrandbits(32), this=True, pop=8),
        0x90: pystub(c, 3, ret=r.getrandbits(32), this=True, pop=12),
    })
    e.w32(self, e.r32(callback))
    child = r.choice([0, 0, rnd(c, 0x30)])
    e.w32(self + 0x50, child)
    ready = r.getrandbits(32) | (r.randrange(2))
    item = r.getrandbits(32)
    hook_rec(c, 0x4cc5f0, 0, ret=ready, this=True, pop=0)
    hook_rec(c, 0x4cc1d0, 0, ret=item, this=True, pop=0)
    hook_rec(c, 0x4db860, 1, this=True, pop=4)
    return [self, r.getrandbits(32), r.getrandbits(32)]

S(0x4b12c0, 'GUESS conditional_child_dispatch_and_notify', 'thiscall', None, ret=None, gen=gen, note='batch62124')
