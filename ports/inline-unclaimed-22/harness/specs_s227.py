"""specs_s227.py - unclaimed area 22, batch227 (src/batch227.cpp): 0x59d450, the eight-way mode table (parked in
docs/20-unclaimed-20.md, verified here). No stubs: a pure function of this's words."""
from pilot import S
from helpers22 import _rnd


def _g_59d450(c):
    self_ = _rnd(c, 0x40)
    c.emu.w32(self_ + 4, c.rng.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0xffffffff, c.rng.getrandbits(32)]))
    c.emu.w32(self_ + 8, c.rng.choice([0, 1, 2, 3, 4]))
    c.emu.w32(self_ + 0xc, c.rng.getrandbits(32))
    c.emu.w32(self_ + 0x10, c.rng.getrandbits(32))
    return [self_]


S(0x59d450, 'setModeFlags (GUESS)', 'thiscall', None, ret=None, gen=_g_59d450,
  note='batch227; eight-way table on [this+4]; [this+8] == 3 clears [this+0xc]')
