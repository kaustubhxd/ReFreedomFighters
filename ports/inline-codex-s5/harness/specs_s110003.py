"""specs_s839.py - area 50, batch 839: 0x47f490. Helpers 0x478ea0 and 0x478c10 are hooked (deterministic outputs);
the object's virtuals are logged slots; vectors are passed as memory, not as addresses in the log."""
import struct
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot


def _vec_hook(name):
    def h(e, res):
        obj, out, t = e.reg('ecx'), e.arg32(0), e.argf(1)
        e.calllog.append((name, obj, str(round(t, 6)) if t == t else "nan"))   # NaN never equals itself, so log it as text
        for i in range(3):
            v = t * (i + 1) + 0.5 * i
            e.wf32(out + 4 * i, v if abs(v) < 3e38 else 0.0)
        e.ret(eax=0, argbytes=8)
    return h


def _gen(c):
    e, r = c.emu, c.rng
    only_hooks(c, {0x478ea0: _vec_hook('track.478ea0'), 0x478c10: _vec_hook('track.478c10')})
    from recruits_util import pystub
    e.w32(0x7003b0,pystub(c,0,ret=r.getrandbits(32)))
    self = vt_object(c, 0x740, {0x628: vslot('self.vt628', 3), 0x63c: vslot('self.vt63c', 1)}, nslots=0x200, name='self')
    for off in (0x660, 0x664, 0x668, 0x67c, 0x680, 0x684, 0x688):
        e.wf32(self + off, c.fv(-30, 30))
    e.wf32(self + 0x678, c.fv(0, 5))
    e.wf32(self + 0x722, c.fv(-2, 40))
    e.w8(self + 0x6c5, r.choice([0, 1, 3]))
    e.w8(self + 0x72f, r.choice([0, 0, 1]))
    if r.random() < 0.85:
        obj = rnd(c, 0x40)
        e.wf32(obj + 4, r.choice([0.0, c.fv(-10, 60)]))
        e.w32(self + 0x695, obj)
    else:
        e.w32(self + 0x695, 0)
    out = rnd(c, 0x20)
    p = rnd(c, 0x20)
    for i in range(3):
        e.wf32(p + 4 * i, r.choice([c.fv(-30, 30), e.rf32(self + 0x660 + 4 * (0 if i == 0 else 2 if i == 2 else 0))]))
    dt = r.choice([c.fv(0, 3), r.uniform(0, 1), 0.0])
    return [self, out, p, F(dt)]


S(0x47f490, 'area50 0x47f490 (no GC name)', 'thiscall', None, ret='st0', gen=_gen, note='area50 batch839')
