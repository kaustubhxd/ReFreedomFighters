"""specs_s1015.py - unclaimed-10, batch 11: ZHeliIf scalar deleting destructor (0x51e810). Thiscall, one stack argument (flags;
bit 0 means delete), returns this. The base destructor chain (0x519430 -> 0x500a10) and operator delete (0x634273) run as
original code; delete is hooked to log (ptr, size) only."""
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


S(0x51e810, 'ZHeliIf::~ZHeliIf (unknown) thiscall', 'thiscall', None, ret='eax', gen=_dtor,
  note='unclaimed-10 batch 11; vtable 0x69fa64; base dtor 0x519430 original; delete size 0x1c hooked (logged)')
