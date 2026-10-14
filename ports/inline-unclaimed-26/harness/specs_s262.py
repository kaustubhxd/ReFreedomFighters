"""specs_s262.py - unclaimed area 26 (docs/20-unclaimed-26.md): 0x513510, record fill through vtable slots on A and
the engine object's slot 0x58."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fill(c):
    e = c.emu
    avt = e.logging_vtable('objA513', 28, impl={}, argwords={0x40: 1, 0x50: 1, 0x6c: 1})
    A = _rnd(c, 0x40)
    e.w32(A, avt)
    r = c.rng.getrandbits(32)
    o_vt = e.logging_vtable('eng9b513', 0x17, impl={0x58: lambda em, a: (r, None)},
                            argwords={0x58: 1})
    o = _rnd(c, 0x40)
    e.w32(o, o_vt)
    eng = _rnd(c, 0x200)
    e.w32(eng + 0x9b, o)
    e.w32(0x70039c, eng)
    out = _rnd(c, 0x40)
    return [out, A]


S(0x513510, 'fillRecord (GUESS)', 'thiscall', None, ret='al', gen=_fill,
  note='batch262; vtable calls on A (0x40, 0x50, 0x6c) and engine slot 0x58; ret 4')
