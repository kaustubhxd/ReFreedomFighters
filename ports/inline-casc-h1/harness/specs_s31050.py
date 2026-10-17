"""specs_s31050.py - batch 31050: conditional bit operations on field."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g45fa00(c):
    clear_hooks(c)
    field = c.rng.choice([0, 8, 9, 0xfffffff7, c.rng.getrandbits(32)])
    self_obj = obj(c, 0x20, {0x14: field})
    param = c.rng.choice([0, 1, c.rng.getrandbits(8)])
    return [self_obj, param]

S(0x45fa00, 'cond_bit_ops', 'thiscall', None, ret=None, gen=_g45fa00)
