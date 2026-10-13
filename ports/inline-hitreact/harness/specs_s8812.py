"""specs_s8812.py - hitreact batch 8812: AdjustCone5 0x5428f0 (fastcall ix1, ix2; stack ix3, ix5, base, ax, ay, particles; ret 0x18).
All callees are the exe's own code in both builds (PSVECSubtract, vmtmul, vmmul, PSVECAdd, vnorm, vcross, vadd, the Cramer solver
0x547860, vscalar, vscalar3, vaddscalar). The limb end x5 is placed from a chosen local L (inside / outside the wedge on either side,
behind the apex, on the boundary, at the apex), with orthonormal or random bases, degenerate tetrahedra and zero / 10000 masses."""
import math
from pilot import S, F
from wkit import fedge
from hkit import fvec


def _rot(r):
    a, b, g = (r.uniform(-math.pi, math.pi) for _ in range(3))
    ca, sa, cb, sb, cg, sg = math.cos(a), math.sin(a), math.cos(b), math.sin(b), math.cos(g), math.sin(g)
    return [cb * cg, -cb * sg, sb,
            sa * sb * cg + ca * sg, -sa * sb * sg + ca * cg, -sa * cb,
            -ca * sb * cg + sa * sg, ca * sb * sg + sa * cg, ca * cb]


def _gen(c):
    r = c.rng
    emu = c.emu
    parts = emu.alloc(0x34 * 16 + 0x40, 4)
    emu.wbytes(parts, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    for i in range(16):
        p = parts + 0x34 * i
        for k in range(3):
            emu.wf32(p + 0xc + 4 * k, r.uniform(-100, 100))
        emu.wf32(p + 0x30, r.choice((1.0, 1.0, 0.5, 2.0, 3.0, 10000.0)))
    ix = r.sample(range(16), 4)
    if r.random() < 0.05:
        ix[r.randrange(1, 4)] = ix[0]          # coincident particles: singular solver
    ix1, ix2, ix3, ix5 = ix
    base = _rot(r) if r.random() < 0.85 else [r.uniform(-2, 2) for _ in range(9)]
    if r.random() < 0.03:
        base = [0.0] * 9
    x1 = [r.uniform(-100, 100) for _ in range(3)]
    sc = r.choice((1.0, 10.0, 40.0))
    x2 = [x1[k] + r.uniform(-1, 1) * sc for k in range(3)]
    x3 = [x1[k] + r.uniform(-1, 1) * sc for k in range(3)]
    if r.random() < 0.05:                     # x3 on the line x1-x2: degenerate tetrahedron
        t = r.uniform(-2, 2)
        x3 = [x1[k] + t * (x2[k] - x1[k]) for k in range(3)]
    ax = r.choice((r.uniform(-3, 3), r.uniform(-0.3, 0.3), 0.0, 1.0, -1.0))
    if r.random() < 0.04:
        ax = fedge(c)
    L2 = r.choice((r.uniform(0, 1), r.uniform(0, 1), r.uniform(-1, 0), r.uniform(-0.05, 0.05), 0.0))
    mode = r.random()
    if mode < 0.2:       # inside
        L0 = r.uniform(-1, 1) * abs(L2) / max(abs(ax), 1e-3) * 0.99
    elif mode < 0.8:     # outside on either side
        L0 = r.choice((1, -1)) * (abs(L2) / max(abs(ax), 1e-3) + r.uniform(0, 2))
    elif mode < 0.9:     # on the boundary
        L0 = r.choice((1, -1)) * abs(L2) / ax if ax else r.uniform(-1, 1)
    else:
        L0 = r.choice((0.0, -0.0, r.uniform(-1, 1)))
    L1 = r.uniform(-1, 1)
    s = r.choice((1.0, 5.0, 30.0))
    L = [L0 * s, L1 * s, L2 * s]
    if r.random() < 0.04:
        L = [0.0, 0.0, 0.0]
    if r.random() < 0.03:
        L[r.randrange(3)] = fedge(c)
    exact = r.random() < 0.25
    if exact:              # exact mode: signed permutation base, integer x1, exact L on / off the wedge edges, L2 = 0
        perm = r.sample(range(3), 3)
        base = [0.0] * 9
        for i in range(3):
            base[3 * i + perm[i]] = r.choice((1.0, -1.0))
        x1 = [float(r.randrange(-50, 50)) for _ in range(3)]
        ax = r.choice((1.0, 2.0, 0.5, -1.0, -2.0, 0.0))
        L2 = r.choice((0.0, float(r.randrange(1, 9)), float(r.randrange(1, 9)), float(r.randrange(-4, 9))))
        L0 = r.choice((L2 / ax if ax else 0.0, -L2 / ax if ax else 0.0, L2 / ax if ax else 0.0, -L2 / ax if ax else 0.0,
                       float(r.randrange(-8, 9)), 0.0))
        L = [L0, float(r.randrange(-8, 9)), L2]
        if r.random() < 0.1:
            L[r.randrange(3)] = r.choice((float('nan'), float('inf'), -float('inf')))
    x5 = [x1[k] + L[0] * base[k] + L[1] * base[3 + k] + L[2] * base[6 + k] for k in range(3)]
    if not exact and r.random() < 0.3:   # the other orientation (columns): L ends up mixed
        x5 = [x1[k] + sum(L[j] * base[3 * k + j] for j in range(3)) for k in range(3)]
    for ixk, v in ((ix1, x1), (ix2, x2), (ix3, x3), (ix5, x5)):
        for k in range(3):
            emu.wf32(parts + 0x34 * ixk + 0xc + 4 * k, v[k])
    for ixk in (ix1, ix2, ix3, ix5):
        q = r.random()
        if q < 0.04:
            emu.wf32(parts + 0x34 * ixk + 0x30, r.choice((0.0, -0.0)))
        elif q < 0.06:
            emu.wf32(parts + 0x34 * ixk + 0x30, fedge(c))
    if r.random() < 0.25:  # heavy limb: G.n near the 1e-6 cut of the final denominator
        for ixk in (ix1, ix2, ix3):
            emu.wf32(parts + 0x34 * ixk + 0x30, 10.0 ** r.uniform(3, 7))
        emu.wf32(parts + 0x34 * ix5 + 0x30, r.choice((10.0 ** r.uniform(3, 9), float('inf'), 10000.0)))
    ay = r.uniform(-3, 3)
    return [ix1, ix2, ix3, ix5, fvec(c, base), F(ax), F(ay), parts]


S(0x5428f0, 'AdjustCone5', 'fastcall', gen=_gen)
