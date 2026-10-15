from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x40)
    for off in (0xc, 0x10, 0x1c, 0x28):
        e.w32(self + off, r.getrandbits(32))
    outvals = {'6c': [r.getrandbits(32) for _ in range(3)], '50': [r.getrandbits(32) for _ in range(2)]}
    def make(tag):
        def side(emu, k):
            arg = emu.arg32(0)
            emu.calllog.append((tag, emu.reg('ecx'), arg))
            if arg != self:
                emu.w32(arg, outvals[tag][k])
        return pystub(c, 1, this=True, pop=4, side=side)
    object = obj(c, 0x80, {0x6c: make('6c'), 0x50: make('50')})
    return [self, object]


S(0x4e7480, 'GUESS initialize object fields through callbacks', 'thiscall', None,
  ret=None, gen=gen, note='batch62091')
