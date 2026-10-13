"""specs_s340.py - gap band batch 340: 0x41ea90 increments the dword at this+0x49 (no arguments, no return value). The object
is a block with random bytes so the store shows in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x60)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x60)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41ea90, 'inc dword at +0x49 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='gap band batch 340')
