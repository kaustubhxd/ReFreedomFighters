"""specs_s1218.py - pathfinding batch 1218: door / gate checks, PostProcessPath."""
from pilot import S
from pfspec import rnd, reporter, allocator, hooks, sf


def path_points(c, n):
    r = c.rng
    pts = []
    x, y, z = r.uniform(-500, 500), r.uniform(-50, 50), r.uniform(-500, 500)
    for _ in range(n):
        pts.append((x, y, z))
        x += r.uniform(-120, 120)
        y += r.uniform(-20, 20)
        z += r.uniform(-120, 120)
    return pts


def chk_list(c, pts):
    e = c.emu
    lst = rnd(c, 0x18)
    e.w32(lst + 8, len(pts))
    arr = e.alloc(16 * max(len(pts), 1) + 16, 4)
    run = 0.0
    for k, p in enumerate(pts):
        e.wf32(arr + 16 * k, run)
        run += 10.0
        for j in range(3):
            e.wf32(arr + 16 * k + 4 + 4 * j, sf(p[j]))
    e.w32(lst + 0xc, arr)
    e.w32(lst + 0x10, rnd(c, 4 * len(pts) + 8))
    e.w32(lst + 0x14, rnd(c, 4 * len(pts) + 8))
    e.wf32(lst + 4, run)
    return lst


def quads(c, pts, n):
    """n door quads: most stand across a random path segment (raised 50, like the checks), some anywhere."""
    r = c.rng
    e = c.emu
    a = e.alloc(0x34 * n + 8, 4)
    for k in range(n):
        q = a + 0x34 * k
        if pts and len(pts) > 1 and r.random() < 0.8:
            i = r.randrange(len(pts) - 1)
            p0, p1 = pts[i], pts[i + 1]
            t = r.uniform(-0.2, 1.2)
            m = [p0[j] + (p1[j] - p0[j]) * t for j in range(3)]
            m[1] += 50
            dx, dz = p1[0] - p0[0], p1[2] - p0[2]
            ln = max((dx * dx + dz * dz) ** 0.5, 1e-3)
            px, pz = -dz / ln * r.uniform(20, 80), dx / ln * r.uniform(20, 80)
            h = r.uniform(20, 100)
            corners = [(m[0] - px, m[1] - h, m[2] - pz), (m[0] + px, m[1] - h, m[2] + pz),
                       (m[0] + px, m[1] + h, m[2] + pz), (m[0] - px, m[1] + h, m[2] - pz)]
        else:
            corners = [tuple(c.fv(-500, 500) for _ in range(3)) for _ in range(4)]
        for v, cv in enumerate(corners):
            for j in range(3):
                e.wf32(q + 0xc * v + 4 * j, sf(cv[j]))
        e.w32(q + 0x30, r.getrandbits(32))
    return a


def pathfinder(c, pts):
    r = c.rng
    e = c.emu
    o = rnd(c, 0xa0)
    nd = r.randint(0, 4)
    e.w32(o + 0x3e, nd)
    e.w32(o + 0x42, quads(c, pts, nd) if r.random() < 0.9 else 0)
    ng = r.randint(0, 3)
    e.w32(o + 0x36, ng)
    e.w32(o + 0x3a, quads(c, pts[-2:] if len(pts) > 1 else pts, ng) if r.random() < 0.8 else 0)
    return o


def _check(c, which):
    pts = path_points(c, 3)
    o = pathfinder(c, pts)
    e = c.emu
    a = e.alloc(16, 4)
    b = e.alloc(16, 4)
    i = c.rng.randrange(2)
    for j in range(3):
        e.wf32(a + 4 * j, sf(pts[i][j] + (50 if j == 1 else 0)))
        e.wf32(b + 4 * j, sf(pts[i + 1][j] + (50 if j == 1 else 0)))
    return [o, a, b, rnd(c, 4)]


S(0x52a850, 'ZPathfinder3::CheckLineAgainstAdditionalDoors', 'thiscall', None, ret='eax',
  gen=lambda c: _check(c, 'doors'))
S(0x52a970, 'ZPathfinder3::CheckLineAgainstGates', 'thiscall', None, ret='eax', gen=lambda c: _check(c, 'gates'))


def _post(c):
    r = c.rng
    reporter(c)
    allocator(c)
    hooks(c.emu, {0x52b9d0: ('ProcessAdditionalDoors', 'this', 0)})
    pts = path_points(c, r.randint(2, 6))
    o = pathfinder(c, pts)
    c.emu.w32(o + 0x2d, r.choice([0, 0, 1]))
    return [o, chk_list(c, pts) if r.random() < 0.95 else 0]


S(0x52b4e0, 'ZPathfinder3::PostProcessPath', 'thiscall', None, ret='eax', gen=_post)
