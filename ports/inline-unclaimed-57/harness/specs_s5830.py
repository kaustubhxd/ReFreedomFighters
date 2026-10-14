"""specs_s5829.py - residue 9, 0x485ed0 (ZFFActorActionThrow::~ZFFActorActionThrow(), gc name map), thiscall, one stack argument (flags), ret 4, returns this.
The delete helper 0x634273 (cdecl, two args) is a logging stub that writes nothing; the argument's bit 0 is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _d5ed0(c):
    e = c.emu
    self_obj = _rnd(c, 0x100)

    def hdel(em, r):
        p = em.arg32(0)
        em.calllog.append(('del', 'self' if p == self_obj else 'other', em.arg32(1), ()))
        em.ret(eax=0, argbytes=0)

    e.hook(0x634273, hdel)
    return [self_obj, c.rng.getrandbits(32)]


S(0x5eaf50, 'ZFFActorActionThrow::~ZFFActorActionThrow (gc map) thiscall', 'thiscall', None, ret=None, gen=_d5ed0,
  note='residue 9; delete helper 0x634273 hooked (logs the pointer identity and size)')
