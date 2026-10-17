"""specs_s808.py - animation layer thread, batch 808: ZLNKOBJ per-bone table helpers."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot


def _lnk(c, slots=None):
    e, r = c.emu, c.rng
    n = r.randint(0, 10)
    tab = rnd(c, 0x18 * n + 0x30)
    for i in range(n):
        e.w8(tab + 0x18 * i + 4, r.choice([0, 1, 2, 3, r.getrandbits(8)]))
    o = vt_object(c, 0x40, slots or {}, nslots=0xd2, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, n)
    return o, n


def _act(c):
    only_hooks(c, {})
    o, _ = _lnk(c, {0x228: vslot('ActivateAnimSegment', 5, ret=c.rng.getrandbits(32))})
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _chk(c):
    only_hooks(c, {})
    o, _ = _lnk(c, {0x23c: vslot('CheckActiveAnim(name)', 2, ret=c.rng.getrandbits(32))})
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _bone(c):
    only_hooks(c, {})
    o, n = _lnk(c)
    return [o, c.rng.randint(0, max(n - 1, 0))]


def _motion(c):
    only_hooks(c, {})
    r = c.rng
    o, n = _lnk(c, {0x324: vslot('CheckBoneMotion(i)', 1, ret=lambda e, a: r2.choice([0, 0, 0, 0, 1, 0x100]))})
    r2 = __import__('random').Random(r.getrandbits(32))
    return [o]


def _running(c):
    only_hooks(c, {})
    r = c.rng
    o, n = _lnk(c)
    ctl = vt_object(c, 0x10, {0x14: vslot('ctl.14', 0, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    c.emu.w32(o + 0x18, 0 if r.random() < 0.2 else ctl)
    return [o]


def _plain(c):
    only_hooks(c, {})
    return [_lnk(c)[0]]


def _resetall(c):
    only_hooks(c, {})
    return [_lnk(c, {0x340: vslot('EndMatBoneMotion', 2)})[0]]


S(0x4610f0, 'ZLNKOBJ::ActivateAnim(hdr)', 'thiscall', None, ret='eax', gen=_act, note='batch808')
S(0x461970, 'ZLNKOBJ::CheckActiveAnim(hdr)', 'thiscall', None, ret='eax', gen=_chk, note='batch808')
S(0x4619c0, 'ZLNKOBJ::CheckBoneAnimRunning', 'thiscall', None, ret='al', gen=_bone, note='batch808')
S(0x4619e0, 'ZLNKOBJ::CheckBoneMotion(int)', 'thiscall', None, ret='al', gen=_bone, note='batch808')
S(0x461a00, 'ZLNKOBJ::CheckBoneMotion()', 'thiscall', None, ret='al', gen=_motion, note='batch808')
S(0x4634d0, 'ZLNKOBJ::IsAnimationRunning', 'thiscall', None, ret='al', gen=_running, note='batch808')
S(0x463fc0, 'ZLNKOBJ::ResetInactiveBones', 'thiscall', None, gen=_plain, note='batch808')
S(0x463f60, 'ZLNKOBJ::ResetAllAnimBones', 'thiscall', None, gen=_resetall, note='batch808')
