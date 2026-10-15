"""specs_s67533.py - cascade s6 batch 67533 (0x45bba0, thiscall() plain ret, return value unused). sys[0x1aa3] holds the object manager at +0x18 (slots 0x60 / 0xe4, 2 args each) and slot 0x80
(1 arg); sys[0x9b] slot 0x160 returns table objects; the string compare at 0x676414 is a cdecl recorder; the logger at 0x700390 has slot 0x20 returning an object whose cdecl slot 0x2c logs
(3 args for fmt 0x684c78, 2 for 0x684c24)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g45bba0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu

    def cmp(em, res_):
        a0, a1 = em.arg32(0), em.arg32(1)
        em.calllog.append(('cmp', a0, a1))
        em.ret(eax=r.choice([0, 0, 1, 9]), argbytes=0)
    e.w32(0x676414, e.stub_fn('recorder', cmp))

    def lg2c(em, res_):
        f = em.arg32(1)
        n = 2 if f == 0x684c78 else 1
        em.calllog.append(('log', tuple(em.arg32(i) for i in range(1, n + 1))))
        em.ret(eax=0, argbytes=0)
    y = obj(c, 0x20, {0x2c: e.stub_fn('recorder', lg2c)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=y)}))
    objs = [rnd(c, 0x20) for _ in range(3)]
    recs = [rnd(c, 0x20) for _ in range(2)]
    r3s = [rnd(c, 0x50) for _ in range(2)]
    tabs = [rnd(c, 0x50) for _ in range(2)]
    mgr = obj(c, 0x20, {0x60: pystub(c, 2, this=True, ret=lambda em, k: r.choice(objs + objs + [0] if k > 0 else objs)),
                        0xe4: pystub(c, 2, this=True, ret=lambda em, k: r.choice(recs + [0]))})
    p = obj(c, 0x40, {0x80: pystub(c, 1, this=True, ret=lambda em, k: r.choice(r3s + [0]))})
    _w(c, p + 0x18, mgr)
    so = sysobj(c, table_slots={0x160: pystub(c, 1, this=True, ret=lambda em, k: r.choice(tabs + [0]))}, table_size=0x180)
    _w(c, so + 0x1aa3, p)
    n = r.choice([0, 1, 2, 3, 4])
    arr = e.alloc(0x40, 4)
    e.wbytes(arr, bytes(0x40))
    holder = rnd(c, 0x80)
    t = rnd(c, 0x300)
    _w(c, t + 4, r.choice([0, rnd(c, 0x10)]))
    _w(c, t + 8, holder)
    _w(c, t + 0x20, n)
    _w(c, t + 0x254, arr)
    return [t]


S(0x45bba0, 'GUESS bind_objects_to_table', 'thiscall', None, ret=None, gen=_g45bba0, note='batch67533')
