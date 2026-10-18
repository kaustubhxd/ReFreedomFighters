"""specs_s213084.py - batch 213084: angle driven turn-rate curve, Sonnet-w3b."""
import math
import struct
from unicorn.x86_const import UC_X86_REG_XMM0
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')
f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]


def nextf(v, d):
    b = struct.unpack('<I', struct.pack('<f', v))[0]
    return struct.unpack('<f', struct.pack('<I', b + d))[0]


def g549450(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    consts = [struct.unpack('<f', bytes(e.rbytes(a, 4)))[0] for a in (0x693d3c, 0x693d48, 0x693d4c, 0x693d58, 0x693d38, 0x693d30)]

    def sqrt_side(em, k):
        a = em.reg('xmm0') & ((1 << 64) - 1)
        x = struct.unpack('<d', struct.pack('<Q', a))[0]
        em.calllog.append(('sqrt', a))
        try:
            z = math.sqrt(x)
        except ValueError:
            z = math.nan
        em.mu.reg_write(UC_X86_REG_XMM0, struct.unpack('<Q', struct.pack('<d', z))[0])
    hook_rec(c, 0x634d7c, 0, side=sqrt_side)

    def vec(scale=3):
        return (f32(r.uniform(-scale, scale)), f32(r.uniform(-scale, scale)), f32(r.uniform(-scale, scale)))
    q1 = rnd(c, 0x10)
    q2 = rnd(c, 0x10)
    e.wbytes(q1, struct.pack('<fff', *vec()))
    e.wbytes(q2, struct.pack('<fff', *vec()))
    Sobj = obj(c, 0x20, {0x2c: pystub(c, 0, ret=q1, this=True), 0x38: pystub(c, 0, ret=q2, this=True)}, nslots=0x40)
    X = rnd(c, 0x8060)
    e.w32(X + 0x8049, Sobj)
    this = rnd(c, 0x20)
    e.w32(this + 8, X)
    R = rnd(c, 0xc0)
    e.wbytes(R + 0x94, struct.pack('<fff', *vec()))
    e.wbytes(R + 0x4c, struct.pack('<f', r.choice([1.0, 2.5, -3.0, 0.0, NAN, f32(r.uniform(-5, 5))])))
    e.wbytes(R + 0xac, struct.pack('<f', r.choice([1.0, 2.0, 0.5, 0.0, 10.0, f32(r.uniform(0.1, 5)), -1.0, NAN])))

    def tval(emu, k):
        x = r.random()
        if x < 0.55:
            kk = r.choice(consts + [0.0])
            return r.choice([kk, nextf(kk, 1), nextf(kk, -1) if kk else -1e-30, f32(kk + 0.001), f32(kk - 0.001)])
        if x < 0.85:
            return f32(r.uniform(-0.3, 3.4))
        return r.choice([NAN, -1.0, 4.0, float('inf'), -float('inf'), 0.0, -0.0])

    def f4(emu, k):
        emu.calllog.append(('ab', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 12))))
    hook_rec(c, 0x4e0030, 0, pop=0, st0=tval, side=f4)

    def v3(emu, k):
        emu.calllog.append(('sub', bytes(emu.rbytes(emu.reg('edx'), 12)), bytes(emu.rbytes(emu.arg32(0), 12))))
        z = r.random()
        if z < 0.15:
            v = (0.0, 0.0, 0.0)
        elif z < 0.25:
            v = (3.0, 4.0, 0.0)
        else:
            v = vec(5)
        emu.wbytes(emu.reg('ecx'), struct.pack('<fff', *v))
    hook_rec(c, 0x43e920, 1, pop=4, nullflag=(0,), side=v3)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this, R]


S(0x549450, 'turn_rate_curve', 'thiscall', None, ret='eax', gen=g549450)
