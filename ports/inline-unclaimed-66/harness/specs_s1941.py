"""specs_s1941.py - unclaimed-66 batch 42 (gap band, GUESS name). THISCALL(this), no arguments, no return value.

0x517540 (ZCar::ClassInit2 in the vehicles area, unclaimed here) is a recording GUESS stub hooked by address. The object under test is 0x1800
random bytes with a logging vtable; its slot +0x328 logs its three stack arguments and returns a fixed value per case."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    self = _rnd(c, 0x1800)
    k = c.rng.random()
    c.emu.w32(self + 0x165c, 0 if k < 0.3 else c.rng.getrandbits(32))
    rv = c.rng.getrandbits(32)

    def h328(e, r):
        e.calllog.append(('this vtable +0x328 (stub)', 0x328, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=rv, argbytes=12)
    vt = c.emu.fake_vtable('batch42 obj', 0x328 // 4 + 1, slots={0x328: h328})
    c.emu.w32(self, vt)

    def h517(e, r):
        e.calllog.append(('0x517540 (GUESS stub)', 0x517540, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x517540, h517)
    return [self]


S(0x51f5d0, 'GUESS FUN_0051f5d0 (0x517540, then vtable +0x328 when [this+0x165c] is set)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1941; gap band; 0x517540 GUESS stub; vtable +0x328 logging stub')
