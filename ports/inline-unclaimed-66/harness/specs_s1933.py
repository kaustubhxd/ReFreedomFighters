"""specs_s1933.py - unclaimed-66 batch 33 (gap band, GUESS name). Stdcall(X), ret 4.

0x5003d0 (another area's helper) is hooked: it returns a fixed object P whose first dword is random. The global at 0x7003a4 is a fake
object whose vtable +0x7c (one argument, callee pops) is a logging stub. X+4 holds a holder."""
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
    vt = c.emu.fake_vtable('global obj 7003a4', 0x80 // 4 + 1, slots={
        0x7c: _slot('global obj +0x7c (stub)', 0x7c, 1, lambda e, a: (0, None))})
    obj = c.emu.fake_object('global obj 7003a4', 0x40, vtable=vt)
    c.emu.w32(0x7003a4, obj)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    return [x]


S(0x50b540, 'GUESS FUN_0050b540 (helper then global vtable +0x7c)', 'stdcall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1933; gap band; 0x5003d0 another area: HOOKED; global 0x7003a4 vtable stubbed')
