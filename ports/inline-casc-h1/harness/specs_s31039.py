"""specs_s31039.py - batch 31039: arithmetic and parameter passing."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g52b370(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {0x7d: c.rng.getrandbits(32)})
    param = c.rng.choice([0, 1, 5, 10, c.rng.getrandbits(16)])
    return [self_obj, param]

def _g4e5310(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    param_obj = obj(c, 0x20, {0x13: c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])})
    return [self_obj, param_obj]

def _g5df690(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    p1 = c.rng.getrandbits(32)
    p2 = c.rng.getrandbits(32)
    p3 = c.rng.getrandbits(32)
    return [self_obj, p1, p2, p3]

S(0x52b370, 'calc_offset', 'thiscall', None, ret='eax', gen=_g52b370)
S(0x4e5310, 'field_check_return', 'thiscall', None, ret='eax', gen=_g4e5310)
S(0x5df690, 'copy_three_params', 'thiscall', None, ret=None, gen=_g5df690)
