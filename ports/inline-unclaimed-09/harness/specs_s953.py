"""specs_s953.py - area 56 band, claim A12: 0x537a70 (store one argument at this+0x5302, return true).

The object is 0x5400 random bytes (the store reaches +0x5306). The argument is random. No callees."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    return [_rnd(c, 0x5400), c.rng.getrandbits(32)]


S(0x537a70, 'unnamed 0x537a70 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-56 A12; band list; no callees')
