"""specs_s1116.py - unclaimed-11 batch 17 (slice 10, full list), thiscall with one pointer argument, ret 4, no names.

0x64dde0 (GUESS): copies 16 bytes from *arg to this+0x10061.
The argument is a 0x40-byte buffer; the 'equal' case is produced in about half the cases for 0x441420."""
from pilot import S


def _obj(c):
    o = c.emu.alloc(0x10100, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x10100)))
    return o


def _cmp(c):
    o = _obj(c)
    buf = c.emu.alloc(0x40, 4)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    v = c.rng.getrandbits(32)
    c.emu.w32(buf, v)
    c.emu.w32(o + 8, v if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    c.emu.w32(o + 0x4c, 0 if c.rng.random() < 0.7 else c.rng.getrandbits(32))
    return [o, buf]


def _copy(c):
    o = _obj(c)
    buf = c.emu.alloc(0x40, 4)
    c.emu.wbytes(buf, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [o, buf]


S(0x64dde0, 'GUESS (no name) copy 16 bytes thiscall', 'thiscall', None, ret=None, gen=_copy, note='unclaimed-11 batch 17')
