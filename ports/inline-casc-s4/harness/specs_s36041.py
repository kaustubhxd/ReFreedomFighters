"""specs_s36041.py - cascade s4 batch 36041: 0x6019b0 (find a record by name), 0x62da60 (token class by code), 0x427020 (release a library entry), 0x628b40 (parse a name through a callback), 0x620c00 (append a record and notify)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, reftab


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g6019b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    n = r.choice([0, 1, 2, 3, 5])
    found = r.choice([-1, -1, 0, 1, 2, 4])
    cn = [0]

    def sc(em, res):
        k = cn[0]
        cn[0] += 1
        em.calllog.append(('cmp', em.arg32(0), em.arg32(1)))
        em.ret(eax=(0 if k == found else r.choice([-1, 1, 0x100])), argbytes=0)
    e.stub_import('_stricmp', sc)
    arr = e.alloc(4 * max(n, 1), 4)
    for i in range(n):
        rec = rnd(c, 0x20)
        e.w32(rec, r.choice([0, 0, 0, 1, 5]))
        e.w32(rec + 0xc, rnd(c, 8))
        p1 = e.alloc(8, 4)
        e.w32(p1, rec)
        e.w32(arr + 4 * i, p1)
    sysobj(c, table_slots={0x58: pystub(c, 1, this=True, ret=lambda em, k: 0xcc000000 + k)})
    d = rnd(c, 0x20)
    e.w32(d + 4, arr)
    e.w32(d + 0xc, n)
    return [d, rnd(c, 8)]


def _g62da60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    vals = [r.choice([0, 0, 1, 0x100]), r.choice([0, 1, 5])]
    ob = obj(c, 0x40, {})
    e.w32(ob + 0x1c, pystub(c, 4, pop=0, ret=lambda em, k, _v=vals: _v[min(k, 1)]))
    p = rnd(c, 0x20)
    if r.random() < 0.5:
        e.w32(p + 0xc, 0)
    code = r.choice([0xf, 0x12, 0x12, 0x1b, 0x1c, 0x1c, 0x1d, 0, 0x11])
    return [p, code, r.getrandbits(32), r.getrandbits(32), ob]


def _g427020(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x634273, 2, pop=0)

    def fl(em, res):
        em.calllog.append(('FreeLibrary', em.arg32(0)))
        em.ret(eax=1, argbytes=4)
    e.stub_import('FreeLibrary', fl)
    key = r.getrandbits(32) | 1
    elems = []
    for _ in range(r.choice([0, 1, 2, 3])):
        el = rnd(c, 0x20)
        e.w32(el + 4, key if r.random() < 0.35 else r.getrandbits(32))
        e.w32(el + 8, r.choice([1, 1, 2, 0]))
        e.w32(el + 0xc, 0 if r.random() < 0.3 else obj(c, 0x20, {0x14: pystub(c, 1, this=True)}))
        e.w32(el + 0x10, 0 if r.random() < 0.3 else obj(c, 0x20, {0x14: pystub(c, 1, this=True)}))
        elems.append(el)
    lst = reftab(c, elems)
    d = rnd(c, 0x120)
    e.w32(d + 0x10c, lst if r.random() < 0.92 else 0)
    return [d, key]


def _g628b40(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cval = r.getrandbits(32)
    good = r.random() < 0.8
    text = bytes(r.randint(0x41, 0x5a) for _ in range(r.randint(0, 8)))

    def cb(em, rr):
        pl88, pl8c = em.arg32(1), em.arg32(3)
        cur = em.r32(pl8c)
        em.calllog.append(('cb', em.arg32(0), em.arg32(2), em.r32(pl88)))
        em.wbytes(cur, text + bytes(16 - len(text)))
        em.w32(pl8c, cur + len(text))
        em.w32(pl88, cval if good else cval ^ 1)
        em.ret(0, 0)
    ob = rnd(c, 0x60)
    e.w32(ob + 0x3c, e.stub_fn('cb', cb))
    e.w32(ob + 0x44, r.choice([2, 2, 0, 3]))
    hook_rec(c, 0x62c5b0, 2, pop=0, deref={0: -16}, ret=r.choice([0, 1, 5]))
    hook_rec(c, 0x628c10, 1, pop=0, deref={0: -16}, ret=r.choice([0xffffffff, 0, 1, 2, 3]))
    return [ob, r.getrandbits(32), cval]


def _g620c00(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    for addr, na, rv in ((0x620cb0, 4, 0), (0x620180, 4, r.choice([0, 1, 1, 1])), (0x6206e0, 1, r.choice([0, 1, 1])),
                         (0x6200d0, 1, 0), (0x6204a0, 1, 0)):
        hook_rec(c, addr, na, pop=0, ret=rv)
    a = rnd(c, 0x240)
    e.w32(a + 4, r.getrandbits(32))
    e.w32(a + 0x44, 0 if r.random() < 0.2 else pystub(c, 2, pop=0))
    e.w32(a + 0x50, r.choice([0, 1, 0x80]))
    buf = e.alloc(0x20, 4)
    e.wbytes(buf, bytes([0x55]) * 0x20)
    ed = a + 0x22c
    e.w32(ed + 8, buf if r.random() < 0.3 else buf + 8)
    e.w32(ed + 0xc, buf)
    e.w32(ed + 0x10, 0 if r.random() < 0.2 else r.getrandbits(32) | 1)
    b = rnd(c, 0x50)
    return [a, b, r.getrandbits(32), r.getrandbits(32)]


S(0x6019b0, 'GUESS find a record by name', 'thiscall', None, ret='eax', gen=_g6019b0, note='batch36041')
S(0x62da60, 'GUESS token class by code', 'cdecl', None, ret='eax', gen=_g62da60, note='batch36041')
S(0x427020, 'GUESS release a library entry', 'thiscall', None, ret='al', gen=_g427020, note='batch36041')
S(0x628b40, 'GUESS parse a name through a callback', 'cdecl', None, ret='eax', gen=_g628b40, note='batch36041')
S(0x620c00, 'GUESS append a record and notify', 'cdecl', None, ret='eax', gen=_g620c00, note='batch36041')
