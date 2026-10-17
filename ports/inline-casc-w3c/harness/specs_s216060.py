"""specs_s216060.py - Sonnet-w3c hand specs."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g448a30(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x40
    this = rnd(c, 0x40)
    VTH = rnd(c, 0x40); c.emu.w32(this, VTH)
    OBJ = rnd(c, 0x20); OBJV = rnd(c, 0x240); c.emu.w32(OBJ, OBJV)
    L = rnd(c, 0x20); LV = rnd(c, 0x80); c.emu.w32(L, LV); c.emu.w32(0x700390, L)
    LOGO = rnd(c, 0x20); LOGV = rnd(c, 0x80); c.emu.w32(LOGO, LOGV)
    c.emu.w32(this + 0x18, r.getrandbits(32)); c.emu.w32(this + 8, r.getrandbits(32))
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    c.emu.w32(VTH + 0x20, pystub(c, 0, ret=lambda emu, k: OBJ, this=True, side=mkside(11)))
    c.emu.w32(OBJV + 0x1d8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=mkside(11)))
    c.emu.w32(LV + 0x20, pystub(c, 2, ret=lambda emu, k: LOGO, this=True, side=mkside(11)))
    c.emu.w32(LOGV + 0x30, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(11)))
    SEQ = [r.choice([1, 1, 0, 2]), r.choice([3, 3, 4, 0])]
    CI = [0]
    def ret1600(emu, k):
        v = SEQ[CI[0] % 2]; CI[0] += 1; return v | (r.getrandbits(24) << 8)
    def side_wr(emu, k, _s=mkside(3)):
        _s(emu, k)
        emu.w32(emu.arg32(0), r.choice([0, 0, 1, r.getrandbits(32)]))
    def hk(addr, n, pop, this_, j, ret=None, stackmark=(), side=None):
        def sd(emu, k, _s=mkside(j)):
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=(side or sd))
    hk(0x610100, 1, 4, False, 0)
    hk(0x4e1600, 0, 0, True, 1, ret=ret1600)
    hk(0x4e12f0, 2, 8, True, 2, stackmark=(0,), side=side_wr)
    hk(0x4e11e0, 2, 8, True, 4, stackmark=(0,), side=side_wr)
    hk(0x4e1b30, 0, 0, True, 5)
    hk(0x4690b0, 0, 0, True, 6)
    hk(0x4cc1d0, 0, 0, True, 7)
    hk(0x4cbec0, 0, 0, 'mark', 8)
    return [this, rnd(c, 0x20)]


def g50c900(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x40
    this = rnd(c, 0x40)
    A = rnd(c, 0x20)
    G = rnd(c, 0x20); GV = rnd(c, 0x20); c.emu.w32(G, GV); c.emu.w32(0x70039c, G)
    TB = rnd(c, 0x20); TBV = rnd(c, 0x160); c.emu.w32(TB, TBV); c.emu.w32(G + 0x9b, TB)
    L = rnd(c, 0x20); LV = rnd(c, 0x80); c.emu.w32(L, LV); c.emu.w32(0x700390, L)
    LOGO = rnd(c, 0x20); LOGV = rnd(c, 0x80); c.emu.w32(LOGO, LOGV)
    RO = rnd(c, 0x20); ROV = rnd(c, 0x100); c.emu.w32(RO, ROV)
    XO = rnd(c, 0x20); XOV = rnd(c, 0x140); c.emu.w32(XO, XOV)
    YO = rnd(c, 0x20); YOV = rnd(c, 0x280); c.emu.w32(YO, YOV)
    ENT = []
    for _ in range(6):
        e = rnd(c, 0x10); c.emu.w32(e, r.getrandbits(32)); ENT.append(e)
    EI = [0]
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    TI = [0]
    def ret58(emu, k):
        # first call: X (or 0), second call: Y (or 0)
        n = TI[0]; TI[0] += 1
        if n == 0: return XO
        return YO
    c.emu.w32(TBV + 0x58, pystub(c, 1, ret=ret58, this=True, side=mkside(11)))
    c.emu.w32(TBV + 0x138, pystub(c, 0, ret=lambda emu, k: RO, this=True, side=mkside(11)))
    def side_88(emu, k, _s=mkside(11)):
        _s(emu, k)
        emu.w32(emu.arg32(1), r.getrandbits(32))
    c.emu.w32(ROV + 0x88, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(1,), side=side_88))
    c.emu.w32(TBV + 0x114, pystub(c, 5, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(4,), side=mkside(11)))
    c.emu.w32(YOV + 0x25c, pystub(c, 2, ret=lambda emu, k: (0), this=True, side=mkside(11)))
    c.emu.w32(XOV + 0x130, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(11)))
    c.emu.w32(LV + 0x20, pystub(c, 2, ret=lambda emu, k: LOGO, this=True, side=mkside(11)))
    def side_2c(emu, k, _s=mkside(11)):
        _s(emu, k)
        if emu.arg32(1) == 0x69d974: emu.calllog.append(('a2', emu.arg32(2)))
    c.emu.w32(LOGV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=side_2c))
    def r3d0(emu, k):
        v = ENT[EI[0] % 6]; EI[0] += 1; return v
    def hk(addr, n, pop, this_, j, ret=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x5003d0, 1, 4, True, 0, ret=r3d0)
    hk(0x5002f0, 1, 4, True, 1)
    hk(0x506040, 0, 0, True, 2)
    hk(0x41e680, 0, 0, True, 3)
    hk(0x4d2280, 0, 0, 'mark', 4)
    hk(0x4d3ad0, 3, 12, 'mark', 5)
    hk(0x4d2ed0, 1, 4, 'mark', 6)
    hk(0x4d2330, 0, 0, 'mark', 7)
    return [this, A]


def g600c70(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x10
    this = rnd(c, 0x10)
    STR = rnd(c, 0x20); c.emu.wbytes(STR, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 3, 9]))) + b'\0')
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    def alloc(emu, k):
        sz = emu.arg32(0)
        if sz == 0xc and r.random() < 0.2: return 0
        return rnd(c, 0x40)
    def hk(addr, n, pop, this_, j, ret=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x41e290, 1, 0, False, 0, ret=alloc)
    hk(0x5f2d60, 2, 8, True, 1)
    hk(0x42b390, 2, 8, True, 2, ret=lambda emu, k: rnd(c, 0x10), stackmark=(1,))
    return [this, STR, r.getrandbits(32)]


def g600e40(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x10
    this = rnd(c, 0x10)
    STR = rnd(c, 0x20); c.emu.wbytes(STR, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 3, 9]))) + b'\0')
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    def alloc(emu, k):
        sz = emu.arg32(0)
        if sz == 0xc and r.random() < 0.2: return 0
        return rnd(c, 0x40)
    def hk(addr, n, pop, this_, j, ret=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x41e290, 1, 0, False, 0, ret=alloc)
    hk(0x5f2d60, 2, 8, True, 1)
    return [this, STR, r.getrandbits(32)]


def g600f20(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x10
    this = rnd(c, 0x10)
    STR = rnd(c, 0x20); c.emu.wbytes(STR, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 3, 9]))) + b'\0')
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    def alloc(emu, k):
        sz = emu.arg32(0)
        if sz == 0xc and r.random() < 0.2: return 0
        return rnd(c, 0x40)
    def hk(addr, n, pop, this_, j, ret=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x41e290, 1, 0, False, 0, ret=alloc)
    hk(0x5f2d60, 2, 8, True, 1)
    hk(0x42b390, 2, 8, True, 2, ret=lambda emu, k: rnd(c, 0x10), stackmark=(1,))
    return [this, STR, r.getrandbits(32), r.getrandbits(32)]


def g42c380(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x40
    this = rnd(c, 0x40)
    VTH = rnd(c, 0x140); c.emu.w32(this, VTH)
    DST = rnd(c, 0x40)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    def fill16(emu, addr):
        emu.wbytes(addr, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, addr, tag):
        emu.calllog.append((tag, emu.rbytes(addr, 16).hex()))
    def side_11c(emu, k, _s=mkside(9)):
        _s(emu, k)
        fill16(emu, emu.arg32(0))
    c.emu.w32(VTH + 0x11c, pystub(c, 1, ret=lambda emu, k: rnd(c, 0x10), this=True, stackmark=(0,), side=side_11c))
    def hk(addr, n, pop, this_, j, ret=None, stackmark=(), act=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    def a_ctor(emu): fill16(emu, emu.reg('ecx'))
    def a_assign(emu):
        a = emu.arg32(0); e = emu.reg('ecx')
        log16(emu, e, 'Ldst')
        if 0x0f000000 <= a < 0x10000000: log16(emu, a, 'Lsrc')
        fill16(emu, e)
    def a_len(emu): log16(emu, emu.reg('ecx'), 'Llen')
    def a_dtor(emu): log16(emu, emu.reg('ecx'), 'Ldtor')
    def a_copy(emu):
        a = emu.arg32(0); e = emu.reg('ecx')
        emu.wbytes(e, emu.rbytes(a, 16))
    def a_cat(emu):
        a = emu.arg32(0); e = emu.reg('ecx')
        log16(emu, a, 'Lcat_src'); log16(emu, e, 'Lcat_dst'); fill16(emu, e)
    hk(0x4cbeb0, 0, 0, 'mark', 0, act=a_ctor)
    hk(0x4cbee0, 1, 4, 'mark', 1, stackmark=(0,), act=a_assign)
    hk(0x4cc5f0, 0, 0, 'mark', 2, ret=lambda emu, k: (0 if r.random() < 0.4 else r.randrange(1, 100)), act=a_len)
    hk(0x4cbe50, 1, 4, True, 3, stackmark=(0,), act=a_copy)
    hk(0x4cbe80, 1, 4, 'mark', 4, act=a_ctor)
    hk(0x4cc2c0, 1, 4, 'mark', 5, stackmark=(0,), act=a_cat)
    hk(0x4cbec0, 0, 0, 'mark', 6, act=a_dtor)
    return [this, DST]


def g434bf0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x10
    this = rnd(c, 0x10)
    VTH = rnd(c, 0x60); c.emu.w32(this, VTH)
    OB = rnd(c, 0x10); OBV = rnd(c, 0x40); c.emu.w32(OB, OBV)
    STR = rnd(c, 0x40)
    c.emu.wbytes(STR, bytes(r.choice(b'ab\\/c') for _ in range(r.randrange(0, 16))) + b'\0')
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j, rec=False):
        def side(emu, k):
            emu.calllog.append(('vt', emu.r32(this), zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    c.emu.w32(VTH + 0x50, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(5)))
    c.emu.w32(OBV + 0x34, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(5)))
    def strrchr_like(emu, k):
        base = emu.arg32(0)
        n = 0
        while emu.rbytes(base + n, 1)[0] != 0 and n < 64: n += 1
        if r.random() < 0.4: return 0
        return base + r.randrange(0, n + 1)
    c.emu.w32(0x676258, pystub(c, 2, ret=strrchr_like, pop=0, this=False, side=mkside(4)))
    def alloc(emu, k):
        sz = emu.arg32(0)
        if sz == 0x6f: return OB
        return rnd(c, sz + 16)
    def hk(addr, n, pop, this_, j, ret=None):
        def sd(emu, k, _s=mkside(j)):
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, side=sd)
    hk(0x41e290, 1, 0, False, 0, ret=alloc)
    hk(0x4d5440, 0, 0, True, 1, ret=lambda emu, k: emu.reg('ecx'))
    hk(0x634273, 2, 0, False, 2)
    return [this, STR]


S(0x448a30, 'GUESS hand 0x448a30', 'thiscall', None, ret='eax', gen=g448a30, note='batch216060')
S(0x50c900, 'GUESS hand 0x50c900', 'thiscall', None, ret='eax', gen=g50c900, note='batch216060')
S(0x600c70, 'GUESS hand 0x600c70', 'thiscall', None, ret='eax', gen=g600c70, note='batch216060')
S(0x600e40, 'GUESS hand 0x600e40', 'thiscall', None, ret='eax', gen=g600e40, note='batch216060')
S(0x600f20, 'GUESS hand 0x600f20', 'thiscall', None, ret='eax', gen=g600f20, note='batch216060')
S(0x42c380, 'GUESS hand 0x42c380', 'thiscall', None, ret='eax', gen=g42c380, note='batch216060')
S(0x434bf0, 'GUESS hand 0x434bf0', 'thiscall', None, ret='eax', gen=g434bf0, note='batch216060')


def g441e40(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    MV = rnd(c, 0x10)
    mode = r.random()
    if mode < 0.5:
        c.emu.w32(0x6ff968, 0)
    else:
        M = rnd(c, 0x10); c.emu.w32(M, MV); c.emu.w32(0x6ff968, M)
    NEWM = rnd(c, 0x10); c.emu.w32(NEWM, MV)
    pools = []
    def mkpool():
        p = rnd(c, 0x900)
        c.emu.w16(p + 2, r.choice([0, 0, 1, 2, 7, 0x20, 0x7f]))
        pools.append(p)
        return p
    VT = rnd(c, 0x340)
    def mkobj():
        o = rnd(c, 0x90)
        c.emu.w32(o, VT)
        c.emu.w32(o + 0x7b, 0 if r.random() < 0.5 else mkpool())
        return o
    this = mkobj()
    kids = [mkobj() for _ in range(3)]
    BLOB = rnd(c, 0x20)
    allobj = [this] + kids
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            for o in allobj:
                emu.calllog.append(('vt', zlib.crc32(emu.rbytes(o, 0x90)), zlib.crc32(emu.rbytes(emu.r32(o + 0x7b), 0x40)) if emu.r32(o + 0x7b) else 0))
            emu.calllog.append(('g', emu.r32(0x6ff968)))
            sr[j](emu, k)
        return side
    c.emu.w32(MV + 4, pystub(c, 1, ret=lambda emu, k: mkpool() + 4, this=True, side=mkside(11)))
    c.emu.w32(VT + 0x20, pystub(c, 0, ret=lambda emu, k: r.choice([0, BLOB]), this=True, side=mkside(10)))
    for off in (0x310, 0x30c):
        c.emu.w32(VT + off, pystub(c, 0, ret=lambda emu, k: r.choice([0, 0, 0, 1, 0x100, 0x1ff]), this=True, side=mkside(9)))
    c.emu.w32(BLOB + 8, rnd(c, 0x10))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NEWM, pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x4cca60, 2, ret=lambda emu, k: NEWM, pop=8, this=True, side=mkside(1))
    hook_rec(c, 0x634d10, 3, ret=r.getrandbits(32), pop=0, this=False, side=mkside(3))
    kl = list(kids)
    def nxt(emu, k):
        return 0 if (not kl or r.random() < 0.35) else kl.pop(0)
    hook_rec(c, 0x4db7e0, 0, ret=nxt, pop=0, this=True, side=mkside(8))
    return [this, r.getrandbits(32)]


S(0x441e40, 'GUESS hand 0x441e40', 'thiscall', None, ret='eax', gen=g441e40, note='batch216060')


def g41e4b0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    VT = rnd(c, 0x60)
    this = rnd(c, 0x40); c.emu.w32(this, VT)
    C = rnd(c, 0x40)
    c.emu.w32(C + 0x10, r.choice([0, 1, 5, 100, 0x3ffffffe, 0x3fffffff, 0x40000000, 0x7fffffff, 0xfffffffe, 0xffffffff]))
    HEAP = [rnd(c, 0x40) for _ in range(4)]
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40))))
            sr[j](emu, k)
        return side
    c.emu.w32(VT + 0x44, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    if r.random() < 0.5:
        c.emu.w32(0x70038c, 0)
    else:
        MG = rnd(c, 0x10); MV = rnd(c, 0x20); c.emu.w32(MG, MV); c.emu.w32(0x70038c, MG)
        c.emu.w32(MV + 8, pystub(c, 1, ret=lambda emu, k: r.choice(HEAP), this=True, side=mkside(1)))
    c.emu.w32(0x6762f0, pystub(c, 1, ret=lambda emu, k: r.choice(HEAP), pop=0, this=False, side=mkside(2)))
    hook_rec(c, 0x4cc930, 2, ret=lambda emu, k: C, pop=8, this=True, side=mkside(3))
    hook_rec(c, 0x634d10, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(4))
    return [this]


S(0x41e4b0, 'GUESS hand 0x41e4b0', 'thiscall', None, ret='eax', gen=g41e4b0, note='batch216060')


def g42b2e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x10)
    ln = r.choice([0, 0, 1, 2, 5, 17, 0x40])
    SRC = rnd(c, 0x80)
    a0 = SRC; a1 = SRC + ln
    HEAP = rnd(c, 0x100)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x10)), zlib.crc32(emu.rbytes(HEAP, 0x60))))
            sr[j](emu, k)
        return side
    hook_rec(c, 0x6014a0, 1, ret=lambda emu, k: HEAP, pop=4, this=True, side=mkside(0))
    c.emu.w32(0x676278, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1)))
    return [this, a0, a1, r.getrandbits(32)]


S(0x42b2e0, 'GUESS hand 0x42b2e0', 'thiscall', None, ret='eax', gen=g42b2e0, note='batch216060')


def g42db40(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x40
    this = rnd(c, 0x1c00)
    VT = rnd(c, 0x80); c.emu.w32(this, VT)
    # input text: a few lines of chars incl. CR/LF, whitespace, '/', '='
    alpha = b'ab=;  \t/\r\n\r\n'
    def line():
        n = r.choice([0, 0, 1, 2, 3, 6, 20])
        return bytes(r.choice(alpha) for _ in range(n))
    txt = b''.join(line() + r.choice([b'\n', b'\r\n', b'\r', b'']) for _ in range(r.choice([0, 1, 2, 3, 5])))
    if r.random() < 0.1:
        txt = bytes(r.choice(b'ab c') for _ in range(0x1ff)) + b'\n' + txt
    TXT = rnd(c, len(txt) + 16)
    c.emu.wbytes(TXT, txt + b'\0')
    sr = [seh_record(c, 2) for _ in range(10)]
    def cstr(emu, a):
        out = b''
        while len(out) < 0x230:
            b = emu.rbytes(a + len(out), 1)
            if b == b'\0': break
            out += b
        return out
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x1ab7, 0x20))))
            sr[j](emu, k)
        return side
    def fill(emu, addr, n=16):
        emu.wbytes(addr, bytes(r.getrandbits(8) for _ in range(n)))
    def wstr(emu, addr):
        t = bytes(r.choice(b'abxy/ \t') for _ in range(r.choice([0, 1, 3, 9]))) + b'\0'
        emu.wbytes(addr, t)
    def side68(emu, k, _s=mkside(0)):
        emu.calllog.append(('L68', cstr(emu, emu.arg32(0)).hex()))
        wstr(emu, emu.arg32(1)); wstr(emu, emu.arg32(2))
        _s(emu, k)
    c.emu.w32(VT + 0x68, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0, 1, 2), side=side68))
    def side60(emu, k, _s=mkside(1)):
        emu.calllog.append(('L60', cstr(emu, emu.arg32(0)).hex(), cstr(emu, emu.arg32(1)).hex()))
        _s(emu, k)
    c.emu.w32(VT + 0x60, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0, 1), side=side60))
    def side_cmp(emu, k, _s=mkside(2)):
        emu.calllog.append(('Lcmp', cstr(emu, emu.arg32(0)).hex()))
        _s(emu, k)
    c.emu.w32(0x676414, pystub(c, 2, ret=lambda emu, k: r.choice([0, 0, 1, 0xffffffff]), pop=0, this=False, stackmark=(0,), side=side_cmp))
    def hk(addr, n, pop, j, act, stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this='mark', stackmark=stackmark, side=sd)
    def a_ctor(emu):
        a = emu.arg32(0)
        emu.calllog.append(('Lctor', cstr(emu, a).hex()))
        fill(emu, emu.reg('ecx'))
    def a_asg(emu):
        e = emu.reg('ecx'); a = emu.arg32(0)
        emu.calllog.append(('Lsrc', emu.rbytes(a, 16).hex(), 'Ldst', emu.rbytes(e, 16).hex()))
        fill(emu, e)
    def a_dtor(emu):
        emu.calllog.append(('Ldtor', emu.rbytes(emu.reg('ecx'), 16).hex()))
    hk(0x4cbe80, 1, 4, 3, a_ctor, stackmark=(0,))
    hk(0x4cc2c0, 1, 4, 4, a_asg, stackmark=(0,))
    hk(0x4cbec0, 0, 0, 5, a_dtor)
    return [this, TXT]


S(0x42db40, 'GUESS hand 0x42db40', 'thiscall', None, ret='al', gen=g42db40, note='batch216060')


def g432270(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    VT = rnd(c, 0x80); c.emu.w32(this, VT)
    A0 = rnd(c, 0x20)
    STRA = rnd(c, 0x20)
    def tok():
        pre = r.choice([b'strCC', b'strCC', b'strCr', b'strCx', b'abcde', b'strC'])
        nm = bytes(r.choice(b'abz') for _ in range(r.choice([0, 1, 3])))
        val = (b'=' + bytes(r.choice(b'0123=x') for _ in range(r.choice([0, 1, 3])))) if r.random() < 0.7 else b''
        return pre + nm + val
    parts = [tok() if r.random() < 0.85 else b'' for _ in range(r.choice([0, 1, 2, 3, 4]))]
    txt = b';'.join(parts) + (b';' if r.random() < 0.7 else b'')
    BUF = rnd(c, len(txt) + 64)
    c.emu.wbytes(BUF, txt + bytes(48))
    SB90 = rnd(c, 0x40)
    LOG3 = rnd(c, 0x10); LV3 = rnd(c, 0x40); c.emu.w32(LOG3, LV3)
    LOG2 = rnd(c, 0x10); LV2 = rnd(c, 0x40); c.emu.w32(LOG2, LV2)
    MG = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(MG, MV); c.emu.w32(0x700390, MG)
    G2 = rnd(c, 0x10); GV = rnd(c, 0x80); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    sr = [seh_record(c, 2) for _ in range(12)]
    def cstr(emu, a):
        out = b''
        while len(out) < 0x230:
            b = emu.rbytes(a + len(out), 1)
            if b == b'\0': break
            out += b
        return out
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(BUF, len(txt) + 8))))
            sr[j](emu, k)
        return side
    def fill(emu, addr, n=16):
        emu.wbytes(addr, bytes(r.getrandbits(8) for _ in range(n)))
    mk = [0]
    def l3(emu, k, _s=mkside(0)):
        emu.calllog.append(('L3', cstr(emu, emu.arg32(1)).hex() if False else emu.arg32(1)))
        _s(emu, k)
    c.emu.w32(LV3 + 0x2c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=l3))
    c.emu.w32(LV2 + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1)))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG3 if k == 0 else LOG2, this=True, side=mkside(2)))
    c.emu.w32(VT + 0x68, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3), stackmark=()))
    c.emu.w32(VT + 0x6c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(4)))
    c.emu.w32(GV + 0x60, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(5)))
    def side_atoi(emu, k, _s=mkside(6)):
        emu.calllog.append(('Latoi', cstr(emu, emu.arg32(0)).hex()))
        _s(emu, k)
    c.emu.w32(0x6762d8, pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 7, 300, 0xffffffff]), pop=0, this=False, side=side_atoi))
    def hk(addr, n, pop, j, act, ret=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this='mark', stackmark=stackmark, side=sd)
    def a_copy(emu):
        fill(emu, emu.reg('ecx'))
    def a_ctor(emu):
        fill(emu, emu.reg('ecx'))
    def a_fromint(emu):
        emu.calllog.append(('Lint', emu.arg32(0)))
        fill(emu, emu.reg('ecx'))
    def a_dtor(emu):
        emu.calllog.append(('Ldtor', emu.rbytes(emu.reg('ecx'), 16).hex()))
    hk(0x4cbe50, 1, 4, 7, a_copy)
    hk(0x4cbeb0, 0, 0, 8, a_ctor)
    hk(0x4cbf30, 1, 4, 9, a_fromint)
    hk(0x4cbec0, 0, 0, 10, a_dtor)
    def r1d0(emu, k):
        return STRA if k == 0 else (BUF if k == 1 else (SB90 if k % 2 == 0 else SB90 + 0x20))
    def a_c(emu):
        pass
    hk(0x4cc1d0, 0, 0, 11, a_c, ret=r1d0)
    return [this, A0]


S(0x432270, 'GUESS hand 0x432270', 'thiscall', None, ret='eax', gen=g432270, note='batch216060')


def g5fb400(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x10)
    H = rnd(c, 0x40); N1 = rnd(c, 0x40); N2 = rnd(c, 0x40)
    nodes = [H, N1, N2]
    c.emu.w32(this, H); c.emu.w32(this + 4, r.choice([0, 1, 7, 0xffffffff]))
    def setkey(n, d):
        b = r.getrandbits(32)
        c.emu.w32(n + 0xd, b); c.emu.w32(n + 0x11, (b + d) & 0xffffffff)
        c.emu.w32(n + 0x19, r.getrandbits(32))
    for n in nodes: setkey(n, r.choice([-2, -1, 0, 1, 2, 5]))
    c.emu.w32(H + 5, r.choice([N1, N2, 0]))
    c.emu.w32(H + 9, r.choice([N1, N2, 0]))
    c.emu.w32(H + 1, r.getrandbits(32))
    KEY = rnd(c, 0x20)
    kb = r.getrandbits(32)
    kd = r.choice([-2, -1, 0, 1, 2, 5])
    c.emu.w32(KEY, kb); c.emu.w32(KEY + 4, (kb + kd) & 0xffffffff); c.emu.w32(KEY + 0xc, r.getrandbits(32))
    OUT = rnd(c, 0x10)
    NEW = rnd(c, 0x40); RET5 = rnd(c, 0x40)
    allm = nodes + [NEW, RET5, KEY, this]
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            for m in allm:
                emu.calllog.append(('m', zlib.crc32(emu.rbytes(m, 0x40))))
            sr[j](emu, k)
        return side
    c.emu.w32(0x676408, pystub(c, 3, ret=lambda emu, k: r.choice([0, 0, 0, 1, 0xffffffff, 5, 0xfffffff9]), pop=0, this=False, side=mkside(0)))
    hook_rec(c, 0x5fb2c0, 1, ret=lambda emu, k: r.choice([N1, N2, RET5]), pop=4, this=True, side=mkside(1))
    hook_rec(c, 0x6014a0, 1, ret=lambda emu, k: NEW, pop=4, this=True, side=mkside(2))
    hook_rec(c, 0x5f10c0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(3))
    def sd430(emu, k, _s=mkside(4)):
        emu.calllog.append(('edx', emu.reg('edx')))
        _s(emu, k)
    hook_rec(c, 0x430480, 0, ret=0, pop=0, this=True, side=sd430)
    a2 = r.choice([H, N1, N2])
    a1 = r.choice([0, 0, 0, 1, 0x80000000])
    return [this, OUT, a1, a2, KEY]


S(0x5fb400, 'GUESS hand 0x5fb400', 'thiscall', None, ret='eax', gen=g5fb400, note='batch216060')


def _g4d4(c, which):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    sr = [seh_record(c, 2) for _ in range(4)]
    CELL = rnd(c, 0x10)
    c.emu.w32(CELL, r.getrandbits(32))
    c.emu.w32(0x6763f4 if which == 0 else 0x6763f8, pystub(c, 1 if which == 0 else 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=sr[0]))
    c.emu.w32(0x6763d8, pystub(c, 1, ret=lambda emu, k: r.choice([0, 0, 1, 0xffffffff, 0x100]), pop=0, this=False, side=sr[1]))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=sr[2]))
    if which == 0:
        return [CELL]
    return [r.getrandbits(32), r.getrandbits(32), CELL]


def g4d4a40(c): return _g4d4(c, 0)
def g4d4b20(c): return _g4d4(c, 1)


S(0x4d4a40, 'GUESS hand 0x4d4a40', 'stdcall', None, ret='eax', gen=g4d4a40, note='batch216060')
S(0x4d4b20, 'GUESS hand 0x4d4b20', 'stdcall', None, ret='eax', gen=g4d4b20, note='batch216060')


def g602bc0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20))))
            sr[j](emu, k)
        return side
    def logL(emu, a, tag):
        emu.calllog.append((tag, emu.r32(a), emu.r32(a + 4), emu.r32(a + 8), emu.r32(a + 12), emu.rbytes(a + 0x14, 1).hex()))
    def hk(addr, n, pop, j, act=None, this_=True, stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x603110, 0, 0, 0)
    hk(0x602260, 1, 4, 1, act=lambda emu: logL(emu, emu.reg('ecx'), 'L260'), this_='mark')
    hk(0x6031e0, 1, 4, 2, act=lambda emu: logL(emu, emu.arg32(0), 'L1e0'), stackmark=(0,))
    hk(0x602240, 0, 0, 3, act=lambda emu: logL(emu, emu.reg('ecx'), 'L240'), this_='mark')
    return [this]


S(0x602bc0, 'GUESS hand 0x602bc0', 'thiscall', None, ret='eax', gen=g602bc0, note='batch216060')


def g5f3050(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    OBJ = rnd(c, 0x20); NEW = rnd(c, 0x20)
    VT = rnd(c, 0x40); c.emu.w32(NEW, VT)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('o', zlib.crc32(emu.rbytes(NEW, 0x20))))
            sr[j](emu, k)
        return side
    c.emu.w32(VT + 0x30, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else OBJ), pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x604650, 0, ret=lambda emu, k: (0 if r.random() < 0.3 else NEW), pop=0, this=True, side=mkside(2))
    return [r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32)])]


S(0x5f3050, 'GUESS hand 0x5f3050', 'thiscall', None, ret='eax', gen=g5f3050, note='batch216060')


def g42b160(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    sr = [seh_record(c, 2) for _ in range(2)]
    hook_rec(c, 0x5f10c0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=sr[0])
    n = r.choice([0, 1, 2, 3, 5])
    b = rnd(c, 0x10)
    d = r.choice([0, rnd(c, 0x10), r.getrandbits(32) & ~3])
    return [b, b + 12 * n, d, r.getrandbits(32)]


S(0x42b160, 'GUESS hand 0x42b160', 'fastcall', None, ret='eax', gen=g42b160, note='batch216060')


def g5a3dc0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x100)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x100))))
            sr[j](emu, k)
        return side
    VT = rnd(c, 0x10)
    c.emu.w32(VT, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    for i in range(4):
        if r.random() < 0.6:
            o = rnd(c, 0x10); c.emu.w32(o, VT)
            c.emu.w32(this + 0xe9 + 4 * i, o)
        else:
            c.emu.w32(this + 0xe9 + 4 * i, 0)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x40); c.emu.w32(T, TV)
    c.emu.w32(G2 + 0x9b, T)
    c.emu.w32(TV + 0x34, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    return [this]


S(0x5a3dc0, 'GUESS hand 0x5a3dc0', 'thiscall', None, ret='eax', gen=g5a3dc0, note='batch216060')


def g600be0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x30)
    sr = [seh_record(c, 2) for _ in range(3)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x30))))
            sr[j](emu, k)
        return side
    hook_rec(c, 0x5fa5d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(0))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1))
    return [this]


S(0x600be0, 'GUESS hand 0x600be0', 'thiscall', None, ret='eax', gen=g600be0, note='batch216060')


def g601d80(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    OBJ = rnd(c, 0x40)
    VT = rnd(c, 0x80)
    c.emu.w32(OBJ, VT)
    sr = [seh_record(c, 2) for _ in range(3)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('o', zlib.crc32(emu.rbytes(OBJ, 0x40))))
            sr[j](emu, k)
        return side
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: OBJ, pop=0, this=False, side=mkside(0))
    def a603500(emu, k, _s=mkside(1)):
        emu.wbytes(OBJ, bytes(r.getrandbits(8) for _ in range(0x40)))
        emu.w32(OBJ, VT)
        _s(emu, k)
    hook_rec(c, 0x603500, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=a603500)
    T58 = c.emu.r32(0x6b97b4 + 0x58)   # the real class vtable is installed by the function, so hook the exe slot target
    def ret58(emu, k):
        emu.calllog.append(('o58', zlib.crc32(emu.rbytes(OBJ, 0x40))))
        return r.getrandbits(32)
    hook_rec(c, T58, 1, ret=ret58, pop=4, this=True, side=mkside(2))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x601d80, 'GUESS hand 0x601d80', 'thiscall', None, ret='eax', gen=g601d80, note='batch216060')


def g474e00(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20); VT = rnd(c, 0x1a0); c.emu.w32(this, VT)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x60); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    c.emu.w32(0x6ff9ac, r.getrandbits(32))
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(TV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    def s168(emu, k, _s=mkside(1)):
        log16(emu, emu.arg32(1), 'L168'); _s(emu, k)
    c.emu.w32(VT + 0x168, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(1,), side=s168))
    def hk(addr, n, pop, j, act, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            act(emu); _s(emu, k)
        hook_rec(c, addr, n, ret=r.getrandbits(32), pop=pop, this='mark', stackmark=stackmark, side=sd)
    hk(0x4d2280, 0, 0, 2, lambda emu: fill16(emu, emu.reg('ecx')))
    def a_cat(emu):
        e = emu.reg('ecx'); log16(emu, e, 'Lcat'); fill16(emu, e)
    hk(0x4d3ab0, 2, 8, 3, a_cat)
    hk(0x4d2330, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, r.getrandbits(32)]


S(0x474e00, 'GUESS hand 0x474e00', 'thiscall', None, ret='eax', gen=g474e00, note='batch216060')


def g4352f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0xa0)
    M = rnd(c, 0x10); MV = rnd(c, 0x80); c.emu.w32(M, MV); c.emu.w32(0x7003ac, M)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0xa0))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def s6c(emu, k, _s=mkside(0)):
        b = emu.arg32(0)
        emu.calllog.append(('Lbuf', emu.rbytes(b, 0x80).hex()))
        n = r.choice([0, 3, 40, 100])
        emu.wbytes(b, bytes(r.randrange(1, 256) for _ in range(n)))
        _s(emu, k)
    c.emu.w32(MV + 0x6c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=s6c))
    def hk(addr, n, pop, j, act, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            act(emu); _s(emu, k)
        hook_rec(c, addr, n, ret=r.getrandbits(32), pop=pop, this='mark', stackmark=stackmark, side=sd)
    def a_ctor(emu):
        emu.calllog.append(('Lctor', emu.rbytes(emu.arg32(0), 0x80).hex()))
        fill16(emu, emu.reg('ecx'))
    def a_asg(emu):
        log16(emu, emu.arg32(0), 'Lsrc'); log16(emu, emu.reg('ecx'), 'Ldst')
    hk(0x4cbe80, 1, 4, 1, a_ctor, stackmark=(0,))
    hk(0x4cbee0, 1, 4, 2, a_asg, stackmark=(0,))
    hk(0x4cbec0, 0, 0, 3, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this]


S(0x4352f0, 'GUESS hand 0x4352f0', 'thiscall', None, ret='eax', gen=g4352f0, note='batch216060')


def g435630(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40)
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x7003ac, M)
    STR = rnd(c, 0x20)
    CS = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(MV + 0x14, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    def hk(addr, n, pop, j, act=None, ret=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbe80, 1, 4, 1, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x4cbee0, 1, 4, 2, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), log16(emu, emu.reg('ecx'), 'Ldst')), stackmark=(0,))
    hk(0x4cbec0, 0, 0, 3, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hk(0x4cc5f0, 0, 0, 4, ret=lambda emu, k: r.choice([0, 3, 77]), this_=True)
    hk(0x4cc1d0, 0, 0, 5, ret=lambda emu, k: CS, this_=True)
    return [this, STR]


S(0x435630, 'GUESS hand 0x435630', 'thiscall', None, ret='eax', gen=g435630, note='batch216060')


def g5ebae0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0xb0)
    P = rnd(c, 0x10)
    sr = [seh_record(c, 2) for _ in range(3)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0xb0)), zlib.crc32(emu.rbytes(P, 0x10))))
            sr[j](emu, k)
        return side
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: P, pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x4de7a0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(1))
    return [this, r.getrandbits(32)]


S(0x5ebae0, 'GUESS hand 0x5ebae0', 'thiscall', None, ret='eax', gen=g5ebae0, note='batch216060')


def g4314c0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20); VT = rnd(c, 0x80); c.emu.w32(this, VT)
    G2 = rnd(c, 0x20); GV = rnd(c, 0x80); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    CS1 = rnd(c, 0x20); CS2 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(G2, 0x20))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(VT + 0x68, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(GV + 0x60, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    def hk(addr, n, pop, j, act=None, ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this='mark', side=sd)
    hk(0x4cbeb0, 0, 0, 2, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x4cc000, 1, 4, 3, lambda emu: (log16(emu, emu.reg('ecx'), 'Lf'), fill16(emu, emu.reg('ecx'))))
    cnt = [0]
    def csret(emu, k):
        cnt[0] += 1
        return CS1 if cnt[0] % 2 == 1 else CS2
    hk(0x4cc1d0, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Lc'), ret=csret)
    hk(0x4cbec0, 0, 0, 5, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    fv = r.choice([0.0, -0.0, 1.0, -1.5, 3.25, 1e30, float('inf'), float('nan'), r.uniform(-1000, 1000)])
    return [this, r.getrandbits(32), F(fv)]


S(0x4314c0, 'GUESS hand 0x4314c0', 'thiscall', None, ret='eax', gen=g4314c0, note='batch216060')


def g435a10(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x70)
    OBJ = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(3)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x70))))
            sr[j](emu, k)
        return side
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else OBJ), pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x43cf00, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(1))
    return [this]


S(0x435a10, 'GUESS hand 0x435a10', 'thiscall', None, ret='eax', gen=g435a10, note='batch216060')


def g4d16e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x30)
    TAIL = rnd(c, 0x20)
    c.emu.w32(this + 0x1c, r.choice([0, TAIL]))
    c.emu.w32(this + 0x18, r.getrandbits(32))
    NODE = rnd(c, 0x20); BUF = rnd(c, 0x40)
    STR = rnd(c, 0x30)
    c.emu.wbytes(STR, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 5, 20]))) + b'\0')
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x30)), zlib.crc32(emu.rbytes(NODE, 0x20)), zlib.crc32(emu.rbytes(TAIL, 0x20))))
            sr[j](emu, k)
        return side
    def al(emu, k):
        sz = emu.arg32(0)
        if sz == 0x14: return 0 if r.random() < 0.25 else NODE
        return BUF
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(0))
    def sd_cpy(emu, k, _s=mkside(1)):
        emu.calllog.append(('src', emu.rbytes(emu.arg32(1), 0x30).hex()))
        _s(emu, k)
    hook_rec(c, 0x634d22, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=sd_cpy)
    return [this, STR]


S(0x4d16e0, 'GUESS hand 0x4d16e0', 'thiscall', None, ret='eax', gen=g4d16e0, note='batch216060')


def g4668d0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x20)
    SUB = rnd(c, 0x10); c.emu.w32(this + 8, SUB)
    OBJ = rnd(c, 0x20); OV = rnd(c, 0x140); c.emu.w32(OBJ, OV)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x130); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(OBJ, 0x20))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def s114(emu, k, _s=mkside(0)):
        log16(emu, emu.arg32(4), 'L114'); _s(emu, k)
    c.emu.w32(TV + 0x114, pystub(c, 6, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(4,), side=s114))
    c.emu.w32(OV + 0x128, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    hook_rec(c, 0x4db2f0, 1, ret=lambda emu, k: OBJ, pop=4, this=True, side=mkside(2))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4d2280, 0, 0, 3, lambda emu: fill16(emu, emu.reg('ecx')))
    def a_parse(emu):
        log16(emu, emu.reg('ecx'), 'Lp')
        v = r.choice([0.0, 1.0, -2.5, 1e20, float('inf'), r.uniform(-100, 100)])
        if r.random() < 0.8:
            emu.w32(emu.arg32(1), struct.unpack('<I', struct.pack('<f', v))[0])
    hk(0x4d2d30, 2, 8, 4, a_parse, stackmark=(1,))
    hk(0x4d2330, 0, 0, 5, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this]


S(0x4668d0, 'GUESS hand 0x4668d0', 'thiscall', None, ret='st0', gen=g4668d0, note='batch216060')


def g4558a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x60); VT = rnd(c, 0x200); c.emu.w32(this, VT)
    c.emu.w32(this + 0x49, r.choice([0, 0, 0, r.getrandbits(32)]))
    P = rnd(c, 0x20)
    c.emu.wbytes(P, bytes([r.choice([0, 0, 65, 66])]) + bytes(r.randrange(1, 256) for _ in range(6)) + b'\0')
    c.emu.w32(this + 0x4d, r.choice([0, P, P, P]))
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    R1 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x60))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(0)))
    def s1d8(emu, k, _s=mkside(1)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(VT + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    c.emu.w32(LV + 0x2c, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(2)))
    def hk(addr, n, pop, j, act=None, ret=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else r.getrandbits(32)), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x43e0f0, 0, 0, 3, this_=True)
    hk(0x4cbe80, 1, 4, 4, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x456ab0, 0, 0, 5, lambda emu: log16(emu, emu.reg('ecx'), 'Lpar'), ret=lambda emu, k: r.choice([0, 0, r.getrandbits(32)]))
    hk(0x4cbec0, 0, 0, 6, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'), ret=lambda emu, k: r.getrandbits(32))
    hk(0x4cc1d0, 0, 0, 7, ret=lambda emu, k: r.getrandbits(32), this_=True)
    return [this]


S(0x4558a0, 'GUESS hand 0x4558a0', 'thiscall', None, ret='eax', gen=g4558a0, note='batch216060')


def g4720f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x3d0)
    OB = rnd(c, 0x20); OV = rnd(c, 0x20); c.emu.w32(OB, OV)
    pre = r.random() < 0.4
    c.emu.w32(this + 0x3b7, OB if pre else 0)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x80); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    E = rnd(c, 0x10); INFO = rnd(c, 0x50)
    bit = r.random() < 0.5
    fl = r.getrandbits(32)
    fl = (fl | 0x400) if bit else (fl & ~0x400)
    c.emu.w32(INFO + 0x3c, fl)
    c.emu.w32(E + 8, INFO)
    c.emu.w32(E + 4, r.choice([0, rnd(c, 0x10)]))
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    NEWO = rnd(c, 0x20); c.emu.w32(NEWO, OV)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x3d0))))
            sr[j](emu, k)
        return side
    c.emu.w32(TV + 0x58, pystub(c, 1, ret=lambda emu, k: E, this=True, side=mkside(0)))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(1)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(2)))
    c.emu.w32(OV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    nullok = bit
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if (nullok and r.random() < 0.3) else NEWO), pop=0, this=False, side=mkside(4))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: NEWO, pop=8, this=True, side=mkside(5))
    return [this, r.getrandbits(32)]


S(0x4720f0, 'GUESS hand 0x4720f0', 'thiscall', None, ret='eax', gen=g4720f0, note='batch216060')


def g4cc000(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40)
    inline = r.random() < 0.5
    c.emu.w32(this, this + 4 if inline else rnd(c, 0x20))
    G2 = rnd(c, 0x20); GV = rnd(c, 0x1a0); c.emu.w32(0x70039c, G2); c.emu.w32(G2, GV)
    X = rnd(c, 0x10); XV = rnd(c, 0x1a0); c.emu.w32(X, XV)
    HEAP = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40))))
            sr[j](emu, k)
        return side
    def cstr(emu, a):
        out = b''
        while len(out) < 0x90:
            b = emu.rbytes(a + len(out), 1)
            if b == b'\0': break
            out += b
        return out
    c.emu.w32(GV + 0x190, pystub(c, 0, ret=lambda emu, k: X, this=True, side=mkside(0)))
    c.emu.w32(XV + 0x198, pystub(c, 5, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1)))
    c.emu.w32(0x676328, pystub(c, 2, ret=lambda emu, k: r.choice([0, 0, 1, 0x100]), pop=0, this=False, side=mkside(2)))
    def s_cpy(emu, k, _s=mkside(3)):
        emu.wbytes(emu.arg32(0), bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 5, 20]))) + b'\0')
        _s(emu, k)
    c.emu.w32(0x67642c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, stackmark=(0,), side=s_cpy))
    first = [True]
    def a_cc(emu):
        e = emu.reg('ecx')
        a = emu.arg32(0)
        if first[0]:
            first[0] = False
            emu.calllog.append(('Lbuf', cstr(emu, a).hex()))
            if inline:
                emu.w32(e, e + 4)
            else:
                emu.w32(e, HEAP)
            emu.wbytes(e + 4, bytes(r.getrandbits(8) for _ in range(8)))
        else:
            emu.calllog.append(('Lasg', emu.r32(e), a))
    def sd(emu, k, _s=mkside(4)):
        a_cc(emu); _s(emu, k)
    hook_rec(c, 0x4cc630, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=sd)
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, stackmark=(0,), side=mkside(5))
    fv = r.choice([0.0, -0.0, 1.0, -1.5, 3.25, 1e30, float('inf'), float('nan'), r.uniform(-1000, 1000)])
    return [this, F(fv)]


S(0x4cc000, 'GUESS hand 0x4cc000', 'thiscall', None, ret='eax', gen=g4cc000, note='batch216060')


def g42bf90(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x1b70)
    POOL = c.emu.alloc(0x10400, 16)
    BASE = POOL + 0x200
    pre = r.random() < 0.4
    c.emu.w32(this + 0x1b55, BASE if pre else 0)
    OBJ = rnd(c, 0x20)
    c.emu.w32(this + 0x1b51, OBJ)
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x1b40, 0x30)), zlib.crc32(emu.rbytes(POOL + 0x1f0, 0x20))))
            sr[j](emu, k)
        return side
    def al(emu, k):
        sz = emu.arg32(0)
        if sz == 0xa000: return BASE
        return 0 if r.random() < 0.25 else OBJ
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x634d10, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x4ccdd0, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, side=mkside(2))
    neg = r.random() < 0.3
    hook_rec(c, 0x4cd9b0, 2, ret=lambda emu, k: ((-r.randrange(1, 0x100)) & 0xffffffff) if neg else r.choice([0, 1, 5, 0x40, 0x100]), pop=8, this=True, side=mkside(3))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(4)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(5)))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(6)))
    a0 = r.choice([0, 1, 2, 3, 0x10, 0x11, 0x80, 0xfb, 0xfffa, 0xfffb, 0xffff, 0x10000, 0x10004, 0x1fffd])
    if a0 > 0x300 and not neg:
        a0 = a0
    return [this, a0]


S(0x42bf90, 'GUESS hand 0x42bf90', 'thiscall', None, ret='eax', gen=g42bf90, note='batch216060')


def g442d20(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x90); VT = rnd(c, 0x340); c.emu.w32(this, VT)
    c.emu.w32(this + 8, r.getrandbits(32))
    SUB = rnd(c, 0x30)
    OBJ = rnd(c, 0x30)
    cnt = r.choice([0, 0, 1, 2, 3, 5])
    if r.random() < 0.2:
        c.emu.w32(this + 0x7b, 0)
    else:
        LP = rnd(c, 0x440)
        c.emu.w16(LP + 2, cnt)
        OV = rnd(c, 0x340)
        for i in range(8):
            o = rnd(c, 0x10); c.emu.w32(o, OV); c.emu.w32(LP + 0x404 + 4 * i, o)
        c.emu.w32(this + 0x7b, LP)
        c.emu.w32(OV + 0x324, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=lambda emu, k: (emu.calllog.append(('lp', emu.reg('ecx'))), None)[1]))
    c1 = struct.unpack('<f', struct.pack('<I', c.emu.r32(0x67d164)))[0]
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x90)), zlib.crc32(emu.rbytes(SUB, 0x30))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(12)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 12).hex()))
    c.emu.w32(VT + 0x2f0, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.25 else OBJ), pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x4e3e70, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(2))
    flv = r.choice([c1, c1 - 1.0, c1 + 1.0, c1 * 2 + 0.5, 0.0, -1.0, 100.0, float('nan'), float('inf'), c1 + 1e-3, c1 - 1e-3])
    def s443(emu, k, _s=mkside(3)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    hook_rec(c, 0x443080, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, stackmark=(0,), st0=flv, side=s443)
    def s4fc0(emu, k, _s=mkside(4)):
        log16(emu, emu.arg32(0), 'Lv'); _s(emu, k)
    hook_rec(c, 0x4e4fc0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s4fc0)
    hook_rec(c, 0x4e4fe0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(5))
    return [this]


S(0x442d20, 'GUESS hand 0x442d20', 'thiscall', None, ret='eax', gen=g442d20, note='batch216060')


def g531a50(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x30)
    OBJ = rnd(c, 0x30); NEW = rnd(c, 0x30)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x30)), zlib.crc32(emu.rbytes(OBJ, 0x30)), zlib.crc32(emu.rbytes(NEW, 0x30))))
            sr[j](emu, k)
        return side
    hook_rec(c, 0x52e0a0, 3, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff, 7]), pop=12, this=True, side=mkside(0))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NEW, pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x476dc0, 1, ret=lambda emu, k: OBJ, pop=4, this=True, side=mkside(2))
    def s52d1(emu, k, _s=mkside(3)):
        emu.calllog.append(('Lout', emu.r32(emu.arg32(1)), emu.r32(emu.arg32(2))))
        emu.w32(emu.arg32(1), r.getrandbits(32))
        emu.w32(emu.arg32(2), r.getrandbits(32))
        _s(emu, k)
    hook_rec(c, 0x52d1c0, 8, ret=lambda emu, k: r.getrandbits(32), pop=32, this=True, stackmark=(1, 2), side=s52d1)
    return [this, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x531a50, 'GUESS hand 0x531a50', 'thiscall', None, ret='eax', gen=g531a50, note='batch216060')


def g434ad0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    ITV = rnd(c, 0x80); IT = rnd(c, 0x10); c.emu.w32(IT, ITV)
    c.emu.w32(this + 4, 0 if r.random() < 0.15 else IT)
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        n = rnd(c, 0x10); inner = rnd(c, 0x20); c.emu.w32(n, inner); nodes.append(n)
    seq = list(nodes)
    GOB = rnd(c, 0x10); GV = rnd(c, 0x40); c.emu.w32(GOB, GV); c.emu.w32(0x700394, GOB)
    EB = rnd(c, 0x10); EV = rnd(c, 0x10); c.emu.w32(EB, EV)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(EB, 0x10))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def s4c(emu, k, _s=mkside(0)):
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
        _s(emu, k)
    c.emu.w32(ITV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=s4c))
    def s64(emu, k, _s=mkside(1)):
        emu.calllog.append(('it', emu.rbytes(emu.arg32(0), 12).hex()))
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
        _s(emu, k)
    c.emu.w32(ITV + 0x64, pystub(c, 1, ret=lambda emu, k: (seq.pop(0) if seq else 0), this=True, stackmark=(0,), side=s64))
    c.emu.w32(GV + 0x30, pystub(c, 2, ret=lambda emu, k: r.choice([0xfffffffb, 0, 7, 0x7fffffff, 0x80000000, 1]), this=True, side=mkside(2)))
    c.emu.w32(EV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    def hk(addr, n, pop, j, act=None, stackmark=(), ret=None, this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbeb0, 0, 0, 4, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x4cbe80, 1, 4, 5, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x4cbee0, 1, 4, 6, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), log16(emu, emu.reg('ecx'), 'Ldst')), stackmark=(0,))
    hk(0x4cbec0, 0, 0, 7, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hk(0x4cc1d0, 0, 0, 8, lambda emu: log16(emu, emu.reg('ecx'), 'Lcs'), ret=lambda emu, k: r.getrandbits(32))
    return [this, EB]


S(0x434ad0, 'GUESS hand 0x434ad0', 'thiscall', None, ret=None, gen=g434ad0, note='batch216060')


def g5fa7e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40)
    NODES = [rnd(c, 0x10) for _ in range(3)]
    BUF = rnd(c, 0x30)
    ni = [0]
    sr = [seh_record(c, 2) for _ in range(3)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40)), [zlib.crc32(emu.rbytes(n, 0x10)) for n in NODES]))
            sr[j](emu, k)
        return side
    def a(emu, k):
        v = NODES[ni[0] % 3]; ni[0] += 1
        return v
    hook_rec(c, 0x6014a0, 1, ret=a, pop=4, this=True, side=mkside(0))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: BUF, pop=0, this=False, side=mkside(1))
    return [this]


S(0x5fa7e0, 'GUESS hand 0x5fa7e0', 'thiscall', None, ret='eax', gen=g5fa7e0, note='batch216060')


def g45fb40(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20); VT = rnd(c, 0x200); c.emu.w32(this, VT)
    A = rnd(c, 0x10); c.emu.w32(this + 8, A)
    H = rnd(c, 0x20); c.emu.w32(this + 0x10, H)
    CV = rnd(c, 0x80); C = rnd(c, 0x10); c.emu.w32(C, CV)
    c.emu.w32(H + 8, 0 if r.random() < 0.15 else C)
    M = rnd(c, 0x10); MV = rnd(c, 0x100); c.emu.w32(M, MV); c.emu.w32(0x70038c, M)
    M2 = rnd(c, 0x10); M2V = rnd(c, 0x40); c.emu.w32(M2, M2V); c.emu.w32(0x700390, M2)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    RS = []
    for _ in range(5):
        o = rnd(c, 0x30)
        c.emu.w32(o + 0x1c, r.choice([0, r.getrandbits(32) | 1]))
        c.emu.w32(o + 0x14, r.choice([0, 8, 0x18, 0x10, 7, 0xff]))
        RS.append(o)
    seq = [r.choice([0, 0, 1]) for _ in range(6)]
    NODES = [rnd(c, 0x10) for _ in range(6)]
    R1 = rnd(c, 0x20)
    try:
        c.emu.w32(0x1c, 1); c.emu.w32(0x14, 8)   # a null deref must look like a match, so a dropped null check shows
    except Exception:
        pass
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), [zlib.crc32(emu.rbytes(o, 0x30)) for o in RS]))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def s4c(emu, k, _s=mkside(0)):
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
        _s(emu, k)
    c.emu.w32(CV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=s4c))
    cnt = [0]
    def s5c(emu, k, _s=mkside(1)):
        emu.calllog.append(('it', emu.rbytes(emu.arg32(0), 12).hex()))
        cnt[0] += 1
        v = r.choice([0, 1, 0xdead]) if cnt[0] < 6 else 0
        emu.wbytes(emu.arg32(0), struct_pack(v) + bytes(r.getrandbits(8) for _ in range(8)))
        _s(emu, k)
    import struct
    def struct_pack(v): return struct.pack('<I', v)
    c.emu.w32(CV + 0x5c, pystub(c, 1, ret=lambda emu, k: NODES[k % 6], this=True, stackmark=(0,), side=s5c))
    c.emu.w32(MV + 0xcc, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else r.choice(RS)), this=True, side=mkside(2)))
    c.emu.w32(M2V + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(3)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(4)))
    def s1d8(emu, k, _s=mkside(5)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(VT + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    hook_rec(c, 0x4da3a0, 0, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x101]), pop=0, this=True, side=mkside(6))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(7))
    def a_d(emu, k, _s=mkside(8)):
        log16(emu, emu.reg('ecx'), 'Ldtor'); _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a_d)
    fv = r.choice([0.0, -0.0, 1.5, float('nan'), r.uniform(-100, 100)])
    return [this, F(fv)]


S(0x45fb40, 'GUESS hand 0x45fb40', 'thiscall', None, ret='eax', gen=g45fb40, note='batch216060')


def g4d7220(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x80)
    UV = rnd(c, 0x40); U = rnd(c, 0x10); c.emu.w32(U, UV)
    c.emu.w32(this + 0x15, U)
    O = rnd(c, 0x440); Q = rnd(c, 0x40)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x80)), zlib.crc32(emu.rbytes(O, 0x440)), zlib.crc32(emu.rbytes(Q, 0x40))))
            sr[j](emu, k)
        return side
    def al(emu, k):
        return O if emu.arg32(0) == 0x432 else Q
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x4d6520, 3, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff, 5]), pop=12, this=True, side=mkside(1))
    c.emu.w32(UV + 0xc, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    hook_rec(c, 0x62f9d0, 4, ret=lambda emu, k: r.choice([0, 0, 0, 1, 5]), pop=16, this=True, side=mkside(3))
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(4))
    return [this, r.getrandbits(32), r.choice([3, 3, 3, 0, 1, 2, 4])]


S(0x4d7220, 'GUESS hand 0x4d7220', 'thiscall', None, ret='eax', gen=g4d7220, note='batch216060')


def g555570(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    A = rnd(c, 0x20)
    SA = rnd(c, 0x10); SB = rnd(c, 0x10)
    c.emu.w32(A + 4, SA); c.emu.w32(A + 8, SB)
    PP = rnd(c, 0x10)
    QQ = rnd(c, 0x10)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x80); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    ESI = rnd(c, 0x20); EV = rnd(c, 0x450); c.emu.w32(ESI, EV)
    M2 = rnd(c, 0x10); M2V = rnd(c, 0x40); c.emu.w32(M2, M2V); c.emu.w32(0x700390, M2)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    R1 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(A, 0x20)), zlib.crc32(emu.rbytes(ESI, 0x20))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(TV + 0x58, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else ESI), this=True, side=mkside(0)))
    c.emu.w32(EV + 0x1e0, pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff]), this=True, side=mkside(1)))
    def s1d8(emu, k, _s=mkside(2)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(EV + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    c.emu.w32(EV + 0x438, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    c.emu.w32(M2V + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(4)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(5)))
    c.emu.w32(PP, r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, ret=lambda emu, k: (PP if emu.reg('ecx') == SA else QQ), pop=4, this=True, side=mkside(6))
    hook_rec(c, 0x5002f0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(7))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(8))
    def a_d(emu, k, _s=mkside(9)):
        emu.calllog.append(('Ldtor', emu.rbytes(emu.reg('ecx'), 16).hex())); _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a_d)
    return [A]


S(0x555570, 'GUESS hand 0x555570', 'stdcall', None, ret='eax', gen=g555570, note='batch216060')


def g5b86a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x100)
    RD = rnd(c, 0x20)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x80); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    SRC = rnd(c, 0x60)
    c.emu.wbytes(SRC, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 7, 30]))) + b'\0')
    OBJ = rnd(c, 0x30)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x100))))
            sr[j](emu, k)
        return side
    c.emu.w32(TV + 0x58, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    ints = [0]
    def rint(emu, k):
        v = r.choice([0, 0, 1, 0x1234, r.getrandbits(32)])
        return v
    hook_rec(c, 0x4e5e60, 0, ret=rint, pop=0, this=True, side=mkside(1))
    fl = [0]
    def fv(emu, k):
        fl[0] += 1
        return r.choice([0.0, 1.0, -2.5, 3.14159, 1e10, float('nan')])
    hook_rec(c, 0x4e5e80, 0, ret=lambda emu, k: 0, pop=0, this=True, st0=fv, side=mkside(2))
    hook_rec(c, 0x4e5ea0, 0, ret=lambda emu, k: SRC, pop=0, this=True, side=mkside(3))
    hook_rec(c, 0x4e6330, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(4))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: OBJ, pop=0, this=False, side=mkside(5))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=mkside(6))
    return [this, RD]


S(0x5b86a0, 'GUESS hand 0x5b86a0', 'thiscall', None, ret='eax', gen=g5b86a0, note='batch216060')


def g49b490(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x50)
    SRC = rnd(c, 0x10)
    c.emu.w32(SRC, r.choice([0, 1, 5, 0x40, r.getrandbits(32)]))
    c.emu.w32(SRC + 4, r.choice([0, 3, 0x100, 0x40000001, r.getrandbits(32)]))
    c.emu.w32(SRC + 8, r.choice([0, 7, 0x20, 0x20000001, r.getrandbits(32)]))
    O = rnd(c, 0x20); B = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x50)), zlib.crc32(emu.rbytes(O, 0x20))))
            sr[j](emu, k)
        return side
    cnt = [0]
    def c6b(emu, k):
        return r.getrandbits(32)
    hook_rec(c, 0x4e6b30, 0, ret=c6b, pop=0, this=True, side=mkside(0))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if (emu.arg32(0) == 0x15 and r.random() < 0.25) else (O if emu.arg32(0) == 0x15 else B)), pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x4e6c80, 4, ret=lambda emu, k: r.getrandbits(32), pop=16, this=True, side=mkside(2))
    return [this, 0 if r.random() < 0.15 else SRC]


S(0x49b490, 'GUESS hand 0x49b490', 'thiscall', None, ret='eax', gen=g49b490, note='batch216060')


def g555d10(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    A = rnd(c, 0x20)
    SA = rnd(c, 0x10); SB = rnd(c, 0x10)
    c.emu.w32(A + 4, SA); c.emu.w32(A + 8, SB)
    PP = rnd(c, 0x10); QQ = rnd(c, 0x10)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x80); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    ESI = rnd(c, 0x20); EV = rnd(c, 0x700); c.emu.w32(ESI, EV)
    M2 = rnd(c, 0x10); M2V = rnd(c, 0x40); c.emu.w32(M2, M2V); c.emu.w32(0x700390, M2)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    R1 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(A, 0x20)), zlib.crc32(emu.rbytes(ESI, 0x20))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(TV + 0x58, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.25 else ESI), this=True, side=mkside(0)))
    def s1e0(emu, k):
        emu.calllog.append(('f', emu.arg32(0)))
        return r.choice([0, 1, 0x100, 0x1ff])
    c.emu.w32(EV + 0x1e0, pystub(c, 1, ret=s1e0, this=True, side=mkside(1)))
    def s1d8(emu, k, _s=mkside(2)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(EV + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    c.emu.w32(EV + 0x674, pystub(c, 0, ret=lambda emu, k: r.choice([0, 0, 1, 0xffffff00, 5]), this=True, side=mkside(3)))
    c.emu.w32(EV + 0x670, pystub(c, 0, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff]), this=True, side=mkside(4)))
    c.emu.w32(M2V + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(5)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(6)))
    c.emu.w32(PP, r.getrandbits(32))
    hook_rec(c, 0x5003d0, 1, ret=lambda emu, k: (PP if emu.reg('ecx') == SA else QQ), pop=4, this=True, side=mkside(7))
    hook_rec(c, 0x5002f0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(8))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(9))
    def a_d(emu, k, _s=mkside(10)):
        emu.calllog.append(('Ldtor', emu.rbytes(emu.reg('ecx'), 16).hex())); _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a_d)
    return [A]


S(0x555d10, 'GUESS hand 0x555d10', 'stdcall', None, ret='eax', gen=g555d10, note='batch216060')


def g42c9a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x4c0); VT = rnd(c, 0x1b0); c.emu.w32(this, VT)
    SOBJ = this + 0x4a3
    lit = c.emu.rbytes(0x679e88, 7)
    def seg():
        return bytes(r.choice(b'abc.:') for _ in range(r.choice([0, 1, 3])))
    if r.random() < 0.1:
        txt = bytes(r.choice(b'ab.') for _ in range(r.choice([0, 1, 4])))
    else:
        txt = b'%' + seg() + b'%' + bytes(r.choice(b'\\/') for _ in range(r.choice([0, 1, 3]))) + seg() + b'tail'
        if r.random() < 0.5:
            txt = b'%' + b'%' + bytes(r.choice(b'\\/') for _ in range(r.choice([0, 1, 3]))) + b'x'
    TXT = rnd(c, 0x80); c.emu.wbytes(TXT, txt + b'\0')
    T2 = rnd(c, 0x40); c.emu.wbytes(T2, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 12]))) + b'\0')
    BUF = rnd(c, 0x110)
    R = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x4a0, 0x20)), zlib.crc32(emu.rbytes(BUF, 0x110))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: (T2 if emu.reg('ecx') == R else TXT), pop=0, this=True, side=mkside(0))
    c.emu.w32(0x676410, pystub(c, 3, ret=lambda emu, k: r.choice([0, 0, 1, 0xffffffff]), pop=0, this=False, side=mkside(1)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: BUF, pop=0, this=False, side=mkside(2))
    def s19c(emu, k, _s=mkside(3)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(VT + 0x19c, pystub(c, 1, ret=lambda emu, k: R, this=True, stackmark=(0,), side=s19c))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbec0, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hk(0x4cbe80, 1, 4, 5, lambda emu: (emu.calllog.append(('Lctor', emu.rbytes(emu.arg32(0), 0x40).hex())), fill16(emu, emu.reg('ecx'))))
    hk(0x4cbee0, 1, 4, 6, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'),), stackmark=(0,))
    return [this]


S(0x42c9a0, 'GUESS hand 0x42c9a0', 'thiscall', None, ret='eax', gen=g42c9a0, note='batch216060')


def g4c8e20(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x60); RD = rnd(c, 0x20)
    BUF = rnd(c, 0x100)
    VTS = [rnd(c, 0x80), rnd(c, 0x80)]
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x40, 0x20)), zlib.crc32(emu.rbytes(BUF, 0x40))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    cnts = [r.choice([0, 1, 2, 3]), r.choice([0, 1, 2, 3])]
    for oi in range(2):
        state = [0]
        def s4c(emu, k, oi=oi, state=state, _s=mkside(2 * oi)):
            state[0] = 0
            emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
            _s(emu, k)
        def s5c(emu, k, oi=oi, state=state, _s=mkside(2 * oi + 1)):
            i = state[0]; state[0] += 1
            emu.w32(emu.arg32(0), 1 if i < cnts[oi] else 0)
            _s(emu, k)
        c.emu.w32(VTS[oi] + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=s4c))
        c.emu.w32(VTS[oi] + 0x5c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=s5c))
    ci = [0]
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(16)))
        emu.w32(e, VTS[ci[0] % 2]); ci[0] += 1
    def hk(addr, n, pop, j, act=None, stackmark=(), ret=None, this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4ccba0, 0, 0, 4, a_ctor)
    hk(0x4e6330, 1, 4, 5, lambda emu: log16(emu, emu.arg32(0), 'Lrd'), stackmark=(0,), this_=True)
    hk(0x4cdd40, 0, 0, 6, lambda emu: log16(emu, emu.reg('ecx'), 'Lcnt'), ret=lambda emu, k: r.choice([0, 1, 2, 3, 0x20000000, 0x40000000]))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: BUF, pop=0, this=False, side=mkside(7))
    hk(0x4c8fe0, 0, 0, 8, this_=True)
    hk(0x4ccf60, 0, 0, 9, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, RD]


S(0x4c8e20, 'GUESS hand 0x4c8e20', 'thiscall', None, ret='eax', gen=g4c8e20, note='batch216060')


def g5fa910(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x50)
    N1 = rnd(c, 0x20); N2 = rnd(c, 0x20); N3 = rnd(c, 0x30)
    B1 = rnd(c, 0x30); O = rnd(c, 0x20); P = rnd(c, 0x40)
    ni = [0]
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x50)), zlib.crc32(emu.rbytes(O, 0x20)), [zlib.crc32(emu.rbytes(n, 0x30)) for n in (N1, N2, N3)], emu.r32(0x724278)))
            sr[j](emu, k)
        return side
    def a14(emu, k):
        v = [N1, N2, N3][ni[0] % 3]; ni[0] += 1
        return v
    hook_rec(c, 0x6014a0, 1, ret=a14, pop=4, this=True, side=mkside(0))
    hook_rec(c, 0x603090, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(1))
    def al(emu, k):
        sz = emu.arg32(0)
        if sz == 0x28: return B1
        if sz == 0xa: return 0 if r.random() < 0.25 else O
        return 0 if r.random() < 0.25 else P
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(2))
    hook_rec(c, 0x4690b0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(3))
    hook_rec(c, 0x5fb660, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(4))
    hook_rec(c, 0x606b80, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(5))
    return [this, r.getrandbits(32), r.getrandbits(32)]


S(0x5fa910, 'GUESS hand 0x5fa910', 'thiscall', None, ret='eax', gen=g5fa910, note='batch216060')


def g5853f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x90)
    G2 = rnd(c, 0xc0); GV = rnd(c, 0x1c0); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x120); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    BUF = rnd(c, 0x20); O = rnd(c, 0x110)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x90)), zlib.crc32(emu.rbytes(BUF, 0x20))))
            sr[j](emu, k)
        return side
    c.emu.w32(TV + 0x114, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(GV + 0x1a4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    hook_rec(c, 0x469870, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(2))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (BUF if emu.arg32(0) == 10 else (0 if r.random() < 0.25 else O)), pop=0, this=False, side=mkside(3))
    hook_rec(c, 0x4d8330, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, side=mkside(4))
    return [this]


S(0x5853f0, 'GUESS hand 0x5853f0', 'thiscall', None, ret='eax', gen=g5853f0, note='batch216060')


def g443d60(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x90)
    WR = rnd(c, 0x10); WV = rnd(c, 0x40); c.emu.w32(WR, WV)
    objs = []
    for i in range(5):
        if r.random() < 0.3:
            c.emu.w32(this + 0x5d + 4 * i, 0)
        else:
            o = rnd(c, 0x20); ov = rnd(c, 0x20); c.emu.w32(o, ov)
            c.emu.w32(o + 0x10, r.getrandbits(32))
            c.emu.w32(this + 0x5d + 4 * i, o)
            objs.append((o, ov))
    DATA = [rnd(c, 0x40) for _ in range(5)]
    di = [0]
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x90))))
            sr[j](emu, k)
        return side
    def s10(emu, k, _s=mkside(0)):
        sz = r.choice([0, 1, 5, 15, 16, 17, 0x1f, 0x20])
        emu.w32(emu.arg32(0), sz)
        _s(emu, k)
    for o, ov in objs:
        c.emu.w32(ov + 0x10, pystub(c, 1, ret=lambda emu, k: DATA[k % 5], this=True, stackmark=(0,), side=s10))
    def swr(emu, k, _s=mkside(1)):
        ln = min(emu.arg32(1), 0x20)
        emu.calllog.append(('W', emu.arg32(1), emu.rbytes(emu.arg32(0), ln).hex()))
        _s(emu, k)
    c.emu.w32(WV + 0x1c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=swr))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.calllog.append(('Lc', emu.r32(e), emu.arg32(0)))
        emu.wbytes(e + 4, bytes(r.getrandbits(8) for _ in range(12)))
    hk(0x4e3d60, 1, 4, 2, a_ctor)
    hk(0x4e3e40, 1, 4, 3, lambda emu: emu.calllog.append(('Lf', emu.rbytes(emu.reg('ecx'), 16).hex())))
    hk(0x4e3340, 1, 4, 4, lambda emu: emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12))), stackmark=(0,), this_=True)
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(5))
    return [this, WR, r.getrandbits(32)]


S(0x443d60, 'GUESS hand 0x443d60', 'thiscall', None, ret='eax', gen=g443d60, note='batch216060')


def g59f1a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x7b0); VT = rnd(c, 0x740); c.emu.w32(this, VT)
    runa = r.random() < 0.7
    runb = r.random() < 0.7
    if not (runa or runb):
        runa = True
    skipkind_a = r.choice([0, 1])
    c.emu.w32(this + 0x78a, 0 if (runa or skipkind_a) else r.getrandbits(32) | 1)
    c.emu.w32(this + 0x792, r.getrandbits(32) | 1 if (runa or not skipkind_a) else 0)
    skipkind_b = r.choice([0, 1])
    c.emu.w32(this + 0x78e, 0 if (runb or skipkind_b) else r.getrandbits(32) | 1)
    c.emu.w32(this + 0x796, r.getrandbits(32) | 1 if (runb or not skipkind_b) else 0)
    c.emu.w32(this + 0x79a, r.choice([0, 1, 0x100]))
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x80); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    E1 = rnd(c, 0x30); EV1 = rnd(c, 0x2e0); c.emu.w32(E1, EV1)
    OB = rnd(c, 0x10); OBV = rnd(c, 0x20); c.emu.w32(OB, OBV)
    M2 = rnd(c, 0x10); M2V = rnd(c, 0x40); c.emu.w32(M2, M2V); c.emu.w32(0x700390, M2)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    R1 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x780, 0x30))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(VT + 0x72c, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else E1), this=True, side=mkside(0)))
    c.emu.w32(TV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    c.emu.w32(VT + 0x4f8, pystub(c, 0, ret=lambda emu, k: OB, this=True, side=mkside(2)))
    c.emu.w32(VT + 0x4fc, pystub(c, 0, ret=lambda emu, k: OB, this=True, side=mkside(3)))
    c.emu.w32(OBV + 8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(4)))
    c.emu.w32(EV1 + 0x2d0, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(5)))
    c.emu.w32(M2V + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(6)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(7)))
    def s1d8(emu, k, _s=mkside(8)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(VT + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(9))
    def a_d(emu, k, _s=mkside(10)):
        emu.calllog.append(('Ldtor', emu.rbytes(emu.reg('ecx'), 16).hex())); _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a_d)
    return [this]


S(0x59f1a0, 'GUESS hand 0x59f1a0', 'thiscall', None, ret='eax', gen=g59f1a0, note='batch216060')


def g48fcb0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x30)
    cval = struct.unpack('<f', struct.pack('<I', c.emu.r32(0x678858)))[0]
    fv = r.choice([cval, cval, cval + 1.0, cval - 1.0, float('nan'), 0.0, -0.0])
    c.emu.w32(this + 0x10, struct.unpack('<I', struct.pack('<f', fv))[0])
    ED = rnd(c, 0x20); EV = rnd(c, 0x170); c.emu.w32(ED, EV)
    SP = rnd(c, 0x10); c.emu.w32(SP, r.getrandbits(32))
    c.emu.w32(ED + 0xc, SP)
    c.emu.w32(ED + 4, r.choice([0, rnd(c, 0x10)]))
    ST = rnd(c, 0x40)
    enabled = r.random() < 0.7
    BLK0 = rnd(c, 0x40)
    c.emu.w32(ST + 0x34, r.choice([0, BLK0]))
    MC = rnd(c, 0x10); MCV = rnd(c, 0x10); c.emu.w32(MC, MCV)
    M = rnd(c, 0x20); c.emu.w32(M + 0xc, MC if enabled else 0); c.emu.w32(0x700390, M)
    BLK = rnd(c, 0x40)
    G2 = rnd(c, 0xc0); GV = rnd(c, 0x1d0); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x80); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x30)), zlib.crc32(emu.rbytes(ST, 0x40)), zlib.crc32(emu.rbytes(BLK, 0x40)), zlib.crc32(emu.rbytes(BLK0, 0x40))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    tcount = [0]
    def tm(emu, k):
        return r.choice([100, 0xffffffff, 5, 0x7fffffff, r.getrandbits(32)])
    c.emu.w32(GV + 0x1c8, pystub(c, 2, ret=tm, this=True, side=mkside(0)))
    c.emu.w32(GV + 0x4c if False else TV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    c.emu.w32(EV + 0x160, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(MCV + 4, pystub(c, 1, ret=lambda emu, k: BLK + 4, this=True, side=mkside(3)))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbe80, 1, 4, 4, lambda emu: (emu.calllog.append(('Lctor', emu.arg32(0))), fill16(emu, emu.reg('ecx'))))
    hk(0x4cc2c0, 1, 4, 5, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), log16(emu, emu.reg('ecx'), 'Ldst'), fill16(emu, emu.reg('ecx'))), stackmark=(0,))
    hk(0x4cbec0, 0, 0, 6, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hk(0x494b40, 1, 4, 7, this_=True)
    hk(0x494ac0, 1, 4, 8, this_=True)
    hk(0x4cc1d0, 0, 0, 9, lambda emu: log16(emu, emu.reg('ecx'), 'Lcs'))
    hook_rec(c, 0x41e680, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(10))
    return [this, ED, ST]


S(0x48fcb0, 'GUESS hand 0x48fcb0', 'thiscall', None, ret='eax', gen=g48fcb0, note='batch216060')


def g505510(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    YO = rnd(c, 0x10); YV = rnd(c, 0x240); c.emu.w32(YO, YV); c.emu.w32(this + 0x14, YO)
    ENT = rnd(c, 0x90)
    c.emu.w8(ENT + 0x7c, r.choice([0, 0x20, 0x21, 0xdf, 0xff])) if hasattr(c.emu, 'w8') else c.emu.wbytes(ENT + 0x7c, bytes([r.choice([0, 0x20, 0x21, 0xdf, 0xff])]))
    RES = rnd(c, 0x60)
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    LOG3 = rnd(c, 0x10); LV3 = rnd(c, 0x40); c.emu.w32(LOG3, LV3)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x130); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    R1 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(ENT, 0x90))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(YV + 0x228, pystub(c, 5, ret=lambda emu, k: (0 if r.random() < 0.6 else RES), this=True, side=mkside(0)))
    def s1d8(emu, k, _s=mkside(1)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(YV + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    c.emu.w32(YV + 0x128, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: (LOG3 if emu.arg32(1) == 0x183 else LOG), this=True, side=mkside(3)))
    c.emu.w32(LV + 0x30, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(4)))
    c.emu.w32(LV3 + 0x30, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(4)))
    c.emu.w32(TV + 0x114, pystub(c, 6, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(4,), side=mkside(5)))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cc1d0, 0, 0, 6, this_=True)
    hk(0x4cbec0, 0, 0, 7, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hk(0x4d2280, 0, 0, 8, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x4d3ab0, 2, 8, 9, lambda emu: log16(emu, emu.reg('ecx'), 'Lcat'))
    hk(0x4d2330, 0, 0, 10, lambda emu: log16(emu, emu.reg('ecx'), 'Ld2'))
    fl = lambda: F(r.choice([0.0, 1.0, -2.5, float('nan'), 1e9, r.uniform(-50, 50)]))
    return [this, 0 if r.random() < 0.2 else ENT, r.choice([0, 1, 2, 3, 0x103, 0xff, r.getrandbits(32)]), fl(), fl(), r.getrandbits(32), fl()]


S(0x505510, 'GUESS hand 0x505510', 'thiscall', None, ret='eax', gen=g505510, note='batch216060')


def g499670(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    BASEP = rnd(c, 0x10); c.emu.w32(this + 0x14, BASEP)
    NR = 140
    POOL = c.emu.alloc(0x70 * NR + 0x40, 16)
    RB = POOL + 0x10
    R = [RB + 0x70 * i for i in range(NR)]
    # acyclic chain by random walk with steps +1, +2, -1
    chain = []
    if r.random() < 0.9:
        i = r.choice([r.randrange(0, 6), r.randrange(105, 126)])
        seen = set()
        for _ in range(r.choice([1, 2, 4, 7])):
            if i in seen or i < 0 or i >= NR - 3: break
            seen.add(i); chain.append(i)
            i += r.choice([1, 1, 1, 2, -1])
    for i in chain:
        c.emu.wbytes(R[i], bytes(r.getrandbits(8) for _ in range(0x70)))
        c.emu.w32(R[i] + 0x60, 0)
    for a_, b_ in zip(chain, chain[1:]):
        c.emu.w32(R[a_] + 0x60, R[b_])
    BASE = R[r.choice([0, 0, 0, 1, 2, 3])] if not chain else (R[chain[0]] - 0x70 * r.choice([0, 0, 1, 3, 112, 111]) if chain[0] >= 112 else R[r.choice([0, 0, 1, 2, 3])])
    c.emu.w32(BASEP + 4, BASE)
    ARG1 = rnd(c, 0x60)
    c.emu.w32(ARG1 + 0x50, R[chain[0]] if chain else 0)
    c.emu.w32(ARG1 + 8, r.choice([R[r.randrange(0, 12)], R[r.randrange(100, 130)], BASE - 0x38, BASE - 0x70 * 3 - 5, BASE + 0x70 * 5 + 0x6f]))
    WOB = rnd(c, 0x10); WV = rnd(c, 0x20); c.emu.w32(WOB, WV)
    P = rnd(c, 0x10); c.emu.w32(P, WOB)
    VT = rnd(c, 0x80)
    NODES = [rnd(c, 0x10) for _ in range(3)]
    cnt = r.choice([0, 1, 2, 3])
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(ARG1, 0x60))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(WV + 8, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    def w10(emu, k, _s=mkside(1)):
        emu.calllog.append(('W', emu.arg32(1), emu.rbytes(emu.arg32(0), 2).hex()))
        _s(emu, k)
    c.emu.w32(WV + 0x10, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=w10))
    c.emu.w32(VT + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=mkside(2)))
    seq = [0]
    def s64(emu, k):
        i = seq[0]; seq[0] += 1
        return NODES[i] if i < cnt else 0
    c.emu.w32(VT + 0x64, pystub(c, 1, ret=s64, this='mark', stackmark=(0,), side=mkside(3)))
    def hk(addr, n, pop, j, act=None, ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this='mark', side=sd)
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x14)))
        emu.w32(e, VT)
    hk(0x4ccb40, 2, 8, 4, a_ctor)
    hk(0x4cd6f0, 2, 8, 5, lambda emu: log16(emu, emu.reg('ecx'), 'Lmerge'))
    hk(0x4cf690, 0, 0, 6, lambda emu: log16(emu, emu.reg('ecx'), 'Lsort'))
    hk(0x4cdd40, 0, 0, 7, ret=lambda emu, k: r.choice([0, 1, 5, 0x80000000]))
    hk(0x4ccef0, 0, 0, 8, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, P, ARG1]


S(0x499670, 'GUESS hand 0x499670', 'thiscall', None, ret='eax', gen=g499670, note='batch216060')


def g478780(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x760); VT = rnd(c, 0x600); c.emu.w32(this, VT)
    cached = r.random() < 0.45
    c.emu.wbytes(this + 0x690, bytes([1 if cached else 0]))
    ESI = rnd(c, 0x10); EV = rnd(c, 0x220); c.emu.w32(ESI, EV)
    c.emu.w32(this + 0x5b2, 0 if r.random() < 0.2 else ESI)
    c.emu.wbytes(this + 0x6c4, bytes([r.choice([0, 1, 7])]))
    c.emu.wbytes(this + 0x6c3, bytes([r.choice([0, 1, 9])]))
    V0 = rnd(c, 0x10); V1 = rnd(c, 0x10)
    O = rnd(c, 0x20); BLK = rnd(c, 0x30); c.emu.w32(O + 0xc, BLK)
    NB = rnd(c, 0x30)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    T = rnd(c, 0x10); TV = rnd(c, 0x60); c.emu.w32(T, TV); c.emu.w32(G2 + 0x9b, T)
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x680, 0xe0)), zlib.crc32(emu.rbytes(O, 0x20)), zlib.crc32(emu.rbytes(BLK, 0x30)), zlib.crc32(emu.rbytes(NB, 0x30))))
            sr[j](emu, k)
        return side
    def fl():
        return struct.unpack('<I', struct.pack('<f', r.choice([0.0, 1.0, -3.5, 1e20, float('inf'), float('nan'), r.uniform(-100, 100)])))[0]
    c.emu.wbytes(V0, struct.pack('<III', fl(), fl(), fl()))
    c.emu.wbytes(V1, struct.pack('<III', fl(), fl(), fl()))
    c.emu.w32(VT + 0x5e4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(EV + 0x214, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    c.emu.w32(TV + 0x4c, pystub(c, 7, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(3)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(4)))
    def al(emu, k):
        return O if emu.arg32(0) == 0x18 else NB
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(5))
    hook_rec(c, 0x476dc0, 1, ret=lambda emu, k: O, pop=4, this=True, side=mkside(6))
    def s43(emu, k, _s=mkside(7)):
        emu.calllog.append(('edx', emu.reg('edx')))
        emu.wbytes(emu.reg('ecx'), struct.pack('<III', fl(), fl(), fl()))
        _s(emu, k)
    hook_rec(c, 0x43e920, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', side=s43)
    return [this, V0, V1]


S(0x478780, 'GUESS hand 0x478780', 'thiscall', None, ret='eax', gen=g478780, note='batch216060')


def g4901f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x20); VT = rnd(c, 0x1a0); c.emu.w32(this, VT)
    lit1 = c.emu.rbytes(0x68d8c0, 3); lit2 = c.emu.rbytes(0x68d8c4, 3)
    # string table: names ending in lit1 / lit2 / something else
    tbl = b''
    names = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        base = bytes(r.choice(b'abxyz_') for _ in range(r.choice([0, 1, 4, 7])))
        suf = r.choice([lit1, lit2, b'zzz', b'qq'])
        nm = base + suf
        names.append(nm); tbl += nm + b'\0'
    H = rnd(c, 0x40 + len(tbl) + 0x20)
    c.emu.w32(H + 4, r.choice([0, 0x40000000, 0x80000000, 0xc0000000, 0x40000001, 0xc0000002, 0x1]))
    c.emu.w32(H + 8, 0x20)
    c.emu.wbytes(H + 0x20, tbl + b'\0' * 8)
    c.emu.wbytes(H + 8 - 0 + 0, struct.pack('<I', 0x20))
    c.emu.wbytes(H + 8 + 0, struct.pack('<I', 0x20))
    # when the table is read at offset 8 (type 0) the strings must also be there
    c.emu.wbytes(H + 8, tbl[:0])
    TBL8 = tbl
    SOBJ = None
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    VTS = rnd(c, 0x80)
    c.emu.w32(VT + 0x170, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=mkside(0)))
    c.emu.w32(VT + 0x168, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=lambda emu, k: (emu.calllog.append(('v168', emu.arg32(0))), mkside(1)(emu, k))[1]))
    c.emu.w32(VT + 0xc0, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    def s90(emu, k, _s=mkside(3)):
        _s(emu, k)
    c.emu.w32(VT + 0x90, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), this=True, st0=1.0, side=s90))
    cnt = r.choice([0, 1, 2, 3])
    NODES = [rnd(c, 0x10) for _ in range(3)]
    seq = [0]
    def s4c(emu, k, _s=mkside(4)):
        seq[0] = 0
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
        _s(emu, k)
    def s5c(emu, k, _s=mkside(5)):
        i = seq[0]; seq[0] += 1
        emu.w32(emu.arg32(0), 1 if i < cnt else 0)
        _s(emu, k)
    c.emu.w32(VTS + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=s4c))
    c.emu.w32(VTS + 0x5c, pystub(c, 1, ret=lambda emu, k: NODES[k % 3], this='mark', stackmark=(0,), side=s5c))
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x14)))
        emu.w32(e, VTS)
    def hk(addr, n, pop, j, act=None, ret=None, this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, side=sd)
    hk(0x4ccd10, 2, 8, 6, a_ctor)
    hk(0x4cd0e0, 0, 0, 7, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hook_rec(c, 0x45e420, 1, ret=lambda emu, k: H, pop=4, this=False, side=mkside(8))
    ncount = len(names)
    hk(0x48db70, 0, 0, 9, ret=lambda emu, k: ncount, this_=True)
    def cstr(emu, a):
        out = b''
        while len(out) < 0x40:
            b = emu.rbytes(a + len(out), 1)
            if b == b'\0': break
            out += b
        return out
    def scmp(emu, k, _s=mkside(10)):
        a, b = cstr(emu, emu.arg32(0)), cstr(emu, emu.arg32(1))
        emu.calllog.append(('cmp', a.hex(), b.hex()))
        _s(emu, k)
    c.emu.w32(0x676414, pystub(c, 2, ret=lambda emu, k: 0 if cstr(emu, emu.arg32(0)) == cstr(emu, emu.arg32(1)) else 1, pop=0, this=False, side=scmp))
    return [this, 0 if r.random() < 0.35 else r.getrandbits(32) | 1]


S(0x4901f0, 'GUESS hand 0x4901f0', 'thiscall', None, ret='eax', gen=g4901f0, note='batch216060')


def g4780f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x5e0); VT = rnd(c, 0x5b0); c.emu.w32(this, VT)
    RD = rnd(c, 0x20)
    O = rnd(c, 0x20); OV = rnd(c, 0x10); c.emu.w32(O, OV)
    VTL = rnd(c, 0x80)
    NODES = [rnd(c, 0x10) for _ in range(3)]
    CNT = r.choice([0, 1, 2, 3])
    NEW = rnd(c, 0x30); HOLD = rnd(c, 0x10); HV = rnd(c, 0x20); c.emu.w32(HOLD, HV)
    c.emu.w32(NEW + 0, HV) if False else None
    G2 = rnd(c, 0x1ab0); c.emu.w32(0x70039c, G2)
    A1 = rnd(c, 0x30); A2 = rnd(c, 0x30); c.emu.w32(G2 + 0x1aa3, A1); c.emu.w32(A1 + 0x18, A2)
    A2V = rnd(c, 0x20); c.emu.w32(A2, A2V)
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    NAMEOBJ = rnd(c, 0x10); c.emu.w32(NAMEOBJ + 4, r.choice([0, rnd(c, 0x10)]))
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x5b0, 0x40)), zlib.crc32(emu.rbytes(NEW, 0x30))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    seq = [0]
    def s4c(emu, k, _s=mkside(0)):
        seq[0] = 0
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
        _s(emu, k)
    def s5c(emu, k, _s=mkside(1)):
        i = seq[0]; seq[0] += 1
        emu.w32(emu.arg32(0), 1 if i < CNT else 0)
        _s(emu, k)
    c.emu.w32(VTL + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=s4c))
    c.emu.w32(VTL + 0x5c, pystub(c, 1, ret=lambda emu, k: NODES[k % 3], this='mark', stackmark=(0,), side=s5c))
    c.emu.w32(HV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(3)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=lambda emu, k: 0, pop=0, this=False, side=mkside(4)))
    c.emu.w32(VT + 0x20, pystub(c, 0, ret=lambda emu, k: NAMEOBJ, this=True, side=mkside(5)))
    c.emu.w32(VT + 0x5a4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(6)))
    c.emu.w32(A2V + 0xc, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(7)))
    def hk(addr, n, pop, j, act=None, ret=None, this_='mark', stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x473370, 1, 4, 8, this_=True)
    hk(0x4e11d0, 2, 8, 9, this_=True)
    def w4(emu):
        emu.w32(emu.arg32(0), r.choice([0, 1, 0x55, r.getrandbits(32)]))
    hk(0x4e11e0, 2, 8, 10, w4, this_=True)
    hk(0x4e12e0, 2, 8, 11, w4, this_=True, stackmark=(0,))
    def a_fill(emu):
        e = emu.arg32(0)
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x14)))
        emu.w32(e, VTL)
    hk(0x4e0fd0, 1, 4, 12, lambda emu: log16(emu, emu.arg32(0), 'Llist'), this_=True, stackmark=(0,))
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x14)))
        emu.w32(e, VTL)
    hk(0x4ccba0, 0, 0, 13, a_ctor)
    hk(0x4e1b30, 0, 0, 14, this_=True)
    hk(0x4cdd40, 0, 0, 15, ret=lambda emu, k: r.choice([0, 1, 2, 5]))
    hk(0x4ccf60, 0, 0, 16, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NEW, pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: HOLD, pop=8, this=True, side=mkside(1))
    return [this, RD]


S(0x4780f0, 'GUESS hand 0x4780f0', 'thiscall', None, ret='eax', gen=g4780f0, note='batch216060')


def g452bc0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40); VT = rnd(c, 0x1f0); c.emu.w32(this, VT)
    RD = rnd(c, 0x20)
    c.emu.w32(this + 0x18, r.getrandbits(32))
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    NAMEOBJ = rnd(c, 0x20); NV = rnd(c, 0x1f0); c.emu.w32(NAMEOBJ, NV)
    R1 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(18)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(VT + 0x20, pystub(c, 0, ret=lambda emu, k: NAMEOBJ, this=True, side=mkside(0)))
    def s1d8(emu, k, _s=mkside(1)):
        fill16(emu, emu.arg32(0)); _s(emu, k)
    c.emu.w32(NV + 0x1d8, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=s1d8))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: (LOG if emu.arg32(1) == 0x3f else LOG2), this=True, side=mkside(2)))
    LOG2 = rnd(c, 0x10); LV2 = rnd(c, 0x40); c.emu.w32(LOG2, LV2)
    c.emu.w32(LV + 0x30, pystub(c, 3, ret=lambda emu, k: 0, pop=0, this=False, side=mkside(3)))
    c.emu.w32(LV2 + 0x2c, pystub(c, 3, ret=lambda emu, k: 0, pop=0, this=False, side=mkside(4)))
    types = [r.choice([2, 3, 0x102, 2, 1, 3]) for _ in range(6)]
    ti = [0]
    def t16(emu, k):
        v = types[ti[0] % 6]; ti[0] += 1
        return v
    hook_rec(c, 0x4e1600, 0, ret=t16, pop=0, this=True, side=mkside(5))
    def w4(emu):
        emu.calllog.append(('pre', emu.r32(emu.arg32(0))))
        if r.random() < 0.7:
            emu.w32(emu.arg32(0), r.choice([0, 1, 0x100, r.getrandbits(32)]))
    def hk(addr, n, pop, j, act=None, ret=None, this_='mark', stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x448a30, 1, 4, 6, this_=True)
    hk(0x4e11e0, 2, 8, 7, w4, this_=True, stackmark=(0,))
    hk(0x4e12f0, 2, 8, 8, w4, this_=True, stackmark=(0,))
    hk(0x4e1b30, 0, 0, 9, this_=True)
    hk(0x4cc1d0, 0, 0, 10, this_=True)
    hk(0x4cbec0, 0, 0, 11, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, RD]


S(0x452bc0, 'GUESS hand 0x452bc0', 'thiscall', None, ret='eax', gen=g452bc0, note='batch216060')


def g5c6f40(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x90)
    OBJ = rnd(c, 0x30); c.emu.w32(this + 0x44, OBJ)
    LISTO = rnd(c, 0x10); LV = rnd(c, 0x80); c.emu.w32(LISTO, LV)
    c.emu.w32(OBJ + 0x18, 0 if r.random() < 0.15 else LISTO)
    c.emu.w32(this + 0x71, struct.unpack('<I', struct.pack('<f', r.choice([0.0, 1.0, 2.5, -3.25, 1e10, r.uniform(-9, 9)])))[0])
    cnt = r.choice([0, 1, 2, 3])
    NODES = [rnd(c, 0x10) for _ in range(3)]
    SBUFS = [rnd(c, 0x40) for _ in range(8)]
    si = [0]
    ENT = rnd(c, 0x10); EV = rnd(c, 0x260); c.emu.w32(ENT, EV)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0xae0); AV = rnd(c, 0x150); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    C3 = rnd(c, 0x10); C3V = rnd(c, 0x270); c.emu.w32(C3, C3V); c.emu.w32(A + 0xadc, C3)
    HOB = rnd(c, 0x10); HV = rnd(c, 0x70); c.emu.w32(HOB, HV)
    HOLD = rnd(c, 0x10); HOLDV = rnd(c, 0x20); c.emu.w32(HOLD, HOLDV); c.emu.w32(this + 0x60, HOLD)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x40, 0x40)), [zlib.crc32(emu.rbytes(b, 0x40)) for b in SBUFS]))
            sr[j](emu, k)
        return side
    seq = [0]
    def s4c(emu, k, _s=mkside(0)):
        seq[0] = 0
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12)))
        _s(emu, k)
    def s5c(emu, k, _s=mkside(1)):
        i = seq[0]; seq[0] += 1
        emu.w32(emu.arg32(0), 1 if i < cnt else 0)
        _s(emu, k)
    c.emu.w32(LV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=s4c))
    c.emu.w32(LV + 0x5c, pystub(c, 1, ret=lambda emu, k: NODES[k % 3], this=True, stackmark=(0,), side=s5c))
    c.emu.w32(AV + 0x58, pystub(c, 1, ret=lambda emu, k: ENT, this=True, side=mkside(2)))
    fl = lambda emu, k: r.choice([0.0, 1.5, -2.0, 7.25, float('nan'), r.uniform(-50, 50)])
    c.emu.w32(EV + 0x248, pystub(c, 0, ret=lambda emu, k: 0, this=True, st0=fl, side=mkside(3)))
    c.emu.w32(EV + 0x240, pystub(c, 0, ret=lambda emu, k: 0, this=True, st0=fl, side=mkside(4)))
    c.emu.w32(C3V + 0x25c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(5)))
    c.emu.w32(AV + 0x138, pystub(c, 0, ret=lambda emu, k: HOB, this=True, side=mkside(6)))
    c.emu.w32(AV + 0x4c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(7)))
    c.emu.w32(HV + 0x60, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(8)))
    c.emu.w32(HOLDV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(9)))
    def al(emu, k):
        v = SBUFS[si[0] % 8]; si[0] += 1
        return v
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(10))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=mkside(11))
    hook_rec(c, 0x5c7570, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(12))
    return [this]


S(0x5c6f40, 'GUESS hand 0x5c6f40', 'thiscall', None, ret='eax', gen=g5c6f40, note='batch216060')


def g483b60(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0x20); VT = rnd(c, 0x3a0); c.emu.w32(this, VT)
    mask = c.emu.rbytes(0x67cd50, 8)
    c0 = struct.unpack('<f', struct.pack('<I', c.emu.r32(0x67cd44)))[0]
    A1 = rnd(c, 0x10)
    c.emu.wbytes(A1, struct.pack('<fff', *[r.choice([1.0, 2.0, 100.0, 100.0, 1.0, float('nan'), 0.0]) for _ in range(3)]))
    G2 = rnd(c, 0x1ab0); c.emu.w32(0x70039c, G2)
    Z = rnd(c, 0x30); c.emu.w32(G2 + 0x1aa3, Z)
    QO = rnd(c, 0x10); QV = rnd(c, 0x60); c.emu.w32(QO, QV); c.emu.w32(Z + 0x1c, QO)
    A = rnd(c, 0x10); AV = rnd(c, 0x60); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    objs = []
    for i in range(4):
        e = rnd(c, 0x10); ev = rnd(c, 0x270); c.emu.w32(e, ev)
        f = rnd(c, 0x10); fv = rnd(c, 0x5a0); c.emu.w32(f, fv)
        ob = rnd(c, 0x60)
        c.emu.w32(ob + 0x54, 0 if r.random() < 0.15 else e)
        objs.append((ob, e, ev, f, fv))
    n = r.choice([0, 1, 2, 3, 4, 4, 4, 3])
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20))))
            sr[j](emu, k)
        return side
    def rf():
        if r.random() < 0.65: return r.choice([0.1, -0.1, 0.5, -0.5, 0.9, -0.9])
        return r.choice([0.0, 0.25, -0.75, 1.5, -3.0, 50.0, float('nan'), float('inf'), r.uniform(-5, 5)])
    def wf(emu, a, k): emu.wbytes(a, struct.pack('<' + 'f' * k, *[rf() for _ in range(k)]))
    def lg(emu, a, k, tag): emu.calllog.append((tag, emu.rbytes(a, 4 * k).hex()))
    def s384(emu, k, _s=mkside(0)):
        wf(emu, emu.arg32(0), 9); wf(emu, emu.arg32(1), 3); _s(emu, k)
    c.emu.w32(VT + 0x384, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0, 1), side=s384))
    def s38(emu, k, _s=mkside(1)):
        arr = emu.arg32(0)
        for i in range(n):
            emu.w32(arr + 4 * i, objs[i][0])
        wf(emu, emu.arg32(1), 9)
        emu.calllog.append(('q38', emu.arg32(2), emu.arg32(5), emu.arg32(6), emu.arg32(7), emu.arg32(8), emu.arg32(9)))
        lg(emu, emu.arg32(3), 9, 'q4c'); lg(emu, emu.arg32(4), 3, 'q1c')
        _s(emu, k)
    c.emu.w32(QV + 0x38, pystub(c, 10, ret=lambda emu, k: n, this=True, stackmark=(0, 1, 3, 4), side=s38))
    for ob, e, ev, f, fv in objs:
        c.emu.w32(ev + 0x1e0, pystub(c, 1, ret=lambda emu, k: r.choice([1, 1, 1, 1, 5, 0, 0x100]), this=True, side=mkside(2)))
        c.emu.w32(ev + 0x25c, pystub(c, 2, ret=lambda emu, k, f=f: (0 if r.random() < 0.1 else f), this=True, side=mkside(3)))
        c.emu.w32(fv + 0x1e0, pystub(c, 1, ret=lambda emu, k: r.choice([1, 1, 1, 1, 5, 0, 0x100]), this=True, side=mkside(4)))
        c.emu.w32(fv + 0x588, pystub(c, 0, ret=lambda emu, k: r.choice([1, 1, 1, 7, 0]), this=True, side=mkside(5)))
        def sf384(emu, k, _s=mkside(6)):
            lg(emu, emu.arg32(0), 9, 'f70'); wf(emu, emu.arg32(1), 3); _s(emu, k)
        c.emu.w32(fv + 0x384, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0, 1), side=sf384))
    c.emu.w32(AV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(7)))
    def hk(addr, n_, pop, j, act=None, ret=None, this_='mark', st0=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        kw = {}
        if st0 is not None: kw['st0'] = st0
        hook_rec(c, addr, n_, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, side=sd, stackmark=stackmark, **kw)
    def a441970(emu):
        lg(emu, emu.arg32(0), 9, 'm4c'); emu.calllog.append(('e441970', emu.reg('edx'))); wf(emu, emu.reg('ecx'), 3)
    hk(0x441970, 1, 4, 8, a441970, stackmark=(0,))
    def a441940(emu):
        lg(emu, emu.reg('edx'), 3, 'm2148'); wf(emu, emu.reg('ecx'), 3)
    hk(0x441940, 0, 0, 9, a441940)
    hk(0x4ccba0, 0, 0, 10, lambda emu: emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(16))))
    def a43e(emu):
        lg(emu, emu.reg('edx'), 3, 'v28'); lg(emu, emu.arg32(0), 3, 'v1c'); wf(emu, emu.reg('ecx'), 3)
    hk(0x43e920, 1, 4, 11, a43e, stackmark=(0,))
    def a4419(emu):
        lg(emu, emu.reg('ecx'), 3, 'v213c'); lg(emu, emu.reg('edx'), 9, 'm4c2'); wf(emu, emu.reg('ecx'), 3)
    hk(0x4419f0, 0, 0, 12, a4419)
    hk(0x4ccf60, 0, 0, 13, lambda emu: lg(emu, emu.reg('ecx'), 4, 'Ldtor'))
    def a4e0870(emu):
        lg(emu, emu.reg('ecx'), 3, 'dv1c'); lg(emu, emu.reg('edx'), 3, 'dv28')
    dists = sorted([r.choice([c0 * 0.9, c0 * 0.5, c0 * 0.25, c0 * 1.5, 0.0, 1e30, 5.0, c0]) for _ in range(8)], reverse=True)
    if r.random() < 0.15: dists[r.randrange(8)] = float('nan')
    di = [0]
    def stdist(emu, k):
        v = dists[di[0] % 8]; di[0] += 1
        return v
    hk(0x4e0870, 0, 0, 14, a4e0870, st0=stdist)
    return [this, r.getrandbits(32), A1]


S(0x483b60, 'GUESS hand 0x483b60', 'thiscall', None, ret='eax', gen=g483b60, note='batch216060')


def g595570(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x6c0); VT = rnd(c, 0x140); c.emu.w32(this, VT)
    ent = rnd(c, 0x90)
    c.emu.w32(ent + 0x7a, rnd(c, 0x10))
    c.emu.w16(this + 0x165, r.getrandbits(16)) if hasattr(c.emu, 'w16') else None
    ebxmode = r.choice(['same_null', 'same', 'diff', 'null_diff'])
    arg = 0 if ebxmode in ('same_null', 'null_diff') else ent
    if ebxmode in ('same_null', 'same'):
        c.emu.w32(this + 0x688, arg)
    else:
        c.emu.w32(this + 0x688, r.choice([0, ent + 4, 0x1234]) if arg else r.choice([ent, 0x1234]))
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x150); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    H = rnd(c, 0x10); HV = rnd(c, 0x90); c.emu.w32(H, HV)
    CST = rnd(c, 0x20)
    c.emu.wbytes(CST, bytes([r.choice([0, 65])]) + b'bc\0')
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x680, 0x40)), emu.r32(ent + 0x7a)))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(VT + 0x12c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(AV + 0x138, pystub(c, 0, ret=lambda emu, k: H, this=True, side=mkside(1)))
    c.emu.w32(AV + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(AV + 0x114, pystub(c, 5, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(4,), side=mkside(3)))
    def s88(emu, k, _s=mkside(4)):
        if r.random() < 0.6: emu.w32(emu.arg32(1), r.getrandbits(32))
        _s(emu, k)
    c.emu.w32(HV + 0x88, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(1,), side=s88))
    def scmp(emu, k, _s=mkside(5)):
        _s(emu, k)
    c.emu.w32(0x676414, pystub(c, 2, ret=lambda emu, k: r.choice([0, 0, 1, 0xffffffff]), pop=0, this=False, side=scmp))
    def hk(addr, n, pop, j, act=None, ret=None, this_='mark', stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cc5f0, 0, 0, 6, ret=lambda emu, k: r.choice([0, 0, 3]), this_=True)
    hk(0x4cc1d0, 0, 0, 7, ret=lambda emu, k: (0 if r.random() < 0.15 else CST), this_=True)
    hk(0x4d2280, 0, 0, 8, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x4d2330, 0, 0, 9, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    for addr, n, pop, j in ((0x4d3a00, 3, 12, 10), (0x4d39a0, 2, 8, 11), (0x4d3ad0, 3, 12, 12)):
        hk(addr, n, pop, j, lambda emu: (log16(emu, emu.reg('ecx'), 'Lt'), fill16(emu, emu.reg('ecx'))))
    hk(0x41e680, 0, 0, 13, this_=True)
    hk(0x4cbe80, 1, 4, 14, lambda emu: (emu.calllog.append(('Lctor', emu.arg32(0))), fill16(emu, emu.reg('ecx'))))
    hk(0x4cbee0, 1, 4, 15, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), log16(emu, emu.reg('ecx'), 'Ldst')), stackmark=(0,), this_=True)
    hk(0x4cbec0, 0, 0, 16, lambda emu: log16(emu, emu.reg('ecx'), 'Ld90'))
    return [this, arg]


S(0x595570, 'GUESS hand 0x595570', 'thiscall', None, ret='eax', gen=g595570, note='batch216060')


def g5f9be0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    V = rnd(c, 0x20); c.emu.w32(this + 4, V)
    def mkstr(b):
        buf = c.emu.alloc(len(b) + 8, 4)
        c.emu.wbytes(buf, b + b'\0' * 4)
        o = c.emu.alloc(0x10, 4)
        c.emu.w32(o, buf); c.emu.w32(o + 4, buf + len(b))
        return o
    alpha = b'ab'
    def rs(): return bytes(r.choice(alpha) for _ in range(r.choice([0, 1, 2, 3, 5, 6, 8])))
    def rs0(): return bytes(r.choice(b'ab\0') for _ in range(r.choice([0, 1, 2, 3, 5, 6, 8])))
    size = r.choice([0, 1, 2, 3, 4])
    strs = [rs0() if r.random() < 0.3 else rs() for _ in range(size)]
    key = r.choice(strs) if (strs and r.random() < 0.4) else rs()
    if strs and r.random() < 0.2:
        key = strs[0] + b'a'
    cap = size + r.choice([0, 0, 1, 3])
    arr = c.emu.alloc(max(cap, 1) * 4 + 8, 4)
    for i, b in enumerate(strs): c.emu.w32(arr + 4 * i, mkstr(b))
    c.emu.w32(V + 0xc, arr); c.emu.w32(V + 0x10, cap); c.emu.w32(V + 0x14, size)
    KEY = c.emu.alloc(len(key) + 8, 4); c.emu.wbytes(KEY, key + b'\0' * 4)
    NS = rnd(c, 0x10); NEWARR = rnd(c, 0x80)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', emu.r32(V + 0xc) != arr, emu.r32(V + 0x10), emu.r32(V + 0x14), zlib.crc32(emu.rbytes(NEWARR, 0x40)), emu.r32(arr), emu.r32(arr + 4)))
            sr[j](emu, k)
        return side
    def al(emu, k):
        return NS if emu.arg32(0) == 0xc else NEWARR
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(0))
    hook_rec(c, 0x42b390, 2, ret=lambda emu, k: NS + r.choice([0, 4]), pop=8, this=True, stackmark=(1,), side=mkside(1))
    hook_rec(c, 0x41e2c0, 1, ret=lambda emu, k: 0, pop=0, this=False, side=mkside(2))
    return [this, KEY]


S(0x5f9be0, 'GUESS hand 0x5f9be0', 'thiscall', None, ret='eax', gen=g5f9be0, note='batch216060')


def g5bd630(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = 0 if r.random() < 0.2 else rnd(c, 0x90)
    sr = [seh_record(c, 2) for _ in range(2)]
    def side(emu, k):
        if this:
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x90))))
        sr[0](emu, k)
    hook_rec(c, 0x469870, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=side)
    return [this]


S(0x5bd630, 'GUESS hand 0x5bd630', 'thiscall', None, ret='eax', gen=g5bd630, note='batch216060')


def g46a5e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x100)
    G2 = rnd(c, 0xc0); GV = rnd(c, 0x1b0); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x70); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    E = rnd(c, 0x10); EV = rnd(c, 0x220); c.emu.w32(E, EV)
    O = rnd(c, 0x10); OV = rnd(c, 0x10); c.emu.w32(O, OV)
    P = rnd(c, 0x10); PV = rnd(c, 0x10); c.emu.w32(P, PV)
    c.emu.w32(this + 0xd9, r.choice([0, O]))
    c.emu.w32(this + 0x9e, r.choice([0, P]))
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x90, 0x70))))
            sr[j](emu, k)
        return side
    c.emu.w32(AV + 0x58, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else E), this=True, side=mkside(0)))
    c.emu.w32(EV + 0x210, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    c.emu.w32(OV, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(PV, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    c.emu.w32(GV + 0x1a8, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(4)))
    hook_rec(c, 0x46a4f0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(5))
    return [this]


S(0x46a5e0, 'GUESS hand 0x46a5e0', 'thiscall', None, ret='eax', gen=g46a5e0, note='batch216060')


def g4b1320(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x90)
    RD = rnd(c, 0x20)
    STR = rnd(c, 0x20)
    c.emu.wbytes(STR, bytes([r.choice([0, 65])]) + b'xy\0')
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x40, 0x50))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    hook_rec(c, 0x4e5e60, 0, ret=lambda emu, k: r.choice([0, 1, 0x100, r.getrandbits(32)]), pop=0, this=True, side=mkside(0))
    hook_rec(c, 0x4e5ea0, 0, ret=lambda emu, k: r.choice([0, STR, STR]), pop=0, this=True, side=mkside(1))
    def hk(addr, n, pop, j, act=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this='mark', stackmark=stackmark, side=sd)
    hk(0x4cbe80, 1, 4, 2, lambda emu: (emu.calllog.append(('Lctor', emu.arg32(0))), fill16(emu, emu.reg('ecx'))))
    hk(0x4cbee0, 1, 4, 3, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), log16(emu, emu.reg('ecx'), 'Ldst')), stackmark=(0,))
    hk(0x4cbec0, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, RD]


S(0x4b1320, 'GUESS hand 0x4b1320', 'thiscall', None, ret='eax', gen=g4b1320, note='batch216060')


def g4bb830(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    G2 = rnd(c, 0x1ab0); GV = rnd(c, 0x10); c.emu.w32(0x70039c, G2)
    en = r.random() < 0.8
    EO = rnd(c, 0x10); EV = rnd(c, 0x80); c.emu.w32(EO, EV)
    c.emu.w32(G2 + 0x1a9f, EO if en else 0)
    M = rnd(c, 0x10); MV = rnd(c, 0x80); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    C = rnd(c, 0x10); c.emu.w32(M + 0xadc, C) if False else None
    MB = rnd(c, 0xae0); c.emu.w32(MB, MV); c.emu.w32(G2 + 0x9b, MB); c.emu.w32(MB + 0xadc, C)
    ENT = rnd(c, 0x90)
    RD = rnd(c, 0x20)
    BYT = c.emu.alloc(8, 4); c.emu.wbytes(BYT, bytes([r.choice([0xff, 3, 0x43, 0x83, 0x03, 0x01, 0x40, 0xc3])]) + b'\0' * 7)
    c.emu.w32(RD, BYT)
    STR = rnd(c, 0x10)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(ENT, 0x90))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(EV + 0x6c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(MV + 0x60, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else ENT), this=True, side=mkside(1)))
    def hk(addr, n, pop, j, act=None, ret=None, this_='mark', st0=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        kw = {}
        if st0 is not None: kw['st0'] = st0
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, side=sd, **kw)
    hk(0x4e5ea0, 0, 0, 2, ret=lambda emu, k: STR, this_=True)
    hk(0x4cbe80, 1, 4, 3, lambda emu: (emu.calllog.append(('Lc', emu.arg32(0))), fill16(emu, emu.reg('ecx'))))
    hk(0x4cc1d0, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Lcs'))
    hk(0x4e5e80, 0, 0, 5, this_=True, st0=lambda emu, k: r.choice([0.0, 1.5, -2.0, float('nan'), r.uniform(-9, 9)]))
    hk(0x4e5e60, 0, 0, 6, ret=lambda emu, k: r.choice([0, 1, 0x100, 5]), this_=True)
    hk(0x43eb80, 1, 4, 7, this_=True)
    hk(0x4cbec0, 0, 0, 8, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    c.emu.w32(ENT + 0x40, r.getrandbits(32)); c.emu.w32(ENT + 0x2c, r.getrandbits(32)); c.emu.w32(ENT + 0x88, r.getrandbits(32))
    return [0, r.getrandbits(32), RD]


S(0x4bb830, 'GUESS hand 0x4bb830', 'thiscall', None, ret='eax', gen=g4bb830, note='batch216060')


def g4a1460(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x8c0); c.emu.w32(this + 4, r.getrandbits(32))
    RD = rnd(c, 0x10); RV = rnd(c, 0x60); c.emu.w32(RD, RV)
    OBJS = [rnd(c, 0x850) for _ in range(8)]
    oi = [0]
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x150); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    H = rnd(c, 0x10); HV = rnd(c, 0x90); c.emu.w32(H, HV)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40)), zlib.crc32(emu.rbytes(this + 0x40, 0x40)), zlib.crc32(emu.rbytes(this + 0x8a0, 0x20)), [zlib.crc32(emu.rbytes(o + 0x800, 0x44)) for o in OBJS[:3]], emu.r32(0x7002a8)))
            sr[j](emu, k)
        return side
    c.emu.w32(0x7002a8, r.getrandbits(32))
    def w2(emu, k, _s=mkside(0)):
        emu.wbytes(emu.arg32(0), bytes([r.getrandbits(8), r.getrandbits(8)])); _s(emu, k)
    c.emu.w32(RV + 0x44, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=w2))
    cnt = r.choice([0, 1, 2, 3, 0xffffffff, 0x80000000, 4])
    def w4(emu, k, _s=mkside(1)):
        emu.w32(emu.arg32(0), cnt); _s(emu, k)
    c.emu.w32(RV + 0x48, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=w4))
    c.emu.w32(RV + 0x40, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    def s88(emu, k, _s=mkside(3)):
        if r.random() < 0.6: emu.w32(emu.arg32(1), r.getrandbits(32))
        _s(emu, k)
    c.emu.w32(AV + 0x138, pystub(c, 0, ret=lambda emu, k: H, this=True, side=mkside(4)))
    c.emu.w32(HV + 0x88, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(1,), side=s88))
    def al(emu, k):
        v = OBJS[oi[0] % 8]; oi[0] += 1
        return v
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(5))
    return [this, RD]


S(0x4a1460, 'GUESS hand 0x4a1460', 'thiscall', None, ret='al', gen=g4a1460, note='batch216060')


def g4b56b0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    this = rnd(c, 0xf8); VT = rnd(c, 0x90); c.emu.w32(this, VT)
    OB = rnd(c, 0x10); OV = rnd(c, 0x200); c.emu.w32(OB, OV); c.emu.w32(this + 0x44, OB)
    c.emu.w32(this + 0xee, r.choice([0, 1, 2, 3, 0xffffffff]))
    c.emu.wbytes(this + 0x9b, bytes([r.choice([0, 1])]) + b'\0')
    c.emu.w32(this + 0xde, struct.unpack('<I', struct.pack('<f', r.choice([0.0, 0.0, 1.0, 5.0, -1.0, float('nan')])))[0])
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x150); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    H = rnd(c, 0x10); HV = rnd(c, 0x90); c.emu.w32(H, HV)
    M = rnd(c, 0x10); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(0x700390, M)
    LOG = rnd(c, 0x10); LV = rnd(c, 0x40); c.emu.w32(LOG, LV)
    R1 = rnd(c, 0x20)
    lit = c.emu.rbytes(0x6920a8, 16).split(b'\0')[0]
    ENTS = []
    for i in range(3):
        e = rnd(c, 0x10)
        nm = c.emu.alloc(len(lit) + 8, 4)
        kind = r.choice(['lit', 'lit', 'other', 'null'])
        c.emu.wbytes(nm, (lit if kind == 'lit' else b'zz') + b'\0' * 4)
        c.emu.w32(e + 4, 0 if kind == 'null' else nm)
        ENTS.append(e)
    PP = [rnd(c, 0x10) for _ in range(3)]
    for p in PP: c.emu.w32(p + 4, struct.unpack('<I', struct.pack('<f', r.choice([0.0, -0.0, 2.0, 7.5, -3.0, float('nan')])))[0])
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x40, 0xb8))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(VT + 0x8c, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(AV + 0x138, pystub(c, 0, ret=lambda emu, k: H, this=True, side=mkside(1)))
    def s88(emu, k, _s=mkside(2)):
        if r.random() < 0.6: emu.w32(emu.arg32(1), r.getrandbits(32))
        _s(emu, k)
    c.emu.w32(HV + 0x88, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(1,), side=s88))
    def s130(emu, k, _s=mkside(3)):
        emu.calllog.append(('a130', emu.arg32(0), emu.arg32(1), 1 if emu.arg32(2) == 0 else 0))
        if emu.arg32(2) > 0x10000000 or True:
            try:
                if r.random() < 0.7: emu.w32(emu.arg32(2), r.choice(PP))
            except Exception: pass
        _s(emu, k)
    c.emu.w32(OV + 0x130, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(2,), side=s130))
    c.emu.w32(OV + 0x1dc, pystub(c, 2, ret=lambda emu, k: R1, this=True, stackmark=(0,), side=lambda emu, k: (fill16(emu, emu.arg32(0)), mkside(4)(emu, k))[1]))
    c.emu.w32(OV + 0x124, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(5)))
    c.emu.w32(MV + 0x20, pystub(c, 2, ret=lambda emu, k: LOG, this=True, side=mkside(6)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=lambda emu, k: 0, pop=0, this=False, side=mkside(7)))
    idx = [0]
    def r5620(emu, k):
        return 0 if r.random() < 0.25 else ENTS[emu.arg32(0) % 3]
    hook_rec(c, 0x4b5620, 1, ret=r5620, pop=4, this=True, side=mkside(8))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=mkside(9))
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=lambda emu, k: (emu.calllog.append(('Ld', emu.rbytes(emu.reg('ecx'), 16).hex())), mkside(10)(emu, k))[1])
    return [this]


S(0x4b56b0, 'GUESS hand 0x4b56b0', 'thiscall', None, ret='eax', gen=g4b56b0, note='batch216060')


def g4fe9e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x100); VT = rnd(c, 0x20); c.emu.w32(this, VT)
    c.emu.w32(this + 0x44, r.getrandbits(32))
    RD = rnd(c, 0x140); RV = rnd(c, 0x30); c.emu.w32(RD, RV)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x150); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    H = rnd(c, 0x10); HV = rnd(c, 0x90); c.emu.w32(H, HV)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x40, 0xc0))))
            sr[j](emu, k)
        return side
    def logW(emu, tag): emu.calllog.append((tag, zlib.crc32(emu.rbytes(emu.reg('ecx'), 0x13c))))
    c.emu.w32(VT + 8, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    def s18(emu, k, _s=mkside(1)):
        n = emu.arg32(1)
        emu.calllog.append(('w18', emu.arg32(0) - this, n, emu.rbytes(emu.arg32(0), n).hex()))
        _s(emu, k)
    c.emu.w32(RV + 0x18, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=s18))
    c.emu.w32(AV + 0x138, pystub(c, 0, ret=lambda emu, k: H, this=True, side=mkside(2)))
    c.emu.w32(AV + 0x4c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    c.emu.w32(HV + 0x60, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(4)))
    T44 = c.emu.r32(0x68e9cc + 0x44)
    def a44(emu, k, _s=mkside(5)):
        logW(emu, 'W44'); emu.calllog.append(('a44', emu.arg32(0) - this)); _s(emu, k)
    hook_rec(c, T44, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', side=a44)
    def a99c0(emu, k, _s=mkside(6)):
        logW(emu, 'W9c0'); emu.calllog.append(('a9c0', emu.arg32(0) - this)); _s(emu, k)
    hook_rec(c, 0x4999c0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', side=a99c0)
    def a9970(emu, k, _s=mkside(7)):
        logW(emu, 'W970'); _s(emu, k)
    hook_rec(c, 0x499970, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a9970)
    return [this, RD]


S(0x4fe9e0, 'GUESS hand 0x4fe9e0', 'thiscall', None, ret='al', gen=g4fe9e0, note='batch216060')


def g5ebbd0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x80)
    ARR = rnd(c, 0x40)
    k = r.choice([0, 1, 2, 3])
    for i in range(k): c.emu.w32(ARR + 4 * i, r.getrandbits(32))
    c.emu.w32(this + 0x62, ARR); c.emu.w32(this + 0x66, ARR + 4 * k)
    n2 = r.choice([0, 1, 2, 5, 0x3fffffff])
    c.emu.w32(this + 0x6a, (ARR + 4 * n2) & 0xffffffff if n2 < 100 else (ARR - 0x10) & 0xffffffff)
    H = rnd(c, 0x10); c.emu.w32(this + 0x3a, H); c.emu.w32(H + 4, r.getrandbits(32))
    sr = [seh_record(c, 2) for _ in range(4)]
    def side(emu, k_):
        emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x80))))
        sr[0](emu, k_)
    hook_rec(c, 0x634273, 2, ret=lambda emu, k_: r.getrandbits(32), pop=0, this=False, side=side)
    hook_rec(c, 0x54f870, 2, ret=lambda emu, k_: r.getrandbits(32), pop=8, this=True, side=side)
    return [this]


S(0x5ebbd0, 'GUESS hand 0x5ebbd0', 'thiscall', None, ret='eax', gen=g5ebbd0, note='batch216060')


def g45cb50(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    OW = rnd(c, 0x60); c.emu.w32(this + 8, OW)
    c.emu.w32(this + 4, r.getrandbits(32))
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    CB = rnd(c, 0xae0); c.emu.w32(G2 + 0x9b, CB)
    OBJA = rnd(c, 0x60); OBJB = rnd(c, 0x10); TV = rnd(c, 0x1e0); c.emu.w32(OBJB, TV)
    c.emu.w32(CB + 0xadc, OBJB if r.random() < 0.5 else OBJA)
    ED = rnd(c, 0x60)
    c.emu.w32(ED + 0x54, r.choice([OBJB, OBJA, OBJB]))
    c.emu.w32(OW + 0x50, r.choice([0, ED, ED, ED]))
    DST = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20)), zlib.crc32(emu.rbytes(DST, 0x20))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    c.emu.w32(TV + 0x1d4, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(OBJA, 0)
    TVA = rnd(c, 0x1e0); c.emu.w32(OBJA, TVA)
    c.emu.w32(TVA + 0x1d4, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbe80, 1, 4, 2, lambda emu: (emu.calllog.append(('Lc', emu.arg32(0))), fill16(emu, emu.reg('ecx'))))
    hk(0x4cc2c0, 1, 4, 3, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), emu.calllog.append(('Ldst', emu.reg('ecx') - DST if emu.reg('ecx') >= DST and emu.reg('ecx') < DST + 0x20 else emu.reg('ecx')))), stackmark=(0,), this_=True)
    hk(0x4cbec0, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, DST, r.choice([0, 1, 0x100, 0x12345600, r.getrandbits(32)])]


S(0x45cb50, 'GUESS hand 0x45cb50', 'thiscall', None, ret='eax', gen=g45cb50, note='batch216060')


def g430010(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20)
    nodes = [rnd(c, 0x40) for _ in range(5)]
    nn = r.choice([0, 1, 2, 3, 5])
    # acyclic tree: node i has children among nodes > i
    for i in range(5):
        n = nodes[i]
        l = r.choice([0] + nodes[i + 1:]) if i < 4 else 0
        rr = r.choice([0] + nodes[i + 1:]) if i < 4 else 0
        c.emu.w32(n + 9, l); c.emu.w32(n + 5, rr)
        for off in (0x19, 0xd):
            b = r.choice([0, c.emu.alloc(0x10, 4)])
            k = r.choice([0, 4, 8])
            c.emu.w32(n + off, b)
            c.emu.w32(n + off + (8 if off == 0x19 else 8), (b + k) & 0xffffffff)
    root = 0 if nn == 0 else nodes[r.randrange(0, min(nn, 5))]
    sr = [seh_record(c, 2) for _ in range(4)]
    def side(emu, k):
        emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20))))
        sr[0](emu, k)
    hook_rec(c, 0x54f870, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=side)
    return [this, root]


S(0x430010, 'GUESS hand 0x430010', 'thiscall', None, ret='eax', gen=g430010, note='batch216060')


def g4385e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x50)
    H = rnd(c, 0x10); HV = rnd(c, 0x10); c.emu.w32(H, HV)
    c.emu.w32(this + 0x3e, r.choice([0, H]))
    BLK = rnd(c, 0x20)
    NEWH = H
    BIG = rnd(c, 0x300)
    n256 = (BIG + 0xff) & ~0xff
    BUF = n256 - r.choice([0, 1, 3, 8, 21, 30])
    if BUF < BIG: BUF = n256
    STR = rnd(c, 0x30); c.emu.wbytes(STR, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 1, 5, 20]))) + b'\0')
    sr = [seh_record(c, 2) for _ in range(5)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x30, 0x20)), zlib.crc32(emu.rbytes(BLK - 8, 0x30)), zlib.crc32(emu.rbytes(BUF, 0x40))))
            sr[j](emu, k)
        return side
    c.emu.w32(HV + 4, pystub(c, 1, ret=lambda emu, k: BLK + 8, this=True, side=mkside(0)))
    def al(emu, k):
        return BUF if emu.arg32(0) != 0x1c else H
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: H, pop=8, this=True, side=mkside(2))
    return [this, STR, r.choice([0, 1, 0x1ff, 0x80, r.getrandbits(32)])]


S(0x4385e0, 'GUESS hand 0x4385e0', 'thiscall', None, ret='eax', gen=g4385e0, note='batch216060')


def g4d1530(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40)
    c.emu.w32(this + 0x14, r.choice([0, rnd(c, 0x10)]))
    c.emu.w32(this + 0xc, r.choice([0, rnd(c, 0x10)]))
    objs = []
    nobj = r.choice([0, 1, 2, 3])
    for i in range(nobj):
        o = rnd(c, 0x10); ov = rnd(c, 0x20); c.emu.w32(o, ov); objs.append((o, ov))
    c.emu.w32(this + 0x24, objs[0][0] if objs else 0)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40))))
            sr[j](emu, k)
        return side
    for i, (o, ov) in enumerate(objs):
        nxt = objs[i + 1][0] if i + 1 < nobj else 0
        def d14(emu, k, nxt=nxt, _s=mkside(0)):
            emu.w32(this + 0x24, nxt); _s(emu, k)
        c.emu.w32(ov + 0x14, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=d14))
    PEER = rnd(c, 0x40); N1 = rnd(c, 0x40); N2 = rnd(c, 0x40)
    mode = r.choice([0, 1, 2, 3, 4])
    if mode == 0:
        c.emu.w32(this + 0x2c, 0)
    else:
        c.emu.w32(this + 0x2c, PEER)
        c.emu.w32(this + 0x34, r.choice([0, N1])); c.emu.w32(this + 0x30, r.choice([0, N2]))
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1))
    hook_rec(c, 0x4d2030, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=mkside(2))
    return [this]


S(0x4d1530, 'GUESS hand 0x4d1530', 'thiscall', None, ret='eax', gen=g4d1530, note='batch216060')


def g4c90a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x50); VT = rnd(c, 0x70); c.emu.w32(this, VT)
    OB = rnd(c, 0x10); c.emu.w32(this + 0x44, OB)
    RD = rnd(c, 0x20)
    BYT = c.emu.alloc(8, 4); c.emu.wbytes(BYT, bytes([r.choice([0xff, 4, 0x44, 0x84, 0xc4, 0x03, 0x05, 0x40])]) + b'\0' * 7)
    c.emu.w32(RD, BYT)
    STR = rnd(c, 0x10)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x150); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    H = rnd(c, 0x10); HV = rnd(c, 0x90); c.emu.w32(H, HV)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x40, 0x10)), zlib.crc32(emu.rbytes(OB, 0x10))))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(AV + 0x138, pystub(c, 0, ret=lambda emu, k: H, this=True, side=mkside(0)))
    c.emu.w32(AV + 0x4c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    c.emu.w32(HV + 0x60, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(VT + 0x58, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    def hk(addr, n, pop, j, act=None, ret=None, this_='mark', stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbe80, 1, 4, 4, lambda emu: (emu.calllog.append(('Lc', emu.arg32(0))), fill16(emu, emu.reg('ecx'))))
    hk(0x4cbee0, 1, 4, 5, lambda emu: (log16(emu, emu.arg32(0), 'Lsrc'), log16(emu, emu.reg('ecx'), 'Ldst')), stackmark=(0,))
    hk(0x4cbec0, 0, 0, 6, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    hk(0x4e5ea0, 0, 0, 7, ret=lambda emu, k: STR, this_=True)
    hk(0x4cc1d0, 0, 0, 8, lambda emu: log16(emu, emu.reg('ecx'), 'Lcs'))
    c.emu.w32(OB + 4, r.getrandbits(32))
    return [this, r.getrandbits(32), RD]


S(0x4c90a0, 'GUESS hand 0x4c90a0', 'thiscall', None, ret='eax', gen=g4c90a0, note='batch216060')


def g4c4630(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0xb0); c.emu.w32(this + 4, r.getrandbits(32))
    RD = rnd(c, 0x10); RV = rnd(c, 0x80); c.emu.w32(RD, RV)
    R1 = rnd(c, 0x10); R1V = rnd(c, 0x50); c.emu.w32(R1, R1V)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x80, 0x30)), emu.r32(this + 4)))
            sr[j](emu, k)
        return side
    def fill16(emu, a): emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(16)))
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def w4(slot):
        def f(emu, k, _s=mkside(slot)):
            emu.w32(emu.arg32(0), r.getrandbits(32)); _s(emu, k)
        return f
    c.emu.w32(RV + 0x40, pystub(c, 1, ret=lambda emu, k: R1, this=True, side=w4(0)))
    c.emu.w32(R1V + 0x40, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=w4(1)))
    c.emu.w32(RV + 0x58, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=w4(2)))
    c.emu.w32(RV + 0x50, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=w4(3)))
    c.emu.w32(RV + 0x6c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=w4(4)))
    def hk(addr, n, pop, j, act=None, stackmark=(), this_='mark'):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x4cbeb0, 0, 0, 5, lambda emu: fill16(emu, emu.reg('ecx')))
    hk(0x6352f0, 1, 4, 6, lambda emu: emu.w32(emu.arg32(0), r.getrandbits(32)), stackmark=(0,), this_=True)
    def a4740(emu):
        emu.calllog.append(('v94', emu.r32(emu.arg32(0)))); log16(emu, emu.arg32(2), 'S90')
        emu.w32(emu.arg32(1), r.getrandbits(32))
    hk(0x4c4740, 3, 12, 7, a4740, stackmark=(0, 1, 2), this_=True)
    hk(0x4cbec0, 0, 0, 8, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, RD]


S(0x4c4630, 'GUESS hand 0x4c4630', 'thiscall', None, ret='al', gen=g4c4630, note='batch216060')


def g442ad0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20); VT = rnd(c, 0x340); c.emu.w32(this, VT)
    H = 0 if r.random() < 0.2 else rnd(c, 0x20)
    NODES = [rnd(c, 0x10) for _ in range(3)]
    cnt = r.choice([0, 1, 2, 3])
    VTL = rnd(c, 0x80)
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x70); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    EN = rnd(c, 0x20)
    Lad = [0]
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x20))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    c.emu.w32(VT + 0x314, pystub(c, 0, ret=lambda emu, k: H, this=True, side=mkside(0)))
    seq = [0]
    def s4c(emu, k, _s=mkside(1)):
        seq[0] = 0
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12))); _s(emu, k)
    def s5c(emu, k, _s=mkside(2)):
        i = seq[0]; seq[0] += 1
        emu.w32(emu.arg32(0), 1 if i < cnt else 0); _s(emu, k)
    c.emu.w32(VTL + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=s4c))
    c.emu.w32(VTL + 0x5c, pystub(c, 1, ret=lambda emu, k: NODES[k % 3], this='mark', stackmark=(0,), side=s5c))
    c.emu.w32(AV + 0x54, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else EN), this=True, side=mkside(3)))
    def hk(addr, n, pop, j, act=None, this_='mark', stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: r.getrandbits(32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    def a_L(emu):
        e = emu.reg('ecx'); Lad[0] = e
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x14))); emu.w32(e, VTL)
    hk(0x4ccba0, 0, 0, 4, a_L)
    hk(0x4e3180, 0, 0, 5, lambda emu: emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(4))))
    def a49(emu):
        C = emu.arg32(0)
        emu.calllog.append(('C', emu.r32(C), emu.r32(C + 4), emu.r32(C + 0x5c) == Lad[0]))
    hk(0x4e49d0, 1, 4, 6, a49, this_=True, stackmark=(0,))
    hk(0x44a1f0, 0, 0, 7, this_=True)
    hk(0x4da720, 1, 4, 8, this_=True)
    hk(0x4d9ce0, 0, 0, 9, this_=True)
    hk(0x4ccf60, 0, 0, 10, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this]


S(0x442ad0, 'GUESS hand 0x442ad0', 'thiscall', None, ret='eax', gen=g442ad0, note='batch216060')


def g44a200(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x30); RD = rnd(c, 0x20)
    pre = r.random() < 0.4
    HOLD = rnd(c, 0x10); HOLDV = rnd(c, 0x20); c.emu.w32(HOLD, HOLDV)
    c.emu.w32(this + 0x18, HOLD if pre else 0)
    NEWO = rnd(c, 0x20)
    VTL = rnd(c, 0x80)
    NODES = [rnd(c, 0x10) for _ in range(3)]
    cnt = r.choice([0, 1, 2, 3])
    G2 = rnd(c, 0xc0); c.emu.w32(0x70039c, G2)
    A = rnd(c, 0x10); AV = rnd(c, 0x70); c.emu.w32(A, AV); c.emu.w32(G2 + 0x9b, A)
    EN = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x30))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    seq = [0]
    def s4c(emu, k, _s=mkside(0)):
        seq[0] = 0
        emu.wbytes(emu.arg32(0), bytes(r.getrandbits(8) for _ in range(12))); _s(emu, k)
    def s5c(emu, k, _s=mkside(1)):
        i = seq[0]; seq[0] += 1
        emu.w32(emu.arg32(0), 1 if i < cnt else 0); _s(emu, k)
    c.emu.w32(VTL + 0x4c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=s4c))
    c.emu.w32(VTL + 0x5c, pystub(c, 1, ret=lambda emu, k: NODES[k % 3], this='mark', stackmark=(0,), side=s5c))
    c.emu.w32(AV + 0x58, pystub(c, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else EN), this=True, side=mkside(2)))
    c.emu.w32(HOLDV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    NV = rnd(c, 0x20); c.emu.w32(NEWO, NV)
    c.emu.w32(NV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    def hk(addr, n, pop, j, act=None, this_='mark', stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    def a_L(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x14))); emu.w32(e, VTL)
    hk(0x4ccba0, 0, 0, 4, a_L)
    hook_rec(c, 0x610100, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=False, side=mkside(5))
    hk(0x4e0fd0, 1, 4, 6, lambda emu: log16(emu, emu.arg32(0), 'LL'), this_=True, stackmark=(0,))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NEWO, pop=0, this=False, side=mkside(7))
    hk(0x4ccbe0, 2, 8, 8, this_=True, ret=lambda emu, k: NEWO)
    hk(0x4e1b30, 0, 0, 9, this_=True)
    hk(0x4ccf60, 0, 0, 10, lambda emu: log16(emu, emu.reg('ecx'), 'Ldtor'))
    return [this, RD]


S(0x44a200, 'GUESS hand 0x44a200', 'thiscall', None, ret='eax', gen=g44a200, note='batch216060')


def g497750(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40)
    M = rnd(c, 0x10); MV = rnd(c, 0x100); c.emu.w32(M, MV); c.emu.w32(0x70038c, M)
    BUF = rnd(c, 0x40); O2 = rnd(c, 0x20); R = rnd(c, 0x20)
    FB = rnd(c, 0x10); OB = rnd(c, 0x10); OV = rnd(c, 0x10); c.emu.w32(OB, OV)
    pre = r.random() < 0.6
    c.emu.w32(this + 0x30, r.choice([0, FB]) if pre else 0)
    c.emu.w32(this + 0x2c, r.choice([0, OB]) if pre else 0)
    c.emu.w32(this + 0x34, r.getrandbits(32)); c.emu.w32(this + 0x38, r.getrandbits(32))
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40))))
            sr[j](emu, k)
        return side
    c.emu.w32(MV + 0x48, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(MV + 0xdc, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    c.emu.w32(MV + 0xd8, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(2)))
    c.emu.w32(MV + 0x24, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(3)))
    c.emu.w32(OV, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(4)))
    cnt = [0]
    def al(emu, k):
        return BUF if emu.arg32(0) != 0x10 else (0 if r.random() < 0.25 else O2)
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, this=False, side=mkside(5))
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(6))
    hook_rec(c, 0x4ccdd0, 3, ret=lambda emu, k: R, pop=12, this=True, side=mkside(7))
    return [this, r.choice([0, 1, 0x40, 0x100, r.getrandbits(32) & 0xffff])]


S(0x497750, 'GUESS hand 0x497750', 'thiscall', None, ret='eax', gen=g497750, note='batch216060')


def g492250(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x5d60)
    G2 = rnd(c, 0x1ac0); GV = rnd(c, 0xc8); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    STR = rnd(c, 0x10)
    c.emu.w32(G2 + 0x1aab, r.choice([0, STR, STR]))
    WV = rnd(c, 0x80)
    RO = rnd(c, 0x10); ROV = rnd(c, 0x80); c.emu.w32(RO, ROV)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0xba0, 0x30)), zlib.crc32(emu.rbytes(this + 0x5d40, 0x10))))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    wl = [0]
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x20))); emu.w32(e, WV)
        emu.calllog.append(('cb', emu.arg32(1)))
    def hk(addr, n, pop, j, act=None, this_='mark', stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x499880, 2, 8, 0, a_ctor, stackmark=(0,))
    hk(0x49a790, 2, 8, 1, lambda emu: emu.calllog.append(('o', emu.arg32(0), emu.arg32(1))), ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff]))
    hk(0x49b340, 2, 8, 2, lambda emu: log16(emu, emu.reg('ecx'), 'W340'))
    hk(0x49b2e0, 1, 4, 3, lambda emu: log16(emu, emu.reg('ecx'), 'W2e0'))
    for off, nm in ((0x68, 4), (0x58, 5), (0x40, 6)):
        def f(emu, k, off=off, _s=mkside(nm)):
            emu.calllog.append(('w', off, emu.arg32(0) - this)); _s(emu, k)
        c.emu.w32(WV + off, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', side=f))
    c.emu.w32(GV + 4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=mkside(7)))
    c.emu.w32(GV + 0xbc, pystub(c, 0, ret=lambda emu, k: RO, this=True, side=mkside(8)))
    c.emu.w32(ROV + 0x70, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(9)))
    hk(0x492200, 1, 4, 10, this_=True, stackmark=(0,))
    hk(0x492880, 1, 4, 11, this_=True, stackmark=(0,))
    hk(0x499970, 0, 0, 12, lambda emu: log16(emu, emu.reg('ecx'), 'Wd'))
    return [this]


S(0x492250, 'GUESS hand 0x492250', 'thiscall', None, ret='eax', gen=g492250, note='batch216060')


def g601b10(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    A1 = rnd(c, 0x10)                       # out: length
    c.emu.w32(A1, r.getrandbits(32))
    BUFN = 0x80
    BUF = rnd(c, BUFN)
    c.emu.wbytes(BUF, bytes(r.getrandbits(8) | 1 for _ in range(BUFN)))
    STR = rnd(c, 0x20)
    SD = {}
    G1 = rnd(c, 0x40); V1 = rnd(c, 0x150); c.emu.w32(G1, V1); c.emu.w32(0x70039c, G1)
    M = rnd(c, 0x40); VM = rnd(c, 0x70); c.emu.w32(M, VM); c.emu.w32(0x700394, M)
    Z = rnd(c, 0x40); VZ = rnd(c, 0x30); c.emu.w32(Z, VZ); c.emu.w32(0x700390, Z)
    O2 = rnd(c, 0x40); V2 = rnd(c, 0x34); c.emu.w32(O2, V2)
    sr = [seh_record(c, 2) for _ in range(14)]
    SB = [0]
    def mkside(j, act=None):
        def side(emu, k):
            if act: act(emu, k)
            emu.calllog.append(('sv', j, SB[0] and zlib.crc32(emu.rbytes(SB[0], 0x80)), zlib.crc32(emu.rbytes(BUF, BUFN)), emu.r32(A1)))
            sr[j](emu, k)
        return side
    def a144(emu, k):
        S = emu.arg32(0)
        emu.wbytes(S, bytes(r.getrandbits(8) for _ in range(0x80)))
        emu.w32(S, STR)
        SB[0] = S
    c.emu.w32(V1 + 0x144, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, stackmark=(0,), side=mkside(0, a144)))
    ISOK = r.choice([0, 1, 1, 1])
    c.emu.w32(VM + 0x34, pystub(c, 2, ret=lambda emu, k: (r.choice([0, 0x100]) if not ISOK else r.choice([1, 0x1ff, 0xa5])), this=True, side=mkside(1)))
    LEN = r.choice([0, 1, 7, 0x20, 0x3f])
    c.emu.w32(VM + 0x30, pystub(c, 2, ret=lambda emu, k: LEN, this=True, side=mkside(2)))
    def a60(emu, k):
        ln = emu.arg32(2)
        emu.wbytes(emu.arg32(1), bytes(r.getrandbits(8) | 1 for _ in range(min(ln, BUFN))))
    EQ = r.choice([0, 1, 1, 1])
    c.emu.w32(VM + 0x60, pystub(c, 5, ret=lambda emu, k: (LEN if EQ else r.choice([LEN + 1, LEN - 1, 0, r.getrandbits(32)])), this=True, side=mkside(3, a60)))
    c.emu.w32(VZ + 0x20, pystub(c, 2, ret=lambda emu, k: O2, this=True, side=mkside(4)))
    c.emu.w32(V2 + 0x2c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(5)))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: emu.r32(emu.reg('ecx')), pop=0, this='mark', side=mkside(6))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.0 else BUF), pop=0, this=False, side=mkside(7))
    hook_rec(c, 0x41e2c0, 1, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(8))
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=mkside(9))
    return [r.getrandbits(32), A1]


S(0x601b10, 'GUESS hand 0x601b10', 'stdcall', None, ret='eax', gen=g601b10, note='batch216060')


def g492640(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40); VT = rnd(c, 0x1a0); c.emu.w32(this, VT)
    G2 = rnd(c, 0x1ac0); GV = rnd(c, 0xc8); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    OB = rnd(c, 0x20); OV = rnd(c, 0x48); c.emu.w32(OB, OV); c.emu.w32(G2 + 0x190f, OB)
    c.emu.w32(G2 + 0x1aab, r.getrandbits(32))
    WV = rnd(c, 0x68)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40)), emu.r32(G2 + 0x1aab)))
            sr[j](emu, k)
        return side
    def log16(emu, a, tag): emu.calllog.append((tag, emu.rbytes(a, 16).hex()))
    def a_ctor(emu):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x20))); emu.w32(e, WV)
        emu.calllog.append(('cb', emu.arg32(1)))
    def hk(addr, n, pop, j, act=None, this_='mark', stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x499880, 2, 8, 0, a_ctor, stackmark=(0,))
    hk(0x49a790, 2, 8, 1, None, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff, 1]))
    hk(0x49b340, 2, 8, 2, lambda emu: log16(emu, emu.reg('ecx'), 'W340'))
    hk(0x49b2e0, 1, 4, 3, lambda emu: log16(emu, emu.reg('ecx'), 'W2e0'))
    hk(0x499970, 0, 0, 4, lambda emu: log16(emu, emu.reg('ecx'), 'Wd'))
    hk(0x634273, 2, 0, 5, this_=False, stackmark=())
    def f40(emu, k, _s=mkside(6)):
        emu.w32(emu.arg32(0), 0x40 if r.random() < 0.7 else r.getrandbits(32))
        emu.calllog.append(('w', 0x40, emu.reg('ecx') - 0))
        _s(emu, k)
    c.emu.w32(WV + 0x40, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=f40))
    def f60(emu, k, _s=mkside(7)):
        if r.random() < 0.8: emu.w32(emu.arg32(0), r.choice([0, 0x1234, r.getrandbits(32)]))
        _s(emu, k)
    c.emu.w32(WV + 0x60, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', stackmark=(0,), side=f60))
    c.emu.w32(OV + 0x40, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(8)))
    c.emu.w32(VT + 0x188, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(9)))
    c.emu.w32(VT + 0xa8, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(10)))
    c.emu.w32(VT + 0xa0, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(11)))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(12)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(13)))
    return [this, r.getrandbits(32)]


S(0x492640, 'GUESS hand 0x492640', 'thiscall', None, ret='al', gen=g492640, note='batch216060')


def g4fe8a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x100)
    c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x100)))
    SO = rnd(c, 0x20); SV = rnd(c, 0x18); c.emu.w32(SO, SV)
    OV = rnd(c, 0x48)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x100))))
            sr[j](emu, k)
        return side
    def rd(emu, k, _s=mkside(0)):
        a = emu.arg32(0); n = emu.arg32(1)
        emu.calllog.append(('rd', a - this, n, emu.reg('ecx')))
        emu.wbytes(a, bytes(r.getrandbits(8) for _ in range(n)) if r.random() < 0.9 else bytes(n))
        _s(emu, k)
    c.emu.w32(SV + 0x10, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), this=True, side=rd))
    def ctor(emu, k, _s=mkside(1)):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x20))); emu.w32(e, OV)
        emu.calllog.append(('cb', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x4febf0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', side=ctor)
    def w40(emu, k, _s=mkside(2)):
        emu.calllog.append(('w', emu.arg32(0)))
        _s(emu, k)
    c.emu.w32(OV + 0x40, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this='mark', side=w40))
    def dt(emu, k, _s=mkside(3)):
        emu.calllog.append(('Wd', emu.rbytes(emu.reg('ecx'), 16).hex()))
        _s(emu, k)
    hook_rec(c, 0x499980, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=dt)
    return [this, SO]


S(0x4fe8a0, 'GUESS hand 0x4fe8a0', 'thiscall', None, ret='al', gen=g4fe8a0, note='batch216060')


def g5ca720(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TSZ = 0x7c0
    this = rnd(c, TSZ)
    c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TSZ)))
    G2 = rnd(c, 0x100); GV = rnd(c, 0x1b0); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    TB = rnd(c, 0x20); TV = rnd(c, 0x120); c.emu.w32(TB, TV); c.emu.w32(G2 + 0x9b, TB)
    OBJ = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TSZ))))
            sr[j](emu, k)
        return side
    def a_5c9530(emu, k, _s=mkside(0)):
        emu.calllog.append(('c', emu.reg('ecx') - this))
        emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TSZ)))
        _s(emu, k)
    hook_rec(c, 0x5c9530, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a_5c9530)
    c.emu.w32(TV + 0x114, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.3 else OBJ), pop=0, this=False, side=mkside(2))
    hook_rec(c, 0x4d83b0, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, side=mkside(3))
    c.emu.w32(GV + 0x1a4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(4)))
    return [this]


S(0x5ca720, 'GUESS hand 0x5ca720', 'thiscall', None, ret='eax', gen=g5ca720, note='batch216060')


def g42d420(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x1c00)
    N = r.choice([0, 1, 2, 3, 4, 6])
    ELEMS = rnd(c, 12 * (N + 2))
    CH = [0x20, 0x20, 0x0a, 0x0a, 0x0d, 0x41]
    BUFS = []
    for i in range(N + 2):
        n = r.choice([1, 1, 1, 1, 0, 2, 3])
        b = rnd(c, 8)
        c.emu.wbytes(b, bytes([r.choice(CH)] + [r.choice(CH) for _ in range(7)]))
        BUFS.append(b)
        c.emu.w32(ELEMS + 12 * i, b); c.emu.w32(ELEMS + 12 * i + 4, b + n); c.emu.w32(ELEMS + 12 * i + 8, b + 8)
    SENT = ELEMS + 12 * N
    # sentinel: length 1
    c.emu.w32(SENT + 4, BUFS[N] + 1)
    VEC = rnd(c, 0x10); c.emu.w32(this + 0x1b6d, VEC); c.emu.w32(VEC + 4, SENT)
    MAP = rnd(c, 0x40); c.emu.w32(this + 0x1b65, MAP)
    CELL = rnd(c, 0x10); c.emu.w32(CELL, ELEMS + 12 * r.randint(0, N))
    P1 = rnd(c, 8); P2 = rnd(c, 8)
    c.emu.w32(P1, r.getrandbits(32)); c.emu.w32(P2, r.getrandbits(32))
    BB = [rnd(c, 0x20) for _ in range(4)]
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', emu.r32(CELL), zlib.crc32(emu.rbytes(this + 0x1b60, 0x20))))
            sr[j](emu, k)
        return side
    def setstr(emu, a):
        b = r.choice([0, 0, BB[0], BB[1], BB[2]]); n = r.choice([0, 0, 5, 9])
        emu.w32(a, b); emu.w32(a + 4, b + n if b else b); emu.w32(a + 8, b + (n + r.choice([0, 3]) if b else 0))
    def hk(addr, n, pop, j, act=None, this_=False, stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x42b390, 2, 8, 0, lambda emu: setstr(emu, emu.reg('ecx')), this_='mark', stackmark=(1,))
    hk(0x5f2d60, 2, 8, 1, lambda emu: (emu.calllog.append(('as', emu.rbytes(emu.arg32(0), 1).hex())), setstr(emu, emu.reg('ecx')) if r.random() < 0.7 else None), this_='mark')
    def p4309(emu):
        emu.calllog.append(('f', emu.reg('edx'), emu.rbytes(emu.reg('ecx'), 2).hex()))
    hk(0x4309b0, 1, 4, 2, p4309, this_=True, ret=lambda emu, k: 0 if (emu.reg('ecx') == BUFS[N] or r.random() < 0.4) else r.choice([1, 0x100, r.getrandbits(32)]))
    hk(0x431330, 2, 8, 3, lambda emu: emu.calllog.append(('k', emu.rbytes(emu.arg32(1), 12).hex())), this_=True, stackmark=(0, 1), ret=lambda emu, k: P1)
    hk(0x431110, 2, 8, 4, lambda emu: emu.calllog.append(('k', emu.rbytes(emu.arg32(1), 12).hex())), this_=True, stackmark=(0, 1), ret=lambda emu, k: P2)
    hk(0x42b0f0, 3, 12, 5, lambda emu: emu.calllog.append(('pp', emu.r32(emu.reg('ecx')))), this_='mark')
    hk(0x430a20, 2, 8, 6, None, this_=True)
    hk(0x54f870, 2, 8, 7, None, this_='mark')
    return [this, CELL]


S(0x42d420, 'GUESS hand 0x42d420', 'thiscall', None, ret=None, gen=g42d420, note='batch216060')


def g493550(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x5d40; PS = 0x1180
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    P = rnd(c, PS); c.emu.wbytes(P, bytes(r.getrandbits(8) for _ in range(PS)))
    TV = rnd(c, 0x1a0); c.emu.w32(this, TV)
    if r.random() < 0.8:
        if c.emu.r32(this + 0xadc) == 0: c.emu.w32(this + 0xadc, r.getrandbits(32) | 1)
    else:
        c.emu.w32(this + 0xadc, 0)
    G2 = rnd(c, 0x1b00); c.emu.wbytes(G2, bytes(r.getrandbits(8) for _ in range(0x1b00))); GV = rnd(c, 0x180); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    O1 = rnd(c, 0x20); O1V = rnd(c, 0x20); c.emu.w32(O1, O1V)
    c.emu.w32(G2 + 0x1aa3, r.choice([0, O1, O1]))
    EO = rnd(c, 0x20); EV = rnd(c, 0xa4); c.emu.w32(EO, EV); c.emu.w32(G2 + 0x190f, EO)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    AO = [rnd(c, 0x40), rnd(c, 0x40)]
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS)), zlib.crc32(emu.rbytes(P, PS)), zlib.crc32(emu.rbytes(G2, 0x1b00))))
            sr[j](emu, k)
        return side
    def ps(n, ret=None, pop=None, this_=True, j=0, sm=()):
        return pystub(c, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=sm, side=mkside(j))
    c.emu.w32(ZV + 0x20, ps(2, ret=lambda emu, k: LG, j=0))
    c.emu.w32(LV + 0x2c, ps(3, pop=0, this_=False, j=1))
    c.emu.w32(O1V + 0x14, ps(1, j=2))
    c.emu.w32(EV + 0x98, ps(0, j=3))
    c.emu.w32(EV + 0x9c, ps(1, j=4))
    c.emu.w32(GV + 0x16c, ps(0, j=5))
    c.emu.w32(TV + 0x194, ps(0, j=6))
    cnt = [0]
    def a41(emu, k):
        pass
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.25 else AO[min(k, 1)]), pop=0, this=False, side=mkside(7))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=mkside(8))
    hook_rec(c, 0x4ccad0, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=mkside(9))
    def memset(emu, k, _s=mkside(10)):
        emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)) if emu.arg32(1) == 0 else b'')
        _s(emu, k)
    def memcpy(emu, k, _s=mkside(11)):
        emu.wbytes(emu.arg32(0), emu.rbytes(emu.arg32(1), emu.arg32(2)))
        _s(emu, k)
    hook_rec(c, 0x634d10, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=memset)
    hook_rec(c, 0x634d22, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=memcpy)
    return [this, P]


S(0x493550, 'GUESS hand 0x493550', 'thiscall', None, ret=None, gen=g493550, note='batch216060')


def g4a9600(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x15e90
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    G2 = rnd(c, 0x100); GV = rnd(c, 0x1b0); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    TB = rnd(c, 0x20); TV = rnd(c, 0x120); c.emu.w32(TB, TV); c.emu.w32(G2 + 0x9b, TB)
    AO = [rnd(c, 0x100) for _ in range(4)]
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS))))
            sr[j](emu, k)
        return side
    def a_vs(emu, k, _s=mkside(0)):
        _s(emu, k)
    c.emu.w32(TV + 0x114, pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(0)))
    c.emu.w32(GV + 0x1a4, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(1)))
    hook_rec(c, 0x469870, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=mkside(2))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=mkside(3))
    hook_rec(c, 0x4d8330, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, side=mkside(4))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if (k > 0 and r.random() < 0.3) else AO[min(k, 3)]), pop=0, this=False, side=mkside(5))
    def memset(emu, k, _s=mkside(6)):
        if emu.arg32(1) == 0: emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
        _s(emu, k)
    hook_rec(c, 0x634d10, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=memset)
    return [this]


S(0x4a9600, 'GUESS hand 0x4a9600', 'thiscall', None, ret='eax', gen=g4a9600, note='batch216060')


def g540c70(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x80); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x80)))
    cnt = r.choice([0, 1, 2, 3, 5, 5])
    a0 = r.choice([3, 3, 0, 1, 2])
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = [rnd(c, 0x20) for _ in range(2)]; LV = [rnd(c, 0x34) for _ in range(2)]
    for i in range(2): c.emu.w32(LG[i], LV[i])
    def pool(n):
        p = rnd(c, n); c.emu.wbytes(p, bytes(r.getrandbits(8) for _ in range(n))); return p
    AO = [pool(0x34 * max(cnt, 1) + 0x40), pool(48 * max(cnt, 1) + 0x40), pool(1800 + 0x40)]
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x80))))
            sr[j](emu, k)
        return side
    nl = [0]
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG[min(k, 1)], this=True, side=mkside(0)))
    for i in range(2):
        c.emu.w32(LV[i] + 0x2c, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(1 + i)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if (k > 0 and r.random() < 0.25) else AO[min(k, 2)]), pop=0, this=False, side=mkside(3))
    def ctor(emu, k, _s=mkside(4)):
        emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(0x34)))
        _s(emu, k)
    hook_rec(c, 0x542110, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=ctor)
    hook_rec(c, 0x545260, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(5))
    return [this, a0, cnt]


S(0x540c70, 'GUESS hand 0x540c70', 'thiscall', None, ret='eax', gen=g540c70, note='batch216060')


def g434010(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20); VT = rnd(c, 0xb0); c.emu.w32(this, VT)
    O4 = rnd(c, 0x20); O4V = rnd(c, 0x90); c.emu.w32(O4, O4V)
    NEW4 = rnd(c, 0x28); c.emu.w32(NEW4, O4V)
    c.emu.w32(this + 4, r.choice([0, O4, O4]))
    OB = rnd(c, 0x20); OBV = rnd(c, 0x40); c.emu.w32(OB, OBV)
    NULLB = False
    pass
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    BUFA = rnd(c, 0x40); BUFB = rnd(c, 0x40)
    NODES = [rnd(c, 0x10) for _ in range(r.randint(0, 3))]
    NOBJ = []
    for nd in NODES:
        ob = rnd(c, 0x10); obv = rnd(c, 0x40); c.emu.w32(ob, obv); c.emu.w32(nd, ob); NOBJ.append(obv)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(BUFA, 0x20)), zlib.crc32(emu.rbytes(BUFB, 0x20)), emu.r32(this + 4)))
            sr[j](emu, k)
        return side
    LENA = [0]
    def a_ctorA(emu, k, _s=mkside(0)):
        e = emu.reg('ecx')
        n = r.choice([0, 3, 6, 9, 12])
        emu.wbytes(BUFA, bytes(r.choice(b'ab\\/\\/.') for _ in range(n)) + bytes(0x40 - n))
        emu.w32(e, BUFA); LENA[0] = n
        emu.calllog.append(('arg', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x4cbe80, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', side=a_ctorA)
    def a_len(emu, k, _s=mkside(1)):
        emu.calllog.append(('len', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cc5f0, 0, ret=lambda emu, k: LENA[0], pop=0, this='mark', side=a_len)
    def a_copy(emu, k, _s=mkside(2)):
        e = emu.reg('ecx')
        emu.calllog.append(('cp', emu.r32(emu.arg32(0))))
        emu.wbytes(BUFB, emu.rbytes(BUFA, 0x20) + bytes(0x20))
        emu.w32(e, BUFB)
        _s(emu, k)
    hook_rec(c, 0x4cbe50, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=a_copy)
    def a_dtor(emu, k, _s=mkside(3)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this='mark', side=a_dtor)
    def strrchr_like(emu, k):
        base = emu.arg32(0)
        n = 0
        while emu.rbytes(base + n, 1)[0] != 0 and n < 32: n += 1
        emu.calllog.append(('dot', emu.arg32(1), n))
        if r.random() < 0.3: return 0
        return base + r.randrange(0, n + 1)
    c.emu.w32(0x676258, pystub(c, 2, ret=strrchr_like, pop=0, this=False, side=mkside(4)))
    alloc_k = [0]
    def alloc(emu, k):
        sz = emu.arg32(0)
        if sz == 0x28: return NEW4
        if sz == 0x6f: return 0 if NULLB else OB
        return 0
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(5))
    hook_rec(c, 0x4cca60, 2, ret=lambda emu, k: emu.reg('ecx'), pop=8, this=True, side=mkside(6))
    hook_rec(c, 0x4d5440, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0, this=True, side=mkside(7))
    okw = lambda emu, k: (r.choice([0, 0x100]) if r.random() < 0.3 else r.choice([1, 0x1ff]))
    c.emu.w32(VT + 0xa0, pystub(c, 1, ret=lambda emu, k: r.choice([0, 0, 0x100, 1, 0x1ff]), this=True, side=mkside(8)))
    c.emu.w32(VT + 0x34, pystub(c, 2, ret=okw, this=True, side=mkside(9)))
    c.emu.w32(OBV + 0x34, pystub(c, 2, ret=okw, this=True, side=mkside(10)))
    nxt = [0]
    c.emu.w32(O4V + 0x4c, pystub(c, 1, ret=lambda emu, k: (nxt.__setitem__(0, 0), 0)[1], this=True, stackmark=(0,), side=mkside(11)))
    def nextn(emu, k):
        i = nxt[0]; nxt[0] += 1
        return NODES[i] if i < len(NODES) else 0
    c.emu.w32(O4V + 0x64, pystub(c, 1, ret=nextn, this=True, stackmark=(0,), side=mkside(12)))
    c.emu.w32(O4V + 0x84, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(13)))
    for ov in NOBJ:
        c.emu.w32(ov + 0x2c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), this=True, side=mkside(13)))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(14)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=mkside(15)))
    STR = rnd(c, 0x10)
    return [this, STR, r.choice([0, 1, 0x100, 5])]


S(0x434010, 'GUESS hand 0x434010', 'thiscall', None, ret='eax', gen=g434010, note='batch216060')


def g4af780(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x60); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x60)))
    TV = rnd(c, 0x60); c.emu.w32(this, TV)
    pz = lambda: 0 if r.random() < 0.5 else r.getrandbits(32)
    c.emu.w32(this + 0x4c, pz()); c.emu.w32(this + 0x48, pz())
    for off in (0x54, 0x55, 0x56):
        c.emu.w32(this + off, 0 if r.random() < 0.5 else 1)   # byte flags (neighbouring bytes get clobbered, deliberate)
    c.emu.w32(this + 0x58, r.getrandbits(32))
    PO = rnd(c, 0x20); POV = rnd(c, 0x1e0); c.emu.w32(PO, POV); c.emu.w32(PO + 4, r.choice([0, 0x6f0000 + 0x100, r.getrandbits(32)]))
    c.emu.w32(this + 0x44, PO)
    G2 = rnd(c, 0x100); GV = rnd(c, 0x10); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    M = rnd(c, 0xae0); MV = rnd(c, 0x140); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    OBJ = rnd(c, 0x20); OV = rnd(c, 0x260); c.emu.w32(OBJ, OV); c.emu.w32(M + 0xadc, OBJ)
    O1 = rnd(c, 0x20); O1V = rnd(c, 0x90); c.emu.w32(O1, O1V)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    BUFX = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x60))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    rz = lambda emu, k: r.choice([0, 0, 1, r.getrandbits(32)])
    c.emu.w32(MV + 0x138, pystub(c, 0, ret=lambda emu, k: O1, this=True, side=mkside(0)))
    def a88(emu, k, _s=mkside(1)):
        if r.random() < 0.7: emu.w32(emu.arg32(1), r.choice([0, r.getrandbits(32)]))
        _s(emu, k)
    c.emu.w32(O1V + 0x88, pystub(c, 2, ret=rnd32, this=True, stackmark=(1,), side=a88))
    c.emu.w32(OV + 0x25c, pystub(c, 0, ret=rnd32, this=True, side=mkside(2)))
    c.emu.w32(MV + 0x4c, pystub(c, 3, ret=rz, this=True, side=mkside(3)))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=rz, this=True, side=mkside(4)))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(5)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=rnd32, pop=0, this=False, side=mkside(6)))
    c.emu.w32(POV + 0xbc, pystub(c, 1, ret=rnd32, this=True, side=mkside(7)))
    c.emu.w32(POV + 0xcc, pystub(c, 1, ret=rnd32, this=True, side=mkside(8)))
    def a1d8(emu, k, _s=mkside(9)):
        emu.w32(emu.arg32(0), BUFX)
        _s(emu, k)
    c.emu.w32(POV + 0x1d8, pystub(c, 2, ret=lambda emu, k: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    c.emu.w32(TV + 0x58, pystub(c, 0, ret=rnd32, this=True, side=mkside(10)))
    def a_dtor(emu, k, _s=mkside(11)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dtor)
    return [this]


S(0x4af780, 'GUESS hand 0x4af780', 'thiscall', None, ret=None, gen=g4af780, note='batch216060')


def g42a820(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x1c20
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.wbytes(this + 0x62, b'\0')
    for off in (0x1b5a, 0x1b5b, 0x1b5c): c.emu.wbytes(this + off, bytes([r.choice([0, 0, 1, 0x80])]))
    G2 = rnd(c, 0x20); GV = rnd(c, 0x70); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    M = rnd(c, 0x20); MV = rnd(c, 0x80); c.emu.w32(M, MV); c.emu.w32(0x700394, M)
    BUFS = [rnd(c, 0x20) for _ in range(4)]
    for b in BUFS: c.emu.wbytes(b, bytes(r.getrandbits(8) for _ in range(0x20)))
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    PR = r.choice([0.2, 0.5, 0.5, 0.8])
    def lk(emu, k, _s=mkside(0)):
        emu.w32(emu.arg32(1), r.choice(BUFS))
        _s(emu, k)
    c.emu.w32(GV + 0x5c, pystub(c, 2, ret=lambda emu, k: (r.choice([1, 0x1ff, 0xa5]) if r.random() < PR else r.choice([0, 0x100])), this=True, stackmark=(1,), side=lk))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(1)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=rnd32, pop=0, this=False, side=mkside(2)))
    c.emu.w32(MV + 0x78, pystub(c, 1, ret=rnd32, this=True, side=mkside(3)))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=rnd32, pop=0, this=False, side=mkside(4)))
    hook_rec(c, 0x42de30, 0, ret=rnd32, pop=0, this='mark', side=mkside(5))
    def a_ctor(emu, k, _s=mkside(6)):
        emu.w32(emu.reg('ecx'), emu.arg32(0))
        _s(emu, k)
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=a_ctor)
    def a_asg(emu, k, _s=mkside(7)):
        emu.calllog.append(('asg', emu.r32(emu.arg32(0))))
        _s(emu, k)
    hook_rec(c, 0x4cbee0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=a_asg)
    def a_dt(emu, k, _s=mkside(8)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dt)
    hook_rec(c, 0x42da80, 1, ret=rnd32, pop=4, this=True, side=mkside(9))
    return [this]


S(0x42a820, 'GUESS hand 0x42a820', 'thiscall', None, ret=None, gen=g42a820, note='batch216060')


def g617150(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40)
    edi = rnd(c, 0x20); A = rnd(c, 0x60); B = rnd(c, 0x20); DX = rnd(c, 0x80)
    c.emu.w32(edi + 0xc, A); c.emu.w32(edi + 0x10, B); c.emu.w32(B + 8, DX)
    c.emu.wbytes(A, bytes(r.getrandbits(8) for _ in range(0x60)))
    FLT = r.random() < 0.65
    c.emu.wbytes(A + 0x3c, bytes([r.choice([0x00, 0x20, 0x30]) if FLT else r.choice([0x10, 0x11])]))
    c.emu.w32(A + 0x44, r.choice([0, r.getrandbits(32) | 1]) if FLT else (r.getrandbits(32) | 1 if r.random() < 0.8 else 0))
    esi = rnd(c, 0xb9b0); CC = rnd(c, 0x1400)
    c.emu.w32(esi + 0xb9a4, CC); c.emu.wbytes(CC + 0x13f0, bytes([r.choice([0, 0, 0, 1, 0x80]) if not FLT else 0]))
    G2 = rnd(c, 0x1ac0); OO = rnd(c, 0x40); c.emu.w32(0x70039c, G2); c.emu.w32(G2 + 0x1aa3, OO)
    X = r.choice([0, 4, 0x10, 0x20]); c.emu.w32(OO + 0x20, X)
    R = rnd(c, 0x60); c.emu.w32(DX + 0x10, R - X + 0)
    c1 = c.emu.r32(0x678858); c2 = c.emu.r32(0x6785d0); lim = c.emu.r32(0x680a60)
    NAN = 0x7fc00000
    pick = lambda base: r.choice([base, base, base, base ^ 1, NAN])
    c.emu.w32(DX + 0x54, pick(c1)); c.emu.w32(DX + 0x58, pick(c2))
    c.emu.w32(DX + 0x20, r.choice([0, 0x100, 0x1000, 0x1100, 0x4, 0x2000, 0x100, 0x1000]))
    c.emu.w32(R + 0x10, r.choice([lim, lim, lim, (lim + 1) & 0xffffffff, (lim - 1) & 0xffffffff, NAN, NAN, 0, 0x7f7fffff]))
    OBJ = rnd(c, 0x10); O14 = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(OBJ, 0xc)), zlib.crc32(emu.rbytes(A + 0x30, 0x20))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: (0 if r.random() < 0.15 else (OBJ if emu.arg32(0) == 0xc else O14)), pop=0, this=False, side=mkside(0))
    def a617360(emu, k, _s=mkside(1)):
        if r.random() < 0.3: emu.wbytes(A + 0x3c, bytes([emu.rbytes(A + 0x3c, 1)[0] & ~0x10 & 0xff]))
        _s(emu, k)
    hook_rec(c, 0x617360, 0, ret=rnd32, pop=0, this=True, side=a617360)
    hook_rec(c, 0x658db0, 0, ret=rnd32, pop=0, this=True, side=mkside(2))
    hook_rec(c, 0x616490, 3, ret=rnd32, pop=12, this=True, side=mkside(3))
    hook_rec(c, 0x616580, 3, ret=rnd32, pop=12, this=True, side=mkside(4))
    hook_rec(c, 0x616620, 3, ret=rnd32, pop=12, this=True, side=mkside(5))
    return [this, edi, esi]


S(0x617150, 'GUESS hand 0x617150', 'thiscall', None, ret='eax', gen=g617150, note='batch216060')


def g5f18e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    len1 = r.choice([0, 1, 3])
    s1 = bytes(r.choice(b'abc') for _ in range(len1))
    ALPHA = b'ab cd=ef;gh ij=kl;mn;'
    s2 = bytes(r.choice(ALPHA) for _ in range(r.randint(0, 14)))
    TYPES = list(range(1, 12)) * 2 + [0xff, 0x41, 0x44, 0xc5, 0, 12, 0x3f]
    a1 = rnd(c, 0x120)
    blob = b'\x07' + s1 + b'\0' + b'\x55' + s2 + b'\0'
    pay = bytes(r.choice(TYPES) for _ in range(0x80))
    c.emu.wbytes(a1, blob + pay)
    OBJ = rnd(c, 0x20); OV = rnd(c, 0x40); c.emu.w32(OBJ, OV)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    BUFC = rnd(c, 0x80)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(BUFC, 0x80))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def cstr(emu, a):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < 0x7f: n += 1
        return emu.rbytes(a, n)
    def strchr_(emu, k):
        s = emu.arg32(0); ch = emu.arg32(1) & 0xff
        d = cstr(emu, s)
        i = d.find(bytes([ch]))
        return 0 if i < 0 else s + i
    def strrchr_(emu, k):
        s = emu.arg32(0); ch = emu.arg32(1) & 0xff
        d = cstr(emu, s)
        i = d.rfind(bytes([ch]))
        return 0 if i < 0 else s + i
    c.emu.w32(0x676254, pystub(c, 2, ret=strchr_, pop=0, this=False, side=mkside(0)))
    c.emu.w32(0x676258, pystub(c, 2, ret=strrchr_, pop=0, this=False, side=mkside(1)))
    def a_ctor(emu, k, _s=mkside(2)):
        d = cstr(emu, emu.arg32(0))
        emu.wbytes(BUFC, d + bytes(0x80 - len(d)))
        emu.w32(emu.reg('ecx'), BUFC)
        emu.calllog.append(('cs', d.hex()))
        _s(emu, k)
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=a_ctor)
    def a_dt(emu, k, _s=mkside(3)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dt)
    def adv(emu):
        p = emu.reg('ecx')
        emu.w32(p, emu.r32(p) + r.choice([1, 2, 4]))
    def hlp(j, nargs, wr):
        def sd(emu, k, _s=mkside(j)):
            adv(emu)
            if wr and nargs: emu.w32(emu.arg32(0), r.getrandbits(32))
            _s(emu, k)
        return sd
    hook_rec(c, 0x4e5ea0, 0, ret=rnd32, pop=0, this='mark', side=hlp(4, 0, False))
    hook_rec(c, 0x4e5e60, 0, ret=rnd32, pop=0, this='mark', side=hlp(5, 0, False))
    hook_rec(c, 0x4e6420, 0, ret=rnd32, pop=0, this='mark', side=hlp(6, 0, False))
    hook_rec(c, 0x4e6250, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=hlp(7, 1, True))
    hook_rec(c, 0x4e6180, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=hlp(8, 1, True))
    hook_rec(c, 0x4e6050, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=hlp(9, 1, True))
    hook_rec(c, 0x4e6330, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=hlp(10, 1, False))
    hook_rec(c, 0x4ccbe0, 2, ret=rnd32, pop=8, this='mark', side=mkside(11))
    hook_rec(c, 0x4ccfe0, 0, ret=rnd32, pop=0, this='mark', side=mkside(12))
    for off in (0x1c, 0x20, 0x24):
        c.emu.w32(OV + off, pystub(c, 2, ret=rnd32, this=True, side=mkside(13)))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(13)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=rnd32, pop=0, this=False, side=mkside(13)))
    return [OBJ, a1]


S(0x5f18e0, 'GUESS hand 0x5f18e0', 'stdcall', None, ret=None, gen=g5f18e0, note='batch216060')


def g4402a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x20); TV = rnd(c, 0x1d0); c.emu.w32(this, TV)
    OBJ = rnd(c, 0x20); OV = rnd(c, 0x90); c.emu.w32(OBJ, OV)
    XS = [rnd(c, 0x10) for _ in range(3)]
    X0 = r.choice([0, XS[0], XS[0]])
    c.emu.w32(OBJ + 8, X0)
    G2 = rnd(c, 0x100); GV = rnd(c, 0x10); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    M = rnd(c, 0x20); MV = rnd(c, 0x60); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    CV = rnd(c, 0x70)
    W = rnd(c, 0x10); WV = rnd(c, 0x160); c.emu.w32(W, WV)
    OB54 = []
    for i in range(3):
        ob = rnd(c, 0x60)
        c.emu.wbytes(ob, bytes(r.getrandbits(8) for _ in range(0x60)))
        c.emu.w32(ob + 0x3c, r.choice([0, 0x800000, 0x1, 0x800001]))
        c.emu.w32(ob + 0x54, r.choice([0, W, W]))
        OB54.append(ob)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(OBJ, 0x20)), [emu.r32(o + 0x3c) for o in OB54]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def a1c0(emu, k, _s=mkside(0)):
        emu.calllog.append(('a6', emu.arg32(4) & 0xff)) if False else None
        _s(emu, k)
    # arg 4 (a6 dword) has stack garbage above its low byte: log only the low byte
    def a1c0b(emu, k, _s=mkside(0)):
        emu.calllog.append(('a6', emu.r32(emu.reg('esp') + 20) & 0xff))
        _s(emu, k)
    c.emu.w32(TV + 0x1c0, pystub(c, 4, pop=20, ret=lambda emu, k: (0 if r.random() < 0.25 else OBJ), this=True, side=a1c0b))
    c.emu.w32(MV + 0x4c, pystub(c, 1, ret=rnd32, this=True, side=mkside(1)))
    c.emu.w32(MV + 0x50, pystub(c, 1, ret=rnd32, this=True, side=mkside(2)))
    nz = lambda emu, k: r.choice([0, 0, 1, 0x1ff]) if r.random() < 0.7 else OB54[r.randrange(3)]
    first = [True]
    def r54(emu, k):
        return r.choice([0, 0, OB54[0], OB54[1], OB54[2], OB54[2]])
    c.emu.w32(MV + 0x54, pystub(c, 1, ret=r54, this=True, side=mkside(3)))
    c.emu.w32(OV + 0x74, pystub(c, 2, ret=rnd32, this=True, side=mkside(4)))
    nxt = [0]
    def a50(emu, k, _s=mkside(5)):
        i = nxt[0]; nxt[0] += 1
        emu.w32(emu.arg32(0), XS[i] if (i + 1 < len(XS) and r.random() < 0.6) else 0)
        _s(emu, k)
    c.emu.w32(OV + 0x50, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a50))
    cnt = [0]
    def a4c(emu, k, _s=mkside(6)):
        cnt[0] = r.choice([0, 1, 2, 3])
        emu.w32(emu.arg32(0), r.getrandbits(32) & 0xffff)
        _s(emu, k)
    def a5c(emu, k, _s=mkside(7)):
        emu.w32(emu.arg32(0), cnt[0])
        if cnt[0] > 0: cnt[0] -= 1
        _s(emu, k)
    c.emu.w32(CV + 0x4c, pystub(c, 1, ret=rnd32, this='mark', stackmark=(0,), side=a4c))
    c.emu.w32(CV + 0x5c, pystub(c, 1, ret=rnd32, this='mark', stackmark=(0,), side=a5c))
    def a_ctor(emu, k, _s=mkside(8)):
        emu.w32(emu.reg('ecx'), CV)
        _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=a_ctor)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=mkside(9))
    hook_rec(c, 0x4cd540, 1, ret=rnd32, pop=4, this='mark', side=mkside(10))
    hook_rec(c, 0x4da340, 4, ret=rnd32, pop=16, this=True, side=mkside(11))
    hook_rec(c, 0x4dc630, 2, ret=rnd32, pop=8, this=True, side=mkside(12))
    c.emu.w32(WV + 0x154, pystub(c, 0, ret=rnd32, this=True, side=mkside(13)))
    c.emu.w32(WV + 0x158, pystub(c, 0, ret=rnd32, this=True, side=mkside(13)))
    A = r.choice([0, 0x1234]); B = r.choice([0, 0x5678])
    return [this, r.getrandbits(32), r.getrandbits(32), A, B, r.getrandbits(32), r.getrandbits(32), r.choice([0, 1, 0xff, 0x100])]


S(0x4402a0, 'GUESS hand 0x4402a0', 'thiscall', None, ret='eax', gen=g4402a0, note='batch216060')


def g5207e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x2720
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    TV = rnd(c, 0x270); c.emu.w32(this, TV)
    c.emu.w32(this + 4, r.choice([0, 0, rnd(c, 0x10)]))
    DV = rnd(c, 0x1e0)
    def mkD():
        d = rnd(c, 0x20); c.emu.w32(d, DV)
        e = rnd(c, 0x40); c.emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0x40)))
        c.emu.w32(e + 0x23, r.choice([0, 0x100000, 0x100001, 0x200000, 0x300000]))
        c.emu.w32(d + 0xc, e)
        return d
    DOBJ = mkD(); c.emu.w32(this + 0x25d1, DOBJ)
    nodes = []
    for i in range(r.choice([0, 1, 2, 3])):
        n = rnd(c, 0x70); c.emu.wbytes(n, bytes(r.getrandbits(8) for _ in range(0x70)))
        c.emu.w32(n + 0x54, mkD()); nodes.append(n)
    for i, n in enumerate(nodes): c.emu.w32(n + 0x60, nodes[i + 1] if i + 1 < len(nodes) else 0)
    c.emu.w32(this + 0x50, nodes[0] if nodes else 0)
    RO = [rnd(c, 0x10) for _ in range(2)]; ROV = rnd(c, 0x90)
    for q in RO: c.emu.w32(q, ROV)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    G2 = rnd(c, 0x100); GV = rnd(c, 0x10); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    M = rnd(c, 0x20); MV = rnd(c, 0x150); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    O1 = rnd(c, 0x20); O1V = rnd(c, 0x90); c.emu.w32(O1, O1V)
    BUFX = rnd(c, 0x20); STRN = rnd(c, 0x20)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x20, TS - 0x20))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    c.emu.w32(TV + 0x80, pystub(c, 2, ret=rnd32, this=True, side=mkside(0)))
    c.emu.w32(TV + 0x25c, pystub(c, 2, ret=lambda emu, k: r.choice([0, RO[0], RO[1]]), this=True, side=mkside(1)))
    c.emu.w32(ROV + 0x84, pystub(c, 1, ret=rnd32, this=True, side=mkside(2)))
    c.emu.w32(DV + 0x8c, pystub(c, 1, ret=rnd32, this=True, side=mkside(3)))
    def a1d8(emu, k, _s=mkside(4)):
        emu.w32(emu.arg32(0), BUFX)
        _s(emu, k)
    c.emu.w32(DV + 0x1d8, pystub(c, 2, ret=lambda emu, k: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(5)))
    c.emu.w32(LV + 0x2c, pystub(c, 3, ret=rnd32, pop=0, this=False, side=mkside(6)))
    c.emu.w32(MV + 0x138, pystub(c, 0, ret=lambda emu, k: O1, this=True, side=mkside(7)))
    def a88(emu, k, _s=mkside(8)):
        if r.random() < 0.7: emu.w32(emu.arg32(1), r.getrandbits(32))
        _s(emu, k)
    c.emu.w32(O1V + 0x88, pystub(c, 2, ret=rnd32, this=True, stackmark=(1,), side=a88))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=rnd32, this=True, side=mkside(9)))
    hook_rec(c, 0x515630, 0, ret=rnd32, pop=0, this=True, side=mkside(10))
    hook_rec(c, 0x4dc110, 0, ret=lambda emu, k: r.choice([STRN, BUFX]), pop=0, this=True, side=mkside(11))
    def a850(emu, k, _s=mkside(12)):
        emu.calllog.append(('edx', emu.reg('edx')))
        _s(emu, k)
    hook_rec(c, 0x4cc850, 0, ret=lambda emu, k: r.choice([0, 0, 1, 0x100]), pop=0, this=True, side=a850)
    def a_dt(emu, k, _s=mkside(13)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dt)
    return [this]


S(0x5207e0, 'GUESS hand 0x5207e0', 'thiscall', None, ret='eax', gen=g5207e0, note='batch216060')


def g4ad4d0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x300
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    BV = rnd(c, 0x40); c.emu.w32(this + 0x11a, BV)
    QV = rnd(c, 0x60); c.emu.w32(this + 0x1c6, QV)
    PO = rnd(c, 0x20); POV = rnd(c, 0x1e0); c.emu.w32(PO, POV); c.emu.w32(this + 0x44, PO)
    VTX = rnd(c, 0x220)
    XO = [rnd(c, 0x20) for _ in range(3)]
    for q in XO: c.emu.w32(q, VTX)
    c.emu.w32(this + 0x6a, r.choice([0, 0, 0x1234]))
    G2 = rnd(c, 0x100); GV = rnd(c, 0x10); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    M = rnd(c, 0x20); MV = rnd(c, 0x60); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    G3 = rnd(c, 0x20); G3V = rnd(c, 0xd0); c.emu.w32(G3, G3V); c.emu.w32(0x70038c, G3)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LGA = rnd(c, 0x20); LVA = rnd(c, 0x34); c.emu.w32(LGA, LVA)
    LGB = rnd(c, 0x20); LVB = rnd(c, 0x34); c.emu.w32(LGB, LVB)
    BUFS = [rnd(c, 0x20) for _ in range(3)]
    VALS = [0x11, 0x22, 0x33]
    O106V = rnd(c, 0xb0)
    O106 = []
    for i in range(3):
        o = rnd(c, 0x120); c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x120))); c.emu.w32(o, O106V)
        c.emu.w32(o + 0x106, r.choice(VALS + [0x44])); O106.append(o)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x20, TS - 0x20)), [emu.r32(o + 0x106) for o in O106]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    cnt14 = [r.choice([0, 1, 2, 3])]
    def r14(emu, k):
        if cnt14[0] > 0:
            cnt14[0] -= 1; return r.choice([1, 0x100 | 1, 5])
        return 0
    c.emu.w32(BV + 0x14, pystub(c, 0, ret=r14, this=True, side=mkside(0)))
    c.emu.w32(BV + 0x30, pystub(c, 1, ret=lambda emu, k: r.choice(VALS), this=True, side=mkside(1)))
    c.emu.w32(BV + 0x28, pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 5]), this=True, side=mkside(2)))
    c.emu.w32(BV + 0x3c, pystub(c, 1, ret=rnd32, this=True, side=mkside(3)))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=lambda emu, k: (0 if (r.random() < 0.2 and emu.arg32(0) != 0x1234) else r.choice(XO)), this=True, side=mkside(4)))
    c.emu.w32(VTX + 0x210, pystub(c, 1, ret=rnd32, this=True, side=mkside(5)))
    c.emu.w32(VTX + 0x128, pystub(c, 3, ret=rnd32, this=True, side=mkside(6)))
    def a1d8(emu, k, _s=mkside(7)):
        emu.w32(emu.arg32(0), r.choice(BUFS))
        _s(emu, k)
    c.emu.w32(VTX + 0x1d8, pystub(c, 2, ret=lambda emu, k: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    c.emu.w32(POV + 0x1d8, pystub(c, 2, ret=lambda emu, k: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: (LGA if emu.arg32(1) == 0x290 else LGB), this=True, side=mkside(8)))
    c.emu.w32(LVA + 0x2c, pystub(c, 3, ret=rnd32, pop=0, this=False, side=mkside(9)))
    c.emu.w32(LVB + 0x2c, pystub(c, 4, ret=rnd32, pop=0, this=False, side=mkside(10)))
    cnt = [0]
    def a4c(emu, k, _s=mkside(11)):
        cnt[0] = r.choice([0, 1, 2, 3])
        _s(emu, k)
    def a5c(emu, k, _s=mkside(12)):
        emu.w32(emu.arg32(0), cnt[0])
        if cnt[0] > 0: cnt[0] -= 1
        _s(emu, k)
    c.emu.w32(QV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a4c))
    c.emu.w32(QV + 0x5c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a5c))
    c.emu.w32(QV + 0x44, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(13)))
    c.emu.w32(G3V + 0xcc, pystub(c, 1, ret=lambda emu, k: r.choice([0, O106[0], O106[1], O106[2]]), this=True, side=mkside(14)))
    c.emu.w32(O106V + 0xac, pystub(c, 0, ret=rnd32, this=True, side=mkside(15)))
    def a_dt(emu, k, _s=mkside(15)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dt)
    return [this]


S(0x4ad4d0, 'GUESS hand 0x4ad4d0', 'thiscall', None, ret=None, gen=g4ad4d0, note='batch216060')


def g439970(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x1400); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x1400)))
    TV = rnd(c, 0x70); c.emu.w32(this, TV)
    LST = rnd(c, 0x20); LV = rnd(c, 0x70); c.emu.w32(LST, LV)
    c.emu.w32(this + 0x1338, r.choice([0, LST, LST]))
    STRS = []
    for t in (b'', b'a', b'a', b'ab', b'ab'):
        s = rnd(c, 0x10); c.emu.wbytes(s, t + b'\0' * 3); STRS.append(s)
    def mknode(size=0x100):
        n = rnd(c, size); c.emu.wbytes(n, bytes(r.getrandbits(8) for _ in range(size)))
        c.emu.w32(n + 0xaf, r.choice([0] + STRS + STRS))
        for base in (0x80, 0x90):
            k = r.choice([0, 1, 2, 3, 4, 4])
            for i in range(4):
                c.emu.w32(n + base + 4 * i, (r.getrandbits(32) & 0x7fffffff if r.random() < 0.8 else 0xfffffffe) if i < k else 0xffffffff)
        return n
    A0 = mknode()
    NODES = [mknode() for _ in range(r.choice([0, 1, 2, 3]))]
    NEW = mknode()
    W = rnd(c, 0x20); WV = rnd(c, 0x20); c.emu.w32(W, WV)
    E1 = rnd(c, 0x20); c.emu.wbytes(E1, bytes(r.getrandbits(8) for _ in range(0x20)))
    c.emu.w32(E1 + 4, r.choice([0, 0, 5]))
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x1330, 0x20)), zlib.crc32(emu.rbytes(A0, 0x100)), [zlib.crc32(emu.rbytes(n, 0x100)) for n in NODES + [NEW]]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    idx = [0]
    def a4c(emu, k, _s=mkside(0)):
        idx[0] = 0
        _s(emu, k)
    def r64(emu, k):
        i = idx[0]; idx[0] += 1
        return NODES[i] if i < len(NODES) else 0
    c.emu.w32(LV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a4c))
    c.emu.w32(LV + 0x64, pystub(c, 1, ret=r64, this=True, stackmark=(0,), side=mkside(1)))
    c.emu.w32(LV + 4, pystub(c, 1, ret=lambda emu, k: NEW + 4, this=True, side=mkside(2)))
    c.emu.w32(TV + 0x58, pystub(c, 1, ret=lambda emu, k: r.choice([0, E1 + 4]), this=True, side=mkside(3)))
    c.emu.w32(TV + 0x60, pystub(c, 1, ret=lambda emu, k: r.choice([0, W]), this=True, side=mkside(4)))
    c.emu.w32(WV + 0x10, pystub(c, 1, ret=lambda emu, k: r.choice([0, E1 + 4]), this=True, side=mkside(5)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x20), pop=0, this=False, side=mkside(6))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: LST, pop=8, this=True, side=mkside(7))
    hook_rec(c, 0x4cc130, 1, ret=lambda emu, k: r.choice([0, 1, 1, 0x100, 0x1ff]), pop=4, this=True, side=mkside(8))
    hook_rec(c, 0x4cbeb0, 0, ret=rnd32, pop=0, this=True, side=mkside(9))
    def a_assign(emu, k, _s=mkside(10)):
        emu.calllog.append(('as', emu.arg32(0) == A0))
        _s(emu, k)
    hook_rec(c, 0x4cbee0, 1, ret=rnd32, pop=4, this=True, side=a_assign)
    hook_rec(c, 0x439fd0, 1, ret=rnd32, pop=4, this=True, side=mkside(11))
    return [this, A0]


S(0x439970, 'GUESS hand 0x439970', 'thiscall', None, ret=None, gen=g439970, note='batch216060')


def g4ad9a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x300
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    BV = rnd(c, 0x40); c.emu.w32(this + 0x11a, BV)
    QV = rnd(c, 0x60); c.emu.w32(this + 0x1c6, QV)
    PO = rnd(c, 0x20); POV = rnd(c, 0x1e0); c.emu.w32(PO, POV); c.emu.w32(this + 0x44, PO)
    VTX = rnd(c, 0x220)
    XO = [rnd(c, 0x20) for _ in range(3)]
    for q in XO: c.emu.w32(q, VTX)
    c.emu.w32(this + 0x6a, r.choice([0, 0, 0x1234]))
    G2 = rnd(c, 0x100); GV = rnd(c, 0x10); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    M = rnd(c, 0x20); MV = rnd(c, 0x60); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    G3 = rnd(c, 0x20); G3V = rnd(c, 0xd0); c.emu.w32(G3, G3V); c.emu.w32(0x70038c, G3)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LGA = rnd(c, 0x20); LVA = rnd(c, 0x34); c.emu.w32(LGA, LVA)
    LGB = rnd(c, 0x20); LVB = rnd(c, 0x34); c.emu.w32(LGB, LVB)
    BUFS = [rnd(c, 0x20) for _ in range(3)]
    VALS = [0x11, 0x22, 0x33]
    O106V = rnd(c, 0xb0)
    O106 = []
    for i in range(3):
        o = rnd(c, 0x120); c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0x120))); c.emu.w32(o, O106V)
        c.emu.w32(o + 0x106, r.choice(VALS + [0x44])); O106.append(o)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x20, TS - 0x20)), [emu.r32(o + 0x106) for o in O106]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    cb = [0]
    def b4c(emu, k, _s=mkside(0)):
        cb[0] = r.choice([0, 1, 2, 3])
        _s(emu, k)
    def b5c(emu, k, _s=mkside(1)):
        emu.w32(emu.arg32(0), cb[0])
        if cb[0] > 0: cb[0] -= 1
        _s(emu, k)
    c.emu.w32(BV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=b4c))
    c.emu.w32(BV + 0x5c, pystub(c, 1, ret=lambda emu, k: r.choice(VALS), this=True, stackmark=(0,), side=b5c))
    c.emu.w32(VTX + 0x1e0, pystub(c, 1, ret=lambda emu, k: r.choice([0, 0x100, 1, 0x1ff]), this=True, side=mkside(4)))
    cnt14 = [r.choice([0, 1, 2, 3])]
    def r14(emu, k):
        if cnt14[0] > 0:
            cnt14[0] -= 1; return r.choice([1, 0x100 | 1, 5])
        return 0
    c.emu.w32(BV + 0x14, pystub(c, 0, ret=r14, this=True, side=mkside(0)))
    c.emu.w32(BV + 0x30, pystub(c, 1, ret=lambda emu, k: r.choice(VALS), this=True, side=mkside(1)))
    c.emu.w32(BV + 0x28, pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 5]), this=True, side=mkside(2)))
    c.emu.w32(BV + 0x3c, pystub(c, 1, ret=rnd32, this=True, side=mkside(3)))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=lambda emu, k: (0 if (r.random() < 0.2 and emu.arg32(0) != 0x1234) else r.choice(XO)), this=True, side=mkside(4)))
    c.emu.w32(VTX + 0x210, pystub(c, 1, ret=rnd32, this=True, side=mkside(5)))
    c.emu.w32(VTX + 0x128, pystub(c, 3, ret=rnd32, this=True, side=mkside(6)))
    def a1d8(emu, k, _s=mkside(7)):
        emu.w32(emu.arg32(0), r.choice(BUFS))
        _s(emu, k)
    c.emu.w32(VTX + 0x1d8, pystub(c, 2, ret=lambda emu, k: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    c.emu.w32(POV + 0x1d8, pystub(c, 2, ret=lambda emu, k: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: (LGA if emu.arg32(1) == 0x290 else LGB), this=True, side=mkside(8)))
    c.emu.w32(LVA + 0x2c, pystub(c, 3, ret=rnd32, pop=0, this=False, side=mkside(9)))
    c.emu.w32(LVB + 0x2c, pystub(c, 4, ret=rnd32, pop=0, this=False, side=mkside(10)))
    cnt = [0]
    def a4c(emu, k, _s=mkside(11)):
        cnt[0] = r.choice([0, 1, 2, 3])
        _s(emu, k)
    def a5c(emu, k, _s=mkside(12)):
        emu.w32(emu.arg32(0), cnt[0])
        if cnt[0] > 0: cnt[0] -= 1
        _s(emu, k)
    c.emu.w32(QV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a4c))
    c.emu.w32(QV + 0x5c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a5c))
    c.emu.w32(QV + 0x44, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(13)))
    c.emu.w32(G3V + 0xcc, pystub(c, 1, ret=lambda emu, k: r.choice([0, O106[0], O106[1], O106[2]]), this=True, side=mkside(14)))
    c.emu.w32(O106V + 0xac, pystub(c, 0, ret=rnd32, this=True, side=mkside(15)))
    def a_dt(emu, k, _s=mkside(15)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dt)
    return [this]


S(0x4ad9a0, 'GUESS hand 0x4ad9a0', 'thiscall', None, ret=None, gen=g4ad9a0, note='batch216060')


def g42d000(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x1c00)
    N = r.choice([0, 1, 2, 3, 4, 6])
    ELEMS = rnd(c, 12 * (N + 2))
    CH = [0x20, 0x20, 0x0a, 0x0a, 0x24, 0x24, 0x0d, 0x41]
    BUFS = []
    for i in range(N + 2):
        n = r.choice([1, 1, 1, 1, 0, 2, 3])
        b = rnd(c, 8)
        c.emu.wbytes(b, bytes([r.choice(CH)] + [r.choice(CH) for _ in range(7)]))
        BUFS.append(b)
        c.emu.w32(ELEMS + 12 * i, b); c.emu.w32(ELEMS + 12 * i + 4, b + n); c.emu.w32(ELEMS + 12 * i + 8, b + 8)
    SENT = ELEMS + 12 * N
    c.emu.w32(SENT + 4, BUFS[N] + 1)
    VEC = rnd(c, 0x10); c.emu.w32(this + 0x1b6d, VEC); c.emu.w32(VEC + 4, SENT)
    MAP = rnd(c, 0x40); c.emu.w32(this + 0x1b65, MAP)
    CELL = rnd(c, 0x10); c.emu.w32(CELL, ELEMS + 12 * r.randint(0, N))
    BB = [rnd(c, 0x20) for _ in range(4)]
    SOS = [rnd(c, 0x10) for _ in range(3)]
    for so in SOS:
        b = r.choice(BB); c.emu.w32(so, b); c.emu.w32(so + 4, b + r.choice([1, 3, 5])); c.emu.w32(so + 8, b + 8)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', emu.r32(CELL), zlib.crc32(emu.rbytes(this + 0x1b60, 0x20)), [emu.rbytes(so, 12).hex() for so in SOS]))
            sr[j](emu, k)
        return side
    def setstr(emu, a):
        b = r.choice([0, 0, BB[0], BB[1], BB[2]]); n = r.choice([0, 0, 5, 9])
        emu.w32(a, b); emu.w32(a + 4, b + n if b else b); emu.w32(a + 8, b + (n + r.choice([0, 3]) if b else 0))
    def hk(addr, n, pop, j, act=None, this_=False, stackmark=(), ret=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else (lambda emu, k: r.getrandbits(32))), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x42b390, 2, 8, 0, lambda emu: setstr(emu, emu.reg('ecx')), this_='mark', stackmark=(1,))
    hk(0x5f2d60, 2, 8, 1, lambda emu: (emu.calllog.append(('as', emu.arg32(0), emu.arg32(1))), setstr(emu, emu.reg('ecx')) if r.random() < 0.7 else None), this_='mark')
    hk(0x5f2c60, 2, 8, 2, lambda emu: (emu.calllog.append(('ap', emu.arg32(0), emu.arg32(1))), setstr(emu, emu.reg('ecx')) if r.random() < 0.5 else None), this_='mark')
    def p4309(emu):
        emu.calllog.append(('f', emu.reg('edx'), emu.rbytes(emu.reg('ecx'), 2).hex()))
    hk(0x4309b0, 1, 4, 3, p4309, this_=True, ret=lambda emu, k: 0 if (emu.reg('ecx') == BUFS[N] or r.random() < 0.4) else r.choice([1, 0x100, r.getrandbits(32)]))
    def a_be20(emu):
        emu.calllog.append(('k', emu.arg32(0) if emu.arg32(0) < 0x50000000 else 0, emu.rbytes(emu.arg32(0), 12).hex() if emu.arg32(0) >= 0x50000000 else ''))
    hk(0x42be20, 1, 4, 4, a_be20, this_=True, stackmark=(0,), ret=lambda emu, k: r.choice(SOS))
    hk(0x54f870, 2, 8, 5, None, this_='mark')
    return [this, CELL]


S(0x42d000, 'GUESS hand 0x42d000', 'thiscall', None, ret=None, gen=g42d000, note='batch216060')


def g598a50(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x2300
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    G2 = rnd(c, 0x100); GV = rnd(c, 0x1c0); c.emu.w32(G2, GV); c.emu.w32(0x70039c, G2)
    M = rnd(c, 0x20); MV = rnd(c, 0x40); c.emu.w32(M, MV); c.emu.w32(G2 + 0x9b, M)
    OV = rnd(c, 0x10)
    def mkobj():
        o = rnd(c, 0x10); c.emu.w32(o, OV); return o
    c.emu.w32(this + 0x22d7, r.choice([0, mkobj()]))
    for off in (0x75, 0x48, 0x4c, 0x50, 0x71, 0x79, 0x7d, 0x81):
        c.emu.w32(this + off, r.choice([0, mkobj(), mkobj()]))
    c.emu.w32(this + 0x5c, r.choice([0, mkobj()]))
    k = r.choice([0, 1, 2, 3])
    B0 = rnd(c, 0x40)
    for i in range(k):
        nd = rnd(c, 0x30)
        for off in (8, 0xc, 0x10, 0x14): c.emu.w32(nd + off, r.choice([0, rnd(c, 0x10)]))
        c.emu.w32(B0 + 4 * i, nd)
    c.emu.w32(this + 0x1da2, B0); c.emu.w32(this + 0x1da6, B0 + 4 * k); c.emu.w32(this + 0x1daa, B0 + 4 * (k + r.choice([0, 0, 1, 2])))
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x90)), zlib.crc32(emu.rbytes(this + 0x1da0, 0x14)), zlib.crc32(emu.rbytes(this + 0x22d0, 0x10))))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    c.emu.w32(OV, pystub(c, 1, ret=rnd32, this=True, side=mkside(0)))
    c.emu.w32(GV + 0x1a8, pystub(c, 1, ret=rnd32, this=True, side=mkside(1)))
    c.emu.w32(MV + 0x34, pystub(c, 1, ret=rnd32, this=True, side=mkside(2)))
    hook_rec(c, 0x5eaaf0, 0, ret=rnd32, pop=0, this=True, side=mkside(3))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=mkside(4))
    hook_rec(c, 0x4690b0, 0, ret=rnd32, pop=0, this=True, side=mkside(5))
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this=True, side=mkside(6))
    return [this]


S(0x598a50, 'GUESS hand 0x598a50', 'thiscall', None, ret=None, gen=g598a50, note='batch216060')


def g444530(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0xd0); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0xd0)))
    CV = rnd(c, 0x70)
    sr = [seh_record(c, 2) for _ in range(8)]
    ALLN = []
    def mknode_chain(depth):
        """build a chain of nodes; returns head node (or 0). node: byte flags at +8, next at +0xc, data pairs after."""
        nxt = 0
        nodes = []
        for _ in range(depth):
            n = rnd(c, 0x80); c.emu.wbytes(n, bytes(r.getrandbits(8) for _ in range(0x80)))
            nodes.append(n)
        for i, n in enumerate(nodes):
            al = r.choice([0, 1, 2, 3, 4, 5])
            if i == len(nodes) - 1: nxt = 0
            else: nxt = nodes[i + 1]
            # bit0 of flags decides whether the chain continues
            c.emu.wbytes(n + 8, bytes([al]))
            c.emu.w32(n + 0xc, nxt)
            # data pairs: even al: pairs start at +0xc (first pair = next ptr, X); odd al: +0x10
            base = n + 0xc if al % 2 == 0 else n + 0x10
            cnt = max(al // 2, 0) if al >= 2 else 0
            for k in range(cnt):
                lo = base + 8 * k
                if k == 0 and al % 2 == 0:
                    lov = nxt & ~7
                else:
                    lov = ((r.getrandbits(8) + 8) << 4)
                hiv = lov + 0x70 * r.choice([-1, 0, 0, 1, 2]) if lov >= 0x70 else lov
                if not (k == 0 and al % 2 == 0): c.emu.w32(lo, lov)
                c.emu.w32(lo + 4, hiv & 0xffffffff)
        return nodes
    def mkR():
        """R = (node, first pair ptr, limit) with a pair array of k pairs"""
        k = r.choice([1, 1, 2])
        arr = rnd(c, 8 * (k + 1))
        for i in range(k):
            lov = (r.getrandbits(8) + 8) << 4
            c.emu.w32(arr + 8 * i, lov | r.choice([0, 3, 7]))
            c.emu.w32(arr + 8 * i + 4, (lov + 0x70 * r.choice([-1, 0, 1, 2])) & 0xffffffff | r.choice([0, 5]))
        nodes = mknode_chain(r.choice([0, 1, 2, 3]))
        first = nodes[0] if nodes else 0
        if r.random() < 0.15: return (first, 0, 0)
        return (first, arr, arr + 8 * k)
    RS = [mkR() for _ in range(3)]
    key = lambda off: c.emu.r32(this + off)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0xd0))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    cnt_calls = [0]
    def a440(emu, k, _s=mkside(0)):
        rr = RS[k % 3]
        a = emu.arg32(0)
        emu.w32(emu.reg('ecx'), rr[0]); emu.w32(emu.reg('ecx') + 4, rr[1]); emu.w32(emu.reg('ecx') + 8, rr[2])
        emu.calllog.append(('key', a, k))
        _s(emu, k)
    hook_rec(c, 0x440ce0, 1, ret=rnd32, pop=4, this='mark', side=a440)
    hook_rec(c, 0x4444a0, 0, ret=rnd32, pop=0, this=True, side=mkside(1))
    def a_ctor(emu, k, _s=mkside(2)):
        emu.w32(emu.reg('ecx'), CV)
        _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=a_ctor)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=mkside(3))
    hook_rec(c, 0x4cd540, 1, ret=rnd32, pop=4, this='mark', side=mkside(4))
    hook_rec(c, 0x4da770, 1, ret=rnd32, pop=4, this=True, side=mkside(5))
    cnt = [0]
    def a4c(emu, k, _s=mkside(6)):
        cnt[0] = r.choice([0, 1, 2, 3]); _s(emu, k)
    def a5c(emu, k, _s=mkside(7)):
        emu.w32(emu.arg32(0), cnt[0])
        if cnt[0] > 0: cnt[0] -= 1
        _s(emu, k)
    c.emu.w32(CV + 0x4c, pystub(c, 1, ret=rnd32, this='mark', stackmark=(0,), side=a4c))
    c.emu.w32(CV + 0x5c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32) & 0xfffffff0 | 0x20000000, this='mark', stackmark=(0,), side=a5c))
    return [this]


S(0x444530, 'GUESS hand 0x444530', 'thiscall', None, ret=None, gen=g444530, note='batch216060')


def g5fd7c0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x40); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x40)))
    N = r.choice([0, 1, 2, 3, 4])
    ARR = rnd(c, 4 * (N + 1) + 8)
    ELS = []
    for i in range(N):
        e = rnd(c, 0xa0); c.emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(0xa0)))
        ELS.append(e)
    for i, e in enumerate(ELS): c.emu.w32(ARR + 4 * i, e)
    if ELS: c.emu.w32(ARR + 4 * N, r.choice(ELS))
    # field +0x20 of an element: sometimes equal to the pointer of some element in the array
    for i, e in enumerate(ELS):
        c.emu.w32(e + 0x20, r.choice(ELS + [r.getrandbits(32)] * (1 + len(ELS) // 2)) if ELS else 0)
    if ELS: c.emu.w32(ARR + 4 * N, c.emu.r32(r.choice(ELS) + 0x20))
    c.emu.w32(this + 0x18, ARR); c.emu.w32(this + 0x20, N)
    SUB = rnd(c, 0x20); c.emu.w32(this + 4, SUB)
    W = rnd(c, 0x20); WV = rnd(c, 0x60); c.emu.w32(W, WV)
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k: 0, pop=0, this=False))
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40)), zlib.crc32(emu.rbytes(SUB, 0x20)), [emu.r32(e + 0x20) for e in ELS]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def hk(addr, n, pop, j, this_='mark', stackmark=(), ret=None, act=None):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, n, ret=(ret if ret is not None else rnd32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    hk(0x5f9680, 1, 4, 0, act=lambda emu: emu.wbytes(emu.reg('ecx'), bytes(r.getrandbits(8) for _ in range(8))))
    hk(0x5f3e40, 1, 4, 1, this_=True, stackmark=(0,))
    hk(0x5fb770, 2, 8, 2, this_=True, stackmark=(1,))
    hk(0x5fbf90, 1, 4, 3, this_=True, ret=lambda emu, k: r.getrandbits(32))
    hk(0x5f9be0, 1, 4, 4, act=lambda emu: emu.calllog.append(('s', emu.rbytes(emu.reg('ecx'), 8).hex())))
    hk(0x5fa4f0, 1, 4, 5, act=lambda emu: emu.calllog.append(('s', emu.rbytes(emu.reg('ecx'), 8).hex())))
    hk(0x5fa0d0, 2, 8, 6, act=lambda emu: emu.calllog.append(('s', emu.rbytes(emu.reg('ecx'), 8).hex())), ret=None) if False else hk(0x5fa0d0, 2, 8, 6, act=lambda emu: emu.calllog.append(('s', emu.rbytes(emu.reg('ecx'), 8).hex())), ret=lambda emu, k: r.choice([0, 1, 2, 3, 5, 0xffffffff]))
    hk(0x5f92c0, 2, 8, 7, this_=True, stackmark=(1,))
    hk(0x5fda30, 3, 12, 8, this_=True, stackmark=(2,))
    hk(0x5f98a0, 0, 0, 9, act=lambda emu: emu.calllog.append(('dt', emu.rbytes(emu.reg('ecx'), 8).hex())))
    for off in (0x38, 0x2c, 0x30):
        c.emu.w32(WV + off, pystub(c, 1, ret=rnd32, this=True, side=mkside(10)))
    return [this, W]


S(0x5fd7c0, 'GUESS hand 0x5fd7c0', 'thiscall', None, ret=None, gen=g5fd7c0, note='batch216060')


def g4620d0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x140); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x140)))
    TV = rnd(c, 0x350); c.emu.w32(this, TV)
    A = rnd(c, 0x80); c.emu.wbytes(A, bytes(r.getrandbits(8) for _ in range(0x80)))
    c.emu.wbytes(A + 0x5a, bytes([r.choice([0, 0, 1, 7]), r.choice([0, 0, 1])]))
    c.emu.w32(A + 0x3c, r.choice([0, 0x800000, 0x1, 0x800001]))
    c.emu.w32(A + 0x6c, r.getrandbits(32))
    c.emu.w32(this + 8, A)
    O6 = rnd(c, 0x20); O6V = rnd(c, 0x60); c.emu.w32(O6, O6V); c.emu.w32(this + 0x6c, O6)
    a0 = rnd(c, 0x20); A2 = rnd(c, 0x80); c.emu.w32(a0 + 8, A2); KEY = r.getrandbits(32); c.emu.w32(A2 + 0x6c, KEY)
    N_old = r.choice([1, 2, 3])
    NODES = [rnd(c, 0x90) for _ in range(r.choice([0, 1, 2, 3]))]
    OLD = rnd(c, 24 * N_old + 0x20); c.emu.wbytes(OLD, bytes(r.getrandbits(8) for _ in range(24 * N_old)))
    for i in range(N_old):
        c.emu.wbytes(OLD + 24 * i + 4, bytes([r.choice([0, 1, 3, 2])]))
        c.emu.w32(OLD + 24 * i + 0x14, (r.choice(NODES) + 4) if NODES and r.random() < 0.6 else r.getrandbits(32))
    c.emu.w32(this + 0x1c, OLD)
    ITO = rnd(c, 0x20); ITV = rnd(c, 0x70); c.emu.w32(ITO, ITV); c.emu.w32(this + 0x18, r.choice([0, ITO, ITO]))
    for nd in NODES: c.emu.wbytes(nd, bytes(r.getrandbits(8) for _ in range(0x90)))
    G2 = rnd(c, 0x1ac0); U = rnd(c, 0x40); MG = rnd(c, 0x20); MV = rnd(c, 0xd0)
    c.emu.w32(G2 + 0x1aa3, U); c.emu.w32(U + 0x18, MG); c.emu.w32(MG, MV); c.emu.w32(0x70039c, G2)
    NNEW = r.choice([0, 1, 2, 3])
    TA = rnd(c, 0x100); TB = rnd(c, 0x100); IDX = rnd(c, 0x30 * 4 + 0x40)
    c.emu.wbytes(TA, bytes(r.choice([0xff] + list(range(N_old))) for _ in range(256)))
    c.emu.wbytes(TB, bytes(r.randrange(max(NNEW, 1)) for _ in range(256)))
    c.emu.wbytes(IDX, bytes(r.getrandbits(8) for _ in range(0x30 * 4 + 0x40)))
    for k in range(4): c.emu.wbytes(IDX + 0x2e + 0x30 * k, bytes([r.randrange(0, 256)]))
    NEWBUF = rnd(c, 24 * 4 + 0x40); c.emu.wbytes(NEWBUF, bytes(r.getrandbits(8) for _ in range(24 * 4 + 0x40)))
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x140)), zlib.crc32(emu.rbytes(NEWBUF, 24 * 4)), zlib.crc32(emu.rbytes(OLD, 24 * N_old)), [emu.r32(nd + 0x44) for nd in NODES]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    c.emu.w32(O6V + 0x58, pystub(c, 1, ret=rnd32, this=True, side=mkside(0)))
    c.emu.w32(O6V + 8, pystub(c, 1, ret=rnd32, this=True, side=mkside(1)))
    for off, nm, j in ((0x2cc, 0, 2), (0x218, 0, 3)):
        c.emu.w32(TV + off, pystub(c, nm, ret=rnd32, this=True, side=mkside(j)))
    c.emu.w32(TV + 0x284, pystub(c, 2, ret=rnd32, this=True, side=mkside(4)))
    c.emu.w32(TV + 0x130, pystub(c, 3, ret=rnd32, this=True, stackmark=(2,), side=mkside(5)))
    c.emu.w32(TV + 0x344, pystub(c, 2, ret=rnd32, this=True, side=mkside(6)))
    cc8 = [0]
    def r_c8(emu, k):
        cc8[0] += 1
        return TA if cc8[0] % 2 == 1 else TB
    c4 = [0]
    def r_c4(emu, k):
        c4[0] += 1
        return IDX if c4[0] % 2 == 1 else r.getrandbits(32)
    c.emu.w32(MV + 0xc8, pystub(c, 1, ret=r_c8, this=True, side=mkside(7)))
    c.emu.w32(MV + 0xc4, pystub(c, 1, ret=r_c4, this=True, side=mkside(8)))
    c.emu.w32(MV + 0xbc, pystub(c, 1, ret=rnd32, this=True, side=mkside(9)))
    c.emu.w32(MV + 0xb0, pystub(c, 1, ret=lambda emu, k: NNEW, this=True, side=mkside(10)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: NEWBUF, pop=0, this=False, side=mkside(11))
    def memset(emu, k, _s=mkside(12)):
        if emu.arg32(1) == 0 and emu.arg32(2) <= 24 * 4: emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
        _s(emu, k)
    hook_rec(c, 0x634d10, 3, ret=rnd32, pop=0, this=False, side=memset)
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=mkside(13))
    hook_rec(c, 0x4dcdf0, 1, ret=rnd32, pop=4, this=True, side=mkside(14))
    idxn = [0]
    def a4c(emu, k, _s=mkside(15)):
        idxn[0] = 0; _s(emu, k)
    def r64(emu, k):
        i = idxn[0]; idxn[0] += 1
        return NODES[i] if i < len(NODES) else 0
    c.emu.w32(ITV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a4c))
    c.emu.w32(ITV + 0x64, pystub(c, 1, ret=r64, this=True, stackmark=(0,), side=mkside(16)))
    hook_rec(c, 0x4d2280, 0, ret=rnd32, pop=0, this='mark', side=mkside(17))
    hook_rec(c, 0x4d2330, 0, ret=rnd32, pop=0, this='mark', side=mkside(18))
    hook_rec(c, 0x4d39a0, 2, ret=rnd32, pop=8, this='mark', side=mkside(19))
    hook_rec(c, 0x4d3ab0, 2, ret=rnd32, pop=8, this='mark', side=mkside(19))
    return [this, a0]


S(0x4620d0, 'GUESS hand 0x4620d0', 'thiscall', None, ret=None, gen=g4620d0, note='batch216060')


def g52cb60(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    this = rnd(c, 0x80); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x80)))
    KINDS = [0x1923482, 0x1923483, 0x1923484, 0x82349201, 0x83349201, 0x84349201, 0x1923485, 0x12345678]
    BUF = rnd(c, 0x40); c.emu.wbytes(BUF, bytes(r.getrandbits(8) for _ in range(0x40)))
    m = r.choice([1, 1, 2, 2, 3, 0])
    c.emu.w32(BUF, r.choice(KINDS))
    c.emu.wbytes(BUF + 4, bytes([r.choice([0, 1, 0x80, 0xff])]))
    c.emu.wbytes(this + 0x31, bytes([r.choice([0, 1, 0x80, 0xff])]))
    c.emu.wbytes(0x701b58, bytes([r.choice([0, 1])]))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k: 0, pop=0, this=False))
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    OBJ = rnd(c, 0x20); c.emu.wbytes(OBJ, bytes(r.getrandbits(8) for _ in range(0x20)))
    OB2 = rnd(c, 0x20)
    c.emu.w32(this + 0x65, OB2)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x80)), zlib.crc32(emu.rbytes(BUF, 0x40)), emu.rbytes(0x701b58, 1).hex()))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(0)))
    THREE = (0x6a0f98, 0x6a0fac, 0x6a1090, 0x6a1078)
    def a2c(emu, k, _s=mkside(1)):
        if emu.arg32(1) in THREE: emu.calllog.append(('a3', emu.arg32(2)))
        _s(emu, k)
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=rnd32, pop=0, this=False, side=a2c))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: r.choice([0, OBJ]), pop=0, this=False, side=mkside(2))
    hook_rec(c, 0x52cfd0, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0, this=True, side=mkside(3))
    hook_rec(c, 0x530fb0, 2, ret=rnd32, pop=8, this=True, side=mkside(4))
    hook_rec(c, 0x531270, 3, ret=lambda emu, k: r.choice([0, 3, 10, 0x40]), pop=12, this=True, side=mkside(5))
    return [this, BUF, m | (r.getrandbits(8) << 24) if m == 99 else m]


S(0x52cb60, 'GUESS hand 0x52cb60', 'thiscall', None, ret='eax', gen=g52cb60, note='batch216060')


def g599f10(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x1e00
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    VECARR = rnd(c, 0x40)
    cap = r.choice([0, 0, 4, 8])
    c.emu.w32(this + 0x1da2, VECARR); c.emu.w32(this + 0x1da2 + 4, VECARR + r.choice([0, 4]))
    end0 = c.emu.r32(this + 0x1da2 + 4)
    c.emu.w32(this + 0x1da2 + 8, end0 if r.random() < 0.4 else VECARR + 0x20)
    T = rnd(c, 0x1ac0); TV = rnd(c, 0x70); c.emu.w32(T, TV); c.emu.w32(0x70039c, T)
    M = rnd(c, 0x20); MV = rnd(c, 0x150); c.emu.w32(M, MV); c.emu.w32(T + 0x9b, M)
    H = rnd(c, 0x4c0); Q = rnd(c, 0x20); QV = rnd(c, 0x110); c.emu.w32(Q, QV)
    c.emu.w32(H + 0x4ac, r.choice([0, Q, Q])); c.emu.w32(0x7003b8, H)
    CO = rnd(c, 0x20); COV = rnd(c, 0x70); c.emu.w32(CO, COV)
    c.emu.w32(Q + 0x18, CO)
    PV = rnd(c, 0x20)
    ITEMS = []
    IV = rnd(c, 0x200)
    for i in range(4):
        it = rnd(c, 0x60); c.emu.wbytes(it, bytes(r.getrandbits(8) for _ in range(0x60))); c.emu.w32(it, IV)
        p = rnd(c, 0x10); c.emu.w32(p + 4, r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
        c.emu.w32(it + 0x54, r.choice([0, p, p, p]))
        ITEMS.append(it)
    O134 = rnd(c, 0x20); O134V = rnd(c, 0x98); c.emu.w32(O134, O134V)
    O138 = rnd(c, 0x20); O138V = rnd(c, 0x90); c.emu.w32(O138, O138V)
    G3 = rnd(c, 0x20); G3V = rnd(c, 0xd0); c.emu.w32(G3, G3V); c.emu.w32(0x70038c, G3)
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    POOL = {0x1c: [rnd(c, 0x40) for _ in range(4)], 0x10: [rnd(c, 0x20) for _ in range(4)], 0x29: [rnd(c, 0x30) for _ in range(12)]}
    cntA = {0x1c: 0, 0x10: 0, 0x29: 0}
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS)), emu.rbytes(this + 0x1da2, 12).hex(), zlib.crc32(emu.rbytes(VECARR, 0x40)), [zlib.crc32(emu.rbytes(b, 0x30)) for b in POOL[0x1c] + POOL[0x29]]))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def a5c_t(emu, k, _s=mkside(0)):
        if r.random() < 0.7: emu.w32(emu.arg32(1), r.choice([0, 1, 5]))
        else: emu.w32(emu.arg32(1), 0)
        emu.calllog.append(('key', emu.arg32(0)))
        _s(emu, k)
    FOUND = r.choice([0, 1, 1])
    def a5c_T(emu, k, _s=mkside(0)):
        if FOUND: emu.w32(emu.arg32(1), r.choice([0, 7, 300, 0x80000000]))
        _s(emu, k)
    c.emu.w32(TV + 0x5c, pystub(c, 2, ret=lambda emu, k: r.choice([0x100, 1, 0x1ff]) if FOUND else r.choice([0, 0x100]), this=True, stackmark=(1,), side=a5c_T))
    c.emu.w32(0x6762d8, pystub(c, 1, ret=lambda emu, k: r.choice([0, 1, 7, 300]), pop=0, this=False, side=mkside(1)))
    hook_rec(c, 0x596d30, 1, ret=rnd32, pop=4, this=True, side=mkside(2))
    hook_rec(c, 0x59a9b0, 1, ret=rnd32, pop=4, this=True, side=mkside(3))
    c.emu.w32(QV + 0x100, pystub(c, 1, ret=rnd32, this=True, side=mkside(4)))
    c.emu.w32(COV + 0x14, pystub(c, 0, ret=lambda emu, k: r.getrandbits(8), this=True, side=mkside(5)))
    cnt = [0]
    def a4c(emu, k, _s=mkside(6)):
        cnt[0] = r.choice([0, 1, 2, 3]); _s(emu, k)
    def a5c(emu, k, _s=mkside(7)):
        emu.w32(emu.arg32(0), cnt[0])
        if cnt[0] > 0: cnt[0] -= 1
        _s(emu, k)
    c.emu.w32(COV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a4c))
    c.emu.w32(COV + 0x5c, pystub(c, 1, ret=lambda emu, k: r.randrange(1, 6), this=True, stackmark=(0,), side=a5c))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=lambda emu, k: ITEMS[emu.arg32(0) % 4], this=True, side=mkside(8)))
    c.emu.w32(IV + 0x1e0, pystub(c, 1, ret=lambda emu, k: r.choice([0, 0x100, 1, 0x1ff, 1]), this=True, side=mkside(9)))
    c.emu.w32(MV + 0x134, pystub(c, 0, ret=lambda emu, k: O134, this=True, side=mkside(10)))
    c.emu.w32(MV + 0x138, pystub(c, 0, ret=lambda emu, k: O138, this=True, side=mkside(10)))
    def a90(emu, k, _s=mkside(11)):
        emu.wbytes(emu.arg32(1), bytes([r.choice([0, 1, 5])]))
        _s(emu, k)
    c.emu.w32(O134V + 0x90, pystub(c, 2, ret=rnd32, this=True, stackmark=(1,), side=a90))
    def a88(emu, k, _s=mkside(12)):
        if r.random() < 0.7: emu.w32(emu.arg32(1), r.getrandbits(32))
        _s(emu, k)
    c.emu.w32(O138V + 0x88, pystub(c, 2, ret=rnd32, this=True, stackmark=(1,), side=a88))
    c.emu.w32(G3V + 0xcc, pystub(c, 1, ret=lambda emu, k: r.choice([0, 0x20001000]), this=True, side=mkside(13)))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k: LG, this=True, side=mkside(14)))
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=rnd32, pop=0, this=False, side=mkside(15)))
    def alloc(emu, k):
        sz = emu.arg32(0)
        lst = POOL[sz]
        i = cntA[sz]; cntA[sz] += 1
        if sz != 0x1c and r.random() < 0.15: return 0
        return lst[i % len(lst)]
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(16))
    hook_rec(c, 0x5b7dd0, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0, this=True, side=mkside(17))
    hook_rec(c, 0x49e250, 1, ret=rnd32, pop=4, this=True, side=mkside(18))
    hook_rec(c, 0x5b7b90, 2, ret=lambda emu, k: emu.reg('ecx'), pop=8, this=True, side=mkside(19))
    hook_rec(c, 0x5fe3b0, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=mkside(19))
    return [this]


S(0x599f10, 'GUESS hand 0x599f10', 'thiscall', None, ret=None, gen=g599f10, note='batch216060')


def g5ac140(c):
    clear_hooks(c)
    head = seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    import pe_emu
    from recruits_util import _HOOKED
    TS = 0x80
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    VA = rnd(c, 0x80); k = r.choice([0, 1, 2, 3])
    c.emu.w32(this + 0x6e, VA); c.emu.w32(this + 0x72, VA + 16 * k)
    c.emu.wbytes(VA, bytes(r.getrandbits(8) for _ in range(0x80)))
    O1 = rnd(c, 0x20); O1V = rnd(c, 0x290); c.emu.w32(O1, O1V); c.emu.w32(this + 0x1a, O1)
    O2 = rnd(c, 0x20); O2V = rnd(c, 0x290); c.emu.w32(O2, O2V); c.emu.w32(this + 0x42, O2)
    c.emu.wbytes(this + 0x19, bytes([r.choice([0, 1, 2])]))
    T = rnd(c, 0x1b00); TV = rnd(c, 0x10); c.emu.w32(T, TV); c.emu.w32(0x70039c, T)
    OB = rnd(c, 0x20); OBV = rnd(c, 0xc4); c.emu.w32(OB, OBV); c.emu.w32(T + 0x1907, OB)
    # input string with $name$ tokens
    ALPHA = b'abcxyz '
    parts = []
    for _ in range(r.choice([0, 1, 2, 3])):
        lit = bytes(r.choice(ALPHA) for _ in range(r.choice([1, 1, 3, 6])))
        nm = bytes(r.choice(b'ABCD') for _ in range(r.choice([0, 1, 2, 5])))
        parts.append(lit + b'$' + nm + b'$')
    tail = bytes(r.choice(ALPHA) for _ in range(r.choice([0, 1, 4, 9])))
    s = b''.join(parts) + tail
    if r.random() < 0.08: s = b''
    if r.random() < 0.12: s = b'a' * r.choice([0x3ff, 0x3fe, 0x3f0, 0x400, 0x401])
    det = False
    xr = r.random()
    if xr < 0.10:
        det = True
        s = b'q' * r.choice([0, 3]) + b'$' + b'A' * r.choice([0x1f, 0x20, 0x1e]) + b'$' + b'z' * r.choice([0, 2])
    elif xr < 0.22:
        det = True
        A = r.choice([0x3ff, 0x400, 0x3fe, 0x3e0])
        K = r.choice([0, 1, 2, 3]) if A >= 0x3fe else 0
        if A == 0x3e0:
            tgt = r.choice([0x3fe, 0x3ff, 0x400, 0x401]); K = tgt - 6 - A
        s = b'a' * A + b'$B$' + b'c' * K
    S = rnd(c, len(s) + 16); c.emu.wbytes(S, s + b'\0' * 8)
    if r.random() < 0.05: S = 0
    STRS = [rnd(c, 0x20) for _ in range(3)]
    for q in STRS: c.emu.wbytes(q, bytes(r.choice(b'0123456789xy') for _ in range(r.choice([1, 3, 7]))) + b'\0' * 4)
    SOBJ = rnd(c, 0x10); SOBJV = rnd(c, 0x10)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS)), emu.rbytes(this + 0x6e, 8).hex(), zlib.crc32(emu.rbytes(VA, 0x80))))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def cstr(emu, a):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < 0x3ff: n += 1
        return emu.rbytes(a, n)
    def sncat(emu, k_, _s=mkside(0)):
        d = emu.arg32(0); src = emu.arg32(1); n = emu.arg32(2)
        dd = cstr(emu, d)
        take = b''
        for i in range(n):
            ch = emu.rbytes(src + i, 1)
            if ch == b'\0': break
            take += ch
        emu.calllog.append(('cat', dd.hex(), take.hex(), n))
        emu.wbytes(d + len(dd), take + b'\0')
        _s(emu, k_)
    c.emu.w32(0x676428, pystub(c, 3, ret=lambda emu, k_: emu.arg32(0), pop=0, this=False, stackmark=(0,), side=sncat))
    def a284(emu, k_, _s=mkside(1)):
        emu.calllog.append(('s', cstr(emu, emu.arg32(0)).hex()))
        _s(emu, k_)
    c.emu.w32(O1V + 0x284, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a284))
    c.emu.w32(O2V + 0x284, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a284))
    def a44(emu, k_, _s=mkside(2)):
        emu.calllog.append(('nm', cstr(emu, emu.arg32(0)).hex()))
        _s(emu, k_)
    c.emu.w32(OBV + 0x44, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a44))
    c.emu.w32(OBV + 0x64, pystub(c, 1, ret=rnd32, this=True, side=mkside(3)))
    def abc(emu, k_, _s=mkside(4)):
        emu.w32(emu.arg32(0), r.choice(STRS + [0]))
        _s(emu, k_)
    c.emu.w32(OBV + 0xbc, pystub(c, 2, ret=lambda emu, k_: emu.arg32(0), this=True, stackmark=(0,), side=abc))
    hook_rec(c, 0x439320, 3, ret=lambda emu, k_: (0 if det else r.choice([0, 0x1234, 0x5678])), pop=12, this=True, side=mkside(5))
    def a_dt(emu, k_, _s=mkside(6)):
        emu.calllog.append(('dt', emu.r32(emu.reg('ecx'))))
        _s(emu, k_)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=a_dt)
    def a5acbf0(emu, k_, _s=mkside(7)):
        emu.calllog.append(('x4d4', emu.rbytes(emu.arg32(0), 6).hex()))
        _s(emu, k_)
    hook_rec(c, 0x5acbf0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=a5acbf0)
    def fatal(emu, rr_):
        import pilot as _p
        emu.calllog.append(('fatal',))
        for kk, vv in _p.SENTINELS.items(): emu.mu.reg_write(pe_emu.REGS[kk], vv)
        emu.mu.reg_write(pe_emu.UC_X86_REG_EBP, pe_emu.STACK_TOP - 0x80)
        emu.mu.reg_write(pe_emu.UC_X86_REG_ESP, pe_emu.STACK_TOP - 0x200)
        emu.w32(pe_emu.TEB, head)
        emu.mu.reg_write(pe_emu.UC_X86_REG_EIP, emu.RET_ADDR)
    c.emu.hook(0x634047, fatal)
    _HOOKED.add(0x634047)
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k_: emu.r32(emu.reg('ecx')), pop=0, this='mark', side=mkside(8))
    return [this, S]


S(0x5ac140, 'GUESS hand 0x5ac140', 'thiscall', None, ret=None, gen=g5ac140, note='batch216060')


def g5fe980(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k_: 0, pop=0, this=False))
    BASE = rnd(c, 0x400); c.emu.wbytes(BASE, bytes(r.getrandbits(8) for _ in range(0x400)))
    LIMIT = BASE + r.choice([0x10, 0x20, 0x200, 0x400])
    OFFV = rnd(c, 0x10); c.emu.w32(OFFV, r.choice([0, 4, 8, 0x1c, 0x100]))
    CXV = rnd(c, 0x40)
    a0 = rnd(c, 0xb00); c.emu.wbytes(a0, bytes(r.getrandbits(8) for _ in range(0xb00)))
    c.emu.w32(a0, CXV); c.emu.w32(a0 + 0x96, rnd(c, 0x20)); c.emu.w32(a0 + 0x9e, BASE); c.emu.w32(a0 + 0xa2, LIMIT)
    A2V = rnd(c, 0x20); a2 = rnd(c, 0x20); c.emu.w32(a2, A2V)
    if r.random() < 0.25: a2 = 0
    STR = rnd(c, 0x40); c.emu.wbytes(STR, bytes(r.getrandbits(8) for _ in range(0x40)))
    def mkobj(is_child):
        o = rnd(c, 0xc0); c.emu.wbytes(o, bytes(r.getrandbits(8) for _ in range(0xc0)))
        n = r.choice([0, 1, 3, 8])
        src = rnd(c, 0x20); c.emu.wbytes(src, bytes(r.getrandbits(8) for _ in range(0x20)))
        c.emu.w32(o + 0x60, src); c.emu.w32(o + 0x64, src + n)
        b4c = r.choice([0, 0x10, 0x100]); c.emu.w32(o + 0x4c, b4c)
        T = rnd(c, 0x100)
        c.emu.w32(o + 0x98, T)
        # two tables inside the same region (+0x80 / +0x84 offsets from T)
        c.emu.w32(o + 0x84, 0); c.emu.w32(o + 0x80, 0x80)
        for base in (0, 0x80):
            cnt = r.choice([0, 1, 2, 3])
            c.emu.w32(T + base, cnt)
            for i in range(cnt):
                key = b4c + r.choice([0, 0, max(n - 1, 0), n, n + 3, 0x1000])
                c.emu.w32(T + base + 6 * i + 4, key)
                c.emu.wbytes(T + base + 6 * i + 8, bytes([r.choice([0, 1, 2, 5, 6]), 0]))
        c.emu.w32(o + 0xa0, r.choice([0, 1, 2, 3])); c.emu.w32(o + 0xa8, r.choice([0, 0, 1, 2, 3]))
        arr = rnd(c, 0x20)
        for i in range(4): c.emu.w32(arr + 4 * i, r.choice([0, 4, 8, 0x10]))
        c.emu.w32(o + 0xac, arr); c.emu.w32(o + 0xb0, STR)
        c.emu.w32(o + 0x9c, 0)
        return o, n
    this, nthis = mkobj(False)
    if r.random() < 0.5:
        ch, nch = mkobj(True)
        c.emu.w32(this + 0x9c, ch)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(BASE, 0x400)), emu.r32(OFFV), zlib.crc32(emu.rbytes(this, 0xc0))))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    c.emu.w32(CXV + 0x30, pystub(c, 1, ret=rnd32, this=True, side=mkside(0)))
    c.emu.w32(A2V + 0x10, pystub(c, 3, ret=rnd32, this=True, stackmark=(1,), side=mkside(1)))
    def memcpy(emu, k_, _s=mkside(2)):
        d = emu.arg32(0); s_ = emu.arg32(1); n = emu.arg32(2)
        emu.wbytes(d, emu.rbytes(s_, n))
        _s(emu, k_)
    hook_rec(c, 0x634d22, 3, ret=rnd32, pop=0, this=False, side=memcpy)
    hook_rec(c, 0x600ba0, 1, ret=lambda emu, k_: r.choice([0, 0x100, 1, 0x1ff]), pop=4, this=True, side=mkside(3))
    hook_rec(c, 0x5ffb00, 1, ret=lambda emu, k_: r.choice([STR, STR + 4]), pop=4, this=True, side=mkside(4))
    hook_rec(c, 0x6000b0, 1, ret=lambda emu, k_: r.choice([0, 1, 7]), pop=4, this=True, side=mkside(5))
    LG = rnd(c, 0x20); LGV = rnd(c, 0x40); c.emu.w32(LG, LGV)
    hook_rec(c, 0x5fa630, 0, ret=lambda emu, k_: LG, pop=0, this=False, side=mkside(6))
    def lg14(emu, k_, _s=mkside(7)):
        emu.calllog.append(('lg14', emu.arg32(0), emu.arg32(2), emu.arg32(3)))
        _s(emu, k_)
    c.emu.w32(LGV + 0x14, pystub(c, 1, ret=rnd32, pop=0, this=False, side=lg14))
    c.emu.w32(LGV + 0xc, pystub(c, 1, ret=rnd32, pop=0, this=False, side=mkside(8)))
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG2 = rnd(c, 0x20); LV2 = rnd(c, 0x34); c.emu.w32(LG2, LV2)
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k_: LG2, this=True, side=mkside(9)))
    c.emu.w32(LV2 + 0x2c, pystub(c, 3, ret=rnd32, pop=0, this=False, side=mkside(10)))
    def a42(emu, k_, _s=mkside(11)):
        e = emu.reg('ecx')
        emu.wbytes(e, bytes(r.getrandbits(8) for _ in range(12)))
        q_ = r.random()
        if q_ < 0.4:
            emu.w32(e, STR); emu.w32(e + 4, STR + 4); emu.w32(e + 8, STR + 4 + r.choice([0, 3]))
        elif q_ < 0.55:
            emu.w32(e, 0); emu.w32(e + 4, 0); emu.w32(e + 8, r.choice([0, 8]))
        elif q_ < 0.7:
            emu.w32(e, STR); emu.w32(e + 4, STR); emu.w32(e + 8, STR)
        _s(emu, k_)
    hook_rec(c, 0x42b390, 2, ret=rnd32, pop=8, this='mark', stackmark=(1,), side=a42)
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this='mark', side=mkside(12))
    return [this, a0, OFFV, a2]


S(0x5fe980, 'GUESS hand 0x5fe980', 'thiscall', None, ret=None, gen=g5fe980, note='batch216060')


def g5fdd20(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k_: 0, pop=0, this=False))
    this = rnd(c, 0x140); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x140)))
    N = r.choice([0, 1, 2, 3])
    c.emu.w32(this + 0xd8, N)
    ARR = rnd(c, 0x20); BASE100 = rnd(c, 0x200); c.emu.wbytes(BASE100, bytes(r.getrandbits(8) for _ in range(0x200)))
    c.emu.w32(this + 0xe8, ARR); c.emu.w32(this + 0x100, BASE100)
    KEYS = [0x11, 0x22, 0x33, 0x44]
    for i in range(N):
        off = 0x40 * i
        c.emu.w32(ARR + 4 * i, off)
        c.emu.w32(BASE100 + off, r.choice(KEYS))
        n16 = r.choice([0, 1, 2, 3, 4])
        c.emu.wbytes(BASE100 + off + 4, bytes([n16, 0]))
        for j in range(n16):
            c.emu.wbytes(BASE100 + off + 6 + 2 * j, bytes([r.choice([1, 2, 3, 5]), 0]))
    c.emu.w32(this + 0xa0, r.choice([0, 1])); c.emu.w32(this + 0xa8, r.choice([8, 8, 8, 0]))
    IDT = rnd(c, 0x40)
    for i in range(8): c.emu.w32(IDT + 4 * i, r.choice([0, 4, 8, 0x10]))
    STR = rnd(c, 0x40); c.emu.wbytes(STR, bytes(r.getrandbits(8) for _ in range(0x40)))
    c.emu.w32(this + 0xac, IDT); c.emu.w32(this + 0xb0, STR)
    CH = rnd(c, 0x140); EO = rnd(c, 0x20)
    c.emu.w32(CH + 0x121, EO); c.emu.w32(EO + 5, r.getrandbits(32))
    c.emu.w32(this + 0x9c, CH if r.random() < 0.75 else 0)
    VARR = rnd(c, 0x40)
    c.emu.w32(this + 0x10c, VARR); c.emu.w32(this + 0x10c + 4, VARR); c.emu.w32(this + 0x10c + 8, VARR + r.choice([0, 0x10, 0x20]))
    # hash object
    HOLD = rnd(c, 0x60); HO = rnd(c, 0x20); HOV = rnd(c, 0x20); c.emu.w32(HO, HOV); c.emu.w32(HOLD + 0x3c, HO); c.emu.w32(0x724278, HOLD)
    # 32-bit map (a0) with a few nodes
    NP32 = [rnd(c, 0x30) for _ in range(10)]
    NP16 = [rnd(c, 0x30) for _ in range(24)]
    HDRP = [rnd(c, 0x20) for _ in range(4)]
    MP = [rnd(c, 0x10) for _ in range(4)]
    cnt = {'n32': 0, 'n16': 0, 'hdr': 0, 'mp': 0}
    a0 = rnd(c, 0x10); H2 = rnd(c, 0x20)
    c.emu.w32(a0, H2); c.emu.w32(a0 + 4, 0)
    c.emu.w32(H2 + 1, 0); c.emu.w32(H2 + 5, H2); c.emu.w32(H2 + 9, H2)
    def bst_insert(emu, M, key, kwidth, node, valoff):
        H = emu.r32(M)
        emu.wbytes(node, bytes(0x20)) if False else None
        emu.w32(node + 1, 0); emu.w32(node + 5, 0); emu.w32(node + 9, 0)
        if kwidth == 2: emu.wbytes(node + 0xd, bytes([key & 0xff, (key >> 8) & 0xff]))
        else: emu.w32(node + 0xd, key)
        root = emu.r32(H + 1)
        if root == 0:
            emu.w32(H + 1, node); emu.w32(H + 5, node); emu.w32(H + 9, node)
        else:
            cur = root
            while True:
                ck = emu.r32(cur + 0xd) & (0xffff if kwidth == 2 else 0xffffffff)
                if key < ck:
                    nx = emu.r32(cur + 5)
                    if nx == 0:
                        emu.w32(cur + 5, node)
                        if cur == emu.r32(H + 5): emu.w32(H + 5, node)
                        break
                    cur = nx
                else:
                    nx = emu.r32(cur + 9)
                    if nx == 0:
                        emu.w32(cur + 9, node)
                        if cur == emu.r32(H + 9): emu.w32(H + 9, node)
                        break
                    cur = nx
        emu.w32(M + 4, emu.r32(M + 4) + 1)
    # pre-populate the 32-bit map
    class FakeEmu:
        def __init__(s, e): s.e = e
        def r32(s, a): return s.e.r32(a)
        def w32(s, a, v): s.e.w32(a, v)
        def wbytes(s, a, b): s.e.wbytes(a, b)
    fe = FakeEmu(c.emu)
    for k in r.sample(KEYS, r.choice([0, 1, 2, 3])):
        node = NP32[cnt['n32']]; cnt['n32'] += 1
        bst_insert(fe, a0, k, 4, node, 0x11); c.emu.w32(node + 0x11, 0)
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0xd0, 0x50)), emu.rbytes(this + 0x10c, 12).hex(), emu.r32(a0 + 4), zlib.crc32(emu.rbytes(H2, 0x20)), [zlib.crc32(emu.rbytes(n, 0x20)) for n in NP32[:cnt['n32'] + 2]], [zlib.crc32(emu.rbytes(h_, 0x20)) for h_ in HDRP]))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def a41(emu, k_):
        i = cnt['mp']; cnt['mp'] += 1
        return MP[i % 4]
    hook_rec(c, 0x41e290, 1, ret=a41, pop=0, this=False, side=mkside(0))
    def a6014(emu, k_):
        i = cnt['hdr']; cnt['hdr'] += 1
        h = HDRP[i % 4]
        emu.wbytes(h, bytes(r.getrandbits(8) for _ in range(0x20)))
        return h
    c.emu.w32(0, 0) if False else None
    hook_rec(c, 0x6014a0, 1, ret=a6014, pop=4, this=False, side=mkside(1))
    hook_rec(c, 0x5fe3b0, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=mkside(2))
    hook_rec(c, 0x600780, 2, ret=rnd32, pop=8, this=True, side=mkside(3))
    hook_rec(c, 0x5ffb00, 1, ret=lambda emu, k_: r.choice([STR, STR + 4]), pop=4, this=True, side=mkside(4))
    def a5ffc10(emu, k_, _s=mkside(5)):
        emu.calllog.append(('st', emu.rbytes(emu.reg('ecx'), 18).hex()))
        _s(emu, k_)
    hook_rec(c, 0x5ffc10, 1, ret=lambda emu, k_: r.getrandbits(32), pop=4, this='mark', side=a5ffc10)
    HS = [0, 1, 2, 3, 0x10001, 0x20003]
    c.emu.w32(HOV, pystub(c, 1, ret=lambda emu, k_: r.choice(HS), this=True, side=mkside(6)))
    c.emu.w32(HOV + 0x10, pystub(c, 2, ret=rnd32, this=True, side=mkside(7)))
    def a600540(emu, k_, _s=mkside(8)):
        M = emu.reg('ecx'); out = emu.arg32(0); pair = emu.arg32(2)
        key = emu.r32(pair) & 0xffff
        emu.calllog.append(('i16', key, emu.arg32(1) == emu.r32(M), emu.r32(pair + 2)))
        node = NP16[cnt['n16']]; cnt['n16'] += 1
        bst_insert(emu, M, key, 2, node, 0xf)
        emu.w32(out, node)
        _s(emu, k_)
    hook_rec(c, 0x600540, 3, ret=rnd32, pop=12, this=True, stackmark=(0, 2), side=a600540)
    def a600610(emu, k_, _s=mkside(9)):
        M = emu.reg('ecx'); out = emu.arg32(0); pair = emu.arg32(2)
        key = emu.r32(pair)
        emu.calllog.append(('i32', key, emu.arg32(1) == emu.r32(M), emu.r32(pair + 4)))
        node = NP32[cnt['n32']]; cnt['n32'] += 1
        bst_insert(emu, M, key, 4, node, 0x11)
        emu.w32(out, node)
        _s(emu, k_)
    hook_rec(c, 0x600610, 3, ret=rnd32, pop=12, this=True, stackmark=(0, 2), side=a600610)
    return [this, a0]


S(0x5fdd20, 'GUESS hand 0x5fdd20', 'thiscall', None, ret=None, gen=g5fdd20, note='batch216060')


def g42ee70(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x1b90
    T = rnd(c, TS); c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    TV = rnd(c, 0xc0); c.emu.w32(T, TV)
    VEC = rnd(c, 0x10); VARR = rnd(c, 0x80)
    nv = r.choice([0, 1, 2, 3]); extra = r.choice([0, 0, 5, 11])
    c.emu.w32(VEC, VARR); c.emu.w32(VEC + 4, VARR + 12 * nv + extra)
    c.emu.w32(T + 0x1b69, VEC)
    ABUF = rnd(c, 0x40); c.emu.wbytes(ABUF, bytes(r.choice(b'abc.$ ') for _ in range(r.choice([0, 1, 4, 9]))) + b'\0' * 4)
    BUFA = rnd(c, 0x40); BUFB = rnd(c, 0x40); BUFM = rnd(c, 0x40); BUFD = rnd(c, 0x400)
    c.emu.wbytes(BUFM, b'xyz\0')
    c.emu.wbytes(BUFB, b'\0' * 8)
    HEAPP = [rnd(c, 0x10), rnd(c, 0x10)]
    cnt = {'h': 0}
    sr = [seh_record(c, 2) for _ in range(20)]
    M = T + 0x1a17
    c.emu.w32(M, BUFM)
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(T + 0x1a00, 0x30)), emu.rbytes(VEC, 8).hex(), zlib.crc32(emu.rbytes(BUFA, 0x40)), zlib.crc32(emu.rbytes(BUFD, 0x80))))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def cstr(emu, a, lim=0x3f00):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def ctor(emu, k_, _s=mkside(0)):
        e = emu.reg('ecx'); src = emu.arg32(0)
        s = cstr(emu, src, 0x30)
        tgt = BUFA if src == ABUF else BUFB
        emu.wbytes(tgt, s + b'\0')
        emu.w32(e, tgt)
        emu.calllog.append(('ctor', s.hex()))
        _s(emu, k_)
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=ctor)
    def asg(emu, k_, _s=mkside(1)):
        emu.calllog.append(('asg', emu.r32(emu.r32(emu.arg32(0)))) if False else ('asg', cstr(emu, emu.r32(emu.arg32(0)), 0x30).hex()))
        _s(emu, k_)
    hook_rec(c, 0x4cbee0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=asg)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k_, _s=mkside(2): (emu.calllog.append(('dt', emu.r32(emu.reg('ecx')))), _s(emu, k_)))
    hook_rec(c, 0x4cc180, 1, ret=lambda emu, k_: r.choice([0, 0, 1, 0x100, 0x1ff]), pop=4, this=True, side=mkside(3))
    def a42aee0(emu, k_, _s=mkside(4)):
        emu.calllog.append(('f', emu.reg('edx')))
        _s(emu, k_)
    hook_rec(c, 0x42aee0, 3, ret=rnd32, pop=12, this=True, side=a42aee0)
    def a42b080(emu, k_, _s=mkside(5)):
        emu.calllog.append(('g', emu.reg('edx')))
        _s(emu, k_)
    hook_rec(c, 0x42b080, 1, ret=rnd32, pop=4, this=True, side=a42b080)
    def a6014(emu, k_):
        i = cnt['h']; cnt['h'] += 1
        return HEAPP[i % 2]
    hook_rec(c, 0x6014a0, 1, ret=a6014, pop=4, this=False, side=mkside(6))
    def memset(emu, k_, _s=mkside(7)):
        if emu.arg32(1) == 0 and emu.arg32(2) <= 0x3e80: emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
        _s(emu, k_)
    hook_rec(c, 0x634d10, 3, ret=rnd32, pop=0, this=False, stackmark=(0,), side=memset)
    def a5f2d60(emu, k_, _s=mkside(8)):
        e = emu.reg('ecx'); b = emu.arg32(0); en = emu.arg32(1)
        n = en - b
        data = emu.rbytes(b, n)
        emu.wbytes(BUFD, data + b'\0')
        emu.w32(e, BUFD); emu.w32(e + 4, BUFD + n); emu.w32(e + 8, BUFD + (0 if r.random() < 0.3 else n + 1))
        emu.calllog.append(('asr', data.hex()))
        _s(emu, k_)
    hook_rec(c, 0x5f2d60, 2, ret=rnd32, pop=8, this='mark', stackmark=(0, 1), side=a5f2d60)
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this='mark', side=mkside(9))
    # vtable of T
    def a74(emu, k_, _s=mkside(10)):
        _s(emu, k_)
    c.emu.w32(TV + 0x74, pystub(c, 0, ret=lambda emu, k_: r.choice([0, 1, 0x100, 0x1ff]), this=True, side=a74))
    def a7c(emu, k_, _s=mkside(11)):
        p = emu.arg32(0)
        emu.w32(p, emu.r32(p) + 1)
        _s(emu, k_)
    c.emu.w32(TV + 0x7c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a7c))
    def a70(emu, k_, _s=mkside(12)):
        s = bytes(r.choice(b'pqrs/') for _ in range(r.choice([0, 3, 9])))
        emu.wbytes(emu.arg32(0), s + b'\0')
        emu.calllog.append(('70', cstr(emu, emu.arg32(1), 0x30).hex()))
        _s(emu, k_)
    c.emu.w32(TV + 0x70, pystub(c, 2, ret=rnd32, this=True, stackmark=(0,), side=a70))
    def ab0(emu, k_, _s=mkside(13)):
        emu.calllog.append(('b0', emu.rbytes(emu.arg32(0), 12).hex()))
        _s(emu, k_)
    c.emu.w32(TV + 0xb0, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=ab0))
    def ab4(emu, k_, _s=mkside(14)):
        emu.calllog.append(('b4', cstr(emu, emu.arg32(0), 0x100).hex()))
        _s(emu, k_)
    c.emu.w32(TV + 0xb4, pystub(c, 1, ret=lambda emu, k_: r.choice([0, 1, 0x100, 0x1ff]), this=True, stackmark=(0,), side=ab4))
    c.emu.w32(0x67625c, pystub(c, 2, ret=lambda emu, k_: r.choice([0, 0, 1]), pop=0, this=False, side=mkside(15)))
    Z = rnd(c, 0x20); ZV = rnd(c, 0x40); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LV = rnd(c, 0x34); c.emu.w32(LG, LV)
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k_: LG, this=True, side=mkside(16)))
    def a2c(emu, k_, _s=mkside(17)):
        if emu.arg32(1) == 0x676c18: emu.calllog.append(('a3', emu.arg32(2)))
        _s(emu, k_)
    c.emu.w32(LV + 0x2c, pystub(c, 2, ret=rnd32, pop=0, this=False, side=a2c))
    c.emu.w32(ZV + 0x34, pystub(c, 2, ret=rnd32, pop=0, this=False, side=mkside(18)))
    # write the template string where a0 points
    return [T, ABUF]


def g42b460(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x1b90
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            ec = emu.reg('ecx'); emu.calllog.append(('t', j, ec if T <= ec < T + TS else 0, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    def alloc(emu, k):
        sz = emu.arg32(0)
        if r.random() < 0.2: return 0
        return rnd(c, 0x20)
    def hdr(emu, k):
        return rnd(c, 0x20)
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x4cbeb0, 0, ret=rnd32, pop=0, this=True, side=mkside(0))
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=mkside(1))
    hook_rec(c, 0x4cbee0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=mkside(2))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=mkside(3))
    hook_rec(c, 0x4cbf30, 1, ret=rnd32, pop=4, this=True, side=mkside(4))
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(5))
    hook_rec(c, 0x6014a0, 1, ret=hdr, pop=4, this=False, side=mkside(6))
    hook_rec(c, 0x42c9a0, 0, ret=rnd32, pop=0, this=True, side=mkside(7))
    return [T, r.getrandbits(32)]


def g5cce70(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0xe40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            ec = emu.reg('ecx')
            emu.calllog.append(('t', j, ec - T if T <= ec < T + TS else -1, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    S1 = rnd(c, 0x20); c.emu.wbytes(S1, b'abc\0')
    S2 = rnd(c, 0x20); c.emu.wbytes(S2, b'xyz\0')
    for j, a in enumerate([0x469870, 0x4e1b60, 0x662750, 0x662be0, 0x662ed0, 0x4de7a0]):
        hook_rec(c, a, 0, ret=rnd32, pop=0, this=True, side=mkside(j))
    def alloc(emu, k):
        if r.random() < 0.25: return 0
        return rnd(c, 0x110)
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(6))
    hook_rec(c, 0x4d8330, 3, ret=lambda emu, k: rnd(c, 0x20), pop=12, this=True, side=mkside(7))
    ES = c.emu.rbytes(0x67b0d8, 16)
    def cstr(emu, a):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < 64: n += 1
        return emu.rbytes(a, n)
    ECMP = cstr(c.emu, 0x67b0d8)
    equal = r.choice([True, False])
    def slot5c(emu, k, _s=mkside(8)):
        out = emu.arg32(1)
        emu.w32(out, S1 if not equal else S2)
        _s(emu, k)
    def scmp(emu, k, _s=mkside(9)):
        emu.calllog.append(('cmp', cstr(emu, emu.arg32(0)).hex(), cstr(emu, emu.arg32(1)).hex()))
        _s(emu, k)
    c.emu.w32(0x676414, pystub(c, 2, ret=lambda emu, k: 0 if cstr(emu, emu.arg32(0)) == cstr(emu, emu.arg32(1)) else 1, pop=0, this=False, side=scmp))
    if equal:
        c.emu.wbytes(S2, ECMP + b'\0')
    r5c = [r.choice([0, 1, 0x100, 0xff]) for _ in range(3)]
    s5c = pystub(c, 2, ret=lambda emu, k: r5c[min(k, 2)], pop=8, this=True, stackmark=(1,), side=slot5c)
    s114 = pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=16, this=True, side=mkside(10))
    s1a4 = pystub(c, 1, ret=rnd32, pop=4, this=True, side=mkside(11))
    mgr = obj(c, 0x40, {0x114: s114})
    from recruits_util import sysobj
    so = sysobj(c, slots={0x5c: s5c, 0x1a4: s1a4})
    c.emu.w32(so + 0x9b, mgr)
    return [T]


def g440f50(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    def cstr(emu, a, lim=0x120):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    sr = [seh_record(c, 2) for _ in range(12)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, emu.reg('ecx') if False else 0))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    SB = rnd(c, 0x20)
    SSTR = bytes(r.randrange(65, 90) for _ in range(r.choice([0, 3, 12]))) + b'\0'
    c.emu.wbytes(SB, SSTR)
    SS2 = rnd(c, 0x40); c.emu.wbytes(SS2, bytes(r.randrange(65, 90) for _ in range(r.choice([0, 1, 5, 20]))) + b'\0')
    # chain nodes for 4db520
    def mk_node(flagbit):
        nd = rnd(c, 0x80)
        if r.random() < 0.8:
            st = rnd(c, 0x40)
            f = rnd(c, 0x40)
            fl = (r.getrandbits(32) | 0x100000) if flagbit else (r.getrandbits(32) & ~0x100000)
            c.emu.w32(f + 0x23, fl & 0xffffffff)
            c.emu.w32(st + 0xc, f)
            c.emu.w32(nd + 0x54, st)
        else:
            c.emu.w32(nd + 0x54, 0)
        return nd
    ln = r.choice([0, 1, 2, 3, 4])
    stop = r.randrange(0, ln + 1)
    chain = [mk_node(i == stop) for i in range(ln)]
    cur = {'i': 0}
    def nxt(emu, k):
        i = k + 1
        return chain[i] if i < len(chain) else 0
    hook_rec(c, 0x4db520, 0, ret=nxt, pop=0, this=True, side=mkside(0))
    # sub-object slot 0x20c
    def s20c_side(emu, k, _s=mkside(1)):
        emu.calllog.append(('s20c', emu.reg('ecx')))
        _s(emu, k)
    s20c = pystub(c, 2, ret=rnd32, pop=8, this=True, side=s20c_side)
    SV = c.emu.alloc(0x240, 4); c.emu.w32(SV + 0x20c, s20c)
    def mk_sub(prev_next):
        nd = rnd(c, 0x80)
        if r.random() < 0.7:
            so = rnd(c, 0x20); c.emu.w32(so, SV)
            c.emu.w32(nd + 0x54, so)
        else:
            c.emu.w32(nd + 0x54, 0)
        c.emu.w32(nd + 0x60, prev_next)
        return nd
    lst = 0
    for _ in range(r.choice([0, 1, 2, 3])): lst = mk_sub(lst)
    # 4db550 result
    def s1d8(emu, k, _s=mkside(2)):
        emu.calllog.append(('s1d8', emu.r32(emu.arg32(0)) if False else 0, emu.arg32(1)))
        _s(emu, k)
    o2 = rnd(c, 0x20); c.emu.w32(o2, SS2)
    s1d8s = pystub(c, 2, ret=lambda emu, k: o2, pop=8, this=True, stackmark=(0,), side=s1d8)
    q_obj = obj(c, 0x20, {0x1d8: s1d8s})
    q = rnd(c, 0x40); c.emu.w32(q, q_obj); c.emu.wbytes(q + 0x1c, bytes([r.choice([0, 1, 7])]))
    qq = r.choice([0, q, q])
    hook_rec(c, 0x4db550, 0, ret=lambda emu, k: qq, pop=0, this=True, side=mkside(3))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=mkside(4))
    hook_rec(c, 0x4cc5a0, 0, ret=lambda emu, k: SB, pop=0, this=True, side=mkside(5))
    # logging objects
    def s2c(emu, k, _s=mkside(6)):
        fmt = emu.arg32(1)
        if fmt == 0x67ccc4:
            emu.calllog.append(('log7', emu.arg32(0) != 0, emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4), emu.arg32(5), cstr(emu, emu.arg32(6)).hex()))
        else:
            emu.calllog.append(('log3', fmt, emu.arg32(2)))
        _s(emu, k)
    s2cs = pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)
    LO = obj(c, 0x20, {0x2c: s2cs})
    def s20(emu, k, _s=mkside(7)):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    s20s = pystub(c, 2, ret=lambda emu, k: LO, pop=8, this=True, side=s20)
    G390 = obj(c, 0x20, {0x20: s20s})
    c.emu.w32(0x700390, G390)
    # this object
    cls = rnd(c, 0x80)
    if r.random() < 0.7: c.emu.w32(cls + 0x3c, r.getrandbits(32))
    fcnt = [0]
    fl = [r.getrandbits(32) for _ in range(3)]
    def s2a8(emu, k):
        return fl[min(k, 2)]
    s2a8s = pystub(c, 0, ret=s2a8, pop=0, this=True, side=mkside(8))
    T = obj(c, 0x80, {0x2a8: s2a8s})
    c.emu.w32(T + 0x54, chain[0] if chain else 0)
    c.emu.w32(T + 0x30, r.getrandbits(32))
    c.emu.w32(T + 8, cls)
    c.emu.w32(T + 4, r.choice([0, rnd(c, 0x20)]))
    t0 = rnd(c, 0x20)
    c.emu.w32(T + 0xc, t0)
    c.emu.w32(T + 0x50, lst)
    return [T, r.getrandbits(32), r.getrandbits(32)]


def g4d5880(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    sr = [seh_record(c, 2) for _ in range(16)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    SIGS = [0x2014b50, 0x2014b50, 0x2014b50, 0x6054b50, 0x52756e65, 0x04034b50]
    neof = r.choice([0, 1, 2, 4, 7])
    cnt = {'eof': 0, 'nl': 0}
    HV = r.getrandbits(32)
    def s1c(emu, k, _s=mkside(0)):
        emu.calllog.append(('eof', cnt['eof'], emu.arg32(0)))
        _s(emu, k)
    def eofret(emu, k):
        cnt['eof'] += 1
        return 0 if cnt['eof'] <= neof else r.choice([1, 5])
    s1cs = pystub(c, 1, ret=eofret, pop=4, this=True, side=s1c)
    def s14(emu, k, _s=mkside(1)):
        dst = emu.arg32(0); n = emu.arg32(1)
        if n == 4:
            b = SIGS[r.randrange(len(SIGS))].to_bytes(4, 'little')
        elif n == 0x2a:
            b = bytearray(r.getrandbits(8) for _ in range(0x2a))
            nl = r.choice([0, 0, 3, 17, 0x41])
            b[0x18:0x1a] = nl.to_bytes(2, 'little')
            b[0x14:0x18] = r.choice([0, 0, 5, 0x20]).to_bytes(4, 'little')
            b[0x1a:0x1c] = r.choice([0, 6, 0x30]).to_bytes(2, 'little')
            b[0x1c:0x1e] = r.choice([0, 7, 0x30]).to_bytes(2, 'little')
            b = bytes(b)
            cnt['nl'] = int.from_bytes(b[0x18:0x1a], 'little')
        else:
            b = bytes(r.getrandbits(8) for _ in range(n))
        emu.wbytes(dst, b)
        emu.calllog.append(('rd', n, emu.arg32(2), zlib.crc32(b)))
        _s(emu, k)
    s14s = pystub(c, 3, ret=rnd32, pop=12, this=True, stackmark=(0,), side=s14)
    s10s = pystub(c, 3, ret=rnd32, pop=12, this=True, side=mkside(2))
    sCs = pystub(c, 1, ret=rnd32, pop=4, this=True, side=mkside(3))
    stream = obj(c, 0x20, {0x10: s10s, 0xc: sCs, 0x14: s14s, 0x1c: s1cs})
    def mk_ret(): return lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x4d5440, 0, ret=rnd32, pop=0, this='mark', side=mkside(4))
    hook_rec(c, 0x4d5580, 0, ret=rnd32, pop=0, this='mark', side=mkside(5))
    hook_rec(c, 0x4d7540, 0, ret=rnd32, pop=0, this='mark', side=mkside(6))
    okv = r.random() < 0.8
    def s6aa0(emu, k, _s=mkside(7)):
        ob = emu.reg('ecx')
        emu.w32(ob + 0x11, HV); emu.w32(ob + 0x2e, 0x1234 + k)
        _s(emu, k)
    hook_rec(c, 0x4d6aa0, 2, ret=lambda emu, k: 1 if okv else r.choice([0, 0x100]), pop=8, this='mark', side=s6aa0)
    ok2 = [r.random() < 0.7 for _ in range(8)]
    def s6520(emu, k, _s=mkside(8)):
        buf = emu.arg32(0); dst = emu.arg32(1)
        emu.wbytes(dst, bytes(r.getrandbits(8) for _ in range(0x1c)))
        emu.calllog.append(('6520', zlib.crc32(emu.rbytes(buf, cnt['nl'] + 1))))
        _s(emu, k)
    hook_rec(c, 0x4d6520, 3, ret=lambda emu, k: 1 if ok2[min(k, 7)] else 0, pop=12, this='mark', stackmark=(0, 1), side=s6520)
    def s62c0(emu, k, _s=mkside(9)):
        emu.calllog.append(('62c0', emu.rbytes(emu.arg32(0), 0x1c).hex()))
        _s(emu, k)
    hook_rec(c, 0x4d62c0, 4, ret=rnd32, pop=16, this='mark', stackmark=(0,), side=s62c0)
    def s7c30(emu, k, _s=mkside(10)):
        emu.calllog.append(('7c30', zlib.crc32(emu.rbytes(emu.arg32(0), cnt['nl'] + 1)), emu.rbytes(emu.arg32(1), 8).hex()))
        _s(emu, k)
    hook_rec(c, 0x4d7c30, 4, ret=rnd32, pop=16, this=True, stackmark=(0, 1), side=s7c30)
    def simp(emu, k, _s=mkside(11)):
        emu.wbytes(emu.arg32(2), bytes(r.getrandbits(8) for _ in range(8)))
        _s(emu, k)
    c.emu.w32(0x676138, pystub(c, 3, ret=rnd32, pop=12, this=False, stackmark=(2,), side=simp))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x80), pop=0, this=False, side=mkside(12))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=mkside(13))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, this=False, side=mkside(14)))
    def s2c(emu, k, _s=mkside(15)):
        emu.calllog.append(('log', emu.arg32(1)))
        _s(emu, k)
    s2cs = pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)
    LO = obj(c, 0x20, {0x2c: s2cs})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    s20s = pystub(c, 2, ret=s20, pop=8, this=True)
    G390 = obj(c, 0x20, {0x20: s20s})
    c.emu.w32(0x700390, G390)
    T = rnd(c, 0x40)
    c.emu.w32(T + 9, r.choice([1, 1, 4, 4, 4, 2, 0, 5]))
    c.emu.w32(T + 0x15, stream)
    return [T, r.getrandbits(32)]


def g497990(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj, reftab_vt
    sr = [seh_record(c, 2) for _ in range(40)]
    TS = 0x90
    MH = [0]
    T = rnd(c, TS)
    def mkside(j):
        def side(emu, k):
            ec = emu.reg('ecx')
            emu.calllog.append(('t', j, ec - T if T <= ec < T + TS else -1, zlib.crc32(emu.rbytes(T, TS)), emu.rbytes(MH[0] + 0xbc0, 1) if MH[0] else 0))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    # shared reftab for the holders
    nrt = r.choice([0, 1, 2, 3])
    rt_elems = [rnd(c, 0x10) for _ in range(nrt)]
    RTV = reftab_vt(c, rt_elems)
    RT = rnd(c, 0x20); c.emu.w32(RT, RTV)
    # looked-up objects for 0xcc
    looked = {}
    s30 = pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(20))
    s34 = pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(21))
    LOBJV = c.emu.alloc(0x40, 4); c.emu.w32(LOBJV + 0x30, s30); c.emu.w32(LOBJV + 0x34, s34)
    for e in rt_elems:
        if r.random() < 0.7:
            lo = rnd(c, 0x20); c.emu.w32(lo, LOBJV); c.emu.w32(lo + 4, r.getrandbits(32))
            looked[e] = lo
    def mk_fl(setbit):
        f = rnd(c, 0x40); st = rnd(c, 0x40)
        fl = (r.getrandbits(32) | 0x100000) if setbit else (r.getrandbits(32) & ~0x100000)
        c.emu.w32(f + 0x23, fl & 0xffffffff)
        c.emu.w32(st + 0xc, f)
        return st
    # slot 0x50: next sibling via a chain dict
    nxt = {}
    def s50(emu, k, _s=mkside(22)):
        out = emu.arg32(0)
        cur = emu.r32(out)
        emu.w32(out, nxt.get(cur, 0))
        emu.calllog.append(('s50', 1 if nxt.get(cur, 0) else 0))
        _s(emu, k)
    s50s = pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s50)
    XV = c.emu.alloc(0x80, 4); c.emu.w32(XV + 0x50, s50s)
    def mk_holder():
        h = rnd(c, 0x20)
        c.emu.w32(h + 8, RT if r.random() < 0.8 else 0)
        return h
    def mk_x():
        x = mk_fl(r.random() < 0.5)
        c.emu.w32(x, XV)
        c.emu.w32(x + 0x10, mk_holder() if r.random() < 0.85 else 0)
        # children chain
        nch = r.choice([0, 1, 2])
        ch = [rnd(c, 0x60) for _ in range(nch)]
        for i, cc in enumerate(ch):
            y = rnd(c, 0x20)
            c.emu.w32(y, XV)
            c.emu.w32(y + 0x10, mk_holder() if r.random() < 0.8 else 0)
            c.emu.w32(cc + 0x54, y if r.random() < 0.85 else 0)
            nxt[cc] = ch[i + 1] if i + 1 < nch else 0
        c.emu.w32(x + 8, ch[0] if ch else 0)
        return x
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3])):
        nd = rnd(c, 0x60)
        c.emu.w32(nd + 0x54, mk_x() if r.random() < 0.9 else 0)
        nodes.append(nd)
    # fix: a node X shares nxt for its children via the X object; children chain keyed by child pointer (global dict)
    LV = reftab_vt(c, list(nodes))
    def ctorL(emu, k, _s=mkside(0)):
        emu.w32(emu.reg('ecx'), LV)
        _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=ctorL)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=mkside(1))
    hook_rec(c, 0x4cdb90, 0, ret=rnd32, pop=0, this='mark', side=mkside(2))
    for j, a in enumerate([0x496620, 0x496690, 0x497470, 0x498270, 0x498430, 0x498650, 0x496160, 0x497fe0]):
        hook_rec(c, a, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=mkside(3 + j))
    def lg1(emu, k, _s=mkside(11)):
        emu.calllog.append(('96700', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x496700, 1, ret=rnd32, pop=4, this=True, side=lg1)
    hook_rec(c, 0x496530, 0, ret=rnd32, pop=0, this=True, side=mkside(12))
    hook_rec(c, 0x4dbbc0, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('bc0', emu.reg('ecx'))), _s(emu, k)))
    hook_rec(c, 0x4dbbd0, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(14): (emu.calllog.append(('bd0', emu.reg('ecx'))), _s(emu, k)))
    # stream
    good = r.random() < 0.8
    rc = {'n': 0}
    def s18(emu, k, _s=mkside(15)):
        dst = emu.arg32(0); n = emu.arg32(1)
        i = rc['n']; rc['n'] += 1
        if i == 1: b = (0xd if good or r.random() < 0.5 else r.getrandbits(32)).to_bytes(4, 'little')
        elif i == 2: b = (0x2000 if good or r.random() < 0.5 else r.getrandbits(32)).to_bytes(4, 'little')
        else: b = bytes(r.getrandbits(8) for _ in range(n))
        emu.wbytes(dst, b)
        emu.calllog.append(('rd', i, n, zlib.crc32(b)))
        _s(emu, k)
    s18s = pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(0,), side=s18)
    def s14(emu, k, _s=mkside(16)):
        emu.calllog.append(('s14', emu.arg32(0)))
        _s(emu, k)
    s14s = pystub(c, 1, ret=rnd32, pop=4, this=True, side=s14)
    def sc(emu, k, _s=mkside(17)):
        emu.calllog.append(('sc', emu.arg32(0)))
        _s(emu, k)
    scs = pystub(c, 1, ret=rnd32, pop=4, this=True, side=sc)
    S = obj(c, 0x20, {0xc: scs, 0x14: s14s, 0x18: s18s})
    # T
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    arr = rnd(c, 0x60)
    c.emu.w32(T + 0x44, arr)
    c.emu.w32(T + 0x4c, r.choice([0, 1, 2, 3]))
    # globals
    ls = []
    def s48(emu, k, _s=mkside(18)):
        emu.calllog.append(('s48', emu.arg32(0)))
        _s(emu, k)
    s48s = pystub(c, 1, ret=rnd32, pop=4, this=True, side=s48)
    def scc(emu, k, _s=mkside(19)):
        emu.calllog.append(('scc', emu.arg32(0)))
        _s(emu, k)
    sccs = pystub(c, 1, ret=lambda emu, k: looked.get(emu.arg32(0), 0), pop=4, this=True, side=scc)
    g38 = obj(c, 0x20, {0x48: s48s, 0xcc: sccs})
    c.emu.w32(0x70038c, g38)
    sl = {}
    for j, off in enumerate([0x10, 0x14]):
        sl[off] = pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(23 + j))
    m_slots = {}
    for j, off in enumerate([0x74, 0x78]):
        m_slots[off] = pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(25 + j))
    o8 = obj(c, 0x20, {0x28: pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(27)), 0x2c: pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(28))})
    so = sysobj(c, slots=sl, table_slots=m_slots, table_size=0xc10)
    M = c.emu.r32(so + 0x9b)
    c.emu.w32(M + 8, o8)
    MH[0] = M
    # error logger
    def s2c(emu, k, _s=mkside(29)):
        emu.calllog.append(('log', emu.arg32(1)))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, S]


def g603500(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x6033c0, 1, ret=rnd32, pop=4, this=True, side=mkside(0))
    def s5f(emu, k, _s=mkside(1)):
        a = emu.arg32(0)
        emu.calllog.append(('l', emu.r32(a), emu.rbytes(a + 4, 1)))
        _s(emu, k)
    hook_rec(c, 0x5f5490, 2, ret=rnd32, pop=8, this=True, stackmark=(0,), side=s5f)
    hook_rec(c, 0x603850, 0, ret=rnd32, pop=0, this=True, side=mkside(2))
    c.emu.w32(0x724698, r.choice([0, 0, 1, 0x1234]))
    return [T, r.getrandbits(32)]


def g606a70(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, emu.reg('ecx'), zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x6071c0, 0, ret=rnd32, pop=0, this=True, side=mkside(0))
    hook_rec(c, 0x59a9b0, 1, ret=rnd32, pop=4, this=True, side=mkside(1))
    def s6ee(emu, k, _s=mkside(2)):
        emu.calllog.append(('loc', emu.r32(emu.arg32(2))))
        _s(emu, k)
    def sw(emu, k):
        emu.w32(T + 7, r.getrandbits(32)); 
    hook_rec(c, 0x606ee0, 3, ret=rnd32, pop=12, this=True, stackmark=(2,), side=s6ee)
    return [T]


def g603430(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(5)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, (emu.reg('ecx') - T) if j != 3 else 0, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x5f9700, 2, ret=rnd32, pop=8, this=True, side=mkside(0))
    hook_rec(c, 0x603850, 0, ret=rnd32, pop=0, this=True, side=mkside(1))
    hook_rec(c, 0x603c80, 2, ret=rnd32, pop=8, this=True, side=mkside(2))
    def alloc(emu, k):
        emu.calllog.append(('alloc', emu.arg32(0)))
        if r.random() < 0.25: return 0
        return rnd(c, 0x60)
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(3))
    c.emu.w32(0x724698, r.choice([0, 0, 1, 0x77]))
    return [T, r.getrandbits(32), r.getrandbits(32)]


def g5fb660(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    T = rnd(c, 0x20)
    head = rnd(c, 0x20)
    n = r.choice([0, 1, 2, 3, 5, 7])
    nodes = []
    def build(lo, hi, parent):
        if lo >= hi: return 0
        m = r.randrange(lo, hi)
        nd = nodes[m]
        c.emu.w32(nd + 1, parent)
        c.emu.w32(nd + 5, build(lo, m, nd))
        c.emu.w32(nd + 9, build(m + 1, hi, nd))
        return nd
    nodes = [rnd(c, 0x30) for _ in range(n)]
    vals = []
    for nd in nodes:
        if r.random() < 0.75:
            v = rnd(c, 0x1a0)
            vals.append(v)
            bg = r.choice([0, r.getrandbits(32) | 1])
            c.emu.w32(v + 0x172, bg)
            c.emu.w32(v + 0x17a, r.choice([bg, (bg + 8) & 0xffffffff, r.getrandbits(32), 0]))
            c.emu.w32(nd + 0x19, v)
        else:
            c.emu.w32(nd + 0x19, 0)
    if n:
        root = build(0, n, head)
        c.emu.w32(head + 1, root)
        c.emu.w32(head + 5, nodes[0])
        c.emu.w32(head + 9, nodes[-1])
    else:
        c.emu.w32(head + 5, head); c.emu.w32(head + 9, head); c.emu.w32(head + 1, 0)
    c.emu.w32(T + 1, head)
    c.emu.w32(T + 5, n if r.random() < 0.9 else 0)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            ec = emu.reg('ecx')
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(head, 0x20)), zlib.crc32(emu.rbytes(T, 0x20))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def s54(emu, k, _s=mkside(0)):
        emu.calllog.append(('54', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this=True, side=s54)
    hook_rec(c, 0x5fdb70, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('db', emu.reg('ecx'))), _s(emu, k)))
    hook_rec(c, 0x5fae50, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('ae', emu.reg('ecx'))), _s(emu, k)))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(3): (emu.calllog.append(('free', emu.arg32(0), emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x5fb370, 1, ret=rnd32, pop=4, this=True, side=mkside(4))
    return [T]


def g461250(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    sr = [seh_record(c, 2) for _ in range(12)]
    POOL = []
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, 0x80))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    # container
    ENT = rnd(c, 0x90)
    def s4(emu, k, _s=mkside(0)):
        emu.calllog.append(('cont4', emu.arg32(0)))
        _s(emu, k)
    def s20c(emu, k, _s=mkside(1)):
        emu.calllog.append(('cont20', emu.arg32(0) - ENT))
        _s(emu, k)
    CONT = obj(c, 0x40, {4: pystub(c, 1, ret=lambda emu, k: ENT + 4, pop=4, this=True, side=s4), 0x20: pystub(c, 1, ret=rnd32, pop=4, this=True, side=s20c)})
    def alloc(emu, k):
        emu.calllog.append(('alloc', emu.arg32(0)))
        return rnd(c, 0x30)
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(2))
    hook_rec(c, 0x4cca60, 2, ret=lambda emu, k: CONT, pop=8, this=True, side=mkside(3))
    hook_rec(c, 0x462460, 2, ret=rnd32, pop=8, this=True, stackmark=(), side=mkside(4))
    def s288(emu, k, _s=mkside(5)):
        emu.calllog.append(('288', emu.arg32(0)))
        _s(emu, k)
    ok34c = [r.choice([0, 1, 0x100, 5]) for _ in range(2)]
    def s34c(emu, k, _s=mkside(6)):
        emu.calllog.append(('34c', emu.arg32(0) - ENT, emu.arg32(1)))
        _s(emu, k)
    def s228(emu, k, _s=mkside(7)):
        emu.calllog.append(('228', emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4)))
        _s(emu, k)
    T = obj(c, 0x80, {0x288: pystub(c, 1, ret=rnd32, pop=4, this=True, side=s288), 0x34c: pystub(c, 2, ret=lambda emu, k: ok34c[0], pop=8, this=True, side=s34c), 0x228: pystub(c, 5, ret=rnd32, pop=20, this=True, side=s228)})
    EVO = obj(c, 0x20, {0x20: pystub(c, 1, ret=lambda emu, k: r.choice([0, rnd(c, 0x10)]), pop=4, this=True, side=mkside(8))})
    c.emu.w32(T + 0x5c, EVO)
    c.emu.w32(T + 0x18, r.choice([0, CONT]))
    A2 = r.getrandbits(32)
    if r.random() < 0.5: A2 |= 1
    return [T, r.choice([0, r.getrandbits(32) | 1, r.getrandbits(32) | 1]), A2, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g4dc440(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    TS = 0x80
    sr = [seh_record(c, 2) for _ in range(12)]
    def cstr(emu, a, lim=0x60):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    T = rnd(c, TS)
    flagsel = r.choice([0, 0x40000, 0x40000 | 0x4000, 0x40000 | 0x4000 | 0x400, 0x40000 | 0x200000, 0x40000 | 0x800, r.getrandbits(32) | 0x40000])
    c.emu.w32(T + 0x3c, flagsel)
    SB = rnd(c, 0x20); c.emu.wbytes(SB, bytes(r.randrange(65, 90) for _ in range(r.choice([0, 2, 7]))) + b'\0')
    R = rnd(c, 0x10); c.emu.w32(R, SB)
    last = [0]
    def s2f(emu, k, _s=mkside(0)):
        last[0] = emu.arg32(0)
        _s(emu, k)
    hook_rec(c, 0x4da2f0, 2, ret=lambda emu, k: R, pop=8, this=True, stackmark=(0,), side=s2f)
    def sdt(emu, k, _s=mkside(1)):
        emu.calllog.append(('dt', emu.reg('ecx') == last[0]))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=sdt)
    newflags = [r.choice([0x40000 | 0x4000, 0x40000, 0x40000 | 0x4000 | 0x200000, r.getrandbits(32) | 0x40000]) for _ in range(2)]
    def s630(emu, k, _s=mkside(2)):
        emu.calllog.append(('630', emu.arg32(0), emu.arg32(1)))
        emu.w32(T + 0x3c, newflags[0])
        _s(emu, k)
    hook_rec(c, 0x4dc630, 2, ret=rnd32, pop=8, this=True, side=s630)
    hook_rec(c, 0x4d9f90, 0, ret=rnd32, pop=0, this=True, side=mkside(3))
    hook_rec(c, 0x4dae60, 0, ret=rnd32, pop=0, this=True, side=mkside(4))
    def s95(emu, k, _s=mkside(5)):
        emu.calllog.append(('95', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x4d95f0, 2, ret=rnd32, pop=8, this=True, side=s95)
    # node chain
    nn = r.choice([0, 1, 2, 3])
    nodes = [rnd(c, 0x60) for _ in range(nn)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x50, nodes[i + 1] if i + 1 < nn else 0)
        if r.random() < 0.8:
            a = rnd(c, 0x20)
            bl = [rnd(c, 0x30) for _ in range(r.choice([0, 1, 2]))]
            for j, b in enumerate(bl):
                c.emu.w32(b + 0xc, bl[j + 1] if j + 1 < len(bl) else 0)
                c.emu.w32(b + 0x23, 0x100021 if r.random() < 0.25 else r.getrandbits(32))
            c.emu.w32(a + 0xc, bl[0] if bl else 0)
            c.emu.w32(nd + 0x54, a)
        else:
            c.emu.w32(nd + 0x54, 0)
    c.emu.w32(T + 0x50, nodes[0] if nodes else 0)
    # logger
    def s2c(emu, k, _s=mkside(6)):
        emu.calllog.append(('log', emu.arg32(1), cstr(emu, emu.arg32(2)).hex()))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 3, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, r.choice([0, 1, 1, 0x100])]


def g4dbe30(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    TS = 0x80
    sr = [seh_record(c, 2) for _ in range(16)]
    def cstr(emu, a, lim=0x60):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    T = rnd(c, TS)
    want = r.choice([0, 1, 1, 0, 5])
    curbit = r.choice([0, 1])
    base = r.getrandbits(32) & ~0x40000 & ~0x200c00 & ~0x40000000
    if r.random() < 0.5: base |= 0x200c00 & r.getrandbits(32)
    if r.random() < 0.5: base |= 0x40000000
    if curbit: base |= 0x40000
    if r.random() < 0.3: base = (base & ~0xff) | r.choice([0, 1, 0x80])
    c.emu.w32(T + 0x3c, base)
    c.emu.w32(T + 0x64, r.choice([0, 0, 0x1234]))
    def newflags(): return (r.getrandbits(32) & ~0x200c00) | (0x200c00 & r.getrandbits(32) if r.random() < 0.4 else 0)
    SB = rnd(c, 0x20); c.emu.wbytes(SB, bytes(r.randrange(65, 90) for _ in range(r.choice([0, 2, 7]))) + b'\0')
    SB2 = rnd(c, 0x20); c.emu.wbytes(SB2, bytes(r.randrange(97, 120) for _ in range(r.choice([1, 3]))) + b'\0')
    R1 = rnd(c, 0x10); c.emu.w32(R1, SB)
    R2 = rnd(c, 0x10); c.emu.w32(R2, SB2)
    last = []
    def s2f(emu, k, _s=mkside(0)):
        last.append(emu.arg32(0))
        emu.calllog.append(('2f0', emu.reg('ecx') == T, k))
        _s(emu, k)
    hook_rec(c, 0x4da2f0, 2, ret=lambda emu, k: R1 if k % 2 == 0 else R2, pop=8, this=True, stackmark=(0,), side=s2f)
    def sdt(emu, k, _s=mkside(1)):
        emu.calllog.append(('dt', [emu.reg('ecx') == x for x in last]))
        _s(emu, k)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=sdt)
    def mk1(addr, j, mod=False, n=1):
        def sd(emu, k, _s=mkside(j)):
            emu.calllog.append((hex(addr), emu.arg32(0) if n else 0, emu.arg32(1) if n > 1 else 0))
            if mod: emu.w32(T + 0x3c, newflags()); emu.w32(T + 0x64, r.choice([0, 7]))
            _s(emu, k)
        hook_rec(c, addr, n, ret=rnd32, pop=4 * n, this=True, side=sd)
    mk1(0x4da770, 2, False, 1)
    mk1(0x4dc630, 3, True, 2)
    mk1(0x4dc840, 4, True, 1)
    mk1(0x4d9ce0, 5, False, 0)
    mk1(0x4d9bf0, 6, False, 0)
    mk1(0x4dc1a0, 8, True, 0)
    mk1(0x4d9d20, 9, False, 1)
    mk1(0x4dc440, 10, True, 1)
    mk1(0x4dae60, 11, False, 0)
    s320 = pystub(c, 1, ret=rnd32, pop=4, this=True, side=mkside(12))
    E = obj(c, 0x30, {0x320: s320})
    hook_rec(c, 0x4daff0, 0, ret=lambda emu, k: r.choice([0, E]), pop=0, this=True, side=mkside(7))
    s284 = pystub(c, 0, ret=rnd32, pop=0, this=True, side=mkside(13))
    X = obj(c, 0x40, {0x284: s284}); c.emu.w32(X + 8, rnd(c, 0x20))
    nn = r.choice([1, 1, 2, 3])
    nodes = [rnd(c, 0x60) for _ in range(nn)]
    for i, nd in enumerate(nodes):
        c.emu.w32(nd + 0x50, nodes[i + 1] if i + 1 < nn else 0)
        c.emu.w32(nd + 0x54, X if (want == 0 or r.random() < 0.8) else 0)
        c.emu.w32(nd + 0x3c, r.getrandbits(32) & ~0x40000 if r.random() < 0.5 else r.getrandbits(32) | 0x40000)
    c.emu.w32(T + 0x50, nodes[0])
    def s2c(emu, k, _s=mkside(14)):
        emu.calllog.append(('log', emu.arg32(1), cstr(emu, emu.arg32(2)).hex(), cstr(emu, emu.arg32(3)).hex()))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 4, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, want]


def g49a790(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    TS = 0x40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(12)]
    def ofields(emu):
        o = emu.reg('ecx')
        return (emu.rbytes(o, 1)[0], emu.r32(o + 1), emu.r32(o + 5), emu.r32(o + 9), emu.r32(o + 0x11))
    def mkside(j, withO=False):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS)), ofields(emu) if withO else 0))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    cnt = r.choice([0, 1, 2, 3, 5])
    B = rnd(c, 4 + 0xc * 5 + 8)
    c.emu.w32(B, cnt)
    c.emu.w32(T + 0x1c, B)
    c.emu.w32(T + 0x20, r.getrandbits(32))
    szv = r.choice([0x30, 0x30, 0x18, 0xffffffff])
    good = r.random() < 0.8
    def s_e0(emu, k, _s=mkside(0)):
        emu.calllog.append(('e0', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    def s_dc(emu, k, _s=mkside(1)):
        b = emu.arg32(0)
        emu.wbytes(b, bytes(r.getrandbits(8) for _ in range(0x30)))
        emu.calllog.append(('dc', emu.arg32(1), emu.arg32(2), emu.rbytes(b, 0x30).hex()))
        _s(emu, k)
    G394 = obj(c, 0x200, {0xe0: pystub(c, 2, ret=lambda emu, k: szv, pop=8, this=True, side=s_e0),
                          0xdc: pystub(c, 3, ret=lambda emu, k: 1 if good else r.choice([0, 0x100]), pop=12, this=True, stackmark=(), side=s_dc)})
    c.emu.w32(0x700394, G394)
    def alloc(emu, k, _s=mkside(2)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x40 + 0x10 * 5), pop=0, this=False, side=alloc)
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(3): (emu.calllog.append(('free', emu.arg32(0) != 0, emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x4d5510, 0, ret=rnd32, pop=0, this='mark', side=mkside(4))
    hook_rec(c, 0x4d5640, 0, ret=rnd32, pop=0, this='mark', side=mkside(5, True))
    def s75(emu, k, _s=mkside(6, True)):
        emu.calllog.append(('7530', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x4d7530, 1, ret=rnd32, pop=4, this='mark', side=s75)
    def s76(emu, k, _s=mkside(7, True)):
        emu.calllog.append(('7610', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x4d7610, 2, ret=rnd32, pop=8, this='mark', side=s76)
    for off in range(cnt):
        for q in range(3):
            c.emu.w32(B + 4 + 0xc * off + 4 * q, r.getrandbits(32))
    def s2c(emu, k, _s=mkside(8)):
        emu.calllog.append(('log', emu.arg32(1), emu.arg32(2) if emu.arg32(1) != 0x68ecbc else 0))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, r.getrandbits(32), r.getrandbits(32)]


def g52a370(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    TS = 0x100
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def s43(emu, k, _s=mkside(0)):
        emu.calllog.append(('43', emu.reg('ecx') == T, emu.arg32(0), emu.arg32(1), emu.arg32(2)))
        _s(emu, k)
    hook_rec(c, 0x43de40, 3, ret=rnd32, pop=12, this=True, side=s43)
    def alloc(emu, k, _s=mkside(1)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    def al_ret(emu, k):
        if r.random() < 0.15: return 0
        return rnd(c, max(emu.arg32(0), 0x240) + 8) if emu.arg32(0) <= 0x1000 else 0
    hook_rec(c, 0x41e290, 1, ret=al_ret, pop=0, this=False, side=alloc)
    hook_rec(c, 0x52cec0, 2, ret=lambda emu, k: r.choice([0, rnd(c, 0x20)]), pop=8, this=True, side=mkside(2))
    hook_rec(c, 0x52cea0, 1, ret=rnd32, pop=4, this=True, side=mkside(3))
    hook_rec(c, 0x52a300, 1, ret=rnd32, pop=4, this=True, side=mkside(4))
    s114 = pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=16, this=True, side=mkside(5))
    OBJ = obj(c, 0x40, {0x4c: pystub(c, 2, ret=rnd32, pop=8, this=True, side=mkside(6))})
    s138 = pystub(c, 0, ret=lambda emu, k: OBJ, pop=0, this=True, side=mkside(7))
    def s4c(emu, k, _s=mkside(8)):
        emu.calllog.append(('4c', emu.arg32(0) == T))
        _s(emu, k)
    s4cs = pystub(c, 1, ret=rnd32, pop=4, this=True, side=s4c)
    so = sysobj(c, slots={}, table_slots={0x114: s114, 0x138: s138, 0x4c: s4cs}, table_size=0x40)
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    return [T, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g5aba60(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    TS = 0x100
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    objs = []
    def mkl(name, j, n, pop, extra=False):
        def sd(emu, k, _s=mkside(j)):
            o = emu.reg('ecx')
            emu.calllog.append((name, objs.index(o) if o in objs else -1, [emu.arg32(i) for i in range(n)]))
            _s(emu, k)
        return pystub(c, n, ret=rnd32, pop=pop, this=True, side=sd)
    OVT = {0x26c: mkl('26c', 0, 3, 12), 0x27c: mkl('27c', 1, 1, 4), 0x248: mkl('248', 2, 1, 4)}
    def newobj():
        o = obj(c, 0xb0, OVT)
        objs.append(o)
        return o
    def d20(emu, k, _s=mkside(3)):
        emu.calllog.append(('d20', [emu.arg32(i) for i in range(6)]))
        _s(emu, k)
    def d1c4(emu, k, _s=mkside(4)):
        emu.calllog.append(('d1c4', emu.arg32(0)))
        _s(emu, k)
    DEV = obj(c, 0x20, {0x20: pystub(c, 6, ret=rnd32, pop=24, this=True, side=d20), 0x1c4: pystub(c, 1, ret=lambda emu, k: newobj(), pop=4, this=True, side=d1c4)})
    def m58(emu, k, _s=mkside(5)):
        emu.calllog.append(('m58', emu.arg32(0)))
        _s(emu, k)
    so = sysobj(c, slots={}, table_slots={0x58: pystub(c, 1, ret=lambda emu, k: DEV, pop=4, this=True, side=m58)}, table_size=0x40)
    n = r.choice([0, 1, 2, 3, 4])
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.w32(T + 0x7f, n)
    for i in range(4):
        c.emu.w32(T + 0x1a + 4 * i, r.choice([0, newobj()]))
        c.emu.w32(T + 0x42 + 4 * i, r.choice([0, newobj()]))
    def alloc(emu, k, _s=mkside(6)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x100), pop=0, this=False, side=alloc)
    def s14(emu, k, _s=mkside(7)):
        emu.calllog.append(('n14', [emu.arg32(i) for i in range(5)]))
        _s(emu, k)
    NEWO = obj(c, 0x40, {0x14: pystub(c, 5, ret=rnd32, pop=20, this=True, side=s14)})
    hook_rec(c, 0x5ec720, 1, ret=lambda emu, k: NEWO, pop=4, this=True, side=mkside(8))
    c.emu.w32(0x7142fc, r.getrandbits(32))
    return [T, r.getrandbits(32), r.getrandbits(32), r.choice([0, r.getrandbits(32) | 1]), r.choice([0, 1, 0x100, 0x3f, r.getrandbits(32)])]


def g57ee90(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    from recruits_util import obj, sysobj
    TS = 0x100
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(14)]
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
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    C1 = cstr(c.emu, 0x6aad2c); C2 = cstr(c.emu, 0x6aad40)
    def mkstr():
        ch = r.choice([0, 1, 2, 3])
        b = [C1, C2, b'abc', b''][ch]
        sp = rnd(c, 0x40); c.emu.wbytes(sp, b + b'\0')
        ro = rnd(c, 0x10); c.emu.w32(ro, sp)
        return ro
    # object slots for 0xbc
    def s_bc(emu, k, _s=mkside(0)):
        emu.calllog.append(('bc', emu.arg32(1)))
        _s(emu, k)
    BC = obj(c, 0x20, {0xbc: pystub(c, 2, ret=lambda emu, k: mkstr(), pop=8, this=True, stackmark=(0,), side=s_bc)})
    so = sysobj(c, slots={}, table_slots={}, table_size=0xb00)
    c.emu.w32(so + 0x1907, BC)
    # manager objects: +0xae4 obj with vslot 0
    objs = []
    def mkl(name, j, n, pop):
        def sd(emu, k, _s=mkside(j)):
            o = emu.reg('ecx')
            emu.calllog.append((name, objs.index(o) if o in objs else -1, [emu.arg32(i) for i in range(n)]))
            _s(emu, k)
        return pystub(c, n, ret=rnd32, pop=pop, this=True, side=sd)
    VT = {0x28c: mkl('28c', 1, 0, 0), 0x284: mkl('284', 2, 1, 4), 0x26c: mkl('26c', 3, 3, 12)}
    def newo(sz=0x80):
        o = obj(c, sz, VT)
        objs.append(o)
        return o
    ET = pystub(c, 2, ret=lambda emu, k: 0x4000 + k, pop=8, this=True, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('v0', emu.arg32(0), emu.arg32(1))), _s(emu, k)))
    E = obj(c, 0x20, {0: ET})
    M = c.emu.r32(so + 0x9b)
    c.emu.w32(M + 0xae4, E)
    A = T
    c.emu.w32(A + 0xc, 0)
    # objects at A+0xc+4i and A+0x1c+4i
    for i in range(4):
        o = newo()
        o8 = rnd(c, 0x60)
        c.emu.wbytes(o8 + 0x40, struct.pack('<f', r.choice([0.0, 1.5, -3.0, 100.25, 1e6, r.uniform(-500, 500)])))
        c.emu.w32(o + 8, o8)
        c.emu.w32(A + 0xc + 4 * i, o)
        c.emu.w32(A + 0x1c + 4 * i, newo())
    # values at A+0xac+4i
    nvalid = r.choice([0, 1, 2, 3, 4])
    for i in range(4):
        c.emu.w32(A + 0xac + 4 * i, r.choice([0x82, 0x36, 5, 0x1234, r.getrandbits(32) & 0xffff]) if i < nvalid or r.random() < 0.3 else 0xffffffff)
    def s57(emu, k, _s=mkside(5)):
        a0 = emu.arg32(0)
        emu.calllog.append(('57', cstr(emu, a0).hex(), emu.arg32(1), emu.arg32(2)))
        _s(emu, k)
    hook_rec(c, 0x57edf0, 3, ret=rnd32, pop=12, this=True, stackmark=(0,), side=s57)
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=mkside(6))
    return [T]


def g5f37f0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0xad8
    T = rnd(c, TS)
    SRC = rnd(c, 0xa8)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    cnt = {'n': 0}
    def alloc(emu, k, _s=mkside(0)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    def al_ret(emu, k):
        n = cnt['n']; cnt['n'] += 1
        if n < 3 and r.random() < 0.2: return 0
        return rnd(c, emu.arg32(0) + 0x10)
    hook_rec(c, 0x41e290, 1, ret=al_ret, pop=0, this=False, side=alloc)
    def s600(emu, k, _s=mkside(1)):
        emu.calllog.append(('600', emu.reg('ecx') - T, emu.arg32(0) - SRC))
        _s(emu, k)
    hook_rec(c, 0x600240, 1, ret=rnd32, pop=4, this=True, side=s600)
    hook_rec(c, 0x5f9130, 2, ret=rnd32, pop=8, this=True, side=mkside(2))
    hook_rec(c, 0x5f5620, 1, ret=rnd32, pop=4, this=True, side=mkside(3))
    return [T, SRC, r.getrandbits(32)]


def g5f9940(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x20
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(12)]
    def cstr(emu, a, lim=0x40):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS)), zlib.crc32(emu.rbytes(ARR, 0x40))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    ARR = rnd(c, 0x40)
    names = [bytes(r.choice(b'abcd') for _ in range(r.choice([0, 1, 3, 8, 11]))) for _ in range(4)]
    n = r.choice([0, 1, 2, 3])
    ents = []
    for i in range(n):
        nm = r.choice(names)
        sb = rnd(c, 0x20); c.emu.wbytes(sb, nm + b'\0')
        e = rnd(c, 0x20)
        c.emu.w32(e + 4, sb); c.emu.w32(e + 8, sb + len(nm))
        c.emu.w32(ARR + 4 * i, e)
        ents.append(e)
    c.emu.w32(T, ARR)
    c.emu.w32(T + 4, ARR + 4 * n)
    c.emu.w32(T + 8, ARR + 4 * n + (0 if r.random() < 0.4 else 8))
    A1nm = r.choice(names)
    A1 = rnd(c, 0x30); c.emu.wbytes(A1, A1nm + b'\0')
    # IAT 0x676408: strncmp
    def sncmp(emu, k, _s=mkside(0)):
        a = emu.arg32(0); b = emu.arg32(1); nn = emu.arg32(2)
        emu.calllog.append(('ncmp', emu.rbytes(a, nn).hex(), emu.rbytes(b, nn).hex(), nn))
        _s(emu, k)
    def ncmp_ret(emu, k):
        a = emu.arg32(0); b = emu.arg32(1); nn = emu.arg32(2)
        return 0 if emu.rbytes(a, nn) == emu.rbytes(b, nn) else 1
    c.emu.w32(0x676408, pystub(c, 3, ret=ncmp_ret, pop=0, this=False, side=sncmp))
    def smm(emu, k, _s=mkside(1)):
        d = emu.arg32(0); sr_ = emu.arg32(1); nn = emu.arg32(2)
        emu.calllog.append(('mmove', emu.arg32(2)))
        emu.wbytes(d, emu.rbytes(sr_, nn))
        _s(emu, k)
    c.emu.w32(0x676278, pystub(c, 3, ret=rnd32, pop=0, this=False, side=smm))
    def memcpy(emu, k, _s=mkside(2)):
        d = emu.arg32(0); s_ = emu.arg32(1); nn = emu.arg32(2)
        emu.calllog.append(('memcpy', nn))
        emu.wbytes(d, emu.rbytes(s_, nn))
        _s(emu, k)
    hook_rec(c, 0x634d22, 3, ret=rnd32, pop=0, this=False, side=memcpy)
    def al(emu, k, _s=mkside(3)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x60), pop=0, this=False, side=al)
    def s6014(emu, k, _s=mkside(4)):
        emu.calllog.append(('6014', emu.arg32(0), emu.rbytes(emu.reg('ecx') - 4, 0x10).hex()))
        _s(emu, k)
    hook_rec(c, 0x6014a0, 1, ret=lambda emu, k: rnd(c, 0x20), pop=4, this=True, side=s6014)
    hook_rec(c, 0x5f9720, 0, ret=rnd32, pop=0, this=True, side=mkside(5))
    def s2c60(emu, k, _s=mkside(6)):
        emu.calllog.append(('2c60', cstr(emu, emu.arg32(0)).hex(), emu.arg32(1) - emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x5f2c60, 2, ret=rnd32, pop=8, this=True, side=s2c60)
    hook_rec(c, 0x605ba0, 1, ret=rnd32, pop=4, this=True, side=mkside(7))
    def s5fe(emu, k, _s=mkside(8)):
        emu.calllog.append(('5fe', emu.arg32(0) - ARR, emu.r32(emu.arg32(1)) != 0))
        _s(emu, k)
    hook_rec(c, 0x5fe3b0, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=s5fe)
    c.emu.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, this=False, side=mkside(9)))
    def s2c(emu, k, _s=mkside(10)):
        emu.calllog.append(('log', emu.arg32(1), emu.arg32(2)))
        _s(emu, k)
    from recruits_util import obj
    LO = obj(c, 0x20, {0x2c: pystub(c, 3, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, A1, r.getrandbits(32), r.getrandbits(32)]


def g512590(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    TS = 0x140
    sr = [seh_record(c, 2) for _ in range(24)]
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
    objs = []
    def mkl(name, j, n, pop, retf=None):
        def sd(emu, k, _s=mkside(j)):
            o = emu.reg('ecx')
            emu.calllog.append((name, objs.index(o) if o in objs else -1, [emu.arg32(i) for i in range(n)]))
            _s(emu, k)
        return pystub(c, n, ret=(retf or rnd32), pop=pop, this=True, side=sd)
    def reg_obj(o): objs.append(o); return o
    # node objects (vtable 0x1e0)
    p1e0 = [r.random() < 0.4 for _ in range(16)]
    cnt1e0 = [0]
    def r1e0(emu, k):
        cnt1e0[0] += 1
        return 1 if r.random() < 0.4 else r.choice([0, 0x100])
    NV = {0x1e0: mkl('1e0', 0, 1, 4, r1e0)}
    ND = rnd(c, 0x20)
    nn = r.choice([0, 1, 2, 3])
    nodes = [rnd(c, 0x80) for _ in range(nn)]
    for i, nd in enumerate(nodes):
        o = reg_obj(obj(c, 0x20, NV))
        nm = rnd(c, 0x20); c.emu.wbytes(nm, bytes(r.randrange(97, 123) for _ in range(r.choice([1, 4]))) + b'\0')
        c.emu.w32(o + 4, r.choice([0, nm]))
        c.emu.w32(nd + 0x54, o)
        c.emu.w32(nd + 0x60, nodes[i + 1] if i + 1 < nn else 0)
    # vec objects
    POOL = rnd(c, 0x20)
    def vslot4(name, j):
        return mkl(name, j, 1, 4, lambda emu, k: rnd(c, 0x20))
    V1 = reg_obj(obj(c, 0x20, {4: vslot4('v1', 1)}))
    V2 = reg_obj(obj(c, 0x20, {4: vslot4('v2', 2)}))
    # esi object
    ES = rnd(c, 0x40)
    esv = obj(c, 0x40, {8: mkl('es8', 3, 0, 0), 0x4c: mkl('es4c', 4, 0, 0), 0x54: mkl('es54', 5, 1, 4)})
    c.emu.w32(ES, c.emu.r32(esv))
    c.emu.w32(ES + 4, r.choice([0, 1, 4, 5, 0x100, r.getrandbits(32)]))
    c.emu.w32(ES + 0x30, r.getrandbits(32))
    if r.random() < 0.5: c.emu.w32(ES + 4, c.emu.r32(ES + 4) | 1)
    # E object (mgr 0x58 result)
    E = reg_obj(obj(c, 0x20, {0x10c: mkl('e10c', 6, 2, 8, lambda emu, k: ES), 0x3c: mkl('e3c', 7, 1, 4)}))
    sl = {0x50: mkl('m50', 8, 1, 4, lambda emu, k: rnd(c, 0x10)), 0x58: mkl('m58', 9, 1, 4, lambda emu, k: E)}
    so = sysobj(c, slots={}, table_slots=sl, table_size=0x40)
    # this object
    S1D8 = reg_obj(obj(c, 0x10, {}))
    SB = rnd(c, 0x20); c.emu.wbytes(SB, bytes(r.randrange(65, 90) for _ in range(r.choice([0, 3]))) + b'\0')
    R = rnd(c, 0x10); c.emu.w32(R, SB)
    def s1d8(emu, k, _s=mkside(10)):
        emu.calllog.append(('1d8', emu.arg32(1)))
        _s(emu, k)
    T = obj(c, TS, {0x124: mkl('124', 11, 4, 16), 0x1d8: pystub(c, 2, ret=lambda emu, k: R, pop=8, this=True, stackmark=(0,), side=s1d8)})
    c.emu.wbytes(T + 4, bytes(r.getrandbits(8) for _ in range(TS - 4)))
    c.emu.w32(T + 0x50, nodes[0] if nodes else 0)
    c.emu.w32(T + 0x127, V1)
    c.emu.w32(T + 0x12b, V2)
    c.emu.w32(T + 0x123, 0xdead)
    objs.append(T)
    # hooks
    def s850(emu, k, _s=mkside(12)):
        emu.calllog.append(('850', cstr(emu, emu.reg('ecx')).hex(), emu.reg('edx')))
        _s(emu, k)
    p850 = r.choice([0.2, 0.4, 0.6])
    hook_rec(c, 0x4cc850, 0, ret=lambda emu, k: 0 if r.random() < p850 else r.choice([1, 0xffffffff, 5]), pop=0, this=False, side=s850)
    hook_rec(c, 0x4db860, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('860', objs.index(emu.reg('ecx')) if emu.reg('ecx') in objs else -1, emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x44a1f0, 0, ret=rnd32, pop=0, this=True, side=mkside(14))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=mkside(15))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, this=False, side=mkside(16)))
    def s2c(emu, k, _s=mkside(17)):
        emu.calllog.append(('log', emu.arg32(1), cstr(emu, emu.arg32(2)).hex()))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 3, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T]


def g520110(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    TS = 0x2720
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(10)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def rel(emu):
        ec = emu.reg('ecx')
        return ec - T if T <= ec < T + TS else -1
    def s0(emu, k, _s=mkside(0)):
        emu.calllog.append(('v0', rel(emu), [emu.arg32(i) for i in range(3)]))
        _s(emu, k)
    def s4(emu, k, _s=mkside(1)):
        emu.calllog.append(('v4', rel(emu), emu.arg32(0) - T, emu.arg32(1) - T))
        _s(emu, k)
    VT = c.emu.alloc(0x20, 4)
    c.emu.w32(VT, pystub(c, 3, ret=rnd32, pop=12, this=True, side=s0))
    c.emu.w32(VT + 4, pystub(c, 2, ret=rnd32, pop=8, this=True, side=s4))
    def s5273(emu, k, _s=mkside(2)):
        emu.calllog.append(('ctor', rel(emu)))
        emu.w32(emu.reg('ecx'), VT)
        _s(emu, k)
    hook_rec(c, 0x5273b0, 0, ret=rnd32, pop=0, this=True, side=s5273)
    def s5149(emu, k, _s=mkside(3)):
        emu.calllog.append(('base', rel(emu), [emu.arg32(i) for i in range(3)]))
        _s(emu, k)
    hook_rec(c, 0x514940, 3, ret=rnd32, pop=12, this=True, side=s5149)
    hook_rec(c, 0x527570, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('2757', rel(emu))), _s(emu, k)))
    s114 = pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=16, this=True, side=lambda emu, k, _s=mkside(5): (emu.calllog.append(('114', [emu.arg32(i) for i in range(4)])), _s(emu, k)))
    so = sysobj(c, slots={}, table_slots={0x114: s114}, table_size=0x40)
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    return [T, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def g4e6ce0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import reftab_vt
    TS = 0x40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    elems = [rnd(c, 0x20) for _ in range(r.choice([0, 1, 2, 3, 5]))]
    VT = reftab_vt(c, list(elems))
    c.emu.w32(T + 0xc, VT)
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('free', elems.index(emu.arg32(0)) if emu.arg32(0) in elems else -1, emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('dtor', emu.reg('ecx') - T)), _s(emu, k)))
    return [T]


def g5fb370(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x20
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(2)]
    nodes = []
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    n = r.choice([0, 1, 2, 3, 5, 7])
    nodes = [rnd(c, 0x30) for _ in range(n)]
    def build(lo, hi):
        if lo >= hi: return 0
        m = r.randrange(lo, hi)
        nd = nodes[m]
        c.emu.w32(nd + 5, build(lo, m))
        c.emu.w32(nd + 9, build(m + 1, hi))
        bg = r.choice([0, r.getrandbits(32) | 1])
        c.emu.w32(nd + 0xd, bg)
        c.emu.w32(nd + 0x15, r.choice([bg, (bg + 8) & 0xffffffff, r.getrandbits(32), 0]))
        return nd
    root = build(0, n)
    def s54(emu, k, _s=mkside(0)):
        ec = emu.reg('ecx')
        emu.calllog.append(('54', ec == T, nodes.index(ec - 0xd) if (ec - 0xd) in nodes else -1, nodes.index(emu.arg32(0)) if emu.arg32(0) in nodes else emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x54f870, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s54)
    return [T, root]


def g5afef0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj, reftab_vt
    TS = 0x1d40
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    elems = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 4, 6]))]
    LV = reftab_vt(c, list(elems))
    lastc = [0]
    def ctorL(emu, k, _s=mkside(0)):
        lastc[0] = emu.reg('ecx')
        emu.w32(emu.reg('ecx'), LV)
        _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=ctorL)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('dt', emu.reg('ecx') - lastc[0])), _s(emu, k)))
    key = r.choice([7, 8])
    objs = []
    def s2e8(emu, k, _s=mkside(2)):
        emu.calllog.append(('2e8', objs.index(emu.reg('ecx')) if emu.reg('ecx') in objs else -1))
        _s(emu, k)
    s2e8s = pystub(c, 0, ret=lambda emu, k: key if r.random() < 0.5 else r.choice([7, 8, 9]), pop=0, this=True, side=s2e8)
    def newo():
        o = obj(c, 0x20, {0x2e8: s2e8s})
        objs.append(o)
        return o
    A1 = newo()
    omap = {e: newo() for e in elems}
    def m58(emu, k, _s=mkside(3)):
        emu.calllog.append(('m58', elems.index(emu.arg32(0)) if emu.arg32(0) in elems else -1))
        _s(emu, k)
    so = sysobj(c, slots={}, table_slots={0x58: pystub(c, 1, ret=lambda emu, k: omap.get(emu.arg32(0), A1), pop=4, this=True, side=m58)}, table_size=0x40)
    def s130(emu, k, _s=mkside(4)):
        emu.calllog.append(('130', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    CO = obj(c, 0x20, {0x130: pystub(c, 3, ret=rnd32, pop=12, this=True, stackmark=(2,), side=s130)})
    T = rnd(c, TS)
    c.emu.w32(T + 0x44, CO)
    return [T, A1]


def g4ff9d0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x20
    T = rnd(c, TS)
    ARR = rnd(c, 0x60)
    sr = [seh_record(c, 2) for _ in range(4)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS)), zlib.crc32(emu.rbytes(ARR, 0x60))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    n = r.choice([0, 1, 2, 3, 5])
    items = []
    for i in range(n):
        if r.random() < 0.75:
            it = rnd(c, 0x50); items.append(it)
            c.emu.w32(ARR + 4 * i, it)
        else:
            c.emu.w32(ARR + 4 * i, 0)
    extra = r.choice([0, 0, 0, 2])
    c.emu.w32(T, ARR)
    c.emu.w32(T + 4, ARR + 4 * n + extra)
    c.emu.w32(T + 8, ARR + 4 * n + extra + r.choice([0, 4, 8, 0x10]))
    hook_rec(c, 0x4ff920, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('d', items.index(emu.reg('ecx')) if emu.reg('ecx') in items else -1)), _s(emu, k)))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('free', items.index(emu.arg32(0)) if emu.arg32(0) in items else -1, emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('54', emu.reg('ecx') == T, emu.arg32(0) - ARR, emu.arg32(1))), _s(emu, k)))
    return [T]


def g6041e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    TS = 0x40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(8)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x603430, 2, ret=rnd32, pop=8, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('base', emu.reg('ecx') == T, emu.arg32(0), emu.arg32(1))), _s(emu, k)))
    def s6014(emu, k, _s=mkside(1)):
        ec = emu.reg('ecx')
        emu.calllog.append(('6014', emu.arg32(0), emu.rbytes(ec, 12).hex() if False else emu.r32(ec) , emu.r32(ec + 4), emu.r32(ec + 8)))
        _s(emu, k)
    POOL = []
    hook_rec(c, 0x6014a0, 1, ret=lambda emu, k: rnd(c, 0x20), pop=4, this='mark', side=s6014)
    big = r.random() < 0.3
    capz = r.random() < 0.3
    def s6c(emu, k, _s=mkside(2)):
        sp = emu.arg32(0)
        b = emu.r32(sp)
        emu.w32(sp + 4, (emu.r32(sp + 4) + (0x21 if big else r.choice([0, 3, 8, 0x20]))) & 0xffffffff)
        if capz: emu.w32(sp + 8, b)
        emu.calllog.append(('6c', emu.r32(sp + 4) - b, emu.r32(sp + 8) - b))
        _s(emu, k)
    A1 = obj(c, 0x20, {0x6c: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s6c)})
    def s0(emu, k, _s=mkside(3)):
        emu.calllog.append(('slot0', emu.arg32(0) != 0, emu.rbytes(emu.arg32(0), 4).hex()))
        _s(emu, k)
    OB = obj(c, 0x20, {0: pystub(c, 1, ret=rnd32, pop=4, this=True, side=s0)})
    G42 = rnd(c, 0x60); c.emu.w32(G42 + 0x3c, OB)
    c.emu.w32(0x724278, G42)
    def s54(emu, k, _s=mkside(4)):
        emu.calllog.append(('54', emu.arg32(0) != 0, emu.arg32(1)))
        _s(emu, k)
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this='mark', stackmark=(), side=s54)
    c.emu.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, this=False, side=mkside(5)))
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    return [T, A1, r.getrandbits(32)]


def g5bfac0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    TS = 0x80
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    hook_rec(c, 0x469870, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('base', emu.reg('ecx') == T)), _s(emu, k)))
    def cstr(emu, a, lim=0x40):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    ECONST = cstr(c.emu, 0x67a6d8)
    STR = [rnd(c, 0x40) for _ in range(3)]
    c.emu.wbytes(STR[0], ECONST + b'\0')
    c.emu.wbytes(STR[1], ECONST[:-1] + b'x\0' if ECONST else b'x\0')
    c.emu.wbytes(STR[2], ECONST + b'zz\0')
    pick = r.randrange(3)
    okv = r.choice([0, 1, 1, 1, 0x100])
    def s5c(emu, k, _s=mkside(1)):
        emu.calllog.append(('5c', emu.arg32(0)))
        if okv & 0xff: emu.w32(emu.arg32(1), STR[pick])
        _s(emu, k)
    s114 = pystub(c, 4, ret=lambda emu, k: r.getrandbits(32), pop=16, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('114', [emu.arg32(i) for i in range(4)])), _s(emu, k)))
    so = sysobj(c, slots={0x5c: pystub(c, 2, ret=lambda emu, k: okv, pop=8, this=True, stackmark=(1,), side=s5c)}, table_slots={0x114: s114}, table_size=0x40)
    G8 = rnd(c, 0x2c20); c.emu.w32(0x7003b8, G8)
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    return [T]


def g480ff0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj
    TS = 0x660
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(6)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    objs = []
    def mkl(name, j, slot):
        def sd(emu, k, _s=mkside(j)):
            o = emu.reg('ecx')
            emu.calllog.append((name, objs.index(o) if o in objs else -1, emu.arg32(0)))
            _s(emu, k)
        return pystub(c, 1, ret=rnd32, pop=4, this=True, side=sd)
    OV = {0: mkl('v0', 0, 0), 4: mkl('v4', 1, 4)}
    def newo():
        o = obj(c, 0x20, OV); objs.append(o); return o
    cntv = r.choice([0, 1, 2, 3])
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.w32(T + 0x459, cntv)
    for i in range(5):
        c.emu.w32(T + 0x45d + 4 * i, r.choice([0, newo()]))
    for off in (0x61a, 0x62e, 0x632, 0x636, 0x63a, 0x62a, 0x63e):
        c.emu.w32(T + off, r.choice([0, newo()]))
    def s1a8(emu, k, _s=mkside(2)):
        emu.calllog.append(('1a8', objs.index(emu.arg32(0)) if emu.arg32(0) in objs else emu.arg32(0)))
        _s(emu, k)
    SO = obj(c, 0x200, {0x1a8: pystub(c, 1, ret=rnd32, pop=4, this=True, side=s1a8)})
    c.emu.w32(0x70039c, SO)
    hook_rec(c, 0x471f60, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(3): (emu.calllog.append(('base', emu.reg('ecx') == T)), _s(emu, k)))
    return [T]


def g52b4e0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    from recruits_util import obj
    TS = 0x80
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(20)]
    rnd32 = lambda emu, k: r.getrandbits(32)
    LIM = struct.unpack('<f', c.emu.rbytes(0x678858, 4))[0]
    def fl(emu, a, n=3):
        return emu.rbytes(a, 4 * n).hex()
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    n = r.choice([1, 2, 2, 3, 4])
    PB = rnd(c, 16 * n + 0x80)
    pts = PB + 0x40
    for q in range(16 * n + 0x20):
        pass
    for i in range(n):
        for off in (4, 8, 0xc, 0x14, 0x18, 0x1c):
            c.emu.wbytes(pts + 16 * i + off, struct.pack('<f', r.uniform(-50, 50)))
    P = rnd(c, 0x30)
    c.emu.w32(P + 8, n)
    c.emu.w32(P + 0xc, pts)
    c.emu.w32(P + 4, r.getrandbits(32))
    c.emu.w32(P + 0x10, r.choice([0, rnd(c, 0x20)]))
    c.emu.w32(P + 0x14, r.choice([0, rnd(c, 0x20)]))
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    if r.random() < 0.5: c.emu.wbytes(T + 0x2d, b'\0\0\0\0')
    else: c.emu.wbytes(T + 0x2d, b'\x01\0\0\0')
    hook_rec(c, 0x52b9d0, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('b9d0', emu.reg('ecx') == T)), _s(emu, k)))
    errp = 0.12 if n > 1 else 0.3
    outs = [-1.0, 0.0, 0.25, LIM * 0.5, LIM, LIM * 2, 3.0]
    rrs = [rnd(c, 0x40) for _ in range(4)]
    def mk852(j, nm, errprob):
        def sd(emu, k, _s=mkside(j)):
            emu.calllog.append((nm, emu.reg('ecx') == T, fl(emu, emu.arg32(0)), fl(emu, emu.arg32(1))))
            _s(emu, k)
        def retf(emu, k):
            return 0 if r.random() < errprob else r.choice(rrs)
        def ssd(emu, k):
            emu.wbytes(emu.arg32(2), struct.pack('<f', r.choice(outs)))
            sd(emu, k)
        return ssd, retf
    ssd, retf = mk852(1, 'a970', 0.0)
    hook_rec(c, 0x52a970, 3, ret=lambda emu, k: 1 if r.random() < errp else 0, pop=12, this=True, stackmark=(0, 1, 2), side=ssd)
    ssd, retf = mk852(2, 'a850', 0.25)
    hook_rec(c, 0x52a850, 3, ret=retf, pop=12, this=True, stackmark=(0, 1, 2), side=ssd)
    for rr in rrs: c.emu.w32(rr + 0x30, r.getrandbits(32))
    def s43(emu, k, _s=mkside(3)):
        emu.calllog.append(('43e', fl(emu, emu.reg('edx')), fl(emu, emu.arg32(0))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))
        _s(emu, k)
    hook_rec(c, 0x43e920, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=s43)
    def s45(emu, k, _s=mkside(4)):
        emu.calllog.append(('451', fl(emu, emu.reg('ecx')), fl(emu, emu.reg('edx')), emu.arg32(0)))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))
        _s(emu, k)
    hook_rec(c, 0x451890, 1, ret=rnd32, pop=4, this='mark', side=s45)
    def s4e(emu, k, _s=mkside(5)):
        emu.calllog.append(('4e0', fl(emu, emu.reg('ecx')), fl(emu, emu.reg('edx'))))
        _s(emu, k)
    hook_rec(c, 0x4e0870, 0, ret=rnd32, pop=0, this='mark', st0=lambda emu, k: r.uniform(0, 20), side=s4e)
    NS = []
    def s476(emu, k, _s=mkside(6)):
        emu.calllog.append(('476', emu.arg32(0), emu.reg('ecx') != 0))
        _s(emu, k)
    def r476(emu, k):
        cnt = emu.arg32(0)
        o = rnd(c, 0x30)
        if cnt > 0x80: cnt = 0x80
        c.emu.w32(o + 0xc, rnd(c, 16 * (cnt + 2) + 0x40))
        c.emu.w32(o + 0x10, rnd(c, 4 * (cnt + 2) + 0x10))
        NS.append(o)
        return o
    hook_rec(c, 0x476dc0, 1, ret=r476, pop=4, this=True, side=s476)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, 0x20), pop=0, this=False, side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('alloc', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x41e2c0, 1, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('f2c0', emu.arg32(0) - pts)), _s(emu, k)))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('free', emu.arg32(0) == P, emu.arg32(1))), _s(emu, k)))
    def s2c(emu, k, _s=mkside(10)):
        emu.calllog.append(('log', emu.arg32(1)))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, P]


def g5e94c0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj, reftab_vt
    TS = 0x1d40
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(20)]
    def cstr(emu, a, lim=0x40):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS)), zlib.crc32(emu.rbytes(RC, 0x3d0))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    objs = []
    def idx(emu):
        o = emu.reg('ecx')
        return objs.index(o) if o in objs else -1
    def mk0(name, j, n, pop, retf=None):
        def sd(emu, k, _s=mkside(j)):
            emu.calllog.append((name, idx(emu), [emu.arg32(i) for i in range(n)]))
            _s(emu, k)
        return pystub(c, n, ret=(retf or rnd32), pop=pop, this=True, side=sd)
    # name objects
    names = []
    for i in range(3):
        nm = rnd(c, 0x20); c.emu.wbytes(nm, bytes(r.randrange(97, 123) for _ in range(r.choice([1, 4]))) + b'\0')
        no = rnd(c, 0x10); c.emu.w32(no + 4, r.choice([0, nm, nm]))
        names.append(no)
    pskip = r.choice([0.1, 0.3])
    OV = {0x1e0: mk0('1e0', 0, 1, 4, lambda emu, k: 1 if r.random() < pskip else r.choice([0, 0x100])),
          0x2e8: mk0('2e8', 1, 0, 0, lambda emu, k: r.choice(names)),
          0x35c: mk0('35c', 2, 0, 0)}
    def newo():
        o = obj(c, 0x40, OV); objs.append(o); return o
    elems = [rnd(c, 0x10) for _ in range(r.choice([0, 1, 2, 4, 6, 8]))]
    omap = {e: newo() for e in elems}
    LV = reftab_vt(c, list(elems))
    lastc = [0]
    def ctorL(emu, k, _s=mkside(3)):
        lastc[0] = emu.reg('ecx')
        emu.w32(emu.reg('ecx'), LV)
        _s(emu, k)
    hook_rec(c, 0x4ccba0, 0, ret=rnd32, pop=0, this='mark', side=ctorL)
    hook_rec(c, 0x4ccf60, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('dt', emu.reg('ecx') - lastc[0])), _s(emu, k)))
    def sm(emu, k, _s=mkside(5)):
        emu.calllog.append(('memset', emu.arg32(1), emu.arg32(2)))
        emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
        _s(emu, k)
    hook_rec(c, 0x634d10, 3, ret=rnd32, pop=0, this=False, stackmark=(0,), side=sm)
    def m58(emu, k, _s=mkside(6)):
        emu.calllog.append(('m58', elems.index(emu.arg32(0)) if emu.arg32(0) in elems else -1))
        _s(emu, k)
    so = sysobj(c, slots={}, table_slots={0x58: pystub(c, 1, ret=lambda emu, k: omap.get(emu.arg32(0), 0), pop=4, this=True, side=m58)}, table_size=0x40)
    QV = obj(c, 0x20, {0x320: mk0('320', 7, 0, 0)})
    objs.append(QV)
    MM = obj(c, 0x600, {0x55c: mk0('55c', 8, 1, 4, lambda emu, k: r.choice([0, QV, QV]))})
    def s130(emu, k, _s=mkside(9)):
        emu.calllog.append(('130', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    CO = obj(c, 0x200, {0x130: pystub(c, 3, ret=rnd32, pop=12, this=True, stackmark=(2,), side=s130)})
    RC = rnd(c, 0x3d0)
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.w32(T + 0x44, CO)
    c.emu.w32(T + 0x1d0b, MM)
    c.emu.w32(T + 0x1d0f, r.choice([0, RC, RC]))
    def scmp(emu, k, _s=mkside(10)):
        emu.calllog.append(('cmp', cstr(emu, emu.arg32(0)).hex(), emu.arg32(1)))
        _s(emu, k)
    pz = r.choice([0.12, 0.25, 0.4])
    c.emu.w32(0x676414, pystub(c, 2, ret=lambda emu, k: 0 if r.random() < pz else 1, pop=0, this=False, side=scmp))
    return [T]


def g49cda0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    from recruits_util import obj, sysobj
    TS = 0x80
    T = rnd(c, TS)
    CNT = rnd(c, 0x10)
    sr = [seh_record(c, 2) for _ in range(40)]
    def cstr(emu, a, lim=0x40):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS)), emu.r32(CNT)))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    def rf(n): return b''.join(struct.pack('<f', r.uniform(-9, 9)) for _ in range(n))
    def hx(emu, a, n): return emu.rbytes(a, n).hex()
    many = r.random() < 0.3
    lastR = [0]; lastS = [0]
    nodes = []
    def nid(emu, o): return nodes.index(o) if o in nodes else -1
    sib = {}; inext = {}; gnext = {}
    masks = {}
    def mk1e0(emu, k):
        o = emu.reg('ecx'); m = emu.arg32(0)
        if many and m in (0x800024, 0x800023, 0x800020): return 0
        d = masks.setdefault(o, {})
        if m not in d: d[m] = r.random() < 0.5 if m != 0x100021 else d.get(m, r.random() < 0.4)
        return 1 if d[m] else 0
    def s1e0(emu, k, _s=mkside(0)):
        emu.calllog.append(('1e0', nid(emu, emu.reg('ecx')), emu.arg32(0)))
        _s(emu, k)
    def s20(emu, k, _s=mkside(1)):
        emu.calllog.append(('20', nid(emu, emu.reg('ecx'))))
        _s(emu, k)
    def s94(emu, k, _s=mkside(2)):
        emu.calllog.append(('94', nid(emu, emu.reg('ecx')), hx(emu, emu.arg32(0), 36), hx(emu, emu.arg32(1), 12)))
        _s(emu, k)
    def s8c(emu, k, _s=mkside(3)):
        emu.calllog.append(('8c', nid(emu, emu.reg('ecx')), hx(emu, emu.arg32(0), 12)))
        _s(emu, k)
    def s50(emu, k, _s=mkside(4)):
        out = emu.arg32(0); cur = emu.r32(out)
        emu.w32(out, gnext.get(cur, 0))
        emu.calllog.append(('50', nid(emu, emu.reg('ecx')), nid(emu, cur)))
        _s(emu, k)
    VT = {0x1e0: pystub(c, 1, ret=mk1e0, pop=4, this=True, side=s1e0),
          0x20: pystub(c, 0, ret=lambda emu, k: sib.get(emu.reg('ecx'), 0), pop=0, this=True, side=s20),
          0x94: pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(0, 1), side=s94),
          0x8c: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s8c),
          0x50: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s50)}
    def newn():
        o = obj(c, 0xa0, VT); nodes.append(o); return o
    def newF(kind):
        F = rnd(c, 0x40); c.emu.w32(F + 0x23, kind & 0xffffffff)
        d = rnd(c, 0x20); c.emu.w32(d + 0xc, F)
        return d
    kinds = [0x80000d, 0x100000, 0x200002, 0x80000d, 0x55]
    def mk_inner():
        ids = [rnd(c, 0x60) for _ in range(r.choice([0, 1, 2]))]
        for i, cc in enumerate(ids):
            c.emu.w32(cc + 0x54, newF(r.choice(kinds)) if r.random() < 0.85 else 0)
            inext[cc] = ids[i + 1] if i + 1 < len(ids) else 0
        return ids[0] if ids else 0
    # chain A
    na = r.choice([1, 2, 3])
    A_ = [newn() for _ in range(na)]
    for i, a in enumerate(A_):
        sib[a] = A_[i + 1] if i + 1 < na else 0
        c.emu.w32(a + 0x54, mk_inner())
        masks[a] = {0x100021: (i == na - 1) or r.random() < 0.3}
    # G chain per a (only found one used)
    def mk_G():
        ng = 10 if many else r.choice([0, 1, 2, 3, 3, 10])
        gs = [rnd(c, 0x60) for _ in range(ng)]
        for j, g in enumerate(gs):
            gnext[g] = gs[j + 1] if j + 1 < ng else 0
            if r.random() < 0.9:
                e = newn()
                ec = rnd(c, 0x80)
                c.emu.w32(e + 8, ec)
                Fe = rnd(c, 0x40); c.emu.w32(Fe + 0x23, (r.getrandbits(32) | 0x800000) if (many or r.random() < 0.8) else (r.getrandbits(32) & ~0x800000))
                c.emu.w32(e + 0xc, Fe)
                # children chain
                ch = [newn() for _ in range(0 if many else r.choice([0, 0, 1, 2]))]
                for q, cc in enumerate(ch):
                    sib[cc] = ch[q + 1] if q + 1 < len(ch) else 0
                    Fc = rnd(c, 0x40); c.emu.w32(Fc + 0x23, 0x1000ea if r.random() < 0.15 else r.getrandbits(32))
                    c.emu.w32(cc + 0xc, Fc)
                sib[e] = ch[0] if ch else 0
                c.emu.w32(g + 0x54, e)
            else:
                c.emu.w32(g + 0x54, 0)
        return gs[0] if gs else 0
    for a in A_:
        c.emu.w32(a + 8, mk_G())
    OBJ = rnd(c, 0xa0)
    c.emu.w32(OBJ + 0x54, A_[0]); c.emu.w32(OBJ + 0x6c, r.getrandbits(32))
    nodes.append(OBJ)
    hook_rec(c, 0x4db520, 0, ret=lambda emu, k: inext.get(emu.reg('ecx'), 0), pop=0, this=True, side=lambda emu, k, _s=mkside(5): (emu.calllog.append(('db520',)), _s(emu, k)))
    # helpers writing outputs
    def wr(addr, n): c.emu.wbytes(addr, rf(n // 4))
    hook_rec(c, 0x4ccbe0, 2, ret=rnd32, pop=8, this='mark', side=lambda emu, k, _s=mkside(6): (lastR.__setitem__(0, emu.reg('ecx')), emu.calllog.append(('ccbe0', emu.arg32(0), emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x4de7a0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(7): (emu.wbytes(emu.reg('ecx'), rf(9)), _s(emu, k)))
    hook_rec(c, 0x4db7c0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(8): (emu.wbytes(emu.arg32(0), rf(3)), _s(emu, k)))
    def s6c0(emu, k, _s=mkside(9)):
        emu.calllog.append(('b6c0', hx(emu, emu.arg32(0), 36)))
        emu.wbytes(emu.arg32(1), rf(3)); emu.wbytes(emu.arg32(0), rf(9))
        _s(emu, k)
    hook_rec(c, 0x4db6c0, 2, ret=rnd32, pop=8, this=True, stackmark=(0, 1), side=s6c0)
    hook_rec(c, 0x4daf90, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(10): (emu.wbytes(emu.arg32(0), rf(3)), _s(emu, k)))
    def s670(emu, k, _s=mkside(11)):
        emu.calllog.append(('b670', hx(emu, emu.arg32(0), 12)))
        emu.wbytes(emu.arg32(0), rf(3))
        _s(emu, k)
    hook_rec(c, 0x4db670, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s670)
    def s420(emu, k, _s=mkside(12)):
        emu.calllog.append(('de420', hx(emu, emu.reg('edx'), 36)))
        emu.wbytes(emu.reg('ecx'), rf(9))
        _s(emu, k)
    hook_rec(c, 0x4de420, 0, ret=rnd32, pop=0, this='mark', side=s420)
    def s330(emu, k, _s=mkside(13)):
        ec = emu.reg('ecx')
        emu.calllog.append(('df330', nid(emu, ec), emu.reg('edx') - ec, emu.arg32(0) - ec, hx(emu, emu.arg32(1), 36), hx(emu, emu.arg32(2), 12), hx(emu, emu.arg32(3), 12)))
        _s(emu, k)
    pok = r.choice([0.3, 0.6, 0.9])
    hook_rec(c, 0x4df330, 4, ret=lambda emu, k: 1 if (many or r.random() < pok) else 0, pop=16, this=True, stackmark=(1, 2, 3), side=s330)
    def mkfl(addr, n, pop, j, nm):
        def sd(emu, k, _s=mkside(j)):
            emu.calllog.append((nm, hx(emu, emu.reg('ecx'), 36), hx(emu, emu.reg('edx'), 12), [emu.arg32(i) for i in range(n - 1)]))
            _s(emu, k)
        hook_rec(c, addr, n, ret=lambda emu, k: 1 if r.random() < 0.6 else 0, pop=pop, this='mark', stackmark=(n - 1,), side=sd)
    mkfl(0x49b9a0, 2, 8, 14, 'b9a0'); mkfl(0x49bbc0, 3, 12, 15, 'bbc0'); mkfl(0x49be80, 4, 16, 16, 'be80')
    # container slots
    def cslot(nm, j, n, pop, size):
        def sd(emu, k, _s=mkside(j)):
            emu.calllog.append((nm, emu.arg32(0)))
            if size: emu.wbytes(emu.arg32(1), rf(size // 4))
            _s(emu, k)
        return pystub(c, n, ret=rnd32, pop=pop, this=True, stackmark=((1,) if size else (0,)), side=sd)
    c1 = obj(c, 0xa0, {0x54: pystub(c, 1, ret=lambda emu, k: r.choice([0, 1]), pop=4, this=True, side=lambda emu, k, _s=mkside(17): (emu.calllog.append(('c54', emu.arg32(0))), _s(emu, k))),
                       8: pystub(c, 3, ret=rnd32, pop=12, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(18): (emu.calllog.append(('c8', emu.arg32(1), emu.arg32(2))), _s(emu, k))),
                       0x80: cslot('c80', 19, 2, 8, 0x20), 0x84: cslot('c84', 20, 2, 8, 0x30), 0x88: cslot('c88', 21, 2, 8, 0x3c)})
    o1 = rnd(c, 0x30); c.emu.w32(o1 + 0x18, c1)
    so = sysobj(c, slots={}, table_slots={}, table_size=0x40)
    SO = rnd(c, 0x1b00); c.emu.w32(SO + 0x1aa3, o1)
    c.emu.w32(0x70039c, c.emu.r32(so))  # keep vtable; fields replaced below
    # make 0x70039c point at an object with both +0x9b table and +0x1aa3
    c.emu.w32(SO, c.emu.r32(so)); c.emu.w32(SO + 0x9b, c.emu.r32(so + 0x9b)); c.emu.w32(0x70039c, SO)
    SB = rnd(c, 0x20); c.emu.wbytes(SB, bytes(r.randrange(65, 90) for _ in range(r.choice([0, 3]))) + b'\0')
    RS = rnd(c, 0x10); c.emu.w32(RS, SB)
    hook_rec(c, 0x4da2f0, 2, ret=lambda emu, k: RS, pop=8, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(22): (lastS.__setitem__(0, emu.arg32(0)), emu.calllog.append(('a2f0', nid(emu, emu.reg('ecx')), emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(23): (emu.calllog.append(('dtS', emu.reg('ecx') == lastS[0], emu.reg('ecx') == lastR[0])), _s(emu, k)))
    hook_rec(c, 0x4ccfe0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(24): (emu.calllog.append(('dtR', emu.reg('ecx') - lastR[0])), _s(emu, k)))
    def s30(emu, k, _s=mkside(25)):
        emu.calllog.append(('log', emu.arg32(1), cstr(emu, emu.arg32(2)).hex()))
        _s(emu, k)
    LO = obj(c, 0x40, {0x30: pystub(c, 3, ret=rnd32, pop=0, this=False, side=s30)})
    def s20l(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20l, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    if r.random() < 0.07: return [T, CNT, 0]
    return [T, CNT, OBJ]


def g5e9e20(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    from recruits_util import obj, sysobj
    TS = 0x2400
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(30)]
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS))))
            sr[j](emu, k)
        return side
    rnd32 = lambda emu, k: r.getrandbits(32)
    nn = r.choice([0, 1, 2, 3, 5])
    cnt = {'v40': 0}
    def rel(emu, a): return a - T if T <= a < T + TS else (-2 if a == 0 else -1)
    def mkst(name, slot, width, j):
        def sd(emu, k, _s=mkside(j)):
            dst = emu.arg32(0)
            if slot == 0x40:
                kk = cnt['v40']; cnt['v40'] += 1
                if kk == 142: b = nn.to_bytes(4, 'little')
                else: b = bytes(r.getrandbits(8) for _ in range(width))
            else:
                b = bytes(r.getrandbits(8) for _ in range(width))
            emu.wbytes(dst, b)
            emu.calllog.append((name, rel(emu, dst), zlib.crc32(b)))
            _s(emu, k)
        return pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=sd)
    def s18(emu, k, _s=mkside(5)):
        dst = emu.arg32(0); nb = emu.arg32(1)
        b = bytes(r.getrandbits(8) for _ in range(nb))
        emu.wbytes(dst, b)
        emu.calllog.append(('s18', rel(emu, dst), nb, zlib.crc32(b)))
        _s(emu, k)
    SV = {0x40: mkst('s40', 0x40, 4, 0), 0x48: mkst('s48', 0x48, 4, 1), 0x50: mkst('s50', 0x50, 4, 2), 0x68: mkst('s68', 0x68, 1, 3), 0x6c: mkst('s6c', 0x6c, 12, 4),
          0x18: pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(0,), side=s18)}
    S = obj(c, 0x20, SV)
    def m58(emu, k, _s=mkside(6)):
        emu.calllog.append(('m58', emu.arg32(0)))
        _s(emu, k)
    so = sysobj(c, slots={}, table_slots={0x58: pystub(c, 1, ret=lambda emu, k: rnd(c, 0x20), pop=4, this=True, side=m58)}, table_size=0x40)
    # vector at T+0x1da2
    ARR = rnd(c, 0x60)
    sz = r.choice([0, 0, 1, 2, 3]); cap = sz + r.choice([0, 1, 4])
    for i in range(sz): c.emu.w32(ARR + 4 * i, r.getrandbits(32))
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    if r.random() < 0.15:
        c.emu.w32(T + 0x1da2, 0); c.emu.w32(T + 0x1da6, 0); c.emu.w32(T + 0x1daa, 0)
    else:
        c.emu.w32(T + 0x1da2, ARR); c.emu.w32(T + 0x1da6, ARR + 4 * sz); c.emu.w32(T + 0x1daa, ARR + 4 * cap)
    objs = []
    def sh(emu): return objs.index(emu.reg('ecx')) if emu.reg('ecx') in objs else -1
    def al(emu, k, _s=mkside(7)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    def alr(emu, k):
        if emu.arg32(0) in (0x10, 0x29, 0x4c) and r.random() < 0.15: return 0
        o = rnd(c, 0x60); objs.append(o); return o
    hook_rec(c, 0x41e290, 1, ret=alr, pop=0, this=False, side=al)
    def s6014(emu, k, _s=mkside(8)):
        emu.calllog.append(('6014', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x6014a0, 1, ret=lambda emu, k: rnd(c, 0x60), pop=4, this=True, side=s6014)
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this=True, side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('54', emu.reg('ecx') - T, emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x5b7dd0, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0, this=True, side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('7dd0', sh(emu))), _s(emu, k)))
    hook_rec(c, 0x5b7bd0, 0, ret=lambda emu, k: emu.reg('ecx'), pop=0, this=True, side=lambda emu, k, _s=mkside(11): (emu.calllog.append(('7bd0', sh(emu))), _s(emu, k)))
    hook_rec(c, 0x5b7c00, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(12): (emu.calllog.append(('7c00', sh(emu))), _s(emu, k)))
    hook_rec(c, 0x5b7e40, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('7e40', sh(emu))), _s(emu, k)))
    hook_rec(c, 0x5eaab0, 2, ret=lambda emu, k: rnd(c, 0x20), pop=8, this=True, side=lambda emu, k, _s=mkside(14): (emu.calllog.append(('eaab0', sh(emu), emu.arg32(1))), _s(emu, k)))
    hook_rec(c, 0x5fe3b0, 2, ret=rnd32, pop=8, this=True, stackmark=(1,), side=lambda emu, k, _s=mkside(15): (emu.calllog.append(('fe3b0', emu.reg('ecx') - T, emu.arg32(0), sh(type('X', (), {'reg': lambda s_, n: emu.r32(emu.arg32(1))})()))), _s(emu, k)))
    c.emu.w32(0x7003b0, 0)
    hook_rec(c, 0x59a6e0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=lambda emu, k, _s=mkside(16): (emu.calllog.append(('a6e0', emu.reg('ecx') == T, emu.r32(emu.arg32(0)))), _s(emu, k)))
    def s6352(emu, k, _s=mkside(17)):
        emu.w32(emu.arg32(0), r.getrandbits(32))
        emu.calllog.append(('6352',))
        _s(emu, k)
    hook_rec(c, 0x6352f0, 1, ret=rnd32, pop=4, this=False, stackmark=(0,), side=s6352)
    return [T, S]


def g4e6910(c):
    clear_hooks(c)
    r = c.rng
    import zlib, struct
    from recruits_util import rnd
    import pe_emu
    TLS = rnd(c, 0x40)
    idx = r.randrange(0, 8)
    pobj = rnd(c, 0x20)
    c.emu.w32(pe_emu.TEB + 0x2c, TLS)
    c.emu.w32(0x7257d4, idx)
    c.emu.w32(TLS + 4 * idx, pobj)
    c.emu.w32(pobj + 4, r.choice([0, 1, 3, 0xfffffffe, r.getrandbits(32)]))
    c.emu.w32(0x700564, r.choice([0, 1, 2, 5, 0xffffffff, 0x80000000, r.getrandbits(32)]))
    c.emu.wbytes(0x700560, struct.pack('<f', r.uniform(-4, 4)))
    def sd(emu, k):
        emu.calllog.append(('hdr', emu.r32(0x700564)))
        emu.w32(emu.arg32(0), r.choice([0xffffffff, 0xffffffff, 0, 7]))
    hook_rec(c, 0x63456a, 1, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=sd)
    def sf(emu, k):
        emu.calllog.append(('ftr', emu.r32(0x700564)))
        emu.w32(emu.arg32(0), r.choice([1, 2, 3]))
    hook_rec(c, 0x63452b, 1, ret=lambda emu, k: r.getrandbits(32), pop=0, this=False, side=sf)
    fl = r.choice([r.uniform(0.001, 50.0), r.uniform(-5, 5), 0.0, 1.0, 1e-30])
    return [struct.unpack('<I', struct.pack('<f', fl))[0]]


def g48c6c0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    from recruits_util import obj, sysobj, reftab_vt
    TS = 0x1d80
    import recruits_util as _ru
    HEAPLO = _ru.HEAP_LO; HEAPHI = _ru.HEAP_HI
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
    objs = []
    MG8 = [0]; C8 = [0]
    def idx(emu):
        o = emu.reg('ecx'); return objs.index(o) if o in objs else (('T', o - T) if T <= o < T + TS else (('M8', o - MG8[0]) if MG8[0] and 0 <= o - MG8[0] < 16 else (('C8', o - C8[0]) if C8[0] and 0 <= o - C8[0] < 16 else -1)))
    def mk(name, j, n, pop, retf=None, st0=None, stackmark=(), wr=0):
        def sd(emu, k, _s=mkside(j)):
            emu.calllog.append((name, idx(emu), [(emu.arg32(i) if HEAPLO <= emu.arg32(i) < HEAPHI else 'S') if i in stackmark else emu.arg32(i) for i in range(n)]))
            if wr: emu.wbytes(emu.arg32(0), b''.join(struct.pack('<f', r.uniform(-3, 3)) for _ in range(wr)))
            _s(emu, k)
        return pystub(c, n, ret=(retf or rnd32), pop=pop, this=True, stackmark=stackmark, side=sd, **({'st0': st0} if st0 else {}))
    # string objects
    def mkstr():
        sp = rnd(c, 0x20); c.emu.wbytes(sp, bytes(r.randrange(97, 123) for _ in range(r.choice([0, 3, 6]))) + b'\0')
        so = rnd(c, 0x10); c.emu.w32(so, sp); return so
    SO1 = mkstr(); SO2 = mkstr(); SO3 = mkstr()
    PV = obj(c, 0x20, {0x1dc: mk('p1dc', 0, 2, 8, lambda emu, k: SO1, stackmark=(0,))}); objs.append(PV)
    pyes = r.random() < 0.5
    OV = {0x240: mk('o240', 1, 1, 4, stackmark=(0,), wr=4), 0x84: mk('o84', 2, 1, 4, stackmark=(0,)),
          0x24c: mk('o24c', 3, 0, 0, lambda emu, k: r.choice([0, PV, PV])), 0x1dc: mk('o1dc', 4, 2, 8, lambda emu, k: SO2, stackmark=(0,)),
          0x258: mk('o258', 5, 1, 0, lambda emu, k: 1 if r.random() < 0.5 else 0)}
    def newo():
        o = obj(c, 0x20, OV); objs.append(o); return o
    ne = r.choice([0, 1, 2, 3])
    elems = [rnd(c, 0x10) for _ in range(ne)]
    omap = {}
    for e in elems:
        k_ = r.getrandbits(32); c.emu.w32(e, k_); omap[k_] = newo()
    LV0 = reftab_vt(c, list(elems))
    LV = c.emu.alloc(0xb0, 4)
    c.emu.wbytes(LV, c.emu.rbytes(LV0, 0x80))
    c.emu.w32(LV + 0x9c, pystub(c, 1, ret=0, pop=4, this=True, st0=lambda emu, k: r.uniform(-5, 5), side=mkside(6)))
    c.emu.w32(LV + 0x5c, mk('l5c', 34, 1, 4, lambda emu, k: elems[0] if elems else 0)); c.emu.w32(LV + 0x54, mk('l54', 35, 1, 4))
    LIST = rnd(c, 0x20); c.emu.w32(LIST, LV)
    m58 = mk('m58', 7, 1, 4, lambda emu, k: omap.get(emu.arg32(0), 0))
    L1 = obj(c, 0x80, {0x98: mk('l98', 8, 0, 0, lambda emu, k: r.choice([0, LIST, LIST])), 0x90: mk('l90', 9, 1, 4)})
    objs.append(L1)
    mt = {0x58: m58, 0x138: mk('m138', 10, 0, 0), 0x114: mk('m114', 11, 5, 20, lambda emu, k: r.getrandbits(16))}
    so = sysobj(c, slots={0x14: mk('s14', 12, 0, 0)}, table_slots=mt, table_size=0x40)
    SO_ = rnd(c, 0x2000); c.emu.w32(SO_, c.emu.r32(so)); c.emu.w32(SO_ + 0x9b, c.emu.r32(so + 0x9b)); c.emu.w32(SO_ + 0x190f, L1)
    c.emu.wbytes(SO_ + 0x6f, struct.pack('<ii', r.randrange(1, 2000), r.randrange(1, 2000)))
    MG = c.emu.r32(SO_ + 0x9b); MG8[0] = rnd(c, 0x20); c.emu.w32(MG + 8, MG8[0])
    c.emu.w32(0x70039c, SO_)
    E4 = obj(c, 0x20, {0x70: mk('e70', 13, 0, 0), 0x74: mk('e74', 14, 1, 4, lambda emu, k: r.choice([0, 0, 5, 7]) if emu.arg32(0) == 0 else r.choice([0, 5, 9]))})
    c.emu.w32(0x7003a4, r.choice([0, E4, E4])); objs.append(E4)
    E5 = obj(c, 0x20, {0x10: mk('e10', 15, 0, 0)}); c.emu.w32(0x7003ac, E5)
    # this
    OBJ = obj(c, 0x20, {0x20c: mk('t20c', 16, 2, 8), 0x12c: mk('t12c', 17, 2, 8)}); objs.append(OBJ)
    EMB_V = c.emu.alloc(0x20, 4); c.emu.w32(EMB_V + 0x10, mk('emb10', 18, 0, 0))
    TV = c.emu.alloc(0x100, 4)
    for off, nm, j in ((0xb0, 'tb0', 19), (0xa4, 'ta4', 20), (0xa0, 'ta0', 21)):
        c.emu.w32(TV + off, mk(nm, j, 1 if off == 0xa0 else 0, 4 if off == 0xa0 else 0, lambda emu, k: SO3 if False else r.getrandbits(32)))
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.w32(T, TV); c.emu.w32(T + 0xadc, r.choice([0, OBJ, OBJ])); C8[0] = rnd(c, 0x20); c.emu.w32(T + 0xc8, C8[0]); c.emu.w32(T + 0x1c61, EMB_V)
    objs.append(T)
    LO = None
    def s2c(emu, k, _s=mkside(22)):
        import traceback
        try: return s2c_(emu, k, _s)
        except Exception: traceback.print_exc(); raise
    def s2c_(emu, k, _s):
        fmt = emu.arg32(1); sp = emu.reg('esp') + 4
        extra = []
        if fmt == 0x68dd18:
            extra = [cstr(emu, emu.r32(sp + 8)).hex(), cstr(emu, emu.r32(sp + 12)).hex(), emu.rbytes(sp + 16, 40).hex(), cstr(emu, emu.r32(sp + 56)).hex()]
        elif fmt == 0x677368: extra = [emu.r32(sp + 8)]
        elif fmt == 0x68dea0: extra = [cstr(emu, emu.r32(sp + 8)).hex() if emu.r32(sp + 8) > 0x1000 else emu.r32(sp + 8), emu.r32(sp + 12)]
        emu.calllog.append(('log', fmt, extra))
        _s(emu, k)
    LO = obj(c, 0x40, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    p0 = r.choice([0.15, 0.3, 0.5])
    def scmp(emu, k, _s=mkside(23)):
        emu.calllog.append(('cmp', cstr(emu, emu.arg32(0)).hex(), emu.arg32(1)))
        _s(emu, k)
    tgt = r.randrange(0, 26)
    cc = [0]
    def cret(emu, k):
        n_ = cc[0]; cc[0] += 1
        if emu.r32(T + 0xadc) == 0 and emu.arg32(1) in (0x68db3c, 0x68db14): return 1
        return 0 if (n_ == tgt or (n_ < tgt and False)) else 1
    c.emu.w32(0x676414, pystub(c, 2, ret=cret, pop=0, this=False, side=scmp))
    def cret3(emu, k):
        n_ = cc[0]; cc[0] += 1
        return 0 if n_ == tgt else 1
    def sn(emu, k, _s=mkside(24)):
        emu.calllog.append(('ncmp', cstr(emu, emu.arg32(0)).hex(), emu.arg32(1), emu.arg32(2)))
        _s(emu, k)
    c.emu.w32(0x676408, pystub(c, 3, ret=cret3, pop=0, this=False, side=sn))
    c.emu.w32(0x6762d8, pystub(c, 1, ret=lambda emu, k: r.choice([0, 3, 7]), pop=0, this=False, side=lambda emu, k, _s=mkside(25): (emu.calllog.append(('atoi', cstr(emu, emu.arg32(0)).hex())), _s(emu, k))))
    c.emu.w32(0x676374, pystub(c, 1, ret=rnd32, pop=4, this=False, side=lambda emu, k, _s=mkside(26): (emu.calllog.append(('ex', emu.arg32(0))), _s(emu, k))))
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=lambda emu, k, _s=mkside(27): (emu.calllog.append(('ctorS',)), _s(emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(28): (emu.calllog.append(('dtS',)), _s(emu, k)))
    hook_rec(c, 0x48aad0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k, _s=mkside(29): (emu.calllog.append(('a5d0', emu.r32(emu.reg('ecx') + 4))), _s(emu, k)))
    for ad, j in ((0x496a40, 30), (0x496760, 31), (0x49d480, 32), (0x48f700, 33)):
        hook_rec(c, ad, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(j), ad=ad: (emu.calllog.append((hex(ad), idx(emu))), _s(emu, k)))
    cmd = rnd(c, 0x20); c.emu.wbytes(cmd, bytes(r.randrange(97, 123) for _ in range(r.choice([2, 5, 9]))) + b'\0')
    arg = r.choice([0, mkstr(), mkstr()])
    if arg: arg = c.emu.r32(arg)
    return [T, r.getrandbits(32), cmd, arg]


def g453bf0(c):
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
    DTRI = struct.pack('<fff', r.uniform(-1, 1), r.uniform(-1, 1), r.uniform(-1, 1))
    objs = []
    def idx(emu):
        o = emu.reg('ecx'); return objs.index(o) if o in objs else (('T', o - T) if T <= o < T + TS else -1)
    def mk(name, j, n, pop, retf=None, st0=None, stackmark=(), wr=0, side2=False, big=False):
        def sd(emu, k, _s=mkside(j)):
            if name in ('v84',): emu.calllog.append(('v84c', emu.rbytes(emu.arg32(0), 12).hex()))
            emu.calllog.append((name, idx(emu), [(emu.arg32(i) if _ru.HEAP_LO <= emu.arg32(i) < _ru.HEAP_HI else 'S') if i in stackmark else emu.arg32(i) for i in range(n)]))
            if side2: emu.wbytes(emu.arg32(0), struct.pack('<fff', r.uniform(-0.04, 0.04), r.uniform(-0.04, 0.04), r.choice([-0.998, 0.998, 0.998, -0.998, r.uniform(-1, 1)])))
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
    tap(0x4e29c0, 'tap9c0', [('r', 'edx', 48), ('a', 1, 48), ('a', 3, 12), ('a', 0, 0), ('a', 2, 0)])
    tap(0x4e2bb0, 'tapbb0', [('r', 'ecx', 48), ('r', 'edx', 0)])
    return [T]


def g52e830(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    import recruits_util as _ru
    from recruits_util import obj, sysobj
    em = c.emu
    sr = [seh_record(c, 2) for _ in range(30)]
    rnd32 = lambda emu, k: r.getrandbits(32)
    ft = lambda v: struct.pack('<f', v)
    NR, NE = 6, 5
    TS = 0x9e + 32 * NE + 0x20
    CS = 0x130
    T = rnd(c, TS)
    C = rnd(c, CS)
    RB = rnd(c, 0x15 * NR + 0x10)
    em.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    em.wbytes(C, bytes(r.getrandbits(8) for _ in range(CS)))
    em.wbytes(RB, bytes(r.getrandbits(8) for _ in range(0x15 * NR + 0x10)))
    ref = em.rbytes(0x68af2c, 4)
    em.w32(T + 0x98, RB)
    em.wbytes(T + 5, bytes([r.choice([0, 1, 1])]))
    for off in (6, 0xa, 0xe, 0x12, 0x16, 0x1a):
        em.wbytes(T + off, ft(r.uniform(-30, 30)))
    em.w32(T + 0x38, r.randrange(0, 20))
    nloop = r.choice([0, 1, 2, 3, 4])
    em.w32(T + 0x4c, nloop)
    for off in (0x3c, 0x40, 0x44):
        em.w32(T + off, r.choice([1, 2, 3, 64, 100, 640, 0]) if r.random() < 0.1 else r.choice([1, 2, 3, 64, 100, 640]))
    n96 = r.randrange(0, NR + 1)
    em.wbytes(T + 0x96, struct.pack('<H', n96))
    # record chain
    m = r.choice([0, 1, 1, 2, 2, 3, 4])
    ridx = r.sample(range(1, NR), m) if m else []
    nidx = r.sample(range(NE), min(m, NE)) if m else []
    for i in range(NR):
        rec = RB + 0x15 * i
        if r.random() < 0.6: em.wbytes(rec + 0xa, ref)
        elif r.random() < 0.1: em.w32(rec + 0xa, 0x7fc00000)
        em.wbytes(rec + 4, struct.pack('<HHH', *[r.choice([0, 1, 7, 100, 1000, 0xffff]) if r.random() < 0.4 else r.randrange(0, 1200) for _ in range(3)]))
        em.wbytes(rec + 0xe, struct.pack('<H', 0)); em.wbytes(rec + 0x14, bytes([r.choice([0, 2, 4, 0x80])]))
    for j, ri in enumerate(ridx):
        rec = RB + 0x15 * ri
        nxt = ridx[j + 1] if j + 1 < m else 0
        flag = r.random() < 0.5
        if flag:
            e = nidx[j]
            em.wbytes(rec + 0x14, bytes([r.choice([1, 3, 5, 0x81])]))
            em.wbytes(rec + 0xe, struct.pack('<H', e))
            nd = T + 0x9e + 32 * e
            em.wbytes(nd, struct.pack('<H', nxt))
            for off in (4, 8, 0xc, 0x10, 0x14, 0x18):
                em.wbytes(nd + off, ft(r.uniform(-20, 20)))
        else:
            em.wbytes(rec + 0xe, struct.pack('<H', nxt))
    S0 = ridx[0] if m else 0
    # context
    mode = r.random()
    n0 = mode < 0.06
    P44 = 0
    if n0 or mode < 0.45:
        P44 = rnd(c, 0x20)
        em.wbytes(P44 + 0x10, bytes([1]))
        em.w32(P44, r.choice([0, 100, 5000]))
        em.w32(P44 + 4, r.choice([0, 10, 100, 100000]))
        if r.random() < 0.15 and not n0: em.wbytes(P44 + 0x10, bytes([0]))
    em.w32(C + 0x44, P44)
    tgt = r.randrange(0, 6 + nloop)
    if n0: tgt = r.choice([0, 1, 2, 3])
    em.wbytes(C + 0x49, struct.pack('<I', tgt))
    em.wbytes(C + 0x48, bytes([r.choice([0, 0, 1])]))
    em.wbytes(C + 0x99, bytes([r.choice([0, 1, 1, 1])]))
    em.wbytes(C + 0x107, bytes([r.choice([0, 1])]))
    em.wbytes(C + 0x108, bytes([r.choice([0, 1])]))
    A20 = r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])
    A24 = r.choice([0, 1, 0x100, 0x101, r.getrandbits(32)])
    if n0:
        em.wbytes(C + 0x107, bytes([0])); A24 = r.choice([0, 0x100, 0x200])
        em.wbytes(C + 0x109, struct.pack('<H', 0))
    else:
        em.wbytes(C + 0x109, struct.pack('<H', S0))
    for off in (0xe3, 0xe7, 0xeb, 0xef, 0xf3, 0xf7):
        em.wbytes(C + off, ft(r.uniform(-20, 20)))
    A8 = rnd(c, 16); A12 = rnd(c, 16)
    for q in (A8, A12):
        em.wbytes(q, struct.pack('<fff', r.uniform(-20, 20), r.uniform(-20, 20), r.uniform(-20, 20)))
    A16 = struct.unpack('<I', ft(r.uniform(-5, 50)))[0]
    D = r.getrandbits(32)
    def mkside(j):
        def side(emu, k):
            emu.calllog.append(('t', j, zlib.crc32(emu.rbytes(T, TS)), zlib.crc32(emu.rbytes(C, CS)), zlib.crc32(emu.rbytes(RB, 0x15 * NR))))
            sr[j](emu, k)
        return side
    def rel(v):
        if C <= v < C + CS: return ('C', v - C)
        if T <= v < T + TS: return ('T', v - T)
        if _ru.HEAP_LO <= v < _ru.HEAP_HI: return ('H', 0)
        return ('S', 0)
    def fl(emu, a, n=3):
        return emu.rbytes(a, 4 * n).hex()
    hook_rec(c, 0x531220, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(0): (emu.calllog.append(('1220', emu.reg('ecx') == T)), _s(emu, k)))
    def rb0(emu, k):
        return (r.getrandbits(24) << 8) | (1 if r.random() < 0.08 else 0)
    hook_rec(c, 0x52b0c0, 0, ret=rb0, pop=0, this=True, side=lambda emu, k, _s=mkside(1): (emu.calllog.append(('b0c0', emu.reg('ecx') == C)), _s(emu, k)))
    hook_rec(c, 0x52b080, 0, ret=rnd32, pop=0, this=True, side=lambda emu, k, _s=mkside(2): (emu.calllog.append(('b080', emu.reg('ecx') == C)), _s(emu, k)))
    def s0ca0(emu, k, _s=mkside(3)):
        emu.calllog.append(('ca0', emu.rbytes(emu.reg('ecx'), 12).hex() if True else 0, [rel(emu.arg32(i)) for i in range(3)]))
        _s(emu, k)
    pr = 0.1
    hook_rec(c, 0x530ca0, 3, ret=lambda emu, k: 0 if r.random() < pr else r.getrandbits(32) | 1, pop=12, this='mark', side=s0ca0)
    def ax_ret(emu, k):
        x = r.random()
        v = 0xffff if x < 0.06 else (0 if x < 0.12 else r.randrange(1, 0xffff))
        return (r.getrandbits(16) << 16) | v
    def s130(emu, k, _s=mkside(4)):
        emu.calllog.append(('130', emu.reg('ecx') == T, [rel(emu.arg32(0)), rel(emu.arg32(1))], emu.arg32(2), emu.arg32(3), emu.arg32(4), emu.arg32(5)))
        _s(emu, k)
    hook_rec(c, 0x530130, 6, ret=ax_ret, pop=24, this=True, side=s130)
    def s2b0(emu, k, _s=mkside(5)):
        emu.calllog.append(('2b0', emu.reg('ecx') == T, [rel(emu.arg32(0)), rel(emu.arg32(1)), rel(emu.arg32(4))], emu.arg32(2), emu.arg32(3), emu.arg32(5)))
        _s(emu, k)
    def r2b0(emu, k):
        x = r.random()
        v = 0xffff if x < 0.05 else (0 if x < 0.1 else S0)
        return (r.getrandbits(16) << 16) | v
    hook_rec(c, 0x52f2b0, 6, ret=r2b0, pop=24, this=True, side=s2b0)
    NS = []
    def n_alloc(emu, k):
        if n0: return 0
        return rnd(c, 0x30)
    hook_rec(c, 0x41e290, 1, ret=n_alloc, pop=0, this=False, side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('alloc', emu.arg32(0))), _s(emu, k)))
    def r476(emu, k):
        o = emu.reg('ecx')
        em.w32(o + 0xc, rnd(c, 16 * 80 + 0x40))
        em.w32(o + 0x10, rnd(c, 4 * 80 + 0x10))
        em.w32(o + 0x14, rnd(c, 4 * 80 + 0x10))
        NS.append(o)
        import os
        if os.environ.get('DBG'): print('N', hex(o), hex(em.r32(o+0xc)), hex(em.r32(o+0x10)), hex(em.r32(o+0x14)))
        return o
    hook_rec(c, 0x476dc0, 1, ret=r476, pop=4, this=True, side=lambda emu, k, _s=mkside(7): (emu.calllog.append(('476', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x41e2c0, 1, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('f2c0', emu.arg32(0) == (NS[0] and em.r32(NS[0] + 0xc)))), _s(emu, k)))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('free', emu.arg32(0) in NS, emu.arg32(1))), _s(emu, k)))
    def s52d(emu, k, _s=mkside(10)):
        a8p, acp = emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('d1c0', emu.reg('ecx') == T, rel(emu.arg32(0))[0], emu.r32(a8p), emu.r32(acp), fl(emu, emu.arg32(4)), emu.arg32(5), emu.arg32(6), rel(emu.arg32(7)), emu.arg32(0) != 0))
        emu.w32(a8p, emu.r32(a8p) + r.choice([0, 1, 1, 2]))
        emu.wbytes(acp, ft(r.uniform(0, 50)))
        emu.wbytes(emu.arg32(3), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))
        _s(emu, k)
    hook_rec(c, 0x52d1c0, 8, ret=rnd32, pop=32, this=True, stackmark=(0, 1, 2, 3, 4), side=s52d)
    def s43(emu, k, _s=mkside(11)):
        emu.calllog.append(('43e', fl(emu, emu.reg('edx')), fl(emu, emu.arg32(0))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', r.uniform(-9, 9), r.uniform(-9, 9), r.uniform(-9, 9)))
        _s(emu, k)
    hook_rec(c, 0x43e920, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=s43)
    def s4e(emu, k, _s=mkside(12)):
        emu.calllog.append(('4e0', fl(emu, emu.reg('ecx')), fl(emu, emu.reg('edx'))))
        _s(emu, k)
    hook_rec(c, 0x4e0870, 0, ret=rnd32, pop=0, this='mark', st0=lambda emu, k: r.uniform(0, 20), side=s4e)
    hitp = 1.0 if n0 else 0.25
    def s2e0(emu, k, _s=mkside(13)):
        q = emu.arg32(0)
        emu.calllog.append(('2e0', emu.rbytes(q, 0x70).hex(), [emu.arg32(i) for i in range(1, 6)]))
        _s(emu, k)
    RC = obj(c, 0x20, {0x2e0: pystub(c, 6, ret=lambda emu, k: (r.getrandbits(24) << 8) | (1 if r.random() < hitp else 0), pop=24, this=True, stackmark=(0,), side=s2e0)})
    def s1c8(emu, k, _s=mkside(14)):
        emu.calllog.append(('1c8', emu.arg32(0), emu.arg32(1)))
        _s(emu, k)
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=lambda emu, k: r.choice([0, 1000, 6000, 100000, 0x7fffffff]), pop=8, this=True, side=s1c8)}, table_size=0xb10)
    em.w32(em.r32(so + 0x9b) + 0xadc, RC)
    def s2c(emu, k, _s=mkside(15)):
        emu.calllog.append(('log', emu.arg32(1)))
        _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    em.w32(0x700390, G390)
    return [T, A8, A12, A16, A20, A24, C, D]


def g41ca80(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    from recruits_util import obj, sysobj
    em = c.emu
    sr = [seh_record(c, 2) for _ in range(40)]
    rnd32 = lambda emu, k: r.getrandbits(32)
    def cs(emu, a, lim=0x200):
        out = b''
        for i in range(lim):
            ch = emu.rbytes(a + i, 1)[0]
            if ch == 0: break
            out += bytes([ch])
        return out
    def gs(emu, o): return cs(emu, emu.r32(o))
    def ss(emu, o, b):
        buf = rnd(c, len(b) + 8)
        emu.wbytes(buf, b + b'\0'); emu.w32(o, buf)
    def mkside(j):
        def side(emu, k):
            sr[j](emu, k)
        return side
    def lg(*a): em.calllog.append(a)
    segs = [b'C:\\Games\\FF', b'D:\\x', b'..\\data', b'/opt/ff', b'Freeboy']
    ex = [b'Freedom.exe', b'a.exe', b'FF.EXE', b'x.bin']
    def hkx(addr, nargs, pop, this_, j, act=None, ret=None, stackmark=()):
        def sd(emu, k, _s=mkside(j)):
            if act: act(emu)
            _s(emu, k)
        hook_rec(c, addr, nargs, ret=(ret if ret is not None else rnd32), pop=pop, this=this_, stackmark=stackmark, side=sd)
    # string class
    hkx(0x4cbeb0, 0, 0, 'mark', 0, act=lambda emu: (ss(emu, emu.reg('ecx'), b''), lg('s0')))
    hkx(0x4cbe80, 1, 4, 'mark', 1, act=lambda emu: (ss(emu, emu.reg('ecx'), cs(emu, emu.arg32(0))), lg('sc', cs(emu, emu.arg32(0)), emu.arg32(0) if emu.arg32(0) < 0x01000000 else 'P')), stackmark=(0,))
    hkx(0x4cbee0, 1, 4, 'mark', 2, act=lambda emu: (lg('sa', gs(emu, emu.arg32(0))), ss(emu, emu.reg('ecx'), gs(emu, emu.arg32(0)))), stackmark=(0,))
    hkx(0x4cc2c0, 1, 4, 'mark', 3, act=lambda emu: (lg('sp', gs(emu, emu.reg('ecx')), gs(emu, emu.arg32(0))), ss(emu, emu.reg('ecx'), gs(emu, emu.reg('ecx')) + gs(emu, emu.arg32(0)))), stackmark=(0,))
    hkx(0x4cbec0, 0, 0, 'mark', 4, act=lambda emu: lg('sd', gs(emu, emu.reg('ecx'))))
    def a421(emu):
        b = r.choice(segs) + b'\\' + r.choice(ex)
        ss(emu, emu.reg('ecx'), b); lg('p421', b)
    hkx(0x421080, 0, 0, 'mark', 5, act=a421)
    hkx(0x420ae0, 0, 0, 'mark', 6, act=lambda emu: lg('p420', cs(emu, emu.reg('ecx'))))
    def a820(emu): lg('820', emu.reg('ecx'), emu.reg('edx'))
    hkx(0x41c820, 0, 0, 'mark', 7, act=lambda emu: lg('820', emu.reg('ecx'), emu.reg('edx')))
    hkx(0x41c780, 0, 0, False, 8, act=lambda emu: lg('c780'))
    hkx(0x41cf80, 0, 0, False, 9, act=lambda emu: lg('cf80'))
    hkx(0x41cfd0, 0, 0, False, 10, act=lambda emu: lg('cfd0'))
    hkx(0x6078a0, 0, 0, False, 11, act=lambda emu: lg('78a0'), ret=lambda emu, k: (r.getrandbits(24) << 8) | (1 if r.random() < 0.6 else 0))
    hkx(0x6078d0, 0, 0, False, 12, act=lambda emu: lg('78d0'))
    hkx(0x41c9c0, 0, 0, False, 13, act=lambda emu: lg('c9c0'))
    hkx(0x41e290, 1, 0, False, 14, act=lambda emu: lg('alloc', emu.arg32(0)), ret=lambda emu, k: rnd(c, 0x40))
    def vtobj(raw, slots, nm):
        vt = em.alloc(0x200, 4)
        for off, (nargs, pop) in slots.items():
            em.w32(vt + off, pystub(c, nargs, ret=rnd32, pop=pop, this=True, side=(lambda emu, k, _o=off, _n=nm, _s=mkside(20 + len(nm) % 7 + (off % 5)): (lg('vs', _n, _o, emu.reg('ecx') == raw, [emu.arg32(i) for i in range(slots[_o][0])]), _s(emu, k)))))
        em.w32(raw, vt)
        return raw
    def a5f1(emu):
        lg('5f12d0')
    def r5f1(emu, k):
        return vtobj(emu.reg('ecx'), {0x94: (1, 4), 0x78: (0, 0), 0x10: (0, 0), 0: (1, 4)}, 'o1')
    hkx(0x5f12d0, 0, 0, True, 15, act=a5f1, ret=r5f1)
    def r4ff(emu, k):
        return vtobj(emu.reg('ecx'), {0xc: (0, 0), 0x10: (0, 0), 0: (1, 4)}, 'o2')
    hkx(0x4ff7b0, 0, 0, True, 16, act=lambda emu: lg('4ff7b0'), ret=r4ff)
    # imports
    def imp(name, nargs, pop, j, f):
        def h(e, rr):
            lg(name, *f(e))
            sr[j](e, 0)
        return h
    def stub(name, n, stdc, j, body, retf):
        def h(e, rr, _b=body, _r=retf):
            lg(name, *_b(e))
            sr[j](e, 0)
            e.ret(eax=_r(e), argbytes=(4 * n if stdc else 0))
        c.emu.stub_import(name, h)
    from recruits_util import stub_memset
    stub_memset(c)
    stub('CreateMutexA', 3, True, 30, lambda e: (e.arg32(0), e.arg32(1), cs(e, e.arg32(2))), lambda e: r.getrandbits(32))
    stub('strchr', 2, False, 31, lambda e: (e.arg32(0) < 0x01000000 and e.arg32(0), e.arg32(1)), lambda e: (r.getrandbits(32) | 1) if r.random() < 0.35 else 0)
    def gm(e):
        b = r.choice(segs) + b'\\' + r.choice(ex)
        e.wbytes(e.arg32(1), b + b'\0')
        return (e.arg32(0), e.arg32(2), b)
    stub('GetModuleFileNameA', 3, True, 32, gm, lambda e: 5)
    def srch(e):
        s_ = cs(e, e.arg32(0)); ch = e.arg32(1) & 0xff
        e._srch = s_.rfind(bytes([ch]))
        return (s_, ch)
    def srchr(e):
        return (e.arg32(0) + e._srch) if e._srch >= 0 else 0
    stub('strrchr', 2, False, 33, srch, srchr)
    h = r.choice([0xffffffff, 0xffffffff, 0x1234, 0x77])
    stub('CreateFileA', 7, True, 34, lambda e: (cs(e, e.arg32(0)), [e.arg32(i) for i in range(1, 7)]), lambda e: h)
    stub('CloseHandle', 1, True, 35, lambda e: (e.arg32(0),), lambda e: r.getrandbits(32))
    def sst(e):
        return (cs(e, e.arg32(0)), cs(e, e.arg32(1)))
    stub('strstr', 2, False, 36, sst, lambda e: (r.getrandbits(32) | 1) if r.random() < 0.4 else 0)
    # engine objects
    def s150(emu, k, _s=mkside(37)):
        lg('150', cs(emu, emu.arg32(0))); _s(emu, k)
    sysobj(c, slots={0x150: pystub(c, 1, ret=rnd32, pop=4, this=True, side=s150)})
    def s2c(emu, k, _s=mkside(38)):
        lg('log', emu.arg32(1)); _s(emu, k)
    LO = obj(c, 0x20, {0x2c: pystub(c, 2, ret=rnd32, pop=0, this=False, side=s2c)})
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=lambda emu, k: (lg('lg', emu.arg32(0), emu.arg32(1)), LO)[1], pop=8, this=True)})
    em.w32(0x700390, G390)
    em.w32(0x6e4004, r.choice([0, 0, 3]))
    cmdline = rnd(c, 0x40)
    em.wbytes(cmdline, r.choice([b'-TC\0', b'-ExportSIF x\0', b'abc\0', b'\0']) + bytes(8))
    return [r.getrandbits(32) | 0x10000, r.getrandbits(32), cmdline, r.getrandbits(32)]


def g580000(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, json, os
    import pe_emu
    from recruits_util import obj, sysobj, stub_memset
    em = c.emu
    CAL = json.load(open(os.path.join(os.path.dirname(os.path.abspath(__file__)), 'callees_580000.json')))
    st = {'ebp': None}
    def msh(e, rr):
        d, v, n = e.arg32(0), e.arg32(1), e.arg32(2)
        if st['ebp'] is not None:
            e.calllog.append(('memset', st['ebp'] - d, v & 0xff, n))
        if n:
            e.wbytes(d, bytes([v & 0xff]) * n)
        e.ret(eax=d, argbytes=0)
    c.emu.stub_import('memset', msh)
    rnd32 = lambda emu, k: r.getrandbits(32)
    def win(emu, a):
        if st['ebp'] is None: st['ebp'] = a + 0xa0
        x = st['ebp'] - a
        n = max(0, min(0x50, x - 0x14))
        return (x, n, zlib.crc32(emu.rbytes(a, n)) if n else 0)
    def state(emu):
        a = emu.r32(pe_emu.TEB)
        return (emu.r32(a + 4), emu.r32(a + 8))
    def mk(addr, nargs):
        def side(emu, k):
            ecx = emu.reg('ecx')
            emu.calllog.append(('c', addr, win(emu, ecx), [emu.arg32(i) for i in range(nargs)], state(emu)))
        return side
    for ak, (cv, nargs) in CAL.items():
        if cv != 'thiscall': continue
        a = int(ak, 16)
        hook_rec(c, a, nargs, ret=rnd32, pop=4 * nargs, this='mark', side=mk(a, nargs))
    def s34(emu, k):
        emu.calllog.append(('v34', win(emu, emu.arg32(0)), state(emu)))
    REG = obj(c, 0x40, {0x34: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s34)})
    so = sysobj(c)
    em.w32(so + 0x9b, REG)
    return []


def g5ff2b0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct
    import recruits_util as _ru
    from recruits_util import obj, sysobj
    TS = 0x180
    T = rnd(c, TS)
    sr = [seh_record(c, 2) for _ in range(30)]
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
    BS = 0x240
    blob_off = {k: r.randrange(0x40, BS - 0x40, 4) for k in (0x6c, 0x70, 0x74, 0x78, 0x7c, 0x8c, 0x90)}
    a0v = r.randrange(0, 0x100); a8v = r.choice([0, 1, 2, 3, 4])
    n1 = r.choice([0, 1, 2, 3])
    ncnt = [r.choice([0, 1, 2, 3]) for _ in range(4)]
    hdr_val = {0x94: BS, 0x6c: blob_off[0x6c], 0x70: blob_off[0x70], 0x74: blob_off[0x74], 0x78: blob_off[0x78], 0x7c: blob_off[0x7c], 0x8c: blob_off[0x8c], 0x90: blob_off[0x90], 0x12e: n1}
    st = {'k5c': 0, 'elem': -1, 'rem': 0, 'after_cnt': False}
    def valid_v():
        if a8v and r.random() < 0.12: return (a0v + a8v) & 0xffff
        if a8v and r.random() < 0.7: return (a0v + r.randrange(0, a8v)) & 0xffff
        return r.getrandbits(16) | (r.getrandbits(1) << 20)
    def s5c(emu, k, _s=mkside(0)):
        dst = emu.arg32(0)
        rel = dst - T
        if 0 <= rel < TS:
            v = hdr_val.get(rel, r.getrandbits(32) & 0xffff)
            if rel == 0x12a: v = r.getrandbits(32)
        elif _ru.HEAP_LO <= dst < _ru.HEAP_HI:   # element field +0x18
            v = r.getrandbits(32); st['elem'] += 1; st['rem'] = -1
        else:  # stack: c8, count or value
            if st['k5c'] == 0 or (st['elem'] < 0):
                v = r.getrandbits(32)
            elif st['rem'] == -1:
                v = ncnt[st['elem'] % 4]; st['rem'] = v
            else:
                v = valid_v(); st['rem'] -= 1
        st['k5c'] += 1
        emu.w32(dst, v)
        emu.calllog.append(('s5c', rel if 0 <= rel < TS else ('E' if _ru.HEAP_LO <= dst < _ru.HEAP_HI else 'S'), v))
        _s(emu, k)
    def s64(emu, k, _s=mkside(1)):
        v = struct.pack('<f', r.choice([struct.unpack('<f', c.emu.rbytes(0x678858, 4))[0], struct.unpack('<f', c.emu.rbytes(0x678858, 4))[0], r.uniform(-2, 2)]))
        emu.wbytes(emu.arg32(0), v)
        emu.calllog.append(('s64', v.hex()))
        _s(emu, k)
    def s54(emu, k, _s=mkside(2)):
        v = r.getrandbits(16)
        emu.wbytes(emu.arg32(0), struct.pack('<H', v))
        emu.calllog.append(('s54', emu.arg32(0) - T, v))
        _s(emu, k)
    BLOB = rnd(c, BS)
    def s70(emu, k, _s=mkside(3)):
        dst = emu.arg32(0); n = emu.arg32(1)
        if dst == T + 0x18 or dst == T + 0x28:
            b = bytes(r.getrandbits(8) for _ in range(n))
        else:
            b = bytearray(r.getrandbits(8) for _ in range(n))
            def put(off, val):
                b[off:off + 4] = struct.pack('<I', val)
            if n == BS:
                put(blob_off[0x7c], a0v); put(blob_off[0x7c] + 4, a8v)
                for kk in (0x6c, 0x74, 0x78): put(blob_off[kk], r.getrandbits(32))
            b = bytes(b)
        emu.wbytes(dst, b)
        emu.calllog.append(('s70', dst - T if 0 <= dst - T < TS else 'H', n, zlib.crc32(b)))
        _s(emu, k)
    s74 = pystub(c, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(4): (emu.calllog.append(('s74', emu.arg32(0))), _s(emu, k)))
    S = obj(c, 0x80, {0x5c: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s5c), 0x64: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s64),
                      0x54: pystub(c, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=s54), 0x70: pystub(c, 2, ret=rnd32, pop=8, this=True, stackmark=(0,), side=s70), 0x74: s74})
    c.emu.wbytes(T, bytes(r.getrandbits(8) for _ in range(TS)))
    H = obj(c, 0x20, {}) if False else 0
    c.emu.w32(T + 0x9c, r.choice([0, rnd(c, 0x20)]))
    A2 = rnd(c, 0x10)
    # hooks
    objs = []
    def al(emu, k, _s=mkside(5)):
        emu.calllog.append(('alloc', emu.arg32(0)))
        _s(emu, k)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: rnd(c, max(min(emu.arg32(0), 0x400), 0x40) + 0x10), pop=0, this=False, side=al)
    hook_rec(c, 0x41e2c0, 1, ret=rnd32, pop=0, this=False, side=lambda emu, k, _s=mkside(6): (emu.calllog.append(('free', 1)), _s(emu, k)))
    def s4123(emu, k, _s=mkside(7)):
        ev = emu.arg32(0); cn = emu.arg32(2)
        for i in range(cn):
            e = ev + 0x1c * i
            cap = r.choice([1, 2, 3])
            emu.w32(e, rnd(c, 4 * cap + 0x20)); emu.w32(e + 4, cap); emu.w32(e + 8, 0)
        emu.calllog.append(('4123', emu.arg32(1), cn, emu.arg32(3), emu.arg32(4)))
        _s(emu, k)
    hook_rec(c, 0x634123, 5, ret=rnd32, pop=20, this=False, side=s4123)
    hook_rec(c, 0x600420, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(8): (emu.calllog.append(('6420', emu.reg('ecx') - T, emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x5ffb00, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(9): (emu.calllog.append(('fb00', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x602d30, 1, ret=lambda emu, k: rnd(c, 0x20), pop=0, this=False, side=lambda emu, k, _s=mkside(10): (emu.calllog.append(('2d30', emu.arg32(0))), _s(emu, k)))
    hook_rec(c, 0x602ff0, 1, ret=lambda emu, k: r.choice([0, rnd(c, 0x20), rnd(c, 0x20)]), pop=4, this=True, side=lambda emu, k, _s=mkside(11): (emu.calllog.append(('2ff0', emu.arg32(0))), _s(emu, k)))
    okv = r.choice([0, 1])
    hook_rec(c, 0x5fe4e0, 0, ret=lambda emu, k: okv, pop=0, this=True, side=mkside(12))
    hook_rec(c, 0x5fe080, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(13): (emu.calllog.append(('e080', emu.arg32(0) - T)), _s(emu, k)))
    hook_rec(c, 0x5fdd20, 1, ret=rnd32, pop=4, this=True, side=lambda emu, k, _s=mkside(14): (emu.calllog.append(('dd20', emu.arg32(0) - T)), _s(emu, k)))
    def sl14(emu, k, _s=mkside(15)):
        sp = emu.reg('esp') + 4
        emu.calllog.append(('sl14', emu.arg32(2), emu.rbytes(sp + 12, 16).hex()))
        _s(emu, k)
    LOGO = obj(c, 0x40, {0x14: pystub(c, 3, ret=rnd32, pop=0, this=False, stackmark=(1,), side=sl14)})
    hook_rec(c, 0x5fa630, 0, ret=lambda emu, k: LOGO, pop=0, this=False, side=mkside(16))
    c.emu.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, this=False, side=mkside(17)))
    def s2c(emu, k, _s=mkside(18)):
        emu.calllog.append(('log', emu.arg32(1), emu.arg32(2)))
        _s(emu, k)
    LO = obj(c, 0x40, {0x2c: pystub(c, 3, ret=rnd32, pop=0, this=False, side=s2c)})
    def s20(emu, k):
        emu.calllog.append(('lg', emu.arg32(0), emu.arg32(1)))
        return LO
    G390 = obj(c, 0x20, {0x20: pystub(c, 2, ret=s20, pop=8, this=True)})
    c.emu.w32(0x700390, G390)
    return [T, S, A2, r.choice([0, 1])]


S(0x42ee70, 'GUESS hand 0x42ee70', 'thiscall', None, ret='al', gen=g42ee70, note='batch216060')


def g5fd2a0(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k_: 0, pop=0, this=False))
    this = rnd(c, 0x40); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x40)))
    BASEO = rnd(c, 0x100); OBJV = rnd(c, 0x40)
    OBJS = []
    for i in range(4):
        o = rnd(c, 0x10); c.emu.w32(o, OBJV); OBJS.append(o)
        c.emu.w32(BASEO + 0x10 * i, o)
    a0 = rnd(c, 0xb0); c.emu.wbytes(a0, bytes(r.getrandbits(8) for _ in range(0xb0)))
    c.emu.w32(a0 + 0x20, r.choice([0, 0, 0, 0, 1]))
    c.emu.w32(a0 + 0x9e, BASEO)
    if r.random() < 0.06: a0 = 0
    # tree
    H = rnd(c, 0x20); c.emu.w32(this + 1, H)
    def mkstr(txt):
        b = rnd(c, 0x40); c.emu.wbytes(b, txt + b'\0' * 4)
        s = rnd(c, 0x10); c.emu.w32(s, b); c.emu.w32(s + 4, b + len(txt)); c.emu.w32(s + 8, b + len(txt) + 1)
        return s
    TXT = [b'\\ab', b'x\\ab\\cd', b'ab', b'\\\\ab\\q', b'zz']
    nn = r.choice([0, 1, 2, 3, 4, 5, 5])
    nodes = []
    EL = []
    for i in range(nn):
        n = rnd(c, 0x40); c.emu.wbytes(n, bytes(0x40))
        ks = mkstr(r.choice(TXT)); 
        for q in range(3): c.emu.w32(n + 0xd + 4 * q, c.emu.r32(ks + 4 * q))
        val = rnd(c, 0x40); vec = rnd(c, 0x10)
        ne = r.choice([0, 1, 2, 3])
        arr = rnd(c, 0x20); es = []
        for q in range(ne):
            e = rnd(c, 0x30); c.emu.wbytes(e, bytes(0x30))
            c.emu.w32(e, r.choice([0x14, 0x15, 0x15, 0x16, 0x17, 0x24, 0x24, 0x13, 0x25, 0x20, 0x2a]))
            c.emu.w32(e + 8, 0x10 * r.randrange(4))
            c.emu.w32(arr + 4 * q, e); es.append(e)
        c.emu.w32(vec, arr); c.emu.w32(vec + 8, ne)
        c.emu.w32(val + 0x30, vec); c.emu.w32(val + 0x34, r.choice([0, 0, 1]))
        c.emu.w32(n + 0x19, val)
        nodes.append(n); EL.append(es)
    VALM = {}
    for n, es in zip(nodes, EL): VALM[c.emu.r32(n + 0x19)] = es
    c.emu.w32(H + 1, 0); c.emu.w32(H + 5, H); c.emu.w32(H + 9, H)
    order = r.choice([[1, 3, 0, 2, 4], [1, 4, 2, 3, 0]]) if nn == 5 else list(range(nn))
    if nn == 4: order = r.choice([[1, 3, 0, 2], [1, 3, 2, 0]])
    rankmap = {}
    if nn >= 1:
        ranks = sorted(order)
        byrank = {rk: nodes[i] for i, rk in enumerate(ranks)}
        root = byrank[order[0]]
        c.emu.w32(H + 1, root); c.emu.w32(root + 1, H)
        for rk in order[1:]:
            nd_ = byrank[rk]; cur = root
            while True:
                ck = [q for q, v in byrank.items() if v == cur][0]
                side = 5 if rk < ck else 9
                nx = c.emu.r32(cur + side)
                if nx == 0:
                    c.emu.w32(cur + side, nd_); c.emu.w32(nd_ + 1, cur); break
                cur = nx
        c.emu.w32(H + 5, byrank[ranks[0]]); c.emu.w32(H + 9, byrank[ranks[-1]])
    BUFS = [rnd(c, 0x40) for _ in range(3)]; BUFK = [rnd(c, 0x40) for _ in range(4)]
    cnt = {'k': 0, 's': 0}
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, 0x40)), [emu.r32(n + 0x34 - 0x19 + 0x19) for n in []], [emu.r32(emu.r32(n + 0x19) + 0x34) for n in nodes]))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def cstr(emu, a, lim=0x80):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    hook_rec(c, 0x600800, 0, ret=rnd32, pop=0, this=True, side=mkside(0))
    SC = [b'ab', b'\\ab', b'a\\b\\c', b'', b'x']
    def a42b390(emu, k_, _s=mkside(1)):
        e = emu.reg('ecx'); t = r.choice(SC)
        b = BUFS[0]; emu.wbytes(b, t + b'\0')
        emu.w32(e, b); emu.w32(e + 4, b + len(t)); emu.w32(e + 8, b + (0 if r.random() < 0.3 else len(t) + 1))
        emu.calllog.append(('s30', t.hex()))
        _s(emu, k_)
    hook_rec(c, 0x42b390, 2, ret=rnd32, pop=8, this='mark', stackmark=(1,), side=a42b390)
    def a5fa640(emu, k_, _s=mkside(2)):
        emu.calllog.append(('fa', emu.reg('edx') - emu.reg('ecx'), emu.arg32(0), emu.arg32(1), emu.arg32(2) == a0))
        _s(emu, k_)
    def r5fa640(emu, k_):
        lo = emu.reg('ecx'); hi = emu.reg('edx')
        if hi <= lo or r.random() < 0.2: return hi
        cand = [p for p in range(lo, hi) if emu.rbytes(p - 1, 1) == b'\\' or emu.rbytes(p, 1) == b'\\']
        if cand and r.random() < 0.8: return r.choice(cand)
        return lo + r.randrange(0, hi - lo)
    hook_rec(c, 0x5fa640, 5, ret=r5fa640, pop=20, this=True, side=a5fa640)
    def a4312f0(emu, k_, _s=mkside(3)):
        out = emu.arg32(0)
        t = r.choice(SC); b = BUFS[1]
        emu.wbytes(b, t + b'\0')
        emu.w32(out, b); emu.w32(out + 4, b + len(t)); emu.w32(out + 8, b + (0 if r.random() < 0.3 else len(t) + 1))
        emu.calllog.append(('sub', emu.arg32(1), emu.arg32(2)))
        _s(emu, k_)
    hook_rec(c, 0x4312f0, 3, ret=lambda emu, k_: (emu.arg32(0) if r.random() < 0.7 else emu.reg('ecx')), pop=12, this='mark', stackmark=(0,), side=a4312f0)
    def a5f2d60(emu, k_, _s=mkside(4)):
        e = emu.reg('ecx'); b = emu.arg32(0); en = emu.arg32(1)
        data = emu.rbytes(b, en - b) if 0 <= en - b < 0x80 else b''
        emu.wbytes(BUFS[2], data + b'\0')
        emu.w32(e, BUFS[2]); emu.w32(e + 4, BUFS[2] + len(data)); emu.w32(e + 8, BUFS[2] + (0 if r.random() < 0.3 else len(data) + 1))
        emu.calllog.append(('asr', data.hex()))
        _s(emu, k_)
    hook_rec(c, 0x5f2d60, 2, ret=rnd32, pop=8, this='mark', side=a5f2d60)
    hook_rec(c, 0x54f870, 2, ret=rnd32, pop=8, this='mark', side=mkside(5))
    def a5f10c0(emu, k_, _s=mkside(6)):
        e = emu.reg('ecx'); ks = emu.arg32(0)
        b = emu.r32(ks); en = emu.r32(ks + 4)
        data = emu.rbytes(b, en - b)
        tgt = BUFK[cnt['k'] % 4]; cnt['k'] += 1
        emu.wbytes(tgt, data + b'\0')
        emu.w32(e, tgt); emu.w32(e + 4, tgt + len(data)); emu.w32(e + 8, tgt + (0 if r.random() < 0.3 else len(data) + 1))
        emu.calllog.append(('cp', data.hex()))
        _s(emu, k_)
    hook_rec(c, 0x5f10c0, 1, ret=rnd32, pop=4, this='mark', stackmark=(0,), side=a5f10c0)
    hook_rec(c, 0x5fccb0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k_, _s=mkside(7): (emu.calllog.append(('nz', cstr(emu, emu.r32(emu.reg('ecx'))).hex())), _s(emu, k_)))
    def r5fc010(emu, k_):
        es = VALM.get(emu.reg('ecx'), [])
        return es[0] if es else 0
    hook_rec(c, 0x5fc010, 0, ret=r5fc010, pop=0, this=True, side=mkside(8))
    hook_rec(c, 0x5fb8b0, 1, ret=rnd32, pop=4, this=True, side=mkside(9))
    c.emu.w32(OBJV + 0x28, pystub(c, 0, ret=rnd32, this=True, side=mkside(10)))
    return [this, a0]


S(0x5fd2a0, 'GUESS hand 0x5fd2a0', 'thiscall', None, ret=None, gen=g5fd2a0, note='batch216060')


def g480a40(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x680
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    c.emu.w32(this + 0x417, r.choice([0x1800, 0x800, 0x1000, 0, 0x2000, 0xffff, 0x7]))
    c.emu.w32(this + 0x413, r.choice([0, 5, 9]))
    T = rnd(c, 0x100); TV = rnd(c, 0x1b0); c.emu.w32(T, TV); c.emu.w32(0x70039c, T)
    M = rnd(c, 0x20); MV = rnd(c, 0x130); c.emu.w32(M, MV); c.emu.w32(T + 0x9b, M)
    OB = rnd(c, 0x20); OBV = rnd(c, 0x130); c.emu.w32(OB, OBV)
    GL = rnd(c, 0x440); c.emu.wbytes(GL, bytes(r.getrandbits(8) for _ in range(0x440)))
    c.emu.w32(GL + 0x408, r.choice([0, 1, 2, 3])); c.emu.w32(0x7003b8, GL)
    POOL = {0x28: rnd(c, 0x40), 0x108: [rnd(c, 0x110) for _ in range(6)]}
    for q in POOL[0x108]: c.emu.wbytes(q, bytes(r.getrandbits(8) for _ in range(0x110)))
    cn = {'a': 0}
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS)), emu.r32(GL + 0x408), zlib.crc32(emu.rbytes(GL + 0x40c, 0x20)), [zlib.crc32(emu.rbytes(q, 0x110)) for q in POOL[0x108]]))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    hook_rec(c, 0x471b50, 3, ret=rnd32, pop=12, this=True, side=mkside(0))
    def memset(emu, k_, _s=mkside(1)):
        if emu.arg32(1) == 0 and emu.arg32(2) <= 0x80: emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
        _s(emu, k_)
    hook_rec(c, 0x634d10, 3, ret=rnd32, pop=0, this=False, side=memset)
    def alloc(emu, k_):
        sz = emu.arg32(0)
        if sz == 0x28: return 0 if r.random() < 0.15 else POOL[0x28]
        i = cn['a']; cn['a'] += 1
        return 0 if r.random() < 0.15 else POOL[0x108][i % 6]
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, this=False, side=mkside(2))
    hook_rec(c, 0x4cca60, 2, ret=lambda emu, k_: emu.reg('ecx'), pop=8, this=True, side=mkside(3))
    hook_rec(c, 0x4de7a0, 0, ret=rnd32, pop=0, this=True, side=mkside(4))
    hook_rec(c, 0x4d8180, 2, ret=rnd32, pop=8, this=True, side=mkside(5))
    hook_rec(c, 0x4d8330, 3, ret=lambda emu, k_: emu.reg('ecx'), pop=12, this=True, side=mkside(6))
    hook_rec(c, 0x4d83b0, 3, ret=lambda emu, k_: emu.reg('ecx'), pop=12, this=True, side=mkside(7))
    stub6 = pystub(c, 6, ret=lambda emu, k_: r.getrandbits(32), this=True, side=mkside(8))
    def a114(emu, k_, _s=mkside(9)):
        if emu.arg32(3) == 0x96:
            emu.w32(MV + 0x114, stub6)
        _s(emu, k_)
    c.emu.w32(MV + 0x114, pystub(c, 4, ret=lambda emu, k_: r.getrandbits(32), this=True, side=a114))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=lambda emu, k_: r.choice([0, OB]), this=True, side=mkside(10)))
    c.emu.w32(OBV + 0x128, pystub(c, 1, ret=rnd32, this=True, side=mkside(11)))
    def a1a4(emu, k_, _s=mkside(12)):
        if r.random() < 0.3:
            emu.w32(this + 0x417, r.choice([0x1800, 0x800, 0x1000, 0x100, 0x1900, 0xffff, 0x101, 0x1, 0x2000]))
            emu.w32(this + 0x413, r.choice([0, 5, 9]))
        _s(emu, k_)
    c.emu.w32(TV + 0x1a4, pystub(c, 1, ret=rnd32, this=True, side=a1a4))
    return [this, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x480a40, 'GUESS hand 0x480a40', 'thiscall', None, ret='eax', gen=g480a40, note='batch216060')


def g494060(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x5d50
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    STRS = [b'dir\\file', b'dir/file', b'dirx', b'dir', b'dir\\', b'a']
    CHOSEN = r.choice(STRS)
    STRB = rnd(c, 0x40); c.emu.wbytes(STRB, b'\0' * 6 + CHOSEN + b'\0' * 4)
    LP = rnd(c, 0x20); LPV = rnd(c, 0x40); c.emu.w32(LP, LPV)
    c.emu.w32(this + 0x1c, LPV)
    c.emu.w32(this + 8, rnd(c, 0x20))
    T = rnd(c, 0x1b00); TV = rnd(c, 0x140); c.emu.w32(T, TV); c.emu.w32(0x70039c, T)
    OB1 = rnd(c, 0x20); OB1V = rnd(c, 0xc0); c.emu.w32(OB1, OB1V); c.emu.w32(T + 0x190f, OB1)
    M = rnd(c, 0xae0); MV = rnd(c, 0x140); c.emu.w32(M, MV); c.emu.w32(T + 0x9b, M)
    NL = rnd(c, 0x20); NLV = rnd(c, 0x60); c.emu.w32(NL, NLV); c.emu.w32(M + 0xadc, NL)
    NODES = [rnd(c, 0x10) for _ in range(3)]
    c.emu.w32(NL + 8, r.choice([0, NODES[0], NODES[0]]))
    SUBO = rnd(c, 0x20); SUBOV = rnd(c, 0x20); c.emu.w32(SUBO, SUBOV)
    SUBP = rnd(c, 0x20); SUBPV = rnd(c, 0x20); c.emu.w32(SUBP, SUBPV)
    def optobj(addr, off):
        o = rnd(c, 0x20); ov = rnd(c, 0xe0); c.emu.w32(o, ov)
        if addr == 'g': c.emu.w32(0x7003a4, r.choice([0, o]))
        elif addr == 'h': c.emu.w32(0x7003b8, r.choice([0, o]))
        else: c.emu.w32(T + addr, r.choice([0, o]))
        return o, ov
    o1, o1v = optobj(0x1a9f, 0); o2, o2v = optobj(0x1aa3, 0); o3, o3v = optobj('g', 0); o4, o4v = optobj('h', 0)
    BUF = rnd(c, 0x100); BUF90 = rnd(c, 0x80); BUF110 = rnd(c, 0x80)
    sr = [seh_record(c, 2) for _ in range(24)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x1b0, 0x20)), emu.r32(NL + 8), [emu.r32(n) for n in NODES[:1]]))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def cstr(emu, a, lim=0x80):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    def nxt(j):
        def f(emu, k_, _s=mkside(j)):
            p = emu.arg32(0); cur = emu.r32(p)
            emu.calllog.append(('nx', cur in NODES))
            i = NODES.index(cur) if cur in NODES else 2
            emu.w32(p, NODES[i + 1] if i < 1 and r.random() < 0.6 else 0)
            _s(emu, k_)
        return f
    c.emu.w32(NLV + 0x50, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=nxt(0)))
    hook_rec(c, 0x4dc420, 1, ret=rnd32, pop=4, this=True, side=mkside(1))
    c.emu.w32(OB1V + 0x40, pystub(c, 0, ret=rnd32, this=True, side=mkside(2)))
    OB3 = rnd(c, 0x20); OB3V = rnd(c, 0xc0); c.emu.w32(OB3, OB3V); c.emu.w32(T + 0x1907, OB3)
    c.emu.w32(OB3V + 0xb0, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(3)))
    c.emu.w32(LPV + 0x34, pystub(c, 1, ret=lambda emu, k_: STRB, this=True, side=mkside(4)))
    def ctor90(emu, k_, _s=mkside(5)):
        s = cstr(emu, emu.arg32(0))
        emu.wbytes(BUF90, s + b'\0'); emu.w32(emu.reg('ecx'), BUF90)
        emu.calllog.append(('s90', s.hex()))
        _s(emu, k_)
    hook_rec(c, 0x4cbe80, 1, ret=rnd32, pop=4, this='mark', side=ctor90)
    def a128(emu, k_, _s=mkside(6)):
        t = r.choice([CHOSEN, CHOSEN[:3], b'zzz', CHOSEN[:4], b''])
        emu.wbytes(BUF110, t + b'\0'); emu.w32(emu.arg32(0), BUF110)
        emu.calllog.append(('s110', t.hex()))
        _s(emu, k_)
    c.emu.w32(TV + 0x128, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a128))
    def strncmp(emu, k_, _s=mkside(7)):
        a = cstr(emu, emu.arg32(0))[:emu.arg32(2)]; b = cstr(emu, emu.arg32(1))[:emu.arg32(2)]
        emu.calllog.append(('cmp', a.hex(), b.hex(), emu.arg32(2)))
        _s(emu, k_)
    def rstrncmp(emu, k_):
        a = cstr(emu, emu.arg32(0))[:emu.arg32(2)]; b = cstr(emu, emu.arg32(1))[:emu.arg32(2)]
        return 0 if a == b else 1
    c.emu.w32(0x67640c, pystub(c, 3, ret=rstrncmp, pop=0, this=False, side=strncmp))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k_, _s=mkside(8): (emu.calllog.append(('dt', emu.r32(emu.reg('ecx')))), _s(emu, k_)))
    WV = rnd(c, 0x80)
    def ctorW(emu, k_, _s=mkside(9)):
        emu.w32(emu.reg('ecx'), WV)
        emu.calllog.append(('wc', emu.arg32(0) == BUF, emu.arg32(1)))
        _s(emu, k_)
    hook_rec(c, 0x4998c0, 2, ret=rnd32, pop=8, this='mark', side=ctorW)
    hook_rec(c, 0x49b360, 2, ret=rnd32, pop=8, this='mark', side=mkside(10))
    hook_rec(c, 0x49b330, 1, ret=rnd32, pop=4, this='mark', side=mkside(11))
    hook_rec(c, 0x49ab80, 2, ret=lambda emu, k_: r.choice([0, 1, 0x100, 0x101, 0x2]), pop=8, this='mark', side=mkside(12))
    hook_rec(c, 0x499980, 0, ret=rnd32, pop=0, this='mark', side=mkside(13))
    hook_rec(c, 0x4989a0, 1, ret=rnd32, pop=4, this=True, stackmark=(0,), side=mkside(14))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k_: BUF, pop=0, this=False, side=mkside(15))
    hook_rec(c, 0x634273, 2, ret=rnd32, pop=0, this=False, side=mkside(16))
    for off in (0x3c, 0x5c, 0x60, 0x54, 0x8):
        def wf(emu, k_, off=off, _s=mkside(17)):
            emu.calllog.append(('w', off, emu.arg32(0)))
            _s(emu, k_)
        c.emu.w32(WV + off, pystub(c, 1, ret=rnd32, this='mark', side=wf))
    c.emu.w32(TV + 0, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(18)))
    c.emu.w32(o1v + 0x8c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(19)))
    c.emu.w32(o2v + 0x40, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(19)))
    c.emu.w32(o3v + 0xd8, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(19)))
    c.emu.w32(o4v + 4, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(19)))
    O138 = rnd(c, 0x20); O138V = rnd(c, 0x20); c.emu.w32(O138, O138V)
    O134 = rnd(c, 0x20); O134V = rnd(c, 0x20); c.emu.w32(O134, O134V)
    c.emu.w32(MV + 0x138, pystub(c, 0, ret=lambda emu, k_: O138, this=True, side=mkside(20)))
    c.emu.w32(MV + 0x134, pystub(c, 0, ret=lambda emu, k_: O134, this=True, side=mkside(20)))
    c.emu.w32(O138V + 4, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(21)))
    c.emu.w32(O134V + 4, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=mkside(22)))
    return [this, r.getrandbits(32)]


S(0x494060, 'GUESS hand 0x494060', 'thiscall', None, ret='al', gen=g494060, note='batch216060')


def g4d3200(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib, struct as _st
    c.emu.w32(0x7003b0, pystub(c, 0, ret=lambda emu, k_: 0, pop=0, this=False))
    this = rnd(c, 0x4020); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x4020)))
    LV = rnd(c, 0x70); c.emu.w32(this + 0x4008, LV)
    nel = r.choice([0, 1, 2, 3])
    ELS = []
    for i in range(nel):
        E = rnd(c, 0x140); c.emu.wbytes(E, bytes(r.getrandbits(8) for _ in range(0x140)))
        hdr = rnd(c, 0x10); c.emu.wbytes(hdr, bytes(r.choice(b'ABCDXYZ_') for _ in range(4)) + bytes(12))
        typ = r.choice([2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 30])
        c.emu.w32(hdr + 8, typ)
        dlen = r.choice([0, 4, 8])
        c.emu.w32(E, dlen); c.emu.w32(E + 4, hdr)
        nb = r.choice([4, 4, 8, 12, 16])
        c.emu.w32(E + 8, nb)
        data = E + dlen + 0xc
        for q in range(4):
            if typ == 3:
                c.emu.w32(data + 4 * q, _st.unpack('<I', _st.pack('<f', r.choice([0.5, 1.25, -3.0, 100.0])))[0])
            else:
                c.emu.w32(data + 4 * q, r.choice([1, 7, 0xffffffff, 0x10, 5, 0xfffffff0, 0, 0, 2]))
        ELS.append(E)
    T = rnd(c, 0x100); TV = rnd(c, 0x1c0); c.emu.w32(T, TV); c.emu.w32(0x70039c, T)
    M = rnd(c, 0x20); MV = rnd(c, 0x60); c.emu.w32(M, MV); c.emu.w32(T + 0x9b, M)
    O2 = rnd(c, 0x20); O2V = rnd(c, 0x1b0); c.emu.w32(O2, O2V)
    ITEM = rnd(c, 0x20); ITV = rnd(c, 0x1e0); c.emu.w32(ITEM, ITV)
    STRB = rnd(c, 0x40); c.emu.wbytes(STRB, b'itemname\0')
    Z = rnd(c, 0x20); ZV = rnd(c, 0x28); c.emu.w32(Z, ZV); c.emu.w32(0x700390, Z)
    LG = rnd(c, 0x20); LGV = rnd(c, 0x34); c.emu.w32(LG, LGV)
    sr = [seh_record(c, 2) for _ in range(14)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this + 0x4000, 0x20))))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def cstr(emu, a, lim=0x2800):
        n = 0
        while emu.rbytes(a + n, 1)[0] != 0 and n < lim: n += 1
        return emu.rbytes(a, n)
    ci = [0]
    def a4c(emu, k_, _s=mkside(0)):
        ci[0] = 0; emu.w32(emu.arg32(0), 1 if ELS else 0); _s(emu, k_)
    def r5c(emu, k_):
        p = emu.arg32(0)
        i = ci[0]; ci[0] += 1
        emu.w32(p, 1 if i < len(ELS) else 0)
        return ELS[i] if i < len(ELS) else 0
    c.emu.w32(LV + 0x4c, pystub(c, 1, ret=rnd32, this=True, stackmark=(0,), side=a4c))
    c.emu.w32(LV + 0x5c, pystub(c, 1, ret=r5c, this=True, stackmark=(0,), side=mkside(1)))
    c.emu.w32(ZV + 0x20, pystub(c, 2, ret=lambda emu, k_: LG, this=True, side=mkside(2)))
    KINDS = {0x69643c: '', 0x696450: 'vv', 0x696470: 'ss', 0x696480: 'vd', 0x69649c: 'ss', 0x6964ac: 'vvs', 0x6964cc: 'vs', 0x6964f0: 'vvs', 0x69651c: 'vs', 0x69650c: 'vv'}
    def a2c(emu, k_, _s=mkside(3)):
        fmt = emu.arg32(1)
        kinds = KINDS.get(fmt, '')
        ex = []
        i = 2
        for kd in kinds:
            if kd == 'v': ex.append(emu.arg32(i)); i += 1
            elif kd == 's': ex.append(cstr(emu, emu.arg32(i)).hex()); i += 1
            elif kd == 'd': ex.append((emu.arg32(i), emu.arg32(i + 1))); i += 2
        emu.calllog.append(('log', fmt, ex))
        _s(emu, k_)
    c.emu.w32(LGV + 0x2c, pystub(c, 2, ret=rnd32, pop=0, this=False, side=a2c))
    c.emu.w32(TV + 0x190, pystub(c, 0, ret=lambda emu, k_: O2, this=True, side=mkside(4)))
    def a198(emu, k_, _s=mkside(5)):
        dst = emu.arg32(1); fmt = emu.arg32(2)
        old = cstr(emu, dst)
        if fmt == 0x696460:
            a, b = emu.arg32(3), emu.arg32(4); out = ('H%d:%d:' % (a, b)).encode(); ex = [a, b]
        elif fmt == 0x696468:
            v = emu.arg32(4); out = old + ('%d,' % v).encode(); ex = [emu.arg32(3) == dst, v]
        elif fmt == 0x696494:
            lo, hi = emu.arg32(4), emu.arg32(5); out = old + ('f%x%x,' % (lo, hi)).encode(); ex = [emu.arg32(3) == dst, lo, hi]
        else:
            out = b'?'; ex = []
        emu.wbytes(dst, out + b'\0')
        emu.calllog.append(('spf', fmt, ex))
        _s(emu, k_)
    c.emu.w32(O2V + 0x198, pystub(c, 3, ret=rnd32, pop=0, this=False, stackmark=(1,), side=a198))
    c.emu.w32(MV + 0x58, pystub(c, 1, ret=lambda emu, k_: r.choice([0, ITEM]), this=True, side=mkside(6)))
    def a1d8(emu, k_, _s=mkside(7)):
        emu.w32(emu.arg32(0), STRB); _s(emu, k_)
    c.emu.w32(ITV + 0x1d8, pystub(c, 2, ret=lambda emu, k_: emu.arg32(0), this=True, stackmark=(0,), side=a1d8))
    hook_rec(c, 0x4cbec0, 0, ret=rnd32, pop=0, this='mark', side=lambda emu, k_, _s=mkside(8): (emu.calllog.append(('dt', emu.r32(emu.reg('ecx')))), _s(emu, k_)))
    hook_rec(c, 0x634047, 0, ret=0, pop=0, this=False)
    return [this]


S(0x4d3200, 'GUESS hand 0x4d3200', 'thiscall', None, ret=None, gen=g4d3200, note='batch216060')


def g51b790(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    import zlib
    TS = 0x5e0
    this = rnd(c, TS); c.emu.wbytes(this, bytes(r.getrandbits(8) for _ in range(TS)))
    VTA = rnd(c, 0x10); VTB = rnd(c, 0x10)
    T = rnd(c, 0x100); TV = rnd(c, 0x10); c.emu.w32(T, TV); c.emu.w32(0x70039c, T)
    M = rnd(c, 0x20); MV = rnd(c, 0x130); c.emu.w32(M, MV); c.emu.w32(T + 0x9b, M)
    FIELDS = [0x22e, 0x232, 0x236, 0x23a] + list(range(0x26e, 0x292, 4))
    sr = [seh_record(c, 2) for _ in range(20)]
    def mkside(j):
        def side(emu, k_):
            emu.calllog.append(('t', zlib.crc32(emu.rbytes(this, TS))))
            sr[j](emu, k_)
        return side
    rnd32 = lambda emu, k_: r.getrandbits(32)
    def scramble(emu):
        if r.random() < 0.6:
            for o in r.sample(FIELDS, 4):
                emu.w32(this + o, r.choice([0, 0x3f800000, r.getrandbits(32)]))
    def vstub(slot_id):
        def f(emu, k_, _s=mkside(slot_id)):
            emu.calllog.append(('vc', emu.reg('ecx') - this))
            scramble(emu)
            _s(emu, k_)
        return f
    c.emu.w32(VTA + 0, pystub(c, 3, ret=rnd32, this=True, side=vstub(0)))
    c.emu.w32(VTA + 4, pystub(c, 3, ret=rnd32, this=True, side=vstub(1)))
    c.emu.w32(VTB + 0, pystub(c, 3, ret=rnd32, this=True, side=vstub(2)))
    def ctorA(emu, k_, _s=mkside(3)):
        emu.w32(emu.reg('ecx'), VTA); _s(emu, k_)
    def ctorB(emu, k_, _s=mkside(4)):
        emu.w32(emu.reg('ecx'), VTB); _s(emu, k_)
    hook_rec(c, 0x526ef0, 0, ret=rnd32, pop=0, this=True, side=ctorA)
    hook_rec(c, 0x5273b0, 0, ret=rnd32, pop=0, this=True, side=ctorB)
    hook_rec(c, 0x5167d0, 0, ret=rnd32, pop=0, this=True, side=mkside(5))
    hook_rec(c, 0x4e1b60, 0, ret=rnd32, pop=0, this=True, side=mkside(6))
    hook_rec(c, 0x511c60, 0, ret=rnd32, pop=0, this=True, side=mkside(7))
    hook_rec(c, 0x511cd0, 3, ret=rnd32, pop=12, this=True, side=mkside(8))
    def memset(emu, k_, _s=mkside(9)):
        if emu.arg32(1) == 0 and emu.arg32(2) <= 0x80: emu.wbytes(emu.arg32(0), bytes(emu.arg32(2)))
        _s(emu, k_)
    hook_rec(c, 0x634d10, 3, ret=rnd32, pop=0, this=False, side=memset)
    c.emu.w32(MV + 0x114, pystub(c, 4, ret=rnd32, this=True, side=mkside(10)))
    return [this, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x51b790, 'GUESS hand 0x51b790', 'thiscall', None, ret='eax', gen=g51b790, note='batch216060')
S(0x42b460, 'GUESS hand 0x42b460', 'thiscall', None, ret='eax', gen=g42b460, note='batch216060')
S(0x5cce70, 'GUESS hand 0x5cce70', 'thiscall', None, ret='eax', gen=g5cce70, note='batch216060')
S(0x440f50, 'GUESS hand 0x440f50', 'thiscall', None, ret=None, gen=g440f50, note='batch216060')
S(0x4d5880, 'GUESS hand 0x4d5880', 'thiscall', None, ret='al', gen=g4d5880, note='batch216060')
S(0x497990, 'GUESS hand 0x497990', 'thiscall', None, ret=None, gen=g497990, note='batch216060')
S(0x603500, 'GUESS hand 0x603500', 'thiscall', None, ret='eax', gen=g603500, note='batch216060')
S(0x606a70, 'GUESS hand 0x606a70', 'thiscall', None, ret='eax', gen=g606a70, note='batch216060')
S(0x603430, 'GUESS hand 0x603430', 'thiscall', None, ret='eax', gen=g603430, note='batch216060')
S(0x5fb660, 'GUESS hand 0x5fb660', 'thiscall', None, ret=None, gen=g5fb660, note='batch216060')
S(0x461250, 'GUESS hand 0x461250', 'thiscall', None, ret='eax', gen=g461250, note='batch216060')
S(0x4dc440, 'GUESS hand 0x4dc440', 'thiscall', None, ret=None, gen=g4dc440, note='batch216060')
S(0x4dbe30, 'GUESS hand 0x4dbe30', 'thiscall', None, ret=None, gen=g4dbe30, note='batch216060')
S(0x49a790, 'GUESS hand 0x49a790', 'thiscall', None, ret='al', gen=g49a790, note='batch216060')
S(0x52a370, 'GUESS hand 0x52a370', 'thiscall', None, ret='eax', gen=g52a370, note='batch216060')
S(0x5aba60, 'GUESS hand 0x5aba60', 'thiscall', None, ret=None, gen=g5aba60, note='batch216060')
S(0x57ee90, 'GUESS hand 0x57ee90', 'thiscall', None, ret=None, gen=g57ee90, note='batch216060')
S(0x5f37f0, 'GUESS hand 0x5f37f0', 'thiscall', None, ret='eax', gen=g5f37f0, note='batch216060')
S(0x5f9940, 'GUESS hand 0x5f9940', 'thiscall', None, ret=None, gen=g5f9940, note='batch216060')
S(0x512590, 'GUESS hand 0x512590', 'thiscall', None, ret=None, gen=g512590, note='batch216060')
S(0x520110, 'GUESS hand 0x520110', 'thiscall', None, ret='eax', gen=g520110, note='batch216060')
S(0x4e6ce0, 'GUESS hand 0x4e6ce0', 'thiscall', None, ret=None, gen=g4e6ce0, note='batch216060')
S(0x5fb370, 'GUESS hand 0x5fb370', 'thiscall', None, ret=None, gen=g5fb370, note='batch216060')
S(0x5afef0, 'GUESS hand 0x5afef0', 'thiscall', None, ret='eax', gen=g5afef0, note='batch216060')
S(0x4ff9d0, 'GUESS hand 0x4ff9d0', 'thiscall', None, ret=None, gen=g4ff9d0, note='batch216060')
S(0x6041e0, 'GUESS hand 0x6041e0', 'thiscall', None, ret='eax', gen=g6041e0, note='batch216060')
S(0x5bfac0, 'GUESS hand 0x5bfac0', 'thiscall', None, ret='eax', gen=g5bfac0, note='batch216060')
S(0x480ff0, 'GUESS hand 0x480ff0', 'thiscall', None, ret=None, gen=g480ff0, note='batch216060')
S(0x52b4e0, 'GUESS hand 0x52b4e0', 'thiscall', None, ret='eax', gen=g52b4e0, note='batch216060')
S(0x5e94c0, 'GUESS hand 0x5e94c0', 'thiscall', None, ret=None, gen=g5e94c0, note='batch216060')
S(0x49cda0, 'GUESS hand 0x49cda0', 'thiscall', None, ret='eax', gen=g49cda0, note='batch216060')
S(0x5e9e20, 'GUESS hand 0x5e9e20', 'thiscall', None, ret='al', gen=g5e9e20, note='batch216060')
S(0x4e6910, 'GUESS hand 0x4e6910', 'stdcall', None, ret='st0', gen=g4e6910, note='batch216060')
S(0x48c6c0, 'GUESS hand 0x48c6c0', 'thiscall', None, ret='al', gen=g48c6c0, note='batch216060')
S(0x453bf0, 'GUESS hand 0x453bf0', 'thiscall', None, ret='eax', gen=g453bf0, note='batch216060')
S(0x5ff2b0, 'GUESS hand 0x5ff2b0', 'thiscall', None, ret='eax', gen=g5ff2b0, note='batch216060')
S(0x52e830, 'GUESS hand 0x52e830', 'thiscall', None, ret='eax', gen=g52e830, note='batch216060')
S(0x41ca80, 'GUESS hand 0x41ca80', 'stdcall', None, ret='eax', gen=g41ca80, note='batch216060')
S(0x580000, 'GUESS hand 0x580000', 'cdecl', None, ret=None, gen=g580000, note='batch216060')
