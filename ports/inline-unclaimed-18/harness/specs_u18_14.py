"""specs_u18_14.py - core-todo residue 17 (unclaimed-18 thread): ZActor::SetInitialPosDir (0x47be10)."""
from pilot import S
from ckit import obj, rnd, rvt


def _sipd(c):
    r = c.rng
    e = c.emu
    sysobj = rnd(c, 0x2000)
    e.w32(0x70039c, sysobj)
    eng = obj(e, 'engine', 0x40, {0x114: (4, lambda e, t, a: (r.getrandbits(16), None, tuple(a[i] for i in range(4))))},
              nslots=0x118 // 4)
    e.w32(sysobj + 0x9b, eng)
    o = rnd(c, 0x700)
    e.w32(o, rvt(e, 'actor', {0x128: (3, lambda e, t, a: (0, None, (a[0], a[1], a[2])))}, nslots=0x12c // 4))
    pos = rnd(c, 0x10)
    dire = rnd(c, 0x10)
    return [o, pos, dire]


S(0x47be10, 'ZActor::SetInitialPosDir', 'thiscall', None, ret=None, gen=_sipd,
  note='u18 core residue 17; engine slot 0x114 takes six arguments, slot 0x128 one')
