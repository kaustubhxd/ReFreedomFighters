"""specs_s32004.py - h2 batch 32004: constants and multi-write functions.
Global 0x7003b8 is populated with a heap pointer for 0x5de3d0.
"""
from pilot import S
from recruits_util import rnd, obj, clear_hooks


def _me(c, n=0x80):
    return rnd(c, n)


def _g64c770(c):
    clear_hooks(c)
    return []


def _g654710(c):
    clear_hooks(c)
    return []


def _g549350(c):
    clear_hooks(c)
    return [_me(c, 0x4100)]


def _g5de3d0(c):
    clear_hooks(c)
    # Set up global 0x7003b8 to point to a writable heap object
    target = obj(c, 0x3000, {})
    c.emu.w32(0x7003b8, target)
    return [_me(c, 0x100)]


S(0x64c770, 'GUESS return constant 0x71', 'cdecl', None, ret='eax', gen=_g64c770, note='batch32004')
S(0x654710, 'GUESS return constant 0x6f62b8', 'cdecl', None, ret='eax', gen=_g654710, note='batch32004')
S(0x549350, 'GUESS set two vtable fields', 'thiscall', None, ret=None, gen=_g549350, note='batch32004')
S(0x5de3d0, 'GUESS write self to global pointer field', 'thiscall', None, ret=None, gen=_g5de3d0, note='batch32004')
