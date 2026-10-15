"""specs_s35197.py - 0x51db60 (thiscall, no args, ret=None, nan_heap). [0x7003b8] -> block with byte +0xab8 set in 1/6. Engine: slot 0x1c0 (2 args; returns an x87 float: first call around the constant at 0x67a284, second random), unaligned +0x1aa3 -> E with [+0x1c] = F (slot 0x74, 1 arg, returns an id) and [+0x18] = G (slot 0xf8, 1 arg, returns a record or 0 in 1/4; byte +2 random);
table slots 0x58 (1 arg) and 0x160 (1 arg; returns an object with dword +0x44 or 0 in 1/4). this: 0x700 random bytes with steered unaligned floats +0x597 (around [0x680a90], [0x680a90] + KC, and the constant at 0x68af28), +0x54e, +0x552, +0x556 and dwords +0x56a; slots 0x8c / 0x90 (1 arg, the stack vectors recorded as three dwords).
0x51c470 (al true in 1/2), 0x517030 (2 args), 0x516f40 (1 arg, vector recorded) and 0x5168b0 hooked. 0x4e0d00, 0x441940 and the CRT sin/cos run as real code."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub, sysobj


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _f(b):
    return struct.unpack('<f', struct.pack('<I', b))[0]


def _sf(c, lo, hi):
    v = c.fv(lo, hi)
    return v if (v == v and abs(v) < 1e5) else 0.5


def _g51db60(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    g = rnd(c, 0xac0)
    e.w8(g + 0xab8, r.choice([0, 0, 0, 0, 1, 7]))
    e.w32(0x7003b8, g)
    K1 = _f(e.r32(0x67a284))
    KC = _f(e.r32(0x67d164))
    B0 = _f(e.r32(0x680a90))
    K5 = _f(e.r32(0x68af28))
    rv = [r.choice([K1 - 1, K1 * 0.5, K1, K1 + 1, _sf(c, -2, 2)]), _sf(c, -3, 3)]
    Fo = obj(c, 0x20, {0x74: pystub(c, 1, this=True, ret=r.getrandbits(32))}, nslots=0x30)
    rec = 0 if r.random() < 1 / 4 else rnd(c, 0x10)
    Go = obj(c, 0x20, {0xf8: pystub(c, 1, this=True, ret=rec)}, nslots=0x40)
    E = rnd(c, 0x40)
    e.w32(E + 0x1c, Fo)
    e.w32(E + 0x18, Go)
    ob = 0 if r.random() < 1 / 4 else rnd(c, 0x60)
    so = sysobj(c, slots={0x1c0: pystub(c, 2, this=True, st0=lambda em, k: rv[min(k, 1)])},
                table_slots={0x58: pystub(c, 1, this=True), 0x160: pystub(c, 1, this=True, ret=ob)}, table_size=0x170)
    e.wbytes(so + 0x1aa3, E.to_bytes(4, 'little'))
    me = obj(c, 0x700, {0x8c: pystub(c, 1, this=True, deref={0: 3}), 0x90: pystub(c, 1, this=True, deref={0: 3})}, nslots=0x24)

    def pf(off, v):
        e.wbytes(me + off, _fb(v).to_bytes(4, 'little'))
    pf(0x597, r.choice([B0, B0 + KC, B0 + KC * 0.5, B0 - 1, K5 - 1, K5, K5 + 1, _sf(c, -5, 5)]))
    pf(0x54e, _sf(c, -50, 50))
    pf(0x552, _sf(c, -50, 50))
    pf(0x556, _sf(c, -50, 50))
    e.wbytes(me + 0x56a, r.getrandbits(32).to_bytes(4, 'little'))
    hook_rec(c, 0x51c470, 0, this=True, pop=0, ret=lambda em, k: (r.getrandbits(24) << 8) | 1 if r.random() < 0.5 else (r.getrandbits(24) << 8))
    hook_rec(c, 0x517030, 2, this=True, pop=8)
    hook_rec(c, 0x516f40, 1, this=True, pop=4, deref={0: 3})
    hook_rec(c, 0x5168b0, 0, this=True, pop=0)
    return [me]


S(0x51db60, 'GUESS spawn randomly placed effect', 'thiscall', None, ret=None, gen=_g51db60, nan_heap=True, note='batch35197')
