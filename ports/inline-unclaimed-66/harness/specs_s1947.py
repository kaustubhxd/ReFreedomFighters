"""specs_s1947.py - unclaimed-66 batch 48 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4.

0x5003d0 (ret 4, index argument, ECX = holder) is a recording GUESS stub hooked by address; it returns p, which holds random bytes.
The object at [this+0x18] has a logging vtable whose +0x600 slot takes one argument (ret 4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    def h600(e, r):
        e.calllog.append(('this+0x18 vtable +0x600 (stub)', 0x600, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt = c.emu.fake_vtable('batch48 obj', 0x600 // 4 + 1, slots={0x600: h600})
    obj = c.emu.fake_object('batch48 obj', 0x40, vtable=vt)
    self = _rnd(c, 0x40)
    c.emu.w32(self + 0x18, obj)
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)
    return [self, x]


S(0x508180, 'GUESS FUN_00508180 (0x5003d0, float scale by 0x67cd40, vtable +0x600 of this+0x18)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1947; gap band; 0x5003d0 GUESS stub by address')
