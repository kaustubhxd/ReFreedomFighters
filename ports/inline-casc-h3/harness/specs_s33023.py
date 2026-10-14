"""specs_s33023.py - h3 batch 33023: field copiers."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x200):
    return rnd(c, n)

def _g445fc0(c):
    clear_hooks(c)
    # Create self with data at offsets
    self = c.emu.alloc(0x300, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x300)))
    # Create destination
    dst = c.emu.alloc(0x40, 4)
    c.emu.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [self, dst]

S(0x445fc0, 'copy_four_dwords', 'thiscall', None, ret=None, gen=_g445fc0)
