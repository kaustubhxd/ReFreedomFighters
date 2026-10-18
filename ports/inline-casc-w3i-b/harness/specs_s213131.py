"""specs_s213131.py - batch 213131: cloth/rope relaxation (distance constraints, pinned vertices, index-pair copies), Sonnet-w3b."""
import struct
from pilot import S, F
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub


def g450fc0(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    rb = lambda: r.getrandbits(32)
    f32 = lambda v: struct.unpack('<f', struct.pack('<f', v))[0]

    def fv(lo=-4.0, hi=4.0):
        return f32(r.choice([0.0, 0.0, 1.0, -1.0, 0.5, r.uniform(lo, hi), r.uniform(lo, hi), float('nan') if r.random() < 0.02 else 2.0]))

    def w32u(addr, v):
        e.wbytes(addr, struct.pack('<I', v & 0xffffffff))
    this = rnd(c, 0x80)
    n = r.choice([0, 1, 2, 3, 4, 5, 3, 4])
    cnt = r.choice([0, 1, 2, 3, 5])
    pc = 2 * r.choice([0, 1, 2, 3])
    m = r.choice([0, 1, 2, 3])
    w32u(this + 0x18, m)
    e.wbytes(this + 0x34, struct.pack('<f', f32(r.choice([0.5, 1.0, 0.25, r.uniform(0, 1.5), 0.0]))))
    w32u(this + 0x44, n)
    w32u(this + 0x48, cnt)
    w32u(this + 0x54, pc)
    nv = max(1, 2 * n)
    # constraint records
    cons = e.alloc(16 * max(cnt, 1) + 16, 4)
    for i in range(cnt):
        rec = struct.pack('<HHffff', r.randrange(nv), r.randrange(nv), fv(0, 1), fv(0, 3), 0.0, 0.0)[:12] + struct.pack('<f', fv(0, 3))
        e.wbytes(cons + 16 * i, rec)
    w32u(this + 0x4c, cons)
    pairs = e.alloc(2 * max(pc, 1) + 8, 4)
    e.wbytes(pairs, b''.join(struct.pack('<H', r.randrange(nv)) for _ in range(max(pc, 1) + 1)))
    w32u(this + 0x50, pairs)
    B = e.alloc(12 * nv + 16, 4)
    e.wbytes(B, b''.join(struct.pack('<f', fv()) for _ in range(3 * nv)))
    w32u(this + 0x58, B)
    rows = e.alloc(16 * 4, 4)
    Ps = []
    for k in range(3):
        P = e.alloc(12 * nv + 16, 4)
        e.wbytes(P, b''.join(struct.pack('<f', fv()) for _ in range(3 * nv)))
        Ps.append(P)
        w32u(rows + 16 * k, P)
    w32u(this + 0x5c, rows)
    W = e.alloc(4 * nv + 8, 4)
    e.wbytes(W, b''.join(struct.pack('<f', f32(r.choice([0.0, 0.0, 1.0, 0.5, float('nan') if r.random() < 0.05 else 2.0]))) for _ in range(nv)))
    w32u(this + 0x64, W)
    row = r.randrange(3)

    def perturb(emu, k):
        P = emu.arg32(0)
        for _ in range(2):
            idx = r.randrange(3 * nv)
            emu.wbytes(P + 4 * idx, struct.pack('<f', fv()))
    hook_rec(c, 0x44ef80, 4, pop=16, this=True, side=perturb)
    hook_rec(c, 0x44f0f0, 2, pop=8, this=True, side=perturb)
    hook_rec(c, 0x44f550, 0, pop=0, this=True)
    return [this, row, rb()]


S(0x450fc0, 'cloth_relax', 'thiscall', None, ret=None, gen=g450fc0)
