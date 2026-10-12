"""specs_s784.py - unclaimed-77 claim 14 (docs/20-unclaimed-77.md): ZTreeGroup::CheckDynamicLineColi. Thiscall, six stack arguments,
ret 24, returns al = 0. The function reads none of its arguments; the spec passes random values (the enum, two pointers, a bool, two ints)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    self = _rnd(c, 0x40)
    return [self, c.rng.getrandbits(32), _rnd(c, 16), _rnd(c, 16), c.rng.getrandbits(8), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4429c0, 'ZTreeGroup::CheckDynamicLineColi (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-77 claim 14; constant false, six arguments unread')
