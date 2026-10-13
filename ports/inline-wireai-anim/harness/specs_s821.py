"""specs_s821.py - animation layer thread, batch 821: ZMovementBase helpers."""
from pilot import S, F
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _owner(c, slots, flag=None):
    e, r = c.emu, c.rng
    own = vt_object(c, 0x700, slots, nslots=0x180, name='owner')
    return own


def _mv(c, owner):
    e, r = c.emu, c.rng
    m = vt_object(c, 0x40, {}, nslots=1, name='move')
    e.w32(m + 4, owner)
    box = rnd(c, 0x80)
    e.w32(m + 8, box)
    e.w8(m + 0x1c, r.getrandbits(8))
    return m


def _find(c):
    only_hooks(c, {})
    r = c.rng
    own = _owner(c, {0x35c: vslot('owner.FindBestAnim', 1, ret=r.getrandbits(32))})
    nm = c.emu.alloc(0x20, 4)
    c.emu.wbytes(nm, b'Walk\0')
    return [_mv(c, own), nm]


def _settings(c):
    only_hooks(c, {})
    r = c.rng
    own = _owner(c, {0x5e4: vslot('owner.Settings', 1, ret=r.getrandbits(32))})
    return [_mv(c, own), rnd(c, 0x40)]


def _calc(c):
    only_hooks(c, {})
    r = c.rng
    return [rnd(c, 0x40), c.fbuf(3), c.fbuf(3), c.fbuf(3), c.fbuf(3)]


def _msc(c):
    only_hooks(c, {0x4ea390: logged_fn('ZCollisionBox::MovingSphereCollision', 6, ret=lambda e, a: a[0] & 1)})
    r = c.rng
    own = _owner(c, {})
    p = rnd(c, 0x700)
    c.emu.w8(p + 0x5ff, r.choice([0, 1, 1]))
    for off in (0x42d, 0x431, 0x435):
        c.emu.wf32(p + off, c.fv())
    own_p = own
    c.emu.w32(own_p + 4, p)
    m = vt_object(c, 0x40, {}, nslots=1, name='move')
    c.emu.w32(m + 4, p)
    c.emu.w32(m + 8, rnd(c, 0x80))
    c.emu.w8(m + 0x1c, r.getrandbits(8))
    return [m, r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x488490, 'ZMovementBase::FindBestAnim', 'thiscall', None, ret='eax', gen=_find, note='batch821')
S(0x489330, 'ZMovementBase::GetSettingsFromAnim', 'thiscall', None, ret='eax', gen=_settings, note='batch821')
S(0x487c30, 'ZMovementBase::CalcNewSpeed', 'thiscall', None, gen=_calc, note='batch821')
S(0x4883d0, 'ZMovementBase::CheckMovingSphereCollision', 'thiscall', None, ret='al', gen=_msc, note='batch821')
