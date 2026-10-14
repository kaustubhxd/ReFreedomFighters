"""specs_s5732.py - unclaimed-57, band batch 32: 0x5d5970 (thiscall, no args). Stubs: the object's own vtable slot +0x110 (two arguments,
logged); the sub-object at +0x25 (set in half the cases) with slot +0x25c (one argument, logged). Leaf otherwise."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tenth(c):
    vt_sub = c.emu.logging_vtable('band5d5970_sub', 160, argwords={0x25c: 1})
    vt_self = c.emu.logging_vtable('band5d5970_self', 72, argwords={0x110: 2})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt_sub)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj, vt_self)
    c.emu.w32(obj + 8, c.rng.getrandbits(32))
    c.emu.w32(obj + 0x25, sub if c.rng.random() < 0.5 else 0)
    return [obj]


S(0x5d5970, 'unnamed_5d5970 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_tenth,
  note='unclaimed-57 band batch 32; sub slot +0x25c and this slot +0x110 stubbed (logged)')
