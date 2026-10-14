"""specs_s37088.py - cascade s6 batch 37088 (0x438910, thiscall(), plain ret). Iterator object at this+0x15 (slot 0x4c: 1 arg, slot 0x5c: yields scripted keys and writes the valid flag
through its pointer argument, slot 0 destructor). The entry's owner link (this+0xc) is tag 3 or tag 1; the owner's world has a bucket table (3 buckets of 10 bytes) of node lists
mixing matching nodes (payload this+4, first dword 0), nodes with other payloads and matching payloads whose first dword is non-zero."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g438910(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    t = rnd(c, 0x40)
    W = rnd(c, 0x1400)
    _w(c, W + 0x1208, r.randrange(0, 50))
    tbl = e.alloc(0x40, 4)
    e.wbytes(tbl, bytes(r.getrandbits(8) for _ in range(0x40)))
    _w(c, W + 0x1344, tbl)
    X = rnd(c, 0x30)
    _w(c, X + 0x11, W)
    if r.random() < 0.5:
        link = X + 4
        _w(c, link, 3)
    else:
        link = rnd(c, 0x20)
        _w(c, link, 1)
        _w(c, link + 8, X + 4)
    _w(c, t + 0xc, link)
    me = t + 4
    _w(c, me, r.choice([0, 0, 5]))
    others = []
    for _ in range(4):
        o = rnd(c, 0x10)
        _w(c, o, r.choice([0, 0, 7]))
        others.append(o)
    for b in range(3):
        head = 0
        nodes = []
        for _ in range(r.choice([0, 1, 2, 3, 5])):
            nd = rnd(c, 0x10)
            nodes.append(nd)
        for i, nd in enumerate(nodes):
            _w(c, nd, me if r.random() < 0.5 else r.choice(others))
            _w(c, nd + 5, nodes[i + 1] if i + 1 < len(nodes) else 0)
        _w(c, tbl + 10 * b + 4, nodes[0] if nodes else 0)
    script = [(r.randrange(0, 3), 1) for _ in range(r.choice([0, 1, 2, 3, 4]))] + [(r.randrange(0, 3), 0)]

    def nxt(em, k):
        key, fl = script[min(k, len(script) - 1)]
        _w(c, em.arg32(0), fl)
        return key
    seq = []

    def ret(em, k):
        key, fl = script[min(k, len(script) - 1)]
        return key

    def side(em, k):
        key, fl = script[min(k, len(script) - 1)]
        em.w32(em.arg32(0), fl)
    it = obj(c, 0x20, {0x0: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True, nullflag=(0,)),
                       0x5c: pystub(c, 1, this=True, nullflag=(0,), side=side, ret=ret)})
    if r.random() < 0.9:
        _w(c, t + 0x15, it)
    else:
        _w(c, t + 0x15, 0)
    return [t]


S(0x438910, 'GUESS drain_iterator_unlink', 'thiscall', None, ret=None, gen=_g438910, note='batch37088')
