"""specs_s31051.py - batch 31051: copy four parameters and initialize."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g5df690(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {})
    param1 = c.rng.getrandbits(32)
    param2 = c.rng.getrandbits(32)
    param3 = c.rng.getrandbits(32)
    param4 = c.rng.getrandbits(32)
    return [self_obj, param1, param2, param3, param4]

S(0x5df690, 'copy_four_params_init', 'thiscall', None, ret=None, gen=_g5df690)
