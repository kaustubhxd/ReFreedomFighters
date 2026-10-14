"""specs_s1126.py - unclaimed-11 batch 27 (gap band): 0x5b7b90 (GUESS, no name), thiscall, two stack args (ret 8), eax = this.
Body: dword arg1 to this+0; float arg2 to this+8; zero to this+4, +0xc, +0x10, +0x14, +0x24; byte 0 to this+0x28.
The object is 0x40 random bytes; args are random 32-bit values."""
from pilot import S


def _gen(c):
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5b7b90, 'GUESS (no name) struct init thiscall ret 8', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-11 batch 27 (gap band)')
