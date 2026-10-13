"""specs_s1114.py - unclaimed-11 batch 15 (slice 10): two leaves.
0x4d5120 IOFSMemoryAccess_t::nativeEof (high), thiscall, no args: al = (dword at this+8 >= dword at this+0xc), signed.
0x58a660 (GUESS: no matching name), thiscall, two stack args (ret 8): index = signed byte arg1; dword arg2 stored at this+0x2c2d+4*index.
The object is 0x3000 random bytes; the index is kept in -128..127 so the store stays inside the object."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x3000, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x3000)))
    return o


def _eof(c):
    # +8 and +0xc are equal in about 30% of cases (the >= boundary), otherwise random.
    o = _obj(c)
    v = c.rng.getrandbits(32)
    c.emu.w32(o + 8, v)
    c.emu.w32(o + 0xc, v if c.rng.random() < 0.3 else c.rng.getrandbits(32))
    return [o, 0]


def _slot(c):
    o = _obj(c)
    return [o, c.rng.randint(-128, 127) & 0xff, c.rng.getrandbits(32)]


S(0x4d5120, 'IOFSMemoryAccess_t::nativeEof (high) thiscall', 'thiscall', None, ret='al', gen=_eof,
  note='unclaimed-11 batch 15 (slice 10)')
S(0x58a660, 'GUESS byte-indexed dword slot store at +0x2c2d thiscall', 'thiscall', None, ret=None, gen=_slot,
  note='unclaimed-11 batch 15 (slice 10)')
