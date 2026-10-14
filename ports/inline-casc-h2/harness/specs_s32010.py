"""specs_s32010.py - h2 batch 32010: field writes and external calls
"""
from pilot import S
from recruits_util import rnd, clear_hooks, hook_rec

def _me(c, n=0x100):
    return rnd(c, n)

def _g4cd180(c):
    clear_hooks(c)
    hook_rec(c, 0x634273, 0)
    return [_me(c, 0x100)]

S(0x4cd180, 'GUESS write vtable and call', 'thiscall', None, ret=None, gen=_g4cd180, note='batch32010')
