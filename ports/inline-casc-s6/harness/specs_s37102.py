"""specs_s37102.py - cascade s6 batch 37102 (0x5fe080, thiscall(map) ret 4). The object has an optional child (+0x9c, a trivial object so the recursion ends at once), a table
(+0xa0 base id, +0xa8 count, +0xac array, +0xb0 offset) and an {id, id2} array (+0xbc, count +0xb8). The global at 0x724278 holds an object whose +0x3c points at a key-mapping
object (slot 0: arg -> random 16-bit key). `map` is a small BST (header +0 -> root, nodes: left +5, right +9, key word +0xd, value +0xf); 0x600540 (insert) is a hook that
writes a fresh pool node through its out pointer. When there is no child the table path is forced (the original leaves a stack slot unset otherwise)."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g5fe080(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    keys = [10, 20, 30, 40]
    sel = r.sample(keys, r.choice([0, 1, 2, 3, 4]))
    sel.sort()
    nodes = [rnd(c, 0x20) for _ in sel]

    def build(lo, hi, parent):
        if lo >= hi:
            return 0
        m = r.randrange(lo, hi)
        nd = nodes[m]
        _w(c, nd + 1, parent)
        _w(c, nd + 0xd, sel[m], 2)
        _w(c, nd + 5, build(lo, m, nd))
        _w(c, nd + 9, build(m + 1, hi, nd))
        return nd
    hdr = rnd(c, 0x20)
    root = build(0, len(sel), hdr)
    _w(c, hdr + 1, root)
    _w(c, hdr + 0xd, 0, 2)
    mp = rnd(c, 0x20)
    _w(c, mp, hdr)
    pool = [rnd(c, 0x20) for _ in range(6)]

    def ins(em, k):
        em.w32(em.arg32(0), pool[k % 6])
        key = int.from_bytes(em.rbytes(em.arg32(2), 2), 'little')
        _w(c, pool[k % 6] + 0xd, key, 2)
    hook_rec(c, 0x600540, 3, this=True, nullflag=(0,), stackmark=(1,), deref={2: -6}, side=ins)
    hook_rec(c, 0x5ffb00, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x5ffe20, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    kmap = obj(c, 0x20, {0x0: pystub(c, 1, this=True, ret=lambda em, k: r.choice(keys + [5, 15]) | (r.getrandbits(16) << 16))})
    G = rnd(c, 0x80)
    _w(c, G + 0x3c, kmap)
    _w(c, 0x724278, G)
    def mkobj(child_obj):
        o = rnd(c, 0x100)
        _w(c, o + 0x9c, child_obj)
        n = r.choice([0, 1, 2, 3, 4])
        arr = e.alloc(4 * 5 + 4, 4)
        for i in range(n):
            _w(c, arr + 4 * i, r.choice([0, 1, 2, 3, 4, 5, 6, 0x10001]), 2)
            _w(c, arr + 4 * i + 2, r.getrandbits(16), 2)
        _w(c, o + 0xb8, n)
        _w(c, o + 0xbc, arr)
        if child_obj:
            cntA = r.choice([0, 0, 2, 3, 4])
            base = r.choice([0, 1, 2, 3])
        else:
            cntA = r.choice([2, 3, 4])
            base = 0
        tbl = e.alloc(0x40, 4)
        e.wbytes(tbl, bytes(r.getrandbits(8) for _ in range(0x40)))
        _w(c, o + 0xa8, cntA)
        _w(c, o + 0xa0, base)
        _w(c, o + 0xac, tbl)
        _w(c, o + 0xb0, r.getrandbits(32))
        return o
    leaf = mkobj(0)
    mid = mkobj(leaf) if r.random() < 0.3 else leaf
    this = mkobj(mid) if r.random() < 0.7 else mkobj(0)
    return [this, mp]


S(0x5fe080, 'GUESS fill_map_nodes', 'thiscall', None, ret=None, gen=_g5fe080, note='batch37102')
