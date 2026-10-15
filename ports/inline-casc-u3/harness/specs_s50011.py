"""specs_s50011.py - u3 batch 50011 (Haiku slot, run by Sonnet 5.5), tier H. 0x4e1c90: fastcall(out, P, N, verts, n): polygons of 0-6 vertices (random floats), plane point P and normal N,
sometimes vertices placed exactly on the plane (distance 0) or built so all / none / some are in front; 0x43e920, 0x4e0d00 and 0x441940 run as exe code; the output buffer is random-filled; /GS check keeps eax."""
import struct
from pilot import S, F
from recruits_util import rnd, clear_hooks, hook_rec


def _fb(v):
    return struct.pack('<f', v)


def _g4e1c90(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x633654, 0, pop=0, ret=lambda em, k: em.reg("eax"))
    n = r.choice([0, 1, 2, 3, 3, 4, 4, 5, 6])
    out = rnd(c, 12 * (2 * n + 2) + 16)
    verts = rnd(c, 12 * n + 16)
    P = rnd(c, 0x10)
    N = rnd(c, 0x10)
    for j in range(3):
        e.wbytes(P + 4 * j, _fb(r.uniform(-5, 5)))
    nv = [r.uniform(-1, 1) for _ in range(3)]
    if r.random() < 0.3:
        nv = r.choice([[1.0, 0, 0], [0, 1.0, 0], [0, 0, 1.0], [0, 0, 0]])
    for j in range(3):
        e.wbytes(N + 4 * j, _fb(nv[j]))
    p = struct.unpack('<3f', e.rbytes(P, 12))
    for i in range(n):
        k = r.random()
        if k < 0.1:
            v = [p[j] + r.choice([0.0, 0.0, 1.0]) * (1 if nv[j] == 0 else 0) for j in range(3)]
        else:
            v = [r.uniform(-8, 8) for _ in range(3)]
        for j in range(3):
            e.wbytes(verts + 12 * i + 4 * j, _fb(v[j]))
    return [out, P, N, verts, n]


S(0x4e1c90, 'GUESS clip polygon against plane', 'fastcall', None, ret='eax', gen=_g4e1c90, nan_heap=True, note='batch50011')
