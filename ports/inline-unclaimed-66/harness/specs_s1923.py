"""specs_s1923.py - unclaimed-66 batch 1923: GUESS FUN_00659b90 (thiscall, one argument, ret 4).

Vtable +0xe0 (one argument) is a logging stub. 0x63f570 is a GUESS STUB here (hooked by address, records ECX and its argument): its real body is a separate job."""
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
    def h(e, r):                       # 0x63f570 stubbed by address: its own job (its pointer chasing needs real objects)
        e.calllog.append(('0x63f570 (GUESS stub)', 0x63f570, e.reg('ecx'), (e.arg32(0),)))
        e.ret(eax=0, argbytes=4)
    c.emu.hook(0x63f570, h)
    vt = c.emu.fake_vtable('leaf659b90 obj', 0xe0 // 4 + 1, slots={
        0xe0: _slot('leaf659b90 obj +0xe0 (stub)', 0xe0, 1, lambda e, a: (0, None))})
    obj = _rnd(c, 0x200)
    c.emu.w32(obj, vt)
    return [obj, c.rng.getrandbits(32)]


S(0x659b90, 'GUESS FUN_00659b90 (vtable +0xe0 then bound 0x63f570)', 'thiscall', None, ret=None, gen=_obj,
  note='unclaimed-66 batch 1923; slice-5 (GUESS); vtable +0xe0 stubbed; 0x63f570 GUESS stub (hook)')
