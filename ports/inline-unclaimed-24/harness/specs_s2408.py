"""specs_s2408.py - decomp area 24, batch 2408: ZSHAPE::CopyDataBlock(DBLK*) (0x44aaf0), thiscall, ret 4.
The callees are the render-GC init (0x610100, a bare `ret 4`, runs as exe code), DBLK::NextBlock (0x4e1b30) and
ZSHAPE::DefineBezierSpline (0x44ab20). The block reader and the spline builder are recorded, not checked here."""
from pilot import S
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    self_ = rnd(c, 0x200)
    dblk = rnd(c, 0x40)
    hook_rec(c, 0x4e1b30, 0, this=True, ret=r.getrandbits(32))
    hook_rec(c, 0x44ab20, 0, this=True)
    return [self_, dblk]


S(0x44aaf0, 'ZSHAPE::CopyDataBlock', 'thiscall', None, ret=None, gen=_gen, note='batch2408')
