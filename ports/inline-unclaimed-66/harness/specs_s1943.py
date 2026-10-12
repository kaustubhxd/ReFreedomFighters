"""specs_s1943.py - unclaimed-66 batch 44 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4.

0x51b5c0 (THISCALL with one argument, ret 4) is a recording GUESS stub hooked by address. The object under test has a logging vtable whose
+0x38 slot returns a fixed value per case; x is a second object whose slot 0 logs its argument."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    rv = c.rng.getrandbits(32)

    def h38(e, r):
        e.calllog.append(('this vtable +0x38 (stub)', 0x38, e.reg('ecx'), ()))
        e.ret(eax=rv, argbytes=0)
    vt_self = c.emu.fake_vtable('batch44 self', 0x38 // 4 + 1, slots={0x38: h38})
    self = _rnd(c, 0x40)
    c.emu.w32(self, vt_self)

    def h0(e, r):
        e.calllog.append(('x vtable slot 0 (stub)', 0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt_x = c.emu.fake_vtable('batch44 x', 1, slots={0: h0})
    x = _rnd(c, 0x40)
    c.emu.w32(x, vt_x)

    def h51b(e, r):
        e.calllog.append(('0x51b5c0 (GUESS stub)', 0x51b5c0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x51b5c0, h51b)
    return [self, x]


S(0x51ff00, 'GUESS FUN_0051ff00 (0x51b5c0, vtable +0x38 of this, then vtable slot 0 of x)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1943; gap band; 0x51b5c0 GUESS stub')
