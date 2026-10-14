"""specs_s31026.py - batch 31026: simple byte and dword setters (5 functions)."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g51c520(c):
    clear_hooks(c)
    o = obj(c, 0x1000, {})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [o, param]

def _g5398c0(c):
    clear_hooks(c)
    o = obj(c, 0x1000, {})
    param = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, param]

def _g54ba20(c):
    clear_hooks(c)
    o = obj(c, 0x2000, {})
    param = c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])
    return [o, param]

def _g5eebc0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    param = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, param]

def _g639c40(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    param = c.rng.choice([0, 1, 0xffffffff, c.rng.getrandbits(32)])
    return [o, param]

S(0x51c520, 'set_byte_469', 'thiscall', None, ret=None, gen=_g51c520)
S(0x5398c0, 'set_dword_52f2', 'thiscall', None, ret=None, gen=_g5398c0)
S(0x54ba20, 'set_byte_a273', 'thiscall', None, ret=None, gen=_g54ba20)
S(0x5eebc0, 'set_dword_73', 'thiscall', None, ret=None, gen=_g5eebc0)
S(0x639c40, 'set_dword_29', 'thiscall', None, ret=None, gen=_g639c40)
