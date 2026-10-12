"""specs_s2472.py - decomp area 24, batch 2472 (local-pointer rows).
0x4528c0 ZDebugGeom::CopyDataBlock(DBLK*), thiscall, ret 4: ZRenderGC::Init (0x610100, exe), DBLK::Get(&local, 1) (0x4e11e0,
recorder; the local's address is a stack pointer, recorded as a marker), DBLK::NextBlock (0x4e1b30, recorder).
0x455790 ZParticleTemplate::ClassInit2(), thiscall, plain ret: ZGEOM::ClassInit2 (0x45d3a0, recorder), then
GetController(&local, this+0xed) (0x456b70, recorder; the local is a stack pointer)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _blk(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e11e0, 2, this=True, stackmark=(0,))
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    return [rnd(c, 0x100), rnd(c, 0x40)]


def _ctl(c):
    clear_hooks(c)
    hook_rec(c, 0x45d3a0, 0, this=True)
    hook_rec(c, 0x456b70, 2, this=True, stackmark=(0,))
    return [rnd(c, 0x200)]


S(0x4528c0, 'ZDebugGeom::CopyDataBlock', 'thiscall', None, ret=None, gen=_blk, note='batch2472')
S(0x455790, 'ZParticleTemplate::ClassInit2', 'thiscall', None, ret=None, gen=_ctl, note='batch2472')
