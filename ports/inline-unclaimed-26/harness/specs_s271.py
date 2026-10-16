"""specs_s271.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x5ac5d0, forwards one argument to each child in a
pointer array at this+0x1a (count at this+0x7f), through each child's slot 0x248."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _all(c):
    e = c.emu
    n = c.rng.randrange(0, 5)
    self_ = _rnd(c, 0x100)
    e.w32(self_ + 0x7f, n)
    for i in range(n):
        child_vt = e.logging_vtable('kid5ac%d' % i, 0x93, impl={}, argwords={0x248: 1})
        child = _rnd(c, 0x40)
        e.w32(child, child_vt)
        e.w32(self_ + 0x1a + 4 * i, child)
    return [self_, c.rng.getrandbits(32)]


S(0x5ac5d0, 'forwardAll (GUESS)', 'thiscall', None, ret=None, gen=_all, note='batch271; child slot 0x248; ret 4')
