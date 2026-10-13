"""specs_s327.py - area 71 batch 327: 0x4876a0, thiscall, two stack arguments (a, b), ret 8, returns this. Writes the two
arguments and the vtable 0x68cf50 at [this], the byte at +0x1c and zeros at +0x8, +0xc, +0x14, +0x18. The object is a block with
random bytes so every store shows in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    a = c.rng.getrandbits(32)
    b = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, a, b]


S(0x4876a0, 'init pair record (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='area 71 batch 327 (leaf, residue 10)')
