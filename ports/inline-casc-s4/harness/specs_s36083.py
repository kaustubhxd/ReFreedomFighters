"""specs_s36083.py - cascade s4 batch 36083: 0x444840 (collect unflagged blocks of 0x70 bytes from ranges into an array)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, logger


def _g444840(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    logger(c, 2, 0x30)

    def blocks(k):
        a = e.alloc(0x70 * k + r.choice([8, 16]), 8)
        for i in range(k):
            e.w32(a + 0x70 * i + 0x3c, r.choice([0, 0x10000000, 0x10000000, 0x20000000, 0]))
        lo = a | r.choice([0, 0, 1, 5])
        hi = (a + 0x70 * (k - 1)) | r.choice([0, 0, 2, 7])
        return lo, hi

    def mknode(npairs, link, nxt):
        al = 2 * npairs + (1 if link else 0)
        nd = e.alloc(0x80, 8)
        e.wbytes(nd + 8, bytes([al]))
        if link:
            e.w32(nd + 0xc, nxt)
        base = nd + 0xc + (4 if link else 0)
        for i in range(npairs):
            lo, hi = blocks(r.choice([1, 2, 3]))
            e.w32(base + 8 * i, lo)
            e.w32(base + 8 * i + 4, hi)
        return nd

    chain = r.choice([0, 1, 2, 3])
    nodes = []
    nxt = 0
    for i in range(chain):
        link = (i < chain - 1) or r.random() < 0.3
        nodes.append(None)
    # build from the tail so the links exist
    built = []
    nxt = 0
    for i in reversed(range(chain)):
        link = i < chain - 1
        built.append(mknode(r.choice([1, 2, 3]), link, nxt if link else 0))
        nxt = built[-1]
    built.reverse()
    first = built[0] if built else 0
    # the iterator starts inside the first node's own range (the node's chain tail gets reached when cur hits limit)
    if first:
        al = r.choice([None])
    root = mknode(r.choice([1, 2]), bool(built), first if built else 0)
    node0 = root
    al0 = e.rbytes(node0 + 8, 1)[0]
    cur0 = node0 + 0xc + (4 if al0 & 1 else 0)
    lim0 = node0 + (al0 + 3) * 4
    if r.random() < 0.1:
        cur0 = 0
    if r.random() < 0.05:
        node0 = 0

    junk = r.getrandbits(32)

    def fill(em, k):
        p = em.reg('ecx')
        em.w32(p, node0)
        em.w32(p + 4, cur0)
        em.w32(p + 8, lim0)
        em.w32(p + 12, junk)
    hook_rec(c, 0x440ce0, 1, this='mark', side=fill)
    cap = r.choice([0, 1, 2, 3, 5, 8, 20])
    out = e.alloc(0x100, 8)
    t = rnd(c, 0xd0)
    e.w32(t + 0xbc, r.getrandbits(32))
    return [t, out, out + 4 * cap]


S(0x444840, 'GUESS collect unflagged blocks from ranges into an array', 'thiscall', None, ret='eax', gen=_g444840, note='batch36083')
