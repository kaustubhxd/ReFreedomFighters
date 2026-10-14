"""specs_s37101.py - cascade s6 batch 37101 (0x535300, thiscall(list) ret 4). The list object (slots 0x4c / 0x5c with an out flag) yields n keys (n up to 0x45 to reach the 0x41 cap);
table slot 0x60 returns entity blocks; the window object at +0x1a9f has slots 0x54 and 0x1dc (window or 0); this slots 0x184 / 0x1e8; logger at 0x700390. Records come from a
pool whose +4 field is the record size."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _w(c, a, v, n=4):
    c.emu.wbytes(a, (v & ((1 << (8 * n)) - 1)).to_bytes(n, 'little'))


def _g535300(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    if r.random() < 0.05:
        t = obj(c, 0x51c0, {})
        return [t, 0]

    def lg(em, res_):
        em.calllog.append(('log', em.arg32(0), em.arg32(1), em.arg32(2)))
        em.ret(eax=0, argbytes=0)
    Lg = obj(c, 0x20, {0x2c: e.stub_fn('log', lg)})
    e.w32(0x700390, obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=Lg)}))
    ents = []
    for _ in range(4):
        en = rnd(c, 0xe0)
        _w(c, en + 4, r.choice([5, 1, 2, 5]))
        _w(c, en + 0x8c, r.choice([0xffffffff, 0, 1, 5]))
        ents.append(en)
    wins = []
    for _ in range(4):
        w = rnd(c, 0x20)
        _w(c, w + 8, r.choice([0, 1, 2, 3, 0xfffffffe, 0xffffffff, 0x100]))
        wins.append(w)
    n = r.choice([0, 1, 2, 3, 5, 0x41, 0x45]) if r.random() < 0.9 else r.randrange(0, 8)
    keys = [r.getrandbits(32) for _ in range(n + 2)]

    def s5c(em, k):
        em.w32(em.arg32(0), 1 if k < n else 0)
    list_ = obj(c, 0x40, {0x4c: pystub(c, 1, this=True, nullflag=(0,)), 0x5c: pystub(c, 1, this=True, nullflag=(0,), side=s5c, ret=lambda em, k: keys[min(k, len(keys) - 1)])})
    sysobj(c, table_slots={0x60: pystub(c, 1, this=True, ret=lambda em, k: ents[k % 4])}, table_size=0x70)
    so = e.r32(0x70039c)
    win = obj(c, 0x200, {0x54: pystub(c, 1, this=True, ret=lambda em, k: r.randrange(0, 4)),
                         0x1dc: pystub(c, 1, this=True, ret=lambda em, k: wins[em.arg32(0)] if r.random() < 0.8 else 0)})
    _w(c, so + 0x1a9f, win)
    pool = e.alloc(0x40 * 80, 4)
    e.wbytes(pool, bytes(r.getrandbits(8) for _ in range(0x40 * 80)))
    for i in range(80):
        _w(c, pool + 0x40 * i + 4, 0x40)
    t = obj(c, 0x51c0, {0x184: pystub(c, 2, this=True), 0x1e8: pystub(c, 1, this=True, ret=lambda em, k: r.getrandbits(32))})
    _w(c, t + 0x51a9, pool)
    return [t, list_]


S(0x535300, 'GUESS drain_key_list', 'thiscall', None, ret=None, gen=_g535300, note='batch37101')
