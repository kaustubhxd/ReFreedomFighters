"""specs_s213108.py - batch 213108: particle emitter update with timer re-arm, spawn loop and vector helpers, Sonnet-w3b."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def g5168b0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    thr = struct.unpack('<f', bytes(e.rbytes(0x67d9fc, 4)))[0]   # 0.001f

    def fv(lo=-3, hi=3):
        return f32(r.choice([0.0, 0.5, 1.0, -1.0, 2.0, r.uniform(lo, hi), r.uniform(lo, hi)]))

    def vec3b():
        return struct.pack('<fff', fv(), fv(), fv())

    def lg(emu, name, addr, n):
        emu.calllog.append((name, bytes(emu.rbytes(addr, n))))

    this = rnd(c, 0x80)
    e.w32(this + 8, 0 if r.random() < 0.12 else r.getrandbits(32) | 1)
    f10 = f32(r.choice([thr, thr * 2, thr * 0.5, 0.5, 1.0, 0.1, -1.0, r.uniform(0.001, 2)]))
    e.wbytes(this + 0x10, struct.pack('<f', f10))
    tick = r.choice([r.randrange(0, 200000), r.randrange(-1000, 1000), 0])
    f18 = f32(r.choice([(tick + r.choice([-3, -1, 0, 1, 5, 1000])) / 1024.0, r.uniform(0, 200), -1.0]))
    e.wbytes(this + 0x18, struct.pack('<f', f18))
    e.wbytes(this + 0x1c, bytes([r.getrandbits(8)]))
    f71 = fv(-2, 2)
    e.wbytes(this + 0x71, struct.pack('<f', f71))
    f75 = f32(r.choice([0.0, 0.5, 1.0, 0.25, r.random()]))
    e.wbytes(this + 0x75, struct.pack('<f', f75))
    e.wbytes(this + 0xc, struct.pack('<f', f32(r.choice([-0.5, -2.0, 0.0, 0.3, 5.0, f10, f10 - 0.1, r.uniform(-3, 3)]))))
    f14 = f32(r.choice([0.0, 0.5, 1.0, 0.25, r.random()]))
    e.wbytes(this + 0x14, struct.pack('<f', f14))
    for off in (0x2d, 0x31, 0x35, 0x39, 0x3d, 0x41, 0x45, 0x49, 0x4d, 0x51, 0x55, 0x59):
        e.wbytes(this + off, struct.pack('<f', fv()))
    e.wbytes(this + 0x5d, struct.pack('<f', fv()))
    e.wbytes(this + 0x61, struct.pack('<f', fv()))
    e.wbytes(this + 0x1d, struct.pack('<fff', fv(), fv(), fv()))
    # engine
    def rand_st0(emu, k):
        sel = emu.arg32(1)
        if sel == 0x96:
            return f32(r.choice([f75, f75, f75 + 0.001, f75 - 0.001, r.random(), 0.0, 1.0, NAN]))
        if sel == 0xab:
            return f32(r.choice([f14, f14, f14 + 0.001, f14 - 0.001, r.random(), 0.0, 1.0, NAN]))
        return f32(r.choice([0.0, 0.5, 1.0, r.random(), -1.0]))
    eng = obj(c, 0x100, {0x1c0: pystub(c, 2, this=True, st0=rand_st0), 0x1c4: pystub(c, 2, this=True, st0=rand_st0)}, nslots=0x80)
    e.w32(eng + 0x40, tick & 0xffffffff)
    e.wbytes(eng + 0x48, struct.pack('<f', f32(r.choice([0.0, 0.016, 0.1, 1.0, r.uniform(0, 2)]))))
    e.w32(0x70039c, eng)
    # W object at this[0x29] (unaligned)
    def s80(emu, k):
        emu.wbytes(emu.arg32(0), vec3b())
        emu.wbytes(emu.arg32(1), vec3b())

    def s84(emu, k):
        lg(emu, 'q84', emu.arg32(0), 12)
    W = obj(c, 0x20, {0x80: pystub(c, 2, this=True, nullflag=(0, 1), side=s80), 0x84: pystub(c, 1, this=True, nullflag=(0,), side=s84)}, nslots=0x40)
    e.w32(this + 0x29, W)
    # Z object at this[0]
    def s218(emu, k):
        lg(emu, 'r218', emu.arg32(1), 12)
        lg(emu, 'c218', emu.arg32(2), 12)
    Z = obj(c, 0x20, {0x218: pystub(c, 4, this=True, nullflag=(1, 2), side=s218)}, nslots=0x100)
    e.w32(this, Z)
    e.w32(this + 4, r.getrandbits(32))

    def s0a10(emu, k):
        emu.wbytes(emu.reg('ecx'), vec3b())
    hook_rec(c, 0x4e0a10, 0, pop=0, this='mark', side=s0a10)

    def s0980(emu, k):
        lg(emu, 'a0980', emu.reg('ecx'), 12)
        lg(emu, 'b0980', emu.reg('edx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3b())
    hook_rec(c, 0x4e0980, 0, pop=0, this='mark', side=s0980)

    def s19f0(emu, k):
        lg(emu, 'a19f0', emu.reg('ecx'), 12)
        lg(emu, 'b19f0', emu.reg('edx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3b())
    hook_rec(c, 0x4419f0, 0, pop=0, this='mark', side=s19f0)

    def s1940(emu, k):
        lg(emu, 'a1940', emu.reg('ecx'), 12)
        lg(emu, 'b1940', emu.reg('edx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3b())
    hook_rec(c, 0x441940, 0, pop=0, this='mark', side=s1940)

    def s8e0(emu, k):
        lg(emu, 'e8e0', emu.reg('edx'), 12)
        lg(emu, 'b8e0', emu.arg32(0), 12)
        emu.wbytes(emu.reg('ecx'), vec3b())
    hook_rec(c, 0x43e8e0, 1, pop=4, this='mark', nullflag=(0,), side=s8e0)

    def sd00(emu, k):
        lg(emu, 'cd00', emu.reg('ecx'), 12)
        if r.random() < 0.7:
            emu.wbytes(emu.reg('ecx'), vec3b())
    hook_rec(c, 0x4e0d00, 1, pop=4, this='mark', side=sd00)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x5168b0, 'emitter_update', 'thiscall', None, ret=None, gen=g5168b0)
