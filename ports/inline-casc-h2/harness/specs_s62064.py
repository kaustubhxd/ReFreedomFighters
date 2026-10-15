from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    helper_ret = r.getrandbits(32)
    hook_rec(c, 0x5625c0, 1, this=True, pop=4, ret=helper_ret,
             side=lambda emu, k: emu.calllog.append(('helper', emu.reg('ecx'), emu.arg32(0))))
    state = r.choice([7, 0, 6, 8])
    active = r.choice([0, 1])
    callback_value = r.getrandbits(32)
    component = rnd(c, 0x120)
    embedded_vt = e.alloc(0x18, 4)
    e.w32(embedded_vt + 0x14, pystub(c, 0, this=True, ret=active))
    e.w32(component + 0xcb, embedded_vt)
    resource = obj(c, 0x90, {0x88: pystub(c, 2, this=True, pop=8,
                     side=lambda emu, k: (emu.calllog.append(('resource', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))), emu.w32(emu.arg32(1), callback_value)))}, nslots=0x89 // 4)
    engine = sysobj(c, table_slots={0x138: pystub(c, 0, this=True, ret=resource)}, table_size=0x13c // 4)
    self = obj(c, 0x1d0, {0x84: pystub(c, 0, this=True, ret=component)}, nslots=0x85 // 4)
    e.w32(self + 0x1c5, state)
    return [self, r.getrandbits(32)]


S(0x56a090, 'GUESS conditionally resolve and forward an engine value', 'thiscall', None,
  ret='eax', gen=gen, note='batch62064')
