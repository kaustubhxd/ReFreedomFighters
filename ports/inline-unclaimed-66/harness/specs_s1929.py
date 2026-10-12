"""specs_s1929.py - unclaimed-66 batch 29 (gap band, GUESS names). Thiscall with one stack argument X (ret 4). The helpers 0x5003d0
and 0x5002f0 are other areas': hooked by address as recording stubs (0x5003d0 returns a fixed object; 0x5002f0 logs its argument).
The sub-object at this+0x14 has a vtable whose +0x350, +0x35c and +0x2d8 slots return random dwords (logged)."""
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


def _shape(c):
    P = _rnd(c, 0x40)

    def h5003(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=P, argbytes=4)

    def h5002(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    c.emu.hook(0x5002f0, h5002)
    sub_vt = c.emu.fake_vtable('shape sub', 0x360 // 4 + 1, slots={
        0x350: _slot('shape sub +0x350 (stub)', 0x350, 0, lambda e, a: (c.rng.getrandbits(32), None)),
        0x35c: _slot('shape sub +0x35c (stub)', 0x35c, 0, lambda e, a: (c.rng.getrandbits(32), None)),
        0x2d8: _slot('shape sub +0x2d8 (stub)', 0x2d8, 0, lambda e, a: (c.rng.getrandbits(32), None))})
    sub = c.emu.fake_object('shape sub', 0x40, vtable=sub_vt)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x14, sub)
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x20)
    c.emu.w32(x + 8, holder)
    return [self, x]


S(0x5195b0, 'GUESS FUN_005195b0 (vtable +0x350, helpers stubbed)', 'thiscall', None, ret=None, gen=_shape,
  note='unclaimed-66 batch 1929; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED')
S(0x5195e0, 'GUESS FUN_005195e0 (vtable +0x35c, helpers stubbed)', 'thiscall', None, ret=None, gen=_shape,
  note='unclaimed-66 batch 1929; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED')
S(0x519670, 'GUESS FUN_00519670 (vtable +0x2d8, helpers stubbed)', 'thiscall', None, ret=None, gen=_shape,
  note='unclaimed-66 batch 1929; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED')
