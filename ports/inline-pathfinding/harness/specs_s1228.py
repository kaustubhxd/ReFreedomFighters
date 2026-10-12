"""specs_s1228.py - pathfinding batch 1228: ZActor path setters (SetMaxPathLen, SetPathNotify,
SetPathNotifySyncToCycle, SetStayInsidePath). Single stores; no calls."""
from pilot import S, F
from pfspec import rnd, sf


def _f(c):
    r = c.rng
    return [rnd(c, 0x800), F(sf(c.fv(-1000, 1000)))]


S(0x47be90, 'ZActor::SetMaxPathLen', 'thiscall', None, gen=_f)
S(0x47bfc0, 'ZActor::SetPathNotify', 'thiscall', None, gen=_f)


def _b(c):
    r = c.rng
    return [rnd(c, 0x800), r.choice([0, 1, 2, 0xff, r.getrandbits(32)])]


S(0x47bfe0, 'ZActor::SetPathNotifySyncToCycle', 'thiscall', None, gen=_b)
S(0x47c130, 'ZActor::SetStayInsidePath', 'thiscall', None, gen=_b)
