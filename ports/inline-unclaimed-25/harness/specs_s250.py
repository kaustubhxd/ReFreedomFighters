"""specs_s250.py - unclaimed area 25, slice 4: 0x478a00.
Flag set: ext_4de420 copy plus three dwords out (eax = last). Flag clear: tail call to slot 0x80 of the object returned by slot 0x20.
Fakes: this has a logging vtable whose slot 0x20 returns a second object with a logging vtable (slot 0x80, 2 stack args)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _copy(c):
    obj = _rnd(c, 0x700)
    inner = _rnd(c, 0x40)
    ivt = c.emu.logging_vtable('Inner', 0x140, impl={0x80: lambda e, a: (c.rng.getrandbits(32), None)},
                               argwords={0x80: 2})
    c.emu.w32(inner, ivt)
    svt = c.emu.logging_vtable('Self', 0x140, impl={0x20: lambda e, a: (inner, None)}, argwords={})
    c.emu.w32(obj, svt)
    c.emu.w8(obj + 0x5d2, c.rng.choice([0, 1, 2, 0x80]))
    a1 = _rnd(c, 0x40)
    out = _rnd(c, 0x20)
    c.emu.mu.ctl_flush_tb()
    return [obj, a1, out]


S(0x478a00, 'copyTriple (GUESS name ZActor::CanPlayAnimSegment)', 'thiscall', None, ret='eax', gen=_copy,
  note='batch250; flag set copies 0x24 bytes and three dwords; flag clear tail-calls slot 0x80 of slot 0x20 result')
