"""specs_s31027.py - batch 31027: byte swap, multi-store, and comparison functions (5 functions)."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g466600(c):
    clear_hooks(c)
    o = obj(c, 0x100, {0: c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [o, param]

def _g518730(c):
    clear_hooks(c)
    o = obj(c, 0x400, {})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [o, param]

def _g54db80(c):
    clear_hooks(c)
    o = obj(c, 0x50000, {0x40ad: c.rng.choice([0, 1, 2, 100, c.rng.getrandbits(32)])})
    return [o]

def _g49b340(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    p1 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    p2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, p1, p2]

def _g5b07d0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    p1 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    p2 = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, p1, p2]

S(0x466600, 'byte_swap', 'thiscall', None, ret='al', gen=_g466600)
S(0x518730, 'set_byte_2loc', 'thiscall', None, ret=None, gen=_g518730)
S(0x54db80, 'cmp_1_or_inc', 'thiscall', None, ret='eax', gen=_g54db80)
S(0x49b340, 'set_2dwords_14_18', 'thiscall', None, ret=None, gen=_g49b340)
S(0x5b07d0, 'set_2dwords_8_10', 'thiscall', None, ret=None, gen=_g5b07d0)
