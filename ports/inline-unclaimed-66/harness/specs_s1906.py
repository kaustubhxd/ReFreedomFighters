"""specs_s1906.py - unclaimed-66 batch 1906: five slice-5 leaves (GUESS names). Thiscall; 0x484d10 has one unused argument (ret 4).

Objects are random bytes. 0x4837d0's chain: this+0x455 -> object with a dword at +0x10. 0x612150: this+0x14 -> object x whose
vtable's +0x30 slot is a logging stub (called with the vtable as ECX and x as its argument, callee pops 4). 0x484d10's vtable
+0x594 slot is a logging stub (one argument, callee pops 4)."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs, impl):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        eax, st0 = impl(e, args)
        e.ret(eax=eax, argbytes=4 * nargs, st0=st0)
    return h


def _chain(c):
    inner = _rnd(c, 0x40)
    mid = _rnd(c, 0x20)
    c.emu.w32(mid + 0x10, c.rng.getrandbits(32))
    self = _rnd(c, 0x500)
    c.emu.w32(self + 0x455, mid)
    return [self]


def _obj(c):
    return [_rnd(c, 0x100)]


def _x(c):
    x_vt = c.emu.fake_vtable('x', 0x30 // 4 + 1, slots={
        0x30: _slot('x vtable +0x30 (stub)', 0x30, 1, lambda e, a: (c.rng.getrandbits(32), None))})
    x = c.emu.fake_object('x', 0x40, vtable=x_vt)
    self = _rnd(c, 0x100)
    c.emu.w32(self + 0x14, x)
    return [self]


def _forward(c):
    vt = c.emu.fake_vtable('forward target', 0x594 // 4 + 1, slots={
        0x594: _slot('forward target +0x594 (stub)', 0x594, 1, lambda e, a: (0, None))})
    obj = c.emu.fake_object('forward', 0x100, vtable=vt)
    return [obj, c.rng.getrandbits(32)]


S(0x4837d0, 'GUESS FUN_004837d0 (chain getter)', 'thiscall', None, ret='eax', gen=_chain,
  note='unclaimed-66 batch 1906; slice-5 leaf (GUESS)')
S(0x560310, 'GUESS FUN_00560310 (global zero)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1906; slice-5 leaf (GUESS)')
S(0x4364d0, 'GUESS FUN_004364d0 (reset returns this)', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-66 batch 1906; slice-5 leaf (GUESS)')
S(0x484d10, 'GUESS FUN_00484d10 (vtable +0x594 forward)', 'thiscall', None, ret=None, gen=_forward,
  note='unclaimed-66 batch 1906; slice-5 leaf (GUESS); vtable slot stubbed')
S(0x612150, 'GUESS FUN_00612150 (vtable +0x30 of x via its vtable)', 'thiscall', None, ret='eax', gen=_x,
  note='unclaimed-66 batch 1906; slice-5 leaf (GUESS); x vtable slot stubbed')
