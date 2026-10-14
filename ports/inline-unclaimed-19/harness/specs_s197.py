"""specs_s197.py - unclaimed area 19 (docs/20-unclaimed-19.md): 0x45c160 calls exe helper 0x45f960 (not claimed)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _wrap(c):
    e = c.emu
    obj_vt = e.logging_vtable('obj45f9', 16, impl={0x3c: lambda em, a: (0, None)}, argwords={0x3c: 1})
    obj = _rnd(c, 0x40)
    e.w32(obj, obj_vt)
    self_ = _rnd(c, 0x40)
    e.w32(self_ + 0x14, c.rng.getrandbits(32))
    if c.rng.random() < 0.6:
        p = _rnd(c, 0x40)
        e.w32(p + 0x18, c.rng.getrandbits(32))
        e.w32(self_ + 0x10, p)
    else:
        e.w32(self_ + 0x10, 0)
    return [self_, obj]


S(0x45c160, 'boolWrap (GUESS)', 'thiscall', None, ret='al', gen=_wrap, note='batch197; calls exe 0x45f960; ret 4')
