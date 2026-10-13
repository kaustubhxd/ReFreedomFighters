"""specs_s8383.py - residue 6 batch 83 (GUESS name). FUN_004d7520 (thiscall, one stack argument, ret 4): [this+0x1d] = arg."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    return [_rnd(c, 0x40), c.rng.getrandbits(32)]


S(0x4d7520, 'GUESS FUN_004d7520 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='residue 6 batch 83; [this+0x1d] = arg; ret 4')
