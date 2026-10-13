"""specs_s356.py - gap band batch 356: 0x41f160, thiscall, no arguments; zeroes the dwords at +8, +0xc and +0x10. The block has
random bytes so the stores show in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41f160, 'zero three dwords at +8 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen, note='gap band batch 356')
