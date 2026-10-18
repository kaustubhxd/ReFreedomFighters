"""specs_s252021.py - hand specs (Sonnet-w4f): 0x60f1f0 span map logger."""
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g60f1f0(c):
    clear_hooks(c); seh_chain(c, c.rng.choice([0, 1, 2])); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    sr = [seh_record(c, 2) for _ in range(10)]
    cs = lambda emu, a: bytes(emu.rbytes(a, 0x41)).split(bytes(1))[0]
    G = rnd(c, 0x2000); VG = rnd(c, 0x400); em.w32(G, VG); em.w32(0x70039c, G)
    E2 = rnd(c, 0x100); em.w32(G + 0x1aa3, E2); em.wbytes(E2 + 0x76, bytes([r.choice([0, 1, 1, 1, 1])]))
    R = rnd(c, 0x40); VR = rnd(c, 0x400); em.w32(R, VR)
    em.w32(VG + 0x190, pystub(c, 0, this=True, ret=R, side=lambda emu, k: (emu.calllog.append(('g190',)), sr[0](emu, k))))
    VL = rnd(c, 0x200)
    d = r.choice([1, 2, 3, 5])
    recs = []
    for _ in range(r.choice([0, 1, 2, 3, 4])):
        p = rnd(c, 0x10)
        esi = r.choice([0, 1, 3, 8, 0x10, 0x1f]); st = esi * d + r.randrange(d)
        ln = r.choice([0, 1, 2, 5, 0x10]) * d + r.randrange(d)
        em.w32(p, ln); em.w32(p + 4, st); recs.append(p)
    def log184(emu, k):
        emu.calllog.append(('r184', emu.arg32(0) == R, emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4), cs(emu, emu.arg32(5))))
        sr[1](emu, k)
    em.w32(VR + 0x184, pystub(c, 6, pop=0, nullflag=(5,), ret=R32, side=log184))
    em.w32(VL + 0x4c, pystub(c, 1, this=True if False else False, nullflag=(0,), ret=R32, side=lambda emu, k: (emu.calllog.append(('l4c', emu.r32(emu.reg('ecx')) == VL)), sr[2](emu, k))))
    em.w32(VL + 0x64, pystub(c, 1, nullflag=(0,), ret=lambda emu, k: recs[k] if k < len(recs) else 0, side=lambda emu, k: (emu.calllog.append(('l64', emu.r32(emu.reg('ecx')) == VL)), sr[3](emu, k))))
    def ctor(emu, k):
        emu.w32(emu.reg('ecx'), VL); emu.calllog.append(('ctor', emu.arg32(0), emu.arg32(1))); sr[4](emu, k)
    hook_rec(c, 0x4ccbe0, 2, ret=R32, pop=8, side=ctor)
    S3 = rnd(c, 0x40)
    hook_rec(c, 0x4ce480, 1, ret=R32, pop=4, this=True, nullflag=(0,), side=lambda emu, k: (emu.calllog.append(('assign', emu.r32(emu.arg32(0)) == VL)), sr[5](emu, k)))
    hook_rec(c, 0x4ccfe0, 0, ret=R32, pop=0, side=lambda emu, k: (emu.calllog.append(('dtor', emu.r32(emu.reg('ecx')) == VL)), sr[6](emu, k)))
    return [r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), S3, d << 6 | r.choice([0, 1, 5, 63])]


S(0x60f1f0, 'GUESS hand port 0x60f1f0', 'stdcall', None, ret=None, gen=g60f1f0, note='batch252021')


def g53ca50(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<I', struct.pack('<f', v))[0]
    C = rnd(c, 0x1300)
    T1 = rnd(c, 0x80); T2 = rnd(c, 0x400); FP = rnd(c, 0xa4 * 8); MT = rnd(c, 0x100)
    em.w32(C + 0x1201, T1); em.w32(C + 0x1205, T2); em.w32(C + 0x11f9, FP); em.w32(C + 0x11fd, MT)
    pos = 0; entries = []
    for q in range(7):
        if q == 0: keys = [0, 1, 2, 3, 4, 5]
        elif q == 1: keys = [0, 1, 2, 3]
        else: keys = sorted(r.sample(range(0, 6), r.choice([1, 2, 3, 4])))
        n = len(keys); em.w32(T1 + 8 * q, n); em.w32(T1 + 8 * q + 4, pos)
        for kx in keys:
            t = r.choice([0, 1, 2, 2, 3]) if r.random() < 0.9 else r.choice([0, 1])
            if q <= 1 and kx <= 1 and r.random() < 0.8: t = 2
            if q <= 1 and kx >= 2 and t in (2, 3) and r.random() < 0.9: t = r.choice([0, 1])
            if t == 2 and not (q <= 1 and kx <= 1): t = r.choice([0, 1, 3])   # type 2 only where its follow-up lookups (key >= 2) cannot reach type 2 again: no cycles
            pay = r.choice([2, 3, 4, 5]) if t == 2 else r.choice([0, 1, 2, 3, 4])
            em.w32(T2 + 4 * pos, (t << 30) | (kx << 16) | pay); pos += 1; entries.append((q, kx))
    for q in range(8): em.w32(FP + 0xa4 * q + 8, f32(r.choice([0.0, 1.0, -2.5, 0.0, float('nan'), -0.0, 3.0])))
    for q in range(8):
        em.w32(MT + 12 * q, r.choice([0, 1, 2, 3, 4])); em.w32(MT + 12 * q + 4, r.choice([0, 1, 2, 3, 4]))
    E = rnd(c, 0x40); VE = rnd(c, 0x100); em.w32(E, VE); em.w32(0x700390, E)
    Rr = rnd(c, 0x40); VR = rnd(c, 0x100); em.w32(Rr, VR)
    em.w32(VE + 0x20, pystub(c, 2, this=True, ret=Rr, side=lambda emu, k: emu.calllog.append(('e20', emu.arg32(0), emu.arg32(1)))))
    em.w32(VR + 0x2c, pystub(c, 4, pop=0, ret=R32, side=lambda emu, k: emu.calllog.append(('r2c', emu.arg32(0) == Rr, emu.arg32(1), emu.arg32(2), emu.arg32(3)))))
    em.w32(0x7003b0, em.stub_fn('hook3', lambda emu, cur: (emu.calllog.append(('hook3',)), emu.ret(eax=r.getrandbits(32), argbytes=0))))
    pr = lambda: r.choice([0, 1, 2, 3, 4, 5, 0xffffffff, 7])
    if r.random() < 0.8:
        x, kx = r.choice(entries); a, b = (x, kx) if r.random() < 0.5 else (kx, x)
    else:
        a, b = pr(), pr()
    return [C, a, b, r.choice([0, 0, 0, 1])]


S(0x53ca50, 'GUESS hand port 0x53ca50', 'thiscall', None, ret='al', gen=g53ca50, note='batch252021')


def g421240(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    dbl = lambda v: struct.pack('<d', v)
    flt = lambda v: struct.pack('<f', v)
    C = rnd(c, 0x2700); OUT = rnd(c, 0x10)
    VC = rnd(c, 0x400); em.w32(C, VC)
    em.wbytes(C + 4, dbl(r.choice([0.0, r.uniform(-500, 500), 12.5, 1e4])))
    em.wbytes(C + 0xc, dbl(r.choice([0.0, r.uniform(0, 1000), 3.25])))
    em.wbytes(C + 0x14, dbl(r.choice([0.0, r.uniform(-500, 500), 7.0])))
    em.w32(C + 0x1c, r.getrandbits(32))
    em.wbytes(C + 0x58, flt(r.choice([1.0, 0.5, 60.0, 1000.0, 3.7, -2.0, 0.0])))
    em.wbytes(C + 0x1b40, flt(r.choice([1.0, 0.25, 2.5, -1.5, 0.0])))
    em.wbytes(C + 0x1b5c, bytes([r.choice([0, 0, 1])]))
    em.wbytes(C + 0x1e90, bytes([r.choice([0, 1, 1])]))
    em.wbytes(C + 0x23c6, struct.pack('<Q', r.choice([0, r.getrandbits(40), r.getrandbits(64) & 0x7fffffffffffffff, 0xffffffff, 0x80000000, 0x100000000])))
    em.wbytes(C + 0x23ce, dbl(r.choice([0.0, 0.0, 0.2, 0.05, -0.0, 5.0])))
    em.wbytes(C + 0x25e8, bytes([r.choice([0, 0, 0, 1])]))
    NOW = r.randrange(0, 1000000)
    def clock_(emu, cur): emu.calllog.append(('clock',)); emu.ret(eax=NOW, argbytes=0)
    em.stub_import('clock', clock_)
    QV = struct.pack('<Q', r.choice([r.getrandbits(40), r.getrandbits(63), 0xffffffff, 0x100000000, 0])); qok = r.random() < 0.8
    def qpc_(emu, cur):
        emu.calllog.append(('qpc',)); emu.wbytes(emu.arg32(0), QV); emu.ret(eax=1 if qok else 0, argbytes=4)
    em.stub_import('QueryPerformanceCounter', qpc_)
    G = rnd(c, 0x400); VG = rnd(c, 0x400); em.w32(G, VG); em.w32(0x70039c, G)
    EV = r.choice([0, r.getrandbits(40), r.getrandbits(63), 0xffffffff, 0x100000000, 0x80000000])
    def s1c8(emu, cur):
        emu.calllog.append(('s1c8', emu.reg('ecx') == G, emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, (EV >> 32) & 0xffffffff); emu.ret(eax=EV & 0xffffffff, argbytes=8)
    em.w32(VG + 0x1c8, em.stub_fn('s1c8', s1c8))
    def reg1fc(emu, cur):
        p, size = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('reg', p - C, size, emu.arg32(2), emu.arg32(3), emu.arg32(4), bytes(emu.rbytes(p, size))))
        emu.ret(eax=r.getrandbits(32), argbytes=20)
    em.w32(VC + 0x1fc, em.stub_fn('reg1fc', reg1fc))
    return [C, OUT]


S(0x421240, 'GUESS hand port 0x421240', 'thiscall', None, ret='eax', gen=g421240, note='batch252021')


def g60cf30(c):
    import struct
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    flt = lambda v: struct.pack('<f', v)
    st = lambda emu: bytes(emu.rbytes(0x724b34, 1))
    C = rnd(c, 0x1500); D = rnd(c, 0x40); VD = rnd(c, 0x100); H = rnd(c, 0x40); VH = rnd(c, 0x100)
    em.w32(C + 0x1377, D); em.w32(D, VD); em.w32(C + 0xbd, H); em.w32(H, VH)
    em.wbytes(C + 0x13f1, bytes([r.choice([0, 1, 1])]))
    A = rnd(c, 0x1000); VA = rnd(c, 0x400); em.w32(A, VA); em.w32(0x70039c, A)
    fv = lambda: r.choice([0.0, 0.0, 1.5, -2.0, float('nan'), -0.0])
    em.wbytes(A + 0x9c7, flt(fv())); em.wbytes(A + 0x9c3, flt(fv()))
    EV = r.getrandbits(63)
    def s1c8(emu, cur):
        emu.calllog.append(('s1c8', emu.reg('ecx') == A, emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, (EV >> 32) & 0xffffffff); emu.ret(eax=EV & 0xffffffff, argbytes=8)
    em.w32(VA + 0x1c8, em.stub_fn('s1c8', s1c8))
    for off in (0x178, 0x17c):
        def tm(emu, cur, off=off):
            emu.calllog.append(('tm', off, emu.reg('ecx') == A, emu.arg32(0), emu.arg32(1), emu.arg32(2))); emu.ret(eax=r.getrandbits(32), argbytes=12)
        em.w32(VA + off, em.stub_fn('tm%x' % off, tm))
    B = rnd(c, 0x40); VB = rnd(c, 0x100); em.w32(B, VB); em.w32(0x700390, B)
    Rr = rnd(c, 0x40); VR = rnd(c, 0x100); em.w32(Rr, VR)
    em.w32(VB + 0x20, pystub(c, 2, this=True, ret=Rr, side=lambda emu, k: emu.calllog.append(('b20', emu.arg32(0), emu.arg32(1), st(emu)))))
    em.w32(VR + 0x2c, pystub(c, 2, pop=0, ret=R32, side=lambda emu, k: emu.calllog.append(('r2c', emu.arg32(0) == Rr, emu.arg32(1), st(emu)))))
    def d3c(emu, cur):
        emu.calllog.append(('d3c', emu.arg32(0) == D, emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4)))
        emu.ret(eax=r.choice([0x88760868, 0x88760868, 0, 0x88760869, 1]), argbytes=20)
    em.w32(VD + 0x3c, em.stub_fn('d3c', d3c))
    def dc(emu, cur):
        emu.calllog.append(('dc', emu.arg32(0) == D)); emu.ret(eax=r.choice([0x88760869, 0x88760869, 0, 5]), argbytes=4)
    em.w32(VD + 0xc, em.stub_fn('dc', dc))
    def d38(emu, cur):
        emu.calllog.append(('d38', emu.arg32(0) == D, emu.arg32(1) - C)); emu.ret(eax=r.choice([0, 0, 1, 0x80004005]), argbytes=8)
    em.w32(VD + 0x38, em.stub_fn('d38', d38))
    em.w32(VH + 0x64, pystub(c, 0, this=True, ret=R32, side=lambda emu, k: emu.calllog.append(('h64', st(emu)))))
    hook_rec(c, 0x60d610, 0, ret=R32, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h610', st(emu))))
    hook_rec(c, 0x608330, 0, ret=R32, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h330', st(emu))))
    return [C]


S(0x60cf30, 'GUESS hand port 0x60cf30', 'thiscall', None, ret=None, gen=g60cf30, note='batch252021')


def g4261c0(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    D = rnd(c, 0x1000)
    A = rnd(c, 0x100)
    for q in range(32):
        FLP = rnd(c, 0x80)
        for k in range(16): em.wbytes(FLP + 4 * k, struct.pack('<f', r.choice([0.0, 1.5, -2.25, r.uniform(-100, 100), 1e6])))
        em.w32(A + 4 * q, FLP)
    pieces = [b'abc', b' ', b'x=', b'%%', b'%d', b'%s', b'%5.2f', b'%f', b'%-3d', b'%v', b'%2v', b'%3v', b'%2.3v', b'%.2v', b'%3.v', b'%.v', b'%v', b'%12v', b'%2.2v', b'%', b'%.', b'%..v']
    fm = b''.join(r.choice(pieces) for _ in range(r.choice([0, 1, 2, 3, 4, 5])))
    FM = rnd(c, 0x100); em.wbytes(FM, fm + bytes(1))
    cs = lambda emu, a: bytes(emu.rbytes(a, 0x100)).split(bytes(1))[0]
    def h42abee(emu, k):
        dest, fmt_, args = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        text = b'<' + cs(emu, fmt_) + b'@' + str((args - A) // 4).encode() + b'>'
        emu.wbytes(dest, text + bytes(1)); emu.calllog.append(('vsprintf', dest - D, cs(emu, fmt_), (args - A) // 4))
        h42abee.n = len(text)
    hook_rec(c, 0x42abee, 3, ret=lambda emu, k: h42abee.n, pop=0, nullflag=(1,), side=h42abee)
    def h42ac56(emu, k):
        dest = emu.arg32(0); v = struct.unpack('<d', struct.pack('<II', emu.arg32(2), emu.arg32(3)))[0]
        text = ('%8.3f' % v).encode(); emu.wbytes(dest, text + bytes(1)); emu.calllog.append(('sprintf', dest - D, emu.arg32(1), text))
        h42ac56.n = len(text)
    hook_rec(c, 0x42ac56, 4, ret=lambda emu, k: h42ac56.n, pop=0, side=h42ac56)
    def memcpy_(emu, cur):
        d, s_, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        data = bytes(emu.rbytes(s_, n)); emu.calllog.append(('memcpy', n, data)); emu.wbytes(d, data); emu.ret(eax=d, argbytes=0)
    em.stub_import('memcpy', memcpy_)
    return [D, FM, A]


S(0x4261c0, 'GUESS hand port 0x4261c0', 'stdcall', None, ret='eax', gen=g4261c0, note='batch252021')


def g61aed0(c):
    clear_hooks(c); r = c.rng; em = c.emu
    count = r.choice([1, 2, 3, 4, 5, 8, 13, 16])
    SRC = rnd(c, 0x90 * 5 + 0x40)
    flags = r.choice([0x2000, 0, 0x2001, 0x1fff, 0xffffffff, 0x2000, 0])
    for q in range(5):
        em.wbytes(SRC + 0x90 * q + 0x18, bytes(r.getrandbits(8) for _ in range(4)))
        for j in range(4): em.wbytes(SRC + 0x90 * q + 0x24 * j + 0x18, bytes(r.getrandbits(8) for _ in range(4)))
    def memset_(emu, cur):
        d, v, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('memset', d, v, n)); emu.wbytes(d, bytes([v & 0xff]) * n); emu.ret(eax=d, argbytes=0)
    em.stub_import('memset', memset_)
    return [SRC, count, flags]


S(0x61aed0, 'GUESS hand port 0x61aed0', 'stdcall', None, ret=None, gen=g61aed0, note='batch252021')


def g661370(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    B = rnd(c, 0x2000)
    A = rnd(c, 0x100); EN = rnd(c, 0x200)
    em.w32(0x70039c, EN); em.w32(EN + 0x1aa3, A); em.w32(A + 0x20, B)
    NV = 12
    vs = []
    for k in range(NV):
        vs += [r.uniform(-1.2, 1.2), r.uniform(-1.2, 1.2), r.uniform(-0.6, 0.6)] + [r.uniform(-1, 1) for _ in range(6)]
    em.wbytes(B + 0x1000, struct.pack('<%df' % (9 * NV), *vs))
    nn = r.choice([0, 1, 2, 3])
    mask = r.choice([1, 2, 4, 0x10, 0x80000000, 3])
    offs = [0x40 + 0x80 * q for q in range(3)]
    for q in range(3):
        nd = B + offs[q]
        em.w32(nd + 8, offs[q + 1] if q + 1 < nn else 0)
        em.w32(nd + 0x2c, mask & r.choice([0xffffffff, 0xffffffff, 0, mask]) if r.random() < 0.8 else r.choice([0, 8]))
        em.w32(nd + 0x14, 0x1000)
        ioff = 0x400 + 0x100 * q; em.w32(nd + 0x3c, ioff)
        ns = r.choice([0, 1, 2, 3]); data = struct.pack('<H', ns)
        for _ in range(ns):
            n = r.choice([2, 3, 4, 5, 6, 8])
            data += struct.pack('<H', n) + struct.pack('<%dH' % n, *[r.randrange(NV) for _ in range(n)])
        em.wbytes(B + ioff, data)
    HR = rnd(c, 0x80)
    em.wbytes(HR, struct.pack('<f', r.choice([100.0, 1e9, 0.9, 0.5, r.uniform(0.1, 3.0), 1.0])))
    O = rnd(c, 0x10); D = rnd(c, 0x10)
    em.wbytes(O, struct.pack('<3f', r.uniform(-0.5, 0.5), r.uniform(-0.5, 0.5), -1.0))
    em.wbytes(D, struct.pack('<3f', r.uniform(-0.3, 0.3), r.uniform(-0.3, 0.3), r.choice([2.0, 1.0, 0.7, 0.45])))
    first = offs[0] if nn else 0
    if r.random() < 0.4:   # engineered ray / triangle: two nodes see the same triangle (equal t twice: strict `>` matters), plane through the origin (t == 0) or t > 1
        z0 = r.choice([0.0, 0.0, -1.0, 0.4, 1.0])
        tri = [(-1.0, -1.0, z0), (1.0, -1.0, z0), (0.0, 2.0, z0)]
        if r.random() < 0.5: tri = [tri[0], tri[2], tri[1]]
        em.wbytes(B + 0x1000, struct.pack('<27f', *[v for tv in tri for v in tv], *([0.0] * 18)))
        for q, strip in ((0, [0, 1, 2]), (1, [3, 4, 0, 1, 2])):
            nd = B + offs[q]; em.w32(nd + 8, offs[1] if q == 0 else 0); em.w32(nd + 0x2c, mask)
            em.wbytes(B + 0x400 + 0x100 * q, struct.pack('<HH', 1, len(strip)) + struct.pack('<%dH' % len(strip), *strip))
        em.wbytes(O, struct.pack('<3f', 0.0, 0.0, -1.0)); em.wbytes(D, struct.pack('<3f', 0.0, 0.0, r.choice([2.0, 1.0, 0.7])))
        em.wbytes(HR, struct.pack('<f', r.choice([100.0, 1e9, 5.0])))
        first = offs[0]
    if nn and r.random() < 0.2:   # a leading node at offset 1 (chains to the real first node) so `off != 0` cannot be weakened to `off > 1`
        nd = B + 1
        em.w32(nd + 8, offs[0]); em.w32(nd + 0x2c, 0); em.w32(nd + 0x14, 0x1000); em.w32(nd + 0x3c, 0x400)
        first = 1
    return [HR, first, O, D, r.choice([0, 1]), mask]


S(0x661370, 'GUESS hand port 0x661370', 'stdcall', None, ret='al', gen=g661370, note='batch252021')


def g4235b0(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    cs = lambda emu, a: bytes(emu.rbytes(a, 0x100)).split(bytes(1))[0]
    C = rnd(c, 0x2700); OUT = rnd(c, 0x100)
    a1 = r.choice([0, 1, 4, 0x10, 0x20]); a2 = r.choice([0, 1, 2, 3])
    NAME = rnd(c, 0x40); name = r.choice([b'models\\hero.tex', b'a', b'ABCDEFGHIJKLMNOPQRSTUVWXYZ', b'', b'x\\y'])
    em.wbytes(NAME, name + bytes(1))
    tail = name[-15:] if len(name) > 15 else name
    text = (tail if r.random() < 0.6 else tail.swapcase() if r.random() < 0.5 else b'zzz')[:15]
    idv = a2 if r.random() < 0.8 else r.getrandbits(8); szv = a1 if r.random() < 0.85 else a1 + 1
    plain = struct.pack('<II', idv, szv) + text.ljust(16, b'\0') + bytes(4) + bytes(r.getrandbits(8) for _ in range(a1))
    rle = struct.pack('<H', (-len(plain)) & 0xffff) + plain
    chunk = struct.pack('<I', len(rle)) + rle
    stream = chunk * 3
    FILE = rnd(c, 0x40); CH = rnd(c, 0x40); em.wbytes(CH, r.choice([b'data\\res.pak', b'x', b'']) + bytes(1))
    em.w32(C + 0x255b, CH)
    BUFP = rnd(c, 0x800); em.wbytes(BUFP, stream)
    ST = r.choice(['fresh', 'fresh', 'cont', 'cont', 'end', 'zero'])
    em.wbytes(C + 0x1b3f, bytes([1 if r.random() < 0.08 else 0]))
    if ST in ('cont', 'end'):
        em.w32(C + 0x25dc, BUFP); em.w32(C + 0x25e4, len(stream))
        em.w32(C + 0x25e0, BUFP + (len(chunk) * r.choice([0, 1, 2]) if ST == 'cont' else len(stream)))
    else:
        em.w32(C + 0x25dc, 0); em.w32(C + 0x25e0, 0); em.w32(C + 0x25e4, 0)
    em.wbytes(C + 0x25eb, bytes(0x40))   # no random record pointers
    if r.random() < 0.4:
        ENT = rnd(c, 0x100); em.w32(C + 0x25eb + a2 * 8, ENT); em.w32(C + 0x25ef + a2 * 8, a1 + 0x1c)
        if r.random() < 0.6: em.wbytes(ENT, bytes(a1 + 0x1c))
    G = rnd(c, 0x200); VG = rnd(c, 0x200); em.w32(G, VG); em.w32(0x700394, G)
    SZ = r.choice([len(stream), len(stream), len(stream) + 5, 0, 0xffffffff])
    em.w32(VG + 0x30, pystub(c, 2, this=True, ret=SZ, side=lambda emu, k: emu.calllog.append(('g30', cs(emu, emu.arg32(0)), emu.arg32(1)))))
    def rd(emu, k):
        buf, n = emu.arg32(1), emu.arg32(2)
        emu.wbytes(buf, stream[:n]); emu.calllog.append(('g60', cs(emu, emu.arg32(0)), n, emu.arg32(3), emu.arg32(4)))
    em.w32(VG + 0x60, pystub(c, 5, this=True, ret=R32, side=rd))
    E = rnd(c, 0x40); VE = rnd(c, 0x100); em.w32(E, VE); em.w32(0x700390, E)
    Rr = rnd(c, 0x40); VR = rnd(c, 0x100); em.w32(Rr, VR)
    em.w32(VE + 0x20, pystub(c, 2, this=True, ret=Rr, side=lambda emu, k: emu.calllog.append(('e20', emu.arg32(0), emu.arg32(1)))))
    em.w32(VR + 0x2c, pystub(c, 34, pop=0, ret=R32, side=lambda emu, k: emu.calllog.append(('r2c', emu.arg32(0) == Rr, emu.arg32(1), tuple(emu.arg32(2 + q) for q in range(32))))))
    POOL = [rnd(c, 0x800) for _ in range(8)]
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: POOL[k % 8], pop=0, side=lambda emu, k: emu.calllog.append(('alloc', emu.arg32(0))))
    hook_rec(c, 0x634273, 2, ret=R32, pop=0, side=lambda emu, k: emu.calllog.append(('free', emu.arg32(0) in POOL, emu.arg32(1))))
    def memset_(emu, cur):
        d, v, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('memset', d in POOL, v, n)); emu.wbytes(d, bytes([v & 0xff]) * n); emu.ret(eax=d, argbytes=0)
    em.stub_import('memset', memset_)
    def memcpy_(emu, cur):
        d, s_, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        data = bytes(emu.rbytes(s_, n)); emu.calllog.append(('memcpy', n, data)); emu.wbytes(d, data); emu.ret(eax=d, argbytes=0)
    em.stub_import('memcpy', memcpy_)
    def stricmp_(emu, cur):
        a = cs(emu, emu.arg32(0)).lower(); b = cs(emu, emu.arg32(1)).lower()
        emu.calllog.append(('stricmp', a, b)); emu.ret(eax=(a > b) - (a < b) & 0xffffffff, argbytes=0)
    em.stub_import('_stricmp', stricmp_)
    return [C, OUT, a1, a2, NAME, r.getrandbits(32)]


S(0x4235b0, 'GUESS hand port 0x4235b0', 'thiscall', None, ret='eax', gen=g4235b0, note='batch252021')


def g612e70(c):
    clear_hooks(c); seh_chain(c, c.rng.choice([0, 1, 2])); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    sr = [seh_record(c, 2) for _ in range(14)]
    cs = lambda emu, a: bytes(emu.rbytes(a, 0x40)).split(bytes(1))[0]
    C = rnd(c, 0x22300)
    names = [b'png', b'bmp', b'tga', b'jpg', b'dds', b'RGBA', b'Rgba', b'a', b'']
    TAB = C + 0x2203c; NS = []
    for q in range(19):
        s_ = rnd(c, 0x20); nm = r.choice(names) + (b'%d' % q if r.random() < 0.7 else b''); em.wbytes(s_, nm + bytes(1)); NS.append(nm)
        em.w32(TAB + 16 * q, s_); em.w32(TAB + 16 * q + 4, r.getrandbits(32)); em.w32(TAB + 16 * q + 8, r.randrange(0, 5)); em.w32(TAB + 16 * q + 12, r.randrange(0, 5))
    I = rnd(c, 0x40); VI = rnd(c, 0x100); em.w32(I, VI)
    NM = rnd(c, 0x20)
    em.wbytes(NM, (r.choice(NS) if r.random() < 0.7 else r.choice([b'zzz', b'png', b'PNG0'])) + bytes(1))
    W, H = r.choice([0, 1, 2, 3, 4]), r.choice([0, 1, 2, 3])
    em.w32(VI + 4, pystub(c, 0, this=True, ret=NM, side=lambda emu, k: (emu.calllog.append(('i4', cs(emu, emu.arg32(0)) if False else 0)), sr[0](emu, k))))
    em.w32(VI + 0x1c, pystub(c, 0, this=True, ret=W, side=lambda emu, k: (emu.calllog.append(('i1c',)), sr[1](emu, k))))
    em.w32(VI + 0x20, pystub(c, 0, this=True, ret=H, side=lambda emu, k: (emu.calllog.append(('i20',)), sr[2](emu, k))))
    em.w32(VI + 0x50, pystub(c, 0, this=True, ret=R32, side=lambda emu, k: (emu.calllog.append(('i50',)), sr[3](emu, k))))
    em.w32(VI + 0x48, pystub(c, 0, this=True, ret=R32, side=lambda emu, k: (emu.calllog.append(('i48',)), sr[4](emu, k))))
    em.wbytes(0x724b70, struct.pack('<I', r.choice([0, 0, 0x55])) if False else bytes([0, 0, 0, 0]) if r.random() < 0.5 else bytes([0x55, 0, 0, 0]))
    POOL = [rnd(c, 0x200) for _ in range(4)]
    CT = r.getrandbits(32)
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: POOL[k % 4], pop=0, side=lambda emu, k: (emu.calllog.append(('alloc', emu.arg32(0))), sr[5](emu, k)))
    hook_rec(c, 0x41e2c0, 1, ret=0, pop=0, side=lambda emu, k: (emu.calllog.append(('free', emu.arg32(0) in POOL, bytes(emu.rbytes(emu.arg32(0), 16)) if emu.arg32(0) in POOL else b'')), sr[6](emu, k)))
    hook_rec(c, 0x634cec, 3, ret=R32, pop=12, side=lambda emu, k: (emu.calllog.append(('init', emu.arg32(0), emu.arg32(1), emu.arg32(2))), emu.w32(emu.arg32(0), 0x1234), sr[7](emu, k)))
    def h4cfe(emu, k):
        emu.w32(emu.arg32(1), CT); emu.calllog.append(('ctx', emu.arg32(0))); sr[8](emu, k)
    hook_rec(c, 0x634cfe, 2, ret=R32, pop=8, nullflag=(1,), side=h4cfe)
    def h4d04(emu, k):
        x, y = emu.arg32(1), emu.arg32(2)
        emu.w32(emu.arg32(3), (x * 0x10001 + y * 0x101 + 0xff000000) & 0xffffffff); emu.calllog.append(('px', emu.arg32(0) == CT, x, y)); sr[9](emu, k)
    hook_rec(c, 0x634d04, 4, ret=lambda emu, k: 1 if (k % 7) == 3 else 0, pop=16, nullflag=(3,), side=h4d04)
    hook_rec(c, 0x634cf8, 1, ret=R32, pop=4, side=lambda emu, k: (emu.calllog.append(('rel', emu.arg32(0) == CT)), sr[10](emu, k)))
    def lf(emu, p):
        return (emu.r32(p + 0x1c), emu.r32(p + 0x20))
    def h30c0(emu, k):
        a = emu.arg32(0)
        isheap = 0x20000000 <= a < 0x30000000
        emu.calllog.append(('h30c0', a if isheap else 'S', emu.arg32(1), lf(emu, a) if not isheap else 0)); sr[11](emu, k)
    hook_rec(c, 0x6130c0, 2, ret=R32, pop=8, this=True, nullflag=(0,), side=h30c0)
    hook_rec(c, 0x636020, 8, ret=R32, pop=0x20, side=lambda emu, k: (emu.calllog.append(('ctor', emu.arg32(0) in POOL, emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4), emu.arg32(5), emu.arg32(6), emu.arg32(7))), sr[12](emu, k)))
    hook_rec(c, 0x639d00, 1, ret=R32, pop=4, side=lambda emu, k: (emu.calllog.append(('setname', cs(emu, emu.arg32(0)))), sr[13](emu, k)))
    hook_rec(c, 0x6363a0, 0, ret=R32, pop=0, side=lambda emu, k: emu.calllog.append(('dtor', lf(emu, emu.reg('ecx')))))
    return [C, I, r.getrandbits(32)]


S(0x612e70, 'GUESS hand port 0x612e70', 'thiscall', None, ret='eax', gen=g612e70, note='batch252021')


def g424130(c):
    clear_hooks(c); seh_chain(c, c.rng.choice([0, 1, 2])); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    sr = [seh_record(c, 2) for _ in range(16)]
    cs = lambda emu, a: bytes(emu.rbytes(a, 0x40)).split(bytes(1))[0]
    nsl = [0]
    def mkslot(vt, off, nargs, ret=0, pop=None, nullflag=(), extra=None):
        i = nsl[0]; nsl[0] += 1
        def side(emu, k):
            emu.calllog.append(('slot%x' % off, emu.reg('ecx') if False else 0, tuple(emu.arg32(q) for q in range(nargs) if q not in nullflag)))
            if extra: extra(emu, k)
            sr[i % 16](emu, k)
        em.w32(vt + off, pystub(c, nargs, this=True, ret=ret, pop=pop, nullflag=nullflag, side=side))
    def mkobj(slots):
        o = rnd(c, 0x40); vt = rnd(c, 0x300); em.w32(o, vt)
        for off, spec in slots.items(): mkslot(vt, off, *spec)
        return o
    C = rnd(c, 0x2800); VT = rnd(c, 0x300); em.w32(C, VT)
    CH = [rnd(c, 0x40) for _ in range(4)]
    exe_str = bytes(em.rbytes(0x677f44, 0x20)).split(bytes(1))[0]
    em.wbytes(CH[0], b'level1.dat\0'); em.wbytes(CH[1], b'log.txt\0'); em.wbytes(CH[2], b'name\0')
    em.wbytes(CH[3], r.choice([exe_str, exe_str.upper(), b'', b'other']) + bytes(1))
    for off, ch in ((0x1997, CH[0]), (0x2242, CH[1]), (0x2a3, CH[2]), (0x1e91, CH[3])): em.w32(C + off, ch)
    em.wbytes(C + 0x25e9, bytes([r.choice([0, 1, 1])]))
    em.w32(C + 0x6f, r.choice([0, 1, 5, 100, 0xffffffff])); em.w32(C + 0x73, r.choice([0, 1, 5, 100, 3]))
    O = mkobj({0xd8: (1,)})
    mkslot(VT, 0x6c, 1, ret=lambda emu, k: r.choice([1, 1, 0, 0x100, 0x1ff]))
    mkslot(VT, 0x58, 0); mkslot(VT, 0x16c, 0); mkslot(VT, 0x170, 0); mkslot(VT, 0xc0, 0)
    mkslot(VT, 0xbc, 0, ret=O); mkslot(VT, 0x148, 2, nullflag=(0,), ret=R32)
    em.w32(C + 0x1aa3, r.choice([0, mkobj({0xc: (0,)})]))
    em.w32(C + 0x223d, 0); em.w32(C + 0x1a9f, 0xdead)
    A5 = mkobj({0x11c: (0,)}); em.w32(C + 0x9b, A5)
    em.w32(0x7003a0, r.choice([0, mkobj({0xc: (0,)})]))
    G = rnd(c, 0x2000); em.w32(0x70039c, G)
    A6 = r.choice([0, mkobj({0x23c: (0,)})]); em.w32(G + 0x190f, A6)
    GP = mkobj({0x18: (1,), 0x68: (3, 0, None, (1,))}); em.w32(0x700394, GP)
    E = mkobj({0x24: (2,)}); VE = G and 0
    Eo = rnd(c, 0x40); VEo = rnd(c, 0x200); em.w32(Eo, VEo); em.w32(0x700390, Eo)
    Rr = rnd(c, 0x40); VR = rnd(c, 0x100); em.w32(Rr, VR)
    em.w32(VEo + 0x20, pystub(c, 2, this=True, ret=Rr, side=lambda emu, k: emu.calllog.append(('e20', emu.arg32(0), emu.arg32(1)))))
    em.w32(VEo + 0x24, pystub(c, 2, pop=0, ret=R32, side=lambda emu, k: (emu.calllog.append(('e24', emu.arg32(0) == Eo, emu.arg32(1), cs(emu, emu.arg32(2)) if emu.arg32(1) == 0x678154 else b'')), sr[13](emu, k))))
    em.w32(VR + 0x2c, pystub(c, 2, pop=0, ret=R32, side=lambda emu, k: emu.calllog.append(('r2c', emu.arg32(0) == Rr, emu.arg32(1), tuple(emu.arg32(2 + q) for q in range(32)) if emu.arg32(1) == 0x6780c4 else ()))))
    POOL = [rnd(c, 0x100) for _ in range(2)]
    O1 = r.choice([0, mkobj({0xc: (0,)})]); O2 = r.choice([0, mkobj({0xc: (0,)})]); O3 = r.choice([0, mkobj({0xc: (0,)})])
    hook_rec(c, 0x48a440, 0, ret=O1, pop=0, side=lambda emu, k: (emu.calllog.append(('h48a',)), sr[14](emu, k)))
    hook_rec(c, 0x607c20, 0, ret=O2, pop=0, side=lambda emu, k: (emu.calllog.append(('h607',)), sr[15](emu, k)))
    hook_rec(c, 0x5328b0, 0, ret=O3, pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('h532', emu.reg('ecx') in POOL)), sr[0](emu, k)))
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: POOL[k % 2], pop=0, side=lambda emu, k: (emu.calllog.append(('alloc', emu.arg32(0))), sr[1](emu, k)))
    hook_rec(c, 0x4cbee0, 1, ret=R32, pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('s_assign', emu.reg('ecx') == C + 0x2a3)), sr[2](emu, k)))
    hook_rec(c, 0x4cbec0, 0, ret=R32, pop=0, side=lambda emu, k: (emu.calllog.append(('s_dtor',)), sr[3](emu, k)))
    def h42ac56(emu, k):
        dest = emu.arg32(0); text = b'<' + cs(emu, emu.arg32(1)) + b'|' + (b'%x' % emu.arg32(2)) + b'>'
        emu.wbytes(dest, text + bytes(1)); emu.calllog.append(('sprintf', text)); h42ac56.n = len(text)
    hook_rec(c, 0x42ac56, 3, ret=lambda emu, k: h42ac56.n, pop=0, nullflag=(0,), side=h42ac56)
    TS = rnd(c, 0x40); em.wbytes(TS, b'Sun Oct 18 12:00:00 2026\n\0')
    TV = r.getrandbits(32)
    def time_(emu, cur): emu.calllog.append(('time',)); emu.w32(emu.arg32(0), TV); emu.ret(eax=TV, argbytes=0)
    em.stub_import('_time32', time_)
    def ctime_(emu, cur): emu.calllog.append(('ctime', emu.r32(emu.arg32(0)))); emu.ret(eax=TS, argbytes=0)
    em.stub_import('_ctime32', ctime_)
    def stricmp_(emu, cur):
        a = cs(emu, emu.arg32(0)).lower(); b = cs(emu, emu.arg32(1)).lower()
        emu.calllog.append(('stricmp', a, b)); emu.ret(eax=((a > b) - (a < b)) & 0xffffffff, argbytes=0)
    em.stub_import('_stricmp', stricmp_)
    return [C]


S(0x424130, 'GUESS hand port 0x424130', 'thiscall', None, ret='al', gen=g424130, note='batch252021')


def g64a410(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    ff = lambda: struct.pack('<f', r.choice([r.uniform(-3, 3), r.uniform(-50, 50), 0.0, 1.0]))
    C = rnd(c, 0x18300); VT = rnd(c, 0x200); em.w32(C, VT)
    for off in (0x1821d, 0x181f9): em.wbytes(C + off, b''.join(ff() for _ in range(12)))
    NS = r.choice([1, 2, 3]); X = []; SEC = []; ROOM = []
    for k in range(NS):
        X.append(rnd(c, 0x200)); SEC.append(rnd(c, 0x80)); ROOM.append(rnd(c, 0x80))
    TERM = rnd(c, 0x80)
    chain = [rnd(c, 0x80) for _ in range(r.choice([0, 1, 2, 3]))]
    for k in range(NS):
        em.w32(SEC[k] + 0x3c, X[k]); em.wbytes(SEC[k] + 8, b''.join(ff() for _ in range(12))); em.wbytes(SEC[k] + 0x2c, b''.join(ff() for _ in range(3)))
        em.w32(ROOM[k] + 8, SEC[k]); em.w32(ROOM[k] + 0x14, TERM if k == 0 else rnd(c, 0x40))
        cnt = r.choice([0, 1, 2, 3]); ENT = rnd(c, 0x34 * 4 + 8)
        em.w32(X[k] + 0x8c, cnt); em.w32(X[k] + 0x90, ENT)
        em.wbytes(X[k] + 0x87, bytes([r.choice([0, 0, 0, 1])]))
        em.w32(X[k] + 0x88, r.choice([0, 0, ROOM[(k + 1) % NS]]) if r.random() < 0.5 else 0)
        for q in range(cnt): em.w32(ENT + 0x34 * q + 0x30, X[r.randrange(NS)])
    # top-level chain: ROOM[0][0x14] -> chain[0] -> chain[1] ... -> TERM  (a1 = TERM); sometimes ROOM[0][0x14] == TERM (no chain)
    if chain:
        em.w32(ROOM[0] + 0x14, chain[0])
        for q, nd in enumerate(chain): em.w32(nd + 0x30, chain[q + 1] if q + 1 < len(chain) else TERM)
    em.w32(TERM + 0x30, 0)
    DST = [rnd(c, 0x40) for _ in range(4)]
    cs = lambda emu, a, n: bytes(emu.rbytes(a, n))
    def s64(emu, k):
        emu.wbytes(emu.arg32(0), ff() * 0 + b''.join(ff() for _ in range(3)))
        emu.wbytes(emu.arg32(1), b''.join(ff() for _ in range(12)))
        emu.calllog.append(('s64', cs(emu, emu.arg32(2), 0x30), cs(emu, emu.arg32(3), 12), emu.arg32(4) - X[0] if False else emu.arg32(4)))
    em.w32(VT + 0x64, pystub(c, 5, this=True, nullflag=(0, 1, 2, 3), ret=lambda emu, k: r.choice([1, 1, 0, 0x100, 1]), side=s64))
    def s68(emu, k):
        emu.wbytes(emu.arg32(0), b''.join(ff() for _ in range(12)))
        emu.calllog.append(('s68', cs(emu, emu.arg32(1), 0x30), emu.arg32(2)))
    em.w32(VT + 0x68, pystub(c, 3, this=True, nullflag=(0, 1), ret=lambda emu, k: r.choice([1, 1, 0]), side=s68))
    def s14(emu, k):
        o = emu.arg32(0); emu.calllog.append(('s14', o, emu.arg32(1)))
    em.w32(VT + 0x14, pystub(c, 2, this=True, ret=lambda emu, k: ROOM[k % NS], side=s14))
    em.w32(VT + 0x18, pystub(c, 1, this=True, ret=lambda emu, k: DST[k % 4], side=lambda emu, k: emu.calllog.append(('s18', emu.arg32(0)))))
    return [C, ROOM[0], TERM, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.choice([0, 1])]


S(0x64a410, 'GUESS hand spec 0x64a410', 'thiscall', None, ret='eax', gen=g64a410, note='batch252021')


def g612a20(c):
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    C = rnd(c, 0x22100); I = rnd(c, 0x40); VI = rnd(c, 0x100); em.w32(I, VI)
    D = rnd(c, 0x40); VD = rnd(c, 0x100); S_ = rnd(c, 0x40); VS = rnd(c, 0x100)
    G = rnd(c, 0x200); em.w32(0x70039c, G); em.w32(G + 0x93, r.choice([0, 1, 2, 3, 0x7fffffff]))
    em.w32(C + 0x22030, r.choice([0x3e, 0x3e, 0x15, 0x1a, 0x32])); em.w32(C + 0x22004, D); em.w32(D, VD); em.w32(S_, VS)
    W, H = r.choice([1, 2, 3, 4, 8]), r.choice([1, 2, 4, 5])
    N = r.choice([1, 2, 3, 4])
    IW, IH = r.choice([1, 2, 4, 8]), r.choice([1, 2, 3, 8])
    recs = [rnd(c, 0x10) for _ in range(8)]
    for q in range(8): em.w32(recs[q] + 4, max(1, W >> q)); em.w32(recs[q] + 8, max(1, H >> q))
    em.w32(VI + 0x34, pystub(c, 0, this=True, ret=N, side=lambda emu, k: emu.calllog.append(('i34',))))
    em.w32(VI + 0x38, pystub(c, 1, this=True, ret=lambda emu, k: recs[min(emu.arg32(0), 7)], side=lambda emu, k: emu.calllog.append(('i38', emu.arg32(0)))))
    em.w32(VI + 0x20, pystub(c, 0, this=True, ret=IH, side=lambda emu, k: emu.calllog.append(('i20',))))
    em.w32(VI + 0x1c, pystub(c, 0, this=True, ret=IW, side=lambda emu, k: emu.calllog.append(('i1c',))))
    cs = lambda emu, a, n: bytes(emu.rbytes(a, n))
    def i14(emu, k):
        p = emu.arg32(0)
        emu.calllog.append(('i14', tuple(emu.r32(p + 4 * q) & (0xff if q == 12 else 0xffffffff) for q in range(13)), emu.arg32(1)))
    em.w32(VI + 0x14, pystub(c, 2, this=True, nullflag=(0,), ret=R32, side=i14))
    def mk(emu, k):
        emu.w32(emu.arg32(7), S_); emu.calllog.append(('d50', emu.arg32(0) == D, emu.arg32(1), emu.arg32(2), emu.arg32(3), emu.arg32(4), emu.arg32(5), emu.arg32(6)))
    em.w32(VD + 0x50, pystub(c, 8, nullflag=(7,), ret=R32, side=mk))
    BITS = rnd(c, 0x400); PITCH = r.choice([4, 16, 32, 64])
    def s40(emu, k):
        o = emu.arg32(2); emu.w32(o, PITCH); emu.w32(o + 4, BITS)
        emu.calllog.append(('s40', emu.arg32(0) == S_, emu.reg('ecx') == S_, emu.arg32(1), emu.arg32(3), emu.arg32(4)))
    em.w32(VS + 0x40, pystub(c, 5, this=True, nullflag=(2,), ret=R32, side=s40))
    em.w32(VS + 0x44, pystub(c, 2, ret=R32, side=lambda emu, k: emu.calllog.append(('s44', emu.arg32(0) == S_, emu.arg32(1)))))
    POOL = [rnd(c, 0x400) for _ in range(2)]
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: POOL[k % 2], pop=0, side=lambda emu, k: emu.calllog.append(('alloc', emu.arg32(0))))
    def h3690(emu, k):
        dstb, srcb, w, h, f = emu.reg('ecx'), emu.reg('edx'), emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.wbytes(dstb, bytes(((i * 7 + f + w + h) & 0xff) for i in range(min(w * h * 4, 0x300))))
        emu.calllog.append(('h3690', dstb in POOL, srcb in POOL, w, h, f))
    hook_rec(c, 0x613690, 3, ret=R32, pop=12, side=h3690)
    hook_rec(c, 0x634273, 2, ret=R32, pop=0, side=lambda emu, k: emu.calllog.append(('free', emu.arg32(0) in POOL, emu.arg32(1))))
    def memcpy_(emu, cur):
        d, s_, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        data = bytes(emu.rbytes(s_, n)); emu.calllog.append(('memcpy', d - BITS if BITS <= d < BITS + 0x400 else d, n, data)); emu.wbytes(d, data); emu.ret(eax=d, argbytes=0)
    em.stub_import('memcpy', memcpy_)
    return [C, I]


S(0x612a20, 'GUESS hand spec 0x612a20', 'thiscall', None, ret='eax', gen=g612a20, note='batch252021')


def g6515d0(c):
    clear_hooks(c); seh_chain(c, c.rng.choice([0, 1, 2])); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    sr = [seh_record(c, 2) for _ in range(10)]
    C = rnd(c, 0x1400)
    G = rnd(c, 0x2000); VG = rnd(c, 0x400); em.w32(G, VG); em.w32(0x70039c, G)
    em.w32(G + 0x7f, r.choice([0, 0, 24, 32, 0x10])); em.wbytes(G + 0x63, bytes([r.choice([0, 1])]))
    em.w32(G + 0x87, r.getrandbits(32)); em.w32(G + 0x8b, r.getrandbits(32))
    E2 = rnd(c, 0x100); em.w32(G + 0x1aa3, E2); em.wbytes(E2 + 0x76, bytes([r.choice([0, 1])]))
    em.w32(C + 0x12f, rnd(c, 0x40))
    Eo = rnd(c, 0x40); VEo = rnd(c, 0x200); em.w32(Eo, VEo); em.w32(0x700390, Eo)
    Rr = rnd(c, 0x40); VR = rnd(c, 0x100); em.w32(Rr, VR)
    em.w32(VEo + 0x20, pystub(c, 2, this=True, ret=Rr, side=lambda emu, k: emu.calllog.append(('e20', emu.arg32(0), emu.arg32(1)))))
    em.w32(VR + 0x2c, pystub(c, 3, pop=0, ret=R32, side=lambda emu, k: emu.calllog.append(('r2c', emu.arg32(0) == Rr, emu.arg32(1), emu.arg32(2)))))
    em.w32(VG + 0x1a4, pystub(c, 1, this=True, ret=R32, side=lambda emu, k: (emu.calllog.append(('g1a4', emu.arg32(0))), sr[0](emu, k))))
    POOL = [rnd(c, 0x120) for _ in range(3)]
    OBJ = [rnd(c, 0x40) for _ in range(3)]
    hook_rec(c, 0x41e290, 1, ret=lambda emu, k: POOL[k % 3], pop=0, side=lambda emu, k: (emu.calllog.append(('alloc', emu.arg32(0))), sr[1](emu, k)))
    hook_rec(c, 0x657da0, 2, ret=R32, pop=8, this=True, side=lambda emu, k: (emu.calllog.append(('base',)), sr[2](emu, k)))
    hook_rec(c, 0x6528a0, 0, ret=R32, pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('h28a0',)), sr[3](emu, k)))
    ctor_null = [r.random() < 0.15 for _ in range(3)]
    hook_rec(c, 0x4d8330, 3, ret=lambda emu, k: 0 if ctor_null[k % 3] else OBJ[k % 3], pop=12, this=True, side=lambda emu, k: (emu.calllog.append(('ctor', emu.reg('ecx') in POOL, emu.arg32(0), emu.arg32(1), emu.arg32(2))), sr[4](emu, k)))
    def memset_(emu, cur):
        d, v, n = emu.arg32(0), emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('memset', d - C, v, n)); emu.wbytes(d, bytes([v & 0xff]) * n); emu.ret(eax=d, argbytes=0)
    em.stub_import('memset', memset_)
    HW, HDC = r.choice([0x1234, 0]), r.choice([0x5678, 0x99]); planes = r.choice([1, 1, 2]); bits = r.choice([16, 24, 32, 8 * 2])
    def gdw(emu, cur): emu.calllog.append(('gdw',)); emu.ret(eax=HW, argbytes=0)
    def gdc(emu, cur): emu.calllog.append(('gdc', emu.arg32(0))); emu.ret(eax=HDC, argbytes=4)
    def gcaps(emu, cur):
        emu.calllog.append(('caps', emu.arg32(0), emu.arg32(1))); emu.ret(eax=planes if emu.arg32(1) == 0xe else bits, argbytes=8)
    def rdc(emu, cur): emu.calllog.append(('rdc', emu.arg32(0), emu.arg32(1))); emu.ret(eax=1, argbytes=8)
    TK = r.getrandbits(32)
    def gcur(emu, cur): emu.calllog.append(('cursor',)); emu.ret(eax=TK, argbytes=0)
    for nm, f in (('GetDesktopWindow', gdw), ('GetDC', gdc), ('GetDeviceCaps', gcaps), ('ReleaseDC', rdc), ('GetCursor', gcur)): em.stub_import(nm, f)
    return [C, r.getrandbits(32), r.getrandbits(32)]


S(0x6515d0, 'GUESS hand spec 0x6515d0', 'thiscall', None, ret='eax', gen=g6515d0, note='batch252021')


def g4f1d60(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    C = rnd(c, 0x700); VT = rnd(c, 0x400); em.w32(C, VT)
    G = rnd(c, 0x1000); em.w32(0x70039c, G)
    M = rnd(c, 0x40); VM = rnd(c, 0x100); em.w32(M, VM); em.w32(G + 0x9b, M)
    em.wbytes(G + 0xa10, bytes([r.choice([0, 0x7f, 0x80, 0xff, 0x90, 0x10])]))
    OBJS = {0: 0}
    for h in (1, 2, 3):
        o = rnd(c, 0x40); OBJS[h] = o
    INV = {v: k for k, v in OBJS.items()}
    NEXT = {0: 0}
    for h in (1, 2, 3): NEXT[h] = OBJS[r.choice([0, 1, 2, 3])]
    def mkO(o):
        vo = rnd(c, 0x400); em.w32(o, vo)
        def sl(off, nargs, ret=0, tag=''):
            em.w32(vo + off, pystub(c, nargs, this=True, ret=ret, side=lambda emu, k, off=off, nargs=nargs: emu.calllog.append(('o%x' % off, INV.get(emu.reg('ecx'), -1), tuple(emu.arg32(q) for q in range(nargs))))))
        sl(0x20, 0, ret=lambda emu, k: NEXT[INV.get(emu.reg('ecx'), 0)])
        sl(0x1e0, 1, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff]))
        sl(0x300, 1); sl(0x2f8, 0); sl(0x2fc, 1); sl(0x304, 0)
    for h in (1, 2, 3): mkO(OBJS[h])
    def m58(emu, k):
        h = emu.arg32(0); emu.calllog.append(('m58', h))
    em.w32(VM + 0x58, pystub(c, 1, this=True, ret=lambda emu, k: OBJS.get(emu.arg32(0), 0), side=m58))
    em.w32(VM + 0x4c, pystub(c, 1, this=True, ret=lambda emu, k: INV.get(emu.arg32(0), 7), side=lambda emu, k: emu.calllog.append(('m4c', INV.get(emu.arg32(0), -1)))))
    hs = lambda: r.choice([0, 1, 2, 3])
    em.w32(C + 0x1a3, hs()); em.w32(C + 0x19f, hs())
    em.wbytes(C + 0x5fa, bytes([r.choice([0, 1, 1, 1])])); em.wbytes(C + 0x5f7, bytes([r.choice([0, 1])])); em.wbytes(C + 0x6a, bytes([r.choice([0, 1])]))
    f77, f7b = struct.pack('<f', r.choice([0.0, 1.5, -2.0, 100.0])), struct.pack('<f', r.choice([0.5, 3.0, 0.0]))
    em.wbytes(C + 0x77, f77); em.wbytes(C + 0x7b, f7b)
    em.w32(C + 0x1d3, r.getrandbits(32))
    for off, na in ((0x2e8, 0), (0x2d8, 0)):
        em.w32(VT + off, pystub(c, na, this=True, ret=R32, side=lambda emu, k, off=off: emu.calllog.append(('t%x' % off,))))
    em.w32(VT + 0x2dc, pystub(c, 4, this=True, ret=R32, side=lambda emu, k: emu.calllog.append(('t2dc', emu.arg32(0), emu.arg32(1), emu.arg32(2), INV.get(emu.arg32(3), -1)))))
    em.w32(VT + 0x310, pystub(c, 0, this=True, ret=lambda emu, k: hs(), side=lambda emu, k: emu.calllog.append(('t310',))))
    hook_rec(c, 0x4f3ab0, 0, ret=R32, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h3ab0',)))
    return [C]


S(0x4f1d60, 'GUESS hand spec 0x4f1d60', 'thiscall', None, ret='eax', gen=g4f1d60, note='batch252021')


def g63fea0(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    ff = lambda: struct.pack('<f', r.choice([r.uniform(-3, 3), r.uniform(-50, 50), 0.0, 1.0]))
    M = rnd(c, 0x40); VM = rnd(c, 0x100); em.w32(M, VM)
    I = rnd(c, 0x80); S_ = rnd(c, 0x80); VS = rnd(c, 0x400); em.w32(S_, VS); em.w32(I + 0x3c, S_)
    SENT = rnd(c, 0x40); em.w32(S_ + 8, SENT)
    em.wbytes(I + 0x42, bytes([r.choice([0, 1, 0xff, 0xfe])]))
    npairs = r.choice([0, 1, 1, 2, 3]); pairs = []
    for _ in range(npairs):
        m = r.choice([1, 1, 2, 3])
        arr = rnd(c, 0x70 * 4 + 0x20)
        for q in range(m):
            for off in range(0, 0x70, 4):
                if off != 0x50: em.wbytes(arr + 0x70 * q + off, ff())
        nn = r.choice([0, 1, 2, 3]); prev = SENT
        nodes = [rnd(c, 0x80) for _ in range(nn)]
        for q, nd in enumerate(nodes):
            for off in range(0, 0x50, 4): em.wbytes(nd + off, ff())
            em.w32(nd + 0x50, nodes[q + 1] if q + 1 < nn else SENT)
        em.w32(arr + 0x50, nodes[0] if nn else SENT)
        pairs.append((arr, arr + 0x70 * (m - 1)))
    BUF = rnd(c, 0x400)
    alloc_ok = r.random() < 0.85
    E = rnd(c, 0x40); VE = rnd(c, 0x100); em.w32(E, VE); em.w32(0x700390, E)
    Rr = rnd(c, 0x40); VR = rnd(c, 0x100); em.w32(Rr, VR)
    em.w32(VE + 0x20, pystub(c, 2, this=True, ret=Rr, side=lambda emu, k: emu.calllog.append(('e20', emu.arg32(0), emu.arg32(1)))))
    em.w32(VR + 0x2c, pystub(c, 2, pop=0, ret=R32, side=lambda emu, k: emu.calllog.append(('r2c', emu.arg32(0) == Rr, emu.arg32(1)))))
    em.w32(VM + 0x20, pystub(c, 1, this=True, ret=lambda emu, k: BUF if alloc_ok else 0, side=lambda emu, k: emu.calllog.append(('m20', emu.arg32(0)))))
    em.w32(VS + 0x80, pystub(c, 2, this=True, ret=R32, side=lambda emu, k: emu.calllog.append(('s80', emu.arg32(0) - I, emu.arg32(1) - I))))
    def s388(emu, k):
        d = emu.arg32(0)
        for q, (lo, hi) in enumerate(pairs): emu.w32(d + 8 * q, lo); emu.w32(d + 8 * q + 4, hi)
        emu.calllog.append(('s388', len(pairs)))
    em.w32(VS + 0x388, pystub(c, 2, this=True, nullflag=(0, 1), ret=lambda emu, k: emu.arg32(0) + 8 * len(pairs), side=s388))
    em.w32(VS + 0x384, pystub(c, 2, this=True, nullflag=(0, 1), ret=lambda emu, k: emu.arg32(0), side=lambda emu, k: emu.calllog.append(('s384',))))
    return [M, I]


S(0x63fea0, 'GUESS hand spec 0x63fea0', 'thiscall', None, ret=None, gen=g63fea0, note='batch252021')


def g518bc0(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    fl = lambda: struct.pack('<f', r.choice([0.0, 0.5, 1.0, 2.0, 5.0, 20.0, 100.0, -1.0, 50.0, 1000.0, 0.01, 0.1, 12.0, 15.0, 150.0, 250.0, 800.0, 1500.0, 0.4, 0.8, r.uniform(0, 3), r.uniform(0, 300)]))
    C = rnd(c, 0x1800); VT = rnd(c, 0x400); em.w32(C, VT)
    P = rnd(c, 0x80); em.w32(C + 0x5c, P)
    for off in (4, 0x24, 0x28): em.wbytes(P + off, fl())
    em.wbytes(P + 0x35, r.choice([3, 3, 3, 0, 1]).to_bytes(4, 'little'))
    em.w32(C + 0x12f, r.getrandbits(32))
    hv = lambda: r.choice([0, 0, 1, 2, 3, 5, 6, 7])
    for off in (0x1621, 0x1625, 0x1629, 0x162d, 0x1631, 0x1635, 0x1639, 0x1645): em.w32(C + off, hv() if off not in (0x1639, 0x1645) else r.choice([0, 1, 2, 5]))
    for off in (0x1e1, 0x2bf, 0x163d, 0x1f1, 0x1641): em.wbytes(C + off, fl())
    for off in (0x1649, 0x160b): em.wbytes(C + off, bytes([r.choice([0, 1])]))
    em.w32(C + 0x1603, r.choice([0, 1, 2, 2, 3]))
    G = rnd(c, 0x2000); VG = rnd(c, 0x400); em.w32(G, VG); em.w32(0x70039c, G)
    A = rnd(c, 0x40); VA = rnd(c, 0x100); em.w32(A, VA); em.w32(G + 0x1a9f, A if r.random() < 0.9 else 0)
    M = rnd(c, 0x40); VM = rnd(c, 0x100); em.w32(M, VM); em.w32(G + 0x9b, M)
    SND = [0] + [rnd(c, 0x100) for _ in range(3)]
    for sd in SND[1:]:
        for off in (0x60, 0x64, 0x78, 0x84): em.wbytes(sd + off, fl())
    em.w32(VA + 0x60, pystub(c, 2, this=True, ret=R32, side=lambda emu, k: emu.calllog.append(('a60', emu.arg32(0), emu.arg32(1)))))
    em.w32(VM + 0x60, pystub(c, 1, this=True, ret=lambda emu, k: SND[emu.arg32(0) & 3], side=lambda emu, k: emu.calllog.append(('m60', emu.arg32(0)))))
    em.w32(VG + 0x1c0, pystub(c, 2, this=True, st0=lambda emu, k: r.choice([0.0, 0.5, 1.0, 0.25, 0.75, 2.0]), side=lambda emu, k: emu.calllog.append(('g1c0', emu.arg32(0), emu.arg32(1)))))
    em.w32(VT + 0x2e8, pystub(c, 1, this=True, ret=lambda emu, k: hv(), side=lambda emu, k: emu.calllog.append(('t2e8', emu.arg32(0)))))
    em.w32(VT + 0x2ec, pystub(c, 1, this=True, ret=R32, side=lambda emu, k: emu.calllog.append(('t2ec', emu.arg32(0)))))
    hook_rec(c, 0x522f60, 2, ret=R32, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('h522f60', emu.reg('ecx') == P, emu.arg32(0), emu.arg32(1))),
             st0=lambda emu, k: r.choice([0.0, 0.3, 0.6, 1.0, 2.0, 5.0, -1.0, 15.0, 50.0, 300.0, 0.9]))
    return [C]


S(0x518bc0, 'GUESS hand spec 0x518bc0', 'thiscall', None, ret=None, gen=g518bc0, note='batch252021')


def g6593e0(c):
    import struct
    clear_hooks(c); r = c.rng; em = c.emu
    R32 = lambda emu, k: r.getrandbits(32)
    fv = lambda: struct.pack('<f', r.choice([r.uniform(-3, 3), r.uniform(0.1, 20), 0.0, 1.0, 0.5, 100.0, r.uniform(0.5, 1.5)]))
    fvec = lambda n: b''.join(fv() for _ in range(n))
    this = rnd(c, 0x2400 + 0x100)
    G = rnd(c, 0x2000); em.w32(0x70039c, G)
    E2 = rnd(c, 0x100); BASE = rnd(c, 0x1000); em.w32(G + 0x1aa3, E2); em.w32(E2 + 0x20, BASE)
    M = rnd(c, 0x6000); em.w32(G + 0x9b, M)
    L = rnd(c, 0x800); Lp = rnd(c, 0x100); Lq = rnd(c, 0x100); em.w32(L + 0x38, Lp); em.w32(L + 0x44, Lq)
    cnt = r.choice([0, 3, 2, 5, 12, 13, 14, 4, 6]); em.w32(Lp + 0x68, cnt)
    em.w32(L + 0x3c, r.choice([0, 8, 8, 0x2400, 1]))
    OUT = rnd(c, 0x1b00 + 0x400)
    Q = rnd(c, 0x40); VQ = rnd(c, 0x100); em.w32(Q, VQ)
    em.w32(M + 0x5d35, Q if r.random() < 0.9 else 0)
    # lights: heap objects with word +0x5a (id), flags +0x3c, offset +0x6c, pointer +0x54
    def mklight(j, special=False):
        o = rnd(c, 0x100)
        em.wbytes(o + 0x5a, r.choice([0, 1, 2, 3, 1, 2, 3, 1]).to_bytes(2, 'little'))
        em.w32(o + 0x3c, r.choice([0, 0, 0, 0, 0, 0x2400, 0x400, 0x2000, 0x1]))
        em.w32(o + 0x6c, 0x100 + 0x40 * (j % 8))
        P54 = rnd(c, 0x40); em.w32(P54 + 0x18, r.getrandbits(32)); em.w32(o + 0x54, P54)
        return o
    lights = [mklight(j) for j in range(14)]
    ARR = rnd(c, 0x80)
    for j in range(14): em.w32(ARR + 4 * j, lights[j])
    # descriptors inside L + 0x2c + 0x40 * k: type byte +0xc, colour bytes +0x10..+0x12, floats
    for k in range(8):
        d = BASE + 0x100 + 0x40 * k
        em.wbytes(d + 0xc, bytes([r.choice([0, 1, 2, 3, 3, 1, 2, 4])]))
        em.wbytes(d + 0x10, bytes([r.getrandbits(8) for _ in range(3)]))
        for off in (0x14, 0x18, 0x1c, 0x24, 0x28, 0x2c, 0x30, 0x34, 0x38): em.wbytes(d + off, fv())
    # extra first light (L[0x44][0x38] when L flag 8)
    em.w32(Lq + 0x38, mklight(0) if r.random() < 0.8 else 0)
    S2 = [rnd(c, 0x80) for _ in range(4)]
    for s2 in S2: em.wbytes(s2 + 8, fvec(12)); em.wbytes(s2 + 0x2c, fvec(12))
    em.wbytes(this + 0x8, fvec(12)); em.wbytes(this + 0x20, fvec(12))
    def s8(emu, k):
        emu.w32(emu.arg32(0), emu.arg32(1)); emu.w32(emu.arg32(0) + 4, OUT); emu.calllog.append(('q8', emu.arg32(1)))   # out struct {count, output array}
    em.w32(VQ + 8, pystub(c, 2, this=True, nullflag=(0,), ret=ARR, side=s8))
    hook_rec(c, 0x63eab0, 1, ret=lambda emu, k: S2[k % 4], pop=4, this=True, side=lambda emu, k: emu.calllog.append(('h63eab0', emu.arg32(0))))
    hook_rec(c, 0x6590e0, 0, ret=R32, pop=0, this=True, side=lambda emu, k: emu.calllog.append(('h6590e0', emu.reg('ecx') - OUT)))
    return [this, r.getrandbits(32), L]


S(0x6593e0, 'GUESS hand spec 0x6593e0', 'thiscall', None, ret='eax', gen=g6593e0, note='batch252021')
