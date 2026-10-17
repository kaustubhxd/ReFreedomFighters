"""specs_s232002.py - Sonnet-w3f hand specs."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
def g51f3e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x1700
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(5)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def rel(emu):
        ec = emu.reg('ecx')
        return ec - T if T <= ec < T + TS else -1
    VT = c.emu.alloc(0x20, 4)
    def sv(emu, k, _s=mkside(0)):
        emu.calllog.append(('v0', rel(emu), [emu.arg32(i) for i in range(3)]))
        _s(emu, k)
    c.emu.w32(VT, pystub(c, 3, ret=rnd32, pop=12, this=True, side=sv))
    def s5273(emu, k, _s=mkside(1)):
        emu.calllog.append(('ctor', rel(emu)))
        emu.w32(emu.reg('ecx'), VT)
        _s(emu, k)
    hook_rec(c, 0x5273b0, 0, ret=rnd32, pop=0, this=True, side=s5273)
    hook_rec(c, 0x511c60, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('c60', rel(emu))), _s(emu, k)))
    def s7050(emu, k, _s=mkside(3)):
        emu.calllog.append(('base', rel(emu), [emu.arg32(i) for i in range(3)]))
        _s(emu, k)
    hook_rec(c, 0x517050, 3, ret=rnd32, pop=12, this=True, side=s7050)
    return [T, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x51f3e0, 'GUESS hand 0x51f3e0', 'thiscall', None, ret='eax', gen=g51f3e0, note='batch232002')


def g4cbf30(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x120)
    H0 = rnd(c, 0x40)
    c.emu.w32(T, T + 4 if r.random() < 0.5 else H0)
    heaps = [H0]
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x40))))
            sr[j](emu, k)
        return side
    def cstr(emu, a):
        b = emu.rbytes(a, 24)
        return b.split(b'\0')[0].hex()
    nul = r.random() < 0.2
    def s_itoa(emu, k, _s=mkside(0)):
        emu.calllog.append(('itoa', emu.arg32(0), emu.arg32(2)))
        txt = str(int(emu.arg32(0)) - (1 << 32) if emu.arg32(0) >= 1 << 31 else int(emu.arg32(0))).encode() + b'\0'
        emu.wbytes(emu.arg32(1), txt)
        _s(emu, k)
    c.emu.w32(0x6762d0, pystub(c, 3, pop=0, this=False, stackmark=(1,), ret=lambda emu, k: 0 if nul else emu.arg32(1), side=s_itoa))
    def s630(emu, k, _s=mkside(1)):
        obj = emu.reg('ecx'); src = emu.arg32(0)
        txt = emu.rbytes(src, 24).split(b'\0')[0] + b'\0'
        isT = (obj == T)
        emu.calllog.append(('asg', isT, txt.hex()))
        if r.random() < 0.5: nb = obj + 4
        else:
            nb = rnd(c, 0x40); heaps.append(nb)
        emu.wbytes(nb, txt)
        emu.w32(obj, nb)
        _s(emu, k)
    hook_rec(c, 0x4cc630, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=s630)
    def s273(emu, k, _s=mkside(2)):
        a = emu.arg32(0)
        emu.calllog.append(('free', heaps.index(a) if a in heaps else -1, emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=s273)
    return [T, r.choice([0, 1, 9, 10, 12345, 0xffffffff, 0x80000000, r.getrandbits(32)])]


S(0x4cbf30, 'GUESS hand 0x4cbf30', 'thiscall', None, ret='eax', gen=g4cbf30, note='batch232002')


def g600d70(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x10)
    NODE = rnd(c, 0x20)
    BUF = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 5, 7, 8, 9, 12])
    cs = rnd(c, 0x20)
    c.emu.wbytes(cs, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(this, 0x10)), zlib.crc32(emu.rbytes(NODE, 0x18))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NODE, pop=0, this=False, side=mkside(0))
    def s14a0(emu, k, _s=mkside(1)):
        emu.calllog.append(('f14a0', emu.reg('ecx') - NODE, emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x6014a0, 1, ret=lambda emu, k: BUF, pop=4, this=True, side=s14a0)
    def s2d60(emu, k, _s=mkside(2)):
        a, b = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('f2d60', emu.reg('ecx') - NODE, a == cs, b - a, emu.rbytes(a, b - a).hex()))
        _s(emu, k)
    hook_rec(c, 0x5f2d60, 2, ret=rnd32, pop=8, this=True, side=s2d60)
    return [this, cs, r.getrandbits(32)]


S(0x600d70, 'GUESS hand 0x600d70', 'thiscall', None, ret='eax', gen=g600d70, note='batch232003')


def g5fb110(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    M = rnd(c, 0x20)
    END = rnd(c, 0x40); c.emu.w32(M, END)
    def mkstr(n):
        b = rnd(c, 0x20)
        c.emu.wbytes(b, bytes(r.choice(b'ab') for _ in range(n)) + b'\0')
        return b
    def mkkey(n):
        s = rnd(c, 0x10); b = mkstr(n)
        c.emu.w32(s, b); c.emu.w32(s + 4, b + n); c.emu.w32(s + 8, b + n + 4)
        return s, b
    K, kb = mkkey(r.choice([0, 1, 2, 3, 5]))
    nodes = []
    for _ in range(2):
        nd = rnd(c, 0x60); nbuf = mkstr(r.choice([0, 1, 2, 3, 5]))
        ln = r.choice([0, 1, 2, 3, 5])
        c.emu.w32(nd + 0xd, nbuf); c.emu.w32(nd + 0x11, nbuf + ln)
        nodes.append(nd)
    where = r.choice(['end', 0, 1, 1])
    NEWN = rnd(c, 0x60)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(M, 8))))
            sr[j](emu, k)
        return side
    def s_cc40(emu, k, _s=mkside(0)):
        emu.w32(emu.arg32(0), END if where == 'end' else nodes[where])
        emu.calllog.append(('cc40', emu.reg('ecx') == M, emu.arg32(1) == K))
        _s(emu, k)
    hook_rec(c, 0x5fcc40, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, stackmark=(0,), side=s_cc40)
    def s_cmp(emu, k, _s=mkside(1)):
        a, b, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('cmp', a == kb, n))
        _s(emu, k)
    def r_cmp(emu, k):
        a, b, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        x, y = emu.rbytes(a, n), emu.rbytes(b, n)
        return 0 if x == y else (0xffffffff if x < y else 1) if r.random() < 0.7 else (r.getrandbits(31) | (0x80000000 if x < y else 0))
    c.emu.w32(0x676408, pystub(c, 3, pop=0, this=False, ret=r_cmp, side=s_cmp))
    blocks = []
    def s_10c0(emu, k, _s=mkside(2)):
        t = emu.reg('ecx'); src = emu.arg32(0)
        kbg, keg = emu.r32(src), emu.r32(src + 4)
        txt = emu.rbytes(kbg, keg - kbg)
        b = rnd(c, 0x20); blocks.append(b)
        emu.wbytes(b, txt)
        z = r.random()
        emu.w32(t, b if z > 0.15 else 0); emu.w32(t + 4, b + len(txt)); emu.w32(t + 8, (b + len(txt) + r.choice([0, 3])) if z > 0.15 else 0)
        emu.calllog.append(('10c0', src == K, txt.hex()))
        _s(emu, k)
    hook_rec(c, 0x5f10c0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=s_10c0)
    def s_c2f0(emu, k, _s=mkside(3)):
        emu.w32(emu.arg32(0), NEWN)
        t = emu.arg32(2)
        emu.calllog.append(('c2f0', emu.reg('ecx') == M, emu.arg32(1) == (END if where == 'end' else nodes[where]), emu.rbytes(emu.r32(t), emu.r32(t + 4) - emu.r32(t)).hex() if emu.r32(t) else ''))
        _s(emu, k)
    hook_rec(c, 0x5fc2f0, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, stackmark=(0, 2), side=s_c2f0)
    def s_870(emu, k, _s=mkside(4)):
        a = emu.arg32(0)
        emu.calllog.append(('870', blocks.index(a) if a in blocks else -1, emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x54f870, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this='mark', side=s_870)
    return [M, K]


S(0x5fb110, 'GUESS hand 0x5fb110', 'thiscall', None, ret='eax', gen=g5fb110, note='batch232003')


def g496380(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import reftab_vt
    T = rnd(c, 0x40)
    P = rnd(c, 0x10); Q = rnd(c, 0x10)
    c.emu.w32(T + 0x14, P); c.emu.w32(P, Q)
    BM = rnd(c, 0x80)
    n = r.choice([0, 1, 2, 3, 4])
    elems = []; Bs = []
    for _ in range(n):
        e = rnd(c, 0x10); b = rnd(c, 0x10)
        A = r.choice([r.randrange(0, 100000), r.randrange(0, 4000), 112 * r.randrange(1, 880), 112 * r.randrange(1, 880) - 1])
        B = r.choice([0, 1, 100, 111, 112, 113, r.randrange(0, 2000)])
        c.emu.w32(e, A); c.emu.w32(b, B)
        elems.append(e); Bs.append(b)
    LV = reftab_vt(c, list(elems))
    sr = [seh_record(c, 2) for _ in range(5)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(BM, 0x80))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    lastc = [0]
    def ctorL(emu, k, _s=mkside(0)):
        lastc[0] = emu.reg('ecx')
        emu.w32(emu.reg('ecx'), LV)
        _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=ctorL)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('dt', emu.reg('ecx') - lastc[0])), _s(emu, k)))
    hook_rec(c, 0x4ce480, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('480', emu.reg('ecx') == Q, emu.arg32(0) - lastc[0])), _s(emu, k)))
    def s2d0(emu, k, _s=mkside(3)):
        i = emu.r32(emu.arg32(0) + 4) - 1
        emu.calllog.append(('2d0', emu.reg('ecx') - lastc[0], i))
        _s(emu, k)
    hook_rec(c, 0x4cf2d0, 1, ret=lambda emu, k: Bs[emu.r32(emu.arg32(0) + 4) - 1], pop=4, this='mark', stackmark=(0,), side=s2d0)
    return [T, BM]


S(0x496380, 'GUESS hand 0x496380', 'thiscall', None, ret='eax', gen=g496380, note='batch232004')


def g45e710(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x40)
    VT = rnd(c, 0x180)
    c.emu.w32(T, VT)
    sr = [seh_record(c, 2) for _ in range(7)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x40))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    if r.random() < 0.1:
        c.emu.w32(T + 0x10, 0)
        O = 0
    else:
        O = rnd(c, 0x40); c.emu.w32(T + 0x10, O)
    # registry
    G = rnd(c, 0xe0); c.emu.w32(0x70039c, G)
    M = rnd(c, 0x1d00); c.emu.w32(G + 0x9b, M)
    RB = rnd(c, 0x40)
    RSZ = r.choice([0x10, 0x20, 0x30])
    c.emu.w32(RB - 8, (r.getrandbits(4) << 28) | RSZ)
    use_rb = r.random() < 0.8
    c.emu.w32(M + 0x1c5d, RB if use_rb else 0)
    edx = r.choice([0, RB - 4, RB, RB + RSZ - 1, RB + RSZ, RB + RSZ + 8, rnd(c, 0x20), 0x1000])
    # sub-objects
    d = r.choice([0, rnd(c, 0x10)])
    t = r.choice([0, rnd(c, 0x10)])
    R = rnd(c, 0x20); c.emu.w32(R + 4, t); c.emu.w32(R + 0xc, d)
    Q = rnd(c, 0x10); c.emu.w32(Q + 4, R if r.random() < 0.85 else 0)
    p = r.choice([0, rnd(c, 0x10)])
    if O:
        c.emu.w32(O + 0xc, edx); c.emu.w32(O + 0x10, p)
        c.emu.w32(O + 0x1c, Q if r.random() < 0.85 else 0)
    def sv(tag, j):
        def f(emu, k, _s=mkside(j)):
            emu.calllog.append((tag, emu.reg('ecx') == T))
            _s(emu, k)
        return f
    c.emu.w32(VT + 8, pystub(c, 0, ret=rnd32, pop=0, this=True, side=sv('v8', 0)))
    c.emu.w32(VT + 0x140, pystub(c, 0, ret=rnd32, pop=0, this=True, side=sv('v140', 1)))
    if t or r.random() < 0.85:
        E = rnd(c, 0x10); VE = rnd(c, 0x80); c.emu.w32(E, VE); c.emu.w32(0x7003a4, E)
        def se(tag, j):
            def f(emu, k, _s=mkside(j)):
                emu.calllog.append((tag, emu.reg('ecx') == E, emu.arg32(0)))
                _s(emu, k)
            return f
        c.emu.w32(VE + 0x6c, pystub(c, 1, ret=rnd32, pop=4, this=True, side=se('e6c', 2)))
        c.emu.w32(VE + 0x58, pystub(c, 1, ret=rnd32, pop=4, this=True, side=se('e58', 3)))
    else:
        c.emu.w32(0x7003a4, 0)
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('free', emu.arg32(0), emu.arg32(1))), _s(emu, k)))
    return [T]


S(0x45e710, 'GUESS hand 0x45e710', 'thiscall', None, ret=None, gen=g45e710, note='batch232005')


def g5f0880(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x90)
    G = rnd(c, 0x2000); c.emu.w32(0x70039c, G)
    CX = rnd(c, 0x10); VC = rnd(c, 0x100); c.emu.w32(CX, VC); c.emu.w32(G + 0x190f, CX)
    dcv = r.choice([r.randrange(0, 0x3000), 0x1c0, 0x1c1, 0x1bf, 0x80000000 | r.randrange(0, 0x100), r.getrandbits(32)])
    sr = [seh_record(c, 2) for _ in range(9)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x90))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    c.emu.w32(VC + 0xdc, pystub(c, 0, ret=lambda emu, k: dcv, pop=0, this=True, side=mkside(0)))
    nodes = []
    nfail = r.choice([0, 0, 0, 5, 27])
    cnt = [0]
    def ral(emu, k):
        cnt[0] += 1
        if cnt[0] == nfail: return 0
        b = rnd(c, 0xa8); nodes.append(b); return b
    hook_rec(c, 0x41e290, 1, ret=ral, pop=0, this=False, side=mkside(1))
    def idx(emu):
        e = emu.reg('ecx'); return nodes.index(e) if e in nodes else (0 if e == 0 else -1)
    hook_rec(c, 0x5ab2e0, 1, ret=lambda emu, k: emu.reg('ecx'), pop=4, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('ctor', idx(emu), emu.arg32(0))), _s(emu, k)))
    def mk(addr, n, tag, j):
        hook_rec(c, addr, n, ret=rnd32, pop=4 * n, this=True, side=lambda emu, k, _s=mkside(j): (emu.calllog.append((tag, idx(emu), [emu.arg32(q) for q in range(n)])), _s(emu, k)))
    mk(0x5aba60, 4, 'aba60', 3); mk(0x5ac5d0, 1, 'c5d0', 4); mk(0x5acac0, 1, 'cac0', 5); mk(0x5ac940, 1, 'c940', 6); mk(0x5ac620, 2, 'c620', 7); mk(0x5ac640, 2, 'c640', 8)
    return [T, r.getrandbits(32), r.getrandbits(32)]


S(0x5f0880, 'GUESS hand 0x5f0880', 'thiscall', None, ret='eax', gen=g5f0880, note='batch232005')


def g602290(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x30)
    bufs = [rnd(c, 0x10) for _ in range(4)]
    cnt = [0]
    def mkstr():
        if r.random() < 0.25: return 0
        n = r.choice([0, 1, 3, 8, 12])
        s = rnd(c, 0x20)
        c.emu.wbytes(s, bytes(r.randrange(1, 256) for _ in range(n)) + b'\0')
        return s
    sr = [seh_record(c, 2) for _ in range(5)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x30))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def r14(emu, k):
        b = bufs[cnt[0]]; cnt[0] += 1; return b
    hook_rec(c, 0x6014a0, 1, ret=r14, pop=4, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('14a0', emu.reg('ecx') - T, emu.arg32(0))), _s(emu, k)))
    def rng_hook(addr, tag, j):
        def f(emu, k, _s=mkside(j)):
            a, b = emu.arg32(0), emu.arg32(1)
            emu.calllog.append((tag, emu.reg('ecx') - T, b - a, emu.rbytes(a, b - a).hex()))
            _s(emu, k)
        hook_rec(c, addr, 2, ret=rnd32, pop=8, this=True, side=f)
    rng_hook(0x5f2d60, 'd60', 1); rng_hook(0x5f2c60, 'c60', 2)
    return [T, mkstr(), mkstr(), mkstr(), mkstr()]


S(0x602290, 'GUESS hand 0x602290', 'thiscall', None, ret='eax', gen=g602290, note='batch232006')


def g57d500(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x20)
    A = rnd(c, 0x100)
    def mkstr(n):
        s = rnd(c, 0x10)
        c.emu.wbytes(s, bytes(r.choice(b'ab') for _ in range(n)) + b'\0')
        return s
    key = mkstr(r.choice([1, 2, 3]))
    P0 = rnd(c, 0x10); c.emu.w32(P0, mkstr(r.choice([1, 2])) if r.random() < 0.7 else key); c.emu.w32(T, P0)
    key_eff = None
    a2 = key if r.random() < 0.75 else 0
    # container with slot 0x40
    Rv = rnd(c, 0x10) if r.random() < 0.25 else 0
    C = rnd(c, 0x10); VC = rnd(c, 0x60); c.emu.w32(C, VC); c.emu.w32(T + 4, C)
    L = rnd(c, 0x10); VL = rnd(c, 0x140); c.emu.w32(L, VL); c.emu.w32(T + 8, L)
    G = rnd(c, 0x1a00); c.emu.w32(0x70039c, G)
    RG = rnd(c, 0x10); VRG = rnd(c, 0x80); c.emu.w32(RG, VRG); c.emu.w32(G + 0x1907, RG)
    MG = rnd(c, 0x10); VMG = rnd(c, 0x140); c.emu.w32(MG, VMG); c.emu.w32(G + 0x9b, MG)
    DEV = rnd(c, 0x10); VD = rnd(c, 0x90); c.emu.w32(DEV, VD)
    TT = rnd(c, 0x40); HO = rnd(c, 0x10); VH = rnd(c, 0x10); c.emu.w32(HO, VH); c.emu.w32(TT + 0x15, HO)
    nent = r.choice([0, 1, 2, 3])
    TB = rnd(c, 28 * 5)
    for i in range(5):
        base = TB + 28 * i
        if i < nent:
            c.emu.w32(base, mkstr(r.choice([1, 2, 3]))) if r.random() < 0.7 else c.emu.w32(base, key)
            c.emu.w32(base + 4, r.getrandbits(32))
            c.emu.w32(base + 8, r.choice([0, rnd(c, 0x10)])); c.emu.w32(base + 0xc, r.choice([0, rnd(c, 0x10)]))
        else:
            c.emu.w32(base, 0)
            break
    sr = [seh_record(c, 2) for _ in range(11)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(A, 0x100))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def cs(emu, a): return emu.rbytes(a, 8).split(b'\0')[0].hex()
    c.emu.w32(VC + 0x40, pystub(c, 2, ret=lambda emu, k: Rv, pop=8, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('c40', emu.reg('ecx') == C, cs(emu, emu.arg32(0)), emu.arg32(1))), _s(emu, k))))
    cnt = [0]
    first0 = r.random() < 0.4
    second0 = r.random() < 0.3
    def r60(emu, k):
        cnt[0] += 1
        if cnt[0] == 1: return 0 if first0 else TT
        return 0 if second0 else TT
    c.emu.w32(VRG + 0x60, pystub(c, 1, ret=r60, pop=4, this=True, side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('r60', emu.reg('ecx') == RG, emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VMG + 0x138, pystub(c, 0, ret=lambda emu, k: DEV, pop=0, this=True, side=mkside(2)))
    def s88(emu, k, _s=mkside(3)):
        v = r.getrandbits(32); emu.w32(emu.arg32(1), v)
        emu.calllog.append(('d88', emu.reg('ecx') == DEV, emu.arg32(0), v))
        _s(emu, k)
    c.emu.w32(VD + 0x88, pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=s88))
    c.emu.w32(VMG + 0x114, pystub(c, 5, ret=rnd32, pop=20, this=True, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('m114', [emu.arg32(q) for q in range(5)])), _s(emu, k))))
    c.emu.w32(VL + 0x12c, pystub(c, 2, ret=rnd32, pop=8, this=True, side=lambda emu, k, _s=mkside(5): (emu.calllog.append(('l12c', emu.reg('ecx') == L, emu.arg32(0), emu.arg32(1))), _s(emu, k))))
    c.emu.w32(VH, pystub(c, 0, ret=lambda emu, k: TB, pop=0, this=True, side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('h0', emu.reg('ecx') == HO)), _s(emu, k))))
    def strcmp(emu, k):
        a, b = emu.arg32(0), emu.arg32(1)
        x = emu.rbytes(a, 8).split(b'\0')[0]; y = emu.rbytes(b, 8).split(b'\0')[0]
        return 0 if x == y else (1 if x > y else 0xffffffff)
    c.emu.w32(0x676414, pystub(c, 2, pop=0, this=False, ret=strcmp, side=lambda emu, k: emu.calllog.append(('cmp', cs(emu, emu.arg32(0)), cs(emu, emu.arg32(1))))))
    hook_rec(c, 0x57c910, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('c910', emu.reg('ecx') == A, emu.arg32(0) == Rv)), _s(emu, k)))
    hook_rec(c, 0x57d200, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('d200', emu.reg('ecx'), emu.reg('edx') - A)), _s(emu, k)))
    def s80(emu, k):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(16)))
        emu.calllog.append(('be80', cs(emu, emu.arg32(0))))
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=s80)
    hook_rec(c, 0x4cbee0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('bee0', emu.reg('ecx') == A, emu.rbytes(emu.arg32(0), 16).hex())), _s(emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('bec0', emu.rbytes(emu.reg('ecx'), 16).hex())), _s(emu, k)))
    return [T, A, a2]


S(0x57d500, 'GUESS hand 0x57d500', 'thiscall', None, ret='al', gen=g57d500, note='batch232007')


def g603a50(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 3, 4])
    c.emu.w32(T + 0x14, n)
    VO = rnd(c, 0x40)
    pool = []
    def mkobj():
        o = rnd(c, 0x10); c.emu.w32(o, VO); pool.append(o); return o
    for _ in range(8): mkobj()
    def mkelems(k):
        a = rnd(c, 8 * k)
        for q in range(k):
            t = r.choice([0, 1, 4, 4, 7])
            c.emu.w32(a + 8 * q, r.choice(pool) if t == 4 else r.getrandbits(32))
            c.emu.wbytes(a + 8 * q + 4, bytes([t]))
        return a
    def mkvec(data, size):
        s = rnd(c, 0x10); c.emu.w32(s, data); c.emu.w32(s + 8, size); return s
    NEL = 48
    SRC = rnd(c, 0x20)
    # nested: S1 {S2, off, cnt}
    S2 = mkvec(mkelems(NEL), r.choice([NEL, NEL, 3, 1, 0]))
    S1 = rnd(c, 0x10); c.emu.w32(S1, S2); c.emu.w32(S1 + 4, r.choice([0, 0, 1, 5])); c.emu.w32(S1 + 8, r.choice([8, 8, 2, 0]))
    c.emu.w32(SRC + 4, S1)
    S2b = mkvec(mkelems(NEL), r.choice([NEL, NEL, 2, 1, 0]))
    S3 = rnd(c, 0x10); c.emu.w32(S3, S2b); c.emu.w32(S3 + 4, r.choice([0, 1, 3])); c.emu.w32(S3 + 8, r.choice([4, 4, 1, 0, 0]))
    c.emu.w32(SRC + 8, S3)
    NODE = rnd(c, 0x40); VTN = rnd(c, 0x40); VTN_ = VTN
    ndst = r.choice([n, n, n, max(0, n - 1)])
    DST = mkelems(NEL)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x20))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NODE, pop=0, this=False, side=mkside(0))
    def s3500(emu, k, _s=mkside(1)):
        t = emu.reg('ecx')
        emu.w32(t, VTN); emu.w32(t + 0xc, DST); emu.w32(t + 0x14, ndst)
        emu.calllog.append(('c3500', t == NODE, emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x603500, 1, ret=lambda emu, k: emu.reg('ecx'), pop=4, this=True, side=s3500)
    def pidx(emu):
        e = emu.reg('ecx')
        return pool.index(e) if e in pool else ('node' if e == NODE else -1)
    def vs(tag, j, vt, retf):
        c.emu.w32(vt, pystub(c, 0, ret=retf, pop=0, this=True, side=lambda emu, k, _s=mkside(j): (emu.calllog.append((tag, pidx(emu))), _s(emu, k))))
    c.emu.w32(VO + 0x24, 0); c.emu.w32(VO + 0x28, 0); c.emu.w32(VTN + 0x24, 0); c.emu.w32(VTN + 0x28, 0)
    vs('o24', 2, VO + 0x24, lambda emu, k: r.choice(pool))
    vs('o28', 3, VO + 0x28, rnd32)
    vs('n24', 4, VTN + 0x24, lambda emu, k: r.choice(pool))
    vs('n28', 5, VTN + 0x28, rnd32)
    c.emu.w32(0x7003b0, pystub(c, 0, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('fatal',)), _s(emu, k))))
    return [T, SRC]


S(0x603a50, 'GUESS hand 0x603a50', 'thiscall', None, ret='eax', gen=g603a50, note='batch232008')


def g45cd90(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import reftab_vt
    T = rnd(c, 0x20)
    VT = rnd(c, 0x200); c.emu.w32(T, VT)
    H = rnd(c, 0x10); c.emu.w32(T + 8, H)
    U = rnd(c, 0x20); c.emu.w32(T + 0x10, U)
    ids = [r.randrange(1, 9) for _ in range(r.choice([0, 1, 2, 3, 5]))]
    ids = list(dict.fromkeys(ids))
    LL = reftab_vt(c, list(ids))
    Lo = rnd(c, 0x10); c.emu.w32(Lo, LL)
    c.emu.w32(U + 8, Lo if r.random() > 0.15 else 0)
    relems = []
    LVR = reftab_vt(c, relems)
    VE = rnd(c, 0x80)
    objs = {}
    for i in set(ids):
        if r.random() < 0.8:
            e = rnd(c, 0x40); c.emu.w32(e, VE)
            c.emu.w32(e + 4, r.choice([0, 1, 4, 8, 5, 9, 12, 13, 2]))
            c.emu.w32(e + 0x14, r.choice([0, 1, 2, 3, 4, 0x20, 0x21, 5]))
            c.emu.w32(e + 0x1c, r.choice([0, 0, 0, 1]))
            objs[i] = e
    GM = rnd(c, 0x10); VGM = rnd(c, 0x100); c.emu.w32(GM, VGM); c.emu.w32(0x70038c, GM)
    G = rnd(c, 0xe0); c.emu.w32(0x70039c, G)
    MG = rnd(c, 0x10); VMG = rnd(c, 0x80); c.emu.w32(MG, VMG); c.emu.w32(G + 0x9b, MG)
    LGO = rnd(c, 0x10); VLO = rnd(c, 0x60); c.emu.w32(LGO, VLO); c.emu.w32(0x700390, LGO)
    LG = rnd(c, 0x10); VLG = rnd(c, 0x60); c.emu.w32(LG, VLG)
    A4 = 0
    if r.random() < 0.6:
        A4 = rnd(c, 0x10); VA4 = rnd(c, 0x200); c.emu.w32(A4, VA4)
    S2 = rnd(c, 0x10); S4 = rnd(c, 0x10); CS = rnd(c, 0x20)
    ok54 = r.random() < 0.85
    a1 = r.choice([0, 1, 2, 3, 4, 0x20, 1, 4, 5])
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x20))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    objl = list(objs.values())
    def oi(emu): 
        e = emu.reg('ecx'); return objl.index(e) if e in objl else -1
    def fill(emu):
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(16)))
    hook_rec(c, 0x4da3a0, 0, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | (1 if r.random() < 0.85 else 0), pop=0, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('a3a0', emu.reg('ecx') == H)), _s(emu, k)))
    lastc = [0]
    def ctorR(emu, k, _s=mkside(1)):
        lastc[0] = emu.reg('ecx'); emu.w32(emu.reg('ecx'), LVR); _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=ctorR)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('dtR', emu.reg('ecx') - lastc[0], list(relems))), _s(emu, k)))
    def s540(emu, k, _s=mkside(3)):
        relems.append(emu.arg32(0)); emu.calllog.append(('d540', emu.reg('ecx') - lastc[0], emu.arg32(0))); _s(emu, k)
    hook_rec(c, 0x4cd540, 1, ret=rnd32, pop=4, this='mark', side=s540)
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: CS, pop=0, this=True, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('c1d0', emu.reg('ecx') in (S2, S4))), _s(emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(5): (emu.calllog.append(('bec0', emu.rbytes(emu.reg('ecx'), 16).hex())), _s(emu, k)))
    hook_rec(c, 0x4dc630, 2, ret=rnd32, pop=8, this=True, side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('c630', emu.reg('ecx') == H, emu.arg32(0), emu.arg32(1))), _s(emu, k)))
    c.emu.w32(VGM + 0xcc, pystub(c, 1, ret=lambda emu, k: objs.get(emu.arg32(0), 0), pop=4, this=True, side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('gcc', emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VT + 0x1d8, pystub(c, 2, ret=lambda emu, k: S2, pop=8, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(8): (fill(emu), emu.calllog.append(('t1d8', emu.reg('ecx') == T, emu.arg32(1))), _s(emu, k))))
    if A4:
        c.emu.w32(VA4 + 0x1d8, pystub(c, 2, ret=lambda emu, k: S4, pop=8, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(9): (fill(emu), emu.calllog.append(('a41d8', emu.reg('ecx') == A4, emu.arg32(1))), _s(emu, k))))
    c.emu.w32(VE + 0x14, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('e14', oi(emu))), _s(emu, k))))
    c.emu.w32(VE + 0x48, pystub(c, 3, ret=rnd32, pop=12, this=True, side=lambda emu, k, _s=mkside(11): (emu.calllog.append(('e48', oi(emu), [emu.arg32(q) for q in range(3)])), _s(emu, k))))
    c.emu.w32(VE + 0x54, pystub(c, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(12): (emu.calllog.append(('e54', oi(emu), emu.arg32(0) == T)), _s(emu, k))))
    c.emu.w32(VMG + 0x4c, pystub(c, 1, ret=lambda emu, k: 0x1234, pop=4, this=True, side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('m4c', emu.arg32(0) == T)), _s(emu, k))))
    c.emu.w32(VMG + 0x54, pystub(c, 1, ret=lambda emu, k: 1 if ok54 else 0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('m54', emu.arg32(0)))))
    c.emu.w32(VLO + 0x20, pystub(c, 2, ret=lambda emu, k: LG, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    def s2c(emu, k):
        fmt = emu.arg32(1)
        n = 5 if fmt == 0x685180 else 4
        emu.calllog.append(('l2c', emu.arg32(0) == LG, fmt, [emu.arg32(q) for q in range(2, n)]))
    c.emu.w32(VLG + 0x2c, pystub(c, 0, ret=rnd32, pop=0, this=False, side=s2c))
    return [T, a1, r.getrandbits(32), r.getrandbits(32), A4]


S(0x45cd90, 'GUESS hand 0x45cd90', 'thiscall', None, ret='eax', gen=g45cd90, note='batch232009')


def g57e4f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import reftab_vt
    T = rnd(c, 0x400)
    n = r.choice([0, 1, 2, 5, 12, 20, 0x40, 0x91, 0x95])
    c.emu.w32(T + 0x338, n)
    FL = rnd(c, 0xa0); BA = rnd(c, 0xa0)
    for i in range(0xa0):
        c.emu.wbytes(FL + i, bytes([r.choice([0, 1])]))
        c.emu.wbytes(BA + i, bytes([r.choice([0, 1, 1])]))
    if r.random() < 0.6: c.emu.wbytes(BA, b'\0')
    c.emu.w32(T + 0x32c, FL); c.emu.w32(T + 0x330, BA)
    c.emu.w32(T + 0x33c, r.choice([1, 2, 5]))
    c.emu.w32(T + 0x188, r.getrandbits(32))
    G = rnd(c, 0x1a00); c.emu.w32(0x70039c, G)
    # table of 0x10-byte entries partitioning [0, 0x100)
    nent = 9
    TB = rnd(c, 0x10 * nent) if r.random() > 0.2 else 0
    if TB:
        pos = 0
        for k in range(nent):
            ln = r.choice([3, 5, 8, 13, 20]) if k < nent - 1 else 0x200
            if k == 1: ln = r.choice([11, 13, 20, 7, 8, 9, 10])
            c.emu.w32(TB + 0x10 * k, pos); c.emu.w32(TB + 0x10 * k + 0xc, ln)
            pos += ln
    c.emu.w32(G + 0x190b, TB)
    mode = r.random()
    if TB and mode < 0.6:
        # sparse flags: one set flag at a chosen offset inside / around entry 1
        st1 = c.emu.r32(TB + 0x10); ln1 = c.emu.r32(TB + 0x10 + 0xc)
        for q in range(0xa0): c.emu.wbytes(BA + q, b'\0')
        lo_t = r.choice([5, 6, 7, 8, 9, 10, 11, 12, ln1, ln1 - 1])
        pos_t = st1 + lo_t
        if pos_t < 0xa0:
            c.emu.wbytes(BA + pos_t, b'\1')
            if c.emu.r32(T + 0x338) <= pos_t: c.emu.w32(T + 0x338, pos_t + 1 + r.choice([0, 3]))
    if mode > 0.9:
        for q in range(0xa0): c.emu.wbytes(BA + q, b'\0')
        c.emu.wbytes(BA + 0x90, b'\1'); c.emu.w32(T + 0x338, 0x95)
    MG = rnd(c, 0x10); VMG = rnd(c, 0x80); c.emu.w32(MG, VMG); c.emu.w32(G + 0x9b, MG)
    # objects
    PS = rnd(c, 0x10); CSV = rnd(c, 0x10); c.emu.wbytes(CSV, b'name\0'); c.emu.w32(PS, CSV)
    OBJ = rnd(c, 0x100); c.emu.w32(OBJ, PS)
    O2 = rnd(c, 0x10); VO2 = rnd(c, 0x300); c.emu.w32(O2, VO2)
    ID1 = 777
    ids = [ID1] + [r.randrange(20, 30) for _ in range(r.choice([0, 1, 2, 3]))]
    ids = list(dict.fromkeys(ids))
    wmap = {ID1: OBJ}
    for i in ids[1:]:
        if r.random() < 0.8:
            w = rnd(c, 0x100)
            for k in range(4):
                c.emu.w32(w + 0xac + 4 * k, 0xffffffff if r.random() < 0.7 else r.getrandbits(32))
            wmap[i] = w
    LV = reftab_vt(c, list(ids))
    c.emu.w32(T + 0x23c, LV)
    VGM = rnd(c, 0x100); GM = rnd(c, 0x10); c.emu.w32(GM, VGM); c.emu.w32(0x70038c, GM)
    VS = rnd(c, 0x20); c.emu.w32(T + 0x190, VS)
    o2present = r.random() < 0.8
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T + 0x32c, 0x20)), zlib.crc32(emu.rbytes(BA, 0x50)), zlib.crc32(emu.rbytes(OBJ, 0x100))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def cs(emu, a): return emu.rbytes(a, 8).split(b'\0')[0].hex()
    c.emu.w32(VGM + 0xcc, pystub(c, 1, ret=lambda emu, k: wmap.get(emu.arg32(0), 0), pop=4, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('gcc', emu.arg32(0))), _s(emu, k))))
    c.emu.w32(LV + 0x30, pystub(c, 1, ret=lambda emu, k: ID1, pop=4, this=True, side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('o30', emu.reg('ecx') - T, emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VS + 0xc, pystub(c, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('s0c', emu.reg('ecx') - T)), _s(emu, k))))
    c.emu.w32(VMG + 0x58, pystub(c, 1, ret=lambda emu, k: O2 if o2present else 0, pop=4, this=True, side=lambda emu, k, _s=mkside(3): (emu.calllog.append(('m58', emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VO2 + 0x2d8, pystub(c, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('o2d8', emu.reg('ecx') == O2)), _s(emu, k))))
    c.emu.w32(VO2 + 0x2dc, pystub(c, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(5): (emu.calllog.append(('o2dc', emu.reg('ecx') == O2)), _s(emu, k))))
    hook_rec(c, 0x57d950, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('d950', emu.reg('ecx') - T, emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x57ee90, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('ee90', emu.reg('ecx') == OBJ)), _s(emu, k)))
    hook_rec(c, 0x57d780, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('d780', emu.reg('ecx') - T)), _s(emu, k)))
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    hook_rec(c, 0x4cbeb0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(9): (fill16(emu, emu.reg('ecx')), _s(emu, k)))
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=lambda emu, k, _s=mkside(10): (fill16(emu, emu.reg('ecx')), emu.calllog.append(('be80', cs(emu, emu.arg32(0)))), _s(emu, k)))
    hook_rec(c, 0x4cbee0, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=lambda emu, k, _s=mkside(11): (emu.wbytes(emu.reg('ecx'), emu.rbytes(emu.arg32(0), 16)), emu.calllog.append(('bee0', emu.rbytes(emu.arg32(0), 16).hex())), _s(emu, k)))
    hook_rec(c, 0x4cbe50, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=lambda emu, k, _s=mkside(12): (emu.wbytes(emu.reg('ecx'), emu.rbytes(emu.arg32(0), 16)), emu.calllog.append(('be50', emu.rbytes(emu.arg32(0), 16).hex())), _s(emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('bec0', emu.rbytes(emu.reg('ecx'), 16).hex())), emu.wbytes(emu.reg('ecx'), b'\xdd' * 16), _s(emu, k)))
    hook_rec(c, 0x57c910, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(14): (emu.calllog.append(('c910', emu.reg('ecx') - OBJ, emu.rbytes(emu.arg32(0), 16).hex())), _s(emu, k)))
    return [T]


S(0x57e4f0, 'GUESS hand 0x57e4f0', 'thiscall', None, ret=None, gen=g57e4f0, note='batch232010')


def g5fbbe0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    T = rnd(c, 0x90)
    PT = rnd(c, 0x10); c.emu.wbytes(PT, b'\0'); c.emu.w32(T + 4, PT)
    c.emu.wbytes(T + 0x40, bytes([r.getrandbits(8)]))
    NV = 64
    VEC = rnd(c, 4 * NV)
    elems = []
    for q in range(NV):
        E = rnd(c, 0x70)
        cap = r.choice([1, 2, 4, 8]); size = r.randrange(0, cap + 1)
        D = rnd(c, 4 * 16)
        c.emu.w32(E + 0x58, D); c.emu.w32(E + 0x5c, cap); c.emu.w32(E + 0x60, size)
        c.emu.w32(VEC + 4 * q, E); elems.append(E)
    vsize = r.choice([0, 1, 3, 5])
    vcap = r.choice([1, 2, 4, 5, 8])
    if vsize > vcap: vcap = vsize
    c.emu.w32(T + 0x18, VEC); c.emu.w32(T + 0x1c, vcap); c.emu.w32(T + 0x20, vsize)
    n = r.choice([0, 1, 2, 3, 5])
    LST = rnd(c, 0x10); VL = rnd(c, 0x80); c.emu.w32(LST, VL)
    calls5c = [0]
    fcl = struct.unpack('<I', struct.pack('<f', 0.99))[0]
    badf = r.random() < 0.15
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x40)), zlib.crc32(emu.rbytes(VEC, 4 * NV))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    blocks = []
    def newblock(sz=0x100):
        b = rnd(c, max(sz, 0x100)); blocks.append(b); return b
    def bi(a): return blocks.index(a) if a in blocks else -1
    def newelem():
        blk = newblock()
        D = rnd(c, 4 * 16)
        cap = r.choice([1, 2, 4, 8])
        c.emu.w32(blk + 0x58, D); c.emu.w32(blk + 0x5c, cap); c.emu.w32(blk + 0x60, r.randrange(0, cap + 1))
        return blk
    def s64(emu, k, _s=mkside(0)):
        emu.w32(emu.arg32(0), 0x7fc00000 if (badf and r.random() < 0.3) else (fcl if not badf else r.choice([0x3f800000, fcl + 1, fcl - 1, 0x3f000000, 0x7fc00000])))
        emu.calllog.append(('l64',)); _s(emu, k)
    c.emu.w32(VL + 0x64, pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s64))
    def s5c(emu, k, _s=mkside(1)):
        calls5c[0] += 1
        v = n if calls5c[0] == 1 else r.randrange(1, 50)
        emu.w32(emu.arg32(0), v); emu.calllog.append(('l5c', v)); _s(emu, k)
    c.emu.w32(VL + 0x5c, pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s5c))
    def s60(emu, k, _s=mkside(2)):
        v = (0xffffffff - r.randrange(0, 3)) if r.random() < 0.45 else r.choice([0, 1, 2, 3, vsize - 1 if vsize else 0, vsize, vsize + 1, 7])
        emu.w32(emu.arg32(0), v & 0xffffffff); emu.calllog.append(('l60', v & 0xffffffff)); _s(emu, k)
    c.emu.w32(VL + 0x60, pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s60))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(3): (emu.calllog.append(('fatal',)), _s(emu, k))))
    lastH = [0]
    hook_rec(c, 0x5f9680, 1, ret=rnd32, pop=4, this='mark', side=lambda emu, k, _s=mkside(4): (lastH.__setitem__(0, emu.reg('ecx')), emu.calllog.append(('h680', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x5f98a0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(5): (emu.calllog.append(('h8a0', emu.reg('ecx') - lastH[0])), _s(emu, k)))
    hook_rec(c, 0x5f9dd0, 1, ret=rnd32, pop=4, this='mark', side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('hdd0', emu.reg('ecx') - lastH[0], emu.arg32(0) == LST)), _s(emu, k)))
    hook_rec(c, 0x5fa090, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('h090', emu.reg('ecx') - lastH[0], emu.arg32(0))), _s(emu, k)))
    def r590(emu, k):
        return newblock()
    def ralloc(emu, k):
        sz = emu.arg32(0)
        blk = newblock(max(sz, 8))
        if sz != 0xad2:
            for q in range(64): emu.w32(blk + 4 * q, elems[q % NV])
        return blk
    hook_rec(c, 0x5fc590, 2, ret=r590, pop=12, this=True, side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('c590', emu.reg('ecx') == PT, emu.arg32(0), emu.arg32(1), emu.arg32(2) & 0xff)), _s(emu, k)))
    hook_rec(c, 0x41e290, 1, ret=ralloc, pop=0, this=False, side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('al', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x41e2c0, 1, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('fr', emu.arg32(0) == VEC or bi(emu.arg32(0)))), _s(emu, k)))
    hook_rec(c, 0x5f3480, 3, ret=lambda emu, k: newelem(), pop=12, this=True, side=lambda emu, k, _s=mkside(11): (emu.calllog.append(('n480', bi(emu.reg('ecx')), emu.arg32(0) - emu.arg32(0) if False else bi(emu.arg32(0) - 0x3c), emu.arg32(1), emu.arg32(2))), _s(emu, k)))
    hook_rec(c, 0x5f37f0, 2, ret=lambda emu, k: newelem(), pop=8, this=True, side=lambda emu, k, _s=mkside(12): (emu.calllog.append(('n7f0', bi(emu.reg('ecx')), elems.index(emu.arg32(0)) if emu.arg32(0) in elems else -1, emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x5f4680, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('f680', bi(emu.reg('ecx')), emu.arg32(0) == LST, emu.arg32(1) - lastH[0])), _s(emu, k)))
    hook_rec(c, 0x5fbe50, 3, ret=rnd32, pop=12, this=True, stackmark=(2,), side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('be50', emu.reg('ecx') == PT, bi(emu.arg32(0)), emu.arg32(1) == LST, emu.arg32(2) - lastH[0])), _s(emu, k)))
    def s4630(emu, k, _s=mkside(1)):
        v = emu.reg('ecx'); D = emu.r32(v); cap = emu.r32(v + 4); sz = emu.r32(v + 8)
        nb = rnd(c, 4 * 32)
        emu.wbytes(nb, emu.rbytes(D, 4 * sz)); emu.w32(v, nb); emu.w32(v + 4, max(2 * cap, 4))
        emu.calllog.append(('g630', elems.index(v - 0x58) if (v - 0x58) in elems else -1, cap, sz)); _s(emu, k)
    hook_rec(c, 0x5f4630, 0, ret=rnd32, pop=0, this=True, side=s4630)
    return [T, LST]


S(0x5fbbe0, 'GUESS hand 0x5fbbe0', 'thiscall', None, ret='eax', gen=g5fbbe0, note='batch232011')


def g450980(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    fb = lambda f: struct.unpack('<I', struct.pack('<f', f))[0]
    T = rnd(c, 0x100)
    VT = rnd(c, 0x400); c.emu.w32(T, VT)
    n44 = r.choice([0, 1, 2, 3, 4])
    PA = rnd(c, 12 * 8)
    for q in range(n44 * 3):
        c.emu.w32(PA + 4 * q, fb(r.choice([0.0, 0.0, 0.1, -0.1, 0.2, 1.0, 1.05, r.uniform(-3, 3)])))
    FA = rnd(c, 4 * 8); FB = rnd(c, 4 * 8)
    c.emu.w32(T + 0x44, n44); c.emu.w32(T + 0x58, PA); c.emu.w32(T + 0x60, FA); c.emu.w32(T + 0x64, FB)
    n48 = r.choice([0, 1, 2, 3]) if n44 else 0
    EA = rnd(c, 16 * 4)
    for q in range(n48):
        c.emu.wbytes(EA + 16 * q, struct.pack('<HH', r.randrange(n44), r.randrange(n44)))
    c.emu.w32(T + 0x48, n48); c.emu.w32(T + 0x4c, EA)
    # nodes
    def mknodes(k):
        arr = rnd(c, 4 * 8); nodes = []
        VN = rnd(c, 0x100)
        for q in range(k):
            nd = rnd(c, 0x20); c.emu.w32(nd, VN)
            Q = rnd(c, 0x60)
            for cidx in range(3): c.emu.w32(Q + 0x40 + 4 * cidx, fb(r.choice([0.0, 0.5, 1.0, 2.0, 1e-3])))
            c.emu.w32(nd + 8, Q); c.emu.w32(arr + 4 * q, nd); nodes.append((nd, Q))
        return arr, nodes, VN
    n74 = r.choice([0, 1, 2]); n80 = r.choice([0, 1, 2, 3])
    NA, nodesA, VNA = mknodes(n74); NB, nodesB, VNB = mknodes(n80)
    c.emu.w32(T + 0x74, n74); c.emu.w32(T + 0x78, NA); c.emu.w32(T + 0x80, n80); c.emu.w32(T + 0x84, NB)
    OWN = rnd(c, 0x80); c.emu.w32(T + 8, OWN)
    c.emu.w32(T + 0xa8, r.choice([0, 1, 2]))
    G = rnd(c, 0xe0); c.emu.w32(0x70039c, G)
    MG = rnd(c, 0x10); VMG = rnd(c, 0x200); c.emu.w32(MG, VMG); c.emu.w32(G + 0x9b, MG)
    DEV = rnd(c, 0x10); VD = rnd(c, 0x100); c.emu.w32(DEV, VD)
    OB = rnd(c, 0x10); VOB = rnd(c, 0x40); c.emu.w32(OB, VOB)
    O2 = rnd(c, 0x10); VO2 = rnd(c, 0x400); c.emu.w32(O2, VO2)
    R2 = rnd(c, 0x80) if r.random() < 0.8 else 0
    chain = []
    if R2:
        prev = 0
        for q in range(r.choice([0, 1, 2, 3])):
            ch = rnd(c, 0x80); ob = rnd(c, 0x10); vv = rnd(c, 0x400); c.emu.w32(ob, vv)
            c.emu.w32(ch + 0x54, T if r.random() < 0.3 else ob); c.emu.w32(ch + 0x60, prev)
            chain.append((ch, vv)); prev = ch
        c.emu.w32(R2 + 0x50, prev)
    flag = r.choice([0, 1, 1, 0x100, 0x1ff])
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T + 0x40, 0xc0)), zlib.crc32(emu.rbytes(FA, 32)), zlib.crc32(emu.rbytes(FB, 32))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    Rlist = []
    lastR = [0]
    def ctorR(emu, k, _s=mkside(0)):
        lastR[0] = emu.reg('ecx'); Rlist.clear(); emu.calllog.append(('4ccbe0', emu.arg32(0), emu.arg32(1))); _s(emu, k)
    hook_rec(c, 0x4ccbe0, 2, ret=rnd32, pop=8, this='mark', side=ctorR)
    hook_rec(c, 0x4cdd40, 0, ret=lambda emu, k: len(Rlist), pop=0, this='mark', side=lambda emu, k: None)
    hook_rec(c, 0x4ce5b0, 1, ret=lambda emu, k: Rlist[emu.arg32(0)] if emu.arg32(0) < len(Rlist) else 0, pop=4, this='mark', side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('4ce5b0', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x4cd540, 1, ret=rnd32, pop=4, this='mark', side=lambda emu, k, _s=mkside(2): (Rlist.append(emu.arg32(0)), emu.calllog.append(('4cd540', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x4cdb90, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(3): (emu.calllog.append(('4cdb90', list(Rlist))), _s(emu, k)))
    hook_rec(c, 0x4ccfe0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('4ccfe0', list(Rlist))), _s(emu, k)))
    def s0a10(emu, k, _s=mkside(5)):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(12))); emu.calllog.append(('4e0a10',)); _s(emu, k)
    hook_rec(c, 0x4e0a10, 0, ret=rnd32, pop=0, this='mark', side=s0a10)
    hook_rec(c, 0x4e0d00, 1, ret=rnd32, pop=4, this='mark', side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('4e0d00', emu.arg32(0), emu.rbytes(emu.reg('ecx'), 12).hex())), _s(emu, k)))
    hook_rec(c, 0x441940, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('441940', emu.reg('ecx') - PA, emu.rbytes(emu.reg('edx'), 12).hex())), _s(emu, k)))
    limits = {Q: [struct.unpack('<f', struct.pack('<I', c.emu.r32(Q + 0x40 + 4 * q)))[0] for q in range(3)] for _, Q in nodesA + nodesB}
    def s920(emu, k, _s=mkside(8)):
        Qp = emu.arg32(0) - 0x30
        lim = limits.get(Qp, [1.0, 1.0, 1.0])
        out = emu.reg('ecx')
        for q in range(3):
            v = r.choice([0.0, lim[q], lim[q] * 0.5, lim[q] * 2 + 1e-3, -lim[q], lim[q] * 0.999, float('nan') if r.random() < 0.03 else lim[q]])
            emu.w32(out + 4 * q, fb(v))
        emu.calllog.append(('43e920', emu.rbytes(emu.reg('edx'), 12).hex(), emu.rbytes(out, 12).hex())); _s(emu, k)
    hook_rec(c, 0x43e920, 1, ret=rnd32, pop=4, this='mark', side=s920)
    def s8c(emu, k, _s=mkside(9)):
        emu.calllog.append(('v8c', emu.reg('ecx'), emu.rbytes(emu.arg32(0), 12).hex())); _s(emu, k)
    for VN in (VNA, VNB):
        c.emu.w32(VN + 0x8c, pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s8c))
    c.emu.w32(VT + 0x84, pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('t84', emu.rbytes(emu.arg32(0), 12).hex())), _s(emu, k))))
    c.emu.w32(VT + 0x20, pystub(c, 0, ret=lambda emu, k: O2, pop=0, this=True, side=mkside(11)))
    c.emu.w32(VO2 + 0x25c, pystub(c, 2, ret=lambda emu, k: R2, pop=8, this=True, side=lambda emu, k, _s=mkside(12): (emu.calllog.append(('o25c', emu.arg32(0), emu.arg32(1))), _s(emu, k))))
    for ch, vv in chain:
        c.emu.w32(vv + 0x1e0, pystub(c, 1, ret=lambda emu, k: (r.getrandbits(32) & ~0xff) | r.choice([0, 1]), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('o1e0', emu.arg32(0)))))
    c.emu.w32(VMG + 0x138, pystub(c, 0, ret=lambda emu, k: DEV, pop=0, this=True, side=mkside(13)))
    c.emu.w32(VMG + 0x58, pystub(c, 1, ret=lambda emu, k: OB, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('m58', emu.arg32(0)))))
    outv = r.choice([0, rnd(c, 0x10)])
    def s88(emu, k):
        emu.w32(emu.arg32(1), outv); emu.calllog.append(('d88', emu.arg32(0)))
    c.emu.w32(VD + 0x88, pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=s88))
    c.emu.w32(VOB + 0x20, pystub(c, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('ob20',))))
    c.emu.w32(OWN + 0x6c, r.getrandbits(32))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x100), pop=0, this=False, side=lambda emu, k: emu.calllog.append(('al', emu.arg32(0))))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k: emu.calllog.append(('fr', emu.arg32(0) == NA, emu.arg32(0) == NB, emu.arg32(1))))
    return [T, flag]


S(0x450980, 'GUESS hand 0x450980', 'thiscall', None, ret='eax', gen=g450980, note='batch232012')


_COV = {}
import atexit as _ae, os as _os
_ae.register(lambda: _os.environ.get('W3F_COV') and print('COV', _COV))


def g453390(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    from recruits_util import obj, sysobj, reftab_vt
    TS = 0x100
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(40)]
    def cstr(emu, a, lim=0x40):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def fl(n, lo=-3.0, hi=3.0): return b''.join(struct.pack('<f', r.uniform(lo, hi)) for _ in range(n))
    deg = r.random() < 0.3
    TIE = [False]
    DTRI = struct.pack('<fff', r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-1, 1))
    objs = []
    def idx(emu):
        o = emu.reg('ecx'); return objs.index(o) if o in objs else (('T', o - T) if T <= o < T + TS else -1)
    def mk(name, j, n, pop, retf=None, st0=None, stackmark=(), wr=0, side2=False, big=False):
        def sd(emu, k, _s=mkside(j)):
            if name in ('v84',): emu.calllog.append(('v84c', emu.rbytes(emu.arg32(0), 12).hex()))
            emu.calllog.append((name, idx(emu), [(emu.arg32(i) if _ru.HEAP_LO <= emu.arg32(i) < _ru.HEAP_HI else 'S') if i in stackmark else emu.arg32(i) for i in range(n)]))
            if side2: emu.wbytes(emu.arg32(0), struct.pack('<fff', r.uniform(-0.04, 0.04), r.uniform(-0.04, 0.04), r.choice([-0.998, 0.998, 0.998, -0.998, r.uniform(-1, 1)])))
            if not (TIE[0] and name == 'v84'):
                for (ai, nb) in (wr if isinstance(wr, (list, tuple)) else ([(0, wr)] if wr else [])):
                    emu.wbytes(emu.arg32(ai), fl(nb // 4))
                if big and r.random() < 0.6: emu.wbytes(emu.arg32(0), fl(3, -30.0, 30.0))
                if big and deg: emu.wbytes(emu.arg32(0), DTRI)
            _s(emu, k)
        return pystub(c, n, ret=(retf or rnd32), pop=pop, this=True, stackmark=stackmark, side=sd, **({'st0': st0} if st0 else {}))
    import recruits_util as _ru
    # constants read from exe
    def cf(a): return struct.unpack('<f', c.emu.rbytes(a, 4))[0]
    c680a90 = cf(0x680a90)
    # info objects
    INFO = rnd(c, 0x100); c.emu.wbytes(INFO, b''.join(struct.pack('<f', r.choice([0.5, 1.0, 1.0, 2.0, r.uniform(0.1, 2.0)])) for _ in range(0x100 // 4)))
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.w32(T + 8, INFO)
    c.emu.wbytes(T + 0x20, bytes([1 if r.random() < 0.9 else 0]))
    c.emu.wbytes(T + 4, struct.pack('<I', 0))
    P12 = rnd(c, 0x40); c.emu.wbytes(P12, fl(12, -1, 1))
    def mkvt(base_owner):
        return {0x244: mk('v244', 0, 0, 0, lambda emu, k: P12S[objs.index(emu.reg('ecx'))] if emu.reg('ecx') in objs else P12),
                0x84: mk('v84', 1, 1, 4, stackmark=(0,), wr=[(0, 12)], big=True),
                0x214: mk('v214', 2, 0, 0, lambda emu, k: 0, st0=lambda emu, k: f214(emu)),
                0x20: mk('v20', 3, 0, 0, lambda emu, k: r.choice(owners)),
                0x220: mk('v220', 4, 1, 4), 0x224: mk('v224', 5, 1, 4),
                0x88: mk('v88', 15, 1, 4, stackmark=(0,), side2=True),
                0x80: mk('v80', 6, 2, 8, stackmark=(0, 1), wr=[(0, 48), (1, 48)])}
    P12S = {}
    owners = []
    F0 = struct.unpack('<f', struct.pack('<f', r.uniform(0.5, 3.0)))[0]
    def f32(x): return struct.unpack('<f', struct.pack('<f', x))[0]
    def f214(emu):
        if emu.reg('ecx') == T: return F0
        return r.choice([f32(f32(F0) * 64.0), f32(f32(F0) / 64.0), F0, r.uniform(0.1, 3.0), f32(F0 * 63.0), f32(F0 / 65.0)])
    VT = mkvt(None)
    def newo(F=0x200015):
        o = obj(c, 0x40, VT); objs.append(o)
        P = rnd(c, 0x40); c.emu.wbytes(P, fl(12, -1, 1)); P12S[len(objs) - 1] = P
        Fo = rnd(c, 0x40); c.emu.w32(Fo + 0x23, F)
        c.emu.w32(o + 0xc, Fo)
        c.emu.wbytes(o + 0x20, bytes([r.choice([0, 1, 1, 1])]))
        nm = rnd(c, 0x20); c.emu.wbytes(nm, bytes(r.randrange(97, 123) for _ in range(r.choice([1, 4]))) + b'\0')
        c.emu.w32(o + 4, r.choice([0, nm]))
        i2 = rnd(c, 0x80); c.emu.wbytes(i2, fl(32, 0.0, 3.0)); c.emu.wbytes(i2 + 0x4c, struct.pack('<f', r.choice([499.0, 500.0, 501.0, 600.0, 10.0]))); c.emu.wbytes(i2 + 0x50, struct.pack('<f', r.choice([499.0, 500.0, 501.0, 600.0, 10.0]))); c.emu.w32(o + 8, i2)
        return o
    ne = r.choice([0, 1, 2, 3])
    elems = [rnd(c, 0x10) for _ in range(ne)]
    omap = {}
    for e in elems:
        omap[e] = newo(r.choice([0x200015, 0x200015, 0x1234]))
    # T becomes a normal obj
    TV = c.emu.alloc(0x400, 4)
    for off, st in VT.items(): c.emu.w32(TV + off, st)
    c.emu.w32(T, TV); objs.append(T)
    P12S[len(objs) - 1] = P12
    owners.extend([T] + list(omap.values()))
    # edi list (T+0x52)
    ee = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2]))]
    for e in list(omap)[:1]:
        if r.random() < 0.7 and ee: ee[0] = e
    EV0 = reftab_vt(c, list(elems) if r.random() < 0.5 else ee)
    EO = rnd(c, 0x20); c.emu.w32(EO, EV0)
    c.emu.w32(T + 0x52, r.choice([0, EO, EO]))
    for e in ee:
        if e not in omap: omap[e] = newo()
    LV = reftab_vt(c, list(elems))
    lastc = [0]
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(7): (lastc.__setitem__(0, emu.reg('ecx')), emu.w32(emu.reg('ecx'), LV), _s(emu, k)))
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('dtR', emu.reg('ecx') - lastc[0])), _s(emu, k)))
    hook_rec(c, 0x4cdb90, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('rstR', emu.reg('ecx') - lastc[0])), _s(emu, k)))
    hook_rec(c, 0x4dc630, 2, ret=rnd32, pop=8, this=True, side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('c630', [emu.arg32(0), emu.arg32(1)], emu.reg('ecx') - 0)), _s(emu, k)))
    m58 = mk('m58', 11, 1, 4, lambda emu, k: omap.get(emu.arg32(0), 0))
    m4c = mk('m4c', 12, 1, 4)
    OA = obj(c, 0x40, {0x2dc: pystub(c, 8, ret=rnd32, pop=32, this=True, stackmark=(1, 2, 3, 4), side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('2dc', [emu.arg32(i) for i in (0, 5, 6, 7)], emu.rbytes(emu.arg32(2), 48).hex(), emu.rbytes(emu.arg32(3), 48).hex(), emu.rbytes(emu.arg32(4), 12).hex())), _s(emu, k)))})
    so = sysobj(c, slots={}, table_slots={0x58: m58, 0x4c: m4c}, table_size=0xb00)
    MG = c.emu.r32(so + 0x9b); c.emu.w32(MG + 0xadc, OA)
    def s2c(emu, k, _s=mkside(14)):
        sp = emu.reg('esp') + 4
        emu.calllog.append(('log', emu.r32(sp + 4), [cstr(emu, emu.r32(sp + 8 + 4 * q)).hex() for q in range(4)]))
        _s(emu, k)
    LO = obj(c, 0x40, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)

    def tap(addr, name, spec):
        def h(emu, res, name=name, spec=spec):
            esp = emu.reg('esp')
            if _os.environ.get('W3F_COV'): _COV.setdefault(name, [0])[0] += 1
            out = [name]
            for kind, v, n in spec:
                if kind == 'r': a_ = emu.reg(v)
                else: a_ = emu.r32(esp + 4 + 4 * v)
                if n: out.append(emu.rbytes(a_, n).hex())
                else: out.append(a_)
            emu.calllog.append(tuple(out))
        c.emu.hook(addr, h)
    tap(0x441970, 'tap1970', [('r', 'edx', 12), ('a', 0, 48)])
    tap(0x441940, 'tap1940', [('r', 'ecx', 12), ('r', 'edx', 12)])
    tap(0x446ee0, 'tap6ee0', [('r', 'edx', 12), ('a', 0, 12)])
    tap(0x43e920, 'tap920', [('r', 'edx', 12), ('a', 0, 12)])
    tap(0x4e0d80, 'tapd80', [('r', 'ecx', 12), ('a', 0, 0)])
    import atexit, os
    if os.environ.get('W3F_COV'):
        _cv = _COV.setdefault('n', [0, 0, 0])
        _cv[0] += 1
        def _h(emu, res): _cv[1] += 1
        c.emu.hook(0x4e29c0, lambda emu, res: (_cv.__setitem__(1, _cv[1] + 1)))
    tap(0x4e29c0, 'tap9c0', [('r', 'edx', 48), ('a', 1, 48), ('a', 3, 12), ('a', 0, 0), ('a', 2, 0)])
    tap(0x4e2bb0, 'tapbb0', [('r', 'ecx', 48), ('r', 'edx', 0)])
    if r.random() < 0.6:
        TIE[0] = True
        c.emu.wbytes(P12, struct.pack('<fff', 0.0, 0.0, 0.0))
        for oi_, Pq in list(P12S.items()):
            if oi_ == len(objs) - 1: continue
            c.emu.wbytes(Pq, struct.pack('<fff', *r.choice([(0.0, 0.0, 7.0), (0.0, 0.0, 7.0), (0.0, 0.0, 6.9), (0.0, 0.0, 7.1), (0.5, 0.5, 0.5), (3.0, 4.0, 0.0), (1.0, 2.0, 3.0), (-2.0, 1.0, 5.0)])))
        n995 = struct.unpack('<f', struct.pack('<f', -0.995))[0]
        TV3 = r.choice([(0.0, 0.0, 1.0), (0.0, 0.0, 1.0), (0.3, -0.4, 0.8660254), (0.6, 0.0, 0.8), (-0.48, 0.64, 0.6)])
        def s_a50(emu, k, _s=mkside(39)):
            o = emu.reg('ecx')
            vec = TV3 if o == T else (r.choice([(0.0, 0.0, n995), (0.0, 0.0, n995), (0.0, 0.0, -1.0), (0.01, 0.0, -0.999), (0.0, 0.0, -0.99)]) if TV3 == (0.0, 0.0, 1.0) else (-TV3[0], -TV3[1], -TV3[2]))
            emu.wbytes(emu.arg32(0), struct.pack('<fff', *vec))
            emu.calllog.append(('a50', idx(emu), vec))
            _s(emu, k)
        hook_rec(c, 0x453a50, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s_a50)
    return [T]


S(0x453390, 'GUESS hand 0x453390', 'thiscall', None, ret='eax', gen=g453390, note='batch232013')


def g588a00(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    TS = 0x2d00
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    G = rnd(c, 0xe0); VG = rnd(c, 0x80); c.emu.w32(G, VG); c.emu.w32(0x70039c, G)
    strs = []
    for _ in range(8):
        v = r.choice([0.0, 1.0, -1.0, 0.5, 2.25, 100.0, -3.75, 0.001, 1e6, r.uniform(-9, 9)])
        s = rnd(c, 0x20); c.emu.wbytes(s, repr(round(v, 4)).encode() + b'\0'); strs.append((s, v))
    pok = r.choice([0.0, 0.3, 0.7, 1.0])
    cur = [None]
    ncall = [0]
    nowrite = r.random() < 0.25
    def s5c(emu, k, _s=mkside(1)):
        ok = r.random() < pok
        if ok:
            s, v = r.choice(strs); emu.w32(emu.arg32(1), s); cur[0] = (s, v)
        emu.calllog.append(('v5c', emu.reg('ecx') == G, emu.arg32(0), ok, cur[0][0] if ok else 0))
        _s(emu, k)
        return 0x100 | (1 if ok else 0) if False else None
    ok_state = {'ok': False}
    def r5c(emu, k): return (r.getrandbits(24) << 8) | (1 if ok_state['ok'] else 0)
    def s5c2(emu, k, _s=mkside(1)):
        ok = r.random() < pok
        ok_state['ok'] = ok
        first = (ncall[0] == 0); ncall[0] += 1
        if ok:
            s, v = r.choice(strs)
            if not (first and nowrite):
                emu.w32(emu.arg32(1), s)
            cur[0] = (s, v)
        emu.calllog.append(('v5c', emu.reg('ecx') == G, emu.arg32(0), ok, cur[0][0] if ok else 0))
        _s(emu, k)
    c.emu.w32(VG + 0x5c, pystub(c, 2, ret=r5c, pop=8, this=True, stackmark=(1,), side=s5c2))
    def fatof(emu, k):
        s = emu.arg32(0)
        for ss, v in strs:
            if ss == s: return float(struct.unpack('<f', struct.pack('<f', v))[0])
        return 0.0
    def satof(emu, k):
        emu.calllog.append(('atof', emu.rbytes(emu.arg32(0), 12).split(b'\0')[0].hex()))
    c.emu.w32(0x6762d4, pystub(c, 1, pop=0, this=False, st0=fatof, side=satof))
    hook_rec(c, 0x634123, 5, ret=rnd32, pop=20, this=False, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('a123', emu.arg32(0) - T, emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4))), _s(emu, k)))
    return [T]


S(0x588a00, 'GUESS hand 0x588a00', 'thiscall', None, ret='eax', gen=g588a00, note='batch232014')


def g4acf30(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x200
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(40)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def mkstr(txt=None):
        s = rnd(c, 0x20)
        c.emu.wbytes(s, (txt if txt is not None else bytes(r.choice(b'abc') for _ in range(r.choice([1, 3, 5])))) + b'\0')
        return s
    exe_str = c.emu.rbytes(0x690bf4, 32).split(b'\0')[0]
    # objects
    VO = rnd(c, 0x400)
    allobjs = []
    flagsd = {}
    FLAGKEYS = (0x1007d1, 0x1007d3, 0x1007d5, 0x1007d8)
    strpool = [mkstr(exe_str), mkstr(exe_str), mkstr(), 0]
    def mkobj():
        o = rnd(c, 0x40); c.emu.w32(o, VO)
        c.emu.w32(o + 4, r.choice(strpool))
        flagsd[o] = {k: (r.random() < 0.5) for k in FLAGKEYS}
        allobjs.append(o); return o
    for _ in range(5): mkobj()
    B, O2, O3, O4, OX = allobjs
    ids = {101: B, 102: O2, 103: O3, 104: O4}
    a1 = r.choice([101, 101, 101, 7])
    if a1 == 7: pass
    id4 = r.choice([0, 104])
    c.emu.w32(T + 0x6a, id4)
    c.emu.wbytes(T + 0x48, bytes([r.getrandbits(8), r.getrandbits(8)]))
    # P (T+0x44)
    P = rnd(c, 0x20); VP = rnd(c, 0x400); c.emu.w32(P, VP); c.emu.w32(T + 0x44, P)
    pflag = r.random() < 0.6
    VT = rnd(c, 0x200); c.emu.w32(T, VT)
    SUB = c.emu.alloc(0x20, 4); VSUB = rnd(c, 0x20); c.emu.w32(T + 0x11a, VSUB)
    # manager
    G = rnd(c, 0xe0); c.emu.w32(0x70039c, G)
    MG = rnd(c, 0xae0 + 8); VMG = rnd(c, 0x200); c.emu.w32(MG, VMG); c.emu.w32(G + 0x9b, MG)
    c.emu.w32(MG + 0xadc, r.getrandbits(32))
    DEV = rnd(c, 0x10); VDV = rnd(c, 0x100); c.emu.w32(DEV, VDV)
    LGO = rnd(c, 0x10); VLO = rnd(c, 0x60); c.emu.w32(LGO, VLO); c.emu.w32(0x700390, LGO)
    LG = rnd(c, 0x10); VLG = rnd(c, 0x60); c.emu.w32(LG, VLG)
    S1, S2, S3 = rnd(c, 0x10), rnd(c, 0x10), rnd(c, 0x10)
    CSV = {S1: mkstr(b'one'), S2: mkstr(b'two'), S3: mkstr(b'three')}
    id2_ret = r.choice([0, 102, 102, 102])
    id3 = r.choice([103, 103, 0, 99])
    eidmap = ids
    def oi(emu):
        e = emu.reg('ecx'); return allobjs.index(e) if e in allobjs else ('P' if e == P else ('T' if e == T else -1))
    def fill(emu): emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(16)))
    # object vtable VO
    def s1e0(emu, k, _s=mkside(0)):
        o = emu.reg('ecx'); a = emu.arg32(0)
        v = flagsd[o].get(a, False)
        emu.calllog.append(('o1e0', oi(emu), a, v)); _s(emu, k)
    c.emu.w32(VO + 0x1e0, pystub(c, 1, ret=lambda emu, k: (r.getrandbits(24) << 8) | (1 if flagsd[emu.reg('ecx')].get(emu.arg32(0), False) else 0), pop=4, this=True, side=s1e0))
    def vo(off, tag, n, retf, j):
        c.emu.w32(VO + off, pystub(c, n, ret=retf, pop=4 * n, this=True, side=lambda emu, k, _s=mkside(j): (emu.calllog.append((tag, oi(emu), [emu.arg32(q) for q in range(n)])), _s(emu, k))))
    vo(0x2e8, 'o2e8', 0, lambda emu, k: r.choice(allobjs), 1)
    vo(0x210, 'o210', 1, rnd32, 2)
    vo(0x2c4, 'o2c4', 1, rnd32, 3)
    vo(0x31c, 'o31c', 0, rnd32, 4)
    vo(0x320, 'o320', 0, rnd32, 5)
    vo(0x328, 'o328', 1, rnd32, 6)
    vo(0x2d0, 'o2d0', 2, rnd32, 7)
    vo(0x2f0, 'o2f0', 1, rnd32, 8)
    vo(0xbc, 'obc', 1, rnd32, 9)
    vo(0x128, 'o128', 3, rnd32, 10)
    c.emu.w32(VO + 0x1d8, pystub(c, 2, ret=lambda emu, k: S3, pop=8, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(11): (fill(emu), emu.calllog.append(('o1d8', oi(emu), emu.arg32(1))), _s(emu, k))))
    # P vtable
    c.emu.w32(VP + 0x1d8, pystub(c, 2, ret=lambda emu, k: r.choice([S1, S2]), pop=8, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(12): (fill(emu), emu.calllog.append(('p1d8', emu.arg32(1))), _s(emu, k))))
    c.emu.w32(VP + 0x1e0, pystub(c, 1, ret=lambda emu, k: (r.getrandbits(24) << 8) | (1 if pflag else 0), pop=4, this=True, side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('p1e0', emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VP + 0x128, pystub(c, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(14): (emu.calllog.append(('p128', emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VP + 0x20, pystub(c, 1, ret=lambda emu, k: 0x555, pop=4, this=True, side=lambda emu, k, _s=mkside(15): (emu.calllog.append(('p20', emu.arg32(0))), _s(emu, k))))
    # T vtable / sub
    c.emu.w32(VT + 0x98, pystub(c, 2, ret=lambda emu, k: id3, pop=8, this=True, side=lambda emu, k, _s=mkside(16): (emu.calllog.append(('t98', emu.arg32(0) in allobjs, emu.arg32(1))), _s(emu, k))))
    c.emu.w32(VSUB + 4, pystub(c, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(17): (emu.calllog.append(('sub4', emu.reg('ecx') - T, emu.arg32(0))), _s(emu, k))))
    # manager vtable
    c.emu.w32(VMG + 0x58, pystub(c, 1, ret=lambda emu, k: ids.get(emu.arg32(0), 0) if not (emu.arg32(0) == 101 and nob) else 0, pop=4, this=True, side=lambda emu, k, _s=mkside(18): (emu.calllog.append(('m58', emu.arg32(0))), _s(emu, k))))
    c.emu.w32(VMG + 0x4c, pystub(c, 2, ret=lambda emu, k: (id2_ret if emu.arg32(1) == 0x4954454d else 0x4d2), pop=8, this=True, side=lambda emu, k, _s=mkside(19): (emu.calllog.append(('m4c', emu.arg32(0) == P, emu.arg32(1))), _s(emu, k))))
    c.emu.w32(VMG + 0x114, pystub(c, 6, ret=rnd32, pop=24, this=True, side=lambda emu, k, _s=mkside(20): (emu.calllog.append(('m114', [emu.arg32(q) for q in range(6)])), _s(emu, k))))
    c.emu.w32(VMG + 0x138, pystub(c, 0, ret=lambda emu, k: DEV, pop=0, this=True, side=mkside(21)))
    outv = r.choice([0, 104])
    def s88(emu, k, _s=mkside(22)):
        emu.w32(emu.arg32(1), outv); emu.calllog.append(('d88', emu.arg32(0))); _s(emu, k)
    c.emu.w32(VDV + 0x88, pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=s88))
    # logger
    c.emu.w32(VLO + 0x20, pystub(c, 2, ret=lambda emu, k: LG, pop=8, this=True, side=lambda emu, k, _s=mkside(23): (emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1))), _s(emu, k))))
    def cs(emu, a): return emu.rbytes(a, 8).split(b'\0')[0].hex()
    def s2c(emu, k, _s=mkside(24)):
        fmt = emu.arg32(1)
        n = {0x690b78: 3, 0x690bb0: 4}.get(fmt, 3)
        emu.calllog.append(('l2c', emu.arg32(0) == LG, fmt, [cs(emu, emu.arg32(q)) for q in range(2, n)]))
        _s(emu, k)
    c.emu.w32(VLG + 0x2c, pystub(c, 0, ret=rnd32, pop=0, this=False, side=s2c))
    # strcmp import
    def strcmp(emu, k):
        a, b = emu.arg32(0), emu.arg32(1)
        x = emu.rbytes(a, 32).split(b'\0')[0]; y = emu.rbytes(b, 32).split(b'\0')[0]
        return 0 if x == y else (1 if x > y else 0xffffffff)
    c.emu.w32(0x676414, pystub(c, 2, pop=0, this=False, ret=strcmp, side=lambda emu, k, _s=mkside(25): (emu.calllog.append(('cmp', cs(emu, emu.arg32(0)), cs(emu, emu.arg32(1)))), _s(emu, k))))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: CSV.get(emu.reg('ecx'), CSV[S1]), pop=0, this=True, side=lambda emu, k, _s=mkside(26): (emu.calllog.append(('c1d0', emu.reg('ecx') in CSV)), _s(emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(27): (emu.calllog.append(('bec0', emu.rbytes(emu.reg('ecx'), 16).hex())), emu.wbytes(emu.reg('ecx'), b'\xdd' * 16), _s(emu, k)))
    import os
    if os.environ.get('W3F_SPEC'): print('ADDR', c.case, {'T': hex(T), 'B': hex(B), 'O2': hex(O2), 'O3': hex(O3), 'O4': hex(O4), 'OX': hex(OX), 'P': hex(P), 'MG': hex(MG), 'G': hex(G), 'VO': hex(VO), 'VP': hex(VP), 'LG': hex(LG), 'S1': hex(S1), 'S2': hex(S2), 'S3': hex(S3), 'DEV': hex(DEV)})
    return [T, a1]


nob = False
S(0x4acf30, 'GUESS hand 0x4acf30', 'thiscall', None, ret='eax', gen=g4acf30, note='batch232015')


def g5a6980(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x960
    T = rnd(c, TS)
    c.emu.wbytes(T + 0x658, bytes([r.choice([0, 0, 1, 1, 0x7f])]))
    sr = [seh_record(c, 2) for _ in range(30)]
    def mkside(j):
        def side(emu, k):
            import pe_emu as _pe
            _h = emu.r32(_pe.TEB)
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T + 0x430, 0x4b0)), emu.r32(_h + 8) if _h not in (0, 0xffffffff) else -2))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def mkvec(off):
        n0 = r.choice([0, 1, 3]); room = r.choice([0, 1, 2, 90])
        B = rnd(c, 4 * (n0 + room + 2))
        c.emu.wbytes(T + off, b''.join(__import__('struct').pack('<I', x) for x in (B, B + 4 * n0, B + 4 * (n0 + room))))
    for off in (0x659, 0x665, 0x671): mkvec(off)
    blocks = []
    def newblock(sz=0x100):
        b = rnd(c, max(sz, 0x20)); blocks.append(b); return b
    def bi(a): return blocks.index(a) if a in blocks else (-1 if a else 0)
    failp = r.choice([0.0, 0.0, 0.05])
    def ralloc(emu, k):
        if r.random() < failp: return 0
        return newblock(emu.arg32(0))
    hook_rec(c, 0x41e290, 1, ret=ralloc, pop=0, this=False, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('al', emu.arg32(0))), _s(emu, k)))
    def ctor(addr, name, n, j):
        hook_rec(c, addr, n, ret=lambda emu, k: emu.reg('ecx'), pop=4 * n, this=True, side=lambda emu, k, _s=mkside(j): (emu.calllog.append((name, bi(emu.reg('ecx')), [emu.arg32(q) for q in range(n)])), _s(emu, k)))
    ctor(0x5ed460, 'c460', 0, 1); ctor(0x5ec720, 'c720', 1, 2); ctor(0x5edd80, 'cd80', 1, 3); ctor(0x5f0020, 'c020', 0, 4)
    ctor(0x5ebae0, 'cae0', 1, 5); ctor(0x5eec40, 'cc40', 0, 6); ctor(0x5efd10, 'cd10', 0, 7); ctor(0x5ef080, 'c080', 0, 8); ctor(0x5ab2e0, 'c2e0', 1, 9)
    import struct
    def s3b0(emu, k, _s=mkside(10)):
        vec = emu.reg('ecx'); pos = emu.arg32(0); v = emu.r32(emu.arg32(1))
        B, E, C = emu.r32(vec), emu.r32(vec + 4), emu.r32(vec + 8)
        n = (E - B) // 4; cap = (C - B) // 4
        emu.calllog.append(('g3b0', vec - T, pos == E, n, cap, bi(v)))
        nc = max(2 * cap, 4)
        nb = rnd(c, 4 * nc + 16)
        emu.wbytes(nb, emu.rbytes(B, 4 * n))
        emu.w32(nb + 4 * n, v)
        emu.wbytes(vec, struct.pack('<III', nb, nb + 4 * (n + 1), nb + 4 * nc))
        _s(emu, k)
    hook_rec(c, 0x5fe3b0, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=s3b0)
    # global text with key strings
    keys = [c.emu.rbytes(a, 32).split(b'\0')[0] for a in (0x6afec4, 0x6afed0, 0x6afed8, 0x6afee4, 0x6afeec)]
    parts = []
    for _ in range(r.choice([2, 5, 9])):
        parts.append(r.choice([b';', b'ab', b'xyz', b';;', r.choice(keys), r.choice(keys)]))
    txt = b''.join(parts) + b'\0'
    if r.random() < 0.25: txt = b'\0'
    S = rnd(c, len(txt) + 16)
    c.emu.wbytes(S, txt)
    c.emu.w32(0x6ed270, S)
    def sstr(emu, k):
        s = emu.arg32(0); key = emu.rbytes(emu.arg32(1), 32).split(b'\0')[0]
        body = emu.rbytes(s, len(txt) + 1).split(b'\0')[0]
        i = body.find(key)
        return (s + i) if i >= 0 else 0
    c.emu.w32(0x67625c, pystub(c, 2, pop=0, this=False, ret=sstr, side=lambda emu, k, _s=mkside(11): (emu.calllog.append(('strstr', emu.arg32(0) == S, emu.rbytes(emu.arg32(1), 12).split(b'\0')[0].hex())), _s(emu, k))))
    return [T]


S(0x5a6980, 'GUESS hand 0x5a6980', 'thiscall', None, ret='eax', gen=g5a6980, note='batch232016')
