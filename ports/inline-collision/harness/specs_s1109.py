"""specs_s1109.py - collision thread batch 1109: 0x4e4aa0 Line2D_VS_AABB, 0x4e4660 CNodeQuad::CheckLinesegmentB.
The segment lives in quantised tree space (0..65536). The per-object callback is a Python stub that logs
(ecx, edx) and returns a per-object al."""
import struct
from pilot import S, F


def _info(c):
    e, r = c.emu, c.rng
    info = e.alloc(0x60, 4)
    e.wbytes(info, bytes(r.getrandbits(8) for _ in range(0x60)))
    s = e.alloc(0x10, 4)
    p0 = [r.uniform(0, 65536) for _ in range(3)]
    d = [r.uniform(-40000, 40000) for _ in range(3)]
    k = r.random()
    if k < 0.15:
        d[0] = 0.0
    elif k < 0.3:
        d[2] = r.choice([0.0, -0.0])
    elif k < 0.38:
        d[0] = 0.0
        d[2] = 0.0
    elif k < 0.4:   # integer start on a grid line, so the range tests hit their edges
        p0 = [float(r.choice([0, 0x4000, 0x8000, 0xc000, 0x10000])) for _ in range(3)]
    for j in range(3):
        e.wf32(s + 4 * j, p0[j])
        e.wf32(info + 0x38 + 4 * j, d[j])
    e.w32(info + 0x30, s)
    if d[0] != 0.0:
        e.wf32(info + 0x44, 1.0 / d[0])
    if d[2] != 0.0:
        e.wf32(info + 0x4c, 1.0 / d[2])
    return info


def _l2d(c):
    r = c.rng
    info = _info(c)
    if r.random() < 0.5:
        x0, z0 = r.choice([0, 0x4000, 0x8000]), r.choice([0, 0x4000, 0x8000])
        sz = r.choice([0x4000, 0x8000])
        box = [float(x0), float(z0), float(x0 + sz), float(z0 + sz)]
    else:
        a, b = sorted([r.uniform(0, 65536), r.uniform(0, 65536)])
        cc, d = sorted([r.uniform(0, 65536), r.uniform(0, 65536)])
        box = [a, cc, b, d]
    if r.random() < 0.15:   # the segment ends exactly on the box's near x edge: t = 1.0 exactly
        L = float(r.choice([0x1000, 0x2000, 0x4000]))
        x0 = float(r.choice([0x4000, 0x8000]))
        box = [x0, 0.0, x0 + 0x4000, 65536.0]
        c.emu.wf32(c.emu.r32(info + 0x30), x0 - L)
        c.emu.wf32(c.emu.r32(info + 0x30) + 8, 1000.0)
        c.emu.wf32(info + 0x38, L)
        c.emu.wf32(info + 0x44, 1.0 / L)
        c.emu.w32(info + 0x40, 0)
    return [info, c.emu.alloc(8, 4)] + [F(v) for v in box]


def _cb(c):
    def h(e, rr):
        o = e.reg('ecx')
        e.calllog.append(('cb', e.reg('ecx'), e.reg('edx')))
        e.ret(eax=c.vars['cbret'].get(o, 0), argbytes=0)
    return c.emu.stub_fn('linecb', h)


def _qt(c):
    e, r = c.emu, c.rng
    info = _info(c)
    e.w32(info + 4, _cb(c))
    c.vars['cbret'] = {}
    stride = 0x20
    nodes = e.alloc(stride * 40, 4)
    pool = e.alloc(0x20, 4)
    e.w32(pool, nodes)
    e.w32(pool + 0xc, stride)
    nxt = [1]

    def mk(depth):
        idx = nxt[0]
        nxt[0] += 1
        n = nodes + stride * idx
        objs = 0
        for _ in range(r.choice([0, 0, 1, 2, 3])):
            o = e.alloc(0x20, 4)
            e.w32(o, objs)
            lo = [r.randint(0, 0xffff) for _ in range(3)]
            hi = [min(0xffff, l + r.randint(0, 0x6000)) for l in lo]
            if r.random() < 0.4:   # whole-space box: always hit, so several callbacks run per node
                lo, hi = [0, 0, 0], [0xffff, 0xffff, 0xffff]
            for j in range(3):
                e.w16(o + 0xc + 2 * j, lo[j])
                e.w16(o + 0x12 + 2 * j, hi[j])
            c.vars['cbret'][o + 8] = r.choice([0, 0, 1, 0x100, 0x1ff])
            objs = o
        e.w32(n + 0xc, objs)
        for k in range(4):
            ch = 0
            if depth < 3 and nxt[0] < 38 and r.random() < 0.5:
                ch = mk(depth + 1)
            e.w16(n + 2 * k, ch)
        return idx
    root = nodes + stride * mk(0)
    return [root, info, pool, 0x10000, 0x8000, 0x8000]


S(0x4e4aa0, 'Line2D_VS_AABB', 'fastcall', None, ret='al', gen=_l2d, note='batch1109')
S(0x4e4660, 'CNodeQuad::CheckLinesegmentB', 'thiscall', None, ret='al', gen=_qt, note='batch1109')


def _cls(c):
    e, r = c.emu, c.rng
    root, info, pool, _, _, _ = _qt(c)
    c.vars['info'] = info
    qt = e.alloc(0x40, 4)
    e.w32(qt, root)
    e.w32(qt + 4, e.r32(pool))
    e.w32(qt + 0x10, e.r32(pool + 0xc))
    sc = r.choice([1.0, 2.0, 0.5, r.uniform(0.2, 4.0)])
    e.wf32(qt + 0x1d, sc)
    org = [r.uniform(-1000, 1000) for _ in range(3)]
    for j in range(3):
        e.wf32(qt + 0x21 + 4 * j, org[j])
    # world points that quantise into 0..65536 (sometimes a vertical or x-only segment)
    f = e.alloc(0x10, 4)
    t = e.alloc(0x10, 4)
    pf = [org[j] + (r.uniform(0, 65536) - 32768) / sc for j in range(3)]
    pt = [org[j] + (r.uniform(0, 65536) - 32768) / sc for j in range(3)]
    k = r.random()
    if k < 0.15:
        pt[0], pt[2] = pf[0], pf[2]
    elif k < 0.3:
        pt[2] = pf[2]
    for j in range(3):
        e.wf32(f + 4 * j, pf[j])
        e.wf32(t + 4 * j, pt[j])
    return [qt, info, f, t]


def _scrub_info(c, heap):
    # info+0x30 / +0x34 point into the caller's stack frame, which differs between the exe and the port
    o = c.vars['info'] - 0x20000000
    return heap[:o + 0x30] + b'\0' * 8 + heap[o + 0x38:]


S(0x4e4520, 'CQuadtree::CheckLinesegment', 'thiscall', None, ret='al', gen=_cls, note='batch1109').scrub = _scrub_info
