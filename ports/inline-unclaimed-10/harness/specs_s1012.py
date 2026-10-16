"""specs_s1012.py - unclaimed-10, batch 8: ZActionChamberItem scalar deleting destructor (0x485ed0). Thiscall, one stack
argument (the flags byte; bit 0 means delete), returns this. Operator delete (0x634273, cdecl, (ptr, size)) is hooked: it only
logs its arguments in the call log, so the delete call is compared, not its effect."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dtor(c):
    e = c.emu

    def delete(em, r):
        em.calllog.append(('delete', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    e.hook(0x634273, delete)
    return [_rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x485ed0, 'ZActionChamberItem::~ZActionChamberItem (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-10 batch 8; vtable 0x685294; delete 0x634273 hooked (logged) when bit 0 is set')
