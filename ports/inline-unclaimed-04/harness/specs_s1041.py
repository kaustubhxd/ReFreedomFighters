"""specs_s1041.py - unclaimed-04 batch 41 (docs/20-unclaimed-04.md): 0x44c530 (thiscall, one stack argument a, ret 4).
Hooks by address (GUESS): 0x610100 (stdcall, one argument; logs it), 0x4e12e0 (thiscall, ecx = a, args (&v, 1); writes the case's
result into *(&v), logged), 0x4e1b30 (thiscall, ecx = a, no arguments; logged). The result is 0, 1, or another value per case; 0x4e1b30 runs on every path (the byte is 1 only for result 1)."""
from pilot import S


def _setup(c):
    result = c.rng.choice([0, 1, 1, 2, 0xffffffff, c.rng.getrandbits(32)])

    def h610100(em, r):
        em.calllog.append(('610100', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=4)

    def h4e12e0(em, r):
        em.calllog.append(('4e12e0', 0, em.reg('ecx'), (em.arg32(1),)))
        em.w32(em.arg32(0), result)
        em.ret(eax=0, argbytes=8)

    def h4e1b30(em, r):
        em.calllog.append(('4e1b30', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x610100, h610100)
    c.emu.hook(0x4e12e0, h4e12e0)
    c.emu.hook(0x4e1b30, h4e1b30)


def _args(c):
    o = c.emu.alloc(0x40, 4)
    c.emu.wbytes(o, bytes(c.rng.getrandbits(8) for _ in range(0x40)))
    return [o, c.rng.getrandbits(32)]


S(0x44c530, 'unknown::flag_from_4e12e0 (unknown) thiscall', 'thiscall', None, ret=None, gen=_args, setup=_setup,
  note='unclaimed-04 batch 41; 0x610100, 0x4e12e0 and 0x4e1b30 hooked by address (GUESS)')
