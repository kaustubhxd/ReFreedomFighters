"""specs_s37003.py - cascade s6 batch 37003: 0x6204f0 (append string to a chunked buffer). Allocator object at [self+0x14]: slot 0 = alloc(size), slot 4 = realloc(ptr, size)
(both cdecl, return fresh spec memory; realloc copies the old chunk); 0x634d22 hooked (copies n bytes src -> dst)."""
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _g6204f0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=r.getrandbits(32)))))
    fail = r.random() < 0.08

    def alloc(em, k):
        if fail and r.random() < 0.5:
            return 0
        n = em.arg32(0)
        return rnd(c, min(n, 0x1000) + 8) if n < 0x1000 else rnd(c, 0x1000)

    def realloc(em, k):
        if fail and r.random() < 0.5:
            return 0
        p, n = em.arg32(0), em.arg32(1)
        q = rnd(c, n + 8)
        old = em.r32(p + 4) + 8
        em.wbytes(q, em.rbytes(p, min(old, n)))
        return q
    A = e.alloc(8, 4)
    e.w32(A, pystub(c, 1, pop=0, ret=alloc))
    e.w32(A + 4, pystub(c, 2, pop=0, ret=realloc))

    def cp(em, k):
        d, s, n = em.arg32(0), em.arg32(1), em.arg32(2)
        em.wbytes(d, em.rbytes(s, n))
    hook_rec(c, 0x634d22, 3, pop=0, side=cp)
    me = rnd(c, 0x20)
    form = r.choice(['fresh', 'chunk', 'chunk', 'spare', 'spare0', 'spareswap', 'mid', 'big'])
    cap = r.choice([4, 8, 16, 24, 48])
    if form == 'big':
        cap = r.choice([0x3f8, 0x400, 0x401, 0x500])
    for i in range(6):
        e.w32(me + 4 * i, 0)
    e.w32(me + 0x14, A)
    if form != 'fresh':
        C = rnd(c, cap + 8 + 8)
        e.w32(C, 0)
        e.w32(C + 4, cap)
        e.w32(me, C)
        end = C + 8 + cap
        if form == 'mid':
            start = C + 8
            cur = start + r.randint(0, cap - 1)
            e.w32(me + 0x10, start)
            e.w32(me + 0xc, cur)
            e.w32(me + 8, end)
        else:
            k = r.choice([0, 0, 0, 1, 3]) if cap > 4 else 0
            if form == 'big':
                k = r.choice([0, 1, 4, 8])
            start = C + 8 + k
            e.w32(me + 0x10, start)
            e.w32(me + 0xc, end)
            e.w32(me + 8, end)
            if form in ('spare', 'spareswap'):
                cap2 = (end - start) + (r.randint(1, 9) if form == 'spareswap' else r.choice([0, -1, -3]) if end - start > 3 else 0)
                cap2 = max(cap2, 1) if form == 'spareswap' else max(cap2, 0)
                S2 = rnd(c, cap2 + 24)
                e.w32(S2, r.choice([0, S2 + 8]) if False else 0)
                e.w32(S2 + 4, cap2)
                e.w32(me + 4, S2)
            elif form == 'spare0':
                e.w32(me + 0x10, 0)
                S2 = rnd(c, 0x40)
                e.w32(S2, 0)
                e.w32(S2 + 4, r.choice([4, 16, 0x20]))
                e.w32(me + 4, S2)
    n = r.choice([0, 1, 2, 5, 12, 30, 40])
    s = rnd(c, n + 1)
    e.wbytes(s, bytes(r.randint(1, 255) for _ in range(n)) + b'\0')
    return [me, s]


S(0x6204f0, 'GUESS append string to chunked buffer', 'cdecl', None, ret='eax', gen=_g6204f0, note='batch37003')
