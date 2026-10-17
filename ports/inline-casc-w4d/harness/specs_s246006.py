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
    if r.random() < 0.7:
        pre = r.choice([[], [0x61], [0x61], [0x61, 0x20], [0x61, 0x61], [0x78, 0x6d, 0x6c, 0x20]])
        suf = r.choice([[], [], [0xc2, 0x80], [0xc2], [0xe0, 0x80, 0x80], [0xe0, 0x80, 0x80], [0xe0, 0x80, 0x80], [0xe0, 0x80], [0xf0, 0x80, 0x80, 0x80], [0xf0, 0x80, 0x80], [0xc2, 0x80, 0xe0, 0x80], [0xe0, 0x80, 0x80, 0xf0, 0x80, 0x80],
                        [0xc2, 0x80, 0xc2, 0x80, 0x3f, 0x3e], [0xf0, 0x80, 0x80, 0x80, 0xe0, 0x80], [0xc2, 0x80, 0x3f, 0x3e], [0xe0, 0x80, 0x80, 0x3f, 0x3e], [0xf0, 0x80, 0x80, 0x80, 0x3f, 0x3e]])
        s_ = pre + suf
    BUF = em.alloc(0x80, 4)
    em.wbytes(BUF, bytes(s_) + bytes(r.getrandbits(8) for _ in range(8)))
    OUT = em.alloc(0x10, 4)
    em.w32(OUT, r.getrandbits(32))
    return [ENC, BUF, BUF + len(s_), OUT]


S(0x62bb10, 'GUESS FUN_62bb10', 'cdecl', None, ret='eax', gen=g62bb10, note='batch246006')
