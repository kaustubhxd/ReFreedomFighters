"""specs_s354.py - gap band batch 354: 0x40aa60, cdecl with two pointer-to-pointer arguments; returns **a - **b (unsigned). Each
argument is a holder whose dword points to a block whose dword is the value."""
from pilot import S
import engine_stubs as E


def _holder(c, val):
    blk = E.zero_obj(c, 0x20)
    c.emu.w32(blk, val)
    h = E.zero_obj(c, 0x20)
    c.emu.w32(h, blk)
    return h


def _gen(c):
    r = c.rng
    a = _holder(c, r.getrandbits(32))
    b = _holder(c, r.getrandbits(32))
    c.emu.mu.ctl_flush_tb()
    return [a, b]


S(0x40aa60, 'difference of dereferenced values (unknown) cdecl', 'cdecl', None, ret='eax', gen=_gen,
  note='gap band batch 354')
