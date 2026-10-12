"""specs_s1951.py - unclaimed-66 batches 56 and 57 (gap band, GUESS names). Hooks by address: 0x5003d0 (ret 4, index argument),
0x44b610 (no arguments; logs ECX), 0x44b740 (cdecl, one argument), 0x5122c0 (ret 4, one argument, ECX logged; returns a random byte),
0x5002f0 (ret 4, one argument, ECX logged). The sys child's vtable +0x60 returns v or 0 (one argument, ret 4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _sys_child(c, slots):
    vt = c.emu.fake_vtable('batch56 child', 0x60 // 4 + 1, slots=slots)
    child = c.emu.fake_object('batch56 child', 0x40, vtable=vt)
    sys_ = _rnd(c, 0x1a00)
    c.emu.w32(sys_ + 0x9b, child)
    c.emu.w32(0x70039c, sys_)


def _gap511(c):
    holder = _rnd(c, 0x40)
    x = _rnd(c, 0x40)
    c.emu.w32(x + 4, holder)
    p0 = _rnd(c, 0x40)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p0, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)
    v = 0 if c.rng.random() < 0.3 else _rnd(c, 0x100)

    def h60(e, r):
        e.calllog.append(('sys child vtable +0x60 (stub)', 0x60, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=v, argbytes=4)
    _sys_child(c, {0x60: h60})

    def h610(e, r):
        e.calllog.append(('0x44b610 (GUESS stub)', 0x44b610, e.reg('ecx'), ()))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x44b610, h610)

    def h740(e, r):
        e.calllog.append(('0x44b740 (GUESS stub)', 0x44b740, None, (e.arg32(0),)))
        e.ret(eax=0, argbytes=0)
    c.emu.hook(0x44b740, h740)
    return [x]


S(0x511410, 'GUESS FUN_00511410 (0x5003d0, child vtable +0x60, then 0x44b610 and 0x44b740 when set)', 'stdcall', None, ret=None,
  gen=_gap511, note='unclaimed-66 batch 1951; gap band; helpers GUESS stubs by address')


def _gap519(c):
    self = _rnd(c, 0x40)
    obj = _rnd(c, 0x40)
    c.emu.w32(self + 0x14, obj)
    x = _rnd(c, 0x40)
    h0 = _rnd(c, 0x40)
    h1 = _rnd(c, 0x40)
    c.emu.w32(x + 4, h0)
    c.emu.w32(x + 8, h1)
    p0 = _rnd(c, 0x40)
    p1 = _rnd(c, 0x40)
    rv = c.rng.getrandbits(8)

    def h3d0(e, r):
        e.calllog.append(('0x5003d0 (GUESS stub)', 0x5003d0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=p0 if e.reg('ecx') == h0 else p1, argbytes=4)
    c.emu.hook(0x5003d0, h3d0)

    def h122(e, r):
        e.calllog.append(('0x5122c0 (GUESS stub)', 0x5122c0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=rv, argbytes=4)
    c.emu.hook(0x5122c0, h122)

    def h2f0(e, r):
        e.calllog.append(('0x5002f0 (GUESS stub)', 0x5002f0, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x5002f0, h2f0)
    return [self, x]


S(0x519470, 'GUESS FUN_00519470 (0x5003d0, 0x5122c0 low byte, 0x5003d0, 0x5002f0)', 'thiscall', None, ret=None, gen=_gap519,
  note='unclaimed-66 batch 1951; gap band; helpers GUESS stubs by address')
