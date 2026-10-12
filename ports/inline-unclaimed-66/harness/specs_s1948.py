"""specs_s1948.py - unclaimed-66 batch 49 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4.

0x5003d0 (ret 4, index argument, ECX = holder) is a recording GUESS stub hooked by address; it returns p1 for index 1 and p2 for index 0.
The object at [this+0x14] has a logging vtable whose +0x2dc slot takes two arguments (ret 8)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    def h2dc(e, r):
        e.calllog.append(('this+0x14 vtable +0x2dc (stub)', 0x2dc, e.reg('ecx'), (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)
    vt = c.emu.fake_vtable('batch49 obj', 0x2dc // 4 + 1, slots={0x2dc: h2dc})
    obj = c.emu.fake_object('batch49 obj', 0x40, vtable=vt)
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0x14, obj)
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p1 = _rnd(c, 0x40)
    p2 = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p1 if e.arg32(0) == 1 else p2, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)
    return [self, x]


S(0x519bb0, 'GUESS FUN_00519bb0 (0x5003d0 index 1 and 0, then vtable +0x2dc of this+0x14)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1948; gap band; 0x5003d0 GUESS stub by address')
