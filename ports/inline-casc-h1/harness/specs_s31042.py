"""specs_s31042.py - batch 31042: pointer dereferencing with null checks."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g471a10(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    field_obj = obj(c, 0x100, {0x23: c.rng.choice([0, 0x1007d3, 0x1007d4, c.rng.getrandbits(32)])})
    param_obj = obj(c, 0x20, {0xc: field_obj})
    param = c.rng.choice([0, param_obj])
    return [self_obj, param]

def _g471a70(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    field_obj = obj(c, 0x100, {0x10: c.rng.getrandbits(32)})
    param_obj = obj(c, 0x20, {0xc: field_obj})
    param = c.rng.choice([0, param_obj])
    return [self_obj, param]

S(0x471a10, 'null_check_cmp', 'thiscall', None, ret='al', gen=_g471a10)
S(0x471a70, 'null_check_deref', 'thiscall', None, ret='eax', gen=_g471a70)
