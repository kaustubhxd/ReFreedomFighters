"""specs_s2457.py - decomp area 24, batch 2457 (gap band).
0x452990 (GUESS, unnamed constructor): base 0x447640 (recorder, three arguments), vtable 0x681860, +0x18 = 0x3000,
+0x1c and +0x20 = this; ret 12, eax = this.
0x44d040 ZMotionBlur::CopyDataBlock(DBLK*), thiscall, ret 4: ZRenderGC::Init (0x610100, exe, bare ret 4), DBLK::Get into
this+0x470 with count 0x10 (0x4e12e0, recorder, two arguments), DBLK::NextBlock (0x4e1b30, recorder)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _ctor(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x447640, 3, this=True)
    return [rnd(c, 0x100), r.getrandbits(32), r.getrandbits(32), r.getrandbits(32)]


def _blk(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x4e12e0, 2, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    return [rnd(c, 0x500), rnd(c, 0x40)]


S(0x452990, 'GUESS: ZGEOM-derived constructor (0x452990)', 'thiscall', None, ret='eax', gen=_ctor, note='batch2457')
S(0x44d040, 'ZMotionBlur::CopyDataBlock', 'thiscall', None, ret=None, gen=_blk, note='batch2457')
