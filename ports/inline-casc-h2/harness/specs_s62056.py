from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    msg = obj(c, 0x40, {0x2c: pystub(c, 3, pop=0,
              side=lambda emu, k: emu.calllog.append(('error-message', emu.reg('ecx'), *(emu.arg32(i) for i in range(3)))))})
    logger = obj(c, 0x40, {0x20: pystub(c, 2, this=True, pop=8, ret=msg,
                  side=lambda emu, k: emu.calllog.append(('logger', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))})
    e.w32(0x700390, logger)
    e.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32),
                          side=lambda emu, k: emu.calllog.append(('assert',))))
    self = rnd(c, 0x20)
    e.wbytes(self + 4, bytes([r.choice([0, 1, 2, 3, 0xff])]))
    return [self]


S(0x5f3c40, 'GUESS validate state byte and log invalid values', 'thiscall', None,
  ret='eax', gen=gen, note='batch62056')
