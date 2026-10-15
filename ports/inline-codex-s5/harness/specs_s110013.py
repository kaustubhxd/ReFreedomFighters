"""specs_s1148.py - unclaimed-11 batch 49 (slice 10): 0x44fde0 (GUESS, segment/sphere test), fastcall: ecx = A, edx = B,
stack C, outT, radius pointer, outDist, outVec (ret 0x14), returns al.
ab = A - B, cb = C - B (0x43e920, exe code); lenSq = cb.cb, dot = ab.cb (SSE, in the PC's order); *outT = dot; if the bits of
dot are negative: *outT = 0, closest = B; else if bits(dot) > bits(lenSq) (signed int compare): *outT = 1.0, closest = C; else
t = dot / lenSq, *outT = t, closest = B + cb * t (0x443ef0, exe code). outVec = A - closest (0x43e920). If bits(|outVec|^2) >
bits(r * r): return 0. Else d = (float)sqrt((double)|outVec|^2) (the CRT sqrt; correctly rounded), *outDist = d; if bits(d) >
bits(1e-6) the vector is scaled by 1/d (0x4e0d00, exe code), else 0x451250 (random unit vector through the engine, not verified:
stubbed as a call counter); return 1.
Inputs: B and C random; A is the point at a random t (inside and outside 0..1) plus an offset, sometimes exactly on the
segment (the tiny-distance path); the radius is sometimes the exact distance; specials (NaN, inf, -0) now and then."""
import math
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import struct
from recruits_util import clear_hooks,hook_rec,pystub
from pilot import S


def _f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0] if math.isfinite(x) and abs(x) < 3e38 else x


def _vec(c, v):
    c.emu.alloc(0x10, 16)
    a = c.emu.alloc(0x10, 4)
    for i in range(3):
        c.emu.wf32(a + 4 * i, v[i])
    return a


def _special(c):
    return c.rng.choice((0.0, -0.0, 1e-30, -1.0, 1.0))


def _gen(c):
    clear_hooks(c)
    c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))
    r = c.rng
    B = [_f32(r.uniform(-100, 100)) for _ in range(3)]
    C = [_f32(B[i] + r.choice((r.uniform(-50, 50), 0.0, r.uniform(-1e-3, 1e-3)))) for i in range(3)]
    if C == B: C[0] = _f32(B[0] + 1.)
    t = r.choice((r.uniform(0, 1), r.uniform(-1, 0), r.uniform(1, 2), 0.0, 1.0, 0.5))
    off_scale = r.choice((0.0, 0.0, 1e-7, r.uniform(0, 1), r.uniform(0, 20), r.uniform(0, 200)))
    A = [_f32(B[i] + (C[i] - B[i]) * t + r.uniform(-1, 1) * off_scale) for i in range(3)]
    if r.random() < 0.05:
        A[r.randrange(3)] = _special(c)
    # the distance from A to the true closest point, to pick a radius near it
    cb = [C[i] - B[i] for i in range(3)]
    ll = sum(x * x for x in cb)
    tt = 0.0 if not (ll > 0) else min(1.0, max(0.0, sum((A[i] - B[i]) * cb[i] for i in range(3)) / ll)) if all(
        math.isfinite(x) for x in A + C) else 0.0
    dist = math.sqrt(sum((A[i] - B[i] - cb[i] * tt) ** 2 for i in range(3))) if all(math.isfinite(x) for x in A + C) else 1.0
    rad = r.choice((dist, dist * r.uniform(0.5, 1.5), r.uniform(0, 50), _f32(dist) if math.isfinite(dist) else 1.0,
                    -dist, 0.0, _special(c)))
    pa, pb, pc = _vec(c, A), _vec(c, B), _vec(c, C)
    outs = c.emu.alloc(0x40, 4)
    c.emu.wbytes(outs, bytes(r.getrandbits(8) for _ in range(0x40)))
    prad = c.emu.alloc(4, 4)
    c.emu.wf32(prad, rad)
    hook_rec(c,0x451250,0,this=True,side=lambda em,n: em.wbytes(em.reg("ecx"),struct.pack("<fff",1.,0.,0.)))
    # outT, outDist, outVec live in one random block (disjoint fields)
    return [pa, pb, pc, outs, prad, outs + 8, outs + 0x10]


S(0x44fde0, 'GUESS (no name) segment/sphere test fastcall ret 0x14 returns al', 'fastcall', None, ret='al', gen=_gen,
  note='unclaimed-11 batch 49 (slice 10); 0x451250 stubbed, 0x43e920/0x443ef0/0x4e0d00 exe code')
