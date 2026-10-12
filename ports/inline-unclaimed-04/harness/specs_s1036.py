"""specs_s1036.py - unclaimed-04 batch 36 (docs/20-unclaimed-04.md): 0x45b530 (thiscall, one flag argument, ret 4, returns this).
Stores vtable 0x684358; calls 0x43de70 (hooked by address, recording); when flag bit 0 is set and bit 2 is clear, calls 0x45c510
(cdecl, one argument = this; hooked by address, recording). The object is a zeroed 0x100-byte block."""
from pilot import S


def _setup(c):
    def base(em, r):
        em.calllog.append(('43de70', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def helper(em, r):
        em.calllog.append(('45c510', 0, 0, (em.arg32(0),)))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x43de70, base)
    c.emu.hook(0x45c510, helper)


def _args(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(0x100))
    return [o, c.rng.choice([0, 1, 2, 3, 4, 5, c.rng.getrandbits(32)])]


S(0x45b530, 'unknown::dtor_base_43de70_helper_45c510 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  setup=_setup, note='unclaimed-04 batch 36; base 0x43de70 and helper 0x45c510 hooked by address (GUESS)')
