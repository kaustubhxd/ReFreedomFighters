"""specs_s32009.py - h2 batch 32009: tier B frame setup stdcall functions
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g4c1ed0(c):
    clear_hooks(c)
    hook_rec(c, 0x4c0b00, 0)
    return [_me(c, 4), _me(c, 4)]

S(0x4c1ed0, 'GUESS frame setup stdcall', 'stdcall', None, ret=None, gen=_g4c1ed0, note='batch32009')
