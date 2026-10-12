"""specs_s1022.py - unclaimed-07 batch 22 (slice 6): ZLINEOBJ::SetWidth (0x4f4760). The object's vtable slot +0x294 is a
logging stub (no arguments). The +0xac field is zero about half the time."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _width(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o, e.logging_vtable('lineobj', 0x298 // 4, impl={0x294: lambda em, a: (0, None)}, argwords={0x294: 0}))
    e.w32(o + 0xac, 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32))
    return [o, c.rng.getrandbits(32)]


S(0x4f4760, 'ZLINEOBJ::SetWidth (unknown) thiscall', 'thiscall', None, ret=None, gen=_width,
  note='unclaimed-07 batch 22; stores arg at +0xb0; slot +0x294 when +0xac non-zero')
