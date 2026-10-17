"""specs_s246003.py - w4d batch 246003: 0x61dba0."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, pystub


def g61dba0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    A = rnd(c, 0x140)
    B = rnd(c, 0x20)
    Z = rnd(c, 0x10)
    em.w32(A + 0x124, Z)
    em.w32(A + 0x8c, B if r.random() < 0.5 else B + 0x20)
    if r.random() < 0.3:
        em.w32(A + 0x50, 0)
    C = rnd(c, 8)
    ES = rnd(c, 8)
    E = ES if r.random() < 0.6 else 0
    code = r.choice([-4, -3, -2, -1, 0, 1, 5, 42, 42, 42, 43, 44, -5, -100, 0x7fffffff, r.randrange(-6, 50)])
    outv = r.getrandbits(32)

    def s_fn(emu, k):
        emu.calllog.append(('cb', emu.arg32(0) - B, emu.arg32(1), emu.arg32(2)))
        emu.w32(emu.arg32(3), outv)
    em.w32(B + 0xc, pystub(c, 4, ret=code & 0xffffffff, pop=0, stackmark=(3,), side=s_fn))
    hook_rec(c, 0x620cb0, 4, ret=0, pop=0, side=lambda emu, k: None)
    return [A, B, C, r.getrandbits(32), E]


S(0x61dba0, 'GUESS FUN_61dba0', 'cdecl', None, ret='eax', gen=g61dba0, note='batch246003')


def g62b2f0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x180)
    BUF = rnd(c, 0x40)
    OUT = rnd(c, 8)
    pool = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 13, 14, 20, 21, 30, 29, 9, 5, 6, 7, 10, 11, 20, 21, 30, 29]
    em.wbytes(ENC + 0x4c, bytes(r.choice(pool) if r.random() < 0.8 else r.getrandbits(8) for _ in range(256)))
    n = r.choice([0, 1, 2, 3, 4, 6, 10, 20])
    data = bytes(r.getrandbits(8) for _ in range(n))
    tt = r.choice([12, 13, 12, 13, 5, 0, r.getrandbits(4)])
    tab = bytes(em.rbytes(ENC + 0x4c, 256))
    byc = lambda k: [i for i in range(256) if tab[i] == k]
    if n >= 2 and r.random() < 0.6:
        i = r.randrange(0, n - 1)
        a = byc(r.choice([12, 13]) if r.random() < 0.8 else tt)
        b = byc(r.choice([9, 10, 11, 20, 21, 29, 30, 8, 0, 1, 2, 12]))
        d = bytearray(data)
        if a and b:
            for j in range(i):
                d[j] = r.choice([x for x in range(256) if tab[x] in (2, 3, 4, 9, 10, 11)] or [0])
            d[i] = r.choice(a); d[i + 1] = r.choice(b)
            data = bytes(d)
            tt = tab[d[i]] if r.random() < 0.9 else tt
    em.wbytes(BUF, data)
    for off in (0x164, 0x168, 0x16c):
        def mk(off):
            def s(emu, k):
                emu.calllog.append(('cb', off, emu.arg32(0) - ENC, emu.arg32(1) - BUF))
            return pystub(c, 2, ret=lambda emu, k: r.choice([0, 0, 1]), pop=0, side=s)
        em.w32(ENC + off, mk(off))
    return [tt, ENC, BUF, BUF + n, OUT]


S(0x62b2f0, 'GUESS FUN_62b2f0', 'cdecl', None, ret='eax', gen=g62b2f0, note='batch246003')
