"""specs_s955.py - area 56 band, claim A14: 0x53c1f0 (null for n == 0 or 0x80000000; else this + (n+1)*8).

The argument is 0, 0x80000000, 0xffffffff, or random (so each branch runs). Nothing is dereferenced; the object is 0x40 random bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    n = c.rng.choice([0, 0x80000000, 0xffffffff, c.rng.getrandbits(32)])
    return [_rnd(c, 0x40), n]


S(0x53c1f0, 'unnamed 0x53c1f0 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-56 A14; band list; pure, no callees')
