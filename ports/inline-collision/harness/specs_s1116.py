"""specs_s1116.py - collision thread batch 1116: quadtree box query 0x4e49f0, 0x4e42d0, 0x4e4420. The tree comes
from the batch 1109 builder; the callback stub logs (ecx, edx)."""
from pilot import S, F
from specs_s1109 import _qt, _cls


def _qbox(c, info):
    e, r = c.emu, c.rng
    lo = [r.randint(-100, 0x10000) for _ in range(3)]
    hi = [l + r.choice([0, 1, 100, 0x2000, 0x8000, 0x10000]) for l in lo]
    if r.random() < 0.3:   # on a quadrant grid line
        g = r.choice([0x4000, 0x8000, 0xc000])
        lo[0], hi[0] = g - r.choice([0, 1, 2]), g + r.choice([0, 1, 0x4000])
    k = r.random()
    if k < 0.2:   # covers every quadrant in x, only part of it in z: recursion and collect-all differ
        lo[0], hi[0] = -0x8000, 0x18000   # child test squares are twice the quadrant (loose quadtree)
        lo[2] = r.randint(0, 0xf000)
        hi[2] = lo[2] + r.randint(1, 0x3000)
    elif k < 0.4:   # bounds equal to an object's box bounds (the strict compares sit on their edge)
        objs = list(c.vars['cbret'].keys())
        if objs:
            o = r.choice(objs) - 8
            bx = [e.mu.mem_read(o + 0xc + 2 * j, 2) for j in range(6)]
            bx = [int.from_bytes(bytes(b), 'little') for b in bx]
            ax = r.randrange(3)
            if r.random() < 0.5:
                hi[ax] = bx[ax]
            else:
                lo[ax] = bx[3 + ax]
    for i in range(3):
        e.w32(info + 0x14 + 4 * i, lo[i])
        e.w32(info + 0x20 + 4 * i, hi[i])


def _cb(c):
    e, r = c.emu, c.rng
    root, info, pool, _, _, _ = _qt(c)
    _qbox(c, info)
    return [root, info, pool, 0, 0x8000, 0x8000]


def _ca(c):
    root, info, pool, _, _, _ = _qt(c)
    return [root, info, pool]


def _qcb(c):
    e, r = c.emu, c.rng
    qt, info, f, t = _cls(c)
    mn = e.alloc(0x10, 4)
    mx = e.alloc(0x10, 4)
    for j in range(3):
        a, b = sorted([e.rf32(f + 4 * j), e.rf32(t + 4 * j)])
        e.wf32(mn + 4 * j, a)
        e.wf32(mx + 4 * j, b if r.random() < 0.8 else a)
    return [qt, info, mn, mx]


S(0x4e49f0, 'CNodeQuad collect all (guessed)', 'thiscall', None, gen=_ca, note='batch1116')
S(0x4e42d0, 'CNodeQuad::CheckBox (guessed)', 'thiscall', None, gen=_cb, note='batch1116')
S(0x4e4420, 'CQuadtree::CheckBox (guessed)', 'thiscall', None, gen=_qcb, note='batch1116')
