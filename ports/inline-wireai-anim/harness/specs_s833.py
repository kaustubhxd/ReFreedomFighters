"""specs_s833.py - animation layer thread, batch 833: shadow plane (base and ZIKLNKOBJ) and Load2."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _plane(c, base=False):
    e, r = c.emu, c.rng
    only_hooks(c, {0x461760: logged_fn('ZLNKOBJ::CalcShadowProjectPlane', 3)} if not base else {})
    mod = vt_object(c, 0x40, {0x54: vslot('mod.Plane', 4, ret=r.choice([0, 1]))}, nslots=0x30, name='mod')
    o = vt_object(c, 0x200, {}, nslots=0x30, name='ziklnk')
    e.w32(o + 0x6c, mod)
    out = rnd(c, 0x20)
    return [o, out, r.getrandbits(32), r.getrandbits(32)]


def _load2(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    mgr = vt_object(c, 0x20, {0x25c: vslot('mgr.TrackFlag', 2, ret=r.choice([0, 1, 7]))}, name='mgr')
    g = rnd(c, 0x1b00)
    settings = rnd(c, 0x1000)
    e.w32(settings + 0xadc, mgr)
    e.w32(g + 0x9b, settings)
    e.w32(0x70039c, g)
    blk = rnd(c, 0x800)
    e.w32(0x7003b8, blk)
    return [rnd(c, 0x20)]


S(0x461760, 'ZLNKOBJ::CalcShadowProjectPlane', 'thiscall', None, gen=lambda c: _plane(c, base=True), note='batch833')
S(0x465890, 'ZIKLNKOBJ::CalcShadowProjectPlane', 'thiscall', None, gen=_plane, note='batch833')
S(0x466d90, 'ZIKLNKOBJ::Load2', 'thiscall', None, gen=_load2, note='batch833')
