"""specs_s2475.py - decomp area 24, batch 2475.
0x44c410 Z2DOBJ::~Z2DOBJ, thiscall, ret 4, eax = this: vtable 0x67ff2c, base 0x43de70 (recorder), then flag bit 0: SetState(this,
0x19) (0x4690b0, recorder, cdecl) when bit 2, else operator delete (0x45c510, recorder, cdecl).
0x4495b0 ZLIGHT::MakeLightUnique, thiscall, plain ret: manager B = [([0x70039c]+0x1aa3)+0x18]; slot 0x18 of B with the geometry's
+0x6c value (recorder, returns a bool-ish value); if that is 0, slot 0x6c of B with (+0x6c, 0) (recorder), then ZBaseGeom::SetPrim
(0x4dcdf0, recorder, one argument) on the light."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, hook_rec, clear_hooks


def _dtor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43de70, 0, this=True)
    hook_rec(c, 0x4690b0, 2, pop=0)
    hook_rec(c, 0x45c510, 1, pop=0)
    return [rnd(c, 0x100), r.getrandbits(32)]


def _unique(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dcdf0, 1, this=True)
    so = sysobj(c)
    A = obj(c, 0x40, {})
    v18 = r.choice([0, 1])
    v6c = r.getrandbits(32)
    B = obj(c, 0x40, {0x18: pystub(c, 1, ret=v18),
                      0x6c: pystub(c, 2, ret=v6c)})
    e.w32(so + 0x1aa3, A)
    e.w32(A + 0x18, B)
    geom = rnd(c, 0x80)
    e.w32(geom + 0x6c, r.getrandbits(32))
    o = rnd(c, 0x40)
    e.w32(o + 8, geom)
    return [o]


S(0x44c410, 'Z2DOBJ::~Z2DOBJ', 'thiscall', None, ret='eax', gen=_dtor, note='batch2475')
S(0x4495b0, 'ZLIGHT::MakeLightUnique', 'thiscall', None, ret=None, gen=_unique, note='batch2475')
