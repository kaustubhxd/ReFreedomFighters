"""specs_s9002.py - wire-ai batch 9002: 0x5457f0 (point-to-segment test). Segments of every shape (ordinary, A == B, very short), points
projecting before, inside and past the segment, on the line (distance 0 -> the random-unit-vector path), the radius bound around the
distance (inside, outside, exactly at it), NaN-free. 0x43e920, 0x443ef0 (x87, 53-bit control word) and 0x4e0d00 run as exe code; the
random unit vector 0x547430 is hooked (logs the vector's contents, writes a fixed-length random vector)."""
import math
import struct
from pilot import S, f32
from specs_s705 import nostk


def _v(c, s):
    return [c.rng.uniform(-s, s) for _ in range(3)]


def _dpl(c):
    e = c.emu

    def ruv(em, r):
        p = em.reg('ecx')
        em.calllog.append(('ruv', 0, None, tuple(struct.unpack('<3I', em.rbytes(p, 12)))))
        a = c.rng.uniform(0, 2 * math.pi)
        em.wbytes(p, struct.pack('<3f', f32(math.cos(a)), 0.0, f32(math.sin(a))))
        em.ret()
    e.hook(0x547430, ruv)
    s = c.rng.choice([1.0, 100.0, 3000.0])
    A = _v(c, s)
    k = c.rng.random()
    if k < 0.08:
        B = A[:]
    elif k < 0.16:
        B = [A[i] + x for i, x in enumerate(_v(c, 1e-3))]
    else:
        B = [A[i] + x for i, x in enumerate(_v(c, s))]
    u = c.rng.choice([-0.3, 0.0, 0.2, 0.5, 1.0, 1.4, c.rng.uniform(-0.5, 1.5)])
    off = c.rng.choice([0.0, 0.0, 1e-7, c.rng.uniform(0, s), c.rng.uniform(0, 30)])
    d = _v(c, 1.0)
    P = [A[i] + (B[i] - A[i]) * u + d[i] * off for i in range(3)]
    r = c.rng.choice([c.rng.uniform(0, 2 * s), off, 1e9, 0.0, c.rng.uniform(5, 30)])
    if c.rng.random() < 0.12:                          # distance exactly at / around the 1e-6 cut (0x681370)
        h = c.rng.choice([f32(1e-6), f32(1e-6) * (1 + 2 ** -23), f32(1e-6) * (1 - 2 ** -24), 5e-7, 2e-6])
        A, B, P = [0.0, 0.0, 0.0], [1.0, 0.0, 0.0], [0.5, h, 0.0]
        r = c.rng.choice([1.0, 1e-6])
    pts = []
    for v in (P, A, B):
        p = e.alloc(16, 4)
        e.wbytes(p, struct.pack('<3f', *[f32(x) for x in v]))
        pts.append(p)
    outs = [e.alloc(16, 4) for _ in range(4)]
    for o in outs:
        e.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(16)))
    e.wbytes(outs[1], struct.pack('<f', f32(r)))      # rMax
    return pts + [outs[0], outs[1], outs[2], outs[3]]


S(0x5457f0, 'DistPointLineVar (point to segment)', 'fastcall', None, ret='al', gen=_dpl, note='b9002; helpers as exe code, 0x547430 hooked')
