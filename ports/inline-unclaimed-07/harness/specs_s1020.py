"""specs_s1020.py - unclaimed-07 batch 20 (slice 6): ZFFHintBox::Save (0x5b7760) and CMPCheckInsideHill::CopyData
(0x5d3aa0). The save object is a logging vtable (slots +0x3c and +0x44 take one argument). CopyData copies two dwords
between two random objects; the destination's dwords are compared through the heap."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _save(c):
    e = c.emu
    o = _rnd(c, 0x100)
    s = _rnd(c, 0x40)
    e.w32(s, e.logging_vtable('zsave_hint', 0x48 // 4, impl={0x3c: lambda em, a: (0, None), 0x44: lambda em, a: (0, None)},
                              argwords={0x3c: 1, 0x44: 1}))
    return [o, s]


def _copy(c):
    self_o = _rnd(c, 0x100)
    src = _rnd(c, 0x100)
    return [self_o, src]


S(0x5b7760, 'ZFFHintBox::Save (unknown) thiscall', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-07 batch 20; clears bit 0x40 at +4; save slot +0x44(+0x4c) then +0x3c(+0x48)')
S(0x5d3aa0, 'CMPCheckInsideHill::CopyData (unknown) thiscall', 'thiscall', None, ret=None, gen=_copy,
  note='unclaimed-07 batch 20; copies src+0x4c and src+0x50')
