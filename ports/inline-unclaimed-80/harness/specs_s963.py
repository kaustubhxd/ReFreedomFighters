"""specs_s963.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x4450b0 (see src/batch963.cpp). The predicate 0x441790 (claimed elsewhere)
is hooked by address with a recording stub returning a per-case bool (true 70%). The argument object has a logging vtable with slots +0x3c
and +0x20 (one argument each). The field at self+0xa4 is a logging object (null 40%) whose slot +0x14 returns a per-case value."""
import serial_stubs as ss
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    ss.patch(c, 0x441790, ss.rec(c, 1, ret=1 if c.rng.random() < 0.7 else 0))
    self_o = _rnd(c, 0x200)
    if c.rng.random() < 0.4:
        c.emu.w32(self_o + 0xa4, 0)
    else:
        r14 = c.rng.getrandbits(32)
        g = _rnd(c, 0x40)
        c.emu.w32(g, c.emu.logging_vtable('ZGroupGa4', 0x6, impl={0x14: (lambda e, a, v=r14: (v, None))}))
        c.emu.w32(self_o + 0xa4, g)
    o = _rnd(c, 0x100)
    c.emu.w32(o, c.emu.logging_vtable('ZGroupObjB', 0x11, argwords={0x3c: 1, 0x20: 1}))
    return [self_o, o]


S(0x4450b0, 'predicate then vtable calls (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen,
  note='unclaimed-80 gap band; predicate 0x441790 hooked by address (claimed elsewhere); one stack argument, ret 4')
