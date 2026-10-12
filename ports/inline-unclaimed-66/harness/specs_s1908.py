"""specs_s1908.py - unclaimed-66 batch 1908: three slice-5 leaves (GUESS names).

0x4eb3d0: thiscall, void (the store to this). 0x61bc50: cdecl(obj, a) (two stack arguments, the caller pops); the vtable
+8 slot of obj is a logging stub with one argument (the callee pops 4). 0x4aff10: thiscall with one unused stack argument
(ret 4), result in AL; its vtable +0x84 is a logging stub with no argument (callee pops 0)."""
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


def _obj(c):
    return [_rnd(c, 0x100)]


def _cdecl_obj(c):
    vt = c.emu.fake_vtable('leaf61bc50 obj', 0x30 // 4 + 1, slots={
        0x8: _slot('leaf61bc50 obj +8 (stub)', 0x8, 1, lambda e, a: (0, None))})
    obj = c.emu.fake_object('leaf61bc50 obj', 0x40, vtable=vt)
    return [obj, c.rng.getrandbits(32)]


def _with_vt84(c):
    vt = c.emu.fake_vtable('leaf4aff10 obj', 0x90 // 4 + 1, slots={
        0x84: _slot('leaf4aff10 obj +0x84 (stub)', 0x84, 0, lambda e, a: (0, None))})
    self = _rnd(c, 0x100)
    c.emu.w32(self, vt)
    return [self, c.rng.getrandbits(32)]


S(0x4eb3d0, 'GUESS FUN_004eb3d0 (vtable store)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1908; slice-5 leaf (GUESS); jumps to the no-op ret 0x4690b0 (original)')
S(0x61bc50, 'GUESS FUN_0061bc50 (cdecl forward to vtable +8)', 'cdecl', None, ret=None, gen=_cdecl_obj,
  note='unclaimed-66 batch 1908; slice-5 leaf (GUESS); vtable slot stubbed')
S(0x4aff10, 'GUESS FUN_004aff10 (flag clear and vtable +0x84)', 'thiscall', None, ret='al', gen=_with_vt84,
  note='unclaimed-66 batch 1908; slice-5 leaf (GUESS); vtable slot stubbed')
