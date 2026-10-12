"""specs_s1044.py - unclaimed-04 batch 44 (docs/20-unclaimed-04.md): 0x451a30 (thiscall, one flag argument, ret 4, returns this).
Vtable 0x6813c0; free(this+0x3c, 0x7c) when non-null (0x634273, hooked); base 0x43de70 (hooked); flag bit 0 selects 0x45c510
(bit 2 clear, cdecl this) or 0x4690b0 (bit 2 set, cdecl (this, 0x44)). All hooked by address (GUESS). Object is zeroed 0x100 bytes."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _setup(c):
    def hook_cdecl(name, nargs):
        def h(em, r):
            em.calllog.append((name, 0, 0, tuple(em.arg32(i) for i in range(nargs))))
            em.ret(eax=0, argbytes=0)
        return h

    def base(em, r):
        em.calllog.append(('43de70', 0, em.reg('ecx'), ()))
        em.ret(eax=0, argbytes=0)

    c.emu.hook(0x43de70, base)
    c.emu.hook(0x634273, hook_cdecl('634273', 2))
    c.emu.hook(0x45c510, hook_cdecl('45c510', 1))
    c.emu.hook(0x4690b0, hook_cdecl('4690b0', 2))


def _args(c):
    o = c.emu.alloc(0x100, 4)
    c.emu.wbytes(o, bytes(0x100))
    if c.rng.random() < 0.5:
        c.emu.w32(o + 0x3c, c.emu.alloc(0x80, 4))
    return [o, c.rng.choice([0, 1, 2, 4, 5, 6, c.rng.getrandbits(32)])]


S(0x451a30, 'unknown::dtor_base_43de70_helpers (unknown) thiscall', 'thiscall', None, ret='eax', gen=_args,
  setup=_setup, note='unclaimed-04 batch 44; 0x43de70, 0x634273, 0x45c510, 0x4690b0 hooked by address (GUESS)')
