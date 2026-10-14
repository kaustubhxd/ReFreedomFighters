"""specs_s31054.py - batch 31054: byte read from parameter."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g410100(c):
    clear_hooks(c)
    param = obj(c, 0x20, {4: c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])})
    return [param]

S(0x410100, 'read_byte_param', 'cdecl', None, ret='al', gen=_g410100)
