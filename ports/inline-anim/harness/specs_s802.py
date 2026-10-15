"""specs_s802.py - animation layer thread, batch 802: ZBoneModifyBase::GetBoneAnims."""
from pilot import S, F
from anim_common import only_hooks, install_fmod, rnd, vt_object, vslot


def _gba(c):
    only_hooks(c, {})
    install_fmod(c)
    e, r = c.emu, c.rng
    n = r.randint(1, 8)
    self = rnd(c, 0x300)
    e.w32(self + 0x291, r.choice([0, 0, 0, 0, 1, r.getrandbits(32)]))
    e.w8(self + 0x295, r.choice([0, 0, 0, 0, 1]))
    e.w32(self + 0x11, n)
    tab = rnd(c, 0x18 * n + 0x20)
    for i in range(n):
        b = tab + 0x18 * i
        e.w8(b + 4, r.choice([0, 1, 2, 3, 4, 0x80, r.getrandbits(8)]))
        e.w32(b + 0x10, r.choice([0, r.randint(1, 50), r.getrandbits(32)]))
        e.wf32(b + 0, c.fv(0, 60))
        ba = rnd(c, 0x40)
        frames = r.choice([r.randint(1, 120), 0, -3, r.getrandbits(32)])
        e.w32(ba + 0xc, frames)
        tm = c.fv(0, 100)
        e.wf32(ba + 8, tm)
        k = r.random()
        ln = (float(frames if frames < 1 << 31 else frames - (1 << 32)) if k < 0.15 else
              tm + r.uniform(0.01, 5) if k < 0.5 else c.fv(0, 200))
        e.wf32(ba + 0x18, ln)
        e.wf32(ba + 0x20, r.choice([0.0, 1.0 / max(1, frames & 0xff), c.fv(0, 1)]))
        e.w32(b + 0x14, ba)
    obj = vt_object(c, 0x40, {0x2cc: vslot('obj.vt2cc', 0, ret=r.getrandbits(32))}, name='lnk')
    e.w32(obj + 0x1c, tab)
    ab = rnd(c, 0x1d * n + 0x20)
    return [self, obj, ab]


S(0x646220, 'ZBoneModifyBase::GetBoneAnims', 'thiscall', None, gen=_gba, note='batch802')
