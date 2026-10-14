"""specs_s33024.py - h3 batch 33024: bounded array access."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x200):
    return rnd(c, n)

def _g4db580(c):
    clear_hooks(c)
    # Create self with bound at 0x1c and array data
    self = c.emu.alloc(0x300, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x300)))
    # Set bound to something reasonable (0-10)
    bound = c.rng.randint(3, 8)
    c.emu.wbytes(self + 0x1c, bytes([bound]))
    # Test both within-bounds and out-of-bounds cases
    idx = c.rng.choice([0, 1, bound - 1, bound, bound + 1, 255])
    return [self, idx]

S(0x4db580, 'array_read_bounded', 'thiscall', None, ret='eax', gen=_g4db580)
