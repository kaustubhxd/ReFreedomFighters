"""specs_s834.py - animation layer thread, batch 834: ZIKLNKOBJ DisableFacing, GetFocalPoint, CopyGeometryFrom."""
from pilot import S, f32
from anim_common import only_hooks, logged_fn, rnd, vt_object, vslot


def _obj(c, slots=None):
    e, r = c.emu, c.rng
    o = vt_object(c, 0x200, slots or {}, nslots=0x140, name='ziklnk')
    e.w8(o + 0x158, r.getrandbits(8))
    e.wf32(o + 0x1ca, r.choice([0.0, c.fv(-5, 5)]))
    return o


def _df(c):
    only_hooks(c, {})
    return [_obj(c, {0x3c8: vslot('vt3c8', 5)})]


def _gfp(c):
    only_hooks(c, {})
    o = _obj(c, {0x84: vslot('vt84', 1)})
    return [o, rnd(c, 0x10)]


def _cgf(c):
    only_hooks(c, {0x4620d0: logged_fn('ZLNKOBJ::CopyGeometryFrom', 1)})
    o = _obj(c, {0x32c: vslot('vt32c', 1)})
    return [o, rnd(c, 0x40)]


S(0x466420, 'ZIKLNKOBJ::DisableFacing', 'thiscall', None, gen=_df, note='batch834')
S(0x466800, 'ZIKLNKOBJ::GetFocalPoint', 'thiscall', None, gen=_gfp, note='batch834')
S(0x466360, 'ZIKLNKOBJ::CopyGeometryFrom', 'thiscall', None, gen=_cgf, note='batch834')
