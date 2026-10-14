"""specs_s985.py - residue-11, batch 985: CActionController::Save (0x4a1bf0). The save object's slots (0x40, 0x44, 0x3c) are counting stubs.
The element count is 0..4 (the zero and negative cases skip the loop), and each element is an object whose dword is random."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, obj, r32


def g(c):
    s = obj(c, 0x40, {0x40: _stub(c, 1), 0x44: _stub(c, 1), 0x3c: _stub(c, 1)})
    t = obj(c, 0x200)
    cnt = c.rng.choice([0, 1, 2, 3, 4, -1])
    c.emu.w32(t + 0x48, cnt & 0xffffffff)
    for i in range(max(cnt, 0)):
        e = obj(c, 0x40)
        c.emu.w32(e, r32(c))
        c.emu.w32(t + 0x5c + 4 * i, e)
    c.emu.w32(t + 0x6c, r32(c))
    return [t, s]


S(0x4a1bf0, 'CActionController::Save', 'thiscall', gen=g)
