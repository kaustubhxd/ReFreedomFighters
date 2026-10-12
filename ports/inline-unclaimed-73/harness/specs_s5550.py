"""specs_s5550.py - area 73 batch 55 (gap band, GUESS names). FUN_4fe0c0 copies four words (+0x49, +0x4b, +0x4d, +0x4f) from
the argument into this. FUN_4f3260 stores the argument's low byte at this+0x5fc, calls vtable +0x334 with the byte at
this+0x5fb, and returns the old byte at +0x5fc. FUN_4f04a0 reads the string pointer at this+0x9b: when its first byte is
'%' it calls vtable +0x284 with the string past the '%', otherwise +0x288 with (0x677b5a, string)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_4fe0c0(c):
    return [_rnd(c, 0x100), _rnd(c, 0x100)]


def _gen_4f3260(c):
    e = c.emu
    o = _rnd(c, 0x600)
    rv = c.rng.getrandbits(8)
    e.wbytes(o + 0x5fc, bytes([rv]))
    e.wbytes(o + 0x5fb, bytes([c.rng.getrandbits(8)]))
    e.w32(o, e.logging_vtable('f3260', 0x340 // 4, impl={0x334: lambda em, a: (0, None)}, argwords={0x334: 1}))
    return [o, c.rng.getrandbits(32)]


def _gen_4f04a0(c):
    e = c.emu
    o = _rnd(c, 0x100)
    s = _rnd(c, 0x20)
    if c.rng.random() < 0.5:
        e.wbytes(s, b'%')
    e.w32(o + 0x9b, s)
    e.w32(o, e.logging_vtable('f04a0', 0x290 // 4,
                              impl={0x284: lambda em, a: (0, None), 0x288: lambda em, a: (0, None)},
                              argwords={0x284: 1, 0x288: 2}))
    return [o]


S(0x4fe0c0, 'GUESS FUN_4fe0c0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4fe0c0,
  note='area 73 batch 55; copies words +0x49,+0x4b,+0x4d,+0x4f from the argument into this')
S(0x4f3260, 'GUESS FUN_4f3260 (unknown) thiscall', 'thiscall', None, ret='al', gen=_gen_4f3260,
  note='area 73 batch 55; old byte +0x5fc returned, new byte stored, vt+0x334(byte +0x5fb)')
S(0x4f04a0, 'GUESS FUN_4f04a0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_4f04a0,
  note='area 73 batch 55; string at +0x9b: "%" prefix -> vt+0x284(s+1), else vt+0x288(0x677b5a, s)')
