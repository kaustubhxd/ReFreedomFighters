"""specs_s31008.py - batch 31008: constants, field read, byte store+return, vtable call."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks, hook_rec, pystub

def _g64c750(c):
    # cdecl, returns constant 0x7f
    clear_hooks(c)
    return []

def _g64fb70(c):
    # thiscall, returns dword at [ecx + 0x8c]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0xa0, {0x8c: val})
    return [o]

def _g429b00(c):
    # thiscall, stores 0 at [ecx+0x75], returns 1
    clear_hooks(c)
    o = obj(c, 0x80, {0x75: 0})
    return [o]

def _g46f500(c):
    # thiscall, compare [ecx+0x8c] >= 5, return bool
    clear_hooks(c)
    # Provide values both below and above 5 to exercise both branches
    val = c.rng.choice([0, 1, 4, 5, 6, 10, c.rng.getrandbits(32)])
    o = obj(c, 0xa0, {0x8c: val})
    return [o]

S(0x64c750, 'return_const_7f', 'cdecl', None, ret='eax', gen=_g64c750)
S(0x64fb70, 'read_field_8c', 'thiscall', None, ret='eax', gen=_g64fb70)
S(0x429b00, 'clear_byte_return_1', 'thiscall', None, ret='al', gen=_g429b00)
S(0x46f500, 'compare_ge_5', 'thiscall', None, ret='al', gen=_g46f500)
