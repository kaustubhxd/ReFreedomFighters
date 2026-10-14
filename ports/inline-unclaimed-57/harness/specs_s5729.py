"""specs_s5729.py - unclaimed-57, band batch 29: four constructor-like thiscall functions (no args, return this). The callee 0x469870
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


S(0x5d5570, 'unnamed_5d5570 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 29; calls 0x469870 (hooked, logged); vtable 0x6b557c')
S(0x5d5c90, 'unnamed_5d5c90 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 29; calls 0x469870 (hooked, logged); vtable 0x6b58c8')
S(0x5dac20, 'unnamed_5dac20 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 29; calls 0x469870 (hooked, logged); vtable 0x6b6680')
S(0x5c5a40, 'unnamed_5c5a40 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 29; calls 0x469870 (hooked, logged); vtable 0x6b431c')
