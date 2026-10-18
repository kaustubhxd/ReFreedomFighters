"""specs_s244036.py - hand-written specs for batch 244036."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g661c10(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    f32 = lambda x: struct.unpack('<f', struct.pack('<f', x))[0]
    FV = [0.0, -0.0, 1.0, -1.0, 0.5, -0.5, 2.0, -2.0, 0.0, 1.0, -1.0, 0.5, 2.0, 3.0, 1.5, float('nan') if r.random() < 0.3 else 0.5, r.uniform(-3, 3)]
    ZA3 = r.random() < 0.6   # zero offset vector: positions stay exact vertex values (ties with the limits)
    LV = [0.0, 1.0, 1.0, 2.0, 0.5, -1.0, float('nan'), r.uniform(0, 3)]
    # --- engine base object: [0x70039c]+0x1aa3 -> X, X+0x20 = B (record / vertex / index tables)
    B = rnd(c, 0x600)
    X = rnd(c, 0x40)
    em.w32(X + 0x20, B)
    G = rnd(c, 0x2000)
    em.w32(G + 0x1aa3, X)
    em.w32(0x70039c, G)
    em.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0, side=lambda emu, k: emu.calllog.append(('brk',))))
    rec_off = 0x40
    rec = B + rec_off
    mask = r.choice([1, 2, 4, 0x80, 0xff])
    em.w32(rec + 0x2c, r.choice([mask, mask, 0, mask | 0x100, 0x100]))
    em.w32(rec + 0x14, 0x100)         # vertex array (0x24-byte vertices) at B + 0x100
    em.w32(rec + 0x3c, 0x300)         # u16 index array at B + 0x300
    nv = 8
    for v in range(nv):
        for j in range(3):
            em.wbytes(B + 0x100 + 0x24 * v + 4 * j, struct.pack('<f', r.choice(FV)))
    for i in range(0, 0x80, 2):
        em.wbytes(B + 0x300 + i, struct.pack('<H', r.randrange(0, nv)))
    lo = r.choice([0, 1, 2, 3, 3, 4, 5, 6, 8, 16, 17, 17, 18, 19])
    hi = r.choice([0, 1, 2, 3])
    sign = r.choice([0, 0, 1])
    if sign and hi == 0 and r.random() < 0.7:
        hi = 1   # keep the index pointer inside the table
    a1 = rnd(c, 0x20)
    em.w32(a1, lo | (hi << 16) | (sign << 31))
    em.w32(a1 + 4, rec_off)
    a0 = rnd(c, 0x400)
    a3 = rnd(c, 0x20)
    for j in range(3):
        em.wbytes(a3 + 4 * j, struct.pack('<f', 0.0 if ZA3 else r.choice([0.0, 0.0, 1.0, -1.0, 0.5, 2.0])))
    a5 = rnd(c, 0x20)
    for j in range(3):
        lim = r.choice(LV)
        if r.random() < 0.6:   # tie: the limit equals the magnitude of a vertex coordinate (exact compare edges)
            v = struct.unpack('<f', bytes(em.rbytes(B + 0x100 + 0x24 * r.randrange(0, nv) + 4 * j, 4)))[0]
            if v == v:
                lim = abs(v)
        em.wbytes(a5 + 4 * j, struct.pack('<f', lim))
    a4 = r.getrandbits(32)

    def h43(emu, k):
        d = emu.reg('ecx')
        src = emu.reg('edx')
        emu.calllog.append(('e920', src, emu.arg32(0), bytes(emu.rbytes(src, 12))))
        emu.wbytes(d, bytes(emu.rbytes(src, 12)))
    hook_rec(c, 0x43e920, 1, ret=r.getrandbits(32), pop=4, this='mark', side=h43)

    def h441(emu, k):
        d = emu.reg('ecx')
        m = emu.reg('edx')
        cur = struct.unpack('<3f', bytes(emu.rbytes(d, 12)))
        add = struct.unpack('<3f', bytes(emu.rbytes(m, 12)))
        emu.calllog.append(('a60', m, bytes(emu.rbytes(d, 12))))   # bytes, not floats: nan != nan would fake a mismatch
        emu.wbytes(d, struct.pack('<3f', *[f32(a + b) for a, b in zip(cur, add)]))
    hook_rec(c, 0x441a60, 0, ret=r.getrandbits(32), pop=0, this='mark', side=h441)
    return [a0, a1, mask, a3, a4, a5]


S(0x661c10, 'GUESS triangle-strip clipper against a box (outcodes, 6 flags per vertex)', 'stdcall', 6, ret='eax', gen=g661c10, note='batch244036')


def g4f5300(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 1.0, -1.0, 0.5, 2.0, 100.0, -3.5, 0.25, r.uniform(-9, 9), 1e-3]

    def lg(nm, *idx):
        def s(emu, k):
            emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in idx))
        return s
    # objects the layout code asks for
    Zs = []
    for _ in range(2):
        z = rnd(c, 0x100)
        em.w32(z + 0x6c, r.getrandbits(32))
        em.wbytes(z + 0x40, pk(r.choice(FV)))
        Zs.append(z)
    flagsr = lambda emu, k: r.choice([0, 1, 0x100])
    pool = []
    for _ in range(3):
        o = obj(c, 0x200, {0x1e0: pystub(c, 1, ret=flagsr, pop=4, this=True, side=lg('p1e0', 0)),
                           0x254: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32), pop=4, this=True, side=lg('p254', 0))})
        em.w32(o + 8, r.choice(Zs))
        em.wbytes(o + 0x9b, pk(r.choice(FV)))
        pool.append(o)
    Bf = rnd(c, 0x300)
    Y = obj(c, 0x40, {0x2c: pystub(c, 1, ret=Bf, pop=4, this=True, side=lg('y2c', 0)),
                      0xe4: pystub(c, 2, ret=lambda emu, k: r.getrandbits(32), pop=8, this=True, side=lg('ye4', 0, 1)),
                      0x12c: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, side=lambda emu, k: emu.calllog.append(('y12c', emu.arg32(0), emu.arg32(1), bytes(emu.rbytes(emu.arg32(0), 0x24)))))})
    X = rnd(c, 0x40)
    em.w32(X + 0x18, Y)
    outv = r.getrandbits(32)

    skip88 = r.random() < 0.4   # sometimes the lookup writes nothing: the initial value (0) of the out slot reaches slot 0x58

    def s88(emu, k):
        if not skip88:
            emu.w32(emu.arg32(1), outv)
        emu.calllog.append(('h88', emu.arg32(0)))
    Hn = obj(c, 0x40, {0x88: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, stackmark=(1,), side=s88)})
    H = obj(c, 0x100, {0x58: pystub(c, 1, ret=lambda emu, k: r.choice(pool), pop=4, this=True, side=lg('h58', 0)),
                       0x138: pystub(c, 0, ret=Hn, pop=0, this=True, side=lg('h138'))})
    G = rnd(c, 0x2000)
    em.w32(G + 0x1aa3, X)
    em.w32(G + 0x9b, H)
    em.w32(0x70039c, G)
    Wq = r.choice(pool)
    W = None if r.random() < 0.2 else obj(c, 0x100, {0x1e0: pystub(c, 1, ret=flagsr, pop=4, this=True, side=lg('w1e0', 0)),
                                                       0x2c4: pystub(c, 0, ret=lambda emu, k: r.choice([0, Wq, Wq]), pop=0, this=True, side=lg('w2c4'))})
    me = obj(c, 0x400, {0x230: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t230')),
                        0x244: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t244')),
                        0x20: pystub(c, 0, ret=(W or 0), pop=0, this=True, side=lg('t20')),
                        0x228: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lg('t228'))})
    for i in range(9):
        em.w32(me + 0x93 + 4 * i, r.getrandbits(32))
    em.w32(me + 0xbb, r.choice([0, 1, 7, 100, 640, -5 & 0xffffffff, 0x7fffffff]))
    em.w32(me + 0xbf, r.choice([0, 1, 2, 3, 480, 255, -1 & 0xffffffff]))
    em.w32(me + 0x1c, r.getrandbits(32))
    # hooks for the two exe helpers
    hook_rec(c, 0x4dffb0, 1, ret=r.getrandbits(32), pop=4, this='mark', side=lambda emu, k: emu.calllog.append(('dffb0', bytes(emu.rbytes(emu.reg('ecx'), 8)))))

    def h9350(emu, k):
        emu.calllog.append(('f9350', emu.reg('edx'), bytes(emu.rbytes(emu.reg('ecx'), 72)), tuple(emu.arg32(i) for i in range(5))))
    hook_rec(c, 0x4f9350, 5, ret=r.getrandbits(32), pop=20, this='mark', side=h9350)
    return [me]


S(0x4f5300, 'GUESS 3x3 nine-slice panel layout builder', 'thiscall', 0, ret='eax', gen=g4f5300, note='batch244036')


def g54f2b0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    # representatives of every case of the byte table (0x54f7b0, index = hr - 0x8878001e, 0..0xb4)
    tb = bytes(em.rbytes(0x54f7b0, 0xb5))
    reps = {}
    for i, b in enumerate(tb):
        reps.setdefault(b, []).append(i)
    base = 0x8878001e
    tbl = []
    for b, idxs in reps.items():
        tbl += [base + idxs[0], base + idxs[-1]]
    hrs = tbl + [0x8878001e - 1, base + 0xb5, 0x8878000a, 0x8878000a, 0x88781161, 0x88781161, 0x88781160, 0x88781162, 0x80004001, 0x80004002, 0x80004005, 0x80040110,
                 0x80070005, 0x8007000e, 0x80070057, 0, 0x878000a, 0x8780014, 0x8780015, 1, 0x7fffffff, 0x80000000, 0x80004003, 0x80040111, 0x80070006, 0x8007000f, 0x80070058]
    hr = r.choice(hrs)
    n = r.choice([0, 1, 5, 30, 100, 120])
    src = em.alloc(0x200, 4)
    em.wbytes(src, bytes(r.randrange(33, 126) for _ in range(n)) + b'\0')

    def lg(emu, k):
        f = emu.arg32(1)
        s = emu.rbytes(emu.arg32(2), 0x204)
        s = bytes(s).split(b'\0')[0]
        emu.calllog.append(('log2c', f, emu.arg32(0), s))
    LO = obj(c, 0x40, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, stackmark=(2,), side=lg)})
    MG = obj(c, 0x40, {0x20: pystub(c, 2, ret=LO, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('mg20', emu.arg32(0), emu.arg32(1))))})
    em.w32(0x700390, MG)
    return [hr, src]


S(0x54f2b0, 'GUESS HRESULT to text: appends the message for a DirectX error code and logs it', 'fastcall', 0, ret=None, gen=g54f2b0, note='batch244036')


def g53c5b0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    FV = [0.0, 1.0, -1.0, 0.5, 2.0, 100.0, 3.0, r.uniform(-9, 9), 1e-3]

    def lg(nm, n):
        return lambda emu, k: emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in range(n)))
    # --- tables: K (keys, stride 0xa4, first dword = handle), T3 (triples of key indices), T1 (tracks: count, offset), T2 (dword entries)
    nK = 6
    K = em.alloc(0xa4 * nK + 8, 4)
    for i in range(nK):
        em.w32(K + 0xa4 * i, r.getrandbits(32))
        em.wbytes(K + 0xa4 * i + 4, bytes(r.getrandbits(8) for _ in range(0x40)))
    T3 = em.alloc(12 * nK + 8, 4)
    for i in range(nK):
        for j in range(3):
            em.w32(T3 + 12 * i + 4 * j, r.randrange(0, nK))
    ntr = 4
    T1 = em.alloc(8 * ntr + 8, 4)
    T2 = em.alloc(4 * 96, 4)
    off = 0
    tracks = []
    poison = []
    for t in range(ntr):
        n = r.choice([0, 1, 2, 2, 3, 4])
        pool_f = list(range(0, 12)) + [0x1fff, 0x2000, 0x2001, 0x3ffe, 0x3fff, 0x1000, 0x1001]
        if r.random() < 0.35:   # all frames above 0x1fff: the 0x3fff frame masks of the first / last entry matter
            pool_f = [0x2000, 0x2001, 0x2fff, 0x3000, 0x3ffd, 0x3ffe, 0x3fff]
        frames = sorted(r.choices(pool_f, k=n)) if r.random() < 0.5 else sorted(r.sample(pool_f, n))   # duplicates: several keys on one frame
        tracks.append(frames)
        em.w32(T1 + 8 * t, n)
        em.w32(T1 + 8 * t + 4, off)
        for fr in frames:
            typ = r.choice([0, 1, 2, 3])
            em.w32(T2 + 4 * off, r.randrange(0, nK) | (fr << 16) | (typ << 30))
            off += 1
        poison.append(off)   # slot right after the track: filled with the query frame below (one-past-the-end reads)
        off += 1
        if r.random() < 0.3:   # a second pass over the same frames is possible: keep a spare entry for the lookahead
            pass
    me = rnd(c, 0x1400)
    em.w32(me + 0x1201, T1)
    em.w32(me + 0x1205, T2)
    em.w32(me + 0x11fd, T3)
    em.w32(me + 0x11f9, K)
    # --- engine objects: [0x70039c] + 0x9b -> H, H slot 0x58(handle) -> Ho, Ho slot 0x84(&vec)
    def s84(emu, k):
        emu.calllog.append(('o84', emu.reg('ecx')))
        emu.wbytes(emu.arg32(0), b''.join(struct.pack('<f', r.choice(FV)) for _ in range(3)))
    Hos = [obj(c, 0x80, {0x84: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=s84)}) for _ in range(2)]
    H = obj(c, 0x40, {0x58: pystub(c, 1, ret=lambda emu, k: r.choice(Hos), pop=4, this=True, side=lg('h58', 1))})
    G = rnd(c, 0x200)
    em.w32(G + 0x9b, H)
    em.w32(0x70039c, G)
    em.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0, side=lambda emu, k: emu.calllog.append(('brk',))))
    hook_rec(c, 0x4e0830, 0, ret=r.getrandbits(32), pop=0, this='mark', st0=lambda emu, k: r.choice(FV), side=lambda emu, k: emu.calllog.append(('e830', bytes(emu.rbytes(emu.reg('ecx'), 12)), emu.reg('edx'))))
    hook_rec(c, 0x53bec0, 0, ret=r.getrandbits(32), pop=0, this=True, st0=lambda emu, k: r.choice(FV), side=lambda emu, k: emu.calllog.append(('bec0', emu.reg('ecx'), emu.reg('edx'))))
    # --- arguments
    tid = r.randrange(0, ntr)
    fr_c = tracks[tid]
    if fr_c and r.random() < 0.75:
        frm = r.choice(fr_c) + r.choice([0, 0, 0, 1, -1])
        frm = max(tid, min(frm, 0x3fff))
    else:
        frm = r.choice([tid, tid + 1, 5, 11, 0x1fff, 0x2000, 0x3fff])
    a0, a1 = (tid, frm) if r.random() < 0.5 else (frm, tid)
    if r.random() < 0.05:
        a0 = 0xffffffff
    for pe in poison:
        em.w32(T2 + 4 * pe, r.randrange(0, nK) | (frm << 16) | (r.choice([0, 1, 2, 3]) << 30))
    cnt = rnd(c, 8)
    out = rnd(c, 0x300)
    a4 = r.getrandbits(32)
    a5 = struct.unpack('<I', struct.pack('<f', r.choice(FV)))[0]
    return [me, a0, a1, cnt, out, a4, a5]


S(0x53c5b0, 'GUESS keyframe track sampler: finds the key entries around a frame and interpolates', 'thiscall', 6, ret='al', gen=g53c5b0, note='batch244036')
