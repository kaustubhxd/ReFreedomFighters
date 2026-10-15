from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    collection = rnd(c, 0x30)
    ext_index = r.randrange(0, 17)
    hook_rec(c, 0x5aeff0, 1, this=True, pop=4, ret=ext_index,
             side=lambda emu, k: emu.calllog.append(('find', emu.reg('ecx'), emu.arg32(0))))
    next_result = r.getrandbits(32)
    hook_rec(c, 0x5afe20, 1, this=True, pop=4, ret=next_result,
             side=lambda emu, k: emu.calllog.append(('advance', emu.reg('ecx'), emu.arg32(0))))
    table = obj(c, 0x40, {0x2c: pystub(c, 2, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('report', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    msg = rnd(c, 0x20)
    e.w32(msg, e.r32(table))
    logger = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=msg,
             side=lambda emu, k: emu.calllog.append(('log', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    e.w32(0x700390, logger)
    self = rnd(c, 0x30)
    mode = r.randrange(3)
    e.w32(self + 0x14, 0 if mode == 0 else collection)
    argument = 0 if mode == 1 else rnd(c, 0x20)
    return [self, argument]


S(0x5afdd0, 'GUESS find and advance collection entry', 'thiscall', None,
  ret='eax', gen=gen, note='batch62080')
