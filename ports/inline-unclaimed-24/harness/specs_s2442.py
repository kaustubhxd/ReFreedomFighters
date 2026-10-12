"""specs_s2442.py - decomp area 24, batch 2442 (gap band).
0x44d000 ZMotionBlur::ClassInit(), thiscall, plain ret: SetOwnerDraw(1) on the object at +8 (0x4dcbb0 recorder).
0x444fa0 ZROOM::NotInRoomTree(), thiscall, AL: slot 0x37c of this (recorder), then bit 2 of the result.
0x44a700 ZLIST::Script_GetRefNr(int), thiscall, ret 4: tail jump to slot 0x30 of the object at +0x18 (recorder, one argument).
0x455af0 ZParticleController::CopyDataBlock(DBLK*), thiscall, ret 4: ZRenderGC::Init (0x610100, exe, bare ret 4), then
DBLK::NextBlock (0x4e1b30, recorder).
0x454850 ZTemplate::ClassInit(), thiscall, plain ret: ResetTargets (0x44a1f0, recorder), then a tail jump through the global
pointer at 0x7003b0 (set to a recorder with no arguments; null would be an int3)."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _mb(c):
    clear_hooks(c)
    o = rnd(c, 0x40)
    g = rnd(c, 0x40)
    c.emu.w32(o + 8, g)
    hook_rec(c, 0x4dcbb0, 1, this=True)
    return [o]


def _nir(c):
    clear_hooks(c)
    r = c.rng
    o = obj(c, 0x400, {0x37c: pystub(c, 0, ret=lambda emu, k: r.getrandbits(32))})
    return [o]


def _ref(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    t = obj(c, 0x40, {0x30: pystub(c, 1, ret=lambda emu, k: r.getrandbits(32))})
    e.w32(o + 0x18, t)
    return [o, r.getrandbits(32)]


def _blk(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    return [rnd(c, 0x40), rnd(c, 0x40)]


def _cinit(c):
    clear_hooks(c)
    hook_rec(c, 0x44a1f0, 0, this=True)
    c.emu.w32(0x7003b0, pystub(c, 0, pop=0))
    return [rnd(c, 0x40)]


S(0x44d000, 'ZMotionBlur::ClassInit', 'thiscall', None, ret=None, gen=_mb, note='batch2442')
S(0x444fa0, 'ZROOM::NotInRoomTree', 'thiscall', None, ret='al', gen=_nir, note='batch2442')
S(0x44a700, 'ZLIST::Script_GetRefNr', 'thiscall', None, ret='eax', gen=_ref, note='batch2442')
S(0x455af0, 'ZParticleController::CopyDataBlock', 'thiscall', None, ret='eax', gen=_blk, note='batch2442')
S(0x454850, 'ZTemplate::ClassInit', 'thiscall', None, ret=None, gen=_cinit, note='batch2442')
