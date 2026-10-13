"""specs_s7171.py - area 73 batch 71 (redo, zero arguments). The only call sites are 0x4ee00a (for 0x4f6b80) and 0x4ee026 (for
0x4f7a00); neither has pushes before the call, so both take no arguments. The chain through 0x43ea20 ends in a plain ret
(0x43ea20 -> jmp 0x45c3e0 -> ret), so 0x43ea20 is hooked with no arguments and no popped bytes.
FUN_4f6b80: vtable word 0x69aaf0; a non-null object at +0x93 gets vtable +0x210(1); +0x93 = 0; then 0x43ea20(this).
FUN_4f7a00: vtable word 0x69ae94; 0x4ccfe0(this+0xb3) (hooked, no arguments); then 0x43ea20(this)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _hook(c):
    e = c.emu

    def h_ea20(em, r):
        em.calllog.append(('43ea20', 0, em.reg('ecx'), ()))
        em.ret(argbytes=0)

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
    return [o]


def _gen_7a00(c):
    _hook(c)
    return [_rnd(c, 0x100)]


S(0x4f6b80, 'GUESS FUN_4f6b80 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_6b80,
  note='area 73 batch 71 (redo, 0 args from the call site); vt=0x69aaf0; [+0x93] obj vt+0x210(1); [+0x93]=0; 0x43ea20(this)')
S(0x4f7a00, 'GUESS FUN_4f7a00 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_7a00,
  note='area 73 batch 71 (redo, 0 args from the call site); vt=0x69ae94; 0x4ccfe0(this+0xb3); 0x43ea20(this)')
