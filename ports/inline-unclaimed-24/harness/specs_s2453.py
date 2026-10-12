"""specs_s2453.py - decomp area 24, batch 2453 (gap band).
0x442f90 ZTreeGroup::FreeGlobalBounds(), thiscall, plain ret: for the five dwords at +0x5d, a non-null child gets slot 0x28
with 1 (recorder, pops 4), then the dword is cleared.
0x456f50 ZParticleTemplate::Save(ZSaveGame*), thiscall, ret 4, AL = 1: ZGEOM::Save (0x45f960, recorder, the argument), then
slot 0x3c of the save object with the dword at +0xed (recorder).
0x449d40 (GUESS, unnamed constructor): base 0x45c3a0 (recorder, three arguments), vtable 0x67f61c, dwords at +0x18, +0x1c = 0;
ret 12, eax = this."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _fgb(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x80)
    for i in range(5):
        if r.random() < 0.6:
            child = obj(c, 0x40, {0x28: pystub(c, 1)})
            e.w32(o + 0x5d + 4 * i, child)
        else:
            e.w32(o + 0x5d + 4 * i, 0)
    return [o]


def _save(c):
    clear_hooks(c)
    e = c.emu
    hook_rec(c, 0x45f960, 1, this=True)
    sg = obj(c, 0x40, {0x3c: pystub(c, 1)})
    return [rnd(c, 0x100), sg]


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45c3a0, 3, this=True)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


S(0x442f90, 'ZTreeGroup::FreeGlobalBounds', 'thiscall', None, ret=None, gen=_fgb, note='batch2453')
S(0x456f50, 'ZParticleTemplate::Save', 'thiscall', None, ret='al', gen=_save, note='batch2453')
S(0x449d40, 'GUESS: ZGEOM-derived constructor (0x449d40)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2453')
