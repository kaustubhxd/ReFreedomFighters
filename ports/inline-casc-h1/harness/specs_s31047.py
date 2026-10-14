"""specs_s31047.py - batch 31047: copy dwords, indexed read, and conditional call."""
from pilot import S
from recruits_util import clear_hooks, obj, hook_rec, pystub

def _g64fc20(c):
    clear_hooks(c)
    self_obj = obj(c, 0x70, {0x60: c.rng.getrandbits(32), 0x64: c.rng.getrandbits(32)})
    param = obj(c, 0x20, {})
    return [self_obj, param]

def _g533500(c):
    clear_hooks(c)
    # Create array at offset 0x5462
    array_size = c.rng.choice([2, 4, 8, 16])
    array_fields = {0x546e: array_size}
    for i in range(array_size):
        array_fields[0x5462 + i*4] = c.rng.getrandbits(32)
    self_obj = obj(c, 0x5470, array_fields)

    # Parameter is the index
    param = c.rng.choice([0, 1, array_size - 1, c.rng.getrandbits(8)])
    return [self_obj, param]

def _g514480(c):
    clear_hooks(c)
    hook_rec(c, 0x5138f0, 0)
    field_val = c.rng.getrandbits(32)
    self_obj = obj(c, 0x20, {0: field_val})
    # Param is either equal to field (return early) or different (call ext)
    param = c.rng.choice([field_val, c.rng.getrandbits(32)])
    return [self_obj, param]

S(0x64fc20, 'copy_dwords', 'thiscall', None, ret=None, gen=_g64fc20)
S(0x533500, 'cond_indexed_read', 'thiscall', None, ret='eax', gen=_g533500)
S(0x514480, 'cond_call', 'thiscall', None, ret=None, gen=_g514480)
