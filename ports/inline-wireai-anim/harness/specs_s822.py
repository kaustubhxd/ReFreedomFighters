"""specs_s822.py - animation layer thread, batch 822: ZLNKOBJ::CalcCenSize with the real base-geom accessors."""
from pilot import S
from anim_common import only_hooks, logged_fn, rnd


def _cen(c):
    # ZBaseGeom::CalcCenSize reads the engine state; it is checked elsewhere, so it is logged here
    only_hooks(c, {0x4da1d0: logged_fn('ZBaseGeom::CalcCenSize', 1)})
    e, r = c.emu, c.rng
    geom = rnd(c, 0x80)
    for off in (0x40, 0x44, 0x48):
        e.wf32(geom + off, r.choice([0.0, 1e-5, c.fv(-3, 40), c.fv(-1, 1)]))
    o = rnd(c, 0x40)
    e.w32(o + 8, geom)
    return [o]


S(0x4616c0, 'ZLNKOBJ::CalcCenSize', 'thiscall', None, gen=_cen, note='batch822')
