from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    id_value = r.getrandbits(32)
    nested = rnd(c, 0x80)
    e.w32(nested + 0x6c, id_value)
    arg = rnd(c, 0x20)
    e.w32(arg + 8, nested)
    found = r.getrandbits(32)
    owner = obj(c, 0x120, {0xb0: pystub(c, 1, this=True, pop=4, ret=found,
        side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0))))})
    table = rnd(c, 0x30)
    e.w32(table + 0x18, owner)
    engine = rnd(c, 0x1b20)
    e.w32(engine + 0x1aa3, table)
    e.w32(0x70039c, engine)
    def notify(emu, k):
        emu.calllog.append(('notify', emu.reg('ecx'), emu.arg32(0)))
    slot = pystub(c, 4, this=True, pop=16, ret=r.getrandbits(32),
        side=lambda emu, k: emu.calllog.append(('finish', emu.reg('ecx'), *(emu.arg32(i) for i in range(4)))))
    self = obj(c, 0x2a0, {0x30: slot})
    flag = r.choice([0, 0, 1, 0x100])
    e.w32(self + 0x291, flag)
    hook_rec(c, 0x641b60, 1, this=True, pop=4, side=notify)
    return [self, arg]


S(0x6472c0, 'GUESS resolve input identifier and notify state', 'thiscall', None,
  ret='eax', gen=gen, note='batch62089')
