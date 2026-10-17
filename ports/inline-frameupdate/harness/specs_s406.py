"""specs_s406.py - batch 406: ZPlayer::UpdatePoolGeoms."""
from pilot import S
import fu_kit as K


def _coli_log(e, a):
    p = a[0]
    e.calllog.append(('coli', e.rbytes(p, 0x18).hex(), e.rbytes(p + 0x34, 4).hex(), e.rbytes(p + 0x44, 4).hex(),
                      e.rbytes(p + 0x6c, 1).hex()))


def _upg(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {})
    cmat = [r.uniform(-1, 1) for _ in range(9)]
    cpos = [r.uniform(-500, 500) for _ in range(3)]
    vel = [r.uniform(-5, 5) for _ in range(3)] if r.random() < 0.8 else [0.0, 0.0, 0.0]
    dt = r.choice([1 / 60.0, 1 / 30.0, 0.0, r.uniform(0, 0.1)])
    pos = [cpos[i] + vel[i] * dt * 60 for i in range(3)]
    so = K.rnd(c, 0x100)
    e.wf32(so + 0x48, dt)
    now = r.randint(0, 1 << 22)
    e.w32(so + 0x40, now)
    world = K.obj(c, 0x40, {0x2e0: K.fn(c, 'world.cast', 6, ret=lambda ee, a: K.bool8(c, 0.6), body=_coli_log)}, 'world')
    rm = K.rnd(c, 0xae0 + 8)
    e.w32(rm + 0xadc, world)
    e.w32(so + 0x9b, rm)
    e.w32(0x70039c, so)
    log = K.obj(c, 0x40, {0x30: K.fn(c, 'log.print', 2, cdecl=True, noecx=True)}, 'log')
    logger = K.obj(c, 0x40, {0x20: K.fn(c, 'logger.at', 2, ret=log)}, 'logger')
    e.w32(0x700390, logger)
    g8 = K.rnd(c, 0x48)
    e.wf32(g8 + 0x34, r.uniform(50, 100))
    e.wf32(g8 + 0x44, r.uniform(50, 100))
    self = K.obj(c, 0x700, {0x59c: K.fn(c, 'GetCenterMatPos', 2, body=lambda ee, a: (K.wfloats(ee, a[0], cmat), K.wfloats(ee, a[1], cpos))),
                            0x5c4: K.fn(c, 'slot5c4', 1, body=lambda ee, a: K.wfloats(ee, a[0], vel))}, 'player')
    e.w32(self + 8, g8)
    e.wf32(self + 0x4dd, r.choice([1.0, 80.0, 0.0, r.uniform(0, 200)]))
    K.setbyte(c, self + 0x5ff, 0.15)
    full = r.random() < 0.15
    e.w32(self + 0x4f1, 0)
    nrec = r.choice([0, 1, 2, 3, 5, 6])
    base = K.rnd(c, 0x4b4 + 4 * max(nrec, 1))
    e.w32(base + 0x4b0, nrec)
    for i in range(nrec):
        rec = K.rnd(c, 0x60)
        radius = r.uniform(5, 60)
        e.wf32(rec + 0x38, radius)
        e.wf32(rec + 0x3c, r.choice([10000.0, 20000.0, 9999.0, r.uniform(1, 200), r.uniform(1, 200)]) if not full else 10000.0)
        K.setbyte(c, rec + 0x4c, 0.15)
        x = r.random()
        dist = r.uniform(0, radius + 40) if x < 0.7 else r.uniform(radius + 40, radius + 300)
        import math as _m
        ang = r.uniform(0, 6.283)
        rp = [pos[0] + dist * _m.cos(ang), pos[1] + r.uniform(-50, 50), pos[2] + dist * _m.sin(ang)]
        if r.random() < 0.1:
            rp = list(cpos)   # exactly on the player: zero push direction
        K.wfloats(e, rec + 8, rp)
        e.w32(rec + 0x4d, (now + r.randint(-10, 10)) & 0xffffffff)
        rootPos = [rp[0] + r.uniform(-1, 1), r.uniform(pos[1] - 150, pos[1] + 50), rp[2] + r.uniform(-1, 1)]
        rmat = [r.uniform(-1, 1) for _ in range(9)]
        gb = K.rnd(c, 0x48)
        if r.random() < 0.85:
            e.w32(gb + 0x3c, e.r32(gb + 0x3c) & ~0x800)
        e.wf32(gb + 0x34, r.uniform(0, 50))
        e.wf32(gb + 0x44, r.uniform(10, 60))
        g = K.obj(c, 0x40, {0x7c: K.fn(c, 'g.SetRootTM', 2, sizes={1: 12}),
                            0x80: K.fn(c, 'g.GetRootTM', 2, body=lambda ee, a, rm_=rmat, rp_=rootPos: (K.wfloats(ee, a[0], rm_), K.wfloats(ee, a[1], rp_)))}, 'g')
        e.w32(g + 8, gb)
        o = K.obj(c, 0x40, {0x20: K.fn(c, 'o.geom', 0, ret=g)}, 'o')
        fl = K.rnd(c, 8)
        if r.random() < 0.85:
            e.w8(fl + 4, e.r8(fl + 4) & ~2)
        e.w32(o + 0x1c, fl)
        e.w32(rec + 4, o)
        e.w32(base + 0x4b4 + 4 * i, rec)
    if full:
        e.w32(self + 0x4f1, r.choice([2, 4, 5]))
    e.w32(0x7003b8, base)
    return [self]


S(0x485110, 'ZPlayer::UpdatePoolGeoms', 'thiscall', None, ret=None, gen=_upg,
  note='batch406; collision-response and vector helpers as exe code')
