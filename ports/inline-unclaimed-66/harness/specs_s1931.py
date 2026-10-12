"""specs_s1931.py - unclaimed-66 batch 31 (gap band, GUESS names).

0x508260 is thiscall(X) and 0x50b510 is stdcall(X) (both ret 4). The helpers 0x5003d0 (returns a fixed object P whose first dword is
random; one argument, ret 4) and 0x5002f0 (thiscall, one argument, ret 4) are other areas': hooked by address as recording stubs.
The sub-object at this+0x18 has a vtable whose +0x608 slot (one argument) is a logging stub. X+4 and X+8 hold holder pointers."""
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


def _hooks(c):
    P = _rnd(c, 0x40)
    c.emu.w32(P, c.rng.choice([0, 1, c.rng.getrandbits(32)]))

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    def h5002(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    c.emu.hook(0x5002f0, h5002)


def _x(c):
    _hooks(c)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    c.emu.w32(x + 8, _rnd(c, 0x20))
    return [x]


def _gap508260(c):
    _hooks(c)
    sub_vt = c.emu.fake_vtable('h sub', 0x610 // 4 + 1, slots={
        0x608: _slot('h sub +0x608 (stub)', 0x608, 1, lambda e, a: (0, None))})
    sub = c.emu.fake_object('h sub', 0x40, vtable=sub_vt)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x18, sub)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, _rnd(c, 0x20))
    return [self, x]


S(0x508260, 'GUESS FUN_00508260 (bool to vtable +0x608)', 'thiscall', None, ret=None, gen=_gap508260,
  note='unclaimed-66 batch 1931; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED')
S(0x50b510, 'GUESS FUN_0050b510 (two helper calls, stdcall)', 'stdcall', None, ret=None, gen=_x,
  note='unclaimed-66 batch 1931; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED')
