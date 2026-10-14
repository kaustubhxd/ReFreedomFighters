"""specs_s31023.py - batch 31023: pointer arithmetic thunk."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g4d6e70(c):
    clear_hooks(c)
    hook_rec(c, 0x4d9230, 0, this=True)
    o = obj(c, 0x200, {})
    return [o]

S(0x4d6e70, 'thunk_add4_to_4d9230', 'thiscall', None, ret=None, gen=_g4d6e70)
