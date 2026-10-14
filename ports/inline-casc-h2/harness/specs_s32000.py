"""specs_s32000.py - h2 batch 32000: eight tiny getter/setter functions.
0x4478d0 is hooked (tail jump target from 0x4529d0).
Global 0x6e59d8 and heap fields are populated with random data.
"""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec


def _me(c, n=0x80):
    return rnd(c, n)


def _g443ac0(c):
    clear_hooks(c)
    return [_me(c, 0x40)]


def _g4529d0(c):
    clear_hooks(c)
    hook_rec(c, 0x4478d0, 0, this=True)
    return [_me(c, 0x40)]


def _g466610(c):
    clear_hooks(c)
    return [_me(c, 0x200)]


def _g466cd0(c):
    clear_hooks(c)
    return [_me(c, 0x40)]


def _g469120(c):
    clear_hooks(c)
    c.emu.w32(0x6e59d8, c.rng.getrandbits(32))
    return []


def _g46e680(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g46e6a0(c):
    clear_hooks(c)
    return [_me(c, 0x100)]


def _g46e700(c):
    clear_hooks(c)
    return []


S(0x443ac0, 'GUESS return self', 'thiscall', None, ret='eax', gen=_g443ac0, note='batch32000')
S(0x4529d0, 'GUESS set vtable then tail call', 'thiscall', None, ret=None, gen=_g4529d0, note='batch32000')
S(0x466610, 'GUESS clear flag byte', 'thiscall', None, ret=None, gen=_g466610, note='batch32000')
S(0x466cd0, 'GUESS return byte from self', 'thiscall', None, ret='al', gen=_g466cd0, note='batch32000')
S(0x469120, 'GUESS return global dword', 'cdecl', None, ret='eax', gen=_g469120, note='batch32000')
S(0x46e680, 'GUESS return field at +0x94', 'thiscall', None, ret='eax', gen=_g46e680, note='batch32000')
S(0x46e6a0, 'GUESS return field at +0xa4', 'thiscall', None, ret='eax', gen=_g46e6a0, note='batch32000')
S(0x46e700, 'GUESS return constant', 'cdecl', None, ret='eax', gen=_g46e700, note='batch32000')
