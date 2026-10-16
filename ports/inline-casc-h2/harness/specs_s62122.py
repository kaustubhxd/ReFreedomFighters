from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    output = rnd(c, 0x20)
    map_table = rnd(c, 0x4000)
    id_value = r.randrange(1, 16)
    e.w32(map_table + id_value * 4, output)
    hook_rec(c, 0x63eab0, 1, this=True, pop=4, ret=output)
    handle = rnd(c, 0x100)
    e.w32(handle + 0x68, map_table)
    service = obj(c, 0x30, {0x20: pystub(c, 1, this=True, pop=0, ret=handle)})
    manager = obj(c, 0x30, {0x80: pystub(c, 1, this=True, pop=4, ret=0)})
    sys = rnd(c, 0x2000)
    e.w32(sys + 0x190f, service)
    e.w32(sys + 0x1aa3, manager)
    e.w32(0x70039c, sys)
    self = rnd(c, 0x40)
    outer = rnd(c, 0x30)
    e.w32(self + 0x10, outer)
    mode = r.randrange(3)
    if mode == 0:
        e.w16(self + 0xa, 0)
        direct = rnd(c, 0x20)
        e.w32(outer + 0x10, direct)
        e.w32(direct + 0x10, output)
    elif mode == 1:
        e.w16(self + 0xa, 1)
        e.w32(outer + 0x10, 0)
    else:
        index = r.randrange(0, 8)
        e.w16(self + 0xa, index)
        inner = rnd(c, 0x80)
        e.w32(outer + 0x10, inner)
        data = inner + 0xc
        e.w16(data + 0x40, id_value)
        if index:
            array = rnd(c, 0x40)
            e.w32(data + 0x3c, array)
            e.w32(array + index * 4 + 4, rnd(c, 0x20))
            resolved = rnd(c, 0x80)
            e.w16(resolved + 0x40, id_value)
            manager_code = pystub(c, 1, this=True, pop=4, ret=resolved)
            vt = e.r32(manager)
            e.w32(vt + 0x80, manager_code)
    return [self]

S(0x659000, 'GUESS resolve_nested_resource_and_handle_map', 'thiscall', None, ret='eax', gen=gen, note='batch62122')
