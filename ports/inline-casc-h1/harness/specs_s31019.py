"""specs_s31019.py - batch 31019: 2-param setters, complex lea, multi-field store."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g4eb060(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val1 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    val2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val1, val2]

def _g5398d0(c):
    clear_hooks(c)
    o = obj(c, 0x8000, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    idx = c.rng.choice([0, 1, 2, c.rng.randint(0, 20)])
    return [o, val, idx]

def _g5c7ed0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    return [o]

def _g638c90(c):
    clear_hooks(c)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0x14: inner})
    idx = c.rng.choice([0, 1, 2, c.rng.randint(0, 10)])
    return [o, idx]

S(0x4eb060, 'set_two_dwords_c_10', 'thiscall', None, ret=None, gen=_g4eb060)
S(0x5398d0, 'complex_lea_store_515e', 'thiscall', None, ret=None, gen=_g5398d0)
S(0x5c7ed0, 'multi_field_store_const', 'thiscall', None, ret=None, gen=_g5c7ed0)
S(0x638c90, 'lea_chain_array_idx', 'thiscall', None, ret='eax', gen=_g638c90)
