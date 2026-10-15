"""specs_s5703.py - unclaimed-57, batch 3: ZFFHERO::CreateMovementGuide (0x590d40). Thiscall, no arguments. Operator new (0x41e290,
cdecl, size in [esp+4]) is hooked: a random block, or 0 about one time in five (the null path). The movement-guide constructor
0x5e1040 runs as original code; it calls the movement-base constructor (verified in area 10 batch 6) and sets its fields."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _guide(c):
    e = c.emu

    def new(em, r):
        size = em.arg32(0)
        if c.rng.random() < 0.2:
            em.ret(eax=0, argbytes=0)
        else:
            em.ret(eax=_rnd(c, max(size, 16)), argbytes=0)
    e.hook(0x41e290, new)
    return [_rnd(c, 0x800)]


S(0x590d40, 'ZFFHERO::CreateMovementGuide (unknown) thiscall', 'thiscall', None, ret='eax', gen=_guide,
  note='unclaimed-57 batch 3; new 0x41e290 hooked (null one in five); guide ctor 0x5e1040 runs as original code')
