"""specs_s5740.py - unclaimed-57, band batch 40: 0x5e0f80 (GUESS). Thiscall, two stack args (a, b), ret 8, returns this. The callee
0x5e0e10 runs as original code (the same family as area 10 batch 6); its operator new 0x41e290 is hooked (cdecl fake, random block or 0 one
time in five). The argument a is a random 0x800-byte block; b is random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctor2(c):
    def new(em, r):
        size = em.arg32(0)
        if c.rng.random() < 0.2:
            em.ret(eax=0, argbytes=0)
        else:
            em.ret(eax=_rnd(c, max(size, 16)), argbytes=0)
    c.emu.hook(0x41e290, new)
    return [_rnd(c, 0x800), _rnd(c, 0x800), c.rng.getrandbits(32)]


S(0x5e0f80, 'unnamed_5e0f80 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor2,
  note='unclaimed-57 band batch 40; calls 0x5e0e10 (original code; operator new hooked); vtable 0x6b7748')
