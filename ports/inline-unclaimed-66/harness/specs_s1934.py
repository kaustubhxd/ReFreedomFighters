"""specs_s1934.py - unclaimed-66 batch 34 (gap band, GUESS names). Thiscall(X), ret 4.

0x5003d0 (another area's helper) is hooked: it returns a fixed object P whose first dword is random. The sub-objects at this+0x18 and
this+0x20 have vtables whose +0x68c / +0x394 slots (one argument) are logging stubs. X+4 holds a holder."""
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


def _gap(c):
    P = _rnd(c, 0x40)

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    sub18 = c.emu.fake_object('sub18', 0x40, vtable=c.emu.fake_vtable('sub18', 0x690 // 4 + 1, slots={
        0x68c: _slot('sub18 +0x68c (stub)', 0x68c, 1, lambda e, a: (0, None))}))
    sub20 = c.emu.fake_object('sub20', 0x40, vtable=c.emu.fake_vtable('sub20', 0x398 // 4 + 1, slots={
        0x394: _slot('sub20 +0x394 (stub)', 0x394, 1, lambda e, a: (0, None))}))
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x18, sub18)
    c.emu.w32(self + 0x20, sub20)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    return [self, x]


S(0x5072c0, 'GUESS FUN_005072c0 (helper value to vtable +0x68c)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1934; gap band; 0x5003d0 another area: HOOKED')
S(0x51fd40, 'GUESS FUN_0051fd40 (helper value to vtable +0x394)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1934; gap band; 0x5003d0 another area: HOOKED')
