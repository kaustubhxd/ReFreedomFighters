"""specs_s7171.py - area 73 batch 71 (gap band, tail-jump rows; arity = 0x43ea20's ret 0x14 / 4 = 5, target hooked by address).
FUN_4f6b80: vtable word 0x69aaf0; if the object at +0x93 is non-null its vtable +0x210(1) is called; +0x93 = 0; tail-jump to 0x43ea20.
FUN_4f7a00: vtable word 0x69ae94; 0x4ccfe0 on this+0xb3 (no arguments, hooked); tail-jump to 0x43ea20."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook(c):
    e = c.emu

    def h_ea20(em, r):
        em.calllog.append(('43ea20', 0, em.reg('ecx'), tuple(em.arg32(k) for k in range(5))))
        em.ret(argbytes=0x14)

    def h_cc(em, r):
        em.calllog.append(('4ccfe0', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)
    e.hook(0x43ea20, h_ea20)
    e.hook(0x4ccfe0, h_cc)


def _gen_6b80(c):
    e = c.emu
    _hook(c)
    o = _rnd(c, 0x100)
    if c.rng.random() < 0.6:
        obj = _rnd(c, 0x40)
        e.w32(obj, e.logging_vtable('o6b80', 0x240 // 4, impl={0x210: lambda em, a: (0, None)}, argwords={0x210: 1}))
        e.w32(o + 0x93, obj)
    else:
        e.w32(o + 0x93, 0)
    return [o] + [c.rng.getrandbits(32) for _ in range(5)]


def _gen_7a00(c):
    _hook(c)
    return [_rnd(c, 0x100)] + [c.rng.getrandbits(32) for _ in range(5)]


S(0x4f6b80, 'GUESS FUN_4f6b80 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_6b80,
  note='area 73 batch 71; vt=0x69aaf0; [+0x93] obj vt+0x210(1); [+0x93]=0; jmp 0x43ea20 (ret 0x14, hooked)')
S(0x4f7a00, 'GUESS FUN_4f7a00 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_7a00,
  note='area 73 batch 71; vt=0x69ae94; 0x4ccfe0(this+0xb3) (hooked); jmp 0x43ea20 (ret 0x14, hooked)')
