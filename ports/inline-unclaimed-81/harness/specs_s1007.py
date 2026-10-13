"""specs_s1007.py - area 81 (residue 0), batch 1007: CExplodeMolotov::Load (0x5846c0). The helpers 0x6352f0, 0x584bc0 and 0x4e7480 are counting stubs
(the first two ignore their stack-address argument). The load object lg has slots 0x40 (returns an object with slots 0x40 and 0x6c), 0x68 (returns an
object with slot 0x6c), and 0x50, 0x6c, 0x74 as counting stubs. The float at each element's +0x28 is zero about one time in three. The global chain
(0x7003b8 -> +0x2c51 -> list counter at +0x750) holds a small random count so both appends and skips run."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
import serial_stubs as ss
from pilot import S
from vh import _stub, obj, r32, rf


def g(c):
    ss.patch(c, 0x6352f0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x584bc0, ss.rec(c, 1, log=False))
    ss.patch(c, 0x4e7480, ss.rec(c, 1))
    obj40 = obj(c, 0x40, {0x40: _stub(c, 1), 0x6c: _stub(c, 1)})
    obj68 = obj(c, 0x40, {0x6c: _stub(c, 1)})
    lg = obj(c, 0x40, {0x40: _stub(c, 1, ret=obj40), 0x50: _stub(c, 1), 0x68: _stub(c, 1, ret=obj68),
                       0x6c: _stub(c, 1), 0x74: _stub(c, 1)})
    self_ = obj(c, 0x500)
    c.emu.w32(self_ + 4, r32(c))
    for i in range(5):
        v = 0 if c.rng.random() < 0.33 else rf(c, -2, 2)
        c.emu.w32(self_ + 0x222 + 0x44 * i + 0x28, v)
    gg = obj(c, 0x3000)
    base = obj(c, 0x1000)
    c.emu.w32(gg + 0x2c51, base)
    c.emu.w32(base + 0x750, c.rng.randint(0, 40))
    c.emu.w32(0x7003b8, gg)
    return [self_, lg]


S(0x5846c0, 'CExplodeMolotov::Load', 'thiscall', None, ret='al', gen=g)
