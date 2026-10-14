"""specs_s47001.py - cascade t8 batch 47001: 0x41f550 (swap two keys in a hash table), 0x434e20 (create each directory level of a path)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g41f550(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    a = rnd(c, 0x40) + 0x10
    b = rnd(c, 0x40) + 0x10
    for p in (a, b):
        if r.random() < 0.3:
            e.w32(p - 4, 0)
    bnd = [0, a, a + 1, b, b + 1, 0xffffffff, a + 0x20]
    lo = r.choice(bnd)
    hi = r.choice(bnd)
    ctx = obj(c, 0x40, {0x20: pystub(c, 1, this=True, ret=lambda em, k: r.choice([0, 0, 0, 1, 5])),
                        0xac: pystub(c, 1, this=True, side=lambda em, k: em.w32(em.arg32(0) - 4, r.getrandbits(32)))})
    cb = pystub(c, 0, this=True, ret=lambda em, k: r.getrandbits(32))
    e.w32(ctx + 8, cb if r.random() < 0.7 else 0)
    e.w32(ctx + 0xc, lo)
    e.w32(ctx + 0x10, hi)
    e.w32(0x70038c, ctx)
    t = rnd(c, 0x20)
    e.w32(t + 0x10, r.choice([0, 3, 7, 15, 0x1f, 0xffffffff & 0x3f]))
    tab = rnd(c, 0x100)
    me = rnd(c, 0x40)
    e.w32(me + 4, t)
    e.w32(me + 0x28, tab)
    hook_rec(c, 0x41f190, 1, this=True)
    return [me, a if r.random() > 0.05 else b, b]


def _g434e20(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    n = r.choice([1, 2, 3, 5, 8, 12, 20])
    s = bytes(r.choice(b'ab/\\c:.') for _ in range(n))
    path = e.alloc(0x80, 4)
    e.wbytes(path, s + b'\0' + bytes(r.getrandbits(8) for _ in range(0x70 - n)))
    buf = rnd(c, 0x100)
    hook_rec(c, 0x41e290, 1, ret=buf, pop=0)
    hook_rec(c, 0x634273, 2, pop=0)

    def pb(em, rr):
        s_, set_ = em.arg32(0), em.arg32(1)
        b = em.rbytes(s_, 0x40)
        i = 0
        res = 0
        while i < 0x40 and b[i]:
            if b[i] in (0x2f, 0x5c):
                res = s_ + i
                break
            i += 1
        em.calllog.append(('strpbrk', res - s_ if res else 0))
        em.ret(eax=res, argbytes=0)
    e.stub_import('strpbrk', pb)
    me = obj(c, 0x20, {0x4c: pystub(c, 1, this=True, deref={0: -0x40})})
    return [me, path]


S(0x41f550, 'GUESS swap two keys in hash table', 'thiscall', None, ret=None, gen=_g41f550, note='batch47001')
S(0x434e20, 'GUESS make each directory level of path', 'thiscall', None, ret=None, gen=_g434e20, note='batch47001')
