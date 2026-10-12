"""specs_s945.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): ZGROUP::AddLine (0x43eb00). The object at [g+0x9b] (g from the
global 0x70039c) has a logging vtable with slots +0x58 and +0x4c (one argument each, callee-cleaned). Its sub-object at +0xadc has
slot +0x294 (four arguments, callee-cleaned). The tail call 0x65f400 (xor eax,eax; ret 0xc) is a recording stub returning 0.
Both branches are reached: slot +0x58 returns zero half the time (then the second block runs)."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    r58 = 0 if c.rng.random() < 0.5 else (c.rng.getrandbits(32) | 1)
    r294 = c.rng.getrandbits(32)
    r4c = c.rng.getrandbits(32)
    cobj = _rnd(c, 0x40)
    c.emu.w32(cobj, c.emu.logging_vtable('ZGroupSub', 0xa6, impl={0x294: (lambda e, a, v=r294: (v, None))},
                                        argwords={0x294: 4}))
    obj = _rnd(c, 0xb00)
    c.emu.w32(obj + 0xadc, cobj)
    c.emu.w32(obj, c.emu.logging_vtable('ZGroupObj', 0x17,
                                        impl={0x58: (lambda e, a, v=r58: (v, None)),
                                              0x4c: (lambda e, a, v=r4c: (v, None))},
                                        argwords={0x58: 1, 0x4c: 1}))
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, obj)
    c.emu.w32(0x70039c, g)
    ss.patch(c, 0x65f400, ss.rec(c, 3, ret=0))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x43eb00, 'ZGROUP::AddLine (unknown) thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-80 gap band; slots +0x58/+0x4c on the object, +0x294 on its sub-object at +0xadc, tail 0x65f400 recorded')
