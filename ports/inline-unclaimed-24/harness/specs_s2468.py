"""specs_s2468.py - decomp area 24, batch 2468 (parked light getters).
Each getter loads the object at ([sys]+0x1aa3)+0x18 as ecx, passes (the dword at this geom+0x6c, a stack buffer) to a
vtable slot, and returns the float at the buffer's offset on st0. The slot recorder writes that float into the buffer
(side effect), so both runs see the same value. The buffer address is a stack pointer and is recorded as a marker.
0x4493c0 ZSPOTLIGHT::GetFallOffAngle (slot 0x84, float at buf+0x24), 0x449400 ZOMNILIGHT::GetFarRange (slot 0x80, float at
buf+0x1c), 0x449440 ZSPOTLIGHT::GetFarRange (slot 0x84, float at buf+0x1c)."""
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


S(0x4493c0, 'ZSPOTLIGHT::GetFallOffAngle', 'thiscall', None, ret='st0', gen=_getter(0x84, 0x24), note='batch2468')
S(0x449400, 'ZOMNILIGHT::GetFarRange', 'thiscall', None, ret='st0', gen=_getter(0x80, 0x1c), note='batch2468')
S(0x449440, 'ZSPOTLIGHT::GetFarRange', 'thiscall', None, ret='st0', gen=_getter(0x84, 0x1c), note='batch2468')
