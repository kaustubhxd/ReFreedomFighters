"""specs_s31022.py - batch 31022: simple thunks and setters (5 functions)."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g46eaa0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x78: c.rng.getrandbits(32)})
    return [o]

def _g45ede0(c):
    clear_hooks(c)
    hook_rec(c, 0x4db270, 0, this=True)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {8: inner})
    return [o]

def _g45f060(c):
    clear_hooks(c)
    hook_rec(c, 0x4db780, 0, this=True)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {8: inner})
    return [o]

def _g45fc80(c):
    clear_hooks(c)
    hook_rec(c, 0x4dcac0, 0, this=True)
    inner = obj(c, 0x100, {})
    o = obj(c, 0x200, {8: inner})
    return [o]

def _g46d8c0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0xba: c.rng.choice([0, 1]), 0xc4: 0, 0xbf: 0})
    return [o]

S(0x46eaa0, 'getter_78', 'thiscall', None, ret='eax', gen=_g46eaa0)
S(0x45ede0, 'thunk_to_4db270', 'thiscall', None, ret=None, gen=_g45ede0)
S(0x45f060, 'thunk_to_4db780', 'thiscall', None, ret=None, gen=_g45f060)
S(0x45fc80, 'thunk_to_4dcac0', 'thiscall', None, ret=None, gen=_g45fc80)
S(0x46d8c0, 'cond_setter', 'thiscall', None, ret=None, gen=_g46d8c0)
