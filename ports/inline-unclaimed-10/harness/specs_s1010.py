"""specs_s1010.py - unclaimed-10, batch 6: ZFFHeroMovementBaseMove ctor (0x5e0e10). Thiscall, two stack arguments (ret 8),
returns this in eax. The callees run as ORIGINAL code: the base ctor (0x4876e0) and the member ctors (0x480980), which
call operator new (0x41e290) and the pure ctor 0x4ccbe0. operator new is hooked: a cdecl fake returning a random block of
the requested size (argument in [esp+4]), as in the other specs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hero_ctor(c):
    e = c.emu
    e.hook(0x41e290, lambda em, r: em.ret(eax=_rnd(c, max(em.arg32(0), 16)), argbytes=0))
    o = _rnd(c, 0x800)
    return [o, _rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x5e0e10, 'ZFFHeroMovementBaseMove::ZFFHeroMovementBaseMove (GUESS) thiscall', 'thiscall', None, ret='eax',
  gen=_hero_ctor, note='unclaimed-10 batch 6; base 0x4876e0 and members 0x480980 run as original code; new hooked')
