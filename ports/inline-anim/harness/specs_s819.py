"""specs_s819.py - animation layer thread, batch 819: ZLNKOBJ / ZBoneModifyBase forwarders."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot, install_logger


def _r(c):
    return c.rng.getrandbits(32)


def _mod(c):
    slots = {0x24: vslot('mod.24', 4, ret=_r(c)), 0x1c: vslot('mod.1c', 3, ret=_r(c)),
             0x14: vslot('mod.14', 4, ret=_r(c)), 0x58: vslot('mod.58', 1, ret=c.fbuf(9))}
    return vt_object(c, 0x300, slots, name='mod')


def _lnk(c):
    e, r = c.emu, c.rng
    o = vt_object(c, 0x100, {0x2ac: vslot('vt2ac', 2), 0x98: vslot('vt98', 2)}, nslots=0xd2, name='lnk')
    e.w32(o + 0x6c, _mod(c))
    g = rnd(c, 0x80)
    e.w16(g + 0x5a, r.choice([0, 0, 1, r.getrandbits(16)]))
    e.w32(o + 8, g)
    return o


def _gen(nargs):
    def g(c):
        only_hooks(c, {0x4db2c0: logged_fn('GetMatPos', 2, ret=0x31), 0x641c90: logged_fn('FixParticle', 2, ret=0x32),
                       0x644400: logged_fn('Ragdoll.Hit', 3)})
        install_logger(c, nargs=2)
        return [_lnk(c)] + [_r(c) for _ in range(nargs)]
    return g


def _bm(c):
    only_hooks(c, {0x644400: logged_fn('Ragdoll.Hit', 3), 0x641c90: logged_fn('FixParticle', 2, ret=0x32)})
    o = rnd(c, 0x300)
    c.emu.w32(o + 0x291, c.rng.choice([0, _r(c)]))
    return [o, _r(c), _r(c), F(c.fv())]


def _matarg(c):
    only_hooks(c, {})
    return [_lnk(c), c.fbuf(9)]


def _bmgbm(c):
    only_hooks(c, {})
    install_logger(c, nargs=3)
    e, r = c.emu, c.rng
    m = c.bytes_(0x100)
    dv = vt_object(c, 0x20, {0xc8: vslot('defs.BoneMap', 1, ret=m)}, name='defs')
    s = rnd(c, 0x20)
    e.w32(s + 0x18, dv)
    g = rnd(c, 0x1b00)
    e.w32(g + 0x1aa3, s)
    e.w32(0x70039c, g)
    self = vt_object(c, 0x300, {0x10: vslot('bm.GetBoneMatPos', 4, ret=r.choice([0, 1, 0x100]))}, name='bm')
    return [self, c.fbuf(9), c.fbuf(3), r.randint(0, 255), _lnk(c)]


S(0x4632c0, 'ZLNKOBJ::GetFocusMatPos', 'thiscall', None, ret='eax', gen=_gen(2), note='batch819')
S(0x6461c0, 'ZBoneModifyBase::FixParticle', 'thiscall', None, ret='eax', gen=_bm, note='batch819')
S(0x462d00, 'ZLNKOBJ::AttachBaseGeomToBone', 'thiscall', None, ret='eax', gen=_gen(4), note='batch819')
S(0x4616b0, 'ZLNKOBJ::GetBoneMatPos', 'thiscall', None, ret='eax', gen=_gen(3), note='batch819')
S(0x464710, 'ZLNKOBJ::SetForcedLODLevel', 'thiscall', None, gen=_gen(1), note='batch819')
S(0x462430, 'ZLNKOBJ::CopyPoseFrom', 'thiscall', None, gen=_gen(1), note='batch819')
S(0x4632d0, 'ZLNKOBJ::GetAttachedBaseGeomBoneId', 'thiscall', None, gen=_matarg, note='batch819')
S(0x462d10, 'ZLNKOBJ::GetAttachedGeomMatPos', 'thiscall', None, ret='eax', gen=_gen(3), note='batch819')
S(0x647140, 'ZBoneModifyBase::HitRagdoll', 'thiscall', None, gen=_bm, note='batch819')
S(0x464730, 'ZLNKOBJ::DetachBaseGeomFromBone', 'thiscall', None, gen=_matarg, note='batch819')
S(0x463320, 'ZLNKOBJ::GetRootFocusMatPos', 'thiscall', None, gen=_gen(2), note='batch819')
S(0x646350, 'ZBoneModifyBase::GetBoneMatPos', 'thiscall', None, gen=_bmgbm, note='batch819')
