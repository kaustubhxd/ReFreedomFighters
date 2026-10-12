"""specs_s2461.py - decomp area 24, batch 2461: ZCredits::CopyData(const ZGEOM*), thiscall, ret 4. Tail jump to ZGEOM::CopyData
(0x45d5b0, recorder, one argument, the caller's argument kept)."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    hook_rec(c, 0x45d5b0, 1, this=True)
    return [rnd(c, 0x100), rnd(c, 0x40)]


S(0x5d5ad0, 'ZCredits::CopyData', 'thiscall', None, ret=None, gen=_gen, note='batch2461')
