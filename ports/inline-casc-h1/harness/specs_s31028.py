"""specs_s31028.py - batch 31028: vtable setter, conditional logic, and indexed read (5 functions)."""
from pilot import S
from recruits_util import clear_hooks, hook_rec, obj

def _g4e5000(c):
    clear_hooks(c)
    o = obj(c, 0x100, {})
    return [o]

def _g534d60(c):
    clear_hooks(c)
    hook_rec(c, 0x53a910, 0, this=True, nullflag=(0x52fa,))
    o = obj(c, 0x1000, {0x52fa: c.rng.choice([0, obj(c, 0x100, {})])})
    return [o, c.rng.getrandbits(32)]

def _g5eeb10(c):
    clear_hooks(c)
    o = obj(c, 0x200, {0x49: c.rng.getrandbits(32)})
    param = c.rng.choice([0, 1, c.rng.getrandbits(32)])
    return [o, param]

def _g645c10(c):
    clear_hooks(c)
    o = obj(c, 0x300, {0x266: c.rng.choice([0, 1]), 0x267: c.rng.getrandbits(8)})
    param = obj(c, 0x100, {})
    return [o, param]

def _g63eab0(c):
    clear_hooks(c)
    o = obj(c, 0x200, {})
    table = obj(c, 0x4000, {i*4: c.rng.getrandbits(32) for i in range(4096)})
    o_dict = {0x68: table}
    o = obj(c, 0x200, o_dict)
    param = c.rng.choice([0, 1, 0xfff, c.rng.getrandbits(32)])
    return [o, param]

S(0x4e5000, 'set_vtable_6973a4', 'thiscall', None, ret=None, gen=_g4e5000)
S(0x534d60, 'cond_jmp_53a910', 'thiscall', None, ret=None, gen=_g534d60)
S(0x5eeb10, 'cond_store_flag', 'thiscall', None, ret=None, gen=_g5eeb10)
S(0x645c10, 'cond_byte_copy', 'thiscall', None, ret=None, gen=_g645c10)
S(0x63eab0, 'indexed_read_masked', 'thiscall', None, ret='eax', gen=_g63eab0)
