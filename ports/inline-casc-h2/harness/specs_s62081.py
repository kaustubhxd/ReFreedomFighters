from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    callback = pystub(c, 3, this=True, pop=12,
        side=lambda emu, k: emu.calllog.append(('begin', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))
    end = pystub(c, 0, this=True, pop=0,
        side=lambda emu, k: emu.calllog.append(('end', emu.reg('ecx'))))
    self = obj(c, 0x1190, {0x230: callback, 0xc8: end})
    engine = rnd(c, 0x1410)
    e.w32(0x70039c, engine)
    for off in (0xa10, 0x13fc, 0xad8, 0x13f7):
        e.w8(engine + off, r.getrandbits(8))
    flush = pystub(c, 0, ret=0, side=lambda emu, k: emu.calllog.append(('flush',)))
    e.w32(0x6761f0, flush)
    e.w32(self + 0x137, r.choice([0, 0, 1]))
    e.w8(self + 0x1184, r.getrandbits(8))
    e.w8(self + 0x1185, r.getrandbits(8))
    return [self, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x654d60, 'GUESS reset engine input flags after callback', 'thiscall', None,
  ret=None, gen=gen, note='batch62081')
