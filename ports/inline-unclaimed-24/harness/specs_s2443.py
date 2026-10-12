"""specs_s2443.py - decomp area 24, batch 2443 (gap band).
0x443300 ZTreeGroup::GetStaticChildTreeGroupList(ZTreeGroup***) const, thiscall, ret 4: *out = 0; p = [this+0x7b] (null
returns 0); *out = p + 4; the result is the high half of p with the word at p.
0x4493a0 ZLIGHT::Enable(), thiscall, plain ret: SetControl(0, 0x2000) on +8 (recorder), then +0x18 = (+0x18 & ~1) | 8.
0x445140 ZROOM::SetAttachedDrawBaseGeom(ZBaseGeom*), thiscall, ret 4: slot 0x50 of the sys table ([0x70039c]+0x9b) with the
argument (recorder, returns a random dword); the result is stored at +0xc0."""
from pilot import S
from recruits_util import rnd, pystub, obj, sysobj, hook_rec, clear_hooks


def _static(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    if r.random() < 0.7:
        e.w32(o + 0x7b, rnd(c, 0x40))
    else:
        e.w32(o + 0x7b, 0)
    return [o, rnd(c, 0x10)]


def _enable(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(o + 0x18, r.getrandbits(32))
    e.w32(o + 8, rnd(c, 0x40))
    hook_rec(c, 0x4dc630, 2, this=True)
    return [o]


def _attach(c):
    clear_hooks(c)
    r = c.rng
    sysobj(c, table_slots={0x50: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
    return [rnd(c, 0x100), rnd(c, 0x40)]


S(0x443300, 'ZTreeGroup::GetStaticChildTreeGroupList', 'thiscall', None, ret='eax', gen=_static, note='batch2443')
S(0x4493a0, 'ZLIGHT::Enable', 'thiscall', None, ret=None, gen=_enable, note='batch2443')
S(0x445140, 'ZROOM::SetAttachedDrawBaseGeom', 'thiscall', None, ret=None, gen=_attach, note='batch2443')
