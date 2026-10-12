"""specs_s947.py - unclaimed-80 gap band (docs/20-unclaimed-80.md): 0x49f670. The global at 0x70039c points to an object g; [g+0x9b]
is an object with logging vtable slot +0x138 (no arguments) returning R. R has a logging vtable whose slot +0x88 takes two arguments
(0x681320 and an out-pointer on the stack, logged as 'stk') and writes a per-case dword to the out-pointer. The 16-byte constant
at 0x67a290 comes from the exe image, so the stores are checked against the real constant."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fn(c):
    import pe_emu

    def nostk(v):
        return 'stk' if isinstance(v, int) and pe_emu.STACK_TOP - pe_emu.STACK_SIZE <= v < pe_emu.STACK_TOP else v

    v88 = c.rng.getrandbits(32)

    def impl88(e, args):
        e.w32(args[1], v88)
        return (0, None)

    def h88(e, r):
        args = [e.arg32(k) for k in range(2)]
        e.calllog.append(('ZGroupR', 0x88, e.reg('ecx'), tuple(nostk(a) for a in args)))
        eax, st0 = impl88(e, args)
        e.ret(eax=eax, argbytes=8)

    rvt = c.emu.fake_vtable('ZGroupR', 0x23, {0x88: h88})
    R = _rnd(c, 0x40)
    c.emu.w32(R, rvt)
    objvt = c.emu.logging_vtable('ZGroupObjT', 0x4f, impl={0x138: (lambda e, a, r=R: (r, None))})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, objvt)
    g = _rnd(c, 0x100)
    c.emu.w32(g + 0x9b, obj)
    c.emu.w32(0x70039c, g)
    self_o = _rnd(c, 0x900)
    return [self_o]


S(0x49f670, 'unknown init thiscall', 'thiscall', None, ret=None, gen=_fn,
  note='unclaimed-80 gap band; constant copy, eight 1.0f dwords, slot +0x138 then slot +0x88 with an out-pointer')
