"""specs_s31025.py - batch 31025: byte/word getters and setters (3 functions)."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g4be6d0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [o, param]

def _g4d4a30(c):
    clear_hooks(c)
    o = obj(c, 0x100, {})
    param = obj(c, 0x100, {0: c.rng.getrandbits(32)})
    return [o, param]

def _g4e5470(c):
    clear_hooks(c)
    o = obj(c, 0x100, {})
    param = obj(c, 0x100, {8: c.rng.choice([0, 1, 0xffff, c.rng.getrandbits(16)])})
    return [o, param]

S(0x4be6d0, 'set_byte_d1', 'thiscall', None, ret=None, gen=_g4be6d0)
S(0x4d4a30, 'deref_get_dword', 'thiscall', None, ret='eax', gen=_g4d4a30)
S(0x4e5470, 'get_word_from_8', 'thiscall', None, ret='eax', gen=_g4e5470)
