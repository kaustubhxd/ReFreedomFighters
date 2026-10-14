"""specs_s886.py - area 50, batch 886: 0x598d90 (GUESS name Append598d90), thiscall, four stack args (vector pointer, dword, float,
dword), ret 0x10, void. The table count is at this+0x1cff; the table fills from +0x4ff in 24-byte records. The count is drawn
below and at the capacity (0x100) so both branches run. The vector is a random 12-byte block (copied, not logged)."""
from pilot import S, F
from anim_common import rnd


def _gen(c):
    e, r = c.emu, c.rng
    self = rnd(c, 0x2000)
    n = r.choice([0, 1, 7, 0xfe, 0xff, 0x100, r.randint(0, 0xff)])
    e.w32(self + 0x1cff, n)
    vec = rnd(c, 0x10)
    a1 = r.getrandbits(32)
    a2 = r.choice([0.0, -0.0, 1.5, -3.25, 1e5, float('nan')]) if r.random() < 0.3 else r.uniform(-50, 50)
    a3 = r.getrandbits(32)
    return [self, vec, a1, F(a2), a3]


S(0x598d90, 'Append598d90 (GUESS name)', 'thiscall', None, gen=_gen, note='area50 batch886')
