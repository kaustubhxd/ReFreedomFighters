"""specs_s9601.py - residue 6 batch 96 (GUESS names).
0x4643e0 (thiscall, ret void): Stores two arguments at [this+0x5c] and [this+0x64].
"""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4643e0(c):
    # 0x4643e0: thiscall(a, b) -> void - stores a at [this+0x5c] and b at [this+0x64]
    e = c.emu

    # Create this object
    this_obj = _rnd(c, 0x70)

    # Create arguments
    arg_a = c.rng.getrandbits(32)
    arg_b = c.rng.getrandbits(32)

    return [this_obj, arg_a, arg_b]


S(0x4643e0, 'GUESS FUN_004643e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4643e0,
  note='residue 6 batch 96; stores two arguments at [this+0x5c] and [this+0x64]')
