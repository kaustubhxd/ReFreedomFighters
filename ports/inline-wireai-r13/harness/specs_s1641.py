"""specs_s1641.py - residue 13 batch 1641: CEntityTracker::UpdateEntity. Slot +0x98 is a recorder."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    o = obj(c, 0x200, {0x98: stub(c, seq, 1)})
    c.emu.w32(o + 0x54, r.randint(0, 20))
    c.emu.w32(o + 0x50, r.randint(0, 0x1000))
    return [o, r.choice([-3, -1, 0, 1, 2, 5, 19, 20, 21, r.randint(-5, 30)]) & 0xffffffff]


S(0x5c08d0, 'CEntityTracker::UpdateEntity', 'thiscall', None, ret=None, gen=_gen, note='batch1641')
