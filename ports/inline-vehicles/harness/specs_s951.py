"""specs_s951.py - residue-03, batch 951: ZWeaponTest::CreateWeapons (0x46d5f0). The vtable slots (0x210, 0x2c4, 0x358,
0x2d4) are stood in with vh stubs; the stack-address arguments of 0x2d4 are not recorded and the output vector is filled
from a random source block. The exe helpers 0x4de7a0 and 0x4de7e0 run as exe code."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _rnd, _stub, obj, r32, rf


def g(c):
    idx = c.rng.randint(0, 3)
    src = c.emu.alloc(12, 4)
    for j in range(3):
        c.emu.w32(src + 4 * j, rf(c, -50, 50))
    new = obj(c, 0x40, {0x358: _stub(c, 1), 0x2d4: _stub(c, 2, skip=(0, 1), fills=((1, src, 3),))})
    ed = obj(c, 0x40, {0x2c4: _stub(c, 2, ret=new)})
    t = obj(c, 0x800)
    c.emu.w32(t + 0x370, idx)
    c.emu.w32(t + 0x44, r32(c))
    c.emu.w32(t + 0x4c + 4 * idx, ed)
    if c.rng.random() < 0.5:
        old = obj(c, 0x40, {0x210: _stub(c, 1)})
        c.emu.w32(t + 0x1e0, old)
    else:
        c.emu.w32(t + 0x1e0, 0)
    return [t]


S(0x46d5f0, 'ZWeaponTest::CreateWeapons', 'thiscall', gen=g)
