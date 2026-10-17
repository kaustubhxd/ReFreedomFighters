"""specs_s1216.py - pathfinding batch 1216: ZPathfinder3 request side."""
from pilot import S, F
from pfspec import rnd, hooks, reporter, allocator, vtable, RET


def _fpi(c):
    r = c.rng
    e = c.emu
    reporter(c)
    hooks(e, {0x52e830: ('FindPath3', 'this', 7, {'mask': {3: 0xff, 4: 0xff}, 'peek': {0: 12, 1: 12}}),
              0x52b080: ('isTimeUp', 'this', 0)})
    RET[0x52e830] = r.getrandbits(32)
    self_ = rnd(c, 0xa0)
    e.w8(self_ + 0x24, 1 if r.random() < 0.1 else 0)
    e.w8(self_ + 0x31, 0 if r.random() < 0.15 else 1)
    e.wf32(self_ + 0x20, c.fv(-50, 50))
    e.w8(0x701b4d, 1 if r.random() < 0.08 else 0)
    ctx = rnd(c, 0x160)
    e.w8(ctx + 0x48, r.choice([0, 1]))
    e.w8(ctx + 0x99, r.choice([0, 1]))
    return [self_, c.fbuf(3), c.fbuf(3), F(c.fv(0, 50)), r.getrandbits(32), r.getrandbits(32), ctx,
            r.getrandbits(32)]


S(0x52b170, 'ZPathfinder3::FindPathInternal', 'thiscall', None, ret='eax', gen=_fpi)


def queue(c, cap=None):
    r = c.rng
    e = c.emu
    q = rnd(c, 0x14)
    cap = cap or r.randint(1, 8)
    e.w32(q, rnd(c, cap * 0x32 + 0x10))
    e.w32(q + 4, cap)
    e.w32(q + 8, r.randrange(cap))
    e.w32(q + 0xc, r.randrange(cap))
    e.w32(q + 0x10, r.getrandbits(32))
    return q, cap


def _push(c):
    q, cap = queue(c)
    return [q, rnd(c, 0x32)]


S(0x52a700, 'CPathRequestQueue::<push> (no GC name)', 'thiscall', None, ret='al', gen=_push)


def _qload(c):
    q, cap = queue(c)
    lg = rnd(c, 0x10)
    c.emu.w32(lg, vtable(c, 'ZLoadGame', 0x40, argwords={0x48: 1, 0x18: 2}))
    return [q, lg]


S(0x52b430, 'CPathRequestQueue::Load', 'thiscall', None, ret='al', gen=_qload)


def _req(c):
    r = c.rng
    e = c.emu
    reporter(c)
    allocator(c)
    hooks(e, {0x531a50: ('TryLine', 'this', 3, {'peek': {0: 12, 1: 12}}),
              0x52b4e0: ('PostProcessPath', 'this', 1),
              0x52c000: ('ProcessQueue', 'this', 1)})
    RET[0x531a50] = 0 if r.random() < 0.5 else r.getrandbits(32)
    RET[0x52b4e0] = r.getrandbits(32)
    self_ = rnd(c, 0xa0)
    e.w8(self_ + 0x31, 0 if r.random() < 0.15 else 1)
    e.wf32(self_ + 0x20, c.fv(-50, 50))
    q, cap = queue(c)
    actors = [r.getrandbits(32) for _ in range(3)] + [0xffffffff]
    for k in range(cap):
        e.w32(e.r32(q) + 0x32 * k + 4, r.choice(actors))
    e.w32(self_ + 0x79, 0 if r.random() < 0.05 else q)
    e.w8(0x701b58, r.choice([0, 1]))
    actor = r.choice(actors)
    act = rnd(c, 0x60)
    obj = rnd(c, 8)
    e.w32(obj, vtable(c, 'actorObj', 0x50, argwords={0x128: 3}))
    e.w32(act + 0x54, obj if r.random() < 0.8 else 0)
    m = rnd(c, 16)
    e.w32(m, vtable(c, 'msgtable', 0x20, impl={0x54: lambda em, a: act if r.random() < 0.8 else 0},
                    argwords={0x54: 1}))
    sysi = rnd(c, 0xa0)
    e.w32(sysi + 0x9b, m)
    e.w32(0x70039c, sysi)
    return [self_, actor, c.fbuf(3), c.fbuf(3), r.getrandbits(32), F(c.fv(0, 100)), r.getrandbits(32),
            r.getrandbits(32)]


S(0x52c270, 'ZPathfinder3::RequestPathOld', 'thiscall', None, ret='eax', gen=_req)
