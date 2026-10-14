"""specs_s5750.py - unclaimed-57, band batch 50 (GUESS): 0x5d82a0. Thiscall, one stack arg (a1), ret 4 (no return value). Hook: 0x634d2e (cdecl,
five args, logged: (a1, 0, 0x6f6df8, 0x6fac3c, 0)); it returns the address of a random source record (its +0x4e..+0xc0 bytes are random). Both the
object and the source are random 0x200-byte heap blocks; the two addresses differ, so the copies all run, and the pointer-equality tests take the
copy branch (they are portable heap addresses, so the equal case is not reached by the spec)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cp(c):
    src = _rnd(c, 0x200)

    def h(em, r):
        em.calllog.append(('634d2e', 0, None, (em.arg32(0), em.arg32(1), em.arg32(2), em.arg32(3), em.arg32(4))))
        em.ret(eax=src, argbytes=0)
    c.emu.hook(0x634d2e, h)
    obj = _rnd(c, 0x200)
    return [obj, c.rng.getrandbits(32)]


S(0x5d82a0, 'unnamed_5d82a0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_cp,
  note='unclaimed-57 band batch 50; 0x634d2e hooked (logged, returns a source record)')
