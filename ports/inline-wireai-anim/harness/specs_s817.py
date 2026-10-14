"""specs_s817.py - animation layer thread, batch 817: GetFrameTime, SetLocalIKBone, SolveBoneChain, UpdateGlobalIK."""
import math
from pilot import S, F, f32
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot, install_fmod, install_crt_str


def _gft(c):
    only_hooks(c, {})
    install_fmod(c)
    r = c.rng
    ba = rnd(c, 0x10)
    n = r.choice([1, 10, 30, 0, r.randint(0, 200)])
    c.emu.w16(ba + 8, n)
    return [rnd(c, 0x10), ba, r.choice([0, 1, 0x100]), F(r.choice([r.uniform(-5, n + 20), c.fv(-50, 300)]))]


def _rot(c):
    v = [c.rng.gauss(0, 1) for _ in range(4)]
    n = math.sqrt(sum(x * x for x in v)) or 1
    w, x, y, z = [a / n for a in v]
    return [1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w),
            2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w),
            2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]


def _bones(c, n):
    vals = []
    for i in range(n):
        vals += _rot(c) + [c.fv(-50, 50) for _ in range(3)]
    a = c.emu.alloc(0x30 * n + 0x40, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)
    return a


def _defs(c, n, chain=True):
    e, r = c.emu, c.rng
    d = rnd(c, 0x30 * n + 0x40)
    for i in range(n):
        e.w32(d + 0x30 * i + 0xc, r.randint(0, i - 1) if i > 0 else 0)
    return d


def _slib(c):
    only_hooks(c, {})
    r = c.rng
    n = r.randint(2, 10)
    q = c.fbuf(12 * n + 4)
    mats = _bones(c, n)
    tgt = c.fbuf(9)
    pos = c.fbuf(3)
    return [r.getrandbits(32), q, _bones(c, n), mats, _defs(c, n), r.randint(0, n - 1), tgt, pos]


def _solve(c):
    only_hooks(c, {})
    r = c.rng
    n = r.randint(2, 12)
    qv = []
    for i in range(n):
        v = [r.gauss(0, 1) for _ in range(4)]
        m = math.sqrt(sum(x * x for x in v))
        qv += [x / m for x in v] + [c.fv(-1, 1) for _ in range(5)] + [c.fv(-20, 20) for _ in range(3)]
    q = c.emu.alloc(0x30 * n + 0x40, 4)
    for i, v in enumerate(qv):
        c.emu.wf32(q + 4 * i, v)
    return [r.getrandbits(32), _bones(c, n), r.randint(0, n - 1), q, _defs(c, n)]


def _ugik(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x6421a0: logged_fn('Ragdoll.Pose', 1)})
    install_crt_str(c)
    n = 0x14
    bones = _bones(c, n)
    m = c.bytes_(0x40)
    e.w8(m + 0xe, r.randint(0, n - 1))
    e.w8(m + 0x12, r.randint(0, n - 1))
    dv = vt_object(c, 0x20, {0xc8: vslot('defs.BoneMap', 1, ret=m)}, name='defs')
    s = rnd(c, 0x20)
    e.w32(s + 0x18, dv)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x1aa3, s)
    e.w32(0x70039c, g)
    nm = e.alloc(0x10, 4)
    e.wbytes(nm, r.choice([b'Hitman2', b'hitman2', b'Hero', b'Soldier_01']) + b'\0')
    obj = vt_object(c, 0x40, {0x49c: vslot('obj.49c', 0, ret=r.choice([0, 1, 1])),
                              0x2fc: vslot('obj.2fc', 0, ret=r.choice([0, 0, 1])),
                              0x2e0: vslot('obj.GetName', 0, ret=nm)}, name='obj')
    self = rnd(c, 0x300)
    e.w32(self + 0x291, r.choice([0, 0, 0, r.getrandbits(32) | 1]))
    e.w8(self + 0x295, r.choice([0, 0, 0, 1]))
    e.w8(self + 4, r.choice([0, 1, 1]))
    return [self, bones, r.getrandbits(32), obj]


S(0x4e59b0, 'ZAnimFilePack::GetFrameTime', 'thiscall', None, ret='st0', gen=_gft, note='batch817')
S(0x647430, 'ZBoneModifyBase::SetLocalIKBone', 'thiscall', None, gen=_slib, note='batch817')
S(0x6474f0, 'ZBoneModifyBase::SolveBoneChain', 'thiscall', None, gen=_solve, note='batch817')
S(0x647790, 'ZBoneModifyBase::UpdateGlobalIK', 'thiscall', None, gen=_ugik, note='batch817')
