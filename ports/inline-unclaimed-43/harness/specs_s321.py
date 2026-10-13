"""specs_s321.py - unclaimed-43 batch 321: 0x5eeb80, thiscall, one stack argument, ret 4; stores the argument dword at
this+0x11 (unaligned). The object is a zeroed block with random bytes around the field."""
from pilot import S
import engine_stubs as E


def _gen(c):
    o = E.zero_obj(c, 0x40)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    v = c.rng.getrandbits(32)
    c.emu.mu.ctl_flush_tb()
    return [o, v]


S(0x5eeb80, 'store dword at +0x11 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-43 batch 321 (leaf)')
