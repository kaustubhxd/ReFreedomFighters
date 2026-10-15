"""specs_s1202.py - pathfinding batch 1202: A* open list, GetAreaInfo visitors."""
from pilot import S, u32


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


N = 24


def _queue(c):
    """A valid open list (sorted by f, linked through prev/next) plus some free nodes; sometimes random links."""
    r = c.rng
    e = c.emu
    self_ = _rnd(c, 0xa0)
    arr = _rnd(c, N * 0x15 + 0x20)
    e.w32(self_ + 0x98, arr)
    ids = list(range(1, N))
    r.shuffle(ids)
    k = r.randint(0, N - 2)
    ql = ids[:k]
    costs = sorted(c.fv(0, 100, 0.05) if r.random() < 0.9 else float(r.randint(0, 5)) for _ in ql)
    costs = [x if x == x else 1.0 for x in costs]
    costs.sort()
    if r.random() < 0.5:
        costs.reverse()
    for i, nid in enumerate(ql):
        p = arr + nid * 0x15
        e.wf32(p + 0xa, costs[i])
        e.w16(p + 0x10, ql[i - 1] if i > 0 else 0)
        e.w16(p + 0x12, ql[i + 1] if i + 1 < len(ql) else 0)
    for nid in ids[k:] + [0]:
        p = arr + nid * 0x15
        e.wf32(p + 0xa, c.fv(0, 100))
        if r.random() < 0.8:
            e.w16(p + 0x10, 0)
            e.w16(p + 0x12, 0)
        else:
            e.w16(p + 0x10, r.randrange(N))
            e.w16(p + 0x12, r.randrange(N))
    if r.random() < 0.15:
        for nid in range(N):
            e.w16(arr + nid * 0x15 + 0x10, r.randrange(N))
            e.w16(arr + nid * 0x15 + 0x12, r.randrange(N))
    head = r.choice(ql) if ql and r.random() < 0.8 else r.randrange(N)
    node = r.choice(ids) if r.random() < 0.9 else r.randrange(N)
    return [self_, head | (r.getrandbits(16) << 16 if r.random() < 0.2 else 0),
            node | (r.getrandbits(16) << 16 if r.random() < 0.2 else 0)]


S(0x52d250, 'ZPFOctree_packed::AddToPrioQueue', 'thiscall', None, gen=_queue)


def _func(c):
    r = c.rng
    e = c.emu
    f = _rnd(c, 0x10)
    rec = _rnd(c, 0x10)
    e.w32(f + 4, rec)
    levels = r.randint(1, 6)
    want = r.randint(0, 5)
    e.w32(f + 8, want)
    oct_ = _rnd(c, 0x40)
    e.w32(oct_ + 0x38, levels)
    depth = levels - want - 1 if r.random() < 0.6 else r.randint(-1, 6)
    return f, oct_, depth


def _elem(c):
    f, o, d = _func(c)
    flag = _rnd(c, 4)
    if c.rng.random() < 0.3:
        c.emu.w32(flag, 0)
    return [f, o, flag, c.rng.getrandbits(32), _rnd(c, 12), _rnd(c, 12), d, c.rng.getrandbits(32)]


def _leaf(c):
    f, o, d = _func(c)
    return [f, o, _rnd(c, 4), _rnd(c, 12), _rnd(c, 12), d]


S(0x52d380, 'ZPFOctreeElementFuncGetAreaInfo_packed::Apply', 'thiscall', None, ret='eax', gen=_elem)
S(0x52d4a0, 'ZPFOctreeLeafFuncGetAreaInfo_packed::Apply', 'thiscall', None, ret='eax', gen=_leaf)
S(0x52d510, 'ZPFOctreeNodeFuncGetAreaInfo_packed::Apply', 'thiscall', None, ret='eax', gen=_leaf)
