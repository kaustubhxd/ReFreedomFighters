"""specs_s264.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x4a1190, engine object o: slots 0x138, 0x4c, 0x114."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    e = c.emu
    child_vt = e.logging_vtable('child4a1', 0x19, impl={}, argwords={0x60: 2})
    child = _rnd(c, 0x40)
    e.w32(child, child_vt)
    r4c = c.rng.getrandbits(32)
    w1 = c.rng.getrandbits(16)
    w2 = c.rng.getrandbits(16)
    o_vt = e.logging_vtable('obj4a1', 0x4f, impl={0x138: lambda em, a: (child, None),
                                                   0x4c: lambda em, a: (r4c, None),
                                                   0x114: lambda em, a: (w1 if a[0] == 0x68f774 else w2, None)},
                            argwords={0x138: 0, 0x4c: 2, 0x114: 4})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    self_ = _rnd(c, 0x900)
    e.w32(self_ + 0x44, c.rng.getrandbits(32))
    return [self_]


S(0x4a1190, 'setup (GUESS)', 'thiscall', None, ret=None, gen=_setup,
  note='batch264; engine o slots 0x138, 0x4c, 0x114; child slot 0x60')
