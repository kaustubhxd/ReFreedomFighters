"""specs_s31044.py - batch 31044: null checks and conditional field operations."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g471a70(c):
    clear_hooks(c)
    if c.rng.choice([True, False]):
        # Null case
        param = 0
    else:
        # Non-null case: create object with pointer at offset 0xc
        inner_obj = obj(c, 0x40, {0x23: c.rng.choice([0x1007d9, 0x1007d8, c.rng.getrandbits(32)])})
        outer_obj = obj(c, 0x20, {0xc: inner_obj})
        param = outer_obj
    return [param]

def _g4e54a0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {0xc: c.rng.getrandbits(32)})
    field_value = c.rng.choice([-1, 0, 10, 100, c.rng.getrandbits(32)])
    param_obj = obj(c, 0x50, {0x48: field_value})
    return [self_obj, param_obj]

S(0x471a70, 'null_check_compare_field', 'stdcall', None, ret='al', gen=_g471a70)
S(0x4e54a0, 'field_sign_check_add', 'thiscall', None, ret='eax', gen=_g4e54a0)
