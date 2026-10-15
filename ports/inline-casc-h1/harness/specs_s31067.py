"""specs_s31067.py - Sonnet h1 batch 31067."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def r32(c):
    return c.rng.getrandbits(32)


def g5af170(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x40)
    n = r.randrange(0, 6)
    c.emu.w32(me, n)
    v = r.choice([0, r32(c)])
    if n and r.random() < 0.75:
        v = c.emu.r32(me + 4 + 4 * r.randrange(n))
    return [me, v]


def g4e50c0(c):
    clear_hooks(c)
    r = c.rng
    A = rnd(c, 0x200)
    top = 0x80000000 | (0x40000000 if r.random() < 0.5 else 0) | (r32(c) & 0x3fffffff)
    c.emu.w32(A + 4, top)
    k = r.randrange(0, 5)
    c.emu.w32(A + 0x10, k)
    e = A + 0x14 + 4 * k if top & 0x40000000 else A + 0x10
    cnt = r.randrange(1, 12)
    c.emu.w32(e, cnt)
    t = r.choice([0, 0x40000000, 0x80000000, 0xc0000000])
    c.emu.w32(e + 4, t | (r32(c) & 0x3fffffff))
    c.emu.w32(e + 8, r.choice([8, 12, 16, 0x20]))
    me = rnd(c, 0x20)
    c.emu.w32(me + 4, A)
    arg = rnd(c, 0x60)
    idx = r.randrange(0, cnt + 2)
    c.emu.w32(arg + 0x44, idx)
    if idx <= cnt and r.random() < 0.6:
        off = 8 if t == 0 else c.emu.r32(e + 8)
        want = (arg - c.emu.r32(me + 0xc)) & 0xffffffff
        if off + idx * 4 >= 12:
            c.emu.w32(e + off + idx * 4, want)
    return [me, arg]


def g53b860(c):
    clear_hooks(c)
    r = c.rng
    n = r.choice([0, 1, 2, 3, 4, -1 & 0xffffffff])
    nn = n if n < 0x80000000 else 0
    recs = rnd(c, 0x89 * 5 + 0x20)
    key = rnd(c, 0x89)
    cnt = r.choice([0, 1, 2, 3, -1 & 0xffffffff])
    c.emu.w32(key + 0x25, cnt)
    for k in range(nn):
        rk = recs + 0x89 * k
        mode = r.random()
        if mode < 0.6:
            c.emu.w32(rk + 0x25, cnt)
        elif mode < 0.8:
            c.emu.w32(rk + 0x25, r.choice([0, 1, 2, 3]))
        if mode < 0.5 and cnt < 4:
            for j in range(max(0, min(cnt if cnt < 0x80000000 else 0, 3))):
                c.emu.w32(rk + 5 + 4 * j, c.emu.r32(key + 5 + 4 * j))
    return [recs, n, key]


def g459b90(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x60)
    tab = rnd(c, 0x7c * 8)
    for i in range(8):
        for off in (4, 6, 8, 0xa, 0xc, 0xe):
            c.emu.wbytes(tab + 0x7c * i + off, (r.randrange(0, 9) if r.random() < 0.85 else 0).to_bytes(2, 'little'))
    c.emu.w32(me + 0x3c, tab)
    def sg():
        return r.choice([0, 1, -1 & 0xffffffff, 5, -7 & 0xffffffff])
    return [me, r.randrange(0, 9), sg(), sg(), sg()]


def g5ed340(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0x120)
    arr = c.emu.alloc(16, 4)
    recs = []
    for i in range(4):
        rec = rnd(c, 0x20)
        recs.append(rec)
        c.emu.w32(arr + 4 * i, rec)
    k = r.randrange(0, 5)
    c.emu.w32(me + 0xcb, arr)
    c.emu.w32(me + 0xcf, arr + 4 * k)
    a = r.choice([0, 1, r32(c)])
    b = r.choice([0, 5, -3 & 0xffffffff, 0x7fff, -0x8000 & 0xffffffff])
    for rec in recs:
        if r.random() < 0.5:
            c.emu.w32(rec + 4, a)
        if r.random() < 0.5:
            c.emu.wbytes(rec + 0xc, (b & 0xffff).to_bytes(2, 'little'))
    idx = -1 & 0xffffffff if r.random() < 0.5 else r.randrange(0, 4)
    return [me, a, b, idx]


def g4920e0(c):
    clear_hooks(c)
    r = c.rng
    me = rnd(c, 0xa10)
    n = r.randrange(0, 4)
    nodes = [rnd(c, 0x20) for _ in range(n)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0xc, nodes[i - 1] if i else 0)
        c.emu.w32(nd + 0x10, nodes[i + 1] if i + 1 < n else 0)
    c.emu.w32(me + 0xa04, nodes[0] if n else 0)
    before = r.choice(nodes) if n and r.random() < 0.5 else 0
    return [me, before, rnd(c, 0x20)]


def _bst(c, keys):
    """Build a sentinel BST in memory; returns (this, newnode_key)."""
    nil = rnd(c, 0x20)
    me = rnd(c, 0x20)
    c.emu.w32(me + 8, nil)
    root = nil
    for key in keys:
        nd = rnd(c, 0x20)
        c.emu.w32(nd + 0xc, key)
        c.emu.w32(nd, nil); c.emu.w32(nd + 4, nil); c.emu.w32(nd + 8, nil)
        if root == nil:
            root = nd
            continue
        p = root
        while True:
            pk = c.emu.r32(p + 0xc)
            pk = pk - (1 << 32) if pk >= 1 << 31 else pk
            k = key - (1 << 32) if key >= 1 << 31 else key
            off = 4 if k < pk else 8
            nxt = c.emu.r32(p + off)
            if nxt == nil:
                c.emu.w32(p + off, nd); c.emu.w32(nd, p)
                break
            p = nxt
    c.emu.w32(me + 4, root)
    return me


def g4e8160(c):
    clear_hooks(c)
    r = c.rng
    n = r.randrange(0, 5)
    keys = [r.choice([r.randrange(-5, 6) & 0xffffffff, r32(c)]) for _ in range(n)]
    me = _bst(c, keys)
    nd = rnd(c, 0x20)
    c.emu.w32(nd + 0xc, r.choice([r.randrange(-5, 6) & 0xffffffff, r32(c)]))
    return [me, nd]


def g42b0f0(c):
    clear_hooks(c)
    r = c.rng
    n = r.randrange(1, 7)
    keys = r.sample(range(100), n)
    hdr = rnd(c, 0x20)
    nodes = {}
    root = None
    for k in keys:
        nd = rnd(c, 0x20)
        nodes[k] = nd
        c.emu.w32(nd + 1, 0); c.emu.w32(nd + 5, 0); c.emu.w32(nd + 9, 0)
        if root is None:
            root = k
            continue
        p = root
        while True:
            off = 5 if k < p else 9
            nxt = c.emu.r32(nodes[p] + off)
            if nxt == 0:
                c.emu.w32(nodes[p] + off, nd); c.emu.w32(nd + 1, nodes[p])
                break
            p = [kk for kk, v in nodes.items() if v == nxt][0]
    c.emu.w32(nodes[root] + 1, hdr)
    c.emu.w32(hdr + 1, nodes[root])
    c.emu.w32(hdr + 5, nodes[min(keys)])
    c.emu.w32(hdr + 9, nodes[max(keys)])
    order = [nodes[k] for k in sorted(keys)] + [hdr]
    i = r.randrange(0, len(order))
    j = r.randrange(i, len(order))
    me = c.emu.alloc(4, 4)
    c.emu.w32(me, r32(c))
    return [me, order[i], order[j], r32(c)]


S(0x5af170, 'GUESS list next element', 'thiscall', None, ret='eax', gen=g5af170, note='batch31067')
S(0x4e50c0, 'GUESS tagged table entry compare', 'thiscall', None, ret='al', gen=g4e50c0, note='batch31067')
S(0x53b860, 'GUESS find matching record', 'stdcall', None, ret='eax', gen=g53b860, note='batch31067')
S(0x459b90, 'GUESS follow record links', 'thiscall', None, ret='eax', gen=g459b90, note='batch31067')
S(0x5ed340, 'GUESS set record fields with dirty flag', 'thiscall', None, ret=None, gen=g5ed340, note='batch31067')
S(0x4920e0, 'GUESS linked list insert before/at tail', 'thiscall', None, ret=None, gen=g4920e0, note='batch31067')
S(0x4e8160, 'GUESS sentinel BST insert', 'thiscall', None, ret=None, gen=g4e8160, note='batch31067')
S(0x42b0f0, 'GUESS tree iterator advance to end', 'thiscall', None, ret=None, gen=g42b0f0, note='batch31067')
