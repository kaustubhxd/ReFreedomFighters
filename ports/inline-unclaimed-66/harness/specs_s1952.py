"""specs_s1952.py - unclaimed-66 batch 58 (gap band, GUESS name). THISCALL(this), two arguments, ret 8.

0x55edc0 (stdcall, two arguments, ret 8) is a recording GUESS stub hooked by address. The sys child's vtable +0x4c returns a fixed value per
case (one argument, ret 4). The object at [a+0x15] has a logging vtable whose +0x3c slot takes one argument (ret 4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    rv = c.rng.getrandbits(32)

    def h3c(e, r):
        e.calllog.append(('a+0x15 object vtable +0x3c (stub)', 0x3c, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    vt_o = c.emu.fake_vtable('batch58 obj', 0x3c // 4 + 1, slots={0x3c: h3c})
    obj = c.emu.fake_object('batch58 obj', 0x40, vtable=vt_o)

    a = _rnd(c, 0x40)
    c.emu.w32(a + 0x15, obj)

    def h4c(e, r):
        e.calllog.append(('sys child vtable +0x4c (stub)', 0x4c, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    vt_c = c.emu.fake_vtable('batch58 child', 0x4c // 4 + 1, slots={0x4c: h4c})
    child = c.emu.fake_object('batch58 child', 0x40, vtable=vt_c)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)

    self = _rnd(c, 0x40)

    def h55e(e, r):
        e.calllog.append(('0x55edc0 (GUESS stub)', 0x55edc0, None, (e.arg32(0), e.arg32(1))))
        e.ret(eax=0, argbytes=8)
    c.emu.hook(0x55edc0, h55e)
    b = c.rng.getrandbits(32)
    return [self, a, b]


S(0x5200d0, 'GUESS FUN_005200d0 (0x55edc0, child vtable +0x4c of this+0x20, then vtable +0x3c of [a+0x15])', 'thiscall', None, ret=None,
  gen=_gap, note='unclaimed-66 batch 1952; gap band; 0x55edc0 GUESS stub by address')
