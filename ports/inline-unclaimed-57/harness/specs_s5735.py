"""specs_s5735.py - unclaimed-57, band batch 35: 0x5dd020 (constructor shape, returns this) and 0x5d5940 (counter-gated call). Hooks: 0x469870
(no args, logged); 0x5f09b0 (thiscall, no args, logged). Stub: the object's slot +0x114 (one argument, logged). The counter at +0x2d is 0, 1,
2 or random, and the flag at +0x31 is 0 or 1, so every branch runs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    def log0(em, r):
        em.calllog.append(('469870', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def log5(em, r):
        em.calllog.append(('5f09b0', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x469870, log0)
    c.emu.hook(0x5f09b0, log5)


def _ctor(c):
    _hooks(c)
    return [_rnd(c, 0x200)]


def _gated(c):
    _hooks(c)
    vt = c.emu.logging_vtable('band5d5940', 72, argwords={0x114: 1})
    obj = _rnd(c, 0x200)
    c.emu.w32(obj, vt)
    c.emu.wbytes(obj + 0x31, bytes([c.rng.choice([0, 1])]))
    c.emu.w32(obj + 0x2d, c.rng.choice([0, 1, 2, c.rng.getrandbits(32)]))
    c.emu.w32(obj + 0x19, c.rng.getrandbits(32))
    return [obj]


S(0x5dd020, 'unnamed_5dd020 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 35; calls 0x469870 (hooked, logged); vtable 0x6b6cec')
S(0x5d5940, 'unnamed_5d5940 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_gated,
  note='unclaimed-57 band batch 35; 0x5f09b0 hooked (logged); this slot +0x114 stubbed (logged)')
