"""specs_s213093.py - batch 213093: pair insertion into a chain of small nodes, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g495950(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    d = r.randint(0, 7) if r.random() < 0.9 else r.choice([0, 7, 8, 9])
    size_e = r.choice([1, 2, 3, 4, 6, 7, 8, 9, 16, 20])
    bobj0 = rnd(c, 0x88)
    bobj = bobj0 + r.choice([0, 0, 4])
    bk = r.choice([0, 0x1234, r.getrandbits(32)])
    e.w32(bobj + 0x50, bk)
    other = rnd(c, 0x80)
    e.w32(other + 0x50, bk if r.random() < 0.5 else bk ^ 0x10)
    cobj = rnd(c, 0x80)
    e.w32(cobj + 0x50, bk if r.random() < 0.7 else bk ^ 0x20)
    cval = (cobj - 0x70 + r.choice([0, 0, 4])) & 0xffffffff
    c2 = cval | d
    b2 = bobj | d
    bobj_pool = bobj & ~7

    def mkpair():
        x = r.random()
        if x < 0.2:
            return (c2 + 0x70) & 0xffffffff, r.getrandbits(32)             # key matches
        if x < 0.4:
            return (other & ~7) | d, (b2 - 0x70) & 0xffffffff               # value matches (object may differ)
        if x < 0.55:
            return (bobj & ~7) | d, (b2 - 0x70) & 0xffffffff
        if x < 0.7:
            return (other & ~7) | r.randint(0, 7), r.getrandbits(32)
        return ((other if r.random() < 0.5 else bobj) & ~7) | d, r.getrandbits(32)

    def node(npairs, link, extra_cap):
        n = npairs * 2 + (1 if link else 0)
        cap = n + extra_cap
        buf = rnd(c, 0x10 + 4 * (cap + 6))
        e.wbytes(buf + 9, bytes([cap]))
        e.wbytes(buf + 8, bytes([n]))
        return buf, n

    nnodes = r.choice([0, 0, 1, 1, 2, 3])
    a = 0
    nodes = []
    for _ in range(nnodes):
        npairs = r.choice([0, 1, 1, 2, 3])
        buf, n = node(npairs, len(nodes) > 0, r.choice([0, 0, 1, 2, 3]))
        nodes.append((buf, npairs))
    # link from node i to node i+1
    for i, (buf, npairs) in enumerate(nodes):
        has_link = i + 1 < len(nodes)
        n = npairs * 2 + (1 if has_link else 0)
        cap = max(n + r.choice([0, 0, 1, 2, 3]), n)
        e.wbytes(buf + 8, bytes([n]))
        e.wbytes(buf + 9, bytes([cap if cap < 250 else 250]))
        p = buf + 0xc
        if has_link:
            e.w32(p, nodes[i + 1][0])
            p += 4
        for _p in range(npairs):
            k, v = mkpair()
            e.w32(p, k & 0xffffffff)
            e.w32(p + 4, v & 0xffffffff)
            p += 8
    if nodes:
        a = nodes[0][0]
    ctx = rnd(c, 0x10)
    this = rnd(c, 0x10)
    e.w32(this, ctx)
    off = r.choice([0, 0, 8, 0x10])
    e.w32(this + 4, off)
    allocs = []

    def f4cd9b0(emu, k):
        buf = rnd(c, 0x40 + emu.arg32(0) + off)
        allocs.append(buf)
        return buf
    hook_rec(c, 0x4cd9b0, 2, this=True, ret=f4cd9b0)
    lobj = obj(c, 0x20, {0x2c: pystub(c, 3, ret=r.getrandbits(32), this=True)}, nslots=0x20)
    e.w32(0x70038c, 0 if r.random() < 0.3 else lobj)
    return [this, a, bobj, cval, d, size_e]


S(0x495950, 'tagged_pair_insert', 'thiscall', None, ret='eax', gen=g495950)
