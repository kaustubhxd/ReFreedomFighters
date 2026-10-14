"""specs_s31035.py - batch 31035: simple copy and compare operations."""
from pilot import S
from recruits_util import clear_hooks, obj

def _g465850(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {})
    param = c.rng.choice([0, 0x465710, 0x465711, c.rng.getrandbits(32)])
    return [self_obj, param]

def _g64fc20(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {0x60: c.rng.getrandbits(32), 0x64: c.rng.getrandbits(32)})
    out_obj = obj(c, 0x20, {})
    return [self_obj, out_obj]

def _g5ad2b0(c):
    clear_hooks(c)
    self_obj = obj(c, 0x100, {0x48: 0, 0x49: 0, 0x4a: 0, 0x4b: 0})
    src_bytes = bytes([c.rng.getrandbits(8) for _ in range(4)])
    src_obj = obj(c, 4, {i: b for i, b in enumerate(src_bytes)})
    return [self_obj, src_obj]

S(0x465850, 'const_compare_bool', 'thiscall', None, ret='al', gen=_g465850)
S(0x64fc20, 'copy_two_dwords', 'thiscall', None, ret=None, gen=_g64fc20)
S(0x5ad2b0, 'copy_four_bytes', 'thiscall', None, ret=None, gen=_g5ad2b0)
