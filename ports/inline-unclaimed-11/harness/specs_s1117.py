"""specs_s1117.py - unclaimed-11 batch 18 (gap band 0x5a1000-0x5c1000), thiscall.
0x5ac640 (GUESS): stores the dword arg1 at this+0xd and the dword arg2 at this+0x15 (ret 8).
0x5aaaf0 (GUESS, no name): the byte at [[this+0x474]+0x35] and [[this+0x478]+0x35] is set to 0 (ret 0).
The two pointers are 0x40-byte buffers (the byte is inside them); the object is 0x800 random bytes."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x800, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x800)))
    return o


def _two(c):
    return [_obj(c), c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _ptrs(c):
    o = _obj(c)
    for off in (0x474, 0x478):
        b = c.emu.alloc(0x40, 4)
        c.emu.wbytes(b, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
        c.emu.w32(o + off, b)
    return [o]


S(0x5ac640, 'GUESS CMessageBasics::SetPositionScreenY? (stores +0xd, +0x15) thiscall', 'thiscall', None, ret=None,
  gen=_two, note='unclaimed-11 batch 18 (gap band)')
S(0x5aaaf0, 'GUESS (no name) clear two flag bytes thiscall', 'thiscall', None, ret=None, gen=_ptrs,
  note='unclaimed-11 batch 18 (gap band)')
