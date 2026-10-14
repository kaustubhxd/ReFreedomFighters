"""specs_s1636.py - residue 13 batch 1636: the action check at 0x438d50. The action lookup (vtable +0x60) is a stub
returning a random record; IsActive (0x439670) is a hooked recorder that returns a random byte."""
from pilot import S
from sthelp import rnd, obj, stub, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    r = c.rng
    clear_hooks(c)
    hook(c, seq, 0x439670, 0, ret=r.getrandbits(8))
    rec = rnd(c, 0x20)
    c.emu.w8(rec + 0x10, r.choice([0, 1, r.getrandbits(8)]))
    c.emu.w32(rec + 4, r.choice([0, 1, 3, 4]))
    c.emu.w32(rec + 0xc, rnd(c, 0x20))
    self_ = obj(c, 0x40, {0x60: stub(c, seq, 1, ret=rec if r.random() < 0.85 else 0)})
    return [self_, rnd(c, 8)]


S(0x438d50, 'ZInputActions::CheckAction (residue 13)', 'thiscall', None, ret='al', gen=_gen, note='batch1636')
