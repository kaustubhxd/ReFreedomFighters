"""specs_s33045.py - h3 () batch 33045."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec


def _w(c):
    return c.rng.getrandbits(32)


def _zeroed(c, size, head=0x100):
    e = c.emu
    a = e.alloc(size, 4)
    e.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(head)))
    return a


def _g63ee70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x64cda0, 1, this=True)
    hook_rec(c, 0x4ce180, 1, this=True)
    me = _zeroed(c, 0xba00, 0x100)
    n = r.choice([0, 1, 2, 3, 4])
    n_idx = [r.choice([r.randrange(0, 8), r.randrange(0, 0x1000)])]
    e.w32(me + 0xec, n)
    for i in range(n):
        el = _zeroed(c, 0x10080, 0x40)
        et = _zeroed(c, 0x4000, 0x40)
        e.w32(et + 4 * (n_idx[0] & 0xfff), r.choice([0, _w(c)]))
        e.w32(el + 0x10071, et)
        e.w32(me + 0xf0 + 4 * i, el)
    idx = n_idx[0]
    tbl = _zeroed(c, 0x4000, 0x100)
    for q in range(6):
        e.w32(tbl + 4 * r.randrange(0, 0x1000), _w(c))
    e.w32(tbl + 4 * idx, _w(c))
    e.w32(tbl + 4 * (idx & 0xff), _w(c))
    e.w32(me + 0x68, tbl)
    a = (r.getrandbits(4) << 28) | (r.getrandbits(12) << 16) | (r.getrandbits(4) << 12) | idx
    return [me, a]


def _g4e53f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def side(em, k):
        em.calllog.append(('edx', 0, None, (em.reg('edx'),)))
    hook_rec(c, 0x4cc850, 0, this=True, side=side, ret=lambda em, k: r.choice([0, 0, 1, _w(c)]))
    base = rnd(c, 0x300)
    me = rnd(c, 0x40)
    e.w32(me + 0xc, base)
    a = rnd(c, 0x100)
    e.w32(a + 0x80, 0x40)
    n = r.choice([0, 1, 2, 3, 4])
    e.w32(base + 0x40, n)
    for i in range(n):
        e.w32(base + 0x44 + 4 * i, r.randrange(0x100, 0x2f0) & ~3)
    return [me, a, _w(c)]


def _g4947f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4920e0, 2, this=True)
    me = rnd(c, 0xb00)
    k = r.choice([0, 1, 2, 3, 4])
    nodes = [rnd(c, 0x20) for _ in range(k)]
    a = rnd(c, 0x20)
    member = k > 0 and r.random() < 0.7
    order = list(nodes)
    if member:
        order.insert(r.randrange(0, k + 1), a)
    for n in nodes + [a]:
        e.w32(n + 4, r.randrange(-2, 3) & 0xffffffff)
        e.w32(n + 8, r.randrange(-2, 3) & 0xffffffff)
    if member or (k > 0 and r.random() < 0.5):
        pass
    for i, n in enumerate(order):
        e.w32(n + 0xc, order[i - 1] if i > 0 else 0)
        e.w32(n + 0x10, order[i + 1] if i + 1 < len(order) else 0)
    e.w32(me + 0xa04, order[0] if order else 0)
    if not member:
        pool = nodes + [0]
        e.w32(a + 0xc, r.choice(pool))
        e.w32(a + 0x10, r.choice(pool))
    return [me, a, r.randrange(-2, 3) & 0xffffffff]


def _g64a120(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x63f600, 1, this=True)
    so = sysobj(c)
    ring = _zeroed(c, 0x8280, 0x300)
    j = r.choice([0, 1, 0x1fff, 0x1ffe, r.randrange(0, 0x2000), r.randrange(0, 0x2000)])
    e.w32(ring + 0x268, ring + 0x268 + 8 + 4 * j)
    me = rnd(c, 0x10100 if False else 0x100)
    me = _zeroed(c, 0x10080, 0x40)
    e.w32(me + 0x1005d, ring)
    a = rnd(c, 0x20)
    rc = rnd(c, 0x20)
    e.wbytes(rc + 8, bytes([r.choice([0, 1, 1, 2, 3, 0xff, r.getrandbits(8)])]))
    e.w32(a + 0xc, rc)
    return [me, a]


def _g6055b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)
    hook_rec(c, 0x41e290, 1, pop=0, ret=lambda em, k: rnd(c, 0x40))
    n = r.randrange(0, 22)
    s = e.alloc(0x40, 4)
    e.wbytes(s, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0' + bytes(r.getrandbits(8) for _ in range(10)))
    me = rnd(c, 0x40)
    e.w32(me + 0xc, rnd(c, 0x40))
    e.wbytes(me + 0x10, r.choice([0, 1, 2, n, n + 1, n + 2, 25, r.getrandbits(8)]).to_bytes(2, 'little'))
    return [me, s]


def _g4526a0(c):
    clear_hooks(c)

    def side(em, k):
        em.calllog.append(('edx', 0, None, (em.reg('edx'),)))
    hook_rec(c, 0x43e8e0, 1, this=True, side=side)
    return [_w(c), _w(c)]


def _g444d50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    D = rnd(c, 0x100)
    j = r.randrange(0, 6)
    m = j + r.randrange(1, 5)
    chain = None
    for _ in range(r.choice([0, 1, 2])):
        nd = rnd(c, 0x100)
        e.wbytes(nd + 8, bytes([r.choice([1, 1, 3, 5, 7, 2, 0, 0xfe])]))
        e.w32(nd + 0xc, chain or 0)
        chain = nd
    tmp = (chain or 0, D + 8 * j, D + 8 * m)

    def side(em, k):
        t = em.reg('ecx')
        for i, v in enumerate(tmp):
            em.w32(t + 4 * i, v)
    hook_rec(c, 0x440ce0, 1, this='mark', side=side)
    out = rnd(c, 0x100)
    me = rnd(c, 0xc0)
    lim = r.choice([out + 4 + 8 * t for t in range(0, 14)] + [out + 4 + 8 * 3 + 1])
    return [me, out, lim]


def _g57d460(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x57dde0, 0, this=True, ret=lambda em, k: r.choice([0, 1, _w(c), _w(c), _w(c)]))
    so = sysobj(c)
    if r.random() < 0.85:
        tab = e.alloc(0x80, 4)
        ents = [(r.randrange(0, 0x100), r.randrange(0, 4)), (r.randrange(0, 0x100), r.randrange(0, 0x100))]
        for i, (s0, ln) in enumerate(ents):
            e.w32(tab + 16 * i, s0)
            e.w32(tab + 16 * i + 0xc, ln)
        e.w32(tab + 32, 0)
        e.w32(tab + 32 + 0xc, 0x10000)
        e.w32(so + 0x190b, tab)
    else:
        e.w32(so + 0x190b, 0)
    me = rnd(c, 0xd0)
    for i in range(4):
        v = r.choice([0xffffffff, r.randrange(0, 0x180), r.randrange(0, 0x180), (r.getrandbits(16) << 16) | r.getrandbits(16), r.randrange(0, 0x180)])
        e.w32(me + 0xac + 4 * i, v)
    return [me, rnd(c, 0x20)]


S(0x63ee70, 'GUESS clear slot in children', 'thiscall', None, ret=None, gen=_g63ee70, note='batch33045')
S(0x4e53f0, 'GUESS first matching name entry', 'thiscall', None, ret='eax', gen=_g4e53f0, note='batch33045')
S(0x4947f0, 'GUESS sorted list reinsert', 'thiscall', None, ret=None, gen=_g4947f0, note='batch33045')
S(0x64a120, 'GUESS ring push and refcount', 'thiscall', None, ret=None, gen=_g64a120, note='batch33045')
S(0x6055b0, 'GUESS string assign', 'thiscall', None, ret='al', gen=_g6055b0, note='batch33045')
S(0x4526a0, 'GUESS 20 table calls', 'stdcall', None, ret=None, gen=_g4526a0, note='batch33045')
S(0x444d50, 'GUESS masked pair copy', 'thiscall', None, ret='eax', gen=_g444d50, note='batch33045')
S(0x57d460, 'GUESS resolve ids', 'thiscall', None, ret='eax', gen=_g57d460, note='batch33045')
