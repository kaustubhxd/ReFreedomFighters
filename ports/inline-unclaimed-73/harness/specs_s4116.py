"""specs_s4116.py - area 73 batch 16 (gap band, GUESS names): FUN_4f3930 (dword store), FUN_4f3e60 (render control slot +0x58
with this+0x60; the slot's result is discarded), FUN_4f22e0 (two dwords copied to a heap output pointer)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setter(c):
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


def _f3e60(c):
    e = c.emu
    self_o = _rnd(c, 0x100)
    e.w32(self_o + 0x60, c.rng.getrandbits(32))
    ctl = _rnd(c, 0x100)
    e.w32(ctl, e.logging_vtable('ctl58b', 0x60 // 4, impl={0x58: lambda em, a: (0, None)}, argwords={0x58: 1}))
    sys = _rnd(c, 0x200)
    e.w32(sys + 0x9b, ctl)
    e.w32(0x70039c, sys)
    return [self_o]


def _f22e0(c):
    self_o = _rnd(c, 0x100)
    out = _rnd(c, 0x20)
    return [self_o, out]


S(0x4f3930, 'GUESS FUN_4f3930 (unknown) thiscall', 'thiscall', None, ret=None, gen=_setter,
  note='area 73 batch 16; dword store at +0x97')
S(0x4f3e60, 'GUESS FUN_4f3e60 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f3e60,
  note='area 73 batch 16; render control slot +0x58(this+0x60)')
S(0x4f22e0, 'GUESS FUN_4f22e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_f22e0,
  note='area 73 batch 16; copy this+0x77 and +0x7b to the output pointer')
