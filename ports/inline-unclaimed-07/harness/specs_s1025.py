"""specs_s1025.py - unclaimed-07 batch 25 (slice 6): ZTreeGroup::MoveGlobalBound (0x443aa0). The four table entries at
this+0x5d are logging objects whose slot +8 takes three arguments (the last three of the five; the second is unused).
The type index is 0..3."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _move(c):
    e = c.emu
    o = _rnd(c, 0x200)
    for t in range(4):
        obj = _rnd(c, 0x40)
        e.w32(obj, e.logging_vtable('tree%d' % t, 0x10 // 4 + 1, impl={8: lambda em, a: (0, None)}, argwords={8: 3}))
        e.w32(o + 0x5d + 4 * t, obj)
    typ = c.rng.randint(0, 3)
    return [o, typ, c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x443aa0, 'ZTreeGroup::MoveGlobalBound (unknown) thiscall', 'thiscall', None, ret=None, gen=_move,
  note='unclaimed-07 batch 25; table entry this+0x5d+4*type, slot +8 with args 3..5')
