"""specs_s5736.py - unclaimed-57, band batch 36: 0x5c4530 (constructor shape) and 0x5d5730 (three stack arguments, ret 0xc). Hooks, logged:
0x469870 (no args) and 0x43de40 (thiscall, three arguments; the hook pops 12, as the callee would). Effects not modelled."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    def log0(em, r):
        em.calllog.append(('469870', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def log3(em, r):
        em.calllog.append(('43de40', 0, em.reg('ecx'), (em.arg32(0), em.arg32(1), em.arg32(2))))
        em.ret(eax=0, argbytes=12)
    c.emu.hook(0x469870, log0)
    c.emu.hook(0x43de40, log3)


def _ctor(c):
    _hooks(c)
    return [_rnd(c, 0x200)]


def _three(c):
    _hooks(c)
    return [_rnd(c, 0x200), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x5c4530, 'unnamed_5c4530 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 36; calls 0x469870 (hooked, logged); vtable 0x6b4088')
S(0x5d5730, 'unnamed_5d5730 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_three,
  note='unclaimed-57 band batch 36; calls 0x43de40 with three args (hooked, logged); vtable 0x6b5610')
