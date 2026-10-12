"""specs_s1007.py - unclaimed-07 batch 7 (slice 6): CImpactResponse::Load (0x5dc420).
The load object is a fake vtable. Slots +0x70, +0x74, +0x6c and +0x18 are logging stubs (they record their arguments
and pop them). Slot +0x40 is the count reader: it writes a count through the pointer argument (the PC argument slot,
a stack address, so it is not logged). The allocator 0x41e290 (operator new) is hooked to a fresh buffer of the
requested size, as in the inline-ai specs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _logged(off, nargs):
    def h(em, r):
        args = tuple(em.arg32(k) for k in range(nargs))
        em.calllog.append(('zloadgame', off, em.reg('ecx'), args))
        em.ret(eax=0, argbytes=4 * nargs)
    return h


def _impact(c):
    e = c.emu
    o = _rnd(c, 0x200)
    cnt = c.rng.randint(0, 40)

    def w40(em, r):
        em.w32(em.arg32(0), cnt)
        em.ret(eax=0, argbytes=4)

    pattern = bytes(c.rng.getrandbits(8) for _ in range(0x100))   # the fresh buffer is not zero, so every byte is compared

    def new(em, r):
        size = em.arg32(0)
        em.calllog.append(('new', 0, None, (size,)))
        p = em.alloc(size + 16, 4)
        em.wbytes(p, pattern[:size + 16])
        em.ret(eax=p)

    e.hook(0x41e290, new)
    load = _rnd(c, 0x100)
    slots = {0x70: _logged(0x70, 1), 0x74: _logged(0x74, 1), 0x6c: _logged(0x6c, 1), 0x18: _logged(0x18, 2),
             0x40: w40}
    e.w32(load, e.fake_vtable('zloadgame', 0x80 // 4, slots))
    return [o, load]


S(0x5dc420, 'CImpactResponse::Load (unknown) thiscall', 'thiscall', None, ret='al', gen=_impact,
  note='unclaimed-07 batch 7 (returns bool in al, eax not compared); load slots +0x70, +0x74, +0x6c, +0x40 (count out), +0x18(buf, count)')
