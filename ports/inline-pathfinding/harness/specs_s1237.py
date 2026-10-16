"""specs_s1237.py - pathfinding batch 1237: CDoorBlocker::GetPos (0x4875a0) and GetType (0x52b3e0). The geometry's slot
0x84 is a logged stub (it takes the output pointer); the geometry's +8 sub-object carries the three dwords 0x4daf90 copies."""
from pilot import S
from pfspec import rnd, vtable


def _geomPos(c):
    r = c.rng
    e = c.emu
    door = rnd(c, 0x40)
    out = e.alloc(16)
    if r.random() < 0.7:
        geom = e.alloc(0x40)
        sub = rnd(c, 0x40)
        e.w32(geom + 8, sub)
        e.w32(geom, vtable(c, 'geom', 0x30, impl={0x84: lambda em, a: 0}, argwords={0x84: 1}))
        e.w32(door + 4, geom)
    else:
        e.w32(door + 4, 0)
    return [door, out]


def _door(c):
    return [rnd(c, 0x40)]


S(0x4875a0, 'CDoorBlocker::GetPos', 'thiscall', None, gen=_geomPos, n=300)
S(0x52b3e0, 'CDoorBlocker::GetType', 'thiscall', None, gen=_door, n=300)
