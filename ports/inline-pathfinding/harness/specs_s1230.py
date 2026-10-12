"""specs_s1230.py - pathfinding batch 1230: ZActor::OnPathCanceled (0x479810), OnPathCanceledLockedDoor (0x479850),
OnPathError (0x479890). The message ids are the exe's globals (0x6ffa2c / 0x6ffa30 / 0x6ffa34), set per case; the
actor's +0x128 slot is a logged stub in both builds."""
from pilot import S
from pfspec import rnd, vtable


def _gen(glob):
    def g(c):
        r = c.rng
        e = c.emu
        e.w16(glob, r.getrandbits(16))
        actor = rnd(c, 0x800)
        e.w32(actor, vtable(c, 'actor', 0x200, impl={0x128: lambda em, a: 0}, argwords={0x128: 3}))
        return [actor, r.getrandbits(32)]
    return g


S(0x479810, 'ZActor::OnPathCanceled', 'thiscall', None, gen=_gen(0x6ffa2c), n=200)
S(0x479850, 'ZActor::OnPathCanceledLockedDoor', 'thiscall', None, gen=_gen(0x6ffa30), n=200)
S(0x479890, 'ZActor::OnPathError', 'thiscall', None, gen=_gen(0x6ffa34), n=200)
