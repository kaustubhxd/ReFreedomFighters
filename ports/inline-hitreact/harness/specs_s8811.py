"""specs_s8811.py - hitreact batch 8811: AdjustCone4 0x542310 (fastcall ia, ib; stack ic, id, M, F(a), F(b), parts; ret 0x18).
Exe code in both builds: PSVECSubtract / vmtmul / vmmul / PSVECAdd / vnorm / vcross / vadd3 / the Cramer solver 0x547860 / vscalar /
vscalar3 / vaddscalar. Particles: 16 records of 0x34 bytes (position +0xc, mass +0x30)."""
import math
from pilot import S, F
from wkit import fedge
from hkit import fvec


def _rot(r):
    ax, ay, az = (r.uniform(-math.pi, math.pi) for _ in range(3))
    cx, sx, cy, sy, cz, sz = math.cos(ax), math.sin(ax), math.cos(ay), math.sin(ay), math.cos(az), math.sin(az)
    return [cy * cz, cy * sz, -sy,
            sx * sy * cz - cx * sz, sx * sy * sz + cx * cz, sx * cy,
            cx * sy * cz + sx * sz, cx * sy * sz - sx * cz, cx * cy]


def _gen(c):
    r = c.rng
    e = c.emu
    n = 16
    base = e.alloc(0x34 * n + 0x40, 4)
    e.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * n + 0x40)))
    big = r.random() < 0.3
    mchoice = lambda: r.choice((1.0, 2.0, 10000.0, r.uniform(0.1, 20), r.uniform(0.1, 20), 1e6, 1e30, 0.0, -1.0, fedge(c))) \
        if r.random() < 0.3 else (10000.0 if big else r.uniform(0.2, 20))
    for i in range(n):
        for k in range(3):
            e.wf32(base + i * 0x34 + 0xc + 4 * k, r.uniform(-50, 50))
        e.wf32(base + i * 0x34 + 0x30, mchoice())
    idx = r.sample(range(n), 4)
    if r.random() < 0.05:
        idx[r.randrange(1, 4)] = idx[0]
    ia, ib, ic, id_ = idx
    rm = _rot(r)
    if r.random() < 0.05:
        rm = [0.0] * 9
    a = r.choice((r.uniform(0.1, 2), r.uniform(0.1, 2), 1.0, 0.0, fedge(c))) if r.random() < 0.1 else r.uniform(0.1, 2)
    b = r.choice((r.uniform(0.1, 2), r.uniform(0.1, 2), 1.0, 0.0, fedge(c))) if r.random() < 0.1 else r.uniform(0.1, 2)
    A = [r.uniform(-50, 50) for _ in range(3)]
    for k in range(3):
        e.wf32(base + ia * 0x34 + 0xc + 4 * k, A[k])
    # D in the cone frame: l = M^T (D - A) -> D - A = M l (rows of M are the frame axes)
    mode = r.random()
    if mode < 0.7:
        lz = r.uniform(-30, 30)
        ang = r.uniform(0, 2 * math.pi)
        ratio = r.choice((r.uniform(0, 2), 1.0, 0.999, 1.001, 0.0))   # |s| / l.z: < 1 inside the cone
        rr = abs(lz) * ratio
        lx = rr * math.cos(ang) / (a if math.isfinite(a) and a != 0 else 1.0)
        ly = rr * math.sin(ang) / (b if math.isfinite(b) and b != 0 else 1.0)
        if r.random() < 0.05:
            lx = ly = 0.0
        L = [lx, ly, lz]
        Dv = [A[k] + sum(L[j] * rm[3 * j + k] for j in range(3)) for k in range(3)]
        for k in range(3):
            e.wf32(base + id_ * 0x34 + 0xc + 4 * k, Dv[k])
    if r.random() < 0.05:   # degenerate triangle
        for k in range(3):
            e.wf32(base + ic * 0x34 + 0xc + 4 * k, e.rf32(base + ib * 0x34 + 0xc + 4 * k))
    special = r.random()
    if special < 0.08:      # exact cone surface: M = I, a / b powers of two, integer offsets on a Pythagorean triple (z^2 == x^2 + y^2)
        rm = [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]
        a, b = r.choice((1.0, 0.5, 2.0)), r.choice((1.0, 0.5, 2.0))
        A = [float(r.randrange(-40, 40)) for _ in range(3)]
        p_, q_, z_ = r.choice(((3, 4, 5), (5, 12, 13), (6, 8, 10), (8, 15, 17), (0, 7, 7), (9, 0, 9)))
        z_ += r.choice((0, 0, 0, 1, -1))
        sx, sy = r.choice((1, -1)), r.choice((1, -1))
        L = [sx * p_ / a, sy * q_ / b, float(z_) * r.choice((1, 1, 1, -1))]
        for k in range(3):
            e.wf32(base + ia * 0x34 + 0xc + 4 * k, A[k])
            e.wf32(base + id_ * 0x34 + 0xc + 4 * k, A[k] + L[k])
    elif special < 0.16:    # A, B, C immovable (mass inf): den = 1 / mD exactly, on the 1/8192 cut
        for i in (ia, ib, ic):
            e.wf32(base + i * 0x34 + 0x30, float('inf'))
        e.wf32(base + id_ * 0x34 + 0x30, r.choice((8192.0, 8192.0, 8191.999, 8192.001, 4096.0, 16384.0)))
        _outside(c, base, rm, a, b, A, id_)
    if r.random() < 0.15:   # thin triangle: |r1 x r2| near 1e-3, i.e. the solvers' determinant |r3|^2 near the 1e-6 cut
        B = [e.rf32(base + ib * 0x34 + 0xc + 4 * k) for k in range(3)]
        r1 = [B[k] - A[k] for k in range(3)]
        n1 = math.sqrt(sum(x * x for x in r1)) or 1.0
        v = [r.uniform(-1, 1) for _ in range(3)]
        cr = [r1[1] * v[2] - r1[2] * v[1], r1[2] * v[0] - r1[0] * v[2], r1[0] * v[1] - r1[1] * v[0]]
        nc = math.sqrt(sum(x * x for x in cr)) or 1.0
        nh = [(cr[1] * r1[2] - cr[2] * r1[1]), (cr[2] * r1[0] - cr[0] * r1[2]), (cr[0] * r1[1] - cr[1] * r1[0])]
        nn = math.sqrt(sum(x * x for x in nh)) or 1.0
        t = r.uniform(-2, 2)
        delta = r.choice((1e-3 * r.uniform(0.9, 1.1), 1e-3 * r.uniform(0.99, 1.01), r.uniform(1e-4, 1e-2))) / n1
        for k in range(3):
            e.wf32(base + ic * 0x34 + 0xc + 4 * k, A[k] + t * r1[k] + delta * nh[k] / nn)
        _outside(c, base, rm, a, b, A, id_)
    if r.random() < 0.04:   # D on the apex
        for k in range(3):
            e.wf32(base + id_ * 0x34 + 0xc + 4 * k, A[k])
    if r.random() < 0.03:
        e.wf32(base + id_ * 0x34 + 0xc + 4 * r.randrange(3), fedge(c))
    M = fvec(c, rm + [0.0, 0.0, 0.0])
    return [ia, ib, ic, id_, M, F(a), F(b), base]


def _outside(c, base, rm, a, b, A, id_):
    r = c.rng
    lz = r.uniform(-30, 30)
    ang = r.uniform(0, 2 * math.pi)
    rr = abs(lz) * r.uniform(1.2, 3) + r.uniform(1, 5)
    L = [rr * math.cos(ang) / (a if math.isfinite(a) and a != 0 else 1.0), rr * math.sin(ang) / (b if math.isfinite(b) and b != 0 else 1.0), lz]
    for k in range(3):
        c.emu.wf32(base + id_ * 0x34 + 0xc + 4 * k, A[k] + sum(L[j] * rm[3 * j + k] for j in range(3)))


S(0x542310, 'AdjustCone4', 'fastcall', ret=None, gen=_gen)
