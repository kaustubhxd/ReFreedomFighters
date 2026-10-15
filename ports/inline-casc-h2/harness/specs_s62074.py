from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def gen(c):
    clear_hooks(c)
    r, e = c.rng, c.emu
    item = r.getrandbits(32)
    key = r.choice([0, 0, r.getrandbits(32)])
    mask = r.choice([0, 1, 2, 0x80000000, r.getrandbits(32)])
    nodes = [rnd(c, 0x30) for _ in range(r.randrange(1, 6))]
    for i, node in enumerate(nodes):
        e.w32(node + 0x2c, r.getrandbits(32))
        e.w32(node + 8, 1 if i + 1 < len(nodes) else 0)
    def get_node(emu, k):
        return nodes[min(k, len(nodes) - 1)]
    vt_c = pystub(c, 1, this=True, pop=4, ret=get_node,
                  side=lambda emu, k: emu.calllog.append(('next', emu.reg('ecx'), emu.arg32(0))))
    vt4 = pystub(c, 2, this=True, pop=8,
                 side=lambda emu, k: emu.calllog.append(('visit', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    self = obj(c, 0x20, {0xc: vt_c, 4: vt4})
    return [self, item, key, mask]


S(0x657550, 'GUESS visit matching nodes from keyed collection', 'thiscall', None,
  ret='eax', gen=gen, note='batch62074')
