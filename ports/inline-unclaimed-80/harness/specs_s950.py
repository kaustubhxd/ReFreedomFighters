"""specs_s950.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x43aca0. The state s has a flag byte at +8 (zero 30%), a list head
at +4 (null 20%), and nodes of 1..4 items. A node's first dword points to an item buffer B (item pointer B+4); the item's first dword is
zero half the time and its byte at +0x10 is zero 40% of the time. Item bytes are random, so both flag branches run. The global 0x70039c points to a buffer whose +0x1c dword is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    g = _rnd(c, 0x40)
    c.emu.w32(0x70039c, g)
    s = _rnd(c, 0x20)
    c.emu.wbytes(s + 8, bytes([0 if c.rng.random() < 0.3 else c.rng.randint(1, 255)]))
    nodes = []
    if c.rng.random() >= 0.2:
        for _ in range(c.rng.randint(1, 4)):
            nodes.append(_rnd(c, 0x20))
    for i, nd in enumerate(nodes):
        b = _rnd(c, 0x80)
        c.emu.wbytes(b + 0x10, bytes([0 if c.rng.random() < 0.4 else c.rng.randint(1, 255)]))
        pp = b + 4
        if c.rng.random() < 0.5:
            c.emu.w32(pp, 0)
        c.emu.w32(nd, pp)
        c.emu.w32(nd + 5, nodes[i + 1] if i + 1 < len(nodes) else 0)
    c.emu.w32(s + 4, nodes[0] if nodes else 0)
    return [s]


S(0x43aca0, 'walk clearing item flags (unknown) stdcall', 'stdcall', None, ret=None, gen=_fn,
  note='unclaimed-80 gap band; flag byte at s+8, list at s+4, item flags at P+0x32, global at 0x70039c')
