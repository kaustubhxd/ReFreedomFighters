"""specs_s1236.py - pathfinding batch 1236: the find-path context constructors. The object is random memory (the constructors
must overwrite what they set); the time-slice control is a random pointer value (it is only stored)."""
from pilot import S
from pfspec import rnd


def _ctor(c, size):
    obj = rnd(c, size)
    ctl = c.rng.getrandbits(32)
    return [obj, ctl]


S(0x52cea0, 'time-slice member ctor', 'thiscall', None, gen=lambda c: _ctor(c, 0x80), n=300)
S(0x52cf60, 'CFindPath3Context_packed::CFindPath3Context_packed', 'thiscall', None, gen=lambda c: _ctor(c, 0x100), n=300)
S(0x52a300, 'CFindPathContext::CFindPathContext', 'thiscall', None, gen=lambda c: _ctor(c, 0x100), n=300)
