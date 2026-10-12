"""specs_s1935.py - unclaimed-66 batch 35 (gap band, GUESS name). Thiscall(X), ret 4.

0x5003d0 (another area's helper) is hooked: it returns a fixed object P whose first dword is a random float's bits. The sub-object at
this+0x18 has a vtable whose +0x658 slot (one argument) is a logging stub. X+4 holds a holder."""
import struct
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
    c.emu.wbytes(P, struct.pack('<f', c.rng.uniform(-50.0, 50.0)))

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    sub = c.emu.fake_object('sub658', 0x40, vtable=c.emu.fake_vtable('sub658', 0x660 // 4 + 1, slots={
        0x658: _slot('sub658 +0x658 (stub)', 0x658, 1, lambda e, a: (0, None))}))
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x18, sub)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    return [self, x]


S(0x5081c0, 'GUESS FUN_005081c0 (helper float to vtable +0x658)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1935; gap band; 0x5003d0 another area: HOOKED')
