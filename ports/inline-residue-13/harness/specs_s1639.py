"""specs_s1639.py - residue 13 batch 1639: ZItemTemplateAmmo deleting destructor. Recorders stand in for the delete, the
base destructor, the ZGEOM delete and the 0x4690b0 thunk; the member at +0x70 has a slot-0 stub."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x634273, 2, this=False, pop=False)
    hook(c, seq, 0x43ea20, 0, this=True, pop=True)
    hook(c, seq, 0x45c510, 1, this=False, pop=False)
    hook(c, seq, 0x4690b0, 2, this=False, pop=False)
    item = rnd(c, 0x100)
    c.emu.w32(item + 0x98, rnd(c, 8))
    member = obj(c, 0x40, {0: stub(c, seq, 1)}) if r.random() < 0.8 else 0
    c.emu.w32(item + 0x70, member)
    return [item, r.choice([0, 1, 2, 3, 4, 5, 6, 7])]


S(0x46a990, 'ZItemTemplateAmmo::~ZItemTemplateAmmo (deleting)', 'thiscall', None, ret='eax', gen=_gen, note='batch1639')
