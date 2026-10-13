"""specs_s34.py - inline session batch 34 (Haiku, night): PSVECAdd 0x441940 and PSVECSubtract 0x43e920 (x87 in the exe)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _add(c):
    return [_rnd(c, 0x20), _rnd(c, 0x20)]


S(0x441940, 'PSVECAdd', 'fastcall', None, ret=None, gen=_add, note='batch34; dst += src on three floats (x87 in the exe, float ops here)')


def _sub(c):
    return [_rnd(c, 0x20), _rnd(c, 0x20), _rnd(c, 0x20)]


S(0x43e920, 'PSVECSubtract', 'fastcall', None, ret=None, gen=_sub, note='batch34; dst = src - a on three floats; one stack arg')
