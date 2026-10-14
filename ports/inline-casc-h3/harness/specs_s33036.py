"""specs_s33036.py - h3 batch 33036: single tier B multi-field init."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x80):
    return rnd(c, n)


def _g5b02b0(c):
    clear_hooks(c)
    hook_rec(c, 0x5aedb0, 0, this=True)
    hook_rec(c, 0x5aeda0, 0, this=True)
    return [_me(c, 0x100)]


S(0x5b02b0, 'GUESS multi-field init + two calls', 'thiscall', None, ret='eax', gen=_g5b02b0, note='batch33036')
