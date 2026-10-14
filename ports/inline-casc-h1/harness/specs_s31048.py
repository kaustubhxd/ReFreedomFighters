"""specs_s31048.py - batch 31048: conditional byte write and field initialization."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g537e70(c):
    clear_hooks(c)
    self_obj = obj(c, 0x30, {})
    param = c.rng.choice([0, 1, 2, 3, 4, 5, c.rng.getrandbits(8)])
    return [self_obj, param]

def _g5eec40(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {})
    return [self_obj]

def _g4c62c0(c):
    clear_hooks(c)
    field_word = c.rng.choice([0, 1, 0x100, c.rng.getrandbits(16)])
    field_val = c.rng.getrandbits(32)
    self_obj = obj(c, 0x50, {0x48: field_word, 0x4a: field_val})
    param1 = c.rng.choice([field_word, field_word + 1, c.rng.getrandbits(16)])
    # param2 can be null (0) or valid pointer
    param2 = c.rng.choice([0, obj(c, 0x20, {})])
    return [self_obj, param1, param2]

S(0x537e70, 'cond_byte_write', 'thiscall', None, ret='al', gen=_g537e70)
S(0x5eec40, 'init_fields_vtable', 'thiscall', None, ret=None, gen=_g5eec40)
S(0x4c62c0, 'check_and_copy_word', 'thiscall', None, ret='eax', gen=_g4c62c0)
