"""specs_s1118.py - unclaimed-11 batch 19 (gap band): 0x5ab020, thiscall with eight dword stack arguments (ret 0x20).
GUESS on the name: arguments 1 to 4 are stored as 16 bytes at this+0x8af, arguments 5 to 8 at this+0x8bf (the PC uses two
movups). The object is 0x1000 random bytes."""
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x1000, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x1000)))
    return [o] + [c.rng.getrandbits(32) for _ in range(8)]


S(0x5ab020, 'GUESS (no name) store eight args thiscall ret 0x20', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-11 batch 19 (gap band)')
