"""specs_s320.py - unclaimed-43 batch 320: 0x4dcd00, thiscall, one stack argument, ret 4; stores the argument dword at
this+0x50. The object is a zeroed block with random bytes around the field."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x80)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x80)))
    v = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, v]


S(0x4dcd00, 'store dword at +0x50 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 320 (leaf)')
