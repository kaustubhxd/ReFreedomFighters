"""specs_s939.py - unclaimed-80 (docs/20-unclaimed-80.md): GUESS FUN_4e1440 (0x4e1440). The cursor buffer's tag is 4 or 5 with random
high bits (0x40, 0x80, 0xc0 possible), never 0xff and never another low-six-bit value, so the invalid branch is not reached. Each item
is a zero-terminated string of random bytes (a zero at offset 40 keeps the length inside the buffer). The out pointer is a heap record.
The item size is the original 0x4e1590 (its tag 4 and 5 both map to the string case)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _step(c):
    buf = _rnd(c, 0x40)
    tag = c.rng.choice([4, 5]) | c.rng.choice([0, 0x40, 0x80, 0xc0])
    c.emu.wbytes(buf, bytes([tag]))
    c.emu.wbytes(buf + 40, b'\x00')
    if c.rng.random() < 0.3:
        c.emu.wbytes(buf + c.rng.randint(2, 39), b'\x00')
    self_o = _rnd(c, 0x20)
    c.emu.w32(self_o + 8, buf)
    out = _rnd(c, 8)
    return [self_o, out]


S(0x4e1440, 'GUESS FUN_4e1440 (DBLK cursor step) (unknown) thiscall', 'thiscall', None, ret=None, gen=_step,
  note='unclaimed-80 GUESS; valid tags 4 and 5 only; item size is the original 0x4e1590')
