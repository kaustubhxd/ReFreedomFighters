"""specs_s213106.py - batch 213106: movement/aim update with two log lines, a debug draw and x87 slot returns, Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def crt(c, addr, fn, name):
    def side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append((name, a))
        try:
            z = fn(x)
        except (ValueError, OverflowError):
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, addr, 0, side=side)


def g5179c0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    crt(c, 0x634d7c, math.sqrt, 'sqrt')
    small = [0.0, 0.0, 1.0, -1.0, 0.5, 2.0, -2.0, 3.0]

    def fv():
        return f32(r.choice(small + [r.uniform(-5, 5)]))

    def vec3():
        return struct.pack('<fff', fv(), fv(), fv())

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))
    thr = struct.unpack('<f', bytes(e.rbytes(0x67cd40, 4)))[0]

    this = rnd(c, 0x1680)
    e.w32(this + 4, 0 if r.random() < 0.4 else rnd(c, 0x10))
    e.w32(this + 8, rnd(c, 0x40))
    # s vector (this + 0x15df), floats a and b
    e.wbytes(this + 0x15df, vec3())
    e.wbytes(this + 0x378, struct.pack('<f', fv()))
    e.wbytes(this + 0x37c, struct.pack('<f', fv()))
    e.w32(this + 0x1650, 1 if r.random() < 0.7 else r.choice([0, 2, 0xffffffff]))
    # D vector region: D0 at +0x15eb (written by the 43e920 hook), others random
    # O object (this[0x5c]): floats at +8, +0xc, +0x10 and the three slots
    def st0v(emu, k):
        return f32(r.choice([0.5, 1.0, -1.0, 2.0, 0.0, 0.25, r.uniform(-3, 3), NAN]))
    O = obj(c, 0x40, {0x14: pystub(c, 0, this=True, st0=st0v), 0x4: pystub(c, 1, this=True, st0=st0v), 0x20: pystub(c, 1, this=True)}, nslots=0x20)
    e.wbytes(O + 8, vec3())
    e.w32(this + 0x5c, O)

    # engine and the debug-draw object K
    def sk(emu, k):
        lg(emu, 'p218', emu.arg32(0), 12)
    K = obj(c, 0x20, {0x218: pystub(c, 3, this=True, nullflag=(0,), side=sk)}, nslots=0x100)
    tab = obj(c, 0xb10, {}, nslots=4)
    e.w32(tab + 0xadc, K)
    eng = obj(c, 0x100, {}, nslots=4)
    e.w32(eng + 0x9b, tab)
    e.w32(0x70039c, eng)

    # log manager and its stream
    def h2c(emu, rr):
        a = (emu.arg32(0), emu.arg32(1), emu.arg32(2))
        row = ('log', emu.reg('ecx'),) + a
        if a[1] == 0x69f078:
            row += (emu.arg32(3), emu.arg32(4))
        emu.calllog.append(row)
        emu.ret(eax=0, argbytes=0)
    M = obj(c, 0x20, {0x2c: e.stub_fn('log2c', h2c)}, nslots=0x20)
    Lg = obj(c, 0x20, {0x20: pystub(c, 2, this=True, ret=M)}, nslots=0x20)
    e.w32(0x700390, Lg)

    hook_rec(c, 0x515930, 2, pop=8, this=True)

    def s3330(emu, k):
        emu.wbytes(emu.arg32(0), vec3())
    hook_rec(c, 0x523330, 1, pop=4, this=True, nullflag=(0,), side=s3330)

    def s3ef0(emu, k):
        lg(emu, 'edx3ef0', emu.reg('edx'), 12)
        emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x443ef0, 2, pop=8, this='mark', side=s3ef0)

    def s3e920(emu, k):
        lg(emu, 'q3e920', emu.reg('edx'), 12)
        lg(emu, 'p3e920', emu.arg32(0), 12)
        # D vector: sometimes long enough to pass the length threshold
        if r.random() < 0.25 and thr == thr:
            v = [0.0, 0.0, 0.0]
            v[r.choice([0, 2])] = r.choice([thr, -thr])
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', *v))
        elif r.random() < 0.5:
            emu.wbytes(emu.reg('ecx'), struct.pack('<fff', f32(r.uniform(-1, 1) * (thr * 2 if thr == thr and thr > 0 else 2.0)), 0.0, f32(r.uniform(-1, 1) * 2)))
        else:
            emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x43e920, 1, pop=4, this=True, nullflag=(0,), side=s3e920)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, F(fv()), r.getrandbits(32)]


S(0x5179c0, 'aim_update_log', 'thiscall', None, ret=None, gen=g5179c0)
