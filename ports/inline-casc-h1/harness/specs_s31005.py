"""specs_s31005.py - batch 31005: constants and field reads."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec

def _g50d810(c):
    # cdecl, returns constant 0x69c77c
    clear_hooks(c)
    return []

def _g52b3e0(c):
    # cdecl, returns constant 1
    clear_hooks(c)
    return []

def _g5333e0(c):
    # thiscall, returns dword at [ecx + 0x546e]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x5500, {0x546e: val})
    return [o]

def _g534cf0(c):
    # thiscall, stores vtable and tail-jumps to 0x4e66a0
    clear_hooks(c)
    hook_rec(c, 0x4e66a0, 0, this=True)
    return [obj(c, 0x80, {})]

S(0x50d810, 'return_const_69c77c', 'cdecl', None, ret='eax', gen=_g50d810)
S(0x52b3e0, 'return_const_1', 'cdecl', None, ret='eax', gen=_g52b3e0)
S(0x5333e0, 'read_field_546e', 'thiscall', None, ret='eax', gen=_g5333e0)
S(0x534cf0, 'store_vtable_6a1a60', 'thiscall', None, ret=None, gen=_g534cf0)
