"""specs_c112.py - climb thread batch 112: OpenSewer Move and GetActiveAnim."""
import struct
from pilot import S
from ckit import obj, rnd, floats, wfloats, rvt


def _sys(c, t0):
    s = rnd(c, 0x100)
    c.emu.w32(0x70039c, s)
    c.emu.w32(s + 0x40, t0)
    return s


def _mv(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x5c0)
    t0 = r.randint(0, 1 << 20)
    _sys(c, t0)
    wfloats(e, self_ + 0x54f, [(t0 - r.choice([0, 100, 245, 246, 1000, r.randint(-50, 400)])) / 1024.0])
    wfloats(e, self_ + 0x55b, [c.fv(-500, 500) for _ in range(6)])
    hit = r.choice([0, 1, 0x100])
    e.w32(self_, rvt(e, 'opensewer', {0x48: (5, lambda e, t, a: (hit, None, (a[0], a[1], floats(e, a[2], 9), floats(e, a[3], 3), a[4])))}))
    lg = obj(e, 'log', 0x10, {0x2c: (2, lambda e, t, a: (0, None, (a[0], a[1])), 0)})
    logger = obj(e, 'logger', 0x10, {0x20: (2, lambda e, t, a: (lg, None, (a[0], a[1])))})
    e.w32(0x700390, logger)
    return [self_, c.fbuf(9), c.fbuf(3), c.fbuf(9), c.fbuf(3), c.fbuf(3)]


S(0x5e6eb0, 'ZFFHeroMovementOpenSewer::Move', 'thiscall', None, ret=None, gen=_mv,
  note='c112; mcpy and mpul run as original')


def _ga(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x5c0)
    t0 = r.randint(0, 1 << 20)
    s = _sys(c, t0)
    e.w8(self_ + 0x54d, r.choice([0, 1]))
    if r.random() < 0.9:
        an = rnd(c, 0x80)
        e.w32(an + 0x6c, r.choice([25, 30, 139, r.randint(0, 60)]))
        e.w32(an + 0x60, r.randint(0, 5))
        e.w32(an + 0x64, e.r32(an + 0x60) + r.choice([149, 150, 199, 200, r.randint(0, 300)]))
    else:
        an = 0
    e.mu.mem_write(self_ + 0x553, struct.pack('<I', an))
    wfloats(e, self_ + 0x54f, [(t0 - r.choice([0, 1024, 4000, 5000, 6144, 8192, 8000, r.randint(0, 12000)])) / 1024.0])
    hi = r.choice([0, 0, 1, 0x100])
    osd = rnd(c, 0x22e0)
    p = [c.fv(-500, 500) for _ in range(3)]

    def topos(e, t, a):
        wfloats(e, a[0], p)
        return (0, None, ())
    hin = obj(e, 'heroinner', 0x10, {0x84: (1, topos)})

    def f3a0(e, t, a):
        wfloats(e, a[0], [1.0] * 9)
        wfloats(e, a[1], [2.0] * 3)
        return (0x3a03a0, None, ())
    hero = obj(e, 'hero', 0xa00, {0x438: (0, lambda e, t, a: (hi, None, ())), 0x3a0: (2, f3a0), 0x390: (1, None),
                                  0x20: (0, lambda e, t, a: (hin, None, ()))}, rng=r)
    e.mu.mem_write(hero + 0x852, struct.pack('<I', osd))
    wfloats(e, hero + 0x9e3, [r.choice([0.0, 0.0, 1.0, c.fv()])])
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', hero))
    sew = rnd(c, 16)
    e.mu.mem_write(self_ + 0x557, struct.pack('<I', sew))
    fid = r.getrandbits(32)
    g = obj(e, 'lidgeom', 0x10, {0x128: (3, None)}) if r.random() < 0.8 else 0
    db = obj(e, 'enginedb', 0x10, {0x58: (1, lambda e, t, a: (g, None, (a[0],))),
                                   0x114: (4, lambda e, t, a: (fid, None, (a[0], a[1], a[2], a[3])))})
    e.mu.mem_write(s + 0x9b, struct.pack('<I', db))
    lc = rnd(c, 0x60)
    e.w8(lc + 0x4a, r.choice([0x31, 0x32]))
    gd = rnd(c, 0x2c20, 1)
    e.mu.mem_write(gd + 0x2c15, struct.pack('<I', lc))
    e.w32(0x7003b8, gd)

    def hk(name, pop):
        def h(e, res):
            e.calllog.append((name, e.reg('ecx')) + tuple(e.arg32(i) for i in range(pop // 4)))
            e.ret(argbytes=pop)
        return h
    e.hook(0x594590, hk('RestoreItem', 0))
    e.hook(0x595010, hk('SetTempItem', 4))
    e.hook(0x5c3860, hk('ActivateMenu', 4))

    def cae(e, res):
        e.calllog.append(('CharismaAddExperience', e.reg('ecx'), e.arg32(0), floats(e, e.arg32(1), 3), e.arg32(2), e.arg32(3)))
        e.ret(argbytes=16)
    e.hook(0x596940, cae)
    return [self_, rnd(c, 8), c.fbuf(3), c.fbuf(3), c.fbuf(3), c.fbuf(3)]


S(0x5e3220, 'ZFFHeroMovementOpenSewer::GetActiveAnim', 'thiscall', None, ret='st0', gen=_ga,
  note='c112; RestoreItem, SetTempItem, ActivateMenu and CharismaAddExperience are hooks; ProgressValue and the OSD flag run as original')
