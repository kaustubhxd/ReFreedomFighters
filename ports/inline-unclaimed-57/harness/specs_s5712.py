"""specs_s5712.py - unclaimed-57, batch 12: three small thiscall functions with one stack argument (ret 4). No stubs: none of them calls
anything. 0x4db580 and 0x533500 are indexed reads (indices kept in range: the object is big enough for every index, so the original
does not fault); 0x5ea840 stores a float's bits (the sign test decides between the argument and zero; NaN and -0.0 are among the
values)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _small_idx(c):
    o = _rnd(c, 0x800)
    c.emu.wbytes(o + 0x1c, bytes([c.rng.randrange(0, 9)]))
    return [o, c.rng.randrange(0, 9)]


def _big_idx(c):
    o = _rnd(c, 0x6600)
    c.emu.w32(o + 0x546e, 0 if c.rng.random() < 0.4 else c.rng.getrandbits(32))
    return [o, c.rng.randrange(0, 0x400)]


def _float_arg(c):
    o = _rnd(c, 0x2000)
    v = c.rng.choice([0.0, -0.0, -1.5, 2.5, float('nan'), 1e30, -1e-30])
    return [o, F(v)]


S(0x4db580, 'unnamed_4db580 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_small_idx,
  note='unclaimed-57 batch 12; leaf; index into the dword array at +0, bounded by the byte at +0x1c')
S(0x5ea840, 'ZGameOSD::SetBombTime (unknown) thiscall', 'thiscall', None, ret=None, gen=_float_arg,
  note='unclaimed-57 batch 12; leaf; float bits to +0x1d13, or 0 when the argument is negative')
S(0x533500, 'unnamed_533500 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_big_idx,
  note='unclaimed-57 batch 12; leaf; element at +0x5462 + 4*idx when +0x546e is non-zero')
