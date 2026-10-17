"""specs_s31030.py - batch 31030: indexed reads, conditionals, and calculations (5 functions)."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g4619c0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    table = obj(c, 0x4000, {})
    o_dict = {0x1c: table}
    o = obj(c, 0x200, o_dict)
    param = c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])
    return [o, param]

def _g54e1c0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x5b: c.rng.choice([0, 1]), 0x57: c.rng.choice([0, 1]), 0x1d: c.rng.choice([0, 1])})
    return [o]

def _g5af0d0(c):
    clear_hooks(c)
    limit = c.rng.choice([1, 10, 100, c.rng.getrandbits(16)])
    o = obj(c, 0x1000, {0: limit})
    for i in range(limit if limit < 256 else 256):
        o_dict = o.to_dict() if hasattr(o, 'to_dict') else {}
        # Will be handled by harness
    param = c.rng.choice([0, 1, limit-1, limit, c.rng.getrandbits(32)])
    return [o, param]

def _g4cf1c0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {8: c.rng.choice([0, obj(c, 0x100, {8: c.rng.getrandbits(32)})])})
    param = obj(c, 0x100, {})
    return [o, param]

def _g52b370(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x7d: c.rng.getrandbits(32)})
    param = c.rng.choice([0, 1, 2, c.rng.getrandbits(32)])
    return [o, param]

S(0x4619c0, 'indexed_byte_bit', 'thiscall', None, ret='al', gen=_g4619c0)
S(0x54e1c0, 'cond_logic_noframe', 'thiscall', None, ret='al', gen=_g54e1c0)
S(0x5af0d0, 'bounds_indexed_read', 'thiscall', None, ret='eax', gen=_g5af0d0)
S(0x4cf1c0, 'cond_copy_pointer', 'thiscall', None, ret=None, gen=_g4cf1c0)
S(0x52b370, 'null_check_calc', 'thiscall', None, ret='eax', gen=_g52b370)
