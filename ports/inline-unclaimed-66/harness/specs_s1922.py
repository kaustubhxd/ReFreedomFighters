"""specs_s1922.py - unclaimed-66 batch 1922: GUESS FUN_00656d50 (thiscall, two arguments, ret 8).

Vtable +0xc (one argument, returns a random dword) and +0xa4 (two arguments, void) are logging stubs; the callees pop their arguments.
The object is 0x40 random bytes with the vtable at its start."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _obj(c):
    vt = c.emu.fake_vtable('leaf656d50 obj', 0xa4 // 4 + 1, slots={
        0xc: _slot('leaf656d50 obj +0xc (stub)', 0xc, 1, lambda e, a: (c.rng.getrandbits(32), None)),
        0xa4: _slot('leaf656d50 obj +0xa4 (stub)', 0xa4, 2, lambda e, a: (0, None))})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    return [obj, c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x656d50, 'GUESS FUN_00656d50 (vtable +0xc then +0xa4)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1922; slice-5 (GUESS); both vtable slots stubbed')
