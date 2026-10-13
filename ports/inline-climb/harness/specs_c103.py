"""specs_c103.py - climb thread batch 103: 0x5e0100 ZFFActionClimbSewer::Execute."""
import struct
from pilot import S
from ckit import obj, rnd, floats, wfloats


def _exec(c):
    r = c.rng
    e = c.emu
    self_ = rnd(c, 0x20)
    if r.random() < 0.1:
        e.w32(self_ + 0xc, 0)
    gd = rnd(c, 0x2c20, 1)
    lc = 0 if r.random() < 0.1 else rnd(c, 0x10)
    e.mu.mem_write(gd + 0x2c15, struct.pack('<I', lc))
    e.w32(0x7003b8, gd)

    def mkpoint(tag):
        m = [c.fv(-2, 2) for _ in range(9)]
        p = [c.fv(-500, 500) for _ in range(3)]

        def matpos(e, t, a):
            wfloats(e, a[0], m)
            wfloats(e, a[1], p)
            return (0, None, (tag,))
        return obj(e, tag, 0x10, {0x80: (2, matpos)})
    hp = mkpoint('heropos') if r.random() < 0.6 else 0
    mh = mkpoint('manhole') if r.random() < 0.6 else 0

    def find(e, t, a):
        s = bytes(e.rbytes(a[0], 32)).split(b'\0')[0]
        return ((hp if b'HeroPos' in s else mh), None, (s, a[1]))
    inner = obj(e, 'lidinner', 0x10, {0x25c: (2, find)})
    mid = obj(e, 'lidmid', 0x10, {0x20: (0, lambda e, t, a: (inner, None, ()))})
    m = [c.fv(-2, 2) for _ in range(9)]
    p = [c.fv(-500, 500) for _ in range(3)]

    def lidmatpos(e, t, a):
        wfloats(e, a[0], m)
        wfloats(e, a[1], p)
        return (0, None, ('lid',))
    lid = 0 if r.random() < 0.1 else obj(e, 'lid', 0x10, {0x20: (0, lambda e, t, a: (mid, None, ())), 0x80: (2, lidmatpos)})

    def gsl(e, res):
        e.calllog.append(('GetStartingSewerLid', e.reg('ecx')))
        e.ret(eax=lid)
    e.hook(0x59b3c0, gsl)

    def place(e, t, a):
        return (0, None, (floats(e, a[0], 9), floats(e, a[1], 3)))
    hin = obj(e, 'heroinner', 0x10, {0x74: (2, place)})
    hero = obj(e, 'hero', 0x10, {0x20: (0, lambda e, t, a: (hin, None, ())), 0x228: (5, None)}, nslots=0x100)
    e.w32(self_ + 8, hero)
    return [self_]


S(0x5e0100, 'ZFFActionClimbSewer::Execute', 'thiscall', None, ret='al', gen=_exec,
  note='c103; GetStartingSewerLid is a hook returning a fake lid (it is checked on its own in c102)')
