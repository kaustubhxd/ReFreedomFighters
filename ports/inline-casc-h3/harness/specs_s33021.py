"""specs_s33021.py - h3 batch 33021: field readers and writers."""
from pilot import S
from recruits_util import rnd, clear_hooks

def _me(c, n=0x80):
    return rnd(c, n)

def _g61c5c0(c):
    clear_hooks(c)
    dst = c.emu.alloc(0x80, 4)
    c.emu.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    val1 = c.rng.getrandbits(32)
    val2 = c.rng.getrandbits(32)
    return [dst, val1, val2]

def _g591f30(c):
    clear_hooks(c)
    # Create self with values at 0x65d, 0x661, 0x665
    self = c.emu.alloc(0x700, 4)
    c.emu.wbytes(self, bytes(c.rng.getrandbits(8) for _ in range(0x700)))
    c.emu.w32(self + 0x65d, c.rng.getrandbits(32))
    c.emu.w32(self + 0x661, c.rng.getrandbits(32))
    c.emu.w32(self + 0x665, c.rng.getrandbits(32))
    # Create destination
    dst = c.emu.alloc(0x40, 4)
    c.emu.wbytes(dst, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [self, dst]

S(0x61c5c0, 'set_two_fields', 'cdecl', None, ret=None, gen=_g61c5c0)
S(0x591f30, 'copy_three_to_dest', 'thiscall', None, ret=None, gen=_g591f30)
