"""specs_s1654.py - residue 13 batch 1654: jump thunk 0x480010 -> 0x4805a0 (ZLightOverlay::InitSprites). The target is
hooked by address (no stack arguments, thiscall, returns a random eax); the thunk must return that eax unchanged."""
from pilot import S
from sthelp import rnd, Seq, clear_hooks, hook


def _gen(c):
    seq = Seq(c)
    clear_hooks(c)
    hook(c, seq, 0x4805a0, 0, ret=c.rng.getrandbits(32), this=True, pop=True)
    return [rnd(c, 0x100)]


S(0x480010, 'ZLightOverlay::InitSprites (thunk)', 'thiscall', None, ret='eax', gen=_gen,
  note='batch1654; jump thunk, target hooked')
