"""specs_s1112.py - unclaimed-11 batch 13 (slice 10, full list): 0x493fe0, thiscall, no arguments. al = (dword at this+0x5d39
!= 0). The object is 0x6000 random bytes (the field is at +0x5d39); the field is zero in a third of cases."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x6000, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x6000)))
    c.emu.w32(o + 0x5d39, 0 if c.rng.random() < 0.33 else c.rng.getrandbits(32))
    return [o]


S(0x493fe0, 'GUESS none (no GC name) bool at +0x5d39 thiscall', 'thiscall', None, ret='al', gen=_obj,
  note='unclaimed-11 batch 13 (slice 10, full list)')
