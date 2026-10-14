"""specs_s31007.py - batch 31007: field read and constants."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks

def _g606db0(c):
    # thiscall, returns dword at [ecx + 0x2f]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x80, {0x2f: val})
    return [o]

def _g615ed0(c):
    # cdecl, returns constant 0x55
    clear_hooks(c)
    return []

def _g63dac0(c):
    # cdecl, returns constant 0x1000
    clear_hooks(c)
    return []

def _g63ec50(c):
    # cdecl, returns constant 0xff
    clear_hooks(c)
    return []

S(0x606db0, 'read_field_2f', 'thiscall', None, ret='eax', gen=_g606db0)
S(0x615ed0, 'return_const_55', 'cdecl', None, ret='eax', gen=_g615ed0)
S(0x63dac0, 'return_const_1000', 'cdecl', None, ret='eax', gen=_g63dac0)
S(0x63ec50, 'return_const_ff', 'cdecl', None, ret='eax', gen=_g63ec50)
