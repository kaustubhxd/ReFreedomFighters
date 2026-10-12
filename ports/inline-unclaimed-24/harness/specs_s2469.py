"""specs_s2469.py - decomp area 24, batch 2469 (parked light getters, same shape as batch 2468).
0x449480 ZSPOTLIGHT::GetHotSpotAngle (slot 0x84, float at buf+0x28, buffer 0x38), 0x4494c0 ZOMNILIGHT::GetNearRange (slot 0x80,
float at buf+0x18, buffer 0x24), 0x449500 ZSPOTLIGHT::GetNearRange (slot 0x84, float at buf+0x18, buffer 0x38)."""
from pilot import S, F
from recruits_util import rnd, pystub, obj, sysobj, clear_hooks


def _getter(slot, off):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        val = r.uniform(-3.0, 3.0)
        so = sysobj(c)
        A = obj(c, 0x40, {})
        B = obj(c, 0x40, {slot: pystub(c, 2, stackmark=(1,), side=lambda em, k: em.wf32(em.arg32(1) + off, val))})
        e.w32(so + 0x1aa3, A)
        e.w32(A + 0x18, B)
        geom = rnd(c, 0x80)
        o = rnd(c, 0x40)
        e.w32(o + 8, geom)
        return [o]
    return gen


S(0x449480, 'ZSPOTLIGHT::GetHotSpotAngle', 'thiscall', None, ret='st0', gen=_getter(0x84, 0x28), note='batch2469')
S(0x4494c0, 'ZOMNILIGHT::GetNearRange', 'thiscall', None, ret='st0', gen=_getter(0x80, 0x18), note='batch2469')
S(0x449500, 'ZSPOTLIGHT::GetNearRange', 'thiscall', None, ret='st0', gen=_getter(0x84, 0x18), note='batch2469')
