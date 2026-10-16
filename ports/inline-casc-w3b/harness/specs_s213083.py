"""specs_s213083.py - batch 213083: camera aim with CRT trig, vector helpers and stack leftovers, Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
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


def g5d2280(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    sl = lambda n, ret=None, **kw: pystub(c, n, ret=(r.getrandbits(32) if ret is None else ret), this=True, **kw)
    crt(c, 0x634d70, math.cos, 'cos')
    crt(c, 0x634d76, math.sin, 'sin')
    thr = struct.unpack('<f', bytes(e.rbytes(0x67af28, 4)))[0]
    cth = struct.unpack('<f', bytes(e.rbytes(0x67da04, 4)))[0]

    def fl():
        return r.choice([0.0, -0.0, 1.0, -1.0, 0.5, 3.0, r.uniform(-4, 4), r.uniform(-1, 1), NAN, thr, thr + 1, 1e-3])
    M = obj(c, 0x20, {0x2c: pystub(c, 4, ret=r.getrandbits(32), this=True, pop=0)}, nslots=0x14)
    L = obj(c, 0x20, {0x20: pystub(c, 2, ret=M, this=True)}, nslots=0x10)
    e.w32(0x700390, L)

    def vec_side(emu, k):
        emu.wbytes(emu.arg32(0), struct.pack('<fff', fl(), fl(), fl()))
    W = obj(c, 0x20, {0xac: pystub(c, 0, this=True, st0=lambda emu, k: fl())}, nslots=0x40)
    P = rnd(c, 0x10)
    this = obj(c, 0xe30, {0x88: sl(1, nullflag=(0,), side=vec_side)}, nslots=0x60)
    for off, v in ((0xa54, fl()), (0xae9, fl()), (0xa5c, fl()), (0xdfd, fl())):
        e.wbytes(this + off, struct.pack('<f', v))
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    twopi = f32(2 * math.pi)
    m = r.random()
    if m < 0.5:
        f1v = f32(r.uniform(-3, 3))
        if m < 0.2:
            f0v = f32(f1v + twopi + r.choice([0.01, 0.1, 1.0, 0.0, -0.0001, 3.0]))
        elif m < 0.28:
            f0v = f1v
        elif m < 0.36:
            f0v = f32(f1v + r.choice([1e-6, -1e-6, 1e-4, -1e-4]))
        elif m < 0.44:
            f1v = 0.0
            f0v = f32(twopi + 2.0 ** -13)
        else:
            f0v = f32(r.uniform(-9, 9))
        e.wbytes(this + 0xae9, struct.pack('<f', f0v))
        e.wbytes(this + 0xa54, struct.pack('<f', f1v))
    e.wbytes(this + 0xaf9, struct.pack('<f', r.choice([cth, cth, cth - 1, cth + 1, NAN, 0.0, 0.02, 0.025, 0.03, 0.01])))
    e.wbytes(this + 0xafd, struct.pack('<f', r.choice([cth, cth, cth - 1, cth + 1, NAN, 0.0, 0.02, 0.025, 0.03, 0.01])))
    e.w32(this + 0xb54, W)
    e.w32(this + 0xe18, 0 if r.random() < 0.3 else P)

    def side_v(emu, k):
        emu.calllog.append(('dir', bytes(emu.rbytes(emu.reg('ecx'), 12))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fl(), fl(), fl()))

    def side_43(emu, k):
        emu.calllog.append(('v', bytes(emu.rbytes(emu.reg('edx'), 12))))
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', fl(), fl(), fl()))
    hook_rec(c, 0x4e0d80, 1, this=True, side=side_v)
    hook_rec(c, 0x43e8e0, 1, pop=4, this=True, side=side_43)
    hook_rec(c, 0x4de7a0, 0, this='mark')
    hook_rec(c, 0x5ceed0, 6, this=True)
    hook_rec(c, 0x5cefc0, 4, this=True)

    def xy_side(emu, k):
        if r.random() < 0.6:
            emu.wbytes(emu.arg32(0), struct.pack('<ff', fl(), fl()))
        else:
            emu.calllog.append(('xy', bytes(emu.rbytes(emu.arg32(0), 8))))
    hook_rec(c, 0x5cf300, 2, this=True, nullflag=(0,), side=xy_side)
    hook_rec(c, 0x5a7500, 2, this=True)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x5d2280, 'camera_aim', 'thiscall', None, ret=None, gen=g5d2280)
