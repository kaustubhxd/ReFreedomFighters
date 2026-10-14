"""specs_s32007.py - h2 batch 32007: priority ZBaseGeom::MakeInactive
Complex function with recursion, virtual calls, global reads.
"""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g4dc030(c):
    clear_hooks(c)
    hook_rec(c, 0x4da770, 0)
    hook_rec(c, 0x4dae60, 0)
    hook_rec(c, 0x4daff0, 0)
    hook_rec(c, 0x4dc630, 0)
    return [_me(c, 0x100)]

S(0x4dc030, 'GUESS MakeInactive stub', 'thiscall', None, ret=None, gen=_g4dc030, note='priority h2')
