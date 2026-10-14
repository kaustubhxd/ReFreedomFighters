"""specs_s31045.py - batch 31045: conditional offset calculation and byte reads."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g658d00(c):
    clear_hooks(c)
    byte_val = c.rng.choice([0, 1, 2, 0xff, c.rng.getrandbits(8)])
    fields = {0x3f: byte_val}
    if byte_val != 0:
        fields[0x48] = c.rng.getrandbits(32)
    self_obj = obj(c, 0x50, fields)
    return [self_obj]

def _g410100(c):
    clear_hooks(c)
    inner_obj = obj(c, 0x10, {4: c.rng.choice([0, 1, 0xff, c.rng.getrandbits(8)])})
    param_obj = obj(c, 0x20, {0: inner_obj})
    return [param_obj]

S(0x658d00, 'cond_offset_shift', 'thiscall', None, ret='eax', gen=_g658d00)
S(0x410100, 'dereference_byte_read', 'cdecl', None, ret='al', gen=_g410100)
