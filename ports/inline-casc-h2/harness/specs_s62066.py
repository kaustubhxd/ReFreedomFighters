from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    mask = r.getrandbits(32)
    callback = pystub(c, 1, this=True, pop=4,
                      side=lambda emu, k: emu.calllog.append(('release', emu.reg('ecx'), emu.arg32(0))))
    table = obj(c, 0x20, {0xc: callback})
    manager = rnd(c, 0x240)
    e.w32(manager + 0x234, table)
    self = rnd(c, 0x10064)
    e.w32(self + 0x1005d, manager)
    e.w32(self + 0x10059, mask)
    count = r.randrange(0, 6)
    nodes = [rnd(c, 0x24) for _ in range(count)]
    for i, node in enumerate(nodes):
        flags = rnd(c, 0x20)
        e.w32(node + 8, flags)
        e.w32(flags + 0x14, r.getrandbits(32))
        e.w32(node + 0x1c, nodes[i + 1] if i + 1 < count else 0)
    data = rnd(c, 0x24)
    first = r.choice([0, r.getrandbits(32)])
    e.w32(data + 0xc, first)
    e.w32(data + 0x1c, nodes[0] if nodes else 0)
    return [self, data]


S(0x64c1e0, 'GUESS clear queued object flags and release first entry', 'thiscall', None,
  ret='eax', gen=gen, note='batch62066')
