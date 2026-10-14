"""specs_s32002.py - h2 batch 32002: simple field accessor functions.
"""
from pilot import S
from recruits_util import rnd, clear_hooks


def _me(c, n=0x80):
    return rnd(c, n)


def _g4ea380(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g4f4cb0(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g5333c0(c):
    clear_hooks(c)
    return [_me(c, 0x5400)]


def _g5334f0(c):
    clear_hooks(c)
    return [_me(c, 0x5500)]


S(0x4ea380, 'GUESS set word at +0xa4', 'thiscall', None, ret=None, gen=_g4ea380, note='batch32002')
S(0x4f4cb0, 'GUESS return field at +0x8b', 'thiscall', None, ret='eax', gen=_g4f4cb0, note='batch32002')
S(0x5333c0, 'GUESS return field at +0x52fe', 'thiscall', None, ret='eax', gen=_g5333c0, note='batch32002')
S(0x5334f0, 'GUESS return field at +0x548a', 'thiscall', None, ret='eax', gen=_g5334f0, note='batch32002')
