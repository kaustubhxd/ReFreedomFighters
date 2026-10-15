"""specs_s52008.py - tier H. 0x546d70: up to 3 pairs {i, j, k} at the unaligned pointer [this+0x13] into four 0x34-byte point records at the unaligned pointer [this+0xf] (positions +0xc, weights +0x30); coincident or very close points (the retry loop through engine slot 0x1c4 returning a scripted float list: a few tiny values, then normal ones) and ordinary ones; the real x87 vector helpers and CRT sqrt run; /GS check keeps eax."""
import struct
from pilot import S, EDGE_F
from recruits_util import rnd, obj, clear_hooks, pystub, hook_rec, sysobj


def _f(v):
    return struct.unpack('<f', struct.pack('<f', v))[0]


def _g546d70(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    th0 = struct.unpack('<f', struct.pack('<I', 0x358637bd))[0]
    lst = [r.choice([0.0, 1e-9, -1e-8, 1e-7]) for _ in range(r.choice([0, 1, 2, 3, 4, 6]))] + [_f(r.uniform(-3, 3)) for _ in range(12)]
    if r.random() < 0.25:
        lst = [0.0, 0.0, 0.0] + [th0, 0.0, 0.0] + lst
    sysobj(c, slots={0x1c4: pystub(c, 2, this=True, st0=lambda em, k: lst[min(k, len(lst) - 1)])})
    recs = rnd(c, 4 * 0x34 + 8)
    for i in range(4):
        base = recs + 0x34 * i
        for j in range(3):
            v = r.choice([0.0, 1.0, -2.5, 1e-7, _f(r.uniform(-50, 50)), _f(r.uniform(-1, 1))])
            e.w32(base + 0xc + 4 * j, struct.unpack('<I', struct.pack('<f', v))[0])
        e.w32(base + 0x30, struct.unpack('<I', struct.pack('<f', r.choice([0.0, 1.0, 2.0, 0.5, _f(r.uniform(0.01, 10)), -1.0])))[0])
    if r.random() < 0.4:   # coincide two records
        a, b = r.sample(range(4), 2)
        e.wbytes(recs + 0x34 * b + 0xc, bytes(e.rbytes(recs + 0x34 * a + 0xc, 12)))
    th = struct.unpack('<f', struct.pack('<I', 0x358637bd))[0]   # the exe's 1e-6 threshold
    if r.random() < 0.25:   # a pair exactly one threshold apart
        for j in range(3):
            e.w32(recs + 0xc + 4 * j, 0)
            e.w32(recs + 0x34 + 0xc + 4 * j, 0)
        e.w32(recs + 0x34 + 0xc, 0x358637bd)
    n = r.choice([0, 1, 1, 2, 3, -1])
    arr = rnd(c, 12 * 4 + 4)
    for p in range(4):
        i, j = r.randrange(4), r.randrange(4)
        k = r.choice([0.0, 1.0, 0.1, _f(r.uniform(-2, 5))])
        e.w32(arr + 12 * p, i)
        e.w32(arr + 12 * p + 4, j)
        e.w32(arr + 12 * p + 8, struct.unpack('<I', struct.pack('<f', k))[0])
    me = rnd(c, 0x40)
    e.wbytes(me + 0xf, recs.to_bytes(4, 'little'))
    e.wbytes(me + 0x13, arr.to_bytes(4, 'little'))
    e.w32(me + 0x2c, n & 0xffffffff)
    return [me]


S(0x546d70, 'GUESS separate close point pairs', 'thiscall', None, ret=None, gen=_g546d70, note='batch52008')
