"""specs_s31053.py - batch 31053: simple dword getter."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g64fb70(c):
    clear_hooks(c)
    self_obj = obj(c, 0x90, {0x8c: c.rng.getrandbits(32)})
    return [self_obj]

S(0x64fb70, 'read_dword_field', 'thiscall', None, ret='eax', gen=_g64fb70)
