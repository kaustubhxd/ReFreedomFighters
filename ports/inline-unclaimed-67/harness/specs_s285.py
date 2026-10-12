"""specs_s285.py - unclaimed area 67, gap band: 0x5ff0f0 (search by a word key over an acyclic node graph)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _case(c):
    n = c.rng.choice([0, 1, 2, 4, 6])
    nodes = []
    for _ in range(n):
        nd = c.emu.alloc(0x20, 4)
        c.emu.wbytes(nd, bytes(c.rng.getrandbits(8) for _ in range(0x20)))
        c.emu.w16(nd + 0xd, c.rng.randint(0, 9)) if hasattr(c.emu, 'w16') else c.emu.wbytes(nd + 0xd, bytes([c.rng.randint(0, 9), 0]))
        nodes.append(nd)
    # acyclic: a node only points forward in the list
    for k, nd in enumerate(nodes):
        later = nodes[k + 1:]
        left = later[c.rng.randrange(len(later))] if later and c.rng.random() < 0.7 else 0
        right = later[c.rng.randrange(len(later))] if later and c.rng.random() < 0.7 else 0
        c.emu.w32(nd + 5, left)
        c.emu.w32(nd + 9, right)
    a = _rnd(c, 0x20)
    c.emu.w32(a + 1, nodes[0] if nodes else 0)
    out = _rnd(c, 0x10)
    key = c.emu.alloc(0x10, 4)
    c.emu.wbytes(key, bytes([c.rng.randint(0, 9), 0]) + bytes(14))
    self_ = _rnd(c, 0x20)
    c.emu.w32(self_, a)
    c.emu.mu.ctl_flush_tb()
    return [self_, out, key]


S(0x5ff0f0, 'FUN_5ff0f0 (treeSearch5ff0)', 'thiscall', None, ret=None, gen=_case, note='batch285; word-key tree search, result via out')
