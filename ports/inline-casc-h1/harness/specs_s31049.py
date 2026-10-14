"""specs_s31049.py - batch 31049: copy three parameters and initialize."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g5df720(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {})
    param1 = c.rng.getrandbits(32)
    param2 = c.rng.getrandbits(32)
    param3 = c.rng.getrandbits(32)
    return [self_obj, param1, param2, param3]

S(0x5df720, 'copy_params_init_vtable', 'thiscall', None, ret=None, gen=_g5df720)
