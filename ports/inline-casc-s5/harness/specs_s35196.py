"""specs_s35196.py - 0x446b50 (thiscall(a, unused) ret 8, ret=None, nan_heap). this: object with slot 0x6c (1 arg; the matrix, flag-recorded pointer, recorded as its nine dwords) and [+8] -> block with [+0x50] = matrix block (nine floats), [+0x24] = three floats (the position). a: three floats; special cases make a - position
zero (no normalisation) or parallel to the matrix's second row (|dot| exactly equal to the constant at 0x678610, the W.x += 1 tweak, and zero cross products)."""
import struct
from pilot import S
from recruits_util import rnd, obj, clear_hooks, pystub


def _fb(v):
    return struct.unpack('<I', struct.pack('<f', v))[0]


def _sf(c, lo, hi):
    v = c.fv(lo, hi)
    return v if (v == v and abs(v) < 1e5) else 0.5


def _g446b50(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    me = obj(c, 0x20, {0x6c: pystub(c, 1, this=True, deref={0: 9})}, nslots=0x20)
    mat = rnd(c, 0x24)
    pos = rnd(c, 0x10)
    blk = rnd(c, 0x60)
    P = [_sf(c, -10, 10) for _ in range(3)]
    for i in range(3):
        e.w32(pos + 4 * i, _fb(P[i]))
    M = [_sf(c, -2, 2) for _ in range(9)]
    a = rnd(c, 12)
    t = r.random()
    if t < 0.15:
        A = list(P)                                  # a - position = 0
    elif t < 0.35:
        k = r.choice([1.0, -1.0, 2.0, 0.5, -3.0])    # parallel to the second row: dot = +-1 after normalisation
        M[3], M[4], M[5] = 1.0, 0.0, 0.0
        A = [P[0] + k, P[1], P[2]]
    elif t < 0.45:
        M[3], M[4], M[5] = 0.0, 0.0, 1.0
        A = [P[0], P[1], P[2] + r.choice([1.0, -2.0])]
    elif t < 0.65:   # nearly parallel: the float dot product rounds to exactly +-1.0 while the cross product is small but non-zero
        M[3], M[4], M[5] = r.choice([1.0, -1.0, 2.0]), 0.0, 0.0
        eps = r.choice([1e-5, 1e-4, 2e-4, 3e-4])
        A = [P[0] + r.choice([1.0, -1.0, 5.0]), P[1] + eps * r.choice([1, -1]), P[2] + eps * r.choice([0, 1, -1])]
    elif t < 0.75:   # perpendicular with a non-unit second row: the cross product has only a z component and needs the normalisation
        M[3], M[4], M[5] = r.choice([2.0, 0.5, -3.0]), 0.0, 0.0
        A = [P[0], P[1] + r.choice([1.0, -2.0, 0.25]), P[2]]
    elif t < 0.9:   # near-parallel with a W that has a y component (and sometimes z)
        import math
        th = r.uniform(0, 2 * math.pi)
        wx, wy = math.cos(th), math.sin(th)
        wz = r.choice([0.0, 0.0, 0.3])
        nrm = math.sqrt(wx * wx + wy * wy + wz * wz)
        M[3], M[4], M[5] = wx / nrm, wy / nrm, wz / nrm
        k = r.choice([1.0, -1.0, 3.0])
        eps = r.choice([0.0, 1e-5, 1e-4])
        A = [P[0] + k * M[3] + eps, P[1] + k * M[4], P[2] + k * M[5]]
    else:
        A = [_sf(c, -10, 10) for _ in range(3)]
    for i in range(9):
        e.w32(mat + 4 * i, _fb(M[i]))
    for i in range(3):
        e.w32(a + 4 * i, _fb(A[i]))
    e.w32(blk + 0x50, mat)
    e.w32(blk + 0x24, 0)
    e.w32(me + 8, blk)
    # the position is at [blk + 0x24]: three floats
    for i in range(3):
        e.w32(blk + 0x24 + 4 * i, _fb(P[i]))
    return [me, a, r.getrandbits(32)]


S(0x446b50, 'GUESS orthonormal look-at frame handed to the object', 'thiscall', None, ret=None, gen=_g446b50, nan_heap=True, note='batch35196')
