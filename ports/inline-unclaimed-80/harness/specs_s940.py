"""specs_s940.py - unclaimed-80 (docs/20-unclaimed-80.md): ZGROUP::GetAmbientSettings (0x440900). The global at 0x700390 has a logging
fake whose slot +0x20 (two arguments, callee-cleaned, ret 8) returns the object Y. Y's vtable has slot +0x2c as a logging fake with
two arguments that the CALLER cleans (ret 0, so the exe's add esp,8 is the only cleanup). ecx on that call is Y's vtable pointer,
which the fake logs. The four stack arguments are random; the function returns al = 0."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _fake(c, name, nslots, handlers):
    slots = {}
    for off, (n, cleanup, fn) in handlers.items():
        def h(e, r, off=off, n=n, cleanup=cleanup, fn=fn):
            args = [e.arg32(k) for k in range(n)]
            e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
            eax, st0 = fn(e, args)
            e.ret(eax=eax, argbytes=cleanup)
        slots[off] = h
    return c.emu.fake_vtable(name, nslots, slots)


def _gas(c):
    Y = _rnd(c, 0x40)
    c.emu.w32(Y, _fake(c, 'ZAmbY', 0x60, {0x2c: (2, 0, lambda e, a: (0, None))}))
    g = _rnd(c, 0x40)
    c.emu.w32(g, _fake(c, 'ZAmbG', 0x30, {0x20: (2, 8, lambda e, a, y=Y: (y, None))}))
    c.emu.w32(0x700390, g)
    return [_rnd(c, 0x40), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32), c.rng.getrandbits(32)]


S(0x440900, 'ZGROUP::GetAmbientSettings (unknown) thiscall const', 'thiscall', None, ret='al', gen=_gas,
  note='unclaimed-80; slot +0x20 callee-cleaned; slot +0x2c caller-cleaned with ecx = vtable of Y')
