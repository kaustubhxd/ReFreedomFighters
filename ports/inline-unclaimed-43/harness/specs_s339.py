"""specs_s339.py - gap band batch 339: 0x41d0b0 returns the constant 0x186a0 (eax). No arguments."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41d0b0, 'returns 0x186a0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 339 (constant return)')
