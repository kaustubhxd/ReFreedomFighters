"""specs_s2473.py - decomp area 24, batch 2473 (gap band): ZParticleBox::DrawUpdate (0x459b60), thiscall, plain ret.
When the dword at ([0x70039c])+0x3c differs from this+0x24, it is stored at this+0x24 and ZParticleBox's update (0x459c40, recorder,
one float argument, thiscall pops 4) is called with (the float at sys+0x48) * 60.0 (the constant at 0x67885c).
The sys counter and float are random per case; the float is passed to the recorder as its bits."""
from pilot import S, F
from recruits_util import rnd, hook_rec, clear_hooks, sysobj


def _gen(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hook_rec(c, 0x459c40, 1, this=True)
    so = sysobj(c)
    e.w32(so + 0x3c, r.getrandbits(32))
    e.wf32(so + 0x48, F(r.uniform(-10.0, 10.0)))
    o = rnd(c, 0x100)
    e.w32(o + 0x24, r.choice([0, r.getrandbits(32)]))
    return [o]


S(0x459b60, 'ZParticleBox::DrawUpdate', 'thiscall', None, ret=None, gen=_gen, note='batch2473')
