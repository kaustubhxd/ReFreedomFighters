"""specs_s1954.py - unclaimed-66 batches 63 and 64 (gap band, GUESS names). STDCALL, one argument, ret 4.

0x5003d0 (ret 4, index argument; ECX = holder) is a recording GUESS stub hooked by address: index 0 returns p0 and index 1 returns p1.
The ZSysInterface child's vtable +0x60 (one argument, ret 4) returns v or 0. The child's vtable +0x134 (no arguments) returns a logging object r
whose slot +0x40 takes three arguments (ret 12). p0 and p1 hold pointers to 0x40-byte objects A and B (for 0x50aee0)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sys_child(c, slots, n):
    vt = c.emu.fake_vtable('batch63 child', n, slots=slots)
    child = c.emu.fake_object('batch63 child', 0x40, vtable=vt)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)


def _hook_3d0(c, p0, p1, holder):
    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p0 if e.arg32(0) == 0 else p1, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)


def _gap63(c):
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p0 = _rnd(c, 0x40)
    p1 = _rnd(c, 0x40)
    if c.rng.random() < 0.5:
        c.emu.w32(p1, 0)
    _hook_3d0(c, p0, p1, holder)

    v = 0 if c.rng.random() < 0.3 else _rnd(c, 0x100)

    def h60(e, r):
        e.calllog.append(('sys child vtable +0x60 (stub)', 0x60, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=v, argbytes=4)
    _sys_child(c, {0x60: h60}, 0x60 // 4 + 1)
    return [x]


S(0x5112e0, 'GUESS FUN_005112e0 (0x5003d0, child vtable +0x60, then set or clear bit 8 of [v+0x40])', 'stdcall', None, ret=None,
  gen=_gap63, note='unclaimed-66 batch 1954; gap band; 0x5003d0 GUESS stub by address')


def _gap64(c):
    x = _rnd(c, 0x40)
    holder = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    A = _rnd(c, 0x40)
    B = _rnd(c, 0x40)
    p0 = _rnd(c, 0x40)
    p1 = _rnd(c, 0x40)
    c.emu.w32(p0, A)
    c.emu.w32(p1, B)
    _hook_3d0(c, p0, p1, holder)

    def h40(e, r):
        e.calllog.append(('r vtable +0x40 (stub)', 0x40, e.reg('ecx'), (e.arg32(0), e.arg32(1), e.arg32(2))))
        e.ret(eax=0, argbytes=12)
    vt_r = c.emu.fake_vtable('batch64 r', 0x40 // 4 + 1, slots={0x40: h40})
    r = c.emu.fake_object('batch64 r', 0x40, vtable=vt_r)

    def h134(e, rr):
        e.calllog.append(('sys child vtable +0x134 (stub)', 0x134, e.reg('ecx'), ()))
        e.ret(eax=r, argbytes=0)
    _sys_child(c, {0x134: h134}, 0x134 // 4 + 1)
    return [x]


S(0x50aee0, 'GUESS FUN_0050aee0 (0x5003d0 for A and B, child vtable +0x134, then vtable +0x40 of r)', 'stdcall', None, ret=None,
  gen=_gap64, note='unclaimed-66 batch 1954; gap band; 0x5003d0 GUESS stub by address')
