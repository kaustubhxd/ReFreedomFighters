"""specs_s1011.py - unclaimed-10, batch 7: ZFFHERO::CreateMovementBaseMove (0x590cd0). Thiscall, no arguments, returns the
new block in eax (0 when operator new returns null). operator new (0x41e290) is hooked: a cdecl fake that returns a random
block (about one time in five it returns 0, so the null path is exercised). The constructor 0x5e0e10 runs as original code,
as does its member constructor 0x480980 and 0x4876e0 (see batch 6, docs/20-unclaimed-10.md)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _create(c):
    e = c.emu

    def new(em, r):
        size = em.arg32(0)
        if c.rng.random() < 0.2:
            em.ret(eax=0, argbytes=0)
        else:
            em.ret(eax=_rnd(c, max(size, 16)), argbytes=0)
    e.hook(0x41e290, new)
    return [_rnd(c, 0x800)]


S(0x590cd0, 'ZFFHERO::CreateMovementBaseMove (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_create,
  note='unclaimed-10 batch 7; new 0x41e290 hooked (null one time in five); ctor 0x5e0e10 runs as original code')
