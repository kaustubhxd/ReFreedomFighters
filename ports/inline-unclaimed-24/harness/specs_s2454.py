"""specs_s2454.py - decomp area 24, batch 2454 (gap band).
0x459c10 ZBoneParticle::Load(ZLoadGame*), thiscall, ret 4, AL: ZGEOM::Load (0x45f3c0, recorder, returns AL); if it is set,
slot 0x154 of this (recorder) and AL = 1; else AL = 0.
0x454920 ZInstance::Load(ZLoadGame*), thiscall, ret 4, AL = 1: ZGROUP::Load (0x440e10, recorder), then slot 0x40 of the load
object with this+0x5c (recorder).
0x448a00 ZGateLightMaster::CopyDataBlock(DBLK*), thiscall, ret 4: ZLIGHT::CopyDataBlock (0x448a30, recorder), DBLK::NextBlock
(0x4e1b30, recorder), DBLK::Get(REFTAB* = this+0x1c) (0x4e0fd0, recorder), DBLK::NextBlock again."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks


def _bone(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x45f3c0, 1, this=True, ret=lambda emu, k: r.choice([0, 1]))
    o = obj(c, 0x100, {0x154: pystub(c, 0)})
    return [o, rnd(c, 0x40)]


def _inst(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x440e10, 1, this=True)
    ld = obj(c, 0x40, {0x40: pystub(c, 1)})
    return [rnd(c, 0x100), ld]


def _gate(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x448a30, 1, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    hook_rec(c, 0x4e0fd0, 1, this=True)
    return [rnd(c, 0x100), rnd(c, 0x40)]


S(0x459c10, 'ZBoneParticle::Load', 'thiscall', None, ret='al', gen=_bone, note='batch2454')
S(0x454920, 'ZInstance::Load', 'thiscall', None, ret='al', gen=_inst, note='batch2454')
S(0x448a00, 'ZGateLightMaster::CopyDataBlock', 'thiscall', None, ret=None, gen=_gate, note='batch2454')
