from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub

def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    self = rnd(c, 0x70)
    wanted = r.getrandbits(32)
    count = r.randrange(0, 6)
    items = [rnd(c, 0x40) for _ in range(count)]
    vals = [r.getrandbits(32) for _ in items]
    if count and r.random() < 0.6:
        vals[r.randrange(count)] = wanted
    for p, v in zip(items, vals):
        e.w32(p + 0x34, v)
    def begin(emu, k):
        out = emu.arg32(0)
        emu.w32(out, 1)
    def next_item(emu, k):
        out = emu.arg32(0)
        idx = emu.r32(out) - 1
        if idx < len(items):
            emu.w32(out, idx + 2)
            return items[idx]
        emu.w32(out, 0)
        return 0
    list_obj = obj(c, 0x20, {
        0x4c: pystub(c, 1, this=True, pop=4, side=begin),
        0x5c: pystub(c, 1, this=True, pop=4, ret=lambda emu, k: next_item(emu, k)),
    })
    e.w32(self + 0x5c, list_obj if r.random() < 0.9 else 0)
    return [self, wanted]

S(0x454f20, 'GUESS find collection item by embedded identifier', 'thiscall', None, ret='eax', gen=gen, note='batch62113')
