"""specs_s974.py - unclaimed-80 residue-19 batch 52 (docs/20-unclaimed-80.md), see src/batch974.cpp.
0x659b30: the argument has a pointer at +0x14 (null 40%) to a logging object whose slot 0 (one argument, callee-cleaned) returns 0; the
global 0x812434 is random before the call (it must be overwritten). 0x4f4bf0: callee 0x4f9c60 (claimed in docs/20-unclaimed-18.md) is hooked by
address with a recording thiscall stub (one argument, returns 0)."""
import serial_stubs as ss  # noqa: F401
from pilot import S


def _rnd(c, n):
    a = c.emu.alloc(n, 4)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen659(c):
    c.emu.w32(0x812434, c.rng.getrandbits(32))
    a = _rnd(c, 0x40)
    if c.rng.random() < 0.4:
        c.emu.w32(a + 0x14, 0)
    else:
        o = _rnd(c, 0x40)
        c.emu.w32(o, c.emu.logging_vtable('ZDtorObj', 0x1, argwords={0: 1}))
        c.emu.w32(a + 0x14, o)
    return [a]


def _gen4f4(c):
    def h(em, r):
        c.emu.calllog.append(('4f9c60', None, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    c.emu.hook(0x4f9c60, h)
    self_o = _rnd(c, 0x100)
    a = _rnd(c, 0x100)
    return [self_o, a]


S(0x659b30, 'release-and-clear (unknown) stdcall', 'stdcall', None, ret=None, gen=_gen659,
  note='unclaimed-80 residue-19; global 0x812434 written; object slot 0 called with 1; field cleared')
S(0x4f4bf0, 'wrapper with copy after 0x4f9c60 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen4f4,
  note='unclaimed-80 residue-19; callee 0x4f9c60 hooked by address (claimed elsewhere); copies two dwords')
