"""specs_s2103.py - wire-hero-combat batch 2103: 0x4b9340 ZProjectile::CheckHit, plain lift (2026-10-13).
Hooked and logged: ZBaseGeom::SetControl 0x4dc630. Exe code: vaddscalar4 0x443ef0, PSVECSubtract 0x43e920. Fake: the
geom (+0x44) slot 0x20 -> a parent whose slot 0x84 logs the point and moves it; the render manager's slot 0x58 (the
+0x65 handle -> an object or 0); the collision world (render manager +0xadc) slot 0x2e0 logs its arguments and the
COLI's from / dir / fraction / flag, writes a new fraction and answers hit or not."""
import struct
from pilot import S

NAN = float('nan')


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


class Log:
    def __init__(self, c, words=256):
        self.emu, self.base, self.n, self.cap = c.emu, c.emu.alloc(4 * words, 4), 0, words

    def put(self, *ws):
        for w in ws:
            if self.n < self.cap:
                self.emu.w32(self.base + 4 * self.n, w & 0xffffffff)
                self.n += 1


def _ch(c):
    r = c.rng
    log = Log(c)
    self_ = _rnd(c, 0x100)
    m = _rnd(c, 0x48)
    for off in range(0x18, 0x30, 4):
        c.emu.wf32(m + off, r.uniform(-1, 1) if off < 0x24 else r.uniform(-5000, 5000))
    dx, dy, dz = (r.uniform(-50, 50) for _ in range(3))

    def p84(e, _):
        p = e.arg32(0)
        log.put(0x84, e.reg('ecx'), e.r32(p), e.r32(p + 4), e.r32(p + 8))
        for k, d in enumerate((dx, dy, dz)):
            e.wf32(p + 4 * k, e.rf32(p + 4 * k) + d)
        e.ret(argbytes=4)
    par = c.emu.fake_object('parent', 0x20, slots={0x84: p84})

    def g20(e, _):
        log.put(0x20, e.reg('ecx'))
        e.ret(eax=par, argbytes=0)
    g = c.emu.fake_object('geom', 0x20, slots={0x20: g20})
    c.emu.w32(g + 8, m)
    c.emu.w32(self_ + 0x44, g)
    # pass-through handle +0x65
    h = r.choice((0, 0x1234, 0x5678))
    c.emu.w32(self_ + 0x65, h)
    obj = _rnd(c, 0x20); og = _rnd(c, 0x40); c.emu.w32(obj + 8, og)
    sysobj = _rnd(c, 0x200); c.emu.w32(0x70039c, sysobj)

    def rm58(e, _):
        hh = e.arg32(0)
        log.put(0x58, hh)
        e.ret(eax=obj if hh == 0x1234 else 0, argbytes=4)
    coli = _rnd(c, 0x80)
    c.emu.w32(self_ + 0x8d, coli)
    frac = r.choice((r.random(), r.random(), 0.0, 1.0, NAN))
    hit = r.choice((0, 1, 1, 0x100 + r.getrandbits(8)))

    def ray(e, _):
        p = e.arg32(0)
        log.put(0x2e0, e.reg('ecx'), p, e.arg32(1), e.arg32(2), e.arg32(3), e.arg32(4), e.arg32(5))
        log.put(*[e.r32(p + 4 * k) for k in range(6)], e.r32(p + 0x34), e.r8(p + 0x6c))
        e.w32(p + 0x34, struct.unpack('<I', struct.pack('<f', frac))[0])
        e.ret(eax=hit, argbytes=24)
    world = c.emu.fake_object('world', 0x20, slots={0x2e0: ray})
    rm = c.emu.fake_object('rm', 0xae0, slots={0x58: rm58})
    c.emu.w32(rm + 0xadc, world)
    c.emu.w32(sysobj + 0x9b, rm)

    def setControl(e, _):
        log.put(0x4dc630, e.reg('ecx'), e.arg32(0), e.arg32(1))
        e.ret(argbytes=8)
    c.emu.hook(0x4dc630, setControl)
    t = r.choice((r.uniform(0, 3000), r.uniform(0, 3000), r.uniform(0, 3000), 0.0, -r.uniform(0, 10), NAN, -0.0))
    c.emu.mu.ctl_flush_tb()
    return [self_, struct.unpack('<I', struct.pack('<f', t))[0]]


S(0x4b9340, 'ZProjectile::CheckHit (plain)', 'thiscall', None, ret='st0', gen=_ch,
  note='batch2103; SetControl hooked; vaddscalar4 and PSVECSubtract exe code; parent, render manager, world faked')
