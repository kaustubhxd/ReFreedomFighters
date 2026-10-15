"""specs_s1220.py - pathfinding batch 1220: ZActor path-finished notice and SetPathfinderLinks."""
from pilot import S
from pfspec import rnd, hooks, reporter, vtable, RET


def _actor(c, pf_ok=True):
    e = c.emu
    a = rnd(c, 0x700)
    slots = {0x128: lambda em, args: 0}
    e.w32(a, vtable(c, 'ZActor', 0x760, impl=slots, argwords={0x128: 3}))
    return a


def _opf(c):
    e = c.emu
    r = c.rng
    e.w16(0x6ffa28, r.getrandbits(16))
    a = _actor(c)
    e.w32(a + 0x691, r.choice([0, 0, -1, 1, 3]) & 0xffffffff)
    return [a, r.getrandbits(32)]


S(0x4798d0, 'ZActor::OnPathFinished', 'thiscall', None, gen=_opf)


def _links(c):
    r = c.rng
    e = c.emu
    reporter(c)
    hooks(e, {0x4db7c0: ('ZBaseGeom::GetSize', 'this', 1, {'fill': {0: 12}})})
    a = rnd(c, 0x700)
    pf = rnd(c, 0x10)
    k = r.random()
    pf_impl = {0x21c: lambda em, args: 0}
    if k < 0.15:
        e.w32(a, vtable(c, 'ZActor', 0x760, impl={0x5d0: lambda em, args: 0}, argwords={0x5d0: 0}))
    else:
        e.w32(pf, vtable(c, 'ZPathfinder3', 0x240, impl=pf_impl, argwords={0x21c: 3}, opts={0x21c: {'peek': {0: 12, 1: 12}}}))
        e.w32(a, vtable(c, 'ZActor', 0x760, impl={0x5d0: lambda em, args, pf=pf: pf}, argwords={0x5d0: 0}))
    box = rnd(c, 8)
    geom = rnd(c, 0x20)
    e.w32(geom, vtable(c, 'geom', 0x240, impl={0x80: lambda em, args: 0}, argwords={0x80: 2},
                       opts={0x80: {'fill': {0: 36, 1: 12}}}))
    e.w32(geom + 8, rnd(c, 0x40))
    msgs = rnd(c, 16)
    tgt = geom if r.random() < 0.85 else 0
    e.w32(msgs, vtable(c, 'msgtable', 0x60, impl={0x58: lambda em, args: tgt}, argwords={0x58: 1}))
    sysi = e.r32(0x70039c)
    e.w32(sysi + 0x9b, msgs)
    return [a, r.getrandbits(32), r.choice([0, 1])]


S(0x47bff0, 'ZActor::SetPathfinderLinks', 'thiscall', None, gen=_links, n=300)
