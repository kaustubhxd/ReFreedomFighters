"""specs_s5730.py - unclaimed-57, band batch 30: four constructor-like thiscall functions (no args, return this). The callee 0x469870
(thiscall, no args) is hooked and logged. Each object is a random 0x200-byte block."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _ctor(c):
    def log(em, r):
        em.calllog.append(('469870', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x469870, log)
    return [_rnd(c, 0x200)]


S(0x5d38a0, 'unnamed_5d38a0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 30; calls 0x469870 (hooked, logged); vtable 0x6b5108')
S(0x5d6a40, 'unnamed_5d6a40 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 30; calls 0x469870 (hooked, logged); vtable 0x6b5ae4')
S(0x5dd5e0, 'unnamed_5dd5e0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 30; calls 0x469870 (hooked, logged); vtable 0x6b6e38')
S(0x5c7ac0, 'unnamed_5c7ac0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 30; calls 0x469870 (hooked, logged); vtable 0x6b47b0')
