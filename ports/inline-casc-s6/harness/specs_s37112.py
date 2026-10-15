"""specs_s37112.py - cascade s6 batch 37112 (0x551e60, stdcall(a) ret 4). Hooked 0x5003d0 (first call: id node; later calls: the result node), 0x5002f0, 0x4db9a0; the object
(table slot 0x58) answers slot 0x1e0 and slot 0x50 (writes the next record through its out pointer); records point at linked records whose flag word has bit 10 set or not."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g551e60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))

    def lg(em, res_):
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(2 if em.arg32(1) == 0x6a5b28 else 3))))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    recs = []
    for _ in range(r.choice([0, 1, 2, 3, 4, 6])):
        cur = rnd(c, 0x60)
        _w(c, cur + 0x54, obj(c, 0x20, {0x438: pystub(c, 0, this=True, ret=lambda em, k: r.choice([0, 0, 1, 0x100, 0x101]))}))
        if True:
            X = rnd(c, 0x60)
            Y = rnd(c, 0x20)
            Z = rnd(c, 0x50)
            _w(c, Z + 0x3c, r.choice([0, 0x400, 0xffffffff, 0x3ff, 0x800, r.getrandbits(32)]))
            _w(c, Y + 8, Z)
            _w(c, X + 0x54, Y)
            _w(c, cur + 0x50, X)
        else:
            _w(c, cur + 0x50, 0)
        recs.append(cur)
    first = recs[0] if recs else 0
    nxt = recs[1:] + [0]

    def s50(em, k):
        em.w32(em.arg32(0), nxt[k] if k < len(nxt) else 0)
    ob = obj(c, 0x40, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1, 0x100])),
                       0x50: pystub(c, 1, this=True, stackmark=(0,), side=s50)})
    _w(c, ob + 8, first)
    idnode = rnd(c, 0x10)
    ident = r.choice([5, 6])
    _w(c, idnode, ident)
    found = ob if r.random() < 0.85 else 0
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: found)}, table_size=0x60)
    res = rnd(c, 0x10)
    _w(c, res + 4, r.choice([0, 1, 1, 0, 2, 5, 0xff]), 1)
    hook_rec(c, 0x5003d0, 1, this=True, ret=lambda em, k: idnode if k == 0 else res)
    hook_rec(c, 0x5002f0, 1, this=True, ret=lambda em, k: r.getrandbits(32))
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1, 0x100, 0x101]))
    a = rnd(c, 0x10)
    _w(c, a + 4, rnd(c, 0x10))
    _w(c, a + 8, rnd(c, 0x10))
    return [a]


S(0x551e60, 'GUESS count_records', 'stdcall', None, ret=None, gen=_g551e60, note='batch37112')
