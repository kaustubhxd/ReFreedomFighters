"""specs_s809.py - animation layer thread, batch 809: ZLNKOBJ anim-file and bone lookups."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot


def _env(c):
    e, r = c.emu, c.rng
    m = c.bytes_(0x100)
    dv = vt_object(c, 0x20, {0xb4: vslot('defs.LocalBones', 1, ret=0x1111), 0xc4: vslot('defs.BoneDefs', 1, ret=0x2222),
                             0xc8: vslot('defs.BoneMap', 1, ret=m)}, name='defs')
    s = rnd(c, 0x20)
    e.w32(s + 0x18, dv)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x1aa3, s)
    e.w32(0x70039c, g)


def _lnk(c, slots=None):
    e, r = c.emu, c.rng
    n = r.randint(1, 10)
    tab = rnd(c, 0x18 * n + 0x30)
    for i in range(n):
        e.w8(tab + 0x18 * i + 4, r.choice([0, 1, 2, 3, r.getrandbits(8)]))
        e.w32(tab + 0x18 * i + 0x14, 0 if r.random() < 0.3 else rnd(c, 0x20))
    o = vt_object(c, 0x80, slots or {}, nslots=0xd2, name='lnk')
    e.w32(o + 0x1c, tab)
    e.w32(o + 0x20, n)
    e.w32(o + 8, rnd(c, 0x80))
    return o, n


def _setf(c):
    only_hooks(c, {})
    return [_lnk(c)[0], c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _defs(c):
    only_hooks(c, {})
    _env(c)
    return [_lnk(c)[0]]


def _ctl(c):
    only_hooks(c, {})
    o, n = _lnk(c)
    return [o, c.rng.randint(0, n - 1)]


def _name(c):
    only_hooks(c, {})
    o, n = _lnk(c, {0x2cc: vslot('GetBoneDefs', 0, ret=0x30000000)})
    return [o, c.rng.choice([-1, -5, 0, 3, c.rng.getrandbits(32)])]


def _nr(c):
    only_hooks(c, {})
    _env(c)
    r = c.rng
    return [_lnk(c)[0], r.choice([0, r.getrandbits(8), r.getrandbits(32)])]


def _once(c):
    only_hooks(c, {})
    r = c.rng
    o, _ = _lnk(c, {0x23c: vslot('CheckActiveAnim', 2, ret=r.choice([0, 1, 0x100])),
                    0x22c: vslot('ActivateAnim(name)', 2, ret=r.getrandbits(32))})
    return [o, r.getrandbits(32), r.getrandbits(32)]


def _getanim(c):
    only_hooks(c, {})
    e, r = c.emu, c.rng
    o, _ = _lnk(c)
    f1 = vt_object(c, 0x20, {0x18: vslot('file.GetAnim', 1, ret=r.choice([0, r.getrandbits(32)]))})
    f2 = vt_object(c, 0x20, {0x18: vslot('exfile.GetAnim', 1, ret=r.choice([0, 0, r.getrandbits(32)]))})
    e.w32(o + 0x5c, 0 if r.random() < 0.2 else f1)
    e.w32(o + 0x60, 0 if r.random() < 0.3 else f2)
    return [o, r.getrandbits(32)]


S(0x4643e0, 'ZLNKOBJ::SetAnimFile', 'thiscall', None, gen=_setf, note='batch809')
S(0x4646f0, 'ZLNKOBJ::SetExAnimFile', 'thiscall', None, gen=_setf, note='batch809')
S(0x462d60, 'ZLNKOBJ::GetBoneDefinitions', 'thiscall', None, ret='eax', gen=_defs, note='batch809')
S(0x463300, 'ZLNKOBJ::GetOrigLocalBones', 'thiscall', None, ret='eax', gen=_defs, note='batch809')
S(0x462d30, 'ZLNKOBJ::GetBoneControl', 'thiscall', None, ret='eax', gen=_ctl, note='batch809')
S(0x462f50, 'ZLNKOBJ::GetBoneName', 'thiscall', None, ret='eax', gen=_name, note='batch809')
S(0x462f80, 'ZLNKOBJ::GetBoneNrFromId', 'thiscall', None, ret='eax', gen=_nr, note='batch809')
S(0x461210, 'ZLNKOBJ::ActivateAnimOnce', 'thiscall', None, ret='eax', gen=_once, note='batch809')
S(0x462ad0, 'ZLNKOBJ::GetAnim', 'thiscall', None, ret='eax', gen=_getanim, note='batch809')
