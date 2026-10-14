"""specs_s36069.py - cascade s4 batch 36069: 0x63b850 (append a value to a record's growing list), 0x64b2f0 (fetch or create a cached entry and flag it)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, stub_memmove


def _assert_hook(c):
    r = c.rng
    e = c.emu

    def ah(e2, res_):
        e2.calllog.append(('assert',))
        e2.ret(eax=r.getrandbits(32))
    e.w32(0x7003b0, e.stub_fn('assert hook', ah))
    e._image_dirty = True


def _g63b850(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    cnt = [0]

    def cpy(em, rr):
        d, s_, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.calllog.append(('memcpy', n))
        if n:
            em.wbytes(d, bytes(em.rbytes(s_, n)))
        em.ret(eax=d, argbytes=0)
    e.hook(0x634d22, cpy)
    hook_rec(c, 0x634273, 2, pop=0)
    wid = r.choice([0, 0x1, 0x2, 0x801, 0x1002, 0xffff])
    idx = wid & 0xfff
    nrec = 4
    tabarr = e.alloc(4 * 0x1000, 4)
    rec = rnd(c, 0x50)
    n = r.choice([0, 0, 1, 2, 3])
    e.wbytes(rec + 0x3d, bytes([n]))
    oldbuf = e.alloc(8 * 6, 4)
    e.wbytes(oldbuf, bytes(r.getrandbits(8) for _ in range(48)))
    e.w32(rec + 0x40, oldbuf)
    e.w32(tabarr + 4 * idx, rec)
    arrs = []
    nch = r.choice([0, 1, 2])
    childs = []
    for _ in range(nch):
        ch = e.alloc(0x10080, 16)
        ca = e.alloc(4 * 0x1000, 4)
        e.w32(ca + 4 * idx, r.choice([0, 1, 5]))
        e.w32(ch + 0x10071, ca)
        childs.append(ch)
    xs = [rnd(c, 0x20) for _ in range(3)]
    hook_rec(c, 0x64c7e0, 1, ret=lambda em, k, _x=xs: _x[min(k, 2)])
    newbuf = e.alloc(8 * 6 + 8, 4)
    e.wbytes(newbuf, bytes([0x5a]) * (8 * 6 + 8))
    d = obj(c, 0x120, {0x20: pystub(c, 1, this=True, ret=newbuf), 0x24: pystub(c, 2, this=True)})
    e.w32(d + 0x68, tabarr)
    e.w32(d + 0xec, nch)
    for i, ch in enumerate(childs):
        e.w32(d + 0xf0 + 4 * i, ch)
    so = sysobj(c)
    X = rnd(c, 0x40)
    e.w32(so + 0x1aa3, X)
    a = rnd(c, 0x80)
    e.wbytes(a + 0x5a, wid.to_bytes(2, 'little'))
    return [d, a, r.getrandbits(32)]


def _g64b2f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    _assert_hook(c)
    idx = r.choice([0, 1, 2, 3, 4, 5, 0x801, 0x803, 0xfff])
    tabarr = e.alloc(4 * 0x1000, 4)
    ent = rnd(c, 0x30)
    x = rnd(c, 0x30) if r.random() < 0.6 else 0
    e.w32(ent + 0x10, x)
    e.w32(ent + 8, rnd(c, 0x10))
    if x:
        e.w32(x + 0x18, r.getrandbits(32))
    use_e = r.random() < 0.85
    e.w32(tabarr + 4 * idx, ent if use_e else 0)
    a = r.choice([0, 8, 16])
    tb = e.alloc(0x40, 4)
    e.wbytes(tb, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.wbytes(tb + a + 4, (r.getrandbits(16)).to_bytes(2, 'little'))
    e.wbytes(tb + a + 6, (idx | (r.getrandbits(4) << 12)).to_bytes(2, 'little'))
    rv = r.getrandbits(32)
    M = obj(c, 0x40, {0x80: pystub(c, 1, this=True, ret=rv)})
    e.w32(M + 0x20, tb)
    so = sysobj(c)
    e.w32(so + 0x1aa3, M)
    qv = rv if r.random() < 0.5 else r.getrandbits(32)
    hook_rec(c, 0x658f10, 1, this=True, ret=qv)
    res = rnd(c, 0x30) if r.random() < 0.85 else 0
    hook_rec(c, 0x64b170, 2, this=True, ret=res)
    s = obj(c, 0x10080, {0x50: pystub(c, 1, this=True), 0x4c: pystub(c, 1, this=True, ret=r.choice([0, 1, 0x100]))})
    e.w32(s + 0x10071, tabarr)
    return [s, a, r.getrandbits(32), r.getrandbits(32)]


S(0x63b850, "GUESS append a value to a record's growing list", 'thiscall', None, ret=None, gen=_g63b850, note='batch36069')
S(0x64b2f0, 'GUESS fetch or create a cached entry and flag it', 'thiscall', None, ret='eax', gen=_g64b2f0, note='batch36069')
