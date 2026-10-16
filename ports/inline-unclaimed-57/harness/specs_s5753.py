"""specs_s5753.py - unclaimed-57, band batch 53 (GUESS): 0x5d57c0, the deleting form of 0x5d5790. Thiscall, one stack arg (flags), returns this.
The flags are random (so bit 0 and bit 2 both vary). Hooked and logged: 0x634273 (cdecl, (ptr, size)), 0x43de70 (base dtor, thiscall, no args),
0x4690b0 (cdecl sized free, (ptr, size)), 0x45c510 (cdecl, one arg). The sub-object's slot 0 (one argument) is a logging stub."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _dt(c):
    def log2(name):
        def h(em, r):
            em.calllog.append((name, 0, None, (em.arg32(0), em.arg32(1))))
            em.ret(eax=0, argbytes=0)
        return h

    def log1(em, r):
        em.calllog.append(('45c510', 0, None, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    def base(em, r):
        em.calllog.append(('43de70', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, log2('delete'))
    c.emu.hook(0x4690b0, log2('sized'))
    c.emu.hook(0x45c510, log1)
    c.emu.hook(0x43de70, base)
    vt = c.emu.logging_vtable('band5d57c0_sub', 16, argwords={0: 1})
    sub = _rnd(c, 0x40)
    c.emu.w32(sub, vt)
    obj = _rnd(c, 0x200)
    c.emu.w32(obj + 0x19, sub if c.rng.random() < 0.5 else 0)
    c.emu.w32(obj + 0x29, c.rng.getrandbits(32))
    return [obj, c.rng.getrandbits(32)]


S(0x5d57c0, 'unnamed_5d57c0 (GUESS) thiscall', 'thiscall', None, ret='eax', gen=_dt,
  note='unclaimed-57 band batch 53; deleting form of 0x5d5790; four callees hooked and logged; sub slot 0 stubbed')
