"""specs_s51001.py - u4 (Sonnet) batch 51001. 0x518190: 0x523330 hooked (writes the vector v); the pure vector helpers and 4e0be0 / 4e0030 / sqrt run as real exe code."""
import struct
import math
from pilot import S
from recruits_util import rnd, obj, sysobj, clear_hooks, hook_rec, pystub


def _fb(f):
    return struct.unpack('<I', struct.pack('<f', f))[0]


def _fl(r, lo=-5, hi=5, z=0.1):
    k = r.random()
    if k < z:
        return r.choice([0.0, -0.0])
    if k < z + 0.02:
        return r.choice([float('nan'), float('inf')])
    return r.uniform(lo, hi)


def _g518190(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = rnd(c, 0x1700)
    e.w32(me + 0x5c, rnd(c, 0x20))
    s = r.choice([0.0, r.uniform(0, 3), r.uniform(0.1, 1), -1.0])
    s2 = r.choice([0.0, r.uniform(0, 3), r.uniform(-1, 1)])
    e.w32(me + 0x37c, _fb(s))
    e.w32(me + 0x378, _fb(s2))
    k = r.choice([0.0, -1.0, r.uniform(0.1, 3), r.uniform(0, 1), float('nan')])
    e.wbytes(me + 0x15fb, struct.pack('<f', k))
    e.wbytes(me + 0x15f7, struct.pack('<f', r.uniform(-3, 3)))
    a = [_fl(r) for _ in range(3)]
    vv = [_fl(r, z=0.3) for _ in range(3)]
    if r.random() < 0.15:
        m = r.choice([3e38, 2e38, 1e-44, 5e-45, 1e30])
        vv = [r.choice([m, -m, 0.0]) for _ in range(3)]
    n = 0
    # P near the normalised, flipped, y-cleared v so that |u| lands around the threshold
    vy = [-vv[0], 0.0, -vv[2]]
    n = math.sqrt(vy[0] ** 2 + vy[2] ** 2) or 1.0
    vn = [x / n for x in vy]
    sc = s2 + s
    if r.random() < 0.6:
        P = [vn[i] + r.uniform(-1e-3, 1e-3) for i in range(3)]
        Q = [a[i] + r.choice([0.0, r.uniform(-1e-3, 1e-3), r.uniform(-2, 2)]) for i in range(3)]
    else:
        P = [_fl(r) for _ in range(3)]
        Q = [_fl(r) for _ in range(3)]
    if r.random() < 0.25:
        # exact threshold: u = (Kt, 0, 0) permuted, with a = 0 and zero scale
        Kt = struct.unpack('<f', e.r32(0x67a284).to_bytes(4, 'little'))[0]

        def f32(x):
            return struct.unpack('<f', struct.pack('<f', x))[0]
        cand = [Kt]
        up = down = Kt
        for _ in range(4):
            up = struct.unpack('<f', struct.pack('<I', struct.unpack('<I', struct.pack('<f', up))[0] + 1))[0]
            down = struct.unpack('<f', struct.pack('<I', struct.unpack('<I', struct.pack('<f', down))[0] - 1))[0]
            cand += [up, down]
        good = [x for x in cand if f32(math.sqrt(f32(x * x))) == Kt]
        q0 = r.choice(good) if good else Kt
        ax = r.randrange(3)
        a = [0.0, 0.0, 0.0]
        Q = [0.0, 0.0, 0.0]
        Q[ax] = q0 * r.choice([1, -1])
        e.w32(me + 0x37c, 0)
        e.w32(me + 0x378, 0)
        P = [0.0, 0.0, 0.0]
    for i in range(3):
        e.wbytes(me + 0x15df + 4 * i, struct.pack('<f', P[i]))
        e.wbytes(me + 0x15d3 + 4 * i, struct.pack('<f', Q[i]))

    def fill(em, kk):
        p = em.arg32(0)
        for i in range(3):
            em.w32(p + 4 * i, _fb(vv[i]))
    hook_rec(c, 0x523330, 1, this=True, nullflag=(0,), side=fill)
    av = rnd(c, 0x10)
    for i in range(3):
        e.w32(av + 4 * i, _fb(a[i]))
    bv = rnd(c, 0x10)
    v = rnd(c, 0x10)
    cc = rnd(c, 0x10)
    return [me, av, bv, v, cc]


S(0x518190, 'GUESS camera follow offset vector and side sign', 'thiscall', None, ret=None, gen=_g518190, nan_heap=True, note='batch51001')
