"""specs_s7.py - inline session batch 7 (Haiku, overnight): 0x4ce640, 0x4db9a0, 0x4e86b0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


# 0x4ce640 thiscall: (this, idx). Ring of 20 nodes via +4 so the walk always ends. idx from -2 to 40.
def _chunk(c):
    e, r = c.emu, c.rng
    o = _rnd(c, 0x30)
    count = r.randint(0, 16)
    chunk = r.randint(1, 4) | (0x80000000 if r.random() < 0.1 else 0)
    e.w32(o + 0x14, count)
    e.w32(o + 0xc, chunk)
    e.w32(o + 0x18, r.randint(0, 6))
    nodes = [_rnd(c, 0x10) for _ in range(20)]
    for i, n in enumerate(nodes):
        e.w32(n + 4, nodes[(i + 1) % 20])
    e.w32(o + 4, nodes[0])
    idx = r.randint(-2, 40) & 0xffffffff
    return [o, idx]


S(0x4ce640, 'chunkLookup (unknown) thiscall', 'thiscall', None, ret='eax', gen=_chunk,
  note='batch7; ring of 20 nodes; negative idx passes the first check')


# 0x4db9a0 thiscall: (this, key). Keys drawn from 0x200002 and random values; some lists empty.
def _haskey(c):
    e, r = c.emu, c.rng
    o = _rnd(c, 0x60)
    if r.random() < 0.2:
        e.w32(o + 0x54, 0)
    else:
        head = _rnd(c, 0x20)
        nodes = [_rnd(c, 0x40) for _ in range(r.randint(0, 4))]
        for i, n in enumerate(nodes):
            e.w32(n + 0xc, nodes[i + 1] if i + 1 < len(nodes) else 0)
            e.w32(n + 0x23, 0x200002 if r.random() < 0.5 else r.getrandbits(32))
        e.w32(head + 0xc, nodes[0] if nodes else 0)
        e.w32(o + 0x54, head)
    key = 0x200002 if r.random() < 0.4 else r.getrandbits(32)
    return [o, key]


S(0x4db9a0, 'hasKeyAt23 (unknown) thiscall', 'thiscall', None, ret='al', gen=_haskey,
  note='batch7; NULL head path compares the key to 0x200002')


# 0x4e86b0 thiscall: (this, key, start). A BST built from sorted random keys; start NULL or a random node.
def _tree(c):
    e, r = c.emu, c.rng
    o = _rnd(c, 0x20)
    nil = _rnd(c, 0x20)
    keys = sorted(r.sample(range(-50, 50), r.randint(0, 9)))
    nodes = {}

    def build(lo, hi):
        if lo >= hi:
            return nil
        mid = (lo + hi) // 2
        n = _rnd(c, 0x20)
        e.w32(n + 0xc, keys[mid] & 0xffffffff)
        e.w32(n + 4, build(lo, mid))
        e.w32(n + 8, build(mid + 1, hi))
        nodes[keys[mid]] = n
        return n

    root = build(0, len(keys))
    e.w32(o + 4, root)
    e.w32(o + 8, nil)
    key = r.choice(keys) if keys and r.random() < 0.5 else r.randint(-55, 55)
    start = 0
    if nodes and r.random() < 0.4:
        start = r.choice(list(nodes.values()))
    return [o, key & 0xffffffff, start]


S(0x4e86b0, 'treeFind (unknown) thiscall', 'thiscall', None, ret='eax', gen=_tree,
  note='batch7; sorted BST, key and start drawn from its nodes or outside')
