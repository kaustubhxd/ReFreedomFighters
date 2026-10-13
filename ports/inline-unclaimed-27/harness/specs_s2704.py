"""specs_s2704.py - unclaimed-27 claim 4 (docs/20-unclaimed-27.md): ZMovementGuide::ZMovementGuide (0x4877a0, GUESS-medium
name). The object is 0x800 random bytes. The base constructor 0x4876e0 is original code in both the exe and the port (not
stubbed). The result is eax (this)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _guide(c):
    # the base constructor's sub-object setup calls the CRT malloc import (cdecl): a fresh block of the requested size
    def mh(em, rr):
        em.ret(eax=em.alloc(max(em.arg32(0), 4), 16), argbytes=0)
    c.emu.stub_import('malloc', mh)
    c.emu.stub_import('free', lambda em, rr: em.ret(eax=0, argbytes=0))
    return [_rnd(c, 0x800), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x4877a0, 'ZMovementGuide::ZMovementGuide (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_guide,
  note='unclaimed-27 claim 4; base ctor 0x4876e0 is original code')
