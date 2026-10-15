from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    resource = obj(c, 0x40, {0x130: pystub(c, 2, this=True, pop=8)}, nslots=0x130 // 4 + 1)
    resource_factory = obj(c, 0x20, {0x25c: pystub(c, 2, this=True, pop=8, ret=resource)}, nslots=0x25c // 4 + 1)
    table = obj(c, 0xb20, {0x114: pystub(c, 5, this=True, pop=20, ret=r.getrandbits(32))}, nslots=0x114 // 4 + 1)
    e.w32(table + 0xadc, resource_factory)
    so = sysobj(c)
    e.w32(so + 0x9b, table)
    cursor = rnd(c, 0x20)
    value = r.getrandbits(32)
    e.w32(cursor, value)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=cursor)
    param = rnd(c, 0x20)
    e.w32(param + 4, rnd(c, 0x20))
    return [param]


S(0x50bef0, 'GUESS obtain resource id and dispatch operation', 'stdcall', None,
  ret=None, gen=gen, note='batch62102')
