"""specs_s37060.py - cascade s6 batch 37060 (0x444b90). Chain of tree nodes at this+0x48 (byte flags at +8, bit 0 = next sibling at +0xc, entries {lo, hi|tag} after the header); tag 2
entries append to the out array (limit 1..4 entries), tag 0 entries cover arrays of 0x70-byte structs whose +0x54 objects have slots 0x2a8 / 0x1e0 and an owner flags word at +0x3c.
Every spec tree contains a tag 2 entry in a node with flags >= 2 so the repeated passes terminate."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g444b90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def mkregion():
        if r.random() < 0.04:
            m = 0x102
            R = e.alloc(0x70 * m + 8, 8)
            P = rnd(c, 0x50)
            _w(c, P + 0x3c, 0)
            O = obj(c, 0x20, {0x2a8: pystub(c, 0, this=True, ret=0x10000), 0x1e0: pystub(c, 1, this=True, ret=0)})
            _w(c, O + 8, P)
            for i in range(m):
                _w(c, R + 0x70 * i + 0x54, O)
            return R, R + 0x70 * (m - 1)
        m = r.choice([1, 2, 3])
        R = e.alloc(0x70 * m + 8, 8)
        for i in range(m):
            P = rnd(c, 0x50)
            _w(c, P + 0x3c, r.choice([0, 0, 0x2c00, 0x10000000, 0x4, 0x800, 0x400, 0x2000]))
            O = obj(c, 0x20, {0x2a8: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0x10000, 0, 0, 0x30000])),
                              0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100]))})
            _w(c, O + 8, P)
            _w(c, R + 0x70 * i + 0x54, O)
        return R, R + 0x70 * (m - 1)

    def mknode(nxt, first_tag2):
        n_ent = r.choice([1, 2, 3])
        has_next = nxt != 0
        al = (2 * n_ent + (1 if has_next else 0))
        if not has_next and r.random() < 0.0:
            al = 2 * n_ent
        nd = e.alloc(0x10 + 8 * n_ent + 16, 8)
        e.wbytes(nd, bytes(0x10 + 8 * n_ent + 16))
        _w(c, nd + 8, al, 1)
        start = nd + (0x10 if has_next else 0xc)
        if has_next:
            _w(c, nd + 0xc, nxt)
        for i in range(n_ent):
            tag = 2 if (i == 0 and first_tag2) else r.choice([0, 0, 2, 1, 3, 4, 5, 6, 7])
            if tag == 0:
                lo, hi = mkregion()
                if r.random() < 0.15:
                    lo, hi = hi + 8, lo
            else:
                lo, hi = r.getrandbits(32) & ~7, r.getrandbits(32) & ~7
            _w(c, start + 8 * i, lo | r.getrandbits(3))
            _w(c, start + 8 * i + 4, hi | tag)
        return nd
    last = mknode(0, True)
    chain = last
    for _ in range(r.choice([0, 1, 2])):
        chain = mknode(chain, r.random() < 0.5)
    # sometimes a pass-through node (flags < 2) in front
    if r.random() < 0.25:
        pt = e.alloc(0x20, 8)
        e.wbytes(pt, bytes(0x20))
        _w(c, pt + 8, 1, 1)
        _w(c, pt + 0xc, chain)
        chain = pt
    me = rnd(c, 0x80)
    _w(c, me + 0x48, chain)
    out = e.alloc(0x100, 4)
    k = r.choice([0, 1, 2, 4, 7, 7])
    return [me, out, out + 8 * k]


S(0x444b90, 'GUESS collect entries from tree', 'thiscall', None, ret='eax', gen=_g444b90, note='batch37060')
