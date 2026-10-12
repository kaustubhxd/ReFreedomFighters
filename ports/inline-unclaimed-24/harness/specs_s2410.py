"""specs_s2410.py - decomp area 24, batch 2410: CCivilianPath::CopyEventDataBlock(DBREAD&) (0x5bdc70), thiscall, ret 4.
The DBREAD readers (0x4e5e60 u32, 0x4e5e80 float on st0, 0x4e5ef0 bool) are recorders with a fresh random value per
call (the u32 and bool recorders return a callable's value, the float recorder one st0 value per case)."""
from pilot import S, F
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    self_ = rnd(c, 0x100)
    db = rnd(c, 0x40)
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda e, a: r.getrandbits(32))
    hook_rec(c, 0x4e5e80, 0, this=True, st0=F(r.uniform(-1000.0, 1000.0)))
    hook_rec(c, 0x4e5ef0, 0, this=True, ret=lambda e, a: r.getrandbits(32))
    return [self_, db]


S(0x5bdc70, 'CCivilianPath::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_gen, note='batch2410')
