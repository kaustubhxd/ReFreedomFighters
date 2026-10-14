"""specs_s199.py - unclaimed area 19 (docs/20-unclaimed-19.md): 0x5143a0 calls exe helper 0x523b10 (not claimed)."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    return F(c.rng.uniform(-1e6, 1e6) if c.rng.random() < 0.5 else c.rng.uniform(0, 200))


def _set(c):
    e = c.emu
    obj = _rnd(c, 0x200)
    e.w32(obj + 0x63, 0)
    vt = e.logging_vtable('obj523b', 8, impl={}, argwords={})
    e.w32(obj, vt)
    self_ = _rnd(c, 0x200)
    e.w32(self_ + 0x5c, obj)
    return [self_, _f(c), _f(c), _f(c), _f(c)]


S(0x5143a0, 'setFloats (GUESS)', 'thiscall', None, ret=None, gen=_set, note='batch199; calls exe 0x523b10; ret 0x10')
