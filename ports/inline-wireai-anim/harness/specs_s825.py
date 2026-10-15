"""specs_s825.py - animation layer thread, batch 825: ZActor::UpdateBaseMoveFrame (0x47c540), soldier legs layer.
_CIfmod runs as the fprem stand-in (install_fmod); SMoveType::GetAnimHeader (0x478a80) runs as exe code."""
from pilot import S, f32
from anim_common import only_hooks, rnd, vt_object, vslot, install_fmod


def _ubmf(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    install_fmod(c)
    db = rnd(c, 0x60)
    g = rnd(c, 0xa0)
    e.w32(g + 0x9b, db)
    e.w32(0x70039c, g)
    mts = {}

    def mt(e2, a):
        k = a[0]
        if k not in mts:
            if r.random() < 0.12:
                mts[k] = 0
            else:
                m = rnd(c, 0x10)
                if r.random() < 0.15:
                    e2.w32(m, 0)
                mts[k] = m
        return mts[k]

    def flt(e2, a):
        return 0
    o = vt_object(c, 0x800, {0x5a8: vslot('GetMoveType', 1, ret=mt), 0x244: vslot('SetBoneFrameBlend', 5),
                             0x248: vslot('SetDualFrame', 6)}, nslots=0x180, name='actor')
    e.w32(o + 0x650, r.choice([8, 8, 8, r.randint(0, 12), r.getrandbits(32)]))
    e.w8(o + 0x771, 0 if r.random() < 0.85 else r.getrandbits(8) | 1)
    e.wf32(o + 0x755, r.choice([r.uniform(0, 1), r.uniform(-50, 50), float(r.randint(-5, 5)), c.fv(-1e6, 1e6)]))
    tv = r.random()
    if tv < 0.25:
        e.w32(o + 0x76d, r.choice([0, 0x80000000]))
    elif tv < 0.3:
        e.w32(o + 0x76d, 0x7fc00000 | r.getrandbits(22) | (r.getrandbits(1) << 31))
    else:
        e.wf32(o + 0x76d, r.uniform(-2, 2))
    e.wf32(o + 0x769, r.uniform(0, 2))
    return [o]


S(0x47c540, 'ZActor::UpdateBaseMoveFrame', 'thiscall', None, gen=_ubmf, note='batch825')
