"""specs_s9501.py - residue 6 batch 95 (GUESS names).
0x5acfe0 (thiscall, ret pointer): Returns address of [this+8].
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_5acfe0(c):
    # 0x5acfe0: thiscall() -> void* - returns address of [this+8]
    e = c.emu

    # Create this object
    this_obj = _rnd(c, 0x20)

    return [this_obj]


S(0x5acfe0, 'GUESS FUN_005acfe0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen_5acfe0,
  note='residue 6 batch 95; returns address of [this+8]')
