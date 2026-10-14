"""specs_s5728.py - unclaimed-57, band batch 28: 0x5c5260 (constructor-like, returns this) and 0x5e0df0 (conditional call with a float
argument). Callees 0x469870 (no args) and 0x5a83e0 (thiscall, one float argument) are hooked and logged (their effects are not modelled).
The float is taken from the exe's bit patterns in gen (ordinary values, zero, negative zero, NaN); the sub-object pointer is zero in half
the cases."""
from pilot import S, F


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hooks(c):
    def log0(em, r):
        em.calllog.append(('469870', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def log1(em, r):
        em.calllog.append(('5a83e0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x469870, log0)
    c.emu.hook(0x5a83e0, log1)


def _ctor(c):
    _hooks(c)
    return [_rnd(c, 0x200)]


def _cond(c):
    _hooks(c)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x1d0f, 0 if c.rng.random() < 0.5 else _rnd(c, 0x40))
    v = c.rng.choice([0.0, -0.0, 0.5, -3.25, float('nan')])
    c.emu.w32(obj + 0x1d17, c.rng.choice([0x3f800000, 0xbf800000, 0x7fc00000, c.rng.getrandbits(32)]))
    return [obj]


S(0x5c5260, 'unnamed_5c5260 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_ctor,
  note='unclaimed-57 band batch 28; calls 0x469870 (hooked, logged); sets vtable 0x6b4180')
S(0x5e0df0, 'unnamed_5e0df0 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_cond,
  note='unclaimed-57 band batch 28; calls 0x5a83e0 with the float at +0x1d17 when +0x1d0f is set (hooked, logged)')
