"""specs_s5727.py - unclaimed-57, band batch 27: two constructor-like thiscall functions (no args, return this). Callee 0x469870 (thiscall,
no args) is hooked and logged (the call is recorded; its effect is not modelled). The objects are random 0x200-byte blocks."""
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


S(0x5d48e0, 'unnamed_5d48e0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 27; calls 0x469870 (hooked, logged); sets vtable 0x6b5304')
S(0x5d6c70, 'unnamed_5d6c70 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 27; calls 0x469870 (hooked, logged); sets vtable 0x6b5bc4')
