"""specs_s1912.py - unclaimed-66 batch 1912: GUESS FUN_00434a90, stdcall (one argument, the object; ret 4).

The object's vtable +0x38 (no argument) and +0x30 (one argument, callee pops 4) are logging stubs."""
from pilot import S


def _rnd(c, n, align=4):
    a = c.emu.alloc(n, align)
    c.emu.wbytes(a, bytes(c.rng.getrandbits(8) for _ in range(n)))
    return a


def _slot(name, off, nargs):
    def h(e, r):
        args = [e.arg32(k) for k in range(nargs)]
        e.calllog.append((name, off, e.reg('ecx'), tuple(args)))
        e.ret(eax=0, argbytes=4 * nargs)
    return h


def _obj(c):
    vt = c.emu.fake_vtable('leaf434a90 obj', 0x38 // 4 + 1, slots={
        0x38: _slot('leaf434a90 obj +0x38 (stub)', 0x38, 0),
        0x30: _slot('leaf434a90 obj +0x30 (stub)', 0x30, 1)})
    obj = c.emu.fake_object('leaf434a90 obj', 0x40, vtable=vt)
    return [obj]


S(0x434a90, 'GUESS FUN_00434a90 (two vtable calls)', 'stdcall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1912; slice-5 (GUESS); vtable slots +0x38 and +0x30 stubbed')
