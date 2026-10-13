"""specs_s349.py - gap band batch 349: 0x410120, cdecl with one pointer argument; returns (byte at [*arg] + 5) & 2. The pointed-to block
has random bytes; the argument is a holder block whose first dword points to it."""
from pilot import S
import engine_stubs as E


def _gen(c):
    blk = E.zero_obj(c, 0x40)
    c.emu.wbytes(blk, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    holder = E.zero_obj(c, 0x20)
    c.emu.w32(holder, blk)
    c.emu.mu.ctl_flush_tb()
    return [holder]


S(0x410120, 'flag bit of *arg+5 (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 349')
