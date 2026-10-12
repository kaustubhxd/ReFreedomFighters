"""specs_s1937.py - unclaimed-66 batch 37 (gap band; GUESS name). Thiscall, no arguments.

The CRT free 0x634273 is hooked by address (records ptr and size). The base destructor 0x43ea20 (the tail jump) is a recording GUESS stub
(hooked by address). The three sub-objects at +0x127, +0x12b and +0x1ed are each null (30%) or a fake object whose vtable slot 0 logs its
argument (one, callee pops). The object is 0x200 random bytes; its +0x5c pointer is a heap block."""
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


def _step(c):
    def hfree(e, r):
        e.calllog.append(('CRT free 0x634273 (hook)', 0x634273, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x634273, hfree)

    def hbase(e, r):
        e.calllog.append(('base dtor 0x43ea20 (GUESS stub)', 0x43ea20, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x43ea20, hbase)
    self = _rnd(c, 0x200)
    c.emu.w32(self + 0x5c, _rnd(c, 0x20))
    for off in (0x127, 0x12b, 0x1ed):
        if c.rng.random() < 0.3:
            c.emu.w32(self + off, 0)
        else:
            vt = c.emu.fake_vtable('step obj %x' % off, 4, slots={0: _slot0('step obj %x slot0 (stub)' % off)})
            c.emu.w32(self + off, c.emu.fake_object('step obj %x' % off, 0x40, vtable=vt))
    return [self]


S(0x512070, 'GUESS FUN_00512070 (base dtor step: free, three slot-0 calls, tail to 0x43ea20)', 'thiscall', None, ret=None, gen=_step,
  note='unclaimed-66 batch 1937; gap band; CRT free and 0x43ea20 hooked (GUESS stub)')
