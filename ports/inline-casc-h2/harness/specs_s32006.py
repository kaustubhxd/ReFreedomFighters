"""specs_s32006.py - h2 batch 32006: early tier B functions with calls.
Called functions 0x5390b0 and 0x4c24b0 are hooked.
"""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x80):
    return rnd(c, n)


def _g533ba0(c):
    clear_hooks(c)
    hook_rec(c, 0x5390b0, 0)
    return [_me(c, 0x100)]


def _g4bb9d0(c):
    clear_hooks(c)
    hook_rec(c, 0x4c24b0, 0, this=True)
    return [_me(c, 0x100)]


S(0x533ba0, 'GUESS call and return constant 1', 'thiscall', None, ret='al', gen=_g533ba0, note='batch32006')
S(0x4bb9d0, 'GUESS AND field then call', 'thiscall', None, ret=None, gen=_g4bb9d0, note='batch32006')
