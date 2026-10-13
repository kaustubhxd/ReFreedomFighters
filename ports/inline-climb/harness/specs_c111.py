"""specs_c111.py - climb thread batch 111: 0x59a6b0 ZGameOSD::ProgressValue, 0x5e5600 OpenSewer GotControl."""
import struct
from pilot import S, F
from ckit import obj, rnd, floats, wfloats

S(0x59a6b0, 'ZGameOSD::ProgressValue', 'thiscall', None, ret=None,
  gen=lambda c: [rnd(c, 0x22e0), F(c.rng.choice([c.fv(), c.fv(-0.5, 1.5), 0.0, -0.0, 1.0]))], note='c111')


def _gc(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x5c0)
    sys_ = rnd(c, 0x100)
    e.w32(0x70039c, sys_)
    e.w32(sys_ + 0x40, r.randint(0, 1 << 22))
    hm = [c.fv(-2, 2) for _ in range(9)]
    hp = [c.fv(-500, 500) for _ in range(3)]

    def hmatpos(e, t, a):
        wfloats(e, a[0], hm)
        wfloats(e, a[1], hp)
        return (0, None, (a[0], a[1]))
    osd = rnd(c, 0x22e0)
    hero = obj(e, 'hero', 0xa00, {0x59c: (2, hmatpos)}, rng=r)
    e.mu.mem_write(hero + 0x852, struct.pack('<I', osd))
    e.mu.mem_write(self_ + 0x36d, struct.pack('<I', hero))

    def mp(tag, m, p):
        def f(e, t, a):
            wfloats(e, a[0], m)
            wfloats(e, a[1], p)
            return (0, None, (tag,))
        return f
    lp = [hp[0] + c.fv(-200, 200), hp[1] + c.fv(-5, 5), hp[2] + c.fv(-200, 200)]
    if r.random() < 0.1:
        lp = [hp[0], hp[1], hp[2]]
    setlog = lambda e, t, a: (0, None, (floats(e, a[0], 9), floats(e, a[1], 3)))
    child = obj(e, 'lidchild', 0x10, {0x80: (2, mp('child', [c.fv(-2, 2) for _ in range(9)], [c.fv(-500, 500) for _ in range(3)])),
                                      0x7c: (2, setlog)})
    lid = obj(e, 'lid', 0x10, {0x20: (0, lambda e, t, a: (child, None, ())),
                               0x80: (2, mp('lid', [c.fv(-2, 2) for _ in range(9)], lp)), 0x7c: (2, setlog)})
    db = obj(e, 'enginedb', 0x10, {0x58: (1, lambda e, t, a: (lid, None, (a[0],)))})
    e.mu.mem_write(sys_ + 0x9b, struct.pack('<I', db))
    sew = rnd(c, 16)
    e.mu.mem_write(self_ + 0x557, struct.pack('<I', sew))

    def sti(e, res):
        e.calllog.append(('SetTempItem', e.reg('ecx'), e.arg32(0)))
        e.ret(argbytes=4)
    e.hook(0x595010, sti)
    return [self_]


S(0x5e5600, 'ZFFHeroMovementOpenSewer::GotControl', 'thiscall', None, ret=None, gen=_gc,
  note='c111; SetTempItem is a hook; matrix and vector helpers run as original')
