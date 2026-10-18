"""specs_s803.py - animation layer thread, batch 803: ZBoneModifyBase::GetBonesFrames.

Everything the function touches is built on the fake heap: the layer list, the object's per-bone anim table
(read by GetBoneAnims, which runs as exe code), a file object whose bone-count / bone-anim / bone-id slots are
deterministic functions of their arguments, the engine object at [0x70039c] (clock +0x40, +0x9b, +0x1aa3), the
head-look clip, matrices and the target. DepackBone and the vector helpers run as exe code."""
import math
from pilot import S, F, f32
from anim_common import only_hooks, rnd, vt_object, vslot, install_memset, install_fmod


def _fbuf(c, vals):
    a = c.emu.alloc(4 * len(vals) + 16, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(a + 4 * i, v)
    return a


def _unitq(c):
    v = [c.rng.gauss(0, 1) for _ in range(4)]
    n = math.sqrt(sum(x * x for x in v)) or 1
    return [f32(x / n) for x in v]


def _rot(c):
    """A random 3x3 rotation (from a quaternion) as 9 floats."""
    w, x, y, z = _unitq(c)
    return [1 - 2 * (y * y + z * z), 2 * (x * y - z * w), 2 * (x * z + y * w),
            2 * (x * y + z * w), 1 - 2 * (x * x + z * z), 2 * (y * z - x * w),
            2 * (x * z - y * w), 2 * (y * z + x * w), 1 - 2 * (x * x + y * y)]


def _file(c, nbones_of):
    e = c.emu

    def cnt(e, r):
        h = e.arg32(0)
        e.calllog.append(('Count', h))
        e.ret(eax=nbones_of(h), argbytes=4)

    def gba(e, r):
        h, j = e.arg32(0), e.arg32(1)
        e.calllog.append(('GetBoneAnim', h, j))
        e.ret(eax=(h * 0x9e3779b1 + j * 0x85ebca6b) & 0xffffffff, argbytes=8)

    def gid(e, r):
        b = e.arg32(0)
        e.calllog.append(('GetBoneId', b))
        e.ret(eax=0xcccccc00 | ((b >> 7) ^ (b >> 19)) & 0xff, argbytes=4)

    def gfpq(e, r):
        aid, flag, pos, quat, fr = (e.arg32(k) for k in range(5))
        e.calllog.append(('GetFramePosQuat', aid, flag, fr))
        rr = __import__('random').Random(aid * 7919 + fr)
        v = [rr.gauss(0, 1) for _ in range(4)]
        n = math.sqrt(sum(x * x for x in v))
        for i in range(4):
            e.wf32(quat + 4 * i, v[i] / n)
        for i in range(3):
            e.wf32(pos + 4 * i, rr.uniform(-20, 20))
        e.ret(eax=0, argbytes=0x14)
    return e.fake_object('file', 0x20, nslots=0x10, slots={0xc: gfpq, 0x24: cnt, 0x2c: gba, 0x3c: gid})


def _gbf(c):
    only_hooks(c, {})
    install_memset(c)
    install_fmod(c)
    e, r = c.emu, c.rng
    n = r.randint(2, 12)                       # bones of the object
    # engine object at [0x70039c]
    now = r.randint(0, 1 << 28)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x40, now)
    e.w32(0x70039c, g)
    cc = vt_object(c, 0x10, {0xb8: vslot('cc.b8', 0, ret=r.choice([0, 1, 0x100, 0xff]))}, name='cc')
    e.w32(g + 0x9b, cc)
    r1 = _fbuf(c, [c.fv() for _ in range(9)] + _rot(c) + [c.fv() for _ in range(3)])
    map2 = c.bytes_(0x100)
    for i in range(0x100):
        e.w8(map2 + i, r.choice([0, 0xff, r.randint(1, n - 1), r.randint(1, n - 1), r.randint(1, n - 1)]))
    r3 = _fbuf(c, [c.fv() for _ in range(7)] + _unitq(c) + [0.0] * 4)
    sub = vt_object(c, 0x20, {0xc0: vslot('sub.c0', 1, ret=r1), 0xc8: vslot('sub.c8', 1, ret=map2),
                              0xb8: vslot('sub.b8', 1, ret=r3)}, name='sub')
    s18 = rnd(c, 0x20)
    e.w32(s18 + 0x18, sub)
    e.w32(g + 0x1aa3, s18)
    # self
    self = rnd(c, 0x300)
    e.w32(self + 0x291, r.choice([0] * 12 + [1]))
    e.w8(self + 0x295, r.choice([0] * 12 + [1]))
    e.w32(self + 0x11, n)
    nl = r.choice([0, 1, 2, 3, 4, 4])
    hdrs = []
    for i in range(nl):
        L = self + 0x15 + 0x14 * i
        h = r.getrandbits(32) & ~0xff | 0x10
        hdrs.append(h)
        e.w32(L, h)
        e.w32(L + 4, 0 if r.random() < 0.3 else _fbuf(c, [c.fv(-1, 1) for _ in range(7 * n + 8)]))
        e.wf32(L + 8, c.fv(0, 60))
        e.wf32(L + 0xc, c.fv(0, 1))
        fl = r.choice([0, 0, 1, 4, 5, r.getrandbits(8)])
        if i == nl - 1:
            fl &= ~4
        e.w8(L + 0x10, fl)
    e.w32(self + 0x65, nl)
    for off in (0x22d, 0x23d, 0x24d):
        e.wf32(self + off, r.choice([0.0, c.fv(0, 1)]))
    e.wf32(self + 0x251, r.choice([0.0, 0.0, c.fv(0, 1), 1.0]))
    e.wf32(self + 0x255, c.fv(0, 1))
    tgt = [c.fv(-300, 300) for _ in range(3)]
    if r.random() < 0.1:
        tgt = [0.0, 0.0, 0.0]
    for i, v in enumerate(tgt):
        e.wf32(self + 0x259 + 4 * i, v)
    e.w8(self + 0x265, r.choice([0, 0, 0, 1]))
    # head-look clip
    hl = 0 if r.random() < 0.15 else rnd(c, 0x80)
    if hl:
        e.w8(hl + 0x7c, r.choice([0x10, 0, r.getrandbits(8)]))
    nbmap = {}

    def nbones_of(h):
        if h not in nbmap:
            nbmap[h] = (h >> 9) % 7 if (h >> 3) % 5 else 0
        return nbmap[h]
    f = _file(c, nbones_of)
    # object (ZLNKOBJ): per-bone anim table for GetBoneAnims
    tab = rnd(c, 0x18 * n + 0x20)
    for i in range(n):
        b = tab + 0x18 * i
        e.w8(b + 4, r.choice([0, 0, 0, 1, 3]))
        e.w32(b + 0x10, r.choice([0, r.randint(1, 50)]))
        e.wf32(b + 0, c.fv(0, 60))
        e.w32(b + 0xc, 0 if r.random() < 0.6 else _fbuf(c, _unitq(c) + [c.fv(-1, 1) for _ in range(3)]))
        ba = rnd(c, 0x40)
        e.w32(ba + 0xc, r.randint(1, 100))
        e.wf32(ba + 8, c.fv(0, 100))
        e.wf32(ba + 0x18, c.fv(0, 100))
        e.wf32(ba + 0x20, c.fv(0, 1))
        e.wf32(ba + 0x2c, c.fv(0, 1))
        e.w32(b + 0x14, ba)
    delta = 0 if r.random() < 0.3 else _fbuf(c, [c.fv(-1, 1) for _ in range(7 * n + 8)])
    o8 = rnd(c, 0x80)
    obj = vt_object(c, 0x40, {0x2cc: vslot('obj.2cc', 0), 0x2fc: vslot('obj.2fc', 0, ret=r.choice([0] * 9 + [1])),
                              0x498: vslot('obj.498', 0, ret=hl), 0x49c: vslot('obj.49c', 0, ret=r.choice([0, 1, 0x200])),
                              0x288: vslot('obj.288', 1, ret=delta)}, name='obj')
    e.w32(obj + 0x1c, tab)
    e.w32(obj + 8, o8)
    bmap = c.bytes_(0x100)
    for i in range(0x100):
        e.w8(bmap + i, r.choice([0, 0xff, r.randint(1, n - 1), r.randint(1, n - 1)]))
    bb = _fbuf(c, sum([_unitq(c) + [c.fv(-5, 5) for _ in range(3)] + [0, 0] for _ in range(n)], []))
    for i in range(n):
        e.w32(bb + 0x24 * i + 0x1c, r.choice([0, r.randint(1, 50)]))
        e.w32(bb + 0x24 * i + 0x20, now - r.randint(0, 2000))
    ab = rnd(c, 0x1d * n + 0x40)
    bones = _fbuf(c, _rot(c) + [c.fv(-100, 100) for _ in range(3)] + [c.fv() for _ in range(4)])
    return [self, f, bmap, bb, ab, obj, bones]


S(0x646430, 'ZBoneModifyBase::GetBonesFrames', 'thiscall', None, gen=_gbf, note='batch803')
