"""specs_s955.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x435c60. The object is 0x200 random bytes. The free helper 0x634273 is
hooked by address with a recording cdecl stub (returns 0; the caller pops). The global at 0x7003a0 is random before the call (it must
be zeroed)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    c.emu.w32(0x7003a0, c.rng.getrandbits(32))

    def h_free(em, r):
        em.calllog.append(('free', 0x634273, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)     # cdecl: the caller pops the two arguments

    c.emu.hook(0x634273, h_free)
    self_o = _rnd(c, 0x200)
    return [self_o, c.rng.getrandbits(32)]


S(0x435c60, 'constructor with optional sized free (unknown) thiscall', 'thiscall', None, ret='eax', gen=_fn,
  note='unclaimed-80 gap band; vtable 0x67a5d8, global 0x7003a0 cleared, free 0x634273 hooked (cdecl, recorded)')
