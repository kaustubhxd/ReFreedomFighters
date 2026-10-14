"""specs_s31036.py - batch 31036: conditional logic and initialization."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g54db80(c):
    clear_hooks(c)
    self_obj = obj(c, 0x40b0, {0x40ad: c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])})
    return [self_obj]

def _g5c7ed0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x40, {})
    return [self_obj]

def _g5af0d0(c):
    clear_hooks(c)
    limit = c.rng.choice([1, 5, 10, 100])
    fields = {0: limit}
    for i in range(min(limit, 20)):
        fields[4 + i*4] = c.rng.getrandbits(32)
    self_obj = obj(c, 0x200, fields)
    index = c.rng.choice([0, 1, limit-1, limit, limit+1, c.rng.getrandbits(16)])
    return [self_obj, index]

S(0x54db80, 'field_check_inc', 'thiscall', None, ret='eax', gen=_g54db80)
S(0x5c7ed0, 'multi_init_return_this', 'thiscall', None, ret=None, gen=_g5c7ed0)
S(0x5af0d0, 'bounds_check_indexed_read', 'thiscall', None, ret='eax', gen=_g5af0d0)
