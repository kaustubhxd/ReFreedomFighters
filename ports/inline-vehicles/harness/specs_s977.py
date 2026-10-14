"""specs_s977.py - residue-05, batch 977: ZCollisionBase::GetInnerRoomsLst (0x4ed1d0). The object's slots 0x18 and 0x14 answer a
count (zero sends the call to 0x14); the list entries are pool objects whose slot 0x260 answers a count and whose slot 0x20
answers the next pool object (a closed chain). The list has eight entries (some zero) and the end pointer is 1..8 entries past it."""
import os, sys
for _d in ('..', '../..'):
    _p = os.path.join(os.path.dirname(os.path.abspath(__file__)), _d, 'shared-harness')
    if os.path.isdir(_p) and _p not in sys.path:
        sys.path.insert(0, _p)
from pilot import S
from vh import _stub, obj, r32


def g(c):
    pool = [obj(c, 0x40) for _ in range(3)]
    for o in pool:
        vt = c.emu.r32(o)
        c.emu.w32(vt + 0x260, _stub(c, 0, ret=c.rng.randint(0, 3)))
        c.emu.w32(vt + 0x20, _stub(c, 0, ret=c.rng.choice(pool)))
    t = obj(c, 0x200)
    c.emu.w32(t + 0x1a1, r32(c) if c.rng.random() < 0.8 else 0)
    n18 = 0 if c.rng.random() < 0.4 else c.rng.randint(2, 6)
    n14 = c.rng.randint(0, 6)
    vt = c.emu.r32(t)
    c.emu.w32(vt + 0x18, _stub(c, 4, ret=n18))
    c.emu.w32(vt + 0x14, _stub(c, 6, ret=n14))
    lst = c.emu.alloc(8 * 4, 4)
    for k in range(8):
        c.emu.w32(lst + 4 * k, 0 if c.rng.random() < 0.3 else c.rng.choice(pool))
    p1 = lst
    p2 = lst + 4 * c.rng.randint(1, 8)
    return [t, p1, p2, r32(c), c.rng.randint(0, 6), r32(c)]


S(0x4ed1d0, 'ZCollisionBase::GetInnerRoomsLst', 'thiscall', ret='eax', gen=g)
