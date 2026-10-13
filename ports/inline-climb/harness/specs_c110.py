"""specs_c110.py - climb thread batch 110: 0x5e88e0 ZFFHeroMovementOpenSewer::WantControl."""
import struct
from pilot import S
from ckit import obj, rnd, floats, wfloats


def _wc(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x5c0)
    e.w8(self_ + 0x54c, 0 if r.random() < 0.85 else 1)
    pos = c.fbuf(3)
    edge = r.random() < 0.2
    if edge:   # integer positions so a lid exactly 200 units away gives a squared distance of exactly 40000
        wfloats(e, pos, [float(r.randint(-100, 100)) for _ in range(3)])
    pv = [e.rf32(pos + 4 * i) for i in range(3)]
    n = r.choice([0, 1, 2, 3, 5])
    gd = rnd(c, 0xc6d + 9 * n + 16, 1)
    e.mu.mem_write(gd + 0xc69, struct.pack('<i', n))
    geoms = {}
    for k in range(n):
        rec = gd + 0xc6d + 9 * k
        ref = 0x10000 + k
        e.mu.mem_write(rec + 4, struct.pack('<I', ref))
        e.w8(rec + 8, r.choice([0, 1]))
        near = r.random() < 0.6
        gp = [pv[0] + c.fv(-120, 120), pv[1] - 60 + c.fv(-120, 120), pv[2] + c.fv(-120, 120)] if near else \
            [c.fv(-3000, 3000) for _ in range(3)]
        if edge and r.random() < 0.6:
            gp = [pv[0] + r.choice([200.0, -200.0, 199.0, 201.0]), pv[1] - 60.0, pv[2]]
        m = [c.fv(-2, 2) for _ in range(9)]

        def matpos(e, t, a, m=m, gp=gp):
            wfloats(e, a[0], m)
            wfloats(e, a[1], gp)
            return (0, None, ())
        geoms[ref] = obj(e, 'lid%d' % k, 0x10, {0x80: (2, matpos)})
    e.w32(0x7003b8, gd)
    db = obj(e, 'enginedb', 0x10, {0x58: (1, lambda e, t, a: (geoms.get(a[0], 0), None, (a[0],)))})
    sys_ = rnd(c, 0x100)
    e.mu.mem_write(sys_ + 0x9b, struct.pack('<I', db))
    e.w32(0x70039c, sys_)
    hero = rnd(c, 0xa00)
    e.w8(hero + 0x9f5, 0 if r.random() < 0.1 else 1)
    e.mu.mem_write(hero + 0x9d3, struct.pack('<i', r.choice([0xa, 0xc, 0, 3])))
    e.w8(hero + 0x66c, r.choice([0, 1]))
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', hero))

    def act(e, res):
        e.calllog.append(('ActivateMenu', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    e.hook(0x5c3860, act)
    return [self_, c.fbuf(3), pos, c.fbuf(3)]


S(0x5e88e0, 'ZFFHeroMovementOpenSewer::WantControl', 'thiscall', None, ret='al', gen=_wc,
  note='c110; ActivateMenu is a hook; SetUseAction, PSVECSubtract, in-place vscalar and CRT sqrt run as original')
