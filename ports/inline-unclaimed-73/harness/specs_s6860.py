"""specs_s6860.py - area 73 batch 68 (gap band, GUESS name). FUN_4f9dc0 (plain ret): when [this+0x70] != 0x20: [this+0x6c] |= 2,
vtable +0x2ec(0x20) on this, r = vtable +0x2c4() on this; when r is non-null, vtable +0x2f4(this, 1) on r."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    e = c.emu
    o = _rnd(c, 0x100)
    e.w32(o + 0x70, c.rng.choice([0x20, c.rng.getrandbits(32)]))
    e.w32(o + 0x6c, c.rng.getrandbits(32))
    B = _rnd(c, 0x100)
    e.w32(B, e.logging_vtable('B9dc0', 0x300 // 4, impl={0x2f4: lambda em, a: (0, None)}, argwords={0x2f4: 2}))
    r = B if c.rng.random() < 0.6 else 0
    e.w32(o, e.logging_vtable('f9dc0', 0x300 // 4,
                              impl={0x2ec: lambda em, a: (0, None), 0x2c4: (lambda v: (lambda em, a: (v, None)))(r)},
                              argwords={0x2ec: 1, 0x2c4: 0}))
    return [o]


S(0x4f9dc0, 'GUESS FUN_4f9dc0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='area 73 batch 68; if [this+0x70] != 0x20: [this+0x6c] |= 2; vt+0x2ec(0x20); r = vt+0x2c4(); if r: vt(r)+0x2f4(this, 1)')
