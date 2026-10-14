"""specs_s32011.py - h2 batch 32011: tier B tail jump functions
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g570920(c):
    clear_hooks(c)
    hook_rec(c, 0x5626c0, 0)
    hook_rec(c, 0x5709d0, 0)
    return [_me(c, 0x100)]

S(0x570920, 'GUESS tail jump pattern', 'thiscall', None, ret=None, gen=_g570920, note='batch32011')
