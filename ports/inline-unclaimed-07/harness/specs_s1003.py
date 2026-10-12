"""specs_s1003.py - unclaimed-07 batch 3 (slice 6): ZFFActor::Resurrect (0x5a29a0).
The object is 0x800 random bytes with a logging vtable (slots 0x354, 0x694, 0x6cc record their arguments and ECX).
Its original callee 0x47adc0 is hooked to a logging stub, so the exe and the port see the same call."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _resurrect(c):
    e = c.emu
    o = _rnd(c, 0x800)
    impl = {0x354: lambda em, a: (0, None), 0x694: lambda em, a: (0, None), 0x6cc: lambda em, a: (0, None)}
    argw = {0x354: 2, 0x694: 1, 0x6cc: 0}
    vt = e.logging_vtable('ffactor', 0x6d0 // 4, impl=impl, argwords=argw)
    e.w32(o, vt)
    e.hook(0x47adc0, _ext_47adc0)
    return [o]


def _ext_47adc0(em, r):
    em.calllog.append(('ext47adc0', 0, em.reg('ecx'), ()))
    em.ret()


S(0x5a29a0, 'ZFFActor::Resurrect (unknown) thiscall', 'thiscall', None, ret=None, gen=_resurrect,
  note='unclaimed-07 batch 3; hooks 0x47adc0; slots 0x354, 0x694, then tail slot 0x6cc')
