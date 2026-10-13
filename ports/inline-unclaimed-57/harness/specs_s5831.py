"""specs_s5831.py - residue 9, 0x51e810 (ZHeliIf::~ZHeliIf(), gc name map), thiscall, one stack argument (flags), ret 4, returns this. The base destructor 0x519430
(thiscall, no stack args: it tail-jumps to 0x500a10, which ends in a plain ret) and the delete helper 0x634273 (cdecl, two args) are logging stubs that
write nothing and pop nothing. The flags argument's bit 0 is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d1e810(c):
    e = c.emu
    self_obj = _rnd(c, 0x100)

    def hbase(em, r):
        em.calllog.append(('base', 'self' if em.reg('ecx') == self_obj else 'other', None, ()))
        em.ret(eax=0, argbytes=0)

    def hdel(em, r):
        p = em.arg32(0)
        em.calllog.append(('del', 'self' if p == self_obj else 'other', em.arg32(1), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x519430, hbase)
    e.hook(0x634273, hdel)
    return [self_obj, c.rng.getrandbits(32)]


S(0x51e810, 'ZHeliIf::~ZHeliIf (gc map) thiscall', 'thiscall', None, ret='eax', gen=_d1e810,
  note='residue 9; base dtor 0x519430 and delete 0x634273 hooked')
