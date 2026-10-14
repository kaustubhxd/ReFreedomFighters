"""specs_s5751.py - unclaimed-57, band batch 51 (GUESS): 0x5d5790. Thiscall, no args. The sub-object at +0x19 is set in half the cases; its slot +0
(one argument) is a logging stub. operator delete 0x634273 (cdecl, (ptr, size)) is hooked and logged (its effect is not modelled). The base
destructor 0x43de70 is hooked and logged (its own chain dereferences this+8 and runs engine code that is not modelled here)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dt(c):
    def log(em, r):
        em.calllog.append(('delete', 0, None, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, log)
    def base(em, r):
        em.calllog.append(('43de70', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x43de70, base)
    vt = c.emu.logging_vtable('band5d5790_sub', 16, argwords={0: 1})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x19, sub if c.rng.random() < 0.5 else 0)
    c.emu.w32(obj + 0x29, c.rng.getrandbits(32))
    return [obj]


S(0x5d5790, 'unnamed_5d5790 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_dt,
  note='unclaimed-57 band batch 51; sub slot 0 stubbed; delete 0x634273 logged; base dtor 0x43de70 hooked and logged')
