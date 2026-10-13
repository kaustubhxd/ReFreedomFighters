"""specs_s8815.py - hitreact batch 8815: the capsule-triangle test 0x544330 (fastcall a, b; stack r, out, tri; ret 0xc; al) and the
segment-segment distance 0x5453c0 (fastcall p0, p1; stack q0, q1, tP, sQ, maxD, dist, dir; ret 0x1c; al). Every callee runs as exe
code (PSVECSubtract, vaddscalar, vscalar, vscalar3, vcross, vnorm, the 3x3 solver, the point-segment tests 0x5457f0 / 0x545690 and
the random unit vector 0x547430). 0x547430's engine random (vtable slot 0x1c0 of [0x70039c]) is a stub cycling three values.
Triangles are built like ZFastBoxColi1::AddFace (n = unit(e2 x e1), outward edge perps) with some broken / degenerate records."""
import math
import struct
from pilot import S, F
from wkit import rnd, obj, fedge
from hkit import fvec


def f32(x):
    try:
        return struct.unpack('<f', struct.pack('<f', x))[0]
    except OverflowError:
        return math.copysign(float('inf'), x)


def _cycle_stub(c, vals):
    """thiscall (file, line), ret 8: loads vals[k % n] into ST0 on the k-th call."""
    n = len(vals)
    tab = c.emu.alloc(4 * n, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(tab + 4 * i, v)
    cnt = c.emu.alloc(4, 4)
    code = b'\xa1' + struct.pack('<I', cnt)
    code += b'\x31\xd2\xb9' + struct.pack('<I', n) + b'\xf7\xf1'
    code += b'\xd9\x04\x95' + struct.pack('<I', tab)
    code += b'\xff\x05' + struct.pack('<I', cnt)
    code += b'\xc2\x08\x00'
    a = c.emu.alloc(len(code) + 16, 16)
    c.emu.wbytes(a, code)
    return a


def _engine(c):
    r = c.rng
    vals = [r.choice((0.9, 0.1, 0.3, 0.75, r.uniform(0, 1))) for _ in range(3)]
    if all(abs(v - 0.5) < 1e-3 for v in vals):
        vals[0] = 0.9
    eng = obj(c, 0x200, {0x1c0: _cycle_stub(c, vals)})
    c.emu.w32(0x70039c, eng)
    c.emu.mu.ctl_flush_tb()


def sub(a, b):
    return [a[i] - b[i] for i in range(3)]


def add(a, b):
    return [a[i] + b[i] for i in range(3)]


def mul(a, s):
    return [x * s for x in a]


def cross(a, b):
    return [a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]]


def dot(a, b):
    return a[0] * b[0] + a[1] * b[1] + a[2] * b[2]


def unit(a):
    l = math.sqrt(dot(a, a))
    return mul(a, 1.0 / l) if l > 1e-12 else [0.0, 1.0, 0.0]


def make_tri(c, v0, v1, v2, broken=False):
    """0x7c byte SFastBoxColiTri: +4 n, +0x10 matrix (unused), +0x34 v0, +0x40 v1, +0x4c v2, +0x58/+0x64/+0x70 edge perps."""
    r = c.rng
    e1, e2 = sub(v1, v0), sub(v2, v0)
    n = unit(cross(e2, e1))
    p1 = unit(cross(n, e1))
    p2 = unit(cross(e2, n))
    p0 = unit(mul(add(cross(n, e1), cross(e2, n)), -1.0))
    if broken:
        pick = r.random()
        if pick < 0.3:
            n = mul(n, -1.0)
        elif pick < 0.5:
            p0, p1, p2 = mul(p0, -1.0), p1, p2
        elif pick < 0.7:
            k = r.randrange(9)
            arr = n + p0 + p1 + p2
            arr[3 + k] = fedge(c)
            n, p0, p1, p2 = arr[0:3], arr[3:6], arr[6:9], arr[9:12]
        else:
            n = [fedge(c), fedge(c), fedge(c)]
    t = rnd(c, 0x7c + 4)
    for off, v in ((4, n), (0x34, v0), (0x40, v1), (0x4c, v2), (0x58, p0), (0x64, p1), (0x70, p2)):
        for i in range(3):
            c.emu.wf32(t + off + 4 * i, v[i])
    return t, n


def _tri_pts(c):
    r = c.rng
    k = r.random()
    if k < 0.08:   # degenerate: collinear / coincident vertices
        v0 = [r.uniform(-50, 50) for _ in range(3)]
        d = [r.uniform(-20, 20) for _ in range(3)]
        return v0, add(v0, d), add(v0, mul(d, r.choice((2.0, 0.5, 0.0, -1.0)))), True
    if k < 0.4:    # floor triangle
        y = r.choice((0.0, r.uniform(-10, 10)))
        s = r.choice((50.0, 100.0, 20.0))
        v0 = [r.uniform(-s, 0), y, r.uniform(-s, 0)]
        v1 = [v0[0], y, v0[2] + r.uniform(5, 2 * s)]
        v2 = [v0[0] + r.uniform(5, 2 * s), y, v0[2]]
        if r.random() < 0.5:
            v1, v2 = v2, v1
        return v0, v1, v2, False
    pts = [[r.uniform(-60, 60) for _ in range(3)] for _ in range(3)]
    return pts[0], pts[1], pts[2], False


def _capsule(c, v0, v1, v2, n, rad):
    """Capsule ends a, b placed relative to the triangle."""
    r = c.rng
    def bary():
        u, v = r.random(), r.random()
        if u + v > 1:
            u, v = 1 - u, 1 - v
        return add(v0, add(mul(sub(v1, v0), u), mul(sub(v2, v0), v)))
    def edgept(ext=0.0):
        k = r.randrange(3)
        A, B = [(v0, v1), (v1, v2), (v2, v0)][k]
        t = r.uniform(-ext, 1 + ext)
        return add(A, mul(sub(B, A), t))
    R = rad if rad == rad and abs(rad) < 1e6 else 10.0
    m = r.random()
    if m < 0.18:     # axis crossing the plane through the inside
        p = bary()
        d = unit([r.uniform(-1, 1) for _ in range(3)])
        if dot(d, n) < 0:
            d = mul(d, -1.0)
        L = r.uniform(0.5, 4 * R + 1)
        f = r.random()
        return add(p, mul(d, L * f)), add(p, mul(d, -L * (1 - f)))
    if m < 0.40:     # ends near the plane (caps), either side
        p = bary()
        q = bary() if r.random() < 0.7 else edgept(0.3)
        ha = r.uniform(-1.3 * R, 1.3 * R)
        hb = r.choice((ha, r.uniform(-1.3 * R, 1.3 * R), -ha))
        return add(p, mul(n, ha)), add(q, mul(n, hb))
    if m < 0.62:     # axis near an edge, outside the triangle
        p = edgept(0.4)
        cen = mul(add(add(v0, v1), v2), 1.0 / 3)
        out = unit(sub(p, cen))
        off = add(mul(out, r.uniform(0, 1.4 * R)), mul(n, r.uniform(-1.2 * R, 1.2 * R)))
        d = unit([r.uniform(-1, 1) for _ in range(3)])
        L = r.uniform(0, 4 * R + 1)
        f = r.random()
        base = add(p, off)
        return add(base, mul(d, L * f)), add(base, mul(d, -L * (1 - f)))
    if m < 0.72:     # end near a vertex
        vtx = r.choice((v0, v1, v2))
        d = unit([r.uniform(-1, 1) for _ in range(3)])
        a = add(vtx, mul(d, r.uniform(0, 1.3 * R)))
        b = add(a, mul(unit([r.uniform(-1, 1) for _ in range(3)]), r.uniform(0, 3 * R)))
        return (a, b) if r.random() < 0.5 else (b, a)
    if m < 0.78:     # axis parallel to an edge
        k = r.randrange(3)
        A, B = [(v0, v1), (v1, v2), (v2, v0)][k]
        e = sub(B, A)
        cen = mul(add(add(v0, v1), v2), 1.0 / 3)
        off = mul(unit(sub(A, cen)), r.uniform(0, 1.2 * R))
        off = add(off, mul(n, r.uniform(-R, R)))
        s0 = r.uniform(-0.5, 1.0)
        a = add(add(A, mul(e, s0)), off)
        return a, add(a, mul(e, r.uniform(-1, 1)))
    if m < 0.84:     # zero / tiny length capsule
        a = bary() if r.random() < 0.6 else edgept(0.3)
        a = add(a, mul(n, r.uniform(-1.2 * R, 1.2 * R)))
        return a, add(a, [r.choice((0.0, 1e-5, -3e-5, 1e-3)) for _ in range(3)])
    if m < 0.90:     # far away
        a = [r.uniform(-300, 300) for _ in range(3)]
        return a, add(a, [r.uniform(-50, 50) for _ in range(3)])
    # random near the triangle
    cen = mul(add(add(v0, v1), v2), 1.0 / 3)
    return ([cen[i] + r.uniform(-60, 60) for i in range(3)], [cen[i] + r.uniform(-60, 60) for i in range(3)])


def _exact(c):
    """Integer floor triangle and integer capsule ends: the plane heights and the Cramer results come out exact, so the equality
    edges of the cap / axis tests (h == r, h == 0, t == 1, u == 0, u + v == 1) are reached. Returns (v0, v1, v2, a, b, r)."""
    r = c.rng
    y0 = float(r.choice((0, 0, 3, -5)))
    x0, z0 = float(r.randrange(-20, 0)), float(r.randrange(-20, 0))
    L = float(r.choice((16, 32, 40)))
    v0, v1, v2 = [x0, y0, z0], [x0, y0, z0 + L], [x0 + L, y0, z0]
    if r.random() < 0.5:
        v1, v2 = v2, v1
    rad = float(r.choice((10, 6, 7, 15, 8)))
    def pt():
        k = r.random()
        if k < 0.6:
            u = r.randrange(0, int(L))
            w = r.randrange(0, int(L) - u + 1)
        elif k < 0.8:
            u, w = r.choice(((0, r.randrange(0, int(L))), (r.randrange(0, int(L)), 0)))
        else:
            u = r.randrange(-4, int(L) + 4)
            w = r.randrange(-4, int(L) + 4)
        return [x0 + w, None, z0 + u]
    hs = (rad, -rad, 0.0, rad / 2, -rad / 2, rad + 1, -(rad + 1), 1.0, -1.0, 2 * rad)
    a, b = pt(), pt()
    a[1] = y0 + r.choice(hs)
    b[1] = y0 + r.choice(hs)
    if r.random() < 0.25:
        b = [a[0], y0 + r.choice(hs), a[2]]
    return v0, v1, v2, a, b, rad


def _graze(c, v0, v1, v2, n, rad):
    """Axis almost parallel to the plane with both end heights within 1e-4 of +-r (the slab clip with |db - da| around the 1e-4 cut),
    running across the triangle's edges."""
    r = c.rng
    R = rad if rad == rad and 0 < abs(rad) < 1e6 else 10.0
    u, v = r.random(), r.random()
    if u + v > 1:
        u, v = 1 - u, 1 - v
    p = add(v0, add(mul(sub(v1, v0), u), mul(sub(v2, v0), v)))
    d = unit(cross(n, [r.uniform(-1, 1) for _ in range(3)]))
    L = r.uniform(5, 80)
    f = r.random()
    side = r.choice((1.0, -1.0))
    dh = r.choice((5e-5, 2e-5, 9e-5, 1.1e-4, 3e-4, 1e-6)) * r.choice((1, -1))
    a = add(add(p, mul(d, -L * f)), mul(n, side * R + dh / 2))
    b = add(add(p, mul(d, L * (1 - f))), mul(n, side * R - dh / 2))
    return a, b


def _cap(c):
    r = c.rng
    _engine(c)
    if r.random() < 0.15:
        v0, v1, v2, a, b, rad = _exact(c)
        tri, n = make_tri(c, v0, v1, v2)
        return [fvec(c, a), fvec(c, b), F(rad), rnd(c, 0x14 + 4), tri]
    v0, v1, v2, degen = _tri_pts(c)
    rad = r.choice((10.0, 15.0, 7.0, 6.0, 10.0, r.uniform(0, 20), 0.0, fedge(c) if r.random() < 0.3 else 5.0))
    tri, n = make_tri(c, v0, v1, v2, broken=r.random() < 0.1)
    nn = unit(cross(sub(v2, v0), sub(v1, v0)))
    if r.random() < 0.1:
        a, b = _graze(c, v0, v1, v2, nn, rad)
    else:
        a, b = _capsule(c, v0, v1, v2, nn, rad)
    if r.random() < 0.05:
        (a if r.random() < 0.5 else b)[r.randrange(3)] = fedge(c)
    a, b = [f32(x) for x in a], [f32(x) for x in b]
    if r.random() < 0.05:
        b = list(a)
    out = rnd(c, 0x14 + 4)
    return [fvec(c, a), fvec(c, b), F(rad), out, tri]


S(0x544330, 'CollideSolidCappedCylinderAndTriangle', 'fastcall', ret='al', gen=_cap)


def _dll(c):
    r = c.rng
    _engine(c)
    rv = lambda s=20: [r.uniform(-s, s) for _ in range(3)]
    k = r.random()
    p0 = rv()
    p1 = add(p0, rv(30))
    if k < 0.2:        # exact crossings: dist 0 (random unit vector) or a tiny offset; t and s on 0 / 1 exactly
        p0 = [0.0, 0.0, 0.0]
        p1 = [r.choice((2.0, 4.0, 1.0)), 0.0, 0.0]
        h = r.choice((0.5, 0.25, 0.75, 0.0, 1.0))
        z = r.choice((0.0, 0.0, 2e-6, 1e-6, 5e-6, 1.0, -0.5))
        lo = r.choice((1.0, 2.0, 0.5, 0.0))
        q0 = [p1[0] * h, -lo, z]
        q1 = [p1[0] * h, r.choice((1.0, 3.0, 0.0)) if lo else 1.0, z]
        if r.random() < 0.5:
            q0, q1 = q1, q0
        if r.random() < 0.3:
            p0, p1 = p1, p0
    elif k < 0.25:     # short p (d22 under 1e-6 while den passes), long q
        q0 = rv()
        q1 = add(q0, rv(40))
        p1 = add(p0, [r.choice((1e-4, -2e-4, 3e-4, 5e-4, 1e-3)) for _ in range(3)])
    elif k < 0.22:     # parallel
        d = sub(p1, p0)
        q0 = add(p0, rv(5))
        q1 = add(q0, mul(d, r.choice((1.0, -0.5, 2.0))))
    elif k < 0.3:      # degenerate p (d22 == 0) or q
        if r.random() < 0.5:
            p1 = list(p0)
            q0, q1 = rv(), rv()
        else:
            q0 = rv()
            q1 = add(q0, [r.choice((0.0, 1e-4)) for _ in range(3)])
    elif k < 0.6:      # near-crossing segments (small distance)
        mid = rv()
        d1, d2 = unit(rv()), unit(rv())
        off = mul(unit(cross(d1, d2)), r.uniform(0, 12))
        l1, l2 = r.uniform(0.1, 30), r.uniform(0.1, 30)
        f1, f2 = r.uniform(-0.5, 1.5), r.uniform(-0.5, 1.5)
        p0 = sub(mid, mul(d1, l1 * f1))
        p1 = add(p0, mul(d1, l1))
        cm = add(mid, off)
        q0 = sub(cm, mul(d2, l2 * f2))
        q1 = add(q0, mul(d2, l2))
    else:
        q0 = rv()
        q1 = add(q0, rv(30))
    vals = p0 + p1 + q0 + q1
    if r.random() < 0.06:
        vals[r.randrange(12)] = fedge(c)
    if r.random() < 0.04:
        vals[r.randrange(12)] = r.choice((float('nan'), float('inf'), -float('inf')))
    vals = [f32(x) for x in vals]
    md = r.choice((10.0, 15.0, 6.0, r.uniform(0, 25), 0.0, 1e-7, fedge(c)))
    pv = [fvec(c, vals[0:3]), fvec(c, vals[3:6]), fvec(c, vals[6:9]), fvec(c, vals[9:12])]
    tP = rnd(c, 8)
    sQ = tP if r.random() < 0.08 else rnd(c, 8)   # aliased tP / sQ: sQ is re-read after the tP store
    return pv + [tP, sQ, fvec(c, [md]), rnd(c, 8), rnd(c, 16)]


S(0x5453c0, 'DistLineLineVar', 'fastcall', ret='al', gen=_dll)
