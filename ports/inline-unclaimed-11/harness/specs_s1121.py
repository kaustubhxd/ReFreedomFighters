"""specs_s1121.py - unclaimed-11 batch 22 (gap band): 0x5aeda0 only (0x5aef10 is a duplicate of area 70 and area 62, withdrawn here).
0x5aeda0 (GUESS, no name) zeroes the sixteen dwords at this+0x00..0x3c through 0x5aef10 (a call in the PC, the same
stores here), then returns this in eax (thiscall, no args, ret 0). The object is 0x100 random bytes."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x100)))
    return [o]


S(0x5aeda0, 'GUESS (no name) zero 64 bytes then return this thiscall', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-11 batch 22 (gap band)')
