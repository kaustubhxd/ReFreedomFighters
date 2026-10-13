"""specs_s1141.py - collision thread batch 1141 (GUESS name): 0x441530, a node walk with a sentinel and a flag test. The nodes link
forward only (next and child point to later nodes, or are zero), so the walk terminates. Each node has a type object whose +0xc
points to a flags object (dword at +0x23, bit 0x100000 drawn half the time). The cell p holds a node or the sentinel. The
sentinel is this+8 (any node, or zero); this+0x4c is zero or not."""
from pilot import S, F


def _walk(c):
    e, r = c.emu, c.rng
    n = r.randrange(3, 9)
    nodes = [e.alloc(0x80, 16) for _ in range(n)]
    for nd in nodes:
        e.wbytes(nd, bytes(r.getrandbits(8) for _ in range(0x80)))
    types = []
    for _ in range(4):
        x = e.alloc(0x40, 16)
        e.wbytes(x, bytes(r.getrandbits(8) for _ in range(0x40)))
        fl = r.getrandbits(32)
        fl = (fl | 0x100000) if r.random() < 0.5 else (fl & ~0x100000)
        e.w32(x + 0x23, fl)
        t = e.alloc(0x60, 16)                                       # the candidate is at +0x50: the block must cover it
        e.wbytes(t, bytes(r.getrandbits(8) for _ in range(0x60)))
        e.w32(t + 0xc, x)
        e.w32(t + 0x50, r.choice(nodes + [0]))       # the candidate: read, never followed
        types.append(t)
    for i, nd in enumerate(nodes):
        later = nodes[i + 1:]
        e.w32(nd + 0x50, r.choice(later + [0]) if later else 0)     # next: later node or zero
        e.w32(nd + 0x60, r.choice(later + [0]) if later else 0)     # child: later node or zero
        e.w32(nd + 0x54, r.choice(types))                           # type: never null
    self_ = e.alloc(0x60, 16)
    e.wbytes(self_, bytes(r.getrandbits(8) for _ in range(0x60)))
    e.w32(self_ + 8, r.choice(nodes + [0]))                         # sentinel
    e.w32(self_ + 0x4c, r.choice([0, 0, 1, 0xffff]))
    e.w32(self_ + 0x10, r.choice(nodes))                             # a second node-valued field: a wrong sentinel field is caught
    cell = e.alloc(8, 4)
    start = r.choice(nodes)                                         # the cell always holds a node (the walk dereferences it)
    if r.random() < 0.1 and e.r32(self_ + 8):
        start = e.r32(self_ + 8)                                    # ...sometimes the sentinel itself
    e.w32(cell, start)
    return [self_, cell]


S(0x441530, 'walk over a node tree that stops at the sentinel; flag test on the node type (name GUESS)', 'thiscall', None,
  gen=_walk, note='batch1141')
