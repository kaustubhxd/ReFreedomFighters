from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    global_key = r.randrange(1, 32)
    e.w16(0x7143b0, global_key)
    id_result = r.randrange(0, 32)
    table = obj(c, 0x20, {0x114: pystub(c, 4, this=True, pop=16, ret=id_result)})
    sys = rnd(c, 0x120)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    self = rnd(c, 0x100)
    index = r.randrange(0, 32)
    selected = r.choice([0, 0, 1, 4, 0x1234])
    e.w16(self + 0x10 + index * 2, selected)
    e.w16(self + 0x10 + id_result * 2, selected)
    outer = rnd(c, 0x20)
    iface = rnd(c, 4)
    e.w32(iface, pystub(c, 3, this=True, pop=12, ret=r.getrandbits(32)))
    e.w32(outer + 8, iface)
    e.w32(self + 0xc, outer)
    input = rnd(c, 8)
    e.w32(input, r.getrandbits(32))
    gate = r.choice([0, 1, 0x100]) if r.random() < 0.15 else r.getrandbits(32) | 1
    key = global_key if r.random() < 0.4 else index
    return [self, gate, key, input]

S(0x5f2a80, 'GUESS resolve_index_and_dispatch_selected_record', 'thiscall', None, ret='eax', gen=gen, note='batch62120')
