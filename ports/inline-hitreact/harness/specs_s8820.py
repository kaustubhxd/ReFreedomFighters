"""specs_s8820.py - hitreact batch 8820: ZLNKOBJ::GetBoneFromPoint (0x462d80). Exe code in both builds: 0x463010 (-> the bone modifier's slot 0x58,
a stub returning the case's pose array), 0x460e20, vmmul 0x441970, PSVECAdd, PSVECSubtract, vmtmul 0x441a60, 0x465470. The object's slot 0x2cc
returns the bone table (centre +0, half extents +0x10, 48 bytes a bone); +0x20 = the bone count."""
import math
import struct
from pilot import S
from wkit import rnd, stub, obj, fedge


def _rot(r):
    a, b, c = r.uniform(-3.2, 3.2), r.uniform(-1.5, 1.5), r.uniform(-3.2, 3.2)
    ca, sa, cb, sb, cc, sc = math.cos(a), math.sin(a), math.cos(b), math.sin(b), math.cos(c), math.sin(c)
    return [ca * cb, ca * sb * sc - sa * cc, ca * sb * cc + sa * sc, sa * cb, sa * sb * sc + ca * cc, sa * sb * cc - ca * sc, -sb, cb * sc, cb * cc]


def _gen(c):
    r = c.rng
    emu = c.emu
    n = r.choice((2, 3, 4, 6, 9, 14, 20, 28))
    nb = n + r.choice((0, 0, 0, 1))   # the loop ends on equality with +0x20; sometimes the count is the table size
    tab = emu.alloc(0x30 * (n + 2), 4)
    pose = emu.alloc(0x30 * (n + 2), 4)
    ident = r.random() < 0.5
    CEN, HALF, MAT, POS = [], [], [], []
    for i in range(n + 2):
        CEN.append([r.uniform(-60, 60) for _ in range(3)])
        HALF.append([r.choice((r.uniform(1, 40), r.uniform(20, 120), 0.0, fedge(c))) for _ in range(3)])
        MAT.append([1, 0, 0, 0, 1, 0, 0, 0, 1] if ident else _rot(r))
        POS.append([r.uniform(-100, 100) for _ in range(3)])
    cluster = r.random() < 0.6 and n >= 3
    if cluster:   # a cluster: bones sharing (nearly) one centre and frame, so ties and tiny distances decide
        jit = r.choice((0.0, 0.0, 0.2, 0.7))
        if r.random() < 0.5:
            HALF[2] = [r.uniform(20, 60) for _ in range(3)]   # bone 2 holds the point; the others are empty boxes at the same place
            MAT[2] = [1, 0, 0, 0, 1, 0, 0, 0, 1]
        for i in range(3, n + 2):
            if r.random() < 0.7:
                CEN[i] = [CEN[2][k] + r.uniform(-jit, jit) for k in range(3)]
                HALF[i] = [max(-3e38, min(3e38, HALF[2][k] * r.choice((1.0, 1.0, 0.5, 2.0, 0.0, 0.0)))) for k in range(3)]
                MAT[i] = list(MAT[2])
                POS[i] = list(POS[2])
    pts = []
    for i in range(n + 2):
        for k in range(3):
            emu.wf32(tab + 0x30 * i + 4 * k, CEN[i][k])
            emu.wf32(tab + 0x30 * i + 0x10 + 4 * k, HALF[i][k])
            emu.wf32(pose + 0x30 * i + 0x24 + 4 * k, POS[i][k])
        for k in range(9):
            emu.wf32(pose + 0x30 * i + 4 * k, MAT[i][k])
        pts.append([CEN[i][k] + POS[i][k] for k in range(3)])
    if r.random() < 0.7:
        base = pts[2] if (cluster and r.random() < 0.7) else r.choice(pts)
        p = [base[k] + r.choice((r.uniform(-30, 30), r.uniform(-0.5, 0.5), 0.0)) for k in range(3)]
    else:
        p = [r.choice((r.uniform(-200, 200), fedge(c), 0.0)) for _ in range(3)]
    pa = emu.alloc(16, 4)
    for k in range(3):
        emu.wf32(pa + 4 * k, p[k])
    bm = obj(c, 0x40, {0x58: stub(c, 1, ret=pose)})
    self = obj(c, 0x80, {0x2cc: stub(c, 0, ret=tab)})
    emu.w32(self + 0x6c, bm)
    emu.w32(self + 0x20, nb)
    emu.mu.ctl_flush_tb()
    return [self, pa]


S(0x462d80, 'ZLNKOBJ::GetBoneFromPoint', 'thiscall', ret='eax', gen=_gen)
