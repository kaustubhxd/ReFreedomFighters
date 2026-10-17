"""specs_s244032.py - hand-written specs for batch 244032."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g64ee10(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    import pe_emu

    def sr(emu, k):   # log the SEH try-level (reg.state / [ebp-4]) every callee sees; a per-call log row, not the 8-row recorder
        a = emu.r32(pe_emu.TEB)
        emu.calllog.append(('seh', emu.r32(a + 8) if a != 0xffffffff else -1, emu.r32(a + 4)))

    def lg(nm):
        def s(emu, k):
            emu.calllog.append((nm, emu.arg32(0) if nm in ('s1a4',) else 0))
            sr(emu, k)
        return s
    Q = obj(c, 0x40, {0xdc: pystub(c, 0, ret=lambda emu, k: r.choice([0, 1, 0x100, 0x1ff, r.getrandbits(32)]), pop=0, this=True, side=lg('sdc'))})
    G = obj(c, 0x2000, {0x1a4: pystub(c, 1, ret=r.getrandbits(32), pop=4, this=True, side=lg('s1a4')),
                        0xbc: pystub(c, 0, ret=Q, pop=0, this=True, side=lg('sbc'))})
    em.w32(G + 0x97, r.getrandbits(32))
    head = 0 if r.random() < 0.4 else rnd(c, 0x20)
    em.w32(G + 0x190f, head)
    em.w32(0x70039c, G)
    em.w32(0x6f5a98, r.choice([0x10, 0x40, 0x2c, 0x100]))

    def alloc(emu, k):
        n = emu.arg32(0)
        emu.calllog.append(('alloc', n))
        return 0 if r.random() < 0.2 else em.alloc(0x110, 4)

    def side_alloc(emu, k):
        sr(emu, k)
    hook_rec(c, 0x41e290, 1, ret=alloc, pop=0, side=side_alloc)
    hook_rec(c, 0x660c80, 0, ret=r.getrandbits(32), pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('c80',)), sr(emu, k)))
    hook_rec(c, 0x4ccad0, 2, ret=lambda emu, k: r.getrandbits(32) if r.random() < 0.5 else emu.reg('ecx'), pop=8, this=True, side=lambda emu, k: (emu.calllog.append(('ccad0',)), sr(emu, k)))
    for ad in (0x4d8330, 0x4d83b0):
        hook_rec(c, ad, 3, ret=lambda emu, k: r.choice([0, em.alloc(0x20, 4), r.getrandbits(32)]), pop=12, this=True, side=lambda emu, k, ad=ad: (emu.calllog.append((hex(ad),)), sr(emu, k)))
    hook_rec(c, 0x4d8180, 2, ret=lambda emu, k: r.choice([0, em.alloc(0x20, 4), r.getrandbits(32)]), pop=8, this=True, side=lambda emu, k: (emu.calllog.append(('d8180',)), sr(emu, k)))
    hook_rec(c, 0x650f30, 1, ret=r.getrandbits(32), pop=4, this=True, side=lambda emu, k: (emu.calllog.append(('f30',)), sr(emu, k)))
    hook_rec(c, 0x634d10, 3, ret=r.getrandbits(32), pop=0, side=lambda emu, k: (emu.calllog.append(('memset', emu.arg32(1), emu.arg32(2))), sr(emu, k)))
    me = rnd(c, 0x200)
    return [me, r.getrandbits(32), r.getrandbits(32)]


S(0x64ee10, 'GUESS constructor: registers 7 helper objects with the engine, links into the engine list', 'thiscall', 2, ret='eax', gen=g64ee10, note='batch244032')


def g428b60(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    import pe_emu

    def sr(emu, k):   # try level of the SEH record every callee sees
        a = emu.r32(pe_emu.TEB)
        emu.calllog.append(('seh', emu.r32(a + 8) if a != 0xffffffff else -1, emu.r32(a + 4) if a != 0xffffffff else -1))

    def lg(nm, *idx):
        def s(emu, k):
            emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in idx))
            sr(emu, k)
        return s

    def fmt(emu, k):
        f = emu.arg32(1)
        emu.calllog.append(('fmt', f, emu.arg32(2) if f == 0x6791b0 else None))
        sr(emu, k)
    LO = obj(c, 0x40, {0x2c: pystub(c, 2, ret=r.getrandbits(32), pop=0, side=fmt)})
    MG = obj(c, 0x40, {0x20: pystub(c, 2, ret=LO, pop=8, this=True, side=lg('mg20', 0, 1))})
    em.w32(0x700390, MG)

    def al(emu, k):
        n = emu.arg32(0)
        emu.calllog.append(('alloc', n))
        return 0 if r.random() < 0.25 else em.alloc(0x200, 4)
    hook_rec(c, 0x41e290, 1, ret=al, pop=0, side=sr)
    for ad in (0x428440, 0x4284f0, 0x428560):
        hook_rec(c, ad, 4, ret=lambda emu, k: r.choice([0, em.alloc(0x40, 4), r.getrandbits(32)]), pop=16, this=True, side=lambda emu, k, ad=ad: (emu.calllog.append((hex(ad),)), sr(emu, k)))
    hook_rec(c, 0x429470, 0, ret=lambda emu, k: r.choice([0, 1, 5, 0x100]), pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('9470',)), sr(emu, k)))
    for ad in (0x435d30, 0x435d50, 0x435d70, 0x4361a0):
        hook_rec(c, ad, 1, ret=r.getrandbits(32), pop=4, this=True, side=lambda emu, k, ad=ad: (emu.calllog.append((hex(ad), emu.arg32(0))), sr(emu, k)))
    S_ = rnd(c, 0x140)
    typ = r.choice(list(range(0x0f, 0x1f)) + [0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x1c, 0x1d])
    b25 = r.choice([0, 1, 2, 3, 4, 5, 7])
    flag = r.choice([0, 0, 1])
    em.w32(S_ + 0x24, typ | (b25 << 8) | (flag << 16) | (r.getrandbits(8) << 24) | (r.choice([0, 0, 2, 0x80]) << 16 if not flag else 0))
    if not flag:
        em.w32(S_ + 0x24, (em.r32(S_ + 0x24) & ~0x10000) & 0xffffffff)
    a1 = rnd(c, 0x40)
    return [S_, a1]


S(0x428b60, 'GUESS object factory by type byte (jump table 0x11..0x1c) + registration', 'stdcall', 2, ret='eax', gen=g428b60, note='batch244032')


def g65cc70(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    import pe_emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, -0.0, 1.0, -1.0, 0.5, 2.0, 100.0, -3.25, float('nan'), r.uniform(-10, 10)]

    def sr(emu, k):
        a = emu.r32(pe_emu.TEB)
        emu.calllog.append(('seh', emu.r32(a + 8) if a != 0xffffffff else -1, emu.r32(a + 4) if a != 0xffffffff else -1))

    def rb(n):
        return b''.join(pk(r.choice(FV)) for _ in range(n // 4))

    def lg(nm, *idx):
        def s(emu, k):
            emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in idx))
            sr(emu, k)
        return s
    shrink = r.random() < 0.3   # later 0x4db550 calls report a smaller count (the in-loop bounds test); no W takes the 0x10000 path then
    # --- the element objects (vtable slots 0x358 and 0x94) and what hangs off them
    def mk_w():
        w = rnd(c, 0x100)
        em.w32(w + 0x3c, r.choice([0, 1]) if shrink else r.choice([0, 0x10000, 0x10000, 0x10000, 0x1, 0xffffffff]))
        for o in (0, 4, 8):
            em.wbytes(w + o, pk(r.choice(FV)))
        return w
    Ws = [mk_w() for _ in range(2)]
    Qs = [rnd(c, 0x20) for _ in range(2)]
    for q, w in zip(Qs, Ws):
        em.w32(q + 8, w)
    P54s = [obj(c, 0x40, {0x240: pystub(c, 0, ret=q, pop=0, this=True, side=lg('s240'))}) for q in Qs]
    O1s = []
    for p in P54s:
        o1 = rnd(c, 0x80)
        em.w32(o1 + 0x54, p)
        O1s.append(o1)

    def s94(emu, k):
        emu.calllog.append(('s94', bytes(emu.rbytes(emu.arg32(1), 12))))
        emu.wbytes(emu.arg32(0), rb(48))
        sr(emu, k)

    def mk_el():
        o = obj(c, 0x400, {0x358: pystub(c, 0, ret=lambda emu, k: 0 if r.random() < 0.15 else r.choice(O1s), pop=0, this=True, side=lg('s358')),
                           0x94: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, stackmark=(0, 1), side=s94)})
        return o
    OBJS = [mk_el() for _ in range(4)]
    T2s = []
    for _ in range(3):
        t2 = rnd(c, 0x40)
        cnt = r.choice([0, 1, 1, 2, 3])
        em.wbytes(t2 + 0x1c, bytes([cnt]))
        for j in range(3):
            em.w32(t2 + 4 * j, r.choice(OBJS))
        T2s.append(t2)
    T1s = [rnd(c, 0x40) for _ in range(3)]
    t1map = {t1: t2 for t1, t2 in zip(T1s, T2s)}
    T2sh = []
    for t2 in T2s:
        t = rnd(c, 0x40)
        em.wbytes(t, bytes(em.rbytes(t2, 0x40)))
        cnt = em.rbytes(t2 + 0x1c, 1)[0]
        em.wbytes(t + 0x1c, bytes([max(cnt - 1, 0)]))
        T2sh.append(t)
    t1sh = {t1: t2 for t1, t2 in zip(T1s, T2sh)}
    ncall = {}

    def b550(emu, k):
        t1 = emu.reg('ecx')
        n = ncall.get(t1, 0)
        ncall[t1] = n + 1
        return (t1sh if (shrink and n > 0) else t1map).get(t1, T2s[0])
    # --- iteration structure
    sz = r.choice([1, 2, 3])
    C2 = rnd(c, 0x40)
    em.w32(C2, r.choice([1, 2]))
    em.w32(C2 + 8, 0)
    C = rnd(c, 0x40)
    em.w32(C, sz)
    em.w32(C + 8, C2 if r.random() < 0.6 else 0)
    Es = []

    def mk_e():
        e = rnd(c, 0x100)
        em.w32(e + 0x3c, r.choice([0x1000, 0x1000, 0x1000, 0, 0x21000, 0xffffffff]))
        return e
    for base, n in ((C, sz), (C2, em.r32(C2))):
        for i in range(n):
            node = rnd(c, 0x60)
            e = mk_e()
            Es.append(e)
            em.w32(node + 0x38, e)
            em.w32(base + 0x10 + 4 * i, node)
    i0 = r.randrange(0, sz)
    R = rnd(c, 0x20)
    em.w32(R, C + 0x10 + 4 * i0)
    em.w32(R + 4, i0)
    em.w32(R + 8, C)
    if r.random() < 0.08:
        em.w32(R, 0)
    X1 = rnd(c, 0x400)
    vt = em.alloc(0x40, 4)
    em.w32(vt + 0xc, pystub(c, 1, ret=R, pop=4, this=True, stackmark=(0,), side=lg('sc')))
    em.w32(X1 + 0x1c8, vt)
    me = rnd(c, 0x500)
    em.w32(me + 0x424, X1)
    K = rnd(c, 0x20)
    em.w32(K + 4, r.choice([0, 0, 1, 5]))
    M = rnd(c, 0x20)
    em.w32(M + 4, r.getrandbits(32))
    em.w32(M + 8, r.choice([0, 1, 1, 2, 3]))
    em.w32(me + 0x40c, K)
    em.w32(me + 0x408, M)
    em.w32(me + 0x41c, r.getrandbits(32))
    em.w32(me + 0x410, r.getrandbits(32))
    # --- manager and engine
    LO = obj(c, 0x40, {0x2c: pystub(c, 3, ret=r.getrandbits(32), pop=0, side=lg('log2c', 1, 2))})
    MG = obj(c, 0x40, {0x20: pystub(c, 2, ret=LO, pop=8, this=True, side=lg('mg20', 0, 1))})
    em.w32(0x700390, MG)
    em.w32(0x7003b0, 0)
    B1 = rnd(c, 0x40)
    P3 = [rnd(c, 0x100) for _ in range(3)]
    for p in P3:
        em.w32(p + 0x3c, r.choice([0x21000, 0x21000, 0x21001, 0x1000, 0, 0xffffffff, 0x20000]))

    def big(emu, k):
        n = r.choice([0, 1, 2, 3, 3])
        emu.calllog.append(('big', n, bytes(emu.rbytes(emu.arg32(1), 48)), bytes(emu.rbytes(emu.arg32(5), 12)), bytes(emu.rbytes(emu.arg32(6), 12))))
        for j in range(n):
            emu.w32(emu.arg32(0) + 4 * j, r.choice(P3))
        st_big['n'] = n
        sr(emu, k)
    st_big = {'n': 0}
    X3 = obj(c, 0x80, {0x3c: pystub(c, 11, ret=lambda emu, k: st_big['n'], pop=44, this=True, stackmark=(0, 1, 4, 5, 6), side=big)})
    X2 = rnd(c, 0x40)
    em.w32(X2 + 0x1c, X3)
    G = rnd(c, 0x2000)
    em.w32(G + 0x1aa3, X2)
    em.w32(0x70039c, G)
    # --- hooks
    hook_rec(c, 0x640c10, 1, ret=lambda emu, k: r.choice([0, 1, 1, 0x100]), pop=4, this=True, side=lg('c10', 0))
    for ad in (0x4daf90, 0x4db670):
        hook_rec(c, ad, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k, ad=ad: (emu.wbytes(emu.arg32(0), rb(12)), emu.calllog.append((hex(ad), emu.reg('ecx'))), sr(emu, k)))
    hook_rec(c, 0x4db7c0, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k: (emu.wbytes(emu.arg32(0), rb(12)), emu.calllog.append(('b7c0',)), sr(emu, k)))
    hook_rec(c, 0x4dafb0, 0, ret=lambda emu, k: 0 if r.random() < 0.15 else r.choice(T1s), pop=0, this=True, side=lg('afb0'))
    hook_rec(c, 0x4db550, 0, ret=b550, pop=0, this=True, side=lg('b550'))
    hook_rec(c, 0x4da2f0, 2, ret=lambda emu, k: B1, pop=8, this=True, stackmark=(0,), side=lg('a2f0', 1))
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=lg('c1d0'))
    hook_rec(c, 0x4cbec0, 0, ret=r.getrandbits(32), pop=0, this='mark', side=lg('bec0'))
    for ad in (0x65cb00, 0x65ca80, 0x65da30, 0x640c90):
        hook_rec(c, ad, 1, ret=lambda emu, k: r.choice([0, 1, 1, 0x100]), pop=4, this=True, side=lg(hex(ad), 0))
    hook_rec(c, 0x4db2a0, 1, ret=r.getrandbits(32), pop=4, this=True, stackmark=(0,), side=lambda emu, k: (emu.wbytes(emu.arg32(0), rb(48)), emu.calllog.append(('b2a0', emu.reg('ecx'))), sr(emu, k)))
    hook_rec(c, 0x4e0d40, 1, ret=r.getrandbits(32), pop=4, this='mark', side=lambda emu, k: (emu.wbytes(emu.reg('ecx'), rb(12)), emu.calllog.append(('e0d40', emu.arg32(0))), sr(emu, k)))

    def n43(emu, k):
        emu.calllog.append(('e8e0', bytes(emu.rbytes(emu.reg('edx'), 24)), bytes(emu.rbytes(emu.arg32(0), 12))))
        emu.wbytes(emu.reg('ecx'), rb(12))
        sr(emu, k)
    hook_rec(c, 0x43e8e0, 1, ret=r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=n43)
    return [me]


S(0x65cc70, 'GUESS per-frame scene object traversal (visibility/occluder test with matrices)', 'thiscall', 0, ret='eax', gen=g65cc70, note='batch244032')
