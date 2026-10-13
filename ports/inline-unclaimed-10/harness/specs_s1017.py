"""specs_s1017.py - unclaimed-10, batch 13: ZFFSimpleTrain2::CopyData (0x5b8550). Thiscall, one argument (source), ret 4.
Pure copy: the destination and the source are random 0x800-byte blocks, and every byte is compared. The base-part copy
0x4de420 is a leaf (no calls), so nothing is stubbed."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    return [_rnd(c, 0x800), _rnd(c, 0x800)]


S(0x5b8550, 'ZFFSimpleTrain2::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-10 batch 13; field copies; base part 36 bytes at +0xb7 (0x4de420 inlined)')
