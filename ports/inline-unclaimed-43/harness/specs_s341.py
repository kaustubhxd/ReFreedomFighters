"""specs_s341.py - gap band batch 341: 0x420e90 returns the dword at this+0x1b37 (eax). The object is a block with random
bytes; the dword is unaligned (offset 0x1b37)."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x1c00)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x1c00)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x420e90, 'dword at +0x1b37 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 341')
