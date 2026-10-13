"""specs_s8810.py - hitreact batch 8810: AdjustCone6 (0x542ee0). All callees are exe code in both builds (PSVECSubtract, vmtmul, vmmul,
PSVECAdd, vnorm, vcross, 0x43e8e0, the solver 0x547860, vscalar, vscalar3, vaddscalar: all strict). 16 particle records of 0x34 bytes
(position +0xc, mass +0x30); the result is the particles' new positions."""
import math
import struct
from pilot import S, F
from wkit import rnd, fedge
from hkit import fvec


def _rot(c):
    r = c.rng
    a, b = r.uniform(0, 6.283), r.uniform(-1.5, 1.5)
    ca, sa, cb, sb = math.cos(a), math.sin(a), math.cos(b), math.sin(b)
    return [ca, 0.0, -sa, sa * sb, cb, ca * sb, sa * cb, -sb, ca * cb]


def _gen(c):
    r = c.rng
    emu = c.emu
    base = emu.alloc(0x34 * 16 + 0x40, 4)
    emu.wbytes(base, bytes(r.getrandbits(8) for _ in range(0x34 * 16 + 0x40)))
    m = _rot(c) if r.random() < 0.8 else [r.uniform(-1, 1) for _ in range(9)]
    idx = r.sample(range(16), 4) if r.random() < 0.95 else [r.randrange(16) for _ in range(4)]
    ia, ib, ic, id_ = idx
    centre = [r.uniform(-200, 200) for _ in range(3)]
    for i in range(16):
        for k in range(3):
            emu.wf32(base + i * 0x34 + 0xc + 4 * k, centre[k] + r.uniform(-40, 40))
        emu.wf32(base + i * 0x34 + 0x30, r.choice((1.0, 1.0, 1.0, 10000.0, 0.5, 0.0)) if r.random() < 0.3 else 1.0)
    a = r.choice((0.0, 0.5, 1.0, 1.732, 3.0, r.uniform(0, 5), fedge(c)))
    if r.random() < 0.4 and math.isfinite(a) and abs(a) < 1e6:
        # D placed in joint space near the wedge edge: Lq = (x, y, z) with z around |y a|
        y = r.uniform(-30, 30)
        z = abs(y * a) + r.choice((-5.0, -0.5, 0.0, 0.5, 5.0, -abs(y * a) - 3.0))
        x = r.uniform(-30, 30)
        # world offset = Lq * m^T-ish (approximate: exact placement is not needed, only the spread)
        A = [emu.rf32(base + ia * 0x34 + 0xc + 4 * k) if hasattr(emu, 'rf32') else centre[k] for k in range(3)]
        off = [x * m[0] + y * m[1] + z * m[2], x * m[3] + y * m[4] + z * m[5], x * m[6] + y * m[7] + z * m[8]]
        for k in range(3):
            emu.wf32(base + id_ * 0x34 + 0xc + 4 * k, A[k] + off[k])
    if r.random() < 0.35:   # exact cases: identity matrix, integer A, D = A + (x, y, z) exactly (qz = 0, qz = +-qy a, the 1e-11 cut)
        m = [1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0]
        A = [float(r.randrange(-100, 100)) for _ in range(3)] if r.random() < 0.5 else [0.0, 0.0, 0.0]
        y, z, a = r.choice(((2.0, 3.0, 1.5), (-2.0, 3.0, 1.5), (0.0, 0.0, 0.0), (3.0, 0.0, 1.0), (-3.0, 0.0, 1.0), (4.0, 1.0, 0.5),
                            (-4.0, 1.0, 0.5), (1.0, 2.0, 2.0), (2.0, 5.0, 1.0), (2.0, 3.0 - 2 ** -10, 1.5), (-2.0, 3.0 - 2 ** -12, 1.5),
                            (0.0, 0.0, 5.0), (2.0, 3.0 - 2 ** -14, 1.5)))
        x = float(r.randrange(-20, 20)) if r.random() < 0.6 else 0.0
        for k in range(3):
            emu.wf32(base + ia * 0x34 + 0xc + 4 * k, A[k])
        for k, v in enumerate((x, y, z)):
            emu.wf32(base + id_ * 0x34 + 0xc + 4 * k, A[k] + v)
        # B and C around A (a proper triangle)
        for k in range(3):
            emu.wf32(base + ib * 0x34 + 0xc + 4 * k, A[k] + (10.0 if k == 0 else 1.0))
            emu.wf32(base + ic * 0x34 + 0xc + 4 * k, A[k] + (10.0 if k == 2 else -2.0))
    if r.random() < 0.05:   # collinear triangle A, B, C (singular solve)
        for k in range(3):
            pa = struct.unpack('<f', bytes(emu.rbytes(base + ia * 0x34 + 0xc + 4 * k, 4)))[0]
            emu.wf32(base + ib * 0x34 + 0xc + 4 * k, pa + 10.0)
            emu.wf32(base + ic * 0x34 + 0xc + 4 * k, pa + 20.0)
    emu.mu.ctl_flush_tb()
    return [ia, ib, ic, id_, fvec(c, m), r.getrandbits(32), F(a), base]


S(0x542ee0, 'AdjustCone6', 'fastcall', ret=None, gen=_gen)
