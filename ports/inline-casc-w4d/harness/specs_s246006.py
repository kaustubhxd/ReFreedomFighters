"""specs_s246006.py - w4d batch 246006: 0x58b780."""
import pe_emu
from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g58b780(c):
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    st = lambda emu: emu.r32(emu.r32(pe_emu.TEB) + 8)
    sr = [seh_record(c, 2) for _ in range(8)]

    def log(emu, k, tag, j, *extra):
        emu.calllog.append((tag, st(emu)) + extra)
        sr[j](emu, k)

    THIS = rnd(c, 0xf00)
    OBJ = rnd(c, 0x20)
    OVT = rnd(c, 0x200)
    em.w32(OBJ, OVT)
    n = r.choice([0, 0, 1, 2, 3, 5])
    em.wbytes(THIS + 0xa16, n.to_bytes(4, 'little'))
    if n and r.random() < 0.5:
        em.w32(THIS + 0xa1a + 0x30 * r.randrange(n), OBJ)
    for i in range(n):
        if em.r32(THIS + 0xa1a + 0x30 * i) == OBJ and r.random() < 0.3:
            pass
    em.w32(THIS + 0x417, r.choice([0, 0x400, 0x400, 0x401, 0x3ff, r.getrandbits(32)]))
    em.wbytes(THIS + 0xee3, bytes([r.choice([0, 1, 1, 0x80])]))
    em.wbytes(THIS + 0x64f, r.getrandbits(32).to_bytes(4, 'little'))
    em.wbytes(THIS + 0x7ea, r.getrandbits(16).to_bytes(2, 'little'))
    heaps = []

    def s128(emu, k):
        p = emu.arg32(1)
        log(emu, k, 'v128', 0, emu.reg('ecx') - OBJ, emu.arg32(0), emu.r32(p), emu.arg32(2))
    em.w32(OVT + 0x128, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=12, this=True, stackmark=(1,), side=s128))
    W = rnd(c, 0x10)
    TXT = rnd(c, 0x40)
    nm = bytes(r.randrange(1, 256) for _ in range(r.choice([0, 3, 10, 30]))) + b'\0'
    em.wbytes(TXT, nm)
    em.w32(W, TXT)

    def s1d8(emu, k):
        a = emu.arg32(0)
        if r.random() < 0.5:
            emu.w32(a, a + 4)
        else:
            h = rnd(c, 0x40)
            heaps.append(h)
            emu.w32(a, h)
        log(emu, k, 'v1d8', 1, emu.reg('ecx') - OBJ, emu.arg32(1))
        return W
    em.w32(OVT + 0x1d8, pystub(c, 2, ret=s1d8, pop=8, this=True, stackmark=(0,)))
    hook_rec(c, 0x634273, 2, ret=lambda emu, k: r.getrandbits(32), pop=0, stackmark=(0,),
             side=lambda emu, k: (emu.calllog.append(('free', heaps.index(emu.arg32(0)) if emu.arg32(0) in heaps else -1, emu.arg32(1))), sr[2](emu, k)))
    hook_rec(c, 0x59dce0, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True,
             side=lambda emu, k: log(emu, k, 'c59dce0', 3, emu.reg('ecx') - OBJ))
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    EDI = rnd(c, 0x10)
    EVT = rnd(c, 0x100)
    em.w32(EDI, EVT)

    def s20(emu, k):
        log(emu, k, 'l20', 4, emu.reg('ecx') - LO, emu.arg32(0), emu.arg32(1))
        return EDI
    em.w32(LVT + 0x20, pystub(c, 2, ret=s20, pop=8, this=True))

    def s2c(emu, k):
        t = emu.rbytes(emu.arg32(2), 80).split(b'\0')[0].hex()
        log(emu, k, 'e2c', 5, emu.arg32(0) - EDI, emu.arg32(1), t)
    em.w32(EVT + 0x2c, pystub(c, 3, ret=lambda emu, k: r.getrandbits(32), pop=0, side=s2c))
    return [THIS, OBJ]


S(0x58b780, 'GUESS FUN_58b780', 'thiscall', None, ret=None, gen=g58b780, note='batch246006')


def g4e18e0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    B = r.choice([0, 1, 3, 6, 10])
    A = rnd(c, 0x80)
    em.w32(A + 20, 0)   # A[5] = 0: the size-5 nested op relocates its own bytes to a harmless 0
    C = rnd(c, 0x100) if r.random() < 0.8 else 0
    flag = r.choice([0, 1, 0x80, 0x100, 0xff])
    gen_depth = [0]

    def dw(v):
        return (v & 0xffffffff).to_bytes(4, 'little')

    def idx():
        m = r.random()
        base = r.choice([0, 1, 2, B, B + 1, B + 5, r.randrange(0, 40)])
        return base | (0x80000000 if r.random() < 0.5 else 0)

    def prog(depth):
        out = bytearray()
        for _ in range(r.choice([0, 1, 2, 3, 5, 8])):
            op = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 9, 10, 10, 11, 12, 12, 13, 33, 62])
            hb = r.choice([0, 0, 0x40, 0x80, 0xc0])
            byte = (op | hb)
            if byte == 0xff:
                byte = op
            if op == 12 and depth >= 2:
                op = 11
                byte = op | hb
            out.append(byte)
            if op == 1:
                out += bytes(r.getrandbits(8) for _ in range(8))
            elif op in (2, 3, 11):
                out += dw(r.getrandbits(32))
            elif op in (4, 5):
                out += bytes(r.randrange(1, 255) for _ in range(r.choice([0, 1, 4]))) + b'\0'
            elif op == 7:
                n = r.choice([4, 6, 9])
                out += dw(n) + bytes(r.getrandbits(8) for _ in range(n - 4))
            elif op == 8:
                out += dw(idx())
            elif op == 10:
                out += dw(r.choice([0, 1, 2, 5, 17]))
            elif op == 9:
                k = r.choice([1, 2, 3, 4])
                out += dw(4 * (k + 1)) + b''.join(dw(idx()) for _ in range(k))
            elif op == 12:
                if r.random() < 0.2:
                    kk = r.choice([0, 3, 4, 5, 5, 5])
                    out += dw(kk) + (b'\x08\x06\x00\x00\x00\xff' if kk == 5 else b'')
                    continue
                inner = prog(depth + 1) + b'\xff'
                out += dw(len(inner) + 4) + inner
            elif op == 12:
                pass
        return bytes(out)
    code = prog(0) + b'\xff' + bytes(r.getrandbits(8) for _ in range(8))
    BUF = rnd(c, len(code) + 8)
    em.wbytes(BUF, code)
    THIS = rnd(c, 0x20)
    em.w32(THIS + 0xc, BUF)
    L = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(L, LVT)
    em.w32(0x700390, L)
    X = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(X, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=X, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.reg('ecx') - L, emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 2, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(0) - X, emu.arg32(1)))))
    return [THIS, A, B, C, r.getrandbits(32), flag]


S(0x4e18e0, 'GUESS FUN_4e18e0', 'thiscall', None, ret='eax', gen=g4e18e0, note='batch246006')


def g43a440(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    fl = [0.0, 1.0, -1.0, 0.5, -0.5, 100.0, 200.0, -200.0, 1e-5, 0.00012, 0.00013, -0.00012, -0.00013, 3.0, -3.0, 2.5, 300.0, -300.0, 1e10, -1e10, float('nan'), float('inf')]
    FB = lambda: struct.unpack('<I', struct.pack('<f', r.choice(fl)))[0] if r.random() < 0.85 else r.getrandbits(32)
    THIS = rnd(c, 0x1340)
    BUF = rnd(c, 0x60)
    em.w32(THIS + 0x131c, BUF + r.choice([0, 4, 8]))
    em.w32(THIS + 0x132c, FB())
    em.w32(0x6e48c8, r.choice([0, 0, 0x10, 0x20, 3]))   # offset stored in the table entry of key 0x6e49c0
    G = rnd(c, 0x1500)
    em.w32(0x70039c, G)
    em.wbytes(G + 0x6d, bytes([r.choice([0, 0, 1])]))
    em.wbytes(G + 0x9e3, r.choice([0, 1, 2, 5, 8, 100, -3 & 0xffffffff, r.getrandbits(32)]).to_bytes(4, 'little'))
    em.wbytes(G + 0x9ef, FB().to_bytes(4, 'little'))
    if r.random() < 0.3:   # exact +-1.0 difference for the boundary compares of the G[0x6d]==0 branch
        em.wbytes(G + 0x9ef, struct.pack('<f', 0.0))
        em.w32(THIS + 0x132c, struct.unpack('<I', struct.pack('<f', r.choice([1.0, -1.0, 1.0, -1.0, 0.0])))[0])
        em.wbytes(G + 0x9e3, r.choice([1, 1, 2]).to_bytes(4, 'little'))
    for o in (0x13fc, 0x1401, 0x1406):
        em.wbytes(G + o, bytes([r.choice([0, 0x7f, 0x80, 0xff, r.getrandbits(8)])]))
    OBJ = rnd(c, 0x40)
    em.w32(0x7003a0, OBJ if r.random() > 0.1 else 0)
    REC = rnd(c, 0x20)
    em.w32(REC, FB()); em.w32(REC + 4, FB()); em.w32(REC + 8, FB())
    em.wbytes(REC + 0xc, bytes([r.choice([0, 0, 1, 0x7f]), r.choice([0, 1]), r.choice([0, 5])]))
    nullrec = r.random() < 0.15
    hook_rec(c, 0x43ac30, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True,
             side=lambda emu, k: emu.calllog.append(('ac30', emu.reg('ecx') - THIS)))
    hook_rec(c, 0x435eb0, 1, ret=lambda emu, k: 0 if nullrec else REC, pop=4, this=True,
             side=lambda emu, k: emu.calllog.append(('e5eb0', emu.reg('ecx') - OBJ, emu.arg32(0))))
    return [THIS]


S(0x43a440, 'GUESS FUN_43a440', 'thiscall', None, ret=None, gen=g43a440, note='batch246006')


def g55a170(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    vals = [0.0, 1.0, -1.0, 3.0, 10.0, 100.0, -50.0, 400.0, 749.0, 750.0, 800.0, 0.5, 1e-3, 25.0]
    FV = lambda: r.choice(vals) if r.random() < 0.8 else f32(r.uniform(-900, 900))
    THIS = rnd(c, 0x40)
    OBJ = rnd(c, 0x10)
    OVT = rnd(c, 0x600)
    em.w32(OBJ, OVT)
    em.w32(THIS + 0x1c, OBJ)
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    vec = [rnd(c, 0x10) for _ in range(3)]
    for v in vec:
        em.wbytes(v, pk(FV()))
    ents = [rnd(c, 0x10) for _ in range(3)]
    for e in ents:
        em.wbytes(e + 4, bytes([r.choice([0, 0, 2, 2, 1, 5])]))
    em.w32(0x7003b0, c.emu.alloc(4, 4))   # placeholder, replaced below by a hook address
    FATAL = 0x7003b0
    fat = hook_rec(c, 0x55f000, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))) if False else None

    def s5003d0(emu, k):
        ec = emu.reg('ecx')
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', ec - P1 if ec in (P1,) else (ec - P2 if ec == P2 else -1), i))
        return (vec[i] if ec == P1 else ents[i])
    hook_rec(c, 0x5003d0, 1, ret=s5003d0, pop=4, this='mark')

    def s57c(emu, k):
        a, b = emu.arg32(0), emu.arg32(1)
        emu.wbytes(b, pk(FV(), FV(), FV()))
        emu.wbytes(a, pk(FV(), FV(), FV()))
        emu.calllog.append(('v57c', emu.reg('ecx') - OBJ, emu.rbytes(b, 12).hex()))
    em.w32(OVT + 0x57c, pystub(c, 2, ret=0, pop=8, this=True, stackmark=(0, 1), side=s57c))

    def s43e920(emu, k):
        ecx, edx, a = emu.reg('ecx'), emu.reg('edx'), emu.arg32(0)
        q = r.random()
        res = (FV(), FV(), FV()) if q < 0.55 else (FV(), 0.0, FV()) if q < 0.8 else (0.0, FV(), 0.0)
        emu.calllog.append(('e920', emu.rbytes(edx, 12).hex(), emu.rbytes(a, 12).hex(), res))
        emu.wbytes(ecx, pk(*res))
    hook_rec(c, 0x43e920, 1, ret=0, pop=4, stackmark=(0,), side=s43e920)

    def s4e0d00(emu, k):
        ecx = emu.reg('ecx')
        s = struct.unpack('<f', struct.pack('<I', emu.arg32(0)))[0]
        v = struct.unpack('<3f', emu.rbytes(ecx, 12))
        emu.calllog.append(('e0d00', emu.arg32(0), emu.rbytes(ecx, 12).hex()))
        emu.wbytes(ecx, pk(*[f32(x * s) for x in v]))
    hook_rec(c, 0x4e0d00, 1, ret=0, pop=4, this='mark', side=s4e0d00)

    def s441940(emu, k):
        ecx, edx = emu.reg('ecx'), emu.reg('edx')
        a = struct.unpack('<3f', emu.rbytes(ecx, 12))
        b = struct.unpack('<3f', emu.rbytes(edx, 12))
        emu.calllog.append(('e1940', emu.rbytes(ecx, 12).hex(), emu.rbytes(edx, 12).hex()))
        emu.wbytes(ecx, pk(*[f32(x + y) for x, y in zip(a, b)]))
    hook_rec(c, 0x441940, 0, ret=0, pop=0, side=s441940)
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(FATAL, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    return [THIS, SRC]


S(0x55a170, 'GUESS FUN_55a170', 'thiscall', None, ret=None, gen=g55a170, note='batch246006')


def g55cc30(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    vals = [0.0, 1.0, -1.0, 3.0, 10.0, 16.0, 17.0, 100.0, -50.0, 400.0, 0.5, 1e-3, 25.0, 250.0, -300.0]
    FV = lambda: r.choice(vals) if r.random() < 0.8 else f32(r.uniform(-400, 400))
    THIS = rnd(c, 0x40)
    TVT = rnd(c, 0x100)
    em.w32(THIS, TVT)
    W = rnd(c, 0x20)
    WVT = rnd(c, 0x700)
    em.w32(W, WVT)
    em.w32(THIS + 0x1c, W)
    PO = rnd(c, 0x20)
    em.w32(W + 0x1c, PO)
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    ESI = rnd(c, 0x10)
    em.w32(ESI, r.choice([0, 5, 0x7fffffff, 0x80000000, 0xffffffff, 0x100, r.getrandbits(32)]))
    ENT = rnd(c, 0x10)
    sig = lambda emu, k: None

    def s5003d0(emu, k):
        ec = emu.reg('ecx')
        emu.calllog.append(('e3d0', 1 if ec == P1 else 2 if ec == P2 else -1, emu.arg32(0)))
        return ESI if ec == P1 else ENT
    hook_rec(c, 0x5003d0, 1, ret=s5003d0, pop=4, this='mark')
    hook_rec(c, 0x5002f0, 1, ret=0, pop=4, this='mark',
             side=lambda emu, k: emu.calllog.append(('e2f0', emu.reg('ecx') - ENT, emu.arg32(0))))

    def poke(emu):
        emu.wbytes(PO + 8, bytes([r.getrandbits(8) for _ in range(3)]))

    def v57c(emu, k):
        a, b = emu.arg32(0), emu.arg32(1)
        emu.wbytes(b, pk(FV(), FV(), FV()))
        emu.wbytes(a, pk(FV(), FV(), FV()))
        emu.calllog.append(('v57c', emu.reg('ecx') - W, emu.rbytes(b, 12).hex()))
    em.w32(WVT + 0x57c, pystub(c, 2, ret=0, pop=8, this=True, stackmark=(0, 1), side=v57c))
    em.w32(WVT + 0x620, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(0,),
                               side=lambda emu, k: emu.calllog.append(('v620', emu.rbytes(emu.arg32(0), 12).hex(), emu.arg32(1), emu.arg32(2)))))

    def v578(emu, k):
        a, b = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('v578a', emu.rbytes(a, 12).hex(), emu.rbytes(b, 12).hex()))
        if r.random() < 0.5:
            emu.wbytes(b, pk(FV(), FV(), FV()))
    em.w32(WVT + 0x578, pystub(c, 2, ret=0, pop=8, this=True, stackmark=(0, 1), side=v578))

    def v354(emu, k):
        emu.calllog.append(('v354', emu.arg32(0), emu.arg32(1), emu.rbytes(PO + 8, 3).hex()))
        poke(emu)
    em.w32(WVT + 0x354, pystub(c, 2, ret=0, pop=8, this=True, side=v354))
    em.w32(WVT + 0x5ac, pystub(c, 2, ret=0, pop=8, this=True,
                               side=lambda emu, k: emu.calllog.append(('v5ac', emu.arg32(0), emu.arg32(1), emu.rbytes(PO + 8, 3).hex()))))
    Y = rnd(c, 0x10)
    em.w32(Y + 4, r.choice([0, 0, rnd(c, 0x10)]))
    em.w32(WVT + 0x20, pystub(c, 0, ret=Y, pop=0, this=True))

    def e960(emu, k):
        ecx, edx = emu.reg('ecx'), emu.reg('edx')
        q = r.random()
        res = (FV(), FV(), FV()) if q < 0.6 else (0.0, 0.0, 0.0) if q < 0.7 else (FV(), 0.0, FV())
        emu.calllog.append(('e960', emu.rbytes(ecx, 12).hex(), emu.rbytes(edx, 12).hex(), res))
        emu.wbytes(ecx, pk(*res))
    hook_rec(c, 0x43e960, 0, ret=0, pop=0, side=e960)

    def e0d80(emu, k):
        ecx = emu.reg('ecx')
        s = struct.unpack('<f', struct.pack('<I', emu.arg32(0)))[0]
        v = struct.unpack('<3f', emu.rbytes(ecx, 12))
        emu.calllog.append(('e0d80', emu.arg32(0), emu.rbytes(ecx, 12).hex()))
        ln = f32(sum(x * x for x in v) ** 0.5)
        sc = f32(s / ln) if ln > 0 else 1.0
        emu.wbytes(ecx, pk(*[f32(x * sc) for x in v]))
    hook_rec(c, 0x4e0d80, 1, ret=0, pop=4, this='mark', side=e0d80)
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    Q = rnd(c, 0x80)
    em.wbytes(G + 0x9b, Q.to_bytes(4, 'little'))
    em.w32(Q + 0x44, r.choice([0, 0x100, 0x7fffffff, r.getrandbits(32)]))
    em.w32(TVT + 0x50, pystub(c, 6, ret=lambda emu, k: r.getrandbits(32), pop=24, this=True,
                              side=lambda emu, k: emu.calllog.append(('t50', emu.reg('ecx') - THIS, [emu.arg32(i) for i in range(6)]))))
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2) == em.r32(Y + 4) or emu.arg32(2)))))
    return [THIS, SRC]


S(0x55cc30, 'GUESS FUN_55cc30', 'thiscall', None, ret=None, gen=g55cc30, note='batch246006')


def g615c30(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    fl = [0.0, 1.0, 2.5, -3.0, 100.0, 0.5]
    FB = lambda: struct.unpack('<I', struct.pack('<f', r.choice(fl)))[0] if r.random() < 0.8 else r.getrandbits(32)
    THIS = em.alloc(0x18400, 4)
    TVT = rnd(c, 0x100)
    em.w32(THIS, TVT)
    TBL = em.alloc(0x4000, 4)
    ub(THIS + 0x10071, TBL)
    Q = em.alloc(0x1500, 4)
    QVT = rnd(c, 0x400)
    em.w32(Q, QVT)
    ub(THIS + 0x182a5, Q)
    for i in range(4):
        em.w32(Q + 0x140e + i * 4, r.getrandbits(32))
    em.w32(Q + 0x141e, r.getrandbits(32))
    em.wbytes(Q + 0x1e, bytes([r.getrandbits(8)]))
    em.w32(Q + 0x27, r.getrandbits(32))
    # render-state cache in .data
    D = rnd(c, 0x10)
    DVT = rnd(c, 0x200)
    em.w32(D, DVT)
    em.w32(0x724a00, D)
    em.w32(0x724934, r.choice([1, 1, 0, 2]))
    em.w32(0x724968, r.choice([4, 4, 0, 3]))
    em.w32(0x72493c, r.choice([0, 0, 1]))
    em.w32(0x724928, r.choice([1, 1, 0]))
    em.w32(0x72492c, r.choice([4, 4, 2]))
    em.w32(0x724940, r.choice([0, 0, 1]))
    em.w32(0x724930, r.choice([0, 1, 2]))
    v = r.choice([0, 5, 7])
    em.w32(0x724958, v)
    em.w32(0x724950, r.choice([v, v, 9]))
    em.w32(DVT + 0xc8, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('rs', emu.arg32(0) - D, emu.arg32(1), emu.arg32(2)))))
    em.w32(DVT + 0xfc, pystub(c, 4, ret=0, pop=16, side=lambda emu, k: emu.calllog.append(('tss', emu.arg32(0) - D, emu.arg32(1), emu.arg32(2), emu.arg32(3)))))
    # actors
    n = r.choice([0, 1, 2, 3, 4])
    Vs = []
    for _ in range(2):
        V = em.alloc(0x80, 4)
        for off in (0x68, 0x6c, 0x70, 0x74):
            em.w32(V + off, FB())
        Vs.append(V)
    X2s = []
    for V in Vs:
        x2 = em.alloc(0x20, 4); em.w32(x2 + 0xc, V)
        x1 = em.alloc(0x20, 4); em.w32(x1 + 0xc, x2)
        X2s.append(x1)
    acts = []
    for k in range(6):
        a = em.alloc(0x40, 4)
        em.w32(a + 0x20, r.choice(X2s))
        chain = 0
        for _ in range(r.choice([0, 0, 1, 2, 3])):
            ch = em.alloc(0x30, 4)
            m3 = em.alloc(0x30, 4)   # ch[8]
            m2 = em.alloc(0x30, 4)   # [0x10]
            m1 = em.alloc(0x60, 4)   # [8]
            em.w32(ch + 8, m3); em.w32(m3 + 0x10, m2); em.w32(m2 + 8, m1)
            em.wbytes(m1 + 2, (r.choice([0, 0, 1])).to_bytes(2, 'little'))
            em.w32(m1 + 0x20, r.choice([0x800, 0x800, 0, 0x7ff, 0xfff, 0x1800]))
            em.w32(ch + 0x1c, chain)
            chain = ch
        em.w32(a + 0x1c, chain)
        acts.append(a)
    words = [r.randrange(0, 0x10000) for _ in range(6)]
    lo = lambda w: w & 0xfff
    used = set()
    for k in range(6):
        if lo(words[k]) in used:
            words[k] = (words[k] & ~0xfff) | ((lo(words[k]) + 1) & 0xfff)
        used.add(lo(words[k]))
        em.w32(TBL + 4 * lo(words[k]), acts[k] if r.random() < 0.85 else 0)
    objs = []
    for k in range(6):
        o = em.alloc(0x80, 4)
        em.wbytes(o + 0x5a, words[k].to_bytes(2, 'little'))
        objs.append(o)
    LIST = em.alloc(0x40, 4)
    for i in range(n):
        em.w32(LIST + 4 * i, r.choice(objs))
    P = r.choice(objs)
    hook_rec(c, 0x65c530, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c530', emu.reg('ecx') - THIS, emu.arg32(0) in Vs, Vs.index(emu.arg32(0)) if emu.arg32(0) in Vs else -1)))
    em.w32(QVT + 0x2a4, pystub(c, 2, ret=0, pop=8, this=True,
                               side=lambda emu, k: emu.calllog.append(('q2a4', emu.reg('ecx') - Q, emu.arg32(0), emu.arg32(1), emu.r32(Q + 0x27), emu.rbytes(Q + 0x1e, 1).hex()))))
    em.w32(QVT + 0x154, pystub(c, 3, ret=0, pop=12, this=True,
                               side=lambda emu, k: emu.calllog.append(('q154', emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.r32(Q + 0x27)))))
    em.w32(TVT + 0x80, pystub(c, 2, ret=0, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('t80', emu.reg('ecx') - THIS, emu.arg32(0), emu.arg32(1)))))
    return [THIS, LIST, n, P, r.getrandbits(32), r.randrange(0, 4)]


S(0x615c30, 'GUESS FUN_615c30', 'thiscall', None, ret=None, gen=g615c30, note='batch246006')


def g49dca0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    flt = [0.0, -0.0, 1.0, 2.5, float('nan'), -1.0]
    FBt = lambda: struct.pack('<f', r.choice(flt))
    THIS = em.alloc(0x40, 4)
    G = em.alloc(0x1000, 4)
    em.w32(0x70039c, G)
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)
    em.w32(G + 0x40, r.getrandbits(32))
    em.w32(G + 0x38, r.getrandbits(32))
    em.wbytes(G + 0x9c7, FBt())
    em.wbytes(G + 0x9c3, FBt())
    RO = rnd(c, 0x10)
    RVT = rnd(c, 0x100)
    em.w32(RO, RVT)
    ub(G + 0x9b, RO)
    # items
    nitems = r.choice([0, 1, 2, 3, 4])
    TXT = [rnd(c, 0x20) for _ in range(6)]
    for t in TXT:
        em.wbytes(t, bytes(r.randrange(1, 256) for _ in range(r.choice([0, 3, 8]))) + b'\0')
    items = []
    bxs = []
    IVT = rnd(c, 0x100)
    for k in range(5):
        it = rnd(c, 0x40)
        em.w32(it, IVT)
        em.wbytes(it + 0x18, bytes([r.choice([0x10, 0x10, 0x10, 0x30, 0, 0x0f])]))
        em.w32(it + 0x14, r.choice([0, 0x100, 0x100, 0x1ff, 0x80]))
        em.w32(it + 0x1c, r.choice([0, 5, 5, 7]))
        bx = rnd(c, 0x10)
        em.w32(bx + 4, r.choice([0, 0, TXT[k]]))
        bxs.append(bx)
        em.w32(it + 0x30, r.choice([0, bx, bx]))
        items.append(it)
    pos = [0]
    em.w32(IVT + 0x14, pystub(c, 0, ret=lambda emu, k: TXT[(items.index(emu.reg('ecx')) + (pos.__setitem__(0, pos[0] + 1) or pos[0])) % 6] if emu.reg('ecx') in items else 0, pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('i14', items.index(emu.reg('ecx')) if emu.reg('ecx') in items else -1))))
    ARR = em.alloc(0x40, 4)
    ids = [r.randrange(1, 100) for _ in range(nitems)]
    for i, v in enumerate(ids):
        em.w32(ARR + 4 * i, v)
    em.w32(THIS + 4, ARR)
    em.w32(THIS + 0x10, nitems)
    em.wbytes(THIS + 0x28, bytes([r.getrandbits(8)]))
    mapping = {v: r.choice(items + [0]) for v in ids}
    MO = rnd(c, 0x10)
    MVT = rnd(c, 0x200)
    em.w32(MO, MVT)
    em.w32(0x70038c, MO)
    em.w32(MVT + 0xcc, pystub(c, 1, ret=lambda emu, k: mapping.get(emu.arg32(0), 0), pop=4, this=True,
                              side=lambda emu, k: emu.calllog.append(('m_cc', emu.reg('ecx') - MO, emu.arg32(0), emu.rbytes(THIS + 0x28, 1).hex()))))
    flagB = r.choice([0, 1, 0x100, 0xff01, 0x10000])
    cur = r.choice([0, 0, items[0], r.choice(items)])
    em.w32(RVT + 0xb8, pystub(c, 0, ret=flagB, pop=0, this=True))
    em.w32(RVT + 4, pystub(c, 0, ret=cur, pop=0, this=True))
    em.w32(RVT + 0x58, pystub(c, 1, ret=lambda emu, k: r.choice(bxs), pop=4, this=True,
                              side=lambda emu, k: emu.calllog.append(('r58', emu.arg32(0)))))

    def txt(emu, p):
        return emu.rbytes(p, 40).split(b'\0')[0].hex()

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.reg('ecx') - G, emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.reg('ecx') - G, emu.arg32(0), emu.arg32(1), txt(emu, emu.arg32(2))))))
    hook_rec(c, 0x49d6c0, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('d6c0', emu.reg('ecx') - THIS, emu.rbytes(THIS + 0x28, 1).hex(), emu.r32(G + 0x38))))
    hook_rec(c, 0x48fcb0, 2, ret=0, pop=8, this=True,
             side=lambda emu, k: emu.calllog.append(('fcb0', emu.reg('ecx'), bxs.index(emu.arg32(0)) if emu.arg32(0) in bxs else -1, items.index(emu.arg32(1)) if emu.arg32(1) in items else -1)))
    hook_rec(c, 0x48f7e0, 1, ret=0, pop=4, this=True,
             side=lambda emu, k: emu.calllog.append(('f7e0', emu.reg('ecx'), items.index(emu.arg32(0)) if emu.arg32(0) in items else -1)))
    return [THIS]


S(0x49dca0, 'GUESS FUN_49dca0', 'thiscall', None, ret=None, gen=g49dca0, note='batch246006')


def g4d96d0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    vals = [0.0, 1.0, -1.0, 2.0, -2.0, 3.0, 0.5, 10.0, -10.0, float('nan')]
    flat = r.random() < 0.45
    base = r.choice([0.0, 1.0, -1.0, 2.0])
    FV = (lambda: base) if flat else (lambda: r.choice(vals[:-1]) if r.random() < 0.97 else vals[-1])
    unp = lambda emu, a: struct.unpack('<3f', emu.rbytes(a, 12))

    CVT = rnd(c, 0x100)

    def mkthis():
        t = em.alloc(0x80, 4)
        for off in (0x30, 0x34, 0x38, 0x40, 0x44, 0x48):
            em.wbytes(t + off, pk(FV()))
        em.wbytes(t + 0x4c, pk(r.choice([0.0, 0.0, -0.0, 1.0, 5.0, float('nan')])))
        em.w32(t + 0x3c, r.choice([0, 0, 0, 0x40000, 0x100000, 0x140000]) if r.random() < 0.15 else r.choice([0, 0x100000]))
        P = em.alloc(0x40, 4)
        for off in range(0x18, 0x30, 4):
            em.w32(P + off, r.getrandbits(32))
        em.w32(P, CVT)
        em.w32(t + 0x54, P)
        em.w32(t + 0x50, 0)
        return t
    chain = [mkthis() for _ in range(r.choice([1, 1, 2, 3]))]
    for i in range(len(chain) - 1):
        em.w32(chain[i] + 0x50, chain[i + 1])
    nodes = []
    for _ in range(2):
        nd = em.alloc(0x80, 4)
        em.w32(nd + 0x3c, r.choice([0, 0, 0, 0x40000, 0x1]))
        if r.random() < 0.6:
            co = rnd(c, 0x10)
            em.w32(co, CVT)
            em.w32(nd + 0x54, co)
        nodes.append(nd)
    em.w32(CVT + 0x60, pystub(c, 0, ret=lambda emu, k: r.choice([0, 0, 0, 1, 0x100, 0x101]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('c60',))))
    node = r.choice(nodes + [0])
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    RO = rnd(c, 0x10)
    RVT = rnd(c, 0x100)
    em.w32(RO, RVT)
    em.wbytes(G + 0x9b, RO.to_bytes(4, 'little'))
    em.w32(RO, RVT)
    em.w32(RVT + 0x70, pystub(c, 0, ret=lambda emu, k: r.choice([0, 0, 0, 1, 0x100]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('r70',))))

    def s4db460(emu, k):
        a, b = emu.arg32(0), emu.arg32(1)
        va, vb = [FV(), FV(), FV()], [FV(), FV(), FV()]
        if flat and r.random() < 0.6:
            tgt = r.choice([va, vb])
            tgt[r.randrange(3)] += r.choice([1.0, -1.0])
        emu.wbytes(a, pk(*va))
        emu.wbytes(b, pk(*vb))
        emu.calllog.append(('db460', emu.reg('ecx') in nodes, emu.rbytes(a, 12).hex(), emu.rbytes(b, 12).hex()))
        return r.choice([1, 1, 1, 0, 0x100, 0x101])
    hook_rec(c, 0x4db460, 2, ret=s4db460, pop=8, this='mark', stackmark=(0, 1))

    def mm(name, fn):
        def s(emu, k):
            o, a, b = emu.reg('ecx'), emu.reg('edx'), emu.arg32(0)
            va, vb = unp(emu, a), unp(emu, b)
            emu.calllog.append((name, emu.rbytes(a, 12).hex(), emu.rbytes(b, 12).hex()))
            emu.wbytes(o, pk(*[fn(x, y) for x, y in zip(va, vb)]))
        return s
    # GUESS stubs: 0x43e920 = componentwise min, 0x43e8e0 = componentwise max (fastcall: ecx out, edx in1, stack in2)
    mn = lambda x, y: x if x < y else y
    mx = lambda x, y: x if x > y else y
    hook_rec(c, 0x43e920, 1, ret=0, pop=4, stackmark=(0,), side=mm('e920', mn))
    hook_rec(c, 0x43e8e0, 1, ret=0, pop=4, stackmark=(0,), side=mm('e8e0', mx))

    def s0d00(emu, k):
        ecx = emu.reg('ecx')
        s = struct.unpack('<f', struct.pack('<I', emu.arg32(0)))[0]
        v = unp(emu, ecx)
        emu.calllog.append(('e0d00', emu.arg32(0), emu.rbytes(ecx, 12).hex()))
        emu.wbytes(ecx, pk(*[f32(x * s) for x in v]))
    hook_rec(c, 0x4e0d00, 1, ret=0, pop=4, this='mark', side=s0d00)

    def sdd060(emu, k):
        t = emu.reg('ecx')
        emu.calllog.append(('dd060', t in chain and chain.index(t), emu.rbytes(emu.arg32(0), 12).hex(), emu.r32(t + 0x3c), emu.rbytes(t + 0x30, 12).hex()))
        emu.wbytes(emu.arg32(0), pk(FV(), FV(), FV()))
    hook_rec(c, 0x4dd060, 1, ret=0, pop=4, this=True, stackmark=(0,), side=sdd060)
    return [chain[0], node]


S(0x4d96d0, 'GUESS FUN_4d96d0', 'thiscall', None, ret=None, gen=g4d96d0, note="batch246006")


def g65a0e0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    flt = [0.0, -0.0, 1.0, 2.5, float('nan'), -1.0]
    FBt = lambda: struct.pack('<f', r.choice(flt))
    THIS = em.alloc(0x300, 4)
    TVT = rnd(c, 0x200)
    em.w32(THIS, TVT)
    VT2 = rnd(c, 0x40)
    em.w32(THIS + 0x1f0, VT2)
    G = em.alloc(0x1000, 4)
    em.w32(0x70039c, G)
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)
    em.wbytes(G + 0x9c7, FBt())
    em.wbytes(G + 0x9c3, FBt())
    # items
    CVT = rnd(c, 0x40)
    items = []
    ents = []
    for k in range(6):
        it = em.alloc(0x80, 4)
        em.wbytes(it + 5, bytes([r.choice([1, 1, 1, 0, 3, 2])]))
        ch = 0
        if r.random() < 0.8:
            ch = em.alloc(0x80, 4)
            em.w32(ch + 0x3c, r.choice([0x1000000, 0x1000000, 0x3000000, 0x2000000, 0, 0x1000001]))
            em.w32(ch + 0x68, r.choice([0, 1, 1]))
            em.wbytes(ch + 0x58, bytes([r.choice([0, 1])]))
        em.w32(it + 0x38, ch)
        n = r.choice([0, 1, 2, 3])
        em.wbytes(it + 0x3d, bytes([n]))
        arr = em.alloc(0x40, 4)
        em.w32(it + 0x40, arr)
        for j in range(n):
            if r.random() < 0.8:
                e = em.alloc(0x40, 4)
                if r.random() < 0.8:
                    co = em.alloc(0x10, 4)
                    em.w32(co, CVT)
                    em.w32(e + 0x18, co)
                em.w32(arr + 8 * j, e)
                ents.append(e)
        items.append(it)
    # set structure: nodes of item pointers
    sizes = [r.choice([0, 1, 2, 3]) for _ in range(2)]
    if sum(sizes) == 0:
        sizes[0] = 1
    nodes = []
    pool = list(items)
    r.shuffle(pool)
    cnt = 0
    for sz in sizes:
        nd = em.alloc(0x40, 4)
        em.w32(nd, sz)
        for j in range(sz):
            em.w32(nd + 0x10 + 4 * j, pool[cnt])
            cnt += 1
        nodes.append(nd)
    em.w32(nodes[0] + 8, nodes[1] if sizes[1] and r.random() < 0.9 else 0)
    em.w32(nodes[1] + 8, 0)
    first = nodes[0] if sizes[0] else (nodes[1] if sizes[1] else 0)
    if first == nodes[1] and sizes[0] == 0:
        pass
    pitems = lambda emu, p: emu.r32(p)

    def s0c(emu, k):
        a = emu.arg32(0)
        if sizes[0] == 0:
            nd = nodes[0]
            # empty first node: start at the second if present
            nd = nodes[1] if sizes[1] else 0
            if nd:
                emu.wbytes(a, struct.pack('<3I', nd + 0x10, 0, nd))
            else:
                emu.wbytes(a, struct.pack('<3I', 0, 0, 0))
        else:
            emu.wbytes(a, struct.pack('<3I', nodes[0] + 0x10, 0, nodes[0]))
        emu.calllog.append(('v0c', emu.reg('ecx') - THIS, emu.rbytes(a, 12).hex().replace('', '') if False else 'it'))
    em.w32(VT2 + 0xc, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s0c))

    def s10(emu, k):
        a = emu.arg32(0)
        cur, idx, nd = struct.unpack('<3I', emu.rbytes(a, 12))
        emu.calllog.append(('v10', items.index(emu.r32(cur)) if emu.r32(cur) in items else -1))
        idx += 1
        if idx == emu.r32(nd):
            nd = emu.r32(nd + 8)
            if nd:
                idx = 0; cur = nd + 0x10
            else:
                cur = 0
        else:
            cur += 4
        emu.wbytes(a, struct.pack('<3I', cur, idx, nd))
    em.w32(VT2 + 0x10, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s10))
    em.w32(TVT + 0x80, pystub(c, 1, ret=0, pop=4, this=True,
                              side=lambda emu, k: emu.calllog.append(('t80', emu.reg('ecx') - THIS, items.index(emu.arg32(0)) if emu.arg32(0) in items else -1))))
    em.w32(TVT + 0xe8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, stackmark=(0,),
                              side=lambda emu, k: emu.calllog.append(('t0e8', emu.reg('ecx') - THIS, items.index(emu.arg32(1)) if emu.arg32(1) in items else -1))))
    em.w32(CVT + 8, pystub(c, 4, ret=lambda emu, k: r.choice([0, 0, 1, 0x100, 0x101, 0xff]), pop=16, this=True, stackmark=(2,),
                           side=lambda emu, k: emu.calllog.append(('c8', ents.index(emu.arg32(0)) if emu.arg32(0) in ents else -1, emu.arg32(1) - THIS, emu.arg32(3)))))
    hook_rec(c, 0x4dad20, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('dad20', emu.rbytes(emu.reg('ecx') + 0x3c, 4).hex())))
    hook_rec(c, 0x4dd0c0, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('dd0c0', emu.rbytes(emu.reg('ecx') + 0x3c, 4).hex())))
    hook_rec(c, 0x658d30, 0, ret=lambda emu, k: r.choice([0, 0, 0, 1]), pop=0, this=True,
             side=lambda emu, k: emu.calllog.append(('d30', items.index(emu.reg('ecx')) if emu.reg('ecx') in items else -1)))

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    return [THIS]


S(0x65a0e0, 'GUESS FUN_65a0e0', 'thiscall', None, ret=None, gen=g65a0e0, note='batch246006')


def g43a130(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    fl = [0.0, 1.0, -1.0, 0.5, -0.5, 0.00012, 0.00013, -0.00012, -0.00013, 0.7, 2.0, -2.0, 100.0, 0.3333333, 1e-7, 1.0000001, 255.0, 0.99999994, 0.0001220703125, -0.0001220703125, 0.0001220703125, -0.0001220703125]
    FVf = lambda: (r.choice(fl) if r.random() < 0.85 else f32(r.uniform(-2, 2)))
    BUF = rnd(c, 0x400)
    TH = em.alloc(0x1400, 4)
    em.w32(TH + 0x131c, BUF)
    key_i = r.randrange(3)
    em.w32(0x6e48b8 + 16 * key_i, r.choice([0, 0x10, 0x20, 0x08]))    # table offset field
    em.w32(0x6e48b8 + 16 * key_i + 12, r.choice([0, 1, 8, 0x18, 0x20, 0x30]))   # length field
    key = em.r32(0x6e48c0 + 16 * key_i)
    DEV = rnd(c, 0x10)
    em.w32(0x7003a0, DEV if r.random() > 0.08 else 0)
    P = rnd(c, 0x10)
    PVT = rnd(c, 0x100)
    em.w32(P, PVT)
    nullp = r.random() < 0.1
    OBJ = r.getrandbits(32)
    hook_rec(c, 0x435e90, 1, ret=lambda emu, k: 0 if nullp else P, pop=4, this=True,
             side=lambda emu, k: emu.calllog.append(('e90', emu.reg('ecx') - DEV, emu.arg32(0))))
    okflag = r.choice([1, 1, 1, 0, 0x100])
    em.w32(PVT + 0x14, pystub(c, 1, ret=okflag, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('v14', emu.arg32(0)))))
    for slot in (0x2c, 0x28, 0x30):
        em.w32(PVT + slot, pystub(c, 1, ret=0, pop=4, this=True, st0=lambda emu, k: FVf(),
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('vf', slot, emu.arg32(0)))))
    return [TH, OBJ, key]


S(0x43a130, 'GUESS FUN_43a130', 'thiscall', None, ret=None, gen=g43a130, note='batch246006')


def g6097d0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    fl = [0.0, 1.0, -1.0, 0.5, 2.0, 3.0, 0.7853982, 1.0471976, 100.0, 1000.0, 0.1, 4.0, -2.0, 1.3333334, 0.0001, 16.0]
    sane = r.random() < 0.7
    FVf = (lambda: r.choice([0.5, 1.0, 2.0, 3.0, 0.25, 1.5, 10.0, 100.0])) if sane else (lambda: (r.choice(fl) if r.random() < 0.85 else f32(r.uniform(-5, 5))))
    FP = (lambda: r.choice([0.5, 1.0, 1.5, 0.7853982, 1.0471976])) if sane else (lambda: (r.choice([0.5, 1.0, 2.0, 0.7853982, 1.0471976, 0.0, 100.0, -1.0, 1.5]) if r.random() < 0.9 else f32(r.uniform(0, 3))))
    THIS = rnd(c, 0x20)
    TVT = rnd(c, 0x200)
    em.w32(THIS, TVT)
    SO = rnd(c, 0x80)
    SVT = rnd(c, 0x300)
    em.w32(SO, SVT)
    for off in (0x3c, 0x40, 0x64, 0x68):
        em.wbytes(SO + off, struct.pack('<f', FVf()))
    em.wbytes(SO + 0x5c, struct.pack('<f', FP()))
    em.wbytes(SO + 0x48, bytes([r.choice([0, 0, 1, 2, 3, 0x80])]))
    OUT = rnd(c, 0x40)
    RECT = rnd(c, 0x10)
    w = r.choice([640, 800, 1024, 1]) if sane else r.choice([0, 640, 800, 1024, 1, 0xffffff00, 0x80000000, r.getrandbits(32)])
    h = r.choice([480, 600, 768, 1]) if sane else r.choice([0, 480, 600, 768, 1, 0xffffff00, r.getrandbits(32)])
    x0 = r.choice([0, 0, 10, 0xfffffff0])
    y0 = r.choice([0, 0, 5])
    em.wbytes(RECT, struct.pack('<4I', x0, y0, (x0 + w) & 0xffffffff, (y0 + h) & 0xffffffff))
    ia = r.choice([640, 800, 1024, 1280]) if sane else r.choice([640, 800, 1024, 1, 0, -5 & 0xffffffff, 1280])
    ib = r.choice([480, 600, 768, 720]) if sane else r.choice([480, 600, 768, 1, 3, 0, 720])
    em.w32(TVT + 0xd8, pystub(c, 0, ret=ia, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('d8',))))
    em.w32(TVT + 0xdc, pystub(c, 0, ret=ib, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('dc',))))
    em.w32(TVT + 0xe8, pystub(c, 0, ret=0, pop=0, this=True, st0=lambda emu, k: FVf(), side=lambda emu, k: emu.calllog.append(('e8',))))
    em.w32(SVT + 0x248, pystub(c, 0, ret=0, pop=0, this=True, st0=lambda emu, k: FVf(), side=lambda emu, k: emu.calllog.append(('s248',))))
    return [THIS, OUT, SO, RECT, r.choice([0, 1, 0x100, 0xff, 0x10, 0xf0])]


S(0x6097d0, 'GUESS FUN_6097d0', 'thiscall', None, ret=None, gen=g6097d0, nan_heap=True, note='batch246006')


def g653cc0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    THIS = rnd(c, 0x20)
    VT = rnd(c, 0x300)
    em.w32(THIS, VT)
    stk = (0,)
    log = lambda tag, *a: (lambda emu, k: emu.calllog.append((tag,) + tuple(a(emu) if callable(a[0]) else a)))
    em.w32(VT + 0xf0, pystub(c, 0, ret=r.choice([0, 1, 3, 10, 0x80000000]), pop=0, this=True, side=lambda emu, k: emu.calllog.append(('f0',))))
    em.w32(VT + 0x114, pystub(c, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('v114', emu.arg32(0)))))
    ia = r.choice([640, 800, 1024, 1, 0, 3])
    ib = r.choice([480, 600, 768, 1, 0, 7])
    em.w32(VT + 0xd8, pystub(c, 0, ret=ia, pop=0, this=True))
    em.w32(VT + 0xdc, pystub(c, 0, ret=ib, pop=0, this=True))
    em.w32(VT + 0x134, pystub(c, 4, ret=0, pop=16, this=True, side=lambda emu, k: emu.calllog.append(('v134', [emu.arg32(i) for i in range(4)]))))
    em.w32(VT + 0x150, pystub(c, 4, ret=0, pop=16, this=True, side=lambda emu, k: emu.calllog.append(('v150', [emu.arg32(i) for i in range(4)]))))
    em.w32(VT + 0x14c, pystub(c, 7, ret=0, pop=28, this=True, side=lambda emu, k: emu.calllog.append(('v14c', [emu.arg32(i) for i in range(7)]))))
    em.w32(VT + 0x15c, pystub(c, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('v15c', emu.arg32(0)))))
    fl = [1.0, 2.0, 0.5, 16.0, 8.0, 12.0, 0.25, -4.0, 0.0, 7.0, 1000.0, 3.0]
    FVf = lambda: r.choice(fl) if r.random() < 0.9 else f32(r.uniform(-20, 20))
    em.w32(VT + 0xf4, pystub(c, 0, ret=0, pop=0, this=True, st0=lambda emu, k: FVf()))
    em.w32(VT + 0xf8, pystub(c, 0, ret=0, pop=0, this=True, st0=lambda emu, k: FVf()))

    def s25c(emu, k):
        v = emu.arg32(1)
        vs = []
        for q in range(4):
            b = v + 0x24 * q
            vs.append([emu.r32(b + 4 * j) for j in (0, 1, 2, 6, 7, 8)])
        emu.calllog.append(('v25c', emu.arg32(0), emu.arg32(2), vs, emu.rbytes(emu.arg32(3), 8).hex(), emu.arg32(4)))
    em.w32(VT + 0x25c, pystub(c, 5, ret=0, pop=20, this=True, stackmark=(1, 3), side=s25c))
    B = r.choice([0, 1, 2, 3, 5])
    L = r.choice([-1, 0, 1, 2, 3, 4])
    TXT = rnd(c, 0x80)
    pool = [0, 10, 32, 65, 66, 97, 0x7f, 0x80, 0xff, 0xe9, 48, 49]
    data = bytes(r.choice(pool) if r.random() < 0.8 else r.getrandbits(8) for _ in range(0x40))
    em.wbytes(TXT, data)
    for ch_ in set(data):
        sc = ch_ - 256 if ch_ >= 128 else ch_
        em.wbytes(0x7f5c10 + sc * 8, struct.pack('<2f', f32(r.uniform(0, 1)), f32(r.uniform(0, 1))))
    return [THIS, TXT if r.random() > 0.05 else 0, B, L & 0xffffffff]


S(0x653cc0, 'GUESS FUN_653cc0', 'thiscall', None, ret=None, gen=g653cc0, note='batch246006')


def g5f4170(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    fl = [0.0, 1.0, -1.5, 3.25, 1e10, 0.1]
    THIS = em.alloc(0x300, 4)
    em.w32(THIS + 0x24, r.getrandbits(32))
    # logger and streams
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    arities = [1, 2, 2, 1]
    streams = []
    for i, na in enumerate(arities):
        so = rnd(c, 0x10)
        sv = rnd(c, 0x100)
        em.w32(so, sv)
        em.w32(sv + 0x2c, pystub(c, 1 + na, ret=0, pop=0, side=lambda emu, k, i=i, na=na: emu.calllog.append(('s2c', i, [emu.arg32(j) for j in range(1 + na)]))))
        streams.append(so)
    cnt = [0]

    def s20(emu, k):
        i = cnt[0]
        cnt[0] += 1
        emu.calllog.append(('l20', emu.reg('ecx') - LO, emu.arg32(0), emu.arg32(1)))
        return streams[i % 4]
    em.w32(LVT + 0x20, pystub(c, 2, ret=s20, pop=8, this=True))
    # Y (0x724270), O, H
    Y = rnd(c, 0x10)
    YVT = rnd(c, 0x100)
    em.w32(Y, YVT)
    em.w32(0x724270, Y)
    em.w32(YVT + 0x1c, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('y1c', emu.reg('ecx') - Y, emu.arg32(0)))))

    def s0c(emu, k):
        fmt = emu.arg32(1)
        n = 5 if fmt == 0x6b8b2c else 6
        emu.calllog.append(('y0c', emu.arg32(0) - Y, [emu.arg32(j) for j in range(1, n)]))
    em.w32(YVT + 0xc, pystub(c, 2, ret=0, pop=0, side=s0c))
    OO = rnd(c, 0x80)
    OB = rnd(c, 0x10)
    OVT = rnd(c, 0x100)
    em.w32(OB, OVT)
    em.w32(OO + 0x3c, OB)
    em.w32(0x724278, OO)
    em.w32(OVT + 8, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('o8', emu.reg('ecx') - OB, emu.arg32(0)))))
    HO = rnd(c, 0x120)
    HVT = rnd(c, 0x20)
    em.w32(HO, HVT)
    em.w32(HO + 0x98, r.getrandbits(32))
    ub(THIS + 0x96, HO)
    em.w32(HVT, pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('h0', emu.reg('ecx') - HO, emu.arg32(0)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    # ring
    n = r.choice([1, 2, 3, 4, 5])
    ub(THIS + 0xba, n)
    base = THIS + 0xbe
    for i in range(n):
        kind = r.choice([1, 2, 3, 1, 2, 3, 0, 4, 7])
        if r.random() < 0.15:
            kind = 0
        rec = base + 20 * i
        em.w32(rec, kind)
        em.w32(rec + 4, struct.unpack('<I', struct.pack('<f', r.choice(fl)))[0])
        em.w32(rec + 8, r.getrandbits(32))
        em.w32(rec + 0xc, r.getrandbits(32))
        em.w32(rec + 0x10, r.getrandbits(32))
    h = r.randrange(n)
    ub(THIS + 0xb6, base + 20 * h)
    return [THIS]


S(0x5f4170, 'GUESS FUN_5f4170', 'thiscall', None, ret=None, gen=g5f4170, note='batch246006')


def g480640(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    unp = lambda emu, a: struct.unpack('<3f', emu.rbytes(a, 12))
    vals = [0.0, 1.0, -1.0, 2.0, 0.5, 10.0, -3.0]
    FV = lambda: r.choice(vals)
    THIS = em.alloc(0x40, 4)
    TVT = rnd(c, 0x100)
    em.w32(THIS, TVT)
    N = r.choice([0, 1, 2, 3, 4])
    em.w32(THIS + 0x18, N)
    em.w32(THIS + 0x1c, struct.unpack('<I', struct.pack('<f', r.choice([0.0, 1.0, 5.0, -2.0])))[0])
    em.w32(THIS + 8, r.choice([0x1234, 0x5678]))
    AO = rnd(c, 0x80)
    AVT = rnd(c, 0x300)
    em.w32(AO, AVT)
    em.w32(AO + 0x68, struct.unpack('<I', struct.pack('<f', r.choice([0.0, 1.0, 5.0, 100.0])))[0])
    BO = rnd(c, 0x20)
    em.w32(BO + 8, struct.unpack('<I', struct.pack('<f', r.choice([0.0, 0.5, 5.0, 200.0, -1.0, 1.0])))[0])
    em.w32(AVT + 0x274, pystub(c, 2, ret=0, pop=8, this=True, stackmark=(0,),
                               side=lambda emu, k: emu.calllog.append(('a274', emu.rbytes(emu.arg32(0), 12).hex(), emu.arg32(1)))))

    def a84(emu, k):
        emu.wbytes(emu.arg32(0), pk(FV(), FV(), FV()))
    em.w32(AVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=a84))
    em.w32(TVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=a84))

    def a88(emu, k):
        p = emu.arg32(0)
        emu.calllog.append(('a88', emu.rbytes(p, 12).hex()))
        v = unp(emu, p)
        emu.wbytes(p, pk(*[f32(x + 1.0) for x in v]))
    em.w32(AVT + 0x88, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=a88))
    G = em.alloc(0x1b00, 4)
    em.w32(0x70039c, G)
    O1 = rnd(c, 0x40)
    O2 = rnd(c, 0x20)
    O2VT = rnd(c, 0x100)
    em.w32(O2, O2VT)
    em.w32(O1 + 0x1c, O2)
    em.wbytes(G + 0x1aa3, O1.to_bytes(4, 'little'))
    results = [(r.choice([0, 0, 0, 1]), r.choice([0, 1])) for _ in range(6)]
    cnt = [0]
    this8 = em.r32(THIS + 8)

    def t34(emu, k):
        i = cnt[0]
        cnt[0] += 1
        a = [emu.arg32(j) for j in range(8)]
        emu.calllog.append(('t34', i, emu.r32(a[0]), emu.rbytes(a[2], 12).hex(), emu.rbytes(a[3], 12).hex(), a[1], a[4], a[5], a[6], a[7]))
        same = results[i % 6][1]
        emu.w32(a[0] + 0x10, this8 if same else this8 + 1)
        return results[i % 6][0] | (r.choice([0, 0x100]) if results[i % 6][0] else 0)
    em.w32(O2VT + 0x34, pystub(c, 8, ret=t34, pop=32, this=True, stackmark=(0, 2, 3)))
    C = r.choice([0, 255, 100, 1, 0x80000000, 17])
    return [THIS, AO, BO, C, r.getrandbits(32)]


S(0x480640, 'GUESS FUN_480640', 'thiscall', None, ret='eax', gen=g480640, note='batch246006')


def g439c20(c):
    import struct
    import pe_emu
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    st = lambda emu: emu.r32(emu.r32(pe_emu.TEB) + 8)
    sr = [seh_record(c, 2) for _ in range(8)]

    def log(emu, k, tag, j, *extra):
        emu.calllog.append((tag, st(emu)) + extra)
        sr[j](emu, k)

    def cs(emu, a):
        return emu.rbytes(a, 100).split(b'\0')[0].hex()

    THIS = em.alloc(0x40, 4)
    R = em.alloc(0x40, 4)
    if r.random() < 0.7:
        em.w32(R + 4, 3)
        em.w32(THIS + 8, R + 4)
    else:
        X1 = em.alloc(0x20, 4)
        em.w32(X1, 1)
        em.w32(X1 + 8, R + 4)
        em.w32(THIS + 8, X1)
    Q = em.alloc(0x1400, 4)
    QVT = rnd(c, 0x100)
    em.w32(Q, QVT)
    ub(R + 0x11, Q)
    em.w32(Q + 0x1210, r.choice([0, 2, 4, 0x7fffffff, 0xffffffff]))
    BASE = em.alloc(0x80, 4)
    ub(Q + 0x1344, BASE)
    for i in range(6):
        em.w32(BASE + 10 * i, r.getrandbits(32) if False else 0x1000 + i)
        em.w32(BASE + 10 * i + 4, r.getrandbits(32))
    idxs = [r.choice([-1, 0, 1, 2, 3, 5, 0]) & 0xffffffff for _ in range(8)]
    pos = [0]

    def q64(emu, k):
        i = pos[0]
        pos[0] += 1
        log(emu, k, 'q64', 0, cs(emu, emu.arg32(0)))
        return idxs[i % 8]
    em.w32(QVT + 0x64, pystub(c, 1, ret=q64, pop=4, this=True, stackmark=(0,)))
    LVT = rnd(c, 0x20)
    if r.random() < 0.5:
        LST = em.alloc(0x20, 4)
        em.w32(LST, LVT)
        ub(THIS + 0xd, LST)
    blocks = [em.alloc(0x40, 4) for _ in range(6)]

    def s_slot4(emu, k):
        b = blocks[pos[0] % 6]
        log(emu, k, 'l4', 1, emu.arg32(0))
        return b + 4
    em.w32(LVT + 4, pystub(c, 1, ret=s_slot4, pop=4, this=True))
    RAW = em.alloc(0x40, 4)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: RAW, pop=0, side=lambda emu, k: log(emu, k, 'a1c', 2, emu.arg32(0)))

    def c4ccbe0(emu, k):
        emu.w32(emu.reg('ecx'), LVT)
        log(emu, k, 'c4cc', 3, emu.reg('ecx') - RAW, emu.arg32(0), emu.arg32(1))
    hook_rec(c, 0x4ccbe0, 2, ret=lambda emu, k: emu.reg('ecx'), pop=8, this=True, side=c4ccbe0)
    nodes = [em.alloc(0x20, 4) for _ in range(8)]
    ncnt = [0]

    def c4382e0(emu, k):
        n = nodes[ncnt[0] % 8]
        ncnt[0] += 1
        log(emu, k, 'n382', 4, emu.reg('ecx'))
        return n
    hook_rec(c, 0x4382e0, 0, ret=c4382e0, pop=0, this=True)
    hook_rec(c, 0x437b00, 1, ret=0, pop=4, this=True, stackmark=(0,),
             side=lambda emu, k: log(emu, k, 'c437', 5, emu.reg('ecx') - THIS, cs(emu, emu.arg32(0))))
    LO = rnd(c, 0x10)
    LOVT = rnd(c, 0x100)
    em.w32(LO, LOVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LOVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, stackmark=(2,),
                              side=lambda emu, k: log(emu, k, 'x2c', 6, emu.arg32(1), cs(emu, emu.arg32(2)))))

    def strchr_h(emu, res_):
        s = emu.arg32(0)
        ch = emu.arg32(1) & 0xff
        data = emu.rbytes(s, 0x200).split(b'\0')[0]
        i = data.find(bytes([ch]))
        emu.calllog.append(('strchr', ch, data.hex()))
        emu.ret(eax=(s + i) if i >= 0 else 0, argbytes=0)
    em.w32(0x676254, em.stub_fn('strchr', strchr_h))
    nseg = r.choice([0, 1, 2, 3])
    segs = [bytes(r.choice(b'abcXYZ019_') for _ in range(r.choice([0, 1, 3, 6]))) for _ in range(nseg)]
    rest = bytes(r.choice(b'abcXYZ019_') for _ in range(r.choice([0, 0, 2, 5])))
    txt = b'>'.join(segs + [rest]) if segs else rest
    if segs:
        txt = b''.join(sg + b'>' for sg in segs) + rest
    STR = rnd(c, 0x100)
    em.wbytes(STR, txt + b'\0')
    return [THIS, STR if r.random() > 0.05 else 0]


S(0x439c20, 'GUESS FUN_439c20', 'thiscall', None, ret=None, gen=g439c20, note='batch246006')


def g652420(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    THIS = em.alloc(0x20, 4)
    TVT = rnd(c, 0x300)
    em.w32(THIS, TVT)
    AO = rnd(c, 0x10)
    AVT = rnd(c, 0x20)
    em.w32(AO, AVT)
    bufs = [em.alloc(0x40, 4) for _ in range(8)]
    cnt = [0]

    def a4(emu, k):
        b = bufs[cnt[0] % 8]
        cnt[0] += 1
        emu.calllog.append(('a4', emu.arg32(0), emu.reg('ecx') - AO))
        return b
    em.w32(AVT + 4, pystub(c, 1, ret=a4, pop=4, this=True))
    np_ = r.choice([0, 1, 2, 3])
    nv = r.choice([0, 1, 2, 3, 4, 5, 6, 7])
    PL = em.alloc(0x80, 4)
    wch = r.choice([-100.0, -1.0, -0.5, 0.0, 1.0, 3.0])
    for k in range(np_):
        em.wbytes(PL + 16 * k, pk(r.choice([1.0, 0.0, -1.0]), r.choice([0.0, 1.0, -1.0]), r.choice([0.0, 1.0]), wch if r.random() < 0.7 else r.choice([-2.0, 0.0, 2.0])))
    VS = em.alloc(0x100, 4)
    for i in range(nv):
        em.wbytes(VS + 16 * i, pk(float(r.randrange(-3, 4)), float(r.randrange(-3, 4)), float(r.randrange(-3, 4))) + struct.pack('<I', r.getrandbits(32)))
    em.w32(TVT + 0x258, pystub(c, 6, ret=0, pop=24, this=True, stackmark=(3, 4),
                               side=lambda emu, k: emu.calllog.append(('v258', emu.reg('ecx') - THIS, emu.arg32(0) - AO, emu.arg32(1) - PL, emu.arg32(2),
                                                                       emu.rbytes(emu.arg32(3), 36).hex(), emu.rbytes(emu.arg32(4), 36).hex(), emu.arg32(5)))))
    return [THIS, AO, PL, np_, VS, nv, r.getrandbits(32)]


S(0x652420, 'GUESS FUN_652420', 'thiscall', None, ret=None, gen=g652420, note='batch246006')


def g61bfe0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    blocks = []
    nullobj = False   # a null object faults on both sides (the exe writes through edi + 0xc before testing edi)
    nullmid = r.random() < 0.1
    sizes = {0x274: 0x280, 0x100: 0x100, 0x400: 0x400}

    def alloc_h(emu, k):
        sz = emu.arg32(0)
        emu.calllog.append(('alloc', sz))
        if (sz == 0x274 and nullobj) or (sz != 0x274 and nullmid and r.random() < 0.5):
            return 0
        b = rnd(c, sizes.get(sz, 0x100))
        blocks.append(b)
        return b
    ALLOC = pystub(c, 1, ret=alloc_h, pop=0)
    if r.random() < 0.6:
        AL = rnd(c, 0x10)
        em.w32(AL, ALLOC)
        em.w32(AL + 4, r.getrandbits(32))
        em.w32(AL + 8, r.getrandbits(32))
    else:
        AL = 0
        em.w32(0x6762f0, ALLOC)
        em.w32(0x6762f4, r.getrandbits(32))
        em.w32(0x6762ec, r.getrandbits(32))

    def rel(emu, a):
        return a - blocks[0] if blocks and 0 <= a - blocks[0] < 0x300 else (-1 if not blocks else a)

    def mk(addr, nargs, retf, tag):
        hook_rec(c, addr, nargs, ret=retf, pop=0, side=lambda emu, k: emu.calllog.append((tag,) + tuple(rel(emu, emu.arg32(i)) for i in range(nargs))))
    mk(0x6204f0, 2, lambda emu, k: r.choice([0, 1, 0x1234, 5]), 'h6204f0')
    mk(0x61f2c0, 2, lambda emu, k: r.choice([1, 1, 1, 0, 0x77]), 'h61f2c0')
    mk(0x626ac0, 3, lambda emu, k: 0, 'h626ac0')
    mk(0x626a80, 3, lambda emu, k: 0, 'h626a80')
    mk(0x620e70, 2, lambda emu, k: r.choice([1, 1, 0, 5]), 'h620e70')
    mk(0x61c3d0, 1, lambda emu, k: 0, 'h61c3d0')
    A0 = r.choice([0, 0, 0x4000, r.getrandbits(32)])
    A2 = 0
    if r.random() < 0.5:
        A2 = rnd(c, 0x10)
    return [A0, AL, A2]


S(0x61bfe0, 'GUESS FUN_61bfe0', 'cdecl', None, ret='eax', gen=g61bfe0, note='batch246006')


def g4d6c60(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    THIS = em.alloc(0x80, 4)
    ub(THIS + 0x11, r.getrandbits(32))
    ub(THIS + 0x2e, r.getrandbits(32))
    ub(THIS + 0x40 - 0, r.getrandbits(32))
    em.w32(THIS + 0x3c, r.choice([0, 0, 1]))
    F = rnd(c, 0x10)
    FVT = rnd(c, 0x100)
    em.w32(F, FVT)
    ub(THIS + 0x15, F)
    # the "file"
    stream = bytearray()
    entry_pos = []
    for _ in range(r.choice([0, 1, 2, 3])):
        sig = 0x2014b50 if r.random() > 0.12 else r.choice([0x1234abcd, 0x04034b50])
        stream += struct.pack('<I', sig)
        entry_pos.append(len(stream))
        if sig != 0x2014b50:
            continue
        nl, el, cl = r.choice([0, 1, 4, 7]), r.choice([0, 0, 1, 3]), r.choice([0, 0, 1, 2])
        hdr = bytearray(r.getrandbits(8) for _ in range(0x2a))
        struct.pack_into('<H', hdr, 0x18, nl)
        struct.pack_into('<H', hdr, 0x1a, el)
        struct.pack_into('<H', hdr, 0x1c, cl)
        stream += bytes(hdr) + bytes(r.randrange(1, 256) for _ in range(nl)) + bytes(r.getrandbits(8) for _ in range(el + cl))
    end = r.choice([struct.pack('<I', 0x6054b50), struct.pack('<I', 0x52756e65), b''])
    stream += end
    pos = [0]
    badread = r.random() < 0.08
    nrd = [0]

    def read_h(emu, k):
        dst, n, h = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        d = bytes(stream[pos[0]:pos[0] + n])
        d += bytes(n - len(d))
        emu.wbytes(dst, d)
        pos[0] += n
        nrd[0] += 1
        emu.calllog.append(('rd', n, h, d.hex()))
        return (n - 1) if (badread and nrd[0] == 3) else n
    em.w32(FVT + 0x14, pystub(c, 3, ret=read_h, pop=12, this=True, stackmark=(0,)))

    def seek_h(emu, k):
        emu.calllog.append(('seek', emu.arg32(0), emu.arg32(1), emu.arg32(2)))
        pos[0] = 0
    em.w32(FVT + 0x10, pystub(c, 3, ret=0, pop=12, this=True, side=seek_h))
    em.w32(FVT + 0xc, pystub(c, 1, ret=lambda emu, k: pos[0], pop=4, this=True, side=lambda emu, k: emu.calllog.append(('tell', emu.arg32(0)))))
    em.w32(FVT + 0x1c, pystub(c, 1, ret=lambda emu, k: 1 if pos[0] >= len(stream) else 0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('eof', pos[0]))))
    # known-position list
    known = [p for p in entry_pos if r.random() < 0.4]
    cnt = len(known) + r.choice([0, 0, 1])
    ARR = em.alloc(0x40, 4)
    for i, p in enumerate(known):
        em.w32(ARR + 4 * i, p)
    for i in range(len(known), cnt):
        em.w32(ARR + 4 * i, 0x7777 + i)
    ub(THIS + 0x62, cnt)
    ub(THIS + 0x66, ARR)
    M = rnd(c, 0x10)
    MVT = rnd(c, 0x20)
    em.w32(M, MVT)
    ub(THIS + 0x6a, M)

    def cs(emu, a):
        return emu.rbytes(a, 40).split(b'\0')[0].hex()
    em.w32(MVT + 4, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(0, 1),
                           side=lambda emu, k: emu.calllog.append(('m4', emu.reg('ecx') - M, cs(emu, emu.arg32(0)), emu.rbytes(emu.arg32(1), 26).hex(), emu.arg32(2)))))
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    em.w32(LVT + 0x24, pystub(c, 2, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('l24', emu.arg32(0) - LO, emu.arg32(1)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    return [THIS]


S(0x4d6c60, 'GUESS FUN_4d6c60', 'thiscall', None, ret=None, gen=g4d6c60, note='batch246006')


def g55a3e0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    unp = lambda emu, a: struct.unpack('<3f', emu.rbytes(a, 12))
    vals = [0.0, 1.0, -1.0, 2.0, -2.0, 0.5, 10.0, float('nan')]
    FV = lambda: r.choice(vals[:-1]) if r.random() < 0.96 else vals[-1]
    THIS = em.alloc(0x40, 4)
    W = rnd(c, 0x10)
    WVT = rnd(c, 0x100)
    em.w32(W, WVT)
    em.w32(THIS + 0x1c, W)
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    E0 = rnd(c, 0x10)
    em.w32(E0, r.getrandbits(32))
    em.wbytes(E0 + 4, bytes([r.choice([0, 0, 1, 1, 2, 5])]))
    ents = [rnd(c, 0x10) for _ in range(3)]
    for e in ents:
        em.wbytes(e + 4, bytes([r.choice([0, 0, 2, 2, 1, 5])]))

    def s3d0(emu, k):
        ec = emu.reg('ecx')
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', 1 if ec == P1 else 2 if ec == P2 else -1, i))
        return E0 if ec == P1 else ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    RO = rnd(c, 0x10)
    RVT = rnd(c, 0x100)
    em.w32(RO, RVT)
    em.wbytes(G + 0x9b, RO.to_bytes(4, 'little'))
    OBJ = rnd(c, 0x20)
    OVT = rnd(c, 0x200)
    em.w32(OBJ, OVT)
    SUB = rnd(c, 0x10)
    em.w32(OBJ + 8, SUB)
    em.w32(RVT + 0x58, pystub(c, 1, ret=OBJ, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('r58', emu.arg32(0) == em.r32(E0)))))

    def mod(tag):
        def f(emu, k):
            p = emu.arg32(0)
            emu.calllog.append((tag, emu.rbytes(p, 12).hex()))
            if r.random() < 0.7:
                emu.wbytes(p, pk(FV(), FV(), FV()))
        return f
    em.w32(WVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=mod('w84')))
    em.w32(OVT + 0x8c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=mod('o8c')))
    em.w32(OVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=mod('o84')))

    def s7c0(emu, k):
        p = emu.arg32(0)
        emu.wbytes(p, pk(FV(), FV(), FV()))
        emu.calllog.append(('d7c0', emu.reg('ecx') - SUB, emu.rbytes(p, 12).hex()))
    hook_rec(c, 0x4db7c0, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s7c0)
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    return [THIS, SRC]


S(0x55a3e0, 'GUESS FUN_55a3e0', 'thiscall', None, ret=None, gen=g55a3e0, note='batch246006')


def g49bbc0(c):
    import struct
    from pilot import F
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    A = em.alloc(0x80, 4)
    em.wbytes(A, pk(*[r.choice([1.0, 0.0, 0.5, -1.0, 2.0]) for _ in range(16)]))
    B = em.alloc(0x20, 4)
    em.wbytes(B, pk(*[r.choice([0.0, 1.0, -1.0, 0.5]) for _ in range(3)]))
    flat = r.random() < 0.4
    if flat:
        em.wbytes(A, pk(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1))
        em.wbytes(B, pk(0, 0, 0))
    IO = rnd(c, 0x10)
    IVT = rnd(c, 0x100)
    em.w32(IO, IVT)
    pts = [(float(r.randrange(-2, 3)), float(r.randrange(-2, 3)), float(r.randrange(0, 4))) for _ in range(6)]
    nodes = []
    for _ in range(r.choice([0, 1, 2, 3])):
        n = em.alloc(0x30, 4)
        tri = [r.choice(pts) for _ in range(3)]
        if r.random() < 0.7:
            tri = [(float(r.randrange(-3, 4)), float(r.randrange(-3, 4)), float(r.randrange(-3, 6))) for _ in range(3)]
        if flat:
            P3 = [(0.0, 0.0, 5.0), (3.0, 4.0, 5.0), (0.0, 3.0, 4.0), (0.0, 0.0, 1.0), (6.0, 8.0, 10.0), (0.0, 0.0, 2.0)]
            tri = [r.choice(P3) for _ in range(3)]
        q = r.random()
        if q < 0.12:
            tri[1] = (tri[0][0], tri[0][1], tri[0][2] + 1.0)
        elif q < 0.24:
            tri[2] = (tri[1][0], tri[1][1], tri[1][2] + 1.0)
        elif q < 0.3:
            tri[2] = (tri[0][0], tri[0][1], tri[0][2] + 1.0)
        em.wbytes(n + 4, pk(*tri[0], *tri[1], *tri[2]))
        nodes.append(n)
    special = flat and r.random() < 0.4
    if special:
        n = em.alloc(0x30, 4)
        sv = r.choice([((0.0, 3.0, 4.0), (0.0, 0.0, 1.0), (0.0, 0.0, 2.0)), ((0.0, 0.0, 1.0), (0.0, 0.0, 2.0), (3.0, 3.0, 0.0)), ((0.0, 0.0, 2.0), (3.0, 3.0, 0.0), (0.0, 0.0, 1.0)), ((0.0, 0.0, 1.0), (0.0, 0.0, 2.0), (0.0, 0.0, 3.0))])
        em.wbytes(n + 4, pk(*sv[0], *sv[1], *sv[2]))
        nodes[:] = [n]
    pos = [0]

    def s4c(emu, k):
        pos[0] = 0
        emu.calllog.append(('i4c', emu.reg('ecx') - IO))

    def s64(emu, k):
        i = pos[0]
        pos[0] += 1
        emu.calllog.append(('i64', i, emu.reg('ecx') - IO))
        return nodes[i] if i < len(nodes) else 0
    em.w32(IVT + 0x4c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s4c))
    em.w32(IVT + 0x64, pystub(c, 1, ret=s64, pop=4, this=True, stackmark=(0,)))
    rr = 10.0 if special else r.choice([0.5, 1.0, 2.0, 3.0, 10.0, 0.0]) if not flat else r.choice([5.0, 10.0, 3.0, 4.0, 6.0, 2.0])
    ss = 0.5 if special else r.choice([0.0, 0.5, 1.0, 2.0, -1.0]) if not flat else r.choice([1.0, 0.5, 1.0])
    return [A, B, F(rr), F(ss), IO if r.random() > 0.06 else 0]


S(0x49bbc0, 'GUESS FUN_49bbc0', 'fastcall', None, ret='al', gen=g49bbc0, note='batch246006')


def g5544f0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    vals = [0.0, 1.0, -1.0, 2.5, 100.0]
    FV = lambda: r.choice(vals)
    THIS = em.alloc(0x20, 4)
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    RCVT = rnd(c, 0x100)
    rcs = []
    for _ in range(3):
        o = rnd(c, 0x10)
        em.w32(o, RCVT)
        rcs.append(o)
    clones = [em.alloc(0x10, 4) for _ in range(3)]
    em.w32(RCVT + 0x28, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('rel', rcs.index(emu.reg('ecx')) if emu.reg('ecx') in rcs else -1))))
    em.w32(RCVT + 0x24, pystub(c, 0, ret=lambda emu, k: clones[rcs.index(emu.reg('ecx')) if emu.reg('ecx') in rcs else 0], pop=0, this=True,
                               side=lambda emu, k: emu.calllog.append(('clone', rcs.index(emu.reg('ecx')) if emu.reg('ecx') in rcs else -1))))
    e1 = [em.alloc(0x10, 4) for _ in range(2)]
    for e in e1:
        em.w32(e, r.getrandbits(32))
        em.wbytes(e + 4, bytes([r.choice([0, 0, 1, 1, 2, 5])]))
    e2 = [em.alloc(0x10, 4) for _ in range(4)]
    for i, e in enumerate(e2):
        em.wbytes(e + 4, bytes([r.choice([0, 0, 2, 2, 1, 4, 4])]))
        em.w32(e, r.choice(rcs) if em.rbytes(e + 4, 1)[0] == 4 else r.getrandbits(32))
    # the source entry 0 sometimes type 4 (clone) and sometimes the very same object as the destination
    if r.random() < 0.5:
        em.wbytes(e1[0] + 4, bytes([4]))
        em.w32(e1[0], r.choice(rcs))
    same = r.random() < 0.1

    def s3d0(emu, k):
        ec = emu.reg('ecx')
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', 1 if ec == P1 else 2 if ec == P2 else -1, i))
        if ec == P1:
            return e1[i]
        if same and i == 0:
            return e1[0]
        return e2[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')

    def s20c0(emu, k):
        p = emu.arg32(2)
        emu.wbytes(p, pk(FV(), FV(), FV()))
        emu.calllog.append(('c20c0', emu.reg('ecx') - THIS, emu.arg32(0), emu.arg32(1), emu.rbytes(p, 12).hex()))
    hook_rec(c, 0x5520c0, 3, ret=0, pop=12, this=True, stackmark=(2,), side=s20c0)
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    RO = rnd(c, 0x10)
    RVT = rnd(c, 0x200)
    em.w32(RO, RVT)
    em.wbytes(G + 0x9b, RO.to_bytes(4, 'little'))
    OB = rnd(c, 0x10)
    OVT = rnd(c, 0x200)
    em.w32(OB, OVT)
    em.w32(RVT + 0x58, pystub(c, 1, ret=OB, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('r58', emu.arg32(0)))))
    em.w32(RVT + 0x114, pystub(c, 6, ret=lambda emu, k: r.getrandbits(32), pop=24, this=True,
                               side=lambda emu, k: emu.calllog.append(('r114', [emu.arg32(i) for i in range(6)]))))
    em.w32(OVT + 0x128, pystub(c, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('o128', emu.arg32(0)))))
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    return [THIS, SRC]


S(0x5544f0, 'GUESS FUN_5544f0', 'thiscall', None, ret=None, gen=g5544f0, note='batch246006')


def g6183a0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    flt = [0.0, -0.0, 1.0, 2.5, float('nan'), -1.0]
    FV = lambda: r.choice([0.0, 1.0, -1.0, 2.0, 0.5])
    A = em.alloc(0x20, 4)
    A4 = em.alloc(0x40, 4)
    em.w32(A + 4, A4)
    em.w32(A4 + 0x28, r.choice([0, 7, 9]))
    em.w32(A4 + 0x24, r.getrandbits(32))
    S = em.alloc(0x40, 4)
    X8 = rnd(c, 0x20); X10 = rnd(c, 0x20); Z = em.alloc(0x60, 4)
    em.w32(S + 8, X8); em.w32(X8 + 0x10, X10); em.w32(X10 + 8, Z)
    em.w32(Z + 0x20, r.choice([0, 0, 0, 0x800000, 0x800001, 0x1234]))
    em.w32(Z + 0x38, r.getrandbits(32)); em.w32(Z + 0x44, r.getrandbits(32))
    Cc = em.alloc(0x60, 4)
    em.w32(S + 0x14, Cc)
    Cb = em.alloc(0x40, 4)
    em.w32(Cc + 8, Cb)
    em.w32(Cc + 0xc, r.choice([0, 0, Cb + 0x10]))
    D = em.alloc(0x80, 4)
    em.wbytes(D + 0x10, pk(*[FV() for _ in range(12)]))
    em.wbytes(D + 0x34, pk(FV(), FV(), FV()))
    em.w32(Cc + 0x20, D)
    em.wbytes(Cc + 5, bytes([r.choice([0, 0, 4, 1])]))
    em.wbytes(S + 5, bytes([r.choice([0, 0, 4, 1])]))
    POSE = em.alloc(0x80, 4)
    em.wbytes(POSE, pk(*[FV() for _ in range(20)]))
    em.w32(S + 0xc, r.choice([0, 0, POSE]))
    em.wbytes(Cb + 8, pk(*[FV() for _ in range(20)]))
    em.w32(Cc + 0xc, r.choice([0, POSE + 0x10, Cb + 0x10])) if False else None
    em.w32(S + 0x28, r.getrandbits(32))
    # R
    RO = em.alloc(0x1500, 4)
    RVT = rnd(c, 0x400)
    em.w32(RO, RVT)
    em.wbytes(RO + 0x115f, bytes([r.choice([0, 2, 3, 1])]))
    O1 = em.alloc(0x40, 4)
    O1VT = rnd(c, 0x20)
    em.w32(O1, O1VT)
    em.w32(O1 + 0x30, r.choice([0, 5]))
    em.w32(O1 + 0x2c, r.choice([0x11, 0x22]))
    O2 = em.alloc(0x40, 4)
    O2VT = rnd(c, 0x20)
    em.w32(O2, O2VT)
    em.w32(O2 + 0x18, r.choice([0, 5]))
    em.w32(O2 + 0x14, r.choice([0x33, 0x44]))
    ub(RO + 0x13fa, O1)
    ub(RO + 0x140a, O2)
    em.w32(O1VT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('rel1', emu.reg('ecx') - O1))))
    em.w32(O2VT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('rel2', emu.reg('ecx') - O2))))
    em.w32(RVT + 0x29c, pystub(c, 3, ret=0, pop=12, this=True, side=lambda emu, k: emu.calllog.append(('r29c', emu.reg('ecx') - RO, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))

    def vecs(emu, p):
        return emu.rbytes(p, 12).hex()
    em.w32(RVT + 0x28c, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(0, 1),
                               side=lambda emu, k: emu.calllog.append(('r28c', vecs(emu, emu.arg32(0)), vecs(emu, emu.arg32(1)), emu.arg32(2)))))
    # device and caches
    DEV = rnd(c, 0x10)
    DVT = rnd(c, 0x200)
    em.w32(DEV, DVT)
    em.w32(0x724a00, DEV)
    em.w32(0x724948, r.choice([0, 1, 5]))
    em.w32(0x7249f8, r.choice([0x152, 0x152, 0x100]))
    em.w32(0x724970, r.choice([0x11, 0x22, 0x33]))
    em.w32(0x7249b0, r.choice([0x24, 0x24, 0x25]))
    em.w32(0x7249f0, r.choice([0x33, 0x44, 0x55]))
    em.w32(0x7249f4, r.choice([0, 7, 9, 5]))
    for slot, n in ((0xc8, 3), (0x130, 2), (0x14c, 4), (0x154, 3)):
        em.w32(DVT + slot, pystub(c, n, ret=0, pop=4 * n, side=lambda emu, k, slot=slot, n=n: emu.calllog.append(('dev', slot, emu.arg32(0) - DEV) + tuple(emu.arg32(i) for i in range(1, n)))))
    # hooks
    def fc(addr, name, out):
        def h(emu, k):
            a = emu.arg32(0)
            emu.calllog.append((name, emu.reg('edx') - POSE if POSE <= emu.reg('edx') < POSE + 0x80 else emu.reg('edx'), a - D, vecs(emu, emu.reg('edx'))))
            emu.wbytes(emu.reg('ecx'), pk(FV(), FV(), FV()))
        hook_rec(c, addr, 1, ret=0, pop=4, side=h)
    fc(0x4de440, 'c4de440', True)
    fc(0x441970, 'c441970', True)
    hook_rec(c, 0x610070, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c610070', emu.reg('ecx') - RO, emu.arg32(0))))
    hook_rec(c, 0x6107e0, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c6107e0', emu.reg('ecx') - RO, emu.arg32(0))))
    hook_rec(c, 0x61a660, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('c61a660', emu.reg('ecx'), emu.reg('edx') - A4)))
    # debug
    G = em.alloc(0x1000, 4)
    em.w32(0x70039c, G)
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    return [A, S, RO]


S(0x6183a0, 'GUESS FUN_6183a0', 'thiscall', None, ret=None, gen=g6183a0, note='batch246006')


def g60c100(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    THIS = em.alloc(0x1400, 4)
    TVT = rnd(c, 0x300)
    em.w32(THIS, TVT)
    DEV = rnd(c, 0x10)
    DVT = rnd(c, 0x200)
    em.w32(DEV, DVT)
    ub(THIS + 0x1377, DEV)
    DEV2 = rnd(c, 0x10)
    em.w32(DEV2, DVT)
    em.w32(0x724a00, DEV2)
    em.wbytes(THIS + 0x60, pk(r.choice([0.0, 0.25, 1.0, -0.5])))
    em.wbytes(THIS + 0x64, pk(r.choice([0.0, 0.5, 1.0, -1.0])))
    em.w32(0x724a08, r.choice([0, 1, 2, 3]))
    em.w32(0x724928, r.choice([5, 5, 4]))
    em.w32(0x72492c, r.choice([6, 6, 0]))
    em.w32(0x724934, r.choice([1, 1, 0]))
    em.w32(0x72493c, r.choice([0, 0, 1]))
    em.w32(0x724ad8, r.choice([0x1234, 0x5678]))
    em.w32(0x724848, r.choice([0x1234, 0x5678, 0]))
    em.w32(DVT + 0x94, pystub(c, 3, ret=0, pop=12, stackmark=(2,),
                              side=lambda emu, k: emu.calllog.append(('dev94', emu.arg32(0) - DEV, emu.arg32(1), emu.rbytes(emu.arg32(2), 64).hex()))))
    em.w32(DVT + 0xc8, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('dev_c8', emu.arg32(0) - DEV2, emu.arg32(1), emu.arg32(2)))))
    em.w32(DVT + 0xf4, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('dev_f4', emu.arg32(0) - DEV2, emu.arg32(1), emu.arg32(2)))))
    for a in (0x60ff30, 0x60feb0):
        hook_rec(c, a, 2, ret=0, pop=8, side=lambda emu, k, a=a: emu.calllog.append(('h%x' % a, emu.reg('ecx'), emu.reg('edx'), emu.arg32(0), emu.arg32(1))))
    iw = r.choice([640, 800, 1024, 1, 3])
    ih = r.choice([480, 600, 768, 1, 7])
    em.w32(TVT + 0xd8, pystub(c, 0, ret=iw, pop=0, this=True))
    em.w32(TVT + 0xdc, pystub(c, 0, ret=ih, pop=0, this=True))

    def s25c(emu, k):
        v = emu.arg32(1)
        vs = []
        for q in range(4):
            b = v + 0x24 * q
            vs.append([emu.r32(b + 4 * j) for j in (0, 1, 2, 7, 8)])
        emu.calllog.append(('v25c', emu.arg32(0), emu.arg32(2), vs, emu.rbytes(emu.arg32(3), 8).hex(), emu.arg32(4)))
    em.w32(TVT + 0x25c, pystub(c, 5, ret=0, pop=20, this=True, stackmark=(1, 3), side=s25c))
    return [THIS, r.getrandbits(32)]


S(0x60c100, 'GUESS FUN_60c100', 'thiscall', None, ret=None, gen=g60c100, note='batch246006')


def g63d4a0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    flt = [0.0, -0.0, 1.0, float('nan')]
    THIS = em.alloc(0x300, 4)
    TVT = rnd(c, 0x200)
    em.w32(THIS, TVT)
    SUB = THIS + 0x204
    SVT = rnd(c, 0x20)
    em.w32(SUB, SVT)
    n = r.choice([0, 1, 2, 3])
    ARR = em.alloc(0x20, 4)
    OVT = rnd(c, 0x100)
    objs = []
    thresholds = []
    for i in range(n):
        o = rnd(c, 0x10)
        em.w32(o, OVT)
        em.w32(ARR + 4 * i, o)
        objs.append(o)
        thresholds.append(r.choice([0, 1, 1, 2]))

    def s28(emu, k):
        o = emu.reg('ecx')
        i = objs.index(o)
        p = emu.arg32(0)
        emu.calllog.append(('v28', i, p))
        return (1 if p < thresholds[i] else 0) | (r.choice([0, 0x100]) if p < thresholds[i] else r.choice([0, 0x100]))
    em.w32(OVT + 0x28, pystub(c, 1, ret=s28, pop=4, this=True))
    hook_rec(c, 0x6493f0, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h6493', objs.index(emu.reg('ecx')))))
    hook_rec(c, 0x64b0b0, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h64b0', objs.index(emu.reg('ecx')))))
    G = em.alloc(0x6000, 4)
    em.w32(0x70039c, G)
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)
    ub(G + 0x8f, r.choice([0, 5, 5]))
    R0 = em.alloc(0x6000, 4)
    ub(G + 0x9b, R0)
    E2 = r.choice([0, 0x7777, 0x7777])
    ub(R0 + 0x5d35, E2)
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    # set iterator at this+0x204
    nodes = []
    sizes = [r.choice([0, 1, 2]), r.choice([0, 1, 2])]
    items = []
    for _ in range(4):
        it = em.alloc(0x50, 4)
        em.w32(it + 0x38, r.getrandbits(32))
        items.append(it)
    cntr = 0
    for sz in sizes:
        nd = em.alloc(0x40, 4)
        em.w32(nd, sz)
        for j in range(sz):
            em.w32(nd + 0x10 + 4 * j, items[cntr % 4])
            cntr += 1
        nodes.append(nd)
    em.w32(nodes[0] + 8, nodes[1] if sizes[1] and sizes[0] else 0)
    em.w32(nodes[1] + 8, 0)
    first = nodes[0] if sizes[0] else (nodes[1] if sizes[1] else 0)
    PP = em.alloc(0x10, 4)
    if first:
        em.wbytes(PP, struct.pack('<3I', first + 0x10, 0, first))
    else:
        em.wbytes(PP, struct.pack('<3I', 0, 0, 0))
    em.w32(SVT + 0xc, pystub(c, 1, ret=PP, pop=4, this=True, stackmark=(0,), side=lambda emu, k: emu.calllog.append(('s0c', emu.reg('ecx') - SUB))))
    # container hooks
    hook_rec(c, 0x65ca30, 2, ret=0, pop=8, this='mark', stackmark=(0,), side=lambda emu, k: emu.calllog.append(('c65ca30', emu.arg32(1))))
    hook_rec(c, 0x65d070, 2, ret=0, pop=8, this='mark', side=lambda emu, k: emu.calllog.append(('c65d070', emu.arg32(0), emu.arg32(1) in [em.r32(i + 0x38) for i in items] or emu.arg32(1))))
    hook_rec(c, 0x65cc70, 0, ret=0, pop=0, this='mark', side=lambda emu, k: emu.calllog.append(('c65cc70',)))
    hook_rec(c, 0x65c9d0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: emu.calllog.append(('c65c9d0',)))
    hook_rec(c, 0x65ca60, 1, ret=0, pop=4, this='mark', stackmark=(0,), side=lambda emu, k: emu.calllog.append(('c65ca60',)))
    ncnt = r.choice([-1, 0, 1, 2])
    recs = []
    for _ in range(3):
        rr = em.alloc(0x20, 4)
        em.w32(rr, r.getrandbits(32))
        em.w32(rr + 8, r.choice([0, 1, 2, 0xffffffff]))
        recs.append(rr)
    its = []
    for _ in range(8):
        iv = em.alloc(0x10, 4)
        em.w32(iv, r.getrandbits(32))
        em.w32(iv + 4, r.getrandbits(32))
        its.append(iv)
    rpos = [0]
    ipos = [0]
    hook_rec(c, 0x65c9f0, 0, ret=ncnt & 0xffffffff, pop=0, this='mark', side=lambda emu, k: emu.calllog.append(('c65c9f0',)))

    def rec_h(emu, k):
        v = recs[rpos[0] % 3]
        rpos[0] += 1
        emu.calllog.append(('c65ca20', rpos[0]))
        return v
    hook_rec(c, 0x65ca20, 0, ret=rec_h, pop=0, this='mark')

    def it_h(emu, k):
        v = its[ipos[0] % 8]
        ipos[0] += 1
        emu.calllog.append(('c65c9e0', ipos[0]))
        return v
    hook_rec(c, 0x65c9e0, 0, ret=it_h, pop=0, this='mark')
    hook_rec(c, 0x65ca00, 1, ret=lambda emu, k: (emu.arg32(0) * 3 + 1) & 0xffffffff, pop=4, this='mark', side=lambda emu, k: emu.calllog.append(('c65ca00', emu.arg32(0))))
    em.w32(TVT + 0xd0, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('t0d0',))))
    em.w32(TVT + 0xd4, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('t0d4',))))
    em.w32(TVT + 0xd8, pystub(c, 4, ret=0, pop=16, this=True, side=lambda emu, k: emu.calllog.append(('t0d8', [emu.arg32(i) for i in range(4)]))))
    return [THIS, ARR, n]


S(0x63d4a0, 'GUESS FUN_63d4a0', 'thiscall', None, ret=None, gen=g63d4a0, note='batch246006')


def g6281a0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = em.alloc(0x200, 4)
    pool = [0, 1, 2, 3, 4, 5, 8, 9, 10, 15, 21, 22, 24, 25, 29, 30, 12, 13, 14]   # no LEAD3 / LEAD4 classes (6, 7): they break the 2-byte stepping and the exe loops forever
    cls = bytes(r.choice(pool) if r.random() < 0.9 else r.choice([c_ for c_ in range(32) if c_ not in (6, 7)]) for _ in range(256))
    em.wbytes(ENC + 0x4c, cls)
    # candidate 2-byte units
    asc = list(range(0x20, 0x7f)) + [0x3f, 0x3e, 0x78, 0x6d, 0x6c, 0x58, 0x4d, 0x4c]
    n = r.choice([0, 1, 2, 3, 4, 6, 8])
    units = []
    for i in range(n):
        q = r.random()
        if q < 0.7:
            units.append((0, r.choice(asc)))
        elif q < 0.8:
            units.append((0, 0x3e))
        else:
            units.append((r.choice([0x01, 0x04, 0x30, 0x4e, 0xd8, 0xff, 0x00]), r.getrandbits(8)))
    if r.random() < 0.35 and n >= 6:
        # a PI target "xml" (any case) followed by more content, to reach the checkPiTarget path
        t = r.choice([(0x78, 0x6d, 0x6c), (0x58, 0x6d, 0x6c), (0x78, 0x4d, 0x6c), (0x78, 0x6d, 0x4c), (0x58, 0x4d, 0x4c)])
        units[0:3] = [(0, t[0]), (0, t[1]), (0, t[2])]
        if n > 3 and r.random() < 0.6:
            units[3] = (0, 0x3f)
        if n > 4 and r.random() < 0.6:
            units[4] = (0, 0x3e)
    if r.random() < 0.6:
        # processing-instruction shaped input: target name, then '?' '>' or white space + content + '?' '>'
        cl_ = bytearray(cls)
        for ch in b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_:0123456789':
            cl_[ch] = 29
        cl_[0x41] = 5; cl_[0x42] = 6; cl_[0x3f] = 15; cl_[0x20] = 21; cl_[0x09] = 9; cl_[0x0a] = 10; cl_[0x3e] = 12; cl_[0x3b] = 13; cl_[0x2d] = 22
        em.wbytes(ENC + 0x4c, bytes(cl_))
        nl = r.choice([1, 2, 3, 3, 3, 4])
        if nl == 3 and r.random() < 0.7:
            nm = list(r.choice([b'xml', b'XML', b'xMl', b'xmL', b'Xml', b'xml']))
        else:
            nm = [r.choice(b'abcxmlXML_:z019') for _ in range(nl)]
            if r.random() < 0.2:
                nm[0] = r.choice(b'019-')
        units = [(0, ch) for ch in nm]
        if r.random() < 0.15:
            units[0] = (r.choice([0x01, 0x30, 0x4e, 0x00, 0xff]), r.getrandbits(8))
        if r.random() < 0.15 and len(units) > 1:
            units[1] = (r.choice([0x01, 0x30, 0x4e, 0xff]), r.getrandbits(8))
        q = r.random()
        if q < 0.35:
            units += [(0, 0x3f), (0, 0x3e)]
            if r.random() < 0.3:
                units[-1] = (0, r.choice([0x3f, 0x20, 0x3e]))
        elif q < 0.8:
            units += [(0, r.choice([0x20, 0x09, 0x0a]))]
            for _ in range(r.choice([0, 1, 2, 4])):
                units.append((0, r.choice(b'abc01;-?> x')))
                if r.random() < 0.1:
                    units.append((r.choice([0x01, 0xd8]), r.getrandbits(8)))
            if r.random() < 0.7:
                units += r.choice([[(0, 0x41)], [(0, 0x41)], [(0, 0x42)], [(0xd8, 0x11), (0xdc, 0x22)], [(0xd8, 0x11)], [(0xd8, 0x11), (0xdc, 0x22), (0, 0x3f), (0, 0x3e)], [(0, 0x42), (0x01, 0x00)], [(0, 0x42), (0x01, 0x00)]])
            else:
                units += [(0, 0x3f), (0, 0x3e)]
        else:
            units += [(0, r.choice([0x20, 0x3f, 0x09]))]
            units += [(0, r.choice(b'ab?>x')) for _ in range(r.choice([0, 1, 3]))]
        n = len(units)
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, b''.join(bytes(u) for u in units) + b'\x41' * 2 + bytes(r.getrandbits(8) for _ in range(6)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    end = BUF + 2 * n
    if r.random() < 0.15:
        # a lead byte of a multi-byte character right before an end that is too close: the -2 paths
        lead = r.choice([5, 6, 7])
        em.wbytes(ENC + 0x4c + 0x41, bytes([lead]))
        em.wbytes(BUF, bytes([0, 0x41]) + bytes(r.getrandbits(8) for _ in range(6)))
        end = BUF + r.choice([1, 2, 3, 4, 6, 8][:lead + 1 if lead < 5 else 6]) if False else BUF + r.choice([1, 2, 3, 4, 6, 8])
    return [ENC, BUF, end, OUT]


S(0x6281a0, 'GUESS FUN_6281a0', 'cdecl', None, ret='eax', gen=g6281a0, note='batch246006')


def g62a200(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = em.alloc(0x200, 4)
    pool = [0, 1, 2, 3, 4, 5, 8, 9, 10, 15, 21, 22, 24, 25, 29, 30, 12, 13, 14]   # no LEAD3 / LEAD4 classes (6, 7): they break the 2-byte stepping and the exe loops forever
    cls = bytes(r.choice(pool) if r.random() < 0.9 else r.choice([c_ for c_ in range(32) if c_ not in (6, 7)]) for _ in range(256))
    em.wbytes(ENC + 0x4c, cls)
    # candidate 2-byte units
    asc = list(range(0x20, 0x7f)) + [0x3f, 0x3e, 0x78, 0x6d, 0x6c, 0x58, 0x4d, 0x4c]
    n = r.choice([0, 1, 2, 3, 4, 6, 8])
    units = []
    for i in range(n):
        q = r.random()
        if q < 0.7:
            units.append((0, r.choice(asc)))
        elif q < 0.8:
            units.append((0, 0x3e))
        else:
            units.append((r.choice([0x01, 0x04, 0x30, 0x4e, 0xd8, 0xff, 0x00]), r.getrandbits(8)))
    if r.random() < 0.35 and n >= 6:
        # a PI target "xml" (any case) followed by more content, to reach the checkPiTarget path
        t = r.choice([(0x78, 0x6d, 0x6c), (0x58, 0x6d, 0x6c), (0x78, 0x4d, 0x6c), (0x78, 0x6d, 0x4c), (0x58, 0x4d, 0x4c)])
        units[0:3] = [(0, t[0]), (0, t[1]), (0, t[2])]
        if n > 3 and r.random() < 0.6:
            units[3] = (0, 0x3f)
        if n > 4 and r.random() < 0.6:
            units[4] = (0, 0x3e)
    if r.random() < 0.6:
        # processing-instruction shaped input: target name, then '?' '>' or white space + content + '?' '>'
        cl_ = bytearray(cls)
        for ch in b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_:0123456789':
            cl_[ch] = 29
        cl_[0x41] = 5; cl_[0x42] = 6; cl_[0x3f] = 15; cl_[0x20] = 21; cl_[0x09] = 9; cl_[0x0a] = 10; cl_[0x3e] = 12; cl_[0x3b] = 13; cl_[0x2d] = 22
        em.wbytes(ENC + 0x4c, bytes(cl_))
        nl = r.choice([1, 2, 3, 3, 3, 4])
        if nl == 3 and r.random() < 0.7:
            nm = list(r.choice([b'xml', b'XML', b'xMl', b'xmL', b'Xml', b'xml']))
        else:
            nm = [r.choice(b'abcxmlXML_:z019') for _ in range(nl)]
            if r.random() < 0.2:
                nm[0] = r.choice(b'019-')
        units = [(0, ch) for ch in nm]
        if r.random() < 0.3:
            units[0] = (r.choice([0x01, 0x30, 0x4e, 0x00, 0xff, 0xd8, 0xdc, 0x05, 0x20, 0xff, 0xfe]), r.choice([r.getrandbits(8), 0xfe, 0xff, 0x00, 0xd8, 0xdb, 0xdc, 0xe0]))
        if r.random() < 0.15 and len(units) > 1:
            units[1] = (r.choice([0x01, 0x30, 0x4e, 0xff]), r.getrandbits(8))
        q = r.random()
        if q < 0.35:
            units += [(0, 0x3f), (0, 0x3e)]
            if r.random() < 0.3:
                units[-1] = (0, r.choice([0x3f, 0x20, 0x3e]))
        elif q < 0.8:
            units += [(0, r.choice([0x20, 0x09, 0x0a]))]
            for _ in range(r.choice([0, 1, 2, 4])):
                units.append((0, r.choice(b'abc01;-?> x')))
                if r.random() < 0.1:
                    units.append((r.choice([0x01, 0xd8]), r.getrandbits(8)))
            if r.random() < 0.7:
                units += r.choice([[(0, 0x41)], [(0, 0x41)], [(0, 0x42)], [(0xd8, 0x11), (0xdc, 0x22)], [(0xd8, 0x11)], [(0xd8, 0x11), (0xdc, 0x22), (0, 0x3f), (0, 0x3e)], [(0, 0x42), (0x41, 0x00)], [(0, 0x42), (0x41, 0x00)]])
            else:
                units += [(0, 0x3f), (0, 0x3e)]
        else:
            units += [(0, r.choice([0x20, 0x3f, 0x09]))]
            units += [(0, r.choice(b'ab?>x')) for _ in range(r.choice([0, 1, 3]))]
        n = len(units)
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, b''.join(bytes((u[1], u[0])) for u in units) + b'\x00' * 2 + bytes(r.getrandbits(8) for _ in range(6)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    end = BUF + 2 * n
    if r.random() < 0.15:
        # a lead byte of a multi-byte character right before an end that is too close: the -2 paths
        lead = r.choice([5, 6, 7])
        em.wbytes(ENC + 0x4c + 0x41, bytes([lead]))
        em.wbytes(BUF, bytes([0x41, 0]) + bytes(r.getrandbits(8) for _ in range(6)))
        end = BUF + r.choice([1, 2, 3, 4, 6, 8][:lead + 1 if lead < 5 else 6]) if False else BUF + r.choice([1, 2, 3, 4, 6, 8])
    return [ENC, BUF, end, OUT]


S(0x62a200, 'GUESS FUN_62a200', 'cdecl', None, ret='eax', gen=g62a200, note='batch246006')


def g622650(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = em.alloc(0x200, 4)
    cl_ = bytearray(r.choice([29, 29, 11, 12, 29, 0, 1, 8, 2, 3, 4, 5, 9, 10]) if r.random() < 0.15 else 29 for _ in range(256))
    cl_[0x26] = 2; cl_[0x3c] = 3; cl_[0x5d] = 4; cl_[0x0d] = 9; cl_[0x0a] = 10; cl_[0x3e] = 29; cl_[0x41] = 5; cl_[0x42] = 6
    cl_[0x00] = r.choice([0, 29]); cl_[0x01] = 1; cl_[0x02] = 8
    em.wbytes(ENC + 0x4c, bytes(cl_))
    pool = [0x61, 0x62, 0x20, 0x26, 0x3c, 0x5d, 0x5d, 0x3e, 0x0d, 0x0a, 0x41, 0x00, 0x01, 0x02, 0x30]
    n = r.choice([0, 1, 2, 3, 4, 5, 6])
    units = []
    for _ in range(n):
        q = r.random()
        if q < 0.82:
            units.append((0, r.choice(pool)))
        elif q < 0.9:
            units.append((0xd8, r.getrandbits(8)))
            if r.random() < 0.6:
                units.append((0xdc, r.getrandbits(8)))
        else:
            units.append((r.choice([0x01, 0x30, 0x4e, 0xff]), r.choice([r.getrandbits(8), 0xd8, 0xfe, 0xff])))
    if r.random() < 0.3:
        units += [(0, 0x5d), (0, 0x5d), (0, 0x3e)][:r.choice([1, 2, 3])]
    if r.random() < 0.2:
        units += [(0, 0x42)]    # class 6 only as the last unit
    if r.random() < 0.4:
        # edge patterns: lone lead / CR / bracket units, and class-6 (3 byte) steps landing on a stop class
        cl_[0x00] = 0
        em.wbytes(ENC + 0x4c, bytes(cl_))
        units = r.choice([[(0, 0x41)], [(0, 0x42)], [(0xd8, 0x11)], [(0xd8, 0x11), (0xdc, 0x22)], [(0, 0x0d)], [(0, 0x0d), (0, 0x0a)], [(0, 0x0d), (0, 0x61)],
                          [(0, 0x42), (0, 0x61), (0x05, 0x00)], [(0, 0x61), (0, 0x42), (0, 0x61), (0x05, 0x00)], [(0, 0x5d), (0, 0x5d)], [(0, 0x61), (0, 0x5d), (0, 0x5d)],
                          [(0, 0x61), (0, 0x5d), (0, 0x5d), (0, 0x61)], [(0, 0x5d), (0, 0x5d), (0, 0x61)], [(0, 0x41), (0, 0x61)], [(0, 0x61), (0, 0x41)], [(0, 0x61), (0xd8, 0x11)],
                          [(0, 0x61), (0, 0x42)]])
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, b''.join(bytes((u[1], u[0])) for u in units) + b'\x00\x00' + bytes(r.getrandbits(8) for _ in range(6)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    end = BUF + 2 * len(units)
    if r.random() < 0.2:
        end += 1       # odd length: the end is rounded down
    for a in (0x629c10, 0x62a690):
        def mk(a):
            def side(emu, k):
                emu.calllog.append(('h%x' % a, emu.arg32(0) - ENC, emu.arg32(1) - BUF, emu.arg32(2) - BUF, emu.arg32(3) - OUT))
                emu.w32(emu.arg32(3), emu.arg32(1) + 6)
            return side
        hook_rec(c, a, 4, ret=lambda emu, k: r.choice([5, 0xffffffff, 0, 3, 0xfffffffe]), pop=0, side=mk(a))
    return [ENC, BUF, end, OUT]


S(0x622650, 'GUESS FUN_622650', 'cdecl', None, ret='eax', gen=g622650, note='batch246006')


def g624100(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = em.alloc(0x200, 4)
    cl_ = bytearray(r.choice([29, 29, 11, 12, 29, 0, 1, 8, 2, 3, 4, 5, 9, 10]) if r.random() < 0.15 else 29 for _ in range(256))
    cl_[0x26] = 2; cl_[0x3c] = 3; cl_[0x5d] = 4; cl_[0x0d] = 9; cl_[0x0a] = 10; cl_[0x3e] = 29; cl_[0x41] = 5; cl_[0x42] = 6
    cl_[0x00] = r.choice([0, 29]); cl_[0x01] = 1; cl_[0x02] = 8
    em.wbytes(ENC + 0x4c, bytes(cl_))
    pool = [0x61, 0x62, 0x20, 0x26, 0x3c, 0x5d, 0x5d, 0x3e, 0x0d, 0x0a, 0x41, 0x00, 0x01, 0x02, 0x30]
    n = r.choice([0, 1, 2, 3, 4, 5, 6])
    units = []
    for _ in range(n):
        q = r.random()
        if q < 0.82:
            units.append((0, r.choice(pool)))
        elif q < 0.9:
            units.append((0xd8, r.getrandbits(8)))
            if r.random() < 0.6:
                units.append((0xdc, r.getrandbits(8)))
        else:
            units.append((r.choice([0x01, 0x30, 0x4e, 0xff]), r.choice([r.getrandbits(8), 0xd8, 0xfe, 0xff])))
    if r.random() < 0.3:
        units += [(0, 0x5d), (0, 0x5d), (0, 0x3e)][:r.choice([1, 2, 3])]
    if r.random() < 0.2:
        units += [(0, 0x42)]    # class 6 only as the last unit
    if r.random() < 0.4:
        # edge patterns: lone lead / CR / bracket units, and class-6 (3 byte) steps landing on a stop class
        cl_[0x00] = 0
        em.wbytes(ENC + 0x4c, bytes(cl_))
        units = r.choice([[(0, 0x41)], [(0, 0x42)], [(0xd8, 0x11)], [(0xd8, 0x11), (0xdc, 0x22)], [(0, 0x0d)], [(0, 0x0d), (0, 0x0a)], [(0, 0x0d), (0, 0x61)],
                          [(0, 0x42), (0x61, 0x00), (0x00, 0x05)], [(0, 0x61), (0, 0x42), (0x61, 0x00), (0x00, 0x05)], [(0, 0x5d), (0, 0x5d)], [(0, 0x61), (0, 0x5d), (0, 0x5d)],
                          [(0, 0x61), (0, 0x5d), (0, 0x5d), (0, 0x61)], [(0, 0x5d), (0, 0x5d), (0, 0x61)], [(0, 0x41), (0, 0x61)], [(0, 0x61), (0, 0x41)], [(0, 0x61), (0xd8, 0x11)],
                          [(0, 0x61), (0, 0x42)]])
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, b''.join(bytes((u[0], u[1])) for u in units) + b'\x00\x00' + bytes(r.getrandbits(8) for _ in range(6)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    end = BUF + 2 * len(units)
    if r.random() < 0.2:
        end += 1       # odd length: the end is rounded down
    for a in (0x627bb0, 0x628630):
        def mk(a):
            def side(emu, k):
                emu.calllog.append(('h%x' % a, emu.arg32(0) - ENC, emu.arg32(1) - BUF, emu.arg32(2) - BUF, emu.arg32(3) - OUT))
                emu.w32(emu.arg32(3), emu.arg32(1) + 6)
            return side
        hook_rec(c, a, 4, ret=lambda emu, k: r.choice([5, 0xffffffff, 0, 3, 0xfffffffe]), pop=0, side=mk(a))
    return [ENC, BUF, end, OUT]


S(0x624100, 'GUESS FUN_624100', 'cdecl', None, ret='eax', gen=g624100, note='batch246006')


def g623be0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = em.alloc(0x200, 4)
    cl_ = bytearray(r.choice([29, 29, 29, 29, 11, 12, 0, 1, 8, 2, 3, 4, 9, 10]) if r.random() < 0.1 else 29 for _ in range(256))
    cl_[0x26] = 2; cl_[0x3c] = 3; cl_[0x5d] = 4; cl_[0x0d] = 9; cl_[0x0a] = 10; cl_[0x3e] = 29
    cl_[0xc2] = 5; cl_[0xe0] = 6; cl_[0xf0] = 7; cl_[0x00] = 0; cl_[0x01] = 1; cl_[0x02] = 8
    em.wbytes(ENC + 0x4c, bytes(cl_))
    rets = [r.choice([0, 0, 0, 1]) for _ in range(12)]
    cnt = [0]
    for off in (0x164, 0x168, 0x16c):
        def mk(off):
            def side(emu, k):
                emu.calllog.append(('pred', off, emu.arg32(0) - ENC, emu.arg32(1)))
            def retf(emu, k):
                v = rets[cnt[0] % 12]
                cnt[0] += 1
                return v
            return pystub(c, 2, ret=retf, pop=0, side=side)
        em.w32(ENC + off, mk(off))
    pool = [0x61, 0x62, 0x20, 0x26, 0x3c, 0x5d, 0x5d, 0x3e, 0x0d, 0x0a, 0xc2, 0xe0, 0xf0, 0x00, 0x01, 0x02, 0x80]
    n = r.choice([0, 1, 2, 3, 4, 5, 6])
    units = [r.choice(pool) for _ in range(n)]
    if r.random() < 0.3:
        units += [0x5d, 0x5d, 0x3e][:r.choice([1, 2, 3])]
    if r.random() < 0.5:
        units = r.choice([[0xc2], [0xe0], [0xf0], [0xc2, 0x80], [0xe0, 0x80], [0xe0, 0x80, 0x80], [0xf0, 0x80, 0x80], [0xf0, 0x80, 0x80, 0x80], [0x0d], [0x0d, 0x0a], [0x0d, 0x61],
                          [0x5d, 0x5d], [0x61, 0x5d, 0x5d], [0x61, 0x5d, 0x5d, 0x61], [0x5d, 0x5d, 0x61], [0x61, 0xc2], [0x61, 0xc2, 0x80], [0x61, 0xe0, 0x80], [0x61, 0xe0, 0x80, 0x80], [0x61, 0xf0, 0x80, 0x80], [0x61, 0xf0, 0x80, 0x80, 0x80],
                          [0x61, 0x5d], [0x5d], [0x61, 0x5d, 0x5d, 0x3e], [0x5d, 0x5d, 0x3e]])
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, bytes(units) + bytes(r.getrandbits(8) for _ in range(8)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    end = BUF + len(units)
    for a in (0x62b450, 0x62c060):
        def mk2(a):
            def side(emu, k):
                emu.calllog.append(('h%x' % a, emu.arg32(0) - ENC, emu.arg32(1) - BUF, emu.arg32(2) - BUF, emu.arg32(3) - OUT))
                emu.w32(emu.arg32(3), emu.arg32(1) + 3)
            return side
        hook_rec(c, a, 4, ret=lambda emu, k: r.choice([5, 0xffffffff, 0, 3, 0xfffffffe]), pop=0, side=mk2(a))
    return [ENC, BUF, end, OUT]


S(0x623be0, 'GUESS FUN_623be0', 'cdecl', None, ret='eax', gen=g623be0, note='batch246006')


def g62bb10(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = em.alloc(0x200, 4)
    cl_ = bytearray(r.choice([29, 29, 29, 22, 24, 25, 26, 11, 12, 13, 14, 0, 1, 8, 9, 10, 15, 21, 16, 17, 18, 19, 20]) if r.random() < 0.25 else 29 for _ in range(256))
    for ch in b'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_:':
        cl_[ch] = r.choice([22, 24])
    for ch in b'0123456789-.':
        cl_[ch] = r.choice([25, 26, 27, 29])
    cl_[0x3f] = 15; cl_[0x20] = 21; cl_[0x09] = 9; cl_[0x0a] = 10; cl_[0x3e] = 12
    cl_[0xc2] = 5; cl_[0xe0] = 6; cl_[0xf0] = 7; cl_[0x00] = 0; cl_[0x01] = 1; cl_[0x02] = 8
    if r.random() < 0.5:
        cl_[0x80] = r.choice([0, 1, 8])    # continuation bytes that stop the scan: makes a wrong lead step visible
    em.wbytes(ENC + 0x4c, bytes(cl_))
    rets = [r.choice([0, 1, 1, 1]) for _ in range(16)]
    cnt = [0]
    for off in (0x158, 0x15c, 0x160, 0x14c, 0x150, 0x154, 0x164, 0x168, 0x16c):
        def mk(off):
            def side(emu, k):
                emu.calllog.append(('pred', off, emu.arg32(0) - ENC, emu.arg32(1)))
            def retf(emu, k):
                v = rets[cnt[0] % 16]
                if off >= 0x164:
                    v = 1 if v == 0 and r.random() < 0.15 else 0
                cnt[0] += 1
                return v
            return pystub(c, 2, ret=retf, pop=0, side=side)
        em.w32(ENC + off, mk(off))
    q = r.random()
    nm = [r.choice(b'abxmlXML_:z019') for _ in range(r.choice([1, 2, 3, 3]))]
    if r.random() < 0.5:
        nm = list(r.choice([b'xml', b'XML', b'xMl', b'xmL', b'Xml']))
    s_ = list(nm)
    if q < 0.3:
        s_ += [0x3f, 0x3e]
    elif q < 0.5:
        s_ += [0x3f]
    elif q < 0.9:
        s_ += [r.choice([0x20, 0x09, 0x0a])]
        s_ += [r.choice(b'ab01;-? >') for _ in range(r.choice([0, 1, 2, 3]))]
        s_ += r.choice([[0x3f, 0x3e], [0x3f, 0x3e], [0x3f], [], [0xc2, 0x80], [0xe0, 0x80, 0x80], [0xf0, 0x80, 0x80, 0x80], [0xc2], [0xe0, 0x80], [0xf0, 0x80, 0x80], [0x3f, 0x61]])
    else:
        s_ = [r.choice([0xc2, 0xe0, 0xf0, 0x61, 0x30, 0x00, 0x20])] + s_
    if r.random() < 0.25:
        s_ = [r.choice([0xc2, 0xe0, 0xf0]), 0x80, 0x80, 0x80][:r.choice([1, 2, 3, 4])] + s_
    if r.random() < 0.1:
        s_ = []
    PRE = [[], [0x61], [0x61, 0x20], [0x61, 0x61], [0x78, 0x6d, 0x6c, 0x20], [0x61, 0x61, 0x20]]
    SUF = [[], [0xc2, 0x80], [0xc2], [0xe0, 0x80, 0x80], [0xe0, 0x80], [0xf0, 0x80, 0x80, 0x80], [0xf0, 0x80, 0x80], [0xc2, 0x80, 0xe0, 0x80], [0xe0, 0x80, 0x80, 0xf0, 0x80, 0x80],
           [0xc2, 0x80, 0xc2, 0x80, 0x3f, 0x3e], [0xf0, 0x80, 0x80, 0x80, 0xe0, 0x80], [0xc2, 0x80, 0x3f, 0x3e], [0xe0, 0x80, 0x80, 0x3f, 0x3e], [0xf0, 0x80, 0x80, 0x80, 0x3f, 0x3e]]
    if c.case % 4 != 3:
        # exhaustive cycle over every prefix / lead-sequence combination (the exact-length boundaries need them all)
        j = c.case // 4 * 3 + c.case % 4
        s_ = PRE[j % len(PRE)] + SUF[(j // len(PRE)) % len(SUF)]
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, bytes(s_) + bytes(r.getrandbits(8) for _ in range(8)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    return [ENC, BUF, BUF + len(s_), OUT]


S(0x62bb10, 'GUESS FUN_62bb10', 'cdecl', None, ret='eax', gen=g62bb10, note='batch246006')


def g42bae0(c):
    import pe_emu
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    st = lambda emu: emu.r32(emu.r32(pe_emu.TEB) + 8)
    sr = [seh_record(c, 2) for _ in range(6)]
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)

    def log(emu, k, tag, j, *extra):
        emu.calllog.append((tag, st(emu)) + extra)
        sr[j](emu, k)

    THIS = em.alloc(0x1c00, 4)
    names[THIS] = 'T'
    # [0x70038c] object
    G = rnd(c, 0x10)
    GVT = rnd(c, 0x100)
    em.w32(G, GVT)
    if r.random() < 0.8:
        em.w32(0x70038c, G)
        em.w32(GVT + 0x38, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: log(emu, k, 'g38', 0)))
    else:
        em.w32(0x70038c, 0)
    # members
    def mkobj(label, size=0x40):
        o = em.alloc(size, 4)
        names[o] = label
        return o
    if r.random() < 0.8:
        o37 = mkobj('o37')
        ub(THIS + 0x1b37, o37)
    if r.random() < 0.8:
        o55 = mkobj('o55')
        ub(THIS + 0x1b55, o55)
    if r.random() < 0.8:
        o51 = mkobj('o51')
        OVT = rnd(c, 0x20)
        em.w32(o51, OVT)
        em.w32(OVT, pystub(c, 1, ret=0, pop=4, this=True, side=lambda emu, k: log(emu, k, 'del51', 1, emu.arg32(0))))
        ub(THIS + 0x1b51, o51)
    if r.random() < 0.85:
        L = mkobj('L')
        NODE = em.alloc(0x30, 4)
        names[NODE] = 'N'
        em.w32(L, NODE)
        em.w32(L + 4, r.choice([0, 3, 3]))
        ub(NODE + 1, r.getrandbits(32)); ub(NODE + 5, r.getrandbits(32)); ub(NODE + 9, r.getrandbits(32))
        ub(THIS + 0x1b65, L)
        hook_rec(c, 0x430010, 1, ret=0, pop=4, this=True,
                 side=lambda emu, k: log(emu, k, 'c430010', 2, nm(emu.reg('ecx')), emu.arg32(0) == em.r32(NODE + 1) or emu.arg32(0)))
    for off, lab in ((0x1b69, 'V1'), (0x1b6d, 'V2')):
        if r.random() < 0.8:
            V = mkobj(lab)
            BEG = em.alloc(0x80, 4)
            names[BEG] = lab + 'b'
            n = r.choice([0, 1, 2, 3, 4])
            em.w32(V, BEG)
            em.w32(V + 4, r.getrandbits(32))
            em.w32(V + 8, BEG + 12 * n + r.choice([0, 0, 0, 4]) if False else BEG + 12 * n)
            ub(THIS + off, V)
    if r.random() < 0.8:
        V3 = mkobj('V3')
        BEG3 = em.alloc(0x80, 4)
        names[BEG3] = 'V3b'
        n3 = r.choice([0, 1, 2, 5])
        em.w32(V3, BEG3)
        em.w32(V3 + 8, BEG3 + 4 * n3)
        ub(THIS + 0x1b61, V3)
    hook_rec(c, 0x4d3f80, 0, ret=0, pop=0, this=True, side=lambda emu, k: log(emu, k, 'c4d3f80', 3, nm(emu.reg('ecx'))))
    hook_rec(c, 0x54f870, 2, ret=0, pop=8, this=True, side=lambda emu, k: log(emu, k, 'c54f870', 4, nm(emu.reg('ecx')), nm(emu.arg32(0)), emu.arg32(1)))

    def s080(emu, k):
        log(emu, k, 'c42b080', 5, nm(emu.reg('ecx')), emu.reg('edx'), nm(emu.arg32(0)))
    hook_rec(c, 0x42b080, 1, ret=0, pop=4, side=s080)
    hook_rec(c, 0x634273, 2, ret=0, pop=0, side=lambda emu, k: log(emu, k, 'free', 3, nm(emu.arg32(0)), emu.arg32(1)))
    # the 22 embedded strings: pointer to the inline buffer or to a heap block
    for off in (0x1ab7, 0x1a17, 0x1997, 0x1917, 0x923, 0x8a3, 0x823, 0x7a3, 0x723, 0x6a3, 0x623, 0x5a3, 0x523, 0x4a3, 0x423, 0x3a3, 0x323, 0x2a3, 0x223, 0x1a3, 0x123, 0xa3):
        if r.random() < 0.25:
            h = em.alloc(0x20, 4)
            names[h] = 'str%x' % off
            ub(THIS + off, h)
        else:
            ub(THIS + off, THIS + off + 4)
    return [THIS]


S(0x42bae0, 'GUESS FUN_42bae0', 'thiscall', None, ret=None, gen=g42bae0, note='batch246006')


def g43afe0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    flt = [0.0, -0.0, 1.0, float('nan')]
    THIS = em.alloc(0x1400, 4)
    names = {}

    def nm(a):
        return names.get(a, -1)
    # globals
    GO = rnd(c, 0x30)
    em.w32(GO + 0xc, r.choice([0, 0, 1, 5]))
    em.w32(GO + 0x1c, r.choice([0, 3]))
    em.w32(0x7003a0, GO)
    G = em.alloc(0x1000, 4)
    em.w32(0x70039c, G)
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)
    em.w32(G + 0x1c, r.getrandbits(32))
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    # objects: base B (0x60 bytes), O = B + 4
    def mkbase(lab):
        B = em.alloc(0x60, 4)
        names[B] = lab
        em.w32(B + 4, r.choice([0, 0, 2, 1]))
        em.w32(B + 0x42 - 0, r.choice([0, 1, 2, 5]))
        em.wbytes(B + 0x32, bytes([r.getrandbits(8)]))
        em.wbytes(B + 0x10, bytes([r.choice([0, 1])]))
        ub(B + 0x19, r.choice([0, 1, 2, 5]))
        for off in (0x1d, 0x21, 0x25, 0x29):
            ub(B + off, r.getrandbits(32))
        em.wbytes(B + 0x31, bytes([r.getrandbits(8)]))
        em.wbytes(B + 0x2d, bytes([r.getrandbits(8)]))
        return B
    bases = [mkbase('b%d' % i) for i in range(6)]
    # pre-existing pointer array
    npre = r.choice([0, 0, 1, 2])
    for i in range(npre):
        em.w32(THIS + 0x121c + 4 * i, r.choice(bases))
    em.w32(THIS + 0x1218, npre)
    # records
    M = r.choice([0, 1, 2, 3])
    em.w32(THIS + 0x1210, M)
    BUF = em.alloc(0x20, 4)
    TAB = em.alloc(0x80, 4)
    em.w32(THIS + 0x131c, BUF)
    em.w32(THIS + 0x1344, TAB)
    for i in range(M):
        v = r.choice([0, 0, 1, 3, 5, 0x80])
        em.wbytes(BUF + i, bytes([v]))
        em.wbytes(TAB + 10 * i + 8, bytes([r.choice([0, 1])]))
        em.wbytes(TAB + 10 * i + 9, bytes([r.choice([0, 1, 3, 5])]))
        # linked list of nodes
        head = 0
        for _ in range(r.choice([0, 1, 2, 3])):
            node = em.alloc(0x20, 4)
            b = r.choice(bases)
            em.w32(node, b + 4)
            em.wbytes(node + 4, bytes([r.choice([0, 1])]))
            ub(node + 5, head)
            head = node
        ub(TAB + 10 * i + 4, head)
    # hooks
    hook_rec(c, 0x43a380, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('c43a380', emu.reg('ecx') - THIS)))
    hook_rec(c, 0x43a440, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('c43a440', emu.reg('ecx') - THIS)))
    hook_rec(c, 0x4395d0, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('c4395d0', emu.reg('ecx') - THIS, emu.r32(THIS + 0x1218))))
    hook_rec(c, 0x43a130, 2, ret=0, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('c43a130', emu.reg('ecx') - THIS, emu.arg32(0), emu.arg32(1))))
    hook_rec(c, 0x43b630, 1, ret=0, pop=8, this=True,
             side=lambda emu, k: emu.calllog.append(('c43b630', nm(emu.reg('ecx') - 4), emu.arg32(0), emu.arg32(1) & 0xff)))
    return [THIS]


S(0x43afe0, 'GUESS FUN_43afe0', 'thiscall', None, ret=None, gen=g43afe0, note='batch246006')


def g4dd0c0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    unp = lambda emu, a, n=3: struct.unpack('<%df' % n, emu.rbytes(a, 4 * n))
    FV = lambda: r.choice([0.0, 1.0, -1.0, 2.0, 0.5])
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    THIS = em.alloc(0x80, 4)
    names[THIS] = 'T'
    GO = em.alloc(0x5d60, 4)
    G = em.alloc(0x1b00, 4)
    em.w32(0x70039c, G)
    ub(G + 0x9b, GO)
    # H
    nullh = r.random() < 0.1
    H = rnd(c, 0x10)
    HVT = rnd(c, 0x20)
    em.w32(H, HVT)
    names[H] = 'H'
    ub(GO + 0x5d35, 0 if nullh else H)
    R = em.alloc(0x100, 4)
    names[R] = 'R'
    em.w32(HVT, pystub(c, 2, ret=0, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('h0', emu.reg('ecx') - H, emu.arg32(0), nm(emu.arg32(1))))))
    em.w32(HVT + 0xc, pystub(c, 1, ret=R, pop=4, this=True, stackmark=(0,), side=lambda emu, k: (emu.w32(emu.arg32(0), 0x1234), emu.calllog.append(('h0c',)))))
    flagsets = [0, 0, 0x40000000, 0x40000, 0x40040000, 0x200000, 0x40000000]
    em.w32(THIS + 0x3c, r.choice(flagsets))
    for off in (0x30, 0x34, 0x38):
        em.wbytes(THIS + off, pk(FV()))
    T54 = em.alloc(0x20, 4)
    ub(THIS + 0x54, T54)
    X8 = em.alloc(0x10, 4)
    em.w32(T54 + 8, X8)
    TXT = rnd(c, 0x20)
    em.wbytes(TXT, b'nm\0')
    em.w32(T54 + 4, r.choice([0, TXT]))
    em.wbytes(THIS + 0x5c, struct.pack('<H', r.choice([0, 0, 7, 9])))
    # worlds
    def mkworld(lab):
        w = em.alloc(0x20, 4)
        names[w] = lab
        node = em.alloc(0x80, 4)
        names[node] = lab + 'n'
        em.w32(w + 8, node)
        em.w32(node + 0x50, r.choice([0, 0x1000, 0x2000]))
        em.wbytes(node + 0x24, pk(FV(), FV(), FV()))
        em.wbytes(node, pk(FV(), FV(), FV()))
        return w
    worlds = [mkworld('w%d' % i) for i in range(3)]
    ub(GO + 0xadc, worlds[0])
    # o8: record lookup
    O8 = rnd(c, 0x10)
    O8VT = rnd(c, 0x100)
    em.w32(O8, O8VT)
    em.w32(GO + 8, O8)
    recs = []
    for i in range(2):
        rc = em.alloc(0x30, 4)
        em.w32(rc, worlds[1 + i])
        em.wbytes(rc + 0x1c, bytes([r.choice([0, 1])]))
        recs.append(rc)
    em.w32(O8VT + 0x5c, pystub(c, 1, ret=lambda emu, k: r.choice([0] + recs + recs), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('o8_5c', emu.arg32(0)))))
    base2 = em.alloc(0x80, 4)
    em.wbytes(base2 + 0x5c, struct.pack('<H', r.choice([0, 3, 5])))
    hook_rec(c, 0x4dafb0, 0, ret=base2, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('c4dafb0', emu.reg('ecx') - THIS)))
    hook_rec(c, 0x4db2f0, 1, ret=worlds[1], pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c4db2f0', emu.reg('ecx') - X8, emu.arg32(0))))
    hook_rec(c, 0x4dc630, 2, ret=0, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('c4dc630', emu.reg('ecx') - THIS, emu.arg32(0), emu.arg32(1))))
    hook_rec(c, 0x4de7a0, 0, ret=0, pop=0, this='mark', side=lambda emu, k: emu.wbytes(emu.reg('ecx'), pk(*[float(i % 3 == i // 3) for i in range(9)])))
    hook_rec(c, 0x4db600, 2, ret=0, pop=8, this=True, stackmark=(0, 1),
             side=lambda emu, k: (emu.calllog.append(('c4db600', emu.rbytes(emu.arg32(0), 36).hex(), emu.rbytes(emu.arg32(1), 12).hex())),
                                  emu.wbytes(emu.arg32(1), pk(*[x + 1.0 for x in unp(emu, emu.arg32(1))]))))
    hook_rec(c, 0x4db1f0, 1, ret=0, pop=4, this=True, stackmark=(0,),
             side=lambda emu, k: (emu.calllog.append(('c4db1f0', emu.reg('ecx'), emu.rbytes(emu.arg32(0), 12).hex())), emu.wbytes(emu.arg32(0), pk(FV(), FV(), FV()))))
    hook_rec(c, 0x4db270, 1, ret=0, pop=4, this=True, stackmark=(0,),
             side=lambda emu, k: (emu.calllog.append(('c4db270', emu.reg('ecx'))), emu.wbytes(emu.arg32(0), pk(FV(), FV(), FV()))))

    def fast(name, fn):
        def h(emu, k):
            ec, ed = emu.reg('ecx'), emu.reg('edx')
            v = unp(emu, ec)
            emu.calllog.append((name, emu.rbytes(ec, 12).hex(), emu.rbytes(ed, 12).hex()))
            emu.wbytes(ec, pk(*[fn(a, b) for a, b in zip(v, unp(emu, ed))]))
        return h
    hook_rec(c, 0x43e960, 0, ret=0, pop=0, side=fast('c43e960', lambda a, b: a + b))
    hook_rec(c, 0x441a60, 0, ret=0, pop=0, side=fast('c441a60', lambda a, b: a - b))
    # candidates
    allgood = r.random() < 0.2
    nc = r.choice([0, 1, 3, 6, 14]) if not allgood else r.choice([12, 13, 14, 15])
    cands = []
    CVT = rnd(c, 0x400)
    for i in range(nc):
        cd = em.alloc(0x80, 4)
        names[cd] = 'c%d' % i
        em.w32(cd + 0x3c, r.choice([0, 0x400, 0x40000, 0x40000, 0x800000]) if not allgood else 0)
        em.w32(cd + 0x68, r.choice([0, 1]) if not allgood else 1)
        co = em.alloc(0x20, 4)
        cc = em.alloc(0x40, 4)
        em.w32(co, CVT)
        em.w32(co + 0xc, cc)
        ub(cc + 0x23, r.choice([0x80000d, 0x800000, 0x100000, 0x100002, 0x200002, 0x900000]) if not allgood else 0x800000)
        ub(cd + 0x54, co) if (r.random() < 0.85 or allgood) else None
        cands.append(cd)
    em.w32(CVT + 0x2a8, pystub(c, 0, ret=lambda emu, k: r.choice([0x10000, 0, 0x10001, 0x20000]), pop=0, this=True, side=lambda emu, k: emu.calllog.append(('v2a8',))))
    # collision query object
    Q = rnd(c, 0x10)
    QVT = rnd(c, 0x100)
    em.w32(Q, QVT)
    G1 = em.alloc(0x20, 4)
    em.w32(G1 + 0x1c, Q)
    ub(G + 0x1aa3, G1)

    def s3c(emu, k):
        a = [emu.arg32(i) for i in range(11)]
        for i, cd in enumerate(cands):
            emu.w32(a[0] + 4 * i, cd)
        emu.calllog.append(('q3c', nm(a[2]), a[3], emu.rbytes(a[4], 36).hex(), emu.rbytes(a[5], 12).hex(), a[6] - THIS, a[7], a[8], a[9], a[10]))
        return len(cands)
    em.w32(QVT + 0x3c, pystub(c, 11, ret=s3c, pop=44, this=True, stackmark=(0, 1, 4, 5), side=lambda emu, k: None))
    hook_rec(c, 0x4dac50, 0, ret=lambda emu, k: 0x7000 + emu.reg('ecx') % 0x100, pop=0, side=lambda emu, k: emu.calllog.append(('c4dac50', nm(emu.reg('ecx')))))
    hook_rec(c, 0x4dba00, 1, ret=lambda emu, k: (r.choice([0, 1, 0x100, 0x101]) if not allgood else 1), pop=4, stackmark=(0,),
             side=lambda emu, k: emu.calllog.append(('c4dba00', emu.reg('ecx') - THIS, emu.reg('edx'))))
    cnt = [0]

    def h4db070(emu, k):
        cnt[0] += 1
        emu.calllog.append(('c4db070', emu.reg('ecx'), nm(emu.reg('edx')), emu.arg32(0) - THIS, nm(emu.arg32(1))))
        return emu.reg('ecx') + r.choice([0, 1, 2])
    hook_rec(c, 0x4db070, 2, ret=h4db070, pop=8)
    # logger
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x30, pystub(c, 5, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x30', [emu.arg32(i) for i in range(1, 5)]))))
    return [THIS]


S(0x4dd0c0, 'GUESS FUN_4dd0c0', 'thiscall', None, ret=None, gen=g4dd0c0, note='batch246006')


def g60c4a0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    THIS = em.alloc(0x1500, 4)
    A = rnd(c, 0x20)
    B = rnd(c, 0x20)
    names[A] = 'A'
    names[B] = 'B'
    O1 = rnd(c, 0x10)
    O2 = rnd(c, 0x10)
    names[O1] = 'O1'
    names[O2] = 'O2'
    OV = rnd(c, 0x100)
    em.w32(O1, OV)
    em.w32(O2, OV)
    a0 = r.choice([0, O1, O1, O1])
    b0 = r.choice([0, O2, O2, O2])
    em.w32(A, a0)
    em.w32(B, b0)
    em.wbytes(A + 0x10, bytes([r.choice([0, 1, 1, 0x80])]))
    em.wbytes(B + 0xc, bytes([r.choice([0, 1, 1, 0x80])]))
    ub(THIS + 0x13f2, A)
    ub(THIS + 0x13f6, B)
    em.w32(OV + 0x30, pystub(c, 1, ret=0, pop=4, side=lambda emu, k: emu.calllog.append(('unlock', nm(emu.arg32(0))))))
    # device
    D = rnd(c, 0x10)
    DV = rnd(c, 0x200)
    em.w32(D, DV)
    em.w32(0x724a00, D)
    names[D] = 'D'
    em.w32(DV + 0x14c, pystub(c, 4, ret=0, pop=16, side=lambda emu, k: emu.calllog.append(('d14c', [nm(emu.arg32(i)) for i in range(4)]))))
    em.w32(DV + 0x154, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('d154', [nm(emu.arg32(i)) for i in range(3)]))))
    em.w32(DV + 0x130, pystub(c, 2, ret=0, pop=8, side=lambda emu, k: emu.calllog.append(('d130', [nm(emu.arg32(i)) for i in range(2)]))))
    em.w32(0x724970, r.choice([a0, a0, r.getrandbits(32)]))
    em.w32(0x7249b0, r.choice([0x24, 0x24, 0x23, 0x25, r.getrandbits(32)]))
    em.w32(0x7249f0, r.choice([b0, b0, r.getrandbits(32)]))
    em.w32(0x7249f4, r.choice([0, 0, 1, r.getrandbits(32)]))
    em.w32(0x7249f8, r.choice([0x152, 0x152, 0x151, 0x153, 0]))
    # draw object
    DO = rnd(c, 0x10)
    DOV = rnd(c, 0x200)
    em.w32(DO, DOV)
    ub(THIS + 0x1377, DO)
    em.w32(DOV + 0x11c, pystub(c, 6, ret=lambda emu, k: r.getrandbits(32), pop=24, side=lambda emu, k: emu.calllog.append(('d11c', nm(emu.arg32(0)), [emu.arg32(i) for i in range(1, 6)]))))
    # lock helpers
    n = r.choice([0, 1, 2, 5, 9])
    cnt = r.choice([0, 1, 2, 3, 7, 15, 16, 17, 31, 32, 33, 40])
    SRC = rnd(c, 36 * 10)
    VB = rnd(c, 36 * 10 + 16)
    names[VB] = 'VB'
    IBUF = rnd(c, 0x440)
    idx = IBUF + 0x100
    dst = IBUF + r.choice([0x300, 0, 0x100, 0x102, 0x104, 0xfc, 0xf0, 0x110, 0x2fe])
    voff = r.choice([0, 1, 5, 0x7fff, 0x8000, 0xffff, 0x12345, 0xffffffff, 40, 0x1ffff])
    ioff = r.choice([0, 3, 100, 0x10000, 0xffff])
    em.w32(0x7249f8, em.r32(0x7249f8))
    hook_rec(c, 0x60ee10, 2, ret=lambda emu, k: (VB if (n or r.random() < 0.5) else 0), pop=8, this=True, stackmark=(0, 1),
             side=lambda emu, k: (emu.calllog.append(('lockA', nm(emu.reg('ecx')), emu.r32(emu.arg32(0)))), emu.w32(emu.arg32(1), voff)))
    hook_rec(c, 0x60ed80, 2, ret=lambda emu, k: (dst if (cnt or r.random() < 0.5) else 0), pop=8, this=True, stackmark=(0, 1),
             side=lambda emu, k: (emu.calllog.append(('lockB', nm(emu.reg('ecx')), emu.r32(emu.arg32(0)))), emu.w32(emu.arg32(1), ioff)))
    mode = c.case % 7
    import os
    if os.environ.get('DBG60'):
        print('DBG', hex(THIS), hex(VB), hex(SRC), hex(idx), hex(dst), n, cnt, mode, hex(voff))
    return [THIS, mode, SRC, n, idx, cnt]


S(0x60c4a0, 'GUESS FUN_60c4a0', 'thiscall', None, ret=None, gen=g60c4a0, note='batch246006')


def g5460b0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    V = rnd(c, 0x40)
    O1 = rnd(c, 0x10)
    O2 = rnd(c, 0x10)
    vals = [0.0, 1.0, -1.0, 0.5, 0.25, 3.0, 45.0, 90.0, 180.0, 10.0, -7.5, 100.0, 359.0, 1e-3, 1e30]

    def fv():
        k = r.random()
        if k < 0.5:
            return r.choice(vals)
        if k < 0.9:
            return r.uniform(-200, 200)
        return r.choice([float('nan'), float('inf'), -float('inf'), -0.0])
    f0, f1, f2, f3 = fv(), fv(), fv(), fv()
    m = r.random()
    if m < 0.15:
        f1 = -f0
    elif m < 0.3:
        f3 = -f2
    elif m < 0.4:
        f1 = f0
    elif m < 0.5:
        f3 = f2
    elif m < 0.58:
        f1 = -f0
        f3 = -f2
    return [V, O1, O2, F(f0), F(f1), F(f2), F(f3)]


S(0x5460b0, 'GUESS FUN_5460b0', 'fastcall', None, ret=None, gen=g5460b0, note='batch246006')


def g55c1a0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    THIS = rnd(c, 0x40)
    SRC = rnd(c, 0x10)
    P1 = rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    names[THIS] = 'T'
    # entries
    FV = lambda: r.choice([0.0, 1.0, 2.0, -1.0, 3.0, 0.5, 10.0])
    OBJ = rnd(c, 0x10)
    OVT = rnd(c, 0x80)
    em.w32(OBJ, OVT)
    names[OBJ] = 'O'
    em.w32(OVT + 0x34, pystub(c, 0, ret=lambda emu, k: r.choice([0, 7, 0x12345]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('o34', nm(emu.reg('ecx'))))))
    ents = [rnd(c, 0x10) for _ in range(4)]
    k0 = r.choice([3, 4, 4, 3, 0, 5])
    em.wbytes(ents[0] + 4, bytes([k0]))
    em.w32(ents[0], OBJ if k0 == 4 else r.getrandbits(32))
    em.wbytes(ents[1] + 4, bytes([r.choice([0, 2, 2, 1, 5])]))
    rv = r.choice([0.0, 0.5, 1.0, 2.0, 5.0, 100.0, 1e-3, float('nan'), float('inf')]) if r.random() < 0.9 else FV()
    em.wbytes(ents[1], struct.pack('<f', rv))
    em.wbytes(ents[2] + 4, bytes([r.choice([0, 1, 1, 2, 5])]))
    em.w32(ents[2], r.getrandbits(32))
    em.wbytes(ents[3] + 4, bytes([r.choice([0, 1, 1, 2, 5])]))
    em.w32(ents[3], r.getrandbits(32))

    def s3d0(emu, k):
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', emu.reg('ecx') - P1, i))
        return ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    # logger
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    # G[0x9b]
    G = rnd(c, 0x1b00)
    em.w32(0x70039c, G)
    HO = rnd(c, 0x10)
    HVT = rnd(c, 0x200)
    em.w32(HO, HVT)
    ub(G + 0x9b, HO)
    names[HO] = 'H'
    em.w32(HVT + 0x114, pystub(c, 4, ret=lambda emu, k: r.choice([0, 1, 0x1234, 0xffff, 0x12345678, 0xffffffff]), pop=16, this=True,
                               side=lambda emu, k: emu.calllog.append(('h114', nm(emu.reg('ecx')), [emu.arg32(i) for i in range(4)]))))
    # W
    W = rnd(c, 0x930)
    names[W] = 'W'
    em.w32(THIS + 0x1c, W)
    WP = rnd(c, 0x10)
    key = r.choice([0, 1, 5])
    em.w32(WP + 4, key)
    em.w32(W + 0x54, WP)
    WVT = rnd(c, 0x200)
    em.w32(W, WVT)
    vec = lambda: pk(FV(), FV(), FV())
    em.w32(WVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,),
                              side=lambda emu, k: (emu.wbytes(emu.arg32(0), vec()), emu.calllog.append(('w84', emu.rbytes(emu.arg32(0), 12).hex())))))
    L = rnd(c, 0x10)
    LV2 = rnd(c, 0x200)
    em.w32(L, LV2)
    names[L] = 'L'
    nulll = r.random() < 0.12
    ub(W + 0x913, 0 if nulll else L)
    # items
    n = r.choice([0, 1, 2, 3, 5, 8])
    IVT = rnd(c, 0x200)
    items = []
    for i in range(n):
        if r.random() < 0.12:
            items.append(W)
            continue
        it = rnd(c, 0x80)
        names[it] = 'i%d' % i
        em.w32(it, IVT)
        ip = rnd(c, 0x10)
        em.w32(ip + 4, key if r.random() < 0.7 else key + 1)
        em.w32(it + 0x54, ip)
        items.append(it)
    em.w32(IVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,),
                              side=lambda emu, k: (emu.wbytes(emu.arg32(0), vec()), emu.calllog.append(('i84', nm(emu.reg('ecx')), emu.rbytes(emu.arg32(0), 12).hex())))))
    em.w32(IVT + 0x128, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(1,),
                               side=lambda emu, k: emu.calllog.append(('i128', nm(emu.reg('ecx')), emu.arg32(0), emu.rbytes(emu.arg32(1), 8).hex(), emu.arg32(2)))))
    pos = [0]

    def sl84(emu, k):
        p, rb, cur, m1 = emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3)
        emu.calllog.append(('l84', nm(emu.reg('ecx')), emu.rbytes(p, 12).hex(), rb, emu.r32(cur), m1))
        i = pos[0]
        pos[0] += 1
        emu.w32(cur, i)
        return items[i] if i < len(items) else 0
    em.w32(LV2 + 0x84, pystub(c, 4, ret=sl84, pop=16, this=True, stackmark=(0, 2)))
    return [THIS, SRC]


S(0x55c1a0, 'GUESS FUN_55c1a0', 'thiscall', None, ret=None, gen=g55c1a0, note='batch246006')


def g559a10(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    FV = lambda: r.choice([0.0, 1.0, 2.0, -1.0, 3.0, 0.5, 10.0, -4.0])
    THIS = rnd(c, 0x40)
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    ents = [rnd(c, 0x10) for _ in range(4)]
    vals = [FV(), FV(), FV()]
    for i in range(3):
        em.wbytes(ents[i], pk(vals[i]))
        em.wbytes(ents[i] + 4, bytes([r.choice([0, 1, 2, 3])]))
    em.wbytes(ents[3], pk(r.choice([0.0, 1.0, 2.0, 0.5, -1.0, 100.0, 0.25])))
    outs = [rnd(c, 0x10) for _ in range(3)]
    for o in outs:
        em.wbytes(o + 4, bytes([r.choice([0, 2, 2, 2, 1, 5])]))

    def s3d0(emu, k):
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', 1 if emu.reg('ecx') == P2 else 0, i))
        return outs[i] if emu.reg('ecx') == P2 else ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    W = rnd(c, 0x20)
    WVT = rnd(c, 0x200)
    em.w32(W, WVT)
    em.w32(THIS + 0x1c, W)
    names[W] = 'W'
    same = r.random() < 0.2

    def s84(emu, k):
        v = vals if same else [FV(), FV(), FV()]
        emu.wbytes(emu.arg32(0), pk(*v))
        emu.calllog.append(('w84', nm(emu.reg('ecx')), emu.rbytes(emu.arg32(0), 12).hex()))
    em.w32(WVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s84))
    G = rnd(c, 0x1b00)
    em.w32(0x70039c, G)
    GK = rnd(c, 0x40)
    ub(G + 0x1aa3, GK)
    K = rnd(c, 0x20)
    KVT = rnd(c, 0x100)
    em.w32(K, KVT)
    em.w32(GK + 0x1c, K)
    names[K] = 'K'

    def s30(emu, k):
        a = [emu.arg32(i) for i in range(8)]
        emu.calllog.append(('k30', nm(emu.reg('ecx')), emu.r32(a[0]), a[1], emu.rbytes(a[2], 12).hex(), emu.rbytes(a[3], 12).hex(), a[4:]))
        emu.wbytes(a[0] + 4, pk(FV(), FV(), FV()))
    em.w32(KVT + 0x30, pystub(c, 8, ret=lambda emu, k: r.choice([0, 1, 1, 0x100, 0x101, 0xff]), pop=32, this=True, stackmark=(0, 2, 3), side=s30))
    return [THIS, SRC]


S(0x559a10, 'GUESS FUN_559a10', 'thiscall', None, ret=None, gen=g559a10, note='batch246006')


def g553a30(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)

    def FV():
        q = r.random()
        if q < 0.9:
            return r.choice([0.0, 1.0, 2.0, -1.0, 3.5, 0.5, 10.0, -4.0, 100.0])
        return r.choice([float('nan'), float('inf'), -0.0, 1e30])
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    ents = [rnd(c, 0x10) for _ in range(6)]
    good = r.random() < 0.6
    for e in ents:
        em.wbytes(e, pk(FV()))
        em.wbytes(e + 4, bytes([r.choice([0, 2]) if good or r.random() < 0.8 else r.choice([1, 3, 5])]))
    out = rnd(c, 0x10)
    em.wbytes(out + 4, bytes([r.choice([0, 2, 2, 1, 5, 0x80])]))

    def s3d0(emu, k):
        i = emu.arg32(0)
        isout = emu.reg('ecx') == P2
        emu.calllog.append(('e3d0', 1 if isout else 0, i))
        return out if isout else ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    return [SRC]


S(0x553a30, 'GUESS FUN_553a30', 'stdcall', None, ret=None, gen=g553a30, note='batch246006')


def g556780(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    THIS = rnd(c, 0x40)
    names[THIS] = 'T'
    SRC = rnd(c, 0x10)
    P1 = rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    ents = [rnd(c, 0x10) for _ in range(3)]
    OBJ = rnd(c, 0x10)
    OVT = rnd(c, 0x80)
    em.w32(OBJ, OVT)
    names[OBJ] = 'O'
    em.w32(OVT + 0x34, pystub(c, 0, ret=lambda emu, k: r.choice([0, 7, 0x12345]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('o34', nm(emu.reg('ecx'))))))
    k0 = r.choice([3, 4, 4, 3, 0, 5])
    em.wbytes(ents[0] + 4, bytes([k0]))
    em.w32(ents[0], OBJ if k0 == 4 else r.getrandbits(32))
    ID = r.choice([0, 5, 9, 0x77]) if r.random() < 0.9 else r.getrandbits(32)
    if r.random() < 0.9 and ID == 0:
        ID = 5
    em.w32(ents[1], ID)
    em.w32(ents[2], r.getrandbits(32))
    for i in (1, 2):
        em.wbytes(ents[i] + 4, bytes([r.choice([0, 1, 1, 1, 5])]))

    def s3d0(emu, k):
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', emu.reg('ecx') - P1, i))
        return ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    # globals
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    H = rnd(c, 0xb10)
    HVT = rnd(c, 0x200)
    em.w32(H, HVT)
    ub(G + 0x9b, H)
    names[H] = 'H'
    # N
    N = rnd(c, 0x20)
    NVT = rnd(c, 0x200)
    em.w32(N, NVT)
    names[N] = 'N'
    NB = rnd(c, 0x50)
    ev = [r.choice([0.5, 1.0, 2.0, 3.0, 5.0, float('nan')]) if r.random() < 0.1 else r.choice([1.0, 2.0, 3.0, 5.0, 0.5]) for _ in range(3)]
    em.wbytes(NB + 0x40, pk(*ev))
    em.w32(N + 8, NB)
    small = r.random() < 0.6

    def dv():
        if small:
            if r.random() < 0.06:
                return float('nan')
            return r.choice([0.0, 0.25, -0.5, 1.0, -1.0, 2.0, -2.0, 0.5])
        return r.choice([0.0, 4.0, -6.0, 1.0, 3.0, float('nan'), -3.0, 2.0, 5.0])

    def s8c(emu, k):
        emu.wbytes(emu.arg32(0), pk(dv(), dv(), dv()))
        emu.calllog.append(('n8c', emu.rbytes(emu.arg32(0), 12).hex()))
    em.w32(NVT + 0x8c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s8c))
    # items
    n = r.choice([0, 1, 2, 3, 5])
    MVT = rnd(c, 0x200)
    Ms = []
    toks = {}
    for i in range(n):
        m = rnd(c, 0x20)
        em.w32(m, MVT)
        names[m] = 'M%d' % i
        o2 = rnd(c, 0x20)
        x = rnd(c, 0x80)
        em.w32(o2 + 8, x)
        em.w32(x + 0x3c, r.choice([0, 0x400, 0x400, 0x1000, 0x7ff, 0xffffffff]) )
        em.w32(m + 4, o2)
        Ms.append(m)
        toks[0x1001 + i] = m
    o2of = {m: em.r32(m + 4) for m in Ms}
    em.w32(MVT + 0x20, pystub(c, 0, ret=lambda emu, k: o2of[emu.reg('ecx')], pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('m20', nm(emu.reg('ecx'))))))
    em.w32(MVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,),
                              side=lambda emu, k: (emu.wbytes(emu.arg32(0), pk(*[r.choice([0.0, 0.5, -0.5, 1.0]) for _ in range(3)])), emu.calllog.append(('m84', nm(emu.reg('ecx')))))))
    em.w32(MVT + 0x128, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(1,),
                               side=lambda emu, k: emu.calllog.append(('m128', nm(emu.reg('ecx')), emu.arg32(0), emu.r32(emu.arg32(1)), emu.arg32(2)))))

    def s58(emu, k):
        a = emu.arg32(0)
        emu.calllog.append(('h58', a if a not in toks else ('tok', a - 0x1001)))
        if a in toks:
            return toks[a]
        if a == 0 and Ms:
            return Ms[0]
        return N
    em.w32(HVT + 0x58, pystub(c, 1, ret=s58, pop=4, this=True))
    em.w32(HVT + 0x114, pystub(c, 4, ret=lambda emu, k: r.choice([0, 1, 0x1234, 0xffff, 0x12345678]), pop=16, this=True,
                               side=lambda emu, k: emu.calllog.append(('h114', [emu.arg32(i) for i in range(4)]))))
    # this[0x10]
    P = rnd(c, 0x30)
    names[P] = 'P'
    CV = rnd(c, 0x20)
    CVT = rnd(c, 0x200)
    em.w32(CV, CVT)
    names[CV] = 'C'
    em.w32(P + 0x18, 0 if r.random() < 0.1 else CV)
    pre = r.random() < 0.5
    em.w32(THIS + 0x10, P if pre else 0)
    S = rnd(c, 0x20)
    SVT = rnd(c, 0x400)
    em.w32(S, SVT)
    ub(H + 0xadc, S)
    names[S] = 'S'
    em.w32(SVT + 0x25c, pystub(c, 2, ret=lambda emu, k: r.choice([0, P, P, P]), pop=8, this=True,
                               side=lambda emu, k: emu.calllog.append(('s25c', nm(emu.reg('ecx')), emu.arg32(0), emu.arg32(1)))))
    pos = [0]
    CV2 = rnd(c, 0x20)
    em.w32(CV2, CVT)
    names[CV2] = 'C2'
    swap = r.random() < 0.3
    endmode = r.choice([0, 0, 1, 2]) if Ms else 0

    def s4c(emu, k):
        emu.calllog.append(('c4c', nm(emu.reg('ecx'))))
        pos[0] = 0
        emu.w32(emu.arg32(0), 0xdead)
    em.w32(CVT + 0x4c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s4c))

    def s5c(emu, k):
        i = pos[0]
        pos[0] += 1
        emu.calllog.append(('c5c', nm(emu.reg('ecx')), i))
        if swap and i == 0:
            emu.w32(P + 0x18, CV2)
        if i < n:
            emu.w32(emu.arg32(0), 1)
            return 0x1001 + i
        if endmode == 2 and i == n:
            emu.w32(emu.arg32(0), 1)
            return 0
        emu.w32(emu.arg32(0), 0)
        return 0x1001 if endmode == 1 else 0
    em.w32(CVT + 0x5c, pystub(c, 1, ret=s5c, pop=4, this=True, stackmark=(0,)))
    return [THIS, SRC]


S(0x556780, 'GUESS FUN_556780', 'thiscall', None, ret=None, gen=g556780, note='batch246006')


def g491b70(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    THIS = rnd(c, 0x5d50)
    TVT = rnd(c, 0x200)
    em.w32(THIS, TVT)
    names[THIS] = 'T'
    ub(THIS + 0x5d2d, r.choice([0, 3, 100, 0xfffffffb, 1, 7]))
    em.w32(TVT + 0x90, pystub(c, 3, ret=0, pop=12, this=True, st0=0.5,
                              side=lambda emu, k: emu.calllog.append(('t90', emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    L = rnd(c, 0x20)
    LVT = rnd(c, 0x200)
    em.w32(L, LVT)
    names[L] = 'L'
    em.w32(LVT + 0x14, pystub(c, 0, ret=lambda emu, k: r.choice([0, 1, 2, 7]), pop=0, this=True))
    n = r.choice([0, 1, 2, 3])
    pos = [0]
    endmode = r.choice([0, 0, 1, 2])

    def s4c(emu, k):
        pos[0] = 0
        emu.w32(emu.arg32(0), 0xdead)
        emu.calllog.append(('l4c', pos[0]))
    em.w32(LVT + 0x4c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s4c))

    def s5c(emu, k):
        i = pos[0]
        pos[0] += 1
        emu.calllog.append(('l5c', i))
        if i < n:
            emu.w32(emu.arg32(0), 1)
            return 0x2001 + i
        if endmode == 2 and i == n:
            emu.w32(emu.arg32(0), 1)
            return 0
        emu.w32(emu.arg32(0), 0)
        return 0x2001 if endmode == 1 else 0
    em.w32(LVT + 0x5c, pystub(c, 1, ret=s5c, pop=4, this=True, stackmark=(0,)))
    # globals
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    H = rnd(c, 0xb10)
    HVT = rnd(c, 0x200)
    em.w32(H, HVT)
    ub(G + 0x9b, H)
    S = rnd(c, 0x20)
    SVT = rnd(c, 0x400)
    em.w32(S, SVT)
    em.w32(H + 0xadc, S)
    names[S] = 'S'
    em.w32(SVT + 0x154, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('s154', nm(emu.reg('ecx'))))))
    em.w32(SVT + 0x158, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('s158', nm(emu.reg('ecx'))))))
    YVT = rnd(c, 0x400)
    em.w32(YVT + 0x154, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('y154', nm(emu.reg('ecx'))))))
    em.w32(YVT + 0x158, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('y158', nm(emu.reg('ecx'))))))
    objs = {}
    for t in (0, 0x2001, 0x2002, 0x2003):
        q = r.random()
        if q < 0.2:
            objs[t] = 0
            continue
        x = rnd(c, 0x80)
        names[x] = 'X%x' % t
        if r.random() < 0.8:
            y = rnd(c, 0x20)
            em.w32(y, YVT)
            names[y] = 'Y%x' % t
            em.w32(x + 0x54, y)
        else:
            em.w32(x + 0x54, 0)
        objs[t] = x

    def s54(emu, k):
        a = emu.arg32(0)
        emu.calllog.append(('h54', a))
        return objs.get(a, 0)
    em.w32(HVT + 0x54, pystub(c, 1, ret=s54, pop=4, this=True))
    hook_rec(c, 0x4dc630, 2, ret=0, pop=8, this=True,
             side=lambda emu, k: emu.calllog.append(('c4dc630', nm(emu.reg('ecx')), emu.arg32(0), emu.arg32(1))))
    # nodes
    k = r.choice([0, 1, 2, 3, 5])
    NVT = rnd(c, 0x200)
    OVT = rnd(c, 0x400)
    nodes = []
    alt = rnd(c, 0x20)
    names[alt] = 'ALT'
    em.w32(alt, OVT)
    ax = rnd(c, 0x80)
    em.w32(ax + 0x3c, 0)
    em.w32(alt + 8, ax)
    for i in range(k):
        nd = rnd(c, 0x40)
        em.w32(nd, NVT)
        names[nd] = 'N%d' % i
        em.w32(nd + 4, r.choice([0, 0, 1, 2, 4, 8, 0x100, 5, 0x10]))
        em.w32(nd + 0x14, r.choice([0, 1, 2, 3, 0x201, 0x202, 0x203, 0x200, 1, 2, 0x1ff]))
        if r.random() < 0.85:
            ob = rnd(c, 0x20)
            names[ob] = 'O%d' % i
            em.w32(ob, OVT)
            xx = rnd(c, 0x80)
            em.w32(xx + 0x3c, r.choice([0, 0x400, 0x400, 0x1000, 0xffffffff, 0x3ff, 0x800]))
            em.w32(ob + 8, xx)
            em.w32(nd + 0x30, ob)
        else:
            em.w32(nd + 0x30, 0)
        nodes.append(nd)
    for i, nd in enumerate(nodes):
        em.w32(nd + 0x28, nodes[i + 1] if i + 1 < len(nodes) else 0)
    ub(THIS + 0x5d29, nodes[0] if nodes else 0)

    def ns(slot, tag, setbit):
        def side(emu, kk):
            ec = emu.reg('ecx')
            emu.calllog.append((tag, nm(ec), emu.r32(ec + 4)))
            if setbit:
                emu.w32(ec + 4, emu.r32(ec + 4) | r.choice([0, 1]))
        return side
    em.w32(NVT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=ns(8, 'n8', True)))
    em.w32(NVT + 0xc, pystub(c, 0, ret=0, pop=0, this=True, side=ns(0xc, 'nc', True)))

    def n4c(emu, kk):
        ec = emu.reg('ecx')
        emu.calllog.append(('n4c', nm(ec), emu.r32(ec + 4)))
        if r.random() < 0.25 and emu.r32(ec + 0x30):
            emu.w32(ec + 0x30, alt)
    em.w32(NVT + 0x4c, pystub(c, 0, ret=0, pop=0, this=True, side=n4c))
    em.w32(NVT + 0x54, pystub(c, 1, ret=0, pop=4, this=True,
                              side=lambda emu, kk: emu.calllog.append(('n54', nm(emu.reg('ecx')), nm(emu.arg32(0)), emu.r32(emu.reg('ecx') + 4)))))
    em.w32(OVT + 0x1e8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, kk: emu.calllog.append(('o1e8', nm(emu.reg('ecx'))))))
    return [THIS, L]


S(0x491b70, 'GUESS FUN_491b70', 'thiscall', None, ret=None, gen=g491b70, note='batch246006')


def g554f20(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    FV = lambda: r.choice([0.0, 1.0, 2.0, -1.0, 3.5, 0.5, 10.0, -4.0])
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    e0 = rnd(c, 0x10)
    em.w32(e0, r.choice([0, 5, 9, 0x77]))
    em.wbytes(e0 + 4, bytes([r.choice([0, 1, 1, 1, 5])]))
    outs = [rnd(c, 0x10) for _ in range(6)]
    for o in outs:
        em.wbytes(o + 4, bytes([r.choice([0, 0, 2, 2, 2, 1, 5])]))
        em.wbytes(o, pk(FV()))

    def s3d0(emu, k):
        i = emu.arg32(0)
        isout = emu.reg('ecx') == P2
        emu.calllog.append(('e3d0', 1 if isout else 0, i))
        return outs[i] if isout else e0
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    H = rnd(c, 0x20)
    HVT = rnd(c, 0x200)
    em.w32(H, HVT)
    em.wbytes(G + 0x9b, H.to_bytes(4, 'little'))
    O = rnd(c, 0x20)
    OVT = rnd(c, 0x100)
    em.w32(O, OVT)
    names[O] = 'O'
    A1 = rnd(c, 0x20)
    A2 = rnd(c, 0x20)
    A4 = rnd(c, 0x20)
    B = rnd(c, 0x20)
    Z2 = rnd(c, 0x20)
    for a, nme in ((A1, 'A1'), (A2, 'A2'), (A4, 'A4'), (B, 'B'), (Z2, 'Z2')):
        names[a] = nme
    VT2, VT4, VT1, VT5 = rnd(c, 0x100), rnd(c, 0x100), rnd(c, 0x100), rnd(c, 0x100)
    em.w32(A2, VT2)
    em.w32(A4, VT4)
    em.w32(A1, VT1)
    em.w32(B, VT5)
    z1 = r.random() < 0.12
    z2 = r.random() < 0.12
    z0 = r.random() < 0.1
    cnt = [0]

    def s58(emu, k):
        emu.calllog.append(('h58', emu.arg32(0)))
        return 0 if z0 else O
    em.w32(HVT + 0x58, pystub(c, 1, ret=s58, pop=4, this=True))

    def so20(emu, k):
        i = cnt[0]
        cnt[0] += 1
        emu.calllog.append(('o20', nm(emu.reg('ecx')), i))
        return [0 if z1 else A1, A2, A4][i]
    em.w32(OVT + 0x20, pystub(c, 0, ret=so20, pop=0, this=True))
    em.w32(VT2 + 0x20, pystub(c, 0, ret=lambda emu, k: 0 if z2 else Z2, pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('a2_20', nm(emu.reg('ecx'))))))
    em.w32(VT4 + 0x20, pystub(c, 0, ret=B, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('a4_20', nm(emu.reg('ecx'))))))

    def s80(emu, k):
        m = [FV() for _ in range(9)]
        v = [FV() for _ in range(3)]
        emu.wbytes(emu.arg32(0), pk(*m))
        emu.wbytes(emu.arg32(1), pk(*v))
        emu.calllog.append(('b80', nm(emu.reg('ecx')), pk(*m).hex(), pk(*v).hex()))
    em.w32(VT5 + 0x80, pystub(c, 2, ret=0, pop=8, this=True, stackmark=(0, 1), side=s80))
    return [SRC]


S(0x554f20, 'GUESS FUN_554f20', 'stdcall', None, ret=None, gen=g554f20, note='batch246006')


def g60bba0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    THIS = rnd(c, 0x1500)
    TVT = rnd(c, 0x400)
    em.w32(THIS, TVT)
    names[THIS] = 'T'
    ub(THIS + 0x1285, r.choice([0, 1, 5, 0x40, 0x7e, 0x7f, 0x7f, 0x81, 0x90]))
    ub(THIS + 0x14f2, r.getrandbits(32))
    G = rnd(c, 0x100)
    em.w32(0x70039c, G)
    gv = r.choice([1.0, 2.0, 0.5, 0.0, -1.0, 100.0, 0.001, 1e-30, float('nan'), 255.0, -0.0])
    em.wbytes(G + 0x34, struct.pack('<f', gv))
    KO = rnd(c, 0x90)
    em.wbytes(KO + 0x7a, bytes([r.choice([0, 1, 1, 1, 0x80])]))
    ub(G + 0x1aa3, KO)
    # vtable of this
    em.w32(TVT + 0xd8, pystub(c, 0, ret=lambda emu, k: r.choice([640, 800, 1, 0, 0xffffffff, 1024]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('t_d8',))))
    em.w32(TVT + 0xdc, pystub(c, 0, ret=lambda emu, k: r.choice([480, 600, 1, 0, 768]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('t_dc',))))
    em.w32(TVT + 0x134, pystub(c, 4, ret=0, pop=16, this=True,
                               side=lambda emu, k: emu.calllog.append(('t134', [emu.arg32(i) for i in range(4)]))))
    em.w32(TVT + 0x14c, pystub(c, 7, ret=0, pop=28, this=True,
                               side=lambda emu, k: emu.calllog.append(('t14c', [emu.arg32(i) for i in range(7)]))))
    em.w32(TVT + 0x28c, pystub(c, 3, ret=0, pop=12, this=True,
                               side=lambda emu, k: emu.calllog.append(('t28c', [emu.arg32(i) for i in range(3)]))))

    def s25c(emu, k):
        a = [emu.arg32(i) for i in range(5)]
        n = a[2]
        vt = b''.join(emu.rbytes(a[1] + 36 * i + o, 4) for i in range(n) for o in (0, 4, 8, 0x18))
        emu.calllog.append(('t25c', a[0], n, a[4], vt.hex(), emu.rbytes(a[3], 2 * a[4]).hex()))
    em.w32(TVT + 0x25c, pystub(c, 5, ret=0, pop=20, this=True, stackmark=(1, 3), side=s25c))
    # device object at this[0x1377]
    DO = rnd(c, 0x10)
    DOV = rnd(c, 0x400)
    em.w32(DO, DOV)
    ub(THIS + 0x1377, DO)
    names[DO] = 'DO'
    em.w32(DOV + 0xc8, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('do_c8', nm(emu.arg32(0)), emu.arg32(1), emu.arg32(2)))))
    # global device
    D = rnd(c, 0x10)
    DV = rnd(c, 0x400)
    em.w32(D, DV)
    em.w32(0x724a00, D)
    names[D] = 'D'
    em.w32(DV + 0xc8, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('d_c8', nm(emu.arg32(0)), emu.arg32(1), emu.arg32(2)))))
    em.w32(DV + 0xfc, pystub(c, 4, ret=0, pop=16, side=lambda emu, k: emu.calllog.append(('d_fc', nm(emu.arg32(0)), emu.arg32(1), emu.arg32(2), emu.arg32(3)))))
    em.w32(0x724a08, r.choice([0, 1, 2, 3]))
    em.w32(0x724928, r.choice([5, 5, 0, 4]))
    em.w32(0x72492c, r.choice([6, 6, 0, 7]))
    em.w32(0x724934, r.choice([1, 1, 0, 2]))
    em.w32(0x72493c, r.choice([0, 0, 1]))
    em.w32(0x724968, r.choice([8, 8, 0, 4]))
    # stage caches (exe code 0x60ff30 / 0x60feb0): stages 0 and 1; values 1 / 2 / 0 or 1
    for base, vs in ((0x724868, 1), (0x724888, 2), (0x7248a8, None), (0x7248c8, 1), (0x7248e8, 2), (0x724908, None)):
        for st in (0, 1):
            want = vs if vs is not None else (0 if st == 0 else 1)
            em.w32(base + 4 * st, want if r.random() < 0.6 else r.choice([0, 1, 2, 3]))
    return [THIS]


S(0x60bba0, 'GUESS FUN_60bba0', 'thiscall', None, ret=None, gen=g60bba0, note='batch246006')


def g60d1a0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    FV = lambda: r.choice([0.0, 1.0, 2.0, -1.0, 3.5, 0.5, 10.0, -4.0, 0.25])
    THIS = rnd(c, 0x1500)
    A = rnd(c, 0x20)
    names[A] = 'A'
    O1 = rnd(c, 0x10)
    OV = rnd(c, 0x100)
    em.w32(O1, OV)
    names[O1] = 'O1'
    a0 = r.choice([0, O1, O1, O1])
    em.w32(A, a0)
    em.wbytes(A + 0x10, bytes([r.choice([0, 1, 1, 0x80])]))
    ub(THIS + 0x13f2, A)
    em.w32(OV + 0x30, pystub(c, 1, ret=0, pop=4, side=lambda emu, k: emu.calllog.append(('unlock', nm(emu.arg32(0))))))
    n = r.choice([0, 1, 2, 3])
    usebb = r.random() < 0.5
    PB = rnd(c, 0x38 * 4 + 0x20)
    for off in range(0, 0x38 * 3, 4):
        em.wbytes(PB + off, struct.pack('<f', FV()))
    BB = rnd(c, 0x40)
    for off in range(0, 0x30, 4):
        em.wbytes(BB + off, struct.pack('<f', FV()))
    color = r.getrandbits(32)
    VB = rnd(c, 0x200)
    voff = r.choice([0, 3, 100, 0x10000])
    em.w32(0x724970, r.choice([a0, a0, r.getrandbits(32)]))
    em.w32(0x7249b0, r.choice([0x24, 0x24, 0x23, r.getrandbits(32)]))
    em.w32(0x7249f8, r.choice([0x152, 0x152, 0x151, 0]))
    D = rnd(c, 0x10)
    DV = rnd(c, 0x400)
    em.w32(D, DV)
    em.w32(0x724a00, D)
    names[D] = 'D'
    em.w32(DV + 0x14c, pystub(c, 4, ret=0, pop=16, side=lambda emu, k: emu.calllog.append(('d14c', [nm(emu.arg32(i)) for i in range(4)]))))
    em.w32(DV + 0x130, pystub(c, 2, ret=0, pop=8, side=lambda emu, k: emu.calllog.append(('d130', [nm(emu.arg32(i)) for i in range(2)]))))
    hook_rec(c, 0x60ee10, 2, ret=lambda emu, k: (VB if (n or r.random() < 0.5) else 0), pop=8, this=True, stackmark=(0, 1),
             side=lambda emu, k: (emu.calllog.append(('lockA', nm(emu.reg('ecx')), emu.r32(emu.arg32(0)))), emu.w32(emu.arg32(1), voff)))
    hook_rec(c, 0x60bfc0, 2, ret=0, pop=8, this=True,
             side=lambda emu, k: emu.calllog.append(('c60bfc0', emu.reg('ecx') - THIS, emu.arg32(0), emu.arg32(1), emu.rbytes(VB, 0x90 * n).hex() if n else '')))
    # debug
    G = rnd(c, 0x1000)
    em.w32(0x70039c, G)
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)
    flt = [0.0, 1.0, 2.0, -1.0]
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    return [THIS, PB, n, BB if usebb else 0, color]


S(0x60d1a0, 'GUESS FUN_60d1a0', 'thiscall', None, ret=None, gen=g60d1a0, note='batch246006')


def g61b1e0(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    FV = lambda: r.choice([0.0, 1.0, 2.0, -1.0, 3.5, 0.5, 10.0, -4.0, 0.25, 100.0])
    THIS = rnd(c, 0x40)
    names[THIS] = 'T'
    T4 = rnd(c, 0x40)
    em.w32(THIS + 4, T4)
    em.w32(T4 + 0x14, r.choice([0, 5, 5, 5]))
    em.w32(THIS + 0xc, r.choice([0, 3, 3, 8, 0x40]))
    A = rnd(c, 0x40)
    X = rnd(c, 0x60)
    A10 = rnd(c, 0x20)
    Y = rnd(c, 0x60)
    em.w32(A + 0xc, X)
    em.w32(A + 0x10, A10)
    em.w32(A10 + 8, Y)
    mode = r.choice([1, 1, 2, 3, 5, 0, 4])
    nv = r.choice([0, 1, 3, 0x1f, 0x20, 0x21, 0x40, 2])
    neg = r.random() < 0.12
    em.w32(Y + 0x50, mode)
    em.wbytes(Y + 0xe, struct.pack('<H', nv))
    em.w32(Y + 0x20, r.getrandbits(32))
    if neg:
        em.w32(Y + 0x48, 0xfffffffe)
        em.w32(Y + 0x4c, 0xffffffff)
        xv = r.choice([0.0, 0.5, 1.0, 2.5])
    else:
        em.w32(Y + 0x48, r.choice([0, 1, 2, 0]))
        em.w32(Y + 0x4c, r.choice([1, 2, 4, 1]))
        xv = r.choice([0.0, 0.5, 1.0, 2.5, 3.7, 4.0, 0.0, 1.5, -1.0, -0.5])
    em.wbytes(X + 0x48, struct.pack('<f', xv))
    SRCSZ = 0xb000
    SRC = rnd(c, SRCSZ)
    for off in range(0, SRCSZ, 4):
        if r.random() < 0.9:
            em.wbytes(SRC + off, struct.pack('<f', FV()))
    # colors: equal colors sometimes
    em.w32(Y + 0x14, 0x2800 + r.choice([0, 4, 8]))
    G = rnd(c, 0x1b00)
    em.w32(0x70039c, G)
    K = rnd(c, 0x40)
    em.w32(K + 0x20, SRC)
    ub(G + 0x1aa3, K)
    # B: [0xb9a4] -> C
    B = rnd(c, 0xb9b0)
    C = rnd(c, 0x1410)
    em.w32(B + 0xb9a4, C)
    OV = rnd(c, 0x100)
    objs = []
    for off in (0x13fa, 0x13fe):
        o = rnd(c, 0x40)
        em.w32(o, OV)
        names[o] = 'O%x' % off
        ub(C + off, o)
        objs.append(o)
    bufs = [rnd(c, 0x400), rnd(c, 0x400)]
    buf = bufs[1]
    em.w32(objs[0] + 0x30, bufs[0] if r.random() < 0.5 else 0)
    em.w32(objs[1] + 0x30, bufs[1] if r.random() < 0.5 else 0)
    em.w32(OV + 4, pystub(c, 2, ret=lambda emu, k: bufs[0] if emu.reg('ecx') == objs[0] else bufs[1], pop=8, this=True,
                          side=lambda emu, k: emu.calllog.append(('v4', nm(emu.reg('ecx')), emu.arg32(0), emu.arg32(1)))))
    p1, p2 = r.getrandbits(32), r.getrandbits(32)

    def s65(emu, k):
        a = [emu.arg32(i) for i in range(6)]
        emu.calllog.append(('c65bc00', emu.reg('ecx') - THIS, a[0] - buf, a[1] - SRC if SRC <= a[1] < SRC + SRCSZ else a[1], a[2], a[3], a[4], a[5],
                            emu.rbytes(a[1], 36 * a[2]).hex()))
    hook_rec(c, 0x65bc00, 6, ret=0, pop=0x18, this=True, side=s65)
    # debug
    flt = [0.0, 1.0, 2.0, -1.0]
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    return [THIS, A, B, p1, p2]


S(0x61b1e0, 'GUESS FUN_61b1e0', 'thiscall', None, ret='al', gen=g61b1e0, note='batch246006')


def g6218c0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x10000 else -1)
    PARSER = rnd(c, 0x300)
    names[PARSER] = 'P'
    E1 = rnd(c, 0x60)
    E2 = rnd(c, 0x60)
    names[E1] = 'E1'
    names[E2] = 'E2'
    EVT1 = rnd(c, 0x80)
    EVT2 = rnd(c, 0x80)
    em.w32(E1, EVT1)
    em.w32(E2, EVT2)
    em.w32(E1 + 0x44, r.choice([0, 1, 2, 3]))
    em.w32(E2 + 0x44, r.choice([0, 1, 2]))
    em.w32(PARSER + 0x8c, E1 if r.random() < 0.7 else E2 if r.random() < 0.5 else 0x77)
    em.w32(PARSER + 0xe0, E2)
    em.w32(PARSER + 0x118, r.getrandbits(32))
    em.w32(PARSER + 0x270, r.choice([0, 1]))
    # buffers
    D1 = rnd(c, 0x200)
    D2 = rnd(c, 0x200)
    em.w32(PARSER + 0x1b4, D1 + r.choice([0, 4, 8]))
    em.w32(PARSER + 0x1b0, em.r32(PARSER + 0x1b4) if r.random() < 0.6 else D1 + 0x100)
    em.w32(PARSER + 0x238, D2 + r.choice([0, 4]))
    em.w32(PARSER + 0x234, em.r32(PARSER + 0x238) if r.random() < 0.4 else D2 + 0x100)
    em.w32(PARSER + 0x23c, D2)
    # tokenizer scripts
    toks_pool = [-4, -3, -3, -1, 0, 6, 6, 7, 7, 9, 10, 10, 28, 28, 28, 5, 3, 40, -2, 1]

    def script():
        n = r.choice([0, 1, 2, 3, 4, 6])
        return [r.choice(toks_pool) for _ in range(n)]
    scripts = {E1: script(), E2: script()}
    special = r.random() < 0.3
    if special:
        scripts[E1] = [28] + scripts[E1]
        scripts[E2] = [28] + scripts[E2]
        em.w32(PARSER + 0x270, 1)
        if r.random() < 0.5:
            scripts[E1] = [28, 7, 6, -4]
            scripts[E2] = [r.choice([6, 7, -3]), -4]
    if r.random() < 0.25:
        scripts[E1] = [10, 10] + scripts[E1]
    failmode = (not special) and r.random() < 0.25
    if failmode:
        scripts[E1] = [r.choice([-3, 7, 10])] + scripts[E1]
        em.w32(PARSER + 0x1b0, em.r32(PARSER + 0x1b4))
    pos = {E1: 0, E2: 0}

    def mk_tok(E):
        def tok(emu, k):
            a = [emu.arg32(i) for i in range(4)]
            i = pos[E]
            pos[E] += 1
            t = scripts[E][i] if i < len(scripts[E]) else -4
            emu.w32(a[3], a[1] + r.choice([1, 2, 4]))
            emu.calllog.append(('tok', nm(a[0]), a[1], a[2], i, t))
            return t & 0xffffffff
        return tok
    em.w32(E1 + 0x14, pystub(c, 4, ret=mk_tok(E1), pop=0, stackmark=(3,)))
    em.w32(E2 + 0x14, pystub(c, 4, ret=mk_tok(E2), pop=0, stackmark=(3,)))
    for E in (E1, E2):
        em.w32(E + 0x2c, pystub(c, 2, ret=lambda emu, k: r.choice([-1, 0, 0x41, 0x2603, 7, 0x10000]) & 0xffffffff, pop=0,
                                side=lambda emu, k, E=E: emu.calllog.append(('e2c', nm(emu.arg32(0)), emu.arg32(1)))))
    # callee hooks
    buf1, buf2 = PARSER + 0x1a8, PARSER + 0x22c

    def s620180(emu, k):
        a = [emu.arg32(i) for i in range(4)]
        emu.calllog.append(('c620180', a[0] - PARSER, nm(a[1]), a[2], a[3]))
        if a[0] == buf2:
            emu.w32(buf2 + 0x10, D2 if special else r.choice([0, D2, D2 + 8, D2]))
            emu.w32(buf2 + 0xc, D2 + 0x20)
            emu.w32(buf2 + 8, r.choice([D2 + 0x20, D2 + 0x20, D2 + 0x100]))
    hook_rec(c, 0x620180, 4, ret=lambda emu, k: 1 if special else r.choice([0, 1, 1, 1, 1]), pop=0, side=s620180)

    def s6206e0(emu, k):
        b = emu.arg32(0)
        emu.calllog.append(('c6206e0', b - PARSER))
        emu.w32(b + 8, emu.r32(b + 0xc) + 0x40)
    hook_rec(c, 0x6206e0, 1, ret=lambda emu, k: 1 if special else 0 if failmode else r.choice([1, 1, 0]), pop=0, side=s6206e0)
    ents = []
    for i in range(1 if special else r.choice([0, 1, 2, 3])):
        en = rnd(c, 0x30)
        names[en] = 'en%d' % i
        em.wbytes(en + 0x1c, bytes([0 if special else r.choice([0, 0, 0, 1])]))
        em.w32(en + 0xc, 0 if special else r.choice([0, 0, 0, 5]))
        em.w32(en + 4, 0x6000 + 0x100 * i)
        em.w32(en + 8, r.choice([0x10, 0x20]))
        ents.append(en)
    ecnt = [0]

    def s61fd60(emu, k):
        a = [emu.arg32(i) for i in range(3)]
        i = ecnt[0]
        ecnt[0] += 1
        emu.calllog.append(('c61fd60', a[0] - PARSER, a[1] - D2 if D2 <= a[1] < D2 + 0x200 else a[1], a[2], i))
        emu.w32(PARSER + 0x23c, r.choice([D2, D2 + 4, 0x1234]))
    hook_rec(c, 0x61fd60, 3, ret=lambda emu, k: ents[r.randrange(len(ents))] if ents and (special or r.random() < 0.9) else 0, pop=0, side=s61fd60)
    nst = [0]

    def s626e10(emu, k):
        n = r.choice([-1, 0, 1, 2, 3, 4])
        nst[0] = n
        emu.calllog.append(('c626e10', emu.arg32(0), n))
        if n > 0:
            emu.wbytes(emu.arg32(1), bytes([r.randrange(256) for _ in range(n)]))
    hook_rec(c, 0x626e10, 2, ret=lambda emu, k: nst[0] & 0xffffffff, pop=0, stackmark=(1,), side=s626e10)
    return [PARSER, E1, 0x4000, 0x4040]


S(0x6218c0, 'GUESS FUN_6218c0', 'cdecl', None, ret='eax', gen=g6218c0, note='batch246006')


def g62c270(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x60)
    mb = r.choice([1, 1, 2])
    rawhi = r.random() < 0.2
    em.w32(ENC + 0x44, mb)
    # text builder
    sp = lambda: ''.join(r.choice(' \t\r\n') for _ in range(r.choice([1, 1, 2, 3])))
    namech = 'abcxyzAZ09_.-:'
    q = r.choice('"\'')
    kind = r.random()
    name = ''.join(r.choice(namech) for _ in range(r.choice([1, 3, 7])))
    val = ''.join(r.choice('abcXYZ019._-zazAZ09') for _ in range(r.choice([0, 1, 4])))
    s = sp() + name + (sp() if r.random() < 0.4 else '') + '=' + (sp() if r.random() < 0.4 else '') + q + val + q + r.choice(['', ' ?>', '  x'])
    if kind < 0.08:
        s = ''
    elif kind < 0.16:
        s = s.lstrip(' \t\r\n')                 # no leading space
    elif kind < 0.24:
        s = sp()                                # only space
    elif kind < 0.32:
        s = sp() + '=' + q + val + q            # empty name
    elif kind < 0.40:
        s = sp() + name                         # no equals
    elif kind < 0.48:
        s = sp() + name + sp() + 'x=' + q + val + q   # space then not '='
    elif kind < 0.56:
        s = sp() + name + '=' + sp() + 'x'      # no quote
    elif kind < 0.64:
        s = sp() + name + '=' + q + val + r.choice(['*', '@', ' ', '/', '\x7f', '`', '{', '[', ':', '0', '9', '+'])
    elif kind < 0.70:
        s = sp() + name + '=' + q + val                   # unterminated value
    elif kind < 0.76:
        s = sp() + name + '=' + q + val + ('"' if q == "'" else "'")   # other quote kind
    elif kind < 0.82:
        s = sp() + name + r.choice(['\x80', '\xff']) + '=' + q + val + q   # non ascii
    elif kind < 0.86:
        s = sp() + name + '=' + q + val + r.choice(['\x80', '\xff']) + q
    if kind > 0.9:
        # boundary characters inside the value / name
        ch = r.choice(['`', '{', '@', '[', ':', '/', '9', '0', 'a', 'z', 'A', 'Z', '.', '-', '_', '+', ',', '\x01'])
        s = sp() + name + '=' + q + val + ch + q
    data = s.encode('latin-1')
    if mb == 2:
        data = b''.join(bytes([b, 0]) if r.random() > 0.05 or b < 0x80 else bytes([b, 1]) for b in data)
    TXT = rnd(c, len(data) + 16)
    em.wbytes(TXT, data)
    end = TXT + len(data)
    # converter stub (utf8 style: one ASCII char into the one byte buffer)

    def conv(emu, k):
        enc, fromp, fromlim, top, tolim = [emu.arg32(i) for i in range(5)]
        p = emu.r32(fromp)
        if p + mb <= fromlim:
            b = emu.rbytes(p, mb)
            ok = (mb == 1 and (b[0] < 0x80 or rawhi)) or (mb == 2 and b[1] == 0 and (b[0] < 0x80 or rawhi))
            if ok and emu.r32(top) < tolim:
                t = emu.r32(top)
                emu.wbytes(t, bytes([b[0]]))
                emu.w32(top, t + 1)
                emu.w32(fromp, p + mb)
        emu.calllog.append(('conv', p - TXT, fromlim - TXT, emu.rbytes(p, mb).hex() if p + mb <= fromlim else ''))
    em.w32(ENC + 0x3c, pystub(c, 5, ret=0, pop=0, stackmark=(1, 3, 4), side=conv))
    outs = [rnd(c, 4) for _ in range(4)]
    for o in outs:
        em.w32(o, 0xaaaaaaaa)
    # start pointer: on text start, or equal to end (empty), or at an offset
    return [ENC, TXT, end, outs[0], outs[1], outs[2], outs[3]]


S(0x62c270, 'GUESS FUN_62c270', 'cdecl', None, ret='eax', gen=g62c270, note='batch246006')


def g62a8e0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x180)
    # byte type table at ENC + 0x4c (xmltok BT_* numbering)
    tbl = [1] * 256
    for b in range(0, 9):
        tbl[b] = 0
    tbl[9] = 21
    tbl[10] = 10
    tbl[13] = 9
    tbl[32] = 21
    for b in range(0x21, 0x7f):
        tbl[b] = 28
    for b in range(0x41, 0x5b):
        tbl[b] = 22
    for b in range(0x61, 0x7b):
        tbl[b] = 22
    for b in b'abcdefABCDEF':
        tbl[b] = 24
    for b in range(0x30, 0x3a):
        tbl[b] = 25
    tbl[ord(':')] = 23
    tbl[ord('-')] = 27
    tbl[ord('.')] = 26
    tbl[ord('"')] = 12
    tbl[ord("'")] = 13
    tbl[ord('=')] = 14
    tbl[ord('>')] = 11
    tbl[ord('/')] = 17
    tbl[ord('<')] = 2
    tbl[ord('&')] = 3
    tbl[ord(']')] = 4
    tbl[ord('?')] = 15
    tbl[ord('!')] = 16
    tbl[ord(';')] = 18
    tbl[ord('#')] = 19
    tbl[ord('[')] = 20
    for b in range(0x80, 0xc0):
        tbl[b] = 8
    for b in range(0xc0, 0xe0):
        tbl[b] = 5
    for b in range(0xe0, 0xf0):
        tbl[b] = 6
    for b in range(0xf0, 0xf8):
        tbl[b] = 7
    for b in range(0xf8, 0x100):
        tbl[b] = 0
    if r.random() < 0.25:
        for _ in range(r.choice([1, 3, 8])):
            tbl[r.randrange(0x20, 0x7f)] = r.choice([0, 1, 2, 3, 4, 9, 10, 11, 12, 13, 14, 17, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30])
    em.wbytes(ENC + 0x4c, bytes(tbl))
    # text
    names = ['a', 'ab', 'x1', 'p:q', 'A_', 'n-m', 'd.e', ':z', 'a:b:c', 'é'.encode('utf-8').decode('latin-1'), '\xc3\xa9x', '\xe2\x82\xac', '\xf0\x9f\x98\x80']
    vals = ['\xc3\xa9&', '\xc3\xa9&#1;', '\xc3\xa9&x', 'v', '', 'a b', 'x&amp;y', '&#65;', '&', 'a<b', ']', ']]', '\xc3\xa9', '\xe2\x82', '\xf0\x9f', '\x80', "it's", 'q"q', '\xff', '\x01']

    def sp():
        return ''.join(r.choice(' \t\r\n') for _ in range(r.choice([1, 1, 2])))
    s = ''
    for _k in range(r.choice([1, 1, 2, 3])):
        qq = r.choice('"\'')
        s += (sp() if (_k > 0 or r.random() < 0.1) else '') + r.choice(names) + (sp() if r.random() < 0.3 else '') + '=' + (sp() if r.random() < 0.3 else '') + qq + r.choice(vals) + qq
    s += r.choice(['', ' ', '>', '/>', '>', '/>', ' >', ' />', '\n>', '/x', ' /', '/', ' a', '=', '\x80', ' a="b">', ' a="b"/>', '\n\ta=\'\'>'])
    if r.random() < 0.25:
        seqs = ['\xc3\xa9', '\xe2\x82\xac', '\xf0\x9f\x98\x80']
        sq = r.choice(seqs)
        pre = r.choice(['', 'a:', 'a="v" ', 'a="', "a='", 'a="v"', 'a="v" ', 'a=" ', 'a="v"  ', 'a:b ', 'a = "'])
        suf = r.choice(['', '', '&', '&x;', '=', '="v"', '"', '" ', '"/>'])
        cut = r.random() < 0.3
        s = pre + sq[:len(sq) - 1 if cut else len(sq)] + suf
        if r.random() < 0.4:
            s = pre + sq
        elif r.random() < 0.3:
            s = pre
    if r.random() < 0.1:
        s = r.choice(['a', 'ab', 'p', '\xc3\xa9']) + ':' + r.choice(['', '', '\xc3\xa9', '\xe2\x82\xac', '\xf0\x9f\x98\x80', '\xe2\x82', 'b', 'b='])
    if r.random() < 0.2:
        k = r.randrange(len(s) + 1)
        s = s[:k] + r.choice([chr(i) for i in range(1, 256) if i not in (0,)]) + s[k + 1:]
    if c.case % 3 == 0:
        edges = []
        for sq in ('\xc3\xa9', '\xe2\x82\xac', '\xf0\x9f\x98\x80'):
            for pre in ('', 'a:', 'a="', "a='", 'a="v" ', 'a = "', 'a:b="', 'a="v"'):
                edges.append(pre + sq)
                edges.append(pre + sq[:-1])
                edges.append(pre + sq + ('"' if pre.endswith(('"', "'")) else '='))
        edges += ['a="&"', 'a="&x"', 'a="\xc3\xa9&"', 'a="x"&', 'a="&&"', 'a=\'&\'', 'a="&#1;&"']
        s = edges[(c.case // 3) % len(edges)]
    data = s.encode('latin-1')
    if r.random() < 0.15 and data:
        data = data[:r.randrange(len(data) + 1)]
    TXT = rnd(c, len(data) + 16)
    em.wbytes(TXT, data)
    end = TXT + len(data)
    # predicates

    fixedv = r.random() < 0.7

    def pred(slot, valid_rate):
        vfix = 1 if r.random() < valid_rate else 0
        if c.case % 3 == 0:
            vfix = 1 if slot < 0x164 else 0

        def f(emu, k):
            p = emu.arg32(1)
            emu.calllog.append(('pred', slot, p - TXT))
            if fixedv or c.case % 3 == 0:
                return vfix
            return 1 if r.random() < valid_rate else 0
        em.w32(ENC + slot, pystub(c, 2, ret=f, pop=0))
    for sl in (0x14c, 0x150, 0x154, 0x158, 0x15c, 0x160):
        pred(sl, 0.75)
    for sl in (0x164, 0x168, 0x16c):
        pred(sl, 0.3)

    def s62c060(emu, k):
        a = [emu.arg32(i) for i in range(4)]
        n = r.choice([-2, -1, 0, 1, 1, 1, 3, 1, 1, 3])
        if c.case % 3 == 0:
            n = r.choice([0, 0, 0, 1]) if (c.case % 6 == 3 or r.random() < 0.5) else 0
        newp = min(a[1] + r.choice([1, 2, 3]), a[2])
        emu.calllog.append(('c62c060', a[1] - TXT, a[2] - TXT, n))
        if n != 0 or (c.case % 3 != 0 and r.random() < 0.5) or (c.case % 6 == 3 and n == 0):
            emu.w32(a[3], newp)
        s62c060.n = n
    hook_rec(c, 0x62c060, 4, ret=lambda emu, k: s62c060.n & 0xffffffff, pop=0, stackmark=(3,), side=s62c060)
    nt = rnd(c, 4)
    em.w32(nt, 0xaaaaaaaa)
    return [ENC, TXT, end, nt]


S(0x62a8e0, 'GUESS FUN_62a8e0', 'cdecl', None, ret='eax', gen=g62a8e0, note='batch246006')


def g556030(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)

    def FV():
        q = r.random()
        if q < 0.9:
            return r.choice([0.0, 1.0, 2.0, -1.0, 3.5, 0.5, 10.0, -4.0, 90.0, 180.0, 45.0, 0.25])
        return r.choice([float('nan'), float('inf'), -0.0, 1e30])
    SRC = rnd(c, 0x10)
    P1, P2 = rnd(c, 0x10), rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    em.w32(SRC + 8, P2)
    ents = [rnd(c, 0x10) for _ in range(6)]
    good = r.random() < 0.6
    for e in ents:
        em.wbytes(e, pk(FV()))
        em.wbytes(e + 4, bytes([r.choice([0, 2]) if good or r.random() < 0.8 else r.choice([1, 3, 5])]))
    outs = [rnd(c, 0x10) for _ in range(3)]
    for o in outs:
        em.wbytes(o + 4, bytes([r.choice([0, 2, 2, 1, 5, 0x80])]))

    def s3d0(emu, k):
        i = emu.arg32(0)
        isout = emu.reg('ecx') == P2
        emu.calllog.append(('e3d0', 1 if isout else 0, i))
        return outs[i] if isout else ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    return [SRC]


S(0x556030, 'GUESS FUN_556030', 'stdcall', None, ret=None, gen=g556030, note='batch246006')


def g5563d0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)
    FV = lambda: r.choice([0.0, 1.0, 2.0, -1.0, 3.0, 0.5, 10.0])
    THIS = rnd(c, 0x40)
    names[THIS] = 'T'
    SRC = rnd(c, 0x10)
    P1 = rnd(c, 0x10)
    em.w32(SRC + 4, P1)
    ents = [rnd(c, 0x10) for _ in range(6)]
    OBJ = rnd(c, 0x10)
    OVT = rnd(c, 0x80)
    em.w32(OBJ, OVT)
    names[OBJ] = 'O'
    em.w32(OVT + 0x34, pystub(c, 0, ret=lambda emu, k: r.choice([0, 7, 0x12345]), pop=0, this=True,
                              side=lambda emu, k: emu.calllog.append(('o34', nm(emu.reg('ecx'))))))
    k0 = r.choice([3, 4, 4, 3, 0, 5])
    em.wbytes(ents[0] + 4, bytes([k0]))
    em.w32(ents[0], OBJ if k0 == 4 else r.getrandbits(32))
    KEY = r.choice([0, 1, 5])
    ID = r.choice([5, 9, 0x77])
    em.w32(ents[1], r.getrandbits(32))
    em.w32(ents[2], r.getrandbits(32))
    em.w32(ents[3], ID)
    rv = r.choice([0.0, 0.5, 1.0, 2.0, 5.0, 100.0, 1e-3, float('nan'), float('inf')]) if r.random() < 0.9 else FV()
    em.wbytes(ents[4], struct.pack('<f', rv))
    em.w32(ents[5], KEY)
    for i in (1, 2, 3, 5):
        em.wbytes(ents[i] + 4, bytes([r.choice([0, 1, 1, 1, 5])]))
    em.wbytes(ents[4] + 4, bytes([r.choice([0, 2, 2, 2, 1, 5])]))

    def s3d0(emu, k):
        i = emu.arg32(0)
        emu.calllog.append(('e3d0', emu.reg('ecx') - P1, i))
        return ents[i]
    hook_rec(c, 0x5003d0, 1, ret=s3d0, pop=4, this='mark')
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True,
                              side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 3, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1), emu.arg32(2)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))
    G = rnd(c, 0xb00 + 0x100)
    em.w32(0x70039c, G)
    H = rnd(c, 0xb10)
    HVT = rnd(c, 0x200)
    em.w32(H, HVT)
    ub(G + 0x9b, H)
    names[H] = 'H'
    em.w32(HVT + 0x114, pystub(c, 4, ret=lambda emu, k: r.choice([0, 1, 0x1234, 0xffff, 0x12345678]), pop=16, this=True,
                               side=lambda emu, k: emu.calllog.append(('h114', [emu.arg32(i) for i in range(4)]))))
    N = rnd(c, 0x20)
    NVT = rnd(c, 0x100)
    em.w32(N, NVT)
    names[N] = 'N'

    def s58(emu, k):
        emu.calllog.append(('h58', emu.arg32(0)))
        return N
    em.w32(HVT + 0x58, pystub(c, 1, ret=s58, pop=4, this=True))
    em.w32(NVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,),
                              side=lambda emu, k: (emu.wbytes(emu.arg32(0), pk(FV(), FV(), FV())), emu.calllog.append(('n84', emu.rbytes(emu.arg32(0), 12).hex())))))
    # this[0x10]
    PH = rnd(c, 0x20)
    PHV = rnd(c, 0x200)
    em.w32(PH, PHV)
    names[PH] = 'PH'
    L = rnd(c, 0x20)
    LV2 = rnd(c, 0x200)
    em.w32(L, LV2)
    names[L] = 'L'
    em.w32(PHV + 0x100, pystub(c, 1, ret=lambda emu, k: 0 if r.random() < 0.12 else L, pop=4, this=True,
                               side=lambda emu, k: emu.calllog.append(('ph100', nm(emu.reg('ecx')), emu.arg32(0)))))
    em.w32(THIS + 0x10, PH if r.random() < 0.5 else 0)
    S = rnd(c, 0x20)
    SVT = rnd(c, 0x400)
    em.w32(S, SVT)
    em.w32(H + 0xadc, S)
    names[S] = 'S'
    em.w32(SVT + 0x25c, pystub(c, 2, ret=lambda emu, k: r.choice([0, PH, PH, PH]), pop=8, this=True,
                               side=lambda emu, k: emu.calllog.append(('s25c', nm(emu.reg('ecx')), emu.arg32(0), emu.arg32(1)))))
    # items
    n = r.choice([0, 1, 2, 3, 5])
    IVT = rnd(c, 0x200)
    items = []
    for i in range(n):
        it = rnd(c, 0x80)
        names[it] = 'i%d' % i
        em.w32(it, IVT)
        ip = rnd(c, 0x10)
        em.w32(ip + 4, KEY if r.random() < 0.7 else KEY + 1)
        em.w32(it + 0x54, ip)
        items.append(it)
    vec = lambda: pk(FV(), FV(), FV())
    em.w32(IVT + 0x84, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,),
                              side=lambda emu, k: (emu.wbytes(emu.arg32(0), vec()), emu.calllog.append(('i84', nm(emu.reg('ecx')), emu.rbytes(emu.arg32(0), 12).hex())))))
    em.w32(IVT + 0x128, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(1,),
                               side=lambda emu, k: emu.calllog.append(('i128', nm(emu.reg('ecx')), emu.arg32(0), emu.rbytes(emu.arg32(1), 8).hex(), emu.arg32(2)))))
    pos = [0]

    def sl84(emu, k):
        p, rb, cur, m1 = emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3)
        emu.calllog.append(('l84', nm(emu.reg('ecx')), emu.rbytes(p, 12).hex(), rb, emu.r32(cur), m1))
        i = pos[0]
        pos[0] += 1
        emu.w32(cur, i)
        return items[i] if i < len(items) else 0
    em.w32(LV2 + 0x84, pystub(c, 4, ret=sl84, pop=16, this=True, stackmark=(0, 2)))
    return [THIS, SRC]


S(0x5563d0, 'GUESS FUN_5563d0', 'thiscall', None, ret=None, gen=g5563d0, note='batch246006')


def g627bb0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x180)
    tbl = [1] * 256
    for b in range(0, 9):
        tbl[b] = 0
    tbl[9] = 21
    tbl[10] = 10
    tbl[13] = 9
    tbl[32] = 21
    for b in range(0x21, 0x7f):
        tbl[b] = 28
    for b in list(range(0x41, 0x5b)) + list(range(0x61, 0x7b)):
        tbl[b] = 22
    for b in b'abcdefABCDEF':
        tbl[b] = 24
    for b in range(0x30, 0x3a):
        tbl[b] = 25
    tbl[ord(':')] = 23
    tbl[ord('-')] = 27
    tbl[ord('.')] = 26
    tbl[ord('"')] = 12
    tbl[ord("'")] = 13
    tbl[ord('=')] = 14
    tbl[ord('>')] = 11
    tbl[ord('/')] = 17
    tbl[ord('<')] = 2
    tbl[ord('&')] = 3
    tbl[ord(']')] = 4
    tbl[ord('?')] = 15
    tbl[ord('!')] = 16
    tbl[ord('[')] = 20
    for b in range(0x80, 0xc0):
        tbl[b] = 29
    for b in range(0xc0, 0xe0):
        tbl[b] = r.choice([29, 5])
    for b in range(0xe0, 0xf0):
        tbl[b] = r.choice([29, 6])
    for b in range(0xf0, 0x100):
        tbl[b] = r.choice([29, 7])
    if c.case % 4 == 0:
        tbl[0xc3] = 5
        tbl[0xe2] = 6
        tbl[0xf0] = 7
    em.wbytes(ENC + 0x4c, bytes(tbl))

    def u16(s):
        return b''.join(bytes([ord(ch) >> 8, ord(ch) & 0xff]) for ch in s)
    names = ['a', 'ab', 'x1', 'p:q', 'A_', 'n-m', 'd.e', ':z', 'a:b:c', '\u00e9', '\u00e9x', 'a\u00e9', '\u0100', 'a\u0100b', '\u20ac', '\u4e2d', 'a\u0300', '\u00c3', 'a\u00c3', '\u00f0']
    tails = ['>', '/>', ' >', ' />', ' a="v">', '\n\ta=\'b\' />', ' ', '', '/', '/x', ' /', '>x', ' \u00e9="x">', ' a:b="v">', ' 1>']
    kind = r.random()
    if kind < 0.1:
        s = '?pi?>'
    elif kind < 0.2:
        s = '!--c-->'
    elif kind < 0.3:
        s = '![CDATA[x]]>'
    elif kind < 0.36:
        s = '!x'
    elif kind < 0.42:
        s = '/b>'
    elif kind < 0.46:
        s = ''
    elif kind < 0.5:
        s = r.choice(['!', '?', '/', '!-', '![', '!x'])
    else:
        def rch():
            while True:
                x = r.choice([r.randrange(0x80, 0x400), r.randrange(0x80, 0x3000), r.randrange(0x3000, 0xd800), r.randrange(0xe000, 0x10000)])
                if not (0xd800 <= x < 0xe000):
                    return chr(x)
        if r.random() < 0.4:
            nm_ = r.choice(['', 'a', 'a:', 'ab:']) + rch() + r.choice(['', 'b', rch()])
            tl = r.choice(tails + [' ' + rch() + '="x">', ' a' + rch() + '="x">', '  ' + rch(), ' ' + rch()])
            s = nm_ + tl
        else:
            s = r.choice(names) + r.choice(tails)
    data = u16(s)
    if r.random() < 0.15 and data:
        data = data[:r.randrange(len(data) + 1)]
    if r.random() < 0.12:
        data += r.choice([b'\xd8\x3d', b'\xd8\x3d\xde', b'\xd8\x3d\xde\x00', b'\xdc\x00', b'\xff\xfe', b'\xff\xff', b'\x00\xc3', b'\x00\xe2\x00', b'\x00'])
    if c.case % 4 == 0:
        edges = []
        for pre in ('', 'a', 'a:', 'a ', 'a  ', 'ab ', 'a/', 'a / '):
            for post in (b'', b'\x01\x3e', b'\x00\xb7', b'\x03\x00', b'\x03\x87', b'\x20\x3f', b'\x00\xd7', b'\x00\xc0', b'\x00\xc3\x00', b'\x00\xc3\x00\x00', b'\x00\xe2\x00', b'\x00\xe2\x00\x00', b'\x00\xf0\x00', b'\x00\xf0\x00\x00', b'\x00\xc3', b'\x00\xe2\x82\xac', b'\xd8\x3d\xde\x00', b'\xd8\x3d\xde', b'\xd8\x3d', b'\xd8', b'\xdc\x00', b'\x01\x00', b'\x00\xf0', b'\x00\xe9', b'\x20\xac', b'\x4e\x2d', b'\xff\xfe', b'\x00'):
                edges.append(u16(pre) + post)
        for i_ in range(96):
            cp = (i_ * 1103515245 + 12345) % 0xd000 + 0x80
            edges.append(u16(('', 'a', 'a:', 'a ')[i_ % 4] + chr(cp)))
        edges += [u16('!['), u16('!-'), u16('!x'), u16('!'), u16('/'), u16('a/'), u16('a/>'), u16('a/x'), b'\x00', b'\x00a\x00', u16('a:\u00e9'), u16('a:\u0100'), u16('a:b:'), u16('a:b:c')]
        data = edges[(c.case // 4) % len(edges)]
    TXT = rnd(c, len(data) + 16)
    em.wbytes(TXT, data)
    end = TXT + len(data)

    def mk(addr, nm_):
        def h(emu, k):
            a = [emu.arg32(i) for i in range(4)]
            emu.calllog.append((nm_, a[1] - TXT, a[2] - TXT))
            if r.random() < 0.7:
                emu.w32(a[3], a[1] + r.choice([0, 2, 4]))
        hook_rec(c, addr, 4, ret=lambda emu, k: r.choice([-4, -2, -1, 0, 1, 2, 3, 4, 5, 6]) & 0xffffffff, pop=0, side=h)
    for a_, n_ in ((0x626f60, 'scanAtts'), (0x627420, 'cdata'), (0x627520, 'comment'), (0x6277b0, 'endtag'), (0x6281a0, 'pi')):
        mk(a_, n_)
    nt = rnd(c, 4)
    em.w32(nt, 0xaaaaaaaa)
    return [ENC, TXT, end, nt]


S(0x627bb0, 'GUESS FUN_627bb0', 'cdecl', None, ret='eax', gen=g627bb0, note='batch246006')


def g629c10(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x180)
    tbl = [1] * 256
    for b in range(0, 9):
        tbl[b] = 0
    tbl[9] = 21
    tbl[10] = 10
    tbl[13] = 9
    tbl[32] = 21
    for b in range(0x21, 0x7f):
        tbl[b] = 28
    for b in list(range(0x41, 0x5b)) + list(range(0x61, 0x7b)):
        tbl[b] = 22
    for b in b'abcdefABCDEF':
        tbl[b] = 24
    for b in range(0x30, 0x3a):
        tbl[b] = 25
    tbl[ord(':')] = 23
    tbl[ord('-')] = 27
    tbl[ord('.')] = 26
    tbl[ord('"')] = 12
    tbl[ord("'")] = 13
    tbl[ord('=')] = 14
    tbl[ord('>')] = 11
    tbl[ord('/')] = 17
    tbl[ord('<')] = 2
    tbl[ord('&')] = 3
    tbl[ord(']')] = 4
    tbl[ord('?')] = 15
    tbl[ord('!')] = 16
    tbl[ord('[')] = 20
    for b in range(0x80, 0xc0):
        tbl[b] = 29
    for b in range(0xc0, 0xe0):
        tbl[b] = r.choice([29, 5])
    for b in range(0xe0, 0xf0):
        tbl[b] = r.choice([29, 6])
    for b in range(0xf0, 0x100):
        tbl[b] = r.choice([29, 7])
    if c.case % 4 == 0:
        tbl[0xc3] = 5
        tbl[0xe2] = 6
        tbl[0xf0] = 7
    em.wbytes(ENC + 0x4c, bytes(tbl))

    def u16(s):
        return b''.join(bytes([ord(ch) >> 8, ord(ch) & 0xff]) for ch in s)
    names = ['a', 'ab', 'x1', 'p:q', 'A_', 'n-m', 'd.e', ':z', 'a:b:c', '\u00e9', '\u00e9x', 'a\u00e9', '\u0100', 'a\u0100b', '\u20ac', '\u4e2d', 'a\u0300', '\u00c3', 'a\u00c3', '\u00f0']
    tails = ['>', '/>', ' >', ' />', ' a="v">', '\n\ta=\'b\' />', ' ', '', '/', '/x', ' /', '>x', ' \u00e9="x">', ' a:b="v">', ' 1>']
    kind = r.random()
    if kind < 0.1:
        s = '?pi?>'
    elif kind < 0.2:
        s = '!--c-->'
    elif kind < 0.3:
        s = '![CDATA[x]]>'
    elif kind < 0.36:
        s = '!x'
    elif kind < 0.42:
        s = '/b>'
    elif kind < 0.46:
        s = ''
    elif kind < 0.5:
        s = r.choice(['!', '?', '/', '!-', '![', '!x'])
    else:
        def rch():
            while True:
                x = r.choice([r.randrange(0x80, 0x400), r.randrange(0x80, 0x3000), r.randrange(0x3000, 0xd800), r.randrange(0xe000, 0x10000)])
                if not (0xd800 <= x < 0xe000):
                    return chr(x)
        if r.random() < 0.4:
            nm_ = r.choice(['', 'a', 'a:', 'ab:']) + rch() + r.choice(['', 'b', rch()])
            tl = r.choice(tails + [' ' + rch() + '="x">', ' a' + rch() + '="x">', '  ' + rch(), ' ' + rch()])
            s = nm_ + tl
        else:
            s = r.choice(names) + r.choice(tails)
    data = u16(s)
    if r.random() < 0.15 and data:
        data = data[:r.randrange(len(data) + 1)]
    if r.random() < 0.12:
        data += r.choice([b'\xd8\x3d', b'\xd8\x3d\xde', b'\xd8\x3d\xde\x00', b'\xdc\x00', b'\xff\xfe', b'\xff\xff', b'\x00\xc3', b'\x00\xe2\x00', b'\x00'])
    if c.case % 4 == 0:
        edges = []
        for pre in ('', 'a', 'a:', 'a ', 'a  ', 'ab ', 'a/', 'a / '):
            for post in (b'', b'\x01\x3e', b'\x00\xb7', b'\x03\x00', b'\x03\x87', b'\x20\x3f', b'\x00\xd7', b'\x00\xc0', b'\x00\xc3\x00', b'\x00\xc3\x00\x00', b'\x00\xe2\x00', b'\x00\xe2\x00\x00', b'\x00\xf0\x00', b'\x00\xf0\x00\x00', b'\x00\xc3', b'\x00\xe2\x82\xac', b'\xd8\x3d\xde\x00', b'\xd8\x3d\xde', b'\xd8\x3d', b'\xd8', b'\xdc\x00', b'\x01\x00', b'\x00\xf0', b'\x00\xe9', b'\x20\xac', b'\x4e\x2d', b'\xff\xfe', b'\x00'):
                edges.append(u16(pre) + post)
        for i_ in range(96):
            cp = (i_ * 1103515245 + 12345) % 0xd000 + 0x80
            edges.append(u16(('', 'a', 'a:', 'a ')[i_ % 4] + chr(cp)))
        edges += [u16('!['), u16('!-'), u16('!x'), u16('!'), u16('/'), u16('a/'), u16('a/>'), u16('a/x'), b'\x00', b'\x00a\x00', u16('a:\u00e9'), u16('a:\u0100'), u16('a:b:'), u16('a:b:c')]
        data = edges[(c.case // 4) % len(edges)]
    data = b''.join(data[k:k + 2][::-1] for k in range(0, len(data), 2))   # little endian
    TXT = rnd(c, len(data) + 16)
    em.wbytes(TXT, data)
    end = TXT + len(data)

    def mk(addr, nm_):
        def h(emu, k):
            a = [emu.arg32(i) for i in range(4)]
            emu.calllog.append((nm_, a[1] - TXT, a[2] - TXT))
            if r.random() < 0.7:
                emu.w32(a[3], a[1] + r.choice([0, 2, 4]))
        hook_rec(c, addr, 4, ret=lambda emu, k: r.choice([-4, -2, -1, 0, 1, 2, 3, 4, 5, 6]) & 0xffffffff, pop=0, side=h)
    for a_, n_ in ((0x628fc0, 'scanAtts'), (0x629480, 'cdata'), (0x629580, 'comment'), (0x629810, 'endtag'), (0x62a200, 'pi')):
        mk(a_, n_)
    nt = rnd(c, 4)
    em.w32(nt, 0xaaaaaaaa)
    return [ENC, TXT, end, nt]


S(0x629c10, 'GUESS FUN_629c10', 'cdecl', None, ret='eax', gen=g629c10, note='batch246006')


def g626f60(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x180)
    tbl = [1] * 256
    for b in range(0, 9):
        tbl[b] = 0
    tbl[9] = 21
    tbl[10] = 10
    tbl[13] = 9
    tbl[32] = 21
    for b in range(0x21, 0x7f):
        tbl[b] = 28
    for b in list(range(0x41, 0x5b)) + list(range(0x61, 0x7b)):
        tbl[b] = 22
    for b in b'abcdefABCDEF':
        tbl[b] = 24
    for b in range(0x30, 0x3a):
        tbl[b] = 25
    tbl[ord(':')] = 23
    tbl[ord('-')] = 27
    tbl[ord('.')] = 26
    tbl[ord('"')] = 12
    tbl[ord("'")] = 13
    tbl[ord('=')] = 14
    tbl[ord('>')] = 11
    tbl[ord('/')] = 17
    tbl[ord('<')] = 2
    tbl[ord('&')] = 3
    tbl[ord(']')] = 4
    tbl[ord('?')] = 15
    tbl[ord('!')] = 16
    tbl[ord('[')] = 20
    for b in range(0x80, 0xc0):
        tbl[b] = 29
    for b in range(0xc0, 0xe0):
        tbl[b] = r.choice([29, 5])
    for b in range(0xe0, 0xf0):
        tbl[b] = r.choice([29, 6])
    for b in range(0xf0, 0x100):
        tbl[b] = r.choice([29, 7])
    if c.case % 3 == 0:
        tbl[0xc3] = 5
        tbl[0xe2] = 6
        tbl[0xf0] = 7
    em.wbytes(ENC + 0x4c, bytes(tbl))

    def u16(s):
        return b''.join(bytes([ord(ch) >> 8, ord(ch) & 0xff]) for ch in s)

    def rch():
        while True:
            x = r.choice([r.randrange(0x80, 0x400), r.randrange(0x80, 0x3000), r.randrange(0x3000, 0xd800), r.randrange(0xe000, 0x10000)])
            if not (0xd800 <= x < 0xe000):
                return chr(x)
    names = ['a', 'ab', 'x1', 'p:q', 'A_', 'n-m', 'd.e', ':z', 'a:b:c', 'é', 'éx', 'aé', 'Ā', 'aĀb', '€', '中', 'à', 'a:' + rch(), rch(), 'a' + rch()]
    vals = ['v', '', 'a b', 'x&amp;y', '&#65;', '&', 'a<b', ']', ']]', 'é', '€', 'é&', "it's", 'q"q', 'ÿ', '\x01', rch(), 'a' + rch()]

    def sp():
        return ''.join(r.choice(' \t\r\n') for _ in range(r.choice([1, 1, 2])))
    s = ''
    for _k in range(r.choice([1, 1, 2, 3])):
        qq = r.choice('"\'')
        s += (sp() if (_k > 0 or r.random() < 0.1) else '') + r.choice(names) + (sp() if r.random() < 0.3 else '') + '=' + (sp() if r.random() < 0.3 else '') + qq + r.choice(vals) + qq
    s += r.choice(['', ' ', '>', '/>', '>', '/>', ' >', ' />', '\n>', '/x', ' /', '/', ' a', '=', '\u0080', ' a="b">', ' a="b"/>', '\n\ta=\'\'>', ' ' + rch(), ' a' + rch() + '="x">'])
    if r.random() < 0.15:
        k = r.randrange(len(s) + 1)
        s = s[:k] + r.choice([chr(i) for i in range(1, 256) if i != 0]) + s[k + 1:]
    data = u16(s)
    if r.random() < 0.12 and data:
        data = data[:r.randrange(len(data) + 1)]
    if r.random() < 0.12:
        data += r.choice([b'\xd8\x3d', b'\xd8\x3d\xde', b'\xd8\x3d\xde\x00', b'\xdc\x00', b'\xff\xfe', b'\xff\xff', b'\x00\xc3', b'\x00\xe2\x00', b'\x00'])
    if c.case % 3 == 0:
        edges = []
        posts = (b'', b'\x01\x3e', b'\x00\xb7', b'\x03\x00', b'\x03\x87', b'\x20\x3f', b'\x00\xd7', b'\x00\xc0', b'\x00\xc3\x00', b'\x00\xc3\x00\x00', b'\x00\xe2\x00', b'\x00\xe2\x00\x00', b'\x00\xf0\x00', b'\x00\xf0\x00\x00', b'\x00\xc3', b'\x00\xe2\x82\xac', b'\xd8\x3d\xde\x00', b'\xd8\x3d\xde', b'\xd8\x3d', b'\xd8', b'\xdc\x00', b'\x01\x00', b'\x20\xac', b'\xff\xfe', b'\xff\xfd', b'\xff\xff', b'\x00\xe2\x00\x00&', b'\x00\xe2\x00\x00&\x00', b'\x00\xf0\x00\x00\x00&', b'\x00\xc3\x00&', b'\x00')
        for pre in ('a="v"/', 'a="v" /', 'a="', 'a:', 'a ', 'a="v"', 'a="v" ', 'a', 'a=', "a='", 'a="v"  ', 'a:b ', 'a = "'):
            for post in posts:
                edges.append(u16(pre) + post)
        for i_ in range(96):
            cp = (i_ * 1103515245 + 12345) % 0xd000 + 0x80
            edges.append(u16(('a', 'a:', 'a ', 'a="v" ', 'a="', 'a=')[i_ % 6] + chr(cp)))
        edges += [u16('a="&"'), u16('a="&x"'), u16('a="é&"'), u16('a="x"&'), u16('a="&&"'), u16("a='&'"), u16('a="&#1;&"'), u16('a="Ā&"'), u16('a="/"'), u16('a="v"/>'), u16('a="v">'), u16('a="v" >'), u16('a="v"/x'), u16('a="v"/'), u16('a="v" /')]
        data = edges[(c.case // 3) % len(edges)]
    TXT = rnd(c, len(data) + 16)
    em.wbytes(TXT, data)
    end = TXT + len(data)

    def s628630(emu, k):
        a = [emu.arg32(i) for i in range(4)]
        n = r.choice([-2, -1, 0, 1, 1, 1, 3, 1, 1, 3])
        if c.case % 3 == 0:
            n = r.choice([0, 0, 0, 1])
        newp = min(a[1] + r.choice([2, 4]), a[2])
        emu.calllog.append(('c628630', a[1] - TXT, a[2] - TXT, n))
        if n != 0 or (c.case % 3 != 0 and r.random() < 0.5) or (c.case % 6 == 3 and n == 0):
            emu.w32(a[3], newp)
        s628630.n = n
    hook_rec(c, 0x628630, 4, ret=lambda emu, k: s628630.n & 0xffffffff, pop=0, stackmark=(3,), side=s628630)
    nt = rnd(c, 4)
    em.w32(nt, 0xaaaaaaaa)
    return [ENC, TXT, end, nt]


S(0x626f60, 'GUESS FUN_626f60', 'cdecl', None, ret='eax', gen=g626f60, note='batch246006')


def g49be80(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def FV():
        q = r.random()
        if q < 0.85:
            return r.choice([0.0, 1.0, -1.0, 2.0, -2.0, 0.5, 3.0, 0.25, 4.0, -0.5])
        return r.choice([float('nan'), float('inf'), -0.0, 1e20, 7.5])
    A = rnd(c, 0x30)
    mats = [[1, 0, 0, 0, 1, 0, 0, 0, 1], [0, 1, 0, -1, 0, 0, 0, 0, 1], [2, 0, 0, 0, 2, 0, 0, 0, 2], [1, 0, 0, 0, 0, 1, 0, -1, 0]]
    m9 = r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)]
    em.wbytes(A, pk(*[float(x) for x in m9]))
    B = rnd(c, 0x10)
    em.wbytes(B, pk(*[r.choice([0.0, 0.0, 1.0, -1.0, 2.0, 5.0, -3.0, 0.5]) for _ in range(3)]))
    nitems = r.choice([0, 1, 2, 4])
    items = []
    base_pool = [0.0, 1.0, -1.0, 2.0, 3.0, -2.0, 0.5, 4.0, 6.0, 1.5, 10.0]
    for i in range(nitems):
        it = rnd(c, 0x30)
        names[it] = 'i%d' % i
        q = r.random()
        if q < 0.12:
            v = [r.choice(base_pool) for _ in range(3)]
            vs = v + v + [r.choice(base_pool) for _ in range(3)]            # V0 == V1
        elif q < 0.2:
            v = [r.choice(base_pool) for _ in range(3)]
            vs = [r.choice(base_pool) for _ in range(3)] + v + v           # V1 == V2
        elif q < 0.28:
            v = [r.choice(base_pool) for _ in range(3)]
            vs = v + [r.choice(base_pool) for _ in range(3)] + v           # V2 == V0
        elif q < 0.33:
            vs = [float('nan')] * 9
        else:
            vs = [r.choice(base_pool) if r.random() < 0.9 else FV() for _ in range(9)]
            if r.random() < 0.5:
                for k in (2, 5, 8):
                    vs[k] = abs(vs[k]) + 1.0       # positive z
        em.wbytes(it + 4, pk(*vs))
        items.append(it)
    L = rnd(c, 0x20) if r.random() > 0.1 else 0
    pos = [0]
    if L:
        LVT = rnd(c, 0x100)
        em.w32(L, LVT)
        names[L] = 'L'

        def s4c(emu, k):
            pos[0] = 0
            emu.calllog.append(('l4c', emu.reg('ecx') - L))
        em.w32(LVT + 0x4c, pystub(c, 1, ret=0, pop=4, this=True, stackmark=(0,), side=s4c))

        def s64(emu, k):
            i = pos[0]
            pos[0] += 1
            emu.calllog.append(('l64', i))
            return items[i] if i < len(items) else 0
        em.w32(LVT + 0x64, pystub(c, 1, ret=s64, pop=4, this=True, stackmark=(0,)))
    rr = r.choice([0.0, 1.0, 2.0, 5.0, 10.0, 100.0, -3.0, 0.5, float('nan')])
    kk = r.choice([0.0, 0.1, 0.5, 1.0, 2.0, -1.0, 0.01, float('nan')])
    ss = r.choice([0.0, 0.5, 1.0, 2.0, 4.0, 0.25, -1.0, 0.99, 1.01, float('nan'), float('inf')])
    if r.random() < 0.5 and items:
        # hit oriented: identity transform, zero offset, vertices in front with small coordinates and boundary values
        em.wbytes(A, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(B, pk(0, 0, 0))
        rr = r.choice([2.0, 2.0, 5.0, 10.0])
        kk = r.choice([0.0, 0.1, 0.5, 1.0, 1.0])
        ss = r.choice([1.0, 2.0, 0.5, 4.0, 0.25])
        pool = [(0, 0, 2), (0, 0, 1), (0, 0, 4), (1, 0, 2), (0, 1, 2), (1, 1, 1), (2, 0, 0), (0, 2, 0), (0, 0, 3), (1, 1, 3), (3, 0, 1), (0, 0, 0.5), (-1, 0, 2), (0, -1, 2)]
        for it in items:
            vs = []
            for _ in range(3):
                vs += list(r.choice(pool))
            em.wbytes(it + 4, pk(*[float(x) for x in vs]))
    if r.random() < 0.4 and items:
        # continuous hit oriented mode: random vertices in front of the origin, thresholds near 1
        em.wbytes(A, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(B, pk(0, 0, 0))
        rr = r.choice([10.0, 20.0, 100.0])
        kk = r.choice([0.2, 0.5, 0.7, 0.9, 0.95, 0.97, 0.99, 1.0, 1.1, r.uniform(0.2, 1.2)])
        ss = r.choice([0.25, 0.5, 0.7, 1.0, 1.5, 2.0, 3.0, 4.0, 9.0, 0.1, r.uniform(0.1, 5.0)])
        for it in items:
            vs = []
            for _ in range(3):
                vs += [r.uniform(-3, 3), r.uniform(-3, 3), r.uniform(0.5, 4.0)]
            em.wbytes(it + 4, pk(*vs))
    if items and r.random() < 0.08:
        # duplicated vertices that differ only in the sign of zero (equal as floats)
        it = items[0]
        em.wbytes(it + 4, pk(0.0, 0.0, 1.0, -0.0, -0.0, 1.0, 2.0, 1.0, 3.0))
    from pilot import F as Fl
    return [A, B, Fl(rr), Fl(kk), Fl(ss), L]


S(0x49be80, 'GUESS FUN_49be80', 'fastcall', None, ret='al', gen=g49be80, note='batch246006')


def g62b450(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ENC = rnd(c, 0x180)
    tbl = [1] * 256
    for b in range(0, 9):
        tbl[b] = 0
    tbl[9] = 21
    tbl[10] = 10
    tbl[13] = 9
    tbl[32] = 21
    for b in range(0x21, 0x7f):
        tbl[b] = 28
    for b in list(range(0x41, 0x5b)) + list(range(0x61, 0x7b)):
        tbl[b] = 22
    for b in b'abcdefABCDEF':
        tbl[b] = 24
    for b in range(0x30, 0x3a):
        tbl[b] = 25
    tbl[ord(':')] = 23
    tbl[ord('-')] = 27
    tbl[ord('.')] = 26
    tbl[ord('"')] = 12
    tbl[ord("'")] = 13
    tbl[ord('=')] = 14
    tbl[ord('>')] = 11
    tbl[ord('/')] = 17
    tbl[ord('<')] = 2
    tbl[ord('&')] = 3
    tbl[ord(']')] = 4
    tbl[ord('?')] = 15
    tbl[ord('!')] = 16
    tbl[ord('[')] = 20
    for b in range(0x80, 0xc0):
        tbl[b] = r.choice([8, 29])
    for b in range(0xc0, 0xe0):
        tbl[b] = r.choice([29, 5])
    for b in range(0xe0, 0xf0):
        tbl[b] = r.choice([29, 6])
    for b in range(0xf0, 0x100):
        tbl[b] = r.choice([29, 7])
    if c.case % 3 == 0:
        tbl[0xc3] = 5
        tbl[0xe2] = 6
        tbl[0xf0] = 7
        tbl[0x80] = 8
    em.wbytes(ENC + 0x4c, bytes(tbl))
    fixedv = r.random() < 0.7
    vfix = {}
    for sl in (0x14c, 0x150, 0x154, 0x158, 0x15c, 0x160):
        vfix[sl] = 1 if r.random() < 0.75 else 0
        if c.case % 3 == 0:
            vfix[sl] = 1 if (sl in (0x14c, 0x158, 0x15c)) else (1 if r.random() < 0.5 else 0)

    def pred(slot):
        def f(emu, k):
            emu.calllog.append(('pred', slot, emu.arg32(1) - TXT))
            if fixedv or c.case % 3 == 0:
                return vfix[slot]
            return 1 if r.random() < 0.75 else 0
        em.w32(ENC + slot, pystub(c, 2, ret=f, pop=0))
    names = ['a', 'ab', 'x1', 'p:q', 'A_', 'n-m', 'd.e', ':z', 'a:b:c', '\xc3\xa9', '\xc3\xa9x', 'a\xc3\xa9', '\xe2\x82\xac', 'a\xf0\x9f\x98\x80', '\x80', 'a\x80', '\xff', 'a:\xc3\xa9']
    tails = ['>', '/>', ' >', ' />', ' a="v">', '\n\ta=\'b\' />', ' ', '', '/', '/x', ' /', '>x', ' \xc3\xa9="x">', ' a:b="v">', ' 1>', ' \xe2\x82\xac>', ' \x80>']
    kind = r.random()
    if kind < 0.1:
        s = '?pi?>'
    elif kind < 0.2:
        s = '!--c-->'
    elif kind < 0.3:
        s = '![CDATA[x]]>'
    elif kind < 0.36:
        s = '!x'
    elif kind < 0.42:
        s = '/b>'
    elif kind < 0.46:
        s = ''
    elif kind < 0.5:
        s = r.choice(['!', '?', '/', '!-', '![', '!x'])
    else:
        s = r.choice(names) + r.choice(tails)
    data = s.encode('latin-1')
    if r.random() < 0.15 and data:
        data = data[:r.randrange(len(data) + 1)]
    if r.random() < 0.12:
        data += r.choice([b'\xc3', b'\xe2\x82', b'\xf0\x9f\x98', b'\x80', b'\xff'])
    if c.case % 3 == 0:
        edges = []
        posts = [b'', b'\xc3', b'\xc3\xa9', b'\xe2', b'\xe2\x82', b'\xe2\x82\xac', b'\xf0', b'\xf0\x9f', b'\xf0\x9f\x98', b'\xf0\x9f\x98\x80', b'\x80', b'>', b'/', b'/>', b'[', b'-', b'x', b'\xc3 ', b'\xe2\x82>', b'\xc3\xa9\xe2\x82', b'\xe2\x82\xac\xc3', b'\xf0\x9f\x98\x80\xe2\x82', b'\xc3\xa9\xf0\x9f\x98', b'\xe2\x82\xac\xe2\x82', b'\xf0\x9f\x98\x80\xc3', b'\xc3\xa9\xc3\xa9>']
        for pre in ('a', 'a:', 'a ', 'a/', '', 'ab:', 'a  ', '!', '/', '?'):
            for post in posts:
                edges.append(pre.encode() + post)
        for i_ in range(40):
            edges.append((('a', 'a:', 'a ', '')[i_ % 4]).encode() + bytes([(i_ * 37 + 11) % 256]))
        data = edges[(c.case // 3) % len(edges)]
    TXT = rnd(c, len(data) + 16)
    for sl in (0x14c, 0x150, 0x154, 0x158, 0x15c, 0x160):
        pred(sl)
    em.wbytes(TXT, data)
    end = TXT + len(data)

    def mk(addr, nm_):
        def h(emu, k):
            a = [emu.arg32(i) for i in range(4)]
            emu.calllog.append((nm_, a[1] - TXT, a[2] - TXT))
            if r.random() < 0.7:
                emu.w32(a[3], a[1] + r.choice([0, 1, 2]))
        hook_rec(c, addr, 4, ret=lambda emu, k: r.choice([-4, -2, -1, 0, 1, 2, 3, 4, 5, 6]) & 0xffffffff, pop=0, side=h)
    for a_, n_ in ((0x62a8e0, 'scanAtts'), (0x62ad10, 'cdata'), (0x62add0, 'comment'), (0x62b040, 'endtag'), (0x62bb10, 'pi')):
        mk(a_, n_)
    nt = rnd(c, 4)
    em.w32(nt, 0xaaaaaaaa)
    return [ENC, TXT, end, nt]


S(0x62b450, 'GUESS FUN_62b450', 'cdecl', None, ret='eax', gen=g62b450, note='batch246006')


def g61c790(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x10000 else -1)
    PARSER = rnd(c, 0x300)
    names[PARSER] = 'P'
    E1 = rnd(c, 0x60)
    E2 = rnd(c, 0x60)
    names[E1] = 'E1'
    names[E2] = 'E2'
    em.w32(E1 + 0x44, r.choice([1, 2]))
    em.w32(E2 + 0x44, r.choice([1, 2]))
    em.w32(PARSER + 0x8c, E1 if r.random() < 0.7 else E2 if r.random() < 0.5 else 0x77)
    em.w32(PARSER + 0xe0, E2)
    em.w32(PARSER + 0x118, r.getrandbits(32))
    em.w32(PARSER + 0x1c0, r.choice([0, 1]))
    special = r.random() < 0.3
    # buffers: buf (argument) and buf2 = parser + 0x244
    BUF = rnd(c, 0x20)
    names[BUF] = 'B'
    BD = rnd(c, 0x200)
    em.w32(BUF + 0x10, BD)
    em.w32(BUF + 0xc, BD + r.choice([0, 0, 4, 8]))
    em.w32(BUF + 8, em.r32(BUF + 0xc) if r.random() < 0.4 else BD + 0x100)
    if r.random() < 0.4 and em.r32(BUF + 0xc) > BD:
        em.wbytes(em.r32(BUF + 0xc) - 1, bytes([r.choice([0x20, 0x41])]))
    D2 = rnd(c, 0x200)
    em.w32(PARSER + 0x250, D2 + r.choice([0, 4]))
    em.w32(PARSER + 0x24c, em.r32(PARSER + 0x250) if r.random() < 0.4 else D2 + 0x100)
    em.w32(PARSER + 0x254, D2)
    toks_pool = [-4, -3, -3, -1, 0, 6, 6, 7, 9, 9, 10, 10, 39, 5, 3, 1, 12, -2]

    def script():
        n = r.choice([0, 1, 2, 3, 4, 6])
        return [r.choice(toks_pool) for _ in range(n)]
    scripts = {E1: script(), E2: script()}
    if special:
        scripts[E1] = [9] + scripts[E1]
        scripts[E2] = [9, 7] + scripts[E2][:2] + [-4] if r.random() < 0.5 else [9] + scripts[E2]
    sqz = c.case % 5 == 0
    if sqz:
        scripts[E1] = r.choice([[10, 10, 7], [10, -3, 10], [10, 10, 10, -4], [7, 10, 10]])
        em.w32(BUF + 0xc, BD + r.choice([0, 0, 4]))
        em.w32(BUF + 8, BD + 0x100)
        em.wbytes(BD + 3, bytes([0x20, 0x20, 0x20, 0x20]))
    pos = {E1: 0, E2: 0}

    def mk_tok(E):
        def tok(emu, k):
            a = [emu.arg32(i) for i in range(4)]
            i = pos[E]
            pos[E] += 1
            t = scripts[E][i] if i < len(scripts[E]) else -4
            emu.w32(a[3], a[1] + r.choice([1, 2, 4]))
            emu.calllog.append(('tok', nm(a[0]), a[1], a[2], i, t))
            return t & 0xffffffff
        return tok
    em.w32(E1 + 0x10, pystub(c, 4, ret=mk_tok(E1), pop=0, stackmark=(3,)))
    em.w32(E2 + 0x10, pystub(c, 4, ret=mk_tok(E2), pop=0, stackmark=(3,)))
    for E in (E1, E2):
        em.w32(E + 0x2c, pystub(c, 2, ret=lambda emu, k: (0x20 if sqz else r.choice([-1, 0x20, 0x20, 0x41, 0x2603, 7, 0x10000, 0])) & 0xffffffff, pop=0,
                                side=lambda emu, k, E=E: emu.calllog.append(('e2c', nm(emu.arg32(0)), emu.arg32(1)))))
        em.w32(E + 0x30, pystub(c, 3, ret=lambda emu, k: 0 if special else r.choice([0, 0, 0x41, 0x3c, 0x26, 0x100]), pop=0,
                                side=lambda emu, k, E=E: emu.calllog.append(('e30', nm(emu.arg32(0)), emu.arg32(1), emu.arg32(2)))))
    buf2 = PARSER + 0x244

    def s620180(emu, k):
        a = [emu.arg32(i) for i in range(4)]
        emu.calllog.append(('c620180', a[0] - PARSER if a[0] != BUF else 'BUF', nm(a[1]), a[2], a[3]))
        if a[0] == buf2:
            emu.w32(buf2 + 0x10, D2 if special else r.choice([0, D2, D2 + 8, D2]))
            emu.w32(buf2 + 0xc, D2 + 0x20)
            emu.w32(buf2 + 8, r.choice([D2 + 0x20, D2 + 0x20, D2 + 0x100]))
    hook_rec(c, 0x620180, 4, ret=lambda emu, k: 1 if special else r.choice([0, 1, 1, 1, 1]), pop=0, side=s620180)

    def s6206e0(emu, k):
        b = emu.arg32(0)
        emu.calllog.append(('c6206e0', b - PARSER if b != BUF else 'BUF'))
        emu.w32(b + 8, emu.r32(b + 0xc) + 0x40)
    hook_rec(c, 0x6206e0, 1, ret=lambda emu, k: 1 if special else r.choice([1, 1, 0]), pop=0, side=s6206e0)
    ents = []
    for i in range(1 if special else r.choice([0, 1, 2, 3])):
        en = rnd(c, 0x30)
        names[en] = 'en%d' % i
        em.wbytes(en + 0x1c, bytes([0 if special else r.choice([0, 0, 0, 1])]))
        em.w32(en + 0x18, 0 if special else r.choice([0, 0, 0, 5]))
        em.w32(en + 4, 0x6000 + 0x100 * i if (special or r.random() < 0.85) else 0)
        em.w32(en + 8, r.choice([0x10, 0x20]))
        ents.append(en)

    def s61fd60(emu, k):
        a = [emu.arg32(i) for i in range(3)]
        emu.calllog.append(('c61fd60', a[0] - PARSER, a[1] - D2 if D2 <= a[1] < D2 + 0x200 else a[1], a[2]))
        emu.w32(PARSER + 0x254, r.choice([D2, D2 + 4, 0x1234]))
    hook_rec(c, 0x61fd60, 3, ret=lambda emu, k: ents[r.randrange(len(ents))] if ents and (special or r.random() < 0.9) else 0, pop=0, side=s61fd60)
    nst = [0]

    def s626e10(emu, k):
        n = r.choice([-1, 0, 1, 2, 3, 4])
        nst[0] = n
        emu.calllog.append(('c626e10', emu.arg32(0), n))
        if n > 0:
            emu.wbytes(emu.arg32(1), bytes([r.randrange(256) for _ in range(n)]))
    hook_rec(c, 0x626e10, 2, ret=lambda emu, k: nst[0] & 0xffffffff, pop=0, stackmark=(1,), side=s626e10)
    return [PARSER, E1, 0 if sqz and c.case % 10 == 0 else r.choice([0, 1]), 0x4000, 0x4040, BUF]


S(0x61c790, 'GUESS FUN_61c790', 'cdecl', None, ret='eax', gen=g61c790, note='batch246006')


def g61a060(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)

    def FV():
        q = r.random()
        if q < 0.88:
            return r.choice([0.0, 1.0, -1.0, 2.0, 0.5, -0.5, 3.0, -2.0, 0.25, 10.0])
        return r.choice([float('nan'), float('inf'), -0.0])
    THIS = rnd(c, 0x40)
    names[THIS] = 'T'
    em.w32(THIS + 0xc, r.choice([0, 3, 3, 3]))
    P4 = rnd(c, 0x40)
    em.w32(THIS + 4, P4)
    em.w32(P4 + 0x14, r.choice([0, 5, 5, 5]))     # X = P4 + 0xc: X[8] = P4[0x14]
    Z = rnd(c, 0x20)
    em.w32(P4 + 4, Z)
    S = rnd(c, 0x80)
    names[S] = 'S'
    em.w32(Z + 8, S)
    em.w32(THIS + 8, 0x5000)
    # globals
    G = rnd(c, 0x1b00)
    em.w32(0x70039c, G)
    K = rnd(c, 0x40)
    KB = rnd(c, 0x80)
    em.w32(K + 0x20, KB)
    ub(G + 0x1aa3, K)
    em.w32(S + 0x10, r.choice([0, 4, 8]))
    em.wbytes(KB, pk(*[FV() for _ in range(16)]))
    em.wbytes(KB + 0x10, pk(r.choice([-1.0, 0.0, 1.0, -5.0, FV()])))
    em.wbytes(KB + 0x1c, pk(FV()))
    em.wbytes(KB + 0x2c, pk(FV()))
    em.wbytes(KB + 0x20, pk(FV(), FV(), FV()))
    em.w32(S + 0x20, r.choice([0x1100, 0x1000, 0x1100 | 0x80000, 0, 0x100, 0x1000 | 0x80000, 0x1100, 0x1000]))
    em.wbytes(S + 4, struct.pack('<H', r.choice([0, 1, 0x1234, 0xffff])))
    for off in (0x38, 0x44):
        em.w32(S + off, r.getrandbits(32))
    for off in (0x54, 0x58, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74):
        em.wbytes(S + off, pk(FV()))
    # A, D, transform
    A = rnd(c, 0x40)
    names[A] = 'A'
    Dd = rnd(c, 0x80)
    names[Dd] = 'D'
    em.w32(A + 0x14, Dd)
    em.w32(A + 0x28, r.getrandbits(32))
    em.wbytes(A + 5, bytes([r.choice([0, 0, 0, 4, 1])]))
    em.wbytes(Dd + 5, bytes([r.choice([0, 0, 0, 4, 1])]))
    TB = rnd(c, 0x60)
    D20 = rnd(c, 0x60)
    mats = [[1, 0, 0, 0, 1, 0, 0, 0, 1], [0, 1, 0, -1, 0, 0, 0, 0, 1], [2, 0, 0, 0, 2, 0, 0, 0, 2]]
    em.wbytes(TB, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)])]))
    em.wbytes(TB + 0x24, pk(FV(), FV(), FV()))
    em.wbytes(D20, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)])]))
    em.wbytes(D20 + 0x10, pk(*[FV() for _ in range(9)]))
    em.wbytes(D20 + 0x34, pk(FV(), FV(), FV()))
    em.w32(Dd + 0x20, D20)
    if r.random() < 0.35:
        # culling oriented: identity transforms, plane normals (1, 0, 0) and offsets that make the dots positive or negative
        em.wbytes(TB, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(D20, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(KB + 0x10, pk(1.0, 0.0, 0.0))
        em.wbytes(KB + 0x1c, pk(r.choice([-5.0, -5.0, 5.0, -0.5, 0.0])))
        em.wbytes(KB + 0x20, pk(r.choice([1.0, 1.0, -1.0]), 0.0, 0.0))
        em.wbytes(KB + 0x2c, pk(r.choice([-5.0, -5.0, 5.0, -0.5, 0.0])))
        em.w32(S + 0x10, 0)
        em.w32(THIS + 0xc, 3)
        em.w32(P4 + 0x14, 5)
        em.wbytes(A + 5, bytes([0]))
        em.wbytes(Dd + 5, bytes([0]))
    q = r.random()
    em.w32(Dd + 8, TB - 8)          # T default = D[8] + 8
    TB2 = rnd(c, 0x60)
    TB3 = rnd(c, 0x60)
    for tb in (TB2, TB3):
        em.wbytes(tb, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)])]))
        em.wbytes(tb + 0x24, pk(FV(), FV(), FV()))
    em.w32(Dd + 0xc, TB2 if q < 0.35 else 0)
    em.w32(A + 0xc, TB3 if r.random() < 0.35 else 0)
    # renderer
    R = rnd(c, 0x1500)
    RVT = rnd(c, 0x400)
    em.w32(R, RVT)
    names[R] = 'R'
    em.wbytes(R + 0x115f, bytes([r.choice([0, 2, 2, 3])]))
    V = rnd(c, 0x40)
    Q = rnd(c, 0x40)
    VVT = rnd(c, 0x40)
    QVT = rnd(c, 0x40)
    em.w32(V, VVT)
    em.w32(Q, QVT)
    names[V] = 'V'
    names[Q] = 'Q'
    em.w32(V + 0x30, r.choice([0, 1, 5]))
    em.w32(V + 0x2c, r.choice([0x24, 0x1234]))
    em.w32(Q + 0x18, r.choice([0, 1]))
    em.w32(Q + 0x14, r.choice([0x77, 0x88]))
    ub(R + 0x13fa, V)
    ub(R + 0x140a, Q)
    em.w32(VVT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('v8', nm(emu.reg('ecx'))))))
    em.w32(QVT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('q8', nm(emu.reg('ecx'))))))
    vec3 = lambda emu, a: emu.rbytes(a, 12).hex()
    em.w32(RVT + 0x29c, pystub(c, 3, ret=0, pop=12, this=True, side=lambda emu, k: emu.calllog.append(('r29c', [emu.arg32(i) for i in range(3)]))))
    em.w32(RVT + 0x28c, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(0, 1),
                               side=lambda emu, k: emu.calllog.append(('r28c', emu.rbytes(emu.arg32(0), 36).hex() if emu.arg32(0) < 0x70000000 and emu.arg32(0) > 0x1000 else 0, vec3(emu, emu.arg32(1)), emu.arg32(2)))))
    em.w32(RVT + 0x2ac, pystub(c, 9, ret=0, pop=36, this=True, side=lambda emu, k: emu.calllog.append(('r2ac', [emu.arg32(i) for i in range(9)]))))
    em.w32(RVT + 0x2a8, pystub(c, 4, ret=0, pop=16, this=True, side=lambda emu, k: emu.calllog.append(('r2a8', [emu.arg32(i) for i in range(4)]))))
    em.w32(RVT + 0x2a0, pystub(c, 3, ret=0, pop=12, this=True, side=lambda emu, k: emu.calllog.append(('r2a0', [emu.arg32(i) for i in range(3)]))))
    # device
    DV = rnd(c, 0x20)
    DVT = rnd(c, 0x400)
    em.w32(DV, DVT)
    em.w32(0x724a00, DV)
    names[DV] = 'DEV'
    em.w32(DVT + 0xc8, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('dc8', [emu.arg32(i) for i in range(1, 3)]))))
    em.w32(DVT + 0x130, pystub(c, 2, ret=0, pop=8, side=lambda emu, k: emu.calllog.append(('d130', emu.arg32(1)))))
    em.w32(DVT + 0x14c, pystub(c, 4, ret=0, pop=16, side=lambda emu, k: emu.calllog.append(('d14c', [emu.arg32(i) for i in range(1, 4)]))))
    em.w32(DVT + 0x154, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('d154', [emu.arg32(i) for i in range(1, 3)]))))
    em.w32(0x724948, r.choice([0, 1, 5]))
    em.w32(0x7249f8, r.choice([0x152, 0x152, 0x151]))
    em.w32(0x724970, r.choice([0x24, 0x1234, r.getrandbits(32)]))
    em.w32(0x7249b0, r.choice([0x24, 0x24, 0x23]))
    em.w32(0x7249f0, r.choice([0x77, 0x88, 0x99]))
    em.w32(0x7249f4, r.choice([0, 3, 3]))
    # hooks
    hook_rec(c, 0x610070, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c610070', nm(emu.reg('ecx')), emu.arg32(0))))
    hook_rec(c, 0x6107e0, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c6107e0', nm(emu.reg('ecx')), emu.arg32(0))))
    hook_rec(c, 0x61a6b0, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('c61a6b0', emu.reg('ecx'), emu.reg('edx'))))
    # debug
    flt = [0.0, 1.0, 2.0, -1.0]
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    return [THIS, A, R]


S(0x61a060, 'GUESS FUN_61a060', 'thiscall', None, ret=None, gen=g61a060, note='batch246006')


def g401f20(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    PHYS = 0x2400

    def FV():
        q = r.random()
        if q < 0.9:
            return r.choice([0.0, 1.0, -1.0, 0.5, 0.25, 100.0, -3.5, 1e-3])
        return r.choice([float('nan'), float('inf'), 1e30])
    ch = r.choice([1, 2, 3])
    bs0 = r.choice([256, 512, 128])
    bs1 = r.choice([2048, 1024, 512])
    CI = rnd(c, 0x40)
    em.w32(CI, bs0)
    em.w32(CI + 4, bs1)
    em.w32(CI + 8, r.choice([600, 1000, 2000]))
    em.w32(CI + 0xc, r.choice([600, 1000, 2000]))
    VI = rnd(c, 0x40)
    em.w32(VI + 4, ch)
    em.w32(VI + 0x1c, CI)
    V = rnd(c, 0x80)
    em.w32(V + 4, VI)
    # pcm buffers (physical size PHYS floats)
    bufs = []
    for j in range(ch):
        b = rnd(c, PHYS * 4)
        for off in range(0, PHYS * 4, 4):
            if r.random() < 0.05:
                em.wbytes(b + off, pk(FV()))
        bufs.append(b)
    PA = rnd(c, 0x10)
    for j in range(ch):
        em.w32(PA + 4 * j, bufs[j])
    em.w32(V + 8, PA)
    em.w32(V + 0x10, r.choice([1000, 3000, 6000, 7000]))
    em.w32(V + 0x14, r.choice([0, 100, 1500, 3000]))
    em.w32(V + 0x18, r.choice([-1, 0, 5, 9000, 20000, 0x2001, 0x2000, 100]) if r.random() < 0.9 else 0x2000)
    em.w32(V + 0x20, r.choice([0, 0, 1]))
    em.w32(V + 0x24, r.choice([0, 1]))
    em.w32(V + 0x28, r.choice([0, 1]))
    em.w32(V + 0x30, r.choice([0, 100, 500, 1100, 1500, 3000, 4000, bs1 // 2, bs1 // 2 + 1]))
    gp = r.choice([0xffffffffffffffff, 0, 1000, 123456, 0x100000000 + 5])
    em.w32(V + 0x38, gp & 0xffffffff)
    em.w32(V + 0x3c, gp >> 32)
    seq = r.choice([0, 5, 100, 0xffffffff])
    em.w32(V + 0x40, seq)
    em.w32(V + 0x44, r.choice([0, 0, 0, 1]))
    for off in (0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x60, 0x64):
        em.w32(V + off, r.choice([0, 1, 0xffffffff, r.getrandbits(32)]))
    # block
    VB = rnd(c, 0x80)
    VBA = rnd(c, 0x10)
    for j in range(ch):
        sb = rnd(c, 2048 * 4 + 16)
        for off in range(0, 2048 * 4, 4):
            if r.random() < 0.5:
                em.wbytes(sb + off, pk(FV()))
        em.w32(VBA + 4 * j, sb)
    em.w32(VB, VBA)
    em.w32(VB + 0x1c, r.choice([0, 1, 1, 0, 2]))
    em.w32(VB + 0x2c, r.choice([0, 0, 1]))
    vgp = r.choice([0xffffffffffffffff, 0, 2000, 123456 + 100000, 5, 0x100000000 + 9, 900, 100, 1000])
    em.w32(VB + 0x30, vgp & 0xffffffff)
    em.w32(VB + 0x34, vgp >> 32)
    # sequence continuing, wrong, or first (1)
    q = r.random()
    if q < 0.5:
        s2 = (seq + 1) & 0xffffffff
        hi2 = em.r32(V + 0x44) + (1 if seq == 0xffffffff else 0)
        em.w32(VB + 0x38, s2)
        em.w32(VB + 0x3c, hi2)
    elif q < 0.75:
        em.w32(VB + 0x38, 1)
        em.w32(VB + 0x3c, 0)
    else:
        em.w32(VB + 0x38, r.getrandbits(32))
        em.w32(VB + 0x3c, r.choice([0, 1]))
    for off in (0x58, 0x5c, 0x60, 0x64):
        em.w32(VB + off, r.choice([0, 5, 0xfffffffb, r.getrandbits(32)]))
    # oriented modes: equalities and sign cases the random fields never hit
    if r.random() < 0.5:
        M64 = 1 << 64
        Wv, lWv = r.choice([0, 1]), r.choice([0, 1])
        em.w32(VB + 0x1c, Wv)
        em.w32(V + 0x28, lWv)
        bsl_, bsW_ = (bs0, bs1)[lWv], (bs0, bs1)[Wv]
        centerW_ = em.r32(V + 0x30)
        dd = bsl_ // 4 + bsW_ // 4
        newc_ = dd + centerW_
        endW_ = newc_ - bsW_ // 2 + bsW_
        em.w32(V + 0x18, r.choice([5, 100, 0x2000]))
        sm = r.randrange(5)

        def seqok():
            em.w32(V + 0x40, 0)
            em.w32(V + 0x44, 0)
            em.w32(VB + 0x38, 1 if r.random() < 0.85 else 7)
            em.w32(VB + 0x3c, 0)

        def setgp(gnew, vg):
            gp_ = (gnew - dd) % M64
            em.w32(V + 0x38, gp_ & 0xffffffff)
            em.w32(V + 0x3c, gp_ >> 32)
            em.w32(VB + 0x30, vg & 0xffffffff)
            em.w32(VB + 0x34, vg >> 32)
        if sm == 0:
            if endW_ > 0:
                em.w32(V + 0x10, endW_ + r.choice([0, 0, 0, 1, -1]))
        elif sm == 1:
            em.w32(V + 0x18, r.choice([-2, -7, -1000, -1, 0x7fffffff]) & 0xffffffff)
        elif sm == 2:
            L = [5, 0x100000005, 0x8000000000000005, 0xffffffff00000005, 0x7fffffff00000005, 0x200000005, 0xffffffff, 0x1ffffffff, 1000]
            gnew = r.choice(L)
            q = r.random()
            vg = gnew if q < 0.25 else (gnew ^ (r.choice([1, 2, 0x80000000]) << 32)) if q < 0.5 else r.choice(L)
            seqok()
            em.w32(VB + 0x2c, r.choice([0, 1]))
            setgp(gnew, vg)
        elif sm == 3:
            k = r.randrange(1, 400)
            vg = r.choice([5, 1000, 0x100000005, 123456])
            seqok()
            em.w32(VB + 0x38, 1)
            em.w32(VB + 0x2c, 0)
            setgp(vg + k, vg)
            em.w32(V + 0x18, (newc_ - k + r.choice([0, 0, 0, 1, -1])) & 0xffffffff)
        else:
            seqok()
            em.w32(VB + 0x2c, r.choice([0, 1]))
            gp_ = r.choice([0xffffffffffffffff, 0xffffffffffffffff, 1000, 0xffffffff])
            em.w32(V + 0x38, gp_ & 0xffffffff)
            em.w32(V + 0x3c, gp_ >> 32)
            vg = r.choice([0xffffffff, 0xffffffff, 0xffffffffffffffff, 0xffffffff00000000, 7])
            em.w32(VB + 0x30, vg & 0xffffffff)
            em.w32(VB + 0x34, vg >> 32)
    # CRT stubs
    sizes = {}

    def h_memmove(e, rr):
        d, s_, n = e.arg32(0), e.arg32(1), e.arg32(2)
        e.calllog.append(('memmove', d - bufs[0] if bufs[0] <= d < bufs[0] + PHYS * 4 else d, s_ - d, n))
        if 0 < n <= PHYS * 4:
            e.wbytes(d, e.rbytes(s_, n))
        e.ret(eax=d)

    def h_realloc(e, rr):
        p_, n = e.arg32(0), e.arg32(1)
        e.calllog.append(('realloc', n, p_ in bufs))
        nb = e.alloc(max(n, PHYS * 4), 16)
        e.wbytes(nb, e.rbytes(p_, PHYS * 4))
        e.ret(eax=nb)
    em.stub_import('memmove', h_memmove)
    em.stub_import('realloc', h_realloc)
    return [V, VB]


S(0x401f20, 'GUESS FUN_401f20', 'cdecl', None, ret='eax', gen=g401f20, note='batch246006')


def g659c40(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    FL = [0.0, 1.0, -2.5, 1e30, 3.25, 100.0]
    rb = lambda n: bytes(r.getrandbits(8) for _ in range(n))
    pu = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    # hooks on every direct callee
    rr32 = lambda emu, k: r.getrandbits(32)
    for a in (0x658d30, 0x658d00, 0x658d80):
        hook_rec(c, a, 0, ret=rr32, pop=0, this=True)
    hook_rec(c, 0x63eb90, 1, ret=0, pop=4, this=True, st0=lambda emu, k: r.choice(FL))
    hook_rec(c, 0x646430, 6, ret=rr32, pop=0x18, this=True, nullflag=(3,))
    hook_rec(c, 0x645c30, 4, ret=rr32, pop=0x10, this=True, nullflag=(3,))
    hook_rec(c, 0x647870, 3, ret=rr32, pop=0xc, this=True)
    hook_rec(c, 0x647790, 3, ret=rr32, pop=0xc, this=True)
    hook_rec(c, 0x646040, 0, ret=lambda emu, k: r.choice([0, 1, 1, 0x100, 0x101, 0x1]), pop=0, this=True)
    for a in (0x4df1e0, 0x4de480, 0x4419f0, 0x441940):
        hook_rec(c, a, 0, ret=0, pop=0, side=lambda emu, k, a=a: emu.calllog.append(('f%x' % a, emu.reg('ecx'), emu.reg('edx'))))
    # global chain [0x70039c] -> +0x1aa3 -> +0x18 -> object with vslots 0xc4 / 0xbc / 0xc8
    GL = rnd(c, 0x1b00)
    GM = rnd(c, 0x40)
    GO = rnd(c, 0x20)
    GOVT = rnd(c, 0x200)
    em.w32(0x70039c, GL)
    pu(GL + 0x1aa3, GM)
    em.w32(GM + 0x18, GO)
    em.w32(GO, GOVT)
    B0C = []
    for _ in range(2):
        b = rnd(c, 0x300)
        for k in range(7):
            pu(b + 0xc + 0x30 * k, r.randrange(0, 6))
        B0C.append(b)
    em.w32(GOVT + 0xc4, pystub(c, 1, ret=lambda emu, k: r.choice(B0C), pop=4, this=True))
    em.w32(GOVT + 0xbc, pystub(c, 1, ret=rr32, pop=4, this=True))
    em.w32(GOVT + 0xc8, pystub(c, 1, ret=rr32, pop=4, this=True))
    # items
    items = []
    for i in range(5):
        it = rnd(c, 0x80)
        T = rnd(c, 0x80)
        REF = rnd(c, 0x40)
        RVT = rnd(c, 0x300)
        X = rnd(c, 0x400)
        R8 = rnd(c, 0x60)
        em.wbytes(R8, rb(0x60))
        em.wbytes(X, rb(0x400))
        em.wbytes(it + 5, bytes([r.choice([1, 0, 3, 2, 0x81, 0x80, 1, 1])]))
        em.w32(it + 0x38, T)
        em.w32(T + 0x54, REF)
        pu(T + 0x6c, r.getrandbits(32))
        em.wbytes(T + 0x5a, rb(2))
        em.w32(REF, RVT)
        em.w32(REF + 8, R8)
        pu(X + 0x11, r.choice([1, 2, 3, 4, 1, 5]))
        em.w32(RVT + 0x24c, pystub(c, 0, ret=X, pop=0, this=True))
        em.w32(RVT + 0x2c0, pystub(c, 0, ret=rr32, pop=0, this=True))
        items.append(it)
    # blocks of 8 item slots
    nb = r.choice([1, 1, 2, 3])
    blocks = [rnd(c, 0x40) for _ in range(nb)]
    nextmap = {}
    for bi, b in enumerate(blocks):
        em.w32(b, r.choice([1, 2, 3]))
        em.w32(b + 8, blocks[bi + 1] if bi + 1 < nb else 0)
        for s in range(12):
            em.w32(b + 0x10 + 4 * s, r.choice(items))
            nextmap[b + 0x10 + 4 * s] = b + 0x10 + 4 * s + 4 if s < 5 else 0
    R = rnd(c, 0x10)
    em.w32(R, blocks[0] + 0x10 if r.random() < 0.9 else 0)
    em.w32(R + 4, r.choice([0, 0, 0, 1]) if em.r32(blocks[0]) >= 2 else 0)
    em.w32(R + 8, blocks[0])
    # this object
    THIS = rnd(c, 0x400)
    TVT = rnd(c, 0x200)
    CVT = rnd(c, 0x200)
    em.w32(THIS, TVT)
    em.w32(THIS + 0x1c8, CVT)
    em.w32(CVT + 4, pystub(c, 0, ret=lambda emu, k: r.choice([1, 1, 1, 0x100, 0, 5]) if r.random() < 0.85 else 0, pop=0, this=True))
    em.w32(CVT + 0xc, pystub(c, 1, ret=R, pop=4, this=True, nullflag=(0,)))

    def skip(emu, k):
        p = emu.arg32(0)
        cur = emu.r32(p)
        emu.w32(p, nextmap.get(cur, 0) if r.random() < 0.7 else 0)
    em.w32(CVT + 0x10, pystub(c, 1, ret=0, pop=4, this=True, nullflag=(0,), side=skip))
    em.w32(TVT + 0xc4, pystub(c, 1, ret=0, pop=4, this=True))
    em.w32(TVT + 0x10, pystub(c, 0, ret=0, pop=0, this=True))
    return [THIS]


S(0x659c40, 'GUESS FUN_659c40', 'thiscall', None, ret=None, gen=g659c40, note='batch246006')


def g4d6520(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    THIS = em.alloc(0x80, 4)
    ub(THIS + 0x11, r.getrandbits(32))
    ub(THIS + 0x2e, r.getrandbits(32))
    ub(THIS + 0x40, r.getrandbits(32))
    em.w32(THIS + 0x3c, r.choice([0, 0, 1]))
    F = rnd(c, 0x10)
    FVT = rnd(c, 0x100)
    em.w32(F, FVT)
    ub(THIS + 0x15, F)
    names = [b'a', b'ab', b'a/b', b'abc', b'x', b'a/bc', b'ab/c']
    stream = bytearray()
    entry_pos = []
    ents = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        sig = 0x2014b50 if r.random() > 0.1 else r.choice([0x1234abcd, 0x04034b50])
        stream += struct.pack('<I', sig)
        entry_pos.append(len(stream))
        if sig != 0x2014b50:
            continue
        nm = r.choice(names) if r.random() > 0.1 else b''
        ents.append(nm)
        el, cl = r.choice([0, 0, 1, 3]), r.choice([0, 0, 1, 2])
        hdr = bytearray(r.getrandbits(8) for _ in range(0x2a))
        struct.pack_into('<H', hdr, 0x18, len(nm))
        struct.pack_into('<H', hdr, 0x1a, el)
        struct.pack_into('<H', hdr, 0x1c, cl)
        stream += bytes(hdr) + nm + bytes(r.getrandbits(8) for _ in range(el + cl))
    end = r.choice([struct.pack('<I', 0x6054b50), struct.pack('<I', 0x52756e65), b''])
    stream += end
    pos = [0]
    badread = r.random() < 0.06
    nrd = [0]

    def read_h(emu, k):
        dst, n, h = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        d = bytes(stream[pos[0]:pos[0] + n])
        d += bytes(n - len(d))
        emu.wbytes(dst, d)
        pos[0] += n
        nrd[0] += 1
        emu.calllog.append(('rd', n, h, d.hex()))
        return (n - 1) if (badread and nrd[0] == 3) else n
    em.w32(FVT + 0x14, pystub(c, 3, ret=read_h, pop=12, this=True, stackmark=(0,)))

    def seek_h(emu, k):
        emu.calllog.append(('seek', emu.arg32(0), emu.arg32(1), emu.arg32(2)))
        pos[0] = 0
    em.w32(FVT + 0x10, pystub(c, 3, ret=0, pop=12, this=True, side=seek_h))
    em.w32(FVT + 0xc, pystub(c, 1, ret=lambda emu, k: pos[0], pop=4, this=True, side=lambda emu, k: emu.calllog.append(('tell', emu.arg32(0)))))
    em.w32(FVT + 0x1c, pystub(c, 1, ret=lambda emu, k: 1 if pos[0] >= len(stream) else 0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('eof', pos[0]))))
    known = [p for p in entry_pos if r.random() < 0.3]
    cnt = len(known) + r.choice([0, 0, 1])
    ARR = em.alloc(0x40, 4)
    for i, p in enumerate(known):
        em.w32(ARR + 4 * i, p)
    for i in range(len(known), cnt):
        em.w32(ARR + 4 * i, 0x7777 + i)
    ub(THIS + 0x62, cnt)
    ub(THIS + 0x66, ARR)

    def cs(emu, a):
        return emu.rbytes(a, 40).split(b'\0')[0].hex()
    M = rnd(c, 0x10)
    MVT = rnd(c, 0x20)
    em.w32(M, MVT)
    if r.random() < 0.85:
        ub(THIS + 0x6a, M)

    def s8(emu, k):
        emu.calllog.append(('m8', cs(emu, emu.arg32(0)), emu.arg32(1)))
        if r.random() < 0.7:
            emu.w32(emu.arg32(2), r.choice([0xffffffff, 0, 5, 40]))
    em.w32(MVT + 8, pystub(c, 3, ret=lambda emu, k: r.choice([0, 1, 1, 0x100, 0x101]), pop=12, this=True, stackmark=(0, 1, 2), side=s8))
    em.w32(MVT + 4, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(0, 1),
                           side=lambda emu, k: emu.calllog.append(('m4', emu.reg('ecx') - M, cs(emu, emu.arg32(0)), emu.rbytes(emu.arg32(1), 26).hex(), emu.arg32(2)))))
    LO = rnd(c, 0x10)
    LVT = rnd(c, 0x100)
    em.w32(LO, LVT)
    em.w32(0x700390, LO)
    XO = rnd(c, 0x10)
    XVT = rnd(c, 0x100)
    em.w32(XO, XVT)
    em.w32(LVT + 0x20, pystub(c, 2, ret=XO, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('l20', emu.arg32(0), emu.arg32(1)))))
    em.w32(XVT + 0x2c, pystub(c, 2, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('x2c', emu.arg32(1)))))
    em.w32(0x7003b0, pystub(c, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('fatal',))))

    def strchr_h(emu, res_):
        s = emu.arg32(0)
        ch = emu.arg32(1) & 0xff
        data = emu.rbytes(s, 0x200).split(b'\0')[0]
        i = data.find(bytes([ch]))
        emu.calllog.append(('strchr', ch, data.hex()))
        emu.ret(eax=(s + i) if i >= 0 else 0, argbytes=0)
    em.w32(0x676254, em.stub_fn('strchr', strchr_h))

    def strcmp_h(emu, res_):
        a = emu.rbytes(emu.arg32(0), 0x200).split(b'\0')[0]
        b = emu.rbytes(emu.arg32(1), 0x200).split(b'\0')[0]
        emu.calllog.append(('strcmp', a.hex(), b.hex()))
        emu.ret(eax=(0 if a == b else (1 if a > b else 0xffffffff)), argbytes=0)
    em.w32(0x676414, em.stub_fn('strcmp', strcmp_h))

    def f4cc850(emu, k):
        b = emu.rbytes(emu.reg('ecx'), 0x100).split(b'\0')[0]
        a = emu.rbytes(emu.reg('edx'), 0x100).split(b'\0')[0]
        emu.calllog.append(('w4cc', b.hex(), a.hex()))
        return 0 if b.startswith(a.split(b'*')[0]) else r.choice([1, 2])
    hook_rec(c, 0x4cc850, 0, ret=f4cc850, pop=0)
    # path: an existing name (also with backslashes), a pattern, empty or unknown
    q = r.random()
    base = r.choice(ents) if ents and r.random() < 0.75 else r.choice(names)
    if q < 0.55:
        p = base
    elif q < 0.7:
        p = base.replace(b'/', b'\\')
    elif q < 0.88:
        p = base[:r.randrange(0, len(base) + 1)] + b'*' + r.choice([b'', b'c'])
    elif q < 0.94:
        p = b''
    else:
        p = b'a\\b/c'
    P = em.alloc(0x40, 4)
    em.wbytes(P, p + b'\0')
    OUT = em.alloc(0x40, 4)
    em.wbytes(OUT, bytes(r.getrandbits(8) for _ in range(0x40)))
    OP = 0
    if r.random() < 0.55:
        OP = em.alloc(0x10, 4)
        em.wbytes(OP, bytes(r.getrandbits(8) for _ in range(4)))
    return [THIS, P, OUT, OP]


S(0x4d6520, 'GUESS FUN_4d6520', 'thiscall', None, ret='al', gen=g4d6520, note='batch246006')


def g619770(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def nm(a):
        return names.get(a, a if a < 0x1000 else -1)

    def FV():
        q = r.random()
        if q < 0.88:
            return r.choice([0.0, 1.0, -1.0, 2.0, 0.5, -0.5, 3.0, -2.0, 0.25, 10.0])
        return r.choice([float('nan'), float('inf'), -0.0])
    THIS = rnd(c, 0x40)
    names[THIS] = 'T'
    em.w32(THIS + 0xc, r.choice([0, 3, 3, 3]))
    P4 = rnd(c, 0x40)
    em.w32(THIS + 4, P4)
    em.w32(P4 + 0x14, r.choice([0, 5, 5, 5]))     # X = P4 + 0xc: X[8] = P4[0x14]
    Z = rnd(c, 0x20)
    em.w32(P4 + 4, Z)
    S = rnd(c, 0x80)
    names[S] = 'S'
    em.w32(Z + 8, S)
    em.w32(THIS + 8, 0x5000)
    # globals
    G = rnd(c, 0x1b00)
    em.w32(0x70039c, G)
    K = rnd(c, 0x40)
    KB = rnd(c, 0x80)
    em.w32(K + 0x20, KB)
    ub(G + 0x1aa3, K)
    em.w32(S + 0x10, r.choice([0, 4, 8]))
    em.wbytes(KB, pk(*[FV() for _ in range(16)]))
    em.wbytes(KB + 0x10, pk(r.choice([-1.0, 0.0, 1.0, -5.0, FV()])))
    em.wbytes(KB + 0x1c, pk(FV()))
    em.wbytes(KB + 0x2c, pk(FV()))
    em.wbytes(KB + 0x20, pk(FV(), FV(), FV()))
    em.w32(S + 0x20, r.choice([0x1100, 0x1000, 0x1100 | 0x80000, 0, 0x100, 0x1000 | 0x80000, 0x1100, 0x1000]) | (0x800000 if r.random() < 0.1 else 0))
    em.wbytes(S + 4, struct.pack('<H', r.choice([0, 1, 0x1234, 0xffff])))
    for off in (0x38, 0x44):
        em.w32(S + off, r.getrandbits(32))
    for off in (0x54, 0x58, 0x60, 0x64, 0x68, 0x6c, 0x70, 0x74):
        em.wbytes(S + off, pk(FV()))
    # A, D, transform
    A = rnd(c, 0x40)
    names[A] = 'A'
    Dd = rnd(c, 0x80)
    names[Dd] = 'D'
    em.w32(A + 0x14, Dd)
    em.w32(A + 0x28, r.getrandbits(32))
    em.wbytes(A + 5, bytes([r.choice([0, 0, 0, 4, 1])]))
    em.wbytes(Dd + 5, bytes([r.choice([0, 0, 0, 4, 1])]))
    TB = rnd(c, 0x60)
    D20 = rnd(c, 0x60)
    mats = [[1, 0, 0, 0, 1, 0, 0, 0, 1], [0, 1, 0, -1, 0, 0, 0, 0, 1], [2, 0, 0, 0, 2, 0, 0, 0, 2]]
    em.wbytes(TB, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)])]))
    em.wbytes(TB + 0x24, pk(FV(), FV(), FV()))
    em.wbytes(D20, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)])]))
    em.wbytes(D20 + 0x10, pk(*[FV() for _ in range(9)]))
    em.wbytes(D20 + 0x34, pk(FV(), FV(), FV()))
    em.w32(Dd + 0x20, D20)
    if r.random() < 0.35:
        # culling oriented: identity transforms, plane normals (1, 0, 0) and offsets that make the dots positive or negative
        em.wbytes(TB, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(D20, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(KB + 0x10, pk(r.choice([1.0, 1.0, 1.0, 2.25, 2.0, 2.5]), 0.0, 0.0))
        em.wbytes(KB + 0x1c, pk(r.choice([-5.0, -5.0, 5.0, -0.5, 0.0])))
        em.wbytes(KB + 0x20, pk(r.choice([1.0, 1.0, -1.0]), 0.0, 0.0))
        em.wbytes(KB + 0x2c, pk(r.choice([-5.0, -5.0, 5.0, -0.5, 0.0])))
        em.w32(S + 0x10, 0)
        em.w32(THIS + 0xc, 3)
        em.w32(P4 + 0x14, 5)
        em.wbytes(A + 5, bytes([0]))
        em.wbytes(Dd + 5, bytes([0]))
    q = r.random()
    em.w32(Dd + 8, TB - 8)          # T default = D[8] + 8
    TB2 = rnd(c, 0x60)
    TB3 = rnd(c, 0x60)
    for tb in (TB2, TB3):
        em.wbytes(tb, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.7 else [FV() for _ in range(9)])]))
        em.wbytes(tb + 0x24, pk(FV(), FV(), FV()))
    em.w32(Dd + 0xc, TB2 if q < 0.35 else 0)
    em.w32(A + 0xc, TB3 if r.random() < 0.35 else 0)
    if r.random() < 0.2:
        # zero-dot mode: plane 1 normal (0, 0, 0) so that d1 == 0 exactly (dot with a zero vector), plane 2 with a real normal and positive or negative d2
        em.w32(Dd + 0xc, 0)
        em.w32(A + 0xc, 0)
        em.wbytes(A + 5, bytes([0]))
        em.wbytes(Dd + 5, bytes([0]))
        em.wbytes(TB, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(TB + 0x24, pk(r.choice([0.0, 1.0, 2.0]), r.choice([0.0, 1.0]), r.choice([0.0, 1.0, -1.0])))
        em.wbytes(D20, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(D20 + 0x10, pk(1, 0, 0, 0, 1, 0, 0, 0, 1))
        em.wbytes(D20 + 0x34, pk(r.choice([0.0, 1.0]), 0.0, r.choice([0.0, 1.0])))
        em.wbytes(KB + 0x10, pk(0.0, 0.0, 0.0))
        em.wbytes(KB + 0x1c, pk(r.choice([-5.0, 5.0, 0.0, 1.0])))
        em.wbytes(KB + 0x20, pk(r.choice([1.0, -1.0, 0.0]), r.choice([0.0, 1.0]), r.choice([0.0, 1.0])))
        em.wbytes(KB + 0x2c, pk(r.choice([-5.0, -5.0, 5.0, -0.5, 0.0])))
        if r.random() < 0.5:
            # d1 > 0 and d2 == 0 exactly: plane 1 real normal with a large positive s, plane 2 normal zero
            em.wbytes(KB + 0x10, pk(1.0, 0.0, 0.0))
            em.wbytes(KB + 0x1c, pk(-5.0))
            em.wbytes(KB + 0x20, pk(0.0, 0.0, 0.0))
        em.w32(S + 0x10, 0)
        em.w32(THIS + 0xc, 3)
        em.w32(P4 + 0x14, 5)
        em.w32(S + 0x20, r.choice([0x1100, 0x1000]))
    # renderer
    R = rnd(c, 0x1500)
    RVT = rnd(c, 0x400)
    em.w32(R, RVT)
    names[R] = 'R'
    em.wbytes(R + 0x115f, bytes([r.choice([0, 2, 2, 3])]))
    V = rnd(c, 0x40)
    Q = rnd(c, 0x40)
    VVT = rnd(c, 0x40)
    QVT = rnd(c, 0x40)
    em.w32(V, VVT)
    em.w32(Q, QVT)
    names[V] = 'V'
    names[Q] = 'Q'
    em.w32(V + 0x30, r.choice([0, 1, 5]))
    em.w32(V + 0x2c, r.choice([0x24, 0x1234]))
    em.w32(Q + 0x18, r.choice([0, 1]))
    em.w32(Q + 0x14, r.choice([0x77, 0x88]))
    ub(R + 0x13fa, V)
    ub(R + 0x140a, Q)
    V2 = rnd(c, 0x40)
    V2VT = rnd(c, 0x40)
    em.w32(V2, V2VT)
    names[V2] = 'V2'
    em.w32(V2 + 0x30, r.choice([0, 1, 5]))
    em.w32(V2 + 0x2c, r.choice([5, 0x1234]))
    ub(R + 0x13fe, V2)
    em.w32(V2VT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('w8', nm(emu.reg('ecx'))))))
    em.w32(0x724b30, r.choice([0x152, 0x152, 0x151, 0x77]))
    em.w32(0x724974, r.choice([5, 0x1234, r.getrandbits(32)]))
    em.w32(0x7249b4, r.choice([4, 4, 3]))
    em.w32(VVT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('v8', nm(emu.reg('ecx'))))))
    em.w32(QVT + 8, pystub(c, 0, ret=0, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('q8', nm(emu.reg('ecx'))))))
    vec3 = lambda emu, a: emu.rbytes(a, 12).hex()
    em.w32(RVT + 0x29c, pystub(c, 3, ret=0, pop=12, this=True, side=lambda emu, k: emu.calllog.append(('r29c', [emu.arg32(i) for i in range(3)]))))
    em.w32(RVT + 0x28c, pystub(c, 3, ret=0, pop=12, this=True, stackmark=(0, 1),
                               side=lambda emu, k: emu.calllog.append(('r28c', emu.rbytes(emu.arg32(0), 36).hex() if emu.arg32(0) < 0x70000000 and emu.arg32(0) > 0x1000 else 0, vec3(emu, emu.arg32(1)), emu.arg32(2)))))
    em.w32(RVT + 0x2ac, pystub(c, 9, ret=0, pop=36, this=True, side=lambda emu, k: emu.calllog.append(('r2ac', [emu.arg32(i) for i in range(9)]))))
    em.w32(RVT + 0x2a8, pystub(c, 4, ret=0, pop=16, this=True, side=lambda emu, k: emu.calllog.append(('r2a8', [emu.arg32(i) for i in range(4)]))))
    em.w32(RVT + 0x2a0, pystub(c, 3, ret=0, pop=12, this=True, side=lambda emu, k: emu.calllog.append(('r2a0', [emu.arg32(i) for i in range(3)]))))
    # device
    DV = rnd(c, 0x20)
    DVT = rnd(c, 0x400)
    em.w32(DV, DVT)
    em.w32(0x724a00, DV)
    names[DV] = 'DEV'
    em.w32(DVT + 0xc8, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('dc8', [emu.arg32(i) for i in range(1, 3)]))))
    em.w32(DVT + 0x130, pystub(c, 2, ret=0, pop=8, side=lambda emu, k: emu.calllog.append(('d130', emu.arg32(1)))))
    em.w32(DVT + 0x14c, pystub(c, 4, ret=0, pop=16, side=lambda emu, k: emu.calllog.append(('d14c', [emu.arg32(i) for i in range(1, 4)]))))
    em.w32(DVT + 0x154, pystub(c, 3, ret=0, pop=12, side=lambda emu, k: emu.calllog.append(('d154', [emu.arg32(i) for i in range(1, 3)]))))
    em.w32(0x724948, r.choice([0, 1, 5]))
    em.w32(0x7249f8, r.choice([0x152, 0x152, 0x151]))
    em.w32(0x724970, r.choice([0x24, 0x1234, r.getrandbits(32)]))
    em.w32(0x7249b0, r.choice([0x24, 0x24, 0x23]))
    em.w32(0x7249f0, r.choice([0x77, 0x88, 0x99]))
    em.w32(0x7249f4, r.choice([0, 3, 3]))
    # hooks
    hook_rec(c, 0x610070, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c610070', nm(emu.reg('ecx')), emu.arg32(0))))
    hook_rec(c, 0x6107e0, 1, ret=0, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c6107e0', nm(emu.reg('ecx')), emu.arg32(0))))
    hook_rec(c, 0x61a6b0, 0, ret=0, pop=0, side=lambda emu, k: emu.calllog.append(('c61a6b0', emu.reg('ecx'), emu.reg('edx'))))
    return [THIS, A, R]


S(0x619770, 'GUESS FUN_619770', 'thiscall', None, ret=None, gen=g619770, note='batch246006')


def g6359d0(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)
    names = {}

    def FV():
        q = r.random()
        if q < 0.9:
            return r.choice([0.0, 1.0, -1.0, 2.0, 0.5, 3.0, -2.0])
        return r.choice([float('nan'), float('inf'), -0.0])
    mats = [[1, 0, 0, 0, 1, 0, 0, 0, 1], [0, 1, 0, -1, 0, 0, 0, 0, 1], [2, 0, 0, 0, 2, 0, 0, 0, 2]]

    def mk_obj(depth):
        o = rnd(c, 0x60)
        em.wbytes(o, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.8 else [FV() for _ in range(9)])]))
        em.wbytes(o + 0x24, pk(r.choice([0.0, 1.0, FV()]), r.choice([0.0, 2.0]), r.choice([0.0, -1.0])))
        em.w32(o + 0x50, mk_obj(depth - 1) if depth > 0 and r.random() < 0.5 else 0)
        return o
    THIS = rnd(c, 0x200)
    names[THIS] = 'T'
    em.wbytes(THIS + 0x6f, bytes([r.choice([0, 1, 1, 1])]))
    em.wbytes(THIS + 0x70, bytes([r.choice([0, 1, 1])]))
    ub(THIS + 0x6a, r.getrandbits(32))
    ub(THIS + 0x8f, r.getrandbits(32))
    em.wbytes(THIS + 0x1d, pk(r.choice([0.0, 1.0]), r.choice([0.0, 2.0]), r.choice([0.0, -1.0])))
    em.wbytes(THIS + 0x29, pk(*[float(x) for x in (r.choice(mats) if r.random() < 0.8 else [FV() for _ in range(9)])]))
    em.wbytes(THIS + 0x4d, pk(FV(), FV(), FV()))
    # global chain G -> [+0x1aa3] -> [+0x1c] = O (query object)
    G = rnd(c, 0x1b00)
    GM = rnd(c, 0x40)
    O = rnd(c, 0x20)
    OVT = rnd(c, 0x200)
    em.w32(0x70039c, G)
    ub(G + 0x1aa3, GM)
    em.w32(GM + 0x1c, O)
    em.w32(O, OVT)
    # objects returned by the first query (each with a [0x54] source object having vslot 0x244)
    objs = []
    for i in range(r.choice([0, 1, 2, 3])):
        e = mk_obj(2)
        src = rnd(c, 0x20)
        svt = rnd(c, 0x400)
        em.w32(src, svt)
        em.w32(e + 0x54, src)
        P = rnd(c, 0x40)
        # four vectors; make them coincide sometimes
        vs = []
        for _ in range(4):
            if vs and r.random() < 0.25:
                vs.append(r.choice(vs))
            else:
                vs.append((r.choice([0.0, 1.0, 2.0, FV()]), r.choice([0.0, 1.0, FV()]), r.choice([0.0, 1.0, FV()])))
        em.wbytes(P, pk(*[x for v in vs for x in v]))
        em.w32(svt + 0x244, pystub(c, 0, ret=P, pop=0, this=True))
        objs.append(e)

    def s38(emu, k):
        L, Fb = emu.arg32(0), emu.arg32(1)
        for i, e in enumerate(objs):
            emu.w32(L + 4 * i, e)
        emu.calllog.append(('q38', [emu.arg32(i) if i not in (0, 1) else 0 for i in range(10)], len(objs)))
    em.w32(OVT + 0x38, pystub(c, 10, ret=lambda emu, k: len(objs), pop=40, this=True, stackmark=(0, 1), side=s38))
    # records returned by the second query
    recs = bytearray()
    nrec = r.choice([0, 1, 2, 3])
    for i in range(nrec):
        npts = r.choice([2, 3, 3, 4, 5, 6])
        ob = mk_obj(1)
        if r.random() < 0.5:
            q54 = rnd(c, 0x20)
            q10 = rnd(c, 0x30)
            em.wbytes(q10 + 0x18, bytes([r.choice([0, 2, 3, 1, 0x82])]))
            em.w32(q54 + 0x10, q10 if r.random() < 0.85 else 0)
            em.w32(ob + 0x54, q54)
        else:
            em.w32(ob + 0x54, 0)
        pts = []
        for j in range(npts):
            if pts and r.random() < 0.2:
                pts.append(r.choice(pts))
            else:
                pts.append((r.choice([0.0, 1.0, 2.0, FV()]), r.choice([0.0, 1.0, FV()]), r.choice([0.0, 1.0, FV()])))
        rec = struct.pack('<I', npts) + bytes(r.getrandbits(8) for _ in range(12)) + struct.pack('<I', ob) + bytes(r.getrandbits(8) for _ in range(4)) + struct.pack('<2f', 0.0, 0.0)[:4]
        rec = rec[:0x18]
        rec += pk(*[x for p in pts for x in p])
        recs += rec

    def s84(emu, k):
        emu.w32(emu.arg32(0), nrec)
        emu.wbytes(emu.arg32(1), bytes(recs))
        emu.calllog.append(('q84', emu.arg32(2), emu.arg32(6), emu.arg32(7), nrec))
    em.w32(OVT + 0x84, pystub(c, 8, ret=0, pop=32, this=True, stackmark=(0, 1), side=s84))

    def tri(emu, k):
        def v3(a):
            return emu.rbytes(a, 12).hex()
        emu.calllog.append(('t354', emu.reg('ecx') - THIS, emu.arg32(0), v3(emu.arg32(1)), v3(emu.arg32(2)), v3(emu.arg32(3))))
    hook_rec(c, 0x6354a0, 4, ret=0, pop=0x10, this=True, stackmark=(0, 1, 2, 3), side=tri)
    return [THIS]


S(0x6359d0, 'GUESS FUN_6359d0', 'thiscall', None, ret=None, gen=g6359d0, note='batch246006')


def g61b570(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    ub = lambda a, v: em.wbytes(a, (v & 0xffffffff).to_bytes(4, 'little'))
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)

    def FV():
        q = r.random()
        if q < 0.9:
            return r.choice([0.0, 1.0, -1.0, 2.0, 0.5, 3.0, -2.0, 100.0, 0.25])
        return r.choice([float('nan'), float('inf'), -0.0])
    THIS = rnd(c, 0x40)
    em.w32(THIS + 0xc, r.choice([1, 3, 0x1d, 0x100]))
    P4 = rnd(c, 0x40)
    em.w32(THIS + 4, P4)
    em.w32(P4 + 0x14, r.choice([0, 5, 5, 5, 5]))
    if r.random() < 0.06:
        em.w32(THIS + 0xc, 0)
    # a, aM, S2
    A = rnd(c, 0x40)
    aM = rnd(c, 0x60)
    Z = rnd(c, 0x20)
    S2 = rnd(c, 0x80)
    em.w32(A + 0xc, aM)
    em.w32(A + 0x10, Z)
    em.w32(Z + 8, S2)
    nfr = r.choice([1, 1, 2, 3, 4, 5, 0])
    cnt = r.choice([0, 1, 3, 0x1f, 0x20, 0x21, 0x40, 0x45, 5])
    em.wbytes(S2 + 0xe, struct.pack('<H', cnt))
    ub(S2 + 0x50, nfr)
    ub(S2 + 0x20, r.getrandbits(32))
    ub(S2 + 0x14, r.choice([0, 0x24, 0x100]))
    # time selection: idx / frac chosen so that the frame index stays inside the frame table
    idx = r.randrange(0, nfr) if nfr else 0
    frac = r.choice([0.0, 0.25, 0.5, 0.75])
    md = r.random()
    if md < 0.1:
        a48 = r.choice([0.0, -0.0])
        i48, i4c = r.getrandbits(32), r.getrandbits(32) | 1
    elif md < 0.7:
        f1 = r.randrange(0, 100)
        f2 = r.choice([1, 2, 4, 8])
        i48, i4c = f1, f2
        a48 = float(f1) + (idx + frac) * f2
    elif md < 0.85:
        i48, i4c = 0, 0x80000000
        a48 = (idx + frac) * 2147483648.0
    else:
        i48, i4c = 0xffffff00, r.choice([1, 2, 4])
        a48 = 4294967040.0 + r.choice([0.0, 0.0, 0.0])
    ub(S2 + 0x48, i48)
    ub(S2 + 0x4c, i4c)
    ub(aM + 0x48, struct.unpack('<I', struct.pack('<f', a48))[0])
    # vertex table: nfr frames of cnt vertices of 0x24 bytes
    VT = rnd(c, 0x4000 + 0x100)
    for off in range(0, 0x4000, 4):
        if r.random() < 0.8:
            em.wbytes(VT + off, pk(FV()))
    # globals
    G = rnd(c, 0x1b00)
    em.w32(0x70039c, G)
    K = rnd(c, 0x40)
    ub(G + 0x1aa3, K)
    em.w32(K + 0x20, VT)
    flt = [0.0, 1.0, 2.0, -1.0]
    em.wbytes(G + 0x9c7, struct.pack('<f', r.choice(flt)))
    em.wbytes(G + 0x9c3, struct.pack('<f', r.choice(flt)))
    GVT = rnd(c, 0x200)
    em.w32(G, GVT)

    def s1c8(emu, k):
        emu.calllog.append(('g1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
    em.w32(GVT + 0x1c8, pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=s1c8))
    for slot in (0x178, 0x17c):
        em.w32(GVT + slot, pystub(c, 3, ret=0, pop=12, this=True,
                                  side=lambda emu, k, slot=slot: emu.calllog.append(('dbg', slot, emu.arg32(0), emu.arg32(1), emu.arg32(2)))))
    # renderer chain R[0xb9a4] = W, W[0x13fa] = E, E[0x30] = buffer
    R = rnd(c, 0xb9b0)
    W = rnd(c, 0x1400)
    ub(R + 0xb9a4, W)
    em.wbytes(W + 0x1295, bytes([r.choice([0, 1, 1, 0x80, 0])]))
    em.wbytes(W + 0x1296, bytes([r.choice([0, 0, 1, 2])]))
    E = rnd(c, 0x40)
    ub(W + 0x13fa, E)
    EVT = rnd(c, 0x20)
    em.w32(E, EVT)
    BUF = rnd(c, 0x40)
    if r.random() < 0.6:
        em.w32(E + 0x30, BUF)
    else:
        em.w32(E + 0x30, 0)
    em.w32(EVT + 4, pystub(c, 2, ret=BUF, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('e4', emu.arg32(0), emu.arg32(1)))))
    for a in (0x65bc60, 0x65bcc0, 0x65bd20):
        hook_rec(c, a, 6, ret=0, pop=0x18, this=True,
                 side=lambda emu, k, a=a: emu.calllog.append(('d%x' % a, emu.rbytes(0x724b78, 0x48).hex() if emu.arg32(1) == 0x724b78 else 0)))
    return [THIS, A, R, r.getrandbits(32), r.getrandbits(32)]


S(0x61b570, 'GUESS FUN_61b570', 'thiscall', None, ret='al', gen=g61b570, note='batch246006')


def g5f3430(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    if r.random() < 0.25:
        em.w32(0x7003a4, 0)
        return []
    O = rnd(c, 0x20)
    VT = rnd(c, 0x100)
    em.w32(O, VT)
    em.w32(0x7003a4, O)
    for off in range(0, 0x100, 4):
        if off != 0x4c:
            em.w32(VT + off, pystub(c, 0, ret=0x1111 + off, pop=0, this=True, side=lambda emu, k, off=off: emu.calllog.append(('wrong', off))))
    em.w32(VT + 0x4c, pystub(c, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=lambda emu, k: emu.calllog.append(('s4c', emu.reg('ecx') - O))))
    return []


S(0x5f3430, 'GUESS FUN_5f3430', 'cdecl', None, ret=None, gen=g5f3430, note='batch246006')


def g406090(c):
    import struct
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda *v: b''.join(struct.pack('<f', x) for x in v)

    def FV():
        q = r.random()
        if q < 0.93:
            return r.choice([0.0, 1.0, -1.0, 0.5, 0.25, 3.0, -2.5, 100.0, 1e-3, 1e8])
        return r.choice([float('inf'), -0.0, 1e30])
    dim = r.choice([1, 2, 3, 4, 5, 6, 7, 8, 8, 9, 10, 12, 16])
    n = r.choice([0, -1, 1, 3, 5, 8, 9, 16, 33, 40])
    BOOK = rnd(c, 0x40)
    rnd(c, 0x400)
    em.w32(BOOK, dim)
    VL = rnd(c, 0x400 * 4)
    NANS = [0x7fc00001, 0x7fc00002, 0xffc00003, 0x7fc00010, 0xffc00001]

    def arr(nv):
        out = b''
        for _ in range(nv):
            if r.random() < 0.04:
                out += struct.pack('<I', r.choice(NANS))
            else:
                out += pk(FV())
        return out
    em.wbytes(VL, arr(0x400))
    em.w32(BOOK + 0xc, VL)
    A = rnd(c, 4 * 160)
    em.wbytes(A, arr(160))
    B = rnd(c, 0x20)
    seq = [r.randrange(0, 16) for _ in range(80)]
    if r.random() < 0.3:
        seq[r.randrange(0, 4)] = -1
    if r.random() < 0.15:
        seq[r.randrange(0, 4)] = r.choice([-2, -3, -5])
    if r.random() < 0.05:
        seq[0] = r.choice([0x7fffffff, 0x10000000, 0x20000001]) if False else 15

    def ent(emu, k):
        return seq[k] & 0xffffffff
    hook_rec(c, 0x405f20, 2, ret=ent, pop=0, side=lambda emu, k: emu.calllog.append(('dec', emu.arg32(0) - BOOK, emu.arg32(1) - B)))
    return [BOOK, A, B, n]


S(0x406090, 'GUESS FUN_406090', 'cdecl', None, ret='eax', gen=g406090, note='batch246006')
