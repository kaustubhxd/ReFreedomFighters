"""specs_s8585.py - residue 6 batch 85 (GUESS names).
FUN_0054be20 (thiscall, plain ret): s = [this+0x63ec]; when non-null, vtable +0x48 on s with s as its one argument.
FUN_005f51a0 (stdcall, three arguments ignored, ret 0xc, returns 0): the assert hook at 0x7003b0 is called with no arguments.
The hook is always non-null (a null hook is an int3 in the original, which would count as a faulting case)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen_be20(c):
    e = c.emu
    o = _rnd(c, 0x7000)
    if c.rng.random() < 0.7:
        sub = _rnd(c, 0x40)
        e.w32(sub, e.logging_vtable('sub54be20', 0x80 // 4, impl={0x48: lambda em, a: (0, None)}, argwords={0x48: 1}))
        e.w32(o + 0x63ec, sub)
    else:
        e.w32(o + 0x63ec, 0)
    return [o]


def _gen_51a0(c):
    e = c.emu

    def hassert(em, r):
        em.calllog.append(('assert5f51a0', 0, None, ()))
        em.ret(eax=0, argbytes=0)
    e.w32(0x7003b0, e.stub_fn('assert5f51a0', hassert))
    return [c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x54be20, 'GUESS FUN_0054be20 (unknown) thiscall', 'thiscall', None, ret=None, gen=_gen_be20,
  note='residue 6 batch 85; s = [this+0x63ec]; if s: vt(s)+0x48(s)')
S(0x5f51a0, 'GUESS FUN_005f51a0 (unknown) stdcall', 'stdcall', None, ret='eax', gen=_gen_51a0,
  note='residue 6 batch 85; assert hook 0x7003b0 called (non-null); returns 0; ret 0xc')
