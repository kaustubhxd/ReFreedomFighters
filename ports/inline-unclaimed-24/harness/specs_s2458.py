"""specs_s2458.py - decomp area 24, batch 2458 (gap band).
0x456e30 ZParticleTemplate::Load(ZLoadGame*), thiscall, ret 4, AL = 1: ZGEOM::Load (0x45f3c0, recorder), slot 0x40 of the
load object with this+0xed (recorder), ZParticleTemplate::CreateColorTable (0x455dd0, recorder).
0x448830 ZSPOTLIGHT::CopyData and 0x448880 ZSPOTLIGHTSQUARE::CopyData (const ZGEOM*), thiscall, ret 4: the dword at arg+0x18
is copied to this+0x18; ZGEOM::CopyData (0x45d5b0, recorder); if the byte at (sys table)+0xbad is set, bit 0 (0x448830) or
bit 0 (0x448880) of this+0x14 is set; then slot 0x1e0 of this with 0x800023 (0x448830) or 0x800020 (0x448880). Recorders."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, hook_rec, clear_hooks


def _load(c):
    clear_hooks(c)
    hook_rec(c, 0x45f3c0, 1, this=True)
    hook_rec(c, 0x455dd0, 0, this=True)
    ld = obj(c, 0x40, {0x40: pystub(c, 1)})
    return [rnd(c, 0x100), ld]


def _copy(const):
    def gen(c):
        clear_hooks(c)
        r = c.rng
        e = c.emu
        hook_rec(c, 0x45d5b0, 1, this=True)
        so = sysobj(c, table_size=0xc00)
        tab = e.r32(so + 0x9b)
        e.w8(tab + 0xbad, r.choice([0, 1]))
        o = obj(c, 0x100, {0x1e0: pystub(c, 1)})
        src = rnd(c, 0x40)
        return [o, src]
    return gen


S(0x456e30, 'ZParticleTemplate::Load', 'thiscall', None, ret='al', gen=_load, note='batch2458')
S(0x448830, 'ZSPOTLIGHT::CopyData', 'thiscall', None, ret=None, gen=_copy(0x800023), note='batch2458')
S(0x448880, 'ZSPOTLIGHTSQUARE::CopyData', 'thiscall', None, ret=None, gen=_copy(0x800020), note='batch2458')
