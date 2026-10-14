"""specs_s954.py - area 56 band, claim A13: 0x524350 (stores zeros and a constant, returns this). The object is 0x40 random
bytes; no callees."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    return [_rnd(c, 0x40)]


S(0x524350, 'unnamed 0x524350 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A13; band list; no callees')
