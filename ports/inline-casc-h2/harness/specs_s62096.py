from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x100)
    allocator = rnd(c, 0x4000)
    e.w32(self + 0x60, allocator)
    e.w32(allocator + 0x3408, 0)
    e.w32(allocator, 0)
    e.w32(self + 8, r.getrandbits(32))
    e.w32(self + 0xc, r.getrandbits(32))
    request = r.randrange(0, 0x10000)
    nested = obj(c, 0x20, {0x2c: pystub(c, 2, this=True, pop=0,
        ret=r.getrandbits(32))})
    global_obj = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=nested)})
    e.w32(0x700390, global_obj)
    return [self, request]


S(0x63b7e0, 'GUESS allocate aligned block and report exhaustion', 'thiscall', None,
  ret='eax', gen=gen, note='batch62096')
