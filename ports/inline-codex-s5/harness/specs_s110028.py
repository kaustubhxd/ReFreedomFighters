"""specs_s801.py - animation layer thread, batch 801: QuatSlerp, qpul, ZBoneModifyBase::DepackBone."""
import math
import struct
from pilot import S, F, f32
from recruits_util import clear_hooks, rnd, pystub
def only_hooks(c, _):
    clear_hooks(c)
    c.emu.w32(0x7003b0,pystub(c,0,ret=c.rng.getrandbits(32)))


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




def gen(c):
    a,b,t,out=_slerp(c)
    return [out,a,b,t]
S(0x4df040,"qpul quaternion blend","fastcall",None,ret=None,gen=gen)
