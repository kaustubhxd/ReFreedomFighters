"""specs_s5835.py - residue 9, 0x4c4e50 (ZAnimSequence::Load(ZLoadGame*), gc name map), thiscall, one stack argument, ret 4, returns al = 1. The load object has
fake slots +0x58, +0x68 (one arg each: logs the pointer as an offset from this) and +0x70 (one arg: logs the value)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d4e50(c):
    e = c.emu
    self_obj = _rnd(c, 0x100)
    load = _rnd(c, 0x40)

    def rel(p):
        return p - self_obj if self_obj <= p < self_obj + 0x100 else ('other', p)

    def h58(em, r):
        em.calllog.append(('L58', rel(em.arg32(0)), None, ()))
        em.ret(eax=0, argbytes=4)

    def h68(em, r):
        em.calllog.append(('L68', rel(em.arg32(0)), None, ()))
        em.ret(eax=0, argbytes=4)

    def h70(em, r):
        em.calllog.append(('L70', em.arg32(0), None, ()))
        em.ret(eax=0, argbytes=4)

    vt = e.fake_vtable('d4e50_load', 300, {0x58: h58, 0x68: h68, 0x70: h70})
    e.w32(load, vt)
    return [self_obj, load]


S(0x4c4e50, 'ZAnimSequence::Load (gc map) thiscall', 'thiscall', None, ret='al', gen=_d4e50,
  note='residue 9; load slots +0x58, +0x68, +0x70 fake and logged')
