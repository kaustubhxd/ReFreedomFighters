"""specs_s31040.py - batch 31040: index operations and word comparison."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g591d30(c):
    clear_hooks(c)
    limit = c.rng.choice([1, 5, 10, c.rng.getrandbits(16)])
    fields = {0xa16: limit}
    for i in range(min(limit, 10)):
        idx = i * 6
        fields[0xa1a + idx*8] = c.rng.getrandbits(32)
    self_obj = obj(c, 0xa30, fields)
    index = c.rng.choice([0, 1, limit-1, limit, limit+1, c.rng.getrandbits(16)])
    return [self_obj, index]

def _g517510(c):
    clear_hooks(c)
    field = c.rng.choice([0, 1, 0xffff, c.rng.getrandbits(16)])
    val = c.rng.choice([0, 1, -1, 10, c.rng.getrandbits(32)])
    self_obj = obj(c, 0x1650, {0x164e: field, 0x1639: val})
    param = c.rng.choice([0, field, field+1, c.rng.getrandbits(16)])
    return [self_obj, param]

S(0x591d30, 'bounds_computed_index', 'thiscall', None, ret='eax', gen=_g591d30)
S(0x517510, 'word_cmp_conditional', 'thiscall', None, ret='eax', gen=_g517510)
