from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    resource = obj(c, 0x20, {})
    table = obj(c, 0x1000, {
        0x58: pystub(c, 1, this=True, pop=4, ret=r.choice([0, resource])),
        0x4c: pystub(c, 1, this=True, pop=4, ret=r.getrandbits(32)),
    })
    manager = obj(c, 0x30, {0x294: pystub(c, 4, this=True, pop=16, ret=resource)})
    e.w32(table + 0xadc, manager)
    e.w32(table + 0x14, r.getrandbits(32))
    sys = rnd(c, 0x200)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    hook_rec(c, 0x43ed60, 5, pop=20)
    return [r.getrandbits(32) for _ in range(5)]

S(0x43ea70, 'GUESS acquire_engine_resource_then_forward', 'stdcall', None, ret=None, gen=gen, note='batch62128')
