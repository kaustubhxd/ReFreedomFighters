"""specs_s37058.py - cascade s6 batch 37058 (0x49db30). Allocator at 0x70038c (slot 0xcc: id -> record or 0, deterministic per id), this slot 0xc (record -> small key so ties form
groups), table slot 0x58; records carry +0x1c / +0x20 / +0x40 and objects a word at +0x1d. The parallel quicksort 0x4e69b0 runs as original code."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g49db30(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    n = r.choice([0, 1, 2, 3, 5, 7])
    ids = [r.randint(1, 0xffff) for _ in range(n)]
    base = e.alloc(0x40 + 4 * n, 4)
    for i, v in enumerate(ids):
        e.w32(base + 4 * i, v)

    def mkobj2():
        o = rnd(c, 0x40)
        _w(c, o + 0x1d, r.choice([0, 1, 2, 0x7ff, 0xffff, r.getrandbits(16)]), 2)
        return o
    tabids = {t: (obj(c, 0x20, {}) if False else None) for t in []}
    tmap = {}

    def mkrec():
        R = rnd(c, 0x60)
        t = r.choice([0, 0, 0x91, 0x92, 0x93])
        _w(c, R + 0x1c, t)
        _w(c, R + 0x20, r.getrandbits(r.choice([8, 16, 20])))
        _w(c, R + 0x40, mkobj2())
        if t and t not in tmap:
            holder = rnd(c, 0x20)
            _w(c, holder + 0xc, mkobj2())
            tmap[t] = holder if r.random() < 0.8 else 0
        return R
    recs = {i: (mkrec() if r.random() < 0.75 else 0) for i in set(ids)}
    keymap = {}
    g = obj(c, 0x20, {0xcc: pystub(c, 1, this=True, ret=lambda em, k: recs.get(em.arg32(0), 0))})
    e.w32(0x70038c, g)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: tmap.get(em.arg32(0), 0))}, table_size=0x20)

    def keyfn(em, k):
        a = em.arg32(0)
        if a not in keymap:
            keymap[a] = r.choice([1, 1, 2, 3, 3])
        return keymap[a]
    me = obj(c, 0x40, {0xc: pystub(c, 1, this=True, ret=keyfn)})
    _w(c, me + 8, base)
    _w(c, me + 0x14, n)
    return [me]


S(0x49db30, 'GUESS filter and sort id array', 'thiscall', None, ret=None, gen=_g49db30, note='batch37058')
