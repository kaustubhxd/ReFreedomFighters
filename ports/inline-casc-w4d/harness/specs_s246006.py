"""specs_s246006.py - w4d batch 246006: 0x58b780."""
import pe_emu
from pilot import S
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
    FV = lambda: r.choice(vals[:-1]) if r.random() < 0.97 else vals[-1]
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
