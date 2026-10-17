"""specs_s1503.py - recruits thread batch 1503: follower list add/remove, script natives FollowHero, FreeVIPPrisoner,
AddToFormation, GetFormationControlEventBase, script parameter get/set.
The log object (0x700390) and the assert handler (0x7003b0) are recorders; the handler is always present (an int3
in both runs reports different eips, so the no-handler path is not compared). GetGameOSD runs as exe code."""
from pilot import S
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, reftab, logger


def _assert(c):
    c.emu.w32(0x7003b0, pystub(c, 0, pop=0))


def _params(c, n=4, bad=0.0):
    """Value array: values 8 bytes each (dword, type byte)."""
    r = c.rng
    vals = rnd(c, 8 * (n + 4))
    for i in range(n + 4):
        c.emu.w8(vals + 8 * i + 4, (r.randint(2, 255) if r.random() < bad else r.randint(0, 1)))
    arr = rnd(c, 0x10)
    c.emu.w32(arr, vals)
    c.emu.w32(arr + 8, n + 2)
    blk = rnd(c, 0x10)
    c.emu.w32(blk, arr)
    c.emu.w32(blk + 4, r.randint(0, 2))
    c.emu.w32(blk + 8, n)
    return blk


def _param_at(c):
    clear_hooks(c)
    r = c.rng
    _assert(c)
    blk = _params(c)
    return [blk, r.randint(0, 7)]


def _param_set(c):
    clear_hooks(c)
    r = c.rng
    _assert(c)
    logger(c, 3)
    p = rnd(c, 8)
    c.emu.w8(p + 4, r.choice([0, 1, 1, 0, 2, 0xff]))
    return [p, r.getrandbits(32)]


def _hero_followers(c, n):
    r = c.rng
    h = rnd(c, 0xa1a + 0x30 * (n + 2))
    c.emu.w32(h + 0xa16, n)
    actors = []
    for i in range(n):
        a = rnd(c, 0x40)
        actors.append(a)
        c.emu.w32(h + 0xa1a + 0x30 * i, a)
    return h, actors


def _remove_follower(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x5a2860, 0, this=True)
    logger(c, 3)
    h, actors = _hero_followers(c, r.randint(0, 6))
    if actors and r.random() < 0.8:
        a = r.choice(actors)
    else:
        a = rnd(c, 0x40)
        c.emu.w32(a + 4, 0 if r.random() < 0.5 else c.emu.alloc(8, 4))
    return [h, a]


def _add_follower(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x59dce0, 1, this=True)
    strp = c.emu.alloc(8, 4)
    hook_rec(c, 0x4cc1d0, 0, ret=strp, this=True)
    hook_rec(c, 0x4cbec0, 0, this='mark')
    logger(c, 3)
    h, actors = _hero_followers(c, r.randint(0, 6))
    mys = rnd(c, 0x10)
    if actors and r.random() < 0.25:
        a = r.choice(actors)
    else:
        a = rnd(c, 0x40)
    vt = c.emu.alloc(0x200, 4)
    c.emu.w32(vt + 0x128, pystub(c, 3, deref={1: 1}))
    c.emu.w32(vt + 0x1d8, pystub(c, 2, ret=mys, stackmark=(0,)))
    c.emu.w32(a, vt)
    c.emu.w8(h + 0xee3, r.choice([0, 1, 0x80]))
    return [h, a]


def _follow_hero(c):
    clear_hooks(c)
    r = c.rng
    _assert(c)
    logger(c, 3)
    p0, p1 = rnd(c, 8), rnd(c, 8)
    for p in (p0, p1):
        c.emu.w8(p + 4, r.choice([0, 1, 1, 0, 5]))
    if r.random() < 0.3:
        c.emu.w32(p1, 0)
    hook_rec(c, 0x5003d0, 1, ret=lambda e, k: p1 if e.arg32(0) == 1 else p0, this=True)
    hook_rec(c, 0x58b780, 1, this=True)
    hook_rec(c, 0x594460, 1, this=True)
    hero = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 0x100, r.getrandbits(32)]))})
    cls = rnd(c, 0x30)
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=0 if r.random() < 0.2 else hero),
                           0x154: pystub(c, 2, ret=cls)})
    return [rnd(c, 0x40), rnd(c, 0x10)]


def _free_vip(c):
    clear_hooks(c)
    r = c.rng
    hook_rec(c, 0x596940, 4, this=True, deref={1: 3})
    game = rnd(c, 0x2c40)
    c.emu.w32(game + 0x2c2d, rnd(c, 0x10))
    c.emu.w32(0x7003b8, game)
    vals = [r.getrandbits(32) for _ in range(12)]
    pos = [r.uniform(-500, 500) for _ in range(3)]

    def fill(e, k):
        b, p = e.arg32(0), e.arg32(1)
        for i in range(9):
            e.w32(b + 4 * i, vals[i])
        if r.random() < 0.5:
            for i in range(3):
                e.w32(p + 4 * i, vals[9 + i])

    def getpos(e, k):
        p = e.arg32(0)
        for i in range(3):
            e.wf32(p + 4 * i, pos[i])
    g = obj(c, 0x20, {0x84: pystub(c, 1, nullflag=(0,), side=getpos)})
    a = obj(c, 0x40, {0x3a0: pystub(c, 2, ret=r.getrandbits(32), nullflag=(0, 1), side=fill),
                      0x390: pystub(c, 1, this=True),
                      0x20: pystub(c, 0, ret=g)})
    s = rnd(c, 0x40)
    c.emu.w32(s + 0x1c, a)
    return [s, rnd(c, 0x10)]


def _get_fc(c):
    clear_hooks(c)
    r = c.rng
    logger(c, 2)
    idv = r.getrandbits(32)

    def put(e, k):
        e.w32(e.arg32(1), idv)
    names = obj(c, 0x20, {0x88: pystub(c, 2, nullflag=(1,), side=put)})
    o = rnd(c, 0x40)
    o10 = rnd(c, 0x10)
    c.emu.w32(o + 0x10, o10)
    n = r.randint(0, 3)
    c.emu.w32(o10 + 8, 0 if r.random() < 0.15 else reftab(c, [r.getrandbits(32) for _ in range(n)]))
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=names), 0x58: pystub(c, 1, ret=0 if r.random() < 0.15 else o)})
    c.emu.w32(0x70038c, obj(c, 0x20, {0xcc: pystub(c, 1, ret=r.getrandbits(32))}))
    return [rnd(c, 0x20)]


def _add_to_formation(c):
    clear_hooks(c)
    r = c.rng
    logger(c, 2)
    ps = [rnd(c, 8) for _ in range(3)]
    retp = rnd(c, 8)
    params = rnd(c, 0x10)
    inp = rnd(c, 0x10)
    outp = rnd(c, 0x10)
    c.emu.w32(params + 4, inp)
    c.emu.w32(params + 8, outp)

    def getp(e, k):
        return retp if e.reg('ecx') == outp else ps[min(e.arg32(0), 2)]
    hook_rec(c, 0x5003d0, 1, ret=getp, this=True)
    hook_rec(c, 0x5002f0, 1, this=True)
    res = r.getrandbits(32)

    def setres(e, k):
        if r.random() < 0.8:
            e.w32(e.arg32(0), res)
    fc = obj(c, 0x20, {0x84: pystub(c, 1, deref={0: 6}, side=setres)})
    s = rnd(c, 0x20)
    k = r.random()
    c.emu.w32(s + 0xc, fc if k < 0.6 else 0)
    later = fc if r.random() < 0.6 else 0

    def gfc(e, kk):
        e.w32(s + 0xc, later)
    hook_rec(c, 0x553d00, 0, this=True, side=gfc)
    return [s, params]


S(0x5003d0, 'script param address (0x5003d0)', 'thiscall', ret='eax', gen=_param_at, note='batch1503')
S(0x5002f0, 'script param set int (0x5002f0)', 'thiscall', ret='eax', gen=_param_set, note='batch1503')
S(0x594460, 'ZFFHERO::RemoveFollower', 'thiscall', gen=_remove_follower, note='batch1503')
S(0x58b780, 'ZFFHERO::AddFollower', 'thiscall', gen=_add_follower, note='batch1503', teb=True)
S(0x5591b0, 'ZFFActorIf::FollowHero', 'thiscall', gen=_follow_hero, note='batch1503')
S(0x5592f0, 'ZFFActorIf::FreeVIPPrisoner', 'thiscall', gen=_free_vip, note='batch1503')
S(0x553d00, 'CFFTools_if::GetFormationControlEventBase', 'thiscall', ret='eax', gen=_get_fc, note='batch1503')
S(0x551d70, 'CFFTools_if::AddToFormation', 'thiscall', gen=_add_to_formation, note='batch1503')
