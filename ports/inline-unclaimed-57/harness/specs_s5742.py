"""specs_s5742.py - unclaimed-57, band batch 42: 0x5d5820 (GUESS, fastcall with two stack args, ret 8). Hooks, logged:
0x5d5680 (fastcall helper; its two stack arguments are popped, eight bytes; returns a fixed value chosen in gen), 0x45c4b0 (cdecl allocator, one
argument; returns a random block of at least 54 bytes, or 0 one time in five), and 0x43de40 (thiscall, three arguments, callee pops 12).
The second stack argument is zero in half the cases (the allocator path), otherwise the helper path. Effects of the callees are not modelled."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _f(c):
    rv = c.rng.getrandbits(32)

    def h_helper(em, r):
        em.calllog.append(('5d5680', 0, em.reg('ecx'), (em.reg('edx'), em.arg32(0), em.arg32(1))))
        em.ret(eax=rv, argbytes=8)

    def h_alloc(em, r):
        size = em.arg32(0)
        em.calllog.append(('45c4b0', 0, None, (size,)))
        if c.rng.random() < 0.2:
            em.ret(eax=0, argbytes=0)
        else:
            em.ret(eax=_rnd(c, max(size, 64)), argbytes=0)

    def h_de40(em, r):
        em.calllog.append(('43de40', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    c.emu.hook(0x5d5680, h_helper)
    c.emu.hook(0x45c4b0, h_alloc)
    c.emu.hook(0x43de40, h_de40)
    b = 0 if c.rng.random() < 0.5 else c.rng.getrandbits(32)
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), b]


S(0x5d5820, 'unnamed_5d5820 (GUESS) fastcall', 'fastcall', None, ret='eax', gen=_f,
  note='unclaimed-57 band batch 42; SEH-TAG (fs:[0] frame not reproduced); callees 0x5d5680, 0x45c4b0, 0x43de40 hooked and logged')
