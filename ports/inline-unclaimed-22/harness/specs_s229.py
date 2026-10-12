"""specs_s229.py - unclaimed area 22, batch229 (src/batch229.cpp): 0x5a5dd0, single-precision frame math with one tan call.
The tan call is the real libm slot (pe_emu's math stub) on both sides. No stubs."""
from pilot import S, F
from helpers22 import _rnd


def _g_5a5dd0(c):
    self_ = _rnd(c, 0x900)
    c.emu.wf32(self_ + 0x2f4, c.rng.uniform(0.5, 5.0))
    c.emu.wbytes(self_ + 0x658, bytes([c.rng.choice([0, 1, 7])]))
    c.emu.w32(self_ + 0x8d0, c.rng.choice([1, 2, 3]))
    P = _rnd(c, 0x40)
    Q = _rnd(c, 0x80)
    c.emu.w32(P + 8, Q)
    c.emu.wf32(Q + 0x44, c.rng.uniform(-3.0, 3.0))
    B = _rnd(c, 0x80)
    c.emu.wf32(B + 0x5c, c.rng.uniform(-2.0, 2.0))
    c.emu.wf32(B + 0x40, c.rng.choice([0.5, -2.0, c.rng.uniform(0.5, 4.0)]))
    out = _rnd(c, 0x10)
    return [self_, out, F(c.rng.uniform(-4.0, 4.0)), F(c.rng.uniform(-4.0, 4.0)), P, B]


S(0x5a5dd0, 'frameFromTan (GUESS)', 'thiscall', None, ret=None, gen=_g_5a5dd0,
  note='batch229; single-precision frame math, tan via the libm slot')
