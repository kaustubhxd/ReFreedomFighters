"""specs_s35189.py - 0x5a5f70 (thiscall, no args, ret=None, nan_heap). Engine dt float at +0x48 (0.016, 0.5, 0, KA-ish, random). this: 0x900 random bytes with steered unaligned fields: dword +0x300 (== 0x10000000 in 1/3), O1 +0x689 (null in 1/4) and float +0x68d, byte +0x658, ptrs +0x638/+0x64c/+0x634/+0x630/+0x434, float +0x2fc and +0x8d4
(around KA = float at 0x67c198 and KB at 0x67c194), byte +0x3c7 with float +0x3c8 and dword +0x3cc, float +0x3d0, float +0x374 (exactly 1.0 in 1/3, zero in 1/5, else random), dword +0x378. Hooks: 0x5ec2b0 (2 args), 0x5eebf0 / 0x5efcc0 / 0x5eff00 (0 args), 0x5ac5b0 (1 arg), 0x5acac0 (1 arg), all thiscall and recorded."""
import struct
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _f(b):
    return struct.unpack('<f', struct.pack('<I', b))[0]


def sfv(c, lo, hi):
    v = c.fv(lo, hi)
    return v if (v == v and -1e6 < v < 1e6) else 0.25   # NaN / huge values reach the CRT float-to-int error path (_except1, no stub)


def _g5a5f70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    KA = _f(e.r32(0x67c198))
    KB = _f(e.r32(0x67c194))
    so = sysobj(c, table_size=0x20)
    dt = r.choice([0.016, 0.016, 0.5, 0.0, 1.0, sfv(c, 0, 2), abs(KA) * 0.25 if KA == KA else 0.1])
    e.w32(so + 0x48, _fb(dt))
    me = rnd(c, 0x900)

    def pf(off, v):
        e.wbytes(me + off, _fb(v).to_bytes(4, 'little'))

    def pp(off, v):
        e.wbytes(me + off, v.to_bytes(4, 'little'))

    def pv(*choices):
        return r.choice(choices)
    e.wbytes(me + 0x300, (0x10000000 if r.random() < 1 / 3 else r.getrandbits(32)).to_bytes(4, 'little'))
    pf(0x8bb, sfv(c, -2, 2))
    pp(0x689, 0 if r.random() < 1 / 4 else rnd(c, 0x40))
    pf(0x68d, pv(0.0, 0.3, dt, dt * 0.5, dt * 2, -1.0, sfv(c, 0, 3), sfv(c, -1, 1)))
    e.w8(me + 0x658, r.choice([0, 1, 7]))
    for off in (0x638, 0x64c, 0x634, 0x630, 0x434):
        pp(off, rnd(c, 0x40))
    pf(0x2fc, pv(KA - 1, KA, KA + 1, sfv(c, -5, 5), 0.0))
    pf(0x8d4, pv(0.0, KB - dt, KB, KB + 0.001, KA - dt, KA, sfv(c, -2, 5)))
    e.w8(me + 0x3c7, r.choice([0, 1, 1, 9]))
    pf(0x3c8, pv(0.0, KA * 0.5, KA - dt, KA, KA + 0.5, sfv(c, 0, 3), sfv(c, -1, 1)))
    pp(0x3cc, r.getrandbits(32))
    pf(0x3d0, pv(0.0, 0.0, dt * 0.5, dt, dt * 2, -0.5, sfv(c, -1, 3)))
    t = r.random()
    pf(0x374, 1.0 if t < 1 / 3 else (0.0 if t < 0.5 else pv(dt * 0.5, dt, dt * 2, 2.0, -1.0, sfv(c, -1, 3))))
    pp(0x378, r.getrandbits(32) if r.random() < 0.5 else r.randint(0, 5000))
    hook_rec(c, 0x5ec2b0, 2, this=True, pop=8)
    for a in (0x5eebf0, 0x5efcc0, 0x5eff00):
        hook_rec(c, a, 0, this=True, pop=0)
    hook_rec(c, 0x5ac5b0, 1, this=True, pop=4)
    hook_rec(c, 0x5acac0, 1, this=True, pop=4)
    return [me]


S(0x5a5f70, 'GUESS per-frame timer update of a character', 'thiscall', None, ret=None, gen=_g5a5f70, nan_heap=True, note='batch35189')
