"""specs_s31015.py - batch 31015: multi-field store, setter, chained loads."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g53b6d0(c):
    clear_hooks(c)
    o = obj(c, 0x300, {})
    return [o]

def _g5eeb90(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val]

def _g5f1bc0(c):
    clear_hooks(c)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0xc: inner})
    return [o]

def _g5f2e90(c):
    clear_hooks(c)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0x15: inner})
    return [o]

S(0x53b6d0, 'multi_field_store', 'thiscall', None, ret=None, gen=_g53b6d0)
S(0x5eeb90, 'set_dword_4e', 'thiscall', None, ret=None, gen=_g5eeb90)
S(0x5f1bc0, 'chained_load_jmp_5fbac0', 'thiscall', None, ret=None, gen=_g5f1bc0)
S(0x5f2e90, 'chained_load_jmp_50', 'thiscall', None, ret=None, gen=_g5f2e90)
