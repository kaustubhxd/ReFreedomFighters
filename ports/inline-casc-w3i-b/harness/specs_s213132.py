"""specs_s213132.py - batch 213132: radius / plane test with a four-way result code (SSE dot products, x87 normalise, engine random), Sonnet-w3b."""
import math
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g5941d0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]
    rdf = lambda a: struct.unpack('<f', bytes(e.rbytes(a, 4)))[0]
    C1, C3, K1, K2 = rdf(0x67a6ac), rdf(0x6ad230), rdf(0x6ad1f8), rdf(0x67a6b0)

    def unit():
        v = [r.gauss(0, 1) for _ in range(3)]
        n = math.sqrt(sum(x * x for x in v)) or 1.0
        return [f32(x / n) for x in v]

    def vec3():
        t = r.random()
        if t < 0.3:
            return [f32(x) for x in r.choice([(1, 0, 0), (0, 1, 0), (0, 0, 1), (-1, 0, 0), (0, 0, -1), (0, -1, 0), (K1, 0, 0), (C3, 0, 0), (K2, 0, 0), (C1, 0, 0), (0, 0, C3), (0, 0, K1)])]
        if t < 0.4:
            return [f32(r.choice([0.0, 1.0, -1.0, 0.5, K1, C3])) for _ in range(3)]
        return unit()

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    # positions: P1 - P2 horizontal direction, sometimes purely vertical / zero
    structured = r.random() < 0.65
    M = [1.0, -1.0, 2.0, -2.0, 0.75, -0.75, 0.5, -0.5, C3, K1, f32(0.9), f32(-0.9), 0.1, 0.0, -0.1]
    p2 = [f32(r.uniform(-40, 40)) for _ in range(3)]
    ax, sg = r.choice([0, 2]), r.choice([1.0, -1.0])
    if structured:
        d = [0.0, 0.0, 0.0]
        d[ax] = f32(sg * r.choice([3.0, 50.0, 7.0]))
        if r.random() < 0.08:
            d = [0.0, f32(r.choice([2.0, -2.0])), 0.0]
    else:
        mode = r.random()
        if mode < 0.12:
            d = [0.0, f32(r.uniform(-5, 5)), 0.0]
        elif mode < 0.2:
            d = [0.0, 0.0, f32(r.choice([3.0, -3.0, 50.0]))]
        elif mode < 0.28:
            d = [f32(r.choice([3.0, -3.0, 50.0])), 0.0, 0.0]
        else:
            d = [f32(r.uniform(-100, 100)) for _ in range(3)]
    p1 = [f32(a + b) for a, b in zip(p2, d)]
    P1 = e.alloc(16, 4)
    e.wbytes(P1, struct.pack('<3f', *p1))
    P2 = e.alloc(16, 4)
    e.wbytes(P2, struct.pack('<3f', *p2))
    N = e.alloc(16, 4)
    Pl = e.alloc(48, 4)

    def axisvec():
        v = [0.0, 0.0, 0.0]
        v[r.randrange(3)] = f32(r.choice(M))
        if r.random() < 0.25:
            v[r.randrange(3)] = f32(r.choice([0.0, 0.5, -0.5, 0.25]))
        return v
    if structured:
        pln = axisvec()
        if r.random() < 0.8:
            pln[ax] = f32(sg * r.choice([C3, -0.5, f32(-0.9), -0.75, -1.0, -0.1, 0.5]))
        nn = axisvec()
        other = axisvec()
        if r.random() < 0.25:   # scenario S: d5 == 0.5 exactly with d4 and dot1 in the middle band
            i = r.randrange(3)
            sn = r.choice([1.0, -1.0])
            nn = [0.0, 0.0, 0.0]
            nn[i] = sn
            other = [0.0, 0.0, 0.0]
            other[i] = f32(sn * 0.5)
            pln = [0.0, 0.0, 0.0]
            pln[ax] = f32(-0.25 * sg)
        t = r.random()
        if t < 0.12:   # scenario T: dot1 == C3 exactly and |N.Pl| > 0.9 (the path taken depends on the C3 comparison)
            pln = [0.0, 0.0, 0.0]
            pln[ax] = f32(sg * C3)
            nn = [0.0, 0.0, 0.0]
            nn[ax] = f32(r.choice([2.0, -2.0]))
        elif t < 0.24:   # scenario U: dot1 < C3 and |N.Pl| == 0.9f exactly
            pln = [0.0, 0.0, 0.0]
            pln[ax] = f32(-0.9 * sg)
            nn = [0.0, 0.0, 0.0]
            nn[ax] = f32(r.choice([1.0, -1.0]))
    else:
        pln = vec3()
        nn = r.choice([pln, [-x for x in pln], vec3(), vec3()])
        other = vec3()
    e.wbytes(N, struct.pack('<3f', *nn))
    e.wbytes(Pl, struct.pack('<3f', *pln) + bytes(12) + struct.pack('<3f', *other) + bytes(12))
    rad = f32(r.choice([-100.0, -50.0, 0.0, 20.0, 50.0, 100.0, r.uniform(-120, 120)]))

    def rand_st0(emu, k):
        return f32(r.choice([0.0, 0.25, 0.5, 0.75, 1.0, -1.0]))
    E = obj(c, 0x100, {0x1c0: pystub(c, 2, this=True, st0=rand_st0)}, nslots=0x80)

    def s114(emu, k):
        emu.calllog.append(('code', bytes(emu.rbytes(emu.arg32(4), 4))))
    K = obj(c, 0x40, {0x114: pystub(c, 6, this=True, stackmark=(4,), side=s114, ret=lambda emu, k: rb())}, nslots=0x60)
    w32u(E + 0x9b, K)
    e.w32(0x70039c, E)
    a0 = obj(c, 0x40, {0x128: pystub(c, 1, this=True)}, nslots=0x60)
    hook_rec(c, 0x633654, 0, ret=lambda emu, k: emu.reg('eax'), pop=0, this=True)
    return [a0, N, P1, rb(), P2, Pl, F(rad)]


S(0x5941d0, 'sphere_plane_test', 'stdcall', None, ret='al', gen=g5941d0)
