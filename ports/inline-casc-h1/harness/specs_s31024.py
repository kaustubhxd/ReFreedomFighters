"""specs_s31024.py - batch 31024: simple stdcall arithmetic/store functions (4 functions)."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g46ac30(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x8e: c.rng.getrandbits(32)})
    param = c.rng.choice([0, 1, -1, 0x100, c.rng.getrandbits(32)])
    return [o, param]

def _g4711d0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    param = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, param]

def _g471840(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x8e: c.rng.getrandbits(32)})
    param = c.rng.choice([0, 1, 0x100, c.rng.getrandbits(32)])
    return [o, param]

def _g47be00(c):
    clear_hooks(c)
    o = obj(c, 0x1000, {})
    param = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, param]

S(0x46ac30, 'add_to_8e', 'thiscall', None, ret=None, gen=_g46ac30)
S(0x4711d0, 'set_8e', 'thiscall', None, ret=None, gen=_g4711d0)
S(0x471840, 'sub_from_8e', 'thiscall', None, ret=None, gen=_g471840)
S(0x47be00, 'set_74f', 'thiscall', None, ret=None, gen=_g47be00)
