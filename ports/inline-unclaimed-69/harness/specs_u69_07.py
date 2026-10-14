"""specs_u69_07.py - area 69, group 7 (unclaimed-69 thread)."""
from pilot import S
from ckit import obj, rnd


def _pps(c):
    e = c.emu
    sg = obj(e, 'savegame', 0x80, {0x4c: (1, lambda e, t, a: (0, None, (a[0],))),
                                   0x68: (1, lambda e, t, a: (0, None, (a[0],)))}, nslots=0x70 // 4)
    o = rnd(c, 0x100)
    return [o, sg]


S(0x4e74d0, 'ZParamParticle::Save', 'thiscall', None, ret=None, gen=_pps, note='u69')


def _snl(c):
    r = c.rng
    e = c.emu
    sysobj = rnd(c, 0x200)
    e.w32(0x70039c, sysobj)
    engine = obj(e, 'engine', 0x40, {0x60: (1, lambda e, t, a: (r.getrandbits(32), None, (a[0],)))}, nslots=0x64 // 4)
    e.w32(sysobj + 0x9b, engine)
    e.hook(0x45f3c0, lambda e, res: (e.calllog.append(('ZGEOM::Load', e.reg('ecx'))),
                                     e.ret(eax=r.choice([0, 1, 0x100]), argbytes=4)))
    lg = obj(e, 'loadgame', 0x80, {0x40: (1, lambda e, t, a: (0, None, (a[0],))),
                                   0x68: (1, lambda e, t, a: (0, None, (a[0],)))}, nslots=0x6c // 4)
    o = rnd(c, 0x100)
    return [o, lg]


S(0x44c110, 'ZSNDOBJ::Load', 'thiscall', None, ret='al', gen=_snl, note='u69; ZGEOM::Load is a GUESS stub')
