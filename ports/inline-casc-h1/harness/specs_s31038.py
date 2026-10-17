"""specs_s31038.py - batch 31038: dword copy and multi-field initialization."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g471640(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    src_array = obj(c, 12, {0: c.rng.getrandbits(32), 4: c.rng.getrandbits(32), 8: c.rng.getrandbits(32)})
    return [self_obj, src_array]

def _g65ca30(c):
    clear_hooks(c)
    self_obj = obj(c, 0x500, {})
    ptr = c.rng.getrandbits(32)
    size = c.rng.choice([0, 1, 10, 100, c.rng.getrandbits(16)])
    return [self_obj, ptr, size]

S(0x471640, 'copy_three_dwords', 'thiscall', None, ret=None, gen=_g471640)
S(0x65ca30, 'multi_field_init', 'thiscall', None, ret=None, gen=_g65ca30)
