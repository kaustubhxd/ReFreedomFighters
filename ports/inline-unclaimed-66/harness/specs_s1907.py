"""specs_s1907.py - unclaimed-66 batch 1907: four slice-5 leaves (GUESS names). Thiscall, no stack arguments.

Objects are random bytes. 0x65c9d0's destination is a random 0x40-byte block whose address is stored at this+0x400.
0x4f7950's vtable +0x36c slot is a logging stub (one argument, callee pops 4); its argument is [this+0x93]."""
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
    # the globals are randomised per case (both builds read the same values): 0x6e6730 and the next dword
    c.emu.w32(0x6e6730, c.rng.getrandbits(32))
    c.emu.w32(0x6e6734, c.rng.getrandbits(32))
    return [_rnd(c, 0x500)]


def _store(c):
    dst = _rnd(c, 0x40)
    self = _rnd(c, 0x500)
    c.emu.w32(self + 0x400, dst)
    return [self]


def _forward(c):
    vt = c.emu.fake_vtable('leaf forward', 0x36c // 4 + 1, slots={
        0x36c: _slot('leaf forward +0x36c (stub)', 0x36c, 1, lambda e, a: (0, None))})
    self = _rnd(c, 0x500)
    c.emu.w32(self, vt)
    return [self]


S(0x40ce50, 'GUESS FUN_0040ce50 (empty)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1907; slice-5 leaf (GUESS)')
S(0x4b0b90, 'GUESS FUN_004b0b90 (global dword)', 'thiscall', None, ret='eax', gen=_obj,
  note='unclaimed-66 batch 1907; slice-5 leaf (GUESS); reads the global 0x6e6730')
S(0x65c9d0, 'GUESS FUN_0065c9d0 (store through pointer)', 'thiscall', None, ret=None, gen=_store,
  note='unclaimed-66 batch 1907; slice-5 leaf (GUESS)')
S(0x4f7950, 'GUESS FUN_004f7950 (vtable +0x36c forward)', 'thiscall', None, ret=None, gen=_forward,
  note='unclaimed-66 batch 1907; slice-5 leaf (GUESS); slot stubbed')
