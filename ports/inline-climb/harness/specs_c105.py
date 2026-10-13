"""specs_c105.py - climb thread batch 105: 0x443ef0, fall CalcNewSpeed, fall and jump WantControl."""
import struct
from pilot import S, F
from ckit import obj, rnd, floats, wfloats


def _v4(c):
    r = c.rng
    out = c.fbuf(3, pad=2)
    a = out if r.random() < 0.2 else c.fbuf(3, pad=2)
    b = out if r.random() < 0.3 else c.fbuf(3, pad=2)
    return [out, a, b, F(c.fv())]


S(0x443ef0, 'vaddscalar (4 args)', 'fastcall', None, ret=None, gen=_v4, note='c105; out = a + b*s, x87')


def _fcns(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x580)
    fv = [c.fv(-30, 30) for _ in range(3)]
    if r.random() < 0.15:
        fv = [0.0, 0.0, 0.0]
    wfloats(e, self_ + 0x56b, fv)
    sp = c.fbuf(3, pad=2)
    newsp = [c.fv(-60, 60) for _ in range(3)]

    def base(e, res, newsp=newsp):
        e.calllog.append(('BaseMove::CalcNewSpeed', e.reg('ecx'), e.arg32(0), e.arg32(1), e.arg32(2), e.arg32(3)))
        wfloats(e, e.arg32(2), newsp)
        e.ret(argbytes=16)
    e.hook(0x5e17b0, base)
    return [self_, c.fbuf(3), c.fbuf(3), sp, c.fbuf(3)]


S(0x5e1a10, 'ZFFHeroMovementFall::CalcNewSpeed', 'thiscall', None, ret=None, gen=_fcns,
  note='c105; base CalcNewSpeed is a hook writing a new speed; vaddscalar4, vsetlen and CRT sqrt run as original')


def _hero(c):
    r = c.rng
    e = c.emu
    ground = r.choice([0, 0, 1, 0x100, 0xffffff00, r.getrandbits(32)])
    h = obj(e, 'hero', 0x960, {0x5a4: (0, lambda e, t, a: (ground, None, ()))}, rng=r)
    if r.random() < 0.7:
        wfloats(e, h + 0x942, [r.choice([5.0, 4.99, 0.0, -1.0, 100.0, float('nan'), c.fv(0, 20)])])
    if r.random() < 0.5:
        e.w32(h + 0x417, e.r32(h + 0x417) & ~0xc000000 if r.random() < 0.7 else e.r32(h + 0x417))
    return h


def _fwc(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x560)
    e.w8(self_ + 0x554, 0 if r.random() < 0.8 else 1)
    e.w8(self_ + 0x555, 0 if r.random() < 0.5 else r.getrandbits(8))
    h = _hero(c)
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', h))
    b = c.fbuf(3)
    vel = c.fbuf(3)
    wfloats(e, vel + 4, [r.choice([-20.0, -19.0, -21.0, -100.0, 0.0, float('nan'), c.fv(-60, 10)])])
    if r.random() < 0.5:
        e.mu.mem_write(self_ + 0x557, struct.pack('<f', c.fv()))
    return [self_, c.fbuf(3), b, vel]


S(0x5e7e70, 'ZFFHeroMovementFall::WantControl', 'thiscall', None, ret='al', gen=_fwc, note='c105')


def _jwc(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x560)
    e.w8(self_ + 0x550, 0 if r.random() < 0.8 else 1)
    h = _hero(c)
    if r.random() < 0.6:
        e.w32(h + 0x417, e.r32(h + 0x417) | (1 << 19))
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', h))
    owner = h if r.random() < 0.5 else _hero(c)
    e.w32(self_ + 4, owner)
    return [self_, c.fbuf(3), c.fbuf(3), c.fbuf(3)]


S(0x5e83e0, 'ZFFHeroMovementJump::WantControl', 'thiscall', None, ret='al', gen=_jwc,
  note='c105; GetJump runs as original code')
