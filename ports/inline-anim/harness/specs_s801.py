"""specs_s801.py - animation layer thread, batch 801: QuatSlerp, qpul, ZBoneModifyBase::DepackBone."""
import math
import struct
from pilot import S, F, f32
from anim_common import only_hooks, rnd


def _quat(c, unit=0.8):
    r = c.rng
    if r.random() < unit:
        v = [r.gauss(0, 1) for _ in range(4)]
        n = math.sqrt(sum(x * x for x in v)) or 1.0
        return [f32(x / n) for x in v]
    return [c.fv(-2, 2) for _ in range(4)]


def _qbuf(c, q, pad=4):
    a = c.emu.alloc(4 * (len(q) + pad), 4)
    for i, x in enumerate(q + [c.fv() for _ in range(pad)]):
        c.emu.wf32(a + 4 * i, x)
    return a


def _near(c, q):
    """q, nearly q, or nearly -q (to reach the lerp branch, the slerp branch and the opposite branch)."""
    r = c.rng
    k = r.random()
    if k < 0.3:
        return q[:]
    if k < 0.55:
        return [f32(x + r.uniform(-0.05, 0.05)) for x in q]
    if k < 0.75:
        return [f32(-x + r.uniform(-1e-3, 1e-3) * r.choice([0, 1])) for x in q]
    return _quat(c)


def _t(c):
    r = c.rng
    return F(r.choice([r.random(), 0.0, 1.0, 0.5, c.fv(-1, 2)]))


def _slerp(c):
    only_hooks(c, {})
    p = _quat(c)
    a = _qbuf(c, p)
    b = _qbuf(c, _near(c, p))
    k = c.rng.random()
    out = a if k < 0.1 else b if k < 0.2 else _qbuf(c, [c.fv() for _ in range(4)])
    return [a, b, _t(c), out]


def _qpul(c):
    only_hooks(c, {})
    p = _quat(c)
    a = _qbuf(c, p)
    b = _qbuf(c, _near(c, p))
    k = c.rng.random()
    out = a if k < 0.4 else b if k < 0.5 else _qbuf(c, [c.fv() for _ in range(4)])
    return [out, a, b, _t(c)]


def _gfpq_vt(c):
    """ZAnimFileBase stand-in: vt +0xc = GetFramePosQuat(id, bool, pos*, quat*, frame), thiscall ret 0x14.
    Writes a unit quaternion and a position derived from (id, frame) only, so both runs see the same data
    even though the original and the port pass different stack addresses for the second sample."""
    e = c.emu

    def h(e, r):
        aid, flag, pos, quat, fr = (e.arg32(k) for k in range(5))
        heap = lambda p: 'heap' if 0x20000000 <= p < 0x30000000 else 'stack'
        e.calllog.append(('GetFramePosQuat', aid, flag, heap(pos), heap(quat), fr))
        rr = __import__('random').Random(aid * 7919 + fr)
        v = [rr.gauss(0, 1) for _ in range(4)]
        n = math.sqrt(sum(x * x for x in v))
        for i in range(4):
            e.wf32(quat + 4 * i, v[i] / n)
        for i in range(3):
            e.wf32(pos + 4 * i, rr.uniform(-2, 2))
        e.ret(eax=0, argbytes=0x14)
    return e.fake_object('animfile', 0x20, nslots=8, slots={0xc: h})


def _depack(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    now = r.randint(0, 1 << 30)
    clk = rnd(c, 0x60)
    e.w32(clk + 0x40, now)
    e.w32(0x70039c, clk)
    q = _qbuf(c, [c.fv() for _ in range(12)])                  # ZBoneQuat (0x30) + pad
    bb = _qbuf(c, _quat(c) + [c.fv(-3, 3) for _ in range(3)] + [0, 0])
    a = rnd(c, 0x20)
    anim = r.choice([0, 0, r.randint(1, 4), r.randint(1, 4), r.getrandbits(32)])
    e.w32(a + 0, anim)
    e.wf32(a + 4, c.fv(0, 30))
    e.wf32(a + 8, r.choice([0.0, r.uniform(0, 2), c.fv(-1, 3)]))
    e.w32(a + 0xc, r.choice([0, 0, r.randint(1, 4)]))
    e.wf32(a + 0x10, r.choice([r.random(), 0.0, 1.0, c.fv()]))
    e.wf32(a + 0x14, c.fv(0, 30))
    e.w32(a + 0x18, 0 if r.random() < 0.5 else _qbuf(c, _quat(c) + [c.fv(-1, 1) for _ in range(3)]))
    last = r.choice([anim, anim, 0, r.randint(1, 4)])
    e.w32(bb + 0x1c, last)
    e.w32(bb + 0x20, r.choice([now - r.randint(0, 3000), now, 0xfff06000, r.getrandbits(32)]))
    return [r.getrandbits(32), q, bb, _gfpq_vt(c), a]


S(0x4dfb10, 'QuatSlerp (C_QUATSlerp shape, no GC name)', 'fastcall', None, gen=_slerp, note='batch801')
S(0x4df040, 'qpul (quat blend)', 'fastcall', None, gen=_qpul, note='batch801')
S(0x645c90, 'ZBoneModifyBase::DepackBone', 'thiscall', None, gen=_depack, note='batch801')
