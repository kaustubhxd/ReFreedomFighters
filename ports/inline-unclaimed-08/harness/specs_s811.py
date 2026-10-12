"""specs_s811.py - unclaimed-08 batch 811 (docs/20-unclaimed-08.md): ZFenceGate::Load(ZLoadGame*), thiscall, one argument,
ret 4, result in AL.

The gate is 0x300 random bytes. The load game L (vtable +0x68) returns object A; A (vtable +0x68) returns object B; B
(vtable +0x40) is a logging stub. Every argument is a pointer into the gate, so the call log matches across builds."""
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


def _load(c):
    gate = _rnd(c, 0x300)
    b_obj = c.emu.fake_object('loader B', 0x40, vtable=c.emu.fake_vtable('loader B', 0x40 // 4 + 1, slots={
        0x40: _slot('loader B read (stub)', 0x40, 1, lambda e, a: (0, None))}))
    a_obj = c.emu.fake_object('loader A', 0x40, vtable=c.emu.fake_vtable('loader A', 0x68 // 4 + 1, slots={
        0x68: _slot('loader A child (stub)', 0x68, 1, lambda e, a: (b_obj, None))}))
    l_obj = c.emu.fake_object('load game', 0x40, vtable=c.emu.fake_vtable('ZLoadGame', 0x68 // 4 + 1, slots={
        0x68: _slot('ZLoadGame child (stub)', 0x68, 1, lambda e, a: (a_obj, None))}))
    return [gate, l_obj]


S(0x5c27b0, 'ZFenceGate::Load (unknown)', 'thiscall', None, ret='al', gen=_load,
  note='unclaimed-08 batch 11; clears bit 6 of +4; loader chain +0x68, +0x68, +0x40 stubbed')
