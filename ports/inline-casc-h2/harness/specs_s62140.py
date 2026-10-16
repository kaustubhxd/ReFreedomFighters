from pilot import S
from recruits_util import clear_hooks, obj, pystub, rnd

def gen(c):
    clear_hooks(c)
    e, r = c.emu, c.rng
    resource = rnd(c, 0x60)
    shift_obj = rnd(c, 0x20)
    e.w32(shift_obj + 4, r.randrange(32))
    e.w32(resource + 0x54, shift_obj)
    passed = r.randrange(2)
    resource_vt_obj = obj(c, 0x200, {0x1e0: pystub(c, 1, this=True, pop=4, ret=passed)})
    e.w32(resource, e.r32(resource_vt_obj))
    resource = resource if r.randrange(2) else 0
    table = obj(c, 0x100, {0x58: pystub(c, 1, this=True, pop=4, ret=resource)})
    sys = e.alloc(0x200, 4)
    e.w32(sys + 0x9b, table)
    e.w32(0x70039c, sys)
    mask_obj = rnd(c, 0x20)
    e.w32(mask_obj + 0xc, r.getrandbits(32))
    state = rnd(c, 0x80)
    e.w32(state + 0x54, mask_obj)
    self = rnd(c, 0x80)
    e.w32(self + 0x44, state)
    return [self, r.getrandbits(32)]

S(0x5d2860, 'GUESS test_resource_bitmask', 'thiscall', None, ret='eax', gen=gen, note='batch62140')
