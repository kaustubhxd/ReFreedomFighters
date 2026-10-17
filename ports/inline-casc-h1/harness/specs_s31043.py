"""specs_s31043.py - batch 31043: indexed reads and byte operations."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g4db580(c):
    clear_hooks(c)
    limit = c.rng.choice([1, 5, 10, 20])
    fields = {0x1c: limit}
    for i in range(limit):
        fields[i*4] = c.rng.getrandbits(32)
    self_obj = obj(c, 0x100, fields)
    index = c.rng.choice([0, 1, limit-1, limit, limit+1, c.rng.getrandbits(8)])
    return [self_obj, index]

def _g4cf1c0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x20, {8: c.rng.choice([0, obj(c, 0x20, {8: c.rng.getrandbits(32)}), None])})
    out_obj = obj(c, 0x20, {})
    return [self_obj, out_obj]

def _g624960(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    byte0 = c.rng.choice([0, 0xf4, 0xf5, c.rng.getrandbits(8)])
    byte1 = c.rng.choice([0, 0x30, 0x20, 0x10, c.rng.getrandbits(8)])
    ptr_obj = obj(c, 0x10, {0: byte0, 1: byte1})
    return [self_obj, ptr_obj]

S(0x4db580, 'bounds_indexed_read', 'thiscall', None, ret='eax', gen=_g4db580)
S(0x4cf1c0, 'copy_cond_store', 'thiscall', None, ret=None, gen=_g4cf1c0)
S(0x624960, 'byte_multi_check', 'thiscall', None, ret='al', gen=_g624960)
