"""specs_s338.py - gap band batch 338: 0x4063c0 returns the constant 0x80 (eax). No arguments."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x4063c0, 'returns 0x80 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 338 (constant return)')
