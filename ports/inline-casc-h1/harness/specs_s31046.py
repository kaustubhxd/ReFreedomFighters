"""specs_s31046.py - batch 31046: copy parameters and initialize fields."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g4eb060(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {})
    param1 = c.rng.getrandbits(32)
    param2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [self_obj, param1, param2]

def _g5c7ed0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x40, {})
    return [self_obj]

def _g62c9b0(c):
    clear_hooks(c)
    param = obj(c, 0x20, {})
    return [param]

S(0x4eb060, 'copy_two_params', 'thiscall', None, ret=None, gen=_g4eb060)
S(0x5c7ed0, 'initialize_fields', 'thiscall', None, ret=None, gen=_g5c7ed0)
S(0x62c9b0, 'init_vtable_and_fields', 'cdecl', None, ret=None, gen=_g62c9b0)
