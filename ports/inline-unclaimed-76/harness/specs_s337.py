"""specs_s337.py - gap band, batch 337: 0x61cd30 (cdecl, four arguments). The exe callee 0x61d090 is hooked by address: it records its six
arguments and returns a per-run value."""
from pilot import S


def _gen(c):
    e = c.emu
    rng = c.rng
    rv = rng.getrandbits(32)

    def rec(em, r):
        a = [em.arg32(k) for k in range(6)]
        em.calllog.append(('h61d090', 0, None, tuple(a)))
        em.ret(eax=rv, argbytes=0)

    e.hook(0x61d090, rec)
    obj = e.alloc(0x100, 4)
    e.wbytes(obj, rng.randbytes(0x100))
    return [obj, rng.getrandbits(32), rng.getrandbits(32), rng.getrandbits(32)]


S(0x61cd30, 'wrap61cd30 (GUESS)', 'cdecl', None, ret='eax', gen=_gen, note='batch337; plain ret; callee 0x61d090 hooked')
