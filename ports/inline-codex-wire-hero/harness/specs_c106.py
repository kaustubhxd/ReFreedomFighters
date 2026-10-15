"""specs_c106.py - climb thread batch 106: fall/jump GotControl, jump CalcNewSpeed and GetActiveAnim."""
import struct
from pilot import S
from ckit import obj, rnd, floats, wfloats


def _sys(c):
    r = c.rng
    s = rnd(c, 0x80)
    c.emu.w32(0x70039c, s)
    c.emu.w32(s + 0x40, r.choice([r.randint(0, 1 << 22), r.getrandbits(32), 0, 1024]))
    return s


def _base_hook(c, newsp):
    def base(e, res):
        # log contents (mat and pos are stack buffers in the caller)
        e.calllog.append(('BaseMove::CalcNewSpeed', e.reg('ecx'), floats(e, e.arg32(0), 9), floats(e, e.arg32(1), 3),
                          e.arg32(2)))
        wfloats(e, e.arg32(2), newsp)
        wfloats(e, e.arg32(3), newsp[::-1])
        e.ret(argbytes=16)
    c.emu.hook(0x5e17b0, base)


def _hero(c, extra=None):
    e = c.emu
    m = [c.fv(-2, 2) for _ in range(9)]
    p = [c.fv(-500, 500) for _ in range(3)]

    def matpos(e, t, a):
        wfloats(e, a[0], m)
        wfloats(e, a[1], p)
        return (0, None, ())
    slots = {0x80: (2, matpos)}
    slots.update(extra or {})
    return obj(e, 'hero', 0x960, slots, rng=c.rng)


def _gc(c):
    e = c.emu
    self_ = rnd(c, 0x5c0)
    _sys(c)
    _base_hook(c, [c.fv(-30, 30) for _ in range(3)])
    h = _hero(c)
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', h))

    def tick(e, t, a):
        return (0, None, (a[0],))
    owner = obj(e, 'owner', 0x10, {0x400: (1, tick)})
    e.w32(self_ + 4, owner)
    return [self_]


S(0x5e5060, 'ZFFHeroMovementFall::GotControl', 'thiscall', None, ret=None, gen=_gc,
  note='c106; base CalcNewSpeed is a hook (logs matrix and position contents)')
S(0x5e51e0, 'ZFFHeroMovementJump::GotControl', 'thiscall', None, ret=None, gen=_gc,
  note='c106; base CalcNewSpeed is a hook; owner slot 0x400 logs its float')


def _jcns(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x5c0)
    s = _sys(c)
    _base_hook(c, [c.fv(-60, 60) for _ in range(3)])
    jv = [c.fv(-30, 30) for _ in range(3)] if r.random() < 0.85 else [0.0, 0.0, 0.0]
    wfloats(e, self_ + 0x5a3, jv)
    e.w8(self_ + 0x559, 0 if r.random() < 0.2 else 1)
    # take-off time near the tick counter so both sides of the test come up
    t0 = r.randint(0, 1 << 20)
    e.w32(s + 0x40, t0)
    wfloats(e, self_ + 0x593, [r.choice([2.0, 0.0, 25.0, c.fv(0, 50)])])
    wfloats(e, self_ + 0x551, [t0 / 1024.0 - r.choice([0.0, 0.08, 0.1, 1.0, -1.0, c.fv(-2, 2)])])
    pv = [c.fv(-30, 30) for _ in range(3)]
    pbuf = e.alloc(16, 4)
    wfloats(e, pbuf, pv)
    h = obj(e, 'hero', 0x960, {0x5b8: (0, lambda e, t, a: (pbuf, None, ()))}, rng=r)
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', h))
    return [self_, c.fbuf(3), c.fbuf(3), c.fbuf(3), c.fbuf(3)]


S(0x5e1ae0, 'ZFFHeroMovementJump::CalcNewSpeed', 'thiscall', None, ret=None, gen=_jcns,
  note='c106; base CalcNewSpeed is a hook; vscalar, vaddscalar4, vsetlen and CRT sqrt run as original')


def _jga(c):
    e = c.emu
    r = c.rng
    self_ = rnd(c, 0x5c0)
    s = _sys(c)
    t0 = r.randint(0, 1 << 20)
    e.w32(s + 0x40, t0)
    hdr = rnd(c, 0x80)
    e.w32(hdr + 0x6c, r.choice([15, 25, 30, 0, r.randint(-5, 60)]))
    field = r.choice([0x55f, 0x577])
    e.mu.mem_write(self_ + field, struct.pack('<I', hdr))
    e.mu.mem_write(self_ + field + 8, struct.pack('<i', r.choice([30, 31, 1, 0, r.randint(-3, 60)])))
    e.mu.mem_write(self_ + 0x58f, struct.pack('<I', self_ + field))
    e.w8(self_ + 0x55e, 0 if r.random() < 0.5 else 1)
    for off in (0x551, 0x55a):
        wfloats(e, self_ + off, [t0 / 1024.0 - r.choice([0.0, 0.5, 1.0, 2.0, c.fv(-3, 3)])])
    wfloats(e, self_ + 0x597, [27.0, 27.0, 30.0])
    if r.random() < 0.3:
        wfloats(e, self_ + 0x597, [c.fv(0, 40) for _ in range(3)])
    wfloats(e, self_ + 0x555, [c.fv(-200, 200)])
    out = rnd(c, 8)
    d = c.fbuf(3)
    if r.random() < 0.5:
        wfloats(e, d + 4, [e.rf32(self_ + 0x555) - r.choice([100.0, 99.0, 101.0, 0.0])])
    return [self_, out, c.fbuf(3), c.fbuf(3), c.fbuf(3), d]


S(0x5e2e50, 'ZFFHeroMovementJump::GetActiveAnim', 'thiscall', None, ret='st0', gen=_jga, note='c106')
