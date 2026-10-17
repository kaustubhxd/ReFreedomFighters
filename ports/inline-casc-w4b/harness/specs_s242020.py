"""specs_s242020.py - hand spec for the hand port of 0x4b73f0 (Sonnet-w4b)."""
import struct
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


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
S(0x4b73f0, 'GUESS sound attach', 'thiscall', None, ret=None, gen=g4b73f0, note='batch242020')
