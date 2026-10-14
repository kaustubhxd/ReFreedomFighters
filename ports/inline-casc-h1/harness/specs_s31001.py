"""specs_s31001.py - batch 31001: four simple field read functions."""
from pilot import S
from recruits_util import rnd, obj, clear_hooks

def _g4666d0(c):
    # thiscall, returns dword at [ecx + 0x39]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x80, {0x39: val})
    return [o]

def _g468a20(c):
    # thiscall, returns byte at [ecx + 0x52]
    clear_hooks(c)
    val = c.rng.randint(0, 255)
    o = obj(c, 0x80, {0x52: val})
    return [o]

def _g46e680(c):
    # thiscall, returns dword at [ecx + 0x94]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0xa0, {0x94: val})
    return [o]

def _g46e6f0(c):
    # thiscall, returns dword at [ecx + 0x64]
    clear_hooks(c)
    val = c.rng.getrandbits(32)
    o = obj(c, 0x70, {0x64: val})
    return [o]

S(0x4666d0, 'read_field_39', 'thiscall', None, ret='eax', gen=_g4666d0)
S(0x468a20, 'read_field_52', 'thiscall', None, ret='al', gen=_g468a20)
S(0x46e680, 'read_field_94', 'thiscall', None, ret='eax', gen=_g46e680)
S(0x46e6f0, 'read_field_64', 'thiscall', None, ret='eax', gen=_g46e6f0)
