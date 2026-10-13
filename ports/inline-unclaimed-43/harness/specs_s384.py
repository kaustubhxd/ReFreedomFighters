"""specs_s384.py - gap band batch 384: 0x41e180, thiscall, no arguments, returns this (eax). A constructor: vtable store,
zeroed fields, word +0x4d = 1, byte +0x30 = 1. The object is random bytes so every field store shows in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x60)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x60)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x41e180, 'ctor: vtable 0x67716c and field defaults (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='gap band batch 384')
