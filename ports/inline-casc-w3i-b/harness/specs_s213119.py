"""specs_s213119.py - batch 213119: aim angles from point-record differences (x87 diffs, CRT atan) with clamps and stepping, Sonnet-w3b."""
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


def g527710(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    crt(c, 0x634de2, math.atan, 'atan')
    lo = struct.unpack('<f', bytes(e.rbytes(0x6a0bd0, 4)))[0]
    hi = struct.unpack('<f', bytes(e.rbytes(0x6a0bc8, 4)))[0]
    K = struct.unpack('<f', bytes(e.rbytes(0x6a09e4, 4)))[0]

    def fv():
        return f32(r.choice([0.0, -0.0, 1.0, -1.0, 2.0, -2.0, 0.5, 3.0, 10.0, r.uniform(-4, 4), r.uniform(-4, 4)]))
    this = rnd(c, 0x2200)
    e.w32(this + 0x8d, r.choice([0, 1, 2, 3, 4, 5, 0xffffffff]))
    e.w32(this + 0x91, r.choice([0, 1, 2, 3, 4, 5, 0xffffffff]))
    # float pairs of the point records: obj + 0x55 and obj + 0xde + 0x55 for obj = this+0x95+0x1bc*j, this+0x785+0x1bc*j and the four final records
    addrs = []
    for base in (0x95, 0x785):
        for j in range(0, 6):
            b = base + 0x1bc * j
            addrs += [b + 0x55, b + 0xde + 0x55]
    addrs += [0x785 + 0x55, 0x95 + 0x55, 0x863 + 0x55, 0x173 + 0x55]
    seen = set()
    zmode = r.random() < 0.12   # every record float is +-0.0: ties and sign-of-zero differences everywhere
    for off in addrs:
        if off + 4 <= 0x2200 and off not in seen:
            seen.add(off)
            e.wbytes(this + off, struct.pack('<f', r.choice([0.0, -0.0]) if zmode else fv()))
    e.wbytes(this + 0x21b9, struct.pack('<f', f32(r.choice([1.0, 2.0, 0.5, 0.0, -1.0, r.uniform(0.2, 3)]))))
    e.wbytes(this + 0x21bd, struct.pack('<f', f32(r.choice([1.0, 2.0, 0.5, 0.0, -1.0, r.uniform(0.2, 3)]))))
    tgts = [lo, hi, 0.0, -0.0, 0.5, -0.5, f32(hi + 2 ** -13), f32(hi - 2 ** -13), f32(lo + 2 ** -13), f32(lo - 2 ** -13), r.uniform(-1, 1)]
    for off in (0x38, 0x30):
        e.wbytes(this + off, struct.pack('<f', f32(r.choice(tgts))))
    dtv = f32(r.choice([0.0, 0.016, 0.1, 0.5, 1.0, -0.016, -0.1, NAN, r.uniform(0, 2)]))
    if not zmode and r.random() < 0.5:
        # saturating mode: A and B are +-2.0 and the divisors tiny, so both angles clamp to hi/lo exactly; the step fields are placed near the known targets
        sx = r.choice([1, -1])
        sy = r.choice([1, -1])
        e.w32(this + 0x8d, 1)
        e.w32(this + 0x91, 0)
        e.wbytes(this + 0x1c8, struct.pack('<f', 2.0 * sx))     # j=0 record: F(edi + 0xde) (shared with F(this+0x173))
        e.wbytes(this + 0xea, struct.pack('<f', 0.0))          # F(edi) (shared with F(this+0x95))
        e.wbytes(this + 0x7da, struct.pack('<f', 2.0 * sy))     # F(this+0x785)
        e.wbytes(this + 0x8b8, struct.pack('<f', 2.0 * sx))     # F(this+0x863): d2 = 0
        e.wbytes(this + 0x21b9, struct.pack('<f', f32(0.001)))
        e.wbytes(this + 0x21bd, struct.pack('<f', f32(0.001)))
        cx = hi if sx > 0 else lo
        cy = hi if sy > 0 else lo
        eps = 2.0 ** -13
        dk = f32(dtv * K)
        deltas = [0.0, 0.0, eps / 2, -eps / 2, eps, -eps, 3 * eps, -3 * eps, 1e-6]
        def near(tg):
            base = r.choice([tg, f32(tg + dk), f32(tg - dk)])
            return f32(base + r.choice(deltas))
        e.wbytes(this + 0x38, struct.pack('<f', near(cx)))
        e.wbytes(this + 0x30, struct.pack('<f', near(cy)))
    eng = obj(c, 0x100, {}, nslots=4)
    e.wbytes(eng + 0x48, struct.pack('<f', dtv))
    e.w32(0x70039c, eng)
    return [this]


S(0x527710, 'aim_angles_step', 'thiscall', None, ret=None, gen=g527710)
