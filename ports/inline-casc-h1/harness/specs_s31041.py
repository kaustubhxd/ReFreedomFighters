"""specs_s31041.py - batch 31041: conditional calculation and field initialization."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g589fd0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    param = c.rng.choice([-1, 0, 1, 10, c.rng.getrandbits(32)])
    return [self_obj, param]

def _g5eec40(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {})
    return [self_obj]

S(0x589fd0, 'cond_calc_offset', 'thiscall', None, ret='eax', gen=_g589fd0)
S(0x5eec40, 'init_object_fields', 'thiscall', None, ret=None, gen=_g5eec40)
