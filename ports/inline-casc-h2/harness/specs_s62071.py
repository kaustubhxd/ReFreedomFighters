from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    out_value = r.getrandbits(32)
    resource = obj(c, 0x90, {0x88: pystub(c, 2, this=True, pop=8, stackmark=(1,),
                 side=lambda emu, k: (emu.calllog.append(('resource', emu.reg('ecx'), emu.arg32(0), emu.r32(emu.arg32(1)))), emu.w32(emu.arg32(1), out_value)))}, nslots=0x89 // 4)
    looked = r.getrandbits(32)
    table = sysobj(c, table_slots={
        0x138: pystub(c, 0, this=True, ret=resource),
        0x58: pystub(c, 1, this=True, pop=4, ret=looked,
                     side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0)))),
    }, table_size=0x13c // 4)
    self = rnd(c, 0x20)
    return [self]


S(0x5b7dd0, 'GUESS initialize resource-backed defaults', 'thiscall', None,
  ret='eax', gen=gen, note='batch62071')
