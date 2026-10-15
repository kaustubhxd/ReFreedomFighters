"""specs_s8822.py - hitreact batch 8822: the strip line test 0x4e8c80 (under ZCollisionBox::CalcLineCollision). IntersectTriangleAndLine
0x4e2560 (batch8821) and vaddscalar 0x443ef0 are exe code in both builds. The box: +8 strip count, +0xc the strips (vertex count, surface
words at +8 / +0xc / +0x10, vertices from +0x18); the line start / direction are aimed at one of the triangles in most cases."""
import struct
from pilot import S
from wkit import rnd, fedge


def _gen(c):
    r = c.rng
    emu = c.emu
    grid = r.random() < 0.4   # integer coordinates on one plane: equal t on shared edges, t exactly 1 (= the initial best)
    nstrips = r.choice((0, 1, 1, 2, 3, 5))
    strips = []
    tris = []
    for s in range(nstrips):
        n = r.choice((2, 3, 3, 4, 5, 8))
        base = [r.uniform(-300, 300) for _ in range(3)]
        verts = [[base[k] + r.uniform(-120, 120) for k in range(3)] for _ in range(n)]
        if grid:
            verts = [[float(r.randint(-6, 6)), 0.0, float(r.randint(-6, 6))] for _ in range(n)]
        if r.random() < 0.3 and n >= 3:   # flat floor strip
            for v in verts:
                v[1] = base[1]
        strips.append(verts)
        for k in range(n - 2):
            tris.append((verts[k], verts[k + 1], verts[k + 2]))
    size = sum(0x18 + 0xc * len(v) for v in strips) + 0x40
    mem = emu.alloc(size, 4)
    emu.wbytes(mem, bytes(r.getrandbits(8) for _ in range(size)))
    p = mem
    for verts in strips:
        emu.w32(p, len(verts))
        for i, v in enumerate(verts):
            for k in range(3):
                emu.wf32(p + 0x18 + 0xc * i + 4 * k, v[k])
        p += 0x18 + 0xc * len(verts)
    box = rnd(c, 0x40)
    emu.w32(box + 8, nstrips if r.random() < 0.95 or nstrips == 0 else nstrips)
    emu.w32(box + 0xc, mem)
    if tris and r.random() < 0.8:
        a, b, cc = r.choice(tris)
        u, w = r.uniform(-0.2, 1.0), r.uniform(-0.2, 1.0)
        if grid:
            u, w = r.choice(((0.5, 0.5), (0.0, 0.5), (0.5, 0.0), (0.25, 0.25), (0.0, 0.0), (1.0, 0.0)))
        q = [a[k] + u * (b[k] - a[k]) + w * (cc[k] - a[k]) for k in range(3)]
        d = [r.uniform(-200, 200) for _ in range(3)]
        sc = r.choice((1.0, 0.5, 2.0, -1.0, 0.1))
        if grid:
            d = [float(r.randint(-3, 3)), float(r.choice((-4, -2, 2, 4))), float(r.randint(-3, 3))]
            sc = r.choice((1.0, 1.0, 0.5, 2.0))
        start = [q[k] - sc * d[k] for k in range(3)]
    else:
        start = [r.uniform(-300, 300) for _ in range(3)]
        d = [r.choice((r.uniform(-400, 400), 0.0, fedge(c))) for _ in range(3)]
    sp = emu.alloc(16, 4)
    dp = emu.alloc(16, 4)
    for k in range(3):
        emu.wf32(sp + 4 * k, start[k])
        emu.wf32(dp + 4 * k, d[k])
    out = rnd(c, 0x50)
    flag = r.choice((0, 1, 0x100, 0x101, r.getrandbits(32)))
    return [box, out, sp, dp, flag]


S(0x4e8c80, 'CalcLineCollision line test', 'thiscall', ret='al', gen=_gen)
