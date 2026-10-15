from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    hook_rec(c, 0x43ef30, 3, this=True, pop=12,
             side=lambda emu, k: emu.calllog.append(('prepare', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))
    table_result = r.getrandbits(32)
    sysobj(c, table_slots={0x50: pystub(c, 1, this=True, pop=4, ret=table_result,
                         side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0))))}, table_size=0x54 // 4)
    self = obj(c, 0x400, {0x360: pystub(c, 1, this=True, pop=4,
                     side=lambda emu, k: emu.calllog.append(('dispatch', emu.reg('ecx'), emu.arg32(0))))}, nslots=0x361 // 4)
    arg1 = rnd(c, 0x60)
    p = rnd(c, 0x20)
    nested = rnd(c, 0x40)
    e.w32(arg1 + 0x54, p)
    e.w32(p + 0xc, nested)
    e.w32(nested + 0x23, r.choice([0x200015, 0, r.getrandbits(32)]))
    return [self, arg1, r.getrandbits(32), r.getrandbits(32)]


S(0x444260, 'GUESS conditionally dispatch prepared object', 'thiscall', None,
  ret=None, gen=gen, note='batch62067')
