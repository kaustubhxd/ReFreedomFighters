"""specs_s37087.py - cascade s6 batch 37087 (0x4fc500, thiscall(), returns object or 0). Ids come from a small pool; the table object's slot 0x58 resolves some of them to objects whose
slot 0x128 stub takes 3 arguments (first arg a word of this+0x64, < 0x200) or 2 (word of this+0x80, >= 0x200) and pops accordingly; slot 0x4c takes 2 arguments. Callee 0x4fd800
drops the front node of the id list (so the retry loop ends)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g4fc500(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    pool = [1, 2, 3, 4, 5, 6]
    present = {i for i in pool if r.random() < 0.6}
    idx78 = r.choice(pool)
    present.add(idx78)

    def mkres():
        F = rnd(c, 0x40)
        _w(c, F + 0x23, r.choice([0x400000, 0, 0xffffffff, 0x3fffff, 0x400001]))
        o = rnd(c, 0x20)
        _w(c, o + 0xc, F)

        def s128(em, res_):
            a0 = em.arg32(0)
            if a0 < 0x200:
                em.calllog.append(('128x3', o, a0, em.arg32(1), em.arg32(2)))
                em.ret(eax=0, argbytes=12)
            else:
                em.calllog.append(('128x2', o, a0, em.arg32(1)))
                em.ret(eax=0, argbytes=8)
        vt = e.alloc(0x200, 4)
        _w(c, vt + 0x128, e.stub_fn('128', s128))
        _w(c, o, vt)
        return o
    objs = {i: mkres() for i in present}
    so = sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: objs.get(em.arg32(0), 0)),
                                0x4c: pystub(c, 2, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0x60)
    t = rnd(c, 0x150)
    sv = e.alloc(0x40, 4)
    _w(c, sv + 0x14, pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 5])))
    selid = r.choice(pool + [0])
    _w(c, sv + 0x30, pystub(c, 1, this=True, ret=selid))
    _w(c, t + 0x98, sv)
    M = obj(c, 0x20, {0x12c: pystub(c, 3, this=True, stackmark=())})
    _w(c, t + 0x44, M)
    _w(c, t + 0x62, r.getrandbits(16), 2)
    _w(c, t + 0x64, r.randrange(0x100, 0x200), 2)
    _w(c, t + 0x80, r.randrange(0x200, 0x300), 2)
    _w(c, t + 0x74, r.choice(pool + [0, 0]))
    _w(c, t + 0x78, idx78)
    if r.random() < 0.75:
        N = rnd(c, 0x60)
        ids = [r.choice(pool) for _ in range(r.choice([0, 1, 2, 3, 5]))]
        nodes = []
        for i in ids:
            nd = rnd(c, 0x10)
            _w(c, nd, i)
            nodes.append(nd)
        _w(c, N + 0x48, nodes[0] if nodes else 0)

        def drop(em, k):
            _w(c, N + 0x48, nodes[k + 1] if k + 1 < len(nodes) else 0)
        hook_rec(c, 0x4fd800, 1, this=True, side=drop)
        _w(c, t + 0x84, N)
    else:
        hook_rec(c, 0x4fd800, 1, this=True)
        _w(c, t + 0x84, 0)
    return [t]


S(0x4fc500, 'GUESS rebind_selected', 'thiscall', None, ret='eax', gen=_g4fc500, note='batch37087')
