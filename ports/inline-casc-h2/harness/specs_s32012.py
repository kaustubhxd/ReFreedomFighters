"""specs_s32012.py - h2 batch 32012: tier B tail jump functions variant 2
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g571f10(c):
    clear_hooks(c)
    hook_rec(c, 0x5626c0, 0)
    hook_rec(c, 0x571f20, 0)
    return [_me(c, 0x100)]

S(0x571f10, 'GUESS tail jump pattern var2', 'thiscall', None, ret=None, gen=_g571f10, note='batch32012')
