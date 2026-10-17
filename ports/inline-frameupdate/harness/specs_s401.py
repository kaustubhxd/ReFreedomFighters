"""specs_s401.py - batch 401: ZFFHERO::HealWounded, ZFFHERO::DisplayUseAction, ZGameOSD::FindNextRecruit."""
from pilot import S
import fu_kit as K


def _heal(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {0x466f60: ('ZIKLNKOBJ::PlaySound', 1), 0x596940: ('CharismaAddExperience', 4, 0, None, {1: 12}),
                0x5a2e20: ('SetRecruitMode', 4), 0x634273: ('delete', 2, 0, None, None, {'cdecl': True, 'noecx': True})})
    heapstr = e.cstr('Soldier_%d' % r.randint(0, 99))
    inline = r.random() < 0.7

    def name(e, a):
        if inline:
            e.w32(a[0], a[0] + 4)
            e.wbytes(a[0] + 4, b'Civilian\0')
        else:
            e.w32(a[0], heapstr)
    out = K.obj(c, 0x40, {0x2c: K.fn(c, 'log.printf', 3, sizes={2: 9}, cdecl=True, noecx=True)}, 'out')
    log = K.obj(c, 0x40, {0x20: K.fn(c, 'log.at', 2, ret=out)}, 'log')
    e.w32(0x700390, log)
    pos = [r.uniform(-1000, 1000) for _ in range(3)]
    mat = [r.uniform(-1, 1) for _ in range(9)]
    gpos = [r.uniform(-1000, 1000) for _ in range(3)]

    def m3a0(e, a):
        K.wfloats(e, a[1], mat)
        K.wfloats(e, a[2], pos)
    g = K.obj(c, 0x40, {0x84: K.fn(c, 'g.slot84', 1, sizes={0: 12}, body=lambda e, a: K.wfloats(e, a[0], gpos))}, 'g')
    actor = K.obj(c, 0x80, {0x1d8: K.fn(c, 'actor.name', 2, ret=lambda e, a: a[0], body=name),
                            0x6a8: K.fn(c, 'actor.6a8', 0, ret=r.getrandbits(32)), 0x6a0: K.fn(c, 'actor.6a0', 1),
                            0x3a0: K.fn(c, 'actor.boneIndex', 0, ret=r.getrandbits(32)),
                            0x390: K.fn(c, 'actor.GetIKBoneMatPos', 3, body=m3a0), 0x20: K.fn(c, 'actor.20', 0, ret=g)}, 'actor')
    ti = K.rnd(c, 0x30)
    if r.random() < 0.8:
        e.w32(ti + 0x23, 0x2007f9)
    e.w32(actor + 0xc, ti)
    rec = K.rnd(c, 0x10)
    if r.random() < 0.6:
        e.w32(rec + 4, 2)
    if r.random() < 0.5:
        e.w32(rec + 8, 1)
    e.w32(actor + 0x54, rec)
    self = K.rnd(c, 0x1000)
    return [self, actor]


def _use(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {0x59a860: ('SetHelpMessage', 2, 0, None, {1: ('mask', 0xff)})})
    loc = K.obj(c, 0x10, {0: K.fn(c, 'loc.text', 2, ret=lambda e, a: 0 if r2 < 0.2 else 0x20000000 + (a[1] & 0xfff))}, 'loc')
    r2 = r.random()
    rm = K.rnd(c, 0xaf0)
    e.w32(rm + 0xae4, loc)
    so = K.rnd(c, 0x100)
    e.w32(so + 0x9b, rm)
    e.w32(0x70039c, so)
    self = K.rnd(c, 0xa00)
    x = r.random()
    a = r.randint(0, 17) if x < 0.85 else (r.choice([18, 0x7fffffff, 0x80000000, 0xffffffff]) if x < 0.95 else r.getrandbits(32))
    e.w32(self + 0x9d7, a)
    if r.random() < 0.4:
        e.w32(self + 0x9d3, a)
    if r.random() < 0.3:
        e.w32(self + 0x9df, 0)
    return [self]


def _recruit(c):
    r = c.rng
    e = c.emu
    K.hooks(c, {0x597a20: ('osd.597a20', 1, lambda e, a: bt[a[0] % 7]),
                0x597b10: ('osd.597b10', 1, lambda e, a: bt2[a[0] % 5])})
    bt = [K.bool8(c, 0.8) for _ in range(7)]
    bt2 = [K.bool8(c, 0.8) for _ in range(5)]
    hp = [r.uniform(-3000, 3000) for _ in range(3)]
    hero = K.obj(c, 0x800, {0x84: K.fn(c, 'hero.pos', 1, sizes={0: 12}, body=lambda e, a: K.wfloats(e, a[0], hp)),
                            0x438: K.fn(c, 'hero.438', 0, ret=K.bool8(c, 0.7))}, 'hero')
    hrec = K.rnd(c, 0x20)
    e.w32(hero + 0x54, hrec)
    actors = []
    for i in range(r.randint(0, 8)):
        if actors and r.random() < 0.1:
            actors.append(hero)
            continue
        x = r.random()
        if x < 0.15 and actors:   # same spot as an earlier one (tie: the first stays best)
            p = list(actors[-1][1]) if isinstance(actors[-1], tuple) else [hp[0] + 10, hp[1], hp[2]]
        elif x < 0.3:   # exactly 1500 away on one axis: d2 = 2.25e6, the limit
            p = list(hp)
            p[r.randint(0, 2)] += r.choice([1500.0, -1500.0, 1499.9, 1500.1])
        else:
            p = [hp[k] + r.uniform(-2000, 2000) for k in range(3)]
        a = K.obj(c, 0x800, {0x84: K.fn(c, 'actor.pos', 1, sizes={0: 12}, body=lambda e, ar, p=p: K.wfloats(e, ar[0], p)),
                             0x438: K.fn(c, 'actor.438', 0, ret=K.bool8(c, 0.8))}, 'actor')
        rec = K.rnd(c, 0x20)
        if r.random() < 0.15:
            e.w32(rec + 8, 4)
        e.w32(a + 0x54, rec)
        if r.random() < 0.15:
            e.w32(a + 0x77f, 5)
        actors.append((a, p))
    alist = [x if isinstance(x, int) else x[0] for x in actors]
    handles = {a: 0x1000 + 0x10 * i + r.randint(0, 3) for i, a in enumerate(alist)}

    def nxt(e, a):
        i = e.r32(a[2])
        i = 0 if i == 0xffffffff else i + 1
        e.w32(a[2], i)
        return alist[i] if i < len(alist) else 0
    lst = K.obj(c, 0x100, {0x84: K.fn(c, 'list.near', 4, ret=nxt, sizes={0: 12, 2: 4})}, 'list')
    rm = K.obj(c, 0x100, {0x4c: K.fn(c, 'rm.handle', 1, ret=lambda e, a: handles.get(a[0], 0))}, 'rm')
    so = K.rnd(c, 0x100)
    e.w32(so + 0x9b, rm)
    e.w32(0x70039c, so)
    osd = K.rnd(c, 0x1e00)
    e.w32(osd + 0x1d0b, hero)
    e.w32(osd + 0x4f7, lst if r.random() < 0.92 else 0)
    n = r.choice([0, 0, 1, 2, 3, 5, -1, 0x80000000])
    e.w32(osd + 0x4ef, n)
    for i in range(min(max(n, 0), 5)):
        e.w32(osd + 0x2ef + 4 * i, r.choice(list(handles.values()) or [7]) if r.random() < 0.5 else r.getrandbits(32))
    out = K.rnd(c, 8) if r.random() < 0.85 else 0
    return [osd, out]


S(0x592410, 'ZFFHERO::HealWounded', 'thiscall', None, ret=None, gen=_heal, note='batch401; MYSTR c_str/dtor as exe code')
S(0x591190, 'ZFFHERO::DisplayUseAction', 'thiscall', None, ret=None, gen=_use, note='batch401')
S(0x597720, 'ZGameOSD::FindNextRecruit', 'thiscall', None, ret='eax', gen=_recruit, note='batch401; vdist2 as exe code')
