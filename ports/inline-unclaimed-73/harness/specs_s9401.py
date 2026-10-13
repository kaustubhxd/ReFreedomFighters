"""specs_s9401.py - residue 6 batch 94 (GUESS names).
0x54bba0 (thiscall, ret pointer): Returns address of [this+0x2c].
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_54bba0(c):
    # 0x54bba0: thiscall() -> void* - returns address of [this+0x2c]
    e = c.emu

    # Create this object
    this_obj = _rnd(c, 0x40)

    return [this_obj]


S(0x54bba0, 'GUESS FUN_0054bba0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_54bba0,
  note='residue 6 batch 94; returns address of [this+0x2c]')
