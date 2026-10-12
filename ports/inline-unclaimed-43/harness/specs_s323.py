"""specs_s323.py - area 71 batch 323: 0x484fe0, thiscall, one stack argument (the low byte is stored), ret 4. Writes the byte at
this+0x42c; the object is a zeroed block with random bytes around the field."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x440)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x440)))
    v = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, v]


S(0x484fe0, 'store byte at +0x42c (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 71 batch 323 (leaf, residue 10)')
