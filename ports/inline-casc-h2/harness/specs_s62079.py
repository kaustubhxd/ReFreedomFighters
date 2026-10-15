from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    parsed = rnd(c, 0x10)
    value = r.getrandbits(32)
    e.w32(parsed, value)
    hook_rec(c, 0x5003d0, 1, this=True, pop=4, ret=parsed,
             side=lambda emu, k: emu.calllog.append(('parse', emu.reg('ecx'), emu.arg32(0))))
    result = r.choice([0, 0, rnd(c, 0x20)])
    lookup = pystub(c, 1, this=True, pop=4, ret=result,
             side=lambda emu, k: emu.calllog.append(('lookup', emu.reg('ecx'), emu.arg32(0))))
    syslist = obj(c, 0x70, {0x58: lookup})
    sys = rnd(c, 0xa0)
    e.w32(sys + 0x9b, syslist)
    e.w32(0x70039c, sys)
    dispatch = obj(c, 0x40, {0x2c: pystub(c, 2, this=True, pop=0,
             side=lambda emu, k: emu.calllog.append(('report', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    msg = rnd(c, 0x20)
    e.w32(msg, e.r32(dispatch))
    logger = obj(c, 0x30, {0x20: pystub(c, 2, this=True, pop=8, ret=msg,
             side=lambda emu, k: emu.calllog.append(('log', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    e.w32(0x700390, logger)
    self = rnd(c, 0x20)
    arg = rnd(c, 0x10)
    e.w32(arg + 4, rnd(c, 0x20))
    e.w32(self + 0xc, r.getrandbits(32))
    return [self, arg]


S(0x503710, 'GUESS parse and resolve resource reference', 'thiscall', None,
  ret=None, gen=gen, note='batch62079')
