from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    calls = []
    def stub(tag):
        return pystub(c, 1, this=True, pop=4,
                      side=lambda emu, k: calls.append((tag, emu.reg('ecx'), emu.arg32(0))))
    target = obj(c, 0x40, {0x24: stub('set24'), 0x3c: stub('set3c')}, nslots=0x3d // 4)
    self = rnd(c, 0x50)
    for off in (0x2a, 0x2e, 0x32, 0x36, 0x3a):
        e.w32(self + off, r.getrandbits(32))
    return [self, target]


S(0x4f42a0, 'GUESS initialize five target properties', 'thiscall', None,
  ret=None, gen=gen, note='batch62061')
