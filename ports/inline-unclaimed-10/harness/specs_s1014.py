"""specs_s1014.py - unclaimed-10, batch 10: ZFFActorActionThrow scalar deleting destructor (0x5eaf50). Thiscall, one stack
argument (flags; bit 0 means delete), returns this. Operator delete (0x634273) is hooked to log its (ptr, size) only."""
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


S(0x5eaf50, 'ZFFActorActionThrow::~ZFFActorActionThrow (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-10 batch 10; vtable 0x685294; delete 0x634273 hooked (logged), size 0x21')
