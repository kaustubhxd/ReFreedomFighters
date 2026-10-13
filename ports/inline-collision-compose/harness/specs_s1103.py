"""specs_s1103.py - collision thread batch 1103: 0x4e99c0 ZCollisionBox::FetchPushList.
Builds a ZCollisionBox with 1-4 triangle strips around the sphere centre (floors, walls, slopes, ceilings,
degenerate repeats) and per-strip bounding boxes (some far away so the strip is skipped). Every callee runs as exe
code; the random-direction slot is the batch 1101 stub."""
import struct
from pilot import S, F
from specs_s1101 import _sys, _vec


def _strip(c, p, kind):
    r = c.rng
    n = r.choice([3, 3, 4, 4, 5, 6])
    pts = []
    if kind == 'flat':   # integer-grid floor; p.y is exactly 0 or 1.25 above it (touching), so edges show
        y = float(round(p[1])) - r.choice([0.0, 1.25, 0.5])
        x0, z0 = float(round(p[0])), float(round(p[2]))
        for k in range(n):
            pts.append([x0 + r.randint(-2, 2), y, z0 + r.randint(-2, 2)])
    elif kind == 'slope':   # sloped plane through (or within a hair of) p, so p.y sits on the plane-height edge
        a, b = r.uniform(-0.6, 0.6), r.uniform(-0.6, 0.6)
        y0 = p[1] - r.choice([0.0, 0.0, 1e-6, -1e-6, 1e-4])
        for k in range(n):
            dx, dz = r.uniform(-2, 2), r.uniform(-2, 2)
            pts.append([p[0] + dx, y0 + a * dx + b * dz, p[2] + dz])
    elif kind == 'floor':
        y = p[1] - r.uniform(-0.3, 1.4)
        for k in range(n):
            pts.append([p[0] + r.uniform(-2, 2), y + (r.uniform(-0.3, 0.3) if r.random() < 0.3 else 0.0), p[2] + r.uniform(-2, 2)])
    elif kind == 'ceil':
        y = p[1] + r.uniform(0.2, 1.4)
        for k in range(n):
            pts.append([p[0] + r.uniform(-2, 2), y, p[2] + r.uniform(-2, 2)])
    elif kind == 'wall':
        x = p[0] + r.uniform(-1.4, 1.4)
        for k in range(n):
            pts.append([x + (r.uniform(-0.2, 0.2) if r.random() < 0.3 else 0.0), p[1] + r.uniform(-2, 2), p[2] + r.uniform(-2, 2)])
    else:
        for k in range(n):
            pts.append([p[j] + r.uniform(-2, 2) for j in range(3)])
    if r.random() < 0.2:   # a repeated vertex: degenerate triangles are skipped
        a = r.randrange(n)
        b = r.randrange(n)
        pts[b] = list(pts[a])
    return pts


def _fpl(c):
    r = c.rng
    _sys(c)
    e = c.emu
    p = [r.uniform(-30, 30), r.uniform(-5, 5), r.uniform(-30, 30)]
    if r.random() < 0.3:
        p = [float(r.randint(-30, 30)) + r.choice([0.0, 0.5, 0.25]), float(r.randint(-5, 5)), float(r.randint(-30, 30)) + r.choice([0.0, 0.5])]
    scale = [1.0, 1.0, 1.0] if r.random() < 0.6 else [r.uniform(0.5, 2.0) for _ in range(3)]
    pu = [p[j] * scale[j] for j in range(3)]   # p is given in scaled space; strips are built around p / scale
    ns = r.choice([1, 2, 3, 4])
    strips = [_strip(c, p, r.choice(['flat', 'flat', 'slope', 'slope', 'floor', 'floor', 'wall', 'wall', 'ceil', 'any'])) for _ in range(ns)]
    size = sum(0x18 + 12 * len(s) for s in strips)
    sp = e.alloc(size + 0x40, 4)
    a = sp
    for s in strips:
        e.w32(a, len(s))
        for k in range(1, 6):
            e.w32(a + 4 * k, r.getrandbits(32))
        for k, v in enumerate(s):
            for j in range(3):
                e.wf32(a + 0x18 + 12 * k + 4 * j, v[j])
        a += 0x18 + 12 * len(s)
    nbox = r.choice([0, ns, ns, ns, max(ns - 1, 0)])
    boxes = e.alloc(24 * max(nbox, 1) + 0x20, 4)
    for b in range(nbox):
        s = strips[b]
        lo = [min(v[j] for v in s) for j in range(3)]
        hi = [max(v[j] for v in s) for j in range(3)]
        k = r.random()
        if k < 0.2:   # far away: the strip is skipped
            off = r.choice([-1, 1]) * r.uniform(5, 50)
            lo[0] += off
            hi[0] += off
        elif k < 0.45:   # a small box whose centre is about 1 to 1.6 + its half-diagonal from p (the test's edge)
            h = r.uniform(0.01, 0.5)
            dist = (3 * h * h) ** 0.5 + r.uniform(0.9, 1.6)
            cen = [p[0] + dist, p[1], p[2]]
            lo = [cen[j] - h for j in range(3)]
            hi = [cen[j] + h for j in range(3)]
        for j in range(3):
            e.wf32(boxes + 24 * b + 4 * j, lo[j])
            e.wf32(boxes + 24 * b + 12 + 4 * j, hi[j])
    this = e.alloc(0x40, 4)
    e.wbytes(this, bytes(r.getrandbits(8) for _ in range(0x40)))
    e.w32(this + 8, ns)
    e.w32(this + 0xc, sp)
    e.w32(this + 0x14, boxes)
    e.w32(this + 0x10, (boxes - sp + 24 * nbox) & 0xffffffff)
    impact = e.alloc(0x20, 4)
    e.wbytes(impact, bytes(r.getrandbits(8) for _ in range(0x20)))
    ntri = sum(len(s) - 2 for s in strips)
    out = e.alloc(24 * ntri + 0x30, 4)
    pv = e.alloc(0x20, 4)
    for j in range(3):
        e.wf32(pv + 4 * j, pu[j])
    sv = e.alloc(0x20, 4)
    for j in range(3):
        e.wf32(sv + 4 * j, scale[j])
    return [this, impact, out, pv, sv]


S(0x4e99c0, 'ZCollisionBox::FetchPushList', 'thiscall', None, ret='eax', gen=_fpl, note='batch1103')
