"""specs_s1021.py - unclaimed-07 batch 21 (slice 6): ZBaseGeom::IsMovingObject (0x4db9e0) and ZStdObjBox::CalcCenSize
(0x45b060). IsMovingObject walks this+0x54 -> +0x10 -> a byte at +0x18 (each link null about 20% of the time). CalcCenSize
calls the two helpers 0x43df70 and 0x4db7c0 (hooked, logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _moving(c):
    e = c.emu
    o = _rnd(c, 0x100)
    if c.rng.random() < 0.8:
        p = _rnd(c, 0x40)
        if c.rng.random() < 0.8:
            q = _rnd(c, 0x40)
            e.w32(p + 0x10, q)
        else:
            e.w32(p + 0x10, 0)
        e.w32(o + 0x54, p)
    else:
        e.w32(o + 0x54, 0)
    return [o]


def _calc(c):
    e = c.emu
    o = _rnd(c, 0x100)
    obj8 = _rnd(c, 0x40)
    e.w32(o + 8, obj8)

    def h43df70(em, r):
        em.calllog.append(('43df70', 0, em.reg('ecx'), ()))
        em.ret()

    def h4db7c0(em, r):
        em.calllog.append(('4db7c0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(argbytes=4)

    e.hook(0x43df70, h43df70)
    e.hook(0x4db7c0, h4db7c0)
    return [o]


S(0x4db9e0, 'ZBaseGeom::IsMovingObject (unknown) thiscall const', 'thiscall', None, ret='al', gen=_moving,
  note='unclaimed-07 batch 21; this+0x54 -> +0x10 -> byte +0x18 bit 2; bool compared in al')
S(0x45b060, 'ZStdObjBox::CalcCenSize (unknown) thiscall', 'thiscall', None, ret=None, gen=_calc,
  note='unclaimed-07 batch 21; 0x43df70(this); 0x4db7c0(this+8, this+0x18)')
