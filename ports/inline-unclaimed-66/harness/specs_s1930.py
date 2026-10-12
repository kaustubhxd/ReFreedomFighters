"""specs_s1930.py - unclaimed-66 batch 30 (gap band, GUESS name). Thiscall with one stack argument X (ret 4). The helpers 0x5003d0 and
0x5002f0 are other areas': hooked by address as recording stubs. The sub-object at this+0x18 has a vtable whose +0x684 slot returns a
random dword (logged). X+8 holds a holder pointer."""
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


def _f(c):
    P = _rnd(c, 0x40)

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    def h5002(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    c.emu.hook(0x5002f0, h5002)
    sub_vt = c.emu.fake_vtable('f sub', 0x688 // 4 + 1, slots={
        0x684: _slot('f sub +0x684 (stub)', 0x684, 0, lambda e, a: (c.rng.getrandbits(32), None))})
    sub = c.emu.fake_object('f sub', 0x40, vtable=sub_vt)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x18, sub)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 8, _rnd(c, 0x20))
    return [self, x]


S(0x506bb0, 'GUESS FUN_00506bb0 (vtable +0x684, helpers stubbed)', 'thiscall', None, ret=None, gen=_f,
  note='unclaimed-66 batch 1930; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED')
