"""specs_s278.py - unclaimed area 76 (docs/20-unclaimed-76.md), slice 15 small leaf: 0x45fab0, a.vtbl[0x168](b, c) then
a.vtbl[0x124](0x20, c, (u16)b, this) on the first stack argument."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _two(c):
    e = c.emu
    a_vt = e.logging_vtable('a45fab', 0x5b, impl={}, argwords={0x168: 2, 0x124: 4})
    A = _rnd(c, 0x40)
    e.w32(A, a_vt)
    self_ = _rnd(c, 0x40)
    return [self_, A, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x45fab0, 'twoStep (GUESS)', 'thiscall', None, ret=None, gen=_two, note='batch278; ret 0xc')
