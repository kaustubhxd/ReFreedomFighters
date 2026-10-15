from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x564b10, 0, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('prepare', emu.reg('ecx'))))
    hook_rec(c, 0x563610, 1, this=True, pop=4,
             side=lambda emu, k: emu.calllog.append(('store-label', emu.reg('ecx'), emu.arg32(0))))
    item = r.getrandbits(32)
    resource = obj(c, 0x20, {0x60: pystub(c, 2, this=True, pop=8, ret=r.getrandbits(32),
                    side=lambda emu, k: emu.calllog.append(('resource', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    sysobj(c, table_slots={
        0x138: pystub(c, 0, this=True, ret=resource),
        0x4c: pystub(c, 2, this=True, pop=8, ret=item,
                    side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))),
    }, table_size=0x13c // 4)
    self = rnd(c, 0x90)
    e.w32(self + 0x44, r.getrandbits(32))
    return [self]


S(0x565ab0, 'GUESS resolve resource item and set initialized flag', 'thiscall', None,
  ret=None, gen=gen, note='batch62054')
