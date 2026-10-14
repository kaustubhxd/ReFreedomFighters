"""specs_u18_13.py - core-todo residue 17 (unclaimed-18 thread)."""
import struct
from pilot import S
from ckit import obj, rnd, rvt


def _cad(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x40)
    e.w32(o, rvt(e, 'actions', {0x38: (2, lambda e, t, a: (r.choice([0, 1, 0x100]), None, (a[0], a[1]))),
                                0xa4: (1, lambda e, t, a: (r.getrandbits(8), None, (a[0],)))}, nslots=0xa8 // 4))
    return [o, rnd(c, 0x20), r.getrandbits(32)]


S(0x438110, 'ZInputActions::CheckActionDigital', 'thiscall', None, ret='al', gen=_cad, note='u18 core residue 17')


def _rpa(c):
    r = c.rng
    e = c.emu
    o = rnd(c, 0x100)
    sg = obj(e, 'savegame', 0x40, {0x4c: (1, lambda e, t, a: (0, None, (a[0],))),
                                   0x60: (1, lambda e, t, a: (0, None, (a[0],)))}, nslots=0x64 // 4)
    return [o, sg]


S(0x4e7110, 'ZRunParamAnim::Save', 'thiscall', None, ret=None, gen=_rpa, note='u18 core residue 17')


def _ad(c):
    r = c.rng
    e = c.emu
    sysobj = rnd(c, 0x2000)
    e.w32(0x70039c, sysobj)
    eng = obj(e, 'engine', 0x40, {0x114: (4, lambda e, t, a: (r.getrandbits(16), None, tuple(a[i] for i in range(4))))},
              nslots=0x118 // 4)
    e.w32(sysobj + 0x9b, eng)
    target = obj(e, 'owner', 0x40, {0x128: (3, lambda e, t, a: (0, None, (a[0], a[1], a[2])))}, nslots=0x12c // 4)
    o = rnd(c, 0x40)
    e.w32(o + 8, target)
    return [o]


S(0x5eafd0, 'unnamed ActionDone callback (GC name ZFFActionThrow::CallBack, low)', 'thiscall', None, ret='al',
  gen=_ad, note='u18 core residue 17; engine slot 0x114 takes six arguments, slot 0x128 one')
