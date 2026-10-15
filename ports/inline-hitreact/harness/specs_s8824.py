"""specs_s8824.py - hitreact batch 8824: 0x4ddb20 (segment vs unit sphere) and 0x4dddf0 (triangle vs a box frame's unit sphere). Every
callee runs as exe code in both builds (PSVECSubtract / PSVECAdd / vmtmul / vcross / vnorm, the slab test 0x4dd930, and 0x4ddb20 under
0x4dddf0). Points are drawn at the unit-sphere scale so every branch is reached: inside, tangent, parallel, zero-length, degenerate."""
import math
from pilot import S
from wkit import fedge


def _v(c, x):
    a = c.emu.alloc(16, 4)
    for k in range(3):
        c.emu.wf32(a + 4 * k, x[k])
    return a


def _pt(c, scale=1.5):
    r = c.rng
    k = r.random()
    if k < 0.1:
        return [float(r.randint(-1, 1)) for _ in range(3)]
    if k < 0.15:
        return [r.choice((0.0, fedge(c), 1.0, -1.0)) for _ in range(3)]
    return [r.uniform(-scale, scale) for _ in range(3)]


def _seg(c):
    r = c.rng
    a = _pt(c)
    m = r.random()
    if m < 0.1:
        b = list(a)                                   # zero-length segment
    elif m < 0.25:                                    # a segment passing at an exact distance (tangent / just inside / outside)
        u = [r.uniform(-1, 1) for _ in range(3)]
        l = math.sqrt(sum(x * x for x in u)) or 1.0
        u = [x / l for x in u]
        w = [r.uniform(-1, 1) for _ in range(3)]
        dt = sum(w[k] * u[k] for k in range(3))
        w = [w[k] - dt * u[k] for k in range(3)]
        lw = math.sqrt(sum(x * x for x in w)) or 1.0
        rad = r.choice((1.0, 0.999999, 1.000001, 0.5, 2.0))
        cpt = [w[k] / lw * rad for k in range(3)]
        t0, t1 = r.uniform(-3, 0.5), r.uniform(-0.5, 3)
        a = [cpt[k] + t0 * u[k] for k in range(3)]
        b = [cpt[k] + t1 * u[k] for k in range(3)]
    else:
        b = _pt(c, 3.0)
    return [_v(c, a), _v(c, b)]


def _rot(r, s=1.0):
    a, b, g = r.uniform(-3.2, 3.2), r.uniform(-1.5, 1.5), r.uniform(-3.2, 3.2)
    ca, sa, cb, sb, cg, sg = math.cos(a), math.sin(a), math.cos(b), math.sin(b), math.cos(g), math.sin(g)
    m = [ca * cb, ca * sb * sg - sa * cg, ca * sb * cg + sa * sg, sa * cb, sa * sb * sg + ca * cg, sa * sb * cg - ca * sg, -sb, cb * sg, cb * cg]
    return [x * s for x in m]


def _tri(c):
    r = c.rng
    cen = [r.uniform(-50, 50) for _ in range(3)]
    s = r.choice((1.0, 1.0, 0.5, 0.05, 0.02))
    m = [1, 0, 0, 0, 1, 0, 0, 0, 1] if r.random() < 0.4 else _rot(r)
    m = [x * s for x in m]
    span = 1.0 / s
    mode = r.random()
    if mode < 0.12:                                   # an axis plane through the centre (d = 0 exactly), the triangle off to one side
        k = r.randrange(3)
        o1, o2 = [i for i in range(3) if i != k]
        pl = r.choice((0.0, 0.0, 0.3))
        pts = []
        sg = r.choice((1, -1))
        for (a, b) in r.choice((((3, 0.5), (5, 1), (4, 4)), ((-0.5, -0.5), (3, -3), (-3, 3)), ((1.2, -3), (1.2, 3), (6, 0)))):
            q = [0.0, 0.0, 0.0]
            q[k] = pl
            q[o1], q[o2] = sg * a, sg * b
            pts.append([cen[i] + q[i] * span for i in range(3)])
        return [_v(c, cen), _v(c, [s, 0, 0, 0, s, 0, 0, 0, s]), _v(c, pts[0]), _v(c, pts[1]), _v(c, pts[2])]
    if mode < 0.2:                                    # degenerate: two equal vertices / collinear
        p = [cen[k] + r.uniform(-2, 2) * span for k in range(3)]
        q = [cen[k] + r.uniform(-2, 2) * span for k in range(3)]
        es = [p, list(p), q] if r.random() < 0.5 else [p, q, [2 * q[k] - p[k] for k in range(3)]]
    elif mode < 0.45:                                  # a big triangle whose plane passes near the centre (face hit, no edge)
        nrm = [r.uniform(-1, 1) for _ in range(3)]
        if r.random() < 0.4:                          # a normal with zero components (axis-aligned planes: the slab test's projection axes)
            for k in r.sample(range(3), r.choice((1, 2))):
                nrm[k] = 0.0
            if not any(nrm):
                nrm[r.randrange(3)] = 1.0
            m = [s, 0, 0, 0, s, 0, 0, 0, s]
        off = r.choice((0.0, 0.0, 0.5, 0.99, 1.01, 2.0)) * span
        l = math.sqrt(sum(x * x for x in nrm)) or 1.0
        nrm = [x / l for x in nrm]
        t1 = [nrm[1], -nrm[0], 0.0] if abs(nrm[2]) < 0.9 else [0.0, nrm[2], -nrm[1]]
        lt = math.sqrt(sum(x * x for x in t1)) or 1.0
        t1 = [x / lt for x in t1]
        t2 = [nrm[1] * t1[2] - nrm[2] * t1[1], nrm[2] * t1[0] - nrm[0] * t1[2], nrm[0] * t1[1] - nrm[1] * t1[0]]
        big = r.uniform(3, 8) * span
        o = [cen[k] + nrm[k] * off + r.uniform(-0.5, 0.5) * span * t1[k] for k in range(3)]
        es = [[o[k] + big * (math.cos(th) * t1[k] + math.sin(th) * t2[k]) for k in range(3)] for th in (0.3, 2.4, 4.4)]
        if r.random() < 0.3:
            es = [[o[k] + big * (math.cos(th) * t1[k] + math.sin(th) * t2[k]) for k in range(3)] for th in (0.3, 0.8, 1.3)]  # misses
    else:
        es = [[cen[k] + r.uniform(-2.5, 2.5) * span for k in range(3)] for _ in range(3)]
    return [_v(c, cen), _v(c, m), _v(c, es[0]), _v(c, es[1]), _v(c, es[2])]


S(0x4ddb20, 'segment vs unit sphere (no name)', 'fastcall', ret='al', gen=_seg)
S(0x4dddf0, 'triangle vs unit sphere (no name)', 'fastcall', ret='al', gen=_tri)
