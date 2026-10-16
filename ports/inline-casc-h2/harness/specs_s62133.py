from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    resource = obj(c, 0x30, {
        0xbc: pystub(c, 1, this=True, pop=4),
        0x250: pystub(c, 1, this=True, pop=4),
    })
    table = obj(c, 0x100, {0x58: pystub(c, 1, this=True, pop=4,
                                         ret=r.choice([0, resource, resource, resource]))})
    sys = rnd(c, 0x200)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    key = r.getrandbits(32)
    mode = r.randrange(2)
    selection = r.choice([0, r.getrandbits(32) | 1])
    return [key, mode, selection]

S(0x5d9f00, 'GUESS conditional_resource_action', 'stdcall', None, ret=None, gen=gen, note='batch62133')
