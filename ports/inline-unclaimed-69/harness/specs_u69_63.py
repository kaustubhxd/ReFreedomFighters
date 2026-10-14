"""specs_u69_63.py - area 69, group 63 (slice 8): 0x5ec340, CSprite3D::SetColor (no callees). The list at self+0x3a holds the base pointer at +4;
the entries are 40 bytes; the count is at self+0x3e (0..8). idx is -1 half the time, otherwise 0..7."""
from pilot import S
from ckit import rnd


def _sc(c):
    e = c.emu
    r = c.rng
    o = rnd(c, 0x60)
    lst = rnd(c, 0x10)
    base = rnd(c, 40 * 10 + 0x40)
    e.w32(lst + 4, base)
    e.w32(o + 0x3a, lst)
    e.w32(o + 0x3e, r.randrange(0, 9))
    idx = 0xffffffff if r.random() < 0.5 else r.randrange(0, 8)
    return [o, r.getrandbits(32), idx]


S(0x5ec340, 'setColor5ec340 (CSprite3D::SetColor, thiscall, two args, ret 8)', 'thiscall', None, ret=None, gen=_sc, note='u69 group 63; no callees')
