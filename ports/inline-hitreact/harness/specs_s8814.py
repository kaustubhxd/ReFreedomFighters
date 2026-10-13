"""specs_s8814.py - hitreact batch 8814: ConstrainedParticleSystem::ZeroOut 0x547a70 (fastcall ECX = this, EDX = n). All callees run
as exe code in both builds (vadd, vsub-in-place, PSVECSubtract, vcross, mmmul, mcpy, vaddscalar, vscalar3, AdjustCone4/5/6, the
minimum-distance constraint 0x543680, the distance constraint 0x5434d0). The engine random (slot 0x1c4, used by the two constraints for
coincident particles) is a cycling stub. Object (packed PC layout): +0xf particles, +0x13 distance list, +0x17 minimum-distance list
(0xc per entry: i, j, length), +0x28 particle count, +0x2c / +0x30 the two list counts, +0x50 joint flag. Globals: the joint tables
0x711b98 (8 x 9 floats), alphax 0x711cb8, alphay 0x711cd8. 16 particles around the ctor's default body with perturbations."""
import math
import struct
from pilot import S, F
from wkit import obj, fedge
from hkit import fvec

POSE = [[0, 260, 0], [0, 230, 0], [-50, 210, 0], [50, 210, 0], [-50, 150, 0], [-20, 150, 0], [20, 150, 0], [50, 150, 0],
        [-30, 120, 0], [30, 120, 0], [-50, 90, 0], [50, 90, 0], [-30, 60, 0], [30, 60, 0], [-30, 0, 0], [30, 0, 0]]
CMASS = [1, 1, 2, 2, 1, 2, 2, 1, 2, 2, 1, 1, 1, 1, 1, 1]
DIST = [(0, 1), (1, 2), (1, 3), (2, 5), (3, 6), (1, 5), (1, 6), (2, 6), (3, 5), (5, 6), (2, 4), (3, 7),
        (4, 10), (7, 11), (5, 8), (6, 9), (5, 9), (6, 8), (8, 9), (8, 12), (9, 13), (12, 14), (13, 15), (2, 3)]
ANGLES = [(-15, 65, -30, 10), (-15, 65, -10, 30), (-165, -5, -20, 2), (-165, -5, -2, 20), (-90, 90, -80, 40), (0, 150, -90, 90),
          (-90, 90, -40, 80), (0, 150, -90, 90)]


def f32(x):
    return struct.unpack('<f', struct.pack('<f', x))[0]


def _norm(v):
    l = math.sqrt(sum(x * x for x in v))
    return [x / l for x in v] if l else v


def _cross(a, b):
    return [a[1] * b[2] - a[2] * b[1], a[2] * b[0] - a[0] * b[2], a[0] * b[1] - a[1] * b[0]]


def _base(minx, maxx, miny, maxy):
    d = 0.017453292
    mx, my = (minx + maxx) * 0.5 * d, (miny + maxy) * 0.5 * d
    r0 = _norm([math.sin(mx), math.cos(mx) * math.tan(my), math.cos(mx)])
    r2 = _norm([r0[2], 0.0, -r0[0]])
    r1 = _norm(_cross(r0, r2))
    hx, hy = (maxx - minx) * 0.5 * d, (maxy - miny) * 0.5 * d
    return r0 + r1 + r2, 1.0 / math.tan(hx), 1.0 / math.tan(hy)


def _cycle_stub(c, vals):
    """thiscall (file, line), ret 8: loads vals[k % n] into ST0 on the k-th call; counts calls."""
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


def _gen(c):
    r = c.rng
    emu = c.emu
    eng = obj(c, 0x200, {0x1c4: _cycle_stub(c, [r.uniform(-1, 1) or 0.25, r.uniform(-1, 1) or 0.5, r.uniform(-1, 1) or -0.75])})
    emu.w32(0x70039c, eng)
    # joint tables
    tm = r.random()
    for k, ang in enumerate(ANGLES):
        if tm < 0.6:
            ang = [a + r.uniform(-5, 5) for a in ang] if r.random() < 0.5 else ang
            m, ax, ay = _base(*ang)
        elif tm < 0.85:
            m = [r.uniform(-1, 1) for _ in range(9)]
            ax, ay = r.uniform(-1, 6), r.uniform(-1, 6)
        else:
            m, ax, ay = _base(*ANGLES[k])
            ax, ay = r.choice((ax, 0.0, 10.0, 0.05)), r.choice((ay, 0.0, 10.0, 0.05))
        for j in range(9):
            emu.wf32(0x711b98 + 0x24 * k + 4 * j, m[j])
        emu.wf32(0x711cb8 + 4 * k, ax)
        emu.wf32(0x711cd8 + 4 * k, ay)
    # particles
    parts = emu.alloc(0x34 * 16 + 0x40, 4)
    emu.wbytes(parts, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    sc = r.choice((0.0, 2.0, 8.0, 20.0, 40.0, 80.0))
    a, b = r.uniform(-math.pi, math.pi), r.uniform(-1.5, 1.5) if r.random() < 0.4 else 0.0
    ca, sa, cb, sb = math.cos(a), math.sin(a), math.cos(b), math.sin(b)
    off = [r.uniform(-500, 500) for _ in range(3)] if r.random() < 0.5 else [0.0, 0.0, 0.0]
    P = []
    for i in range(16):
        p = [POSE[i][k] + r.uniform(-sc, sc) for k in range(3)]
        x, y, z = p
        y, z = y * cb - z * sb, y * sb + z * cb
        x, z = x * ca + z * sa, -x * sa + z * ca
        P.append([x + off[0], y + off[1], z + off[2]])
    mode = r.random()
    if mode < 0.15:     # legs / feet crossed or close together
        for i, j in ((12, 13), (14, 15)):
            if r.random() < 0.7:
                t = r.uniform(-1.2, 0.6)
                mid = [(P[i][k] + P[j][k]) * 0.5 for k in range(3)]
                for k in range(3):
                    hv = (P[j][k] - P[i][k]) * 0.5
                    P[i][k], P[j][k] = mid[k] - hv * t, mid[k] + hv * t
    elif mode < 0.2:    # coincident particles (zero vectors in the frames, coincident constraint ends)
        for _ in range(r.randrange(1, 6)):
            i, j = r.sample(range(16), 2)
            P[j] = list(P[i])
    elif mode < 0.23:   # all at one point
        q = [float(r.randrange(-50, 50)) for _ in range(3)]
        P = [list(q) for _ in range(16)]
    elif mode < 0.3:    # integer positions (exact zero tests, plane s = 0)
        P = [[float(round(v)) for v in p] for p in P]
    elif mode < 0.45:   # exact: identity joint tables, unperturbed integer pose with -0.0 zeros (plane s = 0, leg gap exactly 10,
        P = [[float(v) for v in p] for p in POSE]    # z-only frame vectors); a +0 added to -0 shows up as +0
        for k in range(8):
            for j in range(9):
                emu.wf32(0x711b98 + 0x24 * k + 4 * j, 1.0 if j in (0, 4, 8) else 0.0)
        for p in P:
            for k in range(3):
                if p[k] == 0.0 and r.random() < 0.7:
                    p[k] = -0.0
        if r.random() < 0.5:
            P[13][0] = P[12][0] + 10.0
        if r.random() < 0.5:
            P[15][0] = P[14][0] + 10.0
        if r.random() < 0.4:    # vectors along z only
            i, j = r.choice(((8, 9), (8, 12), (9, 13), (2, 3), (3, 7), (2, 4), (12, 13), (9, 8)))
            P[j] = [P[i][0], P[i][1], P[i][2] + r.choice((5.0, -3.0, 1.0))]
    for i in range(16):
        for k in range(3):
            emu.wf32(parts + 0x34 * i + 0xc + 4 * k, P[i][k])
    nanp = r.random() < 0.08
    if nanp:   # two different NaN payloads in one particle (the operand order of the SSE sums)
        i = r.choice((12, 12, 13, 7, 4, 15, 14))
        na, nb = 0x7fc00001 + r.randrange(0x1000), 0xffc12345 + r.randrange(0x1000)
        if r.random() < 0.5:
            na, nb = nb, na
        emu.w32(parts + 0x34 * i + 0xc, na)
        emu.w32(parts + 0x34 * i + 0x10, nb)
    mm = r.random()
    for i in range(16):
        if mm < 0.4:
            m = 1.0
        elif mm < 0.6:
            m = float(CMASS[i])
        else:
            m = r.choice((1.0, 1.0, 1.0, 10000.0, 0.5, 2.0, 3.0, r.uniform(0.1, 5)))
        emu.wf32(parts + 0x34 * i + 0x30, m)
    if r.random() < 0.03:
        emu.wf32(parts + 0x34 * r.choice((r.randrange(16), 12, 13, 7, 4)) + 0x30, r.choice((0.0, float('inf'), fedge(c))))
    if 0.3 <= mode < 0.45 and r.random() < 0.6:   # infinite mass on a plane's second particle: k = 0 * inf = NaN when s = 0
        emu.wf32(parts + 0x34 * r.choice((12, 13, 7, 4)) + 0x30, float('inf'))
    # rest lengths from the default pose
    d = lambda i, j: math.dist(POSE[i], POSE[j])
    dl = [(i, j, d(i, j) * (r.uniform(0.7, 1.3) if r.random() < 0.3 else 1.0)) for i, j in DIST]
    v1, v2, v3, v4 = d(2, 8) * 0.95, d(5, 9) * 1.5, d(2, 6), d(8, 12)
    ml = [(2, 8, v1), (3, 9, v1), (5, 11, v2), (6, 10, v2), (2, 11, v3), (3, 10, v3), (8, 14, d(8, 14) * 0.1), (9, 15, d(8, 14) * 0.1),
          (8, 15, v4), (9, 14, v4), (2, 15, v4 * 2.2), (3, 14, v4 * 1.9),
          (3, 15, d(3, 15) * 0.6) if r.random() < 0.5 else (2, 14, d(2, 14) * 0.6)]
    if r.random() < 0.3:
        ml = [(i, j, v * r.uniform(0.5, 2.0)) for i, j, v in ml]
    if r.random() < 0.3:
        r.shuffle(dl)
        r.shuffle(ml)
    nd = len(dl) if r.random() < 0.7 else r.choice((0, 1, 5, -1, r.randrange(25)))
    nm = len(ml) if r.random() < 0.7 else r.choice((0, 1, 4, -3, r.randrange(14)))
    if (0.3 <= mode < 0.45 or nanp) and r.random() < 0.5:   # no constraints: an infinite mass would make every position NaN through them
        nd = nm = 0
    dla = emu.alloc(0xc * len(dl) + 0x10, 4)
    for k, (i, j, v) in enumerate(dl):
        emu.w32(dla + 0xc * k, i)
        emu.w32(dla + 0xc * k + 4, j)
        emu.wf32(dla + 0xc * k + 8, v)
    mla = emu.alloc(0xc * len(ml) + 0x10, 4)
    for k, (i, j, v) in enumerate(ml):
        emu.w32(mla + 0xc * k, i)
        emu.w32(mla + 0xc * k + 4, j)
        emu.wf32(mla + 0xc * k + 8, v)
    self = emu.alloc(0x80, 4)
    emu.wbytes(self, bytes(r.getrandbits(8) for _ in range(0x80)))
    emu.w32(self + 0xf, parts)
    emu.w32(self + 0x13, dla)
    emu.w32(self + 0x17, mla)
    emu.w32(self + 0x28, 16)
    emu.w32(self + 0x2c, nd & 0xffffffff)
    emu.w32(self + 0x30, nm & 0xffffffff)
    emu.wbytes(self + 0x50, bytes([r.choice((1, 1, 1, 1, 0, 0x80))]))
    n = r.choice((1, 1, 2, 3, 3, 10, 0, -1))
    emu.mu.ctl_flush_tb()
    return [self, n & 0xffffffff]


S(0x547a70, 'ConstrainedParticleSystem::ZeroOut', 'fastcall', ret=None, gen=_gen, max_insns=30000000)
