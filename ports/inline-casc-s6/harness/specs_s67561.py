"""specs_s67561.py - cascade s6 batch 67561 (0x4449e0, thiscall(out, end) ret 8, returns the cursor in eax). this[0xa8] is a list object (sometimes 0) with slots 0x4c (writes the first iterator value)
and 0x5c (returns the next node, writes the following iterator value; stack-marked pointer); nodes have type blocks (+0x54 -> +0xc -> +0x23: bit 0x800000 stored, 0x100000 expandable) and expandable
ones a sub-record with slot 0x2a8 (flags) / 0x50 (child iterator) / +8 first child. The output array has room for 0..6 pointers."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4449e0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def mk_type():
        tb = rnd(c, 0x40)
        t = r.choice([0x800000, 0x800001, 0x900000, 0, 0x200002, 0x400000, 1, 0x200003])
        _w(c, tb + 0x23, t)
        return tb

    def mk_node(allow_sub=True):
        n = rnd(c, 0x70)
        if r.random() < 0.15:
            _w(c, n + 0x54, 0)           # type 0x200002: neither bit
            return n
        if allow_sub and r.random() < 0.45:
            kids = [mk_node(False) for _ in range(r.choice([0, 1, 2, 3]))]
            nxt = kids[1:] + [0]

            def s50(em, k, nxt=nxt):
                em.wbytes(em.arg32(0), (nxt[k] if k < len(nxt) else 0).to_bytes(4, 'little'))
            sub = obj(c, 0x20, {0x2a8: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0x10000, 0x30000, 1])),
                                0x50: pystub(c, 1, this=True, stackmark=(0,), side=s50)})
            _w(c, sub + 0xc, rnd(c, 0x40))
            _w(c, int.from_bytes(e.rbytes(sub + 0xc, 4), 'little') + 0x23, r.choice([0x100000, 0x100000, 0x900000]))
            _w(c, sub + 8, kids[0] if kids else 0)
            _w(c, n + 0x54, sub)
            return n
        sub = rnd(c, 0x40)
        _w(c, sub + 0xc, mk_type())
        _w(c, n + 0x54, sub)
        return n
    nodes = [mk_node() for _ in range(r.choice([0, 1, 2, 3, 4]))]
    its = [1] * len(nodes) + [0]

    def s4c(em, k):
        em.wbytes(em.arg32(0), its[0].to_bytes(4, 'little'))

    def s5c(em, k):
        em.wbytes(em.arg32(0), its[k + 1 if k + 1 < len(its) else len(its) - 1].to_bytes(4, 'little'))
    lst = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, stackmark=(0,), side=s4c),
                        0x5c: pystub(c, 1, this=True, stackmark=(0,), side=s5c,
                                     ret=lambda em, k: nodes[k] if k < len(nodes) else 0)})
    t = rnd(c, 0xc0)
    _w(c, t + 0xa8, lst if r.random() < 0.9 else 0)
    m = r.choice([0, 1, 2, 3, 6])
    out = e.alloc(0x60, 4)
    e.wbytes(out, bytes(0x60))
    return [t, out, out + 4 * m]


S(0x4449e0, 'GUESS collect_visible_nodes', 'thiscall', None, ret='eax', gen=_g4449e0, note='batch67561')
