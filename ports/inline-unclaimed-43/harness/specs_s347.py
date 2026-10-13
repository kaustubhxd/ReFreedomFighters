"""specs_s347.py - gap band batch 347: 0x401000, cdecl with one pointer argument; zeroes the four dwords at it. The block has
random bytes around the 16 bytes so the stores show in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    p = E.zero_obj(c, 0x40)
    c.emu.wbytes(p, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    c.emu.mu.ctl_flush_tb()
    return [p]


S(0x401000, 'zero four dwords (unknown) cdecl', 'cdecl', None, ret=None, gen=_gen,
  note='gap band batch 347')
