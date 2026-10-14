"""specs_u69_06.py - area 69, group 6 (unclaimed-69 thread)."""
from pilot import S
from ckit import obj, rnd


def _eds(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x200)
    n = r.choice([0, 1, 2, 3])
    e.w32(o + 0xec, n)
    for i in range(n):
        child = obj(e, 'shadow%d' % i, 0x40, {0x70: (0, lambda e, t, a: (0, None, ()))}, nslots=0x74 // 4)
        e.w32(o + 0xf0 + 4 * i, child)
    return [o]


S(0x63da50, 'ZDrawBase::EndShadows', 'thiscall', None, ret=None, gen=_eds, note='u69')


def _sn(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    sg = obj(e, 'savegame', 0x80, {0x3c: (1, lambda e, t, a: (0, None, (a[0],))),
                                   0x40: (1, lambda e, t, a: (0, None, (a[0],))),
                                   0x44: (1, lambda e, t, a: (0, None, (a[0],)))}, nslots=0x48 // 4)
    return [o, sg]


S(0x4a8550, 'ZSelectNotify::Save', 'thiscall', None, ret='al', gen=_sn, note='u69')
