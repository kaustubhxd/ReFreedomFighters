"""specs_s2411.py - decomp area 24, batch 2411: ZDamageBox2::CopyEventDataBlock(DBREAD&) (0x5db9f0), thiscall, ret 4.
The DBREAD readers are recorders: GetRefTab (0x4e6330, one stack argument, the ref table at +0x48), u32 (0x4e5e60),
float on st0 (0x4e5e80), bool (0x4e5ef0), unsigned short (0x4e5e40). Each returns a fresh random value per call."""
from pilot import S, F
from recruits_util import rnd, hook_rec, clear_hooks


def _gen(c):
    clear_hooks(c)
    r = c.rng
    self_ = rnd(c, 0x100)
    db = rnd(c, 0x40)
    c.emu.w32(self_ + 0x48, rnd(c, 0x40))
    hook_rec(c, 0x4e6330, 1, this=True)
    hook_rec(c, 0x4e5e60, 0, this=True, ret=lambda e, a: r.getrandbits(32))
    hook_rec(c, 0x4e5e80, 0, this=True, st0=lambda e, a: F(r.uniform(-1000.0, 1000.0)))
    hook_rec(c, 0x4e5ef0, 0, this=True, ret=lambda e, a: r.getrandbits(32))
    hook_rec(c, 0x4e5e40, 0, this=True, ret=lambda e, a: r.getrandbits(16))
    return [self_, db]


S(0x5db9f0, 'ZDamageBox2::CopyEventDataBlock', 'thiscall', None, ret=None, gen=_gen, note='batch2411')
