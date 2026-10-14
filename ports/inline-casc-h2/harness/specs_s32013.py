"""specs_s32013.py - h2 batch 32013: tier B tail jump functions variant 3
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g575150(c):
    clear_hooks(c)
    hook_rec(c, 0x573da0, 0)
    hook_rec(c, 0x575230, 0)
    return [_me(c, 0x100)]

S(0x575150, 'GUESS tail jump pattern var3', 'thiscall', None, ret=None, gen=_g575150, note='batch32013')
