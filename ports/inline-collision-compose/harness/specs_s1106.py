"""specs_s1106.py - collision thread batch 1106: 0x4ea390 ZCollisionBox::MovingSphereCollision.
Boxes come from the batch 1103 generator (box array present) or, in 15% of cases, the batch 1105 generator with the
box array unset, so CalcStripsBoundInfo runs first. The rotation is identity half the time. The engine object gets
a dt at +0x48 and a render manager at +0x9b whose slot 0x50 (one arg) is logged."""
import math
import struct
from pilot import S, F
from specs_s1101 import _sys
from specs_s1103 import _fpl
from specs_s1105 import _csbi


def _rot(r):
    if r.random() < 0.5:
        return [1, 0, 0, 0, 1, 0, 0, 0, 1]
    a = r.uniform(-math.pi, math.pi)
    ca, sa = math.cos(a), math.sin(a)
    return [ca, 0, -sa, 0, 1, 0, sa, 0, ca]


def _msc(c):
    e, r = c.emu, c.rng
    use_csbi = r.random() < 0.15
    if use_csbi:
        src = _csbi(c)[0]
        sysobj = e.r32(0x70039c)
        rmgr = e.r32(sysobj + 0x9b)
        o = _sys(c)                       # a random-float vtable for the sphere-segment fallback
        e.w32(sysobj, e.r32(o))
        e.w32(0x70039c, sysobj)
        impact = e.alloc(0x20, 4)
        p = [r.uniform(-10, 10) for _ in range(3)]
        inv = [1.0, 1.0, 1.0]
    else:
        src, impact, _, pv, sv = _fpl(c)
        sysobj = e.alloc(0x200, 4)
        e.w32(sysobj, e.r32(e.r32(0x70039c)))
        e.w32(0x70039c, sysobj)
        rmgr = e.alloc(0x40, 4)
        e.w32(sysobj + 0x9b, rmgr)
        inv = [1.0 / e.rf32(sv + 4 * j) for j in range(3)]
        p = [e.rf32(pv + 4 * j) * inv[j] for j in range(3)]
    e._image_dirty = True
    e.wf32(sysobj + 0x48, r.choice([1 / 30.0, 1 / 60.0, 0.0, r.uniform(0.001, 0.1)]))
    vt = e.logging_vtable('rmgr', 0x54 // 4, impl={0x50: lambda em, a: (c.vars['rh'], None)}, argwords={0x50: 1})
    c.vars['rh'] = r.getrandbits(32)
    e.w32(rmgr, vt)
    this = e.alloc(0x70, 4)
    e.wbytes(this, bytes(e.mu.mem_read(src, 0x18)))
    if use_csbi:
        e.w32(this + 0x14, 0)
        e.wbytes(this + 0x18, bytes(e.mu.mem_read(src + 0x18, 0x30)))
    m = _rot(r)
    if not use_csbi:
        for i in range(9):
            e.wf32(this + 0x18 + 4 * i, m[i])
        for i in range(3):
            e.wf32(this + 0x3c + 4 * i, 0.0 if r.random() < 0.7 else r.uniform(-5, 5))
    for i in range(3):
        e.wf32(this + 0x48 + 4 * i, r.choice([1000.0, 1000.0, r.uniform(1, 40)]))
    e.wf32(this + 0x64, r.choice([0.0, 0.0, 1 / 30.0, r.uniform(0.001, 0.1)]))
    # positions: box space p mapped to world with the rotation (row vector times m) plus the origin
    org = [e.rf32(this + 0x3c + 4 * i) for i in range(3)]
    mm = [e.rf32(this + 0x18 + 4 * i) for i in range(9)]
    world = [p[0] * mm[6 + j] + p[1] * mm[3 + j] + p[2] * mm[j] + org[j] for j in range(3)]
    newp = e.alloc(0x20, 4)
    oldp = e.alloc(0x20, 4)
    for j in range(3):
        e.wf32(newp + 4 * j, world[j])
        e.wf32(oldp + 4 * j, world[j] + r.uniform(-0.5, 0.5))
    ext = e.alloc(0x20, 4)
    for j in range(3):
        e.wf32(ext + 4 * j, inv[j] if r.random() < 0.8 else r.uniform(0.3, 2.0))
    vel = e.alloc(0x20, 4)
    return [this, impact, oldp, newp, ext, vel, r.getrandbits(8)]


S(0x4ea390, 'ZCollisionBox::MovingSphereCollision', 'thiscall', None, ret='al', gen=_msc, note='batch1106')
