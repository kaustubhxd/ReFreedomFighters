"""specs_s1029.py - unclaimed-04 batch 29 (docs/20-unclaimed-04.md): 0x4265b0 (deleting destructor, thiscall, one flag
argument, ret 4). The base destructor 0x4264b0 is hooked by address with a recording stub (GUESS on its body; not verified
here), and the CRT free 0x634273 is hooked with a recording stub. The object is a zeroed 0x200-byte block, and the flag's bit 0
is random. The port calls the same addresses, so both runs see the same stubs."""
from pilot import S


def _setup(c):
    def base(em, r):
        em.calllog.append(('4264b0', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    def free34(em, r):
        em.calllog.append(('634273', 0, 0, (em.arg32(0), em.arg32(1))))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x4264b0, base)
    c.emu.hook(0x634273, free34)


def _args(c):
    o = c.emu.alloc(0x200, 4)
    c.emu.wbytes(o, bytes(0x200))
    return [o, c.rng.choice([0, 1, 2, 3, c.rng.getrandbits(32)])]


S(0x4265b0, 'unknown::dtor_base_4264b0_free_118 (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  setup=_setup, note='unclaimed-04 batch 29; base 0x4264b0 hooked (GUESS, not verified); free 0x118 hooked (GUESS)')
