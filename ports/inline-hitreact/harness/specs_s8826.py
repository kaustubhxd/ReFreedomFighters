"""specs_s8826.py - hitreact batch 8826: ZIKLNKOBJ::CanPlayAnimSegment 0x465a80 on its REAL callees. Every helper runs as exe code in both
builds: vmmul 0x4419f0, vsetlen 0x4e0d80, 0x43e8e0, vscalar 0x4e0d40, createmat 0x4de040, PSVECAdd / PSVECSubtract, ZCollisionBox::SetBox
0x4eb020 / GetStrips 0x4ea300 / CalcLineCollision 0x4e8c00 (-> 0x4e8c80 -> IntersectTriangleAndLine 0x4e2560) / the box probe 0x4e9200 (->
0x4e9280 -> 0x4dddf0 -> 0x4ddb20 / 0x4dd930), the CRT sqrt 0x634d7c and ftol 0x633910. Only the engine objects are stubs (Python hooks):
  [[0x70039c] + 0x1aa3] + 0x1c = the collision base: slot 0x44 (box locked?) -> a bool from the case; slot 0x48 (LockCollisionBox(buffer,
  0x18000), pops 8) -> the case's ZCollisionBox E (its +0xc / +0x10 strip buffer preset); slot 0x4c(E) unlock; slot 0x84 (GetStripsInsideBox,
  8 arguments) writes the case's strips into its buffer argument and their count, returns 1 (rarely 0).
  this + 0x5c = the animation object: slot 0x2c(header, 0) -> a track handle; slot 0xc(track, 0, pos, quat, t) writes the case's root sample.
The header's +0x70 holds the clip's root delta; a4 is a real yaw matrix in the exe layout (rows z, y, x); vec = the feet. The level: floor
quads around the feet (either winding), sometimes a hole, a wall across the path, a step up or down, a low ceiling."""
import math
import struct
from pilot import S
from pe_emu import F as FP


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _strip(verts, surf=(0, 0, 0)):
    return [(len(verts), surf, [list(v) for v in verts])]


def _f(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _local(v, m, pos):
    """World -> the box frame the way ZCollisionBox reads it: (v - pos) times m transposed (vmtmul 0x441a60 lanes)."""
    d = [_f(v[k] - pos[k]) for k in range(3)]
    return [_f((d[0] * m[6] + d[1] * m[7]) + d[2] * m[8]), _f((d[0] * m[3] + d[1] * m[4]) + d[2] * m[5]),
            _f((d[0] * m[0] + d[1] * m[1]) + d[2] * m[2])]


def _pack(strips, m, pos):
    b = b''
    for n, surf, verts in strips:
        b += struct.pack('<IIIII', n, 0, surf[0], surf[1], surf[2]) + struct.pack('<I', 0)
        for v in verts:
            b += struct.pack('<fff', *_local(v, m, pos))
    return b


def _quad(a, b, cc, d, flip):
    # a quad a b / cc d (cc opposite b) as a strip a, b, cc, d: triangles (a, b, cc) and (d, cc, b) after the odd-k reversal, one facing
    return [a, b, cc, d] if not flip else [b, a, d, cc]


def _gen(c):
    e = c.emu
    r = c.rng
    logbuf = e.alloc(0x400, 4)
    e.wbytes(logbuf, bytes(0x400))
    pos = [4]

    def log(*vals):
        # every hook call appends its values (dwords; floats by bits; bools as 0 / 1) to a heap log the compare covers
        for v in vals:
            if pos[0] + 4 > 0x400:
                return
            if isinstance(v, float):
                v = struct.unpack('<I', struct.pack('<f', v))[0]
            e.w32(logbuf + pos[0], int(v) & 0xffffffff)
            pos[0] += 4
        e.w32(logbuf, pos[0])
    yaw = r.uniform(-math.pi, math.pi)
    cy, sy = math.cos(yaw), math.sin(yaw)
    R = [[cy, 0.0, sy], [0.0, 1.0, 0.0], [-sy, 0.0, cy]]                 # real rotation, world = R * local
    m = [R[0][2], R[1][2], R[2][2], R[0][1], R[1][1], R[2][1], R[0][0], R[1][0], R[2][0]]
    feet = [r.uniform(-500, 500), r.uniform(-50, 50), r.uniform(-500, 500)]
    L = r.choice((0.0, 0.005, 20.0, 60.0, 120.0, 200.0, 320.0))
    rd = [r.choice((0.0, r.uniform(-10, 10))), r.choice((0.0, r.uniform(-20, 20))), L * r.choice((1, 1, -1))]
    samp = [x * r.choice((0.5, 0.0, 1.2)) for x in rd]
    fwd = [R[0][2], 0.0, R[2][2]]
    side = [R[0][0], 0.0, R[2][0]]
    y0 = feet[1]
    strips = []
    n = 0
    flip = r.random() < 0.5
    mixed = r.random() < 0.2

    def floor(cx, cz, h, w, y):
        a = [cx - w, y, cz - w]; b = [cx + w, y, cz - w]; cc = [cx - w, y, cz + w]; d = [cx + w, y, cz + w]
        return _strip(_quad(a, b, cc, d, (r.random() < 0.5) if mixed else flip), (r.getrandbits(16), r.getrandbits(32), r.getrandbits(32)))

    kind = r.choice(('flat', 'flat', 'hole', 'wall', 'stepup', 'stepdown', 'ceiling', 'none', 'stepceil', 'stepup', 'ceiling'))
    if kind != 'none':
        if kind == 'hole':
            strips += floor(feet[0], feet[2], 0, 40.0, y0); n += 1
        else:
            strips += floor(feet[0], feet[2], 0, 600.0, y0); n += 1
    dist = r.uniform(20, 250) if r.random() < 0.5 else max(L, 30.0) * r.uniform(0.3, 0.7)   # half the obstacles over the path
    mid = [feet[0] + fwd[0] * dist, feet[2] + fwd[2] * dist]
    if kind == 'wall':
        hgt = r.choice((30.0, 100.0, 300.0))
        p0 = [mid[0] - side[0] * 200, y0 - 10, mid[1] - side[2] * 200]
        p1 = [mid[0] + side[0] * 200, y0 - 10, mid[1] + side[2] * 200]
        q0 = [p0[0], y0 + hgt, p0[2]]; q1 = [p1[0], y0 + hgt, p1[2]]
        strips += _strip(_quad(p0, p1, q0, q1, r.random() < 0.5)); n += 1
    dy = 0.0
    if kind in ('stepup', 'stepdown', 'stepceil'):
        dy = r.choice((10.0, 20.0, 24.0, 26.0, 40.0)) * (-1 if kind == 'stepdown' else 1)
        strips += floor(mid[0] + fwd[0] * 300, mid[1] + fwd[2] * 300, 0, 300.0, y0 + dy); n += 1
        if r.random() < 0.6:                          # the riser at the step edge (either facing)
            e0 = [mid[0] - side[0] * 300, min(y0, y0 + dy), mid[1] - side[2] * 300]
            e1 = [mid[0] + side[0] * 300, min(y0, y0 + dy), mid[1] + side[2] * 300]
            u0 = [e0[0], max(y0, y0 + dy), e0[2]]; u1 = [e1[0], max(y0, y0 + dy), e1[2]]
            strips += _strip(_quad(e0, e1, u0, u1, r.random() < 0.5)); n += 1
    if kind in ('ceiling', 'stepceil'):
        hc = r.choice((100.0, 150.0, 180.0, 250.0, 204.5, 205.5, 204.9, 205.1)) + (max(dy, 0.0) if r.random() < 0.5 else 0.0)
        strips += floor(mid[0], mid[1], 0, r.choice((80.0, 400.0)), y0 + hc); n += 1
    E = _rnd(c, 0x80)
    buf = e.alloc(0x2000, 4)
    e.wbytes(buf, bytes(0x2000))
    e.w32(E + 0xc, buf)
    e.w32(E + 0x10, 0x2000)
    locked = 1 if r.random() < 0.05 else 0
    ok = 0 if r.random() < 0.03 else 1

    def h44(e2, rr):
        log(0x44)
        e2.ret(eax=locked, argbytes=0)

    def h48(e2, rr):
        log(0x48, e2.arg32(1))
        e2.ret(eax=E, argbytes=8)

    def h4c(e2, rr):
        log(0x4c, e2.arg32(0) == E)
        e2.ret(argbytes=4)

    def h84(e2, rr):
        log(0x84, e2.arg32(2), e2.arg32(6), e2.arg32(7), *struct.unpack('<9I', e2.rbytes(e2.arg32(3), 36)),
            *struct.unpack('<3I', e2.rbytes(e2.arg32(4), 12)), *struct.unpack('<3I', e2.rbytes(e2.arg32(5), 12)))
        bm = struct.unpack('<9f', e2.rbytes(e2.arg32(3), 36))
        bp = struct.unpack('<3f', e2.rbytes(e2.arg32(4), 12))
        e2.wbytes(e2.arg32(1), _pack(strips, bm, bp))
        e2.w32(e2.arg32(0), n)
        e2.ret(eax=ok, argbytes=32)

    vtB2 = e.fake_vtable('vt8826b2', 0x100, {0x44: h44, 0x48: h48, 0x4c: h4c, 0x84: h84})
    B2 = _rnd(c, 0x100)
    e.w32(B2, vtB2)
    A = _rnd(c, 0x100)
    e.w32(A + 0x1c, B2)
    G = _rnd(c, 0x2000)
    e.w32(G + 0x1aa3, A)
    e.w32(0x70039c, G)
    out = e.alloc(0x40, 4)
    lg = e.alloc(0x40, 4)

    def hlog(e2, rr):
        log(0x20)
        e2.ret(eax=out, argbytes=8)

    def hmsg(e2, rr):
        log(0x2c)
        e2.ret(argbytes=0)
    e.w32(lg, e.fake_vtable('vt8826lg', 0x40, {0x20: hlog}))
    e.w32(out, e.fake_vtable('vt8826out', 0x40, {0x2c: hmsg}))
    e.w32(0x700390, lg)
    X = _rnd(c, 0x40)

    def h2c(e2, rr):
        log(0x2c, e2.arg32(1))
        e2.ret(eax=X, argbytes=8)

    def hc(e2, rr):
        log(0xc, e2.arg32(0) == X, e2.arg32(4))
        e2.wbytes(e2.arg32(2), struct.pack('<fff', *samp))
        e2.wbytes(e2.arg32(3), struct.pack('<ffff', 0.0, 0.0, 0.0, 1.0))
        e2.ret(argbytes=20)

    vtO = e.fake_vtable('vt8826o', 0x40, {0x2c: h2c, 0xc: hc})
    obj2 = _rnd(c, 0x40)
    e.w32(obj2, vtO)
    this = _rnd(c, 0x800)
    e.w32(this + 0x5c, obj2)
    P = _rnd(c, 0x100)
    e.wbytes(P + 0x70, struct.pack('<fff', *rd))
    mp = e.alloc(0x30, 4)
    e.wbytes(mp, struct.pack('<9f', *m))
    vec = e.alloc(0x20, 4)
    e.wbytes(vec, struct.pack('<fff', *feet))
    f1 = r.choice((0.0, 3.0))
    f2 = f1 + r.choice((10.0, 20.0, 31.0))
    return [this, P, FP(f1), FP(f2), mp, vec, FP(50.0), FP(-130.0)]


S(0x465a80, 'ZIKLNKOBJ::CanPlayAnimSegment (real callees)', 'thiscall', None, ret='al', gen=_gen)
