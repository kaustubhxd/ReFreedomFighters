"""specs_s1231.py - pathfinding batch 1231: ZActor::OnPathNotify (0x47a4d0) and OnPathRequest (0x47a500).

The actor's vtable slots (0x84 position, 0x624 speed, 0x634, 0x5e8, 0x128) are logged stubs in both builds; the
position stub writes a random point (the same in both). vdist is the exe's own."""
from pilot import S
from pfspec import rnd, vtable, sf


def _actor(c, pos_fn):
    r = c.rng
    e = c.emu
    actor = rnd(c, 0x800)
    impl = {0x128: lambda em, a: 0, 0x624: lambda em, a: 0, 0x634: lambda em, a: 0, 0x5e8: lambda em, a: 0}
    def pos(em, a):
        for k in range(3):
            em.wf32(a[0] + 4 * k, sf(pos_fn(k)))
        return 0
    impl[0x84] = pos
    e.w32(actor, vtable(c, 'actor', 0x900, impl=impl, argwords={0x128: 3, 0x624: 1, 0x634: 2, 0x5e8: 1, 0x84: 1}))
    return actor


def _notify(c):
    r = c.rng
    e = c.emu
    e.w16(0x6ffa44, r.getrandbits(16))
    return [_actor(c, lambda k: 0.0)]


def _req(c):
    r = c.rng
    e = c.emu
    e.w16(0x6ffa24, r.getrandbits(16))
    dist = r.choice([0.0, 60.0, 80.0, 160.0, 210.0, 320.0])
    dx = c.fv(-400, 400)
    actor = _actor(c, lambda k: [dist, 0.0, 0.0][k] + (dx if k == 0 else 0.0))
    dest = actor + 0x742
    e.wf32(dest, 0.0)
    e.wf32(dest + 4, 0.0)
    e.wf32(dest + 8, 0.0)
    e.w8(actor + 0x74e, r.choice([0, 1, 1]))
    return [actor, r.getrandbits(32)]


S(0x47a4d0, 'ZActor::OnPathNotify', 'thiscall', None, gen=_notify, n=200)
S(0x47a500, 'ZActor::OnPathRequest', 'thiscall', None, gen=_req, n=300)
