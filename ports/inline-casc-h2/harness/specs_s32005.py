"""specs_s32005.py - h2 batch 32005: bit operations and multi-write functions.
"""
from pilot import S
from recruits_util import rnd, clear_hooks


def _me(c, n=0x80):
    return rnd(c, n)


def _g65f560(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g4d43c0(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g4f4cc0(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g52a200(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


S(0x65f560, 'GUESS return field plus constant', 'thiscall', None, ret='al', gen=_g65f560, note='batch32005')
S(0x4d43c0, 'GUESS conditional byte compare and set', 'thiscall', None, ret='al', gen=_g4d43c0, note='batch32005')
S(0x4f4cc0, 'GUESS extract bit from field', 'thiscall', None, ret='al', gen=_g4f4cc0, note='batch32005')
S(0x52a200, 'GUESS write three float constants', 'thiscall', None, ret=None, gen=_g52a200, note='batch32005')
