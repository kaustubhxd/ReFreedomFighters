"""specs_s32001.py - h2 batch 32001: eight more tiny getter functions.
Global 0x6e5ef8 populated with random data. Indirect jump at 0x4cbad0 is hooked.
"""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x80):
    return rnd(c, n)


def _g46ed00(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g46eec0(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g46efb0(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g471850(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g474310(c):
    clear_hooks(c)
    return [_me(c, 0x400)]


def _g4744b0(c):
    clear_hooks(c)
    return [_me(c, 0x400)]


def _g4808c0(c):
    clear_hooks(c)
    c.emu.w32(0x6e5ef8, c.rng.getrandbits(32))
    return []


S(0x46ed00, 'GUESS return field at +0x8e', 'thiscall', None, ret='eax', gen=_g46ed00, note='batch32001')
S(0x46eec0, 'GUESS return field at +0xcf', 'thiscall', None, ret='eax', gen=_g46eec0, note='batch32001')
S(0x46efb0, 'GUESS return field at +0xc7', 'thiscall', None, ret='eax', gen=_g46efb0, note='batch32001')
S(0x471850, 'GUESS return address of field at +0xaa', 'thiscall', None, ret='eax', gen=_g471850, note='batch32001')
S(0x474310, 'GUESS return byte at +0x3bb', 'thiscall', None, ret='al', gen=_g474310, note='batch32001')
S(0x4744b0, 'GUESS return field at +0x3b7', 'thiscall', None, ret='eax', gen=_g4744b0, note='batch32001')
S(0x4808c0, 'GUESS return global 0x6e5ef8', 'cdecl', None, ret='eax', gen=_g4808c0, note='batch32001')
