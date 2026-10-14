"""specs_s1514.py - recruits thread batch 1514: SendFollowersToSafepoints, SendFormationEvent_rr.
vdist / vdist2 run as exe code. Recorders: positions (slot 0x84 writes fixed values), REFTAB of safepoint ids,
name resolve (slot 0x114), the followers' event, script parameters, ForwardEventToFollowers, log, assert handler."""
from pilot import S, F
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj, reftab, logger


def _posobj(c, pos, extra=None):
    def put(em, k):
        for i, v in enumerate(pos):
            em.wf32(em.arg32(0) + 4 * i, v)
    slots = {0x84: pystub(c, 1, nullflag=(0,), side=put)}
    slots.update(extra or {})
    return obj(c, 0x40, slots)


def _safe(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    ctr = [r.uniform(-300, 300), r.uniform(-20, 20), r.uniform(-300, 300)]
    area = _posobj(c, ctr)
    h = rnd(c, 0xa1a + 0x30 * 8)
    nf = r.randint(0, 6)
    e.w32(h + 0xa16, nf)
    for i in range(nf):
        p = [ctr[0] + r.uniform(-400, 400), r.uniform(-20, 20), ctr[2] + r.uniform(-400, 400)]
        a = _posobj(c, p, {0x128: pystub(c, 3, deref={1: 1})})
        e.w32(h + 0xa1a + 0x30 * i, a)
    objs = {}
    ids = []
    spots = [[ctr[0] + r.uniform(-500, 500), 0.0, ctr[2] + r.uniform(-500, 500)] for _ in range(3)]
    for i in range(r.randint(0, 6)):
        sid = r.getrandbits(32) | 1
        # positions from a few spots, so equal distances (ties) occur
        objs[sid] = _posobj(c, r.choice(spots) if r.random() < 0.5 else
                            [ctr[0] + r.uniform(-500, 500), 0.0, ctr[2] + r.uniform(-500, 500)])
        ids.append(sid)

    def look(em, rr):
        em.ret(objs.get(em.arg32(0), 0), 4)
    sysobj(c, table_slots={0x58: e.stub_fn('id->obj', look), 0x114: pystub(c, 4, ret=r.getrandbits(32))})
    lst = rnd(c, 0x20)
    e.w32(lst + 0x18, reftab(c, ids) if r.random() < 0.9 else 0)
    return [h, area, F(r.choice([0.0, 200.0, 400.0, r.uniform(0, 600)])), lst]


def _sfe(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    # log printf: (log, fmt) and, for the RAISE_EXCEPTION format only, its string argument
    lrec = e.alloc(4 * 8 * 3 + 4, 4)

    def lp(em, rr):
        k = em.r32(lrec + 96)
        row = lrec + 12 * min(k, 7)
        em.w32(row, em.arg32(0))
        em.w32(row + 4, em.arg32(1))
        em.w32(row + 8, em.arg32(2) if em.arg32(1) == 0x69c6b0 else 0)
        em.w32(lrec + 96, k + 1)
        em.ret(0, 0)
    lo = obj(c, 0x40, {0x2c: e.stub_fn('log printf', lp)})
    e.w32(0x700390, obj(c, 0x40, {0x20: pystub(c, 2, ret=lo)}))
    e.w32(0x7003b0, pystub(c, 0, pop=0))
    ps = [rnd(c, 8) for _ in range(5)]
    e.w8(ps[0] + 4, r.choice([0, 1, 1, 7]))
    e.w32(ps[1], r.choice([0, 0, 1]))
    nm = e.cstr('SomeEvent')
    so = obj(c, 0x40, {0x34: pystub(c, 0, ret=nm)})
    t = r.choice([3, 3, 4, 5])
    e.w8(ps[2] + 4, t)
    e.w32(ps[2], nm if t == 3 else so)
    hook_rec(c, 0x5003d0, 1, ret=lambda em, k: ps[min(em.arg32(0), 4)], this=True)
    hook_rec(c, 0x591820, 2, this=True, deref={1: 2})
    hero = obj(c, 0x40, {0x1e0: pystub(c, 1, ret=r.choice([0, 1, 1, 0x100]))})
    sysobj(c, table_slots={0x58: pystub(c, 1, ret=0 if r.random() < 0.15 else hero),
                           0x114: pystub(c, 4, ret=r.getrandbits(32))})
    params = rnd(c, 0x10)
    return [rnd(c, 0x20), params]


S(0x594c30, 'ZFFHERO::SendFollowersToSafepoints', 'thiscall', gen=_safe, note='batch1514')
S(0x556e80, 'CFFTools_if::SendFormationEvent_rr', 'thiscall', gen=_sfe, note='batch1514')
