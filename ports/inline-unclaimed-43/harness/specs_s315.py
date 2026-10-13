"""specs_s315.py - unclaimed-43 batch 315: 0x52a1e0, thiscall, no arguments, ret 0. Writes three dwords into the object at
+0x29, +0x2d and +0x31. The object is a zeroed block with random bytes around those fields, so a wrong offset or a missed
store shows in the heap compare."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x60)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x60)))
    c.emu.mu.ctl_flush_tb()
    return [o]


S(0x52a1e0, 'set bounds +/-500 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 315 (leaf)')
