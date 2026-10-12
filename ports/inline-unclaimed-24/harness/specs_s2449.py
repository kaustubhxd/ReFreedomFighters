"""specs_s2449.py - decomp area 24, batch 2449 (gap band).
0x4548b0 ZTemplate::CopyData(const ZGEOM*) and 0x4559a0 ZParticleController::CopyData: thiscall, ret 4: base copy (0x43f8c0 /
0x45d5b0, recorders, one argument), then slot 0x1e0 of the ARGUMENT (the exe keeps the argument in esi) with a constant (0x1000e9 / 0x2000e4), recorder.
0x443c30 ZTreeGroup::RemoveDynamicGeom(ZBaseGeom*), thiscall, ret 4: when the dword at arg+0x64 is set, slot 0x314 of this
gives the object, then CQuadtree::Delete (0x4e4840, recorder, one argument, the arg+0x64 value).
0x454820 ZTemplate::ClassInit2(), thiscall, plain ret: ResetTargets (0x44a1f0, recorder), the global at 0x7003b0 is called
(recorder, no arguments), then a tail jump through slot 0x28 of this (recorder)."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _copy(base, const):
    def gen(c):
        clear_hooks(c)
        hook_rec(c, base, 1, this=True)
        src = obj(c, 0x40, {0x1e0: pystub(c, 1)})
        return [rnd(c, 0x100), src]
    return gen


def _rm(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x4e4840, 1, this=True)
    o = obj(c, 0x100, {0x314: pystub(c, 0, ret=lambda emu, k: rnd(c, 0x40))})
    g = rnd(c, 0x80)
    e.w32(g + 0x64, r.choice([0, rnd(c, 0x40)]))
    return [o, g]


def _cinit(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x44a1f0, 0, this=True)
    e.w32(0x7003b0, pystub(c, 0, pop=0))
    o = obj(c, 0x100, {0x28: pystub(c, 0)})
    return [o]


S(0x4548b0, 'ZTemplate::CopyData', 'thiscall', None, ret=None, gen=_copy(0x43f8c0, 0x1000e9), note='batch2449')
S(0x4559a0, 'ZParticleController::CopyData', 'thiscall', None, ret=None, gen=_copy(0x45d5b0, 0x2000e4), note='batch2449')
S(0x443c30, 'ZTreeGroup::RemoveDynamicGeom', 'thiscall', None, ret=None, gen=_rm, note='batch2449')
S(0x454820, 'ZTemplate::ClassInit2', 'thiscall', None, ret=None, gen=_cinit, note='batch2449')
