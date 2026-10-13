"""specs_s711.py - soldier AI batch 711: CFFCoverList::FindCover. Cover lists of 0..24 spots sorted by x and scattered
around the search position (so every filter both passes and fails), identity or random rotation matrices, threat
present or not, and fake geoms for the actor (team record, IsDerivedFrom, slot 0x614 area ref), threat/owner root
points, cover objects (active flag) and the area test (slots 0x8c/0x180). CCoverSpot::Reserve and CoverSpotQuality
are hooked (quality random) so the spot filters themselves are what is compared."""
import math
import struct
from pilot import S, F, f32
from specs_s701 import _rnd
from specs_s705 import _bool, nostk


def _pack3(v):
    return b''.join(struct.pack('<f', f32(x)) for x in v)


def _rot(c):
    if c.rng.random() < 0.5:
        return [1, 0, 0, 0, 1, 0, 0, 0, 1]
    a = c.rng.uniform(-math.pi, math.pi)
    ca, sa = math.cos(a), math.sin(a)
    return [ca, 0, -sa, 0, 1, 0, sa, 0, ca]


def _fc(c):
    e = c.emu
    log = lambda name, off, args: e.calllog.append((name, off, e.reg('ecx'), tuple(nostk(a) for a in args)))
    eng = _rnd(c, 0x200)
    e.w32(0x70039c, eng)
    P = [c.rng.uniform(-500, 500), c.rng.uniform(-50, 50), c.rng.uniform(-500, 500)]

    queue = []
    nullable = set()   # inline-wireai 2026-10-13: only the threat and the area ref may fail to resolve (both null-checked)

    def vec_out(name, off, gen):
        def h(em, r):
            p = em.arg32(0)
            log(name, off, tuple(struct.unpack('<3I', em.rbytes(p, 12))))
            em.wbytes(p, _pack3(queue.pop(0) if (off == 0x84 and queue) else gen()))
            em.ret(eax=0, argbytes=4)
        return h
    near = lambda: [P[0] + c.rng.uniform(-900, 900), P[1] + c.rng.uniform(-200, 200), P[2] + c.rng.uniform(-900, 900)]

    def area_test(em, r):
        p = em.arg32(0)
        log('area', 0x180, tuple(struct.unpack('<3I', em.rbytes(p, 12))) + (em.arg32(1),))
        em.ret(eax=_bool(c), argbytes=8)
    def area_ref(em, r):
        log('geom', 0x614, ())
        v = c.rng.choice([0, c.rng.getrandbits(32)])
        nullable.add(v)
        em.ret(eax=v, argbytes=0)
    vt = e.fake_vtable('geom', 0x1c0, {
        0x84: vec_out('geom', 0x84, near),
        0x8c: vec_out('geom', 0x8c, lambda: [c.rng.uniform(-50, 50) for _ in range(3)]),
        0x180: area_test,
        0x1e0: (lambda em, r: (log('geom', 0x1e0, (em.arg32(0),)), em.ret(eax=_bool(c), argbytes=4))),
        0x614: area_ref})

    def geom():
        g = _rnd(c, 0x80)
        e.w32(g, vt)
        info = _rnd(c, 0x40)
        w = e.r32(info + 0x3c) & ~0x400
        if c.rng.random() < 0.2:
            w |= 0x400
        e.w32(info + 0x3c, w)
        e.w32(g + 8, info)
        team = _rnd(c, 16)
        e.w32(team + 4, c.rng.choice([0, 1, 1, 2]))
        e.w32(g + 0x54, team)
        return g

    def lookup(em, r):
        ref = em.arg32(0)
        log('db', 0x58, (ref,))
        em.ret(eax=geom() if (ref not in nullable or c.rng.random() < 0.95) else 0, argbytes=4)
    db = _rnd(c, 32)
    e.w32(db, e.fake_vtable('db', 0x20, {0x58: lookup}))
    e.wbytes(eng + 0x9b, struct.pack('<I', db))

    def reserve(em, r):
        log('CCoverSpot::Reserve', 0, tuple(em.arg32(k) for k in range(4)))
        em.ret(eax=0, argbytes=16)
    e.hook(0x5df400, reserve)

    def csq(em, r):
        log('CoverSpotQuality', 0, (em.arg32(0),) + tuple(struct.unpack('<3I', em.rbytes(em.arg32(1), 12))) + (em.arg32(2),))
        em.ret(argbytes=12, st0=1.0 if edge else c.rng.choice([0.0, 1.0, 1.0, -0.0, math.nan]))
    e.hook(0x585910, csq)

    edge = c.rng.random() < 0.5
    if edge:
        args = _edge(c, e, P, queue, geom)
        nullable.add(args[2])
        return args
    n = c.rng.choice([0, 1, 4, 12, 24])
    xs = sorted(P[0] + c.rng.uniform(-800, 800) for _ in range(n))
    base = _rnd(c, 0x48 * max(n, 1))
    for i, x in enumerate(xs):
        s = base + 0x48 * i
        e.w32(s + 4, 0 if c.rng.random() < 0.75 else c.rng.getrandbits(32))
        e.w32(s + 0xc, 0 if c.rng.random() < 0.6 else c.rng.getrandbits(32))
        e.wbytes(s + 0x10, _pack3([x, P[1] + c.rng.choice([0, 0, c.rng.uniform(-300, 300)]), P[2] + c.rng.uniform(-800, 800)]))
        a = c.rng.uniform(-math.pi, math.pi)
        e.wbytes(s + 0x1c, _pack3([math.cos(a), 0, math.sin(a)]))
    cl = _rnd(c, 0x80)
    e.wbytes(cl + 0x5f, struct.pack('<II', base, base + 0x48 * n))
    e.wbytes(cl + 0x6f, struct.pack('<I', geom()))
    mat = e.alloc(36, 4)
    e.wbytes(mat, _pack3(_rot(c)))
    pos = e.alloc(16, 4)
    e.wbytes(pos, _pack3(P))
    goal = e.alloc(16, 4)
    e.wbytes(goal, _pack3(near()))
    r = c.rng.choice([300.0, 600.0, 1000.0, c.rng.uniform(50, 2000)])
    threat = c.rng.choice([0, c.rng.getrandbits(32)])
    nullable.add(threat)
    return [cl, c.rng.getrandbits(32), threat, mat, pos,
            F(-r), F(r), F(r), F(0.15 * r), goal, c.rng.choice([0, 1])]
    return [cl, c.rng.getrandbits(32), c.rng.choice([0, c.rng.getrandbits(32)]), mat, pos,
            F(-r), F(r), F(r), F(0.15 * r), goal, c.rng.choice([0, 1])]


def _edge(c, e, P, queue, geom):
    """Inputs placed on the thresholds: a spot at x == lower bound, threat at ~450, owner at ~75/~200, a held
    neighbour at ~350 (x difference and distance) facing away with the candidate's facing exactly across it, and the
    candidate's height difference at ~120 + 0.2 * distance."""
    r = c.rng.choice([300.0, 600.0, 1000.0])
    lo = f32(P[0] - r)
    tx = lo if c.rng.random() < 0.5 else f32(lo + c.rng.uniform(0, r))
    lx = tx - P[0]
    lz = c.rng.uniform(-r / 2, r / 2)
    ly = 120.0
    for _ in range(30):
        ly = 120.0 + 0.2 * math.sqrt(lx * lx + ly * ly + lz * lz)
    ly = (ly + c.rng.choice([-0.01, 0.0, 0.01, -1.0, 1.0])) * c.rng.choice([1, -1])
    T = [tx, P[1] + ly, P[2] + lz]
    def at(dist):
        a = c.rng.uniform(-math.pi, math.pi)
        return [T[0] + dist * math.cos(a), T[1], T[2] + dist * math.sin(a)]
    queue.append(at(450.0 + c.rng.uniform(-0.05, 0.05)))                  # threat root point
    queue.append(at(c.rng.choice([75.0, 200.0]) + c.rng.choice([c.rng.uniform(-0.05, 0.05), c.rng.uniform(-0.001, 0.001)])))   # owner root point
    side = c.rng.choice([-1, 1])
    dn = 350.0 + c.rng.uniform(-0.03, 0.03)
    N = [T[0] + side * dn, T[1], T[2]]
    tf = [0.0, 0.0, 1.0] if c.rng.random() < 0.5 else [side * 0.1, 0.0, 0.995]
    spots = [(T, tf, 0), (N, [0.0, 0.0, -1.0], 0x1234)]
    for _ in range(c.rng.choice([0, 2, 4])):
        spots.append(([P[0] + c.rng.uniform(-r, r), P[1], P[2] + c.rng.uniform(-r, r)], [1.0, 0.0, 0.0], c.rng.choice([0, 9])))
    spots.sort(key=lambda t: f32(t[0][0]))
    n = len(spots)
    base = _rnd(c, 0x48 * n)
    for i, (pp, f, h) in enumerate(spots):
        sp = base + 0x48 * i
        e.w32(sp + 4, h)
        e.w32(sp + 0xc, 0)
        e.wbytes(sp + 0x10, _pack3(pp))
        e.wbytes(sp + 0x1c, _pack3(f))
    cl = _rnd(c, 0x80)
    e.wbytes(cl + 0x5f, struct.pack('<II', base, base + 0x48 * n))
    e.wbytes(cl + 0x6f, struct.pack('<I', geom()))
    mat = e.alloc(36, 4)
    e.wbytes(mat, _pack3([1, 0, 0, 0, 1, 0, 0, 0, 1]))
    pos = e.alloc(16, 4)
    e.wbytes(pos, _pack3(P))
    goal = e.alloc(16, 4)
    e.wbytes(goal, _pack3(P))
    return [cl, c.rng.getrandbits(32), c.rng.getrandbits(32) | 1, mat, pos, F(-r), F(r), F(r), F(0.15 * r), goal,
            c.rng.choice([0, 1])]


S(0x586bc0, 'CFFCoverList::FindCover', 'thiscall', None, ret='eax', gen=_fc, note='b711 [high]; Reserve and CoverSpotQuality hooked')
