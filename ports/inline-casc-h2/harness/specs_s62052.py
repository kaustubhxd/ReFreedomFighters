from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    enabled = r.choice([0, 1])
    engine_id = r.getrandbits(16)
    lookup = pystub(c, 4, this=True, pop=16, ret=engine_id,
                    side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), *(emu.arg32(i) for i in range(4)))))
    sysobj(c, slots={0xe8: pystub(c, 1, this=True, pop=4, ret=enabled,
                                 side=lambda emu, k: emu.calllog.append(('gate', emu.reg('ecx'), emu.arg32(0))))},
           table_slots={0x114: lookup}, table_size=0x120)
    child = obj(c, 0x20, {0x128: pystub(c, 3, this=True, pop=12,
                    side=lambda emu, k: emu.calllog.append(('dispatch', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))}, nslots=0x129 // 4)
    self = rnd(c, 0x60)
    e.w32(self + 0x44, child)
    return [self]


S(0x4c3880, 'GUESS gate and dispatch engine table item', 'thiscall', None,
  ret=None, gen=gen, note='batch62052')
