"""specs_s1637.py - residue 13 batch 1637: BasicShape::Save and ZItemAmmo::Save.
Both need only call counts and the pushed values: the delete (0x634273, cdecl) and ZItem::Save (0x4705a0) are hooked, the
save game's +0x44 slot is a stub that records its argument. Not using shared-harness serial stubs: no DBREAD code runs."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _basic(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x634273, 2, this=False, pop=False)
    shape = rnd(c, 0x40)
    c.emu.w32(shape + 0xc, rnd(c, 0x38) if r.random() < 0.8 else 0)
    return [shape, rnd(c, 0x20)]


S(0x460c10, 'BasicShape::Save', 'thiscall', None, ret='al', gen=_basic, note='batch1637')


def _ammo(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x4705a0, 1, ret=1 if r.random() < 0.9 else 0)
    save = obj(c, 0x80, {0x44: stub(c, seq, 1)})
    item = rnd(c, 0x100)
    c.emu.w32(item + 0x8e, r.getrandbits(32))
    return [item, save]


S(0x470610, 'ZItemAmmo::Save', 'thiscall', None, ret='al', gen=_ammo, note='batch1637')
