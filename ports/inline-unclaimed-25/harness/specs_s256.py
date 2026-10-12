"""specs_s256.py - unclaimed area 25: 0x5c6610 (three helper reads from the block; float results via st0)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    # blk[0] is a pointer to a tagged value: byte 0 = tag (low 6 bits 1..11), dword at +1 and +5 (the helpers read it).
    self_ = _rnd(c, 0x100)
    blk = _rnd(c, 0x40)
    val = _rnd(c, 0x20)
    c.emu.wbytes(val, bytes([c.rng.randint(1, 11)]) + bytes(c.rng.getrandbits(8) for _ in range(0x1f)))
    c.emu.w32(blk, val)
    c.emu.mu.ctl_flush_tb()
    return [self_, blk]


S(0x5c6610, 'ZFFSearchLightGroup::CopyEventDataBlock (residue name)', 'thiscall', None, ret=None, gen=_copy,
  note='batch256; three helper calls on the block, float results via st0')
