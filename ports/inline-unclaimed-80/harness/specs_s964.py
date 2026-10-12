"""specs_s964.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x428710 and 0x428740 (see src/batch964.cpp). The base destructor 0x435b30
(claimed in docs/20-gap-band-42-44.md) is hooked by address with a recording thiscall stub (logs ecx, no arguments). The free helper 0x634273 is
hooked with a recording cdecl stub (logs its two arguments, the caller pops). The argument is random, so both free paths run."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    def h_dtor(em, r):
        c.emu.calllog.append(('dtor', 0x435b30, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def h_free(em, r):
        c.emu.calllog.append(('free', 0x634273, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x435b30, h_dtor)
    c.emu.hook(0x634273, h_free)


def _gen(c):
    _hooks(c)
    return [_rnd(c, 0x200), c.rng.getrandbits(32)]


S(0x428710, 'destructor wrapper with sized free (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-80 gap band; base dtor 0x435b30 hooked (claimed elsewhere); free 0x634273 hooked; size 0x1b2')
S(0x428740, 'destructor wrapper with sized free (unknown) thiscall', 'thiscall', None, ret='eax', gen=_gen,
  note='unclaimed-80 gap band; base dtor 0x435b30 hooked (claimed elsewhere); free 0x634273 hooked; size 0x46')
