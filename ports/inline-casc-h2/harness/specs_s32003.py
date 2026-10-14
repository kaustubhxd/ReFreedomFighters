"""specs_s32003.py - h2 batch 32003: field setters and getters with large offsets.
"""
from pilot import S
from recruits_util import rnd, clear_hooks


def _me(c, n=0x80):
    return rnd(c, n)


def _g54cd00(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g59b330(c):
    clear_hooks(c)
    return [_me(c, 0x13000)]


def _g59c610(c):
    clear_hooks(c)
    return [_me(c, 0x13000)]


def _g5c7f00(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g60d810(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g616a50(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g63db10(c):
    clear_hooks(c)
    return []


def _g63ec90(c):
    clear_hooks(c)
    return []


S(0x54cd00, 'GUESS set vtable to 0x6a3e14', 'thiscall', None, ret=None, gen=_g54cd00, note='batch32003')
S(0x59b330, 'GUESS return field at +0x121a8', 'thiscall', None, ret='eax', gen=_g59b330, note='batch32003')
S(0x59c610, 'GUESS return address of field at +0x12108', 'thiscall', None, ret='eax', gen=_g59c610, note='batch32003')
S(0x5c7f00, 'GUESS set vtable to 0x6b48f0', 'thiscall', None, ret=None, gen=_g5c7f00, note='batch32003')
S(0x60d810, 'GUESS return address of field at +0x94', 'thiscall', None, ret='eax', gen=_g60d810, note='batch32003')
S(0x616a50, 'GUESS set vtable to 0x6bdc38', 'thiscall', None, ret=None, gen=_g616a50, note='batch32003')
S(0x63db10, 'GUESS return constant 0x18', 'cdecl', None, ret='eax', gen=_g63db10, note='batch32003')
S(0x63ec90, 'GUESS return constant 0x35', 'cdecl', None, ret='eax', gen=_g63ec90, note='batch32003')
