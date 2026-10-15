from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    count = r.randrange(0, 9)
    callback = pystub(c, 2, this=True, pop=8,
                      side=lambda emu, k: emu.calllog.append(('cleanup', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    self = obj(c, 0x28, {0x340: callback}, nslots=0x341 // 4)
    entries = rnd(c, max(1, 0x18 * count))
    for i in range(count):
        entry = entries + 0x18 * i
        e.w32(entry + 4, r.getrandbits(32))
        e.w32(entry, r.getrandbits(32))
        e.w32(entry + 0x10, r.getrandbits(32))
        e.w32(entry + 0x14, r.getrandbits(32))
    e.w32(self + 0x1c, entries)
    e.w32(self + 0x20, count)
    return [self]


S(0x463f60, 'GUESS release and clear counted records', 'thiscall', None,
  ret=None, gen=gen, note='batch62068')
