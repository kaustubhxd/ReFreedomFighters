"""specs_s1928.py - unclaimed-66 batch 28 (gap band, GUESS names). Thiscall with one stack argument X (ret 4).

The helpers 0x5003d0 (returns a pointer; one argument, ret 4) and 0x5002f0 (thiscall, one argument, ret 4) belong to other areas; here they
are hooked by address as recording GUESS stubs: 0x5003d0 returns a fixed fake object P, 0x5002f0 logs its argument. The sub-object at
this+0x1c has a vtable whose +0x37c and +0x378 slots return random dwords (logged). X and this are 0x200 random bytes; X+8 is a holder."""
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

    def h5002(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)

    c.emu.hook(0x5003d0, h5003)
    c.emu.hook(0x5002f0, h5002)
    sub_vt = c.emu.fake_vtable('gap sub', 0x380 // 4 + 1, slots={
        0x37c: _slot('gap sub +0x37c (stub)', 0x37c, 0, lambda e, a: (c.rng.getrandbits(32), None)),
        0x378: _slot('gap sub +0x378 (stub)', 0x378, 0, lambda e, a: (c.rng.getrandbits(32), None))})
    sub = c.emu.fake_object('gap sub', 0x40, vtable=sub_vt)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x1c, sub)
    x = _rnd(c, 0x40)
    return [self, x]


S(0x51b180, 'GUESS FUN_0051b180 (vtable +0x37c, helpers stubbed)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1928; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED stubs here')
S(0x51b240, 'GUESS FUN_0051b240 (vtable +0x378, helpers stubbed)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1928; gap band; 0x5003d0 and 0x5002f0 are other areas: HOOKED stubs here')
