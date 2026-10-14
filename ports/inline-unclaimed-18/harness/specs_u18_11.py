"""specs_u18_11.py - area 18, group 11 (unclaimed-18 thread)."""
from pilot import S
from ckit import obj, rnd, rvt


def _is(c):
    r = c.rng
    e = c.emu
    e.hook(0x441790, lambda e, res: (e.calllog.append(('ZGROUP::Save', e.reg('ecx'), e.arg32(0))), e.ret(argbytes=4)))
    o = rnd(c, 0x200)
    e.w32(o + 0x5c, r.getrandbits(32))
    sg = obj(e, 'savegame', 0x40, {0x3c: (1, lambda e, t, a: (0, None, (a[0],)))}, nslots=0x40 // 4)
    return [o, sg]


S(0x454950, 'ZInstance::Save', 'thiscall', None, ret='al', gen=_is,
  note='u18; ZGROUP::Save is a logging hook (not lifted)')
