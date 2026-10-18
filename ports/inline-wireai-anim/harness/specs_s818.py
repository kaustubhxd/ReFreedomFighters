"""specs_s818.py - animation layer thread, batch 818: SafeAcos, ZBoneModifyBase::UpdateLocalIK (head aim IK)."""
import math
from pilot import S, F, f32
from anim_common import only_hooks, rnd, vt_object, vslot


def _sacos(c):
    only_hooks(c, {})
    return [F(c.rng.choice([c.fv(-1, 1), c.fv(-2, 2), 1.0, -1.0]))]


def _unitq(c):
    v = [c.rng.gauss(0, 1) for _ in range(4)]
    n = math.sqrt(sum(x * x for x in v)) or 1
    return [f32(x / n) for x in v]


def _rot(c):
    w, x, y, z = _unitq(c)
    return [1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w),
            2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w),
            2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]


def _buf(c, vals, pad=16):
    a = c.emu.alloc(4 * len(vals) + pad, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)
    return a


def _ulik(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    n = r.randint(3, 24)
    # q: bone 0 as a matrix + pos (SolveBoneChain copies it as a matrix), others quaternion + pos
    qv = _rot(c) + [c.fv(-5, 5) for _ in range(3)]
    for i in range(1, n):
        qv += _unitq(c) + [c.fv(-1, 1) for _ in range(5)] + [c.fv(-20, 20) for _ in range(3)]
    q = _buf(c, qv)
    bdefs = rnd(c, 0x30 * n + 0x40)
    for i in range(n):
        e.w32(bdefs + 0x30 * i + 0xc, r.randint(0, i - 1) if i > 0 else 0)
    mats = _buf(c, sum([_rot(c) for _ in range(n)], []))
    m = c.bytes_(0x40)
    for k in (0xc, 0x16, 0x17):
        e.w8(m + k, r.randint(1, n - 1))
    r3 = _buf(c, [c.fv() for _ in range(7)] + _unitq(c))
    dv = vt_object(c, 0x20, {0xb8: vslot('defs.b8', 1, ret=r3), 0xc8: vslot('defs.BoneMap', 1, ret=m),
                             0xc0: vslot('defs.Mats', 1, ret=mats)}, name='defs')
    s = rnd(c, 0x20)
    e.w32(s + 0x18, dv)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x1aa3, s)
    e.wf32(g + 0x48, r.choice([0.033, 0.016, c.fv(0, 0.2)]))
    e.w32(0x70039c, g)
    obj = vt_object(c, 0x500, {0x49c: vslot('obj.49c', 0, ret=r.choice([0, 1])),
                               0x2cc: vslot('obj.BoneDefs', 0, ret=bdefs)}, name='obj')
    e.w32(obj + 0x417, r.choice([0, 0x400, r.getrandbits(32)]))
    self = rnd(c, 0x300)
    e.w8(self + 4, r.choice([0, 1, 1]))
    e.wf32(self + 0x22d, r.choice([0.0, 1.0, 1.0, r.random(), c.fv(0, 1)]))
    e.wf32(self + 0x251, r.choice([0.0, 0.0, r.random()]))
    for i in range(3):
        e.wf32(self + 0x231 + 4 * i, c.fv(-200, 200))
    sm = r.random()
    for i in range(3):
        e.wf32(self + 0x241 + 4 * i, 0.0 if sm < 0.3 else c.fv(-1, 1))
    return [self, q, r.getrandbits(32), obj]


S(0x477620, 'SafeAcos (no GC name)', 'stdcall', None, ret='st0', gen=_sacos, note='batch818')
S(0x647870, 'ZBoneModifyBase::UpdateLocalIK', 'thiscall', None, gen=_ulik, note='batch818')
