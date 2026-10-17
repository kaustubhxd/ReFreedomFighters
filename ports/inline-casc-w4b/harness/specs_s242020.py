"""specs_s242020.py - hand spec for the hand port of 0x4b73f0 (Sonnet-w4b)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub, seh_record, seh_chain


def g4b73f0(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fu = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
    def zed(f=None):
        def side(emu, k):
            emu.mu.reg_write(UC_X86_REG_EDX, 0)
            if f: f(emu, k)
        return side
    def lg(tag, n):
        return zed(lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    ST = lambda n, ret=R, tag='s', **kw: pystub(c, n, ret=ret, this=True, side=lg(tag, n), **kw)
    THIS = rnd(c, 0x100)
    Q = rnd(c, 0x40)
    other = rnd(c, 0x40)
    pick = lambda emu, k: r.choice([0, 5, 7, 0x1000])
    hook_rec(c, 0x445c50, 0, ret=lambda emu, k: Q if r.random() < 0.5 else other, this=True, side=zed())
    hook_rec(c, 0x4cc5f0, 0, ret=lambda emu, k: r.choice([0, 1, 1]), this=True, side=zed())
    hook_rec(c, 0x4cc1d0, 0, ret=R, this=True, side=zed())
    hook_rec(c, 0x4dc130, 0, ret=lambda emu, k: 0x20000000 + r.randrange(0, 0x100) * 4, this=True, side=zed())
    hook_rec(c, 0x43eb80, 1, ret=pick, this=True, side=zed())
    hook_rec(c, 0x43ec00, 6, ret=pick, this=True, side=zed())
    U = obj(c, 0x40, {0x1e0: ST(1, ret=lambda emu, k: r.choice([0, 1, 0, 0x100]), tag='u1e0')})
    T = rnd(c, 0x80)
    em.w32(T + 0x54, U if r.random() < 0.8 else 0)
    cobj = rnd(c, 0x80)
    kobj = rnd(c, 0x100)
    em.w32(kobj + 0x40, r.getrandbits(32)); em.w32(kobj + 0x64, r.randrange(0, 100))
    def s94(emu, k):
        emu.calllog.append(('s94', emu.arg32(0), emu.arg32(1)))
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
        if k == 0 and r.random() < 0.4: emu.w32(THIS_[0] + 0x91, 0)     # the callee may clear the cached id
    THIS_ = [0]
    vt = {0x94: pystub(c, 2, ret=lambda emu, k: T if (k == 0 or r.random() < 0.7) else 0, this=True, side=s94), 0x90: ST(3, ret=(cobj if r.random() < 0.8 else 0), tag='s90'),
          0x9c: ST(0, tag='s9c'), 0x64: ST(1, tag='s64')}
    # THIS needs its own vtable: build the object with obj() so the slots exist
    THIS = obj(c, 0x100, vt)
    THIS_[0] = THIS
    tbl = obj(c, 0xb10, {0x60: ST(1, ret=(kobj if r.random() < 0.85 else 0), tag='t60')})
    em.w32(tbl + 0xadc, Q)
    Wobj = obj(c, 0x40, {0xc0: ST(0, ret=rnd(c, 0x20), tag='wc0'), 0x70: ST(1, ret=lambda emu, k: r.choice([0, 1, 0x101]), tag='w70')})
    so = sysobj(c)
    em.w32(so + 0x9b, tbl)
    em.w32(so + 0x1a9f, Wobj if r.random() < 0.93 else 0)
    em.w32(THIS + 0x91, r.choice([0, 0, 3, 0x44]))
    em.w32(THIS + 0x85, r.choice([0, 0, 2, 9])); em.w32(THIS + 0x89, r.choice([0, 3, 0]))
    em.w32(THIS + 0x7c, r.choice([1, 3, 4, 2, 0, 1, 4]))
    em.w32(THIS + 0x80, r.choice([0, 1, 2, 2]))
    em.w32(THIS + 0x8d, r.choice([0, 9, 0x2000]))
    em.w32(THIS + 0x68, r.choice([0, 4, 100])); em.w32(THIS + 0x6c, r.choice([0, 2, 50]))
    em.w32(THIS + 0x70, r.choice([0, 0, 1])); em.w32(THIS + 0x78, r.choice([0, 0, 500, 1234]))
    em.wbytes(THIS + 0x54, struct.pack('<f', r.choice([0.0, 0.5, 2.0, -1.0, 0.0])))
    return [THIS, r.getrandbits(32), r.getrandbits(32)]


def g4bf890(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fu = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
    zed = lambda f=None: (lambda emu, k: (emu.mu.reg_write(UC_X86_REG_EDX, 0), f(emu, k) if f else None))
    def lg(tag, n):
        return zed(lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    ST = lambda n, ret=R, tag='s', **kw: pystub(c, n, ret=ret, this=True, side=lg(tag, n), **kw)
    T = r.randrange(5000, 90000)
    def vec_h(tag, wr):
        def side(emu, k):
            e, d = emu.reg('ecx'), emu.reg('edx')
            emu.calllog.append((tag,) + tuple(emu.r32(e + 4 * j) for j in range(3)) + tuple(emu.r32(d + 4 * j) for j in range(3)))
            for j in range(wr): emu.w32(e + 4 * j, fu(r.choice([0.0, 1.0, -2.0, 0.5])))
            emu.mu.reg_write(UC_X86_REG_EDX, 0)
        return side
    hook_rec(c, 0x441a60, 0, ret=R, side=vec_h('h441a60', 3))
    hook_rec(c, 0x441940, 0, ret=R, side=vec_h('h441940', 3))
    hook_rec(c, 0x43ec00, 6, ret=lambda emu, k: r.choice([0, 5, 9]), this=True, deref={1: 3}, side=zed())
    hook_rec(c, 0x44b850, 1, ret=R, this=True, side=lg('h44b850', 1))
    hook_rec(c, 0x44b880, 1, ret=R, this=True, side=lg('h44b880', 1))
    def container(m):
        n = r.choice([0, 1, 2, 3])
        sts = [1] * n + [0]
        def s4c(emu, k):
            emu.w32(emu.arg32(0), 0); emu.mu.reg_write(UC_X86_REG_EDX, 0)
        def s5c(emu, k):
            emu.w32(emu.arg32(0), sts[min(k, len(sts) - 1)]); emu.mu.reg_write(UC_X86_REG_EDX, 0)
        vt = em.alloc(0x80, 4)
        em.w32(vt + 0x14, pystub(c, 0, ret=lambda emu, k: r.choice([0, n, n, 1]), this=True, side=zed()))
        em.w32(vt + 0x4c, pystub(c, 1, ret=R, this=True, nullflag=(0,), side=s4c))
        em.w32(vt + 0x5c, pystub(c, 1, ret=lambda emu, k: 0x300 + k, this=True, nullflag=(0,), side=s5c))
        return vt
    O = obj(c, 0x40, {0x210: ST(1, tag='o210')})
    tbl = obj(c, 0x40, {0x58: ST(1, ret=lambda emu, k: O if r.random() < 0.7 else 0, tag='t58'), 0x60: ST(1, ret=rnd(c, 0x40), tag='t60')})
    so = sysobj(c)
    em.w32(so + 0x9b, tbl); em.w32(so + 0x40, T)
    if r.random() < 0.05: em.w32(so + 0x1a9f, 0)
    X = obj(c, 0x40, {})
    Q = rnd(c, 0x80)
    for j in (0x30, 0x34, 0x38): em.w32(Q + j, fu(r.choice([0.0, 1.0, 5.0])))
    P = obj(c, 0x40, {0x20: ST(0, ret=X, tag='p20')})
    em.w32(P + 8, Q)
    THIS = obj(c, 0x240, {0x60: ST(1, tag='this60')})
    em.w32(THIS + 0x48, container(1)); em.w32(THIS + 0xf4, container(2))
    em.w32(THIS + 0x44, P)
    em.wbytes(THIS + 0x1bc, struct.pack('<f', (T - r.choice([0, 100, 5000])) / 1024.0 if r.random() < 0.8 else 99.0))
    em.wbytes(THIS + 0x1b8, struct.pack('<f', r.choice([0.0, 0.05, 0.1, 1.0])))
    em.w32(THIS + 0x1cc, r.choice([0, 1, 1]))
    c4 = r.choice([1, 2, 3, 5]); c0 = r.choice([1, 3, 5])
    em.w32(THIS + 0x1c4, c4); em.w32(THIS + 0x1c0, c0)
    em.w32(THIS + 0x1c8, r.choice([c4, 1, 2, 0, c4]))
    em.wbytes(THIS + 0x1b4, struct.pack('<f', r.choice([0.25, 1.0, 3.0]))); em.wbytes(THIS + 0x1b0, struct.pack('<f', r.choice([0.5, 2.0, 0.0])))
    em.w32(THIS + 0x1d0, r.choice([0, 1, 1, 1]))
    em.w32(THIS + 0x1a8, r.choice([0, 0, 7]))
    em.w32(THIS + 0x1a0, r.choice([0, 3, 0])); em.w32(THIS + 0x1a4, r.choice([0, 4, 4]))
    return [THIS]


S(0x4bf890, 'GUESS animated effect tick', 'thiscall', None, ret=None, gen=g4bf890, note='batch242020')
def g581c10(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fu = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
    zed = lambda f=None: (lambda emu, k: (emu.mu.reg_write(UC_X86_REG_EDX, 0), f(emu, k) if f else None))
    def lg(tag, n):
        return zed(lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    ST = lambda n, ret=R, tag='s', **kw: pystub(c, n, ret=ret, this=True, side=lg(tag, n), **kw)
    THIS = rnd(c, 0x400)
    fl = lambda: fu(r.choice([0.0, 0.5, 1.0, 2.0, 3.5, -1.0, 10.0, 0.25]))
    for off in range(0x9d, 0x179, 4): em.w32(THIS + off, fl())
    for off in range(0x18d, 0x18d + 0x3c, 4): em.w32(THIS + off, fl())
    for j in range(3): em.w32(THIS + 0x74 + 4 * j, fu(r.choice([0.0, 1.0, 2.0, -3.0])) if r.random() < 0.85 else 0)
    for i in range(5): em.wbytes(THIS + 0x1c9 + i, bytes([r.choice([0, 1, 1])]))
    # chunk decay floats: keep the exp argument moderate
    for i in range(5): em.w32(THIS + 0x9d + 0x2c * i + 0xc, fu(r.choice([0.0, 0.5, 2.0, 10.0]))); em.w32(THIS + 0x9d + 0x2c * i + 0x28, fu(r.choice([0.0, 0.5, 1.0])))
    em.w32(THIS + 0x362, r.getrandbits(32))
    Fo = rnd(c, 0x80)
    allskip = r.random() < 0.2
    def mk_hn():
        hn = obj(c, 0x300, {0x1e0: ST(1, ret=lambda emu, k: 1 if allskip else r.choice([0, 1, 0x101, 0]), tag='h1e0'), 0x438: ST(0, ret=lambda emu, k: 1 if allskip else r.choice([0, 1]), tag='h438'),
                            0x84: ST(1, tag='h84'), 0x88: ST(1, tag='h88')})
        fo = rnd(c, 0x80); em.w32(fo + 0x3c, r.choice([0x40040000, 0, 0x40000000, 0x40040000, 4, 0x00040000]) | r.getrandbits(4))
        em.w32(hn + 8, fo)
        return hn
    hns = [mk_hn() for _ in range(2)]
    Hs = []
    for hn in hns:
        H = rnd(c, 0x80); em.w32(H + 0x54, hn); Hs.append(H)
    def s30(emu, k):
        S = emu.arg32(0)
        emu.calllog.append(('s30', emu.r32(S)))
        for j in range(1, 16): emu.w32(S + 4 * j, fl())
        emu.w32(S + 0x10, Hs[k % 2])
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
    RC = obj(c, 0x40, {0x30: pystub(c, 8, ret=lambda emu, k: r.choice([0, 1, 1]), this=True, deref={0: 1, 2: 3, 3: 3}, side=s30)})
    R1 = rnd(c, 0x40); em.w32(R1 + 0x1c, RC)
    Nn = obj(c, 0x40, {0x78: ST(1, tag='n78', deref={0: 3})})
    tbl = obj(c, 0x40, {0x4c: ST(1, ret=lambda emu, k: 0x900 + k, tag='t4c'), 0x58: ST(1, ret=(Nn if r.random() < 0.85 else 0), tag='t58')})
    so = sysobj(c)
    em.w32(so + 0x9b, tbl); em.w32(so + 0x1aa3, R1)
    em.w32(so + 0x40, r.randrange(0, 1500)); em.w32(so + 0x44, r.randrange(0, 1500))
    return [THIS]


S(0x581c10, 'GUESS five-slot probe', 'thiscall', None, ret=None, gen=g581c10, note='batch242020')
def g582e20(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fu = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
    zed = lambda f=None: (lambda emu, k: (emu.mu.reg_write(UC_X86_REG_EDX, 0), f(emu, k) if f else None))
    def lg(tag, n):
        return zed(lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    ST = lambda n, ret=R, tag='s', **kw: pystub(c, n, ret=ret, this=True, side=lg(tag, n), **kw)
    THIS = rnd(c, 0x400)
    fl = lambda: fu(r.choice([0.0, 0.5, 1.0, 2.0, 3.5, -1.0, 10.0, 0.25]))
    for off in range(0x9d, 0x179, 4): em.w32(THIS + off, fl())
    for off in range(0x18d, 0x18d + 0x3c, 4): em.w32(THIS + off, fl())
    for off in range(0x1ce, 0x1ce + 0x3c, 4): em.w32(THIS + off, fl())
    for i in range(5):
        em.w32(THIS + 0x9d + 0x2c * i + 0xc, fu(r.choice([0.0, 0.5, 2.0]))); em.w32(THIS + 0x9d + 0x2c * i + 0x28, fu(r.choice([0.0, 0.5, 1.0])))
        em.wbytes(THIS + 0x1c9 + i, bytes([r.choice([0, 1, 1])]))
        em.w32(THIS + 0x179 + 4 * i, r.choice([0xd0 + i, 0xd0 + i, 0]))
    em.w32(THIS + 0x4c, 0x4c4c)
    em.wbytes(THIS + 0x50, struct.pack('<f', r.choice([1.0, 2.0, 4.0, 0.5])))
    em.wbytes(THIS + 0x5c, struct.pack('<f', r.choice([0.0, 3.0, 5.0, 8.0, 9.0])))
    dt = r.choice([0.016, 0.5, 1.0])
    em.wbytes(THIS + 0x60, struct.pack('<f', dt + r.choice([-2.0, -1.0, -0.5, 0.25, -0.1, 0.0])))
    em.w32(THIS + 0x64, r.choice([0, 1, 3, 4]))
    A = rnd(c, 0x40)
    def s456(emu, k):
        a0, a1 = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('h456b70', emu.reg('ecx')))
        emu.w32(a0, 0xb0b0); emu.w32(a0 + 4, fl()); emu.w32(a0 + 8, fl())
        emu.w32(a1, fl())
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
    hook_rec(c, 0x456b70, 2, ret=R, this=True, nullflag=(0, 1), side=s456)
    def s84(emu, k):
        emu.calllog.append(('n84', emu.reg('ecx')))
        a = emu.arg32(0)
        if r.random() < 0.5:
            for j in range(3): emu.w32(a + 4 * j, fl())
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
    Nobj = obj(c, 0x40, {0x84: pystub(c, 1, ret=R, this=True, nullflag=(0,), side=s84)})
    Bobj = obj(c, 0x40, {0x218: ST(4, tag='b218', deref={1: 3, 2: 3})})
    def t58(emu, k):
        a = emu.arg32(0)
        if a == 0x4c4c: return A
        if a == 0xb0b0: return Bobj
        return Nobj if a else 0
    tbl = obj(c, 0x40, {0x58: pystub(c, 1, ret=t58, this=True, side=lg('t58', 1))})
    rf = lambda emu, k: r.choice([0.0, 0.25, 0.5, 1.0, 0.75])
    so = sysobj(c, slots={0x1c4: pystub(c, 2, st0=rf, this=True, side=lg('r1c4', 2)), 0x1c0: pystub(c, 2, st0=rf, this=True, side=lg('r1c0', 2))})
    em.w32(so + 0x9b, tbl); em.w32(so + 0x40, r.randrange(0, 12000)); em.wbytes(so + 0x48, struct.pack('<f', dt))
    return [THIS]


S(0x582e20, 'GUESS particle emitter', 'thiscall', None, ret=None, gen=g582e20, note='batch242020')
def g40c780(c):
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    m = r.choice([1, 2, 3, 5, 8])
    n = r.choice([0, 1, 2, 3, 5, 6])
    hook_rec(c, 0x4078d0, 3, ret=R, pop=0, deref={0: m}, side=lambda emu, k: emu.calllog.append(('h4078d0', emu.arg32(1), emu.arg32(2))))
    em.w32(0x725484, r.choice([0, 7, 100]))
    def s40ce50(emu, k):
        a2 = emu.arg32(2)
        emu.calllog.append(('dbg', emu.arg32(0), emu.arg32(1), a2 if 0x20000000 <= a2 < 0x30000000 else 0, emu.arg32(3), emu.arg32(4), emu.arg32(5)))
        if not (0x20000000 <= a2 < 0x30000000):
            emu.calllog.append(('dbgL',) + tuple(emu.r32(a2 + 4 * j) for j in range(m)))
    hook_rec(c, 0x40ce50, 6, ret=R, pop=0, nullflag=(2,), side=s40ce50)
    A = rnd(c, 0x40)
    for j in range(8): em.wbytes(A + 4 * j, struct.pack('<f', r.choice([0.0, 0.25, 0.5, 1.0, 2.0, 3.5, -1.0, 0.75])))
    idx = rnd(c, 0x40)
    cur = 0
    for j in range(8):
        cur = min(m - 1, cur + r.choice([0, 0, 1, 2, 3])) if r.random() < 0.85 else r.randrange(0, m)
        em.w32(idx + 4 * j, cur)
    T = rnd(c, 0x40)
    em.w32(T, n); em.w32(T + 4, m); em.w32(T + 0xc, idx)
    return [A, r.getrandbits(32), T]


S(0x40c780, 'GUESS envelope fill', 'cdecl', None, ret=None, gen=g40c780, note='batch242020')
def g403fe0(c):
    from unicorn.x86_const import UC_X86_REG_EIP
    clear_hooks(c)
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fu = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
    cnt = r.choice([0, 1, 2, 3, 5])
    n = r.choice([0, 1, 3, 6])
    fv = lambda: fu(r.choice([0.0, 0.5, 1.2, 5.5, 20.0, 39.7, 45.0, 100.0, -1.0, 3.0, 12.25]))
    # _ftol: st0 -> edx:eax truncated toward zero, restoring the control word
    code = bytes([0x83, 0xEC, 0x10, 0xD9, 0x3C, 0x24, 0x66, 0x8B, 0x04, 0x24, 0x66, 0x89, 0x44, 0x24, 0x02,
                  0x66, 0x81, 0x4C, 0x24, 0x02, 0x00, 0x0C, 0xD9, 0x6C, 0x24, 0x02, 0xDF, 0x7C, 0x24, 0x08,
                  0xD9, 0x2C, 0x24, 0x8B, 0x44, 0x24, 0x08, 0x8B, 0x54, 0x24, 0x0C, 0x83, 0xC4, 0x10, 0xC3])
    ft = em._alloc_stub_code(code)
    em.stub_import('_ftol', lambda e, rr: e.mu.reg_write(UC_X86_REG_EIP, ft))
    em.w32(0x725478, r.choice([0, 3, 50]))
    def s404700(emu, k):
        a2 = emu.arg32(2)
        emu.calllog.append(('h404700', emu.arg32(0), emu.arg32(1), emu.arg32(4), emu.arg32(5)) + tuple(emu.r32(a2 + 4 * j) for j in range(cnt)))
        a3 = emu.arg32(3)
        for j in range(cnt): emu.w32(a3 + 4 * j, fv())
    hook_rec(c, 0x404700, 6, ret=R, pop=0, nullflag=(2, 3), side=s404700)
    def s4042c0(emu, k):
        a1, a3, L = emu.arg32(2), emu.arg32(3), emu.arg32(4)
        emu.calllog.append(('h4042c0', emu.arg32(5)) + tuple(emu.r32(a1 + 4 * j) for j in range(cnt)) + tuple(emu.r32(a3 + 4 * j) for j in range(cnt)) + tuple(emu.r32(L + 4 * j) for j in range(n)))
        for j in range(n):
            if r.random() < 0.5: emu.w32(L + 4 * j, fv())
        for j in range(cnt):
            if r.random() < 0.5: emu.w32(a3 + 4 * j, fv())
    hook_rec(c, 0x4042c0, 6, ret=R, pop=0, nullflag=(2, 3, 4), side=s4042c0)
    def s404460(emu, k):
        L, a3 = emu.arg32(1), emu.arg32(2)
        emu.calllog.append(('h404460',) + tuple(emu.r32(L + 4 * j) for j in range(n)) + tuple(emu.r32(a3 + 4 * j) for j in range(cnt)))
        for j in range(cnt):
            if r.random() < 0.5: emu.w32(a3 + 4 * j, fv())
    hook_rec(c, 0x404460, 3, ret=R, pop=0, nullflag=(1, 2), side=s404460)
    def s40ce50(emu, k):
        a2 = emu.arg32(2)
        emu.calllog.append(('dbg', emu.arg32(0), emu.arg32(1), emu.arg32(3), emu.arg32(4), emu.arg32(5)) + tuple(emu.r32(a2 + 4 * j) for j in range(cnt)))
    hook_rec(c, 0x40ce50, 6, ret=R, pop=0, nullflag=(2,), side=s40ce50)
    Q = rnd(c, 0x780)
    em.w32(Q + 0x660, r.choice([0, 1, 1])); em.w32(Q + 0x664, fu(r.choice([30.0, 50.0, 5.0])))
    em.w32(Q + 0x6c, fu(r.choice([0.0, 1.0, -2.0]))); em.w32(Q + 0x70, fu(r.choice([-1.0, 0.5, 2.0])))
    em.w32(Q + 0x678, fu(r.choice([0.0, 2.5])))
    for j in range(0x28): em.w32(Q + 0x6c0 + 4 * j, fu(r.choice([0.0, 1.5, 10.0, 25.0, 40.0, -3.0])))
    O = rnd(c, 0x80)
    o10 = rnd(c, 0x20); o14 = rnd(c, 0x20); a1 = rnd(c, 0x20); a2 = rnd(c, 0x20); a3 = rnd(c, 0x20)
    for arr in (o10, o14, a1, a2, a3):
        for j in range(6): em.w32(arr + 4 * j, fu(r.choice([0.0, 0.25, 1.0, 2.0, 5.0, -1.0, 40.0, 0.5])))
    em.w32(O, cnt); em.w32(O + 4, Q); em.w32(O + 8, rnd(c, 0x20)); em.w32(O + 0x10, o10); em.w32(O + 0x14, o14); em.w32(O + 0x1c, r.getrandbits(32)); em.w32(O + 0x2c, n)
    return [O, a1, a2, a3, r.getrandbits(32), fu(r.choice([0.0, 0.5, 2.0])), fu(r.choice([0.0, 1.0, -0.5]))]


S(0x403fe0, 'GUESS curve merge', 'cdecl', None, ret=None, gen=g403fe0, note='batch242020')
def g4b34d0(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    fu = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
    srs = [seh_record(c, 2) for _ in range(24)]
    cnt = [0]
    def zed(f=None):
        def side(emu, k):
            emu.mu.reg_write(UC_X86_REG_EDX, 0)
            srs[cnt[0] % 24](emu, k); cnt[0] += 1
            if f: f(emu, k)
        return side
    def lg(tag, n):
        return zed(lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    ST = lambda n, ret=R, tag='s', **kw: pystub(c, n, ret=ret, this=True, side=lg(tag, n), **kw)
    THIS = rnd(c, 0x100)
    own = r.choice([0x4e, 0x4e, 0x4e, 0x64, 0x60, 0x62, 0x50, 0x70])
    ids = {0x4e: 0x1111, 0x64: 0x2222, 0x60: 0x3333, 0x62: 0x4444, 0x50: 0x5555}
    for off, v in ids.items(): em.wbytes(THIS + off, struct.pack('<H', v))
    idarg = ids.get(own, 0x6666)
    X = obj(c, 0x40, {0x12c: ST(3, tag='x12c'), 0x1d8: pystub(c, 2, ret=lambda emu, k: 0x20000000 + 0x40 * k, this=True, nullflag=(0,), side=zed(lambda emu, k: (emu.w32(emu.arg32(0), 0x5151 + k), emu.w32(emu.arg32(0) + 4, 0x6161), emu.calllog.append(('x1d8', emu.arg32(1))))))})
    em.w32(THIS + 0x44, X)
    for off in (0x9e, 0x9f, 0x9a, 0x98, 0x4d, 0xa0): em.wbytes(THIS + off, bytes([r.choice([0, 0, 1])]))
    em.wbytes(THIS + 0x9e, bytes([r.choice([0, 0, 0, 1])]))
    em.w32(THIS + 0x80, r.choice([0, 0, 7])); em.w32(THIS + 0x74, r.choice([0x400, 0x401, 0x400]))
    for off in (0xd6, 0xe6, 0xa6, 0xda, 0x88): em.w32(THIS + off, r.getrandbits(32))
    hook_rec(c, 0x4b3270, 0, ret=R, this=True, side=zed())
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: 0x7000 + k, this=True, side=lg('h4cc1d0', 0))
    hook_rec(c, 0x4cbec0, 0, ret=R, this=False, side=zed(lambda emu, k: emu.calllog.append(('dtor', emu.r32(emu.reg('ecx')), emu.r32(emu.reg('ecx') + 4)))))
    def s4db6c0(emu, k):
        for a in (emu.arg32(0), emu.arg32(1)):
            for j in range(3): emu.w32(a + 4 * j, fu(r.choice([0.0, 1.0, 2.5])))
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
    hook_rec(c, 0x4db6c0, 2, ret=R, this=True, nullflag=(0, 1), side=s4db6c0)
    hook_rec(c, 0x4dc630, 2, ret=R, this=True, side=zed())
    E = obj(c, 0x40, {0x7c: ST(2, tag='e7c', deref={0: 3, 1: 3})})
    em.w32(E + 8, rnd(c, 0x20))
    Nobj = obj(c, 0x40, {0x1e0: ST(1, ret=lambda emu, k: r.choice([0, 1]), tag='n1e0'), 0x594: ST(1, tag='n594')})
    Wobj = obj(c, 0x40, {0x20: ST(2, tag='w20')})
    Q = obj(c, 0x40, {0x25c: ST(2, ret=lambda emu, k: E if r.random() < 0.6 else 0, tag='q25c'), 0x294: ST(4, ret=E, tag='q294')})
    nvals = r.choice([0, 4, 8, 12])
    def c88(emu, k):
        name = emu.arg32(0)
        out = emu.arg32(1)
        emu.calllog.append(('c88', name))
        if name == 0x692430: v = 0x2a
        elif name == 0x681320: v = r.choice([0, 0x300])
        elif name == 0x692314: v = r.choice([0, 0, 5])
        else: v = 0
        if v is not None and not (name == 0x6923e4):
            emu.w32(out, v)
        else:
            for j in range(max(nvals // 4, 0)): emu.w32(out + 4 * j, 0x9000 + j)
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
    Cobj = obj(c, 0x40, {0x88: pystub(c, 2, ret=R, this=True, nullflag=(1,), side=c88),
                         0xa8: ST(1, ret=nvals, tag='ca8'), 0x28: ST(3, tag='c28', deref={1: max(nvals // 4, 1)})})
    def t58(emu, k):
        a = emu.arg32(0)
        if a == 0x300: return Nobj
        if a == 0x400: return E
        return 0
    tbl = obj(c, 0xb10, {0x138: ST(0, ret=Cobj, tag='t138'), 0x114: ST(4, ret=lambda emu, k: 0x12340000 + k, tag='t114'), 0x58: pystub(c, 1, ret=t58, this=True, side=lg('t58', 1)),
                         0x134: ST(0, ret=(Wobj if r.random() < 0.7 else 0), tag='t134'), 0x4c: ST(1, ret=lambda emu, k: 0x800 + k, tag='t4c'), 0x54: ST(1, ret=rnd(c, 0x40), tag='t54')})
    em.w32(tbl + 0xadc, Q)
    so = sysobj(c)
    em.w32(so + 0x9b, tbl); em.w32(so + 0x40, r.getrandbits(32))
    K = rnd(c, 0x200); em.w32(K + 0xfd, r.choice([0, 0, 3])); em.w32(so + 0x190f, K)
    o = obj(c, 0x40, {0x2c: pystub(c, 2, ret=R, pop=0, this=False, side=zed(lambda emu, k: emu.calllog.append(('log', emu.arg32(0), emu.arg32(1)))))})
    Lobj = obj(c, 0x40, {0x20: ST(2, ret=o, tag='l20')})
    em.w32(0x700390, Lobj)
    rec = rnd(c, 0x20)
    P = obj(c, 0x40, {0x2c: ST(1, ret=lambda emu, k: r.choice([0, 1, 0]), tag='p2c'), 0x4: ST(1, ret=rec, tag='p4')})
    em.w32(0x700334, P)
    return [THIS, idarg, r.getrandbits(32)]


S(0x4b34d0, 'GUESS event handler', 'thiscall', None, ret='eax', gen=g4b34d0, note='batch242020')
def g4b3a70(c):
    from unicorn.x86_const import UC_X86_REG_EDX
    clear_hooks(c)
    seh_chain(c, c.rng.choice([0, 1, 2]))
    r = c.rng
    em = c.emu
    R = lambda emu, k: r.getrandbits(32)
    em.w32(0x7003b0, pystub(c, 0, ret=R))
    srs = [seh_record(c, 2) for _ in range(24)]
    cnt = [0]
    def zed(f=None):
        def side(emu, k):
            emu.mu.reg_write(UC_X86_REG_EDX, 0)
            srs[cnt[0] % 24](emu, k); cnt[0] += 1
            if f: f(emu, k)
        return side
    def lg(tag, n):
        return zed(lambda emu, k: emu.calllog.append((tag,) + tuple(emu.arg32(i) for i in range(n))))
    ST = lambda n, ret=R, tag='s', **kw: pystub(c, n, ret=ret, this=True, side=lg(tag, n), **kw)
    THIS = rnd(c, 0x100)
    X = obj(c, 0x40, {0x12c: ST(3, tag='x12c')})
    em.w32(THIS + 0x44, X)
    em.w32(THIS + 0x84, r.choice([0, 0x301, 0x301, 0x300, 0x500]))
    for off in (0x9f, 0x98): em.wbytes(THIS + off, bytes([r.choice([0, 1, 1])]))
    for off in (0x78, 0x7c): em.w32(THIS + off, r.choice([0, 0x301, 0x303]))
    em.wbytes(THIS + 0x66, struct.pack('<H', 0x1234)); em.wbytes(THIS + 0x72, struct.pack('<H', 0x2345))
    J = obj(c, 0x40, {0x90: ST(2, tag='j90')})
    nel = r.choice([0, 1, 2, 3])
    sts = [1] * nel + [0]
    def s5c(emu, k):
        emu.w32(emu.arg32(0), sts[min(k, len(sts) - 1)]); emu.mu.reg_write(UC_X86_REG_EDX, 0)
    vtB = em.alloc(0x80, 4)
    em.w32(vtB + 0x4c, pystub(c, 1, ret=R, this=True, nullflag=(0,), side=zed(lambda emu, k: emu.w32(emu.arg32(0), 0))))
    em.w32(vtB + 0x5c, pystub(c, 1, ret=lambda emu, k: 0x301 + 2 * k, this=True, nullflag=(0,), side=s5c))
    Bobj = rnd(c, 0x20); em.w32(Bobj, vtB)
    Kobj = obj(c, 0x200, {0xb8: ST(1, tag='kb8'), 0x98: ST(0, ret=(Bobj if r.random() < 0.8 else 0), tag='k98')})
    em.w32(Kobj + 0xfd, r.choice([0, 1, 4]))
    fh = rnd(c, 0x40); em.wbytes(fh + 0x23, struct.pack('<I', r.choice([0x400000, 0, 0x400000])))
    Nobj = obj(c, 0x40, {0x36c: ST(0, tag='n36c'), 0xbc: ST(1, tag='nbc')})
    em.w32(Nobj + 0xc, fh)
    ID = 0x555
    nvals = r.choice([0, 1, 2, 4])
    LST = None
    def c88(emu, k):
        name, out = emu.arg32(0), emu.arg32(1)
        emu.calllog.append(('c88', name))
        if name == 0x6923e4:
            for j in range(nvals): emu.w32(out + 4 * j, r.choice([ID, 0x600, ID, 0x601]))
        else:
            v = {0x685a0c: r.choice([0, 0x77, 0x77]), 0x6922f8: 0x88, 0x68be98: r.choice([0, 0x99]), 0x681320: r.choice([0, 0x301]), 0x692314: 5}.get(name, 0)
            if name == 0x692048: v = LSTobj
            emu.w32(out, v)
        emu.mu.reg_write(UC_X86_REG_EDX, 0)
    Cobj = obj(c, 0x40, {0x88: pystub(c, 2, ret=R, this=True, nullflag=(1,), side=c88), 0x5c: ST(3, tag='c5c'),
                         0xa8: ST(1, ret=nvals * 4, tag='ca8'), 0x28: ST(3, tag='c28', deref={1: max(nvals, 1)}), 0xa0: ST(2, tag='ca0')})
    Eo = rnd(c, 0x20); em.w32(Eo, 0x700); em.w32(Eo + 4, r.getrandbits(32)); em.wbytes(Eo + 8, struct.pack('<H', 0xabcd))
    LSTobj = obj(c, 0x40, {0x14: ST(0, ret=r.choice([0, 1, 2]), tag='l14'), 0x34: ST(1, ret=Eo, tag='l34'), 0x3c: ST(1, tag='l3c')})
    Tn = obj(c, 0x40, {0x128: ST(3, tag='tn128')})
    Tobj = rnd(c, 0x80); em.w32(Tobj + 0x54, Tn if r.random() < 0.8 else 0)
    def t58(emu, k):
        a = emu.arg32(0)
        return Nobj if (a & 1) else 0
    tbl = obj(c, 0xb10, {0x138: ST(0, ret=Cobj, tag='t138'), 0x58: pystub(c, 1, ret=t58, this=True, side=lg('t58', 1)),
                         0x54: ST(1, ret=(Tobj if r.random() < 0.8 else 0), tag='t54'), 0x4c: ST(1, ret=ID, tag='t4c'), 0x114: ST(4, ret=lambda emu, k: 0x12340000 + k, tag='t114')})
    so = sysobj(c)
    em.w32(so + 0x9b, tbl); em.w32(so + 0x1907, J); em.w32(so + 0x190f, Kobj)
    hook_rec(c, 0x4cc1d0, 0, ret=lambda emu, k: 0x7000 + k, this=True, side=lg('h4cc1d0', 0))
    hook_rec(c, 0x4cbec0, 0, ret=R, this=False, side=zed(lambda emu, k: emu.calllog.append(('dtor', emu.r32(emu.reg('ecx')), emu.r32(emu.reg('ecx') + 4)))))
    hook_rec(c, 0x4da2f0, 2, ret=lambda emu, k: 0x20000000 + 0x40 * k, this=True, nullflag=(0,), side=zed(lambda emu, k: (emu.w32(emu.arg32(0), 0x5151 + k), emu.w32(emu.arg32(0) + 4, 0x6161))))
    o = obj(c, 0x40, {0x2c: pystub(c, 2, ret=R, pop=0, this=False, side=zed(lambda emu, k: emu.calllog.append(('log', emu.arg32(0), emu.arg32(1)))))})
    Lobj = obj(c, 0x40, {0x20: ST(2, ret=o, tag='l20')})
    em.w32(0x700390, Lobj)
    return [THIS]


S(0x4b3a70, 'GUESS event release', 'thiscall', None, ret=None, gen=g4b3a70, note='batch242020')
S(0x4b73f0, 'GUESS sound attach', 'thiscall', None, ret=None, gen=g4b73f0, note='batch242020')
