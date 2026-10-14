"""specs_s31037.py - batch 31037: field operations and bit testing."""
from pilot import S
from recruits_util import clear_hooks, obj, hook_rec

def _g4646f0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x80, {})
    param1 = c.rng.getrandbits(32)
    param2 = c.rng.getrandbits(32)
    return [self_obj, param1, param2]

def _g646040(c):
    clear_hooks(c)
    field1 = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    field2 = c.rng.choice([0, 1, c.rng.getrandbits(8)])
    self_obj = obj(c, 0x300, {0x291: field1, 0x295: field2})
    return [self_obj]

def _g593fd0(c):
    clear_hooks(c)
    hook_rec(c, 0x4670b0, 0, this=True)
    flags = c.rng.choice([0, 0x400, 0xffffffff, c.rng.getrandbits(32)])
    self_obj = obj(c, 0x500, {0x417: flags})
    return [self_obj]

S(0x4646f0, 'copy_two_params', 'thiscall', None, ret=None, gen=_g4646f0)
S(0x646040, 'dual_field_check', 'thiscall', None, ret='al', gen=_g646040)
S(0x593fd0, 'bit_test_jump', 'thiscall', None, ret=None, gen=_g593fd0)
