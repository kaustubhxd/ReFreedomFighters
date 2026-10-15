"""specs_s37123.py - cascade s6 batch 37123 (0x471680, thiscall(), plain ret). Owner O (slots 0x1e0, 0x2e8 -> X, 0x320, 0x80 writing the two stack records), X (slot 0x2c4,
2 args -> W or 0), W (slots 0x1e0 / 0x364 / 0x360 / 0x324 / 0x2f0 / 0x300 / 0x7c logging the records), table object (slot 0x4c, field +0xadc), this slot 0x68, the global at
0x7003b8 and the 0x46abf0 hook."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g471680(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    so = sysobj(c, table_slots={0x4c: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))}, table_size=0xb00)
    tab = int.from_bytes(e.rbytes(so + 0x9b, 4), 'little')
    _w(c, tab + 0xadc, r.getrandbits(32))
    kind = r.choice([0x1007d2, 0x1007d8, 0, 0x1007d2])
    yes = lambda em, k: r.choice([0, 1, 0x100, 0x101]) if False else None

    def w1e0(em, k):
        return 1 if em.arg32(0) == kind else 0

    def s80(em, k):
        em.wbytes(em.arg32(0), bytes(r.getrandbits(8) for _ in range(0x24)))
        em.wbytes(em.arg32(1), bytes(r.getrandbits(8) for _ in range(0xc)))

    def s7c(em, k):
        em.calllog.append(('7c', em.rbytes(em.arg32(0), 0x24), em.rbytes(em.arg32(1), 0xc)))
    W = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=w1e0), 0x364: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)),
                      0x360: pystub(c, 1, this=True), 0x324: pystub(c, 1, this=True), 0x2f0: pystub(c, 3, this=True), 0x300: pystub(c, 1, this=True),
                      0x7c: pystub(c, 2, this=True, stackmark=(0, 1), side=s7c)})
    X = obj(c, 0x20, {0x2c4: pystub(c, 2, this=True, ret=lambda em, k: W if r.random() < 0.9 else 0)})
    ok1 = r.random() < 0.9
    O = obj(c, 0x20, {0x1e0: pystub(c, 1, this=True, ret=lambda em, k: 1 if ok1 else 0), 0x2e8: pystub(c, 0, this=True, ret=lambda em, k: X if r.random() < 0.9 else 0),
                      0x320: pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32)), 0x80: pystub(c, 2, this=True, stackmark=(0, 1), side=s80)})
    this = obj(c, 0x60, {0x68: pystub(c, 2, this=True)})
    _w(c, this + 0x44, O)
    _w(c, this + 0x52, r.choice([0, 0, 0, 5]))
    g = rnd(c, 0x20)
    _w(c, 0x7003b8, g)
    hook_rec(c, 0x46abf0, 1, this=True)
    return [this]


S(0x471680, 'GUESS create_companion', 'thiscall', None, ret=None, gen=_g471680, note='batch37123')
