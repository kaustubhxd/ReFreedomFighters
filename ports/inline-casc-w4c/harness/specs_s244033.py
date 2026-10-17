"""specs_s244033.py - hand-written specs for batch 244033."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain
import pe_emu
from unicorn.x86_const import UC_X86_REG_EDX


def g617e20(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, -0.0, 1.0, 0.5, 2.0, -3.0, 100.0, float('nan'), 1e-30, r.uniform(-9, 9)]

    def sr(emu, k):
        a = emu.r32(pe_emu.TEB)
        emu.calllog.append(('seh', emu.r32(a + 8) if a != 0xffffffff else -1))

    def rb(n):
        return b''.join(pk(r.choice(FV)) for _ in range(n // 4))

    def isheap(v):
        return 0x20000000 <= v < 0x30000000

    def dev(name, nargs, pop, ptr_i=None, cnt_i=None, fixed=None):
        """device/wrapper stdcall slot: logs args, and the vec4 block behind a stack pointer argument"""
        def side(emu, k):
            row = [emu.arg32(i) for i in range(nargs)]
            ex = None
            if ptr_i is not None:
                p = row[ptr_i]
                if not isheap(p):
                    n = min(row[cnt_i], 9) * 16 if cnt_i is not None else fixed
                    ex = bytes(emu.rbytes(p, n))
                    row[ptr_i] = 'stk'
            emu.calllog.append((name, tuple(row), ex))
            sr(emu, k)
        return pystub(c, nargs, ret=r.getrandbits(32), pop=pop, stackmark=((ptr_i,) if ptr_i is not None else ()), side=side)
    # --- globals
    G = rnd(c, 0x2000)
    em.wbytes(G + 0x9c7, pk(r.choice(FV)))
    em.wbytes(G + 0x9c3, pk(r.choice(FV)))
    pair_hi = r.getrandbits(32)

    def s1c8(emu, k):
        emu.calllog.append(('s1c8', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, pair_hi)
        sr(emu, k)

    def s17(nm):
        return pystub(c, 3, ret=r.getrandbits(32), pop=12, this=True, side=lambda emu, k: (emu.calllog.append((nm, emu.arg32(0), emu.arg32(1), emu.arg32(2))), sr(emu, k)))
    Gv = obj(c, 0x2000, {0x1c8: pystub(c, 2, ret=r.getrandbits(32), pop=8, this=True, side=s1c8), 0x178: s17('s178'), 0x17c: s17('s17c')})
    for o in range(0x9c3, 0x9cb):   # keep the float fields the vtable-bearing object returns
        em.wbytes(Gv + o, bytes(em.rbytes(G + o, 1)))
    Z = rnd(c, 0x40)
    B = rnd(c, 0x200)
    em.w32(Z + 0x20, B)
    em.w32(Gv + 0x1aa3, Z)
    em.w32(0x70039c, Gv)
    Dobj = obj(c, 0x40, {0x130: dev('d130', 2, 8), 0x14c: dev('d14c', 4, 16), 0x154: dev('d154', 3, 12), 0x11c: dev('d11c', 6, 24)})
    em.w32(0x724a00, Dobj)
    same = r.random() < 0.5
    gv = r.getrandbits(32)
    em.w32(0x724a54, gv)
    em.w32(0x7249f8, gv if same else r.getrandbits(32))
    x1 = r.choice([1.0, 0.5, 4.0, 2.0, 0.25])
    em.wbytes(0x724964, pk(x1))
    em.wbytes(0x724960, pk(r.choice([x1, 0.0, 0.25, -1.0])))
    # --- device (ebx), a1 and its helpers
    ebx = obj(c, 0x40, {0xfc: dev('v0fc', 4, 16), 0xc8: dev('v0c8', 3, 12), 0x13c: dev('v13c', 4, 16, ptr_i=2, cnt_i=3)})
    Oa = obj(c, 0x40, {0x8: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('oa8',)), sr(emu, k)))})
    em.w32(Oa + 0x30, r.choice([0, 0, 1, 7]))
    ea = r.getrandbits(32)
    em.w32(Oa + 0x2c, ea)
    em.w32(0x724970, ea if r.random() < 0.5 else r.getrandbits(32))
    em.w32(0x7249b0, r.choice([0x34, 0x34, 5]))
    Ob = obj(c, 0x40, {0x8: pystub(c, 0, ret=r.getrandbits(32), pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('ob8',)), sr(emu, k)))})
    em.w32(Ob + 0x18, r.choice([0, 0, 1, 7]))
    eb = r.getrandbits(32)
    em.w32(Ob + 0x14, eb)
    Y = rnd(c, 0xc0)
    n = r.choice([0, 1, 2, 3])
    em.w32(Y + 0x98, n)
    ofs = r.choice([0, 8, 16])
    em.w32(Y + 0x9c, ofs)
    for j in range(3):
        em.w32(B + ofs + 8 * j, r.choice([0, 4, 8, 16, 64, 2, 7, 13]))
        em.w32(B + ofs + 8 * j + 4, r.choice([0, 1, 2, 5, 12]))
    a1 = obj(c, 0x1500, {0x29c: pystub(c, 3, ret=r.getrandbits(32), pop=12, this=True, side=lambda emu, k: (emu.calllog.append(('s29c', emu.arg32(0), emu.arg32(1), emu.arg32(2))), sr(emu, k)))})
    em.w32(a1 + 0x1377, ebx)
    em.w32(a1 + 0x1402, Oa)
    em.w32(a1 + 0x140a, Ob)
    # --- this / a0
    Bn = rnd(c, 0x20)
    em.w32(Bn + 8, Y)
    nrec = r.choice([0, 1, 2, 3])
    recs = rnd(c, 0x40)
    A = rnd(c, 0x40)
    em.w32(A + 4, Bn)
    em.w32(A + 0xc, nrec)
    em.w32(A + 0x14, recs)
    em.w32(A + 0x24, r.getrandbits(32))
    em.w32(A + 0x28, r.choice([0x1234, 0, r.getrandbits(32)]))
    em.w32(0x7249f4, em.r32(A + 0x28) if r.random() < 0.5 else r.getrandbits(32))
    em.w32(0x7249f0, em.r32(Ob + 0x14) if r.random() < 0.5 else r.getrandbits(32))
    me = rnd(c, 0x40)
    em.w32(me + 4, A)
    a0 = rnd(c, 0x40)
    for off in (0x20, 0x24, 0x28):
        m = rnd(c, 0x40)
        em.w32(a0 + off, m)
    Rv = rnd(c, 0x20)
    Qo = rnd(c, 0x20)
    em.w32(Qo + 8, Rv)
    em.w32(a0 + 0x14, Qo)
    Ma = rnd(c, 0x80)
    for o in range(0, 0x70, 4):
        if r.random() < 0.7:
            em.wbytes(Ma + o, pk(r.choice(FV)))
    Mbuf = rnd(c, 0x20)
    # --- hooks for the exe helpers
    def m3(emu, k):
        emu.calllog.append(('mat', bytes(emu.rbytes(emu.arg32(1), 64)), bytes(emu.rbytes(emu.arg32(2), 64))))
        emu.wbytes(emu.arg32(0), rb(64))
        sr(emu, k)
    hook_rec(c, 0x410f26, 3, ret=r.getrandbits(32), pop=12, stackmark=(0, 1, 2), side=m3)

    def m2(emu, k):
        emu.calllog.append(('inv', bytes(emu.rbytes(emu.arg32(1), 64))))
        emu.wbytes(emu.arg32(0), rb(64))
        sr(emu, k)
    hook_rec(c, 0x411009, 2, ret=r.getrandbits(32), pop=8, stackmark=(0, 1), side=m2)
    hook_rec(c, 0x658d80, 0, ret=Mbuf, pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('d80', emu.reg('ecx'))), sr(emu, k)))
    hook_rec(c, 0x658db0, 0, ret=Ma, pop=0, this=True, side=lambda emu, k: (emu.calllog.append(('db0', emu.reg('ecx'))), sr(emu, k)))

    def f9(emu, k):
        emu.calllog.append(('f9', emu.reg('edx'), emu.arg32(0)))
        emu.wbytes(emu.reg('ecx'), rb(16))
        sr(emu, k)
    hook_rec(c, 0x459fc0, 1, ret=r.getrandbits(32), pop=4, this='mark', side=f9)
    for j in range(nrec):
        em.w32(recs + 8 * j, r.choice([0, 3, 100, 0x7fffffff]))
        em.w32(recs + 8 * j + 4, r.getrandbits(32))
    return [me, a0, a1]


S(0x617e20, 'GUESS render pass: matrices -> device constants, draw records', 'thiscall', 2, ret='eax', gen=g617e20, note='batch244033')


def g54cec0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu

    def sr(emu, k):
        pass

    def stub(nm, nargs, ret=0, floatarg=False):
        def side(emu, k):
            emu.calllog.append((nm,) + tuple(emu.arg32(i) for i in range(nargs)))
        return pystub(c, nargs, ret=ret, pop=4 * nargs, this=True, side=side)
    flags = lambda emu, k: r.choice([0, 1, 0x100, 0x1ff])
    # children
    nch = r.choice([0, 1, 2, 3, 3])
    kids = []
    def mkkid():
        k_ = obj(c, 0x100, {0x24: stub('k24', 0), 0x48: stub('k48', 1), 0x40: stub('k40', 0), 0x1c: stub('k1c', 1)})
        em.w32(k_ + 0x61, r.choice([1, 2, 3]))
        em.wbytes(k_ + 0x7d, bytes([r.choice([0, 1, 1, 5])]))
        em.wbytes(k_ + 0x7b, bytes([r.choice([0, 1])]))
        return k_
    for i in range(nch):
        kids.append(0 if r.random() < 0.15 else mkkid())
    arr = rnd(c, 0x40)
    for i, k_ in enumerate(kids):
        em.w32(arr + 4 * i, k_)
    # objects returned by this' slots
    Ds = []
    for _ in range(2):
        d = rnd(c, 0x40)
        em.w32(d + 0x20, r.choice([0, 0, 1, 5]))
        em.w32(d + 8, r.choice([-1, 0, 1, 7]) & 0xffffffff)
        Ds.append(d)
    Xs = [obj(c, 0x100, {0x8: pystub(c, 2, ret=flags, pop=8, this=True, side=lambda emu, k: emu.calllog.append(('x8', emu.arg32(0), emu.arg32(1)))),
                         0x40: stub('x40', 0), 0x1c: stub('x1c', 1)}) for _ in range(2)]
    O49 = obj(c, 0x40, {0x28: stub('o28', 1)})
    this_slots = {0x48: pystub(c, 1, ret=lambda emu, k: 0 if r.random() < 0.15 else r.choice(Ds), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('t48', emu.arg32(0)))),
                  0x8: pystub(c, 3, ret=lambda emu, k: 0 if r.random() < 0.2 else r.choice(Xs), pop=12, this=True, side=lambda emu, k: emu.calllog.append(('t8', emu.arg32(0), emu.arg32(1), emu.arg32(2)))),
                  0x10: stub('t10', 0), 0x14: stub('t14', 0), 0x7c: stub('t7c', 0), 0x84: stub('t84', 0),
                  0x60: stub('t60', 2), 0x64: stub('t64', 2), 0x68: stub('t68', 2), 0x88: stub('t88', 2), 0x80: stub('t80', 2),
                  0x34: stub('t34', 1)}
    me = obj(c, 0x8200, this_slots)
    em.w32(me + 0x805d, nch)
    em.w32(me + 0x803d, arr)
    em.w32(me + 0x8061, r.choice([0, 1]))
    em.w32(me + 0x8049, O49)
    em.w32(me + 0x8035, r.getrandbits(32))
    em.wbytes(me + 0x801c, bytes([r.choice([0, 1, 7])]))
    em.w32(me + 4, r.getrandbits(32))
    em.w32(0x7003b0, pystub(c, 0, ret=r.getrandbits(32), pop=0, side=lambda emu, k: emu.calllog.append(('brk',))))
    em.wbytes(0x713e18, bytes([r.choice([0, 1, 9]), r.choice([0, 1, 9])]))
    # --- record stream
    buf = rnd(c, 0x800)
    pos = 0
    top = [1, 2, 4, 5, 0x20, 0x30, 0x32, 0x50, 0x80, 0x81, 0x100, 0x101, 0x102, 0x200, 0x1000, 0x1100, 0x1200, 0x1, 0x2, 0x4, 0x50, 0x101, 3, 7, 0x300, 0x2000, 0]
    subt = [0x40, 0x41, 0x42, 0x44, 0x70, 0x71, 0x43, 0x45, 0x60, 0x10, 0x80, 0x41, 0x42, 0x71]

    def rec(t, size=None):
        nonlocal pos
        if t in (4, 5):   # these loops call straight through the child pointers
            for i, k_ in enumerate(kids):
                if not k_:
                    kids[i] = mkkid()
                    em.w32(arr + 4 * i, kids[i])
        size = size or r.choice([0x28, 0x2c, 0x30, 0x40, 0x48])
        em.w32(buf + pos, t)
        em.w32(buf + pos + 4, size)
        if t in (1, 2, 4, 0x50, 0x1200) or r.random() < 0.7:
            em.w32(buf + pos + 8, r.choice([1, 2, 3, 0, 0, 7]))
        if t in (1, 2):
            em.w32(buf + pos + 0x1c, r.choice([1, 2, 3, 0]))
            em.w32(buf + pos + 0x20, r.getrandbits(32))
            em.w32(buf + pos + 0x18, r.choice([0, 0, 1]))
            em.w32(buf + pos + 0xc, r.choice([0, 0, 9]))
            em.w32(buf + pos + 0x14, r.getrandbits(32))
        if t == 0x101:
            nul = r.randrange(0, size - 0xc)
            for j in range(size - 0xc):
                em.wbytes(buf + pos + 0xc + j, bytes([0 if j == nul and r.random() < 0.8 else r.randrange(1, 255)]))
            em.wbytes(buf + pos + size - 1, b'\0')
        pos += size
    n = r.choice([0, 1, 2, 3, 4, 5])
    for _ in range(n):
        t = r.choice(top)
        rec(t)
        if t == 0x30:
            for _ in range(r.choice([0, 1, 2, 3, 4, 5])):
                rec(r.choice(subt), r.choice([0x10, 0x14, 0x18]))
            rec(0x31, 8)
    rec(0x10000, 8)
    em.w32(me + 0x801d, buf)
    return [me]


S(0x54cec0, 'GUESS render command-stream interpreter (record types, nested vertex stream)', 'thiscall', 0, ret='eax', gen=g54cec0, note='batch244033')


def g64abb0(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    pk = lambda v: struct.pack('<f', v)
    FV = [0.0, 1.0, -1.0, 0.5, 2.0, -3.0, 100.0, 1e-3, float('nan'), r.uniform(-9, 9)]

    def isheap(v):
        return 0x20000000 <= v < 0x30000000

    def rv(emu, p, n):
        return ('h', p) if isheap(p) else ('s', bytes(emu.rbytes(p, n)))

    zero_mode = r.random() < 0.25   # every vector the hooks write is 0: dot products and thresholds tie exactly (the >= / > mutants)

    def rb(n):
        if zero_mode:
            return bytes(n)
        return b''.join(pk(r.choice(FV)) for _ in range(n // 4))
    # --- argument blocks
    T = rnd(c, 0x18400)
    Ct = rnd(c, 0x80)
    em.w32(T + 0x1005d, Ct)
    for off in (0x1007d, 0x10079):
        em.w32(T + off, r.getrandbits(32))
    Pq = rnd(c, 0x40)
    planes = rnd(c, 0x100)
    for i in range(0, 0x60, 4):
        em.wbytes(planes + i, pk(0.0 if zero_mode else r.choice(FV)))
    cnt = r.choice([0, 1, 2, 3, 6])
    a5 = rnd(c, 0x40)
    a6 = rnd(c, 0x40)
    a1 = r.getrandbits(32)
    f7 = r.choice([0.0, 1.0, 0.5, 255.0, 300.0, -2.0, 0.999])

    def flagblk(vals):
        b = rnd(c, 0x40)
        em.w32(b + 0x23, r.choice(vals))
        return b

    def mk_c(vals):
        cc = rnd(c, 0x40)
        em.w32(cc + 0xc, flagblk(vals))
        return cc
    # --- list 1 (next through hook 0x4db520)
    nxt = {}
    Q2 = obj(c, 0x40, {0xf4: pystub(c, 2, ret=lambda emu, k: r.choice([0, 1, 0x100]), pop=8, this=True, side=lambda emu, k: emu.calllog.append(('f4', emu.arg32(0), emu.arg32(1))))})
    Q1 = rnd(c, 0x80)
    em.w32(Q1 + 0x54, Q2)
    Rp = rnd(c, 0x80)
    em.w32(Rp + 0x38, Q1)
    Rs = []
    for _ in range(3):
        rr = rnd(c, 0x80)
        em.w32(rr + 0xc, 0 if r.random() < 0.5 else rnd(c, 0x40))
        em.w32(rr + 8, Rp)
        em.wbytes(rr + 5, bytes([r.choice([0, 0x40, 0x50, 0x10, 0xff])]))
        Rs.append(rr)
    l1 = []
    for _ in range(r.choice([0, 1, 2, 3])):
        n_ = rnd(c, 0x80)
        em.w32(n_ + 0x54, 0 if r.random() < 0.3 else mk_c([0x200002, 0x4000000, 0x1, 0x200000, 0x0, 0x300000, 0x100000]))
        em.w32(n_ + 0x3c, r.choice([0, 0, 0x400, 0x2000, 0x200000, 0x1000]))
        em.wbytes(n_ + 0x4c, pk(0.0 if zero_mode else r.choice(FV)))
        l1.append(n_)
    for i, n_ in enumerate(l1):
        nxt[n_] = l1[i + 1] if i + 1 < len(l1) else 0
    # --- list 2 (next at +0x60); the objects Co also serve as recursion targets
    l2 = []
    for _ in range(r.choice([0, 1, 2])):
        n_ = rnd(c, 0x80)
        co = obj(c, 0x80, {0x2a8: pystub(c, 0, ret=lambda emu, k: r.choice([0, 0, 0x1, 0x8000]), pop=0, this=True, side=lambda emu, k: emu.calllog.append(('a8', emu.reg('ecx'))))})
        em.w32(co + 0xc, flagblk([0x100000, 0x100000, 0x100000, 0x0, 0x300000]))
        em.w32(co + 0x30, r.choice([0, 0, 0, 0x400, 0x800]))
        em.w32(co + 8, rnd(c, 0x80))
        em.w32(co + 0x54, 0)
        em.w32(co + 0x50, 0)
        em.w32(n_ + 0x54, co)
        em.w32(n_ + 0x3c, r.choice([0, 0, 0, 0x400, 0x2000]))
        em.wbytes(n_ + 0x4c, pk(0.0 if zero_mode else r.choice(FV)))
        l2.append(n_)
    for i, n_ in enumerate(l2):
        em.w32(n_ + 0x60, l2[i + 1] if i + 1 < len(l2) else 0)
    O = rnd(c, 0x80)
    em.w32(O + 8, Pq)
    em.w32(O + 0x54, l1[0] if l1 else 0)
    em.w32(O + 0x50, l2[0] if l2 else 0)
    # --- hooks
    def lg(nm):
        return lambda emu, k, nm=nm: emu.calllog.append((nm,))
    hook_rec(c, 0x648a40, 1, ret=r.getrandbits(32), pop=4, this=True, side=lambda emu, k: emu.calllog.append(('a40', emu.arg32(0))))
    hook_rec(c, 0x4db3b0, 0, ret=lambda emu, k: r.getrandbits(32), pop=0, this=True, side=lg('db3b0'))

    def fc(nm, nstk, wsz, edx_n=12, stk_stack=()):
        """fastcall helper: ecx = stack out buffer (written), edx = pointer logged by content/value, nstk stack args"""
        def side(emu, k):
            emu.calllog.append((nm, rv(emu, emu.reg('edx'), edx_n), tuple(rv(emu, emu.arg32(i), 16) if i in stk_stack else emu.arg32(i) for i in range(nstk))))
            if wsz:
                emu.wbytes(emu.reg('ecx'), rb(wsz))
        return side
    hook_rec(c, 0x441970, 1, ret=r.getrandbits(32), pop=4, this='mark', stackmark=(0,), side=fc('h970', 1, 12))
    hook_rec(c, 0x443ef0, 2, ret=r.getrandbits(32), pop=8, this='mark', stackmark=(0,), side=fc('h3ef0', 2, 12, stk_stack=(0,)))
    hook_rec(c, 0x4e09e0, 0, ret=r.getrandbits(32), pop=0, this='mark', side=fc('h9e0', 0, 12))
    hook_rec(c, 0x441a60, 0, ret=r.getrandbits(32), pop=0, this='mark', side=fc('ha60', 0, 12))
    hook_rec(c, 0x4dfd10, 0, ret=r.getrandbits(32), pop=0, this='mark', side=fc('hd10', 0, 36))
    hook_rec(c, 0x441940, 0, ret=r.getrandbits(32), pop=0, this='mark', side=fc('h940', 0, 12))
    hook_rec(c, 0x43e920, 1, ret=r.getrandbits(32), pop=4, this='mark', side=fc('he920', 1, 12))
    hook_rec(c, 0x4de4b0, 1, ret=r.getrandbits(32), pop=4, this='mark', side=fc('he4b0', 1, 36))
    hook_rec(c, 0x64d030, 4, ret=lambda emu, k: r.choice([0] + Rs), pop=16, side=lambda emu, k: emu.calllog.append(('d030', emu.arg32(0), emu.arg32(1), emu.arg32(2), emu.arg32(3))))
    hook_rec(c, 0x4e0870, 0, ret=r.getrandbits(32), pop=0, this='mark', st0=lambda emu, k: r.choice(FV), side=lambda emu, k: emu.calllog.append(('e870', emu.reg('ecx') if isheap(emu.reg('ecx')) else 0, emu.reg('edx'))))
    hook_rec(c, 0x4db520, 0, ret=lambda emu, k: nxt.get(emu.reg('ecx'), 0), pop=0, this=True, side=lg('db520'))
    return [T, a1, O, planes, cnt, a5, a6, struct.unpack('<I', pk(f7))[0]]


S(0x64abb0, 'GUESS recursive visibility walk with clip planes (x87 volume scale)', 'thiscall', 7, ret=None, gen=g64abb0, note='batch244033')
