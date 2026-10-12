"""specs_s1938.py - unclaimed-66 batches 38 and 39 (gap band; GUESS names). Thiscall, no arguments.

0x511950 (member dtor) is a recording GUESS stub (hooked by address; ECX logged). 0x512070 runs as exe code (bound): its CRT free 0x634273 and
the base dtor 0x43ea20 are hooked by address (recording), and its three sub-objects are fakes with a logging slot 0. The object is 0x400
random bytes (the members sit below +0x2d8 and +0x1ed)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot0(name):
    def h(e, r):
        e.calllog.append((name, 0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    return h


def _wrapper(c):
    def h511(e, r):
        e.calllog.append(('0x511950 (GUESS stub)', 0x511950, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x511950, h511)

    def hfree(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, hfree)

    def hbase(e, r):
        e.calllog.append(('base dtor 0x43ea20 (GUESS stub)', 0x43ea20, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x43ea20, hbase)
    self = _rnd(c, 0x400)
    c.emu.w32(self + 0x5c, _rnd(c, 0x20))
    for off in (0x127, 0x12b, 0x1ed):
        if c.rng.random() < 0.3:
            c.emu.w32(self + off, 0)
        else:
            vt = c.emu.fake_vtable('wrap obj %x' % off, 4, slots={0: _slot0('wrap obj %x slot0 (stub)' % off)})
            c.emu.w32(self + off, c.emu.fake_object('wrap obj %x' % off, 0x40, vtable=vt))
    return [self]


S(0x51f4a0, 'GUESS FUN_0051f4a0 (0x511950 then base step 0x512070)', 'thiscall', None, ret=None, gen=_wrapper,
  note='unclaimed-66 batch 1938; gap band; 0x511950 GUESS stub; 0x512070 exe (bound); free and 0x43ea20 hooked')
S(0x51f4c0, 'GUESS FUN_0051f4c0 (vtable store, 0x511950, then 0x512070)', 'thiscall', None, ret=None, gen=_wrapper,
  note='unclaimed-66 batch 1938; gap band; 0x511950 GUESS stub; 0x512070 exe (bound); free and 0x43ea20 hooked')
