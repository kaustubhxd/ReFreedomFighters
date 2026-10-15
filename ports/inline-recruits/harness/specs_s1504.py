"""specs_s1504.py - recruits thread batch 1504: SSquad ctor/copy/targets, ZFFActor::AddToSquad(), and the recruit list
(IsRecruited, AddRecruit, PurgeOneWoundedIfFull). CRT memmove is a Python stand-in (recruits_util.stub_memmove).
GetGameOSD and the SSquad ctor/copy run as exe code under their callers; IsDerivedFrom, AddMember, SetRecruitMode,
the actor sound, RemoveRecruit, RemoveFollower and the actor-mode getter are recorders where noted."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, logger, stub_memmove


def _squad_rec(c, a=None):
    r = c.rng
    sq = rnd(c, 0xf4) if a is None else a
    c.emu.w32(sq, r.randint(0, 12))
    c.emu.w32(sq + 0x38, r.randint(0, 16))
    c.emu.w32(sq + 0x7c, r.randint(0, 12))
    c.emu.w32(sq + 0xb0, r.randint(0, 12))
    return sq


def _ctor(c):
    clear_hooks(c)
    return [rnd(c, 0xf4), c.rng.getrandbits(32)]


def _assign(c):
    clear_hooks(c)
    stub_memmove(c)
    return [rnd(c, 0xf4), _squad_rec(c)]


def _target(c, gone):
    """Target entity: +0 geom with IsKindOf (0x1e0) and slot 0x438."""
    r = c.rng
    g = obj(c, 0x20, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100])),
                      0x438: pystub(c, 0, ret=(1 if gone else 0) | (r.getrandbits(24) << 8))})
    t = rnd(c, 0x10)
    c.emu.w32(t, g)
    return t


def _gone(c):
    clear_hooks(c)
    return [_target(c, c.rng.random() < 0.5)]


def _targets_squad(c, n=None):
    r = c.rng
    sq = rnd(c, 0xf4)
    n = r.randint(0, 16) if n is None else n
    c.emu.w32(sq + 0x38, n)
    ts = []
    for i in range(n):
        t = _target(c, r.random() < 0.3)
        ts.append(t)
        c.emu.w32(sq + 0x3c + 4 * i, t)
    return sq, ts


def _purge(c):
    clear_hooks(c)
    return [_targets_squad(c)[0]]


def _add_target(c):
    clear_hooks(c)
    r = c.rng
    logger(c, 2)
    sq, ts = _targets_squad(c, 16 if r.random() < 0.4 else None)
    t = r.choice(ts) if ts and r.random() < 0.3 else _target(c, False)
    return [sq, t]


def _auto_squad(c):
    clear_hooks(c)
    r = c.rng
    stub_memmove(c)
    logger(c, 3, slot=0x30)
    ok = r.getrandbits(24) << 8 | (0 if r.random() < 0.3 else 1)
    hook_rec(c, 0x5898c0, 1, ret=ok, this='mark')
    grp = rnd(c, 0x20)
    kids = [rnd(c, 0x10) for _ in range(r.randint(0, 4))]
    rec_kind = {k: r.random() < 0.6 for k in kids}
    hook_rec(c, 0x4db9a0, 1, ret=lambda e, k: 1 if rec_kind.get(e.reg('ecx')) else 0, this=True)
    c.emu.w32(grp + 8, kids[0] if kids else 0)
    nxt = {kids[i]: (kids[i + 1] if i + 1 < len(kids) else 0) for i in range(len(kids))}

    def adv(e, k):
        p = e.arg32(0)
        e.w32(p, nxt.get(e.r32(p), 0))
    vt = c.emu.alloc(0x60, 4)
    c.emu.w32(vt + 0x50, pystub(c, 1, nullflag=(0,), side=adv))
    c.emu.w32(grp, vt)
    geom = obj(c, 0x20, {0x20: pystub(c, 0, ret=grp)})
    game = rnd(c, 0xd91 + 0xf4 * 34)
    n = r.choice([r.randint(0, 4), 0x20])
    c.emu.w32(game + 0xd8d, n)
    for i in range(min(n, 34)):
        c.emu.w32(game + 0xd91 + 0xf4 * i + 0x34, r.getrandbits(32))
    if n and r.random() < 0.3:
        c.emu.w32(game + 0xd91 + 0xf4 * r.randint(0, min(n, 34) - 1) + 0x34, grp)
    c.emu.w32(0x7003b8, game)
    a = obj(c, 0xa00, {0x20: pystub(c, 0, ret=geom)})
    team = rnd(c, 8)
    c.emu.w32(team + 4, 1 if r.random() < 0.85 else 2)
    c.emu.w32(a + 0x54, team)
    return [a]


def _is_recruited(c):
    clear_hooks(c)
    r = c.rng
    game = rnd(c, 0x2c60)
    c.emu.w32(0x7003b8, game)
    ids = [r.randint(1, 20) for _ in range(6)]
    for s in range(4):
        osd = 0 if r.random() < 0.2 else rnd(c, 0x2000)
        if osd:
            n = r.randint(0, 6)
            c.emu.w32(osd + 0x1fae, n)
            for i in range(n):
                c.emu.w32(osd + 0x1dae + 4 * i, r.choice(ids))
        c.emu.w32(game + 0x2c2d + 4 * s, osd)
        e = rnd(c, 0x60)
        e8 = rnd(c, 0x40)
        c.emu.w32(e + 8, e8)
        t = rnd(c, 8)
        c.emu.w32(t + 4, r.randint(0, 1))
        c.emu.w32(e + 0x54, t)
        c.emu.w32(game + 0x2c3d + 4 * s, e)
    me = rnd(c, 0x2000)
    hero = rnd(c, 0x60)
    t = rnd(c, 8)
    c.emu.w32(t + 4, r.randint(0, 1))
    c.emu.w32(hero + 0x54, t)
    c.emu.w32(me + 0x1d0b, hero)
    return [me, r.choice(ids + [99])]


def _add_recruit(c):
    clear_hooks(c)
    r = c.rng
    stub_memmove(c)
    logger(c, 2)
    hook_rec(c, 0x5a2e20, 4, this=True)
    hook_rec(c, 0x5a1ac0, 3, this=True)
    a = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 1, 0x100]))})
    so = sysobj(c, table_slots={0x58: pystub(c, 1, ret=a)})
    c.emu.w32(so + 0x40, r.getrandbits(32))
    s = rnd(c, 0x2400)
    n = r.randint(0, 8)
    c.emu.w32(s + 0x1fae, n)
    c.emu.w32(s + 0x1fba, r.choice([n, n + 1, n + 4, r.getrandbits(32)]))
    idv = r.getrandbits(32)
    m = r.randint(0, 5)
    tab = c.emu.alloc(4 * m + 4, 4)
    has = r.random() < 0.9
    pos = r.randint(0, m - 1) if m else -1
    for i in range(m):
        e = rnd(c, 0x20)
        c.emu.w32(e, idv if (has and i == pos) else r.getrandbits(32))
        c.emu.w32(tab + 4 * i, e)
    c.emu.w32(s + 0x1da2, tab)
    c.emu.w32(s + 0x1da6, tab + 4 * m)
    return [s, idv]


def _purge_wounded(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x597e00, 1, this=True)
    hook_rec(c, 0x594460, 1, this=True)
    s = rnd(c, 0x2400)
    n = r.randint(0, 6)
    c.emu.w32(s + 0x1fae, n)
    c.emu.w32(s + 0x1fba, r.choice([n, max(n - 1, 0), n + 1]))
    actors = {}
    for i in range(n):
        a = obj(c, 0x800, {0x128: pystub(c, 3, deref={1: -5})})
        c.emu.w32(a + 0x77f, 5 if r.random() < 0.3 else r.randint(0, 4))
        idv = r.getrandbits(32)
        actors[idv] = a
        c.emu.w32(s + 0x1dae + 4 * i, idv)

    def look(e, rr):
        e.ret(actors.get(e.arg32(0), 0), 4)
    so = sysobj(c, table_slots={0x58: c.emu.stub_fn('id->actor', look),
                                0x4c: pystub(c, 1, ret=r.getrandbits(32)),
                                0x114: pystub(c, 4, ret=r.getrandbits(32))})
    c.emu.w32(so + 0x1b5d, r.choice([0, 1, 2]))
    return [s]


S(0x5889c0, 'SSquad ctor (0x5889c0)', 'thiscall', ret='eax', gen=_ctor, note='batch1504')
S(0x589710, 'SSquad copy (0x589710)', 'thiscall', ret='eax', gen=_assign, note='batch1504')
S(0x59d370, 'target gone (0x59d370)', 'thiscall', ret='al', gen=_gone, note='batch1504')
S(0x58a320, 'SSquad purge targets (0x58a320)', 'thiscall', gen=_purge, note='batch1504')
S(0x589980, 'SSquad::AddTarget', 'thiscall', gen=_add_target, note='batch1504')
S(0x59db90, 'ZFFActor::AddToSquad()', 'thiscall', gen=_auto_squad, note='batch1504')
S(0x597a70, 'ZGameOSD::IsRecruited', 'thiscall', ret='al', gen=_is_recruited, note='batch1504')
S(0x5967b0, 'ZGameOSD::AddRecruit', 'thiscall', gen=_add_recruit, note='batch1504')
S(0x597b50, 'ZGameOSD::PurgeOneWoundedIfFull', 'thiscall', gen=_purge_wounded, note='batch1504')
