from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    count = r.choice([0, 1, 2, 4])
    items = [rnd(c, 0x20) for _ in range(count)]
    indices = [r.choice([0, 1, 2, 15, 0x100, 0x1000]) for _ in items]
    for item, index in zip(items, indices):
        e.w16(item + 0x12, index)
    def populate(emu, call_no):
        base = emu.arg32(0)
        emu.w32(base, count)
        for i, item in enumerate(items):
            emu.w32(base + 4 + 4 * i, item)
    self = obj(c, 0x10200, {
        0x34: pystub(c, 1, this=True, pop=4, side=populate),
    }, nslots=0x35 // 4)
    return [self]


S(0x6493f0, 'GUESS set flag bits for registered item indices', 'thiscall', None,
  ret=None, gen=gen, note='batch62048')
