"""specs_s1920.py - unclaimed-66 batch 1920: GUESS FUN_00438e10 (thiscall, one argument, ret 4).

The object's vtable +0x10 (one argument, returns a random dword) and +0x24 (one argument, void) are logging stubs; the callees
pop their argument. The object is 0x40 random bytes with the vtable at its start."""
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
    vt = c.emu.fake_vtable('leaf438e10 obj', 0x24 // 4 + 1, slots={
        0x10: _slot('leaf438e10 obj +0x10 (stub)', 0x10, 1, lambda e, a: (c.rng.getrandbits(32), None)),
        0x24: _slot('leaf438e10 obj +0x24 (stub)', 0x24, 1, lambda e, a: (0, None))})
    obj = _rnd(c, 0x40)
    c.emu.w32(obj, vt)
    return [obj, c.rng.getrandbits(32)]


S(0x438e10, 'GUESS FUN_00438e10 (vtable +0x10 then +0x24)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1920; slice-5 (GUESS); both vtable slots stubbed')
