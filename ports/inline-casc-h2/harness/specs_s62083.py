from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    enabled = r.choice([0, 0x100, 0x101, 1])
    sys = obj(c, 0x100, {0xe8: pystub(c, 1, this=True, pop=4, ret=enabled,
        side=lambda emu, k: emu.calllog.append(('enabled', emu.reg('ecx'), emu.arg32(0))))})
    e.w32(0x70039c, sys)
    item = rnd(c, 0x40)
    count = r.choice([1, 2, 3, 4])
    index = r.randrange(count)
    got = r.choice([item, item, 0])
    manager = obj(c, 0x40, {
        0x34: pystub(c, 1, this=True, pop=4, ret=got,
            side=lambda emu, k: emu.calllog.append(('get', emu.reg('ecx'), emu.arg32(0)))),
        0x14: pystub(c, 0, this=True, pop=0, ret=count,
            side=lambda emu, k: emu.calllog.append(('count', emu.reg('ecx'))))})
    target = obj(c, 0x380, {0x370: pystub(c, 2, this=True, pop=8,
        side=lambda emu, k: emu.calllog.append(('dispatch', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    self = rnd(c, 0x60)
    e.w32(self + 0x44, target)
    e.w32(self + 0x48, manager)
    e.w32(self + 0x4c, index)
    e.w32(self + 0x50, r.getrandbits(32))
    return [self]


S(0x4858a0, 'GUESS advance gated collection item', 'thiscall', None,
  ret=None, gen=gen, note='batch62083')
