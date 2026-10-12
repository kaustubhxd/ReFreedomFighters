"""specs_s234.py - area 59, batch234 (src/batch234.cpp): 0x45b620, a ring of ids. Capacity is a power of two (the
original masks with cap - 1), every cursor and every list entry is below the capacity, so the table and buffer writes stay
in their arrays. 0x45c0e0 is a recorder (ecx and the id)."""
from pilot import S
from helpers22 import _rnd, _rec_ecx


def _g_45b620(c):
    cap = c.rng.choice([4, 8, 16])
    self_ = _rnd(c, 0x100)
    c.emu.w32(self_ + 0x1c, cap)
    c.emu.w32(self_ + 0x30, c.rng.randrange(0, cap + 1))
    c.emu.w32(self_ + 0x34, cap - 1 if c.rng.random() < 0.4 else c.rng.randrange(0, cap))
    c.emu.w32(self_ + 0x38, c.rng.randrange(0, cap))
    c.emu.w32(self_ + 0x3c, c.rng.randrange(0, cap))
    buf = _rnd(c, cap)
    lst = _rnd(c, cap * 4)
    tab = _rnd(c, cap * 4)
    for i in range(cap):
        c.emu.w32(lst + 4 * i, c.rng.randrange(0, cap))
    c.emu.w32(self_ + 0x248, buf)
    c.emu.w32(self_ + 0x24c, lst)
    c.emu.w32(self_ + 0x250, tab)
    _rec_ecx(c, 0x45c0e0, 1)
    return [self_]


S(0x45b620, 'ringPop (GUESS)', 'thiscall', None, ret=None, gen=_g_45b620,
  note='batch234; id ring with a stack and a cursor; 0x45c0e0 recorded')
