"""specs_s2441.py - decomp area 24, batch 2441 (gap band).
0x450ed0 ZCloth::Load2(), thiscall, plain ret: ZGEOM::Load2 (0x45f3a0, recorder, no arguments), then ZCloth::Initialize
(0x450980, recorder, one argument 0).
0x44c500 Z2DOBJ::CopyData(const ZGEOM*), thiscall, ret 4: when the dword at (arg+0xc)+0x23 is 0x20000b the byte at arg+0x18 is
copied to this+0x18; then ZGEOM::CopyData (0x45d5b0, recorder, one argument) with the same argument.
0x44c160 ZSNDOBJ::ModifyGeomCon(int, int), thiscall, ret 8: SetControl(0, 0x38003) on the object at +8 (0x4dc630 recorder).
0x448f40 ZLIGHT::Disable(), thiscall, plain ret: SetControl(0x2000, 0) on the object at +8, then +0x18 |= 9."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _load2(c):
    clear_hooks(c)
    hook_rec(c, 0x45f3a0, 0, this=True)
    hook_rec(c, 0x450980, 1, this=True)
    return [rnd(c, 0x200)]


def _copy(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x45d5b0, 1, this=True)
    arg = rnd(c, 0x40)
    sub = rnd(c, 0x40)
    e.w32(sub + 0x23, 0x20000b if r.random() < 0.6 else r.getrandbits(32))
    e.w32(arg + 0xc, sub)
    return [rnd(c, 0x40), arg]


def _geom(c, addr_sc):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4dc630, 2, this=True)
    o = rnd(c, 0x40)
    e.w32(o + 8, rnd(c, 0x40))
    return [o] + ([r.getrandbits(32), r.getrandbits(32)] if addr_sc else [])


def _modify(c):
    return _geom(c, True)


def _disable(c):
    return _geom(c, False)


S(0x450ed0, 'ZCloth::Load2', 'thiscall', None, ret=None, gen=_load2, note='batch2441')
S(0x44c500, 'Z2DOBJ::CopyData', 'thiscall', None, ret=None, gen=_copy, note='batch2441')
S(0x44c160, 'ZSNDOBJ::ModifyGeomCon', 'thiscall', None, ret=None, gen=_modify, note='batch2441')
S(0x448f40, 'ZLIGHT::Disable', 'thiscall', None, ret=None, gen=_disable, note='batch2441')
