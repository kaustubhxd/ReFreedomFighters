"""specs_s835.py - animation layer thread, batch 835: ZIKLNKOBJ UpdateTargets and HitRagdoll forwarder."""
from pilot import S, F
from anim_common import only_hooks, rnd, vt_object, vslot


def _ut(c):
    only_hooks(c, {})
    o = vt_object(c, 0x200, {0x408: vslot('vt408', 0), 0x404: vslot('vt404', 0), 0x40c: vslot('vt40c', 0)},
                  nslots=0x110, name='ziklnk')
    return [o]


def _hr(c):
    e, r = c.emu, c.rng
    only_hooks(c, {})
    mod = vt_object(c, 0x40, {0x3c: vslot('mod.HitRagdoll', 3)}, nslots=0x30, name='mod')
    o = vt_object(c, 0x200, {}, nslots=0x30, name='ziklnk')
    e.w32(o + 0x6c, mod)
    return [o, rnd(c, 0x20), rnd(c, 0x20), F(c.fv(-3, 3))]


S(0x467f60, 'ZIKLNKOBJ::UpdateTargets', 'thiscall', None, gen=_ut, note='batch835')
S(0x466c10, 'ZIKLNKOBJ::HitRagdoll', 'thiscall', None, gen=_hr, note='batch835')
