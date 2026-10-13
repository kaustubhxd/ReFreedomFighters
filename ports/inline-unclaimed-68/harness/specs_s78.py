"""specs_s78.py - unclaimed-68 batch 78 (slice 7). Names GUESS (FUN_addr). Virtual slots are logged stubs."""
from pilot import S
from engine_stubs import zero_obj, logged_obj


def _g42cb30(c):
    o = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('ZSlot42cb30', 0x800, impl={0x1bc: (lambda v: (lambda e, a: (v, None)))(c.rng.getrandbits(32))},
                              argwords={0x1bc: 2})
    c.emu.w32(o, vt)
    return [o, c.rng.getrandbits(32), c.rng.getrandbits(32)]


def _g63cfb0(c):
    o = zero_obj(c, 0x100)
    vt = c.emu.logging_vtable('ZSlot63cfb0', 0x200, impl={}, argwords={0x58: 2})
    c.emu.w32(o, vt)
    tab = zero_obj(c, 0x100)
    for i in range(0x40):
        c.emu.w32(tab + 4 * i, c.rng.getrandbits(32))
    c.emu.w32(o + 0x68, tab)
    rec = zero_obj(c, 0x80)
    c.emu.wbytes(rec + 0x5a, bytes([c.rng.randrange(256), c.rng.randrange(256)]))
    obj = zero_obj(c, 0x40)
    c.emu.w32(obj + 8, rec)
    return [o, c.rng.getrandbits(32), obj]


S(0x42cb30, 'FUN_42cb30 (GUESS) thiscall', 'thiscall', None, ret='st0', gen=_g42cb30,
  note='unclaimed-68 batch 78: float of slot +0x1bc(a1, a2) scaled by constants')
S(0x63cfb0, 'FUN_63cfb0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_g63cfb0,
  note='unclaimed-68 batch 78: slot +0x58(table[word & 0xfff], 0) when the word is nonzero')
