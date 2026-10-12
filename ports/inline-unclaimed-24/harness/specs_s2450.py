"""specs_s2450.py - decomp area 24, batch 2450 (gap band).
0x45e540 ZGEOM::FreeEvent(char*), thiscall, ret 4: slot 0x100 of this with the argument (recorder, callee pops 4); if the
result is nonzero, slot 0x148 of this with it (recorder, callee pops 4).
0x442c00 ZTreeGroup::CopyData(const ZGEOM*), thiscall, ret 4: slot 0x1e0 of the ARGUMENT with 0x100020 (recorder), then
ZGROUP::CopyData (0x43f8c0, recorder) on this with the argument."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _fe(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x100, {0x100: pystub(c, 1, ret=lambda emu, k: r.choice([0, rnd(c, 0x20)])),
                       0x148: pystub(c, 1)})
    return [o, rnd(c, 0x20)]


def _tg(c):
    clear_hooks(c)
    hook_rec(c, 0x43f8c0, 1, this=True)
    src = obj(c, 0x40, {0x1e0: pystub(c, 1)})
    return [rnd(c, 0x100), src]


S(0x45e540, 'ZGEOM::FreeEvent', 'thiscall', None, ret=None, gen=_fe, note='batch2450')
S(0x442c00, 'ZTreeGroup::CopyData', 'thiscall', None, ret=None, gen=_tg, note='batch2450')
