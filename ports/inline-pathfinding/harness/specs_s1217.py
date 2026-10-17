"""specs_s1217.py - pathfinding batch 1217: time-slice record, queue pop, ProcessQueue, RespondToRequest."""
from pilot import S, F
from pfspec import rnd, hooks, reporter, allocator, vtable, RET
from specs_s1214 import clock, context
from specs_s1216 import queue


def tsrec(c):
    r = c.rng
    e = c.emu
    ts = rnd(c, 0x14)
    e.w8(ts + 0x10, r.choice([0, 1, 1]))
    e.w32(ts, r.randint(0, 3000))
    e.w32(ts + 4, r.choice([0, 10, 100, 1000, 0xffffffff]))
    e.w32(ts + 8, r.choice([0, 1, 3, 100]))
    e.w32(ts + 0xc, r.choice([0, 1, 2, 200]))
    return ts


S(0x52cf00, 'CTimeSlice::<enable> (no GC name)', 'thiscall', None, ret='al',
  gen=lambda c: [tsrec(c), c.rng.getrandbits(32)])


def _tsb(c):
    clock(c)
    return [tsrec(c)]


S(0x52cf10, 'CTimeSlice::<begin> (no GC name)', 'thiscall', None, gen=_tsb)
S(0x52cf40, 'CTimeSlice::<restart> (no GC name)', 'thiscall', None, gen=_tsb)


def _pop(c):
    q, cap = queue(c)
    return [q, rnd(c, 0x32)]


S(0x52b390, 'CPathRequestQueue::<pop> (no GC name)', 'thiscall', None, ret='al', gen=_pop)


def _pq(c):
    r = c.rng
    e = c.emu
    clock(c)
    ctx = context(c)
    full = rnd(c, 0x240)
    e.wbytes(full, e.rbytes(ctx, 0x51))
    ctx = full

    def respond(em, a):
        em.w8(ctx + 0x99, r.choice([0, 1, 1]))
        return 0
    hooks(e, {0x52c6e0: ('RespondToRequest', 'this', 2, {'impl': respond})})
    self_ = rnd(c, 0xa0)
    e.w32(self_ + 0x18, 0 if r.random() < 0.3 else tsrec(c))
    e.w32(self_ + 0x1c, ctx)
    q, cap = queue(c)
    for k in range(cap):
        e.w32(e.r32(q) + 0x32 * k + 4, r.choice([0, 0, r.getrandbits(32)]))
    e.w32(self_ + 0x79, q)
    return [self_, r.getrandbits(32)]


S(0x52c000, 'ZPathfinder3::ProcessQueue', 'thiscall', None, gen=_pq)


def chkpntlst(c, n):
    e = c.emu
    lst = rnd(c, 0x18)
    e.w32(lst + 8, n)
    pts = e.alloc(16 * max(n, 1) + 16, 4)
    for k in range(4 * max(n, 1)):
        e.wf32(pts + 4 * k, c.fv(-300, 300))
    e.w32(lst + 0xc, pts)
    return lst


def _respond(c):
    r = c.rng
    e = c.emu
    clock(c)
    reporter(c)
    allocator(c)
    ctx = rnd(c, 0x240)
    ctx2 = context(c)
    e.wbytes(ctx, e.rbytes(ctx2, 0x51))
    lst = chkpntlst(c, r.choice([0, 1, 2, 4]))
    lst2 = chkpntlst(c, r.choice([0, 1, 3]))

    def fpi(em, a):
        em.w8(ctx + 0x99, r.choice([0, 1, 1, 1]))
        return r.choice([0, lst, lst])
    hooks_tbl = {0x52b170: ('FindPathInternal', 'this', 7, {'mask': {3: 0xff, 4: 0xff}, 'peek': {0: 12},
                                                           'impl': fpi}),
                 0x52b4e0: ('PostProcessPath', 'this', 1, {'impl': lambda em, a: r.choice([a[0], lst2])})}
    hooks(e, hooks_tbl)
    self_ = rnd(c, 0xa0)
    e.w8(self_ + 0x24, 1 if r.random() < 0.08 else 0)
    q, cap = queue(c)
    e.w32(self_ + 0x79, q)
    e.w8(0x701b58, r.choice([0, 1]))
    obj = rnd(c, 8)

    def pos(em, a):
        for k in range(3):
            em.wf32(a[0] + 4 * k, c.fv(-300, 300))
    e.w32(obj, vtable(c, 'actorObj', 0x190, impl={0x1e0: lambda em, a: r.choice([0, 1]), 0x630: pos},
                      argwords={0x1e0: 1, 0x630: 1, 0x128: 3}, opts={0x630: {'peek': {0: 12}}}))
    act = rnd(c, 0x60)
    e.w32(act + 0x54, obj if r.random() < 0.9 else 0)
    m = rnd(c, 16)
    e.w32(m, vtable(c, 'msgtable', 0x20, impl={0x54: lambda em, a: act if r.random() < 0.9 else 0},
                    argwords={0x54: 1}))
    sysi = e.r32(0x70039c)
    e.w32(sysi + 0x9b, m)
    req = rnd(c, 0x32)
    e.w32(req + 4, r.choice([0, 0xffffffff, r.getrandbits(32), r.getrandbits(32)]))
    for k in range(6):
        e.wf32(req + 8 + 4 * k, c.fv(-300, 300))
    for L in (lst, lst2):        # first point near the request start: the 10..200 re-anchoring branch
        if r.random() < 0.6:
            pts = e.r32(L + 0xc)
            for k in range(3):
                e.wf32(pts + 4 + 4 * k, e.rf32(req + 8 + 4 * k) + r.uniform(-120, 120))
    return [self_, req, ctx]


S(0x52c6e0, 'ZPathfinder3::RespondToRequest', 'thiscall', None, gen=_respond)
