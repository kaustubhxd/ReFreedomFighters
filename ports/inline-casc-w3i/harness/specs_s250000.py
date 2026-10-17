"""specs_s250000.py - Sonnet-w3i: 0x5f9260 (/GS thiscall: slot 0x14 formats into a 0x68 local, then the handler [0x7003b0])."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def _r(c): return c.rng.getrandbits(32)


def _log(tag): return lambda emu, k: emu.calllog.append((tag,))


def g5f9260(c):
    clear_hooks(c)
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def s14(emu, k):
        # the formatter writes a few bytes into the local buffer (arg 1) and logs its arguments
        buf = emu.arg32(1)
        emu.w32(buf, 0xBEEF0000 | c.rng.getrandbits(16))
        emu.calllog.append(('fmt', emu.arg32(2), emu.arg32(3), emu.arg32(4)))

    def ah(e2, res_):
        e2.calllog.append(('handler',))
        e2.ret(eax=_r(c))
    o = obj(c, 0x40, {0x14: pystub(c, 5, ret=_r(c), pop=0, stackmark=(1,), side=s14)}, nslots=0x70)
    c.emu.w32(0x724270, o)
    c.emu.w32(0x7003b0, c.emu.stub_fn('assert hook', ah))
    t = rnd(c, 0xb00)
    c.emu.wbytes(t + 0x82, _r(c).to_bytes(4, 'little'))
    c.emu.wbytes(t + 0xac6, _r(c).to_bytes(4, 'little'))
    return [t]


S(0x5f9260, 'gs_format_handler', 'thiscall', None, ret=None, gen=g5f9260, note='batch250000')


def _fl(v):
    import struct
    return struct.unpack('<I', struct.pack('<f', v))[0]


def g43f2b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    nn = r.choice([0, 0, 1, 2, 3, 4, 5])
    skip = [r.random() < 0.3 for _ in range(nn)]
    ok = [r.random() < 0.7 for _ in range(nn)]
    ref = bytes(e.rbytes(0x67cd0c, 40)).split(b'\0')[0] + b'\0'
    strs = []
    for _ in range(nn):
        m = r.randint(0, 7)
        if m == 0:
            strs.append(0x67cd0c)
            continue
        b = bytearray(ref + b'\0\0')
        if m == 2: b[0] ^= 0x20
        elif m == 3 and len(b) > 1: b[1] ^= 0x20
        elif m == 4 and len(ref) > 2: b[len(ref) - 2] ^= 1
        elif m == 5: b = bytearray(b'\0\0')
        elif m == 6: b = bytearray(ref[:max(1, len(ref) // 2)] + b'\0\0')
        a = e.alloc(len(b) + 4, 1)
        e.wbytes(a, bytes(b))
        strs.append(a)
    vals = [-5.0, -1.0, 0.0, 0.5, 1.0, 2.0, 3.5, 100.0, -100.0, 1e30, -1e30]

    def fv():
        return _fl(r.choice(vals)) if r.random() < 0.8 else _fl(r.uniform(-50, 50))
    outs = [[fv() for _ in range(6)] for _ in range(nn)]
    if nn and r.random() < 0.2:   # a NaN component never passes the max/min compare, so the sentinel survives in that lane
        outs[r.randrange(nn)][r.randrange(6)] = 0x7fc00000
    hook_rec(c, 0x4daa00, 0, this=True, ret=lambda em, k: 1 if skip[min(k, nn - 1)] else 0)
    hook_rec(c, 0x4dc110, 0, this=True, ret=lambda em, k: strs[min(k, nn - 1)])

    def s460(em, k):
        o = outs[min(k, nn - 1)]
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, o[i])
            em.w32(em.arg32(1) + 4 * i, o[3 + i])
    hook_rec(c, 0x4db460, 2, this=True, stackmark=(0, 1), ret=lambda em, k: 1 if ok[min(k, nn - 1)] else 0, side=s460)
    t = rnd(c, 0x100)
    slot = pystub(c, 0, ret=(0 if r.random() < 0.6 else _r(c)), this=True)
    vt = e.alloc(0x40, 4)
    e.w32(vt + 0x20, slot)
    e.w32(t, vt)
    e.wbytes(t + 0x14, bytes([r.choice([0, 1, 2, 3, 0xff])]))
    e.w32(t + 8, rnd(c, 0x60))
    nodes = [rnd(c, 0x70) for _ in range(nn)]
    for i, n in enumerate(nodes):
        e.w32(n + 0x60, nodes[i + 1] if i + 1 < nn else 0)
    e.w32(t + 0x50, nodes[0] if nn else 0)
    return [t]


S(0x43f2b0, 'object_bounds_43f2b0', 'thiscall', None, ret=None, gen=g43f2b0, note='batch250000')


def g5de550(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    tie = r.random() < 0.15   # entry 0: dt == 1024 (t == 1.0), W == 0, position (d,0,0) with d == size*3: dist == r exactly
    Wv = [0, 0, 0] if tie else [fr(-10, 10) if r.random() < 0.9 else _fl(r.choice([0.0, 1.0, -1.0])) for _ in range(3)]

    def s84(em, k):
        for i in range(3):
            em.w32(em.arg32(0) + 4 * i, Wv[i])
    o114 = obj(c, 0x40, {0x84: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=s84)}, nslots=0x40)
    fog = obj(c, 0x40, {0x58: pystub(c, 3, ret=_r(c), pop=12, this=True)}, nslots=0x30)
    st = sysobj(c, slots={}, table_slots={0x138: pystub(c, 0, ret=fog, this=True)})
    now = r.randrange(1024, 200000)
    e.w32(st + 0x40, now)
    e.w32(st + 0x48, fr(0, 0.05))
    t = rnd(c, 0x4c + 0x28 * 6 + 0x20)
    n = r.choice([0, 1, 1, 2, 3, 4, 5])
    e.w32(t + 0x48, n)
    e.w32(t + 0x114, o114)
    for off in (0x118, 0x11c): e.w32(t + off, fr(-2, 2))
    for off in (0x120, 0x124, 0x128): e.w32(t + off, fr(0, 1.3) if r.random() < 0.9 else _fl(r.choice([0.0, 1.0])))
    e.w32(t + 0x12c, fr(0, 1.2) if r.random() < 0.9 else _fl(r.choice([0.0, 0.5, 1.0])))
    e.w32(t + 0x130, rnd(c, 0x170))
    o134 = rnd(c, 0x40)
    e.w32(o134 + 0x20, r.choice([0, 255, 100, 1, 0xffffffff, 0x80000000, r.randrange(0, 400), r.randrange(0, 400)]))
    e.w32(t + 0x134, o134)
    for i in range(n):
        b = t + 0x4c + 0x28 * i
        # a NaN sqrt (stamp after now) always ends in a colour conversion fault on both sides: keep stamp <= now
        tie_i = tie and i == 0
        e.w32(b + 0xc, now - 1024 if tie_i else r.randrange(0, now + 1))
        sz = fr(0.2, 6)
        e.w32(b + 0x10, sz)
        e.w32(b + 0x14, fr(0.5, 5000) if r.random() < 0.95 else _fl(0.0))
        e.w32(b + 0x18, fr(-3, 3))
        for off in (0x1c, 0x20, 0x24): e.w32(b + off, fr(-10, 10))
        for j in range(3): e.w32(b + 4 * j, fr(-10, 10))
        if tie_i:
            import struct
            d = struct.unpack('<f', struct.pack('<f', struct.unpack('<f', struct.pack('<I', sz))[0] * 3.0))[0]
            e.w32(b, _fl(d)); e.w32(b + 4, 0); e.w32(b + 8, 0)
    return [t]


S(0x5de550, 'fog_blend_5de550', 'thiscall', None, ret=None, gen=g5de550, note='batch250000')


def g4e3630(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'), side=_log('gs'))   # the real cookie check keeps eax (the return value)

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    def cbside(em, k):
        em.calllog.append(('cb', em.reg('edx')))
    cb = pystub(c, 0, ret=lambda em, k: r.choice([0, 0, 1, 2, 4, 0x80, 0x101]), this=True, side=cbside)
    o = rnd(c, 0x40)
    e.w32(o, fr(0, 1.5) if r.random() < 0.9 else _fl(r.choice([0.0, 1.0, -1.0, 5.0])))
    e.w32(o + 4, cb)
    st = rnd(c, 12)
    en = rnd(c, 12)
    for i in range(3):
        e.w32(st + 4 * i, fr(-5, 70))
        e.w32(en + 4 * i, fr(-5, 70))
    e.w32(o + 0x30, st)
    e.w32(o + 0x34, en)
    inside = r.random() < 0.3   # ray start inside record 0 / on the root cube centre: t == 0 exactly, with obj[0] == 0.0 the compare is a tie
    bigcnt = r.random() < 0.02
    nrec = 4100 if bigcnt else 16
    rb = bytearray()
    for i in range(nrec):
        rb += r.getrandbits(32).to_bytes(4, 'little')
        lo = [r.randrange(0, 64) for _ in range(3)]
        hi = [min(65535, v + r.randrange(0, 20)) for v in lo]
        for v in lo + hi:
            rb += v.to_bytes(2, 'little')
    recs = e.alloc(len(rb), 4)
    if inside:
        lo0 = [int.from_bytes(rb[4 + 2 * j:6 + 2 * j], 'little') for j in range(3)]
        hi0 = [int.from_bytes(rb[10 + 2 * j:12 + 2 * j], 'little') for j in range(3)]
        for j in range(3): e.w32(st + 4 * j, _fl((lo0[j] + hi0[j]) / 2.0))
        e.w32(o, _fl(0.0))
    e.wbytes(recs, bytes(rb))
    e.w32(o + 0x10, recs)
    tab = bytearray(6)   # entry 0 is the root node
    maxdepth = r.choice([0, 1, 2, 3])

    def entry(octant, last, cnt, cidx, roff):
        hdr = octant | (cnt << 3) | (0x8000 if last else 0)
        return hdr.to_bytes(2, 'little') + cidx.to_bytes(2, 'little') + roff.to_bytes(2, 'little')

    def group(depth):
        k = r.choice([1, 2, 3, 4, 5, 8])
        idx = len(tab) // 6
        tab.extend(bytes(6 * k))
        for j in range(k):
            ci = group(depth + 1) if depth < maxdepth and r.random() < 0.6 else 0
            ent = entry(r.randrange(8), j == k - 1, r.choice([0, 0, 1, 2, 3, 4]), ci, r.randrange(0, 12))
            tab[6 * (idx + j):6 * (idx + j) + 6] = ent
        return idx
    rootc = group(1) if maxdepth > 0 and r.random() < 0.95 else 0
    tab[0:6] = entry(0, True, 0xc00 + r.randrange(0, 0x400) if bigcnt else r.choice([0, 1, 2, 3]), rootc, 0 if (inside or bigcnt) else r.randrange(0, 12))
    tb = e.alloc(len(tab) + 8, 4)
    e.wbytes(tb, bytes(tab))
    e.w32(o + 0xc, tb)
    s = r.choice([16, 32, 64, 128, 64, 33, 0])
    return [tb, o, s, r.randrange(-8, 80), r.randrange(-8, 80), r.randrange(-8, 80)]


S(0x4e3630, 'octree_ray_walk_4e3630', 'thiscall', None, ret='al', gen=g4e3630, note='batch250000')


def g5a4120(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    import struct
    R = lambda emu, k: r.getrandbits(32)
    fl = [0.0, 1.0, -1.0, 2.5, 100.0, 0.25, 3.0]
    FB = lambda: struct.unpack('<I', struct.pack('<f', r.choice(fl)))[0]
    TB = lambda: struct.unpack('<I', struct.pack('<f', r.choice([5.0, 30.0, 60.0, 6.0, 31.0, 61.0, 0.5, 1.0, 0.0, -1.0, 100.0, 5.5, 2.0])))[0]
    THIS = rnd(c, 0x200)
    for off, p in ((267, 0.6), (88, 0.7), (265, 0.4), (266, 0.3), (89, 0.6), (90, 0.6), (91, 0.6), (92, 0.6), (93, 0.3),
                   (94, 0.3), (95, 0.3), (96, 0.3), (98, 0.3), (116, 0.3), (134, 0.3), (152, 0.3)):
        em.wbytes(THIS + off, bytes([1 if r.random() < p else 0]))
    for k in range(4):
        em.wbytes(THIS + 97 + 18 * k, bytes([r.choice([0, 1, 1])]))
        em.w32(THIS + 111 + 18 * k, TB())
    em.w32(THIS + 295, FB()); em.w32(THIS + 275, r.choice([0, FB(), 0x3f800000])); em.w32(THIS + 299, r.getrandbits(32))
    em.w32(THIS + 76, FB()); em.w32(THIS + 80, TB()); em.w32(THIS + 84, r.choice([0, 3, 10, 0xfffffff0]))
    for off in (99, 117, 135, 153, 103, 121, 139, 157): em.w32(THIS + off, r.choice([0, 3, 10, 0xfffffff0, 5]))
    # P object (this+283) with [P+24] -> Q, Q slot +20 gives a size
    P = rnd(c, 0x40); Q = rnd(c, 0x40); VQ = rnd(c, 0x100); em.w32(Q, VQ); em.w32(P + 24, Q)
    em.w32(THIS + 283, P if r.random() < 0.7 else 0)
    em.w32(VQ + 20, pystub(c, 0, ret=lambda emu, k: r.choice([2, 3, 5, 100, 0xfffffff9, 0xffffff9c, 1000]), this=True))
    # W (this+68) with slots +296, +300
    W = rnd(c, 0x40); VW = rnd(c, 0x400); em.w32(W, VW); em.w32(THIS + 68, W)
    em.w32(VW + 296, pystub(c, 1, ret=R, this=True, side=lambda emu, k: emu.calllog.append(('w296', emu.reg('ecx'), emu.arg32(0)))))
    em.w32(VW + 300, pystub(c, 2, ret=R, this=True, side=lambda emu, k: emu.calllog.append(('w300', emu.reg('ecx'), emu.arg32(0), emu.arg32(1)))))
    G = rnd(c, 0x200); em.w32(0x70039c, G); em.w32(G + 72, r.choice([0, 0x3f800000, 0x3f000000, FB()]))
    T = rnd(c, 0xb00); VT = rnd(c, 0x400); em.w32(T, VT); em.w32(G + 155, T)
    def s114(emu, res_):
        # slot 0x114 of the table object: callee pops its 6 stack arguments (ret 0x18); the site at line 0x2b7 pushes only 5
        # (the exe returns with an unbalanced stack there). This FAKE pops 5 words at that site so that the original and the port both
        # run to the end with intact ebx/esi/edi (see the ledger note for 0x5a4120).
        line = emu.arg32(3)
        n = 5 if line == 695 else 6
        emu.calllog.append(('t276', emu.reg('ecx')) + tuple(emu.arg32(i) for i in range(n)))
        emu.ret(eax=(r.getrandbits(16) << 16) | r.getrandbits(16), argbytes=4 * n)
    em.w32(VT + 276, c.emu.stub_fn('recorder', s114))
    em.w32(VT + 180, pystub(c, 1, ret=R, this=True, side=lambda emu, k: emu.calllog.append(('t180', emu.arg32(0)))))
    Y = rnd(c, 0x40); VY = rnd(c, 0x100); em.w32(Y, VY)
    em.w32(VT + 312, pystub(c, 0, ret=Y, this=True))
    def v136(emu, k):
        emu.w32(emu.arg32(1), r.getrandbits(32))
        emu.calllog.append(('y136', emu.reg('ecx'), emu.arg32(0), emu.r32(emu.arg32(1))))
    em.w32(VY + 136, pystub(c, 2, ret=R, this=True, stackmark=(1,), side=v136))
    # global M object and helpers
    em.w32(0x7003b8, rnd(c, 0x20))
    em.w32(0x67644c, pystub(c, 0, ret=lambda emu, k: r.randrange(0, 0x7fffffff)))
    hook_rec(c, 0x589c20, 1, ret=R, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('c20', emu.reg('ecx'), emu.arg32(0))))
    hook_rec(c, 0x59a5e0, 1, ret=R, pop=4, this=True, side=lambda emu, k: emu.calllog.append(('a5e0', emu.reg('ecx'), emu.arg32(0))))
    hook_rec(c, 0x5a4f70, 2, ret=R, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('f70', emu.reg('ecx'), emu.arg32(0), emu.arg32(1))))
    return [THIS]



S(0x5a4120, 'status_widget_tick_5a4120', 'thiscall', None, ret=None, gen=g5a4120, note='batch250000')


def g457d50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))
    hook_rec(c, 0x457760, 1, this=True, ret=lambda em, k: _r(c), side=lambda em, k: em.calllog.append(('p760', em.arg32(0))))
    hook_rec(c, 0x459c40, 1, this=True, ret=lambda em, k: _r(c), side=lambda em, k: em.calllog.append(('p9c40', em.arg32(0))))

    def rs(em, k):
        em.calllog.append(('rand', em.reg('ecx'), em.arg32(0), em.arg32(1)))
    vals = [0, 16383, 32767, 8000, 20000]
    eng = obj(c, 0x40, {0x1bc: pystub(c, 2, ret=lambda em, k: r.choice(vals) if r.random() < 0.3 else r.randrange(0, 32768), pop=8, this=True, side=rs)}, nslots=0x1c0 // 4 + 4)
    e.w32(0x70039c, eng)
    t = rnd(c, 0x200)
    N = r.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 12, 20, 30, 33, 40, 45])
    e.w32(t + 0x34, N)
    e.w32(t + 0x18, r.choice([0, 0, _fl(1.0), fr(-2, 2), 0x80000000, 0x7fc00000 if r.random() < 0.05 else _fl(0.5)]))
    e.w32(t + 0x38, fr(-5, 5))
    p0 = rnd(c, 0x30 * max(N, 1) + 8)
    p1 = rnd(c, 0x10 * max(N, 1) + 8)
    e.w32(t + 0xcc, p0)
    e.w32(t + 0xd0, p1)
    O = rnd(c, 0x60)
    for off in (0x40, 0x44, 0x48): e.w32(O + off, fr(-6, 6) if r.random() < 0.9 else _fl(r.choice([0.0, 1.0, -1.0])))
    e.w32(t + 8, O)
    return [t]


S(0x457d50, 'particle_emitter_init_457d50', 'thiscall', None, ret=None, gen=g457d50, note='batch250000')


def g485110(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    mode = r.choice(['rand', 'rand', 'far', 'zero', 'zero', 'tie_r', 'tie_hi', 'tie_lo', 'tie_len', 'zedge', 'zedge'])
    X, Y, Z = r.randrange(-5, 6), r.randrange(-5, 6), r.randrange(-5, 6)
    if mode not in ('rand', 'far'): Y = 0
    exact = mode not in ('rand', 'far')   # exact integer geometry: dst == P28 (the 0x5c4 vector is zero)

    def vecw(em, addr):
        for i in range(3):
            em.w32(addr + 4 * i, fr(-5, 5) if r.random() < 0.9 else _fl(r.choice([0.0, 1.0, -1.0])))

    def s59c(em, k):
        vecw(em, em.arg32(0))
        if exact:
            for i, v in enumerate((X, Y, Z)): em.w32(em.arg32(1) + 4 * i, _fl(float(v)))
        else:
            vecw(em, em.arg32(1))

    def s5c4(em, k):
        if exact:
            for i in range(3): em.w32(em.arg32(0) + 4 * i, 0)
        else:
            vecw(em, em.arg32(0))
    this = obj(c, 0x620, {0x59c: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=s59c),
                          0x5c4: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=s5c4)}, nslots=0x5c8 // 4)
    O = rnd(c, 0x60)
    if exact:
        e.w32(O + 0x34, _fl(0.0)); e.w32(O + 0x44, _fl(2.0))
    else:
        for off in (0x34, 0x44): e.w32(O + off, fr(-3, 3))
    e.w32(this + 8, O)
    e.w32(this + 0x4dd, _fl(20000.0) if mode == 'tie_len' else fr(0, 100))
    e.wbytes(this + 0x5ff, bytes([r.choice([0, 1, 1, 1])]))

    def s2e0(em, k):
        a0 = em.arg32(0)
        em.calllog.append(('q', em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4), em.arg32(5),
                           tuple(em.r32(a0 + o) for o in (0, 4, 8, 0xc, 0x10, 0x14, 0x34, 0x44))))
    V = obj(c, 0x40, {0x2e0: pystub(c, 6, ret=lambda em, k: r.choice([0, 1]), pop=24, this=True, stackmark=(0,), side=s2e0)}, nslots=0x2e4 // 4 + 2)
    so = sysobj(c, slots={}, table_slots={}, table_size=0xb00)
    T = e.r32(so + 0x9b)
    e.w32(T + 0xadc, V)
    e.w32(so + 0x40, r.randrange(0, 50))
    e.w32(so + 0x48, fr(0, 0.05))
    ob2 = obj(c, 0x40, {0x30: pystub(c, 2, ret=_r(c), pop=0, this=False, side=lambda em, k: em.calllog.append(('log30', em.arg32(1))))}, nslots=0x34 // 4 + 2)
    Lg = obj(c, 0x40, {0x20: pystub(c, 2, ret=ob2, pop=8, this=True, side=lambda em, k: em.calllog.append(('log20', em.arg32(0), em.arg32(1))))}, nslots=0x24 // 4 + 2)
    e.w32(0x700390, Lg)
    n = r.choice([0, 1, 2, 3, 4, 5, 6, 8, 8])
    M = rnd(c, 0x4b4 + 4 * 10)
    e.w32(M + 0x4b0, n)
    e.w32(0x7003b8, M)

    def s80(em, k):
        a = em.arg32(1)
        if exact:
            for q in range(3): em.w32(a + 4 * q, _fl(float(r.randrange(-5, 6))))
            if mode == 'tie_len': em.w32(a, _fl(float(X + 3)))
            em.w32(a + 4, fr(-3, 3) if mode == 'tie_len' else _fl({'tie_hi': 4.0, 'tie_lo': -6.0}.get(mode, 0.0)))   # tie_len: y' inexact so a + (b - a) != b sometimes (the mutant would overwrite [-0xc] with the exact value)
        else:
            vecw(em, a)
    for i in range(n):
        it = rnd(c, 0x60)
        span = 60 if mode == 'far' else 8
        if mode in ('zero', 'tie_r'):
            px, pz = float(X), float(Z)
        elif mode == 'zedge':
            px, pz = float(X), float(Z + r.choice([25, -25, 15, -15]))
        elif mode == 'tie_len':
            px, pz = float(X + 3), float(Z)   # |P - P28| == 3 exactly; 0x4e65e0 gives A == (0, 1) so 0x4e64b0 is a no-op on w
        else:
            px, pz = X + r.uniform(-span, span), Z + r.uniform(-span, span)
        e.w32(it + 8, _fl(px)); e.w32(it + 0xc, fr(-5, 5)); e.w32(it + 0x10, _fl(pz))
        if mode == 'tie_r': e.w32(it + 0x38, _fl(-40.0))
        elif mode == 'tie_len': e.w32(it + 0x38, _fl(-17.0))
        elif mode == 'zedge': e.w32(it + 0x38, _fl(-20.0))
        else: e.w32(it + 0x38, fr(0, 20))
        e.w32(it + 0x3c, r.choice([_fl(20000.0), _fl(10000.0), _fl(20000.0), fr(0, 100)]) if mode != 'tie_len' else _fl(1.0))
        e.wbytes(it + 0x4c, bytes([r.choice([0, 1, 1, 1, 1])]))
        e.w32(it + 0x4d, r.randrange(0, 50))
        Xo = rnd(c, 0x10)
        e.wbytes(Xo + 4, bytes([r.choice([0, 0, 0, 2, 4])]))
        Ob = rnd(c, 0x60)
        e.w32(Ob + 0x3c, r.choice([0, 0, 0, 0x800, 0x1000 | 0x800]) | (r.getrandbits(8) << 16 & 0xf00000))
        if exact:
            e.w32(Ob + 0x34, _fl(1.0)); e.w32(Ob + 0x44, _fl(3.0))
        else:
            for off in (0x34, 0x44): e.w32(Ob + off, fr(-3, 3))
        if exact: e.w32(Ob + 0x3c, 0)
        D = obj(c, 0x40, {0x7c: pystub(c, 2, ret=_r(c), pop=8, this=True, deref={1: 3},
                                       side=lambda em, k: em.calllog.append(('7c', em.arg32(0)))),
                          0x80: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=s80)}, nslots=0x84 // 4 + 2)
        e.w32(D + 8, Ob)
        C1 = obj(c, 0x40, {0x20: pystub(c, 0, ret=D, this=True)}, nslots=0x24 // 4 + 2)
        e.w32(C1 + 0x1c, Xo)
        e.w32(it + 4, C1)
        e.w32(M + 0x4b4 + 4 * i, it)
        if exact:
            e.wbytes(it + 0x4c, bytes([1]))
            e.wbytes(Xo + 4, bytes([0]))
    if exact: e.wbytes(this + 0x5ff, bytes([1]))
    return [this]


S(0x485110, 'item_sweep_485110', 'thiscall', None, ret=None, gen=g485110, note='batch250000')


def g58c450(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg('eax'), side=_log('gs'))   # the real cookie check keeps eax (the returned al)

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    mode = r.choice(['rand'] * 7 + ['t0', 't0', 't1', 't2', 't2', 't2', 't2', 't4a', 't4b', 't4c', 't4d', 't5'])
    sel = {'t0': 0, 't1': 1, 't2': r.choice([2, 3]), 't4a': 4, 't4b': 4, 't4c': 4, 't4d': 4, 't5': 5}.get(mode) if mode != 'rand' else r.choice([0, 0, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 9])
    exact = mode != 'rand'
    ident = [1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0]
    posE = posT = None
    st0v = None
    if mode == 't1': posE, posT = (60.0, 80.0, 0.0), (0.0, 0.0, 0.0)
    if mode == 't5': posE, posT = (210.0, 280.0, 0.0), (0.0, 0.0, 0.0)
    if mode == 't4a': posE, posT, st0v = (30.0, 7.0, 40.0), (0.0, 0.0, 0.0), 100.0
    if mode == 't4b': posE, posT, st0v = (72.0, 96.0, 0.0), (0.0, 0.0, 0.0), 0.0
    if mode == 't4c': posE, posT, st0v = (49.99, 0.0, 0.0), (0.0, 0.0, 0.0), 100.0
    if mode == 't4d': posE, posT, st0v = (60.0, 0.0, 0.0), (0.0, 0.0, 0.0), -100.0
    ext = [float(r.randrange(0, 21)) for _ in range(3)]
    if mode == 't2':   # AABB-style overlap: |dx| = V + ext + 0.5 on one axis (V.x = 30 / 90, V.z = 40 / 90 for sel 2 / 3), other axes overlap
        Vax = {2: {'x': 30, 'z': 40}, 3: {'x': 90, 'z': 90}}[sel]
        ax = r.choice(['x', 'z'])
        d = Vax[ax] + ext[0 if ax == 'x' else 2] + r.choice([0.5, -0.5, 0.0])
        posT = (0.0, 0.0, 0.0)
        posE = (d, 0.0, 0.0) if ax == 'x' else (0.0, 0.0, d)

    def w9(em, a):
        for i in range(9): em.w32(a + 4 * i, _fl(ident[i]) if exact else fr(-1.2, 1.2))

    def w3(em, a, span=120, fixed=None):
        for i in range(3):
            em.w32(a + 4 * i, _fl(fixed[i]) if fixed is not None else (fr(-span, span) if r.random() < 0.9 else _fl(r.choice([0.0, 1.0, -1.0]))))
    idv = r.choice([0x1234, 0x77, 0])

    def mk80(owner):
        def side(em, k):
            em.calllog.append(('s80', owner, em.reg('ecx')))
            w9(em, em.arg32(0))
            w3(em, em.arg32(1), r.choice([30, 120, 300]), (posE if owner == 'E' else posT) if exact and posE is not None else None)
        return side

    def dlog(tag, idx):
        return lambda em, k: em.calllog.append((tag, em.reg('ecx'), tuple(em.r32(em.arg32(idx) + 4 * i) for i in range(3))))
    st0f = (lambda em, k: st0v) if st0v is not None else (lambda em, k: r.choice([80.0, 79.5, 0.0, -50.0, 20.0, 100.0, r.uniform(-150, 150)]))
    vtE = {0x80: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=mk80('E')),
           0x1e0: pystub(c, 1, ret=lambda em, k: r.choice([0, 1]), pop=4, this=True),
           0x3a0: pystub(c, 1, ret=_r(c), pop=0, this=True, stackmark=(0,), side=dlog('e3a0', 0)),
           0x398: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(1,), side=dlog('e398', 1)),
           0x84: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=dlog('e84', 0))}
    E = obj(c, 0x60, vtE, nslots=0x3a4 // 4)
    E8 = rnd(c, 0x60)
    for off in range(0x30, 0x4c, 4): e.w32(E8 + off, _fl(0.0) if exact else fr(-50, 50))
    if exact:
        for k_, off in enumerate((0x40, 0x44, 0x48)): e.w32(E8 + off, _fl(ext[k_]))
    e.w32(E + 8, E8)
    vtT = {0x80: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=mk80('T')),
           0x384: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=mk80('T')),
           0x3a0: pystub(c, 1, ret=_r(c), pop=0, this=True, stackmark=(0,), side=dlog('t3a0', 0)),
           0x398: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(1,), side=dlog('t398', 1)),
           0x84: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=dlog('t84', 0)),
           0x194: pystub(c, 1, ret=_r(c), pop=4, this=True, st0=st0f)}
    T = obj(c, 0x8e0, vtT, nslots=0x3a4 // 4)
    T8 = rnd(c, 0x60)
    for off in range(0x30, 0x3c, 4): e.w32(T8 + off, _fl(0.0) if exact else fr(-50, 50))
    e.w32(T + 8, T8)
    t0sub = r.choice(['ylo', 'yhi', 'xz', 'ymid'])
    qv = [float(r.randrange(-5, 6)) for _ in range(3)]
    for i in range(3): e.w32(T + 0x886 + 4 * i, _fl(qv[i]) if mode == 't0' else fr(-100, 100))
    for i in range(9): e.w32(T + 0x892 + 4 * i, _fl(ident[i]) if exact else fr(-1.2, 1.2))
    a0 = rnd(c, 0x60)
    e.w32(a0 + 0x44, E)
    e.w32(a0 + 0x48, sel)
    a1 = rnd(c, 0x40)
    for i in range(9): e.w32(a1 + 4 * i, fr(-1.2, 1.2))
    a2 = rnd(c, 0x20)
    if mode == 't0':
        d = {'ylo': (3.0, -200.0, 4.0), 'yhi': (3.0, 200.0, 4.0), 'xz': (75.0, 0.0, 0.0), 'ymid': (r.choice([0.0, 74.0]), 0.0, r.choice([0.0, 1.0]))}[t0sub]
        for i in range(3): e.w32(a2 + 4 * i, _fl(qv[i] + d[i]))
        a3 = 1
    else:
        for i in range(3): e.w32(a2 + 4 * i, fr(-100, 100))
        a3 = r.choice([0, 1, 2, 0x100, 0x1ff])

    def s150(em, k):
        w9(em, em.arg32(1)); w3(em, em.arg32(2), 150)
    hook_rec(c, 0x58c150, 3, this=True, ret=lambda em, k: r.choice([0, 1, 1, 1]), pop=12, stackmark=(1, 2), side=s150)
    hook_rec(c, 0x41e680, 0, this=True, ret=idv)

    def s2e0(em, k):
        a = em.arg32(0)
        em.calllog.append(('q', tuple(em.r32(a + o) for o in (0, 4, 8, 0xc, 0x10, 0x14, 0x34, 0x44)), em.rbytes(a + 0x6c, 1), em.arg32(2), em.arg32(3), em.arg32(4)))
        em.w32(a + 0x44, r.choice([0, idv, idv, 0x5555]))
    V = obj(c, 0x40, {0x2e0: pystub(c, 6, ret=_r(c), pop=24, this=True, stackmark=(0,), side=s2e0)}, nslots=0x2e4 // 4 + 2)
    so = sysobj(c, slots={}, table_slots={}, table_size=0xb00)
    Tb = e.r32(so + 0x9b)
    e.w32(Tb + 0xadc, V)
    R = obj(c, 0x40, {0xcc: pystub(c, 1, ret=_r(c), pop=4, this=True)}, nslots=0xd0 // 4 + 2)
    e.w32(0x70038c, R)
    return [T, a0, a1, a2, a3]


S(0x58c450, 'proximity_switch_58c450', 'thiscall', None, ret='al', gen=g58c450, note='batch250000')


def g47b290(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))
    import struct as _st, math as _m

    def ceil_stub(em, res_):
        lo, hi = em.arg32(0), em.arg32(1)
        x = _st.unpack('<d', _st.pack('<II', lo, hi))[0]
        em.calllog.append(('ceil', lo, hi))
        v = float(_m.ceil(x)) if _m.isfinite(x) else x
        em.ret(argbytes=0, st0=v)
    e.w32(0x676340, e.stub_fn('ceil', ceil_stub))   # CRT ceil: cdecl, double on the stack, result on the x87 stack

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    def cstr(n, empty=0.15):
        n = 0 if r.random() < empty else r.randrange(1, n + 1)
        a = e.alloc(n + 4, 1)
        e.wbytes(a, bytes(r.randrange(65, 91) for _ in range(n)) + b'\0')
        return a

    def dl(tag, idx, n=3):
        return lambda em, k: em.calllog.append((tag, em.reg('ecx'), tuple(em.r32(em.arg32(idx) + 4 * i) for i in range(n))))
    e.w32(0x6ffa18, r.choice([_fl(1.0), _fl(0.5), _fl(-2.0), 0, 0x7fc00000, _fl(1.0)]))

    def s3a0(em, k):
        a = em.arg32(0)
        for i in range(3): em.w32(a + 4 * i, fr(-50, 50))
    this = obj(c, 0x440, {0x3a0: pystub(c, 1, ret=_r(c), pop=0, this=True, stackmark=(0,), side=s3a0),
                          0x398: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(1,), side=dl('t398', 1)),
                          0x84: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=dl('t84', 0))}, nslots=0x3a4 // 4)
    P = rnd(c, 0x40)
    Rr = rnd(c, 0x20)
    nm = rnd(c, 0x10)
    e.w32(nm + 4, _r(c))
    e.w32(Rr + 4, nm if r.random() < 0.7 else 0)
    e.w32(P + 0x1c, Rr if r.random() < 0.93 else 0)
    Q = rnd(c, 0x50)
    e.w32(Q + 0x3c, r.choice([0x1000, 0x1000, 0x1000, 0, 0x1001]))
    e.w32(this + 8, Q)
    e.w32(this + 0x10, P)
    sp = cstr(12, 0.25)
    fld = e.alloc(8, 4)
    e.w32(fld, sp)
    e.wbytes(this + 0x412, e.rbytes(fld, 4))
    # camera object Z
    def s8c(em, k):
        a = em.arg32(0)
        em.calllog.append(('z8c', em.reg('ecx'), tuple(em.r32(a + 4 * q) for q in range(3))))   # in/out vector: log the input first
        em.w32(a, fr(-80, 80)); em.w32(a + 4, fr(-80, 80))
        em.w32(a + 8, fr(-5, 100) if r.random() < 0.95 else _fl(r.choice([0.0, 10.0])))

    def s240(em, k):
        a = em.arg32(0)
        for i in range(4): em.w32(a + 4 * i, fr(0, 1))
    Z = obj(c, 0x80, {0x8c: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=s8c),
                      0x240: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=s240),
                      0x248: pystub(c, 0, ret=_r(c), pop=0, this=True, st0=lambda em, k: r.choice([1.0, 0.75, 1.5, 2.0, r.uniform(0.2, 3.0)]))}, nslots=0x24c // 4)
    for off in (0x40, 0x58): e.w32(Z + off, fr(0.1, 3))
    Y = obj(c, 0x40, {0x88: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(1,), side=lambda em, k: em.w32(em.arg32(1), r.randrange(0, 5)))}, nslots=0x8c // 4)
    so = sysobj(c, slots={}, table_slots={0x138: pystub(c, 0, ret=Y, this=True), 0x58: pystub(c, 1, ret=Z, pop=4, this=True)}, table_size=0xb00)
    Wd, Ht = r.choice([640, 800, 100, 1]), r.choice([480, 600, 100, 1])
    U = obj(c, 0x40, {0xec: pystub(c, 0, ret=Wd, this=True), 0xf0: pystub(c, 0, ret=Ht, this=True)}, nslots=0xf4 // 4)
    e.w32(so + 0x190f, U)

    def draw(em, res_):
        a3 = em.r32(em.reg('esp') + 16)
        n = 6 if a3 == 0x68aa08 else 4
        args = tuple(em.arg32(i) for i in range(n))
        if n == 4:
            raw = em.rbytes(args[3], 48) if args[3] else b''
            args = args[:3] + (raw.split(b'\0')[0],)
        em.calllog.append(('draw', n) + args)
        em.ret(eax=_r(c), argbytes=0)
    Dd = obj(c, 0x40, {0x184: c.emu.stub_fn('recorder', draw)}, nslots=0x188 // 4)
    sv = e.r32(so)
    e.w32(sv + 0x190, pystub(c, 0, ret=Dd, this=True))
    # string table object [0x7003a4], slot 0x9c(id, out1, out2)

    def s9c(em, k):
        em.w32(em.arg32(1), r.randrange(0, 100))
        em.w32(em.arg32(2), cstr(10, 0.2))
        em.calllog.append(('s9c', em.arg32(0)))
    St = obj(c, 0x40, {0x9c: pystub(c, 3, ret=_r(c), pop=12, this=True, stackmark=(1, 2), side=s9c)}, nslots=0xa0 // 4)
    e.w32(0x7003a4, St)
    a0 = cstr(10, 0.0) if r.random() < 0.7 else 0
    return [this, a0]


S(0x47b290, 'name_label_draw_47b290', 'thiscall', None, ret=None, gen=g47b290, note='batch250000')


def g44ff60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj
    from unicorn.x86_const import UC_X86_REG_EDX
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    def dv(em, a, n):
        return tuple(em.r32(a + 4 * i) for i in range(n))
    N = r.choice([0, 1, 2, 3, 4, 5, 6])
    tie = r.choice([None] * 5 + ['c10000', 'c225', 'm2', 'm2', 'm1', 'm1'])
    X = 40.0
    nS = r.choice([1, 2, 3, 4])
    A = rnd(c, 12 * (2 * N + 4))
    for i in range(3 * (2 * N + 4)): e.w32(A + 4 * i, fr(-5, 5))
    V0 = rnd(c, 12 * N + 12)
    for i in range(3 * N): e.w32(V0 + 4 * i, fr(-5, 5))
    pins = rnd(c, 4 * N + 4)
    for i in range(N): e.w32(pins + 4 * i, r.choice([0, 0, 1]))
    # slots
    slots = rnd(c, 0x10 * nS)
    owners = []
    for i in range(nS):
        sl = slots + 0x10 * i
        e.w32(sl, A if r.random() < 0.5 else rnd(c, 12 * (2 * N + 4)))
        e.w32(sl + 4, _r(c))
        ow = rnd(c, 0x90) if r.random() < 0.6 else 0
        e.w32(sl + 8, ow)
        e.w32(sl + 0xc, fr(0, 3) if r.random() < 0.8 else fr(-3, 100))
    this = obj(c, 0x100, {}, nslots=0x94 // 4)
    # constraints
    nC2 = r.choice([0, 1, 2, 4, 6])
    cons = rnd(c, 16 * nC2 + 16)
    for j in range(nC2):
        rec = cons + 16 * j
        hi = max(2 * N, 1)
        e.wbytes(rec, (r.randrange(0, hi)).to_bytes(2, 'little') + (r.randrange(0, hi)).to_bytes(2, 'little'))
        e.w32(rec + 4, fr(0.05, 1.0)); e.w32(rec + 8, fr(0.0, 0.5)); e.w32(rec + 0xc, fr(0.2, 6))
    nE = 2 * r.choice([0, 1, 2, 3])
    edges = rnd(c, 2 * nE + 8)
    for j in range(nE): e.wbytes(edges + 2 * j, r.randrange(0, max(2 * N, 1)).to_bytes(2, 'little'))
    n3 = r.choice([0, 1, 2, 3])
    l3 = rnd(c, 2 * n3 + 8)
    for j in range(n3): e.wbytes(l3 + 2 * j, r.randrange(0, max(2 * N, 1)).to_bytes(2, 'little'))
    n40 = r.choice([0, 1, 2, 3])
    l40 = rnd(c, 8 * n40 + 8)
    for j in range(n40):
        e.w32(l40 + 8 * j, r.randrange(0, 3 * max(2 * N, 1))); e.w32(l40 + 8 * j + 4, _r(c))
    O = rnd(c, 0x60)
    span = r.choice([5, 40, 200])
    for off in (0x30, 0x34, 0x38): e.w32(O + off, fr(-span, span))
    e.w32(O + 0x4c, _fl(X - 30.0) if tie in ('m1', 'm2') else fr(0.1, 5))
    e.w32(O + 0x3c, _r(c))
    tptr = rnd(c, 8)
    e.w32(tptr, fr(0, 3))
    tie_t = r.random() < 0.3
    # vtable of this: 0x80 (arg0 matrix out, arg1 vec out), 0x90 (in/out vec)

    def w9(em, a):
        ident = [1.0, 0, 0, 0, 1.0, 0, 0, 0, 1.0]
        for i in range(9): em.w32(a + 4 * i, _fl(ident[i] + (0 if tie else r.uniform(-0.3, 0.3))))

    def w3(em, a, sp, fixed=None):
        for i in range(3): em.w32(a + 4 * i, _fl(fixed[i]) if fixed is not None else (0 if tie else fr(-sp, sp)))
    sp80 = r.choice([5, 50, 150])

    def t80(em, k):
        em.calllog.append(('t80', em.reg('ecx')))
        w9(em, em.arg32(0)); w3(em, em.arg32(1), sp80)

    def t90(em, k):
        em.calllog.append(('t90', dv(em, em.arg32(0), 3)))
        w3(em, em.arg32(0), 3)
    vt = e.alloc(0x94 + 4, 4)
    e.w32(vt + 0x80, pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=t80))
    e.w32(vt + 0x90, pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=t90))
    e.w32(this, vt)
    ocnt = r.choice([1, 2, 3]) if tie == 'm2' else r.choice([0, 1, 2, 3])
    objs = []
    for i in range(ocnt):
        sub = obj(c, 0x40, {0x80: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=lambda em, k: (w9(em, em.arg32(0)), w3(em, em.arg32(1), sp80, (X, 0, 0) if tie in ('m2',) else None)))}, nslots=0x84 // 4)
        ob = rnd(c, 0x60)
        e.w32(ob + 0x54, sub if r.random() < 0.8 else 0)
        objs.append(ob)
    e.w32(this + 0x18, r.choice([0, 1, 2, 3]))
    e.w32(this + 0x1c, nS)
    e.w32(this + 0x20, {'m1': 1, 'm2': 2}.get(tie, r.choice([0, 1, 2, 2, 2, 3])))
    e.w32(this + 0x24, r.choice([3, 3, 0, 1]))
    for i in range(3): e.w32(this + 0x28 + 4 * i, _r(c))
    e.w32(this + 0x34, fr(0.2, 1.0))
    e.w32(this + 0x40, n40)
    e.w32(this + 0x44, N)
    e.w32(this + 0x48, nC2)
    e.w32(this + 0x4c, cons)
    e.w32(this + 0x50, edges)
    e.w32(this + 0x54, nE)
    e.w32(this + 0x58, V0)
    e.w32(this + 0x5c, slots)
    e.w32(this + 0x64, pins)
    e.w32(this + 0x68, l40)
    cur = r.choice([0, 0, 1, 1, 1])
    e.w32(this + 0x7c, (slots + 0x10 * r.randrange(0, nS)) if cur else 0)
    if cur:
        sl = e.r32(this + 0x7c)
        e.w32(sl, A)
    e.w32(this + 0x88, n3)
    e.w32(this + 0x8c, l3)
    e.w32(this + 0x90, r.choice([0, 1, 1]))
    Eo = obj(c, 0x40, {0x80: pystub(c, 2, ret=_r(c), pop=8, this=True, stackmark=(0, 1), side=lambda em, k: (w9(em, em.arg32(0)), w3(em, em.arg32(1), sp80, (X, 0, 0) if tie == 'm1' else None)))}, nslots=0x84 // 4)
    e.w32(this + 0x98, Eo if (tie == 'm1' or r.random() < 0.8) else 0)
    e.w32(this + 0x9c, tptr)
    pat = r.choice(['zero', 'zero', 'z', 'y', 'x', 'rand', 'rand'])
    ev = [fr(-span, span) for _ in range(3)]
    if pat == 'zero': ev = [0, 0, 0]
    elif pat == 'z': ev = [0, 0, ev[2]]
    elif pat == 'y': ev = [0, ev[1], 0]
    elif pat == 'x': ev = [ev[0], 0, 0]
    if tie in ('c10000', 'c225'):
        a_, b_, c_ = (float(r.randrange(-5, 6)) for _ in range(3))
        for off, v in zip((0x30, 0x34, 0x38), (a_, b_, c_)): e.w32(O + off, _fl(v))
        dd = 100.0 if tie == 'c10000' else 15.0
        ev = [_fl(a_ - dd), _fl(b_), _fl(c_)]
        e.w32(O + 0x3c, _r(c))
    for i in range(3): e.w32(this + 0xb4 + 4 * i, ev[i])
    e.w32(this + 0xcc, fr(0, 0.12))
    e.wbytes(this + 0xd0, bytes([0 if tie in ('m1', 'm2') else r.choice([0, 1, 1])]))
    e.w32(this + 8, O)
    # engine
    def s1c8(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
        em.calllog.append(('s1c8', em.arg32(0), em.arg32(1)))

    def lg(tag):
        return pystub(c, 3, ret=_r(c), pop=12, this=True, side=lambda em, k: em.calllog.append((tag, em.arg32(0), em.arg32(1), em.arg32(2))))
    Tt = {0xb8: pystub(c, 0, ret=lambda em, k: 1 if r.random() < 0.08 else 0, this=True)}
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=_r(c), pop=8, this=True, side=s1c8), 0x178: lg('l178'), 0x17c: lg('l17c')},
                table_slots=Tt, table_size=0xb00)
    i44 = r.randrange(0, 4000)
    e.w32(so + 0x40, r.randrange(0, 4000)); e.w32(so + 0x44, i44); e.w32(so + 0x48, fr(0, 0.05))
    if tie_t:
        e.w32(tptr, _fl(i44 / 1024.0))
        for i in range(nS):
            if r.random() < 0.5: e.w32(slots + 0x10 * i + 0xc, _fl(i44 / 1024.0))
    e.wbytes(so + 0x9c7, (0 if r.random() < 0.4 else _fl(1.0)).to_bytes(4, 'little'))
    e.wbytes(so + 0x9c3, (0 if r.random() < 0.3 else _fl(2.0)).to_bytes(4, 'little'))
    Cobj = obj(c, 0x40, {0x70: pystub(c, 4, ret=_r(c), pop=16, this=True),
                         0x60: pystub(c, 2, ret=lambda em, k: _r(c), pop=8, this=True)}, nslots=0x74 // 4)

    def s38(em, k):
        n = len(objs) if objs else 0
        n = r.randrange(0, n + 1) if n else 0
        for i in range(n): em.w32(em.arg32(0) + 4 * i, objs[i])
        em.calllog.append(('r38', n, dv(em, em.arg32(3), 9), dv(em, em.arg32(4), 3), dv(em, em.arg32(5), 3)) + tuple(em.arg32(i) for i in (2, 6, 7, 8, 9)))
        em.mu.reg_write(0, 0) if False else None
        s38.n = n
    Robj = obj(c, 0x40, {0x38: pystub(c, 10, ret=lambda em, k: getattr(s38, 'n', 0), pop=40, this=True, stackmark=(0, 1, 3, 4, 5), nullflag=(2,), side=s38)}, nslots=0x3c // 4)
    W = rnd(c, 0x40)
    e.w32(W + 0x18, Cobj); e.w32(W + 0x1c, Robj)
    e.wbytes(so + 0x1aa3, W.to_bytes(4, 'little'))
    # helper recorders
    def rec_a(tag, idxs):
        return lambda em, k: em.calllog.append((tag, em.reg('ecx')) + tuple(em.arg32(i) for i in idxs))
    hook_rec(c, 0x44ef80, 4, this=True, ret=_r(c), pop=16, stackmark=(1,), nullflag=(2,),
             side=lambda em, k: em.calllog.append(('h44ef80', dv(em, em.arg32(1), 3), em.arg32(3), dv(em, em.arg32(2), 3) if em.arg32(2) else ())))
    hook_rec(c, 0x44f0f0, 2, this=True, ret=_r(c), pop=8, side=rec_a('h44f0f0', (1,)))
    hook_rec(c, 0x44f550, 0, this=True, ret=_r(c), pop=0, side=lambda em, k: em.calllog.append(('h44f550', em.reg('ecx'))))
    hook_rec(c, 0x44f8b0, 3, this=True, ret=_r(c), pop=12, stackmark=(0, 1),
             side=lambda em, k: em.calllog.append(('h44f8b0', dv(em, em.arg32(0), 9), dv(em, em.arg32(1), 3), em.arg32(2))))
    hook_rec(c, 0x450fc0, 2, this=True, ret=_r(c), pop=8, stackmark=(1,),
             side=lambda em, k: em.calllog.append(('h450fc0', em.arg32(0), dv(em, em.arg32(1), 3))))
    hook_rec(c, 0x4db9a0, 1, this=True, ret=lambda em, k: r.choice([0, 1, 1]), pop=4)
    return [this]


S(0x44ff60, 'cloth_update_44ff60', 'thiscall', None, ret=None, gen=g44ff60, note='batch250000')


def g599040(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    from recruits_util import sysobj, reftab
    from unicorn.x86_const import UC_X86_REG_EDX
    hook_rec(c, 0x633654, 0, pop=0, side=_log('gs'))

    def fr(lo, hi):
        return _fl(r.uniform(lo, hi))

    def dv(em, a, n):
        return tuple(em.r32(a + 4 * i) for i in range(n))
    this = rnd(c, 0x2400)
    # message ladder float
    e.w32(this + 0x22e3, r.choice([0, _fl(0.3), _fl(0.5), _fl(1.0), _fl(1.5), _fl(2.0), _fl(2.5), _fl(3.0), _fl(3.5), _fl(4.0), _fl(4.5), _fl(5.0), fr(-1, 6), 0x7fc00000]))
    # widget W and UI object U
    W = obj(c, 0x40, {0x128: pystub(c, 1, ret=_r(c), pop=4, this=True), 0x84: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=lambda em, k: em.calllog.append(('w84', dv(em, em.arg32(0), 3))))}, nslots=0x12c // 4)
    e.w32(this + 0x1d0b, W if r.random() < 0.88 else 0)
    U = rnd(c, 0x40)
    e.w32(this + 0x1d0f, U if r.random() < 0.88 else 0)
    e.w32(this + 0x22d7, rnd(c, 0x20))
    # iterator walk
    nIt = r.choice([0, 1, 2, 3])
    elsArr = e.alloc(4 * nIt + 8, 4)
    for i in range(nIt):
        sub = e.alloc(0x60, 4); e.wbytes(sub, bytes(0x60)); e.w32(sub + 0x54, r.choice([1, 2, 0x1234]))
        el = e.alloc(0x20, 4); e.wbytes(el, bytes(0x20)); e.w32(el + 4, sub)
        e.w32(elsArr + 4 * i, el)
    e.w32(this + 0x1da2, elsArr); e.w32(this + 0x1da6, elsArr + 4 * nIt)
    # ref table
    nX = r.choice([0, 1, 2, 3])
    items = []
    for i in range(nX):
        it = rnd(c, 0x20)
        for off in (0xc, 0x10, 0x14): e.w32(it + off, rnd(c, 0x20))
        items.append(it)
    e.w32(this + 0x5c, reftab(c, items) if r.random() < 0.8 else 0)
    # id lists and T slot 0x58
    pool = [obj(c, 0x40, {0x438: pystub(c, 0, ret=lambda em, k: r.choice([0, 0, 1]), this=True)}, nslots=0x43c // 4) for _ in range(4)]
    n1 = r.choice([0, 1, 2, 3, 4])
    for i in range(4): e.w32(this + 0x1dae + 4 * i, _r(c))
    n2 = r.choice([0, 1, 2, 3, 4, 0x80000000 | 1])
    e.w32(this + 0x2e6, n2 if n2 < 0x80000000 else 0xffffffff)
    for i in range(8): e.w32(this + 0xe6 + 4 * i, _r(c))
    e.w32(this + 0x2ea, r.choice([0, 1, 2, 3]))
    e.wbytes(this + 0x1d4f, bytes([r.choice([0, 1])]))
    e.w32(this + 0x4f3, r.choice([0, 7]))
    e.w32(this + 0x1d13, fr(0, 5))
    nM = r.choice([0, 1, 2, 3])
    e.w32(this + 0x1cff, nM)
    for i in range(6 * 3 + 2): e.w32(this + 0x4ff + 4 * i, fr(-5, 5))
    K = r.choice([0, 1, 2, 3])
    e.w32(this + 0x22c2, K)
    for i in range(3 * 6 + 8): e.w32(this + 0x1fa0 + 4 * i, fr(0.5, 3))
    for i in range(4): e.w32(this + 0x1fc6 + 24 * i, fr(-1, 3) if r.random() < 0.7 else _fl(r.choice([0.0, 1.0, -0.5])))   # timers (a negative one is dropped)
    for i in range(4): e.w32(this + 0x1fc2 + 24 * i, fr(0.5, 3))   # durations (divisors)
    for i in range(3): e.w32(this + 0x1fce + 24 * i + 8, r.randrange(0, 13))
    e.w32(this + 0x1fae, n1)
    e.w32(this + 0x1fb6, _r(c))
    e.w32(this + 0x1fba, n1 + r.choice([0, 0, 1, 3, 6]))   # >= the number of classified items, else the unsigned loop count wraps to ~2^32
    e.wbytes(this + 0x22ce, bytes([r.choice([0, 1])]))
    e.w32(this + 0x22cf, fr(0, 3))
    # sys
    def s1c8(em, k):
        em.mu.reg_write(UC_X86_REG_EDX, r.getrandbits(32))
        em.calllog.append(('s1c8', em.arg32(0), em.arg32(1)))

    def lg(tag):
        return pystub(c, 3, ret=_r(c), pop=12, this=True, side=lambda em, k: em.calllog.append((tag, em.arg32(0), em.arg32(1), em.arg32(2))))
    seq58 = []

    def s58(em, k):
        o = pool[r.randrange(len(pool))]
        seq58.append(o)
        return o
    T = {0x114: pystub(c, 6, ret=lambda em, k: (r.getrandbits(16) << 16) | r.getrandbits(16), pop=24, this=True,
                       side=lambda em, k: em.calllog.append(('t114',) + tuple(em.arg32(i) for i in (0, 1, 2, 3, 4, 5)))),
         0x58: pystub(c, 1, ret=lambda em, k: pool[em.arg32(0) % len(pool)], pop=4, this=True, side=lambda em, k: em.calllog.append(('t58', em.arg32(0))))}
    so = sysobj(c, slots={0x1c8: pystub(c, 2, ret=_r(c), pop=8, this=True, side=s1c8), 0x178: lg('l178'), 0x17c: lg('l17c')}, table_slots=T, table_size=0xb00)
    e.w32(so + 0x48, 0 if r.random() < 0.25 else fr(0, 0.05))
    e.w32(so + 0x1b5d, r.choice([1, 1, 0, 2]))
    e.wbytes(so + 0x9c7, (0 if r.random() < 0.4 else _fl(1.0)).to_bytes(4, 'little'))
    e.wbytes(so + 0x9c3, (0 if r.random() < 0.3 else _fl(2.0)).to_bytes(4, 'little'))
    # manager list
    M = rnd(c, 0x8b8 + 4 * 6)
    nL = r.choice([0, 1, 2, 3])
    e.w32(M + 0x8b4, nL)
    for i in range(nL):
        ob = obj(c, 0x40, {0x84: pystub(c, 1, ret=_r(c), pop=4, this=True, stackmark=(0,), side=lambda em, k: em.calllog.append(('m84', em.reg('ecx'), dv(em, em.arg32(0), 3))))}, nslots=0x88 // 4)
        sub = rnd(c, 0x60)
        for off in (0x30, 0x34, 0x38): e.w32(sub + off, fr(-5, 5))
        e.w32(ob + 8, sub)
        e.w32(M + 0x8b8 + 4 * i, ob)
    e.w32(0x7003b8, M)
    # assert handler
    e.w32(0x7003b0, e.stub_fn('assert hook', lambda em, res_: (em.calllog.append(('assert',)), em.ret(eax=_r(c)))))
    # callee recorders
    def hk(addr, n, ret=0, side=None, **kw):
        hook_rec(c, addr, n, this=True, ret=ret, pop=4 * n, side=side or (lambda em, k, a=addr: em.calllog.append(('h%x' % a, em.reg('ecx')) + tuple(em.arg32(i) for i in range(n)))), **kw)
    U2 = rnd(c, 0x40)

    def s58a0(em, k):
        em.calllog.append(('h5a58a0', em.reg('ecx')))
        if r.random() < 0.5: em.w32(this + 0x1d0f, U2)   # the exe re-reads this[0x1d0f] for the next call
    hook_rec(c, 0x5a58a0, 0, this=True, ret=0, pop=0, side=s58a0)
    hk(0x5a5f40, 0); hk(0x5eac90, 0); hk(0x59a8f0, 0); hk(0x5e0df0, 0); hk(0x5b0220, 0); hk(0x5ea960, 0)
    hk(0x4690b0, 0); hk(0x5aaaf0, 0)
    hk(0x5ea870, 1); hk(0x5aab10, 1); hk(0x5a5e90, 1); hk(0x597e00, 1); hk(0x5a5f00, 1)
    hk(0x5b7d40, 1, ret=lambda em, k: r.choice([0, 0, 1]))
    ks = [r.choice([0, 1, 2, 3, 4, 5, 1, 2, 3, 5, 6, 9]) for _ in range(40)]
    cnt59 = [0]

    def k59(em, k):
        v = ks[cnt59[0] % len(ks)]; cnt59[0] += 1
        return v
    hook_rec(c, 0x59ffc0, 0, this=True, ret=k59, pop=0, side=lambda em, k: em.calllog.append(('h59ffc0', em.reg('ecx'))))
    hook_rec(c, 0x5a57a0, 4, this=True, ret=_r(c), pop=16, stackmark=(0,),
             side=lambda em, k: em.calllog.append(('h5a57a0', em.reg('ecx'), dv(em, em.arg32(0), 3), em.arg32(1), em.arg32(2), em.arg32(3))))
    return [this]


S(0x599040, 'hud_controller_599040', 'thiscall', None, ret=None, gen=g599040, note='batch250000')
