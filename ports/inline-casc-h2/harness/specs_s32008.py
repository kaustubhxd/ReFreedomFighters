"""specs_s32008.py - h2 batch 32008: simple tier B read+call functions
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g4c5680(c):
    clear_hooks(c)
    hook_rec(c, 0x4c5770, 0)
    return [_me(c, 0x100)]

S(0x4c5680, 'GUESS read field and call', 'thiscall', None, ret='al', gen=_g4c5680, note='batch32008')
