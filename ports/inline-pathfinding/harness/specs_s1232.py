"""specs_s1232.py - pathfinding batch 1232: ZActor::FindNextPathAction (0x478640), FindNextPathBlocker (0x478700),
SendPathDone (0x47b7a0). The path object, its lists and records are built per case; the actor's and the pathfinder's
vtable slots are logged stubs in both builds (slot 0x57c writes a position into its second argument)."""
import struct
from pilot import S
from pfspec import rnd, reporter, vtable, sf


def _path(c, n, with_lists=True):
    r = c.rng
    e = c.emu
    path = e.alloc(0x20, 4)
    e.wbytes(path, bytes(0x20))
    e.w32(path + 8, n)
    rec = e.alloc(16 * (n + 2) + 16, 16)
    e.wbytes(rec, bytes(r.getrandbits(8) for _ in range(16 * (n + 2) + 16)))
    e.w32(path + 0xc, rec)
    acts = []
    lst = e.alloc(4 * (n + 3), 4)
    for k in range(n + 2):
        if r.random() < 0.6:
            a = e.alloc(0x20, 4)
            e.w16(a + 2, r.getrandbits(16))
            e.w32(a + 0x1c, r.getrandbits(32))
            e.w32(lst + 4 * k, a)
        else:
            e.w32(lst + 4 * k, 0)
    e.w32(path + 0x14, lst)
    blk = e.alloc(4 * (n + 3), 4)
    for k in range(n + 2):
        e.w32(blk + 4 * k, r.choice([0, 0, r.getrandbits(32)]))
    e.w32(path + 0x10, blk if with_lists else 0)
    return path


def _actor(c, slots=None):
    r = c.rng
    e = c.emu
    actor = rnd(c, 0x1000)
    impl = {0x640: lambda em, a: 0, 0x644: lambda em, a: 0, 0x648: lambda em, a: 0, 0x64c: lambda em, a: 0,
            0x578: lambda em, a: 0, 0x620: lambda em, a: 0}
    def pos(em, a):
        for k in range(3):
            em.wf32(a[1] + 4 * k, sf(c.fv(-300, 300)))
        return 0
    impl[0x57c] = pos
    e.w32(actor, vtable(c, 'actor', 0x900, impl=impl,
                        argwords={0x640: 1, 0x644: 1, 0x648: 1, 0x64c: 1, 0x578: 2, 0x620: 3, 0x57c: 2}))
    return actor


def _fna(c):
    r = c.rng
    e = c.emu
    actor = _actor(c)
    e.w32(actor + 0x6ce, r.choice([0, 0, r.getrandbits(32)]))
    e.w32(actor + 0x64c, r.choice([0xa, 0, 1]))
    path = _path(c, r.randint(0, 4)) if r.random() < 0.85 else 0
    e.w32(actor + 0x695, path)
    return [actor]


def _fnb(c):
    r = c.rng
    e = c.emu
    reporter(c, 0.0)
    actor = _actor(c)
    pf = rnd(c, 0x400)
    e.w32(pf, vtable(c, 'pathfinder', 0x240, impl={0x228: lambda em, a: a[0] ^ 0x5a5a5a5a},
                     argwords={0x228: 1}))
    e.w32(actor + 0x5b2, pf)
    path = _path(c, r.randint(0, 4)) if r.random() < 0.85 else 0
    e.w32(actor + 0x695, path)
    return [actor]


def _sdp(c):
    r = c.rng
    e = c.emu
    actor = _actor(c)
    e.w32(actor + 0x727, r.choice([0, 1, 2, 3, 4, 5]))
    e.w32(actor + 0x72b, r.getrandbits(32))
    e.w32(actor + 0x732, r.getrandbits(32))
    path = _path(c, 1, with_lists=False) if r.random() < 0.5 else 0
    e.w32(actor + 0x695, path)
    return [actor, r.choice([0, 1, 1, 2])]


S(0x478640, 'ZActor::FindNextPathAction', 'thiscall', None, gen=_fna, n=300)
S(0x478700, 'ZActor::FindNextPathBlocker', 'thiscall', None, gen=_fnb, n=300)
S(0x47b7a0, 'ZActor::SendPathDone', 'thiscall', None, gen=_sdp, n=300)
