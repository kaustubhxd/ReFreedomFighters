"""specs_s36031.py - cascade s4 batch 36031: 0x64d880 (release a pool slot, record 0x34), 0x5cdb70 (dispatch with vtable calls), 0x4c85f0 (toggle and flag walk), 0x438a60 (drop records from lists)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, logger, reftab


def _g64d880(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    blocks = [rnd(c, 0x20) for _ in range(3)]
    p = rnd(c, 0x20)
    rnd(c, r.randint(0, 0x300))
    b = rnd(c, 0x20)
    if r.random() < 0.5:
        p, b = b, p
    e.wbytes(b, bytes([r.choice([1, 1, 2, 3, 0])]))
    other = blocks[0]
    a = b if r.random() < 0.2 else blocks[1]
    d = b if r.random() < 0.2 else blocks[2]
    e.w32(b + 8, a)
    e.w32(b + 0xc, d)
    head = b if r.random() < 0.3 else other
    e.w32(other + 0xc, blocks[1] if r.random() < 0.5 else blocks[2])
    E = obj(c, 0x20, {0x2c: pystub(c, 1, this=True, ret=b), 0x34: pystub(c, 1, this=True)})
    e.w32(E + 8, head)
    e.w32(E + 0xc, r.getrandbits(32))
    return [E, p]


def _g5cdb70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for a in (0x5ceb30, 0x5ceb70, 0x5cdab0, 0x5cff20, 0x5d0080, 0x5cecd0):
        hook_rec(c, a, 0, this=True)
    hook_rec(c, 0x5cf420, 1, this=True)
    rets = [r.choice([0, 1, 0x100, 0x101]) for _ in range(2)]
    ed = obj(c, 0x700, {0x80: pystub(c, 2, this=True), 0x438: pystub(c, 0, this=True, ret=lambda em, n, _r=rets: _r[min(n, 1)])})
    o = obj(c, 0x40, {0x80: pystub(c, 2, this=True)})
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=o)})
    s = obj(c, 0xe40, {0x84: pystub(c, 0, this=True)})
    e.w32(s + 0x44, ed)
    e.wbytes(s + 0xdd8, bytes([r.choice([0, 0, 1, 0x80])]))
    e.w32(s + 0xe1c, r.choice([0, 1, 2, 3, 3, 4, 0xffffffff]))
    return [s]


def _g4c85f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2)
    hook_rec(c, 0x4daa20, 1, this=True)
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3, 5])):
        n = rnd(c, 0x60)
        if r.random() < 0.7:
            x = rnd(c, 0x20)
            y = rnd(c, 0x40)
            fl = r.getrandbits(32)
            if r.random() < 0.5:
                fl |= 0x800000
            else:
                fl &= ~0x800000
            e.w32(y + 0x23, fl)
            e.w32(x + 0xc, y)
            e.w32(n + 0x54, x)
        else:
            e.w32(n + 0x54, 0)
        nodes.append(n)
    for a, b in zip(nodes, nodes[1:] + [0]):
        e.w32(a + 0x20, b)

    def nxt(em, rr):
        it = em.arg32(0)
        cur = em.r32(it)
        em.calllog.append(('lst.next', 0x50, em.reg('ecx'), (cur,)))
        em.w32(it, em.r32(cur + 0x20))
        em.ret(0, 4)
    lst = obj(c, 0x40, {0x50: e.stub_fn('list next', nxt)})
    e.w32(lst + 8, nodes[0] if nodes else 0)
    so = sysobj(c, table_size=0xc00)
    tab = e.r32(so + 0x9b)
    e.w32(tab + 0xadc, lst)
    s = rnd(c, 0x60)
    e.wbytes(s + 0x51, bytes([r.choice([0, 1, 1, 2, 0x80, 0xff])]))
    return [s]


def _g438a60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    s = rnd(c, 0x40)
    e.w32(s, 2 if r.random() < 0.7 else r.getrandbits(32))
    nrows = 3
    T = rnd(c, 10 * nrows + 8)
    recs = [s, s, rnd(c, 8), rnd(c, 8)]
    e.w32(recs[2], 2)
    e.w32(recs[3], r.choice([2, 3, 1]))
    for row in range(nrows):
        k = r.choice([0, 1, 2, 3, 4])
        ns = []
        for _ in range(k):
            n = rnd(c, 12)
            e.w32(n, r.choice(recs))
            ns.append(n)
        for a, b in zip(ns, ns[1:] + [0]):
            e.w32(a + 5, b)
        e.w32(T + row * 10 + 4, ns[0] if ns else 0)
    Y = rnd(c, 0x1360)
    e.w32(Y + 0x1344, T)
    W = rnd(c, 0x20)
    e.w32(W + 0x11, Y)
    hook_rec(c, 0x438c30, 0, this=True, ret=W)
    if r.random() < 0.15:
        e.w32(s + 0xd, 0)
    else:
        elems = [r.randint(0, nrows - 1) for _ in range(r.choice([0, 1, 2, 3, 4]))]
        e.w32(s + 0xd, reftab(c, elems))
    return [s]


S(0x64d880, 'GUESS release a pool slot (B, record 0x34)', 'thiscall', None, ret=None, gen=_g64d880, note='batch36031')
S(0x5cdb70, 'GUESS dispatch with vtable calls', 'thiscall', None, ret=None, gen=_g5cdb70, note='batch36031')
S(0x4c85f0, 'GUESS toggle and flag walk', 'thiscall', None, ret=None, gen=_g4c85f0, note='batch36031')
S(0x438a60, 'GUESS drop records from lists', 'thiscall', None, ret=None, gen=_g438a60, note='batch36031')
