"""specs_s5743.py - unclaimed-57, band batch 43: 0x5d8c90 (GUESS). Thiscall, one stack argument (arg), ret 4. Callee 0x45d5b0 (thiscall, one arg)
is hooked and logged. The argument's slot +0x1e0 (one argument) is a logging stub returning a fixed byte chosen in gen, zero in half the
cases, so both the copy path and the early return run. The seven dwords at +0x18..+0x30 are random."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _cp(c):
    def log(em, r):
        em.calllog.append(('45d5b0', 0, em.reg('ecx'), (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)
    c.emu.hook(0x45d5b0, log)
    rv = c.rng.choice([0, 1, 0x100, 0xff])
    vt = c.emu.logging_vtable('band5d8c90_arg', 160, impl={0x1e0: lambda em, a: (rv, None)}, argwords={0x1e0: 1})
    arg = _rnd(c, 0x80)
    c.emu.w32(arg, vt)
    obj = _rnd(c, 0x200)
    return [obj, arg]


S(0x5d8c90, 'unnamed_5d8c90 (GUESS) thiscall', 'thiscall', None, ret=None, gen=_cp,
  note='unclaimed-57 band batch 43; 0x45d5b0 hooked and logged; arg slot +0x1e0 stubbed')
