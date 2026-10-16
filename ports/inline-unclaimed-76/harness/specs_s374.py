"""specs_s374.py - area 76, residue 18, batch 374: 0x43bbe0 (thiscall, one stack argument, ret 4; GUESS). Both objects are 0x200 random bytes;
the writes land inside them, and both sides see the same bytes."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    a = e.alloc(0x200, 4)
    e.wbytes(a, rng.randbytes(0x200))
    this = e.alloc(0x300, 4)
    e.wbytes(this, rng.randbytes(0x300))
    return [this, a]


S(0x43bbe0, 'init43bbe0 (GUESS)', 'thiscall', None, ret=None, gen=_gen,
  note='area 76 batch 374; residue 18')
