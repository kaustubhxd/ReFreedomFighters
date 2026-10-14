"""specs_s31014.py - batch 31014: conditional indirect jump, indirect jump, setters."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g4dbbd0(c):
    clear_hooks(c)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0x54: inner})
    return [o]

def _g4f3230(c):
    clear_hooks(c)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {0x6f: inner})
    return [o]

def _g5186c0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, val]

def _g5332d0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    val = c.rng.choice([0, 1, 0xff, c.rng.randint(0, 255)])
    return [o, val]

S(0x4dbbd0, 'cond_load_field_jmp_1c', 'thiscall', None, ret=None, gen=_g4dbbd0)
S(0x4f3230, 'load_field_jmp_21c', 'thiscall', None, ret=None, gen=_g4f3230)
S(0x5186c0, 'set_dword_1635', 'thiscall', None, ret=None, gen=_g5186c0)
S(0x5332d0, 'set_byte_49', 'thiscall', None, ret=None, gen=_g5332d0)
