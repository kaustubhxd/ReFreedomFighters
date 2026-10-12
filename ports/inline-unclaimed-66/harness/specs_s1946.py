"""specs_s1946.py - unclaimed-66 batch 47 (gap band, GUESS name). THISCALL(this), one stack argument, ret 4.

0x5003d0 (ret 4, index argument; ECX = holder) and 0x5002f0 (ret 4, ECX = p) are recording GUESS stubs hooked by address. The ZSysInterface
child's vtable +0x4c is a logging stub (one argument, ret 4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _gap(c):
    rv = c.rng.getrandbits(32)

    def h4c(e, r):
        e.calllog.append(('sys child vtable +0x4c (stub)', 0x4c, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    vt = c.emu.fake_vtable('batch47 child', 0x4c // 4 + 1, slots={0x4c: h4c})
    child = c.emu.fake_object('batch47 child', 0x40, vtable=vt)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)

    self = _rnd(c, 0x40)
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 8, holder)
    p = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)

    def h2f0(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x5002f0, h2f0)
    return [self, x]


S(0x501830, 'GUESS FUN_00501830 (sys child vtable +0x4c, 0x5003d0, 0x5002f0)', 'thiscall', None, ret=None, gen=_gap,
  note='unclaimed-66 batch 1946; gap band; 0x5003d0 and 0x5002f0 GUESS stubs by address')
