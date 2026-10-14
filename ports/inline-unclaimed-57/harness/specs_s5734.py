"""specs_s5734.py - unclaimed-57, band batch 34: 0x5d8520 (constructor shape) and 0x5d8840 (three stack arguments, ret 0xc). Hooks, logged:
0x469870 (thiscall, no args, no pop) and 0x43de40 (thiscall, three arguments, callee pops 12). Their effects are not modelled."""
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


S(0x5d8520, 'unnamed_5d8520 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 34; calls 0x469870 (hooked, logged); vtable 0x6b5f30')
S(0x5d8840, 'unnamed_5d8840 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_three,
  note='unclaimed-57 band batch 34; calls 0x43de40 with three args (hooked, logged, callee pops 12); vtable 0x6b5fc8')
