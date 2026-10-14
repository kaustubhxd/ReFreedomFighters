"""specs_s800.py - animation layer thread, batch 800 (blend-frame entry points)."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, install_logger, vt_object, vslot


def _addframe(c):
    only_hooks(c, {})
    install_logger(c)
    r = c.rng
    o = rnd(c, 0x100)
    c.emu.w32(o + 0x65, r.choice([0, 1, 2, 3, 4, 4, 4, 0, 1, 2, 3]))
    return [o, r.getrandbits(32), r.getrandbits(32), F(c.fv(-50, 50)), F(c.fv(0, 1)), r.getrandbits(32)]


def _hdr(c, lo=-200, hi=400):
    r = c.rng
    h = rnd(c, 0x80)
    for off in (0x5c, 0x60, 0x64, 0x6c):
        v = r.choice([r.randint(lo, hi), r.randint(0, 60), 0, r.getrandbits(32)])
        c.emu.w32(h + off, v)
    return h


def _sbfb(c):
    only_hooks(c, {})
    r = c.rng
    mod = vt_object(c, 0x40, {0x18: vslot('mod.AddFrame', 5)}, name='mod')
    o = vt_object(c, 0x80, {0x288: vslot('GetAnimDeltaBones', 1, ret=lambda e, a: a[0] ^ 0x1234)}, name='lnk')
    c.emu.w32(o + 0x6c, mod)
    hdr = 0 if r.random() < 0.1 else _hdr(c)
    ab = r.choice([0, 1, 0x100, 0xffffff00, r.getrandbits(32)])
    return [o, hdr, F(c.fv(-2, 2)), F(c.fv(0, 1)), ab, r.getrandbits(32)]


def _bm(c, size=0x300):
    r = c.rng
    o = rnd(c, size)
    c.emu.w32(o + 0x291, r.choice([0, 0, 0, 1, r.getrandbits(32)]))
    c.emu.w8(o + 0x295, r.choice([0, 0, 0, 1, r.getrandbits(8)]))
    c.emu.w32(o + 0x11, r.randint(1, 9))
    return o


def _depack(c):
    only_hooks(c, {0x645c90: logged_fn('DepackBone', 4)})
    r = c.rng
    return [_bm(c), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _doanim(c):
    only_hooks(c, {})
    return [_bm(c)]


def _bis(c):
    only_hooks(c, {})
    return [c.rng.getrandbits(32), _hdr(c)]


def _sub(c):
    only_hooks(c, {})
    r = c.rng
    anim = 0 if r.random() < 0.25 else r.getrandbits(32) | 1
    o = vt_object(c, 0x500, {0x5fc: vslot('GetCurrentUBAnim', 0, ret=anim),
                              0x244: vslot('SetBoneFrameBlend', 5)}, name='player')
    c.emu.w8(o + 0x417, r.getrandbits(8))
    return [o, F(c.fv(-2, 2))]


def _shw(c):
    only_hooks(c, {})
    return [rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x645420, 'ZBoneModifyBase::AddFrame', 'thiscall', None, gen=_addframe, note='batch800; logger path when 4 frames')
S(0x464400, 'ZLNKOBJ::SetBoneFrameBlend', 'thiscall', None, gen=_sbfb, note='batch800')
S(0x645c30, 'ZBoneModifyBase::DepackAnimBones', 'thiscall', None, gen=_depack, note='batch800; DepackBone hooked')
S(0x646040, 'ZBoneModifyBase::DoAnimations', 'thiscall', None, ret='al', gen=_doanim, note='batch800')
S(0x487a50, 'ZMovementBase::BlendInSpeed', 'thiscall', None, ret='st0', gen=_bis, note='batch800')
S(0x484ed0, 'ZPlayer::SetActiveUpperBody', 'thiscall', None, gen=_sub, note='batch800')
S(0x47be00, 'ZActor::SetHoldWeaponUBAnim', 'thiscall', None, gen=_shw, note='batch800')
