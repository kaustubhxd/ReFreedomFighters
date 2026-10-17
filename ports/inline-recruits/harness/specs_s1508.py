"""specs_s1508.py - recruits thread batch 1508: ZFFHERO::InitializeFollowers, ZFFHERO::PushFollower.
mreset, vdist2 and PSVECSubtract run as exe code. The hero position call, the name lookup, the engine random and
the follower's event (records the side value by content) are recorders."""
import math
from pilot import S, F
from recruits_util import rnd, pystub, obj, hook_rec, clear_hooks, sysobj


def _init(c):
    clear_hooks(c)
    r = c.rng
    e = c.emu
    hp = [r.uniform(-1000, 1000) for _ in range(3)]

    def put(em, k):
        p = em.arg32(0)
        for i, v in enumerate(hp):
            em.wf32(p + 4 * i, v)
    s = obj(c, 0xf00, {0x84: pystub(c, 1, side=put)})
    e.w32(s + 0xd4a, r.randint(0, 3))
    idv = r.getrandbits(32)

    def nm(em, k):
        if r.random() < 0.8:
            em.w32(em.arg32(1), idv)
    names = obj(c, 0x20, {0x88: pystub(c, 2, nullflag=(1,), side=nm)})
    sysobj(c, table_slots={0x138: pystub(c, 0, ret=names), 0x58: pystub(c, 1, ret=r.getrandbits(32))})
    return [s]


def _vec(c, vals):
    p = c.emu.alloc(4 * len(vals) + 4, 4)
    for i, v in enumerate(vals):
        c.emu.wf32(p + 4 * i, v)
    return p


def _push(c):
    clear_hooks(c)
    r = c.rng
    a = obj(c, 0x40, {0x128: pystub(c, 3, deref={1: 1})})
    sysobj(c, table_slots={0x114: pystub(c, 4, ret=r.getrandbits(32))},
           rand=r.choice([0.25, 0.5, 0.75, r.random()]))
    hp = [r.uniform(-100, 100), r.uniform(-5, 5), r.uniform(-100, 100)]
    ang = r.uniform(0, 2 * math.pi)
    dist = r.choice([r.uniform(0, 80), r.uniform(0, 300), 0.0])
    fp = [hp[0] + dist * math.cos(ang), hp[1] + r.uniform(-3, 3), hp[2] + dist * math.sin(ang)]
    if r.random() < 0.05:
        fp = [hp[0], fp[1], hp[2]]   # straight above/below: the flattened direction is zero
    yaw = r.uniform(0, 2 * math.pi)
    m = [math.cos(yaw), 0.0, math.sin(yaw), 0.0, 1.0, 0.0, -math.sin(yaw), 0.0, math.cos(yaw)]
    if r.random() < 0.2:
        m = [r.uniform(-1, 1) for _ in range(9)]
    k = r.random()
    if k < 0.3:
        d = [m[0], 0.0, m[2]]
    elif k < 0.5:
        d = [-m[0], 0.0, -m[2]]
    elif k < 0.7:
        d = [m[6], 0.0, m[8]]
    else:
        t = r.uniform(0, 2 * math.pi)
        d = [math.cos(t), 0.0, math.sin(t)]
    return [rnd(c, 0x40), a, _vec(c, d), _vec(c, fp), rnd(c, 12), _vec(c, hp), _vec(c, m),
            F(r.choice([0.0, 50.0, r.uniform(0, 200)]))]


S(0x592850, 'ZFFHERO::InitializeFollowers', 'thiscall', gen=_init, note='batch1508')
S(0x5941d0, 'ZFFHERO::PushFollower', 'thiscall', ret='al', gen=_push, note='batch1508')
