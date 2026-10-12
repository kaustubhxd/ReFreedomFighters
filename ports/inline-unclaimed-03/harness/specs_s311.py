"""specs_s311.py - unclaimed-03 batch 11 (docs/20-unclaimed-03.md): ZOnScreenDisplay::MapIconAdd (0x5aa660), thiscall with
four stack arguments (ret 0x10). The object is 0x1000 random bytes; the index at +0x69d is drawn from 0..15 so the
tables stay inside the object. The position argument is a 3-float buffer. The stores are compared in the heap."""
from pilot import S
import sys, os
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    o = _rnd(c, 0x1000)
    c.emu.w32(o + 0x69d, c.rng.randint(0, 15))
    pos = _rnd(c, 12)
    return [o, pos, c.rng.getrandbits(32), c.rng.getrandbits(8), c.rng.getrandbits(32)]


S(0x5aa660, 'ZOnScreenDisplay::MapIconAdd (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen,
  note='unclaimed-03 batch 11; leaf, index at +0x69d, stores into tables at +0x6a1, +0x7c1, +0x881, +0x821')
