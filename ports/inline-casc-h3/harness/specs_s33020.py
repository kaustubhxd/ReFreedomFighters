"""specs_s33020.py - h3 batch 33020: field initializers."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x100):
    return rnd(c, n)

def _g524660(c):
    clear_hooks(c)
    return [_me(c)]

def _g471640(c):
    clear_hooks(c)
    # Create source object with 3 dwords at offsets 0, 4, 8
    src = c.emu.alloc(0x40, 4)
    c.emu.wbytes(src, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [_me(c), src]

S(0x524660, 'init_float_fields', 'thiscall', None, ret=None, gen=_g524660)
S(0x471640, 'copy_three_dwords', 'stdcall', None, ret=None, gen=_g471640)
