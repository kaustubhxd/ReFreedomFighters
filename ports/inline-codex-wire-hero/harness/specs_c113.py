"""specs_c113.py - climb thread batch 113: ZMovementBase defaults and folded one-liners in the climb vtables."""
from pilot import S
from ckit import obj, rnd, rvt, floats

_o = lambda c: [rnd(c, 0x40)]
S(0x460e10, 'ZLnkAction::Name', 'thiscall', None, ret='eax', gen=_o, note='c113')
S(0x47fbd0, 'ZLnkAction::GetActionId', 'thiscall', None, ret='eax', gen=_o, note='c113')
S(0x549de0, 'return true (folded)', 'thiscall', None, ret='al', gen=_o, note='c113')
S(0x64fbd0, 'return false (folded)', 'thiscall', None, ret='al', gen=_o, note='c113')
S(0x610100, 'empty, one arg (folded)', 'thiscall', None, ret=None, gen=lambda c: [rnd(c, 0x10), c.rng.getrandbits(32)], note='c113')
S(0x487c30, 'ZMovementBase::CalcNewSpeed', 'thiscall', None, ret=None,
  gen=lambda c: [rnd(c, 0x40), c.fbuf(3), c.fbuf(3), c.fbuf(3), c.fbuf(3)], note='c113')


def _owner(c, slots):
    o = rnd(c, 0x40)
    c.emu.w32(o + 4, obj(c.emu, 'owner', 0xa00, slots, rng=c.rng))
    return o


def _fwd(off):
    def g(c):
        v = c.rng.getrandbits(32)
        return [_owner(c, {off: (1, lambda e, t, a: (v, None, (a[0],)))}), c.rng.getrandbits(32)]
    return g


S(0x488490, 'ZMovementBase::FindBestAnim', 'thiscall', None, ret='eax', gen=_fwd(0x35c), note='c113')
S(0x489330, 'ZMovementBase::GetSettingsFromAnim', 'thiscall', None, ret='eax', gen=_fwd(0x5e4), note='c113')


def _load(c):
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(o, rvt(e, 'move', {0x20: (0, None)}))
    lg = obj(e, 'load', 0x10, {0x50: (1, None)})
    return [o, lg]


S(0x489350, 'ZMovementBase::Load', 'thiscall', None, ret='al', gen=_load, note='c113')
S(0x489d00, 'ZMovementBase::Save', 'thiscall', None, ret='al',
  gen=lambda c: [rnd(c, 0x40), obj(c.emu, 'save', 0x10, {0x4c: (1, None)})], note='c113')


def _mv(c):
    e = c.emu
    o = rnd(c, 0x40)
    v = c.rng.getrandbits(32)
    e.w32(o, rvt(e, 'move', {0x40: (5, None), 0x48: (5, lambda e, t, a: (v, None, None))}))
    return [o] + [c.fbuf(3) for _ in range(5)]


S(0x4893c0, 'ZMovementBaseMove::Move (fall slot 5)', 'thiscall', None, ret='eax', gen=_mv, note='c113')


def _defs(c):
    o = rnd(c, 0x40)
    own = rnd(c, 0x420)
    r = c.rng
    v = r.getrandbits(32) & ~(0x8000000 | 0x400)
    v |= r.choice([0, 0x400, 0x8000000, 0x8000400])
    c.emu.w32(own + 0x417, v)
    c.emu.w32(o + 4, own)
    return [o]


S(0x5e3da0, 'ZFFHeroMovementBaseMove::GetActiveWalkDefsList', 'thiscall', None, ret='eax', gen=_defs, note='c113')
S(0x5e3d60, 'ZFFHeroMovementBaseMove::GetActiveRunDefsList', 'thiscall', None, ret='eax', gen=_defs, note='c113')
