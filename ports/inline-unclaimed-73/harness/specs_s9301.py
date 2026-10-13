"""specs_s9301.py - residue 6 batch 93 (GUESS names).
0x4f0020 (thiscall, ret byte): Returns byte from [this+0x20].
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4f0020(c):
    # 0x4f0020: thiscall() -> u8 - returns byte from [this+0x20]
    e = c.emu

    # Create this object with a byte at +0x20
    this_obj = _rnd(c, 0x30)
    byte_val = c.rng.getrandbits(8)
    e.wbytes(this_obj + 0x20, bytes([byte_val]))

    return [this_obj]


S(0x4f0020, 'GUESS FUN_004f0020 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_4f0020,
  note='residue 6 batch 93; returns byte from [this+0x20]')
