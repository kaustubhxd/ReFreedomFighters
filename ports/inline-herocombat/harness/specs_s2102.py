"""specs_s2102.py - wire-hero-combat batch 2102: 0x4b96c0 ZProjectile::FrameUpdate (2026-10-13).
Hooked (call-recording, both builds hit the same hooks): FrameUpdateBallistic 0x4b9940, CheckHit 0x4b9340 (returns a
per-case sequence in ST0: no hit = exactly the distance asked, a hit at a shorter distance, or NaN; it also rewrites the
COLI's hit handle +0x44), ShotImpact 0x4ba7f0, ZBaseGeom::SetControl 0x4dc630. Exe code: vaddscalar4 0x443ef0.
The render manager's slot 0x58 maps handles to the owner / a hit object / 0. The geom (+0x44) logs slot 0x28 and the
position slot 0x70 gets (its 3 floats are logged)."""
import struct
from pilot import S

NAN = float('nan')


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


class Log:
    def __init__(self, c, words=512):
        self.emu = c.emu
        self.base = c.emu.alloc(4 * words, 4)
        self.n = 0
        self.cap = words

    def put(self, *ws):
        for w in ws:
            if self.n < self.cap:
                self.emu.w32(self.base + 4 * self.n, w & 0xffffffff)
                self.n += 1


def fb(x):
    return struct.unpack('<I', struct.pack('<f', x))[0]


def _fu(c):
    r = c.rng
    log = Log(c)
    self_ = _rnd(c, 0x100)
    x = r.random()
    if x < 0.05:
        fl = 0x10 | r.getrandbits(32)
    elif x < 0.15:
        fl = (r.getrandbits(32) & ~0x10) | 8
    else:
        fl = r.getrandbits(32) & ~0x18
    c.emu.w32(self_ + 0x89, fl)
    # time: clock ticks now, +0x69 the last update (s), sometimes odd
    now = r.choice((r.randint(0, 1 << 20), r.randint(0, 1 << 20), r.randint(-50, 50), r.getrandbits(32) - (1 << 31)))
    sysobj = _rnd(c, 0x200)
    c.emu.w32(0x70039c, sysobj)
    c.emu.w32(sysobj + 0x40, now & 0xffffffff)
    y = r.random()
    if y < 0.8:
        last = (now - r.randint(0, 120)) / 1024.0
    elif y < 0.9:
        last = r.choice((0.0, -0.0, 1e9, -1e9, NAN, float('inf')))
    else:
        last = r.uniform(-100, 100)
    c.emu.wf32(self_ + 0x69, last)
    c.emu.wf32(self_ + 0x51, r.choice((r.uniform(0, 60), r.uniform(0, 60), 0.0, -r.uniform(0, 10), NAN)))
    c.emu.wf32(self_ + 0x55, r.choice((r.uniform(0, 5000), 0.0, NAN)))
    c.emu.wf32(self_ + 0x59, r.choice((r.uniform(0, 8000), r.uniform(0, 8000), 0.0)))
    # handles: owner +0x5d, hit object, unknown
    hOwner, hHit, hNone = 0x1000 + r.randint(0, 9), 0x2000 + r.randint(0, 9), 0x3000 + r.randint(0, 9)
    c.emu.w32(self_ + 0x5d, hOwner)
    ownerGeom = _rnd(c, 0x40)
    owner = _rnd(c, 0x20); c.emu.w32(owner + 8, ownerGeom)
    hitGeom = _rnd(c, 0x40)
    hit = _rnd(c, 0x20); c.emu.w32(hit + 8, hitGeom)
    ownerKnown = r.random() < 0.7
    objs = {hOwner: owner if ownerKnown else 0, hHit: hit, hNone: 0}

    def rm58(e, _):
        h = e.arg32(0)
        log.put(0x58, h)
        e.ret(eax=objs.get(h, 0), argbytes=4)
    rm = c.emu.fake_object('rm', 0x20, slots={0x58: rm58})
    c.emu.w32(sysobj + 0x9b, rm)
    # COLI at +0x8d
    coli = _rnd(c, 0x60)
    c.emu.w32(self_ + 0x8d, coli)
    # CheckHit decisions: (kind, fraction, handle); after them always "no hit"
    plan = []
    for _ in range(r.randint(0, 4)):
        k = r.random()
        plan.append(('nan' if k < 0.05 else 'hit', r.random(), r.choice((hOwner, hHit, hHit, hNone))))
    state = {'i': 0}

    def checkHit(e, _):
        d = e.argf(0)
        log.put(0x4b9340, e.reg('ecx'), e.arg32(0))
        i = state['i']; state['i'] += 1
        if i < len(plan):
            kind, f, h = plan[i]
            e.w32(coli + 0x44, h)
            v = NAN if kind == 'nan' else d * f
        else:
            v = d
        e.ret(argbytes=4, st0=v)
    c.emu.hook(0x4b9340, checkHit)

    def shotImpact(e, _):
        log.put(0x4ba7f0, e.reg('ecx'), e.arg32(0), e.r32(coli + 0x44))
        e.ret(argbytes=4)
    c.emu.hook(0x4ba7f0, shotImpact)

    def ballistic(e, _):
        log.put(0x4b9940, e.reg('ecx'))
        e.ret(argbytes=0)
    c.emu.hook(0x4b9940, ballistic)

    def setControl(e, _):
        log.put(0x4dc630, e.reg('ecx'), e.arg32(0), e.arg32(1))
        e.ret(argbytes=8)
    c.emu.hook(0x4dc630, setControl)
    # the projectile's geom +0x44: slot 0x28 remove, slot 0x70 set position; +8 its matrix (row 2 at +0x18, position
    # +0x24, +0x40 a float the end test reads)
    m = _rnd(c, 0x48)
    for off in range(0x18, 0x30, 4):
        c.emu.wf32(m + off, r.uniform(-1000, 1000) if off >= 0x24 else r.uniform(-1, 1))
    c.emu.wf32(m + 0x40, r.choice((r.uniform(0, 8000), 0.0, NAN)))

    def g28(e, _):
        log.put(0x28, e.reg('ecx'))
        e.ret(argbytes=0)

    def g70(e, _):
        p = e.arg32(0)
        log.put(0x70, e.reg('ecx'), e.r32(p), e.r32(p + 4), e.r32(p + 8))
        e.ret(argbytes=4)
    g = c.emu.fake_object('geom', 0x20, slots={0x28: g28, 0x70: g70})
    c.emu.w32(g + 8, m)
    c.emu.w32(self_ + 0x44, g)
    c.emu.mu.ctl_flush_tb()
    return [self_]


S(0x4b96c0, 'ZProjectile::FrameUpdate', 'thiscall', None, ret=None, gen=_fu,
  note='batch2102; CheckHit / ShotImpact / FrameUpdateBallistic / SetControl hooked and logged; vaddscalar4 exe code')
