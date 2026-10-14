"""specs_s33018.py - h3 batch 33018: tail-jump thunks."""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x80):
    return rnd(c, n)

def _g471630(c):
    clear_hooks(c)
    hook_rec(c, 0x471540, 0, this=True)
    return [_me(c)]

def _g4bf4e0(c):
    clear_hooks(c)
    hook_rec(c, 0x4c16b0, 0, this=True)
    return [_me(c)]

S(0x471630, 'thunk_471540', 'thiscall', None, ret=None, gen=_g471630)
S(0x4bf4e0, 'thunk_4c16b0', 'thiscall', None, ret=None, gen=_g4bf4e0)
