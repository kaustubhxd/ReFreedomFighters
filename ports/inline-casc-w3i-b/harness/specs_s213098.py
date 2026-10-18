"""specs_s213098.py - batch 213098: ring-cursor candidate scan with three float thresholds and two dot-product tests, Sonnet-w3b."""
import math
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

NAN = float('nan')


def f32(x):
    try:
        return struct.unpack('<f', struct.pack('<f', x))[0]
    except OverflowError:
        return x


def g5c4700(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    c1, c2, c3 = (struct.unpack('<f', bytes(e.rbytes(a, 4)))[0] for a in (0x6b4148, 0x6b414c, 0x6b4150))
    K = struct.unpack('<d', bytes(e.rbytes(0x6b4140, 8)))[0]
    small = [0.0, 0.0, 1.0, -1.0, 0.5, 2.0, -0.5]

    def vec3():
        return struct.pack('<fff', *[r.choice(small) for _ in range(3)])

    def vec6():
        return struct.pack('<ffffff', *[r.choice(small) for _ in range(6)])

    # engine: random slot 0x1c0 (double on x87), field +0x48 (float), table at +0x9b
    f48 = f32(r.choice([0.5, 1.0, 2.0, 3.0, 0.25, r.uniform(0.1, 4)]))
    thr = f48 * K

    def drand(emu, k):
        return r.choice([thr, thr, thr * 0.5, thr * 2 + 1.0, 0.0, -1.0, NAN, r.uniform(0, thr * 1.5) if thr > 0 else 0.0, thr * (1 - 2 ** -40) if thr else 0.0])
    eng = obj(c, 0x100, {0x1c0: pystub(c, 2, this=True, st0=drand)}, nslots=0x200)
    e.wbytes(eng + 0x48, struct.pack('<f', f48))

    pool = [rnd(c, 0x20) for _ in range(3)]

    def t58(emu, rr):
        i = emu.arg32(0)
        emu.calllog.append(('t58', i))
        emu.ret(eax=pool[i % 3], argbytes=4)
    T = obj(c, 0x20, {0x58: e.stub_fn('t58', t58)}, nslots=0x120)
    e.w32(eng + 0x9b, T)
    e.w32(0x70039c, eng)

    Q = obj(c, 0x20, {0x30: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32) if r.random() < 0.3 else r.randrange(6), this=True)}, nslots=0x20)
    O = rnd(c, 0x40)
    e.w32(O + 0x18, Q)
    this = rnd(c, 0x80)
    e.w32(this + 0x44, O)
    count = r.choice([0, 1, 2, 3, 5])
    e.w32(this + 0x58, count)
    e.w32(this + 0x5c, r.choice([0, 0, 1, 2, count, count + 1, 0xffffffff, r.getrandbits(32)]) if r.random() < 0.8 else r.randrange(6))
    flag = r.choice([0, 1, 1])
    e.w32(this + 0x60, flag)

    def side4940(emu, k):
        emu.wbytes(emu.arg32(0), vec3())
        emu.wbytes(emu.arg32(1), vec6())
    hook_rec(c, 0x5c4940, 2, pop=8, this=True, nullflag=(0, 1), side=side4940)

    def side5010(emu, k):
        p34, p28 = emu.arg32(0), emu.arg32(1)
        if emu.r32(emu.reg('ecx') + 0x60):
            emu.calllog.append(('in5010', bytes(emu.rbytes(p34, 12)), bytes(emu.rbytes(p28, 24))))
        if not emu.r32(emu.reg('ecx') + 0x60) or r.random() < 0.5:
            emu.wbytes(p34, vec3())
            emu.wbytes(p28, vec6())
    hook_rec(c, 0x5c5010, 2, pop=8, this=True, nullflag=(0, 1), side=side5010,
             ret=lambda emu, k: 0xffffffff if r.random() < 0.15 else r.randrange(4))

    def side4a00(emu, k):
        emu.wbytes(emu.arg32(1), vec3())
    hook_rec(c, 0x5c4a00, 2, pop=8, this=True, nullflag=(1,), side=side4a00)

    def dval(emu, k):
        emu.calllog.append(('dist', bytes(emu.rbytes(emu.reg('ecx'), 12)), bytes(emu.rbytes(emu.reg('edx'), 12))))
        return f32(r.choice([c1, c2, c3, c1, c2, c3, c1 * 0.5, c2 * 0.5, c3 * 0.5, c1 * 2, c3 * 2, (c2 + c1) / 2, (c3 + c2) / 2, 0.0, -1.0, NAN, r.uniform(0, max(c1, c2, c3) * 2)]))
    hook_rec(c, 0x4e0830, 0, pop=0, st0=dval)

    def sub_side(emu, k):
        emu.calllog.append(('sub', bytes(emu.rbytes(emu.reg('edx'), 12)), bytes(emu.rbytes(emu.arg32(0), 12))))
        emu.wbytes(emu.reg('ecx'), vec3())
    hook_rec(c, 0x43e920, 1, pop=4, nullflag=(0,), side=sub_side)

    def side4cc0(emu, k):
        emu.calllog.append(('v10', bytes(emu.rbytes(emu.arg32(0), 12))))
    hook_rec(c, 0x5c4cc0, 3, pop=12, this=True, nullflag=(0,), side=side4cc0)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [this]


S(0x5c4700, 'ring_candidate_scan', 'thiscall', None, ret=None, gen=g5c4700)
