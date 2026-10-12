"""specs_s2459.py - decomp area 24, batch 2459 (gap band): ZInstance::CopyDataBlock(DBLK*), thiscall, ret 4: ZGROUP::CopyDataBlock
(0x43f900, recorder), DBLK::Get into this+0x5c with count 1 (0x4e12e0, recorder), DBLK::NextBlock (0x4e1b30, recorder)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x43f900, 1, this=True)
    hook_rec(c, 0x4e12e0, 2, this=True)
    hook_rec(c, 0x4e1b30, 0, this=True, ret=lambda emu, k: r.getrandbits(32))
    return [rnd(c, 0x100), rnd(c, 0x40)]


S(0x4548e0, 'ZInstance::CopyDataBlock', 'thiscall', None, ret=None, gen=_gen, note='batch2459')
