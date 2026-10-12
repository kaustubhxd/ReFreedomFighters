"""specs_s938.py - unclaimed-80 bottom-up leaf (docs/20-unclaimed-80.md): 0x4e1590, the item size at the cursor (this+8). The buffer
is 0x40 random bytes with a zero at offset 40 (so the string case terminates inside it). The tag byte is 0xff (10%), a value in
0..0x3f (80%), or anything (10%); the 0x3f mask and the map cover every case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _size(c):
    buf = _rnd(c, 0x40)
    r = c.rng.random()
    if r < 0.1:
        tag = 0xff
    elif r < 0.9:
        tag = c.rng.randint(0, 0x3f)
    else:
        tag = c.rng.getrandbits(8)
    c.emu.wbytes(buf, bytes([tag]))
    c.emu.wbytes(buf + 40, b'\x00')
    if c.rng.random() < 0.3:
        c.emu.wbytes(buf + c.rng.randint(2, 39), b'\x00')
    self_o = _rnd(c, 0x20)
    c.emu.w32(self_o + 8, buf)
    return [self_o]


S(0x4e1590, 'DBLK item size (unknown) thiscall', 'thiscall', None, ret='eax', gen=_size,
  note='unclaimed-80 bottom-up leaf for CopyDataBlock; the same table as the DBLK item walker stub')
