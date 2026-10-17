"""specs_s407.py - batch 407: ZPlayer::MovementControl."""
from pilot import S
import fu_kit as K


def _mc(c):
    r = c.rng
    e = c.emu
    hit = K.rnd(c, 0x60)
    dps = {}

    def gdp(ee, a):
        return dps.get(ee.reg('ecx'), 0)
    K.hooks(c, {0x484b10: ('PositionCollisionBox', 5, 0, None, {2: 12}),
                0x4eb080: ('box.4eb080', 3, 0, None, {0: 36, 1: 12}),
                0x4ea300: ('GetStrips', 1), 0x4895c0: ('ctl.step', 2), 0x4ea8e0: ('box.step', 2),
                0x4ea260: ('box.ground', 1, hit if r.random() < 0.7 else 0),
                0x4dafb0: ('GetDynamicParent', 0, gdp),
                0x4db6c0: ('GetRootTM', 2, 0, lambda ee, a: (K.wfloats(ee, a[0], pm), K.wfloats(ee, a[1], pp))),
                0x4db9a0: ('IsDerivedFrom', 1, K.bool8(c, 0.5))})
    pm = [r.uniform(-1, 1) for _ in range(9)]
    pp = [r.uniform(-100, 100) for _ in range(3)]
    st = {'n': 0}

    def move(ee, a):
        st['n'] += 1
        K.wfloats(ee, a[2], [r.uniform(-1, 1) for _ in range(9)])
        K.wfloats(ee, a[3], [r.uniform(-500, 500) for _ in range(3)])
    box = K.rnd(c, 0x40)
    mgr = K.obj(c, 0x60, {0x48: K.fn(c, 'mgr.alloc', 2, ret=box), 0x4c: K.fn(c, 'mgr.free', 1)}, 'mgr')
    hold = K.rnd(c, 0x20)
    e.w32(hold + 0x1c, mgr)
    gnd = K.rnd(c, 0x20)
    ggeom = K.rnd(c, 0x60)
    e.w32(gnd + 8, ggeom)
    if r.random() < 0.5:
        dps[ggeom] = K.rnd(c, 0x40)
    if r.random() < 0.6:
        dps[hit] = r.choice([K.rnd(c, 0x40), dps.get(ggeom, 0) or K.rnd(c, 0x40)])
    rm = K.obj(c, 0x60, {0x58: K.fn(c, 'rm.byHandle', 1, ret=gnd if r.random() < 0.7 else 0),
                         0x4c: K.fn(c, 'rm.handle', 1, ret=r.getrandbits(32))}, 'rm')
    so = K.sysobj(c, {}, size=0x1ab0)
    e.w32(so + 0x1aa3, hold)
    e.w32(so + 0x9b, rm)
    rate = r.choice([60.0, 30.0, 120.0, 45.0, r.uniform(10, 200)])
    e.wf32(so + 0x54, rate)
    e.wf32(so + 0x48, r.choice([1 / 30.0, 1 / 60.0, 0.1, 0.0, r.uniform(0, 0.15)]))
    ctl_slots = {0x14: K.fn(c, 'ctl.move', 5, body=move, sizes={0: 36, 1: 12}), 0x18: K.fn(c, 'ctl.end', 0),
                 0x8: K.fn(c, 'ctl.canLeave', 1, ret=K.bool8(c, 0.4)), 0x10: K.fn(c, 'ctl.enter', 0),
                 0xc: K.fn(c, 'ctl.accept', 3, ret=lambda ee, a: K.bool8(c, 0.5))}
    ctls = [K.obj(c, 0x40, ctl_slots, 'ctl%d' % i) for i in range(4)]
    self = K.obj(c, 0x700, {0x324: K.fn(c, 'slot324', 1, ret=K.bool8(c, 0.6)),
                            0x320: K.fn(c, 'slot320', 1, ret=r.getrandbits(32)),
                            0x640: K.fn(c, 'slot640', 1, ret=ctls[0]), 0x644: K.fn(c, 'slot644', 1),
                            0x428: K.fn(c, 'slot428', 0, ret=r.getrandbits(32)), 0x424: K.fn(c, 'slot424', 1)}, 'player')
    n = r.choice([0, 1, 2, 3])
    e.w32(self + 0x459, n)
    for i in range(1, n + 1):
        e.w32(self + 0x45d + 4 * i, ctls[i] if r.random() < 0.85 else 0)
    e.w32(self + 0x455, r.choice(ctls))
    K.setbyte(c, self + 0x591, 0.5)
    K.setbyte(c, self + 0x5ff, 0.3)
    for off, cnt in ((0x525, 9), (0x555, 9), (0x549, 3), (0x579, 3), (0x585, 3), (0x519, 3), (0x4f5, 9)):
        K.wfloats(e, self + off, [r.uniform(-2, 2) for _ in range(cnt)])
    return [self, K.vec(c, 9, -1, 1), K.vec(c, 3, -500, 500), K.vec(c, 9, -1, 1), K.vec(c, 3, -500, 500)]


S(0x484380, 'ZPlayer::MovementControl', 'thiscall', None, ret=None, gen=_mc, note='batch407; vector/matrix helpers as exe code')
