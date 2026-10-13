"""specs_s406.py - gap band parked row 0x41f180 and its target 0x4d0f10 (both thiscall, one stack argument, ret 4). 0x4d0f10 is
exe code (not hooked): it swaps the dword at this+0x821c with its argument and returns the old value. The forwarder's object is
a block whose +0x31 points at the inner 0x8300-byte block (random bytes, so the swap shows in the heap compare)."""
from pilot import S
import engine_stubs as E


def _gen(c):
    r = c.rng
    inner = E.zero_obj(c, 0x8300)
    c.emu.wbytes(inner, bytes(r.getrandbits(8) for _ in range(0x8300)))
    o = E.zero_obj(c, 0x40)
    c.emu.w32(o + 0x31, inner)
    c.emu.mu.ctl_flush_tb()
    return [o, r.getrandbits(32)]


def _gen_inner(c):
    r = c.rng
    inner = E.zero_obj(c, 0x8300)
    c.emu.wbytes(inner, bytes(r.getrandbits(8) for _ in range(0x8300)))
    c.emu.mu.ctl_flush_tb()
    return [inner, r.getrandbits(32)]


S(0x4d0f10, 'swap dword at +0x821c (core leaf) thiscall', 'thiscall', None, ret='eax', gen=_gen_inner,
  note='gap band batch 406; exe leaf, real code')
S(0x41f180, 'forward to 0x4d0f10 via [this+0x31] (gap band parked) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band parked row; target 0x4d0f10 is exe code')
