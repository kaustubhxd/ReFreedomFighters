"""specs_s5717.py - unclaimed-57, batch 17: 0x4c2bc0 (GUESS). Thiscall, two float arguments (a, b), ret 8. Leaf: it reads two heap
pointers (this+0x44, then +0x18) and stores a's bits and b's truncation. The flag at +0xd1 is zero in half the cases. Values for b
include NaN and out-of-range values (the integer indefinite result), which the cvttss2si in the port reproduces."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _tb(c):
    obj = _rnd(c, 0x200)
    c.emu.wbytes(obj + 0xd1, bytes([0 if c.rng.random() < 0.5 else c.rng.getrandbits(8) | 1]))
    sub = _rnd(c, 0x200)
    tgt = _rnd(c, 0x200)
    c.emu.w32(sub + 0x18, tgt)
    c.emu.w32(obj + 0x44, sub)
    vals = [1.5, -2.7, 0.0, 1e10, -1e10, float('nan'), 2147483520.0]
    return [obj, F(c.rng.choice(vals)), F(c.rng.choice(vals))]


S(0x4c2bc0, 'unnamed_4c2bc0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_tb,
  note='unclaimed-57 batch 17; leaf; float bits and cvttss2si of two float args into a heap target')
