"""specs_s31002.py - batch 31002: four simple read functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks

def _g46e720(c):
    # cdecl, returns constant 0x686504
    clear_hooks(c)
    return []

def _g46ee00(c):
    # thiscall, returns dword at [ecx + 0x80]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x90, {0x80: val})
    return [o]

def _g46efa0(c):
    # thiscall, returns dword at [ecx + 0xd5]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0xe0, {0xd5: val})
    return [o]

def _g46efe0(c):
    # thiscall, returns byte at [ecx + 0xc6]
    clear_hooks(c)
    val = c.rng.randint(0, 255)
    o = obj(c, 0xd0, {0xc6: val})
    return [o]

S(0x46e720, 'return_const_686504', 'cdecl', None, ret='eax', gen=_g46e720)
S(0x46ee00, 'read_field_80', 'thiscall', None, ret='eax', gen=_g46ee00)
S(0x46efa0, 'read_field_d5', 'thiscall', None, ret='eax', gen=_g46efa0)
S(0x46efe0, 'read_field_c6', 'thiscall', None, ret='al', gen=_g46efe0)
