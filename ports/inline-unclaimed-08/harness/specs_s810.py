"""specs_s810.py - unclaimed-08 batch 810 (docs/20-unclaimed-08.md): ZFFPRIVATESTDOBJ::Save(ZSaveGame*), thiscall, one
argument, ret 4, result in AL.

The object is 0x40 random bytes. The save game is a fake whose vtable +0x3c and +0x64 log their argument and pop it.
this+0x10 is null (50%) or a fake object with a dword at +0x18 (the base save reads it only then). The base save 0x45f960
runs the original code."""
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


def _save(c):
    obj = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(obj + 0x10, 0)
    else:
        inner = _rnd(c, 0x40)
        c.emu.w32(inner + 0x18, c.rng.getrandbits(32))
        c.emu.w32(obj + 0x10, inner)
    vt = c.emu.fake_vtable('ZSaveGame', 0x64 // 4 + 1, slots={
        0x3c: _slot('ZSaveGame write dword (stub)', 0x3c, 1, lambda e, a: (0, None)),
        0x64: _slot('ZSaveGame write (stub)', 0x64, 1, lambda e, a: (0, None))})
    sg = c.emu.fake_object('ZSaveGame', 0x40, vtable=vt)
    return [obj, sg]


S(0x5aabb0, 'ZFFPRIVATESTDOBJ::Save (unknown)', 'thiscall', None, ret='al', gen=_save,
  note='unclaimed-08 batch 10; base save 0x45f960 original; vtable +0x3c and +0x64 of the save game stubbed')
