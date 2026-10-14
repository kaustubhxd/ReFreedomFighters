"""specs_s33030.py - h3 batch 33030: field initialization with float constants."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _g609a70(c):
    clear_hooks(c)
    # Create self with random data
    self = c.emu.alloc(0x100, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [self]

S(0x609a70, 'field_init_floats', 'thiscall', None, ret='eax', gen=_g609a70)
