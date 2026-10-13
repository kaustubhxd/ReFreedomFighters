"""specs_s1966.py - unclaimed-66 batch 84 (gap band, GUESS name). STDCALL, one argument x, ret 4.

0x5003d0 (ret 4; ECX = holder) is a GUESS stub by address: index 0 returns p0, index 1 returns p1 (random contents). The sys child's vtable
+0x60 (one argument, ret 4) returns v or 0. 0x44b8b0 (THISCALL, one argument, ret 4) is a GUESS stub by address (ECX and the argument logged)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gen(c):
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p0 = _rnd(c, 0x40)
    p1 = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p0 if e.arg32(0) == 0 else p1, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)

    def h44b(e, r):
        e.calllog.append(('0x44b8b0 (GUESS stub)', 0x44b8b0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x44b8b0, h44b)

    v = 0 if c.rng.random() < 0.3 else _rnd(c, 0x40)

    def h60(e, r):
        e.calllog.append(('sys child vtable +0x60 (stub)', 0x60, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=v, argbytes=4)
    vt = c.emu.fake_vtable('batch84 child', 0x60 // 4 + 1, slots={0x60: h60})
    child = c.emu.fake_object('batch84 child', 0x40, vtable=vt)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)
    return [x]


S(0x511330, 'GUESS FUN_00511330 (0x5003d0 index 0, child vtable +0x60, then 0x44b8b0 with the index-1 value)', 'stdcall', None, ret=None,
  gen=_gen, note='unclaimed-66 batch 1966; gap band; GUESS stubs by address')
