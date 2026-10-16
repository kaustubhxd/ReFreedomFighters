from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x562e90, 2, this=True, pop=8,
             ret=r.getrandbits(32),
             side=lambda emu, k: emu.calllog.append(('prepare', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    tail = obj(c, 0x20, {0x350: pystub(c, 3, this=True, pop=12,
              side=lambda emu, k: emu.calllog.append(('child-call', emu.reg('ecx'), emu.arg32(0), emu.arg32(1), emu.arg32(2))))}, nslots=0x351 // 4)
    self = obj(c, 0x60, {0x84: pystub(c, 0, ret=tail, this=True, pop=0)}, nslots=0x85 // 4)
    final = obj(c, 0x20, {0x74: pystub(c, 0, ret=r.getrandbits(32), this=True, pop=0,
              side=lambda emu, k: emu.calllog.append(('finish', emu.reg('ecx'))))})
    sysobj(c, slots={0xbc: pystub(c, 0, ret=final, this=True, pop=0,
              side=lambda emu, k: emu.calllog.append(('engine', emu.reg('ecx'))))}, table_size=0x20)
    return [self, r.getrandbits(32), r.getrandbits(32)]


S(0x57b610, 'GUESS prepare and dispatch nested engine objects', 'thiscall', None,
  ret='eax', gen=gen, note='batch62050')
